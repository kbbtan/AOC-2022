// GCC v11.3.0

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "./inputs/1.txt"
#define READ_MODE "r"
#define LINE_LENGTH 64
#define BASE_BINARY 10

/* Helper method which updates the three max elf sums.
INPUTS
long *maxElfSums: array of max elf sums
long newElfSum: new elf sum to be considered
*/
void updateMaxElfSums(long* maxElfSums, long newElfSum) {
    if (newElfSum > maxElfSums[2]) {
        maxElfSums[0] = maxElfSums[1];
        maxElfSums[1] = maxElfSums[2];
        maxElfSums[2] = newElfSum;
    
    } else if (newElfSum > maxElfSums[1]) {
        maxElfSums[0] = maxElfSums[1];
        maxElfSums[1] = newElfSum;

    } else if (newElfSum > maxElfSums[0]) {
        maxElfSums[0] = newElfSum;

    }
}

int main() {
    FILE* inputFile = fopen(FILENAME, READ_MODE);

    // File does not exist.
    if (inputFile == NULL) {
        printf("File does not exist\n");
        return 1;
    }

    char elfCaloriesStr[LINE_LENGTH];
    long elfSum = 0;

    // Maintain an array of the three max elf sums, sorted in ascending order.
    long maxElfSums[3] = {-1, -1, -1};

    while (fgets(elfCaloriesStr, LINE_LENGTH, inputFile) != NULL) {
        // Detect an empty line.
        if (elfCaloriesStr[0] == '\r') {
            updateMaxElfSums(maxElfSums, elfSum);
            elfSum = 0;

        } else {
            elfSum += strtol(elfCaloriesStr, NULL, BASE_BINARY);

        }
    }

    fclose(inputFile);
    
    // Account for the last elf.
    updateMaxElfSums(maxElfSums, elfSum);
    printf("%ld\n", maxElfSums[0] + maxElfSums[1] + maxElfSums[2]);

    return 0;
}