#include<stdio.h>
struct Process{
    int pid;
    int at;
    int bt;
    int ct;
    int remaining_bt;
    int tat;
    int wt;
};

void main (){
    int n,quantum;
    struct Process p[10];
    float avg_tat=0, avg_wt=0;
    printf("Enter the total number of processes");
    scanf("%d", &n);
    printf("Enter the process details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Process ID: ");
        scanf("%d",&p[i].pid);
        printf("Enter the Arrival Time of the Process: ");
        scanf("%d",&p[i].at);
        printf("Entert the Burst Time of the Process: ");
        scanf("%d",&p[i].bt);
        p[i].remaining_bt = p[i].bt;
    }
    printf("Enter time quantum:");
    scanf("%d",&quantum);
    int current_time = 0, completed = 0;
    while(completed < n) {
        int executed=0;
        for(int i = 0; i < n; i++) {
            if(p[i].remaining_bt > 0 && p[i].at <= current_time) {
                executed=1;
                if(p[i].remaining_bt <= quantum) {
                    current_time += p[i].remaining_bt;
                    p[i].ct = current_time;
                    p[i].remaining_bt = 0;
                    completed++;
                } else {
                    current_time += quantum;
                    p[i].remaining_bt -= quantum;
                }
            }
        }
        if(!executed)
            current_time++;
    }
    for(int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
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
