class Solution {
public:
    bool canForm(const string& s, const string& w) {
        if(s.size() != w.size() - 1) return false;
        
        int i = 0, j = 0;
        bool skipped = false;
        
        while(i < s.size() && j < w.size()) {
            if(s[i] == w[j]) {
                i++;
                j++;
            } else {
                if(skipped) return false;
                skipped = true;
                j++;
            }
        }
        
        return skipped || (j == w.size() - 1);
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n <= 1) return n;
        
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        
        unordered_map<int, vector<int>> lengthGroups;
        for(int i = 0; i < n; i++) {
            lengthGroups[words[i].size()].push_back(i);
        }
        
        vector<vector<int>> dp(n, vector<int>(n, 1));
        int maxLen = 1;
        
        for(int i = n - 1; i >= 0; i--) {
            int targetLen = words[i].size() + 1;
            if(lengthGroups.find(targetLen) != lengthGroups.end()) {
                for(int idx : lengthGroups[targetLen]) {
                    if(idx > i && canForm(words[i], words[idx])) {
                        dp[i][i] = max(dp[i][i], 1 + dp[idx][idx]);
                    }
                }
            }
            maxLen = max(maxLen, dp[i][i]);
        }
        
        return maxLen;
    }
};