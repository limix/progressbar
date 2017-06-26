# ProgressBar

[![Travis](https://img.shields.io/travis/limix/progressbar.svg?style=flat-square)](https://travis-ci.org/limix/progressbar)

ProgressBar is a C library for displaying attractive progress bars on the
command line.
It's heavily influenced by the ruby ProgressBar gem, whose api and behaviour it
imitates.

## Usage

```c
progressbar *progress = progressbar_new("Loading", 100);
for(int i=0; i < 100; i++)
{
  // Do some stuff
  progressbar_inc(progress);
}
progressbar_finish(progress);
```

Example output (from `test/demo.c`):

![demo output](example_output/demo.png)

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
