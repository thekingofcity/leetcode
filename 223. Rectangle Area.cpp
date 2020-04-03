class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long one=(C-A)*(D-B);
        long two=(G-E)*(H-F);
        long ret=one+two;
        
        int left=max(A,E);
        int right=min(C,G);
        int top=min(D,H);
        int bottom=max(B,F);
        
        if(left<right&&bottom<top){
            long overlap=(right-left)*(top-bottom);
            ret-=overlap;
        }
        
        return (int)ret;
    }
};