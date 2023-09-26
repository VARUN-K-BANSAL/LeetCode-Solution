import java.util.Random;

class RandomizedSet {
    ArrayList<Integer> nums;
    HashMap<Integer, Integer> hm;
    Random rand;

    public RandomizedSet() {
        nums = new ArrayList<>();
        hm = new HashMap<>();
        rand = new Random();
    }
    
    public boolean insert(int val) {
        if(hm.containsKey(val)) return false;
        hm.put(val, nums.size());
        nums.add(val);
        return true;
    }
    
    public boolean remove(int val) {
        if(!hm.containsKey(val)) return false;
        
        int loc = hm.get(val);
        if(loc < nums.size() - 1) {
            int last = nums.get(nums.size() - 1);
            hm.put(last, loc);
            nums.set(loc, last);
        }
        
        hm.remove(val);
        nums.remove(nums.size() - 1);
        return true;
    }
    
    public int getRandom() {
        return nums.get(rand.nextInt(nums.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */