#include <stdio.h>
#define BUFFER_SIZE 5

int main()
{
    int choice, left=0, right=0, size=0, item_id=1;
    int buffer_array[BUFFER_SIZE];
    
    while(1) //run until user Exits
    {
        printf("1.Producer\n 2.Consumer\n 3.Exit\n 4.Enter Choice: ");
        scanf("%d", &choice);
        
        if(choice == 3)
            break;
            
        else if(choice == 1)
        {
            if(size == BUFFER_SIZE)
            {
                printf("Buffer is Full\n");
            }
            else
            {
                printf("Producer generated item %d\n",item_id);
                buffer_array[right] = item_id; 
                item_id++; 
                right = (right + 1) % BUFFER_SIZE; 
                size++;
            }
        }
        
        else if(choice == 2)
        {
            if(size == 0)
            {
                printf("Buffer is empty\n");
            }
            else
            {
                printf("Cosumer consumed item %d\n",buffer_array[left]);
                left = (left + 1) % BUFFER_SIZE; 
                size--;
            }
        }
        else
        {
            printf("Wrong choice");
            break;
        }
    }
}
