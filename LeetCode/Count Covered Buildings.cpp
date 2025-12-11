// Question Link - https://leetcode.com/problems/count-covered-buildings/

// Solution - 

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int b = buildings.size();
        map<int, pair<int, int>> mpX, mpY;
        for(int i=0; i<b; i++){
            if(mpX.find(buildings[i][0]) == mpX.end()){
                mpX[buildings[i][0]] = {buildings[i][1], buildings[i][1]};
            }
            else{
                mpX[buildings[i][0]] = {min(mpX[buildings[i][0]].first, buildings[i][1]), max(mpX[buildings[i][0]].second, buildings[i][1])};
            }

            if(mpY.find(buildings[i][1]) == mpY.end()){
                mpY[buildings[i][1]] = {buildings[i][0], buildings[i][0]};
            }
            else{
                mpY[buildings[i][1]] = {min(mpY[buildings[i][1]].first, buildings[i][0]), max(mpY[buildings[i][1]].second, buildings[i][0])};
            }
        }

        int covered = 0;
        for(int i=0; i<b; i++){
            int x = buildings[i][0], y = buildings[i][1];
            if(mpX[x].first < y && y < mpX[x].second){
                if(mpY[y].first < x && x < mpY[y].second){
                    ++covered;
                }
            }
        }

        return covered;

    }
};
