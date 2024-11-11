#define MAX 1001

bool prime[MAX];

void sieve() {
    for (int i = 0; i < MAX; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                prime[j] = false;
            }
        }
    }
}

int search(int x, int y) {
    for (int i = x + 1; i < y; i++) {
        if (prime[i]) {
            return i;
        }
    }
    return -1;
}

bool primeSubOperation(int* nums, int numsSize) {
    sieve();
    
    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i] <= nums[i - 1]) {
            int x = search(nums[i - 1] - nums[i], nums[i - 1]);
            if (x == -1) {
                return false;
            }
            nums[i - 1] -= x;
        }
    }
    return true;
}