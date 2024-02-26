/**
  @file voile_errorno.h
  @brief An implementation of the errno for voile-library
  @details 

  To use, copy voile_errorno.h, src/voile_errorno.c and depends libries, creat voile_conf.h for defining micro. Then include voile_error.h, and compile and link all .c file.
  
  @depends
  [voile_common](https://github.com/Jimmy39/voile-common)
  @author Jimmy Wang
  @version alpha-20240226
  @todo Add example and some comment

  @license MIT License

  Copyright (c) 2024 Jimmy Wang

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
 */
#ifndef __VOILE_ERRORNO_H__
#define __VOILE_ERRORNO_H__

#include "voile_common.h"
#ifdef __VOILE_ERRORNO_CONF
#include "voile_errorno_conf.h"
#endif  // __VOILE_ERRORNO_CONF

/**
 * @brief Define error number
 *
 */
typedef enum {

    /// No error
    success = 0,

    /// Unclassified error
    error = 1,

    /// Function is called with incorrect parameters
    inputRangeError = 2,

    /// You are using a feature not supported by hardware
    hardwareUnsupportedError = 3,

    /// There are invalid parameters in the configuration of devicelist.h
    configError = 4

} voile_errorno_t;

/**
 * @brief Storage error number, disabled by ```__VOILE_DISABLE_DEBUG```
 *
 */
#ifndef __VOILE_DISABLE_DEBUG
extern voile_errorno_t Verrorno;
#endif

/**
 * @brief Set ```Verrorno``` value, can be ignored by ```__VOILE_DISABLE_DEBUG```
 *
 */
#ifndef __VOILE_DISABLE_DEBUG
#define microVerrorno_set(no) (Verrorno = no)
#else
#define microVerrorno_set(no)
#endif

/**
 * @brief Get ```Verrorno``` value, can be ignored by ```__VOILE_DISABLE_DEBUG```
 *
 */
#ifndef __VOILE_DISABLE_DEBUG
#define microVerrorno_get() Verrorno
#else
#define microVerrorno_get() success
#endif

/**
 * @brief Define microVerrorno_alart(message) to use alart output
 *
 */
#ifndef microVerrorno_alart
#define microVerrorno_alart(message)
#endif

/**
 * @brief Trigger an error
 *
 */
#define microVerrorno_error(no, message) \
    do {                                 \
        microVerrorno_set(no);           \
        microVerrorno_alart(message);    \
    } while (0)

/**
 * @brief Alart warning, can be ignored by ```__VOILE_IGNORE_WARNING```
 *
 */
#ifndef __VOILE_IGNORE_WARNING
#define microVerrorno_warning(message) microVerrorno_alart(message)
#else
#define microVerrorno_warning(message)
#endif

/**
 * @brief Cheak input value, can be ignored by ```__VOILE_DISABLE_DEBUG```
 * 
 */
#ifndef __VOILE_DISABLE_DEBUG
#define microVerrorno_cheakInput(conditions, message) \
    do {                                              \
        if (!conditions) {                            \
            microVerrorno_set(inputRangeError);       \
            microVerrorno_alart(message);             \
        }                                             \
    } while (0)
#else
#define microVerrorno_cheakInput(conditions, message)
#endif

#endif  // !__VOILE_ERRORNO_H__
