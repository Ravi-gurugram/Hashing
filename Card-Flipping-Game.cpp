class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;

        // Step 1: Find numbers that appear on both front and back of same card
        for (int i = 0; i < fronts.size(); ++i) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }

        int result = INT_MAX;

        // Step 2: Check all numbers not in 'same' that could be good
        for (int num : fronts) {
            if (!same.count(num)) {
                result = min(result, num);
            }
        }
        for (int num : backs) {
            if (!same.count(num)) {
                result = min(result, num);
            }
        }

        return result == INT_MAX ? 0 : result;
    }
};