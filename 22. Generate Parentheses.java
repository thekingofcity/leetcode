class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList();
        boringStuff(ans, "", 0, 0, n);
        return ans;
    }

    public void boringStuff(List<String> ans, String cur, int open, int close, int n){
        if (cur.length() == n * 2) {
            ans.add(cur);
            return;
        }

        if (open < n)
            boringStuff(ans, cur+"(", open+1, close, n);
        if (close < open)
            boringStuff(ans, cur+")", open, close+1, n);
    }
}