// Question Link - https://www.codechef.com/problems/ALPHABET

// Solution - 

#include <iostream>
using namespace std;

bool func(string word, int n, string s){
    int a[26] = {0};
    int b[26] = {0};
	for(int i=0; s[i]!='\0'; i++){
	    a[s[i]-'a']++;
	}
    for(int i=0; word[i]!='\0'; i++){
        b[word[i]-'a']++;
    }
    for(int i=0; i<26; i++){
        if(a[i] == 0 && b[i] != 0)
            return false;
    }
    return true;
}

int main() {
	// your code goes here
	string s;
	cin >> s;
	int n;
	cin >> n;
	string words[n];
	for(int i=0; i<n; i++)
	    cin >> words[i];
	
	for(int i=0; i<n; i++){
	    if(func(words[i], n, s))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
	}
	return 0;
}
