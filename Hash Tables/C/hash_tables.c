#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//This struct represents the item stored in the table
typedef struct element
{
	int key;
	int value;
}hash_element;

//This struct represents the table
typedef struct hash_table
{
	hash_element *table[11];
}hash_t;

//function to remove an value from hash table
void remove_from_hash(hash_t *HASH, int required_key);

//function to search and get a value from hash table
int get(hash_t *HASH, int required_key);

//function to put a new value into hash table
void put(hash_t *HASH, int required_key, int ITEM);

//creates and initializes hash table
hash_t* create_hash_table();

int main()
{
	
	return 0;
}

//creates and initializes hash table
hash_t* create_hash_table()
{
	hash_t *new_hash_table = (hash_t*)malloc(sizeof(hash_t));
	int i;
	for (int i = 0; i < 11; i++)
	{
		new_hash_table->table[i] = NULL;
	}
	return new_hash_table;
}

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