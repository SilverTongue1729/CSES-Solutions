#include <bits/stdc++.h>

using namespace std;

ios_base::sync_with_stdio(false); cin.tie(0);

#define for_(i,s,e) for (int i=s; i<e; i++)
typedef long long ll;
typedef vector<int> vi;

ll arr[(int)3e5];
ll i,j,k,t,n,a,b,x,y,ans,l;

int main(){
  cin >> t;
  while (t--){
    cin >> y >> x;
    (x > y) ? l=x : l=y;
    if (l&1)
      cout << l*l-(l-x)-y+1 << "\n";
    else
      cout << l*l-(l-y)-x+1 << "\n";
  }

  return 0;
}
