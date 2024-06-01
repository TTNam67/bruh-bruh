#include <stdio.h>
#include <stdlib.h>

//Dac diem cua linked list
//vi tri cua cac phan tu nam rai rac tren thanh RAM

//Linked  list co 2 loai: mot chieu, 2 chieu

// Define a Node structure
struct Node 
{
    int value;
    struct Node* next; //dia chi cua Node tiep theo
};

int main() 
{
    // Create the head node and initialize it to NULL
    struct Node* head = NULL;
    
    int n; 
     printf("Enter the list's length'");
    scanf("%d", &n);

    // Insert nodes at the beginning of the list
    int i;
    for (i = n-1; i >= 0; i--) 
	{
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory
        // Assign data
        newNode->next = head; // Make newNode point to the previous head
        head = newNode; // Update head to point to newNode
    }

    // Traverse the linked list
    printf("Created linked list is: ");
    struct Node* temp = head; // nhiem vu cua temp: 
    while (temp != NULL) 
	{
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");

    // Free the memory (optional, but good practice)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
