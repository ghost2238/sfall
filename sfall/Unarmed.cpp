/*
 *    sfall
 *    Copyright (C) 2008-2021  The sfall team
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

#include <algorithm>

#include "main.h"
#include "FalloutEngine.h"

#include "DamageMod.h"

class Hits {
public:
	static const long count = 20;

private:
	struct HitsData {
		long reqLevel;    // intface_update_items_
		long reqSkill;
		long reqStat[7];
		long minDamage;   // default for all
		long maxDamage;   // default for all (maxDamage + STAT_melee_dmg)
		long bonusDamage; // item_w_damage_
		long bonusCrit;   // compute_attack_
		long apCost;      // item_w_mp_cost_
		bool isPenetrate; // compute_damage_
		bool isSecondary;

//		HitsData() : reqLevel(0), reqSkill(0), reqStat(), minDamage(1), maxDamage(2), bonusDamage(0), bonusCrit(0), costAP(3), isPenetrate(false), isSecondary(false) {}
		HitsData() {
			reqLevel = 0;
			reqSkill = 0;
			std::memset(reqStat, 0, sizeof(reqStat));
			minDamage = 1;
			maxDamage = 2;
			bonusDamage = 0;
			bonusCrit = 0;
			apCost = 3;
			isPenetrate = false;
			isSecondary = false;
		}
	};

	struct SortHits {
		BYTE level;
		BYTE hit; // index in Hits class
	};

	// sorted in descending order of the required stats in group hits
	SortHits sortHits[Hits::count - ATKTYPE_STRONGPUNCH];

	HitsData hit[Hits::count];

	long skillLevel; // SKILL_UNARMED_COMBAT
	long psStat[STAT_base_count];

public:
	class Types{
		public: enum : long {
			punch         = ATKTYPE_PUNCH,
			kick          = ATKTYPE_KICK,

			strong_punch  = ATKTYPE_STRONGPUNCH,
			hammer_punch,
			haymaker,
			jab,
			palm_strike,
			piercing_strike,

			strong_kick,
			snap_kick,
			power_kick,
			hip_kick,
			hook_kick,
			piercing_kick
		};
	};

	Hits() {
		// punch primary 1
		hit[Types::strong_punch].reqLevel = 1;
		hit[Types::strong_punch].reqSkill = 55;
		hit[Types::strong_punch].reqStat[STAT_ag] = 6;
		hit[Types::strong_punch].bonusDamage = 3;
		// primary 2
		hit[Types::hammer_punch].reqLevel = 6;
		hit[Types::hammer_punch].reqSkill = 75;
		hit[Types::hammer_punch].reqStat[STAT_st] = 5;
		hit[Types::hammer_punch].reqStat[STAT_ag] = 6;
		hit[Types::hammer_punch].bonusDamage = 5;
		hit[Types::hammer_punch].bonusCrit = 5;
		// primary 3
		hit[Types::haymaker].reqLevel = 9;
		hit[Types::haymaker].reqSkill = 100;
		hit[Types::haymaker].reqStat[STAT_st] = 5;
		hit[Types::haymaker].reqStat[STAT_ag] = 7;
		hit[Types::haymaker].bonusDamage = 7;
		hit[Types::haymaker].bonusCrit = 15;

		// punch secondary 1
		hit[Types::jab].reqLevel = 5;
		hit[Types::jab].reqSkill = 75;
		hit[Types::jab].reqStat[STAT_st] = 5;
		hit[Types::jab].reqStat[STAT_ag] = 7;
		hit[Types::jab].bonusDamage = 3;
		hit[Types::jab].bonusCrit = 10;
		hit[Types::jab].isSecondary = true;
		// secondary 2
		hit[Types::palm_strike].reqLevel = 12;
		hit[Types::palm_strike].reqSkill = 115;
		hit[Types::palm_strike].reqStat[STAT_st] = 5;
		hit[Types::palm_strike].reqStat[STAT_ag] = 7;
		hit[Types::palm_strike].bonusDamage = 7;
		hit[Types::palm_strike].bonusCrit = 20;
		hit[Types::palm_strike].apCost = 6;
		hit[Types::palm_strike].isPenetrate = true;
		hit[Types::palm_strike].isSecondary = true;
		// secondary 3
		hit[Types::piercing_strike].reqLevel = 16;
		hit[Types::piercing_strike].reqSkill = 130;
		hit[Types::piercing_strike].reqStat[STAT_st] = 5;
		hit[Types::piercing_strike].reqStat[STAT_ag] = 7;
		hit[Types::piercing_strike].bonusDamage = 10;
		hit[Types::piercing_strike].bonusCrit = 40;
		hit[Types::piercing_strike].apCost = 8;
		hit[Types::piercing_strike].isPenetrate = true;
		hit[Types::piercing_strike].isSecondary = true;

		// kick primary 1
		hit[Types::strong_kick].reqLevel = 1;
		hit[Types::strong_kick].reqSkill = 40;
		hit[Types::strong_kick].reqStat[STAT_ag] = 6;
		hit[Types::strong_kick].bonusDamage = 5;
		hit[Types::strong_kick].apCost = 4;
		// primary 2
		hit[Types::snap_kick].reqLevel = 6;
		hit[Types::snap_kick].reqSkill = 60;
		hit[Types::snap_kick].reqStat[STAT_ag] = 6;
		hit[Types::snap_kick].bonusDamage = 7;
		hit[Types::snap_kick].apCost = 4;
		// primary 3
		hit[Types::power_kick].reqLevel = 9;
		hit[Types::power_kick].reqSkill = 80;
		hit[Types::power_kick].reqStat[STAT_st] = 6;
		hit[Types::power_kick].reqStat[STAT_ag] = 6;
		hit[Types::power_kick].bonusDamage = 9;
		hit[Types::power_kick].bonusCrit = 5;
		hit[Types::power_kick].apCost = 4;

		// kick secondary 1
		hit[Types::hip_kick].reqLevel = 6;
		hit[Types::hip_kick].reqSkill = 60;
		hit[Types::hip_kick].reqStat[STAT_st] = 6;
		hit[Types::hip_kick].reqStat[STAT_ag] = 7;
		hit[Types::hip_kick].bonusDamage = 7;
		hit[Types::hip_kick].apCost = 7;
		hit[Types::hip_kick].isSecondary = true;
		// secondary 2
		hit[Types::hook_kick].reqLevel = 12;
		hit[Types::hook_kick].reqSkill = 100;
		hit[Types::hook_kick].reqStat[STAT_st] = 6;
		hit[Types::hook_kick].reqStat[STAT_ag] = 7;
		hit[Types::hook_kick].bonusDamage = 9;
		hit[Types::hook_kick].bonusCrit = 10;
		hit[Types::hook_kick].apCost = 7;
		hit[Types::hook_kick].isPenetrate = true;
		hit[Types::hook_kick].isSecondary = true;
		// secondary 3
		hit[Types::piercing_kick].reqLevel = 15;
		hit[Types::piercing_kick].reqSkill = 125;
		hit[Types::piercing_kick].reqStat[STAT_st] = 6;
		hit[Types::piercing_kick].reqStat[STAT_ag] = 8;
		hit[Types::piercing_kick].bonusDamage = 12;
		hit[Types::piercing_kick].bonusCrit = 50;
		hit[Types::piercing_kick].apCost = 9;
		hit[Types::piercing_kick].isPenetrate = true;
		hit[Types::piercing_kick].isSecondary = true;
	}

	HitsData& Hit(AttackType i) { return hit[i]; }

	// Get hit by index
	HitsData& Hit(size_t index) { return hit[index]; }

	AttackType GetSortHit(size_t index) { return (AttackType)sortHits[index].hit; }

	void Sort() {
		for (char i = ATKTYPE_STRONGPUNCH, j = 0; i < Hits::count; i++, j++) {
			sortHits[j].level = (char)hit[i].reqLevel;
			sortHits[j].hit = i;
		}

		auto greater_comp = [&](const SortHits &a, const SortHits &b) -> bool {
			if (a.level == b.level) {
				return hit[a.hit].reqSkill > hit[b.hit].reqSkill;
			}
			return a.level > b.level;
		};

		std::sort(&sortHits[0], &sortHits[6], greater_comp);
		std::sort(&sortHits[6], &sortHits[12], greater_comp);
	}

	void GetDudeStats(long sLevel) {
		skillLevel = sLevel;
		for (size_t stat = 0; stat < STAT_base_count; stat++) {
			psStat[stat] = fo_stat_level(*ptr_obj_dude, stat);
		}
	}

	long SkillLevel() { return skillLevel; }
	long DudeStat(long stat) { return psStat[stat]; }
};

Hits unarmed;

static bool UnarmedReqStats(AttackType hit) {
	if (unarmed.SkillLevel() >= unarmed.Hit(hit).reqSkill && (long)*ptr_Level_pc >= unarmed.Hit(hit).reqLevel) {
		for (size_t stat = 0; stat < STAT_base_count; stat++) {
			if (unarmed.Hit(hit).reqStat[stat] == 0) continue;
			if (unarmed.Hit(hit).reqStat[stat] > unarmed.DudeStat(stat)) {
				return false;
			}
		}
		return true;
	}
	return false;
}

static bool Punching(bool isPrimary) {
	for (size_t i = 0; i < 6; i++) {
		AttackType hit = unarmed.GetSortHit(i);
		if (unarmed.Hit(hit).isSecondary == isPrimary) continue;

		if (UnarmedReqStats(hit)) {
			if (unarmed.Hit(hit).isSecondary) {
				ptr_itemButtonItems[HANDSLOT_Left].secondaryAttack = hit;
			} else {
				ptr_itemButtonItems[HANDSLOT_Left].primaryAttack = hit;
			}
			return true;
		}
	}
	return false;
}

// Punch hits
static void __fastcall check_unarmed_left_slot(long skillLevel) {
	unarmed.GetDudeStats(skillLevel);

	if (!Punching(true))  ptr_itemButtonItems[HANDSLOT_Left].primaryAttack = ATKTYPE_PUNCH;
	if (!Punching(false)) ptr_itemButtonItems[HANDSLOT_Left].secondaryAttack = ATKTYPE_PUNCH;
}

static void __declspec(naked) intface_update_items_hack_punch() {
	__asm {
		push 0x45F1D7;
		jmp  check_unarmed_left_slot;
	}
}

static bool Kicking(bool isPrimary) {
	for (size_t i = 6; i < 12; i++) {
		AttackType hit = unarmed.GetSortHit(i);
		if (unarmed.Hit(hit).isSecondary == isPrimary) continue;

		if (UnarmedReqStats(hit)) {
			if (unarmed.Hit(hit).isSecondary) {
				ptr_itemButtonItems[HANDSLOT_Right].secondaryAttack = hit;
			} else {
				ptr_itemButtonItems[HANDSLOT_Right].primaryAttack = hit;
			}
			return true;
		}
	}
	return false;
}

// Kick hits
static void check_unarmed_right_slot() {
	if (!Kicking(true))  ptr_itemButtonItems[HANDSLOT_Right].primaryAttack = ATKTYPE_KICK;
	if (!Kicking(false)) ptr_itemButtonItems[HANDSLOT_Right].secondaryAttack = ATKTYPE_KICK;
}

static void __declspec(naked) intface_update_items_hack_kick() {
	__asm {
		push 0x45F380;
		jmp  check_unarmed_right_slot;
	}
}

static long __fastcall get_unarmed_crit_chance(long &chanceOut, AttackType hit) {
	chanceOut = unarmed.Hit(hit).bonusCrit;
	return (chanceOut > 0)
	       ? 0x4239F4  //
	       : 0x423A0D; // skip random roll
}

static void __declspec(naked) compute_attack_hack() {
	__asm {
		sub  esp, 4;
		mov  ecx, esp;                // chanceOut ref
		call get_unarmed_crit_chance; // edx - hit
		pop  ecx; // chance
		jmp  eax;
	}
}

static long __fastcall get_unarmed_damage(TGameObj* source, AttackType hit, long &minOut, long &maxOut) {
	minOut = unarmed.Hit(hit).minDamage + DamageMod_GetHtHMinDamageBonus(source);
	maxOut = unarmed.Hit(hit).maxDamage + fo_stat_level(source, STAT_melee_dmg);
	return unarmed.Hit(hit).bonusDamage;
}

static void __declspec(naked) item_w_damage_hack() {
	static DWORD item_w_damage_hack_ret = 0x478553;
	__asm {
		lea  eax, [esp + 4]; // min_DMG
		lea  edx, [esp + 0]; // max_DMG
		push ecx;
		push edx;      // maxOut ref
		push eax;      // minOut ref
		mov  edx, esi; // hit
		call get_unarmed_damage;
		mov  ebx, eax; // bonus
		pop  ecx;
		jmp  item_w_damage_hack_ret;
	}
}

static long __fastcall check_unarmed_penetrate(AttackType hit) {
	return static_cast<long>(unarmed.Hit(hit).isPenetrate);
}

long Unarmed_GetHitAPCost(AttackType hit) {
	return unarmed.Hit(hit).apCost;
}

////////////////////////////////////////////////////////////////////////////////

static void __declspec(naked) statPCAddExperienceCheckPMs_hook() {
	__asm {
		call intface_update_hit_points_;
		sub  esp, 8;
		lea  edx, [esp + 4]; // modeR
		mov  eax, esp;       // modeL
		call intface_get_item_states_;
		pop  edx;
		pop  ebx;
		xor  eax, eax;
		jmp  intface_update_items_;
	}
}

void Unarmed_Init() {
	// Update unarmed attack after leveling up
	HookCall(0x4AFC15, statPCAddExperienceCheckPMs_hook);

	unarmed = Hits();

	std::string unarmedFile = GetConfigString("Misc", "UnarmedFile", "", MAX_PATH);
	if (!unarmedFile.empty()) {
		const char* file = unarmedFile.insert(0, ".\\").c_str();
		if (GetFileAttributes(file) != INVALID_FILE_ATTRIBUTES) { // check if file exists
			char stat[6] = "Stat0";
			char sHit[4] = "0";
			for (size_t i = 0; i < Hits::count; _itoa(++i, sHit, 10)) {
				if (i < ATKTYPE_STRONGPUNCH && i != ATKTYPE_PUNCH && i != ATKTYPE_KICK) continue;

				auto& hit = unarmed.Hit(i);

				int val = IniGetInt(sHit, "ReqLevel", -1, file);
				if (val >= 0) hit.reqLevel = val;

				val =  IniGetInt(sHit, "SkillLevel", -1, file);
				if (val >= 0) hit.reqSkill = val;

				val = IniGetInt(sHit, "MinDamage", -1, file);
				if (val >= 0) hit.minDamage = val;

				val = IniGetInt(sHit, "MaxDamage", -1, file);
				if (val >= 0) hit.maxDamage = val;

				val = IniGetInt(sHit, "BonusDamage", -1, file);
				if (val >= 0) hit.bonusDamage = val;

				val = IniGetInt(sHit, "BonusCrit", -1, file);
				if (val >= 0) hit.bonusCrit = val;

				val = IniGetInt(sHit, "APCost", -1, file);
				if (val >= 0) hit.apCost = val;

				val = IniGetInt(sHit, "Penetrate", -1, file);
				if (val >= 0) hit.isPenetrate = (val != 0);

				val = IniGetInt(sHit, "Secondary", -1, file);
				if (val >= 0) hit.isSecondary = (val != 0);

				for (size_t s = 0; s < STAT_base_count; _itoa(++s, &stat[4], 10)) {
					val = IniGetInt(sHit, stat, -1, file);
					if (val >= 0) hit.reqStat[s] = val;
				}
				stat[4] = '0';
			}

			// Only if a custom file is used, otherwise use the engine function code
			MakeJump(0x45F0DF, intface_update_items_hack_punch);
			MakeJump(0x45F278, intface_update_items_hack_kick);
		}
	}
	unarmed.Sort();

	// Get critical chance hack
	MakeJump(0x42394D, compute_attack_hack);
	SafeWrite16(0x423A03, 0xC839); // cmp eax, 50 -> cmp eax, ecx
	SafeWrite8(0x423A05, CODETYPE_Nop);

	// Get damage hack
	MakeJump(0x478492, item_w_damage_hack);

	// compute_damage_ penetrate hack
	SafeWrite8(0x4248B4, 0x4E); // mov ecx, [hit]
	MakeCall(0x4248B6, check_unarmed_penetrate, 5);
	SafeWrite16(0x4248C1, 0x01F8); // cmp eax, 1
	SafeWrite8(0x4248C8, CODETYPE_JumpShort);
}

//void Unarmed_Exit() {
//}
