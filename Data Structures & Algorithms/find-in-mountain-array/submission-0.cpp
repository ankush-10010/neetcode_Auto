/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        if(mountainArr.length() < 3){
            return -1;
        }
        int n = mountainArr.length();
        int left = 0;
        int right = n-1;

        while(left < right){
            int mid = left + (right - left)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        int peakIndex = left;
        int l=0;
        int r = peakIndex;
        while(l<=r){
            int mid = l + (r-l)/2;
            int midVal = mountainArr.get(mid);

            if(midVal == target){
                return mid;
            }
            if(midVal > target){
                r = mid - 1;
            }else{
                l = mid+1;
            }
        }

        l = peakIndex + 1;
        r = n-1;

        while(l<=r){
            int mid = l + (r-l)/2;

            int midVal = mountainArr.get(mid);
            if(midVal == target){
                return mid;
            }

            if(midVal > target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }
};