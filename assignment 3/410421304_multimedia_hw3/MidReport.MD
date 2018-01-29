# Mutimedia Assignment 3 - Temporarl Design Report

#Update 1/23: Program update with slightly better 2D logarithm result and SNR
Current Sequnetial Search SNR:~0.3 Current 2D logaritmic Search SNR:~0.06

#Update 1/28: Some previous push include hierachical search and update new SNR rate
Current Sequnetial Search SNR:~15 Current 2D logaritmic Search SNR:~6 Hierachical Search SNR:~12

# Report and Discussion


Result display:
![pic](https://user-images.githubusercontent.com/33059129/35185138-47187ffe-fe3a-11e7-8746-4f39832ab489.PNG "the termporary resullt")
This is the brief view of the work until today. The program is still undfer working to solve some problems.

Problem facing:

The theorem is easy to understand, but some part is difficult to accompilsh. Such as, we need first change the image from 3 channel to
1 channel, then go through blocks in the search window, and find the motion vector that need to be use to generate the result. How to
store the motion vector is just one of the task, in my case i prefer to store the first pixel of the best-match block, then calculate the
motion vector later when we are going to generate the result. Beside that I found that when I working on function in my program, it would slow down or even stall my computer, I think maybe is that I allocate some part of the address wrong or overflow. Some problems still exist, such as the 2D algorithm search, it is still not in its perfect stat. I will keep working on it, and also does the hierarchical search.

Result discussion:

* Alhough 2D Logarithm is much faster, its accuracy is not as good as sequntial search. The reason is that the sequntial search
go through all the possible blocks, but 2D Logarithm search just go through some of "much possible" blocks, which may find some bad
result at some moment. So as hierarchical search.

What I have learn:

Until now, I had already learn how to change the image between channels by convert colors, use getticket to calculate time, and the
theorom of motion compensation.

It is still hard for me to operate a program with visual studio. Although I had use it a lot in this semester, I am stilll scratch
and keep finding result when a new problem emerge. This time I prefer to write a mid-report before full complish the programm, because I
think maybe after I record down all the problem I was facing, I could have a better and clear look on my program, and can keep up 
the energy working on those unsolve problem and keep track of which problem I had facing. Although some problem still done yet, I thought 
I will keep trying until I solve it.

*Readding, coding, debugging. This is what I had done this program, by this circulation.*
  
