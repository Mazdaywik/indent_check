#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Note
{
    int key;
    long kol;
};

struct mini_array_t
{
    struct Note *list_notes;
    long long size;
};

struct array_t
{
    struct mini_array_t *table;
    long long size;
};

int note_search(struct mini_array_t *mini_array, int key)
{
    for (int i = 0; i < mini_array->size; i++)
    {
        if (mini_array->list_notes[i].key == key)
        {
            return i;
        }
    }
    return -1;
}

long array_get(struct array_t *t, int key)
{
    int index = note_search(&t->table[(abs(key) % t->size)], key);
    if (index != -1)
    {
        return t->table[(abs(key) % t->size)].list_notes[index].kol;
    }
    return index;
}

void array_insert(struct array_t *t, int key, long kol)
{
    int index = note_search(&t->table[(abs(key) % t->size)], key);
    if (index != -1)
    {
        t->table[(abs(key) % t->size)].list_notes[index].kol = kol;
    }
    else
    {
        struct mini_array_t *mini_array = &t->table[(abs(key) % t->size)];
        mini_array->list_notes[mini_array->size].key = key;
        mini_array->list_notes[mini_array->size].kol = kol;
        mini_array->size++;        
    }
}

int main()
{
    struct array_t *array =  (struct array_t*)malloc(sizeof(struct array_t));
    array->table = malloc(100000 * sizeof(struct mini_array_t));
    array->size = 100000;

    for (int i = 0; i < 100000; i++)
    {
        array->table[i].list_notes = malloc(500 * sizeof(struct Note));
        array->table[i].size = 0;
        for(int j = 0; j < 500; j++){
            array->table[i].list_notes[j].key = 0;
            array->table[i].list_notes[j].kol = 0;
        }
    }

    int n;
    scanf("%d", &n);

    int xor = 0;
    long long ans = 0;
    int count[n];

    for(int i = 0; i < n; i++)
        count[i] = 0;

    int num;
    scanf("%d", &num);

    xor ^= num;
    if (num == 0)
    {
        count[0] = 1;
        ans++;
    }

    array_insert(array, xor, 0);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &num);
        xor ^= num;

        long j = array_get(array, xor);

        if (j != -1)
        {
            count[i] = count[j] + 1;
        }

        if (xor == 0 && count[i] == 0)
        {
            count[i]++;
        }

        array_insert(array, xor, i);
        ans += count[i];
    }

    printf("%lld\n", ans);

    for (int i = 0; i < 100000; i++)
        free(array->table[i].list_notes);
    free(array->table);
    free(array);

    return 0;
}