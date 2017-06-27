# ProgressBar

[![Travis](https://img.shields.io/travis/limix/progressbar.svg?style=flat-square)](https://travis-ci.org/limix/progressbar)
[![Appveyor](https://ci.appveyor.com/api/projects/status/ccu47dffb2qvi8sa?svg=true)](https://ci.appveyor.com/project/Horta/progressbar)

ProgressBar is a C library for displaying attractive progress bars on the
command line.
It's heavily influenced by the ruby ProgressBar gem, whose api and behaviour it
imitates.

## Usage

```c
#include "progressbar.h"

progressbar *progress = progressbar_new("Loading", 100);

for(int i=0; i < 100; i++)
{
  // Do some stuff
  progressbar_inc(progress);
}
progressbar_finish(progress);
```

Example output (from `test/demo.c`):

![demo output](demo.gif)

## Install

On Linux or macOS systems it can be as simple as
```bash
wget https://github.com/limix/progressbar/archive/0.1.2.tar.gz
tar xzf 0.1.2.tar.gz
cd progressbar-0.1.2
mkdir build
cd build
cmake ..
make
sudo make install
```
assuming that you have the [ncurses](https://www.gnu.org/software/ncurses/)
library installed and that ``cmake`` managed to find it.

On Windows systems you might want to have a look at the
[msys2](http://www.msys2.org) project.
It provides Unix-like environment making it easier to install, use, build and
port software on Windows.
In particular, we need `gcc`, `ncurses`, and `cmake` packages:

```dos
pacman -S --needed ^
    mingw-w64-x86_64-gcc ^
    mingw-w64-x86_64-ncurses ^
    mingw-w64-x86_64-cmake
```

From `progressbar` source directory, do
```dos
mkdir build
cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE ^
         -DCMAKE_BUILD_TYPE=%BUILD_TYPE%
cmake --build . --config Release --target install
```

## Problems

If you encounter any issue, please, [submit it](https://github.com/limix/progressbar/issues).

## Acknowledgements

* **Danilo Horta** - [https://github.com/horta](https://github.com/horta)
* **Johannes Buchner** - [https://github.com/JohannesBuchner](https://github.com/JohannesBuchner)
* **Mariano Anaya** - [https://github.com/rmariano](https://github.com/rmariano)
* **Trevor Fountain** - [https://github.com/doches](https://github.com/doches)

## License

This project is licensed under the MIT License - see the
[LICENSE](LICENSE) file for details
