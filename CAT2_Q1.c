/*
   Name:Clinton Jerry
   Reg:CT100/G/26286/25
   Description:2Darray c_program
*/
		#include <stdio.h>

int main() {
    // Declare and initialize the 2D array
    int scores[2][4] = {
        {65, 92, 84, 72},
        {35, 70, 59, 67}
    };
    
    // Print the array to verify
    printf("2D Array contents:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}