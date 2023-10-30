#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[10];
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    FITNESS_DATA fit;
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        perror(" ");
        return 1;
    }
    int count = 0;
    int file_size = 100;
    char file_line[file_size];
    while(fgets(file_line, file_size, file) != NULL){
        count = count + 1;
        tokeniseRecord(file_line, ",", fit.date, fit.time, fit.steps);
        printf("%s/%s/%s", fit.date, fit.time, fit.steps);
        }
    
    printf("Number of records in file: %d\n", count);
    fclose(file);
    return 0;

}
