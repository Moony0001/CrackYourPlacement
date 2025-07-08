class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = events.size();
        sort(events.begin(), events.end()); // sort the events by their first element
        int i = 0, res = 0, d = 0;   //initialise a pointer, the varible to store the result in, the current day
        while(pq.size()>0 || i<n){  //while the max heap contains an element or the events array is still left to be traversed, we enter the loop
            if(pq.size()==0)    // if the max heap is empty and we entered the while loop that means the events array has not been traversed completely so we set the current day to be the first day of the current event that i is pointing to.
                d = events[i][0];
            while(i<n && events[i][0]<=d)   // here we push all the ending times of the events that started today or before today into pq.
                pq.push(events[i++][1]);
            pq.pop();   // now we pop the first element of the pq as we can attend it obviously and we increase the day by 1 and the count by 1;
            ++res, ++d;
            while(pq.size()>0 && pq.top()<d)    // we remove any elements that cannot be attended anymore as their last day was before today's current day.
                pq.pop();
        }
        return res;
    }
};