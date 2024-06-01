#include <stdio.h>


//Kieu du lieu do nguoi dung tu dinh nghia dua tren cac kieu du lieu ban dau
//int: chua 1 so nguyen
//float: chua 1 so thuc
//char: chua 1 ki tu
//...

//Student: chua 1 chuoi ki tu, 1 so nguyen, 1 so thuc

struct Student 
{
	//attributes:
    char name[50];
    int id;
    float gpa;
};


int main() 
{
	// Create a student variable
    struct Student student1; 

    // Initialize the student's data
    strcpy(student1.name, "Alice Johnson");  // Copy the name into the char array
    student1.id = 12345;
    student1.gpa = 3.85;

    // Access and print the student's information
    printf("Student Information:\n");
    printf("Name: %s\n", student1.name);
    printf("ID: %d\n", student1.id);
    printf("GPA: %.2f\n", student1.gpa); 

    return 0;
}
