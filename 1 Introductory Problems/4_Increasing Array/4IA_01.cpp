#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(false); cin.tie(NULL);

#define for_(i,s,e) for (int i=s; i<e; i++)
typedef long long ll;
typedef vector<int> vi;

// ll arr[(int)3e5];
ll i,j,k,t,n,a,b,ans,largest;

int main(){
  cin >> n;
  for_(i,0,n){
    cin >> a;
    if (a < largest)
      ans += largest-a;
    else
      largest = a;
  }
  cout << ans;

  return 0;
}
