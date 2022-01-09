#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for (int i=s; i<e; i++)
typedef long long ll;
typedef vector<int> vi;

ll i,j,k,t,n,a;
bitset<(int)3e5> arr;

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL);
  
  cin >> n;
  while (++i < n){
    cin >> a;
    arr[a] = 1;
  }
  for_(i,1,n+1)
    if (!arr[i]){
      cout << i;
      break;
    }

  return 0;
}
