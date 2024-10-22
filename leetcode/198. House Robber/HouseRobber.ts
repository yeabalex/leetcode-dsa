function rob(nums: number[]): number {
    if(nums.length<3){
        return Math.max(...nums)
    }
    const maxRobArray: number[] = [nums[0], nums[1], nums[2]+nums[0]]
    let max: number = Math.max(...maxRobArray)

    if(nums.length===3){
        return max
    }
    
    for(let i=3; i<nums.length; i++){
        let subArray: number[] = maxRobArray.slice(0,i-1)
        let temp:number = nums[i]+Math.max(...subArray);
        maxRobArray.push(temp)
        max=Math.max(max,temp)
    }
    return max
};