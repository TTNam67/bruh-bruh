#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the doubly linked list
struct Student 
{
    char name[40];
    char studentID[50];
    bool gender;
    int yearOfBirth;
    float gpa;
    char major[60];
    
    
    struct Student* prev;  // Pointer to the previous node
    struct Student* next;  // Pointer to the next node
}; 

struct Student* head = NULL;  // Your list's head pointer

// Insert a Student at the end of the list
void insertStudent() 
{
    // Allocate memory for the new node
    struct Student* new_node = (struct Student*)malloc(sizeof(struct Student));
    
    printf("\nEnter student's 'name: ");
	scanf("%[^\n]", new_node->name);
    
    printf("Enter student ID: ");
    scanf("%s", new_node->studentID);

    printf("Enter student's gender (1: male, 0: female): ");
	scanf("%d", &new_node->gender);

    printf("Enter student's year of birth: ");
    scanf("%d", &new_node->yearOfBirth);

    printf("Enter student's GPA: ");
    scanf("%f", &new_node->gpa);
	fflush(stdin);
    
    printf("Enter student's major: ");
    scanf("%[^\n]", new_node->major);

    // Initialize pointers
    new_node->next = NULL;

    // If the list is empty, make the new node as head
    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        return;
    }

    // Otherwise, traverse till the last node
    struct Student* last = head;
    while (last->next != NULL)
        last = last->next;

    // Change the next of last node
    last->next = new_node;

    // Make last node as previous of new node
    new_node->prev = last;
}

// Function to delete a node from the doubly linked list
void deleteStudent() 
{
	// Base case: Empty list or invalid node
    if (head == NULL) 
    {
    	printf("There's no student to be deleted");
    	return; 
	}
	
	struct Student* del = head;

	fflush(stdin);
	char id[50];
	printf("Enter the studentID that you want to delete: ");
    scanf("%s", id);
	
	while (del != NULL)
	{
		if (strcmp(id, del->studentID) == 0)
		{
			// Change "next" only if the node to be deleted is NOT the last node
			if (del->next != NULL)
			    del->next->prev = del->prev; 
			
			// Change "prev" only if the node to be deleted is NOT the first node
			if (del->prev != NULL)
			    del->prev->next = del->next;
			
			printf("Delete successfully");

			// If the node to be deleted is the head node
			if (head == del)
				head = del->next;
			free(del);
			return;
		}
		
		del = del->next;
	}
	
	printf("Couldn't find the student with the given studentID");

	// Free the memory occupied by del
	free(del);
}

// Function to update a student by student ID
void updateStudent()
{
    struct Student* temp = head;

	fflush(stdin);
	char id[50];
	printf("Enter the studentID that you want to update: ");
	scanf("%s", id);

    while (temp != NULL)
    {
        if (strcmp(temp->studentID, id) == 0)
        {
        	printf("\nEnter new student's 'name: ");
        	scanf("%[^\n]", temp->name);

        	printf("Enter student's gender (1: male, 0: female): ");
        	scanf("%d", &temp->gender);

        	printf("Enter student's year of birth: ");
        	scanf("%d", &temp->yearOfBirth);

        	printf("Enter student's GPA: ");
        	scanf("%f", &temp->gpa);
        	fflush(stdin);

        	printf("Enter student's major: ");
        	scanf("%[^\n]", temp->major);
            return;
        }
        temp = temp->next;
    }
    printf("Student with ID %s not found.\n", id);
}


// Function to search for a student by ID
void searchStudentForId()
{
    struct Student* node = head;
	fflush(stdin);
	char id[50];
	printf("Enter the studentID that you want to search for: ");
	scanf("%s", id);

    while (node != NULL)
    {
        // Compare the current node's ID with the target ID
        if (strcmp(node->studentID, id) == 0)
        {
        	printf("\nThe student's information: ");
        	printf("Name: %s\n", node->name);
        	printf("ID: %s\n", node->studentID);
        	printf("Gender: %s\n", node->gender ? "Male" : "Female");
        	printf("Year of Birth: %d\n", node->yearOfBirth);
        	printf("GPA: %.2f\n", node->gpa);
        	printf("Major: %s\n\n", node->major);

        }
        node = node->next; // Move to the next node
    }

	printf("Student with ID %s not found.\n", id);
}

//sap xep tu nho -> lon
void sortList()
{
    struct Student* current;
    struct Student* index = NULL;
   	

    // Check if the list is empty
    if (head == NULL)
        return;

    for (current = head; current != NULL; current = current->next)
	{
        for (index = current->next; index != NULL; index = index->next) 
		{
			int result = strcmp(current->name, index->name);
			//strcmp:
			// 0: bang nhau
			// -1: str1 < str2
			//1: str1 > str2
            // Compare adjacent node data
            printf("%d", result);
            if (result > 0) 
			{  
//    			swapStudents(&current, &index);
				struct Student temp;
				strcpy(temp.name, current->name);   // Copy strings using strcpy
				temp.gender = current->gender;
				temp.gpa = current->gpa;
				strcpy(temp.major, current->major);
				strcpy(temp.studentID, current->studentID);
				temp.yearOfBirth = current->yearOfBirth;
				
				strcpy(current->name, index->name);
				current->gender = index->gender;
				current->gpa = index->gpa;
				strcpy(current->major, index->major);
				strcpy(current->studentID, index->studentID);
				current->yearOfBirth = index->yearOfBirth;
				
				strcpy(index->name, temp.name);
				index->gender = temp.gender;
				index->gpa = temp.gpa;
				strcpy(index->major, temp.major);
				strcpy(index->studentID, temp.studentID);
				index->yearOfBirth = temp.yearOfBirth;
            }
        }
    }
}


// Function to print student details in the list
void printList() 
{
	struct Student* node = head;
	
	
    while (node != NULL) {
        printf("Name: %s\n", node->name);
        printf("ID: %s\n", node->studentID);
        printf("Gender: %s\n", node->gender ? "Male" : "Female");
        printf("Year of Birth: %d\n", node->yearOfBirth);
        printf("GPA: %.2f\n", node->gpa);
        printf("Major: %s\n\n", node->major);
        node = node->next;
    }
}

// Function to free the memory used by the doubly linked list
void freeList(struct Student** head_ref) {
    struct Student* current = *head_ref;
    struct Student* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head_ref = NULL; 
}

int getChoice() 
{
    int choice;
    printf("\nStudent Management System\n");
    printf("1. Add Student\n");
    printf("2. Delete Student\n");
    printf("3. Update Student\n");
    printf("4. Search Student\n");
    printf("5. Sort Students\n");
    printf("6. Display Students\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

	fflush(stdin);

    return choice;
}

int main() 
{
    int choice;

    while (1) 
	{
        choice = getChoice();

        switch (choice) 
		{
            case 1:
                insertStudent();
                break;
            case 2:
            	deleteStudent();
        		break;
        	case 3:
        		updateStudent();
        		break;
        	case 4:
        		searchStudentForId();
        		break;
        	case 5:
        		sortList();
        		break;
            case 6:
            	printList();
        		break;
            case 7:
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

