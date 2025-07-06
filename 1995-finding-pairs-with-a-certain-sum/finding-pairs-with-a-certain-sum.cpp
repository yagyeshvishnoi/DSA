class FindSumPairs {
vector<int> one;
vector<int> two; 
unordered_map<int,int> mp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        one = nums1;
        two = nums2;

        for(int  i=0; i<nums2.size();i++){
            mp[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        mp[two[index]]--;
        two[index] += val;
        mp[two[index]]++;
    }
   
    int count(int tot) {
        int count=0;
        for(int i=0; i<one.size(); i++){
            count+=(mp[tot - one[i]]);
        }
        return count;
    }
};