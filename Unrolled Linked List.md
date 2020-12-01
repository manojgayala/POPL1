Tureasy provides some functions which have variable number of arguments to be passed.

~ This is an example which depicts the usage of Unrolled Linked List which can be used as an alternative for some databaes

`` In this example we are considering two databases in the form of an array and an unrolled linked list. one database stores the names of departments and the other stores the 
   top 3 CGs of that department
``
```c
$main() << void
  int i,j;
  string departments[] = {"AI", "CSE", "CE", "EE", "EP", "ES", "MA", "MS"}
  int length = len(string);                                             ~ len is the function to find length of a string
  
  UnrolledLL <float> CGs = UrolledLL <float> new (3)                    ~ This way of convention is used to create an Unrolled Linked List CGs of type float with each array of specified length
  
  for i in [0:length]
    CGs.insert(read x y z)                                              ~ insert is a function to add an array of elements to the Unrolled Linked List CGs at the end by default 
  /
  return 0;
 %
```c
Unrolled Linked List has a wide range of functions like insert(), insertFirst(), insertEnd(), insertPos(), getFirst(), getEnd(), getPos(), removeFirst(), removeEnd(), removePos()
(use of which are obvious by their names) all of which take variable number of arguments.


An example in the above case which do not conform: 
```c
$main() << void
  int i,j;
  string departments[] = {"AI", "CSE", "CE", "EE", "EP", "ES", "MA", "MS"}
  int length = len(string);                                             ~ len is the function to find length of a string
  
  UnrolledLL <float> CGs = UrolledLL <float> new (3)                    ~ This way of convention is used to create an Unrolled Linked List CGs of type float with each array of specified length
  
  for i in [0:length]
    CGs.insert(read x y z p)                                            ~ The length specified in each array is 3 but the user is giving 4 input which is against rules 
  /
  return 0;
 %
```c
