class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<char, pair<int, int>> pos;
    for (int i = 0; i < 26; ++i) {
        pos['a' + i] = {i / 5, i % 5};
    }

    int r = 0, c = 0;
    string res;

    for (char ch : target) {
        int tr = pos[ch].first, tc = pos[ch].second;

        // Special handling to avoid going right into 'z' row (which has only 1 column)
        // So move vertically first if target is 'z'
        if (tr < r) res.append(r - tr, 'U');
        if (tc < c) res.append(c - tc, 'L');
        if (tr > r) res.append(tr - r, 'D');
        if (tc > c) res.append(tc - c, 'R');

        res += '!';
        r = tr;
        c = tc;
    }

    return res;
    
    }
};