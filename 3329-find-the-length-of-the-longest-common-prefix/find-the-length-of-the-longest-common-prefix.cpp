class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st1;
        int n = arr1.size();
        int m = arr2.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            string temp = to_string(arr1[i]);
            for(int j=0;j<temp.size();j++){
                st1.insert(temp.substr(0,j+1));
            }
        }
        for(int i=0;i<m;i++){
            string temp = to_string(arr2[i]);
            for(int j=0;j<temp.size();j++){
                if(st1.count(temp.substr(0,j+1))){
                    ans = max(ans, j+1);
                }
            }
        }
        return ans;
    }
};