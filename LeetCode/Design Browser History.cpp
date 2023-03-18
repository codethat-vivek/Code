// Question Link - https://leetcode.com/problems/design-browser-history/

// Solution - 

class BrowserHistory {

private:
    stack<string> mainStack;
    stack<string> storeStack;
public:
    BrowserHistory(string homepage) {
        mainStack.push(homepage);
    }
    
    void visit(string url) {
        mainStack.push(url);
        while(!storeStack.empty())
            storeStack.pop();
    }
    
    string back(int steps) {
        string ans=mainStack.top();
        while(!mainStack.empty() && steps--){
            ans = mainStack.top();
            storeStack.push(ans);
            mainStack.pop();
        }
        if(!mainStack.empty()) return mainStack.top();
        mainStack.push(ans);
        storeStack.pop();
        return ans;
    }
    
    string forward(int steps) {
        while(steps-- && !storeStack.empty()){
            mainStack.push(storeStack.top());
            storeStack.pop();
        }
        return mainStack.top();
    }
};
