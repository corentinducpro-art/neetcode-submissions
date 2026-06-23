class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
  std::unordered_map<int, int> alreadySeen;

  for (auto i = 0; i < nums.size(); ++i) {
    int target_map = target - nums[i];
    if (alreadySeen.find(target_map) != alreadySeen.end()) {
      return (i > alreadySeen[target_map])
                 ? std::vector<int>{alreadySeen[target_map], i}
                 : std::vector<int>{i, alreadySeen[target_map]};
    } else {
      alreadySeen[nums[i]] = i;
    }
  }
  return std::vector<int>{0, 0};
    }
};
