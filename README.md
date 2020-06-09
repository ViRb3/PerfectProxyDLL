# Perfect Proxy
> A simple and stable proxy DLL for Windows x64.

## Notes
Assembly inlining is not supported in MSVC on x64,
therefore this project uses GCC through MinGW.

## Compilation
- mingw-w64 7.0.0+
- CMake 3.16+

## References
- https://github.com/advancedmonitoring/ProxyDll
- https://silentbreaksecurity.com/adaptive-dll-hijacking/
- https://kevinalmansa.github.io/application%20security/DLL-Proxying/
- https://itm4n.github.io/dll-proxying/