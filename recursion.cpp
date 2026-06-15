#include <iostream>
#include <vector>
#include <string>
#include <cstdint> //for bit maniputation
using namespace std;

class Solution{
    private:
     double fastPow(double x, long long n) {
        if(n == 0) return 1.0;
        if(n == 1) return x;
        double half = fastPow(x, n / 2);
        if(n % 2 == 0) return half * half;
        else return half * half * x;
     }
      void helper(vector<char>&s, int left, int right){
        if(left >= right) return;
        swap(s[left], s[right]);
        helper(s, left + 1, right - 1);
      }

      bool helper2(string s, int left, int right){
        while(left && !isalnum(s[left])) left++;
        while(right && !isalnum(s[right])) right--;
        if(left >= right) return true;
        if(tolower(s[left]) != tolower(s[right])) return false;
        return helper2(s,left+1,right-1);
      }

       void moveDisks(int n, vector<int>& start, vector<int>& mid, vector<int>&end){
        if(n == 1){
            end.push_back(start.back());
            start.pop_back();
            return;
        }
        moveDisks(n - 1, start, end, mid);
        end.push_back(start.back());
        start.pop_back();
        moveDisks(n - 1,mid,start,end);

    }
    public:
     vector<int>memo;
    Solution(){
        memo.assign(100000,-1);
    };
    //Power of Two -https://leetcode.com/problems/power-of-two/description/

    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        if(n % 2 != 0) return false;
        return isPowerOfTwo(n / 2);   
    }

    //Fibonacci Number - https://leetcode.com/problems/fibonacci-number/description/
    int fib(int n) {
        if((n == 0) || (n == 1)) return n;
        return fib(n - 1) + fib(n - 2);   
    }
        
    //Climbing Stairs - https://leetcode.com/problems/climbing-stairs/description/
     
   int climbStairs(int n) {
       // memoization array
        if((n == 1) || (n == 2)) return n;
        if(memo[n] != - 1) return memo[n];
        memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return memo[n];
    }

    //N-th Tribonacci Number
    int tribonacci(int n) {
        if(n == 0 || n == 1) return n;
        if(n == 2) return 1;
        if(memo[n] != -1) return memo[n];
        memo[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return memo[n];
    }

    //Pow(x, n) - https://leetcode.com/problems/powx-n/description/ 
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0){
            x = 1 / x;
            N = -N;
        }      
        return fastPow(x,N); 
    }

     void reverseString(vector<char>& s) {
        helper(s,0,s.size() - 1);
     }

      bool isPalindrome(string s) {
        return helper2(s, 0, s.length() - 1);
    }

    //Ugly Number - https://leetcode.com/problems/ugly-number/description/
    bool isUgly(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        if(n % 2 == 0) return isUgly(n/2);
        if(n % 3 == 0) return isUgly(n/3);   
        if(n % 5 == 0) return isUgly(n/5);
        return false;      
    }

    //Number of 1 Bits - https://leetcode.com/problems/number-of-1-bits/
    int hammingWeight(uint32_t n) {
        if(n == 0) return 0;
        return (n & 1) + hammingWeight(n >> 1);    
    }

    //Tower of Hanoi
     void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        moveDisks(A.size(), A, B, C);
     }

     //Pascal's Triangle - https://leetcode.com/problems/pascals-triangle/description/
      vector<vector<int>> generate(int numRows) {
        if(numRows < 0 ) return {{}};
        if(numRows == 1) return {{1}};
        vector<vector<int>> result = generate(numRows - 1);
        vector<int> prevRow = result.back();
        vector<int> newRow;
        newRow.push_back(1);
        for(int i = 1; i < prevRow.size(); i++){
            newRow.push_back(prevRow[i - 1] + prevRow[i]);
        }
        newRow.push_back(1);
        result.push_back(newRow);
        return result;
      }  
};

  //Test for Tower of Hanoi
     void print(const string& name, const vector<int>& v) {
    cout << name << ": ";
    for (int x : v) cout << x << " ";
    cout << endl;
     }

int main(){
    Solution sol;
    //cout << boolalpha << sol.isPowerOfTwo(16) << endl;
   // cout << boolalpha << sol.isPowerOfTwo(3);
    //cout << sol.fib(5) << endl;
    /*
    vector<char> s = {'h','e','l','l','o'};
    sol.reverseString(s);
    for(char c : s) cout << c << " ";  
    */
   //cout << boolalpha << sol.isPalindrome("amanaplanacanalpanama") << endl;
   //cout << sol.hammingWeight(2147483645);
    vector<int> A = {2, 1, 0};
    vector<int> B, C;
    cout << "Before:\n"; print("A", A); print("B", B); print("C", C);
    sol.hanota(A, B, C);
    cout << "\nAfter:\n"; print("A", A); print("B", B); print("C", C);
}