class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int d = 0;
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int cnt = 0;
        int i = 0;
        while (i < n || !pq.empty()) {
            if (i == n && pq.empty()) break;
            if (pq.empty()) {
                d = events[i][0];
            } else {
                d++;
            }
            while (!pq.empty() && pq.top().first < d) {
                pq.pop();
            }
            while (i < n && events[i][0] <= d && events[i][1] >= d) {
                pq.push({events[i][1], i});
                i++;
            }
            if (!pq.empty()) {
                pq.pop();
                cnt++;
            }
        }
        
        return cnt;
    }
};