class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int mini = INT_MAX;
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]<mini){
                mini = arr[i]-arr[i-1];
                ans.clear();
                ans.push_back({arr[i-1],arr[i]});
            }else if(arr[i]-arr[i-1]==mini){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};