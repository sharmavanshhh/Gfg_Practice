class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
    int low = 0, high = arr.size() - 1;
    int result = -1; // to store the index of first occurrence

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k) {
            result = mid;
            high = mid - 1; // keep searching on the left side
        }
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return result;
}


};