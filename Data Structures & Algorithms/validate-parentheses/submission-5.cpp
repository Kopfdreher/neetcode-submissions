class Solution {
   public:
    bool isValid(string s) {
        stack<char> brckts;

        for (char c : s) {
            if (c == '(') brckts.push(')');
            else if (c == '{') brckts.push('}');
            else if (c == '[') brckts.push(']');
            else if (c == ')' || c == '}' || c == ']') {
                // cout << "c = " << c << "\ntop() " << brckts.top() << endl;
                if (brckts.empty() || c != brckts.top()) return false;
                brckts.pop();
            }
        }
        if (brckts.empty()) return true;
        return false;
    }
};
