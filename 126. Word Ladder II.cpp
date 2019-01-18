class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // if(wordList.size()==0) return 0;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ret;
        if(!dict.count(endWord)) return ret;
        vector<pair<string,int>> q;
        pair<string,int> elem (beginWord, 0), current;
        q.push_back(elem);
        int front=0;
        string oldWord,newWord;
        while(front<q.size()){
            current=q[front];
            oldWord=current.first;
            for(int i=0;i<oldWord.size();++i){
                newWord=oldWord;
                for(char j='a';j<='z';++j){
                    newWord[i]=j;
                    if(dict.count(newWord)){
                        // cout<<newWord<<" "<<current.second<<" "<<front<<endl;
                        if(newWord==endWord){
                            vector<string> ret_;
                            ret_.push_back(endWord);
                            int prev=front;
                            // cout<<endl;
                            while(prev!=0){
                                // cout<<prev<<" "<<q[prev].first<<endl;
                                ret_.push_back(q[prev].first);
                                prev=q[prev].second;
                            }
                            ret_.push_back(beginWord);
                            // since back -> first, so we reverse
                            reverse(ret_.begin(), ret_.end());
                            // answer longer than shortest
                            if(ret.size() && ret[0].size()<ret_.size()) return ret;
                            ret.push_back(ret_);
                            return ret;
                        }
                        if(newWord!=oldWord){
                            elem=make_pair(newWord, front);
                            // cout<<newWord<<" "<<front<<endl;
                            q.push_back(elem);
                            // if(!shortestSize) dict.erase(newWord);
                        }
                    }
                }
            }
            ++front;
        }
        return ret;
    }
};