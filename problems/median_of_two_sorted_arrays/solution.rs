impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        
        let size = nums1.len()+nums2.len();
         
         if size == 0{
            return 0 as f64;
        }

        let mut mean = 0;
        let mut mean_count = 1; 
        let mut mean_idx: Vec<usize> =  Vec::new(); 
        mean_idx.push(size/2);

        if size%2 == 0{
            mean_idx.push(size/2-1);
            mean_count+=1;
        }

        let mut a:usize =0;
        let mut i = 0;
        let mut j = 0;
        let mut smaller;
        let mut remaining : Option<Vec<i32>> = None;
        let mut remaining_idx : Option<usize> = None;

        loop{
            if i == nums1.len(){remaining = Some(nums2); remaining_idx = Some(j);break;}
            if j == nums2.len(){remaining = Some(nums1); remaining_idx = Some(i);break;}
            
            if nums1[i] < nums2[j]{
                smaller = nums1[i];
                i+=1;            
            }
            else{
                smaller = nums2[j];
                j+=1;
                
            }

            if mean_idx.contains(&a){
                mean+=smaller;
                mean_idx.pop();
                if mean_idx.is_empty(){break;}
            }
            
            a+=1;
        }
        
        if !mean_idx.is_empty(){ 
            if let (Some(idx), Some(vector)) = (remaining_idx, remaining) {

                for i in idx..vector.len() {
                    if mean_idx.contains(&a){
                        mean+=vector[i];
                        mean_idx.pop();
                        if mean_idx.is_empty(){break;}
                    }
                    
                    a+=1;
                }
            }

        }

        mean as f64 / mean_count as f64        
    }
}