class Solution {
    int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}
public:
    bool isHappy(int n) {
      int slow = n , fast = n;
        
        do{
            slow = digitSquareSum( slow);
            fast = digitSquareSum( fast);
            fast = digitSquareSum( fast);
            
        }while(slow != fast);
        if (slow == 1) return 1 ;
            return 0; 
    }
};