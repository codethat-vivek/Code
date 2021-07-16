/*
Question -
  Two friends, A and B, are playing the game of matchsticks. In this game, a group of N matchsticks is placed on the table. 
  The players can pick any number of matchsticks from 1 to 4 (both inclusive) during their chance. The player who takes the last match stick wins the game. 
  If A starts first, how many matchsticks should he pick such that he is guaranteed to win the game or determine if it's impossible for him to win.
Note : Consider both A and B play the game optimally

Input:
N = 48
Output:
3
Explanation:
Player A is guaranteed a win if he
picks 3 matchsticks first.

Input:
N = 15
Output:
-1
Explanation:
Player A is guaranteed a loss no matter
how many matches he picks at first.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
*/

// SOLUTION -

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int matchGame(long long N) {
        // code here
        if(N%5 >= 1 && N%5 <= 4)
            return N%5;
        return -1;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.matchGame(N) << endl;
    }
    return 0;
} 
 
