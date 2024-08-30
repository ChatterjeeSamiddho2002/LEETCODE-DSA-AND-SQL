int reverse(int x){
    int rem=0;
    int rev=0;
    int y=x;
    while(x!=0){
        rem=x%10;
                // Check for overflow before multiplying rev by 10
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && rem > 7)) {
            return 0;  // Overflow
        }
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && rem < -8)) {
            return 0;  // Underflow
        }
        rev=rev*10+rem;
        x/=10;
    }
    return rev;

}