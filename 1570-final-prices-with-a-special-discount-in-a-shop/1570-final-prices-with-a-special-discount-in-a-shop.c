/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;
  int* stack = (int*)malloc(pricesSize * sizeof(int)), stackSize = 0; // stack holds undiscounted items
  for (int i = 0; i < pricesSize; ++i) {
    // while current value less than or equal to last stack item value
    while (stackSize && prices[stack[stackSize - 1]] >= prices[i]) {
      prices[stack[--stackSize]] -= prices[i]; // pop from stack and apply current item as discount
    }
    stack[stackSize] = i; ++stackSize; // push undiscounted item to stack
  }
  free(stack);
  return prices;
}