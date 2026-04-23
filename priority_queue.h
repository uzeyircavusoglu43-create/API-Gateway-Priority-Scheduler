#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "rfc9213.h"

// API Gateway'e gelen tek bir istegi temsil eder
typedef struct {
    int request_id;
    char path[128];
    RFC9213_Priority priority;
} APIRequest;

// Min-Heap yapisi
typedef struct {
    APIRequest* array; // Dinamik dizi pointer'i
    int capacity;      // Toplam kapasite
    int size;          // Mevcut eleman sayisi
} MinHeap;

MinHeap* create_min_heap(int initial_capacity);
void insert_request(MinHeap* heap, APIRequest req);
APIRequest extract_min(MinHeap* heap);
void free_heap(MinHeap* heap);

#endif