class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs: string[]): string[][] {
        const map = strs.reduce((acc,  str) => {
            const charCount = new Array<number>(26).fill(0)
            for (const char of str) {
                charCount[char.charCodeAt(0) - 97]++;
            }
            const key = charCount.join(',');
            const list = acc.get(key) ?? [];
            list.push(str);
            return acc.set(key, list);
        }, new Map<string, string[]>());

        return Array.from(map.values());
    }
}