#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forIn(var, vec) for (auto var : vec)
#define forInRange(var, start, end) for (int var = start; var < end; var++)
#define readinput(in) freopen(in, "r", stdin)

int main() {
  readinput("inputs/3.txt");

  regex r("mul\\(([0-9]+),([0-9]+)\\)", regex_constants::ECMAScript);

  ll ans = 0;

  string line;
  while (getline(cin, line)) {
    smatch m;

    string::const_iterator start(line.cbegin());

    while (regex_search(start, line.cend(), m, r)) {
      int a = stoi(m[1]);
      int b = stoi(m[2]);

      ans += a * b;

      start = m.suffix().first;
    }
  }

  cout << ans << endl;
}