class Solution {
public:
    int findComplement(int num) {
        for(int i=0;i<31 && num>=(1<<i);i++){
            if(num&(1<<i))num &= (~(1<<i));
            else num |= (1<<i);
        }
        return num;
    }
};