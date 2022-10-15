// https://www.youtube.com/watch?v=51AkVn5Urno
// beautiful amazing solution and amazing idea

#include <bits/stdc++.h>
using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define MOD 1000000007
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

  /*
  https://www.youtube.com/watch?v=51AkVn5Urno
  This video looks at this simply as states
  (last layer connected and not connected horizontally) and then looks the possible ways this can be extended

  https://www.youtube.com/watch?v=pMEYMYTX-r0
  This video looks at it again as the same two states but it looks at them in terms of
  cutting off a current tile or extending it/them

  Both of them end up with the same recursion as the states are the same
  */


  // vector<vector<ll>> dp2(1000006,vector<ll>(2));
  // dp2[1][0]=1; // squares in the last level are connected horizontally
  // dp2[1][1]=1; // squares in the last level are not connected horizontally
  //
  // for_(i,2,1000002){
  //   dp2[i][0] = (2*dp2[i-1][0] + dp2[i-1][1]) % MOD;
  //   dp2[i][1] = (dp2[i-1][0] + 4*dp2[i-1][1]) % MOD;
  // }

  /*
  This can also be simplified to a single line, Since there are two terms currently, we calculate
  dp[n] = dp[n][0]+dp[n][1];
  dp[n+1] = dp[n+1][0]+dp[n+1][1] = 3*dp[n][0]+5*dp[n][1];
  dp[n+2] = dp[n+2][0]+dp[n+2][1] = 11*dp[n][0]+23*dp[n][1];
  from this we get dp[n+2] = 6*dp[n+1] - 7*dp[n];
  */

  vector<ll> dp(1000006);
  dp[1]=2;
  dp[2]=8;
  for_(i,3,1000002)
    dp[i] = ((6*dp[i-1] - 7*dp[i-2])%MOD+MOD)%MOD;

  int t; cin>>t;
  while (t--){
    int n; cin>>n;
    // cout<<(dp2[n][0]+dp2[n][1])%MOD<<endl;
    cout<<dp[n]<<endl;
  }

  return 0;
}
