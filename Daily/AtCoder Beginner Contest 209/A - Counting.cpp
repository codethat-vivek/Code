// Question Link - https://atcoder.jp/contests/abc209/tasks/abc209_a

// Solution - 

#include <iostream>
using namespace std;
 
int main(){
  
  int a, b;
  cin >> a >> b;
 
  if(b-a+1 >= 0)
    cout << b-a+1;
  else
    cout << 0;
  
  return 0;
}
