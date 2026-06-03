#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution{
    public:
    //FRIST UNIQUE CHAR OF A STRING
    int FirstUniqueChar(string s ){
        int count[26] = {0};
        for(char c: s){
            count[c - 'a']++;
        }
       for(int i = 0; i < s.length(); i++){
        if(count[s[i] - 'a'] == 1) return i;
       }
       
        return -1;

    }
    bool ValidAnagram(string s, string t){
        int count[26] = {0};
        for(char c: s){
            count[c - 'a']++;
        }
        for(char c: t){
            count[c - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(count[i] != 0) return false;
        }
        return true;
    }
 char FindtheDifference(string s, string t){
        char result = 0;
        for(char c: s) result ^= c;
        for(char c: t) result ^= c;
        return result;
    }

    int JewelsAndStones(string j, string s){
        vector<bool> found = {false};
        int count = 0;
        for(char c: j){
            found[c] = true; 
        }
        for(char c: s){
            if(found[c] == true) count++;
        }
        return count;

    }
    bool CheckPanagram(string s){
        int count[26] = {0};
        for(char c: s){
            count[c - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(count[i] == 0) return false;
        }
        return true;
    }
    int FirstOccurence(string haystack, string needle){
        int n = haystack.length();
        int m = needle.length();
        if(m == 0) return -1;
        if(m > n ) return -1;
        for(int i = 0; i <= n - m; i++){
            bool found = true;
            for(int j = 0; j < m; j++){
                if(haystack[i + j] != needle[j]){
                    found = false;
                    break;
                }
            }
                if(found) return i;
            
        }
        return -1;
        
    }
    int LengthOfLastWord(string s){
        int n = s.length();
        int count = 0;
        int i = n - 1;
        while(i > 0 && s[i] == ' '){
            i--;
        }
        while(i > 0 && s[i] != ' '){
            count++;
            i--;
        }
        return count;
    }

    string ReverseWords(string s){
        int n = s.length();
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss >> word){
            words.push_back(word);
        }
        reverse(words.begin(),words.end());
        string result;
        for(auto c: words){
            if(!result.empty()) result += ' ';
            result += c;
        }
        return result;
    }

    string SortSentence(string s){
        stringstream ss(s);
        string word;
        vector<string>words(100);

        while(ss >> word){
            int k = word.length();
         int index = word.back() - '0';
          words[index] = word.substr(0,k - 1);
        }
        string result;
        for(int i = 0; i <= 9; i++){
            if(!words[i].empty()){
                if(!result.empty()) result += ' ';
                result += words[i];
            }
        }
        return result;
    }

    int DistinctSubstring(string s){
        int n = s.length();
        int m = 3;
        if(n < 3) return 0;
        int count = 0;
        for(int i = 0; i <= n - m; i++){
            unordered_set<char> window;
            window.insert(s[i]);
            window.insert(s[i + 1]);
            window.insert(s[i + 2]);
            if(window.size() == 3) count++; 

        }
        return count;
    }
    
};


int main(){
    Solution sol;
    //cout << sol.FirstUniqueChar("leetcode");
    //cout << sol.ValidAnagram("rat","car");
    //cout << sol.FindtheDifference("abcd","abcde");
    //cout << sol.JewelsAndStones("aA","aAAbbbb");
    //cout << boolalpha << sol.CheckPanagram("leetcode");
    //cout << sol.FirstOccurence("leetcode","leeto");
    //cout << sol.LengthOfLastWord("   fly me   to   the moon  ");
    //cout << sol.ReverseWords("the sky is blue");
    //cout << sol.SortSentence("is2 sentence4 This1 a3");
    cout << sol.DistinctSubstring("aababcabc");
    return 0;
}