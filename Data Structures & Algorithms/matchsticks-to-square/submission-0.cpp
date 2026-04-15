class Solution {
private:
    bool backtrack(vector<int>& matchsticks,int index,int sideLength,vector<int>& sides){
        if(index == matchsticks.size()){
            return true;
        }
        //choose , explore , unchoose
        for(int i=0;i<sides.size();i++){
            if(sides[i] + matchsticks[index] <= sideLength){
                sides[i] += matchsticks[index];
                if(backtrack(matchsticks,index+1,sideLength,sides) == true){
                    return true;
                }
                sides[i] -= matchsticks[index];
            }
            
        }
        return false;
        
    }
    bool isPossible(vector<int>& matchsticks,int sum){
        if(sum % 4 == 0){
            return true;
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int count = 0;
        for(int matchstick : matchsticks){
            count += matchstick;
        }
        if(isPossible(matchsticks,count)){
            int sideLength = count / 4;
            vector<int>sides(4,0);
            return backtrack(matchsticks,0,sideLength,sides);
        }else{
            return false;
        }
        
    }
};