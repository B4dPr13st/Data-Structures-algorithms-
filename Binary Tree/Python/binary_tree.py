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

    #Method that returns the reference to the root of the tree
    def getRoot(self):
        return self.root

    #Method that calculates tree size
    def treeSize(self):
        return self.size_left + self.size_right

    #Method that calls the counter of nodes
    #in each direction of the tree from the root
    def sizeUpdte(self):
        self.size_right = self.sizeCount(self.root.right) # Count from right
        self.size_left = self.sizeCount(self.root.left)   # Count from left

    #Method that counts tree size for both sides
    def sizeCount(self, root, n=0):
        if root is None: # Check if tree isn't empty
            return n
        elif root.left is not None:
            return self.sizeCount(root.left, n + 1) # Counting is done recursively
        else:
            return self.sizeCount(root.right, n + 1) # Counting is done recursively

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

    # Method that updates the reference to the root
    def updateRoot(self):
        if self.root is None: # Checking if the tree is empty
            return None

        if self.root.right == None and self.root.left is not None: # If one side of the root is empty,
            self.root = self.root.left                             # # we simply say that the next node is the new root.
        if self.root.left == None and self.root.right is not None:
            self.root = self.root.right
        if self.root.left is not None and self.root.right is None:
            if self.size_left < self.size_right: # Checking which side is larger, we will insert the subtree from the
                temp = self.root.left            # other direction on the shortest side of the tree and
                                                 # transform the first node on the larger side into the new root
                lastSon = self.search(self.root.left, item=None)  # Searching for the last leaf node
                if lastSon.left is None:
                    lastSon.left = temp
                if lastSon.right is None:
                    lastSon.right = temp
                self.root = self.root.right # Updating root
                self.sizeUpdte()
            else:
                temp = self.root.right
                lastSon = self.search(self.root.right, item=None) # Searching for the last leaf node
                if lastSon.left is None:
                    lastSon.left = temp
                if lastSon.right is None:
                    lastSon.right = temp
                self.root = self.root.left # Updating root
                self.sizeUpdte()

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

if __name__ == '__main__':
    myTree = BinaryTree(0)
    myTree.insert(myTree.getRoot(), 10)
    myTree.insert(myTree.getRoot(), 3)
    myTree.insert(myTree.getRoot(), 28)
    myTree.insert(myTree.getRoot(), 56)
    myTree.insert(myTree.getRoot(), 4)
    myTree.insert(myTree.getRoot(), 1)
    myTree.insert(myTree.getRoot(), 13)
    myTree.insert(myTree.getRoot(), 5)
    myTree.printInOrder(myTree.getRoot())
    print("\n--------------------------------")
    myTree.printPreOrder(myTree.getRoot())
    print("\n--------------------------------")
    myTree.printPostOrder(myTree.getRoot())
    print("\n--------------------------------")
    print("\nTree size: ", myTree.treeSize())
    myTree.deletion(56)
    myTree.deletion(0)
    myTree.search(myTree.getRoot(), 28)
    print("\n--------------------------------")
    myTree.printPreOrder(myTree.getRoot())
    print("\n--------------------------------")
    myTree.printPostOrder(myTree.getRoot())
    print("\n--------------------------------")
    print("\nTree size: ", myTree.treeSize())