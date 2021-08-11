---
layout: post
title:  "COMPARING C AND GO: TREE SORT"
date:   2021-07-22 22:12:59 +0700
author: "Akhmal R"
categories: english article
---

# Comparing C and Go Solutions of Tree Sorting

## Preface

In a previous words, I sent the comparison of programming languages C and Go, I compared the times both take to execution and compilation. This specific article is about to do the same thing as previous did. Difference is the programs used in comparison is Tree Sort. With the exact same approach as before, I hope it can extract more data to the comparison than before.

Tree Sort, compared to previous problem Tower of Hanoi, aside of they had different objectives, the complexities are too different to each other. time complexity for Tower of Hanoi is O(2<sup>n</sup> - 1) meanwhile this article's problem's is O(n<sup>2</sup>) that indicates us two diversed comparison problem.

## What is Tree Sort?

For the fast note, it is sorting machine made from binary tree data structure (binary by-design, difficulty reason). For longer explanation, said tree can put the collection of values sorted by inserting each values on collection to the tree and change its sequence mark based on the tree's nature and sorting problem solving. As the problem already a well-known, we can focus on having the solution ready, interpret it and compare both interpreted solution.

![directory](https://raw.githubusercontent.com/akhmal22/akhmal22.github.io/master/images/Tower-of-Hanoi-Tower-of-Brahma-or-Lucas-Tower.jpg)
<sub>Figure 1: Binary Tree illustration</sub>

## How the algorithm going?

The problem is pretty obvious so is the solution, basically comparing each element from the list to determine the sequence. Same as previous solution, this particular solution can make use of recursive approach and non-recursive approach and I will use recursive approach for the algorithm. All we should do in algorithm written in pseodocode below. Given the array of element and empty tree represented as nodes each sequentially defined as 'a' and 't', 'a' will start from 1 and the element position in array (index) will be enclosed by '[]', predefined function 'insert()' used to inserting array elements to the tree, data required for 'insert()' are array element and tree node.

```
(functions)
insert(element, tree):
  if tree is empty then:
    add the element to tree

  if given element lower than given tree node's value then:
    add element to the left of given tree node
  if given element greater than given tree node's value then:
    add element to the right of given tree node

inorderTraverse(tree, element):
  call self for left leaf
  traverse
  call self for right leaf
```

```
(main)
insert(a[1], t)

run iteratively until 10 steps done:
  insert(a[steps], t)
  increment steps

inorderTraverse(t, a)
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

With the specification and explanation above, implementations of the solution are listed in bonus section.

## How the comparison going?

As mentioned above, we are comparing compilation time and execution time. Before gone to comparison, we define the scope of the comparison that the code used same approach and same algorithm, running on same machine (hardware and software) and deliver the solution of same number of disks, code executed don't requested for user's input so user can't distort the results. The results of comparison, provided by 'time' command, are presented in table below.

| Metrices | C | Go |
| :----: | :----: | :----: |
| Compilation time | real 0m0.263s<br /> user 0m0.089s<br /> sys 0m0.029s | real 0m1.036s<br /> user 0m0.285s<br /> sys 0m0.124s |
| Execution time | real 0m0.054s<br /> user 0m0.052s<br /> sys 0m0.002s | real 0m0.025s<br /> user 0m0.024s<br /> sys 0m0.002s |

<sub>Table 3: Measurement results</sub>

Times showed on the table 3 consist 3 kind of time, 'real', 'user' and 'sys'. 'Real' indicates whole time taken on the processes running session, 'user' indicates time spent by CPU in computation process of the executable, 'sys' indicates time spent by CPU in system tasks in order to bring the executable a run.

In compilation time, C beats Go in every aspects of time, but in the execution time, Go beats C in 'real' and 'user' time, Go and C are equal in 'sys' time.

## Conclusion

The measurement resulted that code in C was faster in terms of compilation time than code in Go, contrary to execution time, Go was faster than C.

## Bonus

The implementations are below.

C: [https://git.io/J8i4a][https://git.io/J8i4a]

Go: [https://git.io/J8iBt][https://git.io/J8iBt]

## Article Source

- [https://www.stemlittleexplorers.com/en/make-and-solve-tower-of-hanoi/][https://www.stemlittleexplorers.com/en/make-and-solve-tower-of-hanoi/]
- [https://en.wikipedia.org/wiki/Tower_of_Hanoi][https://en.wikipedia.org/wiki/Tower_of_Hanoi]
- I. Moscovich, 1000 playthinks: puzzles, paradoxes, illusions & games. New York: Workman Pub., 2001.
- Petković Miodrag, Famous puzzles of great mathematicians. Providence, RI: American Mathematical Society, 2013.
- [https://www.geeksforgeeks.org/stack-data-structure-introduction-program/][https://www.geeksforgeeks.org/stack-data-structure-introduction-program/]
- [https://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm][https://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm]
- [https://stackoverflow.com/questions/556405/what-do-real-user-and-sys-mean-in-the-output-of-time1][https://stackoverflow.com/questions/556405/what-do-real-user-and-sys-mean-in-the-output-of-time1]


[https://www.stemlittleexplorers.com/en/make-and-solve-tower-of-hanoi/]: https://www.stemlittleexplorers.com/en/make-and-solve-tower-of-hanoi/
[https://en.wikipedia.org/wiki/Tower_of_Hanoi]: https://en.wikipedia.org/wiki/Tower_of_Hanoi
[https://www.geeksforgeeks.org/stack-data-structure-introduction-program/]: https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
[https://stackoverflow.com/questions/556405/what-do-real-user-and-sys-mean-in-the-output-of-time1]: https://stackoverflow.com/questions/556405/what-do-real-user-and-sys-mean-in-the-output-of-time1
[https://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm]: https://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm
[https://git.io/J8i4a]: https://git.io/J8i4a
[https://git.io/J8iBt]: https://git.io/J8iBt
[https://www.geeksforgeeks.org/iterative-tower-of-hanoi/]: https://www.geeksforgeeks.org/iterative-tower-of-hanoi/
[https://www.geeksforgeeks.org/time-complexity-analysis-tower-hanoi-recursion/]: https://www.geeksforgeeks.org/time-complexity-analysis-tower-hanoi-recursion/
[https://en.wikipedia.org/wiki/Tree_sort]: https://en.wikipedia.org/wiki/Tree_sort
[https://www.geeksforgeeks.org/tree-sort/]: https://www.geeksforgeeks.org/tree-sort/
[https://www.geeksforgeeks.org/binary-tree-data-structure/]: https://www.geeksforgeeks.org/binary-tree-data-structure/
