class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end()); // Key step
            anagramGroups[sortedWord].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(move(pair.second)); // move to avoid copy
        }

        return result;
    }
};
