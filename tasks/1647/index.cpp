#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q, v, a, b;

  cin >> n >> q;

  vector<int> tree(2 * n);

  for (int i = 0; i < n; i++)
  {
    cin >> v;

    tree[i + n] = v;
  }
  

  for (int i = n - 1; i > 0; i--)
  {
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
  }

  while (q) 
  {
    q--;

    cin >> a >> b;
    a += n - 1;
    b += n - 1;

    int m = tree[a];

    while (a <= b)
    {
      if (a % 2 == 1)
      {
        m = min(m, tree[a]);
        a++;
      }

      if (b % 2 == 0)
      {
        m = min(m, tree[b]);
        b--;
      }

      a = floor(a / 2);
      b = floor(b / 2);
    }
    
    cout << m << "\n";
  }
}