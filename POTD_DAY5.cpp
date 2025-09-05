class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        for(long k = 1;k <= 60;k++){
            long target = num1 - (num2*k); //Aim of the problem

            if(target < k){
                break; // if target can't be represented in 2^0
            }

         int setBits = std::popcount(static_cast<unsigned long long>(target));

            if(setBits <= k){
                return (int)k; //if yes
            }

        }

        return -1; //if the num1 is not at all possible to make zero
    }
};
