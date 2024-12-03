#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forIn(var, vec) for (auto var : vec)
#define forInRange(var, start, end) for (int var = start; var < end; var++)
#define readinput(in) freopen(in, "r", stdin)

regex r("mul\\(([0-9]+),([0-9]+)\\)|do\\(\\)|don't\\(\\)",
        regex_constants::ECMAScript);

ll multiply(string s) {
  ll ans = 0;
  bool enabled = true;
  string::const_iterator start(s.cbegin());

  smatch m;

  while (regex_search(start, s.cend(), m, r)) {
    if (m[0] == "don't()") {
      enabled = false;
    } else if (m[0] == "do()") {
      enabled = true;
    } else {
      if (enabled) {
        ll a = stoi(m[1]);
        ll b = stoi(m[2]);
        ans += a * b;
      }
    }

    start = m.suffix().first;
  }

  return ans;
}

int main() {
  readinput("inputs/3.txt");
  string puzzle;
  string line;
  while (getline(cin, line)) {
    puzzle += line;
  }
  cout << multiply(puzzle) << endl;
}