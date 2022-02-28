// student datasbe management sysytem
// file handling
#include<iostream>

#include<cstdio>

#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<iomainip>

int main()
{
	FILE *fp,*ft;
	char another,choice;
	  struct student 
	  {
	  	char first_name[50],last_name[50];
	  	char course[100];
	  	int section;
	  }
	  struct student e;
	  char xfirst_name[50],xlast_name[50];
	  long int recsize;
	  
	  fp= fopen("users.txt","rb+");
	  if(fp==NULL)
	  {
	  	fp=fopen("users.txt","wb+");
	  	  if(fp==NULL)
	  	  {
	  	  	puts("Cannot open file");
	  	  	return 0;
		  }
	  }
	  
	  recsize = sizeof(e);
	  while(1)
	  {
	  	system("cls");
	  	cout<<"\t\t======STUDENT DATABASE SYSTEM========";
	  	cout<<"\n\n\n\n";
	  	cout<<"\n \t\t\t 1.Add Records:";
	  	cout<<"\n \t\t\t 2.List Records:";
	  	cout<<"\n \t\t\t 3.Modify Records:";
	  	cout<<"\n \t\t\t 4.Delete Records:";
	  	cout<<"\n \t\t\t 5.Exit Program:";
	  	cout<<"\n\n";
	  	cout<<"\t\t\t Select Your Choice:=>";
	  	fflush(studin);
	  	choice=getche();
	  	switch()
	  	{
		  case 1:
		  		{
		  		fseek(fp,0,SEEK_END);
		  		another='Y';
		  		while(another == 'Y' || another == 'y')
		  		{
		  			system("cls");
		  			cout<<"Enter the first name:";
		  			cin>>e.first_name;
		  			cout<<"Enter the last name:";
		  			cin>>e.last_name;
		  			cout<< "Enter the choice:";
		  			cin>>e.course;
		  			cout<<"Enter the section:";
		  			cin>>e.section;
		  			fwrite(&e,recsize,1,fp);
		  			cout<<"\n Add another Record (Y/N)";
		  			fflush(stdin);
		  			another = getchar();
				  }
				  break;
		        }
		   case 2:
		        {
		          system("cls");
				  rewind(fp);
				  cout<<"=====View the records in the Databases:";
				  cout<<"\n";
				  while(fread(&e,recsize,1,fp)==1)
				  {
				  	cout<<"\n";
				  	cout<<"\n"<<e.first_name <<setw(10) <<e.last_name;
				  	cout<<"\n";
				  	cout<<"\n"<<e.course <<setw(8)<<e.section;
				  	
				  }
				  cout<<"\n\n";
				  system("pause");	
		        	break;
				} 
			case 3:
			     {
			     	system("cls");
			     	another = 'Y';
			     	while(another =='Y'|| another=='y')
					 {
					 	cout<<"\n Enter the last name of the student:";
					 	cin>>xlast_name;
					 rewind(fp);
			     	while(fread(&e,recsize,1,fp)==1)
			     	{
			     		if(strcmp(e.last_name,xlast_name)==0)
			     		{
			     			cout<<"Enter the first name:";
			     			cin>>e.first_name;
			     			cout<<"Enter the last name:";
			     			cin>>e.last_name;
			     			cout<<"Enter the course:";
			     			cin>>e.course;
			     			cout<<"Enter the section:";
			     			cin>>e.section;
			     			fseek(fp ,-recsize,SEEK_CUR);
			     			fwrite(&e,recsize,1,fp);
			     			break;
						 }
						 else
						     cout<<"record not found";
					 }
					 cout<<"\n modify another record\n";
					 fflush(stdin);
					 another = getchar();
				}
			     	break;
	            }
			case 4:
			      {
			      	system("cls");
			      	another='Y';
			    while(another =='Y'|| another=='y')
			    {
			    	cout<<"Enter the last name of the student:";
			    	cin>>xlast_name;
			    	ft= fopen("temp.data","wb");
			    	remind(fp);
			    	while(fread(&e,recsize,1,fp)==1)
			    	{
			    		if(strcmp(e.last_name,xlast_name)!=0)
			    		{
			    			fwrite(&e,recsize,1,ft);
						}
						fclose(fp);
						fclose(ft);
						remove("users.txt");
						rename("users.txt");
						fp =fopen("users.txt","rb+");
						
						cout<<"\n Delete another account(Y/N)";
						fflush(stdin);
						another=getchar();
						
					}
				  }

			      	break;
			   }
		case 5:
		{
			fclose(fp);
			cout<<"\n\n";
			cout<<"\t\t";
			cout<<"\n\n";
			exit(0);
			
		}	   		    
		  }// switch case 
		  


	  	
	  }// main while
	  system(pause);
	  return 0;
	  
}//int main
