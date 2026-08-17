class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // Increasing side
                low = mid + 1;
            } 
            else {
                // Decreasing side or peak
                high = mid;
            }
        }

        return low;
    }
};