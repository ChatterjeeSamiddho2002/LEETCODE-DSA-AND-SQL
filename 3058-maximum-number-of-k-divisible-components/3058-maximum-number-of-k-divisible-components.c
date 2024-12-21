struct vector {
  int* array;
  int size;
};

void vector_push(struct vector* base, int value) {
  base->array = (int*)realloc(base->array, (base->size + 1) * sizeof(int));
  base->array[base->size] = value;
  ++base->size;
}

int dfs(int node, int parent, struct vector* adjacent_edges, int* values, int k, int* matches, int n) {
  int sum = 0;
  int neighbor_nodes = adjacent_edges[node].size;
  for (int i = 0; i < neighbor_nodes; ++i) {
    int neighbor_node = adjacent_edges[node].array[i];
    if (neighbor_node == parent) continue;
    sum += dfs(neighbor_node, node, adjacent_edges, values, k, matches, n);
  }
  sum += values[node];
  sum %= k;
  if (sum == 0) ++*matches;
  return sum;
}
int maxKDivisibleComponents(int n, int** edges, int edgesSize, int* edgesColSize, int* values, int valuesSize, int k) {
      // 2d array for neighbors of nodes
  struct vector* adjacent_edges = (struct vector*)malloc(n * sizeof(struct vector));
  for (int i = 0; i < n; ++i) adjacent_edges[i] = (struct vector){(int*)malloc(0 * sizeof(int)), 0};
  for (; edgesSize; ++edges, --edgesSize) {
    int first_node = (*edges)[0], second_node = (*edges)[1];
    vector_push(adjacent_edges + first_node, second_node);
    vector_push(adjacent_edges + second_node, first_node);
  }
  int matches = 0;
  dfs(0, -1, adjacent_edges, values, k, &matches, n);
  return matches;
}