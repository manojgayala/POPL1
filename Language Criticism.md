# Criticism of Tureasy

Tureasy as the name suggests is simple, easy to code and understandable programming language. But there is something more the name supports.
It helps the programmer improve her programming skills by giving advices in the same way as elders/professionals nurture newbies.

When a program of tureasy is seen superficially for the first time, it seems to have more symbols and one can be intimidated by that. But this is one of the most important things that helps the programmer makes the language more compact and easy as they eventually become more comfortable with the symbols than using large keywords.

## Insights into some domains of Tureasy.

 ### Variables - precisely sufficient.
Tureasy has an optimal range of primitive datatypes to make things clear for the user. For Eg: Tureasy doesn't provide any datatypes for the unsigned numbers because their usage can be served by other ways in tureasy (larger data types) ensuring that the behaviour of variables is not complicated.

Along with the primitives, tureasy has many special datatypes in its libraries which are useful for the programs demanding non-trivial data structures.Also users can create their own datatypes by abstracting them using the concept of classes and objects.

Tureasy provides storage class specifiers and type specifiers to choose the scope and rigidity of the variable.Even though out of the scope variables cannot be accessed or can be updated, tureasy boldly presents a way to change the value of a variable in functions called, with a symbol `@`. This implies that a variable can be passed by reference i.e a procedure can change the actual parameter values in the caller scope. 

As the program size increases, it becomes necessary to do casts for some variables in tureasy which can be seen as a disadvantage unlike python which takes care of such conversions internally. 

### Statements and Blocks - rendering  hierarchy.
 Tureasy provides all the types of statements that are needed to express logic  in a programming language. i.e **Tureasy is Turing Complete.** (dedicated to the legendary computer scientist.)
       
The formatted labelling of some statements make the control flow easier to manage.These statements can contain multiple expressions which makes the language more compact. Block of statements (Compound statements) in tureasy brings the concept of scope.These blocks are bounded by the end of a statement marked with a `/` .

But some blocks end with a different identifier.Functions end with a `%` and classes end with a `*%`. Having different identifications for blocks can be confusing to the user at first. But such difference also helps programmer in debugging her code unlike C where we have only curly braces for every block.
 
Iterative statements in Tureasy provide an intuitive way to iterate over a collection of variables or over a range. In both these cases the implementation is the same as they are abstracted accordingly. Such generic syntax helps programmer to adapt to language easily.

### Functions - 	both a procedure and a pure function.

Function in a programming language, is certainly one of the most needed tool. Functions in tureasy start with `$`.  It is already mentioned that tureasy takes the help of symbols to render uniqueness to different parts of the language structure. 

In a program, normal functions can be declared in any part of the code and can be used (called) in any scope of the program. This has certain advantages in tureasy. One of them is, as they have global recognition, functions called in tags can be resolved easily.

Tureasy also provides some alternative to global scope of functions, which are called as local functions. These local functions are confined to the scope they are defined. This will have a very good impact on the programming style or approach of the user.

Tureasy is able to support both procedural and functional programming, because as mentioned earlier its functions have the ability to take care of the instant decision to pass parameters by values or by references. These lets the programmer to choose for a function whether to have side-effects or not.Almost all of the builtin functions don't have side-effects, this is very helpful for functional programming style.

### Classes and OOPs  -  well fabricated but subtle.

Tureasy has Object oriented Programming as one of its most featured part of the language.
Classes in tureasy are separated into three blocks.i.e the members, constructors, methods are differed from each other and are defined 
in a block associated to them.This makes the body of a class more organised and also contributes to the encapsulation property of classes.

Classes also let users to define private members and methods in a class and again to promote symbolic coding `_$` and `_specifier` are used for the private methods/members of classes,`.$` is used for overridden methods.

Inheritance in tureasy is well-defined. Child class constructors have to be paired with some parent constructor, this lets the user to create objects without any irregularity(undeclared variables/objects). Multiple Inheritance comes with its challenges. But they are carefully taken care in tureasy.For Eg: To resolve the problem of common methods in parent classes, child class has to override this common method. This can be some kind of time-taking job as users have to check whether there are any common methods. However users who create child classes are  most probably aware of their parents. 

 Even constructors are kind of methods, they don't have any identifiers, this again promotes tureasy's idea of not using redundant keywords. 

Many of the libraries will be maintained using classes.This is aided by the generic version of classes.
A single class can be created to be compatible for many datatypes.

### Tags - The bold attempt.

All the above mentioned features in Tureasy are intended to help the possibility of implementing the soul of tureasy, tags.
Tags are created to help the programmers improve their code in many ways. They are given tips, advices by the tags which are both for their personal development and also to maintain a company's standards.

All this is done at the compiler-level by **turzers** which analyse the semantics.Although tags are so beneficial, effective usage of those are dependent on the user.If not used properly, they may lead to misleading results. So they have to be used only when they are well-known. Full potential of tags may not be visible in the initial stages of this language, as they need more training.

## Conclusion

Finally tureasy can be claimed to be a language which is suitable to use reliably in almost all the domains of programming. Novelty in Tureasy is that it adapts to the coding environment that is associated to the company that uses this language. It is a self-developing language which becomes more powerful for every single compilation of its code.



 






