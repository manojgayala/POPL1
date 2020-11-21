# About Language
TUREASY is a general purpose programming language which has a unique feature of smart compiler. Unlike the traditional compilers which translate code to assembly language, this compiler tries to optimise the code and gives suggestions to the user in improving his code's performance. Tureasy supports generic, object oriented and functional programming. The suggestions and optimisations are implemented using the reflective programming, which is a type of meta-programming. 

# Syntax and Semantics
The language is easy to code. This is an example program for printing "Hello World" in Tureasy.
 <code>
$main
string s = "Hello World\n";
write s;
%
</code>
This code needs to be stored with a .te file extension and can be compiled using the command

<code> tureasy <file_name>.te </code>
This creates an executable file which can be run for the output.
The execution begins with $main and it executes sequentially. string is a in-built data type that stores group of characters. The "write s" is a function used to write the output of the variable 's' onto the screen.The functions are called with parameters space separated after the name of function. By default, few libraries' compiled code is linked to .te file.

An example program to find the sum of positive and negative numbers in an array is 
<code>
$main
int x[5] = {23,-4,9,19,-5};
int pos_sum = 0, neg_sum=0;
for i : [0,5]
	if x[i] > 0
		pos_sum = pos_sum + x[i]; @
	else if x[i] < 0
		neg_sum= neg_sum + x[i]; @
/%
</code>

Every single line instructions are ended with ";" , the conditional statements end with "@" and the iterative statements end with "/".

There is a unique concept of tags in Tureasy which makes it different from other languages. These tags refer to common codes and algorithms such as graphs, greedy algorithms, dynamic programming, loops within loops etc. These tags are mainly used by the compiler to identify what kind of suggestions and optimisations are possible. The tags are even used in improving the compiler's intelligence by learning better implementations of codes and algorithms from users when connected to the internet.
An example code including tags and functions is
<code>
$General_func ( float w0, int a[], int b[], int m)
	float w = w0; 
	#innerloop
	 while d < 0.01
		 d=0;
		 for i:[0,M]
			 d= d + a[i] + b[i]*w;
		/ w = w - 0.001*d;
		/ 
	#!innerloop
	return w;
%
$main
int w0,m;
read w0 m;
int a[m],b[m];
for i : [0,m]
	read a[i];
/
for i: [0,m]
	read b[i];
/
int ans = General_func w0 a b m; 
write ans
%
</code>

The function definition starts with $ similar to main and ! symbol marks the end of it. "#innerloop" and "!innerloop" mark the beginning and end of tags. We can use more than one tags, in that case the intersection of their suggestions is used by compiler. In this case there is an approach of O(M+K) instead of O(M*K) which would be suggested by compiler.
Suggestions would look like:
<code>	tip: inner loop has w variable unchanged - can be written outside outer loop
</code>

# Do's and USP of Tureasy
It is recommended to make use of the tags and improve the code. Good programmers can also work online with tags so that data is collected by tureasy server to improve the compiler. It is advised to indent the code for better readability. Single line comments begin with ~ and multi line comments are enclosed within parenthesis.  Inside functions it is better to declare the variable to be returned in first line because the compiler assumes by default that to be the data type of return value. 
It is advised not to use global variables to avoid scope issues.

Tureasy can be used by everyone for improvement of their coding skills. In industry, it could be used by companies by making private tags that ensures that their data is safe and also helps in development of their own technology. Tureasy can be extended with libraries for meeting specific requirements.

# Don'ts of Tureasy
It is advised not to use irrelevant tags because that might increase compilation time. It is possible that user's implementation is unique and irrelevant suggestions might be given. So suggestions should not be implemented unless the programmer is sure about it. 
