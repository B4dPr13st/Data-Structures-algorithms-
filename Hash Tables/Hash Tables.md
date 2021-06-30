# Hash Tables

![](https://alpingi.com/wp-content/uploads/2018/02/AMCAT-Hash-Tables-Questions.jpg)

**Hash Tables** are data structures that use the concept of 
**Key-value** to store data, we 
will now see how this structure works in this way.

## Key-Value

As said before, **Hash Tables** work from the concept of **Key-value**
, where a certain value is stored by a search key and can only be accessed by it.

A basic example of the use of this concept are **Arrays**, which 
we can directly access a value stored in it from its position (key), example:

```C
int array[3];
int x;

array[2] = 67;
 
x = array[2]
```

In the example above, we access **key** 
2 of the array to access its **value**, which is 67.

**Hash Tables** work this way, keeping a **Value** that can only be accessed by a certain **Key**, the difference 
is that in addition to only allowing access in this way, the 
table uses a hash function responsible for leaving the storage of items in a dispersed 
way, that is, not necessarily what is stored in a **Hash Table** is organized side by side.

Practical examples of using **Hash Tables** are:

- Index large volumes of information, such as in databases
- Storage of access **keys** that are made up of characters mixed with integers, which cannot be used as a direct access index in arrays
- Storage of registration numbers and CPF

Thus, the application of a **Hash Table** is when we need to store data that consists of numbers that are 
too large to be implemented with **Arrays** or **Keys** 
that consist of different types of information, in addition to several other viable scenarios.

Despite all this working from scattering, **Hash Tables** can end up suffering from collisions, that is, when we 
try to store a new **value** in a **key** that is already storing something.

To deal with this we have 3 options:

- Pretend the problem doesn't exist
- Improve the hash function so that collisions occur much less often
- Implement collision handling

## Abstract Data Type

As explained earlier with other data structures, each language has its own abstraction ADT of data structures. As we 
are using C and Python, both representations will be presented here.

**C ADT** Example:
```C
//This struct represents the item stored in the table.
struct Element
{
	int key;
	int value;
};

//This struct represents the table
struct Hash_table
{
	hash_element *table[11];
};
```

**Python ADT** Example:
```Python
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
```

## Implementation of Hash Tables

As said, **Hash Tables** use hash functions to perform any operations within it, the hash 
function here will be included within the functions described as:
```python
h = key % 11
```

In our hash function we will use prime numbers, as the use of prime
numbers drastically reduces the occurrence of collisions.

**Hash Tables** have 3 main operations,
namely **Push/Put**, **Pop/Remove** and **Get**.

#### Push/Put

Inserting a **Hash Table** is as follows:

**C** Example:
```C
//function to put a new value or overwrite into hash table
void put(hash_t *HASH, int required_key, int ITEM)
{
	int h = required_key % 11;
	while (HASH->table[h] != NULL)
	{
		if (HASH->table[h]->key == required_key)
		{
			HASH->table[h]->value = ITEM;
			break;
		}
		h = (h + 1) % 11;
	}
	if (HASH->table[h] == NULL)
	{
		hash_element *new_element = (hash_element*)malloc(sizeof(hash_element));
		new_element->key = required_key;
		new_element->value = ITEM;
		HASH->table[h] = new_element;
	}
}
```

**Python** Example:
```Python
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
```

#### Pop/Remove

Removal in **Hash Tables** usually happens in a logical way.

**C** Example:
```C
//function to remove an value from hash table
void remove_from_hash(hash_t *HASH, int required_key)
{
	int h = required_key % 11;
	while (HASH->table[h] != NULL)
	{
		if (HASH->table[h]->key == required_key)
		{
			HASH->table[h]->key = -1;
		}
		h = (h + 1) % 11;
	}
}
```

**Python** Example:
```Python
#Class method to remove an item
#from hash table
def pop(self, R_key):
    h = R_key % 11
    while self.Hash_list[h] != None:
        if self.Hash_list[h].key == R_key:
            self.Hash_list[h].key = -1  #  Logical removal of an hash table
                                        #  Element
        h = (h + 1) % 11
```

#### Get

The **Get** function looks for a value in the table given a certain key,
if it exists, it will return that value.

**C** Example:
```C
//function to search and get a value from hash table
int get(hash_t *HASH, int required_key)
{
	int h = required_key % 11;
	while (HASH->table[h] != NULL)
	{
		if (HASH->table[h]->key == required_key)
		{
			return HASH->table[h]->value;
		}
		h = (h + 1) % 11;
	}
	return -100;
}
```

**Python** Example:
```Python
#Class method to search an item
#in the hash table
def getElement(self,R_key):
    h = R_key % 11
    while self.Hash_list[h] != None:
        if self.Hash_list[h].key == R_key:
            return self.Hash_list[h].value
        h = (h + 1) % 11
    return None
```

## Complexity analysis and comparisons

Time to make comparisons and final considerations.

The complexity analysis is given in big O notation.

In **Hash Tables**, your main operations **Push/Put**, **Pop/Remove** 
and **Get** have O(1) complexity, but in their worst case they can reach O(n).

## Finishing

This was a short summary and demonstration of implementing Hash Tables, I hope you enjoyed it! :D

Good luck with your studies!

![](https://media.giphy.com/media/fxe8v45NNXFd4jdaNI/giphy.gif)

## References

[Hash Tables - João Arthur Brunet](https://joaoarthurbm.github.io/eda/posts/hashtable/) <br>
[Hash Tables - Theory](https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/st-hash.html) <br>
[Hash Tables - Python](http://blog.chapagain.com.np/hash-table-implementation-in-python-data-structures-algorithms/) <br>
[Hash Tables - Big O](https://www.bigocheatsheet.com/) <br>
[Hash Tables - Python and C](https://www.geeksforgeeks.org/index-mapping-or-trivial-hashing-with-negatives-allowed/) <br>