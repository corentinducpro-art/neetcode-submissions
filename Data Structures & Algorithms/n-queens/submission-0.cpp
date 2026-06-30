class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> result;
  board = std::vector<std::string>(n, std::string(n, '.'));
  recursiveTree(0, n, 0, result);

  return result;
    }

    private:
    void recursiveTree(int row, int n, int depth,
                             std::vector<std::vector<std::string>> &result) {

  if (depth == n) {
    result.push_back(board);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (Col.find(i) != Col.end() || DiagPos.find((row + i)) != DiagPos.end() ||
        DiagNeg.find((row - i)) != DiagNeg.end())
      continue;
    board[row][i] = 'Q';
    Col.insert(i);
    DiagPos.insert((row + i));
    DiagNeg.insert((row - i));

    recursiveTree(row + 1, n, depth + 1, result);

    board[row][i] = '.';
    Col.erase(i);
    DiagPos.erase((row + i));
    DiagNeg.erase((row - i));
  }
                             }
                               std::unordered_set<int> Col;
  std::unordered_set<int> DiagNeg;
  std::unordered_set<int> DiagPos;
  std::vector<std::string> board;
};
