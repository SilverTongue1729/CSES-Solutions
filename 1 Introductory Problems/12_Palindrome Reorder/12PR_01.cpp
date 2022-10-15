#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define MOD1 1000000007
#define MOD2 998244353
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

int i,j,k,c,t,n,ans,odd,nosol=1,len,oddind;
vi letters(26,0);

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  while ((c=getchar())>= 'A' && c<='Z'){
    letters[c-'A']++;
    len++;
  }

  nosol = 1;
  for_(i,0,26){
    if (letters[i]%2){
      odd++;
      oddind = i;
      if (len&1==0 || odd > 1){
        nosol=0;
        break;
      }
    }
  }

  if (nosol){
    for_(i,0,26)
      for_(j,0,letters[i]/2)
        putchar(i+'A');
    if (len&1)
      putchar(oddind+'A');
    for_(i,25,-1)
      for_(j,0,letters[i]/2)
        putchar(i+'A');
  }
  else
    cout << "NO SOLUTION";

  return 0;
}
