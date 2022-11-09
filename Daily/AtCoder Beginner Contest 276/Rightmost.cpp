// Question Link - https://atcoder.jp/contests/abc276/tasks/abc276_a

// Solution - 

#include <iostream>
using namespace std;
 
int main(){
  string s;
  cin >> s;
  int ans = -1;
  for(int i=s.length()-1; i>=0; i--){
    if(s[i] == 'a'){
      ans = i+1;
      break;
    }
  }
  cout << ans << "\n";
}
