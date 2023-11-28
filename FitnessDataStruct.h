
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

#define buffer_size 1000
#define MAX_RECORDS 1000

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[10];
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

#endif // FITNESS_DATA_STRUCT_H
