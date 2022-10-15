#include <bits/stdc++.h>

using namespace std;

ios_base::sync_with_stdio(false); cin.tie(0);

#define for_(i,s,e) for (ll i=s; i<e; i++)
typedef long long ll;
typedef vector<int> vi;

ll arr[(int)3e5];
ll i,j,k,t,n,a,b,x,y,ans;

int main(){
  cin >> n;
  if ((n*(n+1)/2) & 1)
    cout << "NO";
  else {
    cout << "YES\n";
    if (n&1){
      cout << (n-1)/2 << "\n";
      cout << n << " ";
      for_(i,1,(n+1)/4)
        cout << i << " " << n-i << " ";

      cout << "\n" << (n+1)/2 << "\n";
      for_(i, (n+1)/4, 3*(n+1)/4)
        cout << i << " ";
    }
    else{
      cout << n/2 << "\n";
      for_(i,1,n/4+1)
        cout << i << " " << n-i+1 << " ";

      cout << "\n" << n/2 << "\n";
      for_(i, n/4+1, 3*n/4+1)
        cout << i << " ";
    }
  }

  return 0;
}
