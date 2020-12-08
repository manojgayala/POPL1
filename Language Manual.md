# Introduction
This manual describes the Tureasy language in detail. All the specifications related to language features and basic essentials are covered in subsequent sections. The reader is advised to go through the tutorial before referring to the manual for getting familiarised with the syntax and concepts of Tureasy.
# Tags and Turzers
The tags are special kind of statements which groups part of code which has some special implementation involved. It is used in this format 
` #<tag_name> code #!<tag_name>`

Some of the commonly used tags are


The tags provide programmers with tips related to
1. Parallelism	: 	There are some constructs of Tureasy which support parallel execution. The programs including such constructs would improve performance but are hard to code. The tags analyze the data and provide suitable constructs that could replace the existing code.
2. Constraints : The correctness of algorithms can be determined by finding base rules which must be satisfied throughout it. In large programs, it becomes practically impossible to keep track of these rules. So, the programmer could make use of constraint tags and the tag ensures that the property is maintained. In case of failure, it would suggest modifications for the same.
3. Memory optimization : The tags provide us with tips which could optimize memory too. There could be instances where the programmer might allocate heap memory but never use it or might use a lot of stack memory unnecessarily.
4. Time complexity : Tureasy tags try improving the code by understanding the code and providing us with better constructs that could help us reduce time complexity.

The tags use turzers during compilation to provide these tips. The tags are used to colour the nodes in the abstract syntax tree during the semantic analysis phase. During the compilation, an abstract syntax tree is formed after semantic analysis phase which undergoes machine independent code improvement. The turzers are used during this phase. 

Turzers are the files which contain the machine learning models for analyzing the data between tags. The abstract syntax tree is used as input for the turzers. The models within turzers are made using trees and its traversal has certain cost associated to it. The program is compared with these models and tips are given accordingly.

There are private turzers and private tags associated with companies. These turzers have an additional requirement of `.tcnf` files which are the turzer configuration files. These tags can be uniquely defined and modified by the company based on its requirements. 
# Conversions:
### Integral Promotion:
Objects of an integral type can be converted to another wider integral type, i.e, a type that can represent a larger set
of values. This widening type of conversion is called integral promotion. If an int can represent all the values of the
original type, then the value is converted to int; otherwise the value is converted to unsigned int.

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
```
Condition:                                                   Conversion:
* Either operand is of type long double                      Other operand is converted to long double
* Otherwise, if either operand is of type double             Other operand is converted to double
* Otherwise, if either operand is of type float              Other operand is converted to float
Preceding conditions not met;
* If either operand is of type unsigned long                 Other operand is converted to type unsigned long
* Otherwise, if either operand is of type long               Both operands are converted to type unsigned long
    and the other of type unsigned int                          
* Otherwise, if either operand is of type long               Other operand is converted to type long
* Otherwise, either operand is of type unsigned int          Other operand is converted to type unsigned int
* None of the previous conditions met                        Operands are converted to type int
```
# Expressions:
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
