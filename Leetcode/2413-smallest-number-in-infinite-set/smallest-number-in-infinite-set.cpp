class SmallestInfiniteSet {
private:
    int current_min;
    set<int> added_back;

public:
    SmallestInfiniteSet() {
        current_min = 1;
    }
    
    int popSmallest() {
        if (!added_back.empty()) {
            int smallest = *added_back.begin(); 
            added_back.erase(added_back.begin()); 
            return smallest;
        }
        

        int smallest = current_min;
        current_min++;
        return smallest;
    }
    
    void addBack(int num) {
        if (num < current_min) {
            added_back.insert(num); 
        }
    }
};
