#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Number of Recent Calls - https://leetcode.com/problems/number-of-recent-calls/description/
class RecentCounter {
    private:
    queue<int>q;
public:
    RecentCounter() {      
    }
    
    int ping(int t) {
        q.push(t);
        while(q.front() < t - 3000) q.pop();
        return q.size();
    }
};

//Number of Students Unable to Eat Lunch - https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        for(int c: students) q.push(c);
        int i = 0; //The index of sandwiches
        int attempts = 0; //Number of students skip sandwiches consecutively
        while(!q.empty() && attempts < q.size()){
            if(q.front() == sandwiches[i]){
                q.pop();
                i++;
                attempts = 0;
            }
            else{
                int front = q.front();
                q.pop();
                q.push(front);
                attempts++;
            }
        }
        return q.size();
    }

    //Time Needed to Buy Tickets - https://leetcode.com/problems/time-needed-to-buy-tickets/description/
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q; //Index of the customers
        int n = tickets.size();
        int steps = 0;
        for(int i = 0; i < tickets.size(); i++) q.push(i);
        while(true){
            int idx = q.front();
            q.pop();
            tickets[idx]--;
            steps++;
            if(idx == k && tickets[idx] == 0) break;
            if(tickets[idx] > 0) q.push(idx);
        }
        return steps;
        
    }

    //Find the Winner of the Circular Game- https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
     int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; i++) q.push(i);
        while(q.size() > 1){
            for(int i = 1; i <= k - 1; i++){
                int idx = q.front();
                q.pop();
                q.push(idx);
            }
            q.pop();
        }
        return q.front();
    }

    //Reveal Cards In Increasing Order - https://leetcode.com/problems/reveal-cards-in-increasing-order/description/
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int>q;
        for(int i = 0; i < deck.size(); i++)q.push(i);
        vector<int>result(deck.size());
        for(int card : deck){
            int idx = q.front();
            q.pop();
            result[idx] = card;
            if(!q.empty()){
            int nextcard_idx = q.front();
            q.pop();
            q.push(nextcard_idx);
        }
    }
    return result;
}

    //Dota2 Senate - 
    string predictPartyVictory(string senate) {
        queue<int>qR,qD;
        for(int i = 0; i < senate.length(); i++){
            if (senate[i]== 'R') qR.push(i);
            else qD.push(i); 
        }
        int n = senate.length();
        while(!qR.empty() && !qD.empty()){
            int r = qR.front();
            int d = qD.front();
              qR.pop(); qD.pop();
            if(r < d){
              
                qR.push(r + n);
            }
            else{
                qD.push(d + n);
            }
        }
        if(qR.empty()) return "Dire";
        else return "Radiant";
    }
};

int main(){
    //RecentCounter* p = new RecentCounter();
    //cout << p->ping(1) << endl;
    /*cout << p->ping(100) << endl;
    cout << p->ping(3001) << endl;
    cout << p->ping(3002) << endl;*/
    Solution sol;
    vector<int> students = {1,1,1,0,0,1}, sandwiches = {1,0,0,0,1,1}, tickets = {5,1,1,1}, deck = {17,13,11,2,3,5,7};
    //cout << sol.countStudents(students,sandwiches);
    //cout << sol.timeRequiredToBuy(tickets,0);
    //cout << sol.findTheWinner(6,5);
    vector<int> result = sol.deckRevealedIncreasing(deck);
    for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
}