var topKFrequent = function(nums, k) {
    const countMap = new Map();
    const result = [];

    for (const num of nums) {
        countMap.set(num, (countMap.get(num) || 0) + 1);
    }

    const frequencyArray = Array.from(countMap.entries());
    frequencyArray.sort((a, b) => b[1] - a[1]);

    for (let i = 0; i < k; i++) {
        result.push(frequencyArray[i][0]);
    }

    return result;    
};
