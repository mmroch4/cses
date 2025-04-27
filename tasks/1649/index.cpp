#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q, x, m, k, u, a, b, v;

  cin >> n >> q;

  vector<int> tree(2 * n);

  for (int i = 0; i < n; i++)
  {
    cin >> x;

    tree[n + i] = x;
  }
  
  for (int i = n - 1; i > 0; i--)
  {
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
  }

  while (q)
  {
    q--;
  
    cin >> m;

    if (m == 1)
    {
      cin >> k >> u;
      k += n - 1;

      tree[k] = u;

      k /= 2;

      while (k > 0)
      {
        tree[k] = min(tree[2 * k], tree[2 * k + 1]);

        k /= 2;
      }
    }
    else 
    {
      cin >> a >> b;
      a += n - 1;
      b += n - 1;
    
      int v = tree[a];

      while (a <= b)
      {
        if (a % 2 == 1)
        {
          v = min(v, tree[a]);
          a++;
        }

        if (b % 2 == 0)
        {
          v = min(v, tree[b]);
          b--;
        }

        a /= 2;
        b /= 2;
      }

      cout << v << "\n";
    }
  }
}