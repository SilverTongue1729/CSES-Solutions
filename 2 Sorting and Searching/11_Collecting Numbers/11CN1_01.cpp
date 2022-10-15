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

int i,j,t,n,c,ans,ind;
int arr[(int)2e5+1];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  for_(i,0,n){
    cin >> ind;
    arr[ind-1] = i;
  }
  for_(i,1,n)
    if (arr[i] < arr[i-1])
      ans++;
  cout << ++ans;

  return 0;
}
