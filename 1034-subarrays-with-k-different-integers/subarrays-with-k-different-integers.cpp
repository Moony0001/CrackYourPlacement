class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        int left = 0;
        int distinct = 0;
        int prefix_redundant = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            if (freq[nums[right]] == 0) {
                distinct++;
            }
            freq[nums[right]]++;

            // 1. If we exceed k, shrink until valid and RESET our prefix counter!
            if (distinct > k) {
                freq[nums[left]]--;
                left++;
                distinct--;
                prefix_redundant = 0;
            }

            // 2. Strip all redundant elements from the left of our valid window
            while (freq[nums[left]] > 1) {
                freq[nums[left]]--;
                left++;
                prefix_redundant++;
            }

            // 3. If window has exactly k distinct numbers, add (1 + redundant choices)
            if (distinct == k) {
                ans += (1 + prefix_redundant);
            }
        }

        return ans;
    }
};