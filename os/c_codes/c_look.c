#include <stdio.h>
#include <stdlib.h>
void main(){
	int req[50], head, initial, total = 0, dir;
	int n,i,j;
	int temp, index;
	printf("Enter no. of requests: ");
	scanf("%d", &n);
	printf("Enter the requests\n");
	for(i=0; i<n; i++){
		scanf("%d", &req[i]);
	}
	printf("Enter the initial head position: ");
	scanf("%d", &head);
	initial = head;
	
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(req[i] > req[j]){
			temp = req[i];
			req[i] = req[j];
			req[j] = temp;
			}
		}
	}
	
	printf("Enter the direction\n1.Increasing\n2.Decreasing\n3.Exit\n");
	while(1){
		scanf("%d", &dir);
		if(dir == 1){
			head = initial;
			total = 0;
			index = 0;
			for(int i=0; i<n; i++){
				if(req[i] >= head){
					index = i;
					break;
				}
			}
			
			for(i=index; i<n; i++){
				printf("%d -> ", req[i]);
				total += abs(head - req[i]);
				head = req[i];
			}
			
			for(i=0; i<index; i++){
				printf("%d -> ", req[i]);
				total += abs(head - req[i]);
				head = req[i];
			}
			printf("\nTotal head movement = %d\n", total);
		}
		else if(dir == 2){
			head = initial;
			total = 0;
			index = 0;
			for(int i=0; i<n; i++){
				if(req[i] >= head){
					index = i;
					break;
				}
			}
			
			for(i=index-1; i>=0; i--){
				printf("%d -> ", req[i]);
				total += abs(head - req[i]);
				head = req[i];
			}
			
			for(i=n-1; i>=index; i--){
				printf("%d -> ", req[i]);
				total += abs(head - req[i]);
				head = req[i];
			}
			
			printf("\nTotal head movement = %d\n", total);
		}
		else if(dir == 3)
			break;
	}
	
	
}
