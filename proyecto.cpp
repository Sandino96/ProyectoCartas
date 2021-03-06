#include <curses.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstdlib>

using std::string;
using std::ofstream;
using std::endl;
using std::ios;
using std::ifstream;

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
void rulesOfBet();
bool identifyCard(int**, int, int);
void position1(int,int);
void position2(int,int);
void position3(int,int);
void position4(int,int);
void position5(int,int);
void virtualBank(int);
int** newDeck(int**);
void betOn(int);
int betIn();
bool pairOfJacksOrBetter(int,int,int,int,int); 
bool twoPair(int,int,int,int,int);
bool threeOfAKind(int,int,int,int,int);
bool flush(int,int,int,int,int);
bool poker(int,int,int,int,int);
bool fullHouse(int,int,int,int,int);
bool straight(int,int,int,int,int);
bool royalFlush(int,int,int,int,int,int,int,int,int,int);
bool straightFlush(int,int,int,int,int,int,int,int,int,int);

int main(int argc, char*argv[]){
	IniVideo();
	echo();
	int** deck = new int*[4];
	for (int i = 0; i < 4; i++){
		deck[i] = new int[13];
	}
	deck = newDeck(deck);
	int** cardsOnTable = new int*[2];
	for (int i = 0; i < 2; i++){
		cardsOnTable[i] = new int[5];
	}
	int* chanceCards = new int[10];
	int betTemporal = 0;
	char digit;
	int bet = 0;
	string money = "";
	int firstCard, typeOfFirstCard;
	int secondCard, typeOfSecondCard;
	int thirdCard, typeOfThirdCard;
	int fourthCard, typeOfFourthCard;
	int fifthCard, typeOfFifthCard;
	char key;
	echo();
	printw("Press any key to continue...");
	while((key = getch()) != 27) {
		
		noecho();
		betTemporal = 0;
		digit = '\0';
		bet = 0;
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
		virtualBank(0);
		rulesOfBet();
		move(24,50);
		printw("NEW GAME  (TAP ===> N or n)");
		move(26,50);
		printw("LOAD GAME (TAP ===> L or l)                                        ");
		move(28,50);
		printw("EXIT      (TAP ===> ESC)");
		move(30,50);
		printw("OPTION: ");
		printw("%c",key);
		noecho();
		if(key == 110 || key == 78){
			move(26,50);
			printw("                           ");
			move(28,50);
			printw("                           ");
			move(30,50);
			printw("                           ");
			betOn(1000);
			betTemporal = betIn();
			virtualBank(betTemporal);
			move(24,50);
			printw("                           ");
			move(24,50);
			echo();
			printw("YOUR BET: ");
			while((digit = getch())!= 10){
				if(digit > 47 && digit < 58)
					money.push_back(digit);
			}
			noecho();
			bet = atoi(money.c_str());
			betTemporal = betTemporal - bet;
			virtualBank(betTemporal);
			srand(time(0));
			firstCard = (rand() % 13);
			typeOfFirstCard = (rand() % 4);
			secondCard = (rand() % 13);
			typeOfSecondCard = (rand() % 4);
			thirdCard = (rand() % 13);
			typeOfThirdCard = (rand() % 4);
			fourthCard = (rand() % 13);
			typeOfFourthCard = (rand() % 4)	;
			fifthCard = (rand() % 13);
			typeOfFifthCard = (rand() % 4);
			cardsOnTable[0][0] = firstCard;
			cardsOnTable[1][0] = typeOfFirstCard;
			cardsOnTable[0][1] = secondCard;
			cardsOnTable[1][1] = typeOfSecondCard;
			cardsOnTable[0][2] = thirdCard;
			cardsOnTable[1][2] = typeOfThirdCard;
			cardsOnTable[0][3] = fourthCard;
			cardsOnTable[1][3] = typeOfFourthCard;
			cardsOnTable[0][4] = fifthCard;
			cardsOnTable[1][4] = typeOfFifthCard;
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
			}
			move(26,50);
			echo();
			char decision;
			printw("Do you wish to hold any card[Y/N]: ");
			decision = getch();
			if(decision == 89 || decision == 121){
				move(26,50);
				char numbers;
				int sizeChangeCards = 0;
				printw("Cards you wish to hold [Enter the numbers in this format = 123]: ");
				while((numbers=getch()) != 10){
					chanceCards[sizeChangeCards] = numbers;
					sizeChangeCards++;
				}
				noecho();
				for (int i = 0; chanceCards[i] ; i++){
					if (chanceCards[i] == 49){
						firstCard = (rand() % 13);
						typeOfFirstCard = (rand() % 4);
						if (identifyCard(deck, firstCard, typeOfFirstCard)){
							position1(firstCard,typeOfFirstCard);
							deck[firstCard][typeOfFirstCard] = 14;
						}
					} else if (chanceCards[i] == 50){
						secondCard = (rand() % 13);
						typeOfSecondCard = (rand() % 4);
						if (identifyCard(deck, secondCard, typeOfSecondCard)){
							position2(secondCard,typeOfSecondCard);
							deck[typeOfSecondCard][secondCard] = 14;
						}
					} else if (chanceCards[i] == 51){
						thirdCard = (rand() % 13);
						typeOfThirdCard = (rand() % 4);
						if (identifyCard(deck, thirdCard, typeOfThirdCard)){
							position3(thirdCard,typeOfThirdCard);
							deck[typeOfThirdCard][thirdCard] = 14;
						}
					} else if (chanceCards[i] == 52){
						fourthCard = (rand() % 13);
						typeOfFourthCard = (rand() % 4)	;
						if (identifyCard(deck, fourthCard, typeOfFourthCard)){
							position4(fourthCard,typeOfFourthCard);
							deck[typeOfFourthCard][fourthCard] = 14;
						}
					} else if (chanceCards[i] == 53){
						fifthCard = (rand() % 13);
						typeOfFifthCard = (rand() % 4);
						if (identifyCard(deck, fifthCard, typeOfFifthCard)){							
							position5(fifthCard,typeOfFifthCard);
							deck[typeOfFifthCard][fifthCard] = 14;
						}
					}
				}
				if(royalFlush(firstCard,secondCard,thirdCard,fourthCard,fifthCard,typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
					betTemporal = betTemporal + (bet * 250);
					move(6,60);
					printw("YOU WIN WITH ROYAL FLUSH");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(straightFlush(firstCard,secondCard,thirdCard,fourthCard,fifthCard,typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
					betTemporal = betTemporal + (bet * 50);
					move(6,60);
					printw("YOU WIN WITH STRAIGHT FLUSH");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(poker(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal +(bet * 25);
					move(6,62);
					printw("YOU WIN WITH POKER");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if (fullHouse(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 9);
					move(6,60);
					printw("YOU WIN WITH FULL HOUSE");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(flush(typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
					betTemporal = betTemporal + (bet * 6);
					move(6,62);
					printw("YOU WIN WITH FLUSH");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(straight(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 4);
					move(6,62);
					printw("YOU WIN WITH STRAIGHT");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(threeOfAKind(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 3);
					move(6,58);
					printw("YOU WIN WITH THREE OF A KIND");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(twoPair(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 2);
					move(6,62);
					printw("YOU WIN WITH TWO PAIR");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(pairOfJacksOrBetter(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + bet;
					move(6,62);
					printw("YOU WIN WITH PAIR");
					betOn(betTemporal);
					virtualBank(betIn());
				} else {
					move(6,58);
					printw("        YOU LOSE :(         ");
					betOn(betTemporal);
					virtualBank(betIn());
				}
			} else if (decision == 110 || decision == 78) {
				if(royalFlush(firstCard,secondCard,thirdCard,fourthCard,fifthCard,typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
					betTemporal = betTemporal + (bet * 250);
					move(6,60);
					printw("YOU WIN WITH ROYAL FLUSH");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(straightFlush(firstCard,secondCard,thirdCard,fourthCard,fifthCard,typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
					betTemporal = betTemporal + (bet * 50);
					move(6,60);
					printw("YOU WIN WITH STRAIGHT FLUSH");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(poker(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal +(bet * 25);
					move(6,62);
					printw("YOU WIN WITH POKER");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if (fullHouse(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 9);
					move(6,60);
					printw("YOU WIN WITH FULL HOUSE");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(flush(typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
					betTemporal = betTemporal + (bet * 6);
					move(6,62);
					printw("YOU WIN WITH FLUSH");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(straight(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 4);
					move(6,62);
					printw("YOU WIN WITH STRAIGHT");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(threeOfAKind(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 3);
					move(6,58);
					printw("YOU WIN WITH THREE OF A KIND");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(twoPair(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 2);
					move(6,62);
					printw("YOU WIN WITH TWO PAIR");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(pairOfJacksOrBetter(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					move(6,62);
					printw("YOU WIN WITH PAIR");
					betOn(betTemporal);
					virtualBank(betIn());
				} else {
					move(6,58);
					printw("        YOU LOSE :(         ");
					betOn(betTemporal);
					virtualBank(betIn());
				}
			}
		} else if ( key == 108 || key == 76 ){
			move(26,50);
			printw("                           ");
			move(28,50);
			printw("                           ");
			move(30,50);
			printw("                           ");
			betTemporal = betIn();
			virtualBank(betTemporal);
			move(24,50);
			printw("                           ");
			move(24,50);
			echo();
			printw("YOUR BET: ");
			while((digit = getch())!= 10){
				if(digit > 47 && digit < 58)
					money.push_back(digit);
			}
			noecho();
			bet = atoi(money.c_str());
			betTemporal = betTemporal - bet;
			virtualBank(betTemporal);
			srand(time(0));
			firstCard = (rand() % 13);
			typeOfFirstCard = (rand() % 4);
			secondCard = (rand() % 13);
			typeOfSecondCard = (rand() % 4);
			thirdCard = (rand() % 13);
			typeOfThirdCard = (rand() % 4);
			fourthCard = (rand() % 13);
			typeOfFourthCard = (rand() % 4)	;
			fifthCard = (rand() % 13);
			typeOfFifthCard = (rand() % 4);
			cardsOnTable[0][0] = firstCard;
			cardsOnTable[1][0] = typeOfFirstCard;
			cardsOnTable[0][1] = secondCard;
			cardsOnTable[1][1] = typeOfSecondCard;
			cardsOnTable[0][2] = thirdCard;
			cardsOnTable[1][2] = typeOfThirdCard;
			cardsOnTable[0][3] = fourthCard;
			cardsOnTable[1][3] = typeOfFourthCard;
			cardsOnTable[0][4] = fifthCard;
			cardsOnTable[1][4] = typeOfFifthCard;
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
			}
			move(26,50);
			echo();
			char decision;
			printw("Do you wish to hold any card[Y/N]: ");
			decision = getch();
			if(decision == 89 || decision == 121){
				move(26,50);
				char numbers;
				int sizeChanceCards = 0;
				printw("Cards you wish to hold [Enter the numbers in this format = 123]: ");
				while((numbers=getch()) != 10){
					chanceCards[sizeChanceCards] = numbers;
					sizeChanceCards++;
				}
				for (int i = 0; chanceCards[i] ; i++){
					if (chanceCards[i] == 49){
						firstCard = (rand() % 13);
						typeOfFirstCard = (rand() % 4);
						if (identifyCard(deck, firstCard, typeOfFirstCard)){
							position1(firstCard,typeOfFirstCard);
							deck[firstCard][typeOfFirstCard] = 14;
						}
					} else if (chanceCards[i] == 50){
						secondCard = (rand() % 13);
						typeOfSecondCard = (rand() % 4);
						if (identifyCard(deck, secondCard, typeOfSecondCard)){
							position2(secondCard,typeOfSecondCard);
							deck[typeOfSecondCard][secondCard] = 14;
						}
					} else if (chanceCards[i] == 51){
						thirdCard = (rand() % 13);
						typeOfThirdCard = (rand() % 4);
						if (identifyCard(deck, thirdCard, typeOfThirdCard)){
							position3(thirdCard,typeOfThirdCard);
							deck[typeOfThirdCard][thirdCard] = 14;
						}
					} else if (chanceCards[i] == 52){
						fourthCard = (rand() % 13);
						typeOfFourthCard = (rand() % 4)	;
						if (identifyCard(deck, fourthCard, typeOfFourthCard)){
							position4(fourthCard,typeOfFourthCard);
							deck[typeOfFourthCard][fourthCard] = 14;
						}
					} else if (chanceCards[i] == 53){
						fifthCard = (rand() % 13);
						typeOfFifthCard = (rand() % 4);
						if (identifyCard(deck, fifthCard, typeOfFifthCard)){							
							position5(fifthCard,typeOfFifthCard);
							deck[typeOfFifthCard][fifthCard] = 14;
						}
					}
				}
				if(royalFlush(firstCard,secondCard,thirdCard,fourthCard,fifthCard,typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
					betTemporal = betTemporal + (bet * 250);
					move(6,60);
					printw("YOU WIN WITH ROYAL FLUSH");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(straightFlush(firstCard,secondCard,thirdCard,fourthCard,fifthCard,typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
					betTemporal = betTemporal + (bet * 50);
					move(6,60);
					printw("YOU WIN WITH STRAIGHT FLUSH");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(poker(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal +(bet * 25);
					move(6,62);
					printw("YOU WIN WITH POKER");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if (fullHouse(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 9);
					move(6,60);
					printw("YOU WIN WITH FULL HOUSE");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(flush(typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
					betTemporal = betTemporal + (bet * 6);
					move(6,62);
					printw("YOU WIN WITH FLUSH");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(straight(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 4);
					move(6,62);
					printw("YOU WIN WITH STRAIGHT");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(threeOfAKind(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 3);
					move(6,58);
					printw("YOU WIN WITH THREE OF A KIND");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(twoPair(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 2);
					move(6,62);
					printw("YOU WIN WITH TWO PAIR");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(pairOfJacksOrBetter(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + bet;
					move(6,62);
					printw("YOU WIN WITH PAIR");
					betOn(betTemporal);
					virtualBank(betIn());
				} else {
					move(6,58);
					printw("        YOU LOSE :(         ");
					betOn(betTemporal);
					virtualBank(betIn());
				}
			} else if (decision == 110 || decision == 78) {
				if(royalFlush(firstCard,secondCard,thirdCard,fourthCard,fifthCard,typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
					betTemporal = betTemporal + (bet * 250);
					move(6,60);
					printw("YOU WIN WITH ROYAL FLUSH");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(straightFlush(firstCard,secondCard,thirdCard,fourthCard,fifthCard,typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
					betTemporal = betTemporal + (bet * 50);
					move(6,60);
					printw("YOU WIN WITH STRAIGHT FLUSH");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(poker(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal +(bet * 25);
					move(6,62);
					printw("YOU WIN WITH POKER");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if (fullHouse(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 9);
					move(6,60);
					printw("YOU WIN WITH FULL HOUSE");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(flush(typeOfFirstCard,typeOfSecondCard,typeOfThirdCard,typeOfFourthCard,typeOfFifthCard)){
					betTemporal = betTemporal + (bet * 6);
					move(6,62);
					printw("YOU WIN WITH FLUSH");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(straight(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 4);
					move(6,62);
					printw("YOU WIN WITH STRAIGHT");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(threeOfAKind(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 3);
					move(6,58);
					printw("YOU WIN WITH THREE OF A KIND");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(twoPair(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + (bet * 2);
					move(6,62);
					printw("YOU WIN WITH TWO PAIR");
					betOn(betTemporal);
					virtualBank(betIn());
				} else if(pairOfJacksOrBetter(firstCard,secondCard,thirdCard,fourthCard,fifthCard)){
					betTemporal = betTemporal + bet;
					move(6,62);
					printw("YOU WIN WITH PAIR");
					betOn(betTemporal);
					virtualBank(betIn());
				} else {
					move(6,58);
					printw("        YOU LOSE :(         ");
					betOn(betTemporal);
					virtualBank(betIn());
				}
			}
		}
		refresh();
	}
	endwin();
	delete[] chanceCards;
	delete[] cardsOnTable;
	delete[] deck;
	deck = NULL;
	return 0;
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
		printw("           ");
		move(x+1,y);
		printw("    ***    ");
		move(x+2,y);
		printw("   *   *   ");
		move(x+3,y);
		printw("  *     *  ");
		move(x+4,y);
		printw(" ***   *** ");
		move(x+5,y);
		printw("*         *");
		move(x+6,y);
		printw("*         *");
		move(x+7,y);
		printw(" ***   *** ");
		move(x+8,y);
		printw("    * *    ");
		move(x+9,y);
		printw("    * *    ");
		move(x+10,y);
		printw("    ***    ");
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

void virtualBank(int money){
	move(23,4);
	printw("======================");
	move(24,4);
	printw("|    YOUR CREDITS    |");
	move(25,4);
	printw("|                    |");
	move(26,4);
	printw("|     $              |");
	move(26,12);
	printw("%d",money);
	move(27,4);
	printw("|                    |");
	move(28,4);
	printw("======================");
}

void rulesOfBet(){
	move(29,4);
	printw("____________________________");
	move(30,4);
	printw("| 	x1   PAIR              |");
	move(31,4);
	printw("| 	x2   TWO PAIR          |");
	move(32,4);
	printw("| 	x3   THREE OF A KIND   |");
	move(33,4);
	printw("|   x4   STRAIGHT          |");
	move(34,4);
	printw("|   x6   FLUSH             |");
	move(35,4);
	printw("|   x9   FULL HOUSE        |");
	move(36,4);
	printw("|   x25  POKER             |");
	move(37,4);
	printw("|   x50  STRAIGHT FLUSH    |");
	move(38,4);
	printw("|   x250 ROYAL FLUSH       |");
	move(39,4);
	printw("____________________________");
}

void betOn(int money){
	ofstream entrada;
	entrada.open("bet.txt",ios::out|ios::trunc);
	if(!entrada.fail()){
		entrada << money << endl;
		entrada.close();
	}
}

int betIn(){
	int money;
	ifstream salida;
	salida.open("bet.txt",ios::in);
	salida >> money;
	salida.close();
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

bool twoPair(int first, int second, int third, int fourth, int fifth){
	if (((first == second) && (third == fourth)) || ((first == second) && (third == fifth)) || ((first == second) && (fourth == fifth))
		|| ((first == third) && (second == fourth)) || ((first == third) && (second == fifth)) || ((first == fourth) && (second == third))
		|| ((first == fourth) && (second == fifth))){
		return TRUE;
	} else if (((second == third) && (fourth == first)) || ((second == third) && (fourth == fifth)) || ((second == fourth) && (first == fifth))
		|| ((second == fourth) && (first == third)) || ((second == fifth) && (first == third)) || ((second == fifth) && (first == fourth))){
		return TRUE;
	} else if (((third == fourth) && (second == fifth)) || ((third == fourth) && (first == fifth)) || ((third == fifth) && (first == second))
		|| ((third == fifth) && (first == fourth))){
		return TRUE;
	} else if(((fourth == fifth) && (first == third)) || ((fourth == fifth) && (first == second))){
		return TRUE;
	} else {
		return FALSE;
	}
}

bool threeOfAKind(int first, int second, int third, int fourth, int fifth){
	if((first == second && first == third) || (first == second && first == fourth) || (first == second && first == fifth) || (first == third && first == fourth) || (first == third && first == fifth) || (first == fourth && first == fifth)){
		return TRUE;
	} else if (((second == third) && (second == fourth)) || ((second == third) && (second == fifth)) || ((second == fourth) && (second == fifth))){
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
	if ((first == second && (third == fourth && third == fifth)) || (first == third && (second == fourth && second == fifth)) || (first == fourth && (second == third && second == fifth)) || (first == fifth && (second == third && second == fourth))){
		return TRUE;
	} else if ((second == third && (first == fourth && first == fifth)) || (second == fourth && (first == third && first == fifth)) || (second == fifth && (first == third && first == fourth))){
		return TRUE;
	} else if ((third == fourth && (first == second && first == fifth)) || (third == fifth && (first == second && first == fourth))){
		return TRUE;
	} else if (fourth == fifth && (first == second && first == third)){
		return TRUE;
	} else {
		return FALSE;
	}
}

bool royalFlush(int first, int second, int third, int fourth, int fifth, int typeOfFirst, int typeOfSecond, int typeOfThird, int typeOfFourth, int typeOfFifth){
	if(typeOfFirst == typeOfSecond && typeOfFirst == typeOfThird && typeOfFirst == typeOfFourth && typeOfFirst == typeOfFifth){
		int arrayTemporal[5] = {first,second,third,fourth,fifth};
		int temporal, size = 5;
		for (int i = 0; i < size;i++){
			for (int j = 0; j < size-1; j++){
				if (arrayTemporal[j] > arrayTemporal[j+1]){
					temporal = arrayTemporal[j];
					arrayTemporal[j] = arrayTemporal[j+1];
					arrayTemporal[j+1] = temporal;
				}
			}
		}
		if (arrayTemporal[0] == 0 && arrayTemporal[1] == 9 && arrayTemporal[2] == 10 && arrayTemporal[3] == 11 && arrayTemporal[4] == 12){
			return TRUE;
		} else {
			return FALSE;
		}
	} else {
		return FALSE;
	}
}

bool straightFlush(int first, int second, int third, int fourth, int fifth, int typeOfFirst, int typeOfSecond, int typeOfThird, int typeOfFourth, int typeOfFifth){
	if(typeOfFirst == typeOfSecond && typeOfFirst == typeOfThird && typeOfFirst == typeOfFourth && typeOfFirst == typeOfFifth){
		int arrayTemporal[5] = {first,second,third,fourth,fifth};
		int temporal, size = 5;
		for (int i = 0; i < size;i++){
			for (int j = 0; j < size-1; j++){
				if (arrayTemporal[j] > arrayTemporal[j+1]){
					temporal = arrayTemporal[j];
					arrayTemporal[j] = arrayTemporal[j+1];
					arrayTemporal[j+1] = temporal;
				}
			}
		}
		if ((arrayTemporal[0] == arrayTemporal[1]-1) && (arrayTemporal[1] == arrayTemporal[2]-1) && (arrayTemporal[2] == arrayTemporal[3]-1) && (arrayTemporal[3] == arrayTemporal[4]-1)){
			return TRUE;
		} else {
			return FALSE;
		}
	} else {
		return FALSE;
	}
}

bool straight(int first, int second, int third, int fourth, int fifth){
	int arrayTemporal[5] = {first,second,third,fourth,fifth};
	int temporal, size = 5;
	for (int i = 0; i < size;i++){
		for (int j = 0; j < size-1; j++){
			if (arrayTemporal[j] > arrayTemporal[j+1]){
				temporal = arrayTemporal[j];
				arrayTemporal[j] = arrayTemporal[j+1];
				arrayTemporal[j+1] = temporal;
			}
		}
	}
	if ((arrayTemporal[0] == arrayTemporal[1]-1) && (arrayTemporal[1] == arrayTemporal[2]-1) && (arrayTemporal[2] == arrayTemporal[3]-1) && (arrayTemporal[3] == arrayTemporal[4]-1)){
		return TRUE;
	} else {
		return FALSE;
	}
}
