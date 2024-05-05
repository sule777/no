#include <stdio.h>


int main() {
    int partitions[100], processes[100];
    int m,n;

    printf("Enter the number of partitions: ");
    scanf("%d", &n);

    printf("Enter the size of each partition:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &partitions[i]);
    }
    
    printf("\nEnter the number of processes: ");
    scanf("%d", &m);

    printf("Enter the size of each process:\n");
    for (int i = 0; i < m; i++) 
    {
        scanf("%d", &processes[i]);
    }

    for (int i = 0; i < m; i++) 
    {
        int index = -1;
        int min_rem_space = 99999; // or use int max

        for (int j = 0; j < n; j++) 
        {
            if (partitions[j] >= processes[i] && partitions[j] - processes[i] < min_rem_space) 
            {
                min_rem_space =  partitions[j] - processes[i];
                index = j;
            }
        }

        if (index != -1) 
        {
            printf("Process %d: %d -> %d\n", i, processes[i], partitions[index]);
            int temp = partitions[index];
            int t = partitions[index] -= processes[i];
            printf("Remaining of %d is %d\n",temp, t);
        }
        else 
         	printf("Process %d: %d cannot be allocated\n", i, processes[i]);
            
    }

    return 0;
}
