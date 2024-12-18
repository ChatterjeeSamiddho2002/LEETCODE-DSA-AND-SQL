bool lemonadeChange(int* bills, int billsSize) {
    int five = 0, ten = 0;
        for(int i = 0; i < billsSize; i++) {
            int bill = bills[i];
            if( bill == 5)
                five++;
            
            else if( bill == 10) {
                if( five >= 1) {
                    five--;
                    ten++;
                }
                else
                    return false;
            }
            else {
                if(five >= 1 && ten >= 1) {
                    ten--;
                    five--;
                }
                else if( five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }
        return true;
}