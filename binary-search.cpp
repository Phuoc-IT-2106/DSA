#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution{
    public:
    //BASIC BS
     int searchBS(vector<int>& nums, int target) {
        int left = 0; int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1; //NOT FOUND
    }

    //Search Insert Position - https://leetcode.com/problems/search-insert-position/description/
    int searchInsert(vector<int>& nums, int target) {
        int left = 0; int right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid+1;
            else right = mid;
        }
        return left;
    }

    //Find First and Last Position of Element in Sorted Array - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
     int lowerbound(vector<int>& nums, int target) {
        int left = 0; int right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid+1;
            else right = mid;
        }
        return left;
    }
     int upperbound(vector<int>&nums, int target){
       int left = 0; int right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target) left = mid+1;
            else right = mid;
        }
        return left;  
     }

      vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = lowerbound(nums,target);
        if((first == n) || nums[first] != target) return {-1,-1};
        int last = upperbound(nums,target) - 1;
        return{first,last};  
    }

    //Sqrt(x) - https://leetcode.com/problems/sqrtx/description/
    int mySqrt(int x) {
        int left = 0; int right = x; int temp = 0;
        while(left <= right){
            int mid = left + (right - left)/ 2;
            if(mid <= x / mid) {
                temp = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return temp;
}

    // Find Minimum in Rotated Sorted Array - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/    
     int findMin(vector<int>& nums) {
        int left = 0; int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
        
    }
    
    //Search in Rotated Sorted Array - https://leetcode.com/problems/search-in-rotated-sorted-array/description/
     int search(vector<int>& nums, int target) {
        int left = 0; int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[left] <= nums[mid]){
                if(target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else{
                if(target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }       
        return -1;
    }

    //https://leetcode.com/problems/peak-index-in-a-mountain-array/
     int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0; int right = arr.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(arr[mid] < arr[mid + 1]){
                left = mid + 1;
            }
            else right = mid;
        }
        return left;
    }

    //Search a 2D Matrix - https://leetcode.com/problems/search-a-2d-matrix/description/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = n * m - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int row = mid /m;
            int col = mid % m;
            int val = matrix[row][col];
            if(val == target) return true;
            else if(val < target) left = mid+1;
            else right = mid - 1;
        }
        return false;       
    }

    //Koko Eating Bananas - https://leetcode.com/problems/koko-eating-bananas/description/
    bool CanEatAll(vector<int>&piles,int speed, int h){
        long long totalHours = 0;
        for(int pile : piles){
           totalHours +=  (pile + speed - 1LL) / speed;
           if(totalHours > h) return false;
        }
        if(totalHours <= h) return true;
    } 
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(CanEatAll(piles,mid,h)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }

    //Capacity To Ship Packages Within D Days - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        int ans = 0;
        for(int w: weights) right += w;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(canShip(weights,mid,days)){
                ans = mid;

                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }

    bool canShip(vector<int>& weights, int capacity, int days){
        int daysNeeded = 1;
        int currentLoad = 0;
        for(int w: weights){
            if(currentLoad + w > capacity){
                currentLoad = w;
                daysNeeded++;
            }
            else{
                currentLoad += w;
            }
        }
        if(daysNeeded > days) return false;
        return daysNeeded <= days;
    }

    //Single Element in a Sorted Array - https://leetcode.com/problems/single-element-in-a-sorted-array/description/
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(mid % 2 == 1) mid--;
            if(nums[mid] == nums[mid+1]) left = mid + 2;
            else right = mid;
        }
        return nums[left];
    }

    //Kth Missing Positive Number - https://leetcode.com/problems/kth-missing-positive-number/
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        int number_of_missing = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            number_of_missing = arr[mid] - (mid + 1);
            if(number_of_missing < k) left = mid + 1;
            else right = mid - 1;
        }
        return left + k;
    }
};

int main(){
    Solution* p = new Solution;
    vector<int> nums = {5,7,7,8,8,10};
    //cout << p->search(nums,8) << endl;
    cout << p->mySqrt(8) << endl;
    vector<int>arr = {4,5,6,7,0,1,2};
    cout << p->findMin(arr) << endl;
    vector<int>weights = {1,2,3,4,5,6,7,8,9,10};
     int days = 5;
    cout << p->shipWithinDays(weights,days) << endl;
}