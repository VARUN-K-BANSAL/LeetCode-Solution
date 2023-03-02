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
    int findMax(MountainArray& ma) {
        int n = ma.length();
        int l = 0, r = n;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int midVal = ma.get(mid);
            int le = mid > 0 ? ma.get(mid - 1) : -1;
            int ri = mid + 1 < n ? ma.get(mid + 1) : -1;
            
            if(le == -1)
                return midVal > ri ? 0 : 1;
            else if(ri == -1)
                return midVal > le ? n - 1 : n - 2;
            else if(midVal > le && midVal < ri)
                l = mid + 1;
            else if(midVal < le && midVal > ri)
                r = mid;
            else if(midVal > le && midVal > ri)
                return mid;
        }
        
        return 0;
    }
    int binary(MountainArray& ma, int l, int r, int target, bool isLeft) {
        while(l < r) {
            int mid = l + (r - l) / 2;
            int midVal = ma.get(mid);
            if(midVal < target) {
                if(isLeft)
                    l = mid + 1;
                else
                    r = mid;
            } else if (midVal > target) {
                if(isLeft)
                    r = mid;
                else
                    l = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &ma) {
        int maxInd = findMax(ma);
        int foundInLeft = binary(ma, 0, maxInd + 1, target, true);
        return (foundInLeft == -1) ? binary(ma, maxInd, ma.length(), target, false) : foundInLeft;
    }
};