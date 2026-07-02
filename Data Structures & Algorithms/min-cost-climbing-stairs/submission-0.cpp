class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
          std::vector<int> solution = cost;
  solution.push_back(0);

  return recursiveDP(cost, solution, solution.size() - 3);
    }

    private:
    int recursiveDP(std::vector<int> &cost, std::vector<int> &solution,
                          int index) {

  int stepOne = solution[index] + solution[index + 1];
  int stepTwo = solution[index] + solution[index + 2];

  int subproblem_solution = std::min(stepOne, stepTwo);

  solution[index] = subproblem_solution;

  if (index == 0) {
    return std::min(solution[0], solution[1]);
  }

  return recursiveDP(cost, solution, index - 1);
}
};
