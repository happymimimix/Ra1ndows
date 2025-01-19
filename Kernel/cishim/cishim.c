#include<wdm.h>
#include <minwindef.h>
#include"ci.h"
#include "mincrypt.h"

#if defined _M_AMD64 || defined _M_ARM64
#define INT_SIZE 8
typedef long long int_t;
typedef unsigned long long uint_t;
#else
#define INT_SIZE 4
typedef long int_t;
typedef unsigned long uint_t;
#endif
int_t CiValidateFileAsImageType(int a1, int_t a2, int_t a3) {
    return 0;
}
int_t CiRegisterSigningInformation(
    unsigned __int8 a1,
    void* a2,
    unsigned int a3,
    int a4,
    int_t a5,
    unsigned int a6,
    long long* a7) {
    return 0;
}
int_t g_CipRuntimeSignersLock;
int_t g_CipRuntimeSignersCount;
int_t CiUnregisterSigningInformation(long long* P)
{
    return 0;
}
NTSTATUS CiCheckSignedFile(_In_ const PVOID digestBuffer, _In_ int digestSize, _In_ int digestIdentifier, _In_ const LPWIN_CERTIFICATE winCert, _In_ int sizeOfSecurityDirectory, _Out_ PolicyInfo* policyInfoForSigner, _Out_ LARGE_INTEGER* signingTime, _Out_ PolicyInfo* policyInfoForTimestampingAuthority) {
    return STATUS_SUCCESS;
}
int_t CiFindPageHashesInCatalog(
    void* a1,
    unsigned int a2,
    unsigned int a3,
    int a4,
    int a5,
    int a6,
    long long* a7,
    long long* a8,
    struct _UNICODE_STRING* a9) {
    return 0;
}
int_t CiFindPageHashesInSignedFile(
    int_t a1,
    void* a2,
    unsigned int a3,
    unsigned int a4,
    unsigned int* a5,
    int_t a6,
    int_t a7) {
    return 0;
}

PVOID _stdcall CiFreePolicyInfo(PolicyInfo* policyInfo) {

    return 0;
}
int_t CiGetPEInformation(DWORD* a1, unsigned int a2, unsigned int a3)
{
    return 0;
}
NTSTATUS _stdcall CiValidateFileObject(
    struct _FILE_OBJECT* fileObject,
    int a2,
    int a3,
    PolicyInfo* policyInfoForSigner,
    PolicyInfo* policyInfoForTimestampingAuthority,
    LARGE_INTEGER* signingTime,
    BYTE* digestBuffer,
    int* digestSize,
    int* digestIdentifier
) {
    return 0;
}
NTSTATUS CiVerifyHashInCatalog(
    _In_ PCUCHAR digest,      // pointer to the digest itself
    _In_ int digestSize,		// 14h for SHA1
    _In_ int digestIdentifier,	// 8004h for SHA1
    _In_ int a4,			// system context?
    _In_ int a5,			// always 0
    _In_ int a6,			// always 2007Fh
    _Out_ PolicyInfo* policyInfo,
    _Out_opt_ UNICODE_STRING* catalogName,
    _Out_ LARGE_INTEGER* signingTime,
    _Out_ PolicyInfo* policyInfo2
) {
    return 0;
}
int_t CiValidateImageHeader(
    int_t a1,
    int_t a2,
    int_t a3,
    int_t a4,
    int a5,
    int_t a6,
    char a7,
    BYTE* a8)
{
    return 0i64;
}
int_t CiValidateImageData()
{
    return 0i64;
}

WORD g_CiOptions = 0;
PRKPROCESS g_CiSystemProcess;
LIST_ENTRY g_BootDriverList;
int g_CiInitLock;
int g_CiMinimumHashAlgorithm = 0x8004;
int g_CiExclusionListCount;
int g_CiPrivateNtosApis;
char g_CiUpgradeInProgress;
char g_CiVslHvciInterface[104];
int_t  g_CipRuntimeSignersList, g_CiWimListLock;
short g_CiDeveloperMode = 0;
int* g_CiProtectedContent[] = { &g_CiOptions,0x4,&g_CiDeveloperMode,0x4,&g_CiSystemProcess,0x8,&g_CiMinimumHashAlgorithm,0x4,&g_CiExclusionListCount,0x4,&g_CiPrivateNtosApis,0x10,
&g_CiUpgradeInProgress,0x1,&g_CiVslHvciInterface,0x68
};
int __stdcall CiQueryInformation(DWORD* SystemInformation, unsigned int SystemInformationLength, int IsUmciEnabled, unsigned int* ReturnLength)
{
    *ReturnLength = 8;
    if (SystemInformationLength < 8)
        return 0xC0000004;
    if (*SystemInformation != 8 || SystemInformationLength != 8)
        return 0xC0000004;
    SystemInformation[1] = 0;
    SystemInformation[1] |= 0x200u;
    SystemInformation[1] |= 0x40u;
    return 0;
}
void CiSetFileCache(
    int a1,
    KPROCESSOR_MODE a2,
    unsigned __int8 a3,
    unsigned __int8 a4,
    HANDLE* a5,
    unsigned int a6,
    HANDLE Handle)
{
    return 0;
}
int_t CiGetFileCache(int_t a1, char* a2, DWORD* a3, void* a4, int_t a5, int_t a6) {
    return 0;
}
int_t CiHashMemory(
    IN ALG_ID HashAlgId,
    IN void* rgBlob,
    IN DWORD cBlob,
    OUT BYTE rgbHash[MINCRYPT_MAX_HASH_LEN],
    OUT DWORD* pcbHash)
{

    return MinCryptHashMemory(HashAlgId, rgBlob, cBlob, rgbHash, pcbHash);

}
int_t KappxIsPackageFile(int_t a1, BYTE* a2, BYTE* a3) {
    return 1;
}
int_t CiCompareSigningLevels(char a1, char a2)
{
    return 1;
}
DWORD _declspec(dllimport) NtBuildNumber;
int_t CiInitializePolicy(DWORD* a1, DWORD* a2, DWORD* a3, DWORD* a4, DWORD* a5) {
    return 0;
}
int_t CiGetStrongImageReference(int_t a1, unsigned long long* a2)
{
    if (!a1)
        return 0xC00000EF;
    if ((*(DWORD*)a1 & 2) != 0)
        *a2 = *(unsigned long long*)(a1 + 8);
    else
        *a2 = 0;
    return 0;
}
int_t CiReleaseContext(DWORD* a1)
{
    return 0;
}
int_t CiHvciSetImageBaseAddress(int_t a1, int_t a2)
{

    return 0;
}
int_t SIPolicyQueryPolicyInformation(int* a1, int a2, DWORD* a3) {
    return 0;
}
int_t CiQuerySecurityPolicy(
    PCUNICODE_STRING String1,
    PCUNICODE_STRING a2,
    PCUNICODE_STRING a3,
    int_t a4,
    int_t a5) {
    return 0;
}
int_t CiRevalidateImage(char a1, char a2, char a3, int a4, int_t a5, PFILE_OBJECT FileObject) {
    return 1;
}
int_t CiSetInformation(int a1, void* a2, ULONG a3) {
    return 0;
}
int_t CiSetInformationProcess(void* a1, int a2) {
    return 0;
}
int_t CiGetBuildExpiryTime(unsigned long long* a1) {
    *a1 = 0;
    return 0;
}
char CiCheckProcessDebugAccessPolicy(int_t a1, struct _KPROCESS* a2) {
    return 0;
}
int_t CiGetCodeIntegrityOriginClaimForFileObject(int_t a1, int_t a2) {
    return 0;
}
void CiDeleteCodeIntegrityOriginClaimMembers(int_t a1) {

}
void CiDeleteCodeIntegrityOriginClaimForFileObject(int_t a1) {

}
int_t CiCompareExistingSePool(unsigned int* Buf1, unsigned int * Buf2) {
    return 0;
}
int_t CiSetCachedOriginClaim(KPROCESSOR_MODE a1, void* a2, size_t a3, const void* a4) {
    return 0;
}
int_t CiHvciReportMmIncompatibility(int a1, int a2, int a3) {
    return 0;
}
int_t CipInitialize(unsigned int OptionFlags, void** BootDriverListHead, int_t* a3, int_t* a4) {
    g_CiOptions = 0;
    g_CiSystemProcess = NULL;
    g_CipRuntimeSignersLock = 0i64;
    g_CiWimListLock = 0i64;
#ifdef _M_ARM
    int_t * pCiCallBacks = (int_t*)a4;
    if (NtBuildNumber > 10000 || NtBuildNumber <= 8500) {
        pCiCallBacks = (int_t*)a3;
    }
#else
    int_t * pCiCallBacks = (int_t*)a3;
#endif
    if (*pCiCallBacks >= 2 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + INT_SIZE) = CiSetFileCache;
    if (*pCiCallBacks >= 3 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 2 * INT_SIZE) = CiGetFileCache;
    if (*pCiCallBacks >= 4 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 3 * INT_SIZE) = CiQueryInformation;
    if (*pCiCallBacks >= 5 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 4 * INT_SIZE) = CiValidateImageHeader;
    if (*pCiCallBacks >= 6 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 5 * INT_SIZE) = CiValidateImageData;
    if (*pCiCallBacks >= 7 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 6 * INT_SIZE) = CiHashMemory;
    if (*pCiCallBacks >= 8 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 7 * INT_SIZE) = KappxIsPackageFile;
    if (*pCiCallBacks >= 9 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 8 * INT_SIZE) = CiCompareSigningLevels;
    if (*pCiCallBacks >= 10 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 9 * INT_SIZE) = CiValidateFileAsImageType;
    if (*pCiCallBacks >= 11 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 10 * INT_SIZE) = CiRegisterSigningInformation;
    if (*pCiCallBacks >= 12 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 11 * INT_SIZE) = CiUnregisterSigningInformation;
    if (*pCiCallBacks >= 13 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 12 * INT_SIZE) = CiInitializePolicy;
    if (*pCiCallBacks >= 14 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 13 * INT_SIZE) = CiReleaseContext;
    if (*pCiCallBacks >= 15 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 14 * INT_SIZE) = NULL;
    if (*pCiCallBacks >= 16 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 15 * INT_SIZE) = CiGetStrongImageReference;
    if (*pCiCallBacks >= 17 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 16 * INT_SIZE) = CiHvciSetImageBaseAddress;
    if (*pCiCallBacks >= 18 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 17 * INT_SIZE) = SIPolicyQueryPolicyInformation;
    if (*pCiCallBacks >= 19 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 18 * INT_SIZE) = CiQuerySecurityPolicy;
    if (*pCiCallBacks >= 20 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 19 * INT_SIZE) = CiRevalidateImage;
    if (*pCiCallBacks >= 21 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 20 * INT_SIZE) = CiSetInformation;
    if (*pCiCallBacks >= 22 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 21 * INT_SIZE) = CiSetInformationProcess;
    if (*pCiCallBacks >= 23 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 22 * INT_SIZE) = CiGetBuildExpiryTime;
    if (*pCiCallBacks >= 24 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 23 * INT_SIZE) = CiCheckProcessDebugAccessPolicy;
    if (*pCiCallBacks >= 25 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 24 * INT_SIZE) = CiGetCodeIntegrityOriginClaimForFileObject;
    if (*pCiCallBacks >= 26 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 25 * INT_SIZE) = CiDeleteCodeIntegrityOriginClaimMembers;
    if (*pCiCallBacks >= 27 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 26 * INT_SIZE) = CiDeleteCodeIntegrityOriginClaimForFileObject;
    if (*pCiCallBacks >= 28 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 27 * INT_SIZE) = CiHvciReportMmIncompatibility;
    if (*pCiCallBacks >= 29 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 28 * INT_SIZE) = CiCompareExistingSePool;
    if (*pCiCallBacks >= 30 * INT_SIZE)*(int_t*)((int_t)pCiCallBacks + 29 * INT_SIZE) = CiSetCachedOriginClaim;
    return 0;
}
int_t CiInitialize(int a1, void** a2, int_t* a3, int_t* a4)
{

    return CipInitialize(0, a2, a3, a4);
}
