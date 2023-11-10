#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


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
    char mychar;
    char fname[100]; // variable to store file name
    char filename[] = "FitnessData_2023.csv";
    

    printf("Enter Choice:\n");
    scanf("%c", &mychar);
    
    switch(mychar){
        case 'A':
            printf("Input file name:\n");
            scanf("%s", fname);
            if (strcmp(fname, filename) == 0){
                FILE *file = fopen(filename, "r");
                if (file != NULL){
                    printf("File successfully loaded\n");

                    fclose(file);
                }
            } else {
                printf("Error: could not open file\n");
            }
            break;
            }
            
    }
   










