#include <stdio.h>

int main() 
{
	int a;
	printf("Enter a number: ");
    scanf("%d", &a); 
    
    //Operator: + - * /, %, ==
    // cau truc if-else if - else if - ....
    // xet tu tren xuong duoi, gap duoc dieu kien dung thi thuc hien doan code ben trong
    // va khong xet them nhung dieu kien ben duoi nua 
    if (a % 3 == 0)
    {
    	printf("%d chia het cho 3", a);
	}
	else if (a % 3 == 1)
	{
		printf("%d chia 3 du 1", a);
	}
	else if (a % 3 == 2)
	{
		printf("%d chia 3 du 2", a);
	}
	
	int a = 9;
	if (a > 5 && a < 12)
	{
		
	}
}


