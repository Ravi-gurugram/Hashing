class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> posS;
    for (int i = 0; i < s.length(); ++i) {
        posS[s[i]] = i;
    }

    int diff = 0;
    for (int i = 0; i < t.length(); ++i) {
        diff += abs(posS[t[i]] - i);
    }

    return diff;
    }
};