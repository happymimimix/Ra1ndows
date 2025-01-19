#ifdef Uses_Desktop
#include<Windows.h>
#else
#include <windef.h>
#endif
#ifndef RSA32API
#define RSA32API __stdcall
#endif

/* Copyright (C) RSA Data Security, Inc. created 1993.  This is an
   unpublished work protected as such under copyright law.  This work
   contains proprietary, confidential, and trade secret information of
   RSA Data Security, Inc.  Use, disclosure or reproduction without the
   express written authorization of RSA Data Security, Inc. is
   prohibited.
 */

#ifndef _SHA_H_
#define _SHA_H_ 1

#ifdef __cplusplus
extern "C" {
#endif

#define A_SHA1_DIGEST_LEN 20

    typedef struct {
        ULONG       FinishFlag;
        UCHAR        HashVal[A_SHA1_DIGEST_LEN];
        ULONG state[5];                             /* state (ABCDE) */
        ULONG count[2];                             /* number of bytes, msb first */
        unsigned char buffer[64];                   /* input buffer */
    } A_SHA1_CTX;

    void RSA32API A_SHA1Init(A_SHA1_CTX*);
    void RSA32API A_SHA1Update(A_SHA1_CTX*, unsigned char*, unsigned int);
    void RSA32API A_SHA1Final(A_SHA1_CTX*, unsigned char[A_SHA1_DIGEST_LEN]);

#ifdef __cplusplus
}
#endif

#endif