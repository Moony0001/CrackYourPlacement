class MyCalendarTwo {
public:
    vector<pair<int,int>> sched;
    vector<pair<int,int>> doublebook;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto& db : doublebook){
            if(max(db.first, startTime)<min(db.second, endTime)){
                return false;
            }
        }

        for(auto& sc : sched){
            int maxi = max(sc.first, startTime);
            int mini = min(sc.second, endTime);
            if(maxi<mini){
                doublebook.push_back({maxi, mini});
            }
        }
        sched.push_back({startTime, endTime});

        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */