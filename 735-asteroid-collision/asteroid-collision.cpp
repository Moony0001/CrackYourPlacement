class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        vector<int> ans;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push_back(asteroids[i]);
            }else{
                if(asteroids[i]<0){
                    int flag = 1;
                    while(!st.empty() && st.back()>0){
                        if(st.back()<abs(asteroids[i])){
                            st.pop_back();
                        }else if(st.back()==abs(asteroids[i])){
                            st.pop_back();
                            flag = 0;
                            break;
                        }else{
                            flag = 0;
                            break;
                        }
                    }
                    if(flag){
                        st.push_back(asteroids[i]);
                    }
                }else{
                    st.push_back(asteroids[i]);
                }
            }
        }

        return st;
    }
};