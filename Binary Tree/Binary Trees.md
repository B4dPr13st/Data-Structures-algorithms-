# Binary Trees

![](https://barbudinhoweb.files.wordpress.com/2014/10/grafico-1-743037.jpg)

### Definition of a Tree

**Trees** are hierarchical **Data Structures**, formed by a set of arranged elements, called **Nodes** (or **Vertices**,
since a **Tree** is a type of **Graph**) and linked in a specific way by sets of **Edges**.

These **Nodes** follow a hierarchy of levels, where the first level is 0 and contains only one **Node**, the so-called
**Root Node** and can have several other levels after this one.

The links between the **Nodes** of a **Tree** follow a genealogical nomenclature, where a **Node** always
has a **Parent Node**, on the level above, 
and those that are connected, below it, will be the **Children Nodes**.

### Definition of Binary Trees

A **Binary Tree** is a type of structure where each of the **Nodes** can have a maximum
of two **Child Nodes** connected to it.

A **Binary Tree** can be defined recursively, according to the following reasoning. The **root** of the **Tree**
has two **children**, one on the right and one on the left,
which in turn are **roots** of two **subtrees**. Each of these **subtrees**
has a left **subtree** and a right **subtree**, following this same reasoning.

It is important to note that the only **Node** of the **Tree** that does not have a **Father Node** is the
**Root Node** of level 0, which is, like Odin,
**Father of all** the other levels of the **Tree**.

Some applications of **Trees** are:

- Directory System, where its structure is represented in a hierarchical way by trees.
- Databases.
- Graphical Interfaces.
- File Compression, as in **Huffman's Tree**.

### Definition of a Binary Search Tree

**Binary Search Trees** are **Binary Trees** with the following property:
all **Nodes** belonging to the **left subtree**
of any **node** have a smaller **key** that the **key**
of the current one, and where the **nodes** of the **subtree**
to its right have a **key** greater than the **key** of the **node**
in question. 

This property must be valid for all **subtrees**,
allowing the performance of **more efficient searches**, as we can
compare the searched **key** with the **key** of a **node** and decide whether to
continue the **search** only in the **subtree** to the left or right of the node,
thus reducing the number of **nodes** to be visited in the **search.**

## Abstract Data Type

In the implementation of **Binary Trees**, we will use a **Node** structure to represent the **Vertices** of the **Tree**
and we will perform our operations only with this structure.

Together with **Nodes**, in **Python**, we will use a **Class** to represent our **Tree** and make its manipulation easier.

The **Nodes** representing the **Vertices** of our **Tree** will store 3 values, which are the item
we want to store, be it a number or a string,
and two **references**, being them for the **Children Nodes** from the right and left.

**C ADT** Example:
```C
//Struct representing the nodes of the tree
struct binary_tree
{
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
};
```

**Python ADT** Example:
```Python
#Class that represents a node in
#binary tree
class Node:
    def __init__(self, val):
        self.right = None
        self.left = None
        self.data = val

#Class that represents our
#binary tree
class BinaryTree:
    def __init__(self, root=None):
        self.root = Node(root)
        self.size_right = self.sizeCount(self.root.right)
        self.size_left = self.sizeCount(self.root.left)
```

## Implementation of Binary Trees

The type of **Tree** implemented here will be the **Binary Tree**, in **Python**, and the **Binary Search Tree**, in **C**,
the difference between this type and
the **Binary Search Trees** is the organization
regarding the arrangement of the values ​​stored in both, which in **BST** 
is stored in an orderly way between major and minor.

The operations we can perform on a **Binary Tree** are **Insert**, **Remove**, **Sort** and **Search**.

The only operation not shown here is **Sort**.

#### Insert

**C** Example:
```C
//Function to select where the new edge will be insert, to make the tree a binary tree
myTree* add(myTree *tree, int item)
{
	//If tree is NULL, that is a leaf, so add the new edge here
	if (tree == NULL)
	{
		tree = create_tree(item, NULL, NULL);
	}
	//If item is lower than item on the struct, the new function recalls in the left side
	//Lower itens are ever insert on the left side of the actual edge
	else if (tree->item > item)
	{
		tree->left = add(tree->left, item);
	}
	//Counter-case of the last elseif
	else
	{
		tree->right = add(tree->right, item);
	}
	return tree;
}
```

**Python** Example:
```Python
# This method inserts a new node into the tree
def insert(self, temp, key):
    if self.root.data == None: # If root is empty, then our new node is root
        self.root.data = key
        return

    q = []          # Queue that stores the nodes to be visited
    q.append(temp)

    while (len(q)):
        temp = q[0]
        q.pop(0)

        if not temp.left:
            temp.left = Node(key) # Inserting new node
            self.sizeUpdte()      # Updating tree size
            break
        else:
            q.append(temp.left)   # Storing the visit on file

        if not temp.right:
            temp.right = Node(key) # Inserting new node
            self.sizeUpdte()       # Updating tree size
            break
        else:
            q.append(temp.right)   # Storing the visit on file
```

#### Remove

Removal in a **Binary Tree** can be done by removing a specific **Node** or by removing one of the **Leaf Node**,
which are the last **Nodes** of the **Tree**, without reference to others.

When we are removing **We** in a **Tree** we must be careful with removing the **Root Node**, treatments for
this case must be used in your program or structure implementation.

**C** Example:
```C
//Delete a node in tree
myTree* deleteNode(myTree *tree, int item){
	if (is_empty(tree)){
		return tree;
	}

	if (item < tree->item){
		tree->left = deleteNode(tree->left, item);
	}
	else if (item > tree->item){
		tree->right = deleteNode(tree->right, item);
	}
	else{
		if (tree->left == NULL){
			myTree* temp = tree->right;
			free(tree);
			return temp;
		}
		else if (tree->right == NULL){
			myTree* temp = tree->left;
			free(tree);
			return temp;
		}

		myTree* temp = minValueNode(tree->right);

		tree->item = temp->item;

		tree->right = deleteNode(tree->right, temp->item);
	}
	return tree;
}
```

**Python** Example:
```Python
#Method that traverses the tree in
#search of the deepest node to be removed
def deletion(self, key):
    if self.root == None: # Check if root isn't empty
        return None

    if self.root.left == None and self.root.right == None: # Checking that the root
        if self.root.data == key:                          # root is not the only node in the tree
            return None
        else:
            return self.root

    key_node = None
    q = []              # Queue that stores the nodes to be visited
    q.append(self.root)

    while (len(q)):
        temp = q.pop(0)
        if temp.data == key:
            key_node = temp
        if temp.left:
            q.append(temp.left)
        if temp.right:
            q.append(temp.right)

    if key_node: # If the searched key is found
        x = temp.data # storing the key so that the tree is updated
        self.deleteDeepest(temp) # Calling deepest node removal method
        key_node.data = x # Updating the New Node Key

    return self.root

# Method that removes the found node
def deleteDeepest(self, d_node):
    q = []
    q.append(self.root)

    if d_node is self.root: # If the node to be removed is the root
        self.updateRoot()   # We need to update the root
                            # reference if the tree is already populated
    while (len(q)):
        temp = q.pop(0)
        if temp is d_node:
            temp = None
            return
        if temp.right:
            if temp.right is d_node:
                temp.right = None # Performing the removal
                self.sizeUpdte()  # updating tree size
                return
            else:
                q.append(temp.right)

        if temp.left:
            if temp.left is d_node:
                temp.left = None # Performing the removal
                self.sizeUpdte() # updating tree size
                return
            else:
                q.append(temp.left)
```

#### Search

The search in both **Trees** will be done recursively, the only difference is the way this navigation will
be done, since the **Binary Search Tree**
is created following a certain ordering of the elements that make it up .

**C** Example:
```C
//Searching in tree
myTree* search(myTree *tree, int item)
{
	//The tree is empty!
	if ((tree == NULL) || (tree->item == item))
	{
		return tree;
	}
	//Go to the left, the lower itens stay o left side of the edges!
	else if (tree->item > item)
	{
		return search(tree->left, item);
	}
	//Counter-case
	else
	{
		return search(tree->right, item);
	}
}
```

**Python** Example:
```Python
#Method that performs the search in trees
def search(self, root, item, last_son=False):
    if last_son:
        if root.left.left == None or root.left.right == None:
            return root.left
        if root.right.right == None or root.right.left == None:
            return root.right

    if root is None or root.data == item:
        return root
    elif root.left is not None:
        return self.search(root.left, item)
    else:
        return self.search(root.right, item)
```

#### Print
Just one additional section, the way to print a **Tree** has 3 variations,
they are **In Order**, **Pre Order** and **Post Order**.

**C** Example:
```C
//Printing in order
void in_order(myTree *tree)
{
	in_order(tree->left);
	printf("%d\n", tree->item);
	in_order(tree->right);
}

//Printing in pre order
void pre_order(myTree *tree)
{
	printf("%d\n", tree->item);
	pre_order(tree->left);
	pre_order(tree->right);
}

//Printing in post order
void post_order(myTree *tree)
{
	if (!is_empty(tree))
	{
		post_order(tree->left);
		post_order(tree->right);
		printf("%d\n", tree->item);
	}
}
```

**Python** Example:
```Python
#Method showing the tree in preorder
def printPreOrder(self, root):
    print("(", end='')
    if root is not None:
        print("(", end='')
        print(root.data, end='')
        print(")", end='')
        self.printPreOrder(root.left)
        self.printPreOrder(root.right)
    print(")", end=' ')

#Method showing the tree in order
def printInOrder(self, root):
    print("(", end='')
    if root is not None:
        self.printInOrder(root.left)
        print("(", end='')
        print(root.data, end='')
        print(")", end=' ')
        self.printInOrder(root.right)
    print(")", end=' ')

#Method showing the tree in post-order
def printPostOrder(self, root):
    print("(", end='')
    if root is not None:
        self.printPostOrder(root.left)
        self.printPostOrder(root.right)
        print("(", end='')
        print(root.data, end='')
        print(")", end=' ')
    print(")", end=' ')
```

## Complexity analysis and comparisons

Time to make comparisons and final considerations.

The complexity analysis is given in big O notation.

**Search**, **Insert** and **Remove** in a **Binary Tree**
can arrive in O(log(n)) in both the worst and best case.

**Search**, **Insert** and **Remove** in a **Binary Search Tree**
can reach O(log(n)) in the best case and O(n) in its worst case.

The storage complexity of both is O(n).

## Finishing

This was a short summary and demonstration of implementing Binary Trees and Binary Search Trees, I hope you enjoyed it! :D

Good luck with your studies!

![](https://media.giphy.com/media/IzfJSTepKi5vW/giphy.gif)

## References

[Trees in Python](https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/) <br>
[Trees in Python pt2](https://www.geeksforgeeks.org/binary-tree-set-2-properties/) <br>
[Trees in Python pt3](https://www.geeksforgeeks.org/binary-tree-set-3-types-of-binary-tree/) <br>
[Trees in Python - Insertion in level order](https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/) <br>
[Trees in Python - Deletion](https://www.geeksforgeeks.org/deletion-binary-tree/) <br>
[Trees Theory](https://pythonhelp.wordpress.com/2015/01/19/arvore-binaria-de-busca-em-python/) <br>
[Trees Theory 2](https://algoritmosempython.com.br/cursos/algoritmos-python/estruturas-dados/arvores/) <br>
[Trees in C](https://www.ime.usp.br/~pf/algoritmos/aulas/bint.html) <br>
[Trees in C - Removing in BST](https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/) <br>
[Big O](https://www.bigocheatsheet.com/) <br>