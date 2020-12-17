# Criticism of Tureasy

Tureasy as the name suggests is simple, easy to code and understandable programming language. But there is something more the name supports.
It helps the programmer improve her programming skills by giving advices in the same way as elders/professionals nurture newbies.

When a program of tureasy is seen superficially for the first time, it seems to have more symbols and one can be intimidated by that. But this is one of the most important things that helps the programmer makes the language more compact and easy as they eventually become more comfortable with the symbols than using large keywords.

## Insights into some domains of Tureasy.

 ### Variables - precisely sufficient.
Tureasy has an optimal range of primitive datatypes to make things clear for the user. For Eg: Tureasy doesn't provide any datatypes for the unsigned numbers because their usage can be served by other ways in tureasy (larger data types) ensuring that the behaviour of variables is not complicated.
**It has a sufficient range to let the user choose the type, having suitable size and properties.**

   Along with the primitives, tureasy has many special datatypes in its libraries which are useful for the programs demanding non-trivial data structures.Also users can create their own datatypes by abstracting them using the concept of [classes](### Classes and OOPs) and objects.

Tureasy provides storage class specifiers and type specifiers to choose the scope and rigidity of the variable.Even though out of the scope variables cannot be accessed or can be updated, tureasy boldly presents a way to change the value of a variable in functions called at the moment, with a single symbol `@` a variable can be passed by reference i.e a procedure can change the parameter values
and reflect those changes in the caller scope. 
      This doesn't seem to be convincible for the users who have experience in other languages but tureasy provides this ability, by dealing the things at the backend and for the sake of abstraction.


### Statements and Blocks - rendering  hierarchy.
 Tureasy provides all the types of statements that are needed to express logic  in a programming language. i.e **Tureasy is Turing Complete.** (of course it will, as it is dedicated to the legend.)
       
The formatted labelling of the some statements  make the control flow easier to manage.These statements can contain multiple expressions which makes the language more compact.

Block of statements(Compound statements) in tureasy brings the concept of scope.These blocks are surrounded or bounded by the end of a statement for which it is considered as a body and ended with typically with a `\` .

But some blocks end with a different identifier.Functions end with a `%` and classes end with a `*%`.
having different identifications for blocks depending on their hierarchical position, lets the code be more structured and also improves the readability of the program.
 
 These bounds for the blocks seem to be sensitive(not so rigid) but actually they are theoretically sufficient to detect a block and makes the compilation simpler.One way to use it effectively is to mention the end of block by `\` at the time when the block is created.
 
Iterative statements in Tureasy provide an intuitive way to iterate over a collection of variables or over a range,In both these cases the implementation is the same as they are abstracted accordingly.


### Functions - 	both a procedure and a pure function.

Function in a programming language, is certainly one of the most needed tool.Functions in tureasy start with `$`.  It is already mentioned that tureasy takes the help of symbols to render uniqueness to different parts of the language structure. 

In a program, normal functions can be declared in any part of the code and can be used (called) in any scope of the program. This has certain advantages in tureasy. One of them is, as they have global recognition, functions called in tags can be resolved easily.

Tureasy also provides some alternative to global scope of functions, which are called as local functions. These local functions are confined to the scope they are defined. This will have a very good impact on the programming style or approach of the user.

Tureasy is able to support both procedural and functional programming, because as mentioned earlier its functions have the ability to take care of the instant decision to pass parameters by values or by references. These lets the programmer to choose fora function whether to have side-effects or not.Almost all of the builtin functions don't have side-effects, this is very helpful for functional programming style.


### Classes and OOPs  - 

Tureasy has Object oriented Programming as one of its most featured part of the language.
Classes in tureasy are separated into three blocks.i.e the members, constructors, methods are differed from each other and are defined 
in a block associated to them.This makes the body of a class more organised and also contributes to then encapsulation property of classes.

Classes also let users to define private members and methods in a class and again to promote symbolic coding `_$` and `_specifier` are used for the private stuff of classes.


 






