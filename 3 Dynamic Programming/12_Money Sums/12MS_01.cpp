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

  int n; cin>>n;
  vi c(n);
  int sum=0;
  for_(i,0,n){ cin>>c[i]; sum+=c[i];}
  sort(all(c));
  vi dp(sum+1,0);
  dp[0]=1;
  for_(i,1,n+1){
    for (j=sum-c[i-1];j>=0;j--){
      dp[j+c[i-1]] |= dp[j];
    }
  }
  int ans=0;
  for_(i,1,sum+1) if (dp[i]) ans++;
  cout<<ans<<endl;
  for_(i,1,sum+1) if (dp[i]) cout<<i<<" ";

  return 0;
}
