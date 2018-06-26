## Table of contents

* [Introduction](#introduction)
* [Requirements](#requirements)
* [Building fast-xinci](#building-fast-xinci)
* [Examples](#examples)
   * [New words discovery](#new-words-discovery)
   * [Words extraction](#words-extraction)
* [Full documentation](#full-documentation)
* [References](#references)

## Introduction

[xinci] is a C++ library for Chinese new words discovery.
Also see Python package [xinci](https://github.com/Lapis-Hong/xinci)

还在嫌Python包 [xinci](https://github.com/Lapis-Hong/xinci)速度不都快吗？
C++版 新词发现算法来啦，赶快来star吧！



## Requirements

Generally, **fast-xinci** builds on modern Mac OS and Linux distributions.
Since it uses some C++11 features, it requires a compiler with good C++11 support.
These include :

* (g++-4.7.2 or newer) or (clang-3.3 or newer)
*  **cmake** at least version 2.8.9.



## Building fast-xinci

```
$ git clone https://github.com/Lapis-Hong/fast-xinci.git
$ cd fast-xinci
$ mkdir build && cd build && cmake ..
$ make
```
This will create the fast-xinci binary and also all relevant libraries (shared, static, PIC).



## Examples

This library has two main use cases: Chinese words extraction and Chinese new words discovery.


### 1. New words discovery

```
$ ./xinci -input data.txt
```
where `data.txt` is a training file containing `UTF-8` encoded text.
The program will save one file: `result.txt`
`result.txt` is a text file containing the new words and word counts, one per line.

### 2. Words extraction

```
$ ./xinci -input data.txt -a
```


## Full documentation

Invoke a command without arguments or -h to list available arguments and their default values:

```
$ ./xinci
Empty input path.
Usage:
    xinci <args>

The following arguments are mandatory:
  -input              input corpus file path

The following arguments are optional:
  -output             output result file path [result.txt]
  -commonWordsDic     common words dic file path [common.dic]
  -minCandidateLen    min candidate word length [2]
  -maxCandidateLen    max candidate word length [5]
  -leastWordCount     least word count threshold [5]
  -solidRate          solid rate threshold [0.018]
  -entropyRate        entropy rate threshold [1.92]
  -a                  set to all words mode, otherwise only new words [0]

```
## References

https://github.com/Lapis-Hong/xinci

https://github.com/GeorgeBourne/grid



