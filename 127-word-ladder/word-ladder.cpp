class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if(!st.count(endWord)){
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        int ans = 1;
        while(!q.empty()){
            int s = q.size();
            for(int j=0;j<s;j++){
                string word = q.front();
                q.pop();
                if(word == endWord) return ans;

                for(int i=0;i<word.size();i++){
                    char og = word[i];
                    for(char c = 'a'; c<='z'; c++){
                        word[i] = c;
                        if(st.count(word)){
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i] = og;
                }
            }
            ans++;
        }
        return 0;
    }
};