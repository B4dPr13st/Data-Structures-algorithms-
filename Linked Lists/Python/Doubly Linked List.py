import gc

#Node of a DLL(Doubly Linked List)
class Node:
    def __init__(self, next=None, prev=None, data=None):
        self.next = next
        self.prev = prev
        self.data = data

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    #This method inserts an item on DLL's head
    def push(self, new_key):
        new_node = Node(data=new_key)
        new_node.next = self.head
        new_node.prev = None

        if self.head is not None:
            self.head.prev = new_node

        self.head = new_node

    #This method inserts a node after an given DLL's node
    def pushAftr(self, previous, new_key):
        if previous is None:
            print("A non NULL value is necessary!")
            return
        new_node = Node(data=new_key)
        new_node.next = previous.next
        previous.next = new_node
        new_node.prev = previous

        if new_node.next is not None:
            new_node.next.prev = new_node

    #This method inserts a node at DLL's tail
    def pushOnTail(self, new_key):
        new_node = Node(data=new_key)
        last = self.head
        new_node.next = None

        if self.head is None:
            new_node.prev = None
            self.head = new_node
            return

        while last.next is not None:
            last = last.next

        last.next = new_node
        new_node.prev = last

    #This method diplay the list items
    def showList(self, node):
        loop = 0
        if node is None:
            print("The list is empty")
            return

        while node is not None:
            print("List item #" + str(loop) + ": " + str(node.data))
            last = node
            node = node.next
            loop += 1

    #This method reverse the DLL
    def reverse(self):
        aux = None
        current = self.head

        while current is not None:
            aux = current.prev
            current.prev = current.next
            current.next = aux
            current = current.prev

        if aux is not None:
            self.head = aux.prev

    #This method merge two LLs
    def merge(self, first, second):
        if first is None:
            return second

        if second is None:
            return first

        if first.data < second.data:
            first.next = self.merge(first.next, second)
            first.next.prev = first
            first.prev = None
            return first
        else:
            second.next = self.merge(first, second.next)
            second.next.prev = second
            second.prev = None
            return second

    #This method do the merge sort
    def mergeSort(self, aux):
        if aux is None:
            return aux
        if aux.next is None:
            return aux

        second = self.split(aux)

        #Recrusion for left and right halves
        aux = self.mergeSort(aux)
        second = self.mergeSort(second)

        #Merge the sorted halves
        return self.merge(aux, second)

    #This method splits DLL into two DLLs
    def split(self, aux):
        fast = slow = aux
        while True:
            if fast.next is None:
                break
            if fast.next.next is None:
                break
            fast = fast.next.next
            slow = slow.next

        aux = slow.next
        slow.next = None
        return aux

    # This method search an item in list
    def search(self, x):
        current = self.head

        while current != None:
            if current.data == x:
                return True
            current = current.next
        return False

    #This method removes a node from DLL
    def rem(self, toBeDeleted):
        if self.head is None or toBeDeleted is None:
            return

        if self.head == toBeDeleted:
            self.head = toBeDeleted.next

        if toBeDeleted.next is not None:
            toBeDeleted.next.prev = toBeDeleted.prev

        if toBeDeleted.prev is not None:
            toBeDeleted.prev.next = toBeDeleted.next

        gc.collect()

if __name__=='__main__':
    #Start with an empty list
    DLL = DoublyLinkedList()
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
                DLL.push(item)
            elif y == 2:
                print("Insert the number: ")
                item = int(input())
                DLL.pushOnTail(item)
            elif y == 3:
                print("Insert the number: ")
                item = int(input())
                DLL.pushAftr(DLL.head, item)
            else:
                print("Enter a valid option!")
        elif opt == 2:
            DLL.reverse()
        elif opt == 3:
            DLL.head = DLL.mergeSort(DLL.head)
        elif opt == 4:
            DLL.showList(DLL.head)
        elif opt == 5:
            print("Enter the wanted key: ")
            key = int(input())
            if DLL.search(key) == True:
                print("The key is on the list!")
            else:
                print("The key isn't on the list!")
        elif opt == 6:
                DLL.rem(DLL.head)
        elif opt == 7:
            exit()
        else:
            print("Enter a valid option!")