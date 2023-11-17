# My listing command (ls)

## Overview

This project aims to recreate the Unix `ls` command with options `[-lRdrt]`. It's written in C and compiled with a Makefile that includes `re`, `clean`, and `fclean` rules.

## Compilation

Compile the project using the provided Makefile:

```bash
make all
```
## Usage

```bash
./my_ls [-lRdrt] [FILE]...
```

## Result 
![image](https://i.imgur.com/nZPQK4j.png)

## 🚀 Bonus
- Default alphabetical sorting if no sorting options are used (-t, -r)
