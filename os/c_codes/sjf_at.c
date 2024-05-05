// sjf with arrival time

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 50
int pid[MAX], at[MAX], bt[MAX], ct[MAX], tat[MAX], wt[MAX];
int n;

void sort_by_arrival_time() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;

                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }
}

void sjf() {
    sort_by_arrival_time();

    int current_time = 0;
    int completed = 0;
    bool executed[MAX] = { false };

    while (completed < n) {
        int sji = -1;
        int sjbt = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!executed[i] && at[i] <= current_time && bt[i] < sjbt) {
                sji = i;
                sjbt = bt[i];
            }
        }

        if (sji == -1) {
            current_time++;
        } 
        else {
            ct[sji] = current_time + bt[sji];
            tat[sji] = ct[sji] - at[sji];
            wt[sji] = tat[sji] - bt[sji];
            executed[sji] = true;
            current_time = ct[sji];
            completed++;
        }
    }
}

void sort_wt(){
	for (int i = 0; i < n - 1; i++) {
        		for (int j = 0; j < n - i - 1; j++) {
            		if (wt[j] > wt[j + 1]) {
                			int temp = pid[j];
                			pid[j] = pid[j + 1];
                			pid[j + 1] = temp;

               				temp = at[j];
                			at[j] = at[j + 1];
                			at[j + 1] = temp;

               				temp = bt[j];
                			bt[j] = bt[j + 1];
                			bt[j + 1] = temp;
                			
                			temp = ct[j];
                			ct[j] = ct[j + 1];
                			ct[j + 1] = temp;
                			
                			temp = wt[j];
                			wt[j] = wt[j + 1];
                			wt[j + 1] = temp;
                			
                			temp = tat[j];
                			tat[j] = tat[j + 1];
                			tat[j + 1] = temp;
            }
        }
    }
}

int main() {
	
    float atat = 0, awt = 0;			
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pid[i] = i;
        printf("Enter arrival time for process %d: ", i);
        scanf("%d", &at[i]);
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &bt[i]);
    }

    sjf();
    sort_wt();
    printf("PID\tAT\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    
    for (int i = 0; i < n; i++) {
        atat += tat[i];
        awt += wt[i];
    }
    atat /= n;
    awt /= n;
    
    printf("Avg Turnaround Time is %f", atat);
    printf("\nAvg Waiting Time is %f\n", awt);

    return 0;
}
