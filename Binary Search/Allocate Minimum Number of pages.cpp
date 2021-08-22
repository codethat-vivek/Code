/*
ALLOCATE MINIMUM NUMBER OF PAGES:

Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Example :

Input : pages[] = {12, 34, 67, 90}
        m = 2
Output : 113
Explanation:
There are 2 number of students. Books can be distributed 
in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 
      2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student
      2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 
      1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113. 
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int n, int k, int mid)
{
    int student = 1;
    int sum1 = 0;
    for(int i =0; i<n; i++)
    {   
        sum1 = sum1 + arr[i];
        if(sum1 > mid)
        {
            student++;
            sum1 = arr[i];
        }
        if(student > k)
        return false;
        
    }
    return true;
}
int minimumPages(vector<int>& arr, int k) {
    int n =arr.size();

    if (n < k)
    return -1;
    int maxi = 0; int sum =0;
    for(int i = 0; i<n; i++)
    maxi = max(maxi, arr[i]);
   
    for(int i=0; i<n; i++)
    sum += arr[i];
    int start = maxi, end = sum;
    int res = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
       
        if(isValid(arr, n, k, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
        start = mid+1;
    }
     
    return res;
    
}
    
int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
        
    int k;
    cin >> k;
    
    cout << minimumPages(v, k);
    
    return 0;
}
// Lovely Explanation -> https://www.youtube.com/watch?v=2JSQIhPcHQg
