class Solution {
public:
    int help(vector<int> smap, const string& target, int i){
        for(int j=0;j<i;j++){
            if(smap[target[j]-'a']){
                smap[target[j]-'a']--;
            }else{
                return -1;
            }
        }
        int j = (target[i]-'a')+1;
        for(int x = j; x < 26; x++){
            if(smap[x]){
                return x;
            }
        }
        return -1;
    }

    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> smap(26, 0);
        // vector<int> tmap(26, 0);

        for(char c : s){
            smap[c-'a']++;
        }

        string ans = "";

        for(int i=n-1;i>=0;i--){
            int ind = help(smap, target, i);
            if(ind!=-1){
                ans += target.substr(0, i);
                ans += ('a'+ind);
                for(char c : ans){
                    smap[c-'a']--;
                }
                string temp = "";
                for(int a=0;a<26;a++){
                    temp += string(smap[a], a+'a');
                }
                ans += temp;
                break;
            }
        }
        return ans;
    }
};