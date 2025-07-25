class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> pos;  // maps num -> index in nums

    // Initialize positions
    for (int i = 0; i < nums.size(); ++i) {
        pos[nums[i]] = i;
    }

    // Process operations
    for (auto& op : operations) {
        int oldVal = op[0], newVal = op[1];
        int idx = pos[oldVal];

        nums[idx] = newVal;       // Update array
        pos[newVal] = idx;        // Update map with new value
        pos.erase(oldVal);        // Remove old value from map
    }

    return nums;
    }
};