class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
    int count = 0;

    for (int num : nums) {
        count += freq[num];  // All previous occurrences can pair with this one
        freq[num]++;
    }

    return count;
    
    }
};