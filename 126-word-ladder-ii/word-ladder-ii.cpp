class Solution {
public:
    int mini;
    void dfs(vector<vector<string>>& ans, string curr, string& end, vector<string>& path, unordered_map<string,vector<string>>& adj){
        
        path.push_back(curr);
        
        if(curr == end){
            vector<string> temp (path.rbegin(), path.rend());
            ans.push_back(temp);
            path.pop_back();
            return;
        }

        for(int i=0;i<adj[curr].size();i++){
            string s = adj[curr][i];
            dfs(ans, s, end, path, adj);
        }
        path.pop_back();

    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> st (wordList.begin(), wordList.end());

        if(!st.count(endWord)){
            return ans;
        }

        unordered_map<string,vector<string>> adj;

        queue<string> q;
        q.push(beginWord);

        while(!q.empty()){
            int s = q.size();
            unordered_set<string> visitedlevel;
            for(int i=0;i<s;i++){
                string front = q.front();
                q.pop();
                string temp = front;
                for(int j=0;j<front.size();j++){
                    char og = front[j];
                    for(char c='a';c<='z';c++){
                        front[j] = c;
                        if(st.count(front)){
                            adj[front].push_back(temp);
                            if(!visitedlevel.count(front)){
                                visitedlevel.insert(front);
                                q.push(front);
                            }
                        }
                    }
                    front[j] = og;
                }
            }
            for(string t : visitedlevel){
                st.erase(t);
            }
        }

        vector<string> path;

        dfs(ans, endWord, beginWord, path, adj);

        return ans;
    }
};