class Solution {
public:
    void generatestr(int n, string currst, vector<string>& result){
        if(currst.size()==n){
            result.push_back(currst);
            return;
        }
        for(char ch: {'a', 'b', 'c'}){
            if(currst.empty() || currst.back()!=ch){
                generatestr(n, currst+ch,result);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> res;
        generatestr(n, "", res);
        if(res.size()<k){
            return "";
        }
        return res[k-1];
    }
};