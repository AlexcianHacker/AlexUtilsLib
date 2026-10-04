# <p align="center"> Alex Utilities Library 
<p align="center"> A Collection / Library Of Typically CLI Linux/Unix Utilities And Tools
<p align="center"> Originally Compiled With G++ (GNU/GCC) 

### Setup 
Run `g++ -o /AlexUtilsLib/inject inject.cpp` <br> 
Run `g++ -o /AlexUtilsLib/canonize canonize.cpp` <br> 
- (or) Run `g++ -o /AlexUtilsLib/canonize canonize2.cpp` <br> 
- (or) Run `gcc -o /AlexUtilsLib/canonize canonize.c` <br> 


- Repeat For Any Other Binaries. -O3 Optimizations Have Been Tested On `inject` And `canonize` As Working. <br> 

### Bootstrapping With canonize (Any Version) 
Run `./canonize canonize ./canonize` <br>
Run `./canonize inject ./inject`


**Use Sudo If Necessary 


### NOTE ON CANONIZE 

Generally Speaking, You Should Be Using An Absolute Path Instead Of A Relative One, So You Can Use The Tool Anywhere. As Such, The Following Example Outlines The Best Practice For All Usage: 

`./canonize canonize /dir/subdir/canonize` 
