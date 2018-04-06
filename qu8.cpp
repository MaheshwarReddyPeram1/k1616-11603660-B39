#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct Student
{
	int arrvl_time;
	int br_time;
	int Stu_Id;
}z[10];

struct Faculty
{
	int arrvl_time;
	int br_time;
	int Fct_Id;
}w[10];
bool Sort_Student(Student m, Student b)
{
	return m.arrvl_time<b.arrvl_time;
}
bool Sort_Faculty(Faculty m, Faculty b)
{
	return m.arrvl_time<b.arrvl_time;
}
int main()
{
	int t;	
	int Is;
	cool:
	cout<<"Enter 1 for faculty  2 for student"<<endl;
	cin>>Is;
	//Faculty Query Requests
  
  if(Is==1){
    int a1,b1,c1,k1;
	cout<<"Please Enter the number of processes:\n";
	cin>>a1;	
	cout<<"Please Enter the arrival time of each Faculty_process:\n";
	for(b1=0;b1<a1;b1++)
	{
		cout<<"Please Enter the arrival time of Faculty"<<b1+1<<":"<<endl;
		cin>>w[b1].arrvl_time;
		w[b1].Fct_Id = b1+1;
	}
	cout<<"Please Enter the burst time of each Faculty_process:\n";
	for(b1=0;b1<a1;b1++)
	{
		cout<<"Please Enter the burst time of Faculty"<<b1+1<<":"<<endl;
		cin>>w[b1].br_time;
	}
	sort(w, w+a1, Sort_Faculty);
	cout<<"Faculty_Id"<<"\t"<<"Burst time"<<"\t"<<"Arrival time"<<endl;
	for(b1=0;b1<a1;b1++)
	{
		cout<<w[b1].Fct_Id<<"\t\t"<<w[b1].br_time<<"\t\t"<<w[b1].arrvl_time<<endl;
	}
	int br_time2[a1],arrvl_time2[a1];
	for(b1=0;b1<a1;b1++)
	{
		br_time2[b1]=w[b1].br_time;
	}
	for(b1=0;b1<a1;b1++)
	{
		arrvl_time2[b1]=w[b1].arrvl_time;
	}	
	int fixed_time1,wait_time1=0;
	cout<<"Please Enter Time Quantum for Faculty:"<<endl;
	cin>>fixed_time1;
	int time1,count1,remaia1,flag1;
	remaia1=a1;
	for(time1=0,count1=0;remaia1!=0;) 
    {
    if(br_time2[count1]<=fixed_time1 && br_time2[count1]>0) 
    { 
      time1+=br_time2[count1]; 
      br_time2[count1]=0; 
      flag1=1; 
    } 
    else if(br_time2[count1]>0) 
    { 
      br_time2[count1]=br_time2[count1]-fixed_time1; 
      time1+=fixed_time1; 
    }  
    if(br_time2[count1]==0 && flag1==1) 
    { 
      remaia1--; 
      //cout<<count1+1<<"\t"<<time1-w[count1].arrvl_time<<"\t"<<time1-w[count1].arrvl_time-w[count1].br_time<<endl;
      wait_time1+=time1-w[count1].arrvl_time-w[count1].br_time; 
	  flag1=0; 
    } 
    
    if(count1==a1-1) 
      count1=0; 
    else if(w[count1+1].arrvl_time<=time1) 
      count1++; 
    else 
      count1=0; 
  } 
  cout<<"\nAvrg Query Time\n"<<(wait_time1)/a1<<endl; 
  cout<<"\nTotal Time\n"<<(time1)<<endl; 
  }
  //Student Query Requests//.
	else if(Is==2)
	{
  	int n,i;
	cout<<"Please Enter the number of processes:\n";
	cin>>n;	
	cout<<"Please Enter the arrival time of each Student_process:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Please Enter the arrival time of Student"<<i+1<<":"<<endl;
		cin>>z[i].arrvl_time;
		z[i].Stu_Id = i+1;
	}

	cout<<"Please Enter the burst time of each Student_process:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Please Enter the burst time of Student"<<i+1<<":"<<endl;
		cin>>z[i].br_time;
	}
	sort(z, z+n, Sort_Student);
	
	cout<<"Student_id"<<"\t"<<"Burst time"<<"\t"<<"Arrival time"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<z[i].Stu_Id<<"\t\t"<<z[i].br_time<<"\t\t"<<z[i].arrvl_time<<endl;
	}
	int br_time1[n],arrvl_time1[n];
	for(i=0;i<n;i++)
	{
		br_time1[i]=z[i].br_time;
	}
	for(i=0;i<n;i++)
	{
		arrvl_time1[i]=z[i].arrvl_time;
	}
	int fixed_time;
	int wait_time=0;
	cout<<"Please Enter Time Quantum"<<endl;
	cin>>fixed_time;
	int time,count,remain,flag;
	remain=n;
	for(time=0,count=0;remain!=0;) 
    { 
    if(br_time1[count]<=fixed_time && br_time1[count]>0) 
    { 
      time+=br_time1[count]; 
      br_time1[count]=0; 
      flag=1; 
    } 
    else if(br_time1[count]>0) 
    { 
      br_time1[count]=br_time1[count]-fixed_time; 
      time+=fixed_time; 
    } 
    if(br_time1[count]==0 && flag==1) 
    { 
      remain--; 
     // cout<<count+1<<"\t"<<time-z[count].arrvl_time<<"\t"<<time-z[count].arrvl_time-z[count].br_time<<endl;
      wait_time+=time-z[count].arrvl_time-z[count].br_time; 
	  flag=0;
    }
    if(count==n-1) 
      count=0; 
    else if(z[count+1].arrvl_time<=time) 
      count++; 
    else 
      count=0; 
  } 
  cout<<"\nAverage Query Time\n"<<(wait_time)/n<<endl; 
  cout<<"\nTotal Time\n"<<(time)<<endl; 
  }
  
  else{
  	exit(0);
  } 
  goto cool;  
return 0;
}
