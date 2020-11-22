# About Language
TUREASY is a general purpose programming language which has a unique feature of smart compiler. Unlike the traditional compilers which translate code to assembly language, this compiler tries to optimise the code and gives suggestions to the user in improving his code's performance. Tureasy supports generic, object oriented and functional programming. The suggestions and optimisations are implemented using the reflective programming, which is a type of meta-programming. 

# Syntax and Semantics
The language is easy to code. [Here](https://github.com/manojgayala/POPL1/blob/main/Example%20code%20files/Hello%20World.txt) is an example program for printing "Hello World" in Tureasy.
 
This code needs to be stored with a .te file extension and can be compiled using the command

<code> tureasy <file_name>.te </code>

This creates an executable file which can be run for the output.
The functions are called with parameters space separated after the name of function. By default, few libraries' compiled code is linked to .te file.

[Here](https://github.com/manojgayala/POPL1/blob/main/Example%20code%20files/Sum%20of%20pos%20and%20neg%20num%20in%20array.txt) is an example program to find the sum of positive and negative numbers in an array.

There is a unique concept of **tags in Tureasy** which makes it different from other languages. These tags refer to common codes and algorithms such as graphs, greedy algorithms, dynamic programming, loops within loops etc. These tags are mainly used by the compiler to identify what kind of suggestions and optimisations are possible. The tags are even used in improving the compiler's intelligence by learning better implementations of codes and algorithms from users when connected to the internet.
[Here](https://github.com/manojgayala/POPL1/blob/main/Example%20code%20files/Usage%20of%20tags%20in%20Tureasy.txt) is an example code including tags and functions

We can use more than one tags, in that case the intersection of their suggestions is used by compiler. In this case there is an approach of O(M+K) instead of O(M*K) which would be suggested by compiler.
Suggestions would look like:
```	
tip: inner loop has w variable unchanged - can be written outside outer loop
```
# Do's and USP of Tureasy
It is recommended to make use of the tags and improve the code. Good programmers can also work online with tags so that data is collected by tureasy server to improve the compiler. It is advised to indent the code for better readability. Single line comments begin with ~ and multi line comments are enclosed within parenthesis.  Inside functions it is better to declare the variable to be returned in first line because the compiler assumes by default that to be the data type of return value. 
It is advised not to use global variables to avoid scope issues.

Tureasy can be used by everyone for improvement of their coding skills. In industry, it could be used by companies by making private tags that ensures that their data is safe and also helps in development of their own technology. Tureasy can be extended with libraries for meeting specific requirements.

# Don'ts of Tureasy
It is advised not to use irrelevant tags because that might increase compilation time. It is possible that user's implementation is unique and irrelevant suggestions might be given. So suggestions should not be implemented unless the programmer is sure about it. 

