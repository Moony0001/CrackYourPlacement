class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 1;
        int right = 0;
        int n = bloomDay.size();
        if((n/k)<m) return -1;
        for(int b : bloomDay){
            right = max(right, b);
        }

        while(left<right){
            int mid = left+(right-left)/2;

            int cnt = 0;
            int temp = 0;
            for(int i=0;i<n;i++){
                if(mid>=bloomDay[i]){
                    temp++;

                    if(temp==k){
                        cnt++;
                        temp=0;
                    }
                }else{
                    temp=0;
                }
            }

            if(cnt>=m){
                right = mid;
            }else{
                left = mid+1;
            }
        }

        return left;
    }
};