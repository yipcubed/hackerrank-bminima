#include <algorithm>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


#include "../utils/PrintUtils.hpp"
#include "../utils/VectorUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() { // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

int main() {
  stringstream ss;
  stringstream os;
  int n;
  cin >> n;
  string line;
  for (int i = 0; i < n; i++) {
    int nums;
    cin >> nums;
    getline(cin, line);
    getline(cin, line);
    ss.str(line);
    vector<int> res(nums);
    int mx = INT_MIN;
    int mi = INT_MAX;
    for (int ix = 0; ix < nums; ix++) {
      ss >> res[ix];
      mx = max(res[ix], mx);
      mi = min(res[ix], mi);
    }
    int total = mi - mx;
    int notInplace = 0;
    if (res[0] != mx)
      ++notInplace;
    if (res[nums - 1] != mi)
      ++notInplace;
    if (res[0] == mi && res[nums-1] == mx)
      --notInplace;
    os << notInplace << " " << total << endl;
  }
  cout << os.str();

  return 0;
}
