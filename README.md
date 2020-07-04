Current Version: 0.3.0

Versioning System:

Major.Minor.Increment

Major: major version numbers are for significant code base changes with the exception of major version 0 that signifies early development (alpha stage) and will continue naturally into major version 1.

Minor: each development cycle gets a minor version number change. 
Even numbers are for refactoring code, improving existing features, and adding internal and external documentation.
Odd numbers are for feature addition.

Increment: small changes within the current development cycle, including bug fixes and incremental planned feature additions.

Game Controls:

1) Press the enter key to pause/unpause the game, as well as start a new game on game over.
2) Press the left and right arrow keys to move the tetrino piece left and right respectively.
3) Press the up arrow key and left control key to rotate the tetrino piece clockwise and counter-clockwise respectively.
4) Press down to move the piece down (make one step).
5) Press space to hard drop the piece.
6) Press escape to open up a game menu which allows an assortment of options, pressing escape again leaves the menu.

To build on Windows with Microsoft Visual C++ and CMake (version 3.16 and above):

Download the SDL2, SDL2_ttf and SDL2_mixer development libraries. 

Create three environment variables:
1) SDL2 - the path to your SDL2 development library (the folder that has the include and lib directories)
2) SDL2_ttf - the path to your SDL2_ttf development library
3) SDL2_mixer - the path to your SDL2_mixer development library

Make sure you have the appropriate DLL files in the build directory (where the exe file goes):
1) SDL2.dll
2) SDL2_ttf.dll
3) zlib1.dll (for ttf)
4) libfreetype-6.dll (for ttf)
5) SDL2_mixer.dll and its relevant dependencies

Those dll files can be found in the lib directories of SDL2 and SDL2_ttf.

To build on Ubuntu Linux (and possibly other Debian distributions) with CMake:

1) Install SDL2 library for development -> "sudo apt install libsdl2-dev"
2) Install SDL2 TTF library for development -> "sudo apt install libsdl2-ttf-dev"

The FindSDL2 and FindSDL2_ttf cmake modules should be able to find the dependencies with no further configurations on your part.

Running the game requires a few assets. You can find the assets in the latest release package. 

How to contribute:

If you would like to contribute to this project, please consider the following:

1) Code review and refactoring.
2) Documentation: anything from correcting typos, adding neater and clearer comments in code to readable documents and wiki pages that help with developing, building, testing and playing the game.
3) Feature addition: if you wish to add features to the game take a look at the planned features section. 
4) Play testing: if you play the game and find bugs, crashes, unusual behavior, or simply have a suggestion to make, you can raise an issue on the GitHub page.
5) Assets creation: if you would like to add assets to the game (2D art, sound effects and music), contact me.

Licensing:

This software is free to use, free to extend and free to commercialize with no royalty as long as acknowledgements are made to the author(s).
Assets may be copyrighted and thus should not be used in other projects (including fork projects). If you are unsure, ask. 

Acknowledgements:

1) This software uses the SDL2 Library, the SDL2 True Type Font Library and the SDL2 Mixer Library (by Sam Lantinga). More information can be found on the respective web pages: https://www.libsdl.org/index.php https://www.libsdl.org/projects/SDL_ttf/ https://www.libsdl.org/projects/SDL_mixer/. 
2) This game uses the Hemi Head True Type Font by Ray Larabie (Typodermic Fonts - https://typodermicfonts.com/).
3) This game uses sound effects found on the websites https://freesfx.co.uk/ and https://audiojungle.net/.

Planned Features:

Soon:

1) More

Later:
1) Music

Much later, maybe:

1) Controller support.
2) Multi-player mode.

Road Map:

Version 0.4 (refactor & improve cycle):

1) Code cleanup and heavy refactoring
2) Menu sounds
3) More settings in the menu
4) Minor application changes
5) Error handling and reporting

Version 0.5 (add features cycle): 

1) Export more hardcoded settings
2) Customizable color scheme
3) More animations