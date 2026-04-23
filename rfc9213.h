#ifndef RFC9213_H
#define RFC9213_H

#include <stdbool.h>

// RFC 9213 standartlarina gore oncelik yapisi
typedef struct {
    int urgency;       // 0 (En yuksek) ile 7 (En dusuk) arasi. Varsayilan: 3
    bool incremental;  // Varsayilan: false
} RFC9213_Priority;

// String bir header degerini parse edip struct'a donusturen fonksiyon
RFC9213_Priority parse_priority_header(const char* header_string);

#endif