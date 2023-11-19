#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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
    char line[buffer_size];
    char file_name[buffer_size];
    int totalrecords = 0;
    FITNESS_DATA fit[100];
    char min_date[buffer_size];
    char min_time[buffer_size];
    FILE *file = NULL;
    int min_steps = INT_MAX;
    
    
    while(1) {
        printf("Menu Options:\n");
        printf("A: Specify he filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter choice:\n");
        mychar = getchar();
        while (getchar() != '\n');

        switch (mychar)
        {
            case 'A': 
            printf("Input filename:\n");

            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", file_name);

        
            FILE *file = fopen(file_name, "r");
            if (file == NULL) {
                printf("Error: Could not find or open the file.\n");
                return 1;
            } else {
                printf("File successfully loaded.\n");
                }
            break;

            case 'B': 
            totalrecords = 0;
            while (fgets(line, buffer_size, file) != NULL) {
            totalrecords++ ;
            }
            printf("Number of records in file: %d\n", totalrecords);
            break;

            case 'C':
            rewind(file);
            
            totalrecords = 0;
            while (fgets(line, buffer_size, file) != NULL){
                tokeniseRecord(line, " , ", fit[totalrecords].date, fit[totalrecords].time, fit[totalrecords].steps);
                
                int step = atoi(fit[totalrecords].steps);

                if (step < min_steps){
                    min_steps = step;
                    strcpy(min_date, fit[totalrecords].date);
                    strcpy(min_time, fit[totalrecords].time);
                }
                totalrecords++;
            }
            if (min_steps !=  INT_MAX) {
                printf("%s %s\n", min_date, min_time);
            } else {
                printf("No timeslot found.\n");
            }
            break; 
        }
      
        
        
    }
    fclose(file);
    return 0;
    
}

   
    

    
   










