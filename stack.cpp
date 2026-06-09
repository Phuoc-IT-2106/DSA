#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
class Solution{
    public:
    
    //Valid Parentheses - https://leetcode.com/problems/valid-parentheses/description/
    bool ValidParentheses(string s){
        stack<char>st;
        for(char c: s){
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else{
                if(st.empty()) return false;
                char st_top = st.top();
                if((c == ')' && st_top == '(') || (c == '}' && st_top == '{' ) || (c == ']' && st_top == '[')) st.pop();
                else return false;
            }
        }
        return st.empty();
    }

    //SUPPORT FUNCTION
    void printVector(vector<int>&a){
        for(int b : a) cout << b << " ";
    }
    string reverse2(string s ){
        string a;
        for(int i = s.length() - 1; i >= 0; i--) a += s[i];
        return a;
    }

    //Remove All Adjacent Duplicates - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
    string RemoveAdjacentDup(string s){
        stack<char>st;
        for(char c : s){
            if(!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }
        string result;
        while(!st.empty()){
            result += st.top();
            st.pop();
    }
    result = reverse2(result);
    return result;
}

    //Baseball game - https://leetcode.com/problems/baseball-game/description/
    int CalPoints(vector<string>&s){
        if(s.size() == 0) return 0;
        stack<int>st;
        for(string c: s){
             if(c == "C"){
                if(!st.empty()){
                    st.pop();
                }
            }
             else if(c == "D"){
                if(!st.empty()){
                int top = st.top();
                st.push(top * 2);
            }
        }
            else if( c == "+"){
                if(st.size() >= 2){
                int first = st.top(); st.pop();
                int second = st.top(); st.push(first);
                st.push(first + second);
            }
        }
            else st.push(stoi(c));
    }
        int total = 0; 
        while(!st.empty()){
            total += st.top();
            st.pop();
        }
        return total;
    }

    //Evaluate Reverse Polish Notation - https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
    int CalsPolishNotation(vector<string>&tokens){
        if(tokens.size() == 0) return 0;
        stack<int>st;
        for(string c : tokens){
            if((c == "+" ) || (c == "-") || (c == "*") || (c == "/")){
                int right = st.top(); st.pop();
                int left = st.top(); st.pop();
                if(c == "+") st.push(left + right);
                else if(c == "-") st.push(left - right);
                else if(c == "*") st.push(left * right);
                else if(c == "/") st.push(left / right);
                }
                else st.push(stoi(c));
            }
            return st.top();
        }
    
        //Backspace String Compare - https://leetcode.com/problems/backspace-string-compare/description/
        string backspace(string s){
            if(s.size() == 0){
                return " ";
            }
            stack<char>st;
            for(char c: s){
                if(c == '#'){
                    st.pop();        
                }
                else st.push(c);
            }
            string result;
            while(!st.empty()){
                result += st.top(); st.pop();
            }
            return reverse2(result);
        }
        bool CheckBackspace(string s, string t){
            return (backspace(s) == backspace(t));
        }

        //Asteroid Collision - https://leetcode.com/problems/asteroid-collision/description/
         vector<int> asteroidCollision(vector<int>& asteroids) {
            vector<int>result;
            if(asteroids.size() == 0) return result;
            stack<int>st;
            for(int c: asteroids){ 
                bool destroyed = false;
                while(!st.empty() && (st.top() > 0 && c < 0 )){
                    if(abs(c) > st.top()) st.pop();
                    else if(abs(c) == st.top()){
                        st.pop();
                        destroyed = true;
                        break;
                    }
                    else {
                        destroyed = true;
                        break;
                    }
                }
                if(!destroyed)
                st.push(c);
            }
            while(!st.empty()){
                result.push_back(st.top()); st.pop();
            }
            reverse(result.begin(),result.end());
        return result;
    }

    //Make The String Great - https://leetcode.com/problems/make-the-string-great/description/
     string makeGood(string s) {
        if(s.size() == 0 ) return " ";
        stack<char>st;
        for(char c: s){
            if(!st.empty() && toupper(st.top()) == toupper(c) && c != st.top() ) st.pop();
            else st.push(c);
        }
        string result;
        while(!st.empty()){ result += st.top(); st.pop();}
        return reverse2(result);
    }


};







int main(){
    Solution sol;
    //cout << boolalpha << sol.ValidParentheses( "([)]");
    //cout << boolalpha << sol.RemoveAdjacentDup( "abbaca");
    vector<string>op = {"5","2","C","D","+"};
    vector<string>tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    //cout << sol.CalPoints(op) << endl;
    //cout << sol.CalsPolishNotation(tokens);
    //cout << boolalpha << sol.CheckBackspace("a#c","b");
    vector<int>asteroids = {8,-8};
    vector<int> result = sol.asteroidCollision(asteroids);
    //sol.printVector(result);
    cout << sol.makeGood("leEeetcode");
}