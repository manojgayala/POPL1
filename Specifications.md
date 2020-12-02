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




