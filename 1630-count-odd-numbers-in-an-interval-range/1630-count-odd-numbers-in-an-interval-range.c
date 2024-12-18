

int countOdds(int low, int high){
    int count =0;
    if(low<0||high<0){
        return -1;
    }
    for(int i=low;i<=high;i++){
        if(i%2!=0){
            count+=1;
        }
        else{
            count+=0;
        }
    }
    return count;
}