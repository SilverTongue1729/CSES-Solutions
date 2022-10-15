#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define MOD1 1000000007
#define MOD2 998244353
#define LIM1 (int)3e5+5
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

int i,j,t,n,c,ans,m,a,b,ia,ib;
int arr[LIM1],ind[LIM1];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n >> m;
  for_(i,1,n+1){
    cin >> ind[i];
    arr[ind[i]] = i;
  }

  for_(i,2,n+2)
    if (arr[i] < arr[i-1])
      ans++;

  while (m--){
    cin >> a >> b;
    ia = ind[a]; ib = ind[b];

    if (ia-ib==1) (arr[ia]<arr[ib]) ? ans++ : ans--;
    else if (ib-ia==1) (arr[ib]<arr[ia]) ? ans++ : ans--;

    ans -= (arr[ia-1]>arr[ia]) + (arr[ia]>arr[ia+1]) + (arr[ib-1]>arr[ib]) + (arr[ib]>arr[ib+1]);

    swap(ind[a],ind[b]);
    arr[ind[a]] = a; arr[ind[b]] = b;

    ans += (arr[ia-1]>arr[ia]) + (arr[ia]>arr[ia+1]) + (arr[ib-1]>arr[ib]) + (arr[ib]>arr[ib+1]);

    cout << ans << '\n';
  }

  return 0;
}
