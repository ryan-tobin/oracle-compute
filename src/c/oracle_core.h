/**
 * @file oracle_core.h
 * @brief Core Oracle precognitive computation primitives
 * 
 * Low-level temporal computing implementation in C for maximum performance.
 */

#ifndef ORACLE_CORE_H
#define ORACLE_CORE_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Oracle computation context
 */
typedef struct oracle_context {
    uint64_t temporal_state;
    void* prediction_cache;
    size_t cache_size;
} oracle_context_t;

/**
 * @brief Initialize Oracle context
 * @param ctx Context to initialize
 * @return true on success, false on failure
 */
bool oracle_init(oracle_context_t* ctx);

/**
 * @brief cleanup Oracle context
 * @param ctx Context to cleanup
 */
void oracle_cleanup(oracle_context_t* ctx);

/**
 * @brief Execute precognitive computation
 * @param ctx Oracle context
 * @param computation Function to execute
 * @param args Arguments to pass
 * @return Computation result
 */

int64_t oracle_compute(oracle_context_t* ctx,
                       int64_t (*computation)(void*),
                       void* args);

#ifdef __cplusplus
}
#endif

#endif // ORACLE_CORE_H
