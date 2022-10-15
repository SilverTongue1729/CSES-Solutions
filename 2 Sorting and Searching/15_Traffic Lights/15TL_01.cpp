#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD1 1000000007
#define LIM1 300005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

int i,j,t,n,c,ans,x;
multiset<int> pos,len;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> x >> n;

  auto it = pos.begin();
  pos.insert(0);pos.insert(x);
  len.insert(x);
  for_(i,0,n){
    cin >> x;
    it = pos.insert(x);
    len.erase(len.find(*next(it,1)-*prev(it,1)));
    len.insert(*it-*prev(it,1));
    len.insert(*next(it,1)-*it);
    cout << *prev(len.end(),1) << ' ';
  }

  return 0;
}
