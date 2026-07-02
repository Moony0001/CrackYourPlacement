class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> inc;
        stack<int> dec;
        int n = nums.size();
        long long minsum = 0;
        long long maxsum = 0;
        for(int i=0;i<=n;i++){
            while(!inc.empty() && (i==n || nums[inc.top()]>nums[i])){
                int right = i;
                int curr = inc.top();
                inc.pop();
                int left = inc.empty() ? -1 : inc.top();
                int leftc = curr-left;
                int rightc = right-curr;
                long long cnt = leftc*rightc;
                long long cont = nums[curr]*cnt;
                minsum += cont;
            }
            inc.push(i);
            while(!dec.empty() && (i==n || nums[dec.top()]<nums[i])){
                int right = i;
                int curr = dec.top();
                dec.pop();
                int left = dec.empty() ? -1 : dec.top();
                int leftc = curr-left;
                int rightc = right-curr;
                long long cnt = leftc*rightc;
                long long cont = nums[curr]*cnt;
                maxsum+= cont;
            }
            dec.push(i);
        }

        long long ans = maxsum-minsum;
        return ans;
    }
};