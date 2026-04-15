class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // what does it make a greedy question?
        if(hand.size() % groupSize != 0){
            return false;
        }
        int numberOfGroups = hand.size()/groupSize;
        map<int,int> handfreqs;
        for(int i=0;i<hand.size();i++){
            int curr = hand[i];
            handfreqs[curr]++;
        }
        // we wont have to first sort the hand first , as map will do it itself
        // now choose the smallest element from map,
        // iterate through it , find X,X+1,X+2...X+grpszie-1 , reduce freq--

        while(!handfreqs.empty()){
            int X = handfreqs.begin()->first;
            int Xfreq = handfreqs.begin()->second;
            if(Xfreq == 0){
                handfreqs.erase(X);
            }
            for(int i=X;i<X+groupSize;i++){
                if(handfreqs.find(i) == handfreqs.end()){
                    return false;
                }
                handfreqs[i]--;
                if(handfreqs[i]==0){
                    handfreqs.erase(i);
                }
            }
        }
        return true;
    }
};
