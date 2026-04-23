#include "rfc9213.h"
#include <string.h>
#include <stdlib.h>

RFC9213_Priority parse_priority_header(const char* header_string) {
    RFC9213_Priority prio = {3, false}; // RFC'ye gore varsayilan degerler
    
    if (header_string == NULL) return prio;

    if (strstr(header_string, "u=0")) prio.urgency = 0;
    else if (strstr(header_string, "u=1")) prio.urgency = 1;
    else if (strstr(header_string, "u=2")) prio.urgency = 2;
    else if (strstr(header_string, "u=4")) prio.urgency = 4;
    else if (strstr(header_string, "u=5")) prio.urgency = 5;
    else if (strstr(header_string, "u=6")) prio.urgency = 6;
    else if (strstr(header_string, "u=7")) prio.urgency = 7;

    if (strstr(header_string, "i") || strstr(header_string, "i=?1")) {
        prio.incremental = true;
    }

    return prio;
}