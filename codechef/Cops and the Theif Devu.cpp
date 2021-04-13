// Question Link - https://www.codechef.com/problems/COPS

// Solution Link - chttps://www.codechef.com/problems/COPS

// SOLUTION - 

#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;

	while(t--)
	{
	    int m,x,y;
        vector<int> a(101,0);
        cin>>m>>x>>y;
        int p=x*y;
        vector<int> v;
        for(int i=0;i<m;i++)
        {
            int temp;
            cin>>temp;
            int s=temp+p;
            int r=temp-p;
            if(r<1)
                r=1;
            if(s>100)
                s=100;
        for(int j=r;j<=s;j++)	
                a[j] = 1;
        }
        int count = 0;
        for (int i = 1; i <=100; i++)
        {
          if (a[i] == 0)
            count++;
        }
        cout<<count<<endl;
        
	    
	}
	
	return 0;
}
