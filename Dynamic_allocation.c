#include <stdio.h>



int main() 
{
	//allocation
    //static allocation 
    //occurs at compile time 
    //pros: o nho duoc giai phong tu dong 
    //cons: de gay lang phi o nho
    int Numbers[12];
    
    //dynamic allocation
    //occurs at run time 
    //pros: he thong tu dong cap phat khi can thiet 
    int n;
    int *ptr;
    printf("Enter the array's length': ");
    scanf("%d", &n);
    
    
	ptr = (int*)malloc(10 * sizeof(int)); //cap phat 10 o nho (moi o co do lon = 1 so nguyen ~ 4byte)
	//	ptr = (int*)calloc(10, sizeof(int));
	//malloc(40);
	//calloc(10, 4);
	
	
	// Check if the memory allocation is successful
    if (ptr == NULL) 
	{
        printf("Memory not allocated.\n");
        exit(0); // Exit the program with an error code
    }
    
    
    int i;
    for (i = 0; i < n; i++)
    {
    	printf("\nEnter %dth value: ", i+1);
    	scanf("%d", &ptr[i]);
	}
	
	
    printf("\nThe array:");
    for (i = 0; i < n; i++)
    {
    	printf("\n%d", ptr[i]);
	}
	
	free(ptr);
    
}


