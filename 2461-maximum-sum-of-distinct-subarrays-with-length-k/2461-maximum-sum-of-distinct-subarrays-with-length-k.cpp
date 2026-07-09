class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long max_sum = 0;
        long long current_sum = 0;
        unordered_map<int, int> counts; // Tracks frequency of elements in the current window

        for (int i = 0; i < n; i++) {
            // Add the current element to the window
            current_sum += nums[i];
            counts[nums[i]]++;

            if (i >= k) {
                int left_element = nums[i - k];
                current_sum -= left_element;
                counts[left_element]--;
                if (counts[left_element] == 0) {
                    counts.erase(left_element);
                }
            }

            if (i >= k - 1 && counts.size() == k) {
                max_sum = max(max_sum, current_sum);
            }
        }

        return max_sum;
    }
};