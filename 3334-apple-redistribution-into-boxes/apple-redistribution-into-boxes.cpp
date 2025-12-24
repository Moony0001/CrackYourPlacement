class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int total = 0;
        for(int i=0;i<n;i++){
            total+=apple[i];
        }

        sort(capacity.begin(), capacity.end(), greater<int>());
        int i=0;
        while(total>0){
            total-=capacity[i];
            i++;
        }
        return i;
    }
};