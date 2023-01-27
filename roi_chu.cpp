#include <iostream>
#include <cstdlib>
#include <ctime>
#include <mylib.h>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace std;
const int win = 5;
const int dong = 10;
const int cot = 26;
int diemBan = 0, diemMay = 0, sran;  
char random;



bool check = false;
char ki_tu_ngau_nhien();
void outScreen();
void startGame();
void beginGame();
void playGame();

int main(){
	playGame();	
	return 0;
}

char ki_tu_ngau_nhien(){
	srand(time(NULL));
	sran = rand() % 25;
	return 'A'+ sran;
}
void outScreen(){
	for (int i = 0; i < cot ; i++){
		gotoxy(i, dong - dong);
		cout <<	(char)('A' + i);
		gotoxy(i, dong);
		cout << "-";
	} 
	cout << "\nDiem ban " << diemBan << " vs " << diemMay <<" Diem May"; 
}
void startGame(){
	gotoxy(cot/2, dong/2);
	cout << "Bat dau";
	Sleep(1000);
}
void beginGame(){
	random = ki_tu_ngau_nhien();
	for (int i = 0; i < dong; i++){
		gotoxy(sran, i);
		cout << random;
		if(kbhit()){
			if(toupper(getch()) == random){
				check = true;
				break;
			}
		}
		else
			check = false;
		Sleep(500);
		gotoxy(sran, i);
		cout << " ";
	}
	if(check)
		diemBan++;
	else
		diemMay++;
}
void playGame(){
	startGame();
	do{
		clrscr();
		outScreen();
		beginGame();	
	}while (diemBan < win && diemMay < win);
	outScreen();
	if (diemBan == win)
		cout << "\n\t YOU WIN !";
	else 
		cout << "\n\t YOU LOSE!";
}
