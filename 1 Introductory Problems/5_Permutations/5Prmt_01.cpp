#include <bits/stdc++.h>

using namespace std;

ios_base::sync_with_stdio(false); cin.tie(0);

#define for_(i,s,e) for (int i=s; i<e; i++)
typedef long long ll;
typedef vector<int> vi;

ll arr[(int)3e5];
ll i,j,k,t,n,a,b,ans;

int main(){
  cin >> n;
  if (n==1)
    cout << "1";
  else if (n==2||n==3)
    cout << "NO SOLUTION";
  else if (n==4)
    cout << "2 4 1 3";
  else {
    for (i=1;i<=n;i+=2)
      cout << i << " ";
    for (i=2;i<=n;i+=2)
      cout << i << " ";
  }

  return 0;
}
