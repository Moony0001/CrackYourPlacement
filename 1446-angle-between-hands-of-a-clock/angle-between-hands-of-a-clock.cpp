class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12){
            hour = 0;
        }

        double angleh = hour*30+0.5*minutes;
        double anglem = (minutes/60.0)*360.0;

        double angle1 = abs(anglem-angleh);
        double angle2 = 360.0-angle1;

        double ans = min(angle1, angle2);
        return ans;
    }
};