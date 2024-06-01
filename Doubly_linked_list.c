#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node 
{
    int data;
    struct Node* prev;  // Pointer to the previous node
    struct Node* next;  // Pointer to the next node
};

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);

	//Dung den khi moi khoi tao linked list - Head luc nay dang tro toi NULL
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    // 1. Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // 2. Store data and initialize pointers
    new_node->data = new_data;
    new_node->next = NULL; // This will be the last node

    // 3. If the list is empty, make the new node as head
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    // 4. Otherwise, traverse till the last node
    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    // 5. Change the next of last node
    last->next = new_node;

    // 6. Make last node as previous of new node
    new_node->prev = last;
}

// Function to delete a node from the doubly linked list
void deleteNode(struct Node** head_ref, struct Node* del) 
{
    // Base case: Empty list or invalid node
    if (*head_ref == NULL || del == NULL) 
        return; 

    // If the node to be deleted is the head node
    if (*head_ref == del)
        *head_ref = del->next;

    // Change next only if the node to be deleted is NOT the last node
    //Neu sau phan tu can xoa, con 1 phan tu nua 
    if (del->next != NULL)
        del->next->prev = del->prev; 

    // Change prev only if the node to be deleted is NOT the first node
    if (del->prev != NULL)
        del->prev->next = del->next;

    // Free the memory occupied by del
    free(del);
}

// Function to update a node in the doubly linked list
//Thay doi phan tu co gia tri 'oldData' -> 'newData'
void updateNode(struct Node** head_ref, int oldData, int newData) 
{
    // 1. Check if the list is empty
    if (*head_ref == NULL) {
        printf("Error: List is empty.\n");
        return;
    }
    
    // 2. Find the node with the oldData value
    struct Node* current = *head_ref; 
    while (current != NULL && current->data != oldData) {
        current = current->next;
    }

    // 3. If the node is found, update its data
    if (current != NULL) {
        current->data = newData;
        printf("Updated node with data %d to %d.\n", oldData, newData);
    } else {
        printf("Error: Node with data %d not found.\n", oldData);
    }
}

// Function to search for a specific value in the doubly linked list
struct Node* searchValue(struct Node* head, int target_value) {
    struct Node* current = head; // Start from the head of the list

    while (current != NULL) {
        if (current->data == target_value) {
            return current; // Value found, return the node
        }
        current = current->next; // Move to the next node
    }

    return NULL; // Value not found in the list
}

void sortList(struct Node** head_ref) {
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL; // Pointer to the last node

    // Check if the list is empty
    if (*head_ref == NULL)
        return;
		
    do {
        swapped = 0;
        ptr1 = *head_ref;

        while (ptr1->next != lptr) {
            // Compare adjacent node data
            if (ptr1->data > ptr1->next->data) {
                // Swap data of the nodes 
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // Update the last node pointer
    } 
	while (swapped); // Repeat until no more swaps are needed
}

// Function to print nodes in forward direction
void printList(struct Node* node) 
{
    while (node != NULL) 
	{
        printf("%d ", node->data);
        node = node->next;
    }
}

void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;

    while (current != NULL) {
        next = current->next; // Store the next node before freeing
        free(current);       // Free the current node
        current = next;      // Move to the next node
    }

    *head_ref = NULL; // Set head to NULL to indicate an empty list
}


int main() 
{
    // Start with an empty list
    struct Node* head = NULL;

    // Insert data in the list
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 4);
    
    struct Node* nodeToDelete = head->next; // Delete the second node (value 7)

    deleteNode(&head, nodeToDelete);
    // Update the node with data 1 to 12
    updateNode(&head, 1, 12); 

    // Print the list (forward traversal)
    printf("\nCreated DLL is: ");
    printList(head);

    // Free memory (not shown, but important to prevent leaks)
	freeList(&head); 

    return 0;
}
