class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int left = k;
        int right = 0;
        for (int a : arr) {
            right = max(right, a);
        }
        right += k;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            int low = 0;
            int high = n;
            while (low < high) {
                int m = low + (high - low) / 2;

                if (arr[m] >= mid) {
                    high = m;
                } else {
                    low = m + 1;
                }
            }
            int cnt = mid - low;
            if (cnt == k && ((low<n && arr[low] != mid) || low==n)) {
                ans = mid;
                break;
            } else if (cnt > k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};