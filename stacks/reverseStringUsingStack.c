--------------reverse string using Stack- normal way
1) pushing onto top
2) popping from top

time complexity : O(n)-- looping over items n times to push and pop since inserting an elem in stack is O(1)
space complexity : O(n)-- looping n characters so extra space required is n

--------------reverse string normally---

taking two pointers - ptr = first elem , ptr2 = last elem
                      while ptr<ptr2
                        swap ptr->data and ptr2->data

time complexity : O(n)
space complexity : O(1) since no extra space is required
preferred when input is large
