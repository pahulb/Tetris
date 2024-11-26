00001/*
00002  * Copyright (c) 1990 The Regents of the University of California.
00003  * All rights reserved.
00004  *
00005  * Redistribution and use in source and binary forms are permitted
00006  * provided that the above copyright notice and this paragraph are
00007  * duplicated in all such forms and that any documentation,
00008  * advertising materials, and other materials related to such
00009  * distribution and use acknowledge that the software was developed
00010  * by the University of California, Berkeley.  The name of the
00011  * University may not be used to endorse or promote products derived
00012  * from this software without specific prior written permission.
00013  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
00014  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
00015  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
00016  *
00017  *      @(#)stdio.h     5.3 (Berkeley) 3/15/86
00018  */
00019 
00020 /*
00021  * NB: to fit things in six character monocase externals, the
00022  * stdio code uses the prefix `__s' for stdio objects, typically
00023  * followed by a three-character attempt at a mnemonic.
00024  */
00025 
00026 #ifndef _STDIO_H_
00027 #ifdef __cplusplus
00028 extern "C" {
00029 #endif
00030 #define _STDIO_H_
00031 
00032 #define _FSTDIO                 /* ``function stdio'' */
00033 
00034 #define __need_size_t
00035 #include <stddef.h>
00036 
00037 #define __need___va_list
00038 #include <stdarg.h>
00039 
00040 /*
00041  * <sys/reent.h> defines __sFILE, _fpos_t.
00042  * They must be defined there because struct _reent needs them (and we don't
00043  * want reent.h to include this file.
00044  */
00045 
00046 struct __sFile 
00047 {
00048   int unused;
00049 };
00050   
00051 typedef struct __sFILE FILE;
00052 
00053 #define __SLBF  0x0001          /* line buffered */
00054 #define __SNBF  0x0002          /* unbuffered */
00055 #define __SRD   0x0004          /* OK to read */
00056 #define __SWR   0x0008          /* OK to write */
00057         /* RD and WR are never simultaneously asserted */
00058 #define __SRW   0x0010          /* open for reading & writing */
00059 #define __SEOF  0x0020          /* found EOF */
00060 #define __SERR  0x0040          /* found error */
00061 #define __SMBF  0x0080          /* _buf is from malloc */
00062 #define __SAPP  0x0100          /* fdopen()ed in append mode - so must  write to end */
00063 #define __SSTR  0x0200          /* this is an sprintf/snprintf string */
00064 #define __SOPT  0x0400          /* do fseek() optimisation */
00065 #define __SNPT  0x0800          /* do not do fseek() optimisation */
00066 #define __SOFF  0x1000          /* set iff _offset is in fact correct */
00067 #define __SMOD  0x2000          /* true => fgetline modified _p text */
00068 #if defined(__CYGWIN__) || defined(__CYGWIN__)
00069 #define __SCLE        0x4000          /* convert line endings CR/LF <-> NL */
00070 #endif
00071 
00072 /*
00073  * The following three definitions are for ANSI C, which took them
00074  * from System V, which stupidly took internal interface macros and
00075  * made them official arguments to setvbuf(), without renaming them.
00076  * Hence, these ugly _IOxxx names are *supposed* to appear in user code.
00077  *
00078  * Although these happen to match their counterparts above, the
00079  * implementation does not rely on that (so these could be renumbered).
00080  */
00081 #define _IOFBF  0               /* setvbuf should set fully buffered */
00082 #define _IOLBF  1               /* setvbuf should set line buffered */
00083 #define _IONBF  2               /* setvbuf should set unbuffered */
00084 
00085 #ifndef NULL
00086 #define NULL    0
00087 #endif
00088 
00089 #define BUFSIZ  1024
00090 #define EOF     (-1)
00091 
00092 #define FOPEN_MAX       20      /* must be <= OPEN_MAX <sys/syslimits.h> */
00093 #define FILENAME_MAX    1024    /* must be <= PATH_MAX <sys/syslimits.h> */
00094 #define L_tmpnam        1024    /* XXX must be == PATH_MAX */
00095 #ifndef __STRICT_ANSI__
00096 #define P_tmpdir        "/tmp"
00097 #endif
00098 
00099 #ifndef SEEK_SET
00100 #define SEEK_SET        0       /* set file offset to offset */
00101 #endif
00102 #ifndef SEEK_CUR
00103 #define SEEK_CUR        1       /* set file offset to current plus offset */
00104 #endif
00105 #ifndef SEEK_END
00106 #define SEEK_END        2       /* set file offset to EOF plus offset */
00107 #endif
00108 
00109 #define TMP_MAX         26
00110 
00111 #define stdin   (_impure_ptr->_stdin)
00112 #define stdout  (_impure_ptr->_stdout)
00113 #define stderr  (_impure_ptr->_stderr)
00114 
00115 #define _stdin_r(x)     ((x)->_stdin)
00116 #define _stdout_r(x)    ((x)->_stdout)
00117 #define _stderr_r(x)    ((x)->_stderr)
00118 
00119 /*
00120  * Functions defined in ANSI C standard.
00121  */
00122 
00123 #ifdef __GNUC__
00124 #define __VALIST __gnuc_va_list
00125 #else
00126 #define __VALIST char*
00127 #endif
00128 
00129 #ifndef _EXFUN
00130 # define _EXFUN(N,P) N P
00131 #endif
00132 
00133 int     _EXFUN(printf, (const char *, ...));
00134 int     _EXFUN(scanf, (const char *, ...));
00135 int     _EXFUN(sscanf, (const char *, const char *, ...));
00136 int     _EXFUN(vfprintf, (FILE *, const char *, __VALIST));
00137 int     _EXFUN(vprintf, (const char *, __VALIST));
00138 int     _EXFUN(vsprintf, (char *, const char *, __VALIST));
00139 int     _EXFUN(vsnprintf, (char *, size_t, const char *, __VALIST));
00140 int     _EXFUN(fgetc, (FILE *));
00141 char *  _EXFUN(fgets, (char *, int, FILE *));
00142 int     _EXFUN(fputc, (int, FILE *));
00143 int     _EXFUN(fputs, (const char *, FILE *));
00144 int     _EXFUN(getc, (FILE *));
00145 int     _EXFUN(getchar, (void));
00146 char *  _EXFUN(gets, (char *));
00147 int     _EXFUN(putc, (int, FILE *));
00148 int     _EXFUN(putchar, (int));
00149 int     _EXFUN(puts, (const char *));
00150 int     _EXFUN(ungetc, (int, FILE *));
00151 size_t  _EXFUN(fread, (void *, size_t _size, size_t _n, FILE *));
00152 size_t  _EXFUN(fwrite, (const void *, size_t _size, size_t _n, FILE *));
00153 
00154 int     _EXFUN(sprintf, (char *, const char *, ...));
00155 int     _EXFUN(snprintf, (char *, size_t, const char *, ...));
00156 
00157 #ifdef __cplusplus
00158 }
00159 #endif
00160 #endif /* _STDIO_H_ */
