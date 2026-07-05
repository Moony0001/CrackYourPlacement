class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(m<n) return "";
        vector<int> nums(128, 0);

        for(char c : t){
            nums[c]++;
        }
        int req = t.size();
        int i=0;
        int ans = INT_MAX;
        int ind = 0;
        for(int j=0;j<m;j++){
            if(nums[s[j]]>0){
                req--;
            }
            nums[s[j]]--;


            while(req==0){
                if(j-i+1<ans){
                    ans = j-i+1;
                    ind = i;
                }
                nums[s[i]]++;
                if(nums[s[i]]>0){
                    req++;
                }
                i++;
            }

        }
        return (ans == INT_MAX) ? "" : s.substr(ind, ans);
    }
};