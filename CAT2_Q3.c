/*
Name:Clinton Jerry 
Reg:CT100/G/26286/25
Description:A C program that reads a list of intergers from a file ,processes the integers ,and writes the results to a different file 
*/
   #include <stdio.h>
#include <stdlib.h>

// Function prototypes
void inputIntegersToFile();
void processIntegers();
void displayFiles();
int checkFileError(FILE *file, const char *filename);

int main() {
    int choice;
    
    printf("=== Integer File Processing Program ===\n\n");
    
    do {
        printf("Menu:\n");
        printf("1. Input 10 integers to file\n");
        printf("2. Process integers and calculate sum/average\n");
        printf("3. Display file contents\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                inputIntegersToFile();
                break;
            case 2:
                processIntegers();
                break;
            case 3:
                displayFiles();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
        printf("\n");
    } while (choice != 4);
    
    return 0;
}

// Function to check for file errors
int checkFileError(FILE *file, const char *filename) {
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1; // Error occurred
    }
    return 0; // No error
}

// Function 1: Prompt user for 10 integers and store in input.txt
void inputIntegersToFile() {
    FILE *inputFile;
    int numbers[10];
    int i;
    
    printf("Enter 10 integers:\n");
    
    // Get 10 integers from user
    for (i = 0; i < 10; i++) {
        printf("Enter integer %d: ", i + 1);
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input! Please enter integers only.\n");
            while (getchar() != '\n'); // Clear input buffer
            i--; // Retry this input
            continue;
        }
    }
    
    // Open file for writing
    inputFile = fopen("input.txt", "w");
    if (checkFileError(inputFile, "input.txt")) {
        return;
    }
    
    // Write integers to file
    for (i = 0; i < 10; i++) {
        fprintf(inputFile, "%d\n", numbers[i]);
    }
    
    fclose(inputFile);
    printf("Successfully wrote 10 integers to 'input.txt'\n");
}

// Function 2: Read integers, calculate sum and average, write to output.txt
void processIntegers() {
    FILE *inputFile, *outputFile;
    int numbers[10];
    int i, sum = 0;
    float average;
    
    // Open input file for reading
    inputFile = fopen("input.txt", "r");
    if (checkFileError(inputFile, "input.txt")) {
        return;
    }
    
    // Read integers from file
    for (i = 0; i < 10; i++) {
        if (fscanf(inputFile, "%d", &numbers[i]) != 1) {
            printf("Error: Could not read integer %d from file or file has less than 10 integers\n", i + 1);
            fclose(inputFile);
            return;
        }
        sum += numbers[i];
    }
    fclose(inputFile);
    
    // Calculate average
    average = (float)sum / 10;
    
    // Open output file for writing
    outputFile = fopen("output.txt", "w");
    if (checkFileError(outputFile, "output.txt")) {
        return;
    }
    
    // Write results to output file
    fprintf(outputFile, "Sum: %d\n", sum);
    fprintf(outputFile, "Average: %.2f\n", average);
    
    fclose(outputFile);
    printf("Successfully calculated and wrote results to 'output.txt'\n");
    printf("Sum: %d, Average: %.2f\n", sum, average);
}

// Function 3: Read and display contents of both files in formatted manner
void displayFiles() {
    FILE *inputFile, *outputFile;
    char line[100];
    int number, count = 0;
    
    // Display input.txt contents
    printf("=== Contents of input.txt ===\n");
    inputFile = fopen("input.txt", "r");
    if (checkFileError(inputFile, "input.txt")) {
        return;
    }
    
    count = 0;
    while (fscanf(inputFile, "%d", &number) == 1) {
        printf("Number %2d: %d\n", ++count, number);
    }
    fclose(inputFile);
    
    if (count == 0) {
        printf("File is empty or contains no valid integers.\n");
    }
    
    printf("\n");
    
    // Display output.txt contents
    printf("=== Contents of output.txt ===\n");
    outputFile = fopen("output.txt", "r");
    if (checkFileError(outputFile, "output.txt")) {
        return;
    }
    
    while (fgets(line, sizeof(line), outputFile) != NULL) {
        printf("%s", line);
    }
    fclose(outputFile);
    
    printf("\n");
}