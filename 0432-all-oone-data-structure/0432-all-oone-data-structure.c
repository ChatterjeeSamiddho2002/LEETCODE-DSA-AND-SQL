typedef struct KeyNode {
    char* key;
    struct KeyNode* next;
} KeyNode;

typedef struct CountNode {
    int count;
    KeyNode* keys; // List of keys with this count
    struct CountNode* prev;
    struct CountNode* next;
} CountNode;

typedef struct {
    CountNode* head;
    CountNode* tail;
} AllOne;

CountNode* createCountNode(int count) {
    CountNode* node = (CountNode*)malloc(sizeof(CountNode));
    node->count = count;
    node->keys = NULL;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

KeyNode* createKeyNode(char* key) {
    KeyNode* kn = (KeyNode*)malloc(sizeof(KeyNode));
    kn->key = strdup(key);
    kn->next = NULL;
    return kn;
}

AllOne* allOneCreate() {
    AllOne* obj = (AllOne*)malloc(sizeof(AllOne));
    obj->head = createCountNode(0); // dummy head
    obj->tail = createCountNode(0); // dummy tail
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    return obj;
}

void removeKey(AllOne* obj, CountNode* countNode, char* key) {
    KeyNode* current = countNode->keys;
    KeyNode* prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                countNode->keys = current->next; // Remove head of keys
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void addKey(AllOne* obj, CountNode* countNode, char* key) {
    KeyNode* newKeyNode = createKeyNode(key);
    newKeyNode->next = countNode->keys;
    countNode->keys = newKeyNode;
}

CountNode* findOrCreateCountNode(AllOne* obj, int count) {
    CountNode* curr = obj->head->next;
    while (curr != obj->tail) {
        if (curr->count == count) {
            return curr;
        } else if (curr->count > count) {
            CountNode* newNode = createCountNode(count);
            newNode->next = curr;
            newNode->prev = curr->prev;
            curr->prev->next = newNode;
            curr->prev = newNode;
            return newNode;
        }
        curr = curr->next;
    }
    CountNode* newNode = createCountNode(count);
    newNode->prev = obj->tail->prev;
    newNode->next = obj->tail;
    obj->tail->prev->next = newNode;
    obj->tail->prev = newNode;
    return newNode;
}

void allOneInc(AllOne* obj, char* key) {
    CountNode* currCountNode = obj->head->next; // Start from first real node
    int found = 0;

    // Find existing count
    while (currCountNode != obj->tail) {
        KeyNode* keyNode = currCountNode->keys;
        while (keyNode) {
            if (strcmp(keyNode->key, key) == 0) {
                found = 1; // Key exists
                break;
            }
            keyNode = keyNode->next;
        }
        if (found) break;
        currCountNode = currCountNode->next;
    }

    if (found) {
        // Key exists, increment its count
        removeKey(obj, currCountNode, key);
        int newCount = currCountNode->count + 1;
        CountNode* nextCountNode = findOrCreateCountNode(obj, newCount);
        addKey(obj, nextCountNode, key);
        // If current count node is now empty, remove it
        if (currCountNode->keys == NULL) {
            currCountNode->prev->next = currCountNode->next;
            currCountNode->next->prev = currCountNode->prev;
            free(currCountNode);
        }
    } else {
        // New key, count starts at 1
        CountNode* newCountNode = findOrCreateCountNode(obj, 1);
        addKey(obj, newCountNode, key);
    }
}

void allOneDec(AllOne* obj, char* key) {
    CountNode* currCountNode = obj->head->next; // Start from first real node

    while (currCountNode != obj->tail) {
        // Check if key exists in the current count node
        KeyNode* keyNode = currCountNode->keys;
        while (keyNode) {
            if (strcmp(keyNode->key, key) == 0) {
                removeKey(obj, currCountNode, key);
                int oldCount = currCountNode->count;
                
                // If this was the last key in this count node
                if (currCountNode->keys == NULL) {
                    // Remove the count node
                    CountNode* toRemove = currCountNode;
                    currCountNode = currCountNode->next; // Move to next before removing
                    toRemove->prev->next = toRemove->next;
                    toRemove->next->prev = toRemove->prev;
                    free(toRemove);
                }
                
                // Decrement the count
                if (oldCount > 1) {
                    CountNode* newCountNode = findOrCreateCountNode(obj, oldCount - 1);
                    addKey(obj, newCountNode, key);
                }
                return;
            }
            keyNode = keyNode->next;
        }
        currCountNode = currCountNode->next;
    }
}
char* allOneGetMaxKey(AllOne* obj) {
    if (obj->head->next == obj->tail) {
        return ""; // No keys
    }
    CountNode* maxNode = obj->tail->prev;
    return maxNode->keys->key; // Return one key from the max count
}

char* allOneGetMinKey(AllOne* obj) {
    if (obj->head->next == obj->tail) {
        return ""; // No keys
    }
    CountNode* minNode = obj->head->next;
    return minNode->keys->key; // Return one key from the min count
}

void allOneFree(AllOne* obj) {
    CountNode* curr = obj->head;
    while (curr) {
        CountNode* temp = curr;
        curr = curr->next;

        // Free all key nodes in this count node
        KeyNode* keyCurr = temp->keys;
        while (keyCurr) {
            KeyNode* keyTemp = keyCurr;
            keyCurr = keyCurr->next;
            free(keyTemp->key);
            free(keyTemp);
        }

        free(temp);
    }
    free(obj);
}



/**
 * Your AllOne struct will be instantiated and called as such:
 * AllOne* obj = allOneCreate();
 * allOneInc(obj, key);
 
 * allOneDec(obj, key);
 
 * char* param_3 = allOneGetMaxKey(obj);
 
 * char* param_4 = allOneGetMinKey(obj);
 
 * allOneFree(obj);
*/