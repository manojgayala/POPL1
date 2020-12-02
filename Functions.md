## Functions in Tureasy

### Functions in Tureasy

Structure of  function is as below in Tureasy
```c
$function_name() << data_type_of_return_value        ~ '$' signifies the start of a function
   statements;
   return value; (if the return type is not void)
%                                                    ~ '%' signifies end of  function
```

### Pass by value and reference

In tueasy variables can be passed by reference or by value
```c
$function (string a) << void
   a = "I am in function";
%

$main() << void
  string a = "I am in main";
  function(a)                                         ~ variable is passed by reference
  write(a + "\n");                                    ~ a is "I am in main "
  function(@a);                                       ~ '@' used to pass arguments by reference
  write(a + "\n");                                    ~ a is "I am in function"
%
```

### Recursion

Recursive functions are written in the below form in Tureasy
```c
$fact(int n) << int
  if n == 1
    return 1;
  /
  else
    return n*fact(n-1);
  /
%
```

### Pure functions

Tureasy provides a wide range of pure functions
```c
$main() << void
   int x,y;
   x = 4;
   y = sqrt(x);
   write(x,y);
%
In the output we have x as 4 (unchanged) and y as 2
```

### return type of functions

1) In Tureasy functions can return a maximum of only one value which is of same datatype as the one mentioned during the start of the function
```c
$function () << void
  int i,j=0;
  i = 1+1;
  return i,j;           ~ The function type should be void but it is returning an integer and it is returning more than 1 parameter
%
```
