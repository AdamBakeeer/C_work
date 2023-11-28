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
    FILE *file = NULL;
    FITNESS_DATA fit[100];
    int totalrecords = 0;
    int min = INT_MAX;
    int max = INT_MIN;
    int count = 0;
    int mean = 0;
    int longestStart = 0;
    int longestEnd = 0;
    int currentStart = 0;
    int currentEnd = 0;
    int longestDuration = 0;
    int currentDuration = 0;
    
    while(1) {
        printf("Menu Options:\n");
        printf("A: Specify he filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter choice: ");
        
        mychar = getchar();
        while (getchar() != '\n');

        switch (mychar)
        {
            case 'A':
            case 'a':
            
            printf("Input filename: ");

            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", file_name);

        
            file = fopen(file_name, "r");
            if (file == NULL) {
                printf("Error: Could not find or open the file.\n");
                return 1;
            } else {
                printf("File successfully loaded.\n");
            }
            totalrecords = 0;
            while (fgets(line, buffer_size, file) != NULL) {
                tokeniseRecord(line, ",", fit[totalrecords].date , fit[totalrecords].time, fit[totalrecords].steps);
                //int step = atoi(fit[totalrecords].steps);
                totalrecords++;
            }
            fclose(file);
            break;

            case 'B':
            case 'b':
            printf("Number of records in file: %d\n", totalrecords);

            break;

            case 'C':
            case 'c':
            min = INT_MAX;
            for (int i = 0; i < totalrecords; i++) {
                int step = atoi(fit[i].steps);
                if (step < min){
                    min = step;
                }
            }
            
            for (int i = 0; i < totalrecords; i++) {
                int step = atoi(fit[i].steps);
                if (step == min) {
                    printf("Fewest steps: %s %s\n", fit[i].date, fit[i].time);
                }
            }

            break;

            case 'D':
            case 'd':
            for (int i = 0; i < totalrecords; i++) {
                int step = atoi(fit[i].steps);
                if (step > max){
                    max = step;
                }
            }

            for (int i = 0; i < totalrecords; i++) {
                int step = atoi(fit[i].steps);
                if (step == max) {
                    printf("Largest steps: %s %s\n", fit[i].date, fit[i].time);
                }
            }

            break;

            case 'E':
            case 'e':
            count = 0;
            for (int i = 0; i < totalrecords; i++) {
                int step = atoi(fit[i].steps);
                count += step;
            }

            if (totalrecords != 0) {
                //mean = (count + totalrecords / 2) / totalrecords;
                mean = count / totalrecords;
            }

            printf("Mean step count: %d\n", mean);
            break;

            case 'F':
            case 'f':

            for (int i = 0; i < totalrecords; i++) {
                int step = atoi(fit[i].steps);
                if (step > 500) {
                    if (currentDuration == 0) {
                        currentStart = i;
                    }
                    currentDuration ++;
                    currentEnd = i;
                } else {
                    if (currentDuration > longestDuration) {
                        longestDuration = currentDuration;
                        longestStart = currentStart;
                        longestEnd = currentEnd;
                    }
                    currentDuration = 0;
                }
            }
            if (currentDuration > longestDuration) {
                longestDuration = currentDuration;
                longestStart = currentStart;
                longestEnd = currentEnd;
            }

            printf("Longest period start: %s %s\n", fit[longestStart].date, fit[longestStart].time);
            printf("Longest period end: %s %s\n", fit[longestEnd].date, fit[longestEnd].time);
            break;

            case 'Q':
            case 'q':
            return 0;
            

            default: 
            printf("Invalid choice. Try again.\n");


        }
    }
}    









