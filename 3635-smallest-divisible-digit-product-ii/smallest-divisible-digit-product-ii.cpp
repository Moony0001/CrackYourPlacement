class Solution {
public:
    bool prime(long long n, int& req2, int& req3, int& req5, int& req7) {
        while (n % 2 == 0) {
            n = n >> 1;
            req2++;
        }
        while (n % 3 == 0) {
            n = n / 3;
            req3++;
        }
        while (n % 5 == 0) {
            n = n / 5;
            req5++;
        }
        while (n % 7 == 0) {
            n = n / 7;
            req7++;
        }

        return n==1;
    }

    void getfactors(int digit, int& c2, int& c3, int& c5, int& c7) {
        if (digit == 2)
            c2++;
        else if (digit == 3)
            c3++;
        else if (digit == 4)
            c2 += 2;
        else if (digit == 5)
            c5++;
        else if (digit == 6) {
            c2++;
            c3++;
        } else if (digit == 7)
            c7++;
        else if (digit == 8)
            c2 += 3;
        else if (digit == 9)
            c3 += 2;
    }

    bool capcheck(int rem, int req2, int req3, int req5, int req7) {
        int needed = req5 + req7;

        needed += req2 / 3;
        req2 %= 3;
        needed += req3 / 2;
        req3 %= 2;

        if (req3 == 1 && req2 == 2) {
            needed += 2;
        } else if (req3 > 0 || req2 > 0) {
            needed += 1;
        }

        // I want the remaining slots to be greater than the needed slots
        return needed <= rem;
    }

    string suffixbuilder(int remslots, int rem2, int rem3, int rem5, int rem7) {
        string suffix = "";
        suffix += string(rem5, '5');
        suffix += string(rem7, '7');
        suffix += string(rem2 / 3, '8');
        rem2 %= 3;
        suffix += string(rem3 / 2, '9');
        rem3 %= 2;
        if (rem2 == 2 && rem3 == 1) {
            suffix += "26";
        } else if (rem2 == 1 && rem3 == 1) {
            suffix += "6";
        } else if (rem2 == 2) {
            suffix += "4";
        } else if (rem2 == 1) {
            suffix += "2";
        } else if (rem3 == 1) {
            suffix += "3";
        }

        int r = max(0,remslots - (int)suffix.size());
        suffix += string(r, '1');
        sort(suffix.begin(), suffix.end());
        return suffix;
    }

    string smallestNumber(string num, long long t) {
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        if (!prime(t, req2, req3, req5, req7)) {
            return "-1";
        }
        int n = num.size();
        int s = req2 + req3 + req5 + req7;
        int i = n - 1;
        bool zero = false;

        for (int j = 0; j < n; j++) {
            if (num[j] == '0') {
                zero = true;
                i = j;
                break;
            }
        }

        if (!zero) {
            int tot2 = 0, tot3 = 0, tot5 = 0, tot7 = 0;
            for (int j = 0; j < n; j++) {
                getfactors(num[j] - '0', tot2, tot3, tot5, tot7);
            }
            if (tot2 >= req2 && tot3 >= req3 && tot5 >= req5 && tot7 >= req7) {
                return num;
            }
        }

        int pre2 = 0, pre3 = 0, pre5 = 0, pre7 = 0;
        for (int j = 0; j < i; j++) {
            getfactors(num[j] - '0', pre2, pre3, pre5, pre7);
        }
        while (i >= 0) {
            for (char d = num[i] + 1; d <= '9'; d++) {
                int d2 = 0, d3 = 0, d5 = 0, d7 = 0;
                getfactors(d - '0', d2, d3, d5, d7);
                int rem2 = max(req2 - pre2 - d2, 0);
                int rem3 = max(req3 - pre3 - d3, 0);
                int rem5 = max(req5 - pre5 - d5, 0);
                int rem7 = max(req7 - pre7 - d7, 0);

                int remslots = n - i - 1;

                if (capcheck(remslots, rem2, rem3, rem5, rem7)) {
                    string suffix =
                        suffixbuilder(remslots, rem2, rem3, rem5, rem7);
                    return num.substr(0, i) + d + suffix;
                }
            }

            // We are removing the count of the digit that we are going to
            // remove from the remaining count.
            if (i > 0) {
                int rem_c2 = 0, rem_c3 = 0, rem_c5 = 0, rem_c7 = 0;
                getfactors(num[i - 1] - '0', rem_c2, rem_c3, rem_c5, rem_c7);
                pre2 -= rem_c2;
                pre3 -= rem_c3;
                pre5 -= rem_c5;
                pre7 -= rem_c7;
            }

            i--;
        }
        return suffixbuilder(n+1, req2, req3, req5, req7);
    }
};