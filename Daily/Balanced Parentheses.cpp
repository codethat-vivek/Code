/*
Question - BALANCED PARENTHESES

  A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].
  Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the 
  exact same type. There are three types of matched pairs of brackets: [], {}, and ().
  A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. 
  For example, {[(])} is not balanced because the contents in between { and } are not balanced. 
  The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].
  By this logic, we say a sequence of brackets is balanced if the following conditions are met:
  (i) It contains no unmatched brackets.
  (ii) The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.

Given n strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, return YES. Otherwise, return NO.

Constraints:
1 <= n <= 10^3
1 <= |s| <= 10^3, where |s| is the length of the sequence.
All characters in the sequences ∈ { {, }, (, ), [, ] }.
*/

// SOLUTION - 

#include <bits/stdc++.h>

using namespace std;

struct node
{
    char data;
    struct node *next;
}*top = NULL;

void push(char x){
    node *t = (struct node*)malloc(sizeof(struct node));
    t -> data = x;
    t -> next = NULL;
    if(top == NULL)
        top = t;
    else{
        t -> next = top;
        top = t;
    }
}

char pop(){
    char x = 'a';
    if(top != NULL){
        node *t = top;
        top = top -> next;
        x = t -> data;
        free(t);
    }
    return x;
}

bool isMatch(char a, char b){
    if(a == '(' && b == ')')
        return true;
    else if(a == '{' && b == '}')
        return true;
    else if(a == '[' && b == ']')
        return true;
    else
        return false;
}

// Complete the isBalanced function below.
string isBalanced(string s) {
    char popped;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            push(s[i]);
        }
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(top == NULL)
                return "NO";
            popped = pop();
            if(isMatch(popped, s[i]) == false)
                return "NO";
        }
    }
    if(top == NULL)
        return "YES";
    else
        return "NO";
}

int main()
{
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        top = NULL;
        cout << isBalanced(s) << endl;
    }


    return 0;
}
