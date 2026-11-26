class Solution {
public:
    bool canAliceWin(int n) {
        int s = 10;
        int moves = 0;
        while(n>0){
            n-=s;
            s--;
            if(n>=0) moves++;
        }
        return (moves&1) ? true : false;
    }
};