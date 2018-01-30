# Mutimedia Assignment 3

# Report and Discussion


Result display:
![pic](https://user-images.githubusercontent.com/33059129/35548752-870a0c02-05bc-11e8-9c4f-e5232c4be571.PNG "resullt4")
This picture display the result from second version of the program.

Sequenal Search SNR:~16 Current 2D logaritmic Search SNR:~15 Hierachical Search SNR:~12
Response time for Sequential Search:~600ms for 2D logaritmic Search:32ms forHierachical Search:<1ms

Problem facing:

The theorem is easy to understand, but some part is difficult to accompilsh. Such as, we need first change the image from 3 channel to
1 channel, then go through blocks in the search window, and find the motion vector that need to be use to generate the result. How to
store the motion vector is just one of the task, in my case i prefer to store the first pixel of the best-match block, then calculate the motion vector later when we are going to generate the result.
Some problems still exist, such as the 2D algorithm search, it is still not in its perfect stat after serveral trys. But finally I had found the problem and fix it

Result discussion:

* Alhough 2D Logarithm is much faster, its accuracy is slightly less than sequntial search. The reason is that the sequntial search
go through all the possible blocks, but 2D Logarithm search just go through some of "much possible" blocks, which may find some worse
result at some moment. So as hierarchical search, it seems to be much faster then both sequnetial search and 2D logarithm, nut when it comes to the accuracy, it still have some difference between them. It is just a trade-off, depend on how accuarte or how fast you want to choose the best algorithm to use.

What I have learn:

I had already learn how to change the image between channels by convert colors, use getticket to calculate time, and the
theorom of motion compensation. Also something such as image pyramid from hierachical search, or the meaing of SNR rate.

It is still hard for me to operate a program with visual studio. Although I had use it a lot in this semester, I am stilll scratch
and keep finding result when a new problem emerge. This time I prefer to write a mid-report before full complish the programm, because I
think maybe after I record down all the problem I was facing, I could have a better and clear look on my program, and can keep up 
the energy working on those unsolve problem and keep track of which problem I had facing.

After the mid report, I surely improve some parts of the program, such as I had a better result of 2D logarithm search, more accurate SNR, and also I had complete the hierachical search part. I found that it is a great thing to recored what wrong now and wait a lit tle bit time for thinking about what did wrong, keep going when realize what the problem is(and sovle it). Although the result is not that perfect at some part this time, I had learn some precious experience from this.

*Readding, coding, debugging. This is what I had done this program, by this circulation.*
  
