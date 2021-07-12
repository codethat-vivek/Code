// Question Link - https://atcoder.jp/contests/abc209/tasks/abc209_b

// Solution - 

#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    int s = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        s += arr[i];
    }
    s -= n/2;
    if(x >= s)
        cout << "Yes";
    else
        cout << "No";
  
    return 0;
}
