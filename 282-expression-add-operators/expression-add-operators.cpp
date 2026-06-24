class Solution {
private:
    vector<string> ans;
    string s;
    long long target_val;

    void backtrack(int i, const string& path, long long sum, long long tail) {
        // BASE CASE: We consumed the entire string
        if (i == s.length()) {
            if (sum == target_val) ans.push_back(path);
            return;
        }

        long long current_val = 0;
        string val_str = "";

        // Stretch the right bound of the current number we are trying to pluck out
        for (int j = i; j < s.length(); j++) {
            
            // RULE 2: Kill leading zeros (e.g. "0" is fine, "05" is dead)
            if (j > i && s[i] == '0') break;

            val_str += s[j];
            current_val = current_val * 10 + (s[j] - '0'); // Build number safely

            // RULE 4: The Big Bang (First number in the sequence gets no operator)
            if (i == 0) {
                backtrack(j + 1, val_str, current_val, current_val);
            } 
            else {
                // --- BRANCH 1: ADDITION ---
                backtrack(j + 1, path + "+" + val_str, sum + current_val, current_val);
                
                // --- BRANCH 2: SUBTRACTION ---
                // If we subtract 5, the "tail" left behind in history is -5!
                backtrack(j + 1, path + "-" + val_str, sum - current_val, -current_val);
                
                // --- BRANCH 3: MULTIPLICATION (The Time Machine) ---
                backtrack(j + 1, path + "*" + val_str, 
                          sum - tail + (tail * current_val), 
                          tail * current_val);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        this->s = num;
        this->target_val = target;
        backtrack(0, "", 0, 0);
        return ans;
    }
};