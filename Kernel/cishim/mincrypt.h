#ifdef Uses_Desktop
#include<Windows.h>
#else
#include <windef.h>
#endif
#ifndef __MINCRYPT_H__
#define __MINCRYPT_H__


#if defined (_MSC_VER)

#if ( _MSC_VER >= 800 )
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable:4201)    /* Nameless struct/union */
#endif

#if (_MSC_VER > 1020)
#pragma once
#endif

#endif


#ifdef __cplusplus
extern "C" {
#endif


   
#define MINCRYPT_MAX_HASH_LEN               40
#define MINCRYPT_SHA256_HASH_LEN            32
#define MINCRYPT_SHA1_HASH_LEN              20
#define MINCRYPT_MD5_HASH_LEN               16
#define MINCRYPT_MD2_HASH_LEN               16
    typedef unsigned int ALG_ID;

    typedef struct _CRYPTOAPI_BLOB {
        DWORD   cbData;
        BYTE* pbData;
    } CRYPT_INTEGER_BLOB, * PCRYPT_INTEGER_BLOB,
        CRYPT_UINT_BLOB, * PCRYPT_UINT_BLOB,
        CRYPT_OBJID_BLOB, * PCRYPT_OBJID_BLOB,
        CERT_NAME_BLOB, * PCERT_NAME_BLOB,
        CERT_RDN_VALUE_BLOB, * PCERT_RDN_VALUE_BLOB,
        CERT_BLOB, * PCERT_BLOB,
        CRL_BLOB, * PCRL_BLOB,
        DATA_BLOB, * PDATA_BLOB,
        CRYPT_DATA_BLOB, * PCRYPT_DATA_BLOB,
        CRYPT_HASH_BLOB, * PCRYPT_HASH_BLOB,
        CRYPT_DIGEST_BLOB, * PCRYPT_DIGEST_BLOB,
        CRYPT_DER_BLOB, * PCRYPT_DER_BLOB,
        CRYPT_ATTR_BLOB, * PCRYPT_ATTR_BLOB;

    //
    // Algorithm IDs and Flags
    //

    // ALG_ID crackers
#define GET_ALG_CLASS(x)                (x & (7 << 13))
#define GET_ALG_TYPE(x)                 (x & (15 << 9))
#define GET_ALG_SID(x)                  (x & (511))

// Algorithm classes
// certenrolld_begin -- ALG_CLASS_*
#define ALG_CLASS_ANY                   (0)
#define ALG_CLASS_SIGNATURE             (1 << 13)
#define ALG_CLASS_MSG_ENCRYPT           (2 << 13)
#define ALG_CLASS_DATA_ENCRYPT          (3 << 13)
#define ALG_CLASS_HASH                  (4 << 13)
#define ALG_CLASS_KEY_EXCHANGE          (5 << 13)
#define ALG_CLASS_ALL                   (7 << 13)
// certenrolld_end

// Algorithm types
#define ALG_TYPE_ANY                    (0)
#define ALG_TYPE_DSS                    (1 << 9)
#define ALG_TYPE_RSA                    (2 << 9)
#define ALG_TYPE_BLOCK                  (3 << 9)
#define ALG_TYPE_STREAM                 (4 << 9)
#define ALG_TYPE_DH                     (5 << 9)
#define ALG_TYPE_SECURECHANNEL          (6 << 9)
#if (NTDDI_VERSION >= NTDDI_VISTA)
#define ALG_TYPE_ECDH                   (7 << 9)
#endif //(NTDDI_VERSION >= NTDDI_VISTA)
#if (NTDDI_VERSION >= NTDDI_WIN10_RS1)
#define ALG_TYPE_THIRDPARTY             (8 << 9)
#endif //(NTDDI_VERSION >= NTDDI_WIN10_RS1)

// Generic sub-ids
#define ALG_SID_ANY                     (0)

// Generic ThirdParty sub-ids
#if (NTDDI_VERSION >= NTDDI_WIN10_RS1)
#define ALG_SID_THIRDPARTY_ANY          (0)
#endif //(NTDDI_VERSION >= NTDDI_WIN10_RS1)

// Some RSA sub-ids
#define ALG_SID_RSA_ANY                 0
#define ALG_SID_RSA_PKCS                1
#define ALG_SID_RSA_MSATWORK            2
#define ALG_SID_RSA_ENTRUST             3
#define ALG_SID_RSA_PGP                 4

// Some DSS sub-ids
//
#define ALG_SID_DSS_ANY                 0
#define ALG_SID_DSS_PKCS                1
#define ALG_SID_DSS_DMS                 2
#if (NTDDI_VERSION >= NTDDI_VISTA)
#define ALG_SID_ECDSA                   3
#endif //(NTDDI_VERSION >= NTDDI_VISTA)

// Block cipher sub ids
// DES sub_ids
#define ALG_SID_DES                     1
#define ALG_SID_3DES                    3
#define ALG_SID_DESX                    4
#define ALG_SID_IDEA                    5
#define ALG_SID_CAST                    6
#define ALG_SID_SAFERSK64               7
#define ALG_SID_SAFERSK128              8
#define ALG_SID_3DES_112                9
#define ALG_SID_CYLINK_MEK              12
#define ALG_SID_RC5                     13
#if (NTDDI_VERSION >= NTDDI_WINXP)
#define ALG_SID_AES_128                 14
#define ALG_SID_AES_192                 15
#define ALG_SID_AES_256                 16
#define ALG_SID_AES                     17
#endif //(NTDDI_VERSION >= NTDDI_WINXP)

// Fortezza sub-ids
#define ALG_SID_SKIPJACK                10
#define ALG_SID_TEK                     11

// KP_MODE
#define CRYPT_MODE_CBCI                 6       // ANSI CBC Interleaved
#define CRYPT_MODE_CFBP                 7       // ANSI CFB Pipelined
#define CRYPT_MODE_OFBP                 8       // ANSI OFB Pipelined
#define CRYPT_MODE_CBCOFM               9       // ANSI CBC + OF Masking
#define CRYPT_MODE_CBCOFMI              10      // ANSI CBC + OFM Interleaved

// RC2 sub-ids
#define ALG_SID_RC2                     2

// Stream cipher sub-ids
#define ALG_SID_RC4                     1
#define ALG_SID_SEAL                    2

// Diffie-Hellman sub-ids
#define ALG_SID_DH_SANDF                1
#define ALG_SID_DH_EPHEM                2
#define ALG_SID_AGREED_KEY_ANY          3
#define ALG_SID_KEA                     4
#if (NTDDI_VERSION >= NTDDI_VISTA)
#define ALG_SID_ECDH                    5
#define ALG_SID_ECDH_EPHEM              6
#endif //(NTDDI_VERSION >= NTDDI_VISTA)

// Hash sub ids
#define ALG_SID_MD2                     1
#define ALG_SID_MD4                     2
#define ALG_SID_MD5                     3
#define ALG_SID_SHA                     4
#define ALG_SID_SHA1                    4
#define ALG_SID_MAC                     5
#define ALG_SID_RIPEMD                  6
#define ALG_SID_RIPEMD160               7
#define ALG_SID_SSL3SHAMD5              8
#define ALG_SID_HMAC                    9
#define ALG_SID_TLS1PRF                 10
#if (NTDDI_VERSION >= NTDDI_WINXP)
#define ALG_SID_HASH_REPLACE_OWF        11
#endif //(NTDDI_VERSION >= NTDDI_WINXP)
#if (NTDDI_VERSION > NTDDI_WINXPSP2)
#define ALG_SID_SHA_256                 12
#define ALG_SID_SHA_384                 13
#define ALG_SID_SHA_512                 14
#endif //(NTDDI_VERSION > NTDDI_WINXPSP2)

// secure channel sub ids
#define ALG_SID_SSL3_MASTER             1
#define ALG_SID_SCHANNEL_MASTER_HASH    2
#define ALG_SID_SCHANNEL_MAC_KEY        3
#define ALG_SID_PCT1_MASTER             4
#define ALG_SID_SSL2_MASTER             5
#define ALG_SID_TLS1_MASTER             6
#define ALG_SID_SCHANNEL_ENC_KEY        7

#if (NTDDI_VERSION >= NTDDI_VISTA)
// misc ECC sub ids
#define ALG_SID_ECMQV                   1
#endif //(NTDDI_VERSION >= NTDDI_VISTA)

// Our silly example sub-id
#define ALG_SID_EXAMPLE                 80
#define CALG_MD2                (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD2)
#define CALG_MD4                (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD4)
#define CALG_MD5                (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD5)
#define CALG_SHA                (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA)
#define CALG_SHA1               (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA1)
#define CALG_MAC                (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MAC)           // Deprecated. Don't use.
#define CALG_RSA_SIGN           (ALG_CLASS_SIGNATURE | ALG_TYPE_RSA | ALG_SID_RSA_ANY)
#define CALG_DSS_SIGN           (ALG_CLASS_SIGNATURE | ALG_TYPE_DSS | ALG_SID_DSS_ANY)
#if (NTDDI_VERSION >= NTDDI_WINXP)
#define CALG_NO_SIGN            (ALG_CLASS_SIGNATURE | ALG_TYPE_ANY | ALG_SID_ANY)
#endif //(NTDDI_VERSION >= NTDDI_WINXP)
#define CALG_RSA_KEYX           (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_RSA|ALG_SID_RSA_ANY)
#define CALG_DES                (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_DES)
#define CALG_3DES_112           (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_3DES_112)
#define CALG_3DES               (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_3DES)
#define CALG_DESX               (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_DESX)
#define CALG_RC2                (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_RC2)
#define CALG_RC4                (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_STREAM|ALG_SID_RC4)
#define CALG_SEAL               (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_STREAM|ALG_SID_SEAL)
#define CALG_DH_SF              (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_DH|ALG_SID_DH_SANDF)
#define CALG_DH_EPHEM           (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_DH|ALG_SID_DH_EPHEM)
#define CALG_AGREEDKEY_ANY      (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_DH|ALG_SID_AGREED_KEY_ANY)
#define CALG_KEA_KEYX           (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_DH|ALG_SID_KEA)
#define CALG_HUGHES_MD5         (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_ANY|ALG_SID_MD5)
#define CALG_SKIPJACK           (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_SKIPJACK)
#define CALG_TEK                (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_TEK)
#define CALG_CYLINK_MEK         (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_CYLINK_MEK)  // Deprecated. Do not use
#define CALG_SSL3_SHAMD5        (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SSL3SHAMD5)
#define CALG_SSL3_MASTER        (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SSL3_MASTER)
#define CALG_SCHANNEL_MASTER_HASH   (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SCHANNEL_MASTER_HASH)
#define CALG_SCHANNEL_MAC_KEY   (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SCHANNEL_MAC_KEY)
#define CALG_SCHANNEL_ENC_KEY   (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SCHANNEL_ENC_KEY)
#define CALG_PCT1_MASTER        (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_PCT1_MASTER)
#define CALG_SSL2_MASTER        (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SSL2_MASTER)
#define CALG_TLS1_MASTER        (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_TLS1_MASTER)
#define CALG_RC5                (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_RC5)
#define CALG_HMAC               (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_HMAC)
#define CALG_TLS1PRF            (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_TLS1PRF)
#if (NTDDI_VERSION >= NTDDI_WINXP)
#define CALG_HASH_REPLACE_OWF   (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_HASH_REPLACE_OWF)
#define CALG_AES_128            (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_AES_128)
#define CALG_AES_192            (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_AES_192)
#define CALG_AES_256            (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_AES_256)
#define CALG_AES                (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_AES)
#endif //(NTDDI_VERSION >= NTDDI_WINXP)
#if (NTDDI_VERSION > NTDDI_WINXPSP2)
#define CALG_SHA_256            (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_256)
#define CALG_SHA_384            (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_384)
#define CALG_SHA_512            (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_512)
#endif
    LONG
        __stdcall
        MinCryptHashMemory(
            IN ALG_ID HashAlgId,
            IN void* rgBlob,
            IN DWORD cBlob,
            OUT BYTE rgbHash[MINCRYPT_MAX_HASH_LEN],
            OUT DWORD* pcbHash
        );



#ifdef __cplusplus
}       // Balance extern "C" above
#endif

#if defined (_MSC_VER)
#if ( _MSC_VER >= 800 )

#if _MSC_VER >= 1200
#pragma warning(pop)
#else
#pragma warning(default:4201)
#endif

#endif
#endif

#endif // __MINCRYPT_H__
