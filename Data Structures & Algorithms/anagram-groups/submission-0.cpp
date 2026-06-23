class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         std::map<std::array<int, 26>, std::vector<int>> groupAnagramsByIndex;
  std::vector<std::vector<std::string>> result;

  int stringIndex = 0;

  std::array<int, 26> letterCount;
  for (const auto &str : strs) {
    letterCount.fill(0);
    for (const auto &letter : str) {
      letterCount[letter - 'a']++;
    }
    groupAnagramsByIndex[letterCount].push_back(stringIndex);
    stringIndex++;
  }

  std::vector<std::string> currentGroup;
  for (const auto &map : groupAnagramsByIndex) {
    currentGroup.clear();
    for (const auto index : map.second) {
      currentGroup.push_back(strs[index]);
    }
    result.push_back(currentGroup);
  }

  return result;
    }
};
