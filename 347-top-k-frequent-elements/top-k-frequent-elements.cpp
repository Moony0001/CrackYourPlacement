class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        // 1. Count frequencies in O(N) time
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        
        // 2. Create buckets where index = frequency
        // Size is n + 1 because frequency can range from 0 up to n
        vector<vector<int>> buckets(n + 1);
        for (auto& [num, freq] : mp) {
            buckets[freq].push_back(num);
        }
        
        // 3. Gather the top k elements by scanning buckets from right to left
        vector<int> ans;
        ans.reserve(k);
        
        for (int freq = n; freq >= 1; freq--) {
            for (int num : buckets[freq]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans; // Found our top K elements in strictly O(N) time!
                }
            }
        }
        
        return ans;
    }
};