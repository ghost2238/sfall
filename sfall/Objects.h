#pragma once

enum UniqueID : long {
	UID_START = 0x0FFFFFFF, // start at 0x10000000
	UID_END   = 0x7FFFFFFF
};

extern long Objects_uniqueID;

void Objects_Init();
void RestoreObjUnjamAllLocks();

long __fastcall Objects_SetObjectUniqueID(TGameObj* obj);
long __fastcall Objects_SetSpecialID(TGameObj* obj);
void Objects_SetNewEngineID(TGameObj* obj);

void Objects_SetAutoUnjamLockTime(DWORD time);
void Objects_LoadProtoAutoMaxLimit();