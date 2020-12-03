# Classes and Objects 
### Constructors

Multiple constructors can be made for a class.
```
*Node         ~Class
mem:
string value;
string key;
con:
(string key,string value):    ~constructor with two argumets
key.here = key;
value.here = value;
%
(string key):        ~ constructor with a single argument.
key.here = key;
%
*%
```
But different constructors with same type and number of arguments is not valid as they cannot be resolved.
```c
con:       ~ Both contructors have same string argument.
(string value): 
value.here = value;
%
(string key):
key.here = key;
%
```
### Inheritance

```

`` A subclass can be created by using "inherit" keyword 
   followed by parent class name  in the class definition.``

~Node is the same class defined before.

*linkNode inherit Node 
mem:
  linkNode next;
con: 
 (string datakey,linkNode next):(datakey):  ~nxt set of parameters is for the parentclass constructor.
  next.here = next;
%
*%

$main << void
linkNode n = new linkNode("1",new linkNode());
write(n.key) ~prints '1'
```
Every non-default constructor of subclass has to specify the parameters for a parent class'(es') constructor to be called. If default constructor has to be called, then rather empty  `()` has to be specified.

This is not valid.
```
con:  
(string datakey,linkNode next):     ~no parent cconstructor is specified.
next.here = next;
%
```

### Multiple Inheritance
Multiple inheritance can be done in tureasy. 


```
*A ~Class A
mem:
int dataA;
con:
 (int d)
  dataA = d;
 %
met:
 $foo() << void   ~foo in A
 write(dataA);
 %
*%

*B ~Class B
mem:
int dataB;
con:
 (int d)
  dataB = d;
 %
met:
 $foo() << void   ~foo in B
 write(dataB);
 %
*%

*C inherit A,B   ~Class C inherits both A and B.
	con:
	``constructors for A and B has to be specified in the same order
	   as in definition.``

	 (int data1,int data2):(data1):(data2): 
	  write("Constructor of C is called");
	 %
	met:
	 .$foo() << void ~ foo method is overridden using '.$' as it is in both A and B;
	  parent.A.foo();
	%
*%
```
**The common methods have to  be overridden in the child class.**
(Common methods are the ones with same method name and also same set of parameters.)

this leads to compile-time error
```
*C inherit A,B
 con:
   (int data1,int data2):(data1):(data2):
     write("Constructor of C is called");
   %
 *%

$main() << void
C c = new C(1,2);
c.foo();  ~this method cannot be resolved now.
```

### Private Methods

Private methods start with `_$` and private methods can only be invoked in the class it's defined.

```
*A
mem:
_$prifoo() << void        ~this is a private method of A.
write("private method");
%
$foo() << void
prifoo();               ~"prifoo()" can be called in any method of A.
write("\nprivate method is called and returned");
return;
%

```

Private methods(also members) are not inherited by the subclass and also cannot be invoked even with the `parent` keyword.
 
```
*A
 met:
  _$foo() << void
    write("this method is only confined to A");
  %
*%

*B inherit A:  ~B is a subclass of A.
 met:
  $fooB() << void 
    write("I want to call foo in A\n");
    parent.A.foo()       ~ this is not allowed.
  %
*%

$main << void
 B b = new B();
 B.foo();        ~This cannot be done because foo method is not inherited by B.
%
```
### Object Equivalence

Unlike primitive datatypes,`==` operator cannot be used to compare two different objects.
```
``Classes Node,Node2 are created with same contents.
*Node 
mem:
 int v;
/
con:
 (int v): 
   v.here = v;
 %
*%
*Node2 
mem:
 int c;
/
con:
 (int c): 
   c.here = c;
 %
*%
```




```
$main << void
  Node a = new Node(4); ~instance of Node
  Node b = new Node(4); ~instance of Node
  Node c = new NodeB(4); ~instance of Node2
  write(a==c); ~this gives a compilation error as they are of different classes.
  write(a==b); ~this prints false;
%

```
Use `sameas` method to compare contents of two objects.This method can only be used if both objects are of the same class.
```
$main << void
Node n1 = new Node(4);
Node n2 = new Node(4);
if(n1.sameas(n2)).       ~returns true.
 write("Both are equal");
else
 write("No,even they are identical they refer to different objects.");
```







# Strings

### Creations of strings

Strings are declared using keyword **string**.

```
string msg = 'Hello World';
~strings can have spaces
write(msg);
~ prints 'Hello World'
```


### Accessing characters in a string
We can access individual characters of a string by **indexing** or defining the **range of characters** using slicing.
If we access an element out of range our program will raise an ` IndexError `


 ``` 
 string str = 'Language design';
  write('str[2] = ',str[2]);  ~prints the third character 
  
  write('str[1:6]= ',str[1:6]);  ~prints 2nd to 7th
 ~note in languages like python str[1:6] prints 2nd char to 6th char

write('str[-2]= ',str[-2]); ~prints the last 2nd character
```

when we run the above program, we get the following output:
```
str[2] = n
str[1:6]= anguag
str[-2]= g 
```

if we slice the string array incorrectly we will raise an ` RangeError `
```
write(str[12:10]);
>>> RangeError: range specified is invalid

write(str[10:-10]) ~this is wrong as length of string is 16
>>> RangeError: range specified is invalid
```

### string operations

#### concatenation of strings

we can use + operator to join strings together and  * operator can be used to make multiple copies of a string. 

```
string state = 'TS';
string number = '2345';

write('Number plate = ', state+number);

string repeat = 'Hi';
write(repeat*3);
```
above code will output
```
Number plate = TS2345
HiHiHi
```

we should be cautious about where you want blank spaces to occur by placing single quotation marks between strings as shown below.
```
string msg = 'Welcome' + ' ' + 'everyone';

string repeat = ('Hi'+' ')*3;
```
### substring checking
we can test if a substring exists within a string or not, using ` : ` symbol. 
```
>>> 'some' : 'cumbersome'
>True
~ as the word is found, it returns boolean True

>>> 'right' !: 'Alright'
>False 
~ the string 'right' is in 'Alright' but the query was !: which is negation

```

> Note: the above method is case sensetive


### some built-in functions



# TAGS 
### nested tags
Tags can be nested for better suggestions
```
#number_theory
#exponentiation
int ans = 1;
for i : [0,b]
	ans= ans*a /
``	
Tip: {while b>0
	if b&1 ans = ans*a;/
	a = a*a; 
	b=b/2; 	/} in line 2 =>
O(lg(n)) method possible using binary exponentiation
	
``
#!exponentiation
#!number_theory
```
### Common pitfalls while using nested tags
Tags do not work if they aren't closed and nested tags should be closed in first opened last closed method. Here is an example that fails compilation.
```
#greedy_algorithm
#max_events
i=0;
write(i);
for j : [1,n]
	if s[j]>=f[i]		
	~ s[i] is the start time and f[i] is the finish time of event	
		write(j);
		i=j;	//
#!greedy_algorithm	~ error is shown while compilation
#!max_events
```
### using tags for constraints
Constraints can be set on some parameters using tags and that can be used for correctness of algorithm's execution.
```
int vis[n]; 				~ whether visited or not 
for i : [0,n] 
	vis[i]=0; /
vis[0]=1; 					~ starting from 0th vertex

#bfs #unique_queue			~ unique_queue tag is used for putting constraint of uniqueness on queue
Queue q; 						~ standard bfs 
q.enqueue(0); 
write(0); 
List>>int l,neighbors;			~ List is super class and int is its sub class

while !q.Empty() 
	int x = q.dequeue(); 
	vis[x]=1;
	l = g[x];

for i : l
	if !vis[i]
		neighbors.add(i);//

neighbors.sort();
for i,j : neighbors
	q.enqueue(i);
	write(i);/
/
#!unique_queue #!bfs 
`` 
Tip: {vis[i]=1} in line 19 => maintains unique_queue	
This tip signifies that vis[i]=1 must be before neighbors.add(i) which will ensure neighbors is unique and thereby queue is unique.
``
```
When the parameters fail to satisfy constraints, there could be many ways to fix it. The tags do not suggest all of them, it only suggests one. Sometimes, there could be more trivial way to solve it which isn't suggested by tags. Here is an example.
```

``` 
### tags for parallelism
Parallel codes can be suggested to users for better hardware use.
```
#loop
for i : [0,7]
	a[i] = 0;	/
``
Tip : {forAsync i : [0,7]	
			a[i] = 0; /} in line 1 => for faster execution 
``	
#!loop
```
### tags for memory optimisation
The tags suggest ways to modify code for proper usage of memory.
```
~ Recursive insertion in Binary Search Tree
$ insert(Node root, int a) << Node
	Node temp = new Node(a);
	if root is null
		return temp; /
	else if a < root.a
		root.left = insert(root.left,a); / 
	else
		root.right = insert(root.right,a); / 
	return root;
%
``
Tip : { Node temp = new Node(a) } from line 1 to line 3 => memory leaks and unnecessary constructor calls.
`` 
```
### Tags using private turzers
There are some private turzers for companies. Along with usage of these tags certain config files need to be included within .te file for authentication. Here is an example.
```
collect <file_name>.tcnf

# prudential	~ the tag names are decided by company itself
	`` the code of the project ''
#! prudential
``
while compilation, it checks the contents of .tcnf file for authentication
``
```
### Limitations in tips
Here is an example which do not confirm to specification. The tags might not give tips for such cases.
```
a[0]=1;
for i : [1,n]
	a[i]=a[i-1];	/
``
There is actually a possibility of rewriting the code as a[i]=1 for all i's and use parallelism. But, the tags cannot give that tip.
``	
```

# Functions

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

In Tureasy functions can return a maximum of only one value which is of same datatype as the one mentioned during the start of the function
```c
$function () << void
  int i,j=0;
  i = 1+1;
  return i,j;           ~ The function type should be void but it is returning an integer and it is returning more than 1 parameter
%
```

### in-built functions

There are a wide range of in-built functions in Tureasy. The procedure of calling them is as follows
```c
$main() << void
	output_value = function_name(input_values)
%
```

### user-defined functions

```c
$sqrt() << float
	statements;
	return output;
%

This is not the correct procedure because sqrt function is already an inbuilt function in Tureasy. Hence the function should be overridden
```
# Operators

### Bit-Wise Operators
```
~ getBinary function, given a decimal number, prints it's binary number
$getBinary(int n) << void
	int loop;
	~ loop = 15, for 16 bits value, 15th bit to 0th bit
	write("Binary number for n = " + n + " is: ");
	for loop:[15,0]
		if( (1 << loop) & n)    ~ '<<' is the left shift operator, while '&' is the bitwise AND operator
            		write("1"); /
		else
			write "0"; /
    	/
%
```
For n = 15768, above code will output:
```
Binary number of n = 15768 is: 0011110100111110
```
Left shift / Right shift beyond the size of the variable will lead to undefined behavior.
```
int j = 1;  
j << 33; j>> 33;	~ incorrect
```
Here, variable “j” is of type integer where its size is 32bits. When we try to shift it to 33rd bit position we will get an error.

Also they should not be used for negative numbers. We can neither shift a negative number nor get a number shifted by negative number.
```
int j = -1;
j << 1;		~ (-1 << 1) - undefined behavior
j << a;		~ (1 << -1) - undefined behavior
```
### Precedence
The following code snippet depicts the precedence of some binary operators.
```
$precedenceInOP() << void
    int a = 20, b = 10, c = 15, d = 5, result;
    result = a + b * c / d;                                     ~ result = 20 + (( 10 * 15 ) / 5) = 50
    ~ if d equals 0, then this causes run-time error
    result = (a + b) * (c / d);                                 ~ result = (30) * (15/5) = 90
    ~ Operator precedence: '*' > '/' > '+'
    result = a+b*c%d-a*b                                        ~ a + ((b*c) % d) - (a*b) therefore result  = -180
    while(d>1)
        d -= 2;                                                 ~ a = a - 5                     
        result = d**2**3;                                       ~ result = d^(2^3) = d^8
        ~ for exponent operator, associativity: right to left
    /	~ at the end of while loop, result = 1
%
```
Statements such as the following cause error:
```
    int a, b, c = 3;
    a + b = c*c;    ~ this is a semantic error
    <<< error: lvalue required as left operand of assignment
```
In this expression, the equality operator (==) has the highest precedence, followed by conditional-expression operator (? :). So p == 0 is 
grouped as an operand. Its first operand is p == 0, and its second operand is p += 1. However, the last operand of the conditional-expression 
operator is considered to be p rather than p += 2, since this occurrence of p binds more closely to the conditional-expression 
operator than it does to the compound-assignment operator. A syntax error occurs because += 2 does not have a left-hand operand.
```
    p == 0 ? p += 1: p += 2; ~ causes a syntax error
    ~ Default Grouping :( p == 0 ? p += 1 : p ) += 2
```
Using paranthesis will clarify clarify the preceding example:
```
    ( p == 0 ) ? ( p += 1 ) : ( p += 2 )
```
