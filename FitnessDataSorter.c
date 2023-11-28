#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

int comparator(const void *x, const void *y) {
    const FitnessData *a = (const FitnessData *)x;
    const FitnessData *b = (const FitnessData *)y;
    return b->steps - a->steps;
}

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

#define buffer_size 100
#define max_record 100

int main() {
    char line[buffer_size];
    char filename[buffer_size];
    FILE *file = NULL;
    int records = 0;
    FitnessData fit[max_record];
    char outputFilename[buffer_size];
    
    
    printf("Enter filename: ");
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        return 1;
    }

    while(fgets(line, buffer_size, file) != NULL){
        tokeniseRecord(line, ',', fit[records].date, fit[records].time, &fit[records].steps);
        
        if (fit[records].steps <= 0) {
            printf("Error: invalid file\n");
            return 1;
        }

        if (strlen(fit[records].date) == 0) {
            printf("Error: invalid file\n");
            return 1;
        }

        if (strlen(fit[records].time) == 0) {
            printf("Error: invalid file\n");
            return 1;
        }
        records++;
        
    }
    fclose(file);

    qsort(fit, records, sizeof(FitnessData), comparator);

    
    strcpy(outputFilename, filename);
    strcat(outputFilename, ".tsv");

    
    FILE *output_file = fopen(outputFilename, "w");
    if (output_file == NULL) {
        printf("Error creating the output file.\n");
        return 1;
    }
    //fprintf(output_file, "%s", outputFilename);

    for (int i = 0; i < records; i++) {
        char steps[20];
        snprintf(steps, sizeof(steps), "%d", fit[i].steps);
        fprintf(output_file, "%s\t%s\t%s\n", fit[i].date, fit[i].time, steps);
    }
    fclose(output_file);

    printf("Data sorted and written to %s\n", outputFilename);


return 0;
}

