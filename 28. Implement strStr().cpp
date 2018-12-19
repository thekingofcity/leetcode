// Yeah I know this brute force is ugly and slow
// but KMP is quite difficult
// https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1=haystack.length(),l2=needle.length();
        if(l2==0) return 0;
        int i,j,k;
        for(i=0;i<l1;i++){
            k=i;
            for(j=0;j<l2;j++,k++){
                if(haystack[k]==needle[j]){
                }else{
                    break;
                }
            }
            if(j==l2) return i;
        }
        return -1;
    }
};