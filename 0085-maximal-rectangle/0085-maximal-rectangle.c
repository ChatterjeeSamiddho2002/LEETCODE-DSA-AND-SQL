//Function to find maximum between two numbers:
int higher(int a, int b){
    if(a>b) return a;
    else{
        return b;
    }
return 0;
}
int maxarea(int* heights, int n){
    int stack[n + 1];
    int top = -1;             
    int maximumArea = 0;
for (int i = 0; i <= n; i++) {
    int currentHeight;
    if (i == n)
        currentHeight = 0;
    else
        currentHeight = heights[i];
while (top != -1 && currentHeight < heights[stack[top]]) {
    int height = heights[stack[top]];
    top--; 
    int width;
    if (top == -1)
        width = i;
    else
        width = i - stack[top] - 1;
    int area = height * width;
    if (area > maximumArea)
            maximumArea = area;
    }
    top++;
    stack[top] = i;
    }

return maximumArea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;

    int cols = matrixColSize[0];
    int *heights = (int *)calloc(cols, sizeof(int));
    int totalmaximumArea = 0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1')
                heights[j] += 1;
            else
                heights[j] = 0;
        }
        totalmaximumArea = fmax(totalmaximumArea, maxarea(heights, cols));
    }
    free(heights);
    return totalmaximumArea;
}