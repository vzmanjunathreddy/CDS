#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert node at the beginning
void insertAtBeginning(struct Node **head, int data) {
    struct Node* newNode = createNode(data);
    
    // If the list is empty
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        (*head)->prev = newNode;
        last->next = newNode;
        *head = newNode;  // Move the head to the new node
    }
}

// Insert node at the end
void insertAtEnd(struct Node **head, int data) {
    struct Node* newNode = createNode(data);
    
    // If the list is empty
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

// Insert node after a given node
void insertAfterNode(struct Node *head, int prevData, int data) {
    struct Node* temp = head;
    
    // Traverse the list to find the node with prevData
    do {
        if (temp->data == prevData) {
            struct Node* newNode = createNode(data);
            struct Node* nextNode = temp->next;
            
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = nextNode;
            nextNode->prev = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    
    printf("Node with data %d not found!\n", prevData);
}

// Delete node at the beginning
void deleteAtBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = *head;
    struct Node* last = (*head)->prev;
    
    if (*head == (*head)->next) {
        free(*head);
        *head = NULL;
    } else {
        last->next = temp->next;
        temp->next->prev = last;
        *head = temp->next;
        free(temp);
    }
}

// Delete node at the end
void deleteAtEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* last = (*head)->prev;
    struct Node* secondLast = last->prev;
    
    if (*head == last) {
        free(*head);
        *head = NULL;
    } else {
        secondLast->next = *head;
        (*head)->prev = secondLast;
        free(last);
    }
}

// Delete a specific node
void deleteNode(struct Node **head, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = *head;
    
    // Traverse the list to find the node to delete
    do {
        if (temp->data == data) {
            if (temp == *head) {
                deleteAtBeginning(head);
            } else if (temp->next == *head) {
                deleteAtEnd(head);
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
            return;
        }
        temp = temp->next;
    } while (temp != *head);
    
    printf("Node with data %d not found!\n", data);
}

// Traverse the circular doubly linked list
void traverseList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    do {
        printf("Node Data: %d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}

// Search for a node
struct Node* searchNode(struct Node *head, int data) {
    if (head == NULL) {
        return NULL;
    }
    
    struct Node* temp = head;
    do {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);
    
    return NULL;
}

// Reverse the list
void reverseList(struct Node **head) {
    if (*head == NULL) {
        return;
    }
    
    struct Node *temp = NULL;
    struct Node *current = *head;
    
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != *head);
    
    *head = temp->prev;
}

// Main function
int main() {
    struct Node *head = NULL;
    
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    insertAfterNode(head, 10, 15);
    
    printf("Circular Doubly Linked List: \n");
    traverseList(head);
    
    deleteNode(&head, 20);
    printf("\nAfter deleting node with data 20:\n");
    traverseList(head);
    
    deleteAtEnd(&head);
    printf("\nAfter deleting node at the end:\n");
    traverseList(head);
    
    deleteAtBeginning(&head);
    printf("\nAfter deleting node at the beginning:\n");
    traverseList(head);
    
    reverseList(&head);
    printf("\nAfter reversing the list:\n");
    traverseList(head);
    
    return 0;
}
