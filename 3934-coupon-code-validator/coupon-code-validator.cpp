class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        multiset<pair<string, string>> store;
        int n = code.size();
        set<string> st = {"electronics", "grocery", "pharmacy", "restaurant"};
        for (int i = 0; i < n; i++) {
            if (code[i] != "" && st.count(businessLine[i]) && isActive[i]) {
                int flag = 1;
                int x = code[i].size();
                for (int j = 0; j < x; j++) {
                    if (!((code[i][j] >= 48 && code[i][j] <= 57) ||
                          (code[i][j] >= 65 && code[i][j] <= 90) ||
                          (code[i][j] >= 97 && code[i][j] <= 122) ||
                          code[i][j] == 95)) {

                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    store.insert({businessLine[i], code[i]});
                }
            }
        }
        vector<string> ans;
        for (const auto& p : store) {
            ans.push_back(p.second);
        }
        return ans;
    }
};