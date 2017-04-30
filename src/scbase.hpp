#ifndef _SCBASE_HPP_
#define _SCBASE_HPP_

#include <stdio.h>
#include <iso3d.hpp>


#define DEBUG(v...) do {                            \
    printf("spcol:%s:%d: ", __FILE__, __LINE__); \
    printf(v);                                      \
    printf("\n");                                   \
  } while (0)


#endif
