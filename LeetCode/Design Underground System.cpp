// Question Link - https://leetcode.com/problems/design-underground-system/

// Solution - 



class UndergroundSystem {
public:
    map<int, pair<string, int>> um;
    map<pair<string, string>, pair<double, int>> umm;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        um[id] = {stationName, t};        
    }
    
    void checkOut(int id, string stationName, int t) {
        if(umm.find({um[id].first, stationName}) == umm.end()){
            umm[{um[id].first, stationName}] = {t-um[id].second, 1};
        }
        else{
            double avg = umm[{um[id].first, stationName}].first;
            int n = umm[{um[id].first, stationName}].second;
            double newAvg = (avg*n + (t-um[id].second))/(n+1);
            umm[{um[id].first, stationName}] = {newAvg, n+1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return umm[{startStation, endStation}].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
