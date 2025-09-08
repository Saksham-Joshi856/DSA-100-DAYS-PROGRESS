class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;

        for(auto it:queries){
            long long steps = solve(it[0],it[1]);
            ans+=(steps + 1)/2;
        }

        return ans;
    }

    long long solve(int l,int r){
        long long sum = 0;
        long long low = 1;
        long long k = 1;

        while(k > 0){
            if(low > r) break;

            long long high = 4*low - 1;
            long long start = max((long long)l,low);
            long long end = min((long long)r,high);

            if(start <= end){
                sum+=(end-start+1)*k;

            }
            k++;
            low*=4;

        }

        return sum;
    }
};
