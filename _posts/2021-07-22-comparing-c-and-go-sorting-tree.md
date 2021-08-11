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

Tree Sort, compared to previous problem Tower of Hanoi, aside of they had different objectives, the complexities are too different to each other. time complexity for Tower of Hanoi is O(2<sup>n</sup> - 1) meanwhile this article's problem's is O(n<sup>2</sup>) that indicates us two differentiated comparison problem.

## What is Tree Sort?

For the fast note, it is sorting machine made from binary tree data structure (binary by-design, difficulty reason). For longer explanation, said tree can put the collection of values sorted by inserting each values on collection to the tree and change its sequence mark based on the tree's nature and sorting problem solving. As the problem already a well-known, we can focus on having the solution ready, interpret it and compare both interpreted solution.

![directory](https://raw.githubusercontent.com/akhmal22/akhmal22.github.io/master/images/Tower-of-Hanoi-Tower-of-Brahma-or-Lucas-Tower.jpg)
<sub>Figure 1: Binary Tree illustration</sub>

## How the algorithm going?

The problem is pretty obvious so is the solution, basically comparing each element from the list to determine the sequence. Same as previous solution, this particular solution can make use of recursive approach and non-recursive approach and I will use recursive approach for the algorithm. All we should do in algorithm written in pseudocode below. Given the array of element and empty tree represented as nodes each sequentially defined as 'a' and 't', 'a' will start from 1 and the element position in array (index) will be enclosed by '[]', predefined function 'insert()' used to inserting array elements to the tree, data required for 'insert()' are array element and tree node.

## Set the structure crystal clear before gone further

Explaining tree as a data structure with a single figure but firstly I will show your terms used in this data structure in a table

| Term | Definition |
| :----: | :----: |
| Root | Top-most node of the tree |
| Node | An element in the tree |
| Leaf | Bottom-most of the tree |
| Parent | Node that has node/nodes below it |
| Child | Node that has node/nodes above it |
| Key | Data stored by node |

So the tree is consisted of several nodes, node of the tree had its own structure to store and represent the data, model below once again represent the tree if printed graphically.

![directory](https://www.tutorialspoint.com/data_structures_algorithms/images/binary_tree.jpg)
<sub>Figure 2: Tree illustration</sub>

Nodes in binary tree must be at least contain 3 attributes for the tree worked as structured data representation.
- Key: Literal representation of the data on the nodes.
- Left Child: Finger that points to another node, child node assumed position is in the left.
- Right Child: Finger that points to another node, child node assumed position is in the right.

Thus the structure explained above, we can move forward.

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

Follow the algorithm above in order to sorting data using tree data structure. For the programs built, we need to fulfill the function and procedure required based on algorithm. Method name are listed below

| Method Name | Usage |
| :----: | :----: |
| createNode | Allocate one node for the tree |
| storeSorted | Traverse tree in inorder fashion to rearrange the data sequence |
| insert | Insert node to the tree as a child of pre-allocated node |

<sub>Table 1: Methods of tree sort</sub>

For the problem solving lines, we can allocate array consists of several elements and for this interpretation, elements are positive integer. With the specification and explanation above, implementations of the solution are listed in bonus section.

## How the comparison going?

Comparison specification mentioned in previous article is the same for this article, same device, same algorithm and same number of elements for both programs. Screen capture below intended to give more evidence than the previous.

![directory](https://www.tutorialspoint.com/data_structures_algorithms/images/binary_tree.jpg)
<sub>Figure 2: Tree illustration</sub>

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
