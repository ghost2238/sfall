/*
 *    sfall
 *    Copyright (C) 2008-2016  The sfall team
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "main.h"
#include "FalloutEngine.h"

#include "MiscPatches.h"

static char mapName[65]       = {};
static char configName[65]    = {};
static char patchName[65]     = {};
static char versionString[65] = {};

static int* scriptDialog = nullptr;

static void __declspec(naked) WeaponAnimHook() {
	__asm {
		cmp edx, 11;
		je  c11;
		cmp edx, 15;
		je  c15;
		jmp art_get_code_;
c11:
		mov edx, 16;
		jmp art_get_code_;
c15:
		mov edx, 17;
		jmp art_get_code_;
	}
}

static void __declspec(naked) register_object_take_out_hack() {
	__asm {
		push ecx;
		push eax;
		mov  ecx, edx;                            // ID1
		mov  edx, [eax + 0x1C];                   // cur_rot
		inc  edx;
		push edx;                                 // ID3
		xor  ebx, ebx;                            // ID2
		mov  edx, [eax + 0x20];                   // fid
		and  edx, 0xFFF;                          // Index
		xor  eax, eax;
		inc  eax;                                 // Obj_Type CRITTER
		call art_id_;
		mov  edx, eax;
		xor  ebx, ebx;
		dec  ebx;                                 // delay -1
		pop  eax;                                 // critter
		call register_object_change_fid_;
		pop  ecx;
		xor  eax, eax;
		retn;
	}
}

static void __declspec(naked) gdAddOptionStr_hack() {
	__asm {
		mov  ecx, ds:[_gdNumOptions];
		add  ecx, '1';
		push ecx;
		mov  ecx, 0x4458FA;
		jmp  ecx;
	}
}

static void __declspec(naked) action_use_skill_on_hook_science() {
	__asm {
		cmp esi, ds:[_obj_dude];
		jne end;
		mov eax, KILL_TYPE_robot;
		retn;
end:
		jmp critter_kill_count_type_;
	}
}

static void __declspec(naked) intface_item_reload_hook() {
	__asm {
		push eax;
		mov  eax, dword ptr ds:[_obj_dude];
		call register_clear_;
		test eax, eax;
		jnz  fail;
		inc  eax;
		call register_begin_;
		xor  edx, edx;
		xor  ebx, ebx;
		mov  eax, dword ptr ds:[_obj_dude];
		dec  ebx;
		call register_object_animate_;
		call register_end_;
fail:
		pop  eax;
		jmp  gsound_play_sfx_file_;
	}
}

static void __declspec(naked) automap_hack() {
	static const DWORD ScannerHookRet  = 0x41BC1D;
	static const DWORD ScannerHookFail = 0x41BC65;
	__asm {
		mov  eax, ds:[_obj_dude];
		mov  edx, PID_MOTION_SENSOR;
		call inven_pid_is_carried_ptr_;
		test eax, eax;
		jz   fail;
		mov  edx, eax;
		jmp  ScannerHookRet;
fail:
		jmp  ScannerHookFail;
	}
}

static void __declspec(naked) op_obj_can_see_obj_hook() {
	__asm {
		push obj_shoot_blocking_at_;      // check hex objects func pointer
		push 0x20;                        // flags, 0x20 = check ShootThru
		mov  ecx, dword ptr [esp + 0x0C]; // buf **ret_objStruct
		push ecx;
		xor  ecx, ecx;
		call make_straight_path_func_;    // (EAX *objStruct, EDX hexNum1, EBX hexNum2, ECX 0, stack1 **ret_objStruct, stack2 flags, stack3 *check_hex_objs_func)
		retn 8;
	}
}

static DWORD __fastcall GetWeaponSlotMode(DWORD itemPtr, DWORD mode) {
	int slot = (mode > 0) ? 1 : 0;
	ItemButtonItem* itemButton = &ptr_itemButtonItems[slot];
	if ((DWORD)itemButton->item == itemPtr) {
		int slotMode = itemButton->mode;
		if (slotMode == 3 || slotMode == 4) {
			mode++;
		}
	}
	return mode;
}

static void __declspec(naked) display_stats_hook() {
	__asm {
		push eax;
		push ecx;
		mov  ecx, ds:[esp + edi + 0xA8 + 0xC]; // get itemPtr
		call GetWeaponSlotMode;                // ecx - itemPtr, edx - mode;
		mov  edx, eax;
		pop  ecx;
		pop  eax;
		jmp  item_w_range_;
	}
}

static void __declspec(naked) endgame_movie_hook() {
	__asm {
		cmp  [esp + 16], 0x45C563; // call from op_endgame_movie_
		je   playWalkMovie;
		retn;
playWalkMovie:
		call stat_level_;
		xor  edx, edx;
		add  eax, 10;
		mov  ecx, eax;
		mov  eax, 1500;
		call pause_for_tocks_;
		mov  eax, ecx;
		jmp  gmovie_play_;
	}
}

static void __declspec(naked) ListDrvdStats_hook() {
	static const DWORD ListDrvdStats_Ret = 0x4354D9;
	__asm {
		call IsRadInfluence;
		test eax, eax;
		jnz  influence;
		mov  eax, ds:[_obj_dude];
		jmp  critter_get_rads_;
influence:
		xor  ecx, ecx;
		mov  cl, ds:[_RedColor];
		cmp  dword ptr [esp], 0x4354BE + 5;
		jne  skip;
		mov  cl, 131; // color index for selected
skip:
		add  esp, 4;
		jmp  ListDrvdStats_Ret;
	}
}

static void AdditionalWeaponAnimsPatch() {
	if (GetConfigInt("Misc", "AdditionalWeaponAnims", 0)) {
		dlog("Applying additional weapon animations patch.", DL_INIT);
		SafeWrite8(0x419320, 18); // art_get_code_
		const DWORD weaponAnimAddr[] = {
			0x451648, 0x451671, // gsnd_build_character_sfx_name_
			0x4194CC            // art_get_name_
		};
		HookCalls(WeaponAnimHook, weaponAnimAddr);
		dlogr(" Done", DL_INIT);
	}
}

static void SkilldexImagesPatch() {
	dlog("Checking for changed skilldex images.", DL_INIT);
	long tmp = GetConfigInt("Misc", "Lockpick", 293);
	if (tmp != 293) SafeWrite32(0x518D54, tmp);
	tmp = GetConfigInt("Misc", "Steal", 293);
	if (tmp != 293) SafeWrite32(0x518D58, tmp);
	tmp = GetConfigInt("Misc", "Traps", 293);
	if (tmp != 293) SafeWrite32(0x518D5C, tmp);
	tmp = GetConfigInt("Misc", "FirstAid", 293);
	if (tmp != 293) SafeWrite32(0x518D4C, tmp);
	tmp = GetConfigInt("Misc", "Doctor", 293);
	if (tmp != 293) SafeWrite32(0x518D50, tmp);
	tmp = GetConfigInt("Misc", "Science", 293);
	if (tmp != 293) SafeWrite32(0x518D60, tmp);
	tmp = GetConfigInt("Misc", "Repair", 293);
	if (tmp != 293) SafeWrite32(0x518D64, tmp);
	dlogr(" Done", DL_INIT);
}

static void ScienceOnCrittersPatch() {
	switch (GetConfigInt("Misc", "ScienceOnCritters", 0)) {
	case 1:
		HookCall(0x41276E, action_use_skill_on_hook_science);
		break;
	case 2:
		SafeWrite8(0x41276A, 0xEB);
		break;
	}
}

static void BoostScriptDialogLimitPatch() {
	const DWORD script_dialog_msgs[] = {
		0x4A50C2, 0x4A5169, 0x4A52FA, 0x4A5302, 0x4A6B86, 0x4A6BE0, 0x4A6C37,
	};

	if (GetConfigInt("Misc", "BoostScriptDialogLimit", 0)) {
		const int scriptDialogCount = 10000;
		dlog("Applying script dialog limit patch.", DL_INIT);
		scriptDialog = new int[scriptDialogCount * 2]; // Because the msg structure is 8 bytes, not 4.
		SafeWrite32(0x4A50E3, scriptDialogCount); // scr_init
		SafeWrite32(0x4A519F, scriptDialogCount); // scr_game_init
		SafeWrite32(0x4A534F, scriptDialogCount * 8); // scr_message_free
		SafeWriteBatch<DWORD>((DWORD)scriptDialog, script_dialog_msgs); // scr_get_dialog_msg_file
		dlogr(" Done", DL_INIT);
	}
}

static void NumbersInDialoguePatch() {
	if (GetConfigInt("Misc", "NumbersInDialogue", 0)) {
		dlog("Applying numbers in dialogue patch.", DL_INIT);
		SafeWrite32(0x502C32, 0x2000202E);
		SafeWrite8(0x446F3B, 0x35);
		SafeWrite32(0x5029E2, 0x7325202E);
		SafeWrite32(0x446F03, 0x2424448B);        // mov  eax, [esp+0x24]
		SafeWrite8(0x446F07, 0x50);               // push eax
		SafeWrite32(0x446FE0, 0x2824448B);        // mov  eax, [esp+0x28]
		SafeWrite8(0x446FE4, 0x50);               // push eax
		MakeJump(0x4458F5, gdAddOptionStr_hack);
		dlogr(" Done", DL_INIT);
	}
}

static void InstantWeaponEquipPatch() {
	const DWORD PutAwayWeapon[] = {
		0x411EA2, // action_climb_ladder_
		0x412046, // action_use_an_item_on_object_
		0x41224A, // action_get_an_object_
		0x4606A5, // intface_change_fid_animate_
		0x472996, // invenWieldFunc_
	};

	if (GetConfigInt("Misc", "InstantWeaponEquip", 0)) {
		//Skip weapon equip/unequip animations
		dlog("Applying instant weapon equip patch.", DL_INIT);
		SafeWriteBatch<BYTE>(0xEB, PutAwayWeapon); // jmps
		BlockCall(0x472AD5); //
		BlockCall(0x472AE0); // invenUnwieldFunc_
		BlockCall(0x472AF0); //
		MakeJump(0x415238, register_object_take_out_hack);
		dlogr(" Done", DL_INIT);
	}
}

static void DontTurnOffSneakIfYouRunPatch() {
	if (GetConfigInt("Misc", "DontTurnOffSneakIfYouRun", 0)) {
		dlog("Applying DontTurnOffSneakIfYouRun patch.", DL_INIT);
		SafeWrite8(0x418135, 0xEB);
		dlogr(" Done", DL_INIT);
	}
}

static void PlayIdleAnimOnReloadPatch() {
	if (GetConfigInt("Misc", "PlayIdleAnimOnReload", 0)) {
		dlog("Applying idle anim on reload patch.", DL_INIT);
		HookCall(0x460B8C, intface_item_reload_hook);
		dlogr(" Done", DL_INIT);
	}
}

static void MotionScannerFlagsPatch() {
	if (long flags = GetConfigInt("Misc", "MotionScannerFlags", 1)) {
		dlog("Applying MotionScannerFlags patch.", DL_INIT);
		if (flags & 1) MakeJump(0x41BBE9, automap_hack);
		if (flags & 2) {
			// automap_
			SafeWrite16(0x41BC24, 0x9090);
			BlockCall(0x41BC3C);
			// item_m_use_charged_item_
			SafeWrite8(0x4794B3, 0x5E); // jbe short 0x479512
		}
		dlogr(" Done", DL_INIT);
	}
}

static void EncounterTableSizePatch() {
	const DWORD EncounterTableSize[] = {
		0x4BD1A3, 0x4BD1D9, 0x4BD270, 0x4BD604, 0x4BDA14, 0x4BDA44, 0x4BE707,
		0x4C0815, 0x4C0D4A, 0x4C0FD4,
	};

	DWORD tableSize = GetConfigInt("Misc", "EncounterTableSize", 0);
	if (tableSize > 40 && tableSize <= 127) {
		dlog("Applying EncounterTableSize patch.", DL_INIT);
		SafeWrite8(0x4BDB17, (BYTE)tableSize);
		DWORD nsize = (tableSize + 1) * 180 + 0x50;
		SafeWriteBatch<DWORD>(nsize, EncounterTableSize);
		dlogr(" Done", DL_INIT);
	}
}

static void DisablePipboyAlarmPatch() {
	if (GetConfigInt("Misc", "DisablePipboyAlarm", 0)) {
		dlog("Applying Disable Pip-Boy alarm button patch.", DL_INIT);
		SafeWrite8(0x499518, 0xC3);
		SafeWrite8(0x443601, 0x0);
		dlogr(" Done", DL_INIT);
	}
}

static void ObjCanSeeShootThroughPatch() {
	if (GetConfigInt("Misc", "ObjCanSeeObj_ShootThru_Fix", 0)) {
		dlog("Applying ObjCanSeeObj ShootThru Fix.", DL_INIT);
		HookCall(0x456BC6, op_obj_can_see_obj_hook);
		dlogr(" Done", DL_INIT);
	}
}

static const char* musicOverridePath = "data\\sound\\music\\";
static void OverrideMusicDirPatch() {
	if (long overrideMode = GetConfigInt("Sound", "OverrideMusicDir", 0)) {
		const DWORD musicOverride1Addr[] = {0x4449C2, 0x4449DB};
		SafeWriteBatch<DWORD>((DWORD)musicOverridePath, musicOverride1Addr);
		if (overrideMode == 2) {
			const DWORD musicOverride2Addr[] = {0x518E78, 0x518E7C};
			SafeWriteBatch<DWORD>((DWORD)musicOverridePath, musicOverride2Addr);
		}
	}
}

static void DialogueFix() {
	if (GetConfigInt("Misc", "DialogueFix", 1)) {
		dlog("Applying dialogue patch.", DL_INIT);
		SafeWrite8(0x446848, 0x31);
		dlogr(" Done", DL_INIT);
	}
}

static void AlwaysReloadMsgs() {
	if (GetConfigInt("Misc", "AlwaysReloadMsgs", 0)) {
		dlog("Applying always reload messages patch.", DL_INIT);
		SafeWrite8(0x4A6B8D, 0x0);
		dlogr(" Done", DL_INIT);
	}
}

static void RemoveWindowRoundingPatch() {
	if (GetConfigInt("Misc", "RemoveWindowRounding", 1)) {
		const DWORD windowRoundingAddr[] = {0x4D6EDD, 0x4D6F12};
		SafeWriteBatch<BYTE>(0xEB, windowRoundingAddr);
		//SafeWrite16(0x4B8090, 0x04EB); // jmps 0x4B8096 (old)
	}
}

static void InventoryCharacterRotationSpeedPatch() {
	long setting = GetConfigInt("Misc", "SpeedInventoryPCRotation", 166);
	if (setting != 166 && setting <= 1000) {
		dlog("Applying SpeedInventoryPCRotation patch.", DL_INIT);
		SafeWrite32(0x47066B, setting);
		dlogr(" Done", DL_INIT);
	}
}

static void UIAnimationSpeedPatch() {
	DWORD addrs[] = {
		0x45F9DE, 0x45FB33,
		0x447DF4, 0x447EB6,
		0x499B99, 0x499DA8
	};
	SimplePatch<WORD>(addrs, 2, "Misc", "CombatPanelAnimDelay", 1000, 0, 65535);
	SimplePatch<BYTE>(&addrs[2], 2, "Misc", "DialogPanelAnimDelay", 33, 0, 255);
	SimplePatch<BYTE>(&addrs[4], 2, "Misc", "PipboyTimeAnimDelay", 50, 0, 127);
}

static void MusicInDialoguePatch() {
	if (GetConfigInt("Misc", "EnableMusicInDialogue", 0)) {
		dlog("Applying music in dialogue patch.", DL_INIT);
		SafeWrite8(0x44525B, 0);
		//BlockCall(0x450627);
		dlogr(" Done", DL_INIT);
	}
}

static void DisplaySecondWeaponRangePatch() {
	// Display the range of the second attack mode in the inventory when you switch weapon modes in active item slots
	//if (GetConfigInt("Misc", "DisplaySecondWeaponRange", 1)) {
		dlog("Applying display second weapon range patch.", DL_INIT);
		HookCall(0x472201, display_stats_hook);
		dlogr(" Done", DL_INIT);
	//}
}

static void SkipLoadingGameSettingsPatch() {
	if (int skipLoading = GetConfigInt("Misc", "SkipLoadingGameSettings", 0)) {
		dlog("Applying skip loading game settings from saved games patch.", DL_INIT);
		BlockCall(0x493421);
		SafeWrite8(0x4935A8, 0x1F);
		SafeWrite32(0x4935AB, 0x90901B75);
		CodeData PatchData;
		if (skipLoading == 2) {
			const DWORD difficultyAddr[] = {0x49341C, 0x49343B};
			SafeWriteBatch<CodeData>(PatchData, difficultyAddr);
		}
		const DWORD settingsAddr[] = {
			0x493450, 0x493465, 0x49347A, 0x49348F, 0x4934A4, 0x4934B9, 0x4934CE,
			0x4934E3, 0x4934F8, 0x49350D, 0x493522, 0x493547, 0x493558, 0x493569,
			0x49357A
		};
		SafeWriteBatch<CodeData>(PatchData, settingsAddr);
		dlogr(" Done", DL_INIT);
	}
}

static void InterfaceDontMoveOnTopPatch() {
	if (GetConfigInt("Misc", "InterfaceDontMoveOnTop", 0)) { // TODO: remove option? (obsolete)
		dlog("Applying no MoveOnTop flag for interface patch.", DL_INIT);
		SafeWrite8(0x46ECE9, WIN_Exclusive); // Player Inventory/Loot/UseOn
		SafeWrite8(0x41B966, WIN_Exclusive); // Automap
		dlogr(" Done", DL_INIT);
	}
}

static void UseWalkDistancePatch() {
	int distance = GetConfigInt("Misc", "UseWalkDistance", 3) + 2;
	if (distance > 1 && distance < 5) {
		dlog("Applying walk distance for using objects patch.", DL_INIT);
		const DWORD walkDistanceAddr[] = {0x411FF0, 0x4121C4, 0x412475, 0x412906};
		SafeWriteBatch<BYTE>(distance, walkDistanceAddr); // default is 5
		dlogr(" Done", DL_INIT);
	}
}

static void F1EngineBehaviorPatch() {
	if (GetConfigInt("Misc", "Fallout1Behavior", 0)) {
		dlog("Applying Fallout 1 engine behavior patch.", DL_INIT);
		BlockCall(0x4A4343); // disable playing the final movie/credits after the endgame slideshow
		SafeWrite8(0x477C71, 0xEB); // disable halving the weight for power armor items
		HookCall(0x43F872, endgame_movie_hook); // play movie 10 or 11 based on the player's gender before the credits
		dlogr(" Done", DL_INIT);
	}
}

static void __declspec(naked) op_display_msg_hook() {
	__asm {
		cmp  dword ptr ds:_debug_func, 0;
		jne  debug;
		retn;
debug:
		jmp  config_get_value_;
	}
}

static void EngineOptimizationPatches() {
	// Speed up display_msg script function
	HookCall(0x455404, op_display_msg_hook);

	// Remove duplicate code from intface_redraw_ engine function
	BlockCall(0x45EBBF);

	// Improve performance of the data conversion of script interpreter
	// mov eax, [edx+eax]; bswap eax; ret;
	SafeWrite32(0x4672A4, 0x0F02048B);
	SafeWrite16(0x4672A8, 0xC3C8);
	// mov eax, [edx+eax]; bswap eax;
	SafeWrite32(0x4673E5, 0x0F02048B);
	SafeWrite8(0x4673E9, 0xC8);
	// mov ax, [eax]; rol ax, 8; ret;
	SafeWrite32(0x467292, 0x66008B66);
	SafeWrite32(0x467296, 0xC308C0C1);
}

void MiscPatchesInit() {
	EngineOptimizationPatches();

	if (GetConfigString("Misc", "StartingMap", "", mapName, 64)) {
		dlog("Applying starting map patch.", DL_INIT);
		SafeWrite32(0x480AAA, (DWORD)&mapName);
		dlogr(" Done", DL_INIT);
	}

	if (GetConfigString("Misc", "VersionString", "", versionString, 64)) {
		dlog("Applying version string patch.", DL_INIT);
		SafeWrite32(0x4B4588, (DWORD)&versionString);
		dlogr(" Done", DL_INIT);
	}

	if (GetConfigString("Misc", "ConfigFile", "", configName, 64)) {
		dlog("Applying config file patch.", DL_INIT);
		const DWORD configFileAddr[] = {0x444BA5, 0x444BCA};
		SafeWriteBatch<DWORD>((DWORD)&configName, configFileAddr);
		dlogr(" Done", DL_INIT);
	}

	if (GetConfigString("Misc", "PatchFile", "", patchName, 64)) {
		dlog("Applying patch file patch.", DL_INIT);
		SafeWrite32(0x444323, (DWORD)&patchName);
		dlogr(" Done", DL_INIT);
	}

	if (GetConfigInt("Misc", "SingleCore", 1)) {
		dlog("Applying single core patch.", DL_INIT);
		HANDLE process = GetCurrentProcess();
		SetProcessAffinityMask(process, 1);
		CloseHandle(process);
		dlogr(" Done", DL_INIT);
	}

	if (GetConfigInt("Misc", "OverrideArtCacheSize", 0)) {
		dlog("Applying override art cache size patch.", DL_INIT);
		SafeWrite32(0x418867, 0x90909090);
		SafeWrite32(0x418872, 256);
		dlogr(" Done", DL_INIT);
	}

	int time = GetConfigInt("Misc", "CorpseDeleteTime", 6); // time in days
	if (time != 6) {
		dlog("Applying corpse deletion time patch.", DL_INIT);
		if (time <= 0) {
			time = 12; // hours
		} else if (time > 13) {
			time = 13 * 24;
		} else {
			time *= 24;
		}
		SafeWrite32(0x483348, time);
		dlogr(" Done", DL_INIT);
	}

	SimplePatch<DWORD>(0x440C2A, "Misc", "SpecialDeathGVAR", 491); // GVAR_MODOC_SHITTY_DEATH

	// Remove hardcoding for maps with IDs 19 and 37
	if (GetConfigInt("Misc", "DisableSpecialMapIDs", 0)) {
		dlog("Applying disable special map IDs patch.", DL_INIT);
		const DWORD specialMapIdsAddr[] = {0x4836D6, 0x4836DB};
		SafeWriteBatch<BYTE>(0, specialMapIdsAddr);
		dlogr(" Done", DL_INIT);
	}

	// Highlight "Radiated" in red color when the player is under the influence of negative effects of radiation
	const DWORD listDrvdStatsAddr[] = {0x43549C, 0x4354BE};
	HookCalls(ListDrvdStats_hook, listDrvdStatsAddr);

	// Increase the max text width of the information card in the character screen
	const DWORD drawCardAddr[] = {0x43ACD5, 0x43DD37}; // 136, 133
	SafeWriteBatch<BYTE>(145, drawCardAddr);

	F1EngineBehaviorPatch();
	DialogueFix();
	AdditionalWeaponAnimsPatch();
	AlwaysReloadMsgs();
	PlayIdleAnimOnReloadPatch();

	SkilldexImagesPatch();
	RemoveWindowRoundingPatch();

	ScienceOnCrittersPatch();
	InventoryCharacterRotationSpeedPatch();

	dlogr("Patching out ereg call.", DL_INIT);
	BlockCall(0x4425E6);

	OverrideMusicDirPatch();
	BoostScriptDialogLimitPatch();
	MotionScannerFlagsPatch();
	EncounterTableSizePatch();

	DisablePipboyAlarmPatch();

	ObjCanSeeShootThroughPatch();
	UIAnimationSpeedPatch();
	MusicInDialoguePatch();
	DontTurnOffSneakIfYouRunPatch();

	InstantWeaponEquipPatch();
	NumbersInDialoguePatch();

	DisplaySecondWeaponRangePatch();

	SkipLoadingGameSettingsPatch();
	InterfaceDontMoveOnTopPatch();

	UseWalkDistancePatch();
}

void MiscPatchesExit() {
	if (scriptDialog) delete[] scriptDialog;
}
