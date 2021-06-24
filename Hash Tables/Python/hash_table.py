#Class that represents the element
#on n index of hash list
class Element:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value

#Class that represents the hash table
class HashTable:
    def __init__(self):
        self.Hash_list = [None] * 11 #  Initializes list with 15 None
                                     #  spaces

    #Class Method to insert a new item or
    #overwrite an item on hash table
    def push(self,key,item):
        h = key % 11
        while self.Hash_list[h] != None:
            if self.Hash_list[h].key == key:
                self.Hash_list[h].value = item
                break
            h = (h + 1) % 11

        if self.Hash_list[h] == None:
            new_element = Element(key, item)
            self.Hash_list[h] = new_element

    #Class method to search an item
    #in the hash table
    def getElement(self,R_key):
        h = R_key % 11
        while self.Hash_list[h] != None:
            if self.Hash_list[h].key == R_key:
                return self.Hash_list[h].value
            h = (h + 1) % 11
        return None

    #Class method to remove an item
    #from hash table
    def pop(self, R_key):
        h = R_key % 11
        while self.Hash_list[h] != None:
            if self.Hash_list[h].key == R_key:
                self.Hash_list[h].key = -1  #  Logical removal of an hash table
                                            #  Element
            h = (h + 1) % 11

if __name__ == '__main__':
    HashT = HashTable()
    HashT.push(3,1000)
    HashT.push(14,2000)
    HashT.push(15,3000)
    HashT.push(92,4000)
    print(HashT.getElement(15))
    HashT.pop(15)