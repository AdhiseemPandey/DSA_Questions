class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        //pop => population
     vector<int> pop(101,0);
     for( auto it : logs ){
        pop[it[0] - 1950]++;
        pop[it[1] - 1950]--;
     }

    int ans = 0 , mx = pop[0];

    for(int i = 1 ; i <= 100 ; i++ ){
        pop[i] += pop[i-1];
        if(pop[i] > mx){
            mx = pop[i];
            ans = i ; 
        }
    }
    return (ans + 1950);

    }
};