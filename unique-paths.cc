class Solution {
public:
    int gcd(int a, int b) {
        if(a<b){
            a^=b;
            b^=a;
            a^=b;
        }
        while(b) {
            int c = a%b;
            a = b;
            b = c;
        }
        return a;
    }

    int C(int m, int n) {
         if(m<n){
                m^=n;
                n^=m;
                m^=n;
            }
        if(m - n < n) {
            n = m - n;
        }
        int result = 1;
        for(int i = 1; i <= n; i++) {
            int mult = m;
            int divi = i;
            int g = gcd(mult,divi);
            mult /= g;
            divi /= g;
            result /= divi;
            result *= mult;
            m--;
        }
        return result;
    }
    int uniquePaths(int m, int n) {
       int ret=C(m+n-2,n-1);
    }
};