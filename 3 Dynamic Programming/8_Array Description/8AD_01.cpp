#include <bits/stdc++.h>
using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define sz(a) (int)(a.size())
#define LIM1 300005
#define MOD1 1000000007
// #define DEBUG
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef array<int, 2> ii;

int i,j,t,n;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  #ifdef LOCAL
    freopen("/home/sriteja/Programming/Random/input_01.txt","r",stdin);
  #endif

  int m;
  cin>>n>>m;
  vi v(n);
  for_(i,0,n) cin>>v[i];
  for_(i,1,n) if (v[i]&&v[i-1]&& abs(v[i]-v[i-1])>1){ cout<<0; return 0;}
  vector<vector<ll>> dp(n,vector<ll>(m+2,0));
  if (v[0]) dp[0][v[0]]=1;
  else for_(i,1,m+1) dp[0][i]=1;
  for_(i,1,n){
    if (v[i])
      if (v[i-1]) dp[i][v[i]]=dp[i-1][v[i-1]];
      else dp[i][v[i]] = (dp[i-1][v[i]+1]+dp[i-1][v[i]]+dp[i-1][v[i]-1]) % MOD1;
    else for_(j,1,m+1) dp[i][j]=(dp[i-1][j+1]+dp[i-1][j]+dp[i-1][j-1]) % MOD1;
  }
  if (v[n-1]) cout<<*max_element(all(dp[n-1]));
  else{
    ll sum=0;
    for (auto val:dp[n-1]) sum=(sum+val)%MOD1;
    cout<<sum;
  }

  return 0;
}
