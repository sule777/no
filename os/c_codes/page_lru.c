#include <stdio.h>

void main(){
	int m,n;
	int pages[50], frames[50], recent[50]={0};
	int pf = 0, ph = 0;
	int least_index;
	printf("Enter no. of frames: ");
	scanf("%d", &n);
	printf("Enter no. of pages: ");
	scanf("%d", &m);
	printf("Enter page string reference\n");
	for(int i=0; i<m; i++){
		scanf("%d", &pages[i]);
	}
	
	for(int i=0; i<n; i++){
			frames[i] = -1;
		}
	
	for(int i=0; i<m; i++){
		int pg = pages[i];
		int found = 0;
		
		for(int j=0; j<n; j++){
			if(frames[j] == pg){
				found = 1;
				recent[j] = i+1;
				ph++;
				break;
			}
		}
		
		if (!found){
			least_index = 0;
            		for (int j = 1; j < n; j++) 
            		{
                			if (recent[j] < recent[least_index]) {
                    			least_index = j;
                			}
            		}

            		frames[least_index] = pg;
            		recent[least_index] = i + 1;
            		pf++;
        		}

		
		printf("Page reference %d: ", pg);
		for(int j=0; j<n; j++){
			if(frames[j] == -1)
				printf("_ ");
			else
				printf("%d ", frames[j]);
		}
		printf("\n");
	}
	printf("\nTotal page hit = %d", ph);
	printf("\nTotal page miss = %d\n", pf);
}
