#include <curses.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>

using namespace std;
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
void position1(int,int);
void position2(int,int);
void position3(int,int);
void position4(int,int);
void position5(int,int);
int game(int);
double bet(double);
bool pairOfJacksOrBetter(int,int,int,int,int);

int main(){	
	IniVideo();
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	bkgd(COLOR_PAIR(1));
	move(3,56);
	printw("WELCOME TO SANDINO'S VIDEO POKER");
	move(4,60);
	printw("MAY THE LUCK BE WITH YOU");
	position1(0,0);
	position2(0,0);
	position3(0,0);
	position4(0,0);
	position5(0,0);
	int key;
	game(key);
	endwin();
	return 0;
}

int game(int key){
	while((key = getch()) != 27){
		srand(time(0));
		int firstCard, typeOfFirstCard;
		firstCard = 1 + (rand() % 12);
		typeOfFirstCard = 1 + (rand() % 3);
		int secondCard, typeOfSecondCard;
		secondCard = 1 + (rand() % 12);
		typeOfSecondCard = 1 + (rand() % 3);
		int thirdCard, typeOfThirdCard;
		thirdCard = 1 + (rand() % 12);
		typeOfThirdCard = 1 + (rand() % 3);
		int fourthCard, typeOfFourthCard;
		fourthCard = 1 + (rand() % 12);
		typeOfFourthCard = 1 + (rand() % 3);
		int fifthCard, typeOfFifthCard;
		fifthCard = 1 + (rand() % 12);
		typeOfFifthCard = 1 + (rand() % 3);
		if(firstCard == secondCard && typeOfFirstCard == typeOfSecondCard){

		}
		position1(firstCard,typeOfFirstCard);
		position2(secondCard,typeOfSecondCard);
		position3(thirdCard,thirdCard);
		position4(fourthCard,typeOfFourthCard);
		position5(fifthCard,fifthCard);
		double money;
		money = 10000;
		move(2,10);
		printw("%d",money);
		if(pairOfJacksOrBetter(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
			move(6,62);
			printw("YOU WIN WITH PAIR");
		} else {
			move(6,62);
			printw("                 ");			
		}
		refresh();
	}
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
	x = 9; y = 17;
	typeOfCard(type,x,y);
}

void position2(int number, int type){
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
	x = 9; y = 43;
	typeOfCard(type,x,y);
}

void position3(int number,int type){
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
	x = 9, y = 69;
	typeOfCard(type,x,y);
}

void position4(int number, int type){
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
	x = 9, y = 96;
	typeOfCard(type,x,y);
}

void position5(int number, int type){
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
	x = 9, y = 122;
	typeOfCard(type,x,y);
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
	} else if (number == 10){
		move(x,y);
		printw("  * *****          ");
		move(x+1,y);
		printw(" ** *   *          ");
		move(x+2,y);
		printw("* * *   *          ");
		move(x+3,y);
		printw("  * *   *          ");
		move(x+4,y);
		printw("  * *   *          ");
		move(x+5,y);
		printw("  * *   *          ");
		move(x+6,y);
		printw("  * *   *          ");
		move(x+7,y);
		printw("  * *   *          ");
		move(x+8,y);
		printw("  * *   *          ");
		move(x+9,y);
		printw("  * *   *          ");
		move(x+10,y);
		printw("  * *   *          ");
		move(x+11,y);
		printw("  * *****          ");
	} else if(number == 11){
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
	} else if(number == 12){
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
	} else if (number == 13){
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
	if(type == 0){
		move(x,y);
		printw("***********");
		move(x+1,y);
		printw("***********");
		move(x+2,y);
		printw("***********");
		move(x+3,y);
		printw("***********");
		move(x+4,y);
		printw("***********");
		move(x+5,y);
		printw("***********");
		move(x+6,y);
		printw("***********");
		move(x+7,y);
		printw("***********");
		move(x+8,y);
		printw("***********");
		move(x+9,y);
		printw("***********");
		move(x+10,y);
		printw("***********");
		move(x+11,y);
		printw("***********");
	}
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
		printw("           ");
		move(x+1,y);
		printw("           ");
		move(x+2,y);
		printw(" ***   *** ");
		move(x+3,y);
		printw("*   * *   *");
		move(x+4,y);
		printw("*    *    *");
		move(x+5,y);
		printw(" *       * ");
		move(x+6,y);
		printw("  *     *  ");
		move(x+7,y);
		printw("   *   *   ");
		move(x+8,y);
		printw("    * *    ");
		move(x+9,y);
		printw("     *     ");
		move(x+10,y);
		printw("           ");
		move(x+11,y);
		printw("           ");
	} else if (type == 3){
		move(x,y);
		printw("     *     ");
		move(x+1,y);
		printw("    * *    ");
		move(x+2,y);
		printw("   *   *   ");
		move(x+3,y);
		printw("  *     *  ");
		move(x+4,y);
		printw(" *       * ");
		move(x+5,y);
		printw("*         *");
		move(x+6,y);
		printw(" *       * ");
		move(x+7,y);
		printw("  *     *  ");
		move(x+8,y);
		printw("   *   *   ");
		move(x+9,y);
		printw("    * *    ");
		move(x+10,y);
		printw("     *     ");
		move(x+11,y);
		printw("           ");
	} else if (type == 4){
		move(x,y);
		printw("     *     ");
		move(x+1,y);
		printw("    ***    ");
		move(x+2,y);
		printw("   * * *   ");
		move(x+3,y);
		printw("  *  *  *  ");
		move(x+4,y);
		printw(" *   *   * ");
		move(x+5,y);
		printw("*    *    *");
		move(x+6,y);
		printw(" *   *   * ");
		move(x+7,y);
		printw("  *  *  *  ");
		move(x+8,y);
		printw("   * * *   ");
		move(x+9,y);
		printw("    ***    ");
		move(x+10,y);
		printw("     *     ");
		move(x+11,y);
		printw("           ");
	}
}

double bet(double money){
	ofstream entrada;
	entrada.open("bet.txt",ios::out);
	if(!entrada.fail()){
		entrada << money << endl;
		entrada.close();
	}
	ifstream salida;
	salida.open("bet.txt",ios::in);
	salida >> money;
	return money;
}

bool pairOfJacksOrBetter(int first,int second,int third,int fourth,int fifth){
	if((first == 11 && second == 11) || (first == 11 && third == 11) || (first == 11 && fourth == 11) || (first == 11 && fifth == 11)){
		return TRUE;
	} else if((first == 12 && second == 12) || (first == 12 && third == 12) || (first == 12 && fourth == 12) || (first == 12 && fifth == 12)){
		return TRUE;
	} else if((first == 13 && second == 13) || (first == 13 && third == 13) || (first == 13 && fourth == 13) || (first == 13 && fifth == 13)){
		return TRUE;
	} else if((first == 1 && second == 1) || (first == 1 && third == 1) || (first == 1 && fourth == 1) || (first == 1 && fifth == 1)){
		return TRUE;
	} else if((second == 11 && third == 11) || (second == 11 && fourth == 11) || (second == 11 && fifth == 11)){
		return TRUE;
	} else if((second == 12 && third == 12) || (second == 12 && fourth == 12) || (second == 12 && fifth == 12)){
		return TRUE;
	} else if((second == 13 && third == 13) || (second == 13 && fourth == 13) || (second == 13 && fifth == 13)){
		return TRUE;
	} else if((second == 1 && third == 1) || (second == 1 && fourth == 1) || (second == 1 && fifth == 1)){
		return TRUE;
	} else if((third == 11 && fourth == 11) || (third == 11 && fifth == 11)){
		return TRUE;
	} else if((third == 12 && fourth == 12) || (third == 12 && fifth == 12)){
		return TRUE;
	} else if((third == 13 && fourth == 13) || (third == 13 && fifth == 13)){
		return TRUE;
	} else if((third == 1 && fourth == 1) || (third == 1 && fifth == 1)){
		return TRUE;
	} else if (fourth == 11 && fifth == 11){
		return TRUE;
	} else if (fourth == 12 && fifth == 12){
		return TRUE;
	} else if (fourth == 13 && fifth == 13){
		return TRUE;
	} else if (fourth == 1 && fifth == 1){
		return TRUE;
	} else {
		return FALSE;
	}
}

