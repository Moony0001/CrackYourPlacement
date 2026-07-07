class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0){
            return false;
        }

        map<int, int> mp;
        for(int i : hand){
            mp[i]++;
        }

        int loops = n/groupSize;

        for(int i=0;i<loops;i++){
            int temp = groupSize;
            int last = -1;
            for(auto& m : mp){
                if(last!=-1){
                    if(m.first!=last+1){
                        return false;
                    }
                }
                if(m.second==0){
                    continue;
                }else{
                    temp--;
                    m.second--;
                    last = m.first;
                }
                if(temp==0){
                    break;
                }
            }
            if(temp>0){
                return false;
            }
        }

        return true;
    }
};