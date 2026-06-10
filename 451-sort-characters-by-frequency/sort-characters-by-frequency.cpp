class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnt (62,0);
        for(char c : s){
            if(65<=c && c<=90){
                cnt[c-'A']++;
            }else if(97<=c && c<=122){
                cnt[c-'a'+26]++;
            }else{
                cnt[c-'0'+52]++;
            }
        }

        priority_queue<pair<int,char>> pq;
        for(int i=0;i<62;i++){
            if(cnt[i]!=0){
                if(i<26){
                    pq.push({cnt[i],i+'A'});
                }else if(i<52){
                    pq.push({cnt[i],i+'a'-26});
                }else{
                    pq.push({cnt[i],i+'0'-52});
                }
            }
        }
        string ans;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            for(int i=0;i<p.first;i++){
                ans+=p.second;
            }
        }
        return ans;
    }
};