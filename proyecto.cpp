#include <curses.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>

using namespace std;
WINDOW *win;

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
bool identifyCard(int**, int, int);
void position1(int,int);
void position2(int,int);
void position3(int,int);
void position4(int,int);
void position5(int,int);
int** newDeck(int**);
void game(int, int**);
double bet(double);
bool pairOfJacksOrBetter(int,int,int,int,int); 
bool threeOfAKind(int,int,int,int,int);
bool flush(int,int,int,int,int);
bool poker(int,int,int,int,int);
bool fullHouse(int,int,int,int,int);

int main(){
	IniVideo();
	int** deck = new int*[4];
	for (int i = 0; i < 4; i++){
		deck[i] = new int[13];
	}
	int** deckOfCards = new int*[4];
	for (int i = 0; i < 4; i++){
		deckOfCards[i] = new int[13];
	}
	deckOfCards = newDeck(deck);
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	bkgd(COLOR_PAIR(1));
	move(3,56);
	printw("WELCOME TO SANDINO'S VIDEO POKER");
	move(4,60);
	printw("MAY THE LUCK BE WITH YOU");
	position1(13,5);
	position2(13,5);
	position3(13,5);
	position4(13,5);
	position5(13,5);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 13; j++){
			printw("[");
			printw("%d",deckOfCards[i][j]);
			printw("] ");
		}
		printw("\n");
	}
	int key;
	game(key,deckOfCards);
	endwin();
	delete[] deckOfCards;
	deckOfCards = NULL;
	delete[] deck;
	deck = NULL;
	return 0;
}

void game(int key, int** deck){
	while((key = getch()) != 27){
		srand(time(0));
		int firstCard, typeOfFirstCard;
		firstCard = (rand() % 13);
		typeOfFirstCard = (rand() % 4);
		int secondCard, typeOfSecondCard;
		secondCard = (rand() % 13);
		typeOfSecondCard = (rand() % 4);
		int thirdCard, typeOfThirdCard;
		thirdCard = (rand() % 13);
		typeOfThirdCard = (rand() % 4);
		int fourthCard, typeOfFourthCard;
		fourthCard = (rand() % 13);
		typeOfFourthCard = (rand() % 4);
		int fifthCard, typeOfFifthCard;
		fifthCard = (rand() % 13);
		typeOfFifthCard = (rand() % 4);
		if (identifyCard(deck, firstCard, typeOfFirstCard)){
			position1(firstCard,typeOfFirstCard);
			deck[typeOfFirstCard][firstCard] = 14;
		}
		if (identifyCard(deck, secondCard, typeOfSecondCard)){
			position2(secondCard,typeOfSecondCard);
			deck[typeOfSecondCard][secondCard] = 14;
		}
		if (identifyCard(deck, thirdCard, typeOfThirdCard)){
			position3(thirdCard,typeOfThirdCard);
			deck[typeOfThirdCard][thirdCard] = 14;
		}
		if (identifyCard(deck, fourthCard, typeOfFourthCard)){
			position4(fourthCard,typeOfFourthCard);
			deck[typeOfFourthCard][fourthCard] = 14;
		}
		if (identifyCard(deck, fifthCard, typeOfFifthCard)){
			position5(fifthCard,typeOfFifthCard);
			deck[typeOfFifthCard][fifthCard] = 14;
			for (int i = 0; i < 4; i++){
				for (int j = 0; j < 13; j++){
					printw("[");
					printw("%d",deck[i][j]);
					printw("] ");
				}
				printw("\n");
			}
		}
		if(poker(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
			move(6,62);
			printw("YOU WIN WITH POKER");
		} else if (fullHouse(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
			move(6,60);
			printw("YOU WIN WITH FULL HOUSE");
		} else if(flush(typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
			move(6,62);
			printw("YOU WIN WITH FLUSH");
		} else if(threeOfAKind(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
			move(6,58);
			printw("YOU WIN WITH THREE OF A KIND");
		} else if(pairOfJacksOrBetter(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
			move(6,62);
			printw("YOU WIN WITH PAIR");
		} else {
			move(6,58);
			printw("        YOU LOSE :(         ");
		}
		refresh();
	}
}

bool identifyCard(int** deck, int card, int type){
	if(deck[type][card] != 14){
		return TRUE;
	} else {
		card = (rand() % 13);
		type = (rand() % 4);
		return identifyCard(deck,card,type);
	}
}

void position1(int number, int type){
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
	cards(number,x,y);
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
	if (number == 13){
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
	} else if (number == 0){
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
	} else if (number == 1){
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
	} else if(number == 2){
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
	} else if(number == 3){
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
	} else if(number == 4){
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
	} else if(number == 6){
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
	} else if(number == 7){
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
	} else if (number == 9){
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
	if(type == 5){
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
	} else if(type == 0){
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
	} else if (type == 1){
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
	} else if (type == 2){
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
	} else if (type == 3){
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

int** newDeck(int** deck){
	for (int row = 0; row < 4; row++){
		for (int column = 0; column < 13; column++){
			deck[row][column] = column;
		}
	}
	return deck;
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

bool pairOfJacksOrBetter(int first, int second, int third, int fourth, int fifth){
	if((first == 10 && second == 10) || (first == 10 && third == 10) || (first == 10 && fourth == 10) || (first == 10 && fifth == 10)){
		return TRUE;
	} else if((first == 11 && second == 11) || (first == 11 && third == 11) || (first == 11 && fourth == 11) || (first == 11 && fifth == 11)){
		return TRUE;
	} else if((first == 12 && second == 12) || (first == 12 && third == 12) || (first == 12 && fourth == 12) || (first == 12 && fifth == 12)){
		return TRUE;
	} else if((first == 0 && second == 0) || (first == 0 && third == 0) || (first == 0 && fourth == 0) || (first == 0 && fifth == 0)){
		return TRUE;
	} else if((second == 10 && third == 10) || (second == 10 && fourth == 10) || (second == 10 && fifth == 10)){
		return TRUE;
	} else if((second == 11 && third == 11) || (second == 11 && fourth == 11) || (second == 11 && fifth == 11)){
		return TRUE;
	} else if((second == 12 && third == 12) || (second == 12 && fourth == 12) || (second == 12 && fifth == 12)){
		return TRUE;
	} else if((second == 0 && third == 0) || (second == 0 && fourth == 0) || (second == 0 && fifth == 0)){
		return TRUE;
	} else if((third == 10 && fourth == 10) || (third == 10 && fifth == 10)){
		return TRUE;
	} else if((third == 11 && fourth == 11) || (third == 11 && fifth == 11)){
		return TRUE;
	} else if((third == 12 && fourth == 12) || (third == 12 && fifth == 12)){
		return TRUE;
	} else if((third == 0 && fourth == 0) || (third == 0 && fifth == 0)){
		return TRUE;
	} else if (fourth == 10 && fifth == 10){
		return TRUE;
	} else if (fourth == 11 && fifth == 11){
		return TRUE;
	} else if (fourth == 12 && fifth == 12){
		return TRUE;
	} else if (fourth == 0 && fifth == 0){
		return TRUE;
	} else {
		return FALSE;
	}
}

bool threeOfAKind(int first, int second, int third, int fourth, int fifth){
	if((first == second && first == third) || (first == second && first == fourth) || (first == second && first == fifth) || (first == third && first == fourth) || (first == third && first == fifth) || (first == fourth && first == fifth)){
		return TRUE;
	} else if ((second == third) && (second == fourth) || (second == third) && (second == fifth) || (second == fourth) && (second == fifth)){
		return TRUE;
	} else if((third == fourth) && (third == fifth)){
		return TRUE;
	} else {
		return FALSE;
	}
}

bool flush(int first, int second, int third, int fourth, int fifth){
	if((first == second) && (first == third) && (first == fourth) && (first == fifth)){
		return TRUE;
	} else {
		return FALSE;
	}
}

bool poker(int first, int second, int third, int fourth, int fifth){
	if (((first == second) && (first == third) && (first == fourth)) || ((first == second) && (first == third) && (first == fifth))){
		return TRUE;
	} else if (((second == third) && (second == fourth) && (second == fifth)) || ((second == first) && (second == fourth) && (second == fifth))){
		return TRUE;
	} else {
		return FALSE;
	}
}

bool fullHouse(int first, int second, int third, int fourth, int fifth){
	if (first == second && (third == fourth && third == fifth) || (first == third && (second == fourth && second == fifth)) || (first == fourth && (second == third && second == fifth)) || (first == fifth && (second == third && second == fourth))){
		return TRUE;
	} else if (second == third && (first == fourth && first == fifth) || (second == fourth && (first == third && first == fifth)) || (second == fifth && (first == third && first == fourth))){
		return TRUE;
	} else if (third == fourth && (first == second && first == fifth) || (third == fifth && (first == second && first == fourth))){
		return TRUE;
	} else if (fourth == fifth && (first == second && first == third)){
		return TRUE;
	} else {
		return FALSE;
	}
}