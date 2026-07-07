class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt (26,0);
        for(char c : tasks){
            cnt[c-'A']++;
        }

        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(cnt[i]>0){
                pq.push(cnt[i]);
            }
        }
        int ans = 0;
        while(!pq.empty()){
            int count = 0;
            vector<int> wait;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    int temp = pq.top();
                    pq.pop();
                    count++;
                    temp--;
                    if(temp>0){
                        wait.push_back(temp);
                    }
                }
            }
            for(int i=0;i<wait.size();i++){
                pq.push(wait[i]);
            }
            if(pq.empty()){
                ans+=count;
            }else{
                ans+=(n+1);
            }
            
        }
        
        return ans;
    }
};