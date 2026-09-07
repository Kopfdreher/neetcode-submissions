class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> prefix(h.size(), 0);
        int rtn = 0;
        int suffix = 0;
        
        for (int i = 1; i < h.size(); ++i) {
            prefix[i] = max(h[i - 1], prefix[i - 1]);
        }

        for (int i = h.size() - 2; i > 0; --i) {
            suffix = max(suffix, h[i + 1]);
            //printf("suffix = %i\n", suffix);
            //printf("prefix[i] = %i\n", prefix[i]);
            int trapped = min(prefix[i], suffix) - h[i] ;
            //printf("trapped = %i\n", trapped);
            if (trapped > 0) rtn += trapped;
        }
        return rtn;
    }
};
