# Introduction
This language manual is intended to help the readers dive in deep and explore more on details of Tureasy. The reader is assumed to have already gone thoroughly through the tutorial and is comfortable with coding in Tureasy in order to understand and get more familiarized with the base concepts of Tureasy. The topics will be covered precisely in the subsequent sections of the manual.

# Lexical Structure
A program in Tureasy undergoes several processing levels sequentially. After all the processing is done, the program is reduced to set a **tokens**.

## Tokens
Tureasy comprises of the following tokens:
* Identifiers
* Keywords
* Tags
* Constants
* String literals
* Operators

White space (blanks, tabs, comments, form feeds etc.,) are ignored in Tureasy since they separate tokens.

### Comments
Single-line comment: **~** (tilde) starts single-line comment. A multi-line comment is surrounded by **\`\` \`\`** (two open quotes). Comments (both single and multi-line) cannot start within any instructions, string literals, integers etc.,

## Identifiers
Identifiers in Tureasy are a sequence of alphabets, digits and underscores. Identifiers are case-sensitive i.e., *Tureasy* and *tureasy* are different. An identifier should not begin with a digit or an underscore. Length of identifiers are not restricted. 

## Keywords
The following are the identifiers reserved to use only as keywords. 
| Keywords | | | | |
|---|---|---|---|---|
| *if* | *else* | *switch* | *case* | *default* |
| *for* | *while* | *desc* | *break* | *continue* |
| *double* | *long* | *void* | *int* | *float* |
| *string* | *char* | *new* | *return* | *mem* |
| *met* | *con* | *parent* | *here* | *inherit* |
| *fixed* | *static* |

These words can't be used as variable names. In any usage of these keywords as identifiers, an error is popped up.

## Tags
Tags in Tureasy are used to identify the part of code that requires specific modifications. The nodes between the opening and closing tags are colored in the abstract syntax tree formed after the semantical analysis. They begin with **#** and end with **#!**. They should not be used between instructions. string literals, integers etc.

## Constants
Constants in Tureasy are classified as
* Integer constants
* Character constants
* Float constants
* String constants
* Tag constants

### Integer constants

### Character constants
Character constants are sequence of characters. Single-character constants are enclosed in '' eg., 'a'. Multi-character constants are implementation based.  Character constants or String constants (discussed later) can't represent newlines, tabs etc., These kind of special characters are represented by escape sequences shown below.

| Meaning | Escape sequence |
|---|---|
| newline  | \n | 
| backslash | \\\ |
| horizontal tab | \t |
| single quote | \\' |
| double quote | \\" |

### Float constants
Floating point constants consists of 4 parts
	Decimal part
	Fraction part
	character 'e'
	Exponential part

Eg., 10.83e-3 is same as 0.01083 where 10 is the decimal part, .83 is the fraction part and -3 defines the exponent.

### String constants/literals
String literals commonly called as Strings are a sequence of characters surrounded by " " (double
quotes). Two strings separated by '+' are concatenated to form a single string where the end character '\0' of first string is replaced by the next string and '\0' is added at the end. 
Array of strings can also be defined as integers whose behavior is implementation-defined.

# Types, values and Variables
### Variables:
Identifier is the name you supply for a variable in your program. They must differ in spelling and case from any keywords, i.e,
keywords cannot be used as identifiers as they are reserved for special use.
Syntax: *identifier*
```
    nondigit: _ a b c d e f g h i j k l m n o p q r s t u v w x y z 
                A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
    digit: 0 1 2 3 4 5 6 7 8 9
    The first character of the identifier must be a nondigit.
```

# Names
Names a.k.a identifiers are entities that are declared at some point of the code. They have a scope, the part of code where it is known and a binding, the region of code where a specific location is associated with it. The names also get shadowed sometimes when their linkage is changed. This will be covered in subsequent sections.

## Declarations
Declarations provide the necessary properties of an identifier, they may or may not allocate storage to the identifier, it depends on the specifiers and the initializer.

### Syntax for Declarations
#### Variables:
   *declaration*: \
     *specifiers ini-declarator-list*

*specifiers:\
   storageclass-specifier specifiers<sub>opt</sub>*\
   *type-specifier   type-qualifier<sub>opt</sub> specifiers<sub>opt</sub>*
 
 ini-declarator-list contains contains the identifiers being declared and specifiers contain the sequence of type and storage class specifiers  which interpret the variable.
 
 *ini-declarator-list:\
   ini-declarator\
   ini-declarator-list , ini-declarator*

ini-declarator contains a declarator and also an initializer if the variable is allocated a memory.

*ini-declarator:\
  declarator\
  declarator `=` initializer*

#### functions and Constructors:

func-declaration along with the declarator also contain the definition of the function which is a given by func-initializer

*func-declaration:     -->for functions\
  `$`func-declarator `<<` type-specifier `'\n'` func-initializer* 
  

func-initializer is seperated by the remaining part of the declaration syntax by `\n` 

con-declaration contain declarator and the definition of the constructor 
which is also given by func-initializer simialr to the functions.

*con-declaration:      -->for constructors\
con-declarator  `'\n'`  func-initializer*   





#### Classes:  

class-declaration along with the declarator also contain the definition of the class which is a given by class-initializer

   *declaration: \
     `*`class-declarator `inherit`<sub>opt</sub>  parent-class-list<sub>opt</sub> `'\n'` class-initilaizer*  

parent-class-list contains sequence of parents(if inherited) of the current class being declared.

*parent-class-list: \
parent-class-identifier
parent-class-list parent-class-identifier<sub>opt</sub>*




### StorageClass Specifiers
These keywords specify the lifetime and scope of a variable.`local` variables have a local lifetime and are allocated new storage each time execution control passes to the block in which they are defined.
Also they cannot be accessed outside of that block.Variables named with `static` or `global` specifiers have a memory allocated and exist throughout the program. 

#### Syntax:
*storageclass-specifier:* \
`local` \
`static` \
`global` 


### Type Specifiers
Type Specifiers specify the data-type of a variable or the class of an object.They also determine the  location of variable in the memory layout.
#### Syntax: 
*type-specifiers:* \
`void` \
`int` \
`long` \
`class-identifier` \
`func-identifier` 


### Type Qualifiers
These specify the modifiability of a variable or an object.
#### Syntax 
`const` \
`fluid` 

`const` variables and objects cannot be changed after being initialized
 and fluid variables and objects can be changed or modified at any time of the program. If no qualifier is specified, then it is qualified as `fluid` by default.

### Declarators 
Declarators declare a unique identifier and is a part of declaration.
The type of the variable(an array or a single variable) or the  parameters of a function are specified by the declarator. 

#### Syntax for variable declarator 
*declarator:  \
identifier \
declarator [constant-expression<sub>opt</sub>]  -->for arrays* 

#### Syntax for function declarator

 *func-declarator:  \
 func-identifier (parameter-list)*  

parameter-type-list is the list of formal parameters required by the function. 

*parameter-list: \
parameter-declaration \
parameter-list , parameter-declaration*

*parameter-declaration: \
specifiers declarator* 

con-declarator contains no identifier but only the parameters to be passed, also the parameters of the parent class constructor are also specified when there is inheritance.

*con-declarator:  \
(parameter-type-list) \
con-declarator`:`(parameter-type-list)<sub>opt</sub> --> to specify the parent class constructor.*




#### Syntax for Class declarator
Class-declarator contains its identifier and also a generic-type-specifier if the class is a generic class.

generic-type-specifier can take any name other than the keywords of tureasy and the type is resolved at the time of object creation.

*class-declarator:   \
class-identifier `<<`  generic-type-specifier* 





### Initializers
When an object is declared it's value can be specified by a `initializer` then that declaration is called `definition`.

#### Variable initializers
*initializer: \
assigment-expression.   -->assigning a value \
{ initializer list }.   -->for an array \
`new` class-identifier (parameter-list).   -->calling a constructor. \
func-declarator*.  -->calling a function. 

initializer-list contains the list of initializers seperated by comma.

*initializer-list. \
initializer \
initializer-list , initlializer<sub>opt</sub>* 

#### Function initializers
func-initializer contains the code of the function/constructor ended with `%`

*func-initializer:  -->also used for constructors. \
statements `%`* 

'statements' is a series of statements which determine the functionality of the function.

*statements: \
statement. \
statements statement<sub>opt</sub>* 
#### Class initializers
Class-initializer can contain atmost three blocks 

*class-initializer:  \
block<sub>opt </sub>`\n` block<sub>opt</sub>`\n`      block<sub>opt</sub>* ` *% `

*block: \
`mem:` declarations  \
`con:` constructors  \
`met:` functions* 

Each block is used atmost once.


# Conversions:

### Integral Promotion:
Objects of data types which take less number of bits are converted to data types like int during operation. Such conversion is called integral promotion. If an int can represent the value of the original type, then it is converted to int.

### Integral Conversions:
Integral conversions are conversions between integral types. The integral types are char, short, int, long. Tureasy has no data types for unsigned values, so there are no integral conversions for the same.

### Integer and Floating:
When an object of floating type is converted to an integral type, the fractional part is truncated. 
If the resulting value cannot be represented in the integral type, the behavior is undefined.
When a value of integral type is converted to floating type and the value is not exactly representable, then the result may 
be either the next higher or next lower representable value. If the result is out of range, the behavior is undefined.

### Floating Types:
A value of floating type can be safely converted to a more precise floating type with the value unchanged, i.e, conversions 
from float to double or from double to long double are safe.
When a value of floating type is converted to a less precise type and the value isn't representable precisely, it can be
converted to either the next higher or the next lower representable value. The result is undefined if result is out of range.

### Arithmetic Converisons:
Many binary operators cause conversions of operands, so as to bring them into the same type. These conversions are called arithmetic conversions. These are mostly widening conversions where a lower sized data type gets converted to higher sized data type.
| Condition: | Conversion: |
|------|---- |
|Either operand is of type long double | Other operand is converted to long double |
|Otherwise, if either operand is of type double | Other operand is converted to double |
|Otherwise, if either operand is of type float | Other operand is converted to float |                       
|Otherwise, if either operand is of type long | Other operand is converted to type long |
|None of the previous conditions met | Operands are converted to type int |

# Expressions
The expressions are vital to the language. The expressions are evaluated for their side effects (assiginment to variables) or for their values in larger expressions as operands or to affect the execution sequence in statements. The evaluation of expressions would yield one of the following :
-> a variable 
-> a value
-> void
The expression's evaluation respects the rules of precedence and parenthesis.

### Primary Expressions
The simplest form of expressions from which others are constructed are called primary expressions. It includes strings, constants and identifiers. Strings are built in data types in Tureasy, constants and identifiers have been mentioned in Lexical structure section.

### Cast:
The type_name is a type and cast_expression is a value to be converted to that type.
```
    type_name(cast_expression)
```
The cast_expression is taken as input and the method yields its casted value. When there is upcasting (lower memsize to higher memsize), the value is retained as it is so it is done implicitly when required. The downcasting (higher to lower) leads to loss of data and precision, which happens during assignments implicitly. 

### Array references
For accessing an element of array, postfix expression followed by square brackets including another expression is used. Eg. A[b] refers to array named A and the bth index of array.

### Function calls 
The function call is an expression followed by paranthesis which include arguments to be passed to the function. The arguments are separated by comma and in case some value is returned from the function, it is assigned to an lvalue. The standard integral promotions and conversions take place when the types of parameters in function declaration and arguments do not agree.

### Class references
The members or methods of a class can be accessed by using an expression followed by `.` and another expression. The first expression refers to the class name and the second expression refers to the member or method. Public methods and members can be accessed anywhere but the private members can be accessed using this expression only within the class definition.

### Tag expressions
They mark the beginning and end of tags. They use the operator `#` for beginning and end with `#!`. The data between these expressions undergo analysis during compilation.

### Unary operators
These operators work with single operands. These operators include `: ! memsize()`
The expression :a is used for the bitwise negation of a. The operand must be integer or character which could be type casted to int using its ascii value.
The expression !a is used for logical negation of a. The operand is treated to be true for integral value of 0 or NULL, in all other cases it yields false.
The expression memsize(A) is used to find out the memory allocated to final result of A expression. Even objects of classes can be operands of this operator.

### Multiplicative Operators:
The operators * , / , and % are called the multiplicative operators. 
These are syntactically left-associative (i.e, they group left-to-right) and have the same precedence.
```
    Expression * Expression
    Expression / Expression
    Expression % Expression
```
The binary operator * denotes multiplication, with the operands of arithmetic type. 
And the binary operator / yields the quotient, which also has both the operands of arithmetic type. 
While the % operator the remainder of the division of the first operand by the second. Here both the operands must have integral type. 
Incase the second operand is 0 in any of the operators / and % the result is undefined. 
But it is always guaranteed that the absolute value of the remainder is smaller than that of the divisor.

### Additive Operators:
The addition operator + and subtraction operator - are called additive operators. These are left-associative.
```
Expression + Expression
Expression - Expression
```
The operands can be integral or floating values.
The result of the + operator is the sum of the operands while the result of the - operator is the difference of the operands.

### Shift Operators:
The left shift operator << and right shift operator >> group left-to-right.
```
Expression1 << Expression2
Expression1 >> Expression2
```
The << operator causes the bits in Expression1 to be shifted to the left by the number of positions specified in Expression2.
The bit positions that have been vacated by the shift operation are zero-filled.
The >> operator causes the bits in Expression1 to be shifted to the right by the number of positions specified in Expression2.
For both operators, each operand must be integral. The result is undefined if the right operand is negative, or greater than or equal 
to the number of bits in the Expression1's type in left shift.

When the first operand is function declaration for << operator, it means that the return type of function is second operand.
When the first operand is one of the generic types for >> operator it means that the second operand is its type.

### Relational Operators:
The binary operators: less than (<), greater than (>), less than or equal to (<=), greater than or equal to (>=) are
called relational operators and have left-to-right associativity.
```
Expression < Expression
Expression > Expression
Expression <= Expression
Expression >= Expression
```
These operators support integral or floating-point numeric type. 
The char type also supports these operators. In this case, the corresponding character codes are compared.
Here, the result type is bool. If the relationship in the expression is false, the value returned is false(0); otherwise true(1).

### Equality Operators:
The equality operators equal to(==) and not equal to(!=) compare their operands for equality and inequality.
```
Expression == Expression
Expression != Expression
```
These operators are analogous to Relational Operators, i.e, they support integral or floating-point numeric type and 
also string type. The result type is bool.
The == operator returns true(1) if both operands have the same value; otherwise, it returns false(0). 
The != operator returns true(1) if the operands don't have the same value; otherwise, it returns false(0).

### Bitwise AND Operator:
The & operator compares each bit of the first operand to the corresponding bit of the second operand. 
If corresponding bits are 1, the result bit is set to 1. Otherwise, the result bit is set to 0.
```
Expression & Expression
```
Both operands must have integral types. The usual arithmetic conversions are performed.

### Bitwise Exclusive OR Operator:
The ^ operator compares each bit of the first operand to the corresponding bit of the second operand. 
If one bit is 0 and the other bit is 1, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0.
```
Expression ^ Expression
```
Both operands must have integral types. The usual arithmetic conversions are performed.

### Bitwise Inclusive OR Operator:
The | operator compares each bit of the first operand to the corresponding bit of the second operand. 
If either bit is 1, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0.
```
Expression | Expression
```
Both operands must have integral types. The usual arithmetic conversions are performed.

### Logical AND Operator:
The && operator returns true if both operands are true, otherwise false. This operator groups left-to-right.
If either operand is false, the result is false. If the first operand is false, the second operand is not evaluated.
```
Expression && Expression
```
The operands must be bool type or must be convertible to it. The result's type is bool.

### Logical OR Operator:
The || operator returns true if either or both operands is true, otherwise false. This operator groups left-to-right.
The second operand is evaluated only if the first operand evaluates to false.
```
Expression || Expression
```
The operands must be bool type or must be convertible to it. The result's type is bool.

### Conditional Expression Operator:
```
Expression0 ? Expression1 : Expression2
```
The Expression0 must have bool type or must be convertible to it.
If Expression0 unequals 0, Expression1 is evaluated. So, the result of the expression is given by the Expression1.
If Expression0 equals 0, Expression2 is evaluated. So, the result of the expression is the value of Expression2.
So in any case only one of Expression1, Expression2 is evaluated. And if both operands have void type, the result type is void.

### Assignment Operator:
Here, the value of the right-hand operand is assigned to the storage location named by the left-hand operand. Therefore, the left-hand operand must be a modifiable lvalue. There are operators of the form `op=` that perform the operation op between value stored in lvalue and right-hand operand and then assignment is done to lvalue.
```
Assignment_Operator:  = *= /= %= += -= <<= >>= &= ^= |=
Expression1 Assignment_Operator Expression2
```
### Comma Operator
It is used to separate the data in grouping of elements. The groups can be arguments to functions, the array elements, the generic type elements etc.
```
Expression1,Expression2
```

# Blocks and Statements
# Statements
Statements in tureasy are executed in sequence. The statements of a program control the flow of program execution. They are executed for their effect and do not have values. Statements can have internal componentes such as expressions. Statements are begin with identifiers like if,for,etc. Often statement keywords are reserved such that they cannot be used as names of variables or functions. statements are terminated by ';'. They fall into several groups.  

   * labeled-statement
   * expression-statement 
   * compound-statement 
   * selection-statement 
   * iteration-statement 
   * jump-statement 

### labeled statements
Statements may carry label prefixes. A label is an identifier used to flag a location in a program as the target of a goto statement or switch statement.A simple identifier followed by a colon (:) is a label. \

   *labeled-statement: \
         identifier : statement \
         case constant-expression : statement \
         default : statement* \
         
A label name must be unique within the function in which it appears.  Label_identifier has a function scope and the same label cannot be redefined within the same function.  Because labels have their own name space, they do not interfere with other identifiers and cannot be redeclared. \
Within switch statements, case and default labeled statements exist. A statement of the form
`case constant-expression : statement`
indicates that control will pass to this statement if the value of the control expression of the switch statement matches the value of the constant-expression. (In this case, the type of the constant-expression must be an integer or character.) A statement of the form
`default : statement`
indicates that control will pass to this statement if the control expression of the switch statement does not match any of the constant-expressions within the switch statement. If the default statement is omitted, the control will pass to the statement following the switch statement. Within a switch statement, there can be only one default statement, unless the switch statement is within another switch statement. 
### expression statements
Most statements are expression statements, which have the form \

   *expression-statement: \
        expression <sub>opt</sub>;* \
        
Expression statements do all of the real work in a program. expression statements are used for assignments and function calls.. All side effects from the expression are completed before the next statement is executed. An empty expression statement is called a null statement. Expressions and expression statements can be arbitrarily complicated. They don't have to consist of exactly one simple function call, or of one simple assignment to a variable. For one thing, many functions return values, and the values they return can then be used by other parts of the expression.
### compound statement
A compound statement (also called a "block") typically appears as the body of another statement, such as the if statement. A compound statement groups multiple statements into a single statement. Declarations and Types describes the form and meaning of the declarations that can appear at the head of a compound statement.

*compound-statement:\
 declaration-list<sub>opt</sub> statement-list<sub>opt</sub> \
declaration-list:\
  declaration\
  declaration-list declaration*

*statement-list:\
  statement\
  statement-list statement*
  
If there are declarations, they must come before any statements. The scope of each identifier declared at the beginning of a compound statement extends from its declaration point to the end of the block. It is visible throughout the block unless a declaration of the same identifier exists in an inner block.\
Function and class definitions are also syntactically compound statements.

### selection/conditional statement
Selection statements choose one of several flows of control. There are 3 types of selection staements in tureasy: 
* if
* if else
* switch

*selection-statement:\
if expression statement\
if expression statement else statement\
switch (expression) statement*\

In both forms of the if statement, the expression, which must have arithmetic or pointer type,is evaluated, including all side effects.\
If statement:\
In if statement the sub statement or the block will only be executed if the expression is true i.e.the expression value is non zero.\
If else statement:\
In this type of if statement , first substatement will only be executed if expression is non zero, otherwise the second sub statement(under else) is executed which mathches with closest unmatched if(i.e. nested at same level).\
switch statements: \
The switch statement causes control to be transferred to one of several statements depending
on the value of an expression, which must have integral type. The expression here is an integer or a character. The statement here is usually compound and it contains case-labeled statements and optionally a default-labeled statement.refer`labeled statements`. The compound statement should not have local variables as the jump to an internal label may skip over the initialization of such variables. 

### iteration statement
Iteration statements specify looping. There are 2 kinds of iterative statements: for and while.

*iteration-statement:\
while expression statement \
for  type : (low,;high) statement \
for  list*\
In while statements, the substatements are executed repeatedly as long as the expression is non zero, the expression has arithmetic type. If the control expression evaluates to zero the first time through, the substatement may not run at all. With while, the test, including all side effects from the expression, occurs before each execution of the statement.\

In `for` statement, the loop runs till expression is less then high. By default the count is incremented by 1. he for statement lets you repeat a statement or compound statement a specified number of times. The body of a for statement is executed zero or more times until an optional condition becomes false.  Side-effects from each expression are completed immediately after its evaluation.\
The for loop can be used to traverse a list or an array. For loop traverses all the elements of a list.\
A for statement also terminates when a break, goto, or return statement within the statement body is executed. A continue statement in a for loop causes loop-expression to be evaluated. When a break statement is executed inside a for loop, loop-expression is not evaluated or executed. 

### jump statement
Jump statements transfer control unconditionally. \
*jump-statement:\
goto identifier;\
continue;\
break;\
return expression<sub>opt</sub>;\

In the `goto` statement, the identifier must be a label located in the current function. Control transfers to the labeled statement.

The `continue` stayement appears only in iteration statements. It is used within the substatement of iteration statements to transfer control flow to the place just before the end of the substatement. 

The `break` statements appperar in iteration and switch statements and terminates execution of the smallest enclosing such statement , control passes to the statement follwing terminated statemnt.

A function returns caller by the `return` statement. If the function return type is void, the function may not return a value; otherwise, the expression represents the value to be returned. 



# Classes
This section covers the basic semantics of Classes and how they are implemented.

Body of the class contains members, constructors, methods declared in `mem`,`con`,`met` blocks respectively.Classes can have subclasses 

   *declaration: \
     `*`class-declarator `inherit`<sub>opt</sub>  parent-class-list<sub>opt</sub> `'\n'` class-initilaizer <sub>opt</sub>* 

Complete syntax is specified [here](#declarations)
   
   This is the basic declaration of a class where *class-declarator* specifies whether the class is a *normal class* or a *generic class*(a class which uses generic type variables which has different declarations among different instances of the class) along with the name of the class *class-identifier*

## Generic class declaration 
```
*GenClass << G
mem:
G g;
met:
$display() << void 
write(g)
%
*%

$main << void
GenClass << int x;
GenClass << string y;
%
```

## Inherited Classes and Parent Classes

Parent classes of a class can be specified using the `inherit` keyword, these specified class are called *immediate parent classes*
and the latter class is called the *immediate inherited or subclass*.

Subclass relation is transitive closure of the *immediate subclass* relation.

```
*A inherit B,C
mem:
int x:
*%
*B inherit D
mem:
int y
*%
```
here,A is both subclass of B, C and also D.  
B, C are the immediate parentclasses of A \
D is a parentclass of B.

## Class Body
Class Body contains declaration of members, methods, constructors
```
*Class
mem:
var-declarations ...
met:
functions ...
con:
contructors ...
*%
```
This is the general body of a class.Scope of all the members and functions that are declared in or inherited in, is the  entire body of the Class.

## Class Members

 There are three types of members 
                   1.  members that are inherited from its immediate parentclass.
                   2. members are declared  public in this class
                   3. members that are declared private in this class.
     
   Methods which are inherited should not be declared again.  
  
  #### Syntax:
  *members:* \
  *`mem:` mem-declaration-list* 
  
 *mem-declaration-list: \
 mem -declaration \
 mem-declarations mem-declaration<sub>opt</sub>*	
 	
*mem-declaration: \
 var-declaration --> public members   \
`_`var_declartion -->private members*      

Every member of the class can be accessed through `this` keyword.
        
## Class Methods
There are five types of methods:

 1. Methods which are inherited from its immediate parent class.
 2. Methods which are declared public in the this class
 3. Methods which are declared private in this class
 4. Methods which are overridded in this class
 5. Methods which are overloaded in this class.

#### Syntax:
*methods:* \
*`met:` met-declaration-list* 

*met-declaration-list: \
met-declaration \
met-declaraion-list met-declaration<sub>opt</sub>*

*met-declaration:
func-declaration  -->public and overloaded methods \
`_`func-declaration  -->private methods \
`.`func-declaration -->overridden methods.*      

  Every method of the class can be accessed through `this` keyword.     
 
 Methods of a generic class can use the generic type to declare objects in their code and can even return the generic type.These methods are called `generic methods`.

### Inherited methods
A class inherits all the public members and methods from its immediate parent class.
No other method in the class should have the same method 
signature(name and parameter-list) and the return type as of the inherited methods.

There is an exception in the inheritance of public methods when multiple inheritance is occurred. All the common public  methods of the parent classes have to be overridden in the present class or one method can be chosen using `parent` keyword.

### Overriden methods
Only the public methods that are inherited from the parent class can be overridden.Even if the methods are overridden ,the old methods can be invoked using the `parent` keyword (folllowed by the parent class-identifier if multiple inherited)

The overridden method has to be public.

Overridden methods should have the same set of parameters as the parent method but the return type can be different.
```
*Parent
met:
$foo(int x) << int
return 1;
%

*Sub inherit Parent
met:
.$foo(int x) << string.      ~overridded method with different return type.
return '1'
%

```


### Overloaded methods
Two  non -private methods  of a class having same name with different arguments are called overloaded methods.
Resolving the methods is done at compile-time using the set of arguments of both the methods.

Return types of overloaded methods may or may not be same.
```
*Parent
mem:
int x;
met:
 $getX() << int
  return x;
 %
*%
*sub inherit Parent
mem:
float x;
met:
 $getX() << float
  return x;
 %
 *%
 ```
 This return compile-time error as both the getX methods have no difference in their parameter -list to resolve.
 ## Class Constructors
 A constructor is used in the creation of an object that is an instance of a class.
 #### Syntax:
*constructors:*
 *`con:` con-declaration-list \
con-declaration-list* 

*con-declaration: \
con-declaration-list con-declaration<sub>opt</sub>*

Syntax of con-declaration is specified [here](#syntax-for-function-declarator) 

Constructors are identified through their parameter list and they don't need a particular  identifier because by default,*class-identifier*(name) is taken as the identifier of the constructor.


```
*Node
mem:
int x,y
con:
(int x,int y)
here.x = x;
here.y = y;
%
*%
```


*parameter-type-list* is same as the formal parameter list used for the methods and functions

### Constructor overloading
It is similar to method overloading ,to overload a constructor formal parameter list has to be unique for both the constructors otherwise it is a compile-time error.

### Constructor for Inherited Classes
When a class inherits an other class at the time of creation of object, the parentclass constructor should be called before the present class's constructor. So the constructor has to specify the parent's constructor to be called through its parameter-list after specifying the current class' list.
If multiple inheritance has taken place, the parameter-lists has to be specified sequentially in the same order.
```
*Parent
mem:
int x,y;
con:
(int x,int y)
here.x = x;
here.y = here.y;
%
*%

*Child inherit Parent
mem:
int z;
con:
(int z):(int x,int y)
  here.z = here.z + parent.x +parent.y;
 %
*%
```
### Generic Constructors
Constructors can also declare objects of generic type and the generic type can also be specified in the parameter-list.Only generic classes have generic constructors.
```
*GenClass << G
mem:
G g;
met:
$display() << void 
write(g)
%
con:
(G g)
here.g = g;
%
*%
```

# Tags and Turzers
The tags are special kind of statements which groups part of code which has some special implementation involved. It is used in this format 
` #<tag_name> code #!<tag_name>`

Some of the commonly used tags are

|	|	|	|	|	|
|---	|---	|---	|---	|---	|
|	|	|	|	|	|
|	|	|	|	|	|
|	|	|	|	|	|
|	|	|	|	|	|
|	|	|	|	|	|

The tags provide programmers with tips related to
1. Parallelism	: 	There are some constructs of Tureasy which support parallel execution. The programs including such constructs would improve performance but are hard to code. The tags analyze the data and provide suitable constructs that could replace the existing code.
2. Constraints : The correctness of algorithms can be determined by finding base rules which must be satisfied throughout it. In large programs, it becomes practically impossible to keep track of these rules. So, the programmer could make use of constraint tags and the tag ensures that the property is maintained. In case of failure, it would suggest modifications for the same.
3. Memory optimization : The tags provide us with tips which could optimize memory too. There could be instances where the programmer might allocate heap memory but never use it or might use a lot of stack memory unnecessarily.
4. Time complexity : Tureasy tags try improving the code by understanding the code and providing us with better constructs that could help us reduce time complexity.

The tags use turzers during compilation to provide these tips. The tags are used to colour the nodes in the abstract syntax tree during the semantic analysis phase. During the compilation, an abstract syntax tree is formed after semantic analysis phase which undergoes machine independent code improvement. The turzers are used during this phase. 

Turzers are the files which contain the machine learning models for analyzing the data between tags. The abstract syntax tree is used as input for the turzers. The models within turzers are made using trees and its traversal has certain cost associated to it. The program is compared with these models and tips are given accordingly.

There are private turzers and private tags associated with companies. These turzers have an additional requirement of `.tcnf` files which are the turzer configuration files. These tags can be uniquely defined and modified by the company based on its requirements. 

