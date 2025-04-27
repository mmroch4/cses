#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q, m, a, b, k;
  long long x, u;

  cin >> n >> q;

  vector<long long> tree(2 * n);

  long long previous = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> x;

    tree[n + i] = x - previous;

    previous = x;
  }
  
  for (int i = n - 1; i > 0; i--)
  {
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }

  while (q)
  {
    q--;

    cin >> m;

    if (m == 1) 
    {
      cin >> a >> b >> u;
      a += n - 1;
      b += n; // -1 + 1

      tree[a] += u;

      a /= 2;
      
      if (b < 2 * n)
      {
        tree[b] -= u;

        b /= 2;
      }

      while (a > 0 && b > 0)
      {
        tree[a] = tree[2 * a] + tree[2 * a + 1];
        
        a /= 2;

        if (b < 2 * n)
        {
          tree[b] = tree[2 * b] + tree[2 * b + 1];

          b /= 2;
        }
      }
    }
    else
    {
      cin >> k;
      k += n - 1;

      long long s = 0;

      int t = n;

      while (t <= k)
      {
        if (t % 2 == 1)
        {
          s += tree[t];
          t++;
        }

        if (k % 2 == 0)
        {
          s += tree[k];
          k--;
        }

        t /= 2;
        k /= 2;
      }

      cout << s << "\n";
    }
  }
}