#include <stdio.h>
#include <string.h>
#include "priority_queue.h"

int main() {
    printf("--- RFC 9213 Moduler API Gateway Zamanlayicisi ---\n\n");

    MinHeap* scheduler = create_min_heap(2); 

    char* raw_headers[] = {
        "u=5, i", 
        "u=0",    
        NULL,     
        "u=1"     
    };

    char* paths[] = {"/api/background-sync", "/api/process-payment", "/api/get-users", "/api/live-data"};

    printf("[Sisteme Istekler Ekleniyor...]\n");
    for (int i = 0; i < 4; i++) {
        APIRequest req;
        req.request_id = 100 + i;
        strcpy(req.path, paths[i]);
        req.priority = parse_priority_header(raw_headers[i]);
        
        printf("-> Eklendi: ID: %d | Endpoint: %s | Urgency: %d\n", 
               req.request_id, req.path, req.priority.urgency);
               
        insert_request(scheduler, req);
    }

    printf("\n[Istekler Oncelik Sirasina Gore Isleniyor (Extract Min)]\n");
    
    while (scheduler->size > 0) {
        APIRequest processed = extract_min(scheduler);
        printf("<- Isleniyor: ID: %d | Endpoint: %s | Urgency: %d\n", 
               processed.request_id, processed.path, processed.priority.urgency);
    }

    free_heap(scheduler);
    printf("\nBellek basariyla temizlendi. Program kapaniyor.\n");

    return 0;
}