#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Hash Table Structure
typedef struct HashTable {
    int *key;  // Array to store keys
    int *value; // Array to store values
    int size;    // Size of the hash table
} HashTable;

// Basic hash function (simple modulo)
unsigned int hash(int key, int table_size) {
    return key % table_size;
}

// Create a hash table
HashTable* create_table(int size) {
    HashTable *new_table = (HashTable*)malloc(sizeof(HashTable));
    new_table->size = size;
    new_table->key = (int*)malloc(size * sizeof(int));
    new_table->value = (int*)malloc(size * sizeof(int));

    // Initialize all values to -1 (empty slots)
    for (int i = 0; i < size; i++) {
        new_table->key[i] = -1;
        new_table->value[i] = -1;
    }
    return new_table;
}

// Linear Probing Insert
unsigned int linear_probe(int hash, int step, int table_size) {
    return (hash + step) % table_size;
}

void linear_insert(HashTable *hash_table, int key, int value) {
    unsigned int index = hash(key, hash_table->size);
    int step = 0;

    while (hash_table->key[index] != -1) {  // If slot is occupied
        step++;
        index = linear_probe(index, step, hash_table->size);  // Probe linearly
    }

    hash_table->key[index] = key;
    hash_table->value[index] = value;
}

// Quadratic Probing Insert
unsigned int quadratic_probe(int hash, int step, int table_size) {
    return (hash + step * step) % table_size;
}

void quadratic_insert(HashTable *hash_table, int key, int value) {
    unsigned int index = hash(key, hash_table->size);
    int step = 0;

    while (hash_table->key[index] != -1) {  // If slot is occupied
        step++;
        index = quadratic_probe(index, step, hash_table->size);  // Probe quadratically
    }

    hash_table->key[index] = key;
    hash_table->value[index] = value;
}

// Double Hashing Insert
unsigned int hash2(int key, int table_size) {
    return 1 + (key % (table_size - 1));  // Second hash function
}

unsigned int double_hash(int hash, int step, int table_size, int key) {
    return (hash + step * hash2(key, table_size)) % table_size;
}

void double_hash_insert(HashTable *hash_table, int key, int value) {
    unsigned int index = hash(key, hash_table->size);
    int step = 0;

    while (hash_table->key[index] != -1) {  // If slot is occupied
        step++;
        index = double_hash(index, step, hash_table->size, key);  // Double hashing
    }

    hash_table->key[index] = key;
    hash_table->value[index] = value;
}

// Search for a key in the hash table
int search(HashTable *hash_table, int key) {
    unsigned int index = hash(key, hash_table->size);
    int step = 0;

    while (hash_table->key[index] != -1) {
        if (hash_table->key[index] == key) {
            return hash_table->value[index];
        }
        step++;
        index = linear_probe(index, step, hash_table->size);  // Linear probing to check next slot
    }
    return -1;  // Not found
}

// Delete a key-value pair
void delete(HashTable *hash_table, int key) {
    unsigned int index = hash(key, hash_table->size);
    int step = 0;

    while (hash_table->key[index] != -1) {
        if (hash_table->key[index] == key) {
            hash_table->key[index] = -1;  // Mark as deleted
            hash_table->value[index] = -1;
            return;
        }
        step++;
        index = linear_probe(index, step, hash_table->size);  // Linear probing
    }

    printf("Key not found!\n");
}

// Print the hash table
void print_table(HashTable *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        if (hash_table->key[i] != -1) {
            printf("[%d] Key: %d, Value: %d\n", i, hash_table->key[i], hash_table->value[i]);
        } else {
            printf("[%d] Empty\n", i);
        }
    }
}

// Main function to test the hash table
int main() {
    // Create a hash table
    HashTable *hash_table = create_table(TABLE_SIZE);

    // Insert data using linear probing
    linear_insert(hash_table, 5, 100);
    linear_insert(hash_table, 15, 200);
    linear_insert(hash_table, 25, 300);

    printf("Linear Probing Hash Table:\n");
    print_table(hash_table);

    // Insert data using quadratic probing
    HashTable *quadratic_table = create_table(TABLE_SIZE);
    quadratic_insert(quadratic_table, 5, 100);
    quadratic_insert(quadratic_table, 15, 200);
    quadratic_insert(quadratic_table, 25, 300);

    printf("\nQuadratic Probing Hash Table:\n");
    print_table(quadratic_table);

    // Insert data using double hashing
    HashTable *double_hash_table = create_table(TABLE_SIZE);
    double_hash_insert(double_hash_table, 5, 100);
    double_hash_insert(double_hash_table, 15, 200);
    double_hash_insert(double_hash_table, 25, 300);

    printf("\nDouble Hashing Hash Table:\n");
    print_table(double_hash_table);

    // Search for a key
    int key_to_search = 15;
    printf("\nSearch for key %d in Linear Probing Table: %d\n", key_to_search, search(hash_table, key_to_search));
    printf("Search for key %d in Quadratic Probing Table: %d\n", key_to_search, search(quadratic_table, key_to_search));
    printf("Search for key %d in Double Hashing Table: %d\n", key_to_search, search(double_hash_table, key_to_search));

    // Delete a key
    delete(hash_table, 15);
    delete(quadratic_table, 15);
    delete(double_hash_table, 15);

    printf("\nAfter deleting key 15:\n");

    printf("\nLinear Probing Table:\n");
    print_table(hash_table);
    printf("\nQuadratic Probing Table:\n");
    print_table(quadratic_table);
    printf("\nDouble Hashing Table:\n");
    print_table(double_hash_table);

    // Free allocated memory
    free(hash_table->key);
    free(hash_table->value);
    free(hash_table);
    free(quadratic_table->key);
    free(quadratic_table->value);
    free(quadratic_table);
    free(double_hash_table->key);
    free(double_hash_table->value);
    free(double_hash_table);

    return 0;
}
