// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut remainder =0;
        let mut cur_l1 = l1;
        let mut cur_l2 = l2;
        let mut head = Some(Box::new(ListNode::new(0)));
        let mut current =head.as_mut();

        while(cur_l1.is_some() || cur_l2.is_some()){
            let mut sum = remainder;

            if let Some(node) = cur_l1{
                sum+=node.val;
                cur_l1=node.next;
            }
            
            if let Some(node)=cur_l2{
                sum+=node.val;
                cur_l2=node.next;
            }
            
            remainder=sum/10;

            if let Some(node)=current{
                node.next=Some(Box::new(ListNode::new(sum%10)));
                current=node.next.as_mut();
            }
        }

        if remainder > 0
            {
                current.unwrap().next = Some(Box::new(ListNode::new(remainder)));
            }

        head.unwrap().next
    }
}
