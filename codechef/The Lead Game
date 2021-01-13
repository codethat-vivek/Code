// Question Link - https://www.codechef.com/problems/TLG

// Solution Link - https://www.codechef.com/viewsolution/31846633

// SOLUTION -

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n;
    cin>>n;
    int l1=0;int l2=0;
    int t1=0;int t2=0;
    int m1=0;int m2=0;
    while(n--){
        int x,y;
        cin>>x>>y;
        t1+=x;
        t2+=y;
        if(t1>t2)
        l1=t1-t2;
        else
        l2=t2-t1;
        m1=max(m1,l1);
        m2=max(m2,l2);
    }
    if(m1>m2)
    cout<<1<<" "<<m1<<endl;
    else
    cout<<"2 "<<m2<<endl;


	return 0;
}
