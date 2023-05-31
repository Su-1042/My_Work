#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

struct TrieNode
{

    struct TrieNode *children[ALPHABET_SIZE];
    // If we just talk about english alphabets then ALPHABET_SIZE will be 26

    bool isEndofWord;
    // if true->special node->end of word
    // if false-> in between node
};

typedef struct TrieNode *Trie;

Trie Initialise()
{
    Trie t;

    t = (Trie)malloc(sizeof(struct TrieNode));

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        t->children[i] = (Trie)malloc(sizeof(struct TrieNode) * ALPHABET_SIZE);
        t->children[i] = NULL;
    }

    t->isEndofWord = false;

    return t;
}

Trie makenew(Trie T, int index)
{
    T->children[index] = Initialise();
    return T->children[index];
}

void InsertinTrie(Trie T, char *s, int length)
{
    Trie curr = T;

    for (int i = 0; i < length; i++)
    {
        int index = s[i] - 'a';

        if (curr->children[index] == NULL)
        {
            // we will create a new node
            curr->children[index] = makenew(curr, index);
        }

        curr = curr->children[index];
    }

    curr->isEndofWord = true;
}

bool Search(Trie T, char *s, int length)
{
    Trie curr = T;
    int flag = 0;

    for (int i = 0; i < length; i++)
    {
        int index = s[i] - 'a';
        if (curr->children[index] == NULL)
            return false;

        else
        {
            flag++;
            curr = curr->children[index];
        }
    }

    if (flag == length && curr->isEndofWord == true)
        return true;

    return false;
}

Trie AutoComplete(Trie T, char *prefix, int length)
{
    Trie curr = T;

    for (int i = 0; i < length; i++)
    {
        int index = prefix[i] - 'a';
        if (curr->children[index] == NULL)
            return;
        else
            curr = curr->children[index];
    }

    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (curr->children[i] == NULL)
            count++;
    }

    if (count == 26)
    {
        printf("NO WORDS!!!!!\n");
        return NULL;
    }

    else
    {
        return curr;
    }
}

void Print(Trie Root, char *prev, int idx)
{
    if (Root == NULL)
    {
        printf("%s", prev);
        return;
    }

    if (Root->isEndofWord == true)
    {
        printf("%s", prev);
    }

    for (int i = 0; i < 26; i++)
    {
        prev[idx] = 'a' + i;
        prev[idx + 1] = '\0';
        // it is important to thus mark the end of the word

        Print(Root->children[i], prev, idx + 1);
    }

    prev[idx] = 0;
}



Trie Delete(Trie T, char *s, int idx)
{
    // initially your idx will be 0
    if (T == NULL)
    {
        return;
    }

    if (s[idx] == '\0' && T->isEndofWord == NULL)
    {
        T->isEndofWord = false;
        if (CheckForChildren(T))
            return T;
        free(T);
        return NULL;
    }

    Trie temp=T->children[s[idx]-'a'];

    if (temp== NULL)
    {
        return NULL;
    }

    T->children[s[idx]-'a'] = Delete(temp,s,idx+1);

    if(CheckForChildren(T)||T->isEndofWord)
        return T;
    free(T);

}

int main()
{
    int numstrings;
    scanf("%d", &numstrings);

    Trie T;
    T = Initialise();

    for (int i = 0; i < numstrings; i++)
    {
        int len;
        scanf("%d", &len);

        char *word = (char *)malloc(sizeof(char) * (len + 1));
        scanf("%s", word);

        InsertinTrie(T, word, len);
        // printf("inserted\n");
    }

    while (1)
    {
        printf("------------------------\n");
        printf("0: search word\n");
        printf("1: print tree\n");
        printf("2: exit search\n");
        printf("------------------------\n");

        int x;
        scanf("%d", &x);

        if (x == 0)
        {
            int wlen;
            scanf("%d", &wlen);
            char *w = (char *)malloc(sizeof(char) * (wlen + 1));
            scanf("%s", w);

            bool exists;
            exists = Search(T, w, wlen);

            if (exists == true)
                printf("WORD FOUND\n");

            else
                printf("OOPS!!\n");
        }

        else if (x == 1)
        {

            Print(T, empty string, 0);
        }

        else
            break;
        printf("\n");
    }
    printf("\n");
}

// search and insert chalta hai tera

// checkforchildren function likhna hai 
