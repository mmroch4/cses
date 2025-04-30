#include <bits/stdc++.h>

using namespace std;

vector<int> memo;
vector<bool> visited;
vector<int> coins;

int optimal(int x)
{
  if (x < 0)
  {
    return -1;
  }
  
  if (visited[x])
  {
    return memo[x];
  }

  int best = -1;

  for (auto c : coins)
  {
    int opt = optimal(x - c);

    if (opt != -1)
    {
      opt++;
      best = best != -1 ? min(best, opt) : opt;
    }
  }
  
  memo[x] = best;
  visited[x] = true;

  return best;
}

int main()
{
  int n, x, c;
  
  cin >> n >> x;
  
  memo.resize(x + 1);
  visited.resize(x + 1);
  coins.resize(n);
  
  memo[0] = 0;
  visited[0] = true;
  
  for (int i = 0; i < n; i++)
  {
    cin >> c;

    coins[i] = c;
  }
  
  cout << optimal(x) << "\n";
}

// int main()
// {
//   int n, x, c;
  
//   cin >> n >> x;
  
//   vector<int> coins(n);
//   vector<int> value(x + 1, 1e9);
  
//   for (int i = 0; i < n; i++)
//   {
//     cin >> c;
    
//     coins[i] = c;
//   }
  
//   value[0] = 0;

//   for (int i = 1; i <= x; i++)
//   {
//     value[i] = 1e9;

//     for (auto c : coins)
//     {
//       if (i - c >= 0)
//       {
//         value[i] = min(value[i], value[i - c] + 1);
//       }
//     }
//   }
  
//   cout << (value[x] != 1e9 ? value[x] : -1) << "\n";
// }
