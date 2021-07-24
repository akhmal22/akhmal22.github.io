---
layout: post
title:  "COMPARING C AND GO: TOWER OF HANOI PROBLEM"
date:   2021-07-25 21:12:59 +0700
author: "Akhmal R"
categories: english article
---

# Comparing C and Go Solutions of Tower of Hanoi Problem

## Preface

I am going to write an article in comparison area, maybe I will write off few articles like this in near future but comes with different algorithms, in near past you can find the comparison article between paradigms that you can find it yourself on 'post' section, now I will commit the comparison between languages said the one to be the substitution of another, C and Go. C can be pronounced as Programming Languages' father 'cause so many programming language developed based on C or interpreted by C. Go on the other hand was relatively new compared to C, on the time before, Go claimed to be 'modern C' 'cause of features it bore fulfils 'modern language' set but the speed was faster than most of said 'modern language' and also its compiled just like C.

Comparison commited using two programs written in C and Go that solved old classic problem of Tower of Hanoi, using same environment of hardware and software, and time of processes are parameters to be compared in order to have the comparison result. The comparison will comparing time of compilation and execution of both program. Using same algorithm and paradigm, I hope this comparison can be on-par in terms of two programming language performance comparison.

## What is Tower of Hanoi?

Tower of Hanoi is mathematical problem invented by E. Lucas in 1883. The problem given us stack of disks stacked over the pole and another two empty poles, the disks stacked are differ in term of size, top-most disk is the smallest and bottom-most disk is the largest. In order to solve the problem, solver has to place whole stack of disks to one of two empty poles named 'target' pole and ensure the placement steps are the same number to optimal solution according to disk number. Steps commited must be disk-size-concerned, that smaller disks must be placed above larger disks, otherwise, the step is illegal and not counted.

For the Tower of Hanoi problem, given the optimal amount of solution steps are based on pattern (2^n)-1 which 'n' is represent the stack thickness. The question is, how the algorithm going to find the optimal solution? How can we interpret it to the code? and How the comparison going between C and Go code of Tower of Hanoi interpretation?

## How the algorithm going?

Actually for solving Tower of Hanoi problem, there are two basic of approaches you can follow, iterative approach or recursive approach in order to interpret the solution but in this occasion, I will use iterative approach algorithm to interpret the solution to the code. Steps in iterative approach we must follow is written as pseudocode below. In pseudocode below, number of disks represented by 'n', initial pole (disks first stacked there) represented by 'i', mid pole (one of two empty poles) represented by 'm' and final pole (disks final place) represented by 'f'.

```
if n is divisible by 2 then:
 makes legal move from i to m or vice versa
 makes legal move from i to f or vice versa
 makes legal move from m to f or vice versa
if n is not divisible by 2 then:
 makes legal move from i to f or vice versa
 makes legal move from i to m or vice versa
 makes legal move from m to f or vice versa
```

## How can we interpret?

Given algorithm must be executed iteratively until stack compeletely relocated to final pole. Before using above algorithm, we firstly choose data structure that fit well the situation, the situation only allows movement for last inserted disk (smallest disk) then 'stack' data structure is best fit. Tower of Hanoi requires smaller disk placed above larger disk, then add rules in our data structure that only smaller disk can be stacked by another disk. Specification of the data structure methods written below.

| Method Name | Usage |
| :----: | :----: |
| isFull | Check if stack is full |
| pop | Remove element (disk) from the stack |
| push | Insert element (disk) to the stack |
| peek | Return top-most element value of the stack |
| isSmaller | Check if element value to be inserted is smaller than top-most element value of stack |

<sub>Table 1: Methods of stack data structure</sub>

If the data structure has been ready, moved on to solution-focused interpretation, we basically interpret the pseudocode below to the more technical one. Earlier before solution delivered, we must initiate the problem by creating 3 stack places (poles) and create disks as required. Methods to solution delivery are listed below.

| Method Name | Usage |
| :----: | :----: |
| moveDisk | Move disk from stack to stack |
| solveProblem | interpretation of solution pseudocode |

<sub>Table 2: Methods of solution delivery</sub>

With the specification and explanation above, implementations of the solution are embed below.

{% gist 5555251 %}

{% gist 5555251 %}

## How the comparison going?

As mentioned above, we are comparing compilation time and execution time. Before gone to comparison, we define the scope of the comparison that the code used same approach and same algorithm, running on same machine (hardware and software) and deliver the solution of same number of disks, code executed don't requested for user's input so user can't distort the results. The results of comparison, provided by 'time' command, are presented in table below.

| Metrices | C | Go |
| :----: | :----: | :----: |
| Compilation time | real 0m0.263s<br /> user 0m0.089s<br /> sys 0m0.029s | real 0m1.036s<br /> user 0m0.285s<br /> sys 0m0.124s |
| Execution time | real 0m0.054s<br /> user 0m0.052s<br /> sys 0m0.002s | real 0m0.025s<br /> user 0m0.024s<br /> sys 0m0.002s |

<sub>Table 3: Measurement results</sub>

Times showed on the table 3 consist 3 kind of time, 'real', 'user' and 'sys'. 'Real' indicates whole time taken on the processes running session, 'user' indicates time spent by CPU in computation process of the executable, 'sys' indicates time spent by CPU in system tasks in order to bring the executable a run.

## Conclusion

The measurement resulted that code in C was faster in terms of compilation time than code in Go, contrary to execution time, Go was faster than C.

## Article Source

- [https://www.stemlittleexplorers.com/en/make-and-solve-tower-of-hanoi/][https://www.stemlittleexplorers.com/en/make-and-solve-tower-of-hanoi/]
- [https://en.wikipedia.org/wiki/Tower_of_Hanoi][https://en.wikipedia.org/wiki/Tower_of_Hanoi]
- I. Moscovich, 1000 playthinks: puzzles, paradoxes, illusions & games. New York: Workman Pub., 2001.
- Petković Miodrag, Famous puzzles of great mathematicians. Providence, RI: American Mathematical Society, 2013.
- [https://www.geeksforgeeks.org/stack-data-structure-introduction-program/][https://www.geeksforgeeks.org/stack-data-structure-introduction-program/]
- [https://stackoverflow.com/questions/556405/what-do-real-user-and-sys-mean-in-the-output-of-time1][https://stackoverflow.com/questions/556405/what-do-real-user-and-sys-mean-in-the-output-of-time1]
- [https://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm][https://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm]


[https://www.stemlittleexplorers.com/en/make-and-solve-tower-of-hanoi/]: https://www.stemlittleexplorers.com/en/make-and-solve-tower-of-hanoi/
[https://en.wikipedia.org/wiki/Tower_of_Hanoi]: https://en.wikipedia.org/wiki/Tower_of_Hanoi
[https://www.geeksforgeeks.org/stack-data-structure-introduction-program/]: https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
[https://stackoverflow.com/questions/556405/what-do-real-user-and-sys-mean-in-the-output-of-time1]: https://stackoverflow.com/questions/556405/what-do-real-user-and-sys-mean-in-the-output-of-time1
[https://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm]: https://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm
