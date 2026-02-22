# c-flag-utils
Flag utilities for C to make adding flags to projects easier and more intuitive.  
Contributing might never be accepted (as it probally wont be needed), but incase your fork is intuitive and solves a real issue, it will be accepted if:  
1. Good code that is more efficient/readable than the current version  
2. Useful and intuitive comments whenever needed  
3. Well named commits  
4. Incase rewriting something, prove that your version is worth it  

The point of this header is to make flags be globally the same no matter what type of project needs it!  

Requirements:  
Make for the makefile  
well, glibc or something idk-  

Current version: 2.2  
Rewrote code to use a for loop that makes adding flags more modular, and made function return -1 when it fails.  
2.1: removed stdio.h  
2.2: remade comments and renamed function  

Scope for version 3.0:  
Remake system to have it check for ALL args inputted by user, instead of just argv[1].  
