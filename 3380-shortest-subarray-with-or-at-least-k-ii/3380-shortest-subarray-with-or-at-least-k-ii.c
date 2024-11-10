void addBit(int* bitMask, int n){
    for(int i = 0; i < 32 && n; i++){
        if(n & 1)
            bitMask[i]++;
        n >>= 1;
    }
}

int delBit(int* bitMask, int n){
    int curr = 0;
    for(int i = 0; i < 32; i++){
        if(n & 1)
            bitMask[i]--;
        n >>= 1;
        if(bitMask[i])
            curr |= (1 << i);
    }
    return curr;
}
int minimumSubarrayLength(int* nums, int numsSize, int k) {
    int left = 0, right = 0, sum = 0;
    int minLen = INT_MAX;
    int* bitMask = (int*)calloc(32, sizeof(int));
    while(right < numsSize){
        sum |= nums[right];
        addBit(bitMask, nums[right]);
        while(left <= right && sum >= k){
            minLen = fmin(minLen, right - left + 1);
            sum = delBit(bitMask, nums[left++]);
        }
        right++;
    }
    return minLen == INT_MAX? -1 : minLen;
}