#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

WINDOW *win; //manejo de una unica pantalla completa

void IniVideo(){
	win = initscr();
	start_color();
	clear();
	refresh();
	noecho();
	cbreak();
	keypad(win, TRUE);
}

void linesUpAndDown();
void linesOfSides();
void cards(int,int,int);
void position1(int);
int game(bool);
int number();

int main(){	
	IniVideo();
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	bkgd(COLOR_PAIR(1));
	move(3,56);
	printw("WELCOME TO SANDINO'S VIDEO POKER");
	move(4,60);
	printw("MAY THE LUCK BE WITH YOU");
	position1(1);
	refresh();
	getch();
	endwin();
	return 0;
}

void position1(int number){
	move(7,4);
	printw("_____________________");
	move(18,4);
	printw("_____________________");
	for(int i = 8; i <= 18; i++){
		move(i,4);
		printw("|");
	}
	for(int i = 8; i <= 18; i++){
		move(i,24);
		printw("|");
	}
	int x = 9, y = 7;
	cards(number,x,y);
}

void position2(int number){
	move(7,4);
	printw("_____________________");
	move(18,4);
	printw("_____________________");
	for(int i = 8; i <= 18; i++){
		move(i,4);
		printw("|");
	}
	for(int i = 8; i <= 18; i++){
		move(i,24);
		printw("|");
	}
	int x = 9, y = 7;
	cards(number,x,y);
}

void position3(int number){
	move(7,4);
	printw("_____________________");
	move(18,4);
	printw("_____________________");
	for(int i = 8; i <= 18; i++){
		move(i,4);
		printw("|");
	}
	for(int i = 8; i <= 18; i++){
		move(i,24);
		printw("|");
	}
	int x = 9, y = 7;
	cards(number,x,y);
}

void position4(int number){
	move(7,4);
	printw("_____________________");
	move(18,4);
	printw("_____________________");
	for(int i = 8; i <= 18; i++){
		move(i,4);
		printw("|");
	}
	for(int i = 8; i <= 18; i++){
		move(i,24);
		printw("|");
	}
	int x = 9, y = 7;
	cards(number,x,y);
}

void position5(int number){
	move(7,4);
	printw("_____________________");
	move(18,4);
	printw("_____________________");
	for(int i = 8; i <= 18; i++){
		move(i,4);
		printw("|");
	}
	for(int i = 8; i <= 18; i++){
		move(i,24);
		printw("|");
	}
	int x = 9, y = 7;
	cards(number,x,y);
}

void linesUpAndDown(){
	move(7,29);
	printw("_____________________");
	move(7,56);
	printw("_____________________");
	move(7,83);
	printw("_____________________");
	move(7,110);
	printw("_____________________");
	move(18,29);
	printw("_____________________");
	move(18,56);
	printw("_____________________");
	move(18,83);
	printw("_____________________");
	move(18,110);
	printw("_____________________");
}

void linesOfSides(){
	
	for(int i = 8; i <= 18; i++){
		move(i,29);
		printw("|");
	}
	for(int i = 8; i <= 18; i++){
		move(i,49);
		printw("|");
	}
	for(int i = 8; i <= 18; i++){
		move(i,56);
		printw("|");
	}
	for(int i = 8; i <= 18; i++){
		move(i,76);
		printw("|");
	}
	for(int i = 8; i <= 18; i++){
		move(i,83);
		printw("|");
	}
	for(int i = 8; i <= 18; i++){
		move(i,103);
		printw("|");
	}
	for(int i = 8; i <= 18; i++){
		move(i,110);
		printw("|");
	}
	for(int i = 8; i <= 18; i++){
		move(i,130);
		printw("|");
	}
}

void cards(int number, int x, int y){
	if (number == 1){
		move(x,y);
		printw("*******\n");
		move(x+1,y);
		printw("*     *\n");
		move(x+2,y);
		printw("*     *\n");
		move(x+3,y);
		printw("*******\n");
		move(x+4,y);
		printw("*     *\n");
		move(x+5,y);
		printw("*     *\n");
		move(x+6,y);
		printw("*     *");
	} else if (number == 2){
		printw("*******\n");
		printw("      *\n");
		printw("      *\n");
		printw("*******\n");
		printw("*\n");
		printw("*\n");
		printw("*******");
	} else if(number == 3){
		printw("*******\n");
		printw("      *\n");
		printw("      *\n");
		printw("*******\n");
		printw("      *\n");
		printw("      *\n");
		printw("*******");
	} else if(number == 4){
		printw("*     *\n");
		printw("*     *\n");
		printw("*     *\n");
		printw("*******\n");
		printw("      *\n");
		printw("      *\n");
		printw("      *");
	} else if(number == 5){
		printw("*******\n");
		printw("*\n");
		printw("*\n");
		printw("*******\n");
		printw("      *\n");
		printw("      *\n");
		printw("*******");
	} else if(number == 6){
		printw("*******\n");
		printw("*\n");
		printw("*\n");
		printw("*******\n");
		printw("*     *\n");
		printw("*     *\n");
		printw("*******");
	} else if(number == 7){
		printw("*******\n");
		printw("      *");
		printw("      *");
		printw("      *");
		printw("      *");
		printw("      *");
		printw("      *");
	} else if(number == 8){
		printw("*******\n");
		printw("*     *\n");
		printw("*     *\n");
		printw("*******\n");
		printw("*     *\n");
		printw("*     *\n");
		printw("*******");
	} else if(number == 9){
		printw("*******\n");
		printw("*     *\n");
		printw("*     *\n");
		printw("*******\n");
		printw("      *\n");
		printw("      *\n");
		printw("*******");
	} else if(number == 10){
		printw("*******\n");
		printw("   *\n");
		printw("   *\n");
		printw("   *\n");
		printw("   *\n");
		printw("   *\n");
		printw("****");
	} else if(number == 11){
		printw("*******\n");
		printw("*     *\n");
		printw("*     *\n");
		printw("*     *\n");
		printw("*   * *\n");
		printw("*******\n");
		printw("      *");
	} else if (number == 12){
		printw("*   *\n");
		printw("*  *\n");
		printw("* *\n");
		printw("**\n");
		printw("* *\n");
		printw("*  *\n");
		printw("*   *");
	}
}

/*int game(bool start){
	if (start){
		int card = rand %14;
		srand(time(0));
		return card;
	}
}*/
