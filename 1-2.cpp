#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forIn(var, vec) for (auto var : vec)
#define forInRange(var, start, end) for (int var = start; var < end; var++)
#define readinput(in) freopen(in, "r", stdin)

int main() {
  vector<int> l, r;
  ll a, b, sum = 0;

  readinput("inputs/1.txt");

  while (cin >> a >> b) {
    l.push_back(a);
    r.push_back(b);
  }

  map<int, int> count;

  forIn(i, r) count[i]++;

  forIn(i, l) sum += i * count[i];

  cout << sum << endl;
}