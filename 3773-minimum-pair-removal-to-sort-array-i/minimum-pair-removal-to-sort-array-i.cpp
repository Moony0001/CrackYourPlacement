class Node{
    public:
        int val;
        Node* prev;
        Node* next;
};
class Solution {
public:
    bool checkinc(vector<int>& nums){
        bool flag = false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                flag = true;
                break;
            }
        }
        return flag;
    }

    void findminandremove(vector<int>& nums){
        int ind = 0;
        int mini = INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+nums[i+1]<mini){
                mini = nums[i]+nums[i+1];
                ind = i;
            }
        }
        nums[ind] = mini;
        nums.erase(nums.begin()+ind+1);
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(checkinc(nums)){
            findminandremove(nums);
            ans++;
        }
        return ans;
    }
};