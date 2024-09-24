typedef struct TrieNode {
    struct TrieNode* children[10];  // Each node has up to 10 children (for digits 0-9)
} TrieNode;

// Create a new Trie node
TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < 10; i++) {
        node->children[i] = NULL;
    }
    return node;
}
void insertTrie(TrieNode* root, char* numStr) {
    TrieNode* currentNode = root;
    for (int i = 0; numStr[i] != '\0'; i++) {
        int digit = numStr[i] - '0';  // Convert character to corresponding digit
        if (currentNode->children[digit] == NULL) {
            currentNode->children[digit] = createTrieNode();
        }
        currentNode = currentNode->children[digit];
    }
}
int findLongestPrefixInTrie(TrieNode* root, char* numStr) {
    TrieNode* currentNode = root;
    int prefixLength = 0;
    
    for (int i = 0; numStr[i] != '\0'; i++) {
        int digit = numStr[i] - '0';  // Convert character to digit
        if (currentNode->children[digit] == NULL) {
            break;  // No further matching prefix
        }
        currentNode = currentNode->children[digit];
        prefixLength++;
    }
    return prefixLength;
}
int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
        TrieNode* root = createTrieNode();
    char numStr[12];
    int maxPrefixLength = 0;

    // Insert all numbers from arr2 into the Trie
    for (int i = 0; i < arr2Size; i++) {
        sprintf(numStr, "%d", arr2[i]);  // Convert number to string
        insertTrie(root, numStr);
    }

    // For each number in arr1, find the longest common prefix with numbers in Trie
    for (int i = 0; i < arr1Size; i++) {
        sprintf(numStr, "%d", arr1[i]);  // Convert number to string
        int prefixLength = findLongestPrefixInTrie(root, numStr);
        if (prefixLength > maxPrefixLength) {
            maxPrefixLength = prefixLength;
        }
    }

    // Free the Trie (optional, for memory management)
    // Freeing the Trie would involve traversing and freeing all nodes
    // But for simplicity, we're not doing that in this code snippet

    return maxPrefixLength;
}