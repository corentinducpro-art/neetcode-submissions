#include <vector>
#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(const std::vector<int>& nums) {
        std::unordered_set<int> alreadySeen;

        for (const auto& num : nums) {
            if (alreadySeen.find(num) != alreadySeen.end()) {
                return true;
            }
            alreadySeen.insert(num);
        }
        return false;
    }
};