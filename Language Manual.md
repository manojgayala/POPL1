# Introduction
This manual describes the Tureasy language in detail. All the specifications related to language features and basic essentials are covered in subsequent sections. The reader is advised to go through the tutorial before referring to the manual for getting familiarised with the syntax and concepts of Tureasy. The manual is mainly intended for people who are comfortable to code in Tureasy and wish to explore precise rules about particular aspects of the language.
*This language manual is intended to help the readers dive in deep and explore more on details of Tureasy. The reader is assumed to have already gone thoroughly through the tutorial and is comfortable with coding in Tureasy in order to understand and get more familiarized with the base concepts of Tureasy. The topics will be more clear on going through subsequent sections of the manual.*

# Lexical Structure
A program in Tureasy undergoes several processing levels sequentially. After all the processing is done, the program is now been reduced to set a **tokens**.

## Tokens
Tureasy comprises of the following tokens:
* Identifiers
* Keywords
* Tags
* Constants
* String literals
* Operators

White space (blanks, tabs, comments, form feeds etc.,) are ignored in Tureasy since they separate tokens.

## Comments
Single-line comment: **~** (tilde) starts single-line comment. A multi-line comment is surrounded by **\`` \``** (two open quotes). Comments (both single and multi-line) cannot start within any instructions, string literals, character literals, integers etc.,

## Identifiers
Identifiers in Tureasy are a sequence of alphabets, digits and underscores. Identifiers are case-sensitive i.e., Tureasy and tureasy are different. An identifier should not begin with a digit or an underscore. Length of identifiers are not restricted. 

## Keywords

The following are the identifiers reserved to use only as keywords. 
| Keywords | | | | |
|---|---|---|---|---|
| *if* | *else* | *switch* | *case* | *default* |
| *for* | *while* | *do* | *break* | *continue* |
| *desc* | *asc* | *void* | *int* | *float* |
| *string* | *List* | *char* | *return* | *mem* |
| *met* | *con* | *new* | *here* | *inherit* |
| *parent* |

const, double, long, short, static, signed, unsigned

These words can't be used as variable names. In any usage of these identifiers as keywords, an error is popped up.

## Tags

## Constants
Constants in Tureasy are classified as
* Integer constants
* Character constants
* Float constants
* String constants

### Integer constants

### Character constants
Character constants are sequence of characters. Single-character constants are enclosed in '' eg., 'a'. Multi-character constants are implementation based.  Character constants or String constants (discussed later) can't represent newlines, tabs etc., These kind of special characters are represented by escape sequences shown below.

| Meaning | Escape sequence |
|---|---|
| newline  | \n | 
| backslash | \\\ |
| horizontal tab | \t |
| single quote | \\' |
| backspace | \b |
| double quote | \\" |

### Float constants
Floating point constants consists of 4 parts
	Decimal part
	Fraction part
	character 'e'
	Precision part

Eg., 10.83e-3 is same as 0.01083 where 10 is the decimal part, .83 is the fraction part and -3 defines the precision

### Strings constants
String constants also known as string literals are written in detail in the section String Literals.

## String Literals
String literals commonly called as Strings are a sequence of characters surrounded by " " (double
quotes). Two subsequent/adjacent strings are concatenated to form a single string where the end character '\0' of first string is combined with the next one. 
Array of strings can also be defined as integers whose behavior is implementation-defined.

# Types, values and Variables

# Names
## Declarations

Declarations provide the necessary properties of an identifier, they may or may not allocate storage to the identifier, it depends on the specifiers and the initializer.

### Syntax for Declarations
#### Variables:
   *declaration*: \
     *specifiers ini-declarator-list*

*specifiers:\
   storageclass-specifier specifiers<sub>opt</sub>*\
   *type-specifier   type-qualifier<sub>opt</sub> specifiers<sub>opt</sub>*
 
 *ini-declarator-list:\
   ini-declarator\
   ini-declarator-list , ini-declarator*

*ini-declarator:\
  declarator\
  declarator `=` initializer*

#### functions and Constructors:

*func-declaration:     -->for functions\
  `$`func-declarator `<<` type-specifier `'\n'` func-initializer* 

*con-declaration:      -->for constructors\
(paramerter-type-list)  `:`  `'\n'`  func-initializer*   





#### Classes:  
   *declaration: \
     `*`class-declarator `'\n'` class-initilaizer* <sub>opt</sub> 





### StorageClass Specifiers
These keywords specify the lifetime of a variable.`local` variables have a local lifetime and are allocated new storage each time execution control passes to the block in which they are defined.
Also they cannot be accessed outside of that block.Variables named with `static` or `global` specifiers have a memory allocated and exist throughout the program. 

#### Syntax:
storageclass-specifier: \
`local` \
`static` \
`global` 


### Type Specifiers

#### Syntax: 
`void` \
`int` \
`long` \
`class-identifier` \
`func-identifier` 


### Type Qualifiers

#### Syntax 
`const` \
`fluid` 

### Declarators 
Declarators declare a unique identifier and is a part of declaration.
The type of the variable(an array or a single variable) or the  parameters of a function are specified by the declarator. 

#### Syntax for variable declarator 
*declarator:  \
identifier \
declarator [constant-expression<sub>opt</sub>]  -->for arrays* 

#### Syntax for function declarator
*func-initializer: \
statements `%`* 

*statements: \
statement. \
statements statement<sub>opt</sub>* 

#### Syntax for Class declarator

*class-declarator:   \
class-identifier generic-type-specifier* 

*generic-type-specifier: \
`<<` type-specifier* 


### Initializers
When an object is declared it's value can be specified by a `initializer` then that declaration is called `definition`.

#### Variable initializers
*initializer: \
assigment-expression.   -->assigning a value \
{ initializer list }.   -->for an array \
`new` class-identifier (parameter-type-list).   -->calling a constructor. \
func-declarator*.  -->calling a function. 

*initialzer-list. \
initializer \
initialozer-list initlializer<sub>opt</sub>* 

#### Funciton initiliazers
*func-initializer:  -->also used for constructors. \
statements `%`* 

#### Class initializers

*class-initializer:  \
blk<sub>opt</sub> blk<sub>opt</sub>      blk<sub>opt</sub>*  

*blk: \
`mem:` statements `\` \
`con:` constructors `\` \
`met:` functions `\`* 


# Conversions:

### Integral Promotion:
Objects of data types which take less number of bits are converted to data types like int or unsigned int during operation. Such conversion is called integral promotion. If an int can represent the value of the original type, then it is converted to int; otherwise the value is converted to unsigned int.

### Integral Conversions:

Integral conversions are conversions between integral types. The integral types are char, short, int, long.
Signed to Unsigned: Objects of signed integral types can be converted to unsigned types.  Here, the actual bit pattern doesn't change. However, it's interpretation changes.
Unsigned to Signed: Objects of unsigned integral types can be converted to signed types.
If the unsigned value is outside the representable range of the signed type, the result won't have the correct value.

### Integer and Floating:
When an object of floating type is converted to an integral type, the fractional part is truncated. 
If the resulting value cannot be represented in the integral type, the behavior is undefined.
When a value of integral type is converted to floating, and the value is not exactly representable, then the result may 
be either the next higher or next lower representable value. If the result is out of range, the behavior is undefined.

### Floating Types:
A value of floating type can be safely converted to a more precise floating type with the value unchanged, i.e, conversions 
from float to double or from double to long double are safe.
When a value of floating type is converted to a less precise type and the value isn't representable precisely, it can be
converted to either the next higher or the next lower representable value. The result is undefined if result is out of range.

### Arithmetic Converisons:
Many binary operators cause conversions of operands, so as to bring them into the same type. These conversions are called arithmetic conversions.
| Condition: | Conversion: |
|------|---- |
|Either operand is of type long double | Other operand is converted to long double |
|Otherwise, if either operand is of type double | Other operand is converted to double |
|Otherwise, if either operand is of type float | Other operand is converted to float |
|Preceding conditions not met; and| |
|If either operand is of type unsigned long | Other operand is converted to type unsigned long |
|Otherwise, if either operand is of type long and the other of type unsigned int | Both operands are converted to type unsigned long |                          
|Otherwise, if either operand is of type long | Other operand is converted to type long |
|Otherwise, either operand is of type unsigned int | Other operand is converted to type unsigned int |
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
he operands must be bool type or must be convertible to it. The result's type is bool.

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

