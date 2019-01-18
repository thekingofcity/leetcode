class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size()==0) return 0;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        pair<string,int> elem (beginWord, 1), current;
        q.push(elem);
        int i;
        char j;
        string oldWord,newWord;
        while(!q.empty()){
            current=q.front();
            q.pop();
            oldWord=current.first;
            for(i=0;i<oldWord.size();++i){
                newWord=oldWord;
                for(j='a';j<='z';++j){
                    newWord[i]=j;
                    if(dict.count(newWord)){
                        // cout<<newWord<<" "<<current.second+1<<endl;
                        if(newWord==endWord) return current.second+1;
                        if(newWord!=oldWord){
                            elem=make_pair(newWord, current.second+1);
                            q.push(elem);
                            dict.erase(newWord);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
/*
"a"
"c"
["a","b","c"]
*/