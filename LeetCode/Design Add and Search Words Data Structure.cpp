// Question Link - https://leetcode.com/problems/design-add-and-search-words-data-structure/

// Solution - 

class Node{
    public:
    char ch;
    bool isEnd=false;
    unordered_map<char, Node*> um;
    
    Node(){}
    
    Node(char ch){
        this -> ch = ch;
    }
    
};


class WordDictionary {
private:
    Node *root;
public:
    WordDictionary() {
        root = new Node('#');
    }
    
    void addWord(string word) {
        Node *curr = root;
        for(char c : word){
            if(curr -> um.find(c) == curr -> um.end())
                curr -> um[c] = new Node();
            curr = curr -> um[c];
        }
        curr -> isEnd = true;
    }
    
    bool searchHelper(Node *start, string word){
        Node *curr = start;
        char c;
        for(int i=0; i<word.length(); i++){
            c = word[i];
            if(c != '.'){
                if(curr -> um.find(c) == curr -> um.end())
                    return false;
                curr = curr -> um[c];
            }
            else{
                for(auto itr : curr -> um){
                    if(searchHelper(itr.second, word.substr(i+1))) 
                        return true;
                }
                return false;
            }
        }
        return curr -> isEnd;
    }
    
    bool search(string word) {
        return searchHelper(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
