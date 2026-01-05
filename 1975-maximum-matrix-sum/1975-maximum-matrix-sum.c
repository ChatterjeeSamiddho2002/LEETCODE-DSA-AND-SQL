long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
long long sum = 0;
int negativeCount = 0;
int minAbsolute = INT_MAX;
for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
        int value = matrix[i][j];
        if (value < 0) negativeCount++;
        int absoluteValue = abs(value);
            sum += absoluteValue;
            if (absoluteValue < minAbsolute) {
                minAbsolute = absoluteValue;
            }
        }
    }
long long const int x=2;
if (negativeCount % 2 == 1) {
        sum -= x * minAbsolute;
    }

    return sum;
}