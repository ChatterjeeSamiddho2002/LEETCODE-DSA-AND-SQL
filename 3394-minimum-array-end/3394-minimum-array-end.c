long long minEnd(int n, int x) {
     long long sol=x;
     n--;
    long long cbit=1;
    while(n){
        while(sol&cbit) cbit<<=1;
        sol|=((n&1)?cbit:0);
        n>>=1;
        cbit<<=1;
    }
    return sol;
}