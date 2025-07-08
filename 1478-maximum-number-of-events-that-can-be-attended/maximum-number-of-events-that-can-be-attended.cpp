class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());

        int n = events.size();
        int pos = 0;
        int time = 1;
        int attended = 0;
        priority_queue<int,vector<int>,greater<int>> minheap;
        while(pos<n or !minheap.empty()){
            //Time skip: to cover only timeline covered by atleast one event
            if(minheap.empty())
                time = max(time,events[pos][0]);
            
            //Add events starting at current pos
            while(pos<n and events[pos][0]==time){
                minheap.push(events[pos][1]);
                pos++;
            }
            
            //Remove all already ended (unattended) events
            while(!minheap.empty() and minheap.top()<time)
                minheap.pop();
            
            //Pop 1 event at current time
            if(!minheap.empty()){
                minheap.pop();
                attended++;
            }
            time++;
        }
        return attended;
    }
};
