#include <stdio.h>
#define MAX 50
void main(){
	int i,j,temp, n, pid[MAX], at[MAX], bt[MAX], ct[MAX], tat[MAX], wt[MAX];
	float tt=0, wat=0;
	printf("Enter no. of processes\n");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		pid[i] = i;
		printf("Enter arrival time of process P%d = ",i);
		scanf("%d",&at[i]);
		printf("Enter burst time of process P%d = ",i);
		scanf("%d",&bt[i]);
	}
	
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(at[i]>at[j])
			{			
				temp = pid[i];
				pid[i] = pid[j];
				pid[j] = temp;
				
				temp = at[i];
				at[i] = at[j];
				at[j] = temp;
				
				temp = bt[i];
				bt[i] = bt[j];
				bt[j] = temp;
			}
		}
	}
	for(i=0; i<n; i++)
	{
		if(i==0){
			ct[i] = at[i] + bt[i];
		}
		else{
			ct[i] = bt[i] + ct[i-1];
		}	
	}
	
	for(i=0; i<n; i++)
	{
		tat[i] = ct[i] - at[i];
	}
	for(i=0; i<n; i++)
	{
		wt[i] = tat[i] - bt[i];
	}
	printf("PID\tAT\tBT\tCT\tTAT\tWT\n");	
	for(i=0; i<n ; i++)
	{
		printf("%d\t",pid[i]);
		printf("%d\t",at[i]);
		printf("%d\t",bt[i]);
		printf("%d\t",ct[i]);
		printf("%d\t",tat[i]);
		printf("%d  \n",wt[i]);
	}	
	for(i=0; i<n; i++)
	{
		tt = tt + tat[i];
		wat = wat + wt[i];
	}
	
	tt = tt/n;
	wat = wat/n;
	printf("Average Turnaround Time : %f\n", tt);
	printf("Average Waiting Time : %f\n", wat);
}
