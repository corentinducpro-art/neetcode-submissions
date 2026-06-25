class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  std::vector<int> bag;
  std::vector<std::vector<int>> solution;
  std::sort(candidates.begin(), candidates.end());
  recursiveTree(0, target, 0, candidates, solution, bag);

  return solution;
    }
private:
  std::set<std::vector<int>> combinationAlreadyUse;
    void recursiveTree(size_t depth, int target, int currentTarget,
                             std::vector<int> &candidates,
                             std::vector<std::vector<int>> &solution,
                             std::vector<int> &bag) {


  if (currentTarget == target) {
    solution.push_back(bag);
    return;
  }

  if (depth == candidates.size() || currentTarget > target)
    return;

  // Take it
  bag.push_back(candidates[depth]);
  recursiveTree(depth + 1, target, currentTarget + candidates[depth],
                candidates, solution, bag);
  bag.pop_back();

  // Don't take it
  while (depth < (candidates.size() - 1) &&
         candidates[depth] == candidates[depth + 1])
    depth++;
  recursiveTree(depth + 1, target, currentTarget, candidates, solution, bag);

  return;
}
};
