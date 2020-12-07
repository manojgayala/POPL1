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
