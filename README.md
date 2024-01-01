# Sudoku Solver 

*project is still under early development and may see lots of changes*

<img title="Sudoku Solver" alt="introduction picture" src="/project documents/photos/rainmbow boards.png">

### Project Structure: 

- __include__
  - Holds all the important files/utilities that the program needs to run
- __workInProgress__
  - Used for features that are currently in developement before they get added officially to the project.
- test
  - animated
    - has animated test that you can run to make sure that the program is still running as intended and a way to test out some features that are in development
  - basic
    - has basic test that you can run to make sure that the program is still running as intended and a way to test out some features that are in development
  - This directory is strictly for running test on program utilities/features.
- __boards__
	- holds all the boards in a format that the program understands
- __batches__
- __inputtingBoards__
  - This is a directory for a user to input their own custom boards if they so choose to. The format that the inputting board needs to be in doesn't matter, the only thing to recognize is that it reads only numbers from left to right for every row. Something to note is that the amount of numbers per row __does not__ matter. A more user friendly format may be:
        
        1: 000000000
        2: 000000000
        3: 000000000
        4: 000000000
        5: 000000000
        6: 000000000
        7: 000000000
        8: 000000000
        9: 000000000

    or another user friendly input may look like:
  

        1:  000|000|000
        2:  000|000|000
        3:  000|000|000
        4:  ---+---+---
        5:  000|000|000
        6:  000|000|000
        7:  000|000|000
        8:  ---+---+---
        9:  000|000|000
        10: 000|000|000
        11: 000|000|000

    in the examples above and for further examples, the numbers on the left denote the line number for readability. As we previously showed, the way the board can be inputted has a lot of different possibilities. It is up to you for how you want to input the boards. An example of a less-readable format is:

        1: 0sdf0PS0SAL0ASLas0asdief0alskdje0alsd0slask0asd0sdf0PS0SAL0ASLas0asdief0alskdje0alsd0slask0
        2: 0sdf0PS0SAL0ASLas0asdief0alskdje0alsd0slask0asd0sdf0PS0SAL0ASLas0asdief0alskdje0alsd0slask0 
        3:0sdf0PS0SAL0ASLas0asdief0alskdje0alsd0slask0asd0sdf0PS0SAL0ASLas0asdief0alskdje0alsd0slask00sdf0PS0SAL0ASLas0asdief0alskdje0alsd0slask0
        4: 0sdf0PS0SAL0ASLas0asdief0alskdje0alsd0slask0
        5: SOAISFEOISDFOIME
        6: 0sdf0PS0SAL0ASLas0asdief0alskdje0alsd0slask0asd0sdf0PS0SAL0ASLas0asdief0alskdje0alsd0slask0



### Why I Made This Project: 
This is my own personal project that I decided to start working on near the end of 2023.
I chose to work on this project because I wanted to apply using C++ outside of a school setting.
Something to note is that in early summer of 2023, I developed this algorithm on my own.
To my current knowledge there is not another algorithm like mine that exists.
The inspiration behind my algorithm was from a CSCI course at my home town college in Missoula, Montana.
In the course, we were tasked with developing a program in Java to make a program that __solves__ a sudoku board.
I did this fairly quickly, but there was always the thought of "*is this efficient?*".
This thought led me to taking a deeper dive at understanding how my algorithm works and what improvements I can make.
I spent a couple hours brainstorming, coding and running into problems. 
As I progressed further I slowly shaped my algorithm into something that I was personally really proud of!
Even though my program was amazing at solving sudoku boards, I still didn't feel complete with it.
I started to look into GUI software with Java to take my program to another level, but quickly got lost.
I soon started classes at my new University that starts off with teaching C++.
I was extremely lost and confused when I first tried coding in C++.
I spent hours researching and learning C++ so I can build myself up again.
I soon felt like I had a good understanding of things. 
Every class project that was thrown at me was a challenge.
I enjoyed new challenges and quickly overcame all class projects that were given out.
With this momentum I wanted to apply what I had learned outside of class so then I can grow even more.

