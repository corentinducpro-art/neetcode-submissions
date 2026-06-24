class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums)
  {

  std::vector<std::vector<int>> solution_subset;
  std::vector<int> current_vector;
  recursiveTree(0, solution_subset, current_vector, nums);

  return solution_subset;
}

private:
  void recursiveTree(size_t depth,
                     std::vector<std::vector<int>> &solution_subset,
                     std::vector<int> &current_vector, std::vector<int> &nums){

  if (depth == nums.size()) {
    solution_subset.push_back(current_vector);
    return;
  }

  // Take the element
  current_vector.push_back(nums[depth]);
  recursiveTree(depth + 1, solution_subset, current_vector, nums);

  // Don't take it
  current_vector.pop_back();
  recursiveTree(depth + 1, solution_subset, current_vector, nums);
}
};
