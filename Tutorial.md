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