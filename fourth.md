a) - The memory should be allocated to dynamically for implementing vector ( malloc,calloc can be used ) . This is a type of segmentation fault.
     So integer data and the structure vector should be initialized with some memory . 
     (This similar kind of mistake done at many places)

b) - Also data of the structure should be freed before the structure itself. So a problem in vector_free() function.

c) - At some places brackets should be used, better to not mess up with the precedence :) (just a good programming practise ).

d) - I see some memory leaks in the vector_push() as well.

Please see the edited code in fourth.c .

  
