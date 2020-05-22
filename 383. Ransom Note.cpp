class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(128, 0);
        for (char c : magazine) ++m[c];
        for (char c : ransomNote) if (--m[c] < 0) return false;
        return true;
    }
};