# CPPND: Capstone Tank Game

This repo is the Capstone Project for a Udacity course on C++ programming course. The code has been adapted from a snake game example provided.

This game has two players, each controls a single tank that can move in four directions (up, down, left and right) the tanks can fire a projectile which will temporarily immobilise the opponent. The objective is to destroy the other player and increase your score by scoring multiple hits. The game also features destructable terrain in the middle of the map which can be moved through but will stop projectiles. Score is allocated for each hit on a living opponent.

The controls are:  
Player 1:   Movement: Direction Arrows  
            Fire: NumPad 0 (Ensure numlock is off)  

Player 2:   Movement: WASD  
            Fire: Space  

Rubric Marking:  
The following rubric items have been included in the project:

The project demonstrates an understanding of C++ functions and control structures.  
Throughout - but for reference use of nested for loops in main.cpp (ln19-30) and switch case in tank.cpp (ln13-26)

The project accepts user input and processes the input.  
Controller.cpp (ln21-63) accepts input, processes it with PosUpdate() (ln6) and Fire() (ln13), detailed functions are abstracted from tank.cpp

The project uses Object Oriented Programming techniques.  
Class Tank (tank.cpp/.h) and Bullet (bullet.cpp/.h) have been created to hold variables and methods relevant to the objects.

Classes use appropriate access specifiers for class members.  
Game.h has all data members specified as public or private (likewise with all classes) and has appropriate public getter and setter methods (ln 16, 18)

Classes abstract implementation details from their interfaces.  
In Tank.cpp all methods provide a simple interface (abstraction) from the interface details such as (ln 29) which instantiates a bullet object and adds it to a vector but the only exposed interface is Tank::Fire(int team).

Classes encapsulate behavior.  
Classes Tank and Bullet encapsulate the objects and hold all relevant data and methods such as: Direction, Speed, Position, Firing methods, movement methods and updates methods.

The project makes use of references in function declarations.  
In game.cpp the constructor takes a reference to a map object (vector of vector of bools) and stores the map as private data in the game class (ln 6, 14)

The project uses smart pointers instead of raw pointers.  
Tank.cpp/.h uses a vector of unique pointers to hold the created bullet objects (tank.h ln33) and it is used heavily in the Game::Update() (ln 56) function in game.cpp

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
