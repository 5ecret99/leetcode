use std::cmp;
use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut max = 0;
        let mut start = 0;
        let mut pos: [usize;128] = [0;128];
        
        for(end,c) in s.char_indices(){
            start = start.max(pos[c as usize]);
            max=max.max(end-start+1);
            pos[c as usize]=end+1;
        }

        max as i32
    }
}
