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
typedef set<int> si;
typedef multiset<int> msi;
typedef pair<int,int> pi;

int i,j,t,n,c;
int par[LIM1],child[LIM1];
vvi v(LIM1,vi(5,0));

bool compare(const vi& v1, const vi& v2){
  if (v1[0] < v2[0]) return 1;                        // first column is sorted in ascending
  else return ((v1[0] == v2[0]) && (v1[1] > v2[1]));  // second column is sorted in desceding
}

bool compare2(const vi& v1, const vi& v2){
  return v1[2] < v2[2];
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> n;
  for_(i,0,n){ cin >> v[i][0] >> v[i][1]; v[i][2] = i;}
  for_(i,0,n){ par[i] = i; child[i] = i;}
  sort(v.begin(),v.begin()+n,compare);

  for_(i,1,n){
    if (v[i][1] <= v[par[i-1]][1]){
      par[i] = par[i-1];
      v[par[i]][3] = 1;
      v[i][4] = 1;
    }
  }

  for_(i,n-2,-1){
    if (v[i][1] >= v[child[i+1]][1]){
      child[i] = child[i+1];
      v[child[i]][4] = 1;
      v[i][3] = 1;
    }
  }

  sort(v.begin(),v.begin()+n,compare2);

  for_(i,0,n) cout << v[i][3] << ' '; cout << '\n';
  for_(i,0,n) cout << v[i][4] << ' ';

  return 0;
}
