#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define MOD1 1000000007
#define MOD2 998244353
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

int i,j,t,n,c;
ll minv=0,ans=(ll)2e15*(-1);
ll x[(int)2e5+1][2];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  cin >> x[0][0];
  x[0][1] = x[0][0];
  ans = max(ans, x[0][1]-minv);
  minv = min(minv,x[0][1]);
  for_(i,1,n){
    cin >> x[i][0];
    x[i][1] = x[i-1][1] + x[i][0];
    ans = max(ans, x[i][1]-minv);
    minv = min(minv,x[i][1]);
  }

  cout << ans;

  return 0;
}
