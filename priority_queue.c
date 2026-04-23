#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

int compare_requests(APIRequest a, APIRequest b) {
    return a.priority.urgency - b.priority.urgency;
}

void swap(APIRequest* a, APIRequest* b) {
    APIRequest temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap* create_min_heap(int initial_capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    if (!heap) {
        printf("Bellek tahsis hatasi!\n");
        exit(1);
    }
    heap->capacity = initial_capacity;
    heap->size = 0;
    heap->array = (APIRequest*)malloc(initial_capacity * sizeof(APIRequest));
    if (!heap->array) {
        printf("Dizi icin bellek tahsis hatasi!\n");
        free(heap);
        exit(1);
    }
    return heap;
}

void heapify_up(MinHeap* heap, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && compare_requests(heap->array[index], heap->array[parent]) < 0) {
        swap(&heap->array[index], &heap->array[parent]);
        heapify_up(heap, parent);
    }
}

void heapify_down(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && compare_requests(heap->array[left], heap->array[smallest]) < 0)
        smallest = left;

    if (right < heap->size && compare_requests(heap->array[right], heap->array[smallest]) < 0)
        smallest = right;

    if (smallest != index) {
        swap(&heap->array[index], &heap->array[smallest]);
        heapify_down(heap, smallest);
    }
}

void insert_request(MinHeap* heap, APIRequest req) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->array = (APIRequest*)realloc(heap->array, heap->capacity * sizeof(APIRequest));
        if (!heap->array) {
            printf("Realloc hatasi!\n");
            exit(1);
        }
    }
    heap->array[heap->size] = req;
    heapify_up(heap, heap->size);
    heap->size++;
}

APIRequest extract_min(MinHeap* heap) {
    if (heap->size <= 0) {
        APIRequest empty_req = {-1, "", {7, false}};
        return empty_req;
    }
    
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    APIRequest root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify_down(heap, 0);

    return root;
}

void free_heap(MinHeap* heap) {
    if (heap) {
        if (heap->array) free(heap->array);
        free(heap);
    }
}