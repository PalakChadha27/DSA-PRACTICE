class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool first) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                if (first)
                    high = mid - 1;   // Search left
                else
                    low = mid + 1;    // Search right
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, target, true),
                binarySearch(nums, target, false)};
    }
};