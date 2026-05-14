class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        // unordered_map<int, int> mp;
        // for(int i=0;i<n;i++){
        //     mp[nums[i]]++;
        // }
        // bool flag = true;
        // for(int i=1;i<=n;i++){
        //     if(i!=n-1){
        //         if(i==n && mp[i]){
        //             flag = false;
        //             break;
        //         }else if(i!=n){
        //             if(mp[i]!=1){
        //                 flag = false;
        //                 break;
        //             }
        //         }
        //     }else{
        //         if(mp[i]!=2){
        //             flag = false;
        //             break;
        //         }
        //     }
        // }
        // return flag;
        sort(nums.begin(), nums.end());
        
        for(int i=1;i<=n-1;i++){
            if(nums[i-1]!=i){
                return false;
            }
        }
        if(nums[n-1]!=n-1){
            return false;
        }
        return true;
    }
};