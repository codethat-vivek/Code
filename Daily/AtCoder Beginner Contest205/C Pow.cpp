// Question Link - https://atcoder.jp/contests/abc205/tasks/abc205_c

// Solution - 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    
  int a, b, c;
  cin >> a >> b >> c ;

  if(c%2 == 0)
  {
    if(abs(a) == abs(b))
      cout << "=";
    else if(abs(a) > abs(b))
      cout << ">";
    else
      cout << "<";
  }
  else{
    if(a > b)
      cout << ">";
    else if(a < b)
      cout << "<";
    else
      cout << "=";
  }

  return 0;
}
