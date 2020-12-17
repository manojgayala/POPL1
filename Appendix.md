# Classes

Syntax of Classes :  [**Class Declaration**](https://github.com/manojgayala/POPL1/blob/srikar/Appendix.md#user-content-obscuring:~:text=Classes%3A,which%20is%20a%20given%20by%20class%2Dinitializer)

Body of the Class: [**Class Body**](https://github.com/manojgayala/POPL1/blob/srikar/Appendix.md#user-content-inherited-classes-and-parent-classes:~:text=Class%20BodyBody%20contains%20declaration%20of%20members%2C%20methods%2C%20constructors)
 

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
 - [**Overridden methods**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-overriden-methods:~:text=Only%20the%20public%20methods%20that%20are,the%20parent%20class%2Didentifier%20if%20multiple%20inherited))
 - [**Overloaded methods**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Language%20Manual.md#user-content-overloaded-methods:~:text=Two%20non%20%2Dprivate%20methods%20of%20a,of%20arguments%20of%20both%20the%20methods.)
 - [**Operator Overloading methods**](https://github.com/IITH-POPL1/language-manual-iith3/blob/main/Specifications.md#user-content-local-functions:~:text=Functions%20for%20Operator%20Overridding)
  
    - Operator Overloading can be done only for the user-defined classes.





We know that Classes in Tureasy allow the objects to exhibit polymorphism.

 - It is seen in Method Overloading and Operator Overloading,
which is a compile-time polymorphism as their functionality is resolved at the compile-time.

Objects in Tureasy can also exhibit Run-time polymorphism.

 - An object of a child class can be referred by both the child class' reference and the parent class' reference.
- This is used when an object is needed which has the same  structure as the parent class but the overridden, overloaded functions and overloaded operators in the child classes have to be reflected.

```
*ClassA
mem:
int a;
met:
$printmem() << void
write(a);
%
 *ClassB inherit ClassA
 mem:
 float d;
 met:
 .$printmem() << void
 write(a +" "+b);
 %
 *%

$main() << void
ClassB obj = new ClassB();
obj.a = 4;
obj.d = 3.4;
ClassA parentref = obj;
parentref.printmem();
```
```
Output:
4 3.4
```
The method to be invoked is decided at the run-time.Even the `parentref` can't access  the `d` variable(as tureasy is statically typed, the child's members are not known  at compile-time), overridden `printmem()` will be invoked. 

