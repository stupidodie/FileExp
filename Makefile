# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tgr/Downloads/CompressApp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tgr/Downloads/CompressApp

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.19.1/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.19.1/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/tgr/Downloads/CompressApp/CMakeFiles /Users/tgr/Downloads/CompressApp//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/tgr/Downloads/CompressApp/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named CompressApp

# Build rule for target.
CompressApp: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 CompressApp
.PHONY : CompressApp

# fast build rule for target.
CompressApp/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/build
.PHONY : CompressApp/fast

#=============================================================================
# Target rules for targets named filepack

# Build rule for target.
filepack: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 filepack
.PHONY : filepack

# fast build rule for target.
filepack/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/filepack.dir/build.make CMakeFiles/filepack.dir/build
.PHONY : filepack/fast

#=============================================================================
# Target rules for targets named CompressApp_autogen

# Build rule for target.
CompressApp_autogen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 CompressApp_autogen
.PHONY : CompressApp_autogen

# fast build rule for target.
CompressApp_autogen/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp_autogen.dir/build.make CMakeFiles/CompressApp_autogen.dir/build
.PHONY : CompressApp_autogen/fast

#=============================================================================
# Target rules for targets named filepack_autogen

# Build rule for target.
filepack_autogen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 filepack_autogen
.PHONY : filepack_autogen

# fast build rule for target.
filepack_autogen/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/filepack_autogen.dir/build.make CMakeFiles/filepack_autogen.dir/build
.PHONY : filepack_autogen/fast

CompressApp_autogen/mocs_compilation.o: CompressApp_autogen/mocs_compilation.cpp.o

.PHONY : CompressApp_autogen/mocs_compilation.o

# target to build an object file
CompressApp_autogen/mocs_compilation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/CompressApp_autogen/mocs_compilation.cpp.o
.PHONY : CompressApp_autogen/mocs_compilation.cpp.o

CompressApp_autogen/mocs_compilation.i: CompressApp_autogen/mocs_compilation.cpp.i

.PHONY : CompressApp_autogen/mocs_compilation.i

# target to preprocess a source file
CompressApp_autogen/mocs_compilation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/CompressApp_autogen/mocs_compilation.cpp.i
.PHONY : CompressApp_autogen/mocs_compilation.cpp.i

CompressApp_autogen/mocs_compilation.s: CompressApp_autogen/mocs_compilation.cpp.s

.PHONY : CompressApp_autogen/mocs_compilation.s

# target to generate assembly for a file
CompressApp_autogen/mocs_compilation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/CompressApp_autogen/mocs_compilation.cpp.s
.PHONY : CompressApp_autogen/mocs_compilation.cpp.s

algorithm/Huffman.o: algorithm/Huffman.cpp.o

.PHONY : algorithm/Huffman.o

# target to build an object file
algorithm/Huffman.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/filepack.dir/build.make CMakeFiles/filepack.dir/algorithm/Huffman.cpp.o
.PHONY : algorithm/Huffman.cpp.o

algorithm/Huffman.i: algorithm/Huffman.cpp.i

.PHONY : algorithm/Huffman.i

# target to preprocess a source file
algorithm/Huffman.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/filepack.dir/build.make CMakeFiles/filepack.dir/algorithm/Huffman.cpp.i
.PHONY : algorithm/Huffman.cpp.i

algorithm/Huffman.s: algorithm/Huffman.cpp.s

.PHONY : algorithm/Huffman.s

# target to generate assembly for a file
algorithm/Huffman.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/filepack.dir/build.make CMakeFiles/filepack.dir/algorithm/Huffman.cpp.s
.PHONY : algorithm/Huffman.cpp.s

algorithm/Pack.o: algorithm/Pack.cpp.o

.PHONY : algorithm/Pack.o

# target to build an object file
algorithm/Pack.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/filepack.dir/build.make CMakeFiles/filepack.dir/algorithm/Pack.cpp.o
.PHONY : algorithm/Pack.cpp.o

algorithm/Pack.i: algorithm/Pack.cpp.i

.PHONY : algorithm/Pack.i

# target to preprocess a source file
algorithm/Pack.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/filepack.dir/build.make CMakeFiles/filepack.dir/algorithm/Pack.cpp.i
.PHONY : algorithm/Pack.cpp.i

algorithm/Pack.s: algorithm/Pack.cpp.s

.PHONY : algorithm/Pack.s

# target to generate assembly for a file
algorithm/Pack.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/filepack.dir/build.make CMakeFiles/filepack.dir/algorithm/Pack.cpp.s
.PHONY : algorithm/Pack.cpp.s

filepack_autogen/mocs_compilation.o: filepack_autogen/mocs_compilation.cpp.o

.PHONY : filepack_autogen/mocs_compilation.o

# target to build an object file
filepack_autogen/mocs_compilation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/filepack.dir/build.make CMakeFiles/filepack.dir/filepack_autogen/mocs_compilation.cpp.o
.PHONY : filepack_autogen/mocs_compilation.cpp.o

filepack_autogen/mocs_compilation.i: filepack_autogen/mocs_compilation.cpp.i

.PHONY : filepack_autogen/mocs_compilation.i

# target to preprocess a source file
filepack_autogen/mocs_compilation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/filepack.dir/build.make CMakeFiles/filepack.dir/filepack_autogen/mocs_compilation.cpp.i
.PHONY : filepack_autogen/mocs_compilation.cpp.i

filepack_autogen/mocs_compilation.s: filepack_autogen/mocs_compilation.cpp.s

.PHONY : filepack_autogen/mocs_compilation.s

# target to generate assembly for a file
filepack_autogen/mocs_compilation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/filepack.dir/build.make CMakeFiles/filepack.dir/filepack_autogen/mocs_compilation.cpp.s
.PHONY : filepack_autogen/mocs_compilation.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/main.cpp.s
.PHONY : main.cpp.s

mainwindow.o: mainwindow.cpp.o

.PHONY : mainwindow.o

# target to build an object file
mainwindow.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/mainwindow.cpp.o
.PHONY : mainwindow.cpp.o

mainwindow.i: mainwindow.cpp.i

.PHONY : mainwindow.i

# target to preprocess a source file
mainwindow.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/mainwindow.cpp.i
.PHONY : mainwindow.cpp.i

mainwindow.s: mainwindow.cpp.s

.PHONY : mainwindow.s

# target to generate assembly for a file
mainwindow.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/mainwindow.cpp.s
.PHONY : mainwindow.cpp.s

utils.o: utils.cpp.o

.PHONY : utils.o

# target to build an object file
utils.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/utils.cpp.o
.PHONY : utils.cpp.o

utils.i: utils.cpp.i

.PHONY : utils.i

# target to preprocess a source file
utils.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/utils.cpp.i
.PHONY : utils.cpp.i

utils.s: utils.cpp.s

.PHONY : utils.s

# target to generate assembly for a file
utils.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CompressApp.dir/build.make CMakeFiles/CompressApp.dir/utils.cpp.s
.PHONY : utils.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... CompressApp_autogen"
	@echo "... filepack_autogen"
	@echo "... CompressApp"
	@echo "... filepack"
	@echo "... CompressApp_autogen/mocs_compilation.o"
	@echo "... CompressApp_autogen/mocs_compilation.i"
	@echo "... CompressApp_autogen/mocs_compilation.s"
	@echo "... algorithm/Huffman.o"
	@echo "... algorithm/Huffman.i"
	@echo "... algorithm/Huffman.s"
	@echo "... algorithm/Pack.o"
	@echo "... algorithm/Pack.i"
	@echo "... algorithm/Pack.s"
	@echo "... filepack_autogen/mocs_compilation.o"
	@echo "... filepack_autogen/mocs_compilation.i"
	@echo "... filepack_autogen/mocs_compilation.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... mainwindow.o"
	@echo "... mainwindow.i"
	@echo "... mainwindow.s"
	@echo "... utils.o"
	@echo "... utils.i"
	@echo "... utils.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

