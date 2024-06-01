#include <stdio.h>

int main() 
{
    int a, b;
    printf("Enter 1st integer: ");
	scanf("%d", &a);

	printf("\nEnter 2nd integer: ");
    scanf("%d", &b);
    
    int c = Sum(a, b);
    printf("result: %d", c);  
}

//kieu tra ve: void, int, float, char,..
// Tinh tong cua 2 so duoc truyen vao 
int Sum(int a, int b)
{
	int c = a + b; 
	return c;
}
