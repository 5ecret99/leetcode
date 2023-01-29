use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map : HashMap<i32,i32> = HashMap::with_capacity(nums.len());
        for (i,num) in nums.iter().enumerate(){
            match map.get(num){
                None=>map.insert(target-num, i as i32),
                Some(&index)=>return vec![index, i as i32]
            };
        }

        vec![]
    }
}
