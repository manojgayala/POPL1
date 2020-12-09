# Introduction
This tutorial is about the language Tureasy. Our main aim is to familiarise the reader with essentials of Tureasy. After reading this tutorial, the reader would be able to code reasonably good in Tureasy.  Example programs are used to explain different concepts in the tutorial. The reader might be unfamiliar with some lines of example programs in the beginning but would gradually understand to the end of tutorial.

# Getting Started
The reader is advised to write programs in Tureasy for better understanding. Let us start with a simple "Hello World" program.
```
$main() << void              
  write("Hello World\n");   
%
```
This code needs to be stored with a .te file extension and can be compiled using the command 			
`tureasy <file_name>.te`
This creates a default executable file named a.out which can be executed with the command
`./a.out`
And we get the output as "Hello World" printed in a single line and program terminates.

Now we would try to understand the code line by line. The first line has `main` which is a special function which marks the beginning of the program execution. The functions section would cover more about the syntax and details about it. The second line is the heart of the code where we give instruction of displaying a set of characters on console output. The `write` command is used for this purpose. The third line marks the end of function which is followed by program termination.

The set of characters enclosed within double quotes(" ") is called string. Some characters beginning with '\' are called escape sequences which are used for representing hard to type or invisible characters. The escape sequences would be covered in the later sections.

### Arrays
Array is almost like a list, except that its size and contents are constrained to a single type. The type and size of array are determined at time of creation.

#### Initiliziation of arrays
Initilization of all elements of array is done by  ` type arrayname[ ] = {list of values}; `
We can also initilize particular elements by using array subscripts ` arrayname[subscript] = value; `


  
  one more sublte difference to note is that character arrays are initized to exact length of sequence of characters. For instance,
  ```
  char sequence[] = "abcd";
  ~the length of array will be 4
  ``` 
  where as in case of string objects, a special character called null character (\0) is added at end of sequence of characters, which helps the compiler to differentiate the fixed size character array from a dynamic-size string. 
  ```
  string sequence = "abcd";
  ~ the length of above will be 5 as it will include "\0" at end
  ```
  
# I/O Handling
Console Input and Output in Tureasy is easy to understand and program. This doesn't require any formatting unlike other languages like C, C++ etc., The compiler is smart enough to identify the data type of input and output variables and does type casting if required.
Tureasy has some inbuilt functions some of which are offered by default (more on functions is discussed in the subsequent section `Functions`). One of which is the function **read** which is used to take input from the user.  The parameters of read are separated by a **,** (comma). An example of it is as below
```c
$main() << void
	int x;
	float y;
	read(x);		~ Taking a single input
	read(x,y);		~ Taking multiple inputs
%
```   
Here is an example to take input of a string with space
```c

```

The function **write** which is used to print output to the console.  The parameter of the function write is of data type string. An example of it is as below
```c
$main() << void
	int x = 10;
	write("The value of x is "+x);
%
```
**x** is type casted to string internally and the string "The value of x is " and x (after type-casting) are concatenated to one and the final result is printed.   

# File handling
Basic steps while handling files in Tureasy are:
1. Opening a file
2. Operations performed by file
3. Closing the file

A simple code explaining the concept of file handling in Tureasy is as below:
```c
$main() << void
	FILE fptr;
	string path;
	read(path);
	fptr.open(path,"r");
	while(fptr.readLine() != EOF)
		write(fptr.readLine());
	/
	fptr.close();
%
```
A pointer need to be created to access any file named **FILE** and the path of the file need to be stored.  
The file can be opened in any of the below methods
| *r* | *w* | *a* | *br* | *bw* | *ba* |
|---|---|---|---|---|---|

* **r**: opening a file in *read* mode
*  **w**: opening a file in *write* mode
*  **a**: opening a file in *append* mode
*  **br**: opening a  file in *binary read* mode
*  **bw**: opening a file in *binary write* mode
*  **ba**: opening a file in *binary append* mode

**readLine** is a function to read file line to line

A filed open in Tureasy must be close using the function **close**


# Strings


The ability to manipulate text easily is a major part of most programming languages. Tureasy offers ** string ** type and includes a variety of useful string operations.
Strings are stored as a sequence of characters, which are indexed by integers starting from zero. The string type 

### Creating strings

This programming language allows literal strings to be specified as a sequence of characters enclosed in double quote marks.

```
string a = “Hello World”;
```
  
### String operations
To extract a single character, use indexing operator ` a[i] ` as shown:
```
string b = a[6];	~ b gets "W"
```
To obatain a sub-string, use the slicing operator ` a[i:j]  `, where [i:j] specifies the range as all the characters in a whose index is x such that i <= x <= j. Either index can be ommitted to imply, the beginning or the end of string as shown below:
```
string c = a[2:8];	~ c gets "llo Wor"
string d = a[:5];	~ d get "Hello "
string e = a[:];	~ as both ommited, e gets entire "Hello World"

```

Strings are mutable, i.e. content in the strings can be modified without creating a new object. The size of the arrays holding the strings can change size dynamically to provide flexibility for the strings.
```
string str1 = "Hello";
string str2 = "World";

str1 = str1 + " " + str2;
~ str1 finally holds "Hello World"

string str3 = str1*3;
~ str3 gets HelloHelloHello
```
In above example string concatenation operator ` + ` and string duplicate operator ` * `  were used.



### Manipulating strings

```
exmples to be written
```

Table of some important functions supported for string objects. 
function | task
-------- | -----
cmp(str2) | compares the sum of ASCII values of characters in string and returns -1 if str1<str2,  1 if str1>str2 and 0 if equal 
Replace(str2,str3) | replaces specifed sub-string(str2) with str3
Find(str) 	| searches for the specified sub-string(str) and outputs position
WordCount(str)	| gives the count of number of occurences of specifed character in the string OR length of string

# Expressions:
An expression is a formula in which operands are linked to each other by the use of operators to compute a specific value. The operand can be a
function reference, a variable, an array element or a constant. There are four types of expressions:
### Arithmetic expressions:
An arithmetic expression is an expression that consists of operands and arithmetic operators. It computes a value of type int, float or double.
Ex: 3*2/ (5+1 * 4/2) - 2 * (7/4)
### Relational expressions:
A relational expression compares two operands. It's result can be either zero(equivalent to false) or non-zero value(equivalent to true).
Ex: a>=2
### Logical expressions:
A logical expression computes either a zero or non-zero value. It can be seen as a test condition.
Ex: (x > 2) && (y < 6)
### Conditional expressions:
A conditional expression is an expression that returns 1 if the condition is true otherwise 0.
Ex: eligibility = (age > 18) ? "Yes" : "No";

We'll see an example code in Tureasy that covers all above aspects:
```
$main() << void
    int a, b, result;
    string finalAns;
    read(a,b);
    result = a*b + (a/b - b%a)*b
    `` 
        Consider a = 7, b = 3 for this example. Evaluation of value of expression after equality, following precedence rules is shown here:
        a*b + (7/3 - b%a)*b		~ this is an arithmetic expression
        a*b + (2 - b%a)*b
        a*b + (2 - 3%7)*b
        a*b + (2 - 3)*b     here 7/3 is truncated off to 2
        a*b + (-1)*b
        8*3 + (-1)*b
        24 + (-1)*3
        24 + (-3)
        21
    ``
    ~ the following line has both logical and conditional expressions
    if a > 0 && b > 0           ~ (true && true)
    	~ down here is an conditional expression after the = operator
        finalAns = (result > 18) ? "Yes" : "No";     ~ since result > 18, string variable finalAns is assigned "Yes"
        write(finalAns);  ~ prints string "Yes" on to the console
        / 
%
```
# Tags
Tureasy offers its programmers a unique feature of tags. These tags help in improving the code and even finds common logical bugs by understanding what the user is intended to do. Let us understand its usage with an example.
``` 
$main() << void
	int w0,m;
	read(w0 m);                                  
	int a[m],b[m];
	
	for i : (0,m)
		read(a[i]);	/
	for i: (0,m)
		read(b[i]);	/
		
	float w = w0;  
  #innerloop			
	  while d < 0.01	~ line 12
		  d=0;
		  for i:(0,M)
			  d= d + a[i] + b[i]*w;	/ 
          w = w - 0.001*d;	/ 	~ line 16
  #!innerloop
	write(w);
%
```
The opening tags begin with  `#` and closing tags begin with `#!`. The tag names are unique, in this case it is innerloop.
This code gets compiled and executed perfectly fine. But this code can be improved by reducing the time complexity of O(n*n) to O(n). The reader can observe that the inner loop has no variation in the value of `w`. This implies that the inner loop could have been written  out of the while loop leading to linear time complexity. The tags provide such suggestions to the programmer.
The tip would look like
```
Tip : Replace line 16-19 with {
		int A=0,B=0;
		for i: (0,M)
			A = A + a[i];
			B = B + b[i];	/
		while d < 0.01
			d= A + B*w;
			w = w - 0.001*d;	/ } => w is unchanged in inner loop
``` 
This tip could be used by the programmer to make her code even better. It should not be expected that the code for replacement is always provided in tip. The tip mainly focuses on letting the programmer realize a better way to code and sometimes provides the same.
The tip is suggested after compilation using turzers. In this example, GLORE approach is used to detect the improvement. In general, there is an internal logic which is precisely explained in the `Language Manual`.
The proper usage of tags can help us code with ease. 

The tags can be nested too making the suggestions even more accurate. When nesting is done, it is advised to properly identify the part of code corresponding to the tag which ensures more focus for internal analysis. 
The tips are based on machine learning models, so the reader is advised to code while connected to the tureasy server. This would provide data for the improvement of turzers. The reader could connect to the tureasy server using this command 
` turconnect  <file_path> `
The user could instead use the Tureasy IDE which takes care of the server connections.

There are private tags which are confidential and can be accessed only by licensed companies. These tags are project specific and their turzers are trained using company's data. The details are precisely explained in `Language Manual`. 
The programmer is advised to understand the tips before using them because the tips might misinterpret the code's aim. 
