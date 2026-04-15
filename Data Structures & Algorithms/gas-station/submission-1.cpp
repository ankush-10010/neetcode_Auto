class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //gas , cost
        int totalCost = 0;
        int totalGas = 0;
        for(int g:gas){
            totalGas += g;
        }
        for(int c:cost){
            totalCost += c;
        }

        if(totalGas < totalCost){
            return -1;
        }

        int prevGas = 0;
        int currStart = 0;
        for(int i=0;i<gas.size();i++){
            int diff= gas[i] - cost[i];
            prevGas = prevGas + diff;
            if(prevGas<0){
                currStart = i+1;
                prevGas=0;
            }
            
        }      
        return currStart;  
    }
};
