#include <stdio.h>
#include <stdlib.h>

void main(){
	int req[50], n, head, total = 0;
	printf("Enter the total no. of requests: ");
	scanf("%d", &n);
	printf("Enter the requests\n");
	for(int i=0; i<n; i++){
		scanf("%d", &req[i]);
	}
	printf("\nEnter the head position: ");
	scanf("%d", &head);
	
	for(int i=0; i<n; i++){
		printf("%d -> ", req[i]);
		total += abs(req[i] - head);
		head = req[i];
	}
	printf("\nTotal head movement = %d\n", total);
}
