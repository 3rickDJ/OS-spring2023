#include <ncurses.h>

int main(){
	
	initscr(); // abre ventana

	int x = 10;
	int y = 10;
	move(y, x);

	printw("hola linux!");
	refresh();

	getch();

	erase();

	printw("hola ubuntu!");
	refresh();

	getch();

	endwin(); //cierra ventana

	return 0;
}
