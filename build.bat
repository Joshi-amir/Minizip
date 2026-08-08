@echo off

echo Cleaning old build...

if exist MiniZip.exe del MiniZip.exe


echo Building MiniZip...


g++ -Iinclude ^
src\main.cpp ^
src\FileManager.cpp ^
src\FrequencyCounter.cpp ^
src\MinHeap.cpp ^
src\HuffmanTree.cpp ^
src\Compressor.cpp ^
src\BitWriter.cpp ^
src\Decompressor.cpp ^
src\FileHeader.cpp ^
src\BitReader.cpp ^
src\Statistics.cpp ^
-o MiniZip.exe


if %errorlevel%==0 (
    echo.
    echo Build Successful!
    echo Running Program...
    echo.
    MiniZip.exe
) else (
    echo.
    echo Build Failed!
)

pause