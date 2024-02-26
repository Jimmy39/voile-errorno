/**
  @file voile_errorno.c
  @author Jimmy Wang
  @brief An implementation of the errno for voile-library
  @version alpha-20240226
 */

#include "voile_errorno.h"

#ifndef __DISABLE_DEBUG
voile_errorno_t Verrorno = success;
#endif
