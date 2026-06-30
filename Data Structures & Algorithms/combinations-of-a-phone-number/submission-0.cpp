class Solution {
public:
    vector<string> letterCombinations(string digits) {

  if (digits.empty()) {
    return {};
  }

  createMap();
  std::vector<std::string> result;
  std::string chemin_actuel;

  recursiveTree(result, digits, chemin_actuel, 0);

  return result;
}

    private:
      std::map<char, std::string> numToLetter;
    void recursiveTree(std::vector<std::string> &result,
                             const std::string &digits,
                             std::string &chemin_actuel, size_t depth) {

  if (depth == digits.size()) {
    result.push_back(chemin_actuel);
    return;
  }

  for (const auto &letter : numToLetter[digits[depth]]) {
    chemin_actuel += letter;
    recursiveTree(result, digits, chemin_actuel, depth + 1);
    chemin_actuel.pop_back();
  }
}

void createMap() {
  numToLetter['2'] = "abc";
  numToLetter['3'] = "def";
  numToLetter['4'] = "ghi";
  numToLetter['5'] = "jkl";
  numToLetter['6'] = "mno";
  numToLetter['7'] = "pqrs";
  numToLetter['8'] = "tuv";
  numToLetter['9'] = "wxyz";
}
};
