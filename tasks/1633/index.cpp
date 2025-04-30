#include <bits/stdc++.h>

using namespace std;

int main() 
{
  int n;
  cin >> n;

  int mod = 1e9 + 7;

  vector<int> value(n + 1);

  value[0] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int u = 1; u <= 6 && i - u >= 0; u++)
    {
      value[i] += value[i - u];
      value[i] %= mod;
    }
  }
  
  cout << value[n] << "\n";
}