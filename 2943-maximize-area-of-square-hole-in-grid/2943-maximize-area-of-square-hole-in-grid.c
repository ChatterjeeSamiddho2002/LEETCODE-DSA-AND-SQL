int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int longestConsecutive(int* arr, int size) {
    if (size == 0) return 1;

    qsort(arr, size, sizeof(int), cmp);

    int maxLen = 1, currLen = 1;

    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            currLen++;
        } else {
            if (currLen > maxLen)
                maxLen = currLen;
            currLen = 1;
        }
    }

    if (currLen > maxLen)
        maxLen = currLen;

    return maxLen + 1;
}
int maximizeSquareHoleArea(
    int n,
    int m,
    int* hBars,
    int hBarsSize,
    int* vBars,
    int vBarsSize
) {
    int maxH = longestConsecutive(hBars, hBarsSize);
    int maxV = longestConsecutive(vBars, vBarsSize);

    int side = maxH < maxV ? maxH : maxV;
    return side * side;
}
