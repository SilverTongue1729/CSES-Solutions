#include <bits/stdc++.h>

using namespace std;

ios_base::sync_with_stdio(false); cin.tie(0);

#define for_(i,s,e) for (ll1 i=s; i<e; i++)
typedef long long ll;
typedef vector<int> vi;

ll arr[10005];
ll i,j,k,t,n,a,b,x,y,ans;

int main(){
  cin >> n;
  arr[1]=0;
  arr[2]=6;
  arr[3]=28;
  arr[4]=96;

  for (i=1;i<=n && i<=4;i++)
    cout << arr[i] << "\n";
  for_(i,5,n+1){
    arr[i] = arr[i-1] + ((2*i-3)*i-7)*i+16;
    cout << arr[i] << "\n";
  }

  return 0;
}
