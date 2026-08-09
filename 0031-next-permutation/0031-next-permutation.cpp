class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();

        // 1. Find the pivot
        int pivot = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                pivot = i;
                break;
            }
        }

        // 2. If no pivot, array is in descending order
        //    so next permutation is the smallest permutation
        if (pivot == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // 3. Find the smallest element greater than A[pivot]
        //    from the right side
        for (int i = n - 1; i > pivot; i--) {
            if (A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        // 4. Reverse the suffix
        int i = pivot + 1;
        int j = n - 1;

        while (i < j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
};