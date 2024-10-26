/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {

    if(nums.length===1){
        return false
    }
    const unique = new Set(nums);
    const arr = Array.from(unique);

    return !(arr.length===nums.length);
};