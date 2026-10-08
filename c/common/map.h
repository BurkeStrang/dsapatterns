// Hash maps, used where Go would use map[int]int or map[string]int.
//
// IntMap has int keys and StrMap has string keys; both store int values.
// A zeroed map is empty. Looking up a missing key gives 0, the same as Go.
#ifndef DSAPATTERNS_COMMON_MAP_H
#define DSAPATTERNS_COMMON_MAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

enum
{
    MAP_EMPTY = 0,
    MAP_USED = 1,
    MAP_DELETED = 2
};

// ---------------------------------------------------------------------------
// IntMap: int -> int
// ---------------------------------------------------------------------------

typedef struct
{
    int key;
    int value;
    char state;
} IntMapSlot;

typedef struct
{
    IntMapSlot *slots;
    int len;  // number of keys in the map
    int cap;  // number of slots; always a power of two
    int used; // slots that are used or deleted
} IntMap;

static inline unsigned intmap_hash
(
    int key
)
{
    unsigned h = (unsigned)key;
    h ^= h >> 16;
    h *= 0x45d9f3bU;
    h ^= h >> 16;
    return h;
}

// intmap_find returns the slot holding key, or NULL if it is not in the map.
static inline IntMapSlot *intmap_find
(
    const IntMap *map,
    int key
)
{
    if (map->cap == 0)
    {
        return NULL;
    }
    unsigned mask = (unsigned)map->cap - 1;
    for (unsigned i = intmap_hash(key) & mask;; i = (i + 1) & mask)
    {
        IntMapSlot *slot = &map->slots[i];
        if (slot->state == MAP_EMPTY)
        {
            return NULL;
        }
        if (slot->state == MAP_USED && slot->key == key)
        {
            return slot;
        }
    }
}

static inline void intmap_set
(
    IntMap *map,
    int key,
    int value
);

static inline void intmap_grow
(
    IntMap *map
)
{
    IntMap bigger = {0};
    bigger.cap = map->cap < 8 ? 16 : map->cap * 2;
    bigger.slots = calloc((size_t)bigger.cap, sizeof(bigger.slots[0]));
    for (int i = 0; i < map->cap; i++)
    {
        if (map->slots[i].state == MAP_USED)
        {
            intmap_set(&bigger, map->slots[i].key, map->slots[i].value);
        }
    }
    free(map->slots);
    *map = bigger;
}

// intmap_set stores value under key, replacing any earlier value.
static inline void intmap_set
(
    IntMap *map,
    int key,
    int value
)
{
    IntMapSlot *found = intmap_find(map, key);
    if (found != NULL)
    {
        found->value = value;
        return;
    }
    if ((map->used + 1) * 2 > map->cap)
    {
        intmap_grow(map);
    }
    unsigned mask = (unsigned)map->cap - 1;
    unsigned i = intmap_hash(key) & mask;
    while (map->slots[i].state == MAP_USED)
    {
        i = (i + 1) & mask;
    }
    if (map->slots[i].state == MAP_EMPTY)
    {
        map->used++;
    }
    map->slots[i] = (IntMapSlot){key, value, MAP_USED};
    map->len++;
}

// intmap_has reports whether key is in the map.
static inline bool intmap_has
(
    const IntMap *map,
    int key
)
{
    return intmap_find(map, key) != NULL;
}

// intmap_get returns the value stored under key, or 0 if there is none.
static inline int intmap_get
(
    const IntMap *map,
    int key
)
{
    IntMapSlot *slot = intmap_find(map, key);
    return slot == NULL ? 0 : slot->value;
}

// intmap_add adds delta to the value under key (starting from 0 if the key is
// new) and returns the new value. intmap_add(&m, k, 1) is Go's m[k]++.
static inline int intmap_add
(
    IntMap *map,
    int key,
    int delta
)
{
    int value = intmap_get(map, key) + delta;
    intmap_set(map, key, value);
    return value;
}

// intmap_remove deletes key from the map; it does nothing if key is missing.
static inline void intmap_remove
(
    IntMap *map,
    int key
)
{
    IntMapSlot *slot = intmap_find(map, key);
    if (slot != NULL)
    {
        slot->state = MAP_DELETED;
        map->len--;
    }
}

// intmap_next steps through the map. Start with *iter = 0 and call it until
// it returns false; each true result fills in *key and *value.
static inline bool intmap_next
(
    const IntMap *map,
    int *iter,
    int *key,
    int *value
)
{
    while (*iter < map->cap)
    {
        IntMapSlot *slot = &map->slots[(*iter)++];
        if (slot->state == MAP_USED)
        {
            *key = slot->key;
            *value = slot->value;
            return true;
        }
    }
    return false;
}

static inline void intmap_free
(
    IntMap *map
)
{
    free(map->slots);
    *map = (IntMap){0};
}

// ---------------------------------------------------------------------------
// StrMap: string -> int
// ---------------------------------------------------------------------------

typedef struct
{
    char *key; // owned copy of the key
    int value;
    char state;
} StrMapSlot;

typedef struct
{
    StrMapSlot *slots;
    int len;  // number of keys in the map
    int cap;  // number of slots; always a power of two
    int used; // slots that are used or deleted
} StrMap;

static inline unsigned strmap_hash
(
    const char *key
)
{
    unsigned h = 2166136261U;
    for (const char *p = key; *p != '\0'; p++)
    {
        h ^= (unsigned char)*p;
        h *= 16777619U;
    }
    return h;
}

// strmap_find returns the slot holding key, or NULL if it is not in the map.
static inline StrMapSlot *strmap_find
(
    const StrMap *map,
    const char *key
)
{
    if (map->cap == 0)
    {
        return NULL;
    }
    unsigned mask = (unsigned)map->cap - 1;
    for (unsigned i = strmap_hash(key) & mask;; i = (i + 1) & mask)
    {
        StrMapSlot *slot = &map->slots[i];
        if (slot->state == MAP_EMPTY)
        {
            return NULL;
        }
        if (slot->state == MAP_USED && strcmp(slot->key, key) == 0)
        {
            return slot;
        }
    }
}

static inline void strmap_insert_owned
(
    StrMap *map,
    char *key,
    int value
)
{
    unsigned mask = (unsigned)map->cap - 1;
    unsigned i = strmap_hash(key) & mask;
    while (map->slots[i].state == MAP_USED)
    {
        i = (i + 1) & mask;
    }
    if (map->slots[i].state == MAP_EMPTY)
    {
        map->used++;
    }
    map->slots[i] = (StrMapSlot){key, value, MAP_USED};
    map->len++;
}

static inline void strmap_grow
(
    StrMap *map
)
{
    StrMap bigger = {0};
    bigger.cap = map->cap < 8 ? 16 : map->cap * 2;
    bigger.slots = calloc((size_t)bigger.cap, sizeof(bigger.slots[0]));
    for (int i = 0; i < map->cap; i++)
    {
        if (map->slots[i].state == MAP_USED)
        {
            strmap_insert_owned(&bigger, map->slots[i].key,
                                map->slots[i].value);
        }
    }
    free(map->slots);
    *map = bigger;
}

// strmap_set stores value under key, replacing any earlier value. The map
// keeps its own copy of the key.
static inline void strmap_set
(
    StrMap *map,
    const char *key,
    int value
)
{
    StrMapSlot *found = strmap_find(map, key);
    if (found != NULL)
    {
        found->value = value;
        return;
    }
    if ((map->used + 1) * 2 > map->cap)
    {
        strmap_grow(map);
    }
    size_t size = strlen(key) + 1;
    char *copy = malloc(size);
    memcpy(copy, key, size);
    strmap_insert_owned(map, copy, value);
}

// strmap_has reports whether key is in the map.
static inline bool strmap_has
(
    const StrMap *map,
    const char *key
)
{
    return strmap_find(map, key) != NULL;
}

// strmap_get returns the value stored under key, or 0 if there is none.
static inline int strmap_get
(
    const StrMap *map,
    const char *key
)
{
    StrMapSlot *slot = strmap_find(map, key);
    return slot == NULL ? 0 : slot->value;
}

// strmap_add adds delta to the value under key (starting from 0 if the key is
// new) and returns the new value.
static inline int strmap_add
(
    StrMap *map,
    const char *key,
    int delta
)
{
    int value = strmap_get(map, key) + delta;
    strmap_set(map, key, value);
    return value;
}

// strmap_remove deletes key from the map; it does nothing if key is missing.
static inline void strmap_remove
(
    StrMap *map,
    const char *key
)
{
    StrMapSlot *slot = strmap_find(map, key);
    if (slot != NULL)
    {
        free(slot->key);
        slot->key = NULL;
        slot->state = MAP_DELETED;
        map->len--;
    }
}

// strmap_next steps through the map. Start with *iter = 0 and call it until
// it returns false; each true result fills in *key and *value. The key
// belongs to the map and must not be freed.
static inline bool strmap_next
(
    const StrMap *map,
    int *iter,
    const char **key,
    int *value
)
{
    while (*iter < map->cap)
    {
        StrMapSlot *slot = &map->slots[(*iter)++];
        if (slot->state == MAP_USED)
        {
            *key = slot->key;
            *value = slot->value;
            return true;
        }
    }
    return false;
}

static inline void strmap_free
(
    StrMap *map
)
{
    for (int i = 0; i < map->cap; i++)
    {
        if (map->slots[i].state == MAP_USED)
        {
            free(map->slots[i].key);
        }
    }
    free(map->slots);
    *map = (StrMap){0};
}

#endif
