# ProgressBar

[![Release](http://github-release-version.herokuapp.com/github/limix/progressbar/release.svg?style=flat-square)](https://github.com/limix/progressbar/releases/latest) [![Linux / macOS build](https://img.shields.io/travis/limix/progressbar/master.svg?label=Linux%20%2F%20macOS&style=flat-square)](https://travis-ci.org/limix/progressbar) [![Windows build](https://img.shields.io/appveyor/ci/horta/progressbar/master.svg?label=Windows&style=flat-square)](https://ci.appveyor.com/project/Horta/progressbar/branch/master)

ProgressBar is a C library for displaying attractive progress bars on the command line.
It's heavily influenced by the ruby ProgressBar gem, whose api and behaviour it imitates.

## Usage

```c
#include "progressbar.h"

int main()
{
  progressbar *progress = progressbar_new("Loading", 100);

  for(int i=0; i < 100; i++)
  {
    // Do some stuff
    progressbar_inc(progress);
  }

  progressbar_finish(progress);

  return 0;
}
```

Example output from `test/demo.c`:

![demo output](demo.gif)

## Install

### Conda package manager

We provide a [conda](https://conda.io/docs/) distribution of progressbar under [conda-forge](https://conda-forge.org) channel:

```bash
conda install -c conda-forge c-progressbar
```

### Building yourself

On Linux or macOS systems it can be as simple as
```bash
bash <(curl -fsSL https://raw.githubusercontent.com/limix/progressbar/master/install)
```
assuming that you have [ncurses](https://www.gnu.org/software/ncurses/)
library installed and that ``cmake`` managed to find it.

On Windows systems you might want to have a look at the
[msys2](http://www.msys2.org) project first.
It provides Unix-like environment making it easier to install, use, build and
port software on Windows.
In particular, it can be used to install `gcc`, `ncurses`, and `cmake`:

```dos
pacman -S --needed mingw-w64-x86_64-gcc mingw-w64-x86_64-ncurses ^
                   mingw-w64-x86_64-cmake
```

Now from `progressbar` source directory, proceed with
```dos
mkdir build
cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release --target install
```

## Problems

If you encounter any issue, please, [submit it](https://github.com/limix/progressbar/issues).
Suggestions and ideas are also welcome.

## Acknowledgements

* **Danilo Horta** - [https://github.com/horta](https://github.com/horta)
* **Johannes Buchner** - [https://github.com/JohannesBuchner](https://github.com/JohannesBuchner)
* **Mariano Anaya** - [https://github.com/rmariano](https://github.com/rmariano)
* **Trevor Fountain** - [https://github.com/doches](https://github.com/doches)

## License

This project is licensed under the MIT License - see the
[LICENSE](LICENSE) file for details
