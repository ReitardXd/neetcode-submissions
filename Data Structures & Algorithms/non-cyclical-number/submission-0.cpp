class Solution {
public:
    bool isHappy(int n) {
    int slow = n; int fast = Sumofsquares(n);
    while(fast!=slow) { 
        fast= Sumofsquares(fast); 
        
        fast= Sumofsquares(fast); 
        slow = Sumofsquares(slow);
    } 
    return fast == 1;
    } 
    private:
    int Sumofsquares(int n) {
        int output = 0;
        while (n != 0) {
            output += (n % 10) * (n % 10);
            n /= 10;
        }
        return output;
    }
};