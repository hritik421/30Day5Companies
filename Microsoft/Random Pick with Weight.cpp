// You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

// You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

// For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).


class Solution {
public:
    vector<int> cumSum;
    Solution(vector<int>& w) {
        for(int i:w){
            if(cumSum.empty()) cumSum.push_back(i);
            else cumSum.push_back(i+cumSum.back());
        }
    }
    
    int pickIndex() {
        int randomNum = rand()%cumSum.back() + 1;
        int num = lower_bound(cumSum.begin(),cumSum.end(),randomNum) - cumSum.begin();
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
