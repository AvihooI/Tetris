Game Controls:

1) Press the enter key to pause/unpause the game, as well as start a new game on game over.
2) Press the left and right arrow keys to move the tetrino piece left and right respectively.
3) Press the up arrow key and left control key to rotate the tetrino piece clockwise and counter-clockwise respectively.
4) Press down to move the piece down (make one step).
5) Press space to hard drop the piece.

To build on Windows with Microsoft Visual C++ and CMake (version 3.16 and above):

Download the 

Create two environment variables:
1) SDL2 - the path to your SDL2 development library (the folder that has the include and lib directories)
2) SDL2_TTF - the path to your SDL2_ttf development library

Make sure you have the appropriate DLL files in the build directory (where the exe file goes):
1) SDL2.dll
2) SDL2_ttf.dll
3) zlib1.dll
4) libfreetype-6.dll

Those dll files can be found in the lib directories of SDL2 and SDL2_ttf.

To build on Ubuntu Linux (and possibly other Debian distributions) with CMake:

1) Install SDL2 library for development -> "sudo apt install libsdl2-dev"
2) Install SDL2 TTF library for development -> "sudo apt install libsdl2-ttf-dev"

The FindSDL2 and FindSDL2_ttf cmake modules should be able to find the dependencies with no further configurations on your part.

Running the game requires a font file called "hemi_head.ttf" - which can be found here: https://www.dafont.com/hemi-head.font.
The font has to be placed in the same folder as the executable file.

How to contribute:

If you would like to contribute to this project, please consider the following:

1) Code review and refactoring.
2) Documentation: anything from correcting typos, adding neater and clearer comments in code to readable documents and wiki pages that help with developing, building, testing and playing the game.
3) Feature addition: if you wish to add features to the game take a look at the planned features section. 
4) Play testing: if you play the game and find bugs, crashes, unusual behavior, or simply have a suggestion to make, you can raise an issue on the GitHub page.
5) Assets creation: if you would like to add assets to the game (2D art, sound effects and music), contact me.

Licensing:

This software is free to use, free to extend and free to commercialize with no royalty as long as acknowledgements are made to the author(s).

Acknowledgements:

1) This software uses the SDL2 Library and the SDL2 True Type Font Library (by Sam Lantinga). More information can be found on the respective web pages: https://www.libsdl.org/index.php https://www.libsdl.org/projects/SDL_ttf/. 
2) This game uses the Hemi Head True Type Font by Ray Larabie (Typodermic Fonts - https://typodermicfonts.com/).

Planned Features:

Soon:

1) Line clear, tetris and level up animations.
2) Sound effects.
3) A better random piece generator.
4) Configurable display.
5) Persistent configurations.

Later:

1) Music
2) Configurable game settings.

Much later, maybe:

1) Controller support.
2) Multi-player mode. 