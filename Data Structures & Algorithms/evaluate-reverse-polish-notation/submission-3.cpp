class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;

        stack<int> nums;

        for (string &s : tokens) {
            if (s.length() == 1 && (s[0] == '/' || s[0] == '*' || s[0] == '-' || s[0] == '+')) {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();

                if (s[0] == '/')
                    nums.push(b / a);
                else if (s[0] == '*')
                    nums.push(b * a);
                else if (s[0] == '-')
                    nums.push(b - a);
                else if (s[0] == '+')
                    nums.push(b + a);
            } else
                nums.push(stoi(s));
        }
        return nums.top();
    }
};
