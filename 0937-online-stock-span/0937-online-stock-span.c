


typedef struct {
int *prices;
int *spans;
int top;
int capacity;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
    obj->capacity = 10000; // Assuming maximum input size
    obj->prices = (int*)malloc(obj->capacity * sizeof(int));
    obj->spans = (int*)malloc(obj->capacity * sizeof(int));
    obj->top = -1;  // Initialize stack to empty
    return obj;   
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;
    // Pop elements from the stack while the top of the stack has a smaller price
    while (obj->top != -1 && obj->prices[obj->top] <= price) {
        span += obj->spans[obj->top];
        obj->top--;  
}
    obj->top++;
    obj->prices[obj->top] = price;
    obj->spans[obj->top] = span;
    
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->prices);
    free(obj->spans);
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/