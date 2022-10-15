// Gives TLE

#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define MOD1 1000000007
#define LIM1 300005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

int i,j,t,n,c,ans,k;
int arr[LIM1];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  while (n--){
    cin >> k;
    for_(i,0,ans)
      if (k<arr[i]){
        arr[i] = k;
        break;
      }
    if (i==ans){
      arr[ans] = k;
      ans++;
    }
  }

  cout << ans;

  return 0;
}
