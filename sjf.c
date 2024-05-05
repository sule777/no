#include<stdio.h>
struct Process{
    int pid;
    int at;
    int bt;
    int ct;
    int visited;
    int tat;
    int wt;
};

void main (){
    int n,total_bt=0;
    struct Process p[10];
    float avg_tat=0, avg_wt=0;
    printf("Enter the total number of processes");
    scanf("%d", &n);
    printf("Enter the process details");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Process ID: ");
        scanf("%d",&p[i].pid);
        printf("Enter the Arrival Time of the Process: ");
        scanf("%d",&p[i].at);
        printf("Entert the Burst Time of the Process: ");
        scanf("%d",&p[i].bt);
        p[i].visited=0;
        total_bt+=p[i].bt;
    }
    int current_time=0,completed=0;
    while(completed<n){
        int selected_process=-1;
        int minTime=total_bt+1;
        for(int i=0;i<n;i++){
            if(p[i].visited==0 && p[i].bt<minTime && p[i].at<=current_time)
            {
                minTime=p[i].bt;
                selected_process=i;
            }
        }
        if(selected_process==-1){
            current_time++;
            continue;
        }
        current_time+=p[selected_process].bt;
        p[selected_process].ct = current_time;
        p[selected_process].tat = p[selected_process].ct - p[selected_process].at;
        p[selected_process].wt = p[selected_process].tat - p[selected_process].bt;
        p[selected_process].visited = 1;
        completed++;
    }
    for (int i = 0; i < n; i++)
    {
        avg_tat+=p[i].tat;
        avg_wt+=p[i].wt;
    }
    avg_tat /= n;
    avg_wt /= n;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);
}