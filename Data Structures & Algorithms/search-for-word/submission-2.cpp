class Solution {
public:
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word)
  {
  for (size_t i = 0; i < board.size(); i++) {
    for (size_t j = 0; j < board[0].size(); j++) {
      if (recursiveTree(board, word, i, j, board.size(), board[0].size(), 0))
        return true;
    }
  }
  return false;
  }

private:
  bool recursiveTree(std::vector<std::vector<char>> &board, std::string word,
                     int row, int col, int row_max, int col_max, size_t index)
                     {

bool res;

  if (index == word.size())
    return true;

  if (((row >= row_max || col >= col_max) || (row < 0 || col < 0)) ||
      (board[row][col] != word[index]) ||
      alreadySeenPath.find({row, col}) != alreadySeenPath.end())
    return false;
     else {
    alreadySeenPath.insert({row, col});
    res =
        recursiveTree(board, word, row + 1, col, row_max, col_max, index + 1) ||
        recursiveTree(board, word, row - 1, col, row_max, col_max, index + 1) ||
        recursiveTree(board, word, row, col + 1, row_max, col_max, index + 1) ||
        recursiveTree(board, word, row, col - 1, row_max, col_max, index + 1);
    alreadySeenPath.erase({row, col});
  }
  return res;
                     }

  std::set<std::vector<int>> alreadySeenPath;
};
