class Solution {
  /**
   * @param {number[]} nums
   * @return {boolean}
   */
  hasDuplicate(nums) {
    const a = new Set(nums);
    return a.size < nums.length;
  }
}
