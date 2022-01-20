# example_c_wordsort
* en: A simple example in C, that reads words adding them sorted using linked list, and save the list to a file.
* es: Un ejemplo sencillo en C que lee palabras agregándolas ordenadamente en una lista enlazada y la guarda en un archivo.

# Project tree
```bash
/                              | Root folder :)
├── LICENSE                    | Legal text of the license CC0.
├── makefile                   | Configuration file to use with make.
├── README.md                  | This file.
├── src/                       | Source code:
│   ├── errors.*               | ├── Error codes (maybe texts, in the future).
│   ├── list.*                 | ├── Simple linked list for use here (not delete, etc.).
│   ├── sortfile.*             | ├── Core logic for parsing files.
│   └── wordsort.c             | └── Main external logic of app / TUI.
├── test/                      | All files related to tests:
│   ├── all_tests.c            |   ├── Main with all tests.
│   ├── list_tests.*           |   ├── Tests for list.*
│   ├── smalltests.*           |   ├── Simple test module
│   ├── sortfile_tests.*       ¡   ├── Test for sortfile.*
│   └── testfiles/             ¡   └── Text files used in tests:
│       ├── 2lines.txt         |       ├── Test text file with 2 lines
│       ├── 2words.txt         |       ├── Test text file with 2 words
│       ├── emptyLine.txt      |       ├── Test text file with empty line
│       ├── empty.txt          |       ├── Test text empty file
│       ├── medium_input.txt   |       ├── Test text file with 
│       ├── medium_output.txt  |       ├── Sorted output of medium_input.txt
│       ├── wordLine.txt       |       ├── Test text file with word and breakline
│       └── wordNoLine.txt     |       └── Test text file with word
```
# Build and test
Build and run all tests:
```bash
make clean test
```
Build and run main app with valgrind:
```bash
make clean valgrind
```
# Usage:
Once builded, run without arguments to get updated help:
```bash
./wordsort.c
```
