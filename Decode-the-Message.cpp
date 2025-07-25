class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> map;
    char curr = 'a';

    // Create substitution map using first occurrences from key
    for (char ch : key) {
        if (ch != ' ' && map.find(ch) == map.end()) {
            map[ch] = curr++;
        }
    }

    // Decode message
    string result = "";
    for (char ch : message) {
        if (ch == ' ') result += ' ';
        else result += map[ch];
    }

    return result;
    }
};