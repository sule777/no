// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_FRAMES 100
// #define MAX_PAGES 100

// int main() 
// {
//     int frames[MAX_FRAMES] = {0};
//     int pages[MAX_PAGES] = {0};
//     int recent[MAX_FRAMES] = {0}; // Array to store recent access times
//     int n, m; // Number of frames & pages
//     int page_faults = 0;
//     printf("Enter the number of frames: ");
//     scanf("%d", &n);
//     printf("Enter the number of pages: ");
//     scanf("%d", &m);
//     printf("Enter the page reference string:\n");
//     for (int i = 0; i < m; i++) 
//     {
//         scanf("%d", &pages[i]);
//     }
//     for (int i = 0; i < n; i++) 
//     {
//         frames[i] = -1; // Initialize frames with -1 (empty)
//     }
//     for (int i = 0; i < m; i++) 
//     {
//         int page = pages[i];
//         int found = 0;
//         // Check if page is already in frame
//         for (int j = 0; j < n; j++) 
//         {
//             if (frames[j] == page) 
//             {
//                 found = 1;
//                 recent[j] = i + 1; // Update recent access time
//                 break;
//             }
//         }
//         // If page is not found in frame, replace the least recently used page
//         if (!found) 
//         {
//             int least_recent_index = 0;
//             for (int j = 1; j < n; j++) 
//             {
//                 if (recent[j] < recent[least_recent_index]) {
//                     least_recent_index = j;
//                 }
//             }
//             frames[least_recent_index] = page;
//             recent[least_recent_index] = i + 1; // Update recent access time
//             page_faults++;
//         }
//         printf("Page reference %d: ", page);
//         for (int j = 0; j < n; j++) 
//         {
//             if (frames[j] == -1) 
//                 printf(" -");   
//             else 
//                 printf(" %d", frames[j]);
//         }
//         printf("\n");
//     }
//     printf("Total page faults: %d\n", page_faults);
//     return 0;
// }

#include<stdio.h>
#define MAX_FRAMES 100
#define MAX_PAGES 100
int main(){
    int pages[MAX_PAGES]={0},recent[MAX_FRAMES]={0},frames[MAX_FRAMES]={0},m,n,page_faults=0;
    printf("Enter the frame size: ");
    scanf("%d",&m);
    printf("Enter the lenght of thr page reference string: ");
    scanf("%d",&n);
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&pages[i]);
    }
    for (int i = 0; i < m; i++){
        frames[i]=-1;
    }
    for (int i = 0; i < n; i++){
        int page = pages[i];
        int found = 0;
        for (int j = 0; j < m; j++)
        {
            if(frames[j]==page){
                found=1;
                recent[j]=i+1;
                break;
            }
        }

        if(!found){
            int least_recent_index=0;
            for (int j = 1; j < m; j++){
                if (recent[j] < recent[least_recent_index]){
                    least_recent_index=j;
                }
            }
            frames[least_recent_index] = page;
            recent[least_recent_index] = i + 1; // Update recent access time
            page_faults++;
        }    

        printf("Page reference %d: ", page);
        for (int j = 0; j < m; j++) 
        {
            if (frames[j] == -1) 
                printf(" -");   
            else 
                printf(" %d", frames[j]);
        }
        printf("\n");
    }
    printf("%d",page_faults);
    
    return 0;
}