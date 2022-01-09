#include <bits/stdc++.h>

using namespace std;

ios::sync_with_stdio(false); cin.tie(NULL);

#define for_(i,s,e) for (int i=s; i<e; i++)
typedef long long ll;
typedef vector<int> vi;

ll i,j,k,t,n;

int main(){
  cin >> n;
  cout << n << " ";
  while (n!=1)
    if (n&1)
      cout << (n=3*n+1) << " ";
    else
      cout << (n=n/2) << " ";

  return 0;
}
