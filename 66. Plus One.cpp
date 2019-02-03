class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        int digit=0;
        bool carry=0;
        digit=++digits[i];
        if(digit==10){
            carry=1;
            digits[i]=0;
        }
        for(--i;i>=0;--i){
            digit=digits[i];
            if(carry){
                if(++digit==10){
                    carry=1;
                    digits[i]=0;
                }else{
                    digits[i]=digit;
                    return digits;
                }
            }
        }
        if(carry){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
/*
[1,2,3]
[0]
[1,2,9]
[1,9,3]
[1,0,9,4]
[9,9,9]
*/