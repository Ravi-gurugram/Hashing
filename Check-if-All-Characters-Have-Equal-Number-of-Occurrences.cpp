class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26] = {0};

    // Count frequency of each character
    for (char ch : s) {
        freq[ch - 'a']++;
    }

    // Find the first non-zero frequency
    int target = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            target = freq[i];
            break;
        }
    }

    // Check if all non-zero frequencies are equal to target
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0 && freq[i] != target)
            return false;
    }

    return true;
    }
};