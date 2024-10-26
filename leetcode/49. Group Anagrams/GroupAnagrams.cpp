#include <vector>
#include <string>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> meinMap;
        vector<vector<string>> res;

        for (int i=0; i<strs.size(); i++){
            string wordCopy = strs[i];
            sort(strs[i].begin(),strs[i].end());
            meinMap[strs[i]].push_back(wordCopy);
        }

        for (const auto& pair : meinMap){
            res.push_back(pair.second);
        }
        
        return res;
    }
};