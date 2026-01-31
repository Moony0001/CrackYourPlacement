class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        // if(letters[n-1]<=target){
        //     return letters[0];
        // }

        int low = 0;
        int high = n-1;
        char ans = letters[0];
        while(low<=high){
            int mid = low+(high-low)/2;
            if(letters[mid]>target){
                ans = letters[mid];
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};