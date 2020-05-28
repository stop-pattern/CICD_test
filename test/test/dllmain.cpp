// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

Hand manual = {0,0,0,0};
bool door = false;
Spec vspec;

DE void SC Load(void) {

}

DE void SC Dispose(void) {

}

DE int SC GetPluginVersion(void) {
	return PI_VERSION;
}

DE void SC SetVehicleSpec(Spec sp) {
    vspec = sp;
}

DE void SC Initialize(int) {

}

DE Hand SC Elapse(State, int*, int*) {
    if (door) return manual;
    if (manual.B >= (vspec.B + 1) / 2) return manual;
    Hand ret = manual;
    manual.B = (vspec.B + 1) / 2;
    return ret;
}

DE void SC SetPower(int p) {
    manual.P = p;
}

DE void SC SetBrake(int b) {
    manual.B = b;
}

DE void SC SetReverser(int r) {
    manual.R = r;
}

DE void SC KeyDown(int) {

}

DE void SC KeyUp(int) {

}

DE void SC HornBlow(int) {

}

DE void SC DoorOpen(void) {
    door = false;
}

DE void SC DoorClose(void) {
    door = true;
}

DE void SC SetSignal(int) {

}

DE void SC SetBeaconData(Beacon) {

}