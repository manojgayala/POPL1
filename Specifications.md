# Variables and Operators
### Declaration of variables
The variables can start with alphabets or '_' symbol. Do not use keywords for variable names. Here is an example.
```
int x;			~	
List >> int y;		~ this is used for storing lists of type int
```
This is an example that do not conform.
```
int $z;		~ starts with '$'
string int;	~ keyword
```
### Bit-Wise Operators:
```
~ getBinary function, given a decimal number, prints it's binary number
$getBinary(int n) << void
	int loop;
	~ loop = 15, for 16 bits value, 15th bit to 0th bit
	write("Binary number of n = " + n + " is: ");
	for loop: desc (0,15)
		if (1 << loop) & n    ~ '<<' is the left shift operator, while '&' is the bitwise AND operator
            		write("1"); /
		else
			write("0"); /
    	/
%
''
Output : Binary number of n = 15768 is: 0011110100111110
''
```
Left shift / Right shift beyond the size of the variable will lead to undefined behavior.
```
int j = 1;  
j << 33; j>> 33;	~ not valid
~ variable 'j' is of type integer where its size is 32bits. 
~ So, when we try to shift it to 33rd bit position we will get an error.
```
Also they should not be used for negative numbers. Shifting a negative number or shifting by a negative value do not confirm to tureasy.
```
int j = -1;
j << 1;		~ (-1 << 1) - undefined behavior
1 << j;		~ (1 << -1) - undefined behavior
```
### Precedence:
The following code snippet depicts the precedence of some binary operators.
```
$precedenceInOP() << void
    int a = 20, b = 10, c = 15, d = 5, result;
    result = a + b * c / d;                                     ~ result = 20 + (( 10 * 15 ) / 5) = 50
    ~ if d equals 0, then this causes run-time error
    result = (a + b) * (c / d);                                 ~ result = (30) * (15/5) = 90
    ~ Operator precedence: '%' > '*' > '/' > '+'
    result = a+b*c%d-a*b                                        ~ a + (b*(c % d)) - (a*b) therefore result  = -180
    while(d>1)
        d = d- 2;                                                 ~ d = d - 2                     
        result = d**2**3;                                       ~ result = exp(exp(d,2),3)
        ~ for exponent operator, associativity: right to left
    /	~ at the end of while loop, result = 1
%
```
Statements such as the following cause error:
```
    int a, b, c = 3;
    a + b = c*c;    ~ this is a semantic error, lvalue should be some variable
```
```
p == 0 ? p += 1: p += 2; 	~ causes a syntax error
``
Precedence: (==) > (? :). So, its first operand is p == 0, and its second operand is p += 1. 
The last operand is considered to be p rather than p += 2, since occurrence of p binds 
more closely to the conditional-expression operator than it does to the assignment operator.
This results in a syntax error as += 2 does not have a left-hand operand.
Default Grouping :( p == 0 ? p += 1 : p ) += 2
Use of paranthesis for grouping would help.
``
```
### Type Compatibilty:    
```
$main () << void
    float f = 2.5;
    int n = f;      		~ n = 2; loss of a decimal
    write(n + "\n");       	~ prints "2"
    >>> warning: possible loss of data
    genFunction(3.2);
%

$genFunction (int n) << void
    write("n = "+n);    ~ prints "n = 3"
    ~ loss of data occurs due to incompatibility in type of actual and formal parameters.
%
```
### Variable Scope:
```
    float f = 2.32;
    $main() << void
        float f = 1.16;
        write("Value of f is " + f);       ~ Output : "Value of f is 1.16"
        ~ if there exists a local variable with same name as global variable, then global variable is shadowed
    % 
```

```
int a = 1;
while a==1
    int x = 2;
    a = 0;
/
write(x);   ~ displays "error: 'x' undeclared
```
# I/O handling and Control Flow
### For Loops
```
                    ~for loop in tureasy
int k,j,a[n];
for i:(0,n-1)               ~intialise statement and  range  [0,n] implies 0,n are included,
    k=a[i];
    j=i-1;
   /
for i:(0,n-1)               ~	iterates till i<n                            
    k=a[i];
    j=i-1;
/
   ```

By default update statement for 'for' loop in tureasy is incrementation by 1. **desc** should be used to traverse in reverse order.
```
for i: desc (0,n-1)     ~keyword  'desc' should be used to traverse in descending order
  k=a[i];
  /                 ~single line statements should also be closed
```
Even single line statements in for loops should be closed with '/'

```
for i:(0,n-2) 
    k[i]=a[i]+a[i+1];    ~this executes below statements also
write(k[n-1]);           ~this will throw an error.

```   
### while loop
```
 $main() << int
    int t1 = 0, t2 = 1, next = 0, n;
    write("Enter a positive number: ");
    read(n);
    
    write("Fibonacci Series:"+ t1+" " +t2+" ");
    next = t1 + t2;

    while  next < n              ~condition in while loop
        write(next+" ");				~ all fibonacci numbers less than n
        t1 = t2;
        t2 = next;
        next = t1 + t2;
    /
    return 0;
}
```


### break and continue
  **break** is used to end loop imediately
  **continue** statement skips the current iteration of the loop and continues with the next iteration
  ```
  
  for i:(0,n)
      if a[i]<0
        continue;  /        ~skips negative numbers
      if a[i]=0
          break;   /        ~exits out of loop if encounters 0
      s=s+a[i];
      /
   ```    
### if else statement
```
int m;
if k>n 
    write(k);/
 else if k<n
    write(k);/
 else
    write("0");/
  ```  
  
### switch
```
for i:(0,n-1)
		read(o,k);
		
		switch : o							~ : followed by expression
			case 1:
				insert(@root,k);
				break;

			case 2:
				delete(@root,k);
				break;
			 
			case 3:
				t=find(root,k,0);
				break;  
			case 4:
				printtree(@root);
				break; 
			default:                  
				write("check");
				break;
        /
    /    
```

# Functions
### Definition 
Here is an example.
```
$ add(int a,int b) << int        ~ '$' signifies the start of a function
   return a+b; 					~ if the return type is not void
%                                                    ~ '%' signifies end of  function	
```
### return type of functions

In Tureasy functions can return a maximum of only one value which is of same datatype as the one mentioned during the start of the function. This example do not conform to Tureasy.
```
$function () << void
  int i,j=0;
  i = 1+1;
  return i,j;           ~ The function type should be void but it is returning an integer and it is returning more than 1 parameter
%
```
### Pass by value or reference
In Tureasy variables can be passed by reference or by value
```
$ sample (string a) << void
   a = "I am in function";
%

$main() << void
  string a = "I am in main";
  function(a)                                         ~ variable is passed by reference
  write(a + "\n");                                    ~ a is "I am in main "
  function(@a);                                       ~ '@' suggests that it was passed by reference
  write(a + "\n");                                    ~ a is "I am in function"
%
```
### Recursion
An example of recursive functions.
```
$fact(int n) << int
  if n == 1
    return 1;
  /
  else
    return n*fact(n-1);
  /
%
```
### Functional paradigm
Tureasy also supports functional paradigm.
```
$main() << void
   int a[n];
   for i : (0,5)
   		a[i]=i*i+i;			/
	
	List >> int s = a.findAll(x%2==0);			~ finds the list of elements that satisfy condition
	int z = s.max();							~ finds the max
%
```
### user-defined functions
```
$sqrt(float x) << float
	return x*x;
%
``
This is not the correct procedure because sqrt function is already an inbuilt function in Tureasy.
These can be overridden by using .$ before function only in the current program.
``
```
### Local functions
The functions can be defined inside main itself with a pointer to it. These functions use the variables within scope of main as parameters. Here is an example.
```
$main() << void
	List >> int a = [13,45,5,90,7];			~ List of numbers
 func s = [@] $()	<< int 					~ @ is for reference and no name is given to function since we have reference
 	int sum=0;
	
	for i : a
		sum=sum+a[i];		/
		
	return sum;						~ sum is returned
 %
 
 	int x = s();				~ no parameters required to call which saves a lot of memory during multiple calls
	write(x);
%
```
# Strings

### Creations of strings

Strings are declared using keyword **string**.
```
string msg = "Hello World";			~strings can have spaces
write(msg);					~ prints 'Hello World'
```
### Accessing characters in a string
Individual characters of a string can be accessed by **indexing** or defining the **range of characters** using slicing.
Accessing an element out of range in program will raise an ` IndexError `
 ``` 
 string str = "Language design";
  write("str[2] = "+str[2]);  ~prints the third character 
  
  write("str[1:6]= "+str[1:6]);  ~prints 2nd to 7th		~ it includes all the characters within bounds

write("str[-2]= "+str[-2]); 					~prints the last 2nd character

``
Output:
str[2] = n
str[1:6]= anguag
str[-2]= g 
``
```
Incorrect slicing of string will raise an ` RangeError `
```
write(str[12:10]);
>>> RangeError: range specified is invalid

write(str[10:-10]) ~this is wrong as length of string is 16
>>> RangeError: range specified is invalid
```

### String operations

+ operator is used to join strings together and  * operator can be used to make multiple copies of a string. 
```
string state = "TS";
string number = "2345";

write("Number plate = "+ state+number);

string repeat = "Hi";
write(repeat*3);
``
Output:
Number plate = TS2345
HiHiHi
``
```
Existence of substring within string can be checked with ':' operator.
```
"some" : "cumbersome"		~ Output: true
"right" !: "Alright"		~ Output: false	(it means not a substring) 
```
> Note: the above method is case sensetive

### Standard String functions
```
strcmpr(@str1,@str2)	~ return -1 or 0 or +1 for str1  <, ==, >  str2 respectively
~the above function can be overloded by passing another argument as follows
strcmpr(@str1,@str2,n)	~ same function as above, but compares only first n characters


strcpy(@str1,@str2)		~copies the contents in str2 to str1
~the above function can be overloaded with more constraints
strcpy(@str1,@str2,n)	~copies at most n characters of str2 to str1


~the functions mentioned below are to be applied on string objects
 
strReplace

strSplitOn

strCombine

StrWordCount	//by default outputs size of string, else counts specific word

```



### Escape sequences

**optional**

### Formatting strings

**optional**

# Classes and Objects
### Constructors
Multiple constructors can be made for a class.
```
*Node         ~Class
mem:
string value;
string key;
con:
(string key,string value)    ~constructor with two argumets
here.key = key;
here.value = value;
%
(string key)        ~ constructor with a single argument.
here.key = key;
%
*%
```
But different constructors with same type and number of arguments is not valid as they cannot be resolved.
```c
con:       ~ Both contructors have same string argument.
(string value)
here.value = value;
%
(string key)
here.key = key;
%
```
### Private Methods
Private methods start with `_$`.

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
Private methods (also members) are not inherited by the subclass.
 
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
  %
*%

$main << void
 B b = new B();
 b.foo();        ~This cannot be done because foo method is not inherited by B.
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
 (string datakey,linkNode next):(datakey)  ~next set of parameters is for the parentclass constructor.
  here.next = next;
%
*%

$main << void
linkNode n = new linkNode("1",new linkNode());		~ new linkNode() is the default constructor which stores NULL in all members
write(n.key) ~prints '1'
```
Every non-default constructor of subclass must have a parent constructor call( default or non-default). Default constructor requires no parameters.
This is not valid.
```
con:  
(string datakey,linkNode next)    ~no parent constructor is specified.
here.next = next;
%
```

### Multiple Inheritance
Multiple inheritance can be done in Tureasy. 
```
*A 					~Class A
mem:
int data;
con:
 (int d)
  data = d;
 %
met:
 $foo() << void  	 ~foo in A
 write(data);
 %
*%

*B 							~Class B
mem:
int data;
con:
 (int d)
  data = d;
 %
met:
 $foo() << void   ~foo in B
 write(data);
 %
*%

*C inherit A,B   			~Class C inherits both A and B.
	con:
	``constructors for A and B has to be specified in the same order
	   as in definition.``

	 (int data1,int data2):(data1):(data2) 
	  write("Constructor of C is called");
	 %
	met:
	 .$foo() << void 				~ foo method is overridden using '.$' as it is in both A and B;
	  parent.A.foo();
	%
*%
```
**The common methods have to be overridden in the child class.**
(Common methods are the ones with same method name and also same set of parameters.)

This leads to compile-time error
```
*C inherit A,B
 con:
   (int data1,int data2):(data1):(data2):
     write("Constructor of C is called");
   %
 *%

$main() << void
C c = new C(1,2);
c.foo(); 				 ~this method cannot be resolved now.
```
### Object Equivalence

Unlike primitive datatypes,`==` operator cannot be used to compare two different objects.
```
			~Classes Node,Node2 are created with same contents.
$main << void
  Node a = new Node(4); ~instance of Node		~ as defined above
  Node b = new Node(4); ~instance of Node
  Node2 c = new NodeB(4); ~instance of Node2		~ similar class
  write(a==c); 				~this gives a compilation error as they are of different classes.
  write(a==b); 				~this prints false;
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
# TAGS 
### Nested tags
Tags can be nested for better suggestions
```
#number_theory
#exponentiation
int ans = 1;
for i : (0,b-1)					~ a and b are variables in actual function
	ans= ans*a /
``	
Tip: {while b>0
	if b&1
          ans = ans*a;/
	a = a*a; 
	b=b/2; 	/	} in line 2 =>
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
for j : (1,n-1)
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
for i : (0,n) 
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
		neighbors.add(i);//		~ line 19

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

### tags for parallelism
Parallel codes can be suggested to users for better hardware use.
```
#loop	
for i : (0,6)
	a[i] = 0;	/
``
Tip : {forAsync i : (0,6)	
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
for i : (1,n-1)
	a[i]=a[i-1];	/
``
There is actually a possibility of rewriting the code as a[i]=1 for all i's and use parallelism. But, the tags cannot give that tip.
``	
```
 Turzer identifies the constraints/contexts by processing the tags provided by the programmer
       and the processed tag is identified through a vocabulary corpus used by tureasy.
       So programmer has to name the tags appropriatly.
       Irrelavent tags may not help the turzer to identify or even may lead to misleading tips.
 
 ```
 ~Here the user wants to check whether length of string exceeds 6.
 
 #string<6.             ~But this tag is processed to check whether the value of string exceeds 6.
    String s = "1234". ~ line 2
    char[] a;
    char k = 'a';
    for(int i=0;i<10;i++){
       if(a[i]=k).   ~this logical error leads to concatenation of 10 chars to the string.
          s+=i;
    }
 #!string<6 
 
So the tureasy would give the tip related to the value of string more than 6.

Tip: (s = "1234"} in line 2 => violates constraint.
 
 ```

