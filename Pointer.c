#include <stdio.h>

int main() 
{
	
    int num = 42; // Declare an integer variable
    int *ptr;    // Declare a pointer to an integer

    ptr = &num;  // Assign the address of num to ptr

    // Modify the value through the pointer
    *ptr = 99;  
    printf("New value of num: %d\n", num);   // Output: New value of num: 99

	int ** ptr2;
	ptr2 = &ptr;
	printf("Value of num: %d\n", num);         
    printf("Address of num: %p\n", (void*)&num); 
    printf("Value of ptr: %p\n", (void*)ptr);    
    
    //*
	// khai bao: khai bao con tro
	// su dung o cho khac: gia tri tai dia chi
	// vi duL: *ptr (ptr: dia chi cua num): gia tri tai dia chi cua num
	printf("Value pointed to by ptr: %d\n", *ptr);
	
	printf("\n");
	printf("Address of ptr: %p\n", (void*)&ptr); 
	printf("Value of ptr2: %p\n", (void*)ptr2);    
	
	
    return 0;
}
