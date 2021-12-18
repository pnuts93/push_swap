# push_swap
42 Curriculum (Level 2) - An algorithm to sort integers on a stack

## Use

`git clone` repository  
  
`make` for the sorting algorithm binary (`push_swap`)  
  → This binary is supposed to be executed as `./push_swap $STACK` where STACK may be a sequence of integers (eg: `STACK="1 5 3 19"`). It will print on the output the moves needed to sort the stack.  
    
`make bonus` for the checker binary (`checker`)  
  → This binary is supposed to be executed as `./push_swap $STACK | ./checker $STACK`. If the output of the sorting algorithm is not piped to this binary, it will be required to write the moves manually.  
    
`make play` for the interactive binary (`ps_play`)  
  → This binary is supposed to be executed as `./ps_play $STACK` and it will require some manual input. This specific part was not included in the curriculum project and it was written to make the dynamic of the game more understandable.
