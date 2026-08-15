class Solution {
public:
    double myPow(double x, int n) {
        long long N= n;
        if(n < 0){
            x = 1/x;
            N = -N;
        }
       if(N == 0){
        return 1;
       } 
       double halfPow = myPow(x,N/2);
       double halfPowSquare = halfPow * halfPow;
       if(N % 2 != 0){
        return x * halfPowSquare;
       }
       else{
        return halfPowSquare;
       }
    }
};