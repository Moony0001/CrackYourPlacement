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
            int i = 0;
            while(i<n){
                if(mid>=bloomDay[i]){
                    int temp = 0;
                    while(i<n && mid>=bloomDay[i]){
                        temp++;
                        i++;
                    }
                    cnt+=(temp/k);
                }
                i++;
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