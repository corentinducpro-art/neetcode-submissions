class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
          std::vector<int> bag;
  std::vector<std::vector<int>> solution;
  std::vector<int> current_nums;
  current_nums = nums;
  recursiveTree(0, nums, current_nums, solution, bag);
  return solution;
    }

    private:
    void recursiveTree(size_t depth, std::vector<int> &nums,
                             std::vector<int> &current_nums,
                             std::vector<std::vector<int>> &solution,
                             std::vector<int> &bag) {

  if (current_nums.empty()) {
    solution.push_back(bag);
    return;
  }

  for (size_t i = 0; i < current_nums.size(); ++i) {
    int element = current_nums[i];

    // Take
    bag.push_back(element);

    current_nums.erase(current_nums.begin() + i);

    recursiveTree(depth + 1, nums, current_nums, solution, bag);

    // Don't take (Backtrack)
    current_nums.insert(current_nums.begin() + i, element);
    bag.pop_back();
  }
}

};
