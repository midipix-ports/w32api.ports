#ifndef _W32API_WINTERNL_H_
#define _W32API_WINTERNL_H_

#include <windef.h>
#include <winnt.h>

struct winternl_system_process_information;
struct winternl_vm_counters;

typedef struct winternl_system_process_information			SYSTEM_PROCESS_INFORMATION,*PSYSTEM_PROCESS_INFORMATION;
typedef struct winternl_vm_counters					VM_COUNTERS,*PVM_COUNTERS;

typedef LONG KPRIORITY;

struct winternl_vm_counters {
	SIZE_T PeakVirtualSize;
	SIZE_T VirtualSize;
	ULONG PageFaultCount;
	SIZE_T PeakWorkingSetSize;
	SIZE_T WorkingSetSize;
	SIZE_T QuotaPeakPagedPoolUsage;
	SIZE_T QuotaPagedPoolUsage;
	SIZE_T QuotaPeakNonPagedPoolUsage;
	SIZE_T QuotaNonPagedPoolUsage;
	SIZE_T PagefileUsage;
	SIZE_T PeakPagefileUsage;
};

struct winternl_system_process_information {
	ULONG NextEntryOffset;
	ULONG NumberOfThreads;
	LARGE_INTEGER Reserved[3];
	LARGE_INTEGER CreateTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER KernelTime;
	UNICODE_STRING ImageName;
	KPRIORITY BasePriority;
	HANDLE UniqueProcessId;
	HANDLE InheritedFromUniqueProcessId;
	ULONG HandleCount;
	ULONG SessionId;
	ULONG PageDirectoryBase;
	VM_COUNTERS VirtualMemoryCounters;
	SIZE_T PrivatePageCount;
	IO_COUNTERS IoCounters;
};

#endif
