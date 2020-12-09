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
con-declarator  `'\n'`  func-initializer*   





#### Classes:  
   *declaration: \
     `*`class-declarator `inherit`<sub>opt</sub>  parent-class-list<sub>opt</sub> `'\n'` class-initilaizer <sub>opt</sub>* 

*parent-class-list:
parent-class-identifier
parent-class-list parent-class-identifier<sub>opt</sub>*




### StorageClass Specifiers
These keywords specify the lifetime of a variable.`local` variables have a local lifetime and are allocated new storage each time execution control passes to the block in which they are defined.
Also they cannot be accessed outside of that block.Variables named with `static` or `global` specifiers have a memory allocated and exist throughout the program. 

#### Syntax:
*storageclass-specifier:* \
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

`const` variables and objects cannot be changed after being initialized
 and fluid variables and objects can be changed or modified at any time of the program.If no qualifier is specified it i defaultly qualified as `fluid`

### Declarators 
Declarators declare a unique identifier and is a part of declaration.
The type of the variable(an array or a single variable) or the  parameters of a function are specified by the declarator. 

#### Syntax for variable declarator 
*declarator:  \
identifier \
declarator [constant-expression<sub>opt</sub>]  -->for arrays* 

#### Syntax for function declarator

 *func-declarator: \
 func-identifier (parameter-type-list)* 

*con-declarator: \
(parameter-type-list) \
con-declarator`:`(parameter-type-list)<sub>opt</sub> --> to specify the parent class constructor.*




#### Syntax for Class declarator

*class-declarator:   \
class-identifier `<<`  generic-type-specifier* 





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
initializer-list initlializer<sub>opt</sub>* 

#### Function initializers
*func-initializer:  -->also used for constructors. \
statements `%`* 

*statements: \
statement. \
statements statement<sub>opt</sub>* 
#### Class initializers

*class-initializer:  \
block<sub>opt</sub> block<sub>opt</sub>      block<sub>opt</sub>*  

*block: \
`mem:` declarations  \
`con:` constructors  \
`met:` functions*

# Conversions:

### Integral Promotion:
Objects of data types which take less number of bits are converted to data types like int or unsigned int during operation. Such conversion is called integral promotion. If an int can represent the value of the original type, then it is converted to int; otherwise the value is converted to unsigned int.

### Integral Conversions:

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
                      ` CONTINUE EDITING`
### Cast:
The type_name is a type and cast_expression is a value to be converted to that type.
```
    (type_name) cast_expression
```
The cast_expression is converted as if it had been assigned to a variable of type type_name. An expression with a type cast is not an l-value.
Legal Casts: Casting an integral or floating point value to integral type; Casting an arithmetic type to floating type  

### Multiplicative Operators:
The operators * , / , and % are called the multiplicative operators. 
They are syntactically left-associative (i.e, they group left-to-right) and have the same precedence.
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
The addition operator + and subtraction operator - are called additive operators. These group left-to-right.
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
to the number of bits in the Expression1's type.

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
also char type(character codes are compared). And the result type is bool.
The == operator returns true(1) if both operands have the same value; otherwise, it returns false(0). 
The != operator returns true(1) if the operands don't have the same value; otherwise, it returns false(0).

### Bitwise AND Operator:
The & operator compares each bit of the first operand to the corresponding bit of the second operand. 
If both bits are 1, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0.
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
The operands need not have the same type, but each must have boolean or integral type. The result's type is bool.

### Logical OR Operator:
The || operator returns true if either or both operands is true, otherwise false. This operator groups left-to-right.
The second operand is evaluated only if the first operand evaluates to false.
```
Expression || Expression
```
The operands need not have the same type, but each must have boolean or integral type. The result's type is bool.

### Conditional Expression Operator:
```
Logical-OR Expression ? Expression1 : Expression2
```
The Logical-OR Expression must have integral or floating type.
If Logical-OR Expression unequals 0, Expression1 is evaluated. So, the result of the expression is given by the Expression1.
If Logical-OR Expression equals 0, Expression2 is evaluated. So, the result of the expression is the value of Expression2.
So in any case only one of Expression1, Expression2 is evaluated. And if both operands have void type, the result type is void.

### Assignment Operator:
Here, the value of the right-hand operand is assigned to the storage location named by the left-hand operand. Therefore, the 
left-hand operand must be a modifiable l-value. After the assignment, the value of assignment expression is the value stored 
in the left operand and it's type is that of the left operand.
```
Assignment_Operator:  = *= /= %= += -= <<= >>= &= ^= |=
Expression1 Assignment_Operator Expression2
```

# Blocks and Statements

# Classes
This section covers the basic semantics of Classes and how they are implemented.

Body of the class contains members, constructors, methods declared in `mem`,`con`,`met` blocks respectively.Classes can have subclasses 

   *declaration: \
     `*`class-declarator `inherit`<sub>opt</sub>  parent-class-list<sub>opt</sub> `'\n'` class-initilaizer <sub>opt</sub>* 

Complete syntax is specified **here**
   
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
B, C are the immediate parentclasses of A 
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
  *members:*
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
*methods:*
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

*con-declaration:
con-declaration-list con-declaration<sub>opt</sub>*

Syntax of con-declaration is specified **here** \

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

