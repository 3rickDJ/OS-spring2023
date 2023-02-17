# OS

## Practice 1. Curiosidades de C

### Dependencies

+ gcc (c compiler)

**(if you are on a Debian based system eg. Ubuntu) To install it type in your terminal**
```bash
sudo apt-get install gcc
```

### Compile Source Code
First compile the source file with the `gcc` compiler

```bash
gcc main.c -o main.exe
```

Now you will have a `main.exe` file in your current diretory

## Practice 2. Programación con ncurses

### Dependencies

- ncurses library

```bash
sudo apt install libncurses5-dev libncursesw5-dev
```

### Compile Source Code

```bash
gcc -o main main.c -l ncurses
```

## Practice 3. Argumentos para Main

There is nothing special to run this practice.

## How to Execute Binary Files

In your shell type
```bash
./main.exe
```

## Some useful links

- [Ideone](https://ideone.com/) for compile and run `.c` files online.
- [Deepnote](https://www.deepnote.com) a "online ubuntu terminal".
