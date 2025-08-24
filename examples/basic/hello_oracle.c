#include "oracle_core.h"
#include <stdio.h>

int64_t simple_computation(void* args) {
    int* value = (int*)args;
    return (*value) * 2;
}

int main() {
    oracle_context_t ctx;
    
    if (!oracle_init(&ctx)) {
        printf("Failed to initialize Oracle\n");
        return 1;
    }
    
    int input = 42;
    int64_t result = oracle_compute(&ctx, simple_computation, &input);
    
    printf("🔮 Oracle says: %d * 2 = %lld\n", input, result);
    
    oracle_cleanup(&ctx);
    return 0;
}