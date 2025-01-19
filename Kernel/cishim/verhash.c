
#include <assert.h>
#include <memory.h>
#include <stddef.h>
#pragma warning (pop)

// unreferenced inline function has been removed
#pragma warning (disable: 4514)

// unreferenced formal parameter
#pragma warning (disable: 4100)

// conditional expression is constant
#pragma warning (disable: 4127)

// assignment within conditional expression
#pragma warning (disable: 4706)

// nonstandard extension used : nameless struct/union
#pragma warning (disable: 4201)

#ifdef Uses_Desktop
#include<Windows.h>
#else
#include <winerror.h>
#include <windef.h>
#endif

#include "mincrypt.h"

#include "md5.h"
#include "sha1.h"
#include "sha256.h"

#define MAX_RSA_PUB_KEY_BIT_LEN             4096
#define MAX_RSA_PUB_KEY_BYTE_LEN            (MAX_RSA_PUB_KEY_BIT_LEN / 8 )
#define MAX_BSAFE_PUB_KEY_MODULUS_BYTE_LEN  \
    (MAX_RSA_PUB_KEY_BYTE_LEN +  sizeof(DWORD) * 4)



// from \nt\ds\win32\ntcrypto\scp\nt_sign.c

//
// Reverse ASN.1 Encodings of possible hash identifiers.  The leading byte is
// the length of the remaining byte string.
//

LONG
__stdcall
MinCryptHashMemory(
    IN ALG_ID HashAlgId,
    IN void* rgBlob,
    IN DWORD cBlob,
    OUT BYTE rgbHash[MINCRYPT_MAX_HASH_LEN],
    OUT DWORD* pcbHash
)
{
    A_SHA1_CTX Sha1Ctx;
    A_SHA256_CTX Sha256Ctx;
    MD5_CTX Md5Ctx;
    DWORD iBlob;

    switch (HashAlgId) {

    case CALG_MD5:
        MD5Init(&Md5Ctx);
        *pcbHash = MINCRYPT_MD5_HASH_LEN;
        break;

    case CALG_SHA1:
        A_SHA1Init(&Sha1Ctx);
        *pcbHash = MINCRYPT_SHA1_HASH_LEN;
        break;

    case CALG_SHA_256:
        A_SHA256Init(&Sha256Ctx);
        *pcbHash = MINCRYPT_SHA256_HASH_LEN;
        break;
    default:
        *pcbHash = 0;
        return NTE_BAD_ALGID;
    }
    //if (cBlob) {
     //   for (iBlob = 0; iBlob < cBlob; iBlob++) {
            BYTE* pb = rgBlob;
            DWORD cb = cBlob;

       //     if (0 == cb)
          //      continue;

            switch (HashAlgId) {

            case CALG_MD5:
                MD5Update(&Md5Ctx, pb, cb);
                break;

            case CALG_SHA1:
                A_SHA1Update(&Sha1Ctx, pb, cb);
                break;

            case CALG_SHA_256:
                A_SHA256Update(&Sha256Ctx, pb, cb);
                break;
         //   }

      //  }
    }
    switch (HashAlgId) {

    case CALG_MD5:
        MD5Final(&Md5Ctx);
        assert(MD5DIGESTLEN == MINCRYPT_MD5_HASH_LEN);
        memcpy(rgbHash, Md5Ctx.digest, MD5DIGESTLEN);
        break;

    case CALG_SHA1:
        A_SHA1Final(&Sha1Ctx, rgbHash);
        break;

    case CALG_SHA_256:
        A_SHA256Final(&Sha256Ctx, rgbHash);
        break;
    }

    return ERROR_SUCCESS;

}


