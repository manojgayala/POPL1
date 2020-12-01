## OOPS IN TUREASY
Every object in tureasy is an instance of a class.


1.)
Multiple constructors can be made for a class.
```c
*Node
mem:
string value;
string key;
con:
(string key,string value):
key.here = key;
value.here = value;
%
(string key):
key.here = key;
%
*%
```
But different constructors with same type of arguments is not valid as they cannot be resolved.
```c
con: ~ Both contructors have same string argument.
(string value): 
value.here = value;
%
(string key):
key.here = key;
%
```
2.)
Public methods start with `$`
Overridden methods start with `.$`.

A subclass of a class can be created by using 'inherit' keyword followed by parent class name  in the class definition.

```c
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
Every non-default constructor of subclass has to specify the parameters for the parent class'(es') constructor to be called. If default constructor has to be called, then rather empty  `()` has to be specified.

This is not valid.
```c
con:  
(string datakey,linkNode next):~no parent cconstructor is specified.
next.here = next;
%
```

3.)
Multiple inheritance can be done in tureasy.(i.e a class can inherit from multiple classes) and similarly childclass constructor has to specify constructors of the parent classes in the same order as in the definition.
**The common methods have to overriden in the child class.**
(Common methods are the ones with same method name and also same set of parameters.)
```c
*A
mem:
int dataA;
con:
 (int d)
  dataA = d;
 %
met:
 $foo() << void
 write(dataA);
 %
*%

*B
mem:
int dataB;
con:
 (int d)
  dataB = d;
 %
met:
 $foo() << void
 write(dataB);
 %
*%

*C inherit A,B
con:
(int data1,int data2):(data1):(data2):
write("Constructor of C is called");
%
met:
.$foo() << void ~foo(void return) method is overridden as it is in both A & B;
parent.A.foo();
%
*%
```
if common methods are not overridden,it is a compile-time error
```c
*C inherit A,B
con:
(int data1,int data2):(data1):(data2):
write("Constructor of C is called");
%
*%

$main() << void
C c = new C(1,2)
c.foo();  ~this method cannot be resolved now.
```
4.)
Private methods start with `_$` and private methods can only be invoked in the class it's defined.

```c
*A
mem:
_$prifoo() << void
write("private method");
%
$foo() << void
prifoo();
write("\nprivate method is called and returned");
return;
%

```

Private methods(also members) are not inherited by the subclass.
 They also cannot be invoked outside a class ,in particular a subclass which inherits the class cannot access the private method/members even with `parent` keyword.

This code leads to compilation error.
```c
*A
met:
_$foo() << void
write("this method is only confined to A");
%
*%

*B inherit A:
met:
$fooB() << void
write("I want to call foo in A\n");
parent.A.foo()
%
*%
```
5.)
```c
*Node
mem:
 int v;
/
con:
 (int v): 
   v.here = v;
 %
*%
```

Objects cannot be compared through '==' operator.
```c
$main << void
Node n1 = new Node(4);
Node n2 = new Node(4);
if(n1==n2)
 write("Both are equal");
else
 write("No,even they are identical they refer to different objects."); 

```
Use 'sameas' method to compare contents of two objects.This method can only be invoked if both objects are of the same class.
```c
$main << void
Node n1 = new Node(4);
Node n2 = new Node(4);
if(n1.sameas(n2))
 write("Both are equal");
else
 write("No,even they are identical they refer to different objects.");
```

## TAGS IN TUREASY

1) The code snippet prints the bfs tree in ascending order of neighbors
<code>
 int vis[n];		~ whether visited or not
for i : [0,n]
	vis[i]=0;
/

vis[0]=1;	~ starting from 0th vertex

	#bfs #unique_queue			~ unique_queue tag signifies that elements in queue must be unique
Queue q;						~ standard bfs	
q.enqueue(0);
write(0);
List l,neighbors;

while !q.Empty()
	int x = q.dequeue();
	l = g[x];

	for i : l
		if !vis[i]
			neighbors.add(i);
		/
	/

	l.sort();

	for i : l
		q.enqueue(i);
		vis[i]=1;
		write(i);
	/
/							~ we get a tip that vis[i] is double checked....this must be understood that vis[i]=1 must 
										~ be placed inside while loop to avoid parallel edges and self loops leading to
	#!unique_queue	#!bfs								~ queue not being unique		

 </code>
