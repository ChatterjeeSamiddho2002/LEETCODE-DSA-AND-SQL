#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;      // Array to store stack elements
    int* inc;       // Array to store the increment values for each element
    int top;        // Index of the top element
    int maxSize;    // Maximum size of the stack
} CustomStack;

// Initializes the object with maxSize.
CustomStack* customStackCreate(int maxSize) {
    CustomStack* obj = (CustomStack*)malloc(sizeof(CustomStack));
    obj->data = (int*)malloc(maxSize * sizeof(int));   // Stack to hold the elements
    obj->inc = (int*)calloc(maxSize, sizeof(int));     // Array to hold increment values
    obj->top = -1;                                     // Initialize top index as -1 (empty stack)
    obj->maxSize = maxSize;                            // Set the maximum size
    return obj;
}

// Adds x to the top of the stack if the stack has not reached maxSize.
void customStackPush(CustomStack* obj, int x) {
    if (obj->top < obj->maxSize - 1) {  // Ensure there is space in the stack
        obj->top++;
        obj->data[obj->top] = x;
    }
}

// Pops and returns the top of the stack or -1 if the stack is empty.
int customStackPop(CustomStack* obj) {
    if (obj->top == -1) {  // Stack is empty
        return -1;
    }
    int result = obj->data[obj->top] + obj->inc[obj->top]; // Include any pending increment
    if (obj->top > 0) {
        obj->inc[obj->top - 1] += obj->inc[obj->top];  // Carry the increment to the next element
    }
    obj->inc[obj->top] = 0;  // Reset the increment for this element
    obj->top--;  // Pop the top element
    return result;
}

// Increments the bottom k elements of the stack by val. If there are less than k elements, increment all the elements.
void customStackIncrement(CustomStack* obj, int k, int val) {
    int limit = k < obj->top + 1 ? k : obj->top + 1;  // Limit to the number of available elements
    if (limit > 0) {
        obj->inc[limit - 1] += val;  // Add the increment to the last element in the range
    }
}

// Frees the memory allocated for the stack.
void customStackFree(CustomStack* obj) {
    free(obj->data);
    free(obj->inc);
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 * int param_2 = customStackPop(obj);
 * customStackIncrement(obj, k, val);
 * customStackFree(obj);
 */
