void dfs(int node, int parent, int dist, int* farthest, int* maxDist, int** adjList, int* adjSize) {
    if (dist > *maxDist) {
        *maxDist = dist;
        *farthest = node;
    }
    for (int i = 0; i < adjSize[node]; i++) {
        int next = adjList[node][i];
        if (next != parent) {
            dfs(next, node, dist + 1, farthest, maxDist, adjList, adjSize);
        }
    }
}

// Calculate the diameter of a tree
int calculateDiameter(int** edges, int edgesSize) {
    if (edgesSize == 0) return 0;
    
    int n = edgesSize + 1;
    int** adjList = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;  // Start with no allocated memory
    }
    
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        adjList[u] = (int*)realloc(adjList[u], (adjSize[u] + 1) * sizeof(int));
        adjList[v] = (int*)realloc(adjList[v], (adjSize[v] + 1) * sizeof(int));
        adjList[u][adjSize[u]++] = v;
        adjList[v][adjSize[v]++] = u;
    }

    int farthest, maxDist = -1;
    dfs(0, -1, 0, &farthest, &maxDist, adjList, adjSize);

    maxDist = -1;
    dfs(farthest, -1, 0, &farthest, &maxDist, adjList, adjSize);

    for (int i = 0; i < n; i++) {
        free(adjList[i]);  // Free dynamically allocated lists
    }
    free(adjList);
    free(adjSize);
    
    return maxDist;
}

int minimumDiameterAfterMerge(int** edges1, int edges1Size, int* edges1ColSize, int** edges2, int edges2Size, int* edges2ColSize) {
    int D1 = calculateDiameter(edges1, edges1Size);
    int D2 = calculateDiameter(edges2, edges2Size);
    
    int mergedDiameter = (D1 + 1) / 2 + (D2 + 1) / 2 + 1;
    return fmax(D1, fmax(D2, mergedDiameter));
}
