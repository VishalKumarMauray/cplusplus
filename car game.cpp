#include<iostream>
#include<conio.h>
#include<dos.h> 
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 70
#define SCREEN_HEIGHT 29
#define WIN_WIDTH 70 

using namespace std; 
 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int enemyY[4];
int enemyX[4];
int enemyFlag[4];
char car[5][4] = { ' ','+','+',' ', 
					'+','+','+','+', 
					' ','+','+',' ',
					' ','+','+',' ',
					'+','+','+','+' }; 
					
int carPos = WIN_WIDTH/5;
int score = 0; 
char ch=178;

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void setcursor(bool visible, DWORD size)
 {
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
void drawBorder(){  
	for(int i=0; i<SCREEN_HEIGHT; i++){
		for(int j=0; j<17; j++){
			gotoxy(0+j,i); cout<<ch;
			gotoxy(WIN_WIDTH-j,i); cout<<ch;
		}
	} 
	for(int i=0; i<SCREEN_HEIGHT; i++)
	{
		gotoxy(SCREEN_WIDTH,i); cout<<ch;
	} 
}
void genEnemy(int in){
	enemyX[in] = 17 + rand()%(33);  
}
void drawEnemy(int in){
	if( enemyFlag[in] == true ){
		gotoxy(enemyX[in], enemyY[in]);   cout<<"****";  
		gotoxy(enemyX[in], enemyY[in]+1); cout<<" ** "; 
		gotoxy(enemyX[in], enemyY[in]+2); cout<<"****"; 
		gotoxy(enemyX[in], enemyY[in]+3); cout<<" ** ";  
	} 
}
void eraseEnemy(int in){
	if( enemyFlag[in] == true ){
		gotoxy(enemyX[in], enemyY[in]); cout<<"    ";  
		gotoxy(enemyX[in], enemyY[in]+1); cout<<"    "; 
		gotoxy(enemyX[in], enemyY[in]+2); cout<<"    "; 
		gotoxy(enemyX[in], enemyY[in]+3); cout<<"    "; 
	} 
}
void resetEnemy(int in){
	eraseEnemy(in);
	enemyY[in] = 1;
	genEnemy(in);
}

void drawCar(){
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<4; j++)
		{
			gotoxy(j+carPos, i+22);
			 cout<<car[i][j];
		}
	}
}
void eraseCar(){
	for(int i=0; i<5; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+carPos, i+22); cout<<" ";
		}
	}
}
 
int collision(){
	if( enemyY[0]+4 >= 23 ){
		if( enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9  ){
			return 1;
		}
	}
	return 0;
} 
void gameover(){
	system("cls");
	cout<<endl;
	cout<<"\t\t--------------------------"<<endl;
	cout<<"\t\t-------- Game Over -------"<<endl;
	cout<<"\t\t--------------------------"<<endl<<endl;
	cout<<"\t\tPress any key to go back to menu.";
	getch();
}
void updateScore(){
	gotoxy(WIN_WIDTH + 7, 5);cout<<"Score: "<<score<<endl;
}

void instructions(){
	
			system("cls");
			
			char v = 186; 
    		char h = 205; 
		    char tr = 187;
		    char br = 188;
		    char tl = 201;
		    char bl = 200;
		    cout<<"\n\n\t\t\tINSTRUCTION"<<endl;
			cout<<"\t"<<tl;
		    for(int i=0;i<42;i++){
		    	cout<<h;
			}
			cout<<tr<<endl;
			cout<<"\t"<<v<<"\t\t\t\t\t   "<<v<<endl;
			cout<<"\t"<<v<<"  Avoid Cars by moving left or right.     "<<v<<endl;
			cout<<"\t"<<v<<"  Press 'a' to move left                  "<<v<<endl;
			cout<<"\t"<<v<<"  Press 'd' to move right                 "<<v<<endl;
			cout<<"\t"<<v<<"  Press 'escape' to exit                  "<<v<<endl;
			cout<<"\t"<<v<<"\t\t\t\t\t   "<<v<<endl;
			cout<<"\t"<<bl;
		    for(int i=0;i<42;i++){
		    	cout<<h;
			}
			cout<<br<<endl;
			
			cout<<"\n\n\tPress any key to go back to menu";
	getch();
}

void play(){
	carPos = -1 + WIN_WIDTH/2;
	score = 0;
	enemyFlag[0] = 1;
	enemyFlag[1] = 0;
	enemyY[0] = enemyY[1] = 1;
	  
	system("cls"); 
	drawBorder(); 
	updateScore();
	genEnemy(0);
	genEnemy(1);
	
	gotoxy(WIN_WIDTH + 7, 2);cout<<"Car Game";
	gotoxy(WIN_WIDTH + 6, 4);cout<<"----------";
	gotoxy(WIN_WIDTH + 6, 6);cout<<"----------";
	gotoxy(WIN_WIDTH + 7, 12);cout<<"Control ";
	gotoxy(WIN_WIDTH + 7, 13);cout<<"-------- ";
	gotoxy(WIN_WIDTH + 2, 14);cout<<" A Key - Left";
	gotoxy(WIN_WIDTH + 2, 15);cout<<" D Key - Right"; 
	
	gotoxy(18, 5);
	cout<<"Press any key to start";
	getch();
	gotoxy(18, 5);cout<<"                      ";
	
	while(1){
		if(kbhit()){
			char ch = getch();
			if( ch=='a' || ch=='A' ){
				if( carPos > 18 )
					carPos -= 4;
			}
			if( ch=='d' || ch=='D' ){
				if( carPos < 50 )
					carPos += 4;
			} 
			if(ch==27){
				break;
			}
		} 
		
		drawCar(); 
		drawEnemy(0); 
		drawEnemy(1); 
		if( collision() == 1  ){
			gameover();
			return;
		} 
		Sleep(20);
		eraseCar();
		eraseEnemy(0);
		eraseEnemy(1);   
		
		if( enemyY[0] == 10 )
			if( enemyFlag[1] == 0 )
				enemyFlag[1] = 1;
		
		if( enemyFlag[0] == 1 )
			enemyY[0] += 1;
		
		if( enemyFlag[1] == 1 )
			enemyY[1] += 1;
		 
		if( enemyY[0] > SCREEN_HEIGHT-4 ){
			resetEnemy(0);
			score++;
			updateScore();
		}
		if( enemyY[1] > SCREEN_HEIGHT-4 ){
			resetEnemy(1);
			score++;
			updateScore();
		}
	}
}

int main()
{
	setcursor(0,0); 
	srand( (unsigned)time(NULL)); 
	 
	do{
		system("cls");
		gotoxy(10,5); cout<<" -------------------------- "; 
		gotoxy(10,6); cout<<" |        Car Game        | "; 
		gotoxy(10,7); cout<<" --------------------------";
		gotoxy(10,9); cout<<"1. Start Game";
		gotoxy(10,10); cout<<"2. Instructions";	 
		gotoxy(10,11); cout<<"3. Quit";
		gotoxy(10,13); cout<<"Select option: ";
		char op = getche();
		
		if( op=='1') play();
		else if( op=='2') instructions();
		else if( op=='3') exit(0);
		
	}while(1);
	
	return 0;
}
