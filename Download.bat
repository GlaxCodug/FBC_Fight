@echo off
echo Building FBC Fight

gcc *.c -o FBC_Fight -lmingw32 -lSDL2main -lSDL2 -mwindows -static -lsetupapi -lole32 -limm32 -lversion -loleaut32 -lwinmm -lcfgmgr32

if %errorlevel% == 0 (
    echo Build successful! Run FBC_Fight.exe to launch
) else (
    echo Build failed. Check errors above.
)

pause