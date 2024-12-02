#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forIn(var, vec) for (auto var : vec)
#define forInRange(var, start, end) for (int var = start; var < end; var++)
#define readinput(in) freopen(in, "r", stdin)

bool all_increasing_or_decreasing(vector<int> &v) {
  bool increasing = true, decreasing = true;
  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i] >= v[i + 1]) increasing = false;
    if (v[i] <= v[i + 1]) decreasing = false;
  }
  return increasing || decreasing;
}

bool check_diff(vector<int> &v) {
  for (int i = 0; i < v.size() - 1; i++) {
    int cur = abs(v[i] - v[i + 1]);
    if (!(1 <= cur && cur <= 3)) return false;
  }
  return true;
}

bool check(vector<int> &v) {
  return all_increasing_or_decreasing(v) && check_diff(v);
}

int main() {
  vector<vector<int>> reports;

  readinput("inputs/2.txt");

  string line;
  while (getline(cin, line)) {
    vector<int> cur;
    stringstream ss(line);
    int col;
    while (ss >> col) {
      cur.push_back(col);
    }
    reports.push_back(cur);
  }

  // Solution

  int ans = 0;

  for (int row = 0; row < 1000; row++) {
    if (check(reports[row])) {
      ans++;
    }
  }

  cout << ans << endl;
}
