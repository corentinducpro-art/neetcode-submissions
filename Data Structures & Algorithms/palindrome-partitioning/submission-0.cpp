class Solution {
public:
bool estPalindrome(const std::string &s, size_t debut, size_t fin) {
  while (debut < fin) {
    if (s[debut] != s[fin])
      return false;
    debut++;
    fin--;
  }
  return true;
};
    vector<vector<string>> partition(string s) {
          std::vector<std::vector<std::string>> result;
  std::vector<std::string> chemin_actuel;

  recursiveTree(result, s, chemin_actuel, 0);
  return result;
    };

    private:
    void recursiveTree(std::vector<std::vector<std::string>> &result,
                             const std::string &s,
                             std::vector<std::string> &chemin_actuel,
                             size_t index_depart) {

  if (index_depart == s.length()) {
    result.push_back(chemin_actuel);
    return;
  }

  for (size_t index_fin = index_depart; index_fin < s.length(); ++index_fin) {

    if (estPalindrome(s, index_depart, index_fin)) {

      std::string sous_chaine =
          s.substr(index_depart, index_fin - index_depart + 1);
      chemin_actuel.push_back(sous_chaine);
      recursiveTree(result, s, chemin_actuel, index_fin + 1);
      chemin_actuel.pop_back();
    }
  }
                             }
};
