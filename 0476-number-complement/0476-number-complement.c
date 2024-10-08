int findComplement(int num) {
    if(num==0){
        return 1;
    }
    unsigned int x=num;
    x|=x>>1;
    x|=x>>2;
    x|=x>>4;
    x|=x>>8;
    x|=x>>16;
    return num^x;
}