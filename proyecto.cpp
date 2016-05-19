#include <curses.h>
#include <time.h>
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
void typeOfCard(int,int,int);
void position1(int);
void position2(int);
void position3(int);
void position4(int);
void position5(int);
int game(bool);
int number();
void deck();

int main(){	
	IniVideo();
	int exit;
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	bkgd(COLOR_PAIR(1));
	deck();
	move(3,56);
	printw("WELCOME TO SANDINO'S VIDEO POKER");
	move(4,60);
	printw("MAY THE LUCK BE WITH YOU");
	position1(0);
	position2(0);
	position3(0);
	position4(0);
	position5(0);
	while((exit = getch()) != 27){
		srand(time(0));
		int firstCard;
		firstCard = 1 + (rand() % 12);
		int secondCard;
		secondCard = 1 + (rand() % 12);
		int thirdCard;
		thirdCard = 1 + (rand() % 12);
		int fourthCard;
		fourthCard = 1 + (rand() % 12);
		int fifthCard;
		fifthCard = 1 + (rand() % 12);
		position1(firstCard);
		position2(secondCard);
		position3(thirdCard);
		position4(fourthCard);
		position5(fifthCard);
		refresh();
	}
	endwin();
	return 0;
}

void position1(int numberOfCard, int type){
	move(7,4);
	printw("_________________________");
	move(21,4);
	printw("_________________________");
	for(int i = 8; i <= 21; i++){
		move(i,4);
		printw("|");
	}
	for(int i = 8; i <= 21; i++){
		move(i,28);
		printw("|");
	}
	int x = 9, y = 7;
	cards(numberOfCard,x,y);
	typeOfCard();
}

void position2(int number){
	move(7,30);
	printw("_________________________");
	move(21,30);
	printw("_________________________");
	for(int i = 8; i <= 21; i++){
		move(i,30);
		printw("|");
	}
	for(int i = 8; i <= 21; i++){
		move(i,54);
		printw("|");
	}
	int x = 9, y = 33;
	cards(number,x,y);
}

void position3(int number){
	move(7,56);
	printw("_________________________");
	move(21,56);
	printw("_________________________");
	for(int i = 8; i <= 21; i++){
		move(i,56);
		printw("|");
	}
	for(int i = 8; i <= 21; i++){
		move(i,80);
		printw("|");
	}
	int x = 9, y = 59;
	cards(number,x,y);
}

void position4(int number){
	move(7,83);
	printw("_________________________");
	move(21,83);
	printw("_________________________");
	for(int i = 8; i <= 21; i++){
		move(i,83);
		printw("|");
	}
	for(int i = 8; i <= 21; i++){
		move(i,107);
		printw("|");
	}
	int x = 9, y = 86;
	cards(number,x,y);
}

void position5(int number){
	move(7,110);
	printw("_________________________");
	move(21,110);
	printw("_________________________");
	for(int i = 8; i <= 21; i++){
		move(i,110);
		printw("|");
	}
	for(int i = 8; i <= 21; i++){
		move(i,134);
		printw("|");
	}
	int x = 9, y = 113;
	cards(number,x,y);
}

void cards(int number, int x, int y){
	if (number == 0){
		move(x,y);
		printw("*******************");
		move(x+1,y);
		printw("*******************");
		move(x+2,y);
		printw("*******************");
		move(x+3,y);
		printw("*******************");
		move(x+4,y);
		printw("*******************");
		move(x+5,y);
		printw("*******************");
		move(x+6,y);
		printw("*******************");
		move(x+7,y);
		printw("*******************");
		move(x+8,y);
		printw("*******************");
		move(x+9,y);
		printw("*******************");
		move(x+10,y);
		printw("*******************");
		move(x+11,y);
		printw("*******************");
	} else if (number == 1){
		move(x,y);
		printw("********           ");
		move(x+1,y);
		printw("*      *           ");
		move(x+2,y);
		printw("*      *           ");
		move(x+3,y);
		printw("*      *           ");
		move(x+4,y);
		printw("*      *           ");
		move(x+5,y);
		printw("********           ");
		move(x+6,y);
		printw("*      *           ");
		move(x+7,y);
		printw("*      *           ");
		move(x+8,y);
		printw("*      *           ");
		move(x+9,y);
		printw("*      *           ");
		move(x+10,y);
		printw("*      *           ");
		move(x+11,y);
		printw("*      *           ");
	} else if (number == 2){
		move(x,y);
		printw("********           ");
		move(x+1,y);
		printw("       *           ");
		move(x+2,y);
		printw("       *           ");
		move(x+3,y);
		printw("       *           ");
		move(x+4,y);
		printw("       *           ");
		move(x+5,y);
		printw("********           ");
		move(x+6,y);
		printw("*                  ");
		move(x+7,y);
		printw("*                  ");
		move(x+8,y);
		printw("*                  ");
		move(x+9,y);
		printw("*                  ");
		move(x+10,y);
		printw("*                  ");
		move(x+11,y);
		printw("********           ");
	} else if(number == 3){
		move(x,y);
		printw("********           ");
		move(x+1,y);
		printw("       *           ");
		move(x+2,y);
		printw("       *           ");
		move(x+3,y);
		printw("       *           ");
		move(x+4,y);
		printw("       *           ");
		move(x+5,y);
		printw("********           ");
		move(x+6,y);
		printw("       *           ");
		move(x+7,y);
		printw("       *           ");
		move(x+8,y);
		printw("       *           ");
		move(x+9,y);
		printw("       *           ");
		move(x+10,y);
		printw("       *           ");
		move(x+11,y);
		printw("********           ");
	} else if(number == 4){
		move(x,y);
		printw("*      *           ");
		move(x+1,y);
		printw("*      *           ");
		move(x+2,y);
		printw("*      *           ");
		move(x+3,y);
		printw("*      *           ");
		move(x+4,y);
		printw("*      *           ");
		move(x+5,y);
		printw("********           ");
		move(x+6,y);
		printw("       *           ");
		move(x+7,y);
		printw("       *           ");
		move(x+8,y);
		printw("       *           ");
		move(x+9,y);
		printw("       *           ");
		move(x+10,y);
		printw("       *           ");
		move(x+11,y);
		printw("       *           ");
	} else if(number == 5){
		move(x,y);
		printw("********           ");
		move(x+1,y);
		printw("*                  ");
		move(x+2,y);
		printw("*                  ");
		move(x+3,y);
		printw("*                  ");
		move(x+4,y);
		printw("*                  ");
		move(x+5,y);
		printw("********           ");
		move(x+6,y);
		printw("       *           ");
		move(x+7,y);
		printw("       *           ");
		move(x+8,y);
		printw("       *           ");
		move(x+9,y);
		printw("       *           ");
		move(x+10,y);
		printw("       *           ");
		move(x+11,y);
		printw("********           ");
	} else if(number == 6){
		move(x,y);
		printw("********           ");
		move(x+1,y);
		printw("*                  ");
		move(x+2,y);
		printw("*                  ");
		move(x+3,y);
		printw("*                  ");
		move(x+4,y);
		printw("*                  ");
		move(x+5,y);
		printw("********           ");
		move(x+6,y);
		printw("*      *           ");
		move(x+7,y);
		printw("*      *           ");
		move(x+8,y);
		printw("*      *           ");
		move(x+9,y);
		printw("*      *           ");
		move(x+10,y);
		printw("*      *           ");
		move(x+11,y);
		printw("********           ");
	} else if(number == 7){
		move(x,y);
		printw("********           ");
		move(x+1,y);
		printw("       *           ");
		move(x+2,y);
		printw("       *           ");
		move(x+3,y);
		printw("       *           ");
		move(x+4,y);
		printw("       *           ");
		move(x+5,y);
		printw("       *           ");
		move(x+6,y);
		printw("       *           ");
		move(x+7,y);
		printw("       *           ");
		move(x+8,y);
		printw("       *           ");
		move(x+9,y);
		printw("       *           ");
		move(x+10,y);
		printw("       *           ");
		move(x+11,y);
		printw("       *           ");
	} else if(number == 8){
		move(x,y);
		printw("********           ");
		move(x+1,y);
		printw("*      *           ");
		move(x+2,y);
		printw("*      *           ");
		move(x+3,y);
		printw("*      *           ");
		move(x+4,y);
		printw("*      *           ");
		move(x+5,y);
		printw("********           ");
		move(x+6,y);
		printw("*      *           ");
		move(x+7,y);
		printw("*      *           ");
		move(x+8,y);
		printw("*      *           ");
		move(x+9,y);
		printw("*      *           ");
		move(x+10,y);
		printw("*      *           ");
		move(x+11,y);
		printw("********           ");
	} else if(number == 9){
		move(x,y);
		printw("********           ");
		move(x+1,y);
		printw("*      *           ");
		move(x+2,y);
		printw("*      *           ");
		move(x+3,y);
		printw("*      *           ");
		move(x+4,y);
		printw("*      *           ");
		move(x+5,y);
		printw("********           ");
		move(x+6,y);
		printw("       *           ");
		move(x+7,y);
		printw("       *           ");
		move(x+8,y);
		printw("       *           ");
		move(x+9,y);
		printw("       *           ");
		move(x+10,y);
		printw("       *           ");
		move(x+11,y);
		printw("********           ");
	} else if(number == 10){
		move(x,y);
		printw("********           ");
		move(x+1,y);
		printw("    *              ");
		move(x+2,y);
		printw("    *              ");
		move(x+3,y);
		printw("    *              ");
		move(x+4,y);
		printw("    *              ");
		move(x+5,y);
		printw("    *              ");
		move(x+6,y);
		printw("    *              ");
		move(x+7,y);
		printw("    *              ");
		move(x+8,y);
		printw("    *              ");
		move(x+9,y);
		printw("    *              ");
		move(x+10,y);
		printw("    *              ");
		move(x+11,y);
		printw("*****              ");
	} else if(number == 11){
		move(x,y);
		printw("********           ");
		move(x+1,y);
		printw("*      *           ");
		move(x+2,y);
		printw("*      *           ");
		move(x+3,y);
		printw("*      *           ");
		move(x+4,y);
		printw("*      *           ");
		move(x+5,y);
		printw("*      *           ");
		move(x+6,y);
		printw("*      *           ");
		move(x+7,y);
		printw("*      *           ");
		move(x+8,y);
		printw("*      *           ");
		move(x+9,y);
		printw("*    * *           ");
		move(x+10,y);
		printw("********           ");
		move(x+11,y);
		printw("        *          ");
	} else if (number == 12){
		move(x,y);
		printw("*      *           ");
		move(x+1,y);
		printw("*     *            ");
		move(x+2,y);
		printw("*    *             ");
		move(x+3,y);
		printw("*  *               ");
		move(x+4,y);
		printw("* *                ");
		move(x+5,y);
		printw("**                 ");
		move(x+6,y);
		printw("* *                ");
		move(x+7,y);
		printw("*  *               ");
		move(x+8,y);
		printw("*   *              ");
		move(x+9,y);
		printw("*    *             ");
		move(x+10,y);
		printw("*     *            ");
		move(x+11,y);
		printw("*      *           ");
	}
}

void typeOfCard(int type, int x, int y){
	if(type == 1){
		move(x,y);
		printw("           ");
		move(x+1,y);
		printw("     *     ");
		move(x+2,y);
		printw("    * *    ");
		move(x+3,y);
		printw("   *   *   ");
		move(x+4,y);
		printw("  *     *  ");
		move(x+5,y);
		printw(" *       * ");
		move(x+6,y);
		printw("*  *   *  *");
		move(x+7,y);
		printw("* * * * * *");
		move(x+8,y);
		printw(" *  * *  * ");
		move(x+9,y);
		printw("    * *    ");
		move(x+10,y);
		printw("    ***    ");
		move(x+11,y);
		printw("           ");
	} else if (type == 2){
		move(x,y);
		printw(" ***   *** ");
		move(x+1,y);
		printw("    * *    ");
		move(x+2,y);
		printw("     *     ");
		move(x+3,y);
		printw("   *   *   ");
		move(x+4,y);
		printw("  *     *  ");
		move(x+5,y);
		printw(" *       * ");
		move(x+6,y);
		printw("*  *   *  *");
		move(x+7,y);
		printw("* * * * * *");
		move(x+8,y);
		printw(" *  * *  * ");
		move(x+9,y);
		printw("    * *    ");
		move(x+10,y);
		printw("    ***    ");
		move(x+11,y);
		printw("           ");
	} else if (type == 3){
		printw("    *    \n");
		printw("   * *   \n");
		printw("  *   *  \n");
		printw(" *     * \n");
		printw("*       *\n");
		printw(" *     * \n");
		printw("  *   *  \n");
		printw("   * *   \n");
		printw("    *      ");
	} else if (type == 4){
		printw("*********");
		printw("*********");
		printw("*********");
		printw("*********");
		printw("*********");
		printw("*********");
		printw("***   ***");
		printw("***   ***");
		printw("***   ***");
	}
}
/*
int game(bool start){
	if (start){
		int card = rand %14;
		srand(time(0));
		return card;
	}
}*/

void deck(){
	int** deckOfCards;
	int row = 4, column = 13;
	deckOfCards = new int*[row];
	for (int i = 0; i < row; ++i){
		deckOfCards[i] = new int[column];
	}
	for (int i = 0; i < row; ++i){
			for (int j = 0; j < column; ++j){
				//printw("[" + deckOfCards[i][j] + "]	");
			}
			printw("\n");
		}
}