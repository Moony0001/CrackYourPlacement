class Solution {
public:
    int firstbuilder(int n){
        int temp = 0;
        int dig = 1;
        while(n>0){
            temp = temp*10 + dig;
            n--;
            dig++;
        }
        return temp;
    }

    int adderbuilder(int n){
        int temp = 0;
        int dig = 1;
        while(n>0){
            temp = temp*10 + dig;
            n--;
        }
        return temp;
    }

    vector<int> sequentialDigits(int low, int high) {
        int fl = 0;
        int tlow = low;
        while(tlow>0){
            tlow /= 10;
            fl++;
        }
        int cl = 0;
        int thigh = high;
        while(thigh>0){
            thigh /= 10;
            cl++;
        }
        int s = fl;
        
        vector<int> ans;
        while(s<=cl){
            int num = firstbuilder(s);
            int add = adderbuilder(s);
            while(num<=high && num%10!=9){
                if(num>=low){
                    ans.push_back(num);
                }
                num += add;
            }
            if(num>high) break;
            if(num>=low){
                ans.push_back(num); 
            }
            s++;
        }
        return ans;
    }
};