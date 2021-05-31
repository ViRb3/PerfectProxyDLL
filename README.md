# Perfect Proxy

> A simple and stable proxy DLL for Windows x64.

## Notes

Assembly inlining is not supported in MSVC on x64,
therefore this project uses GCC through MinGW.

## Compilation

- mingw-w64 7.0.0+
- CMake 3.16+

If you get an error like: `undefined reference to 'orig_somefunc'`, you may need to prefix your assembly symbols with an underscore:

```patch
#define WRAPPER_GENFUNC(name) \
	FARPROC orig_##name; \
	__declspec(naked) void _##name() \
	{ \
-		asm("jmp *orig_"#name); \
+		asm("jmp *_orig_"#name); \
	}
```

_Source: https://stackoverflow.com/a/36359457_

## References

- https://github.com/advancedmonitoring/ProxyDll
- https://silentbreaksecurity.com/adaptive-dll-hijacking/
- https://kevinalmansa.github.io/application%20security/DLL-Proxying/
- https://itm4n.github.io/dll-proxying/
