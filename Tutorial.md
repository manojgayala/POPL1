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

Now we would try to understand the code line by line. The first line has `main` which is a special function which marks the beginning of the program execution. The functions section would cover more about the syntax and details about it. The second line is the heart of the code where we give instruction of displaying a set of characters on console output. The `write` method is used for this purpose. The third line `%` marks the end of function which is followed by program termination.

The set of characters enclosed within double quotes(" ") is called string. Some characters beginning with '\' are called escape sequences which are used for representing hard to type or invisible characters. The escape sequences would be covered in the later sections.

# I/O Handling
Console Input and Output in Tureasy is easy to program. This doesn't require any formatting unlike C, the compiler is smart enough to identify the data type of input and output variables and does type casting if required.
Tureasy has some inbuilt functions some of which are offered by default (more on functions is discussed in the subsequent section `Functions`). One of which is the function **read** which is used to take input from the user. The parameters of read are separated by a **,** (comma). An example of it is as below
```c
$main() << void
	int x;
	float y;
	read(@x);		~ passed 
	read(@x,@y);		~ Taking multiple inputs	
%
```   
Strings are taken as input with space as delimiter.

The function **write** is used to print output to the console. The parameter of the function write is of data type string. An example of it is as below
```c
$main() << void
	int x = 10;
	write("The value of x is "+x);
%
```
**x** is type casted to string internally and the string "The value of x is " and x are concatenated and the final result is printed. 

# Variables and Operators:
A variable is like placeholder for the data to be processed. The operators are used to manipulate this data. Here is an example for variables and operators.
```
$main() << void
    int a, b, result;
    string finalAns;
    read(@a,@b);
    if a > 0 && b > 0
    	result = a*b + (a/b - b%a)*b;/
	    `` 
		The value of expression after equality is computed taking a = 7, b = 3 
		a*b + (7/3 - b%a)*b
		a*b + (2 - b%a)*b
		a*b + (2 - 3%7)*b
		a*b + (2 - 3)*b         here 7/3 is truncated off to 2
		a*b + (-1)*b
		7*3 + (-1)*b
		21 + (-1)*3
		21 + (-3)
		18
	    ``
    
    finalAns = (result >= 18) ? "Yes" : "No";
    write(finalAns);
%
```
The lines of code enclosed within \`\` and \`\` are called multiline comments which are used for programmer readability. These comments are not compiled.
The values of two variables a, b are read from the user. The operations are done following the precedence rules in Tureasy. The precedence table is mentioned in `Language Manual`.
 Assume that the input given from the user for a and  b is 7,3 respectively. The condition is checked at the beginning and since it is true get executed to result in 18. The 



### Type Casting:
Converting one datatype into another is known as type casting.
Convertion of values from one type to another explicitly can be done using the cast operator as follows −
```
$main() << void
    int a,b;
    double result;
    result = (double) a / b;
    write("Result = " + result);
    ``
    For a = 14, b = 5, the following output gets printed on console:
    Result = 2.800000
    ``
%
```
In the above example, variables a and b are declared under integer datatype. Note here that the cast operator has precedence over division, so
the value of a is first converted to type 'double' and finally it gets divided by b yielding a double value which is assigned to result.

# Loops and conditional statements
This is a program to print factors of a number.
``` 
$main() << void 
    int num;
    write("Enter a positive integer: ");
    read(num);
    write("Factors of "+ num +" are: ");
    for i: (1,num) 
        if num % i == 0 
            write(i +" "); /
        else
            continue; /
 % 
 ```
The output of this program is factors of the given number separated by spaces.`i` is initialised to 1, \
`(1,num)` specifies range of `i` till which loop has to run.\
For each iteration i is incrimented by 1, For loop iterates form i=1 to i=num. when i>num the loop is terminated. For each iteration the `if` statement is checked if the expression `num%i` is true then the sub statement in `if` is executed i.e. the number is displayed in the screen, else next iteration is continued. \
for loops can also be used for list traversing.\
`for listA`
When this statement is executed ,the loop runs till all the elements of list are traversed. The loop begins with first element and traversesa all elements one by one in ascending order.\
suppose if we want alternative elements, whille loop can be used as shown below,\

```
int n,i=0;
while i<=n
    write(a[i]);
    i=i+2; /
 ````
    
Here i is incremented by 2 in each iteration, the output consists of alternative elements of the array. The loop runs repeatedly till i<=n, once i exceeds n the loop breaks.

# Lists and Arrays

### Lists
List is a generic data type in Tureasy, it is a sequence of objects.

A list can be created by the declaration `List>>type identifierName;`
The above declaration creates an empty list.

The elements of a list can be initilized during declaration by enclosing them in square brackets as shown
`  List>>int  scores = [ 22 , 36, 14, 21, 40]; `

To add new elements to an existing list, using append( )
` scores.append(29); ~ this adds 29 to end of the list`


Multiple elements can be added to an existing list by concatenate them shown
```
scores += [ 19, 27];
```
You can reassign or extract a part of a list using slicing operator `:`
```
List>>int scores2 = scores[0:3]; ~scores2 will get [ 22, 36, 14, 21]

List>>int score3 = score[:2]; ~score3 will get [22, 36, 14]

score[1:3] = [35, 15, 20] ~Replaces 36,14,21 with 35,15,20 espectively
``` 

### Arrays
Array is almost like a list, except that its size and contents are constrained to a single type. The type and size of array are determined at time of creation.

### Initializiation of arrays
Initialization of all elements of array is done by  ` type arrayname[ ] = {list of values}; `
We can also initilize particular elements by using array subscripts ` arrayname[subscript] = value; `


  
  one more subtle difference to note is that character arrays are initized to exact length of sequence of characters. For instance,
  ```
  char sequence[] = "abcd";
  ~the length of array will be 4
  ``` 
  where as in case of string objects, a special character called null character (\0) is added at end of sequence of characters, which helps the compiler to differentiate the fixed size character array from a dynamic-size string. 
  ```
  string sequence = "abcd";
  ~ the length of above will be 5 as it will include "\0" at end
  ```
  
# Strings
The ability to manipulate text easily is a major part of most programming languages. Tureasy offers **string** type and includes a variety of useful string operations.
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
To obtain a sub-string, use the slicing operator ` a[i:j]  `, where [i:j] specifies the range as all the characters in a whose index is x such that i <= x <= j. Either index can be ommitted to imply, the beginning or the end of string as shown below:
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

Table of some important functions supported for string objects. 
function | task
-------- | -----
str1.cmp(str2) | compares the sum of ASCII values of characters in string and returns -1 if str1<str2,  1 if str1>str2 and 0 if equal 
Replace(str2,str3) | replaces specifed sub-string(str2) with str3
Find(str) 	| searches for the specified sub-string(str) and outputs position
WordCount(str)	| gives the count of number of occurences of specifed character in the string OR length of string

# Functions
Functions are code-snippets (or parts of code) in Tureasy that attempt to enhance readability, understandability and efficiency of a code. Functions are of 2 types: **pre-defined functions** and **user-defined functions**
Pre-defined functions are those which are provided by the language and user-defined are those which are defined by the programmer.  Some examples of pre-defined functions are **read** , **write** etc., whose functionality is evident.
Here after we will introduce the concepts of functions in Tureasy using user-defined functions as a better approach.
 
 An example of function in Tureasy is as below:
```c
$passing_values(int a) << void
	a = 5;
	write(a);
%

$main() << void
	int x;
	x = sum(2,3);
	write("The value of x is "+x);
	int a = 4;
	passing_values(a);
	write(a);
	passing_values(@a);
	write(a);
%

$sum(int a, int b) << int
	int c;
	c = a+b;
	return c;
%
```
Declaration of function in Tureasy starts with **$** and ends with **%**  as shown above.
A function in Tureasy can return either 1 or none values. 
In the code above, the functions **main** , **sum** , **passing_values** are user-defined and the function **write** is a pre-defined function.

It is advised that the names of function should define the use of that function as shown in the above example. The naming convention for functions is same as for identifiers which is discussed in detail in `Language Manual`.

Functions can be defined in any order in Tureasy **i.e., order of function declarations doesn't matter in Tureasy**. In the example above, the function *sum* is defined after it is called whereas *passing_values* is defined before it is called.

Only declaring a function doesn't execute it. A function needs to be called in order to run that function. This process is referred as **calling of a function**.  In the example above, the statement `x = sum(2,3);` calls the function *sum* and stores the return value in x. Similar mechanism is adopted when calling pre-defined functions like **read** , **write** etc.,

Parameters can be passed into functions using two methods: **pass by value** and **pass by reference**
In the example above, the function *passing_values* is called two times. One by passing it's arguments by value `passing_values(a)`and the other by passing it's arguments by reference `passing_values(@a)`. The variable is preceded by the symbol **@** to pass the parameters by reference.  
In short pass by value mean passing a copy of the variable due to which the original variable doesn't change its value. Pass by reference mean passing the address of the variable due to which the original value stored in the variable is changed. 

### Recursion
A special kind of function in Tureasy is **recursion** in which a function *calls itself until a stopping condition (base case) is reached*.
Here is a snippet to illustrate a recursive function *fibanocci* which returns sum of terms of a fibanocci series to a given digit.

(Fib series is a series which follows the equation T(n) = T(n-1)+T(n-2) where T(0)=T(1)=1)
```c
$fib(int n) << int
  if n <= 1
    return n;
  /
  else
    return fib(n-1)+fib(n-2);
  /
%
```
You may notice that the value of _n_ doesn't change in this example **i.e., the state of the input parameter is the same through out the scope of the function**. In essence, there are no side effects to this recursive example. Recursive functions can be used to write programs of functional programming paradigm **i.e., these kind of functions concentrate more on the mental model of the programmer rather than operational**. In short recursive functions express the logic of the computation without describing it's control flow and hence they find many applications in real world problems which are *model based* 

### Local functions

There are another category of functions that can be defined inside main itself with a reference to it. These functions use the variables within scope of main as parameters. 
Here is an example to illustrate the same
```c
$main() << void
	List >> int a = [13,45,5,90,7];			~ List of numbers
 func s = [@] $()  << int 					~ @ is for reference and no name is given to function since we have reference
 	int sum=0;
	for i : a
		sum=sum+a[i];		
	/	
	return sum;						~ sum is returned
 %
 
 	int x = s(); 					~ no parameters required to call which saves a lot of memory during multiple calls
	write(x);
%
``` 

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
**FILE** is the keyword to denote that the variable *fptr* does operations with the specified file and the path of the file need to be stored.  
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

# Classes and Objects
Tureasy supports object-oriented programming and all the objects are instances of a class.
 Every class consists of three blocks namely members constructors ,methods represented by `mem` ,`con`,`met` respectively. 
 Every Class starts with `*` and ends with `*%`
 Members,Methods are merely variables/objects ,functions respectively in tureasy but in classes private members and methods can be defined.
 Private members/methods are only accessible in the Class body and are declared using `_` as a prefix to their usual declaration.
  
### Basic Class Declaration: 
```
*ClassA           ~name of the class should not have any whitespaces.
mem:               ~member block.
int a;
string b;
met:                ~method block.
$printmem() << void
write(a+" "+b);
%
$setmem(int x,string s)<< void
b = s;
a = x;
%
con:                ~constructor block.
(int x,string s)
a = x;
b = s;
%                  ~constructor terminator
*%                ~class terminator.
```
Members,Methods are merely variables/objects ,functions respectively in tureasy but in classes private members and methods can be defined.
Private members/methods are only accessible in the Class body and are declared using `_` as a prefix to their usual declaration.
```
*ClassA
mem:
int a;
_string b;
met:
$printmem() << void
write(a+" "+b);
%
_$setstring(string s) << void
b = s;
%
*%

$main << void
ClassA obj = new ClassA();
obj.setstring("hlo private var");       ~this is not allowed as setstring() is a private method of ClassA.
%

```
  There can be multiple constructors for a class.
### Object -Instance of a Class
Objects are created by calling the constructor of a class using `new` keyword.
The members and methods are accessed by `.` operator.
```
~Here Two objects are created using two constructors of the ClassA.
$main << void
ClassA obj = new ClassA();                 ~default constructor.
ClassA obj2 = new ClassA(2,'second constructor`);
obj.a = 3;                                 ~member access
obj.setmem(5,'setting throgh a method');   ~method access
obj2.printmem();  
```
### Inheritance

A class can inherit methods and members of a class using inheritance.
Inheritance is done using `inherit` keyword in the declaration of the class followed by the classname of the parent class.  

This class can access both the members and methods of itself and also the public methods of the parent class;
```
*ClassB inherit ClasA
mem:
float d;
*%

$main << void
ClassB inh_obj = new ClassB();
inh_obj.a = 2;       ~accessing parent memeber.
inh_obj.d = 24.0;
inh_obj.printmem();  ~calling the parent method.
```
Multiple inheritance can also be done in the similar way.
 ```
*Class1 
mem:
int x;
*%
*Class2
mem:
string y;

*Class3 inherit Class2,Class1. ~Multiple inheritance.
met:
$printmem()
write(x+" "+y);  ~ x and y are inherited from Class1,Class2.
%
*%
 
```

###  Overriding and Overloading
Methods of a class can be overloaded(different methods with same names) and also its parent methods can be overridden(changing the definition of the method).
Overriding is done by using `.$`
```
*ClassB inherit ClassA
mem:
float d;
met:
.$printmem(). ~overridden method.
write(a+" "+b +" "+d);
%
$setmem(int x,string s,float f).  ~overloaded method.
d =f;  
parent.setmem(x,s);  ~parent method can be accessed through 'parent' keyword.
%
*% 
```


# Tags
Tureasy offers its programmers a unique feature of tags. These tags help in improving the code and even finds common logical bugs by understanding what the user is intended to do. Let us understand its usage with an example.
``` 
$main() << void
	int w0,m;
	read(w0,m);                                  
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
