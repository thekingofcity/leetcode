class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        int l = s.length();
        for (int i = 0; i < l; i++) {
            char c = s.charAt(i);
            if (c == ')' || c == ']' || c == '}') {
                char topElement = stack.empty() ? '#' : stack.pop();
                char startParentheses;
                switch (c){
                    case ')':
                        startParentheses = '(';
                        break;
                    case ']':
                        startParentheses = '[';
                        break;
                    case '}':
                        startParentheses = '{';
                        break;
                    default:
                        startParentheses = '\0';
                }
                if (topElement != startParentheses) {
                    return false;
                }
            }
            else {
                stack.push(c);
            }
        }
        return stack.isEmpty();
    }
}