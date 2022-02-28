// bus reservation system
#include<conio.h>

#include<cstdio>

#include<iostream>

#include<string.h>

#include<cstdlib>

using namespace std;

static int p=0;
class a
{
	char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	
	 public:
	 	
	 	void install();
	 	
	 	void allotment();
	 	
	 	void empty();
	 	
	 	void show();
	 	
	 	void avail();
	 	
	 	void position(int i);
	 	
}
bus [10];

void vline (char ch)
{
	for (int i=80;i>0;i--)
	 cout<<ch;
}
void a::install(){
	cout<<"Enter bus no:";
	cin>>bus[p].busn;
	
	cout<<"Enter Driver's Name:";
	cin>>bus[p].driver;
	
	cout<<"\n Arrival Time";
	cin>>bus[p].arrival;
	
	cout<<"\n Department";
	cin>>bus[p].depart;
	
	cout<<"\From \t\t\t";
	cin>>bus[p].from;
	
	cout<<"To \t\t\t";
	cin>>bus[p].to;
	
	bus[p].empty();
	 p++;
}
void a::allotment()
{
	int seat;
	char number[5];
	top:
		cout<<"Bus no:";
		cin>>number;
		int n;
		for(n=0;n<=p;n++)
		{
			if(strcmp(bus[n].busn,number)==0)
			break;
		}
		while(n<=p)
		{
			cout<<"\nSeat number";
			cin>>seat;
			if(seat>32)
			{
				cout<<"\nThere are only 32 seats available in this bus .";
			}
			else
			{
				if(strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
				{
					cout<<"Enter passenger name:";
					cin>>bus[n].seat[seat/4][(seat%4)-1];
					break;
				}
				else
				{
					cout<<"The seat no. is already reserved\n";
				}
			}
			if(n>p)
			{
			  cout<<"Enter correct bus no:";
			  goto top;
			}
		}
}
void a::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"Empty");
		}
	}
}

void a::show(){
	int n;
	char number[5];
	
	cout<<"Enter the number";
	cin>>number;
	
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		vline('*');
		cout<<"Bus no: \t"<<bus[n].busn
        <<"\n Driver: \t"<<bus[n].driver<<"\t\t Arriavl time: \t"<<bus[n].arrival<<"\t Department time: "<<bus[n].depart<<"\n From: \t\t"
        <<bus[n].from<<"\t\t To: \t\t"<<bus[n].to<<"\n";
        
        vline('*');
        vline('_');
	}
}
int main()
{
	while("cls");
	int w;
	while(1){
		// system ("cls");
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t1.Install\n\t\t\t"<<"2.Reservation \n\t\t\t"<<"3.Show \n\t\t\t"<<"4.Bus Available\n\t\t\t"<<"5.Exit";
		
		cout<<"Enter the choice";
		cin>>w;
		switch(w)
		{
			case 1:
				bus[p].install();
				break;
				
			case 2:
		     	bus[p].allotment();
			    break;
			case 3:
			     bus[p].show();
				 break;
			case 4:
			     bus[p].avail();
				 break;
			case 5:
			   exit(0);	 	 		
		}
	}
	return 0;
}
