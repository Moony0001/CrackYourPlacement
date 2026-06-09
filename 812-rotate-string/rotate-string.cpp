class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string news = s+s;
        size_t pos = news.find(goal);
        if(pos!=string::npos){
            return true;
        }
        return false;
    }
};