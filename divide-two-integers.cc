//The first method is too slow
class Solution {
public:
    int divide(int dividend, int divisor) {
        int positive=1;
		long long dd=dividend;
        long long div=divisor;
        if(dividend<0){
			positive=0-positive;
			dd=0-dd;
		}
        if(divisor<0){
            positive=0-positive;
			div=0-div;
		}
        long long ret=0;
        while(dd>=div){
            dd-=div;
            ret++;
        }
		if(positive<0)
			ret=0-ret;
        return (int)ret;
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        int positive=1;
		long long dd=dividend;
        long long div=divisor;
        if(dividend<0){
			positive=0-positive;
			dd=0-dd;
		}
        if(divisor<0){
            positive=0-positive;
			div=0-div;
		}
        long long tmp, count,ret=0;
        while (dd >= div) {
            tmp = div;
            count = 1;
            while (tmp + tmp <= dd) {
                tmp += tmp;
                count += count;
            }
            ret += count;
            dd -= tmp;
        }
        if(positive<0)
			ret=0-ret;
        return (int)ret;
    }
};