#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q, a, b;
  long long x;

  cin >> n >> q;

  vector<long long> tree(2 * n);

  for (int i = 0; i < n; i++)
  {
    cin >> x;

    tree[n + i] = x;
  }

  for (int i = n - 1; i > 0; i--)
  {
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
  
  while (q)
  {
    q--;
  
    cin >> a >> b;

    a += n - 1;
    b += n - 1;

    long long s = 0;

    while (a <= b)
    {
      if (a % 2 == 1)
      {
        s += tree[a];
        a++;
      }

      if (b % 2 == 0)
      {
        s += tree[b];
        b--;
      }

      a /= 2;
      b /= 2;
    }

    cout << s << "\n";
  }
}