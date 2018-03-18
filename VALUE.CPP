#include<iostream.h>
#include<conio.h>
float tth_val(float ns,float nt)
{
float coin_val;
coin_val=0.15*(ns/nt)*0.5;
return(coin_val);
}
float course_val(float tr,float ns,float nt)
{
float c_val=tr+((ns/nt)*0.5);
return(c_val);
}
void main()
{
clrscr();
float tr,n,t,y,value,cval;
cout<<"\nEnter the no of students:";
cin>>n;
cout<<"Enter the no  of teachers:" ;
cin>>t;
value=tth_val(n,t);
cout<<"\n\nTTH: $"<<value<<"\n\n";
do
{
cout<<"\nEnter the no of students enrolled for a course:";
cin>>n;
cout<<"Enter the no  of teachers available for that course:" ;
cin>>t;
cout<<"\nEnter teacher rating:";
cin>>tr;

cval=course_val(tr,n,t);


cout<<"\nCourse value: $"<<cval<<"\n";
cout<<"\nPer head cost: $"<<cval/n;
cout<<"\n\nEnter 1 to continue:";
cin>>y;
}while(y==1);
}
