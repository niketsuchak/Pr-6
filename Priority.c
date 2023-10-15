#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent a priority queue
typedef struct {
    int heap[MAX_SIZE];
    int size;
} PriorityQueue;

// Function to swap two elements in the heap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min-heap property after adding an element
void heapifyUp(PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && pq->heap[index] < pq->heap[parent]) {
        swap(&pq->heap[index], &pq->heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to insert an element into the priority queue
void insert(PriorityQueue *pq, int value) {
    if (pq->size >= MAX_SIZE) {
        printf("Priority Queue is full, cannot insert more elements.\n");
        return;
    }

    pq->heap[pq->size] = value;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

// Function to maintain the min-heap property after removing an element
void heapifyDown(PriorityQueue *pq, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < pq->size && pq->heap[leftChild] < pq->heap[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < pq->size && pq->heap[rightChild] < pq->heap[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&pq->heap[index], &pq->heap[smallest]);
        heapifyDown(pq, smallest);
    }
}

// Function to remove the minimum element from the priority queue
int removeMin(PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Priority Queue is empty.\n");
        return -1;
    }

    int minValue = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return minValue;
}

int main() {
    PriorityQueue pq = {{3, 1, 7, 5, 2, 4}, 6};
    printf("Original Priority Queue: ");
    for (int i = 0; i < pq.size; i++) {
        printf("%d ", pq.heap[i]);
    }
    printf("\n");

    insert(&pq, 0);
    printf("Priority Queue after inserting 0: ");
    for (int i = 0; i < pq.size; i++) {
        printf("%d ", pq.heap[i]);
    }
    printf("\n");

    int min = removeMin(&pq);
    printf("Removed min element: %d\n", min);
    printf("Priority Queue after removing min element: ");
    for (int i = 0; i < pq.size; i++) {
        printf("%d ", pq.heap[i]);
    }
    printf("\n");

    return 0;
}
