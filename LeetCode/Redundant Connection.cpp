// Question Link - https://leetcode.com/problems/redundant-connection/

// Solution - 

class DisjointSet{
    private:
    vector<int>parent;
    vector<int>size;
    
    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++)
            parent[i] = i;
    }
    
    int findParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    bool doUnion(int firstNode, int secondNode){
        int firstParent = findParent(firstNode);
        int secondParent = findParent(secondNode);
        if(firstParent == secondParent) return false;
        
        if(size[firstParent] < size[secondParent]){
            size[secondParent] += size[firstParent];
            parent[firstParent] = secondParent;
        }
        else{
            size[firstParent] += size[secondParent];
            parent[secondParent] = firstParent;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n+1);
        for(auto &e : edges){
            if(!ds.doUnion(e[0], e[1]))
                return e;
        }
        return {};
    }
};
