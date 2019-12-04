// https://www.lintcode.com/problem/sort-integers-ii/description


class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
        quick_sort(A, 0, A.size() - 1);
    }
private:
    void quick_sort(vector<int>& arr, int start, int end) {
        if (start >= end)
            return ;
        int temp = arr[start];
        int left = start + 1, right = end;
        while (left < right) {
            while (arr[left] < temp && left < right)
                left++;
            while (arr[right] >= temp && left < right)
                right--;
            swap(arr[left], arr[right]);
        }
        if (arr[right] <= temp)
            swap(arr[right], arr[start]);
        else
            right++;
        quick_sort(arr, start, left - 1);
        quick_sort(arr, left, end);
    }
};

