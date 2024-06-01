#include <stdio.h>

int main() 
{
	// char, int, float, 
	//khai bao bien: <ten kieu du lieu> <ten bien>
    char name[50]; // xau ki tu 
    int age;
    float height;

	//%s: string
	//$d: int
	//%f: float
	//%c: char
		
    // Get user input (scanf)
    printf("Enter your name: ");
    scanf("%s", name); // No & needed for strings
    
    
    //&: dia chi cua
    //&age: dia chi cua bien age
    printf("Enter your age: ");
    scanf("%d", &age); // Use & to get the memory address of age
    
    printf("Enter your height (in meters): ");
    scanf("%f", &height);

    // Display formatted output (printf)
    printf("\nHello, %s!\n", name);  
    printf("You are %d years old.\n", age);
    printf("Your height is %.2f meters.\n", height); // Format to 2 decimal places
	
    
}

