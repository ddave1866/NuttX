/************************************************************
 * debug.h
 *
 *   Copyright (C) 2007 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <spudmonkey@racsa.co.cr>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name Gregory Nutt nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************/

#ifndef __DEBUG_H
#define __DEBUG_H

/************************************************************
 * Included Files
 ************************************************************/

#include <nuttx/config.h>

/************************************************************
 * Definitions
 ************************************************************/

/* Debug macros to runtime filter the opsys debug messages */

#ifdef __GNUC__
# define EXTRA_FMT "%s: "
# define EXTRA_ARG ,__FUNCTION__
#else
# define EXTRA_FMT
# define EXTRA_ARG
#endif

#ifdef CONFIG_DEBUG
# define dbg(format, arg...) \
  lib_rawprintf(EXTRA_FMT format EXTRA_ARG, ##arg)

# ifdef CONFIG_ARCH_LOWPUTC
#  define lldbg(format, arg...) \
     lib_lowprintf(EXTRA_FMT format EXTRA_ARG, ##arg)
# else
#  define lldbg(x...)
# endif

# ifdef CONFIG_DEBUG_VERBOSE
#  define vdbg(format, arg...) \
     lib_rawprintf(EXTRA_FMT format EXTRA_ARG, ##arg)
# else
#  define vdbg(x...)
# endif

#else
# define dbg(x...)
# define lldbg(x...)
# define vdbg(x...)
#endif

/* Subsystem specific debug */

#ifdef CONFIG_DEBUG_MM
# define mdbg(format, arg...)   dbg(format, ##arg)
# define mlldbg(format, arg...) lldbg(format, ##arg)
# define mvdbg(format, arg...)  vdbg(format, ##arg)
#else
# define mdbg(x...)
# define mlldbg(x...)
# define mvdbg(x...)
#endif

#ifdef CONFIG_DEBUG_SCHED
# define sdbg(format, arg...)   dbg(format, ##arg)
# define slldbg(format, arg...) lldbg(format, ##arg)
# define svdbg(format, arg...)  vdbg(format, ##arg)
#else
# define sdbg(x...)
# define slldbg(x...)
# define svdbg(x...)
#endif

#ifdef CONFIG_DEBUG_NET
# define ndbg(format, arg...)   dbg(format, ##arg)
# define nlldbg(format, arg...) lldbg(format, ##arg)
# define nvdbg(format, arg...)  vdbg(format, ##arg)
#else
# define ndbg(x...)
# define nlldbg(x...)
# define nvdbg(x...)
#endif

#ifdef CONFIG_DEBUG_FS
# define fdbg(format, arg...)   dbg(format, ##arg)
# define flldbg(format, arg...) lldbg(format, ##arg)
# define fvdbg(format, arg...)  vdbg(format, ##arg)
#else
# define fdbg(x...)
# define flldbg(x...)
# define fvdbg(x...)
#endif

#ifdef CONFIG_DEBUG_LIB
# define ldbg(format, arg...)   dbg(format, ##arg)
# define llldbg(format, arg...) lldbg(format, ##arg)
# define lvdbg(format, arg...)  vdbg(format, ##arg)
#else
# define ldbg(x...)
# define llldbg(x...)
# define lvdbg(x...)
#endif

/************************************************************
 * Public Type Declarations
 ************************************************************/

/************************************************************
 * Public Variables
 ************************************************************/

/************************************************************
 * Public Function Prototypes
 ************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C" {
#else
#define EXTERN extern
#endif

EXTERN int lib_rawprintf(const char *format, ...);

#ifdef CONFIG_ARCH_LOWPUTC
EXTERN int lib_lowprintf(const char *format, ...);
#endif

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __DEBUG_H */
