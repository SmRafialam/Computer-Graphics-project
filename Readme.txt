Computer Graphics Fall 2020   Programming Assignment 1






Questions and answers: 
a. Did you collaborate with anyone in the class? If so, let us know who you talked to and what sort of help you gave or received.
 
I have tried several times to run the code in visual studio but  I could not  compile the code using Visual Studio .So I run the main.cpp file in code blocks.
In code blocks I use
 #include <windows.h>
#include "GL/glut.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
These header files run the code in code blocks.




b. Were there any references (books, papers, websites, etc.) that you found particularly helpful for completing your assignment? Please provide a list.
I get my information from some  Google website and it’s  assist me.


c. Are there any known problems with your code? If so, please provide a list and, if possible, describe what you think the cause is and how you might fix them if you had more time or motivation. This is very important, as we’re much more likely to assign partial credit if you help us understand what’s going on. 
There have been no issues at all.


d. Did you do any extra work? If so, let us know how to use the additional features. If there was a substantial amount of work involved, describe what and how you did it. 
I didn't do it.




e. Got any comments about this assignment that you’d like to share? Was it too long? Too hard? Were the requirements unclear? Did you have fun, or did you hate it? Did you learn something, or was it a total waste of your time? 
No,the actual coding time didn't last much longer. Yes, the requirements were clear. 




MY TASK:  


Task 1: Color Changes
Task 1(a) is to use handle key where c key can change color 
First take  GLuint colorCounter = 0 ; as a global variable
Then for case 'c':
        // add code to change color here
                colorCounter += 1;
                if(colorCounter>4)
            colorCounter=0;
b. For Light postioning changes = press Leftwards/Rightwards/Upwards/Downwards Arrow key
c. For Spin = press R