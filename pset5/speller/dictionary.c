// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

unsigned int word_counter = 0;
bool loaded = false;

// Number of buckets in hash table
const unsigned int N = 143091;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int length = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        length++;
    }
    char word_copy[length + 1];
    for (int i = 0; i < length; i++)
    {
        word_copy[i] = tolower(word[i]);
    }
    word_copy[length] = '\0';
    int hashed = hash(word_copy);
    node *pointer = table[hashed];
    while (pointer != NULL)
    {
        if (strcmp(pointer->word, word_copy) == 0)
        {
            return true;
        }
        else
        {
            pointer = pointer->next;
        }
    }
    return false;
}

// Hashes word to a number
// Credits to stackoverflow
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    for (const char *ptr = word; *ptr != '\0'; ptr++)
    {
        hash = ((hash << 5) + hash) + tolower(*ptr);
    }
    return hash % N;
 }

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    FILE *pFile = fopen(dictionary, "r");
    if (pFile == NULL)
    {
        printf("unable to load the dictionary");
    }
    while (true)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("not enough memory");
            return false;
        }
        fscanf(pFile, "%s", new_node->word);
        new_node->next = NULL;
        if (feof(pFile))
        {
            free(new_node);
            break;
        }
        word_counter++;
        int hashed = hash(new_node->word);
        node *head = table[hashed];
        if (head == NULL)
        {
            table[hashed] = new_node;
        }
        else
        {
            new_node->next = table[hashed];
            table[hashed] = new_node;
        }
    }
    fclose(pFile);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded)
    {
        return word_counter;
    }
    else
    {
        return 0;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *pointer = table[i];
        while (pointer != NULL)
        {
            // Destroy nodes
            node *temp = pointer;
            pointer = pointer->next;
            free(temp);
        }
    }
    loaded = false;
    return true;
}