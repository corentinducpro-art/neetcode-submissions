class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
    return 1;
        return recursiveDP(1, 1, n - 2);
    }

    private:
    int recursiveDP(int one_step, int two_step, int n) {
  int temp = one_step;
  one_step += two_step;
  two_step = temp;
  if (n == 0) {
    return one_step;
  }
  return recursiveDP(one_step, two_step, n - 1);
}
};
