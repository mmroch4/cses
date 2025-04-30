#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, x;
  int mod = 1e9 + 7;

  cin >> n >> x;
  
  vector<int> coins(n);
  vector<int> value(x + 1);

  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }

  value[0] = 1;

  for (int i = 1; i <= x; i++)
  {
    for (auto c : coins)
    {
      if (i - c >= 0)
      {
        value[i] += value[i - c];
        value[i] %= mod;
      }
    }
  }
  
  cout << value[x] << "\n";
}