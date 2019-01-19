class Solution {
public:
    string addBinary(string a, string b) {
        string ret="";
        long asize=a.size(),bsize=b.size();
        long lmax=max(asize,bsize),lmin=min(asize,bsize);
        bool A=false,B=false,C=false;
        int i=0,TEMP=0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(i=0;i<lmin;++i){
            A=a[i]-'0';
            B=b[i]-'0';
            TEMP=A+B+C;
            if(TEMP==0){
                ret.push_back('0');
                C=0;
            }else if(TEMP==1){
                ret.push_back('1');
                C=0;
            }else if(TEMP==2){
                ret.push_back('0');
                C=1;
            }else if(TEMP==3){
                ret.push_back('1');
                C=1;
            }
        }
        // cout<<ret<<endl;
        if(asize>bsize){
            for(;i<lmax;++i){
                A=a[i]-'0';
                TEMP=A+C;
                if(TEMP==0){
                    ret.push_back('0');
                    C=0;
                }else if(TEMP==1){
                    ret.push_back('1');
                    C=0;
                }else if(TEMP==2){
                    ret.push_back('0');
                    C=1;
                }
            }
        }else if(asize<bsize){
            for(;i<lmax;++i){
                B=b[i]-'0';
                TEMP=B+C;
                if(TEMP==0){
                    ret.push_back('0');
                    C=0;
                }else if(TEMP==1){
                    ret.push_back('1');
                    C=0;
                }else if(TEMP==2){
                    ret.push_back('0');
                    C=1;
                }
            }
        }
        // cout<<ret<<endl;
        if(C==1){
            ret.push_back('1');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};