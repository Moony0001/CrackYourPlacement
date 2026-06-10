class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<int> cnt(128, 0);
        
        // Step 1: Count frequencies
        for(char c : s) {
            cnt[c]++;
        }
        
        // Step 2: Create buckets. Index = Frequency.
        // We use a vector of strings because multiple characters might have the same frequency.
        vector<string> buckets(n + 1, "");
        for(int i = 0; i < 128; i++) {
            if(cnt[i] > 0) {
                // Append the character 'cnt[i]' times to the bucket string
                buckets[cnt[i]].append(cnt[i], i);
            }
        }
        
        // Step 3: Read buckets backward
        string ans = "";
        for(int i = n; i >= 1; i--) {
            if(!buckets[i].empty()) {
                ans += buckets[i];
            }
        }
        
        return ans;
    }
};