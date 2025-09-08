class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int i = 1;i < n;i++){
           if(!solve(i) && !solve(n-i)){
                ans.push_back(i);
                ans.push_back(n-i);
                return ans;
           }
        }
        return ans;
    }
    bool solve(int x){
        while(x > 0){
            if(x%10 == 0){
                return true;
            }
            x = x/10;
        }
        return false;
    }
    

};
