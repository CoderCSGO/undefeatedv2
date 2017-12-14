#include <Windows.h>

#include "stdafx.h"

#define undefeated /* define hwid here */(9999999999)

UCHAR
szFileSys[255],
szVolNameBuff[255];

DWORD
dwMFL,
dwSysFlags,
dwSerial;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD Reason, LPVOID lpReserved)
{
	if (Reason == DLL_PROCESS_ATTACH)
	{
		GetVolumeInformation("C:\\", (LPTSTR)szVolNameBuff, 255, &dwSerial, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);

		if (dwSerial == undefeated)
		{
			MessageBox(0, "valid hwid", "solitude", MB_OK | MB_ICONINFORMATION);

			CreateThread(nullptr, 0, static_cast<LPTHREAD_START_ROUTINE>(CheatMain), nullptr, 0, nullptr);

			INIT::Dll = hModule;

			return TRUE;
		}
		else
		{
			MessageBox(NULL, "invalid hwid", "solitude", MB_OK);

			ExitProcess(1);

			return FALSE;
		}
	}
}