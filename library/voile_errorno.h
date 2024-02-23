/**
  @file voile_errorno.h
 
  @details 

  To use, include voile_error.h, and compile and link voile_error.c.

  @author Jimmy Wang
  @brief An implementation of the errno for voile-library
  @version alpha-20240223
  @todo Add example

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

/**
  @brief Define error number
 */
typedef enum {

    /// No error
    success = 0,

    /// Unclassified error
    error = 1,

    /// Function is called with incorrect parameters
    inputRangeError = 2,

    /// You are using a feature not supported by the hardware, or configuration in `devicelist.h` is uncorrect
    hardwareUnsupportedError = 3

} Verrorno_t;

#ifndef __VOILE_DISABLE_DEBUG
/**
  @brief Storage error number, Disabled by ```__VOILE_DISABLE_DEBUG```
 */
extern Verrorno_t Verrorno;
#endif

/**
  @brief Set ```Verrorno``` value, can be ignored by ```__VOILE_DISABLE_DEBUG```
 */
#ifndef __VOILE_DISABLE_DEBUG
#define microVsetErrorno(no) Verrorno = no
#else
#define microVsetErrorno(no)
#endif

/**
  @brief Get ```Verrorno``` value, can be ignored by ```__VOILE_DISABLE_DEBUG```
 */
#ifndef __VOILE_DISABLE_DEBUG
#define microVgetErrorno() Verrorno
#else
#define microVgetErrorno()
#endif

/**
  @brief Define microValart(message) in `divicelist.h` to use alart output
 */
#ifndef microValart
#define microValart(message)
#endif  // !microValart

/**
  @brief Trigger an error
 */
#define microVerror(no, message) \
    do {                         \
        microVsetErrorno(no);    \
        microValart(message);    \
    } while (0)

/**
  @brief Alart warning, can be ignored by ```__VOILE_IGNORE_WARNING```
 */
#ifndef __VOILE_IGNORE_WARNING
#define microVwarning(message) microValart(message)
#else   // !__VOILE_IGNORE_WARNING
#define microwarning(no, message)
#endif  // __VOILE_IGNORE_WARNING

#endif  // !__VOILE_ERRORNO_H__
