#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#include <limits.h>

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
    int min = INT_MAX;
    FILE *file = NULL;
    
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
            rewind(file);
            while (fgets(line, buffer_size, file) != NULL) {
            totalrecords++ ;
            }
            printf("Number of records in file: %d\n", totalrecords);
            break;

            case 'C':
            rewind(file);
            int record = 0;
            int min = INT_MAX;
            while (fgets(line, buffer_size, file) != NULL) {
                tokeniseRecord(line, ",", fit[record].date , fit[record].time, fit[record].steps);
                int step = atoi(fit[record].steps);

                if (step < min) {
                    min = step;
                }
                record ++; 
            }
            for (int i = 0; i < record; i++) {
                int steps = atoi(fit[i].steps);
                if (steps == min)
                {
                    printf("Fewest steps: %s %s\n", fit[i].date, fit[i].time);
                }
            }
            break;

            case 'D':
            rewind(file);
            int records = 0;
            int max = INT_MIN;
            while (fgets(line, buffer_size, file) != NULL) {
                tokeniseRecord(line, ",", fit[records].date , fit[records].time, fit[records].steps);
                int step = atoi(fit[records].steps);

                if (step > max) {
                    max = step;
                }
                records ++;
            }
            for (int i = 0; i < records; i++) { 
                int steps = atoi(fit[i].steps);
                if (steps == max)
                {
                    printf("Largest steps: %s %s\n", fit[i].date, fit[i].time);
                }
            }
            break;

            case 'E':
            rewind(file);
            int count = 0;
            int totalrecord = 0;
            int mean = 0;
            while (fgets(line, buffer_size, file) != NULL) {
                tokeniseRecord(line, ",", fit[records].date , fit[records].time, fit[records].steps);
                int step = atoi(fit[records].steps);

                count = count + step;
                totalrecord++;
            }
            mean = count / totalrecord;

            printf("Mean step count: %d\n", mean);
            break;

            case 'F':
            while (fgets(line, buffer_size, file) != NULL) {
                tokeniseRecord(line, ",", fit[records].date , fit[records].time, fit[records].steps);
                int step = atoi(fit[records].steps);
        

    fclose(file);      
        }
      
        
    
    }
    
    return 0;
    
}

   
    

    
   










