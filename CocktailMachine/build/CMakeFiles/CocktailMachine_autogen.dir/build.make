# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/admin/Desktop/cocktail_machine/CocktailMachine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/admin/Desktop/cocktail_machine/CocktailMachine/build

# Utility rule file for CocktailMachine_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/CocktailMachine_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CocktailMachine_autogen.dir/progress.make

CMakeFiles/CocktailMachine_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/admin/Desktop/cocktail_machine/CocktailMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target CocktailMachine"
	/usr/bin/cmake -E cmake_autogen /home/admin/Desktop/cocktail_machine/CocktailMachine/build/CMakeFiles/CocktailMachine_autogen.dir/AutogenInfo.json ""

CocktailMachine_autogen: CMakeFiles/CocktailMachine_autogen
CocktailMachine_autogen: CMakeFiles/CocktailMachine_autogen.dir/build.make
.PHONY : CocktailMachine_autogen

# Rule to build all files generated by this target.
CMakeFiles/CocktailMachine_autogen.dir/build: CocktailMachine_autogen
.PHONY : CMakeFiles/CocktailMachine_autogen.dir/build

CMakeFiles/CocktailMachine_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CocktailMachine_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CocktailMachine_autogen.dir/clean

CMakeFiles/CocktailMachine_autogen.dir/depend:
	cd /home/admin/Desktop/cocktail_machine/CocktailMachine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/admin/Desktop/cocktail_machine/CocktailMachine /home/admin/Desktop/cocktail_machine/CocktailMachine /home/admin/Desktop/cocktail_machine/CocktailMachine/build /home/admin/Desktop/cocktail_machine/CocktailMachine/build /home/admin/Desktop/cocktail_machine/CocktailMachine/build/CMakeFiles/CocktailMachine_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CocktailMachine_autogen.dir/depend

