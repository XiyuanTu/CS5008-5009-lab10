#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAIN_SIZE 100

// Function to insert a value into the hash table
void insert(int** table, int value, int size) {
    int index = value % size;
    
    // Find an empty slot in the chain
    int i = 0;
    while (table[index][i] != -1) {
        i++;
    }
    
    table[index][i] = value;
}

// Function to print the content of the hash table
void printTable(int** table, int size) {
    for (int i = 0; i < size; i++) {
        printf("Chain[%d] -> ", i);
        int j = 0;
        while (table[i][j] != -1) {
            printf("%d -> ", table[i][j]);
            j++;
        }
        printf("NULL\n");
    }
}

int main() {
    int size, numValues, value;

    printf("Chain Size: ");
    scanf("%d", &size);

    // Create the hash table as a nested array using dynamic memory allocation
    int** table = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        table[i] = (int*)malloc(MAX_CHAIN_SIZE * sizeof(int));
        for (int j = 0; j < MAX_CHAIN_SIZE; j++) {
            table[i][j] = -1;
        }
    }

    printf("Number of values: ");
    scanf("%d", &numValues);

    printf("Input Values:\n");
    for (int i = 0; i < numValues; i++) {
        scanf("%d", &value);
        insert(table, value, size);
    }

    printf("The table:\n");
    printTable(table, size);

    // Free the dynamically allocated memory for the hash table
    for (int i = 0; i < size; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}
