class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int i : bills) {
            if (i == 5) {
                five++;
            } else if (i == 10) {
                if (five == 0) {
                    return false;
                } else {
                    five--;
                }
                ten++;
            } else {
                if ((ten == 0 && five < 3) || (ten > 0 && five == 0)) {
                    return false;
                } else {
                    if (ten > 0 && five > 0) {
                        ten--;
                        five--;
                    } else {
                        five -= 3;
                    }
                }
                twenty++;
            }
        }
        return true;
    }
};