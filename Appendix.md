# Variables and Storage Classes
The variables are the placeholders of the data. 

* [**Syntax**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Tutorial.md#user-content-io-handling:~:text=Variables%20and%20Operators%3A)
* [**Declarations**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-lvalues:~:text=Declarations,-Declarations)
* [**Scope and Linkage**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-types-of-identifiers:~:text=Scope,-The%20scope)

The variables are of different data types and belong to different storage classes.

* [**Data types**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-storage-class:~:text=Basic%20types)
* [**Storage classes**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#storage-class)

These data types are extended to include the data structures called the generic data types.
## Generic Data Types
All of these have a common syntax. The type followed by `>>` datatype of constituent elements followed by variable name.
```
<Generic> >> <datatype> <variable_name>
```
### Lists
List is one of the generic data types in Tureasy, it is a sequence of objects.
More explaination regaring lists can be found in tutorial  [**Lists**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Tutorial.md#user-content-initializiation-of-arrays:~:text=Lists,20%5D%20~Replaces%2036%2C14%2C21%20with%2035%2C15%2C20%20espectively)

Items can be added to list one at a time, or many at a time with the help of .append() function of a list
```
List>> int a;
a.append(10);	~APPENDS 19 TO END OF LIST

a.append([21,17,12,25]);	~the same append function can be overloaded to add multiple elements at the same time 
```

### Queues
Queue is a data structure that follows FIFO (First In First Out) policy. It provides methods like 

- enqueue(a) : adds element
- dequeue() : removes element
- back() : last element
- front() : first element
- size() : number of elements

### Stacks
Stack is a data structure that follows LIFO (Last In First Out) policy. It provides methods like

- push(a) : adds element
- pop() : removes element
- top() : last added element
- size() : number of elements
- reverse() : reverses the order of elements in stack

### Pairs
Pair stores a pair of values and is used in dictionaries. The methods present in are

- first() : first element in the Pair
- second() : second element in the Pair

### Dictionaries
These are basically red black trees and are enclosed by curly braces to signify the same. The methods provided are

- find(a) : searches for key a in the dictionary
- remove(a) : removes key a from dictionary
- getValue(a) : value of key a is returned
- getKeys() : all the keys are returned
- getPairs() : all the key value pairs are returned in a list datatype
- getPred(a) : the immediate key less than key a is returned
- getSucc(a) : the immediate key greater than key a is returned

### Memset
These are basically memory optimized ways of storing a set of elements. They are binary numbers basically. 1 represents exists and 0 represents do not exists. It provides all the logical operations. The size can be specified for the memset at the declaration step.

### Rangetree
These are basically segment trees. These are used for the range queries and range updates. They take an array and a function reference as parameters. The function must contain the aggregate method we are trying to follow for the tree buildup. It provides methods like

- query(a,b) : the answer to range a to b query
- update(a,x) : the update x happens to the position a
- update(a,b,x) : the update happens to range a to b with x    

The last method is basically overloaded.

# Operators
* [**Unary operators**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-tag-expressions:~:text=Unary%20operators,can%20be%20operands%20of%20this%20operator.)
* [**Multiplicative Operators**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-unary-operators:~:text=operator.-,Multiplicative%20Operators,The%20binary%20operator%20*%20denotes%20multiplication%2C%20with%20the%20operands%20of%20arithmetic%20type.%20And%20the%20binary%20operator%20%2F%20yields%20the%20quotient%2C%20which%20also%20has%20both%20the%20operands%20of%20arithmetic%20type.%20While%20the%20%25%20operator%20the%20remainder%20of%20the%20division%20of%20the%20first%20operand%20by%20the%20second.%20Here%20both%20the%20operands%20must%20have%20integral%20type.%20Incase%20the%20second%20operand%20is%200%20in%20any%20of%20the%20operators%20%2F%20and%20%25%20the%20result%20is%20undefined.%20But%20it%20is%20always%20guaranteed%20that%20the%20absolute%20value%20of%20the%20remainder%20is%20smaller%20than%20that%20of%20the%20divisor.)
* [**Additive Operators**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-multiplicative-operators:~:text=divisor.-,Additive%20Operators,The%20operands%20can%20be%20integral%20or%20floating%20values.%20The%20result%20of%20the%20%2B%20operator%20is%20the%20sum%20of%20the%20operands%20while%20the%20result%20of%20the%20%2D%20operator%20is%20the%20difference%20of%20the%20operands.)
* [**Shift Operators**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-additive-operators:~:text=Shift%20Operators,the%20Expression1's%20type%20in%20left%20shift.)
* [**Relational Operators**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-shift-operators:~:text=type.-,Relational%20Operators,These%20operators%20support%20integral%20or%20floating%2Dpoint%20numeric%20type.%20The%20char%20type%20also%20supports%20these%20operators.%20In%20this%20case%2C%20the%20corresponding%20character%20codes%20are%20compared.%20Here%2C%20the%20result%20type%20is%20bool.%20If%20the%20relationship%20in%20the%20expression%20is%20false%2C%20the%20value%20returned%20is%20false(0)%3B%20otherwise%20true(1).)
* [**Equality Operators**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-relational-operators:~:text=true(1).-,Equality%20Operators,These%20operators%20are%20analogous%20to%20Relational%20Operators%2C%20i.e%2C%20they%20support%20integral%20or%20floating%2Dpoint%20numeric%20type%20and%20also%20string%20type.%20The%20result%20type%20is%20bool.%20The%20%3D%3D%20operator%20returns%20true(1)%20if%20both%20operands%20have%20the%20same%20value%3B%20otherwise%2C%20it%20returns%20false(0).%20The%20!%3D%20operator%20returns%20true(1)%20if%20the%20operands%20don't%20have%20the%20same%20value%3B%20otherwise%2C%20it%20returns%20false(0).)
* [**Bitwise Operators**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-equality-operators:~:text=Bitwise%20AND%20Operator,The%20usual%20arithmetic%20conversions%20are%20performed.)
* [**Logical Operators**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-bitwise-inclusive-or-operator:~:text=Logical%20AND%20Operator,it.%20The%20result's%20type%20is%20bool.)
* [**Assignment Operator**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-conditional-expression-operator:~:text=void.-,Assignment%20Operator,Assignment_Operator%3A)
* [**Conditional expression operator**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-logical-or-operator:~:text=Conditional%20Expression%20Operator,type%2C%20the%20result%20type%20is%20void.)
* [**Comma operator**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-assignment-operator:~:text=Comma%20Operator,elements%2C%20the%20generic%20type%20elements%20etc.)

## Precedence Table
Operator precedence determines the order in which certain operations need to be performed in an expression. Grouping of terms in an expression takes place accoringly and thus 
value of the expression is computed. Within an expression, higher precedence operators will be evaluated first. Operators Associativity is used when two operators of same 
precedence appear in an expression. \
Here in the table, operators on the same line have the same precedence; rows are in order of decreasing precedence.
|Category | Operator | Associativity |
|--- |------ |--- |
| Unary | + - : ! memsize() | Right to Left |
| Multiplicative | * / % | Left to Right |
| Additive | + - | Left to Right |
| Shift	| <<  >> | Left to Right |
| Relational | <  <=  >  >= | Left to Right |
| Equality | == != | Left to Right |
| Bitwise AND |	& | Left to Right |
| Bitwise OR | \| | Left to Right |
| Logical AND |	&& | Left to Right |
| Logical OR | \|\| | Left to Right |
| Conditional | ?: | Right to Left |
| Assignment | = += -= /= %= >>= <<= &= ^=  | Right to Left |
| Comma | , | Left to Right |

# Statements
 A statement is a command that the programmer gives to the computer. Statements are major part of the program.The body of any function is a sequence of statements. 
 They fall into several categories.
   * [**Labled statements:**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-statements:~:text=Labeled%20statementsstatements%20exist.%20A%20statement%20of%20the%20form%20case%20constant%2Dexpression%20%3A%20statement%20indicates%20that%20control%20will%20pass%20to%20this%20statement%20if%20the%20value%20of%20the%20control%20expression%20of%20the%20switch%20statement%20matches%20the%20value%20of%20the%20constant%2Dexpression.%20(In%20this%20case%2C%20the%20type%20of%20the%20constant%2Dexpression%20must%20be%20an%20integer%20or%20character.)%20A%20statement%20of%20the%20form%20default%20%3A%20statement%20indicates%20that%20control%20will%20pass%20to%20this%20statement%20if%20the%20control%20expression%20of%20the%20switch%20statement%20does%20not%20match%20any%20of%20the%20constant%2Dexpressions%20within%20the%20switch%20statement.%20If%20the%20default%20statement%20is%20omitted%2C%20the%20control%20will%20pass%20to%20the%20statement%20following%20the%20switch%20statement.%20Within%20a%20switch%20statement%2C%20there%20can%20be%20only%20one%20default%20statement%2C%20unless%20the%20switch%20statement%20is%20within%20another%20switch%20statement.%20In%20classes%20there%20are%20labels%20which%20are%20precisely%20described%20here)       
   * [**Expression-statement :**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-expression-statements:~:text=Expression%20statements%20do%20most%20of%20the,one%20simple%20assignment%20to%20a%20variable.)\
   It is combination of variables,Constants,operators,Function Calls and followed by a semicolon. Expression can be any operation like Arithmetic operation or Logical Operation.
   * [**Compound-statement:**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-expression-statements:~:text=variable.-,Compound%20statements)\
     Compound statement is combination of several expression statements. Compound statement is also called as Block Statement.
   * [**Selection-statement:**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-selectionconditional-statement:~:text=Selection%20statements%20choose%20one%20of%20several,over%20the%20initialization%20of%20such%20variables.)\
     Selection Statements are used in decisions making situations ,there are 3 different types:
      * [**If**](https://github.com/manojgayala/POPL1/blob/srikar/Tutorial.md#user-content-loops-and-conditional-statements:~:text=This%20if%20statement%20is%20a%20conditional,used%20for%20comparing%20two%20values%20equality.)
      * [**If-Else**](https://github.com/manojgayala/POPL1/blob/srikar/Specifications.md#user-content-if-else-statement:~:text=If%20else%20statement,Switch)
      * [**Switch**](https://github.com/manojgayala/POPL1/blob/srikar/Specifications.md#user-content-switch:~:text=%2F-,Switch,Functions)
   * [**Iteration-statement:**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-selectionconditional-statement:~:text=variables.-,Iteration%20statement,A%20for%20statement%20also%20terminates%20when%20a%20break%20or%20return%20statement%20within%20its%20body%20is%20executed.%20A%20continue%20statement%20in%20a%20for%20loop%20causes%20loop%20to%20start%20its%20next%20iteration%20abruptly)\
   These are also Called as Loops. If we want to Execute a part of program many times we will use loops.We will going to explain each and Every loop in Detail in     Later Tutorials. Here is the List of Basic loops in Tureasy language:
      * [**For**](https://github.com/manojgayala/POPL1/blob/srikar/Specifications.md#user-content-file-handling:~:text=f.close()%3B-,For%20Loops,By)
      * [**while**](https://github.com/manojgayala/POPL1/blob/srikar/Specifications.md#user-content-for-loops:~:text=error.-,While%20loop,%7D)
   * [**Jump-statements:**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-iteration-statement:~:text=abruptly.-,Jump%20statement,The%20return%20statement%20is%20used%20to%20return%20to%20its%20caller.%20If%20the%20function%20return%20type%20is%20void%2C%20the%20function%20may%20not%20return%20a%20value%3B%20otherwise%2C%20the%20expression%20represents%20the%20value%20to%20be%20returned.)\
   They are used for nonconsecutive execution.These are Unconditional statements Jump statements are useful for Transfer the Control one part of program to other part of Program there are few Jump Statements in tureasy:
        * [**break**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-jump-statement:~:text=The%20break%20statement%20appears%20in%20iteration,to%20the%20statement%20follwing%20the%20block.)
        * [**continue**](https://github.com/manojgayala/POPL1/blob/srikar/Specifications.md#user-content-while-loop:~:text=%7D-,Continue%20statement,count%20%2B%3Di%3B)
        * [**return**](https://github.com/manojgayala/POPL1/blob/srikar/Language%20Manual.md#user-content-jump-statement:~:text=The%20return%20statement%20is%20used%20to,represents%20the%20value%20to%20be%20returned.)


# Functions
Syntax and structure of functions : [**Function Declaration**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Examples.md#program-1-to-print-hello-world-using-tureasy)

Types of functions : [**pre-defined and user-defined**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Tutorial.md#user-content-functions:~:text=Functions%20are%20of%202%20types%3A%20pre%2Ddefined,user%2Ddefined%20functions%20as%20a%20better%20approach.)

Passing arguments : [**Pass by value & reference**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-pass-by-value-or-pass-by-reference:~:text=In%20Tureasy%20variables%20can%20be%20passed%20by%20reference%20or%20by%20value)

Tureasy supports various types of programming using functions like
- [**Functional paradigm**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-functional-paradigm:~:text=Tureasy%20also%20supports%20functional%20paradigm)

   **Functional paradigm** is a kind of good programming practice where programs are constructed by applying and composing functions. It is a declarative programming paradigm which is strongly recommended to use in Tureasy.

- [**Functional overriding**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-functional-paradigm:~:text=Overriding%20built%2Din%20functions)

   **Function overriding** is a practice where the pre-defined functions are overridden by the programmer to obtain more useful results from a function. This kind of programming is highly recommended when the programmer wants to observe or use intermediate results of the pre-defined function.

- [**Local functions**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-local-functions:~:text=The%20functions%20can%20be%20defined%20inside,as%20parameters.%20Here%20is%20an%20example)

   **Local functions** are special functions in Tureasy which uses the concept of nested functions. In short this mean that a function is return inside another function. This kind of programming is especially useful for efficiency of memory usage, customize the scope of parameters etc.,

Note that *functional paradigm* is supported by both *user-defined* and *pre-defined* functions whereas *function overriding* and *local functions* are supported by only user-defined functions.



# Strings
- [**Creating a string**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Tutorial.md#user-content-strings:~:text=Creating%20strings)

- [**String Operations**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Tutorial.md#user-content-creating-strings:~:text=World%E2%80%9D%3B-,String%20operations,In%20above%20example%20string%20concatenation%20operator%20%2B%20and%20string%20duplicate%20operator%20*%20were%20used.)

- [**Accessing characters**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-creations-of-strings:~:text=Accessing%20characters%20in%20a%20string)

- [**String Manipulation**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Tutorial.md#user-content-string-operations:~:text=Manipulating%20strings,the%20string%20OR%20length%20of%20string)

In addition to functions mentioned in string manipulation section there are:
function  |  task
--------  |  -----
str.ignore(List of sub-strings | Ignores the sub-strings passed as parameter and returs the concatenated characters from the residue. 
str.FindAll(str) 	| searches for the specified sub-string(str) and outputs position where it exists


Some exmples related to strings:
- [**Operations on strings**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-accessing-characters-in-a-string:~:text=String%20operations,%60%60)

- [**Checking existence**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-string-operations:~:text=Existence%20of%20substring%20within%20string%20can,the%20above%20method%20is%20case%20sensetive)

- [**Using strig functions**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-string-operations:~:text=Some%20Standard%20String%20functions,outputs%20length%20of%20string%20by%20default)



# Classes

Syntax of Classes :  [**Class Declaration**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-obscuring:~:text=Classes%3A,which%20is%20a%20given%20by%20class%2Dinitializer)

Body of the Class: [**Class Body**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-inherited-classes-and-parent-classes:~:text=Class%20BodyBody%20contains%20declaration%20of%20members%2C%20methods%2C%20constructors)
 

 - [**Members Syntax**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-syntax:~:text=members%3A,_var_declartion%20%2D%2D%3Eprivate%20members)
 
 - [**Methods Syntax**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-syntax-1:~:text=Syntax%3A-,methods%3A,.func%2Ddeclaration%20%2D%2D%3Eoverridden%20methods,-.)
 
 - [**Constructors Syntax**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-syntax-for-function-declarator:~:text=con%2Ddeclarator%20contains%20no%20identifier%20but%20only,also%20specified%20when%20there%20is%20inheritance.)


Constructors :
     

 - [**How to use multiple constructors (overloading)**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-constructors:~:text=Multiple%20constructors%20can%20be%20made%20for%20a%20class.)
 
 - [**Constructors for Singly Inherited Classes**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-private-methods:~:text=Inheritance,name%20%20in%20the%20class%20definition.%60%60)
 
 - [**Constructors for Multiple Inherited Classes**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-multiple-inheritance:~:text=*C%20inherit%20A%2CB,as%20in%20definition.%60%60)
 
 - [**Generic Constructors**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-constructor-for-inherited-classes:~:text=Generic%20Constructors,parameter%2Dlist.Only%20generic%20classes%20have%20generic%20constructors.)
 
 Methods:
 
 - [**Private methods**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-constructors:~:text=Private%20Methods,Private%20methods%20start%20with%20_%24.)
 
 - [**Inherited methods**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-inherited-methods:~:text=A%20class%20inherits%20all%20the%20public,type%20as%20of%20the%20inherited%20methods.)
 
 - [**Overridden methods**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-overriden-methods:~:text=Only%20the%20public%20methods%20that%20are,the%20parent%20class%2Didentifier%20if%20multiple%20inherited) & [**Polymorphism**]()
 
 - [**Overloaded methods**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-overloaded-methods:~:text=Two%20non%20%2Dprivate%20methods%20of%20a,of%20arguments%20of%20both%20the%20methods.)
 
 - [**Operator Overloading methods**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-local-functions:~:text=Functions%20for%20Operator%20Overridding)
  
    - Operator Overloading can be done only for the user-defined classes.
    


[**Syntax of tags**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Tutorial.md#user-content-overriding-and-overloading:~:text=*%25-,Tags)

[**Benefit of Tags**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Tutorial.md#user-content-overriding-and-overloading:~:text=*%25-,Tags)

[**Nested Tags**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Tutorial.md#user-content-overriding-and-overloading:~:text=*%25-,Tags)

[**Possible suggestions**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-generic-constructors:~:text=Tags%20and%20Turzers)

[**Common Tags**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-generic-constructors:~:text=Tags%20and%20Turzers)

[**Private Tags**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Tutorial.md#user-content-overriding-and-overloading:~:text=*%25-,Tags)

[**Security for data**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-tags-and-turzers:~:text=These%20turzers%20have%20an%20additional%20requirement%20of%20.tcnf%20files)

[**Working of tags**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-generic-constructors:~:text=Tags%20and%20Turzers)

[**Examples related**](https://github.com/manojgayala/POPL1/blob/srikar/Final%20Examples.md)____________________

### Code generation in tips
The tips given to users after compilation make use of metaprogramming internally. The data models in turzers have a specific sequence of instructions and try generating the code from that and based on user's abstract syntax tree. In cases when the code generation is not required, the tips are given in the form of possible explanation. These explanations are generated by the logical reasoning and the statements are also generated with `=>` separated.






