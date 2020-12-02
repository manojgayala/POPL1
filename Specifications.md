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




