#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
const int maxchances=5;												//const int
using namespace std;
int scorecalc(int *chance,int time_of_play)							//function overloading
{
	int totalscore=0;
		for(int i=0;i<time_of_play;i++)
	{
	 totalscore+=chance[i];
	}
	float avscore=static_cast<float>(totalscore)/time_of_play;		//type conversion by static cast
	return avscore;	
}
inline int scorecalc(int chances)									//inline function
{
	int score=100-20*chances;
	return score;
}
class delay															//class
{
	int no_of_char,loop_run;
	public:
		delay()														//default constructor
		{
			no_of_char=5;
			loop_run=10000;	
		}
		delay(int a,int b)											//prameterized constructor		//constructor overloading
		{
			no_of_char=a;
			loop_run=b;	
			
		}
		void printc(char c='.')										//default arguement
			{
				for(int i=0;i<no_of_char;i++)
				{
					hault(loop_run);
					cout<<c;
				}
				cout<<endl;
			}
		void hault(int a)
			{
				for(int i=0;i<a;i++)
				{
					for(int j=0;j<a;j++)
					{}
				}
			}
};
int main()
{
	int *totaldata,time_of_play=0;									//DMA
	totaldata=new int[10];
	delay d1,d2(33,1500);
	char name[20],yn='Y';
	cout<<setw(36)<<" "<<setw(24)<<setfill('*')<<"welcome to the game"<<setfill(' ');		//manipulators
	d1.printc('*');
	cout<<setw(68)<<"Guess a Number Between '0' to '10'"<<endl;
	cout<<setw(35)<<" ";
	system("pause");
	cout<<setw(65)<<"ENTER YOUR NAME TO CONTINUE:"<<endl;
	cout<<setw(43)<<" ";
	cin.get(name,20);												//formatted output
	while(yn=='Y')
	{
		system("CLS");
		static int i=0;
		int number,guess,score,chances;
		srand(time(NULL));
		number=rand()%10+1;
		for(chances=0;chances<maxchances;chances++)
		{
			cout<<setw(68)<<"---------------------------------"<<endl;
			cout<<setw(59)<<"Enter Your Guess:";
			cin>>guess;
			if(guess==number)
				{
				 cout<<setw(56)<<"CORRECT!!!"<<endl;
				 break;
				}
			else
			{
				int remchances=maxchances-chances-1;
				cout<<setw(60)<<"Incorrect Guess!!!"<<endl<<setw(48)<<"You Have "<<remchances<<" Chance Remain"<<endl;
				if(remchances!=0)
				{
					if(guess<number)
						cout<<setw(55)<<"Try Higher"<<endl;
					else
						cout<<setw(55)<<"Try Lower"<<endl;
					continue;
				}
				else
				{
					chances++;	//for calculating score of unssuccess count doen't exceeds 4 so it gives the score of success in 5th try
					break;
				}
			}
		}
		score=scorecalc(chances);
		totaldata[i]=score;
		cout<<setw(55)<<"score is:"<<score<<endl;
		cout<<setw(74)<<"enter 'Y' to play again and enter 'N' to exit"<<endl;
		cout<<setw(35)<<" ";
		yn=getch();
		yn=toupper(yn);
		d2.printc('-');
		i++;
		time_of_play=i;
	}
cout<<setw(50)<<"Thank You:"<<name<<endl;
float avscore=scorecalc(totaldata,time_of_play);
cout<<setw(58)<<"Average Score Is:"<<avscore<<endl;
delete[]totaldata;
cout<<setw(35)<<" ";
system("pause");
return 0;
}
