#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<string.h>
struct students{
	int walid,bal;
	char name[20];
	char username[20];
	char password[20];
	//students *link;
	int select;
}s[10];
struct teachers{
	int walid,bal;
	char name[20];
	char username[20];
	char password[20];
	char course[20];
	//teachers *link;
	int rating;
}t[10];
struct link{
char tlink[64],slink[64],clink[64];
}l[20];
int ns=0,nt=0;
void tth_val()
{
float coin_val;
if(ns==0||nt==0)
cout<<"\nTTH value: $0.5";
else
{
coin_val=0.15*(ns/nt)*0.5;
cout<<"\nTTH value:"<<coin_val<<"\n";
}
getch();
}
int secure(char us[],char pas[])
{
int flag=0,i,u,p;
//students *temp;
//ifstream fi;
//fi.open("stu_det.dat",ios::binary|ios::in);
//fi.read((char *)&temp,sizeof(temp));
for(i=0;i<ns;i++)
{
u=strcmp(s[i].username,us);
p=strcmp(s[i].password,pas);
if(u==0&&p==0)
{
flag=1;
//fi.close();
return(i);
}
}
if(flag==0)
{
cout<<"\nUsername or password is wrong.\n";
getch();
return(-1) ;
//fi.close();
}
}
void stud()
{
int n,ts;
char us[20],pass[20];
struct students *t;
clrscr();
cout<<"\t\tSTUDENT PORTAL\n";
cout<<"\t\t--------------\n";
cout<<"1.Create account\n";
cout<<"2.Log in\n";
cout<<"Enter your choice:";
cin>>n;
switch(n)
{
case 1: clrscr();
	cout<<"\nLOGIN\n______\n";
	cout<<"Enter your name:";
	cin>>s[ns].name;
	cout<<"Enter your username:";
	cin>>s[ns].username;
	cout<<"Enter password:";
	cin>>s[ns].password;
	ns++;
	ofstream fo;
	fo.open("stu_det.dat",ios::binary|ios::out|ios::app);
	fo.write((char*)&s,sizeof(s));
	fo.close();
	break;
case 2: clrscr();
	cout<<"\nLOGIN\n______\n";
	cout<<"Username:";
	cin>>us;
	cout<<"Password:";
	cin>>pass;
	ts=secure(us,pass);
	//if(t!=NULL)
	//{
	if(ts!=-1)
	{
	clrscr();
	cout<<"Loged in successfully\n";
	cout<<"----------------------\n";
	cout<<"\nName : "<<s[ts].name;
	//}
	getch();
	}
	break;
}
}
void teach()
{
 int n,temp;
char us[20],pass[20];
struct teachers *t;
clrscr();
cout<<"\t\tTEACHERS PORTAL\n";
cout<<"\t\t---------------\n";
cout<<"1.Create account\n";
cout<<"2.Log in\n";
cout<<"Enter your choice:";
cin>>n;
switch(n)
{
case 1: clrscr();
	cout<<"\nLOGIN\n______\n";
	cout<<"Enter your name:";
	cin>>t[nt].name;
	cout<<"Enter your username:";
	cin>>t[nt].username;
	cout<<"Enter password:";
	cin>>t[nt].password;
	cout<<"Enter field of expertise:";
	cin>>t[nt].course;
	nt++;
	ofstream fo;
	fo.open("stu_det.dat",ios::binary|ios::out|ios::app);
	fo.write((char*)&s,sizeof(s));
	fo.close();
	break;
case 2: clrscr();
	cout<<"\nLOGIN\n______\nUsername:";
	cin>>us;
	cout<<"Password:";
	cin>>pass;
	//struct teachers *temp;
	temp=secure(us,pass);
	if(temp!=-1)
	{
	clrscr();
	cout<<"Loged in successfully\n";
	cout<<"----------------------\n";
	cout<<"\nName:"<<t[temp].name;
	cout<<"\nCourse:"<<t[temp].course;
	getch();
	}
	break;
}
}
void main()
{
	int ch,d;
	clrscr();
	do
	{
	clrscr();
	cout<<"\n\t\tLOGIN AS\n";
	cout<<"\t\t----------\n";
	cout<<"1.Student\n";
	cout<<"2.Teacher\n";
	cout<<"3.TTH value\n";
	cout<<"4.Exit\n";
	cout<<"Enter your choice.";
	cin>>ch;
	switch(ch)
	{
	case 1:stud();
		break;
	case 2:teach();
		break;
	case 3:tth_val();
		break;
	case 4:exit(0);
	default:cout<<"Wrong choice..";
	}
	}while(1);
}
