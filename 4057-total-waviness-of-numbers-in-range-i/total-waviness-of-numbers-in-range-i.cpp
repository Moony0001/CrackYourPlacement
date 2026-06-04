class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=num1;i<=num2;i++){
            if(i<100) continue;
            int temp = i;
            vector<int> dig;
            while(temp>0){
                dig.push_back(temp%10);
                temp/=10;
            }
            for(int j=1;j<dig.size()-1;j++){
                if((dig[j-1]>dig[j] && dig[j]<dig[j+1]) || (dig[j-1]<dig[j] && dig[j+1]<dig[j])){
                    ans++;
                }
            }
        }

        return ans;
    }
};