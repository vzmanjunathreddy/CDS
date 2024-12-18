#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Deque;

// Initialize the deque
void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if deque is empty
int isEmpty(Deque *dq) {
    return dq->front == -1;
}

// Check if deque is full
int isFull(Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1);
}

// Insert at the front
void insertFront(Deque *dq, int val) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) { // If deque is empty
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = val;
}

// Insert at the rear
void insertRear(Deque *dq, int val) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) { // If deque is empty
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = val;
}

// Delete from the front
void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    if (dq->front == dq->rear) { // Only one element
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

// Delete from the rear
void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    if (dq->front == dq->rear) { // Only one element
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

// Get the front element
int getFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->front];
}

// Get the rear element
int getRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

// Display the deque
void displayDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", dq->arr[dq->rear]);
}

int main() {
    Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertRear(&dq, 30);
    displayDeque(&dq);

    printf("Front: %d\n", getFront(&dq));
    printf("Rear: %d\n", getRear(&dq));

    deleteFront(&dq);
    deleteRear(&dq);
    displayDeque(&dq);

    return 0;
}
