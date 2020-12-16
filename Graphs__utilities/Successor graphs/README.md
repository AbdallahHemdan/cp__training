# Successor graphs
> Directed graphs in which every vertex has exactly one outgoing edge.

## Note
You will find more in the [PDF attached here](https://drive.google.com/file/d/1XYg0pOeQsv8fd9G4AGd3EGhzEV-mq1qZ/view?usp=sharing).

## Calculating the LOG-th Parent
> To calculate the LOG-th parent, your parent in the i-th lvl = parent of your parent in the (i-1)-th lvl

![image](https://user-images.githubusercontent.com/40190772/102415555-09e3c880-4001-11eb-9cbd-ef91b645dc23.png)


```cpp
  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i < n; i++) {
      par[i][j] = par[par[i][j - 1]][j - 1];
    }
  }
```


## Resources
1. https://usaco.guide/silver/func-graphs#solution
2. https://medium.com/@tuvo1106/the-tortoise-and-the-hare-floyds-algorithm-87badf5f7d41

## Problems
1. https://cses.fi/problemset/task/1750
2. https://codeforces.com/contest/1020/problem/B
3. http://www.usaco.org/index.php?page=viewproblem2&cpid=764
4. https://cses.fi/problemset/task/1751
5. http://www.usaco.org/index.php?page=viewproblem2&cpid=1014
