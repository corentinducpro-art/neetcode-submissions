class Solution {
public:
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &nums,
                                               int target)
                                               {
                                                  std::vector<int> bag;
  std::vector<std::vector<int>> result;

  recursiveTree(nums, result, bag, 0, target, 0);

  return result;
                                               }

private:
  void recursiveTree(std::vector<int> &nums,
                     std::vector<std::vector<int>> &result,
                     std::vector<int> &bag, int currentTarget, int target,
                     size_t depth)
                     {
                          if (depth == nums.size())
    return;

  if (currentTarget > target)
    return;
  else if (currentTarget == target) {
    result.push_back(bag);
    return;
  }

  // Take it
  bag.push_back(nums[depth]);
  recursiveTree(nums, result, bag, currentTarget + nums[depth], target, depth);
  bag.pop_back();

  // Don't take it
  recursiveTree(nums, result, bag, currentTarget, target, depth + 1);
                     }
};
