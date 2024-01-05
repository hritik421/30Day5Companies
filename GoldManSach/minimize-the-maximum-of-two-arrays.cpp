class Solution {
public:
    int minimizeSet(int d1, int d2, int uniqueCnt1, int uniqueCnt2) {
        // Brute force approach
        long int low = uniqueCnt1 + uniqueCnt2;
        long int high = INT_MAX;
        long long int LCM = ((long long)d1*d2)/__gcd(d1,d2);
        while(low<=high){
            int mid = low + (high-low)/2;
            int notD1 = mid - mid/d1; // not divisble by d1
            int notD2 = mid - mid/d2; // not divisble by d2
            int notBoth = mid - mid/LCM; // not divisble by both
            if(notD1>=uniqueCnt1 && notD2>=uniqueCnt2 && notBoth>=(uniqueCnt1+uniqueCnt2)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
