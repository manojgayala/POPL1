# About Language
TUREASY is a general purpose programming language which has a unique feature of smart compiler. Unlike the traditional compilers which translate code to assembly language, this compiler tries to optimise the code and gives suggestions to the user in improving his code's performance. Tureasy supports generic, object oriented and functional programming. The suggestions and optimisations are implemented using the reflective programming, which is a type of meta-programming. 

# Syntax and Semantics
The language is easy to code. Tureasy has 40 keywords. 
| Key word  |       			    |
|---		|---			        |
| state  	| *to import libraries    |
| write  	| to print output 	    |
| read  	| to take input		    |
| string 	| sequence of characters|
|  setnull| *all unassigned values are made null     |
|  igend 	| *ignores all errors after this line till the end of program 	|

"state" is used to import external libraries.
This is an example program for printing "Hello World" in Tureasy.
  ```c
~ This is a simple program to print Hello World in Tureasy

{ In Tureasy structure of a function is
    $<function name> << <return type>
      body of function
    %
  '$' denotes the start of a function and '%' denotes the end of the function
}

$main << void
	string s = "Hello World\n";                   ~ "string" is a datatype to store a group of characters
	write s;                                      ~ "write" is a function to print an output on the console
%
```
This code needs to be stored with a .te file extension and can be compiled using the command

<code> tureasy <file_name>.te </code>

This creates an executable file which can be run for the output.
The execution begins with $main and it executes sequentially. String is an in-built data type that stores group of characters. The "write s" is a function used to write the output of the variable 's' onto the screen.The functions are called with parameters space separated after the name of function. By default, the compiled code of few libraries (along with the standard library) is linked to .te file.


An example program to find the sum of positive and negative numbers in an array is 
```c
~ This is a program to find sum of positive ad negative numbers of an array

$main << int
  int x[5] = {23,-4,9,19,-5};
  int pos_sum = 0, neg_sum=0;
  
  {The syntax of for-loop
    for <var> : <range of var>
  }
  for i : [0,5]
	  if x[i] > 0 
		  pos_sum = pos_sum + x[i]; /                     ~ '/' denotes the end of loops/conditions like "if" etc.,
	  else if x[i] < 0 
		  neg_sum= neg_sum + x[i]; /
  /
  return 0;		                                        ~ returning a value follows the syntax "return <var>"
%
```

Every single line instructions are ended with ";" , the conditional statements and the iterative statements end with "/".


| symbol  	|   function		        	|
|---		|---			                |
|  $	    | start of a function       	|
|   %	    | end of function	            |
|  ; 	    | end of line               	|
|  / 	    | end of loops/ iterations  	|
|  @ 	    | pass by reference 	        |
|  << 	    | specifying return type of a function |
|  ~        | single line comments          |
|   {}      |  multiline comments           |
|  #        | opening a tag                 |
|   #!       | closing a tag                 |

In Tureasy, programmer can decide **whether to pass a parameter by value or by reference **(which by default stores the reference addresses of that instance of its class)at the point of time when it is being called.Prefixing  a parameter with '**@**',passes the parameter by reference without creating a local copy of it.
```c
~ This is a program that demonstrates how to pass arguments by reference and by value in Tureasy


$foo (string a,string b) << void
   a = "a in foo";
   b = "b in foo";
%

$main
  string a = "a in main";
  string b = "b in main";
  write a b;
  foo @a b;                                       ~ '@' used to pass arguments by reference
  write a b;
%
```
Output for this program would be

```
a in main
b in main
a in foo
b in main
```
There is a unique concept of **tags in Tureasy** which makes it different from other languages. These tags refer to common codes and algorithms such as graphs, greedy algorithms, dynamic programming, loops within loops etc. These tags are mainly used by the compiler to identify what kind of suggestions and optimisations are possible. The tags are even used in improving the compiler's intelligence by learning better implementations of codes and algorithms from users when connected to the internet.
An example code including tags and functions is
```c
~ Declaration of function 'General_func' is similar to main

$General_func ( float w0, int a[], int b[], int m)
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
	return w;                                   ~ returning a value in Tureasy is same as in C
%

~This is how single comment is done

{ Now the function main begins..
  BTW this is how multicomment is done :)}
  
$main
int w0,m;
read w0 m;                                    ~ 'read' is a function to read the input from the user 
int a[m],b[m];
for i : [0,m]
	read a[i];
/
for i: [0,m]
	read b[i];
/
int ans = General_func w0 a b m;              ~ This is the format of callng a function in Tureasy
write ans
%
```
In this case there is an approach of O(M+K) instead of O(M*K) which would be suggested by compiler. Internally the tag uses GLORE algorithm to identify this.
Suggestions would look like:
```	
tip: inner loop has w variable unchanged - can be written outside outer loop
```
The suggestions also include parallel algorithms and their efficient implementations which enable programmer to make best use of the hardware. We can use more than one tags, in that case the intersection of their suggestions is used by compiler. 
# Do's and USP of Tureasy

 - It is recommended to make use of the tags and improve the code. Good programmers can also work online with tags so that data is collected by tureasy server to improve the compiler. It is advised to indent the code for better readability. Single line comments begin with ~ and multi line comments are enclosed within parenthesis.  Inside functions.

 - Functions can be defined at any part of the body. No prior prototype declaration is necessary.
 - Use same variable names for the parameters and the anrguments which are passed by reference to ensure that no ambiguity occurs in readability and it also makes it easy for the complier.

Tureasy can be used by everyone for improvement of their coding skills. In industry, it could be used by companies by making private tags that ensures that their data is safe and also helps in development of their own technology. Tureasy can be extended with libraries for meeting specific requirements.

# Don'ts of Tureasy
It is advised not to use irrelevant tags because that might increase compilation time. It is possible that user's implementation is unique and irrelevant suggestions might be given. So suggestions should not be implemented unless the programmer is sure about it. 

 - It is advised not to use global variables to avoid scope issues.
