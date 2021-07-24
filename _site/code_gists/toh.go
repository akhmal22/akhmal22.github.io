package main

import (
  "fmt"
)

type Rod struct {
  pos int
  top int
  capacity int
  array []int
}

func createStack(capacity int, position int) *Rod {
  rod := Rod{position, -1, capacity, make([]int, capacity)}
  return &rod
}

func isFull(rod *Rod) bool{
  return rod.top == rod.capacity - 1
}

func isEmpty(rod *Rod) bool{
  return rod.top == -1
}

func push(rod *Rod, item int) bool{
  if isFull(rod) || isSmaller(rod, item) {
    return false
  }else{
    rod.top += 1
    rod.array[rod.top] = item
    return true
  }
}

func pop(rod *Rod) bool{
  if isEmpty(rod) {
    return false;
  }
  rod.top -= 1
  return true
}

func peek(rod *Rod) int{
  if isEmpty(rod) {
    return 2147483647;
  }
  return rod.array[rod.top]
}

func isSmaller(rod *Rod, pushing int) bool{
  return peek(rod) <= pushing
}

func gameCommence(init *Rod, disk int){
  for i := disk - 1; i >= 0; i-- {
		push(init, i)
	}
}

func moveDisk(init *Rod, dest *Rod) bool{
  disk := peek(init)

  if push(dest, disk) {
    pop(init)
    return true
  }else{
    return false
  }
}

func solveProblem(init *Rod, mid *Rod, final *Rod, disks int){
  counter := 0
  for !isFull(final) {
    counter += 1
    if disks % 2 == 0 {
      //fmt.Println("even")
      //fmt.Println("step: ", counter)
      if counter % 3 == 1 {
        if !moveDisk(init, mid){
          moveDisk(mid, init)
        }
      }else if counter % 3 == 2 {
        if !moveDisk(init, final){
          moveDisk(final, init)
        }
      }else{
        if !moveDisk(mid, final){
          moveDisk(final, mid)
        }
      }

    }else{
      //fmt.Println("odd")
      //fmt.Println("step: ", counter)
      if counter % 3 == 1 {
        if !moveDisk(init, final){
          moveDisk(final, init)
        }
      }else if counter % 3 == 2 {
        if !moveDisk(init, mid){
          moveDisk(mid, init)
        }
      }else{
        if !moveDisk(mid, final){
          moveDisk(final, mid)
        }
      }

    }
  }
}

func main() {
  init := createStack(19, 0);
  mid := createStack(19, 1);
  final := createStack(19, 2);

	fmt.Println("Welcome, 世界")

  gameCommence(init, init.capacity)
  fmt.Println("Game Commenced")

  solveProblem(init, mid, final, init.capacity)
  fmt.Println("Problem Solved")
}
