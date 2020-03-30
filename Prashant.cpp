#include<stdio.h>
int main(){
	int at[20],bt[20],ct[20],tat[20],wt[20],p[20],temp[20],temp1[20];
	int tch[20],st[20];
	int i,j=0,k=0,total=0,count=0;
	int n;
	char a;
	float avg_wt, avg_tat;
	
	printf("Enter the 5 process and its burst time\n");
	for(i=0;i<5;i++)
    {
		printf("Select Between Student and Teacher, Press s for Student and t for Teacher: ");
		scanf("%s",&a);
		if(a == 's'){
			printf("S%d: ",j);
			scanf("%d",&st[j]);
			bt[i]=st[j];
			p[i]=i+1;
			j++;
			}
		else if(a == 't'){
			printf("T%d: ",k);
			scanf("%d",&tch[k]);
			bt[i]=tch[k];
			p[i]=i+1;
			k++;
		}
		else{
			printf("Wrong Input");
		}	
}
ct[0]=bt[0];
for(i=1;i<5;i++){
	ct[i]=bt[i]+ct[i-1];
}


for(i=0;i<5;i++){
	at[i]=i;
}

for(i=0;i<5;i++)
    {
        tat[i]=ct[i]-at[i];     //calculate turnaround time
        total+=tat[i];
    }
    avg_tat=(float)total/n;     //average turnaround time
    total=0;
 
 
    //calculate waiting time
    for(i=0;i<5;i++)
    {
        wt[i]=tat[i]-bt[i];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
 
    printf("\nProcess\t     Arrival Time	Burst Time	  Completition Time    \tTurnaround Time  Waiting Time");
    for(i=0;i<5;i++)
    {
        printf("\np%d\t\t  %d\t\t  %d\t\t	%d\t\t    %d\t\t\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
 
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
