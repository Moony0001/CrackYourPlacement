class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int numb = 0;
        int numa = 0;
        int numl = 0;
        int numo = 0;
        int numn = 0;

        for(char c : text){
            if(c=='b'){
                numb++;
            }else if(c=='a'){
                numa++;
            }else if(c=='l'){
                numl++;
            }else if(c=='o'){
                numo++;
            }else if(c=='n'){
                numn++;
            }
        }
        numo = numo/2;
        numl = numl/2;
        int ans = min({numb, numa, numl, numo, numn});
        return ans;
    }
};