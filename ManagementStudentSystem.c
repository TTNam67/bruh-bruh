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

// Function to insert a student at the beginning of the list
void insertAtBeginning(struct Student** head_ref, struct Student new_student) 
{
    struct Student* new_node = (struct Student*)malloc(sizeof(struct Student));

    // Copy data to the new node (using memcpy for efficiency)
    memcpy(new_node, &new_student, sizeof(struct Student)); 

    new_node->next = *head_ref;
    new_node->prev = NULL; 

    if (*head_ref != NULL) 
	{
        (*head_ref)->prev = new_node;
    }

    *head_ref = new_node; 
}

// Function to insert a Student at the end of the list
void insertAtEnd(struct Student** head_ref, struct Student new_student) 
{

    // Allocate memory for the new node
    struct Student* new_node = (struct Student*)malloc(sizeof(struct Student));

    // Copy data from the new_student object
    strcpy(new_node->name, new_student.name);
    strcpy(new_node->studentID, new_student.studentID);
    new_node->gender = new_student.gender;
    new_node->yearOfBirth = new_student.yearOfBirth;
    new_node->gpa = new_student.gpa;
    strcpy(new_node->major, new_student.major);

    // Initialize pointers
    new_node->next = NULL;

    // If the list is empty, make the new node as head
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    // Otherwise, traverse till the last node
    struct Student* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    // Change the next of last node
    last->next = new_node;

    // Make last node as previous of new node
    new_node->prev = last;
}

// Function to delete a node from the doubly linked list
void deleteStudent(struct Student** head_ref, struct Student* del) 
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

// Function to update a student by student ID
void updateStudent(struct Student* head, char* studentID) 
{
    struct Student* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->studentID, studentID) == 0) {
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new GPA: ");
            scanf("%f", &temp->gpa);

            // Optionally, update other fields...
            return;
        }
        temp = temp->next;
    }
    printf("Student with ID %s not found.\n", studentID);
}


// Function to search for a student by ID
struct Student* searchStudentForId(struct Student* head, char* targetID) {
    struct Student* current = head;

    while (current != NULL) {
        // Compare the current node's ID with the target ID
        if (strcmp(current->studentID, targetID) == 0) {
            return current; // Found, return the student node
        }
        current = current->next; // Move to the next node
    }

    return NULL; // Not found
}

//sap xep tu nho -> lon
void sortList(struct Student** head_ref) {
    struct Student* current;
    struct Student* index = NULL;
   	

    // Check if the list is empty
    if (*head_ref == NULL)
        return;

    for (current = *head_ref; current != NULL; current = current->next) 
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
void printList(struct Student* node) 
{
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



int main() 
{
	struct Student* head = NULL;  // Your list's head pointer
	
    struct Student newStudent;
	strcpy(newStudent.name, "John Doe");
	strcpy(newStudent.studentID, "ST001");
	newStudent.gender = 1; // True for male
	newStudent.yearOfBirth = 1998;
	newStudent.gpa = 3.5;
	strcpy(newStudent.major, "Computer Science");
	
	struct Student newStudent2;
	strcpy(newStudent2.name, "Something");
	strcpy(newStudent2.studentID, "ST002");
	newStudent2.gender = 0; // True for male
	newStudent2.yearOfBirth = 1999;
	newStudent2.gpa = 4.0;
	strcpy(newStudent2.major, "Software Engineering");
	
	
	insertAtEnd(&head, newStudent);  
	insertAtEnd(&head, newStudent2);  
	
	
	struct Student newStudent3;
	strcpy(newStudent3.name, "Something2");
	strcpy(newStudent3.studentID, "ST003");
	newStudent3.gender = 1; // True for male
	newStudent3.yearOfBirth = 2003;
	newStudent3.gpa = 3.9;
	strcpy(newStudent3.major, "ABC");
	
	insertAtBeginning(&head, newStudent3);
	//1 -> 2
	sortList(&head);
    printList(head);
    
    char targetID[50];
	printf("Enter the student ID to search for: ");
    scanf("%s", targetID);

    struct Student* foundStudent = searchStudentForId(head, targetID);

    if (foundStudent != NULL) {
        printf("Student found:\n");
        printf("Name: %s\n", foundStudent->name);
        // ... (Print other details)
    } else {
        printf("Student not found.\n");
    }

//    
//    struct Student* nodeToDelete = head->next; // Delete the second node (value 7)
//
//    deleteStudent(&head, nodeToDelete);
//    // Update the node with data 1 to 12
//    updateStudent(&head, 1, 12); 
//
//    // Print the list (forward traversal)
//    printf("\nCreated DLL is: ");
//    printList(head);

    // Free memory (not shown, but important to prevent leaks)
	freeList(&head); 

    return 0;
}
