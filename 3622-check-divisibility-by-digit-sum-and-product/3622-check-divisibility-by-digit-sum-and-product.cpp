class Solution {
public:
    bool checkDivisibility(int n) {
        long long prod = 1;
        long long sum = 0;
        long long orig = n;
        while(n!=0){
            sum+=n%10;
            prod*=n%10;
            n/=10;
        }
        long long res = prod+sum;
        if(orig%res==0) return true;
        else return false;
    }
};