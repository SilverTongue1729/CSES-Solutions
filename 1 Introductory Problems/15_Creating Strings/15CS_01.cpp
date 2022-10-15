#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for (int i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define MOD1 1000000007
#define MOD2 998244353
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

int k,t,n,temp;

void fastprint(int num);

void permute(string str, int l){
  if (n-l==1){
    for_(i,0,n)
      putchar(str[i]);
    putchar('\n');
    return;
  }
  permute(str,l+1);
  string str1 = str;
  for_(i,l+1,n){
    str1 = str;
    if (str1[i] != str1[i-1]){
      temp = str1[i];
      for_(j,i,l)
        str1[j] = str1[j-1];
      str1[l] = temp;
      permute(str1,l+1);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  string str;
  getline(cin, str);
  n = str.size();
  sort(all(str));

  int ans=1;
  for_(i,1,n+1)
    ans*=i;

  int cnt=1;
  for_(i,1,n){
    if (str[i] != str[i-1]){
      for_(j,1,cnt+1)
        ans/=j;
      cnt=0;
    }
    cnt++;
  }
  for_(j,1,cnt+1)
    ans/=j;
  fastprint(ans);

  permute(str,0);

  return 0;
}

void fastprint(int num){
   char snum[65];
   int i = 0;
   do{
       snum[i++] = num % 10 + '0';
       num /= 10;
   } while (num);

   --i;

   while (i >= 0)
     putchar(snum[i--]);

   putchar('\n');
}
