class Solution {
public:
    int leng(int i){
        int length = 0;
        while(i>0){
            i = i/10;
            length++;
        }
        return length;
    }
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        vector<int> a(10001, 0);
        int b = 0;
        for(int i=1;i<=10000;i++){
            if(2*leng(i)+3 >= limit) return {};
            int tsuf = 3*i + i*leng(i) + a[i-1]+leng(i);
            a[i] = a[i-1]+leng(i);
            int cap = i*limit - tsuf;
            if(cap>=n){
                b = i;
                break;
            }
        }

        vector<string> ans;
        int part = 1;
        int i = 0;
        while(part<=b){
            int rem = limit - (3+leng(b)+leng(part));
            string temp = message.substr(i, rem);
            i += rem;
            temp = temp + "<" + to_string(part) + "/" + to_string(b) + ">";
            part++;
            ans.push_back(temp);
        }
        return ans;
    }
};