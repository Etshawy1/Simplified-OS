// Copyright 2020 Joshua J Baker. All rights reserved.
// https://github.com/tidwall/hashmap.c

#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct hashmap;

struct hashmap *hashmap_new(size_t elsize, size_t cap, 
                            uint64_t seed0, uint64_t seed1,
                            uint64_t (*hash)(const void *item, 
                                             uint64_t seed0, uint64_t seed1),
                            int (*compare)(const void *a, const void *b, 
                                           void *udata),
                            void *udata);
void hashmap_free(struct hashmap *map);
size_t hashmap_count(struct hashmap *map);
bool hashmap_oom(struct hashmap *map);
void *hashmap_get(struct hashmap *map, void *item);
void *hashmap_set(struct hashmap *map, void *item);
void *hashmap_delete(struct hashmap *map, void *item);
bool hashmap_scan(struct hashmap *map,
                  bool (*iter)(const void *item, void *udata), void *udata);
void hashmap_set_allocator(void *(*malloc)(size_t), void (*free)(void*));
uint64_t hashmap_murmur(const void *data, size_t len, 
                        uint64_t seed0, uint64_t seed1);

#endif
