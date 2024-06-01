#include <stdio.h>

int main() 
{
	//While
	//Thuc hien 'hanh dong' khi ma dieu kien van con dung
	//Tinh tong cua day so A = 1 + 2 + 3 +...+ 100
	
	int A = 0;
	int i;
	
	while(i <= 100)
	{
		A = A + i;
		i++;
	}
	
	printf("Result: %d", A);
	
	
	//Do while
	// Thuc hien 'hanh dong' 1 lan roi moi xet dieu kien 
	int x = 0;
	do
	{
		printf("\nValue of x: %d", x);
	}
	while(x > 1);
}


