STFU Fab@Home!
==============

Usage
-----

Just start stfu.exe and watch as it answers all of Fab@Home's abort dialog boxes.
Currently, you have to stop the program by pressing `Ctrl` + `C`.

Compilation
-----------

You can compile the code either with GCC or Microsoft Visual Studio. A Makefile
is provided for the first use case, you just have to adjust the CC environment
variable to the appropriate path. If you use Debian/Ubuntu, just install the
`gcc-mingw32` package with your favorite package manager and execute the
`debian_build.sh` shell script. In case of Microsoft Visual Studio, create an
empty C++ project, add the `stfu.c` and build the project.

License
-------

The whole project is licensed under MIT license.
