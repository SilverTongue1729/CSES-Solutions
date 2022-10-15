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

int i,j,t,n,c,ans,k=1,size,pos;
vi nums;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> n;
  nums.resize((n+1)/2);
  for_(i,0,n/2) cout << 2*(i+1) << ' '; // print all even numbers
  for_(i,0,(n+1)/2) nums[i] = 2*i+1; // start with only odd numbers

  if (n%2) pos=-1;
  n-=n/2;

  while (n){
    pos = (pos+k) % n--;
    cout << nums[pos] << ' ';
    nums.erase(nums.begin()+pos);
  }

  return 0;
}
