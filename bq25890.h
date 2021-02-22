#ifndef __BQ25790_H
#define __BQ25790_H

#ifdef __cplusplus
extern "C" {
#endif

#include "bq25790_reg.h"
#include <stdint.h>
#include <stddef.h>

#define BQ25790_SLAVE_ADDR 0x6B

typedef int (*i2c_write_ptr)(uint8_t, uint8_t *, size_t);
typedef int (*i2c_read_ptr) (uint8_t, uint8_t *, size_t);

typedef struct {
    i2c_read_ptr read_ptr;
    i2c_write_ptr write_ptr;
} bq25790_dev_t;


#ifdef __cplusplus
}
#endif

#endif //__BQ25790_H 
