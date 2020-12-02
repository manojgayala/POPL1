## Functions in Tureasy

### Examples which conform

1) Structure of  function is as below in Tureasy
```c
$function_name() << data_type_of_return_value        ~ '$' signifies the start of a function
   statements;
   return value; (if the return type is not void)
%                                                    ~ '%' signifies end of  function
```
2) In tueasy variables can be passed by reference or by value
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

3) Recursive functions are written in the below form in Tureasy
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

```c

```

```c

```

### Examples which do not conform

1) In Tureasy functions can return a maximum of only one value which is of same datatype as the one mentioned during the start of the function
```c
$function () << void
  int i,j=0;
  i = 1+1;
  return i,j;           ~ The function type should be void but it is returning an integer and it is returning more than 1 parameter
%
```

2) Declaration of callee function should be before the caller function in Tureasy. The below example do not conform this rule and hence gives an error
```c
$main() << void
  Hello();
%

$Hello() << void
  write("Hello World!");
%
```

```c

```

```c

```

```c

```
