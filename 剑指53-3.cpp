int GetNumberSameAsIndex(vector<int>& nums) {
    if (nums.size() == 0) return -1;

    int left = 0, right = nums.size() - 1, mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] = mid) return mid;

        if (nums[mid] > mid)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}