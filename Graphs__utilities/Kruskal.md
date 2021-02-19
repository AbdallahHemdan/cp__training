## Applications of Kruskal

### [1] 2nd MST
> We can find 2nd MST using Krusal(eaiser) | using Prim

#### Steps
> This method is applicable only for `small n`

1. Find MST
2. For each edge in the MST
	- Remove edge
	- Run MST, compare it for the min value
	- ReAdd the edge u removed
6. Display MST2 value

[More](https://github.com/AbdallahHemdan/CP__Training/blob/master/Graphs__utilities/Second%20best%20MST%20for%20Small%20n.md)


### [2] Partial MST 
> We already connected some edges together, add minimum number of edges to make the graph full connect (every edge can reach any edge in the graph)

#### Steps

1. Take the given edges which suppose to be connect already
2. Union them together
3. For the rest of the edge (not connected already)
4. Run Kruskal
	5. Sort all the edge
	6. ...etc


### [3] Find MiniMax using Kruskal
> MiniMax is the path between 2 nodes such that maximum cost of edge over path is as minimum as possible



#### Steps for MiniMax of the whole graph 

1. Run Kruskal
2. Last added edge is the minimax

Problem : [F - Travelling Salesman GYM/100712](https://codeforces.com/gym/100712)
#### Steps fro MiniMax between 2 nodes

1. Run Kruskal while the 2 nodes are not connected yet
2. Last added edge is the minimax between the 2 nodes


