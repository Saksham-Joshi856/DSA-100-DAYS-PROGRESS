class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1]; // descending on second element
        return a[0] < b[0];     // ascending on first element
    });

    int count = 0;
    for(int i = 0;i < n;i++){
        int x1 = points[i][0];
        int y1 = points[i][1];

        int bound = INT_MIN;
        int top = y1;

        for(int j = i + 1; j < n ;j++){
            int x2 = points[j][0];
            int y2 = points[j][1];

            if(y2 <= top && y2>bound){
                count++;
                bound = y2;
                if(y2 == top) top--;
            }
        }
    }
    return count;
    }
};
