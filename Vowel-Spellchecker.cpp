class Solution {
public:
   // Helper function to convert string to lowercase
    string toLower(string word) {
        for (char &c : word)
            c = tolower(c);
        return word;
    }

    // Helper function to mask vowels
    string devowel(string word) {
        string result;
        for (char c : word) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                result += '*';
            else
                result += c;
        }
        return result;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelMasked;

        // Preprocess wordlist
        for (string word : wordlist) {
            string lower = toLower(word);
            string masked = devowel(word);

            if (caseInsensitive.find(lower) == caseInsensitive.end())
                caseInsensitive[lower] = word;

            if (vowelMasked.find(masked) == vowelMasked.end())
                vowelMasked[masked] = word;
        }

        vector<string> result;
        for (string query : queries) {
            if (exact.find(query) != exact.end()) {
                result.push_back(query); // Exact match
            } else {
                string lower = toLower(query);
                string masked = devowel(query);

                if (caseInsensitive.find(lower) != caseInsensitive.end())
                    result.push_back(caseInsensitive[lower]); // Case insensitive match
                else if (vowelMasked.find(masked) != vowelMasked.end())
                    result.push_back(vowelMasked[masked]);    // Vowel masked match
                else
                    result.push_back(""); // No match
            }
        }

        return result;
    }
};