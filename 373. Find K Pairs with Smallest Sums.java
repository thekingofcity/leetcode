// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84551/simple-Java-O(KlogK)-solution-with-explanation
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> (nums1[a[0]] + nums2[a[1]]) - (nums1[b[0]] + nums2[b[1]]));
        List<List<Integer>> res = new ArrayList<>();
        
        if (nums1.length == 0 || nums2.length == 0 || k == 0)
            return res;
        
        for (int i = 0; i < nums1.length && i < k; i++){
            pq.offer(new int[]{i, 0});
        }
        
        while (k-- > 0 && !pq.isEmpty()){
            int[] cur = pq.poll();
            List<Integer> tmp=new ArrayList<Integer>();
            tmp.add(nums1[cur[0]]);
            tmp.add(nums2[cur[1]]);
            res.add(tmp);
            if (cur[1] == nums2.length - 1) continue; //Dont' add the next index if there is no more left in 2nd array
            pq.offer(new int[]{cur[0], cur[1] + 1});
        }
        
        return res;
    }
}