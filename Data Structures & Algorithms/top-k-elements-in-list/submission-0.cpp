class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

  std::unordered_map<int, int> alreadySeenNumbers;

  for (const auto num : nums) {
    alreadySeenNumbers[num]++;
  }

  std::vector<std::vector<int>> buckets(nums.size() + 1);
  for (const auto &[num, count] : alreadySeenNumbers) {
    buckets[count].push_back(num);
  }

  std::vector<int> result;

  for (int i = buckets.size() - 1; i >= 0; --i) {
    for (const auto num : buckets[i]) {
      result.push_back(num);
      if (result.size() == k) {
        return result;
      }
    }
  }

  return result;
    }
};
