class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k!=0) return false;

        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& m : mp){
            pq.push(m.first);
        }

        while(!pq.empty()){
            int start = pq.top();
            if(mp[start]>0){
                for(int i=start;i<start+k;i++){
                    if(mp[i]>0){
                        mp[i]--;
                    }else{
                        return false;
                    }
                }
            }else{
                pq.pop();
            }
        }
        return true;
    }
};