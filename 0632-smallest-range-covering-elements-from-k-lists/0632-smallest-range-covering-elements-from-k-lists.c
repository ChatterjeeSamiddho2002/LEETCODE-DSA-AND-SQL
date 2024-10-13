typedef struct {
    int val;
    int row;
    int col;
} HeapNode;

// Min-heap functions
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(HeapNode* heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].val < heap[smallest].val)
        smallest = left;

    if (right < n && heap[right].val < heap[smallest].val)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void buildHeap(HeapNode* heap, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}

int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int k = numsSize;
    HeapNode* heap = (HeapNode*)malloc(k * sizeof(HeapNode));
    int max = INT_MIN;

    // Initialize the heap with the first element from each list
    for (int i = 0; i < k; i++) {
        heap[i].val = nums[i][0];
        heap[i].row = i;
        heap[i].col = 0;
        if (nums[i][0] > max) max = nums[i][0];
    }

    buildHeap(heap, k);

    int range = INT_MAX;
    int start = 0, end = 0;
    
    while (1) {
        int min = heap[0].val;
        int row = heap[0].row;
        int col = heap[0].col;

        if (max - min < range) {
            range = max - min;
            start = min;
            end = max;
        }

        if (col + 1 < numsColSize[row]) {
            heap[0].val = nums[row][col + 1];
            heap[0].col = col + 1;
            if (nums[row][col + 1] > max) max = nums[row][col + 1];
        } else {
            break;  // We've reached the end of one of the lists
        }

        heapify(heap, k, 0);
    }

    free(heap);

    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = start;
    result[1] = end;
    *returnSize = 2;

    return result;
}