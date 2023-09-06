import java.util.HashMap;

class Solution {

    public boolean uniqueOccurrences(int[] arr) {
        int n = arr.length;
        HashMap<Integer, Integer> hm = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            hm.put(arr[i], hm.getOrDefault(arr[i], 0) + 1);
        }

        HashMap<Integer, Integer> hm2 = new HashMap<>();

        for (int freq : hm.values()) {
            if (hm2.containsKey(freq)) {
                return false;
            }
            hm2.put(freq, 1);
        }

        return true;
    }
}
