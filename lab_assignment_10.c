#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//trie

typedef struct Trie {
    int flag;
    struct Trie *children[26];
} Trie;

void insert(Trie **ppTrie, char *word) {
    if (*ppTrie == NULL) return;

    int length = strlen(word);
    Trie *temp = *ppTrie;

    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';

        if (temp->children[index] == NULL) {
            temp->children[index] = (Trie*)calloc(1, sizeof(Trie));
        }

        temp = temp->children[index];
    }

    temp->flag++;
}

int numberOfOccurrences(Trie *pTrie, char *word) {
    if (pTrie == NULL) return 0;

    int length = strlen(word);
    Trie *temp = pTrie;

    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';

        if (temp->children[index] == NULL) {
            return 0;
        }

        temp = temp->children[index];
    }

    return temp->flag;
}

Trie *deallocateTrie(Trie *pTrie) {
    if (pTrie == NULL) return NULL;

    for (int i = 0; i < 26; i++) {
        deallocateTrie(pTrie->children[i]);
    }

    free(pTrie);
    return NULL;
}

int main(void) {
    Trie *trie = (Trie*)calloc(1, sizeof(Trie));

    // read the number of words in the dictionary
    /*int numWords;
    scanf("%d", &numWords);

    // parse line by line, and insert each word to the trie data structure
    char word[100];
    for (int i = 0; i < numWords; i++) {
        scanf("%s", word);
        insert(&trie, word);
    }*/

    // test the numberOfOccurrences function with some sample words
    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    for (int i = 0; i < 5; i++) {
        printf("%s: %d\n", pWords[i], numberOfOccurrences(trie, pWords[i]));
    }

    trie = deallocateTrie(trie);
    if (trie != NULL) {
        printf("There is an error in this program\n");
    }

    return 0;
}
