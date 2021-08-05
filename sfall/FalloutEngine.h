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

#pragma once

/*
 * FALLOUT2.EXE structs, function offsets and wrappers should be placed here
 *
 * only place functions and variables here which are likely to be used in more than one module
 *
 */

#include <stdint.h>

#include "Define.h"
#include "FalloutStructs.h"

// Global variable offsets
// TODO: probably need to hide these by moving inside implementation file

#define FO_VAR_aDialogS_msg               0x50DBE8
#define FO_VAR_aiInfoList                 0x510948
#define FO_VAR_ambient_light              0x51923C
#define FO_VAR_anim_set                   0x54CC14
#define FO_VAR_anon_alias                 0x56CAEC
#define FO_VAR_art                        0x510738
#define FO_VAR_art_name                   0x56C9E4
#define FO_VAR_art_vault_guy_num          0x5108A4
#define FO_VAR_art_vault_person_nums      0x5108A8
#define FO_VAR_artCritterFidShouldRunData 0x56CAF0
#define FO_VAR_aTextSCuts                 0x501A8C
#define FO_VAR_aTextSCutsS                0x503530
#define FO_VAR_aTextSCutsSS               0x50B01C
#define FO_VAR_background_fname_requested 0x596FC2
#define FO_VAR_background_volume          0x518E88
#define FO_VAR_bboxslot                   0x5970E0
#define FO_VAR_bckgnd                     0x5707A4
#define FO_VAR_bk_disabled                0x6AC780
#define FO_VAR_black_palette              0x663FD0
#define FO_VAR_bottom_line                0x664524
#define FO_VAR_btable                     0x59E944
#define FO_VAR_btncnt                     0x43EA1C
#define FO_VAR_cap                        0x518064
#define FO_VAR_carCurrentArea             0x672E68
#define FO_VAR_carGasAmount               0x672E6C
#define FO_VAR_card_old_fid1              0x5709EC
#define FO_VAR_character_points           0x518538
#define FO_VAR_cmap                       0x51DF34
#define FO_VAR_colorTable                 0x6A38D0
#define FO_VAR_combat_end_due_to_load     0x517F98
#define FO_VAR_combat_free_move           0x56D39C
#define FO_VAR_combat_list                0x56D390
#define FO_VAR_combat_state               0x510944
#define FO_VAR_combat_turn_running        0x51093C
#define FO_VAR_combatNumTurns             0x510940
#define FO_VAR_crit_succ_eff              0x510978
#define FO_VAR_critter_db_handle          0x58E94C
#define FO_VAR_critterClearObj            0x518438
#define FO_VAR_crnt_func                  0x664508
#define FO_VAR_cur_id                     0x51C7D4
#define FO_VAR_curr_anim_set              0x51071C
#define FO_VAR_curr_anim_counter          0x56C7DC 
#define FO_VAR_curr_font_num              0x51E3B0
#define FO_VAR_curr_pc_stat               0x6681AC
#define FO_VAR_curr_stack                 0x59E96C
#define FO_VAR_currentProgram             0x59E78C
#define FO_VAR_currentWindow              0x51DCB8
#define FO_VAR_cursor_line                0x664514
#define FO_VAR_debug_func                 0x51DF04
#define FO_VAR_dialog_red_button_down_buf 0x58F4A4
#define FO_VAR_dialog_red_button_down_key 0x58F4BC
#define FO_VAR_dialog_red_button_up_buf   0x58F4AC
#define FO_VAR_dialog_red_button_up_key   0x58F46C
#define FO_VAR_dialog_target              0x518848
#define FO_VAR_dialog_target_is_party     0x51884C
#define FO_VAR_dialogue_head              0x518850
#define FO_VAR_dialogue_state             0x518714
#define FO_VAR_dialogue_switch_mode       0x518718
#define FO_VAR_dialogueBackWindow         0x518740
#define FO_VAR_dialogueWindow             0x518744
#define FO_VAR_display_win                0x631E4C
#define FO_VAR_displayMapList             0x41B560
#define FO_VAR_doing_refresh_all          0x6ADF38
#define FO_VAR_dropped_explosive          0x5190E0
#define FO_VAR_drugInfoList               0x5191CC
#define FO_VAR_edit_win                   0x57060C
#define FO_VAR_Educated                   0x57082C
#define FO_VAR_elevation                  0x631D2C
#define FO_VAR_endgame_subtitle_done      0x570BD0
#define FO_VAR_endgame_subtitle_characters 0x51866C
#define FO_VAR_endgame_voiceover_loaded   0x570AB8
#define FO_VAR_Experience_                0x6681B4
#define FO_VAR_fallout_config             0x50281C
#define FO_VAR_fallout_game_time          0x51C720
#define FO_VAR_fidgetFID                  0x5186F4
#define FO_VAR_fidgetFp                   0x5186FC
#define FO_VAR_flptr                      0x614808
#define FO_VAR_folder_card_desc           0x5705CC
#define FO_VAR_folder_card_fid            0x5705B0
#define FO_VAR_folder_card_title          0x5705B8
#define FO_VAR_folder_card_title2         0x5705BC
#define FO_VAR_frame_time                 0x5709C4
#define FO_VAR_free_perk                  0x570A29
#define FO_VAR_freePtr                    0x519594
#define FO_VAR_frstc_draw1                0x5707D8
#define FO_VAR_game_config                0x58E950
#define FO_VAR_game_global_vars           0x5186C0
#define FO_VAR_game_ui_disabled           0x5186B4
#define FO_VAR_game_user_wants_to_quit    0x5186CC
#define FO_VAR_gconfig_file_name          0x58E978
#define FO_VAR_gcsd                       0x51094C
#define FO_VAR_gdBarterMod                0x51873C
#define FO_VAR_gdialog_speech_playing     0x518710
#define FO_VAR_gDialogMusicVol            0x5187D8
#define FO_VAR_gdNumOptions               0x5186D8
#define FO_VAR_gIsSteal                   0x51D430
#define FO_VAR_glblmode                   0x5709D0
#define FO_VAR_gmouse_3d_current_mode     0x518D38
#define FO_VAR_gmouse_current_cursor      0x518C0C
#define FO_VAR_gmovie_played_list         0x596C78
#define FO_VAR_GNW_win_init_flag          0x51E3E0
#define FO_VAR_GNW95_isActive             0x51E444
#define FO_VAR_GNWWin                     0x5195B8
#define FO_VAR_gsound_background_fade     0x518E40
#define FO_VAR_gsound_initialized         0x518E30
#define FO_VAR_gsound_speech_tag          0x518E54
#define FO_VAR_hit_location_penalty       0x510954
#define FO_VAR_holo_flag                  0x664529
#define FO_VAR_holodisk                   0x6644F4
#define FO_VAR_holopages                  0x66445C
#define FO_VAR_hot_line_count             0x6644F8
#define FO_VAR_i_fid                      0x59E95C
#define FO_VAR_i_lhand                    0x59E958
#define FO_VAR_i_rhand                    0x59E968
#define FO_VAR_i_wid                      0x59E964
#define FO_VAR_i_worn                     0x59E954
#define FO_VAR_idle_func                  0x51E234
#define FO_VAR_In_WorldMap                0x672E1C
#define FO_VAR_info_line                  0x5707D0
#define FO_VAR_interfaceWindow            0x519024
#define FO_VAR_intfaceEnabled             0x518F10
#define FO_VAR_intotal                    0x43E95C
#define FO_VAR_inven_dude                 0x519058
#define FO_VAR_inven_pid                  0x51905C
#define FO_VAR_inven_scroll_dn_bid        0x5190E8
#define FO_VAR_inven_scroll_up_bid        0x5190E4
#define FO_VAR_inventry_message_file      0x59E814
#define FO_VAR_itemButtonItems            0x5970F8
#define FO_VAR_itemCurrentItem            0x518F78
#define FO_VAR_kb_lock_flags              0x51E2EA
#define FO_VAR_language                   0x56C970  // aka _darn_foreign_sub_path
#define FO_VAR_last_buttons               0x51E2AC
#define FO_VAR_last_button_winID          0x51E404
#define FO_VAR_last_level                 0x5707B4
#define FO_VAR_lastMovieH                 0x638E64
#define FO_VAR_lastMovieW                 0x638E68
#define FO_VAR_lastWin                    0x51DD80
#define FO_VAR_Level_                     0x6681B0
#define FO_VAR_Lifegiver                  0x570854
#define FO_VAR_lips_draw_head             0x519248
#define FO_VAR_lipsFID                    0x518704
#define FO_VAR_list_com                   0x56D394
#define FO_VAR_list_total                 0x56D37C
#define FO_VAR_loadingGame                0x5194C4
#define FO_VAR_LSData                     0x613D30
#define FO_VAR_lsgwin                     0x6142C4
#define FO_VAR_main_ctd                   0x56D2B0
#define FO_VAR_main_death_voiceover_done  0x614838
#define FO_VAR_main_window                0x5194F0
#define FO_VAR_map_elevation              0x519578
#define FO_VAR_map_global_vars            0x51956C
#define FO_VAR_map_name                   0x631D58
#define FO_VAR_map_number                 0x631D88
#define FO_VAR_map_state                  0x631D28
#define FO_VAR_mapEntranceElevation       0x519558
#define FO_VAR_mapEntranceTileNum         0x51955C
#define FO_VAR_master_db_handle           0x58E948
#define FO_VAR_master_volume              0x518E84
#define FO_VAR_max                        0x56FB50
#define FO_VAR_maxScriptNum               0x51C7CC
#define FO_VAR_Meet_Frank_Horrigan        0x672E04
#define FO_VAR_Move_on_Car                0x672E64
#define FO_VAR_mouse_buttons              0x6AC7B0
#define FO_VAR_mouse_hotx                 0x6AC7D0
#define FO_VAR_mouse_hoty                 0x6AC7CC
#define FO_VAR_mouse_is_hidden            0x6AC790
#define FO_VAR_mouse_x_                   0x6AC7A8
#define FO_VAR_mouse_y                    0x664450
#define FO_VAR_mouse_y_                   0x6AC7A4
#define FO_VAR_movie_list                 0x518DA0
#define FO_VAR_Mutate_                    0x5708B4
#define FO_VAR_name_color                 0x56D744
#define FO_VAR_name_font                  0x56D74C
#define FO_VAR_name_sort_list             0x56FCB0
#define FO_VAR_num_caps                   0x518060
#define FO_VAR_num_game_global_vars       0x5186C4
#define FO_VAR_num_map_global_vars        0x519574
#define FO_VAR_num_windows                0x6ADF24
#define FO_VAR_obj_dude                   0x6610B8
#define FO_VAR_obj_seen                   0x662445
#define FO_VAR_objectTable                0x639DA0
#define FO_VAR_objItemOutlineState        0x519798
#define FO_VAR_optionRect                 0x58ECC0
#define FO_VAR_optionsButtonDown          0x59D400
#define FO_VAR_optionsButtonDown1         0x570518
#define FO_VAR_optionsButtonDownKey       0x518F2C
#define FO_VAR_optionsButtonUp            0x59D3FC
#define FO_VAR_optionsButtonUp1           0x570514
#define FO_VAR_optionsButtonUpKey         0x518F28
#define FO_VAR_optnwin                    0x663900
#define FO_VAR_outlined_object            0x518D94
#define FO_VAR_pal                        0x56D7E0
#define FO_VAR_partyMemberAIOptions       0x519DB8
#define FO_VAR_partyMemberCount           0x519DAC
#define FO_VAR_partyMemberLevelUpInfoList 0x519DBC
#define FO_VAR_partyMemberList            0x519DA8 // each struct - 4 integers, first integer - objPtr
#define FO_VAR_partyMemberMaxCount        0x519D9C
#define FO_VAR_partyMemberPidList         0x519DA0
#define FO_VAR_patches                    0x5193CC
#define FO_VAR_paths                      0x6B24D0
#define FO_VAR_pc_crit_succ_eff           0x5179B0
#define FO_VAR_pc_kill_counts             0x56D780
#define FO_VAR_pc_name                    0x56D75C
#define FO_VAR_pc_proto                   0x51C370
#define FO_VAR_pc_trait                   0x66BE40
#define FO_VAR_pc_trait2                  0x66BE44
#define FO_VAR_perk_data                  0x519DCC
#define FO_VAR_perkLevelDataList          0x51C120
#define FO_VAR_pip_win                    0x6644C4
#define FO_VAR_pipboy_message_file        0x664348
#define FO_VAR_pipmesg                    0x664338
#define FO_VAR_preload_list_index         0x519640
#define FO_VAR_procTableStrs              0x51C758  // table of procId (from define.h) => procName map
#define FO_VAR_proto_main_msg_file        0x6647FC
#define FO_VAR_proto_msg_files            0x6647AC
#define FO_VAR_protoLists                 0x51C290
#define FO_VAR_ptable                     0x59E934
#define FO_VAR_pud                        0x59E960
#define FO_VAR_quest_count                0x51C12C
#define FO_VAR_quests                     0x51C128
#define FO_VAR_queue                      0x6648C0
#define FO_VAR_quick_done                 0x5193BC
#define FO_VAR_read_callback              0x51DEEC
#define FO_VAR_rectList                   0x51DEF4
#define FO_VAR_retvals                    0x43EA7C
#define FO_VAR_rm_FrameCount              0x6B36A8
#define FO_VAR_rotation                   0x631D34
#define FO_VAR_sad                        0x530014
#define FO_VAR_sampleRate                 0x66815C
#define FO_VAR_scr_blit                   0x6ACA18
#define FO_VAR_scr_size                   0x6AC9F0
#define FO_VAR_screen_buffer              0x51E3FC
#define FO_VAR_script_engine_running      0x51C714
#define FO_VAR_scriptListInfo             0x51C7C8
#define FO_VAR_skill_data                 0x51D118
#define FO_VAR_skldxwin                   0x668140
#define FO_VAR_slot_cursor                0x5193B8
#define FO_VAR_sndfx_volume               0x518E90
#define FO_VAR_sneak_working              0x56D77C // DWORD var
#define FO_VAR_sound_music_path1          0x518E78
#define FO_VAR_sound_music_path2          0x518E7C
#define FO_VAR_speech_volume              0x518E8C
#define FO_VAR_square                     0x631E40
#define FO_VAR_squares                    0x66BE08
#define FO_VAR_stack                      0x59E86C
#define FO_VAR_stack_offset               0x59E844
#define FO_VAR_stat_data                  0x51D53C
#define FO_VAR_stat_flag                  0x66452A
#define FO_VAR_subtitleList               0x638E74
#define FO_VAR_subtitles                  0x663974
#define FO_VAR_sWindows                   0x6727B0
#define FO_VAR_Tag_                       0x5708B0
#define FO_VAR_tag_skill                  0x668070
#define FO_VAR_target_curr_stack          0x59E948
#define FO_VAR_target_pud                 0x59E978
#define FO_VAR_target_stack               0x59E81C
#define FO_VAR_target_stack_offset        0x59E7EC
#define FO_VAR_target_str                 0x56D518
#define FO_VAR_target_xpos                0x672E20
#define FO_VAR_target_ypos                0x672E24
#define FO_VAR_text_char_width            0x51E3C4
#define FO_VAR_text_height                0x51E3BC
#define FO_VAR_text_max                   0x51E3D4
#define FO_VAR_text_mono_width            0x51E3C8
#define FO_VAR_text_object_index          0x51D944
#define FO_VAR_text_object_list           0x6681C0
#define FO_VAR_text_spacing               0x51E3CC
#define FO_VAR_text_to_buf                0x51E3B8
#define FO_VAR_text_width                 0x51E3C0
#define FO_VAR_tile                       0x631D30
#define FO_VAR_title_color                0x56D750
#define FO_VAR_title_font                 0x56D748
#define FO_VAR_trait_data                 0x51DB84
#define FO_VAR_use_language               0x510898  // aka _darn_foreigners
#define FO_VAR_view_page                  0x664520
#define FO_VAR_wd_obj                     0x59E98C
#define FO_VAR_window                     0x6ADE58
#define FO_VAR_window_index               0x6ADD90
#define FO_VAR_wmAreaInfoList             0x51DDF8
#define FO_VAR_wmBkWin                    0x51DE14
#define FO_VAR_wmBkWinBuf                 0x51DE24
#define FO_VAR_wmEncounterIconShow        0x672E48
#define FO_VAR_wmLastRndTime              0x51DEA0
#define FO_VAR_wmMaxAreaNum               0x51DDFC
#define FO_VAR_wmMaxMapNum                0x51DE10
#define FO_VAR_wmMsgFile                  0x672FB0
#define FO_VAR_wmNumHorizontalTiles       0x51DDF4
#define FO_VAR_wmRndCursorFid             0x672E58
#define FO_VAR_wmWorldOffsetX             0x51DE2C
#define FO_VAR_wmWorldOffsetY             0x51DE30
#define FO_VAR_wmYesNoStrs                0x51DD90
#define FO_VAR_world_subtile              0x672E14
#define FO_VAR_world_xpos                 0x672E0C
#define FO_VAR_world_ypos                 0x672E10
#define FO_VAR_WorldMapCurrArea           0x672E08

// colors
#define FO_VAR_BlueColor                  0x6A38EF
#define FO_VAR_DARK_GREY_Color            0x6A59D8
#define FO_VAR_DarkGreenColor             0x6A3A90
#define FO_VAR_DarkGreenGreyColor         0x6A3DF1
#define FO_VAR_DarkRedColor               0x6AA8D0
#define FO_VAR_DarkYellowColor            0x6AB472
#define FO_VAR_DullPinkColor              0x6AB718
#define FO_VAR_GoodColor                  0x6AB4EF
#define FO_VAR_GreenColor                 0x6A3CB0
#define FO_VAR_LIGHT_GREY_Color           0x6A76BF
#define FO_VAR_LIGHT_RED_Color            0x6AB61A
#define FO_VAR_PeanutButter               0x6A82F3
#define FO_VAR_RedColor                   0x6AB4D0
#define FO_VAR_WhiteColor                 0x6AB8CF
#define FO_VAR_YellowColor                0x6AB8BB // Light

// Global variable pointers
// TODO: move to separate namespace

// defines pointer to an engine variable
#define PTR_(name, type)	\
	extern type* ptr_##name;

// X-Macros pattern
#include "FalloutVars_def.h"


/*
 * HOW TO USE ENGINE FUNCTIONS:
 *
 * in ASM code, call offsets directly, don't call wrappers as they might not be __stdcall
 * in C++ code, use wrappers (add new ones if the don't exist yet, see FalloutFuncs_def.h)
 *
 * Note: USE C++!
 * 1) Place thin __declspec(naked) hooks, only use minimum ASM to pass values to/from C++
 * 2) Call __stdcall functions from (1), write those entirely in C++ (with little ASM blocks only to call engine functions, when you are too lazy to add wrapper)
 */

// ENGINE FUNCTION OFFSETS
// TODO: move to separate namespace

#define FUNC(name, addr) extern const DWORD name;

#include "FalloutFuncOffs_def.h"

#undef FUNC

// WRAPPERS
// TODO: move these to different namespace

#ifndef NDEBUG
// Prints debug message to game debug.log file for develop build
void dev_printf(const char* fmt, ...);
#else
void dev_printf(...);
#endif

/*
	Add functions here if they have non-trivial wrapper implementation (like vararg functions or too many arguments, etc.)
	Otherwise use FalloutFuncs_def.h file (much easier).
*/

// prints message to debug.log file
void __declspec() fo_debug_printf(const char* fmt, ...);

void __stdcall fo_interpretReturnValue(TProgram* scriptPtr, DWORD val, DWORD valType);

// prints scripting error in debug.log and stops current script execution by performing longjmp
// USE WITH CAUTION
void __declspec() fo_interpretError(const char* fmt, ...);

long __stdcall fo_tile_num(long x, long y);

TGameObj* __fastcall obj_blocking_at_wrapper(TGameObj* obj, DWORD tile, DWORD elevation, void* func);

// Creates a button on a given window
// buttonType: 0x10 = move window pos, 0x20 or 0x0 = regular click, 0x23 = toggle click
// pictureUp/pictureDown - pointers to a surface
long __stdcall fo_win_register_button(DWORD winRef, long xPos, long yPos, long width, long height, long hoverOn, long hoverOff, long buttonDown, long buttonUp, BYTE* pictureUp, BYTE* pictureDown, long arg12, long buttonType);

void __stdcall DialogOut(const char* text);

long __fastcall DialogOutEx(const char* text, const char** textEx, long lines, long flags, long colors = 0);

// draws an image to the buffer without scaling and with transparency display toggle
void __fastcall fo_windowDisplayBuf(long x, long width, long y, long height, void* data, long noTrans);

// draws an image in the window and scales it to fit the window
void __fastcall fo_displayInWindow(long w_here, long width, long height, void* data);

// draws an image to the buffer of the active script window
void __fastcall window_trans_cscale(long i_width, long i_height, long s_width, long s_height, long xy_shift, long w_width, void* data);

// buf_to_buf_ function with pure MMX implementation
void __cdecl fo_buf_to_buf(BYTE* src, long width, long height, long src_width, BYTE* dst, long dst_width);

// trans_buf_to_buf_ function implementation
void __cdecl fo_trans_buf_to_buf(BYTE* src, long width, long height, long src_width, BYTE* dst, long dst_width);

BYTE* __fastcall fo_loadPCX(const char* file, long* width, long* height);

long __fastcall fo_get_game_config_string(const char** outValue, const char* section, const char* param);

// X-Macro for wrapper functions.
#define WRAP_WATCOM_FUNC0(retType, name) \
	retType __stdcall fo_##name();

#define WRAP_WATCOM_FUNC1(retType, name, arg1t, arg1) \
	retType __stdcall fo_##name(arg1t arg1);

#define WRAP_WATCOM_FUNC2(retType, name, arg1t, arg1, arg2t, arg2) \
	retType __stdcall fo_##name(arg1t arg1, arg2t arg2);

#define WRAP_WATCOM_FUNC3(retType, name, arg1t, arg1, arg2t, arg2, arg3t, arg3) \
	retType __stdcall fo_##name(arg1t arg1, arg2t arg2, arg3t arg3);

#define WRAP_WATCOM_FUNC4(retType, name, arg1t, arg1, arg2t, arg2, arg3t, arg3, arg4t, arg4) \
	retType __stdcall fo_##name(arg1t arg1, arg2t arg2, arg3t arg3, arg4t arg4);

#define WRAP_WATCOM_FUNC5(retType, name, arg1t, arg1, arg2t, arg2, arg3t, arg3, arg4t, arg4, arg5t, arg5) \
	retType __stdcall fo_##name(arg1t arg1, arg2t arg2, arg3t arg3, arg4t arg4, arg5t arg5);

#define WRAP_WATCOM_FUNC6(retType, name, arg1t, arg1, arg2t, arg2, arg3t, arg3, arg4t, arg4, arg5t, arg5, arg6t, arg6) \
	retType __stdcall fo_##name(arg1t arg1, arg2t arg2, arg3t arg3, arg4t arg4, arg5t arg5, arg6t arg6);


#define WRAP_WATCOM_FFUNC1(retType, name, arg1t, arg1) \
	retType __fastcall fo_##name(arg1t arg1);

#define WRAP_WATCOM_FFUNC2(retType, name, arg1t, arg1, arg2t, arg2) \
	retType __fastcall fo_##name(arg1t arg1, arg2t arg2);

#define WRAP_WATCOM_FFUNC3(retType, name, arg1t, arg1, arg2t, arg2, arg3t, arg3) \
	retType __fastcall fo_##name(arg1t arg1, arg2t arg2, arg3t arg3);

#define WRAP_WATCOM_FFUNC4(retType, name, arg1t, arg1, arg2t, arg2, arg3t, arg3, arg4t, arg4) \
	retType __fastcall fo_##name(arg1t arg1, arg2t arg2, arg3t arg3, arg4t arg4);

#define WRAP_WATCOM_FFUNC5(retType, name, arg1t, arg1, arg2t, arg2, arg3t, arg3, arg4t, arg4, arg5t, arg5) \
	retType __fastcall fo_##name(arg1t arg1, arg2t arg2, arg3t arg3, arg4t arg4, arg5t arg5);

#define WRAP_WATCOM_FFUNC6(retType, name, arg1t, arg1, arg2t, arg2, arg3t, arg3, arg4t, arg4, arg5t, arg5, arg6t, arg6) \
	retType __fastcall fo_##name(arg1t arg1, arg2t arg2, arg3t arg3, arg4t arg4, arg5t arg5, arg6t arg6);

#define WRAP_WATCOM_FFUNC7(retType, name, arg1t, arg1, arg2t, arg2, arg3t, arg3, arg4t, arg4, arg5t, arg5, arg6t, arg6, arg7t, arg7) \
	retType __fastcall fo_##name(arg1t arg1, arg2t arg2, arg3t arg3, arg4t arg4, arg5t arg5, arg6t arg6, arg7t arg7);

#define WRAP_WATCOM_FFUNC8(retType, name, arg1t, arg1, arg2t, arg2, arg3t, arg3, arg4t, arg4, arg5t, arg5, arg6t, arg6, arg7t, arg7, arg8t, arg8) \
	retType __fastcall fo_##name(arg1t arg1, arg2t arg2, arg3t arg3, arg4t arg4, arg5t arg5, arg6t arg6, arg7t arg7, arg8t arg8);

#define WRAP_WATCOM_FFUNC9(retType, name, arg1t, arg1, arg2t, arg2, arg3t, arg3, arg4t, arg4, arg5t, arg5, arg6t, arg6, arg7t, arg7, arg8t, arg8, arg9t, arg9) \
	retType __fastcall fo_##name(arg1t arg1, arg2t arg2, arg3t arg3, arg4t arg4, arg5t arg5, arg6t arg6, arg7t arg7, arg8t arg8, arg9t arg9);

#include "FalloutFuncs_def.h"

#undef WRAP_WATCOM_FUNC0
#undef WRAP_WATCOM_FUNC1
#undef WRAP_WATCOM_FUNC2
#undef WRAP_WATCOM_FUNC3
#undef WRAP_WATCOM_FUNC4
#undef WRAP_WATCOM_FUNC5
#undef WRAP_WATCOM_FUNC6
//#undef WRAP_WATCOM_FUNC7

#undef WRAP_WATCOM_FFUNC1
#undef WRAP_WATCOM_FFUNC2
#undef WRAP_WATCOM_FFUNC3
#undef WRAP_WATCOM_FFUNC4
#undef WRAP_WATCOM_FFUNC5
#undef WRAP_WATCOM_FFUNC6
#undef WRAP_WATCOM_FFUNC7
#undef WRAP_WATCOM_FFUNC8
#undef WRAP_WATCOM_FFUNC9

///////////////////////////////// ENGINE UTILS /////////////////////////////////

// rect_free_ function for inline implementation
__forceinline void sf_rect_free(RectList* rect) {
	RectList* front = *ptr_rectList;
	*ptr_rectList = rect;
	rect->nextRect = front;
}

// returns message string from given file or "Error" when not found
const char* GetMessageStr(const MSGList* fileAddr, long messageId);

// similar to GetMessageStr, but returns nullptr when no message is found
const char* MessageSearch(const MSGList* fileAddr, long messageId);

MSGNode* GetMsgNode(MSGList* msgList, int msgNum);

char* GetMsg(MSGList* msgList, int msgNum, int msgType);

Queue* QueueFind(TGameObj* object, long type);

// returns weapon animation code
long AnimCodeByWeapon(TGameObj* weapon);

bool CheckProtoID(DWORD pid);

// returns False if the prototype does not exist, or pointer to prototype by PID in the outProto argument
bool GetProto(long pid, sProto** outProto);

// returns pointer to prototype by PID
// Note: use this function if you need to get the proto immediately without extra checks
__forceinline sProto* GetProto(long pid) {
	sProto* proto;
	fo_proto_ptr(pid, &proto);
	return proto;
}

// wrapper for skill_get_tags with bounds checking
void SkillGetTags(long* result, long num);

// wrapper for skill_set_tags with bounds checking
void SkillSetTags(long* tags, long num);

long GetItemType(TGameObj* item);

__declspec(noinline) TGameObj* __stdcall GetItemPtrSlot(TGameObj* critter, InvenType slot);

long& GetActiveItemMode();

TGameObj* GetActiveItem();

AttackSubType GetWeaponType(DWORD weaponFlag);

bool HeroIsFemale();

// Checks whether the player is under the influence of negative effects of radiation
long __fastcall IsRadInfluence();

// Returns the number of local variables of the object script
long GetScriptLocalVars(long sid);

// Returns window by x/y coordinate (hidden windows are ignored)
WINinfo* __fastcall GetTopWindowAtPos(long xPos, long yPos, bool bypassTrans = false);

// Returns an array of objects within the specified radius from the source tile
void GetObjectsTileRadius(std::vector<TGameObj*> &objs, long sourceTile, long radius, long elev, long type = -1);

// Checks the blocking tiles and returns the first blocking object
TGameObj* CheckAroundBlockingTiles(TGameObj* source, long dstTile);

TGameObj* __fastcall MultiHexMoveIsBlocking(TGameObj* source, long dstTile);

long wmGetCurrentTerrainType();

void SurfaceCopyToMem(long fromX, long fromY, long width, long height, long fromWidth, BYTE* fromSurface, BYTE* toMem);

void DrawToSurface(long toX, long toY, long width, long height, long toWidth, long toHeight, BYTE* toSurface, BYTE* fromMem);

void DrawToSurface(long width, long height, long fromX, long fromY, long fromWidth, BYTE* fromSurf, long toX, long toY, long toWidth, long toHeight, BYTE* toSurf, int maskRef);

void DrawToSurface(long width, long height, long fromX, long fromY, long fromWidth, BYTE* fromSurf, long toX, long toY, long toWidth, long toHeight, BYTE* toSurf);

// Fills the specified interface window with index color
bool __stdcall WinFillRect(long winID, long x, long y, long width, long height, BYTE indexColor);

// Fills the specified interface window with index color 0 (black color)
void ClearWindow(long winID, bool refresh = true);

void PrintFloatText(TGameObj* object, const char* text, long colorText, long colorOutline = 207, long font = 101);

// Print text to surface
void __stdcall PrintText(char* displayText, BYTE colorIndex, DWORD xPos, DWORD yPos, DWORD txtWidth, DWORD toWidth, BYTE* toSurface);
void __stdcall PrintTextFM(const char* displayText, BYTE colorIndex, DWORD xPos, DWORD yPos, DWORD txtWidth, DWORD toWidth, BYTE* toSurface);

// gets the height of the currently selected font
DWORD __stdcall GetTextHeight();

// gets the length of a string using the currently selected font
DWORD __stdcall GetTextWidth(const char* textMsg);
DWORD __stdcall GetTextWidthFM(const char* textMsg);

// get width of Char for current font
DWORD __stdcall GetCharWidth(char charVal);
DWORD __stdcall GetCharWidthFM(char charVal);

// get maximum string length for current font - if all characters were maximum width
DWORD __stdcall GetMaxTextWidth(const char* textMsg);

// get number of pixels between characters for current font
DWORD __stdcall GetCharGapWidth();

// get maximum character width for current font
DWORD __stdcall GetMaxCharWidth();

// Redraw the given object on screen (does not always redraws the whole object)
void RedrawObject(TGameObj* obj);

// Redraws all windows
void RefreshGNW(bool skipOwner = false);

UNLSTDfrm *LoadUnlistedFrm(char *frmName, unsigned int folderRef);
