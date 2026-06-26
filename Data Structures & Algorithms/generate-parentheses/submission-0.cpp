class Solution {
public:
std::vector<std::string> generateParenthesis(int n) {
  std::vector<std::string> solution;
  recursiveTree(0, n, solution, "", 0, 0);
  return solution;
}


void recursiveTree(int depth, int n,
                             std::vector<std::string> &solution,
                             std::string current, int open, int close) {

  if (depth / 2 == n && close == open) {
    solution.push_back(current);
    return;
  }

  if (open < n) {
    recursiveTree(depth + 1, n, solution, current + "(", open + 1, close);
  }
  if (close < open) {
    recursiveTree(depth + 1, n, solution, current + ")", open, close + 1);
  }
}
};
