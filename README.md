# CS-210-PL
SNHU CS-210 Programming Languages
2022-06-18
This repo contains my solution for the final project (Project Three).

_Summarize the project and what problem it was solving._ \
The project consisted of weaving C++ and Python together to read a file containing a list of grocery store items and the number of times those items were bought. The program allowed a user to search for an item and display the number of times it was bought, the frequency compared to all items, or print a histogram of items, all with a text-based interface.

_What did you do particularly well?_ \
My solution is modular and well-encapsulated. Many of the functions are re-used or only slightly modified from previous projects or assignments in the course, so re-use was good.

_Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?_ \
I have exception handling for inputs, but I did not exhaustively test multiple inputs. For a real application rather than an assignment, the input handling should be robust. Most of my C++ code is in the utils header/code files, and could likely be split up into separate libraries.

_Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?_ \
The exception handling for C++ has been challenging. I don't think our text did a good job explaining how the various stream objects interact and how to handle exceptions with them. Google and StackOverflow were crucial in getting the code to handle exceptions the way I wanted them handled and not provide erroneous outputs due to handling some inputs up to a carriage return or whitespace, etc.

_What skills from this project will be particularly transferable to other projects or course work?_ \
I will definitely take the lessons learned from exception handling for C++ and carry them forward. 

_How did you make this program maintainable, readable, and adaptable?_ \
There are good comments for all functions in C++ and Python which minimizes guesswork for how functions work. The functions do a good job of encapsulating and abstracting the functionality and error checking. This encapsulation and abstraction makes reading the main program very easy, and following the code feels fairly natural. Most of the function and variable names make it clear what the code is doing without reading the comments.
