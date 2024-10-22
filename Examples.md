# Program 1 to print Hello World using Tureasy
  ```c

~This is how single comment is done

``
	two open quotes are used for multi-line comment
	This is how multicomment is done :)
``
  
~ This is a simple program to print Hello World in Tureasy

`` In Tureasy structure of a function is
    $<function name> << <return type>
      body of function
    %
  '$' denotes the start of a function and '%' denotes the end of the function
``

$main() << void
	string s = "Hello World\n";                   ~ "string" is a datatype to store a group of characters
	write(s);                                      ~ "write" is a function to print an output on the console
%
```

# Program 2 to find sum of positive and negative numbers in an array
```c
~ This is a program to find sum of positive ad negative numbers of an array

$main() << int
	int x[5] = {23,-4,9,19,-5};
	int pos_sum = 0, neg_sum=0;
  
	``
		The syntax of for-loop
		for <var> : <range of var>
	``
	for i : [0,5]
		if x[i] > 0 
			pos_sum = pos_sum + x[i]; /                     ~ '/' denotes the end of loops/conditions like "if" etc.,
		else if x[i] < 0 
			neg_sum= neg_sum + x[i]; /
        /
  return 0;		                                        ~ returning a value follows the syntax "return <var>"
%
```

# Program 3 to demonstrate the concept of passing arguments in Tureasy
```c
~ This is a program that demonstrates how to pass arguments by reference and by value in Tureasy

$foo (string a,string b) << void
   a = "a in foo";
   b = "b in foo";
%

$main() << void
  string a = "a in main";
  string b = "b in main";
  write(a + "\n" + b);
  foo(@a,b);                                       ~ '@' used to pass arguments by reference
  write("\n"+ a + "\n" + b);
%
```
Output for this program would be

```
a in main
b in main
a in foo
b in main
```

# Program 4 to demonstrate the unique concept of tags in Tureasy
```c
~ Declaration of function 'General_func' is similar to main

$General_func ( float w0, int a[], int b[], int m) << float
	float w = w0;  
  
  ~ In Tureasy '#' denotes the start of a tag
  #innerloop
    ~ syntax for while-loop is same as C except that there are no () braces
	  while d < 0.01
		  d=0;
		  for i:[0,M]
			  d= d + a[i] + b[i]*w;
		  / 
                  w = w - 0.001*d;
         / 
	#!innerloop                                  ~ '#!' denotes the end of a tag
	return w;                                    ~ returning a value in Tureasy is same as in C
%
  
$main() << void
	int w0,m;
	read w0 m;                                    ~ 'read' is a function to read the input from the user 
	int a[m],b[m];
	for i : [0,m]
		read(a[i]);
	/
	for i: [0,m]
		read(b[i]);
	/
	int ans = General_func w0 a b m;              ~ This is the format of callng a function in Tureasy
	write(ans);
%
```

# Program 5 to demonstrate Classes & Objects in Tureasy
  ```c
~ class definition starts with '*' and ends with '*%' 
~ private members and methods are declared with '_' at the start
*Dog
		~ it's members are defined in the 'mem' block.
    mem:
     string name;
     int  age;
     _int insta_followers = 0;
  
		~ methods are defined in 'met' block
    met:
    $Dispabout() << void
      write name " " age " " _insta_followers;
    %
    _$Updatefollowers(int newvalue) << void
      insta_followers.here = newvalue   
    %
    
		~ constructors for the class are defined in the 'con' block
		~ constructor is started with parameters in '( )' and ends with '%'
		~ ':' is used for constructors as they dont have any return type.
    con:
   (string name,int age):
      name.here = name;
      age.here = age;
      Updatefollowers 1;
    % 
       
*%    

$main() << void
	name = "woofy";
	age = "7";
	Dog aDog = new Dog(woofy,7);
	Dog.Dispabout();
    
``` 
