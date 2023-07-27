#include <stdio.h>
#include <stdlib.h>

// Function for linear probing
int linearProbing(int key, int i, int size) {
    return (key + i) % size;
}

// Function for quadratic probing
int quadraticProbing(int key, int i, int size) {
    return (key + i * i) % size;
}

// Function for double hashing
int doubleHashing(int key, int i, int size) {
    int h1 = key % size;
    int h2 = 7 - (key % 7);
    return (h1 + i * h2) % size;
}

// Function to insert a value into the hash table using the specified probing method
void insert(int table[], int value, int size, int (*probe)(int, int, int)) {
    int index, i = 0;
    
    do {
        index = probe(value, i, size);
        if (table[index] == -1) {
            table[index] = value;
            return;
        }
        i++;
    } while (i < size);
    
    printf("Hash table is full. Could not insert value: %d\n", value);
}

// Function to print the content of the hash table
void printTable(int table[], int size) {
    for (int i = 0; i < size; i++) {
        if (table[i] != -1) {
            printf("Table[%d] -> %d\n", i, table[i]);
        } else {
            printf("Table[%d] -> NULL\n", i);
        }
    }
}

int main() {
    int size, numValues, value, choice;

    printf("Table Size: ");
    scanf("%d", &size);

    // Create the hash table and initialize all elements to -1 (empty)
    int* table = malloc(size);
    for (int i = 0; i < size; i++) {
        table[i] = -1;
    }

    printf("Number of values: ");
    scanf("%d", &numValues);

    printf("Choose probing method (1 - Linear Probing, 2 - Quadratic Probing, 3 - Double Hashing): ");
    scanf("%d", &choice);

    int (*probe)(int, int, int);

    switch (choice) {
        case 1:
            probe = linearProbing;
            break;
        case 2:
            probe = quadraticProbing;
            break;
        case 3:
            probe = doubleHashing;
            break;
        default:
            printf("Invalid choice. Skipping value: %d\n", value);
            return 0;
    }

    printf("Input Values:\n");
    for (int i = 0; i < numValues; i++) {
        scanf("%d", &value);
        insert(table, value, size, probe);
    }

    printf("The table:\n");
    printTable(table, size);

    return 0;
}
