class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n,0); //array with all ele zero

        int low = 0; //start pt of array
        int high = n - 1; //end pt of array
        int num = 1; // ele to be filled

        while(low < high){
            ans[low] = num;
            ans[high] = -num;
            low++;
            num++;
            high--;
        }

        return ans;

        
    }
};
