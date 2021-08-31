#include <stdio.h>
#include <stdlib.h>

int size = 0;
int max_size,rear,front;

struct node                   //A struct of nodes
{
	int data;
	struct node *next_ptr;
};

void enqueue(struct node** block_ref, int new_data)         //A function to enqueue ne node.
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	
	new_node->data = new_data;
	
	new_node->next_ptr = (*block_ref);
	
	(*block_ref) = new_node;

}

void dequeue(struct node** block_ref, int key)         //A function to dequeue a node.
{
	struct node *temp = *block_ref, *prev;

	if (temp != NULL && temp->data == key) 
	{
		*block_ref = temp->next_ptr; 
		free(temp); 
		return;
	}
	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next_ptr;
	}
	if (temp == NULL)
		return;

	prev->next_ptr = temp->next_ptr;

	free(temp); 
}

int isFull()      //A function to see if the list is full.
{
    return (size == max_size);  
}
 
int isEmpty()       //A function to see if the list is empty.
{	
    return (size == 0);
}

int getFront(int front)    //A function to get the vlaue in the front of the queue. 
{
    if(isEmpty())
	{
        return -1;
    }
    else
	{
    	printf("\n\nThe front value is : %d\n",front);
        return front;
    }   
}
 
int getRear(int rear)       // A function to et the value in the rear of the queue.
{
    if(isEmpty())
	{
        return -1;
    }
    else
	{
    	printf("The rear value is : %d\n",rear);
        return rear;
    }
}



void printList(struct node *node)     //A funtion to print the lists.
{
while (node != NULL)
{
	printf(" %d ", node->data);
	node = node->next_ptr;
}
}

int main()       //The main function (Hamada Helal)
{
	int x;
	struct node* block = NULL;
	
	printf("Enter he size of the queue : \n");
	scanf("%d",&size);
	max_size = size;
	
	for (int i = 1;i <= size;i++)
{
	printf("Enter the element number %d : \n",i);
	scanf("%d",&x);
	enqueue(&block,x);
	if(i == 1)
	{
		rear = x;
	}
	if (i == size)
	{
		front = x;
	}
	
}
	printf("\n The queue after enqueue : \n");
	printList(block);
	
	getFront(front);
	getRear(rear);
	
	dequeue(&block,rear);
	printf("\n The queue after dequeue : \n");
	printList(block);
	
	return 0;
}

