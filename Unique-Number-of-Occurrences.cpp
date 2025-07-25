class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
         unordered_map<int, int> freq;
    
    // Step 1: Count frequencies
    for (int num : arr) {
        freq[num]++;
    }

    unordered_set<int> seen;

    // Step 2: Check if any frequency is repeated
    for (auto it : freq) {
        if (seen.count(it.second)) {
            return false;  // Duplicate frequency found
        }
        seen.insert(it.second);
    }

    return true;
    
    }
};