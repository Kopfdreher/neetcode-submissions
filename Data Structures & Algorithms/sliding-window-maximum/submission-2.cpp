class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        vector<int> rtn = {};
        deque<int> win = {};

        win.push_back(0);
        for (int i = 1; i < k; i++) {
            while (!win.empty() && v[i] > v[win.back()]) {
                win.pop_back();
            }
            win.push_back(i);
        }
        rtn.push_back(v[win.front()]);

        for (int i = k; i < v.size(); i++) {
            while (!win.empty() && v[i] > v[win.back()]) {
                win.pop_back();
            }
            win.push_back(i);
            while (win.front() < i - k + 1) {
                win.pop_front();
            }
            rtn.push_back(v[win.front()]);
        }
        return rtn;
    }
};
