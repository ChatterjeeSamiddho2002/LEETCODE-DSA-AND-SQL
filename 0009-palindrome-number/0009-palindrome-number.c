bool isPalindrome(int x) {
    if (x<0){
    return false;
}
int rev=0;
int rem=0;
int y=x;
while(x!=0){
    rem=x%10;
    if(rev>(INT_MAX-rem)/10){
        return false;
    }
    rev=rev*10+rem;
    x/=10;
}
return y==rev;
}
