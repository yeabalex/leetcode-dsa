#include <vector>
class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr = {1,1};

        while(n-1>0){
            arr.push_back(arr[arr.size()-1]+arr[arr.size()-2]);
            n--;    
        }

        return arr[arr.size()-1];
    }
};