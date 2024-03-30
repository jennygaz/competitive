# Make Variables
CC = g++
JAVA = javac
PY = python
MACOS = brew
DEBIAN = apt
WINDOWS = winget

# C++ Compiler flags to match UVa Online Judge
# -lm -> Link usual libraries
# -lcrypt -> Link secure libraries
# -O2 -> Optimization level 2
# -std=c++11 -> Use Standard C++11
# -Wall -> Check all warnings
# -Wpedantic -> Check extra style and specific warnings
# Can also add:
# -pipe -> compile it for piping
# -DONLINE_JUDGE -> set as true the variable ONLINE_JUDGE
CFLAGS = -lm -lcrypt -O2 -std=c++11 -Wall -Wpedantic

# Install dependencies
# macOS doesn't have support formulae/casks for python 3.5 as of 03/30/2024
# Fallback to python 3.12 since it has support for most things of python 3.5
macos:
	$(MACOS) install g++ python openjdk

# Debian-like builds of Linux go here
debian:
	sudo $(DEBIAN) install g++ python3 openjdk-17-jdk

# Windows builds (require winget)
windows:
	$(WINDOWS) install python ojdkbuild
	echo "To install g++ in Windows, please go to https://nuwen.net/mingw.html#install and follow the instructions"

# Build targets
cpp: main.cpp
	$(CC) $(CFLAGS) -o maincpp main.cpp

java: Main.java
	$(JAVA) -source 1.8 Main.java

# Run targets

runc: maincpp input
	./maincpp < input

runj: Main.class input
	java Main < input

python: main.py input
	$(PY) main.py < input

# Test targets and compare outputs /* UNDER CONSTRUCTION */
