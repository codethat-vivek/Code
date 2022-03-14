// Question Link - https://leetcode.com/problems/simplify-path/

// Solution - 

class Solution {
public:
    string simplifyPath(string path) {
        if(path[path.length()-1] != '/')
            path += '/';
        string delimiter = "/";
        vector<string>directories;
        size_t pos = 0;
        string dir;
        while ((pos = path.find(delimiter)) != std::string::npos) {
            dir = path.substr(0, pos);
            if(dir == "" || dir == "."){
                path.erase(0, pos + delimiter.length());
                continue;
            }
            else if(dir == ".."){
                if(directories.size())
                    directories.pop_back();
            }
            else
                directories.push_back(dir);
            
            path.erase(0, pos + delimiter.length());
        }
        
        //if(path.size())directories.push_back(path); 
        
        string canonicalPath = "";
        for(string dir : directories){
            cout << dir << " ";
            canonicalPath += ("/"+dir);
        }
        
        return canonicalPath == "" ? "/" : canonicalPath;
    }
};
