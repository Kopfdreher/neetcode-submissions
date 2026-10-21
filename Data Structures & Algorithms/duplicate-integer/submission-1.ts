class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums: number[]): boolean {
      const set = new Set<number>(nums);
      return set.size < nums.length;
    }
}