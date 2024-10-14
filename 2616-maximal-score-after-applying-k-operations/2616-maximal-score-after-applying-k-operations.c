typedef struct {
    int *array;
    int size;
    int capacity;
} MaxHeap;

// Function to create a max heap
MaxHeap* createMaxHeap(int capacity) {
    MaxHeap *maxHeap = (MaxHeap*)malloc(sizeof(MaxHeap));
    maxHeap->capacity = capacity;
    maxHeap->size = 0;
    maxHeap->array = (int*)malloc(capacity * sizeof(int));
    return maxHeap;
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the max heap
void maxHeapify(MaxHeap *maxHeap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest]) {
        largest = left;
    }
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&maxHeap->array[index], &maxHeap->array[largest]);
        maxHeapify(maxHeap, largest);
    }
}

// Function to insert a value into the max heap
void insertMaxHeap(MaxHeap *maxHeap, int value) {
    if (maxHeap->size == maxHeap->capacity) {
        return; // or handle resizing
    }
    maxHeap->array[maxHeap->size] = value;
    int current = maxHeap->size++;
    while (current != 0 && maxHeap->array[current] > maxHeap->array[(current - 1) / 2]) {
        swap(&maxHeap->array[current], &maxHeap->array[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

// Function to extract the maximum value from the max heap
int extractMax(MaxHeap *maxHeap) {
    if (maxHeap->size == 0) {
        return -1; // or handle underflow
    }
    if (maxHeap->size == 1) {
        return maxHeap->array[--maxHeap->size];
    }
    int root = maxHeap->array[0];
    maxHeap->array[0] = maxHeap->array[--maxHeap->size];
    maxHeapify(maxHeap, 0);
    return root;
}

// Function to calculate the maximum score after k operations
long long maxKelements(int* nums, int numsSize, int k) {
    MaxHeap *maxHeap = createMaxHeap(numsSize);
    
    // Build the max heap from the given array
    for (int i = 0; i < numsSize; i++) {
        insertMaxHeap(maxHeap, nums[i]);
    }

    long long score = 0;

    // Perform k operations
    for (int i = 0; i < k; i++) {
        int maxVal = extractMax(maxHeap);
        score += maxVal;
        int newVal = (int)ceil(maxVal / 3.0);
        insertMaxHeap(maxHeap, newVal);
    }

    // Cleanup
    free(maxHeap->array);
    free(maxHeap);
    
    return score;
}

