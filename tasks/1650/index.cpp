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

    unordered_set<int> list;
    unordered_set<int> visited;
    
    while (a <= b)
    {
      if (a % 2 == 1)
      {

        
        a++;
      }

      if (b % 2 == 0)
      {

        
        b--;
      }

      a /= 2;
      b /= 2;
    }

    cout << list.size() << "\n";
  }

}



