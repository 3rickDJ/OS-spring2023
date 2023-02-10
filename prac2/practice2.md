# Practica N. 2

## Programación con ncurses

## Objetivo

Aprender a utilizar una librería que permite dar formato a la salida de un programa, tal como texto, color, posición, etc.

## Desarrollo

Para usar la primera versión:

```c++
#include <curses.h>
```

Para usar la nueva versión:

```c++
#include <ncurses.h>
```

Compilamos con:

```bash
gcc -o hola hola.c -l ncurses
```

Para controlar una ventana, precisamos de `stdscr` y `cursor` o `xterm`.

### Para Añadir un Carácter

Con `stdscr` es `addch()`

Con `cursor` es `waddch()`

### Para mover con coordenadas

Con `stdscr` es `move(y,x)`

Con `cursor` es `wmove(y,x)`

## Ejemplo

Movemos el cursor hacia una posición y colocamos un caracter.

```c++
char ch = 'a';
int x = 2, y = 2;

move(y, x);
addch(ch);
```

Podemos hacer lo mismo usando una sola instrucción, `mvaddch(y, x, ch)`:

```c++
char ch = 'a';
int x = 2, y = 2;

mvaddch(y, x, ch);
```

Una vez importada ncurses con `include`, llamamos a la siguiente función comenzar a usarla:

> esto es modo texto

```c++
#include <ncurses.h>

int main(){
	initscr(); // inicializa la libreria ncurses

	echo();

	noecho(); // no muestra nada en pantalla

	keypad(stdscr, TRUE); // permite mapeo del teclado

	cbreak(); // toma los caracteres de entrada una cada vez, no espera por ellos

	refresh(); // realiza los cambios en la ventana
	return 0;
}
```

## Ejemplo

Imprimimos texto en ventana con `ncurses`

```c++
#include <ncurses.h>

int main(){
	
	initscr(); // abre ventana
	printw("hola linux!");
	refresh();

	getch();

	endwin(); //cierra ventana

	return 0;
}
```

Para incluir colores

```c++
#include <ncurses.h>
#include <stdlib.h>

int main(){
	initscr();

	start_color();

	init_pair(1, COLOR_BLUE, COLOR_YELLOW);
	init_pair(2, COLOR_RED, COLOR_YELLOW);

	bkgd(COLOR_PAIR(2));
	attron(COLOR_PAIR(1)|A_UNDERLINE);

	move(10, 40);

	attron(A_REVERSE);

	printw("Hola, mundo");

	getch();

	endwin();

	exit(0);
}

```

### Lista de Colores

Nombre del Color   | Código
-------------------|--------
`COLOR_BLACK`      | 0
`COLOR_RED`        | 1
`COLOR_GREEN`      | 2
`COLOR_BROWN`      | 3
`COLOR_BLUE`       | 4
`COLOR_MAGENTA`    | 5
`COLOR_CYAN`       | 6
`COLOR_LIGHTGRAY`  | 7
`COLOR_DARKGRAY`   | 8
`COLOR_LIGHTRED`   | 9
`COLOR_LIGHTGREEN` | 10
`COLOR_YELLOW`     | 11
`COLOR_LIGHTBLUE`  | 12
`COLOR_PINK`       | 13
`COLOR_LIGHTCYAN`  | 14
`COLOR_WHITE`      | 15

Modo de Coloreado | Significado
------------------|-----------------------
A_NORMAL          | normal
A_STANDOUT        | mejor modo
A_UNDERLINE       | subrayado
A_REVERSE         | video inverso
A_BLINK           | parpadeo
A_DIM             | media intesidad
A_BOLD            | intensidad
A_INVIS           | caracteres no visibles
A_CHARTEXT        | ---

### Constantes

Nombre       | Símbolo
ACS_ULCORNER | ┌
ACS_LLCORNER | └
ACS_URCORNER | ┐
ACS_LRCORNER | ┘
ACS_HLINE    | ─
ACS_VLINE    | │
ACS_BLOCK    | ╬

## Consideraciones extra

Con `attroff(COLOR_PAIR(1))` apaga el estilo anterior.

`getmaxyx(stdscr, ymax, xmax)` para obtener el tamaño de la ventana
