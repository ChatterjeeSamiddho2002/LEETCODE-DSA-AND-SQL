int compareBots(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int compareFactory(const void* a, const void* b) {
    int* arr1 = *(int**)a;
    int* arr2 = *(int**)b;
    return arr1[0] - arr2[0];
}
long long minimumTotalDistance(int* robot, int robotSize, int** factory, int factorySize, int* factoryColSize) {
    long long** minTotalDistance = (long long**)malloc((robotSize + 1) * sizeof(long long*));
    for (int i = 0; i <= robotSize; i++) {
        minTotalDistance[i] = (long long*)malloc((factorySize + 1) * sizeof(long long));
        memset(minTotalDistance[i], 0, (factorySize + 1) * sizeof(long long));
    }
    qsort(robot, robotSize, sizeof(int), compareBots);
    qsort(factory, factorySize, sizeof(int*), compareFactory);
    for (int i = 1; i <= robotSize; i++) {
        minTotalDistance[i][0] = 200000000001LL;
    }
    for (int i = 0; i < robotSize; i++) {
        for (int j = 0; j < factorySize; j++) {
            minTotalDistance[i + 1][j + 1] = minTotalDistance[i + 1][j];
            long long distanceSum = 0;
            for (int k = i; k >= 0 && k > i - factory[j][1]; k--) {
                distanceSum += llabs((long long)factory[j][0] - robot[k]);
                long long candidate = minTotalDistance[k][j] + distanceSum;
                if (candidate < minTotalDistance[i + 1][j + 1]) {
                    minTotalDistance[i + 1][j + 1] = candidate;
                }
            }
        }
    }
    return minTotalDistance[robotSize][factorySize];
}