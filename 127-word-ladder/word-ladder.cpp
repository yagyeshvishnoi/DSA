class Solution {
public:
    bool diffByOne(string& a, string& b) {
        int d = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) d++;
            if (d > 1) return false;
        }
        return d == 1;
    }

    int ladderLength(string start, string end, vector<string>& word) {
        unordered_set<string> wordSet(word.begin(), word.end());
        
        if (wordSet.find(end) == wordSet.end()) return 0;
        
        unordered_set<string> beginSet, endSet;
        beginSet.insert(start);
        endSet.insert(end);
        
        int step = 1;
        
        while (!beginSet.empty() && !endSet.empty()) {
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }
            
            unordered_set<string> nextSet;
            
            for (string word : beginSet) {
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        
                        word[i] = c;
                        
                        if (endSet.find(word) != endSet.end()) {
                            return step + 1;
                        }
                        
                        if (wordSet.find(word) != wordSet.end()) {
                            nextSet.insert(word);
                            wordSet.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            
            beginSet = nextSet;
            step++;
        }
        
        return 0;
    }
};