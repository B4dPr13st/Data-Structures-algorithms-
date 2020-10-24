#stack implementation using a singly linked list
#Node of list
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Stack:
    #This method initializes the stack
    #Initializing stack
    def __init__(self):
        self.head = Node("head")
        self.size = 0

    #string representation of stack
    def __str__(self):
        current = self.head.next
        out = ""
        while current:
           out += str(current.value) + "->"
           current = current.next
        return out[:-3]

    #get size of stack
    def getSize(self):
        return self.size

    #check if stack is empty
    def isEmpty(self):
        return self.size == 0

    #Get the item on top of stack
    def peek(self):
        # Checking if stack is empty before getting the top item
        if self.isEmpty():
            raise Exception("Stack is empty!")
        return self.head.next.value

    #Insert a value into the stack
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head.next
        self.head.next = new_node
        self.size += 1

    #Remove from stack and return
    def pop(self):
        if self.isEmpty():
            raise Exception("Stack is empty!")
        remove = self.head.next
        self.head.next = self.head.next.next
        self.size -= 1
        return remove.value

#Start program
if __name__ == "__main__":
    stack = Stack()
    for i in range(1,11):
        stack.push(i)
    print(f"Stack: {stack}")

    for _ in range(1,6):
        remove = stack.pop()
        print(f"Pop: {remove}")
    print(f"Stack: {stack}")