class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        vector<int> freq(51,0);
        int l = 0;
        int r = 0;
        for(int r=0;r<n;r++){
            freq[nums[r]]++;
            if(r-l+1>k){
                freq[nums[l]]--;
                l++;
            }

            if(r-l+1==k){
                priority_queue<pair<int,int>> pq1;
                for(int i=0;i<51;i++){
                    if(freq[i]>0){
                        pq1.push({freq[i], i});
                    }
                }
                int cnt = 0;
                int temp = 0;
                while(!pq1.empty() && cnt<x){
                    auto p = pq1.top();
                    pq1.pop();
                    temp+= p.first*p.second;
                    cnt++;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};