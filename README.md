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

Program 1 in [this](https://github.com/manojgayala/POPL1/blob/srikar/Examples.md) shows how to print "Hello World" in Tureasy
This code needs to be stored with a .te file extension and can be compiled using the command

<code> tureasy <file_name>.te </code>

This creates an executable file which can be run for the output.
The execution begins with $main and it executes sequentially. String is an in-built data type that stores group of characters. The "write s" is a function used to write the output of the variable 's' onto the screen.The functions are called with parameters space separated after the name of function. By default, the compiled code of few libraries (along with the standard library) is linked to .te file.


Program 2 in [this](https://github.com/manojgayala/POPL1/blob/srikar/Examples.md) shows how to find sum of positive and negative numbers in an array

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

Program 3 in [this](https://github.com/manojgayala/POPL1/blob/srikar/Examples.md) demonstrates passing parameters in Tureasy


There is a unique concept of **tags in Tureasy** which makes it different from other languages. These tags refer to common codes and algorithms such as graphs, greedy algorithms, dynamic programming, loops within loops etc. These tags are mainly used by the compiler to identify what kind of suggestions and optimisations are possible. The tags are even used in improving the compiler's intelligence by learning better implementations of codes and algorithms from users when connected to the internet.

Program 4 in [this](https://github.com/manojgayala/POPL1/blob/srikar/Examples.md) demonstrates the unique concept of tags in Tureasy

In this case there is an approach of O(M+K) instead of O(M*K) which would be suggested by compiler. Internally the tag uses GLORE algorithm to identify this.
Suggestions would look like:
```	
tip: inner loop has w variable unchanged - can be written outside outer loop
```
The suggestions also include parallel algorithms and their efficient implementations which enable programmer to make best use of the hardware. We can use more than one tags, in that case the intersection of their suggestions is used by compiler.

# Classes & Objects

Program 5 in [this](https://github.com/manojgayala/POPL1/blob/srikar/Examples.md) demonstrates Classes & Objects in Tureasy

This is how a simple class is created in Tureasy, **class definition** starts with * and ends with *% and its members are defined in the **'mem'** block ended with '/' and similarly methods are defined in **'met'** block.Private members and methods  are declared with **'_'** at the start.Private members  and methods cannot be accessed by the object directly.**Getter methods for the private variables are created implicitly when the class is defined.**
Constructors for the class are defined in the **'con'** block ended with '\' and each constructor is started with parameters in **'( )'** and ends with '%'  

# Do's and USP of Tureasy

 - It is recommended to make use of the tags and improve the code. Good programmers can also work online with tags so that data is collected by tureasy server to improve the compiler. It is advised to indent the code for better readability. Single line comments begin with ~ and multi line comments are enclosed within parenthesis.  Inside functions.

 - Functions can be defined at any part of the body. No prior prototype declaration is necessary.
 - Use same variable names for the parameters and the anrguments which are passed by reference to ensure that no ambiguity occurs in readability and it also makes it easy for the complier.

Tureasy can be used by everyone for improvement of their coding skills. In industry, it could be used by companies by making private tags that ensures that their data is safe and also helps in development of their own technology. Private tags mean that they have some private turzers for their companies. Basically, turzers are the files where the models and techniques corresponding to tags are stored. The data collected from tags are trained and tested on various models which can later be used to give suggestions. Turzers can be ket private under an organization's database which develops as the organization grows. These turzers help in maintaining constancy in the productivity of company since staff of the organizatons change but their unique implemenatations and ideologies are stored within the turzer files as models. Tureasy can be also be extended with libraries for meeting specific requirements like gaming.  

# Don'ts of Tureasy 
 -It is advised not to use irrelevant tags because that might increase compilation time. It is possible that user's implementation is unique and irrelevant suggestions might be given. So suggestions should not be implemented unless the programmer is sure about it. 
 - It is advised not to use global variables to avoid scope issues.
 - Initialise the private variables,So even when there are no setter methods for them, they can be accessed safely.
 - Try to make private methods for functionalities  which are used frequently in all the methods of the class so that that cannot be overridden.
 - Don't use "_{datatype}" (eg: '_int'} outside of a class frequently , it may  unnecessarily restrict the function to the file it is created in.
