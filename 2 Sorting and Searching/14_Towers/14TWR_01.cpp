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

int i,j,t,n,c,ans,x;
multiset<int> s;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> n;
  for_(i,0,n) {
  	cin >> x;
  	auto it = s.upper_bound(x);
  	if (it != s.end())
      s.erase(it);
    s.insert(x);
  }
  cout << s.size() << endl;

  return 0;
}
