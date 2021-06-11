#pragma once
#include <tchar.h>
#include <intrin.h>

bool hwidChecker() {
	bool verified = false;
	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;

	if (GetVolumeInformation(
		_T("C:\\"),
		volumeName,
		ARRAYSIZE(volumeName),
		&serialNumber,
		&maxComponentLen,
		&fileSystemFlags,
		fileSystemName,
		ARRAYSIZE(fileSystemName))) {

		if (serialNumber == 2460684972 || serialNumber == 309480728) { // my HWID, pyr0's HWID
			verified = true;
		}
		else {
			verified = false;
		}
	}
	return verified;
}