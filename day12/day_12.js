/**
 * @param {number[]} nums
 * @return {number[][]}
 * 
 * approach 1: using sort & two pointers
 * time complexity: O(n^2)
 * space: O(1)
 */
var threeSum = function(arr) {
    let n = arr.length;

    arr.sort((a,b) => a-b);
    const ans = [];

    for(let i = 0; i<n; i++){
        if(arr[i] > 0) break;
        if(i>0 && arr[i] == arr[i-1]) continue;

        let l = i+1, r = n-1;
        while(l<r){
            let sum = arr[i] + arr[l]+arr[r];
            if(sum > 0) {
                r--;
            }else if(sum < 0){
                l++;
            }else{
                ans.push([arr[i], arr[l], arr[r]]);
                let low = arr[l], high = arr[r];
                while(l<r && arr[l] == low){
                    l++;
                }
                while(r>l && arr[r] == high){
                    r--;
                }
            }
        }
    }
    return ans;
};

/**
 * @param {number[]} nums
 * @return {number[][]}
 * 
 * approach 2: using sort & map
 * time complexity: O(n^2)
 * space: O(n)
 */
var threeSum = function(arr) {
    let n = arr.length;

    arr.sort((a,b) => a-b);
    const ans = [];
    const map = new Map();

    for(let i = 0; i<n; i++){
        map.set(arr[i], i);
    }

    for(let i = 0; i<n; i++){
        if(arr[i] > 0) break;
        for(let j = i+1; j<n; j++){
            let target = 0 - (arr[i]+arr[j]);
            if(map.has(target) && map.get(target) > j){
                ans.push([arr[i], arr[j], target]);
            }

            j = map.get(arr[j]);
        }
        i = map.get(arr[i]);
    }
    return ans;
};