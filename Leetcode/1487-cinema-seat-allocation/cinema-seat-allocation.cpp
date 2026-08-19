class Solution {
public:
    vector<int> is_available(int row,vector<vector<int>>& reservedSeats){
        sort(reservedSeats.begin(),reservedSeats.end());
        unordered_map<int,int> mp;
        for(int i=0;i<reservedSeats.size();i++){
            if(reservedSeats[i][0] < row){
                continue;
            }
            if(reservedSeats[i][0] > row){
                break;
            }
            if(reservedSeats[i][0] == row){
                mp[reservedSeats[i][1]]++;
            }
        }
        vector<int> result(3,-1);
        bool is1 = true;
        bool is2 = true;
        bool is3 = true;
        for(int i=2;i<6;i++){
            if(mp.find(i) != mp.end()){
                is1 = false;
                break;
            }
        }
        for(int i=4;i<8;i++){
            if(mp.find(i) != mp.end()){
                is2= false;
                break;
            }
        }
        for(int i=6;i<10;i++){
            if(mp.find(i) != mp.end()){
                is3 = false;
                break;
            }
        }

        if(is1) result[0] = 1;
        if(is2) result[1] = 2;
        if(is3) result[2] = 3;
        // basically is result[i] == -1 then i+1th group is not available
        return result;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // n rows , each row --> 10 seat
        int count = n*2;
        unordered_map<int,vector<bool>> ruinedBlocks;
        for(auto& res : reservedSeats){
            int row = res[0];
            int seat = res[1];
            if(ruinedBlocks.find(row) == ruinedBlocks.end()){
                ruinedBlocks[row] = {false,false,false};
            }
            if(seat == 2 || seat == 3) ruinedBlocks[row][0] = true;
            else if(seat == 4 || seat == 5) {
                ruinedBlocks[row][0] = true;
                ruinedBlocks[row][1] = true;
            }
            else if(seat == 6 || seat == 7){
                ruinedBlocks[row][1] = true;
                ruinedBlocks[row][2] = true;
            }else if(seat == 8 || seat == 9){
                ruinedBlocks[row][2] = true;
            }else if(seat == 1 || seat == 10){
                // do nothing
            }
        }
        for(const auto& entry : ruinedBlocks){
            const vector<bool>& blocks = entry.second;            
            count -= 2; 
            bool leftAvailable = !blocks[0];
            bool midAvailable = !blocks[1];
            bool rightAvailable = !blocks[2];

            if (leftAvailable && rightAvailable) {
                count += 2;
            } 
            else if (leftAvailable || midAvailable || rightAvailable) {
                count += 1;
            }
        }

        return count;
    }
};