MAX_Q_SIZE = 100

#Class used for queue implementation
class MyQueue():
    def __init__(self, capacity=MAX_Q_SIZE):
        self.front = self.size = 0
        self.rear = capacity - 1
        self.Q = [None] * capacity
        self.capacity = capacity

    def IsEmpty(self):
        return self.size == 0

    def IsFull(self):
        return self.capacity == self.size

    def EnQueue(self, item):
        if self.IsFull():
            print("Full")
            return
        self.rear = (self.rear + 1) % (self.capacity)
        self.Q[self.rear] = item
        self.size += 1
        print("Enqueued", str(item))

    def DeQueue(self):
        if self.IsEmpty():
            print("Empty")
            return

        print("Dequeued", str(self.Q[self.front]))
        self.front = (self.front + 1) % (self.capacity)
        self.size -= 1

    def Queue_Front(self):
        if self.IsEmpty():
            print("Empty queue")
            return
        print("Front item is", str(self.front))

    def Queue_rear(self):
        if self.IsEmpty():
            print("Empty queue")
            return
        print("Rear item is", str(self.rear))

if __name__ == '__main__':
    q = MyQueue()
    MyQueue.EnQueue(3)