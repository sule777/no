#include <stdio.h> 
int main() { 
    int n, r, i, j, k; 
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &r);
    int alloc[n][r], max[n][r], avail[r];
    printf("Enter the allocation matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    }
    printf("Enter the max matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);
    }
    printf("Enter the available matrix: \n");
    for (i = 0; i < r; i++)
        scanf("%d", &avail[i]);

	int f[n], ans[n], index = 0;
	for (k = 0; k < n; k++) { 
		f[k] = 0;
	} 
	int need[n][r]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < r; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) { 
			if (f[i] == 0) { 
				int flag = 0; 
				for (j = 0; j < r; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 
				if (flag == 0) { 
					ans[index++] = i; 
					for (y = 0; y < r; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 
	printf("The SAFE Sequence is as follows: "); 
	for (i = 0; i < n - 1; i++) 
		printf(" P%d ->", ans[i]); 
	printf(" P%d\n", ans[n - 1]); 
	return (0); 
}
