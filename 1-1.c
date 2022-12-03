// GCC v11.3.0

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "./inputs/1.txt"
#define READ_MODE "r"
#define LINE_LENGTH 64
#define BASE_BINARY 10

int main() {
    FILE* inputFile = fopen(FILENAME, READ_MODE);

    // File does not exist.
    if (inputFile == NULL) {
        printf("File does not exist\n");
        return 1;
    }

    char elfCaloriesStr[LINE_LENGTH];
    long elfSum = 0;
    long maxElfSum = -1;

    while (fgets(elfCaloriesStr, LINE_LENGTH, inputFile) != NULL) {
        // Detect an empty line.
        if (elfCaloriesStr[0] == '\r') {
            maxElfSum = elfSum > maxElfSum ? elfSum : maxElfSum;
            elfSum = 0;

        } else {
            elfSum += strtol(elfCaloriesStr, NULL, BASE_BINARY);

        }
    }

    fclose(inputFile);

    // Account for the last elf.
    maxElfSum = elfSum > maxElfSum ? elfSum : maxElfSum;
    printf("%ld\n", maxElfSum);

    return 0;
}