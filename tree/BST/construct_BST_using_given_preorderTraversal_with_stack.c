
Algorithm:
    1.Create an empty stack;
    & Push root
    2.while stack is not empty and curr > top element
    keep popping the elements;
    3.As the stack becomes empty or curr becomes < top element,
    Last popped elem --->rightsubtree = curr; //so wait for that last max elem to whose right curr wants to attach
    4.Push curr in stack as well
    5.If curr < top elem, make top -->left subtree = curr and also push curr in stack

/*---------------------------------------------------------------------------------------------------------------*/
preorder list :  10 5 1 7 40 50

Pass1-----
10 is pushed in stack
Stack - {10}

Pass2-----
since 5 < 10(top element)
10->left = 5 and push 5 in stack
Stack - {10, 5}

Pass3----
since 1 < 5(top)
5->left = 1 and push 1 to stack
Stack - {10, 5, 1}

Pass4----
now 7 > 1
pop 1
Stack - {10, 5}
now again 7 > 5
pop
Stack - {10}
last element popped = 5(max element where 7 can be attached)
5->right = 5
push 7 in stack
Stack - {10, 7}

Pass5----
now 40 > 7
pop 7
Stack - {10}
now 40 > 10
pop 10
Stack - {}
since stack is empty, loop over
last element popped = 10
10->right = 40
push 40 in stack
Stack - {40}

Pass6----
now 50 > 40
pop 40
Stack - {}
since stack is empty
last elem popped = 40
50->right = 40
push 50 in stack
Stack - {50}
