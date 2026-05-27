class MyCalendar {
public:
    map<int, int> sched;

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto nextmeet = sched.lower_bound(startTime);
        if(nextmeet!=sched.end() && nextmeet->first<endTime){
            return false;
        }

        if(nextmeet!=sched.begin()){
            auto prevmeet = prev(nextmeet);
            if(prevmeet->second >startTime){
                return false;
            }
        }

        sched[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */