// Question Link - https://atcoder.jp/contests/abc276/tasks/abc276_d

// Solution - 

#include <iostream>
#include <algorithm>
using namespace std;
 
int calc(int k){
    int res = 0;
    while(k != 1 && k % 2 == 0){
        res++;
        k = k / 2;
    }
    while(k != 1 && k % 3 == 0){
        res++;
        k = k /3;
    }
    if(k != 1) return -1;
    return res;
}
 
int solution(int n, int arr[]){
    int ans = 0;
    int hcf = arr[0];
    for(int i=1; i<n; i++)
        hcf = __gcd(hcf, arr[i]);
    //cout << hcf << endl;
    for(int i=0; i<n; i++){
        int x = calc(arr[i]/hcf);
        if(x == -1) return -1;
        ans += x;
    }
    return ans;
}
 
int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    cout << solution(n, arr) << "\n";
 
    return 0;
}
