class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        /*
        Let x be the smallest number of balls with same value.
        x must be fit in a box with certain number m of balls per box at maxium.
        so x = km + 0 or x = km + (m-1).
        So m must be a factor of x or x+1.
        We can try those factors in a decreasing order greedily.
        */
        sort(balls.begin(), balls.end());
        vector<int> c;
        for (int i = 0; i < balls.size(); ) {
            int j = i;
            while (i < balls.size() && balls[i] == balls[j])  i++;
            c.push_back(i-j);
        }
        sort(c.begin(), c.end());
        int ret = 0;
        for (auto x: c)   ret += (x+1)/2;   
        /* 
            handling the case for base box size = 1. The (x+1)/2 is just a mathematical
            trick to take the ceil of the value when dividing by 2.
        */
        int x = c[0];
        for (int m = x; m >= 2; m--) {
            //[m, m+1] balls per box
            bool ok = true;
            int box = 0;
            for (auto f : c) {
                int a = f/(m+1), b = f%(m+1);
                if (b == 0)
                    box += a;
                else if (b+a >= m)
                    box += a+1;
                else {
                    ok = false;
                    break;
                }
            }
            if (ok)  ret = min(ret, box);
                
            
        }
        return ret;
    }
};