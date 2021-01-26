// List of all engine variables and their types.
// Used to generate ptr_varname pointers.

PTR_(aiInfoList,                 DWORD)
PTR_(ambient_light,              DWORD)
PTR_(art,                        sArt) // array of 11 sArt
PTR_(art_name,                   DWORD)
PTR_(art_vault_guy_num,          DWORD)
PTR_(art_vault_person_nums,      DWORD)
PTR_(background_volume,          DWORD)
PTR_(bckgnd,                     BYTE*)
PTR_(black_palette,              DWORD)
PTR_(BlueColor,                  BYTE)
PTR_(bottom_line,                DWORD)
PTR_(btable,                     DWORD)
PTR_(btncnt,                     DWORD)
PTR_(carCurrentArea,             DWORD)
PTR_(carGasAmount,               long) // from 0 to 80000
PTR_(cmap,                       DWORD)
PTR_(colorTable,                 DWORD)
PTR_(combat_free_move,           DWORD)
PTR_(combat_list,                DWORD)
PTR_(combat_state,               DWORD)
PTR_(combat_turn_running,        DWORD)
PTR_(combatNumTurns,             DWORD)
PTR_(crit_succ_eff,              CritInfo)  // array: 20 critters with 9 body parts and 6 effects each
PTR_(critter_db_handle,          PathNode*)
PTR_(critterClearObj,            DWORD)
PTR_(crnt_func,                  DWORD)
PTR_(curr_font_num,              DWORD)
PTR_(curr_pc_stat,               long) // array of size == PCSTAT_max_pc_stat
PTR_(curr_stack,                 DWORD)
PTR_(currentProgram,             TProgram*)
PTR_(cursor_line,                DWORD)
PTR_(DARK_GREY_Color,            BYTE)
PTR_(DarkGreenColor,             BYTE)
PTR_(DarkGreenGreyColor,         BYTE)
PTR_(dialog_target,              TGameObj*)
PTR_(dialog_target_is_party,     DWORD)
PTR_(dialogueBackWindow,         DWORD)
PTR_(drugInfoList,               DWORD)
PTR_(DullPinkColor,              BYTE)
PTR_(edit_win,                   DWORD)
PTR_(Educated,                   DWORD)
PTR_(elevation,                  DWORD)
PTR_(endgame_subtitle_done,      DWORD)
PTR_(Experience_,                DWORD)
PTR_(fallout_game_time,          DWORD)
PTR_(fidgetFID,                  DWORD)
PTR_(flptr,                      DWORD)
PTR_(folder_card_desc,           DWORD)
PTR_(folder_card_fid,            DWORD)
PTR_(folder_card_title,          DWORD)
PTR_(folder_card_title2,         DWORD)
PTR_(frame_time,                 DWORD)
PTR_(free_perk,                  char)
PTR_(game_global_vars,           long*)  // dynamic array of size == num_game_global_vars
PTR_(game_user_wants_to_quit,    DWORD)
PTR_(gcsd,                       CombatGcsd*)
PTR_(gdBarterMod,                DWORD)
PTR_(gdNumOptions,               DWORD)
PTR_(gIsSteal,                   DWORD)
PTR_(glblmode,                   DWORD)
PTR_(gmouse_3d_current_mode,     long)
PTR_(gmouse_current_cursor,      long)
PTR_(gmovie_played_list,         BYTE) // array of 17 BYTE
PTR_(GoodColor,                  BYTE)
PTR_(GreenColor,                 BYTE)
PTR_(gsound_initialized,         DWORD)
PTR_(hit_location_penalty,       long) // array of 9 long
PTR_(holo_flag,                  DWORD)
PTR_(holopages,                  DWORD)
PTR_(hot_line_count,             DWORD)
PTR_(i_fid,                      DWORD)
PTR_(i_lhand,                    TGameObj*)
PTR_(i_rhand,                    TGameObj*)
PTR_(i_wid,                      DWORD)
PTR_(i_worn,                     TGameObj*)
PTR_(idle_func,                  void*)
PTR_(In_WorldMap,                DWORD) // moving on WorldMap
PTR_(info_line,                  DWORD)
PTR_(interfaceWindow,            DWORD)
PTR_(intfaceEnabled,             DWORD)
PTR_(intotal,                    DWORD)
PTR_(inven_dude,                 TGameObj*)
PTR_(inven_pid,                  DWORD)
PTR_(inven_scroll_dn_bid,        DWORD)
PTR_(inven_scroll_up_bid,        DWORD)
PTR_(inventry_message_file,      MSGList)
PTR_(itemButtonItems,            ItemButtonItem) // array of 2 ItemButtonItem, 0 - left, 1 - right
PTR_(itemCurrentItem,            long)  // 0 - left, 1 - right
PTR_(kb_lock_flags,              DWORD)
PTR_(last_buttons,               DWORD)
PTR_(last_button_winID,          DWORD)
PTR_(last_level,                 DWORD)
PTR_(Level_,                     DWORD)
PTR_(Lifegiver,                  DWORD)
PTR_(LIGHT_GREY_Color,           BYTE)
PTR_(lipsFID,                    DWORD)
PTR_(list_com,                   DWORD)
PTR_(list_total,                 DWORD)
PTR_(loadingGame,                DWORD)
PTR_(LSData,                     DWORD)
PTR_(lsgwin,                     DWORD)
PTR_(main_ctd,                   TComputeAttack)
PTR_(main_death_voiceover_done,  DWORD)
PTR_(main_window,                DWORD)
PTR_(map_elevation,              DWORD)
PTR_(map_global_vars,            long*)  // array
PTR_(map_number,                 DWORD)
PTR_(master_db_handle,           PathNode*)
PTR_(master_volume,              DWORD)
PTR_(max,                        DWORD)
PTR_(maxScriptNum,               long)
PTR_(Meet_Frank_Horrigan,        bool)
PTR_(mouse_buttons,              DWORD)
PTR_(mouse_hotx,                 DWORD)
PTR_(mouse_hoty,                 DWORD)
PTR_(mouse_is_hidden,            DWORD)
PTR_(mouse_x_,                   DWORD)
PTR_(mouse_y,                    DWORD)
PTR_(mouse_y_,                   DWORD)
PTR_(movie_list,                 const char*) // array of 17 char*
PTR_(Mutate_,                    DWORD)
PTR_(name_color,                 DWORD)
PTR_(name_font,                  DWORD)
PTR_(name_sort_list,             DWORD)
PTR_(num_game_global_vars,       DWORD)
PTR_(num_map_global_vars,        DWORD)
PTR_(num_windows,                DWORD)
PTR_(obj_dude,                   TGameObj*)
PTR_(objectTable,                DWORD*) // array of 40000 pointers
PTR_(objItemOutlineState,        DWORD)
PTR_(optionRect,                 DWORD)
PTR_(optionsButtonDown,          DWORD)
PTR_(optionsButtonDown1,         DWORD)
PTR_(optionsButtonDownKey,       DWORD)
PTR_(optionsButtonUp,            DWORD)
PTR_(optionsButtonUp1,           DWORD)
PTR_(optionsButtonUpKey,         DWORD)
PTR_(optnwin,                    DWORD)
PTR_(outlined_object,            TGameObj*)
PTR_(partyMemberAIOptions,       DWORD)
PTR_(partyMemberCount,           DWORD)
PTR_(partyMemberLevelUpInfoList, DWORD*)
PTR_(partyMemberList,            DWORD*) // each struct - 4 integers, first integer - objPtr
PTR_(partyMemberMaxCount,        DWORD)
PTR_(partyMemberPidList,         DWORD*)
PTR_(patches,                    char*)
PTR_(paths,                      PathNode*)  // array
PTR_(pc_crit_succ_eff,           CritInfo) // array: 9 body parts, 6 effects
PTR_(pc_kill_counts,             DWORD)
PTR_(pc_name,                    char) // array of 32 char
PTR_(pc_proto,                   sProto)
PTR_(pc_trait,                   long) // 2 of them
PTR_(PeanutButter,               BYTE)
PTR_(perk_data,                  PerkInfo) // array of size == PERK_count
PTR_(perkLevelDataList,          long*) // dynamic array, limited to PERK_Count
PTR_(pip_win,                    DWORD)
PTR_(pipboy_message_file,        MSGList)
PTR_(pipmesg,                    DWORD)
PTR_(preload_list_index,         DWORD)
PTR_(procTableStrs,              const char*)  // table of procId (from define.h) => procName map
PTR_(proto_main_msg_file,        MSGList)
PTR_(proto_msg_files,            MSGList)  // array of 6 elements
PTR_(ptable,                     DWORD)
PTR_(pud,                        DWORD)
PTR_(queue,                      Queue*)
PTR_(quick_done,                 DWORD)
PTR_(read_callback,              DWORD)
PTR_(rectList,                   RectList*)
PTR_(RedColor,                   BYTE)
PTR_(retvals,                    sElevatorExit) // array: 24 elevators, 4 exits each
PTR_(rotation,                   DWORD)
PTR_(sampleRate,                 DWORD)
PTR_(scr_size,                   BoundRect)
PTR_(scriptListInfo,             ScriptListInfoItem*)  // dynamic array
PTR_(skill_data,                 SkillInfo) // array of size == SKILL_count
PTR_(skldxwin,                   DWORD)
PTR_(slot_cursor,                DWORD)
PTR_(sndfx_volume,               DWORD)
PTR_(sneak_working,              DWORD) // DWORD var
PTR_(sound_music_path1,          char*)
PTR_(sound_music_path2,          char*)
PTR_(speech_volume,              DWORD)
PTR_(square,                     DWORD)
PTR_(squares,                    DWORD*)
PTR_(stack,                      DWORD) // array of 10 DWORD
PTR_(stack_offset,               DWORD) // array of 10 DWORD
PTR_(stat_data,                  StatInfo) // dynamic array, limited to STAT_real_max_stat
PTR_(stat_flag,                  DWORD)
PTR_(subtitleList,               SubTitleList*)
PTR_(sWindows,                   sWindow) // array of 16 sWindow
PTR_(Tag_,                       DWORD)
PTR_(tag_skill,                  DWORD)
PTR_(target_curr_stack,          DWORD)
PTR_(target_pud,                 DWORD*)
PTR_(target_stack,               DWORD) // array of 10 DWORD
PTR_(target_stack_offset,        DWORD) // array of 10 DWORD
PTR_(target_str,                 DWORD)
PTR_(target_xpos,                DWORD)
PTR_(target_ypos,                DWORD)
PTR_(text_char_width,            DWORD)
PTR_(text_height,                DWORD)
PTR_(text_max,                   DWORD)
PTR_(text_mono_width,            DWORD)
PTR_(text_object_index,          DWORD)
PTR_(text_object_list,           FloatText*) // array of 20 FloatText*
PTR_(text_spacing,               DWORD)
PTR_(text_to_buf,                DWORD)
PTR_(text_width,                 DWORD)
PTR_(tile,                       DWORD)
PTR_(title_color,                DWORD)
PTR_(title_font,                 DWORD)
PTR_(trait_data,                 TraitInfo) // // array of size == TRAIT_count
PTR_(view_page,                  DWORD)
PTR_(wd_obj,                     DWORD)
PTR_(window,                     WINinfo*) // array of 50 WINinfo*
PTR_(window_index,               DWORD) // array of 50 DWORD
PTR_(WhiteColor,                 BYTE)
PTR_(wmAreaInfoList,             DWORD)
PTR_(wmBkWin,                    DWORD)
PTR_(wmBkWinBuf,                 BYTE*)
PTR_(wmLastRndTime,              DWORD)
PTR_(wmMsgFile,                  MSGList)
PTR_(wmNumHorizontalTiles,       DWORD)
PTR_(wmWorldOffsetX,             long)
PTR_(wmWorldOffsetY,             long)
PTR_(world_xpos,                 DWORD)
PTR_(world_ypos,                 DWORD)
PTR_(WorldMapCurrArea,           DWORD)
PTR_(YellowColor,                BYTE)

#undef PTR_
