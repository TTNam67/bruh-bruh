#include <stdio.h>

int main() {
    int numbers[5] = {10, 25, 8, 31, 5}; // Initialize with values


	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (numbers[i] > numbers[i])
			{
				//doi gia tri 2 o nay cho nhau
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}


    printf("Elements of the array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    
    return 0;
}
