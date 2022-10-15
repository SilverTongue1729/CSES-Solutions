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

int i,j,k;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("/home/sriteja/Competitive Programming/Random/input_01.txt","r",stdin);
  freopen("/home/sriteja/Competitive Programming/Random/output_01.txt","w",stdout);
#endif

  int a,b;
  cin>>a>>b;
  if (a<b) swap(a,b);
  vector<vector<int>> dp(a+1,vector<int> (b+1,1e9));
  dp[1][1]=0;
  for_(i,1,a+1){
    for_(j,1,b+1){
      if (i==j){
        dp[i][j]=0;
        continue;
      }
      for_(k,1,i/2+1)
        dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
      for_(k,1,j/2+1)
        dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
    }
  }

  cout<<dp[a][b];

  return 0;
}
