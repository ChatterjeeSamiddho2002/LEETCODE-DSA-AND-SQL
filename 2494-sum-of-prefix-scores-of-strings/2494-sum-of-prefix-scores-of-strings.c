/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct TrieNode {
    struct TrieNode* children[26];  // Assuming only lowercase English letters (a-z)
    int count;  // To keep track of how many strings have this prefix
} TrieNode;

// Create a new Trie node
TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->count = 0;
    return node;
}

// Insert a word into the Trie
void insertTrie(TrieNode* root, char* word) {
    TrieNode* currentNode = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';  // Get the position of the character in alphabet
        if (currentNode->children[index] == NULL) {
            currentNode->children[index] = createTrieNode();
        }
        currentNode = currentNode->children[index];
        currentNode->count += 1;  // Increment the count for this prefix
    }
}

// Calculate the sum of scores for all prefixes of a word
int calculateScore(TrieNode* root, char* word) {
    TrieNode* currentNode = root;
    int totalScore = 0;
    
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';  // Get the position of the character in alphabet
        currentNode = currentNode->children[index];
        if (currentNode == NULL) {
            break;  // No more prefixes
        }
        totalScore += currentNode->count;  // Add the count of this prefix
    }
    
    return totalScore;
}
int* sumPrefixScores(char** words, int wordsSize, int* returnSize) {
        // Initialize Trie
    TrieNode* root = createTrieNode();
    
    // Insert all words into the Trie
    for (int i = 0; i < wordsSize; i++) {
        insertTrie(root, words[i]);
    }
    
    // Prepare the result array
    int* result = (int*)malloc(wordsSize * sizeof(int));
    *returnSize = wordsSize;
    
    // Calculate the score for each word
    for (int i = 0; i < wordsSize; i++) {
        result[i] = calculateScore(root, words[i]);
    }
    
    return result;
}