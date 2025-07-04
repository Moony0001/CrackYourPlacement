class Solution {
public:

    int highestpowerof2(long long k){
        int count = 0;
        while(k){
            k = k>>1;
            count++;
        }
        return count;
    }

    char kthCharacter(long long k, vector<int>& operations) {
        int q = highestpowerof2(k);
        int n = operations.size();
        int lim = min(q,n);
        char c = 'a';
        long long allow = k;
        int temp = lim;
        for(int i=lim-1;i>=0;i--){
            long long p = pow(2, temp-1);
            if(p<allow){
                if(operations[i]==1){
                    if(c=='z'){
                        c = 'a';
                    }else{
                        c++;
                    }
                }
                allow = allow-p;
            }
            temp--;
        }

        return c;

    }
};