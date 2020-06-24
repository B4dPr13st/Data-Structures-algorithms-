import sys
import math

#Node class
class Node:
    #Method to initialize the node OBJ
    def __init__(self, data):
        self.data = data #Assign data
        self.next = None #Initialize next as NULL

#Linked List class
class LinkedList:
    #Method to initialize the SLL(Simply Linked List) OBJ(Object)
    def __init__(self):
        self.head = None

    #This method inserts a node at SLL's head
    def push(self, new_item):
        #Allocate the node
        new_node = Node(new_item)
        new_node.next = self.head
        self.head = new_node

    #This method inserts a node after a given node
    def pushAftr(self, previous, new_item):
        if previous is None:
            print("A non NULL node is necessary!")
            return
        new_node = Node(new_item)
        new_node.next = previous.next
        previous.next = new_node

    #This method inserts a node on SLL's tail
    def pushOnTail(self, new_item):
        new_node = Node(new_item)
        #If SLL is empty the new node turns into SLL's head
        if self.head is None:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def reverseList(self):
        previous = None
        current = self.head
        while current is not None:
            next = current.next
            current.next = previous
            previous = current
            current = next
        self.head = previous

    #This method display the list's items
    def showList(self):
        aux = self.head
        loop = 0
        while(aux):
            print("Item list #" + str(loop) + ": " + str(aux.data))
            aux = aux.next
            loop += 1

    #This method search an item in list
    def search(self, x):
        current = self.head

        while current != None:
            if current.data == x:
                return True
            current = current.next
        return False

    #This method removes an specific item from list
    def rem(self, item):
        aux = self.head

        if aux is not None:
            if aux.data == item:
                self.head = aux.next
                aux = None
                return

        while aux is not None:
            if aux.data == item:
                break
            previous = aux
            aux = aux.next

        if aux == None:
            return
        previous.next = aux.next
        aux = None
        print("Key was removed!")

#Function to sort SLL using selectionsort
def selectionSort(head):
    a = b = head

    while b.next:
        c = d = b.next

        while d:
            if b.data > d.data:
                if b.next == d:
                    if b == head:
                        b.next = d.next
                        d.next = b

                        b,d = d,b
                        c = d

                        head = b

                        d = d.next
                    else:
                        b.next = d.next
                        d.next = b
                        a.next = d

                        b, d = d, b
                        c = d

                        d = d.next
                else:
                    if b == head:
                        r = b.next
                        b.next = d.next
                        d.next = r
                        c.next = b

                        b, d = d, b
                        c = d

                        d = d.next

                        head = b
                    else:
                        r = b.next
                        b.next = d.next
                        d.next = r
                        c.next = b
                        a.next = d

                        b, d = d, b
                        c = d

                        d = d.next
            else:
                c = d
                d = d.next

        a = b
        b = b.next
    return head

def remFromHead(head):
    if not head:
        return None
    aux = head
    head = head.next
    aux = None
    print("Head removed!")
    return head

#Function to delete SLL's node for tail
def remFromTail(head):
    if head == None:
        return None
    if head.next == None:
        head = None
        return None
    penultimate = head
    while penultimate.next.next:
        penultimate = penultimate.next
    penultimate.next = None
    print("Tail removed!")
    return head

if __name__=='__main__':
    #Start with an empty list
    SLL = LinkedList()
    while True:
        print("--------------------")
        print("1 - Insert")
        print("2 - Reverse")
        print("3 - Order")
        print("4 - Show")
        print("5 - Search")
        print("6 - Remove")
        print("7 - Exit")
        print("--------------------")
        opt = int(input())
        if opt == 1:
            print("You want to insert on Head, Tail or After another key?")
            print("1 - Head")
            print("2 - Tail")
            print("3 - After another key")
            y = int(input())
            if y == 1:
                print("Insert the number: ")
                item = int(input())
                SLL.push(item)
            elif y == 2:
                print("Insert the number: ")
                item = int(input())
                SLL.pushOnTail(item)
            elif y == 3:
                print("Insert the number: ")
                item = int(input())
                SLL.pushAftr(SLL, item)
            else:
                print("Enter a valid option!")
        elif opt == 2:
            SLL.reverseList()
        elif opt == 3:
            SLL.head = selectionSort(SLL.head)
        elif opt == 4:
            SLL.showList()
        elif opt == 5:
            print("Enter the wanted key: ")
            key = int(input())
            if SLL.search(key) == True:
                print("The key is on the list!")
            else:
                print("The key isn't on the list!")
        elif opt == 6:
            print("You want to remove from Head, Tail or Specific key?")
            print("1 - Head")
            print("2 - Tail")
            print("3 - Specific key")
            x = int(input())
            if x == 1:
                SLL.head = remFromHead(SLL.head)
            if x == 2:
                SLL.head = remFromTail(SLL.head)
            if x == 3:
                print("Enter the key you want to remove: ")
                key = int(input())
                SLL.rem(key)
            if x == 4:
                print("Enter a valid option!")
        elif opt == 7:
            exit()
        else:
            print("Enter a valid option!")