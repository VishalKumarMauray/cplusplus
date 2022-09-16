
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<dos.h>
#include<time.h>

#define MAXSIZE 100

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x,int y)
{
	CursorPosition.X= 5+x;
	CursorPosition.Y= y;
	SetConsoleCursorPosition(console, CursorPosition);
}


class point
{
	private:
		int x;
		int y;
	public:
		point()
		{
			x=y=10;
		}
		point(int x,int y)
		{
			this -> x=x;
			this -> y=y;
		}
		void setpoint(int x, int y)
		{
			this -> x=x;
			this -> y=y;
		}
		int Getx()
		{
			return x;
		}
		int Gety()
		{
			return y;
		}
		void moveup()
		{
			y--;
		}
		void movedown()
		{
			y++;
		}
		void moveleft()
		{
			x--;
		}
		void moveright()
		{
			x++;
		}
		void draw()
		{
			gotoxy(x,y);
			cout<<"*";
		}
		void erase()
		{
			gotoxy(x,y);
			cout<<" ";
		}
		void copypos(point * p)
		{
			p->x=x;
			p->y=y;
		}
		void debug()
		{
			cout<<"("<<x<<","<<y<<")";
		}
};

class snake
{
	private:
		point * cell[MAXSIZE];
		int size;
		char dir;
		point fruit;
		public:
			snake()
			{
				size=1;
				cell[0] = new point(20,20);
				for(int i=2;i<MAXSIZE;i++)
				{
					cell[i]=NULL;
				}
				fruit.setpoint(rand()%33, rand()%25);
			}
			void addcell(int x,int y)
			{
				cell[size++]=new point(x,y);
			}
			void turnup()
			{
				dir = 'w';
			}
			void turndown()
			{
				dir = 's';
			}
			void turnleft()
			{
				dir = 'a';
			}
			void turnright()
			{
				dir = 'd';
			}
			void move()
			{
				system("cls");
				for(int i=size-1;i>0;i--)
				{
					cell[i-1]->copypos(cell[i]);
				}
				switch(dir)
				{
					case 'w':
						cell[0]->moveup();
						break;
					
					case 'a':
						cell[0]->moveleft();
						break;
						
					case 's':
						cell[0]->movedown();
						break;
						
					case 'd':
						cell[0]->moveright();
						break;
				}
				if(fruit.Getx()==cell[0]->Getx() && fruit.Gety()==cell[0]->Gety())
				{
					addcell(0,0);
					fruit.setpoint(rand()%25, rand()%25);
				}
				for(int i=0;i<size;i++)
					cell [i]->draw();
				fruit.draw();
				Sleep(30);
		 }
		 
		 void debug()
		 {
		 	for(int i=0;i<size;i++)
		 	{
		 		cell[i]->debug();
			}
		 }
};

int main()
{	
	 
	do{
		system("cls");
		gotoxy(10,5); cout<<" -------------------------- "; 
		gotoxy(10,6); cout<<" |       Snake Game       | "; 
		gotoxy(10,7); cout<<" --------------------------";
		gotoxy(10,9); cout<<"1. Start Game";
		gotoxy(10,10); cout<<"2. Instructions";	 
		gotoxy(10,11); cout<<"3. Quit";
		gotoxy(10,13); cout<<"Select option: ";
		char op = getche();
		
		if( op=='1')
		{
			snake snake;
	
	do
	{
		
		if(kbhit())
		{
			op= getch();
		}
		switch (op)
		{
			case 'w':
			case 'W':
				snake.turnup();
				break;
				
			case 'a':
			case 'A':
				snake.turnleft();
				break;
				
			case 's':
			case 'S':
				snake.turndown();
				break;
				
			case 'd':
			case 'D':
				snake.turnright();
				break;
		}	
		snake.move();
	}while(op!='e');
		}
		else if( op=='2')
		{
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
			cout<<"\t"<<v<<"  Press 'w' to move in upword direction   "<<v<<endl;
			cout<<"\t"<<v<<"  Press 'a' to move in left direction     "<<v<<endl;
			cout<<"\t"<<v<<"  Press 's' to move in downward direction "<<v<<endl;
			cout<<"\t"<<v<<"  Press 'd' to move in right direction    "<<v<<endl;
			cout<<"\t"<<v<<"\t\t\t\t\t   "<<v<<endl;
			cout<<"\t"<<bl;
		    for(int i=0;i<42;i++){
		    	cout<<h;
			}
			cout<<br<<endl;
			
			cout<<"\n\n\tPress any key to go back to menu";
			getch();
		}
		else if( op=='3') exit(0);
		
	}while(1);
}
