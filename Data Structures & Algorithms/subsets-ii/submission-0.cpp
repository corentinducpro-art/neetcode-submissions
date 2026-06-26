class Solution {
public:
std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
  std::vector<int> bag;
  std::vector<std::vector<int>> solution;
  std::sort(nums.begin(), nums.end());
  recursiveTree(0, nums, solution, bag);
  return solution;
}

    private:
    void recursiveTree(size_t depth, std::vector<int> &nums,
                             std::vector<std::vector<int>> &solution,
                             std::vector<int> &bag) {

  if (depth == nums.size()) {
    solution.push_back(bag);
    return;
  }

  bag.push_back(nums[depth]);
  recursiveTree(depth + 1, nums, solution, bag);
  bag.pop_back();

  while (depth < (nums.size() - 1) && nums[depth] == nums[depth + 1])
    depth++;

  recursiveTree(depth + 1, nums, solution, bag);
}
};
