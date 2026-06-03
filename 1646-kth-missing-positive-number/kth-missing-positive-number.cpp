class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Calculate how many numbers are missing BEFORE arr[mid]
            int missing = arr[mid] - (mid + 1);

            // If we are missing fewer than k numbers, move right
            if (missing < k) {
                left = mid + 1;
            } 
            // If we are missing k or more numbers, move left
            else {
                right = mid - 1;
            }
        }

        // The math perfectly simplifies to left + k
        return left + k;
    }
};