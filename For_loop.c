#include <stdio.h>

int main() 
{
	//Tinh tong cua day so A = 1 + 2 + 3 +...+ 100
	
	int A = 0;
	int i;
	
	//for (initialization, condition, updation)
	for (i = 1; i <= 100; i++)
	{
		A = A + i;
	}
	
	printf("Result: %d", A);
}


