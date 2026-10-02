class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums: number[]): boolean {
        return (new Set<number>(nums).size < nums.length)
    }
}
