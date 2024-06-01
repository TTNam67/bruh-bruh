#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    int id;
    float gpa;
    struct Student *next;
};

struct Student *head = NULL;

// Function prototypes
void addStudent();
void deleteStudent();
void updateStudent();
struct Student *searchStudent();
void sortStudents();
void displayStudents();
int getChoice();

int main() 
{
    int choice;

    while (1) 
	{
        choice = getChoice();

        switch (choice) 
		{
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                sortStudents();
                break;
            case 6:
                displayStudents();
                break;
            case 7:
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// ... (addStudent, deleteStudent, updateStudent, searchStudent, sortStudents, displayStudents functions)

void addStudent()
{
	struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter name: ");
    scanf("%s", newStudent->name);
    printf("Enter ID: ");
    scanf("%d", &newStudent->id);
    printf("Enter GPA: ");
    scanf("%f", &newStudent->gpa);

    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newStudent;
    }
}

void deleteStudent(int id) 
{
    struct Student* temp = head;
    struct Student* prev = NULL;

    if (temp != NULL && temp->id == id) 
	{
        head = temp->next;   
        free(temp);
        return;
    }

    while (temp != NULL && temp->id != id) 
	{
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // Not found

    prev->next = temp->next;

    free(temp);
}

// Function to get user's choice from menu
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
    return choice;
}
