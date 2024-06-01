#include <stdio.h>

int main() {
    int dayOfWeek;

    printf("Enter a number (1-7) representing the day of the week: ");
    scanf("%d", &dayOfWeek);

    switch (dayOfWeek) 
	{
        case 1:
            printf("Monday - Start of the work week!\n");
            break;
        case 2:
            printf("Tuesday - Keep the momentum going!\n");
            break;
        case 3:
            printf("Wednesday - Hump day!\n");
            break;
        case 4:
            printf("Thursday - Almost there!\n");
            break;
        case 5:
            printf("Friday - TGIF!\n");
            break;
        case 6:
            printf("Saturday - Time to relax!\n");
            break;
        case 7:
            printf("Sunday - Enjoy your day off!\n");
            break;
        default:  // Optional default case if no match is found
            printf("Invalid input. Please enter a number between 1 and 7.\n");
    }
    
    return 0;
}
	
}


