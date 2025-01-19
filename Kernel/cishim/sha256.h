/*********************************************************************
* Filename:   sha256.h
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Defines the API for the corresponding SHA1 implementation.
*********************************************************************/

#ifndef SHA256_H
#define SHA256_H

/*************************** HEADER FILES ***************************/
#ifdef Uses_Desktop
#include<Windows.h>
#else
#include <windef.h>
#endif

/****************************** MACROS ******************************/
#define SHA256_BLOCK_SIZE 32            // SHA256 outputs a 32 byte digest

/**************************** DATA TYPES ****************************/
typedef unsigned char BYTE;             // 8-bit byte

typedef struct {
	BYTE data[64];
	ULONG datalen;
	unsigned long long bitlen;
	ULONG state[8];
} A_SHA256_CTX;

/*********************** FUNCTION DECLARATIONS **********************/
void A_SHA256Init(A_SHA256_CTX* ctx);
void A_SHA256Update(A_SHA256_CTX* ctx, const BYTE data[], size_t len);
void A_SHA256Final(A_SHA256_CTX* ctx, BYTE hash[]);


#endif   // SHA256_H