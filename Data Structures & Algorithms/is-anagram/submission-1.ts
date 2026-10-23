class Solution {
  /**
   * @param {string} s
   * @param {string} t
   * @return {boolean}
   */
  isAnagram(s: string, t: string): boolean {
    if (s.length != t.length) return false;
    const hash = new Array<number>(26).fill(0);
    for (let i: number = 0; i < s.length; i++) {
      hash[s.charCodeAt(i) - 97]++;
      hash[t.charCodeAt(i) - 97]--;
    }
    return hash.every((count) => count === 0);
  }
}
