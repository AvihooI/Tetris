How to build and run on Windows with CMake:

Create two environment variables:
1) SDL2 - the path to your SDL2 development library (the library that has the include and lib directories)
2) SDL2_TTF - the path to your SDL2_ttf development library

Make sure you have the appropriate DLL files in the build directory (where the exe file goes):
1) SDL2.dll
2) SDL2_ttf.dll
3) zlib1.dll
4) libfreetype-6.dll

Those dll files can be found in the lib directories of SDL2 and SDL2_ttf