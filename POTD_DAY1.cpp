class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> pq; //To store the pass,total pairs

        int n = classes.size();

        for(int i=0;i<n;i++)
        {
            int pass = classes[i][0];
            int total = classes[i][1];

            double delta = (double)(pass+1)/(total+1) - (double)(pass)/(total); // To store the difference after adding new student

            pq.push({delta,{pass,total}});
        }

        while(extraStudents--){
           int pass = pq.top().second.first;
           int total = pq.top().second.second;
           pass++; 
           total++; 
           double new_delta = (double)(pass+1)/(total+1) - (double)(pass)/(total);

           pq.pop();
           pq.push({new_delta,{pass,total}});

        }

        double ratio = 0; //to calculate the ratio

        while(!pq.empty()){
            ratio+=(double)(pq.top().second.first)/(pq.top().second.second);

            pq.pop();
        }

        return ratio/n;
    }
};
