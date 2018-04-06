#include<stdio.h>
struct Processes
{
    char P_Name;
    int at,bt,ct,wt,mm,pri,bt1;
}pr[10],Pr1[10];
void main()
{
	struct Processes temp;
    int i,Time1=0,t1,m2,bu_t=0,Max,Lim,C=0,k,mf2=0,Lim2,n,Os,j,flag=0,y;
    float w_t=0,T_Time= 0,avt;
    printf("\nPlease Enter Total Number of Processes:\t");
    scanf("%d",&Lim);
    n=Lim;
    for(i=0;i<Lim;i++)
    {
    	printf("\nPlease Enter Process name:-");
    	fflush(stdin);
        scanf("%c",&pr[i].P_Name);
        printf("\nPlease Enter Details For Processesor %c:\n",pr[i].P_Name);
        
        printf("Please Enter Burst Time:-");
        scanf("%d",&pr[i].bt);
        printf("Please Enter Priority:\t");
        scanf("%d",&pr[i].pri);
        printf("Please Enter Arrival Time:-");
        scanf("%d",&pr[i].at);
        pr[i].bt1=pr[i].bt;
        
    }
    printf("\nPlease Enter Time Quantum for Round Robin queue:-");
    scanf("%d",&m2);
    printf("\nPlease Enter Time Quantum for Fixed priority queue:-");
    scanf("%d",&t1);
   
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(i=0;i<Lim;i++)
    {
        Os=i;
        for(j=i+1;j<Lim;j++)
        {
            if(pr[j].at<pr[Os].at)
                Os=j;
        }
        temp=pr[i];
        pr[i]=pr[Os];
        pr[Os]=temp;
    }
    Time1=pr[0].at;
    for(i=0;Lim!=0;i++)
    {
    	while(C!=t1)
    	{
    		C++;
    		if(pr[i].at<=Time1)
    		{
    			for(j=i+1;j<Lim;j++)
    			{
    				if(pr[j].at==Time1&&pr[j].pri<pr[i].pri)
    				{
    					Pr1[mf2]=pr[i];
						mf2++;
    					for(k=i;k<Lim-1;k++)
    						pr[k]=pr[k+1];
    					Lim--;
						C=0;
    					i=j-1;
    					j--;
					}
				}
			}
			Time1++;
			pr[i].bt--;
			if(pr[i].bt==0)
			{
				pr[i].mm=Time1-pr[i].at;
				pr[i].wt=pr[i].mm-pr[i].bt1;
				printf("%c\t|\t%d\t|\t%d\n",pr[i].P_Name,pr[i].mm,pr[i].wt);
				w_t+=Time1-pr[i].at-pr[i].bt1; 
    			T_Time+=Time1-pr[i].at;
    			for(k=i;k<Lim-1;k++)
    				pr[k]=pr[k+1];i--;
    			Lim--;
				C=t1;break;
			}
		}
		C=0;
		if(pr[i].bt!=0)
		{
			Pr1[mf2]=pr[i];
			mf2++;
			for(k=i;k<Lim-1;k++)
    			pr[k]=pr[k+1];
    		Lim--;
		}
			if(i==Lim-1)
				i=-1;
	}
	
	Lim2=mf2;
	for(C=0;Lim2!=0;) 
	{ 
		if(Pr1[C].bt<=m2&&Pr1[C].bt>0) 
    	{ 
    		Time1+=Pr1[C].bt; 
    		Pr1[C].bt=0; 
    		flag=1; 
    	} 
    	else if(Pr1[C].bt>0) 
    	{ 
    		Pr1[C].bt-=m2; 
    		Time1+=m2; 
    	} 
    	if(Pr1[C].bt==0&&flag==1) 
    	{ 
    		Lim2--; 
    		Pr1[C].mm=Time1-Pr1[C].at;
			Pr1[C].wt=Pr1[C].mm-Pr1[C].bt1; 
			printf("%c\t|\t%d\t|\t%d\n",Pr1[C].P_Name,Pr1[C].mm,Pr1[C].wt); 
    		T_Time+=Time1-Pr1[C].at; 
    		w_t+=Time1-Pr1[C].at-Pr1[C].bt1;
    		for(k=C;k<Lim2;k++)
    			Pr1[k]=Pr1[k+1];C--;
    		flag=0; 
    	} 

    	if(C==Lim2-1) 
      		C=0; 
    	else 
    		C++; 
    }
    printf("\nAvg Waiting Time= %f\n",w_t*1.0/n); 
    printf("Avg Trnd Time = %f",T_Time*1.0/n);   
}
