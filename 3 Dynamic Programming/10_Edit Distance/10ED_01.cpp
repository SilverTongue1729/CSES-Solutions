#include <bits/stdc++.h>
using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define sz(a) (int)(a.size())
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

int i,j;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  #ifdef LOCAL
    freopen("/home/sriteja/Programming/Random/input_01.txt","r",stdin);
  #endif

  string sn,sm;
  cin>>sn>>sm;
  int n=sz(sn),m=sz(sm);
  vector<vector<int>> dp(n+1,vector<int> (m+1,1e9));
  dp[0][0]=0;
  for_(i,0,n+1){
    for_(j,0,m+1){
      if (i) dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
      if (j) dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
      if (i&&j) dp[i][j] = min(dp[i][j],dp[i-1][j-1]+ (sn[i-1]!=sm[j-1]) );
    }
  }

  cout<<dp[n][m];

  return 0;
}
