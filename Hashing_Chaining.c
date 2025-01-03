#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Structure for a node in a linked list
struct Node {
    int key;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Hash function (simple modulo)
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert a key into the hash table (chaining)
void insertChaining(struct Node* hashTable[], int key) {
    int index = hash(key);
    struct Node* newNode = createNode(key);

    // Insert at the beginning of the linked list
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Insert a key into the hash table (linear probing)
void insertProbing(int hashTable[], int key) {
    int index = hash(key);
    int initialIndex = index;

    // Linear probing to handle collisions
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE; // Circular probing
        if (index == initialIndex) {
            printf("Hash table overflow.\n");
            return;
        }
    }

    hashTable[index] = key;
}

// Search for a key in the hash table (chaining)
struct Node* searchChaining(struct Node* hashTable[], int key) {
    int index = hash(key);
    struct Node* temp = hashTable[index];

    // Traverse the linked list
    while (temp != NULL) {
        if (temp->key == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Search for a key in the hash table (linear probing)
int searchProbing(int hashTable[], int key) {
    int index = hash(key);
    int initialIndex = index;

    // Linear probing to search
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE; // Circular probing
        if (index == initialIndex) {
            break; // Not found
        }
    }

    return -1; // Key not found
}

// Display the hash table (chaining)
void displayChaining(struct Node* hashTable[]) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d ", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Display the hash table (linear probing)
void displayProbing(int hashTable[]) {
    int i;
    printf("Hash Table:\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        if (hashTable[i] != -1) {
            printf("%d\n", hashTable[i]);
        } else {
            printf("Empty\n");
        }
    }
}

int main() {
    // Chaining
    struct Node* chainingHashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        chainingHashTable[i] = NULL;
    }
    insertChaining(chainingHashTable, 12);
    insertChaining(chainingHashTable, 25);
    insertChaining(chainingHashTable, 35);
    insertChaining(chainingHashTable, 10);
    insertChaining(chainingHashTable, 22);
    insertChaining(chainingHashTable, 12); // Collision
    displayChaining(chainingHashTable);

    // Linear Probing
    int probingHashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        probingHashTable[i] = -1;
    }
    insertProbing(probingHashTable, 12);
    insertProbing(probingHashTable, 25);
    insertProbing(probingHashTable, 35);
    insertProbing(probingHashTable, 10);
    insertProbing(probingHashTable, 22);
    displayProbing(probingHashTable);

    return 0;
}