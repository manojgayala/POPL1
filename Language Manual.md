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
