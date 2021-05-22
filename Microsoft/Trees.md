# 🌳 Trees
- The tree cannot contain cycles, and tree with (n)-nodes has (n-1)-edges
- They may or may not have links back to their parent nodes
- A very simple class definition for Node is as following:
- Balanced tree enough to ensure O(log n) times for **insert** and **find** operations
- Two common types of **balanced trees** are **red-black** trees and **AVL** trees

```cpp
class Node {
  string name;
  Node children [N];
}
```
### 👴 Complete Binary Trees
- A complete binary tree is a binary tree in which every level of the tree is fully filled
- To the extent that the last level is filled, it is filled left to right

![Screenshot 2021-05-22 141808](https://user-images.githubusercontent.com/40190772/119226327-c7bb3780-bb08-11eb-9124-2aad961243e0.png)


### 👶 Full Binary Trees
- A full binary tree is a binary tree in which every node has either zero or two children
- no nodes have only one child

![image](https://user-images.githubusercontent.com/40190772/119226530-e4a43a80-bb09-11eb-92d8-43f12dc454d6.png)


### ⚡ Perfect Binary Trees
- A perfect binary tree is one that is both full and complete
- As a perfect tree must have exactly (2^k - 1) nodes (where k is the number of levels)

![image](https://user-images.githubusercontent.com/40190772/119226577-1ddcaa80-bb0a-11eb-840f-bae31c63148c.png)



## 🦜 Questions to ask about trees
- [x] Tree Vs. Binary Tree
- [x] Binary Tree Vs. Binary Search Tree
- [x] Balanced vs. Unbalanced


## 🚶‍♂️ Binary Tree Traversal
- We have 3 ways for traversing a binary tree:
    1. In-Order Traversal
    2. Pre-Order Traversal
    3. Post-Order Traversal
- The name of the traversal method is respect to the current


### 👈☝👉 In-Order Traversal
- Visit the **left** branch, then the **current** node, and finally, the **right** branch.

```cpp
void inOrderTraversal(TreeNode node) {
  if (node != nUll) {
    inOrderTraversal(node.left);
    visit(node);
    inOrderTraversal(node.right);
  }
}
```

### ☝👈👉 Pre-Order Traversal
- Visit the **current** node, then the **left** branch, and finally, the **right** branch.

```cpp
void preOrderTraversal(TreeNode node) {
  if (node != nUll) {
    visit(node);
    preOrderTraversal(node.left);
    preOrderTraversal(node.right);
  }
}
```


### 👈👉☝ Post-Order Traversal
- Visit the **left** branch, the **right** branch, then finally the **current** node

```cpp
void postOrderTraversal(TreeNode node) {
  if (node != nUll) {
    postOrderTraversal(node.left);
    postOrderTraversal(node.right);
    visit(node);
  }
}
```


## 🎩 Binary Heaps (Min-Heaps and Max-Heaps)
- We'll just discuss min-heaps here. Max-heaps are essentially equivalent
- A min-heap is a **complete binary tree**
- Each node is **smaller** than its children
- **The root**, therefore, is the **minimum element** in the tree

![image](https://user-images.githubusercontent.com/40190772/119228416-39987e80-bb13-11eb-813c-473c5aa376fa.png)

### 🔬 Binary Heaps operations
1. Insert
2. Extract min/max

#### 📌 Insert
1. Insert the element at the bottom (rightmost spot so as to maintain the complete tree property)
2. Then, we Fix (swapping the new element with its parent until min heap property full satisfied)
3. This algorithm will also take **O(log n) time**

![image](https://user-images.githubusercontent.com/40190772/119228974-eb38af00-bb15-11eb-8f19-5bb3c8e9d240.png)

#### 🔪 Extract Minimum Element
1. Min-heap is always **at the top**, The trickier part is how to remove it
2. **Remove the minimum** element and **swap it with the last element** in the heap
3. **Bubble down** this element, **swapping it with one of its children** until the min-heap property is restored
4. This algorithm will also take **O(log n) time**

![image](https://user-images.githubusercontent.com/40190772/119229220-343d3300-bb17-11eb-8bd8-8e158c74289b.png)

## 🚧 Tries (Prefix Trees)
- A trie (sometimes called a **prefix tree**) which is a variant of an **n-ary tree**
- Characters are stored at each node, Each path down the tree may represent a word
- The * nodes (sometimes called "**null nodes**") are often used to **indicate complete words**
- A node in a trie could have anywhere from **1** through **ALPHABET_SIZE + 1**
- A trie can check if a string is a valid prefix in **O(K) time**, where K is the length of the string.

![image](https://user-images.githubusercontent.com/40190772/119230134-2f7a7e00-bb1b-11eb-9897-47d187583430.png)
