# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/workspace/CppND-Capstone-Snake-Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/workspace/CppND-Capstone-Snake-Game/build

# Include any dependencies generated for this target.
include CMakeFiles/TankGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TankGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TankGame.dir/flags.make

CMakeFiles/TankGame.dir/src/main.cpp.o: CMakeFiles/TankGame.dir/flags.make
CMakeFiles/TankGame.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TankGame.dir/src/main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TankGame.dir/src/main.cpp.o -c /home/workspace/CppND-Capstone-Snake-Game/src/main.cpp

CMakeFiles/TankGame.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TankGame.dir/src/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-Snake-Game/src/main.cpp > CMakeFiles/TankGame.dir/src/main.cpp.i

CMakeFiles/TankGame.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TankGame.dir/src/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-Snake-Game/src/main.cpp -o CMakeFiles/TankGame.dir/src/main.cpp.s

CMakeFiles/TankGame.dir/src/game.cpp.o: CMakeFiles/TankGame.dir/flags.make
CMakeFiles/TankGame.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TankGame.dir/src/game.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TankGame.dir/src/game.cpp.o -c /home/workspace/CppND-Capstone-Snake-Game/src/game.cpp

CMakeFiles/TankGame.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TankGame.dir/src/game.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-Snake-Game/src/game.cpp > CMakeFiles/TankGame.dir/src/game.cpp.i

CMakeFiles/TankGame.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TankGame.dir/src/game.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-Snake-Game/src/game.cpp -o CMakeFiles/TankGame.dir/src/game.cpp.s

CMakeFiles/TankGame.dir/src/controller.cpp.o: CMakeFiles/TankGame.dir/flags.make
CMakeFiles/TankGame.dir/src/controller.cpp.o: ../src/controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TankGame.dir/src/controller.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TankGame.dir/src/controller.cpp.o -c /home/workspace/CppND-Capstone-Snake-Game/src/controller.cpp

CMakeFiles/TankGame.dir/src/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TankGame.dir/src/controller.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-Snake-Game/src/controller.cpp > CMakeFiles/TankGame.dir/src/controller.cpp.i

CMakeFiles/TankGame.dir/src/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TankGame.dir/src/controller.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-Snake-Game/src/controller.cpp -o CMakeFiles/TankGame.dir/src/controller.cpp.s

CMakeFiles/TankGame.dir/src/renderer.cpp.o: CMakeFiles/TankGame.dir/flags.make
CMakeFiles/TankGame.dir/src/renderer.cpp.o: ../src/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TankGame.dir/src/renderer.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TankGame.dir/src/renderer.cpp.o -c /home/workspace/CppND-Capstone-Snake-Game/src/renderer.cpp

CMakeFiles/TankGame.dir/src/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TankGame.dir/src/renderer.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-Snake-Game/src/renderer.cpp > CMakeFiles/TankGame.dir/src/renderer.cpp.i

CMakeFiles/TankGame.dir/src/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TankGame.dir/src/renderer.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-Snake-Game/src/renderer.cpp -o CMakeFiles/TankGame.dir/src/renderer.cpp.s

CMakeFiles/TankGame.dir/src/snake.cpp.o: CMakeFiles/TankGame.dir/flags.make
CMakeFiles/TankGame.dir/src/snake.cpp.o: ../src/snake.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TankGame.dir/src/snake.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TankGame.dir/src/snake.cpp.o -c /home/workspace/CppND-Capstone-Snake-Game/src/snake.cpp

CMakeFiles/TankGame.dir/src/snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TankGame.dir/src/snake.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-Snake-Game/src/snake.cpp > CMakeFiles/TankGame.dir/src/snake.cpp.i

CMakeFiles/TankGame.dir/src/snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TankGame.dir/src/snake.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-Snake-Game/src/snake.cpp -o CMakeFiles/TankGame.dir/src/snake.cpp.s

# Object files for target TankGame
TankGame_OBJECTS = \
"CMakeFiles/TankGame.dir/src/main.cpp.o" \
"CMakeFiles/TankGame.dir/src/game.cpp.o" \
"CMakeFiles/TankGame.dir/src/controller.cpp.o" \
"CMakeFiles/TankGame.dir/src/renderer.cpp.o" \
"CMakeFiles/TankGame.dir/src/snake.cpp.o"

# External object files for target TankGame
TankGame_EXTERNAL_OBJECTS =

TankGame: CMakeFiles/TankGame.dir/src/main.cpp.o
TankGame: CMakeFiles/TankGame.dir/src/game.cpp.o
TankGame: CMakeFiles/TankGame.dir/src/controller.cpp.o
TankGame: CMakeFiles/TankGame.dir/src/renderer.cpp.o
TankGame: CMakeFiles/TankGame.dir/src/snake.cpp.o
TankGame: CMakeFiles/TankGame.dir/build.make
TankGame: CMakeFiles/TankGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/workspace/CppND-Capstone-Snake-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable TankGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TankGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TankGame.dir/build: TankGame

.PHONY : CMakeFiles/TankGame.dir/build

CMakeFiles/TankGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TankGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TankGame.dir/clean

CMakeFiles/TankGame.dir/depend:
	cd /home/workspace/CppND-Capstone-Snake-Game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/workspace/CppND-Capstone-Snake-Game /home/workspace/CppND-Capstone-Snake-Game /home/workspace/CppND-Capstone-Snake-Game/build /home/workspace/CppND-Capstone-Snake-Game/build /home/workspace/CppND-Capstone-Snake-Game/build/CMakeFiles/TankGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TankGame.dir/depend

