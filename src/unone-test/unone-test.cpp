/****************************************************************************
**
** Copyright (C) 2019 BlackINT3
** Contact: https://github.com/BlackINT3/none
**
** GNU Lesser General Public License Usage (LGPL)
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
****************************************************************************/
#include <stdio.h>
#include <tchar.h>
#include <iostream>

#include "common/common.h"

int UnitTest(int argc, char* argv[])
{
	printf("---------------------------------------------------------------\n");
	printf("UNONE Test running...\n");
	printf("UNONE_VERSION: %s\n", UNONE_VERSION);
	printf("PROCESS_PATH: %s\n", argv[0]);
	printf("---------------------------------------------------------------\n");
	printf("\n");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

int MiniTest(int argc, char* argv[])
{
	//
	//add mini code test
	//

	//UNONE::PsInjectByRemoteThreadW(9808, LR"("I:\demo\inject - demo64.dll")");
	using namespace UNONE::Plugins::Cryptor;

/*
	std::string hash;
	hash = "123";
	printf("%s\n", Base64Decode(Base64Encode(hash)).c_str());
	RC4("213", hash);
	hash = UNONE::StrStreamToHexStrA(hash);
	printf("%s", hash.c_str());*/

	std::string data;
	UNONE::FsReadFileDataA("c:\\test\\libc64.so", data);
	CHAR* elf = (CHAR*)data.c_str();
	auto is_valid = UNONE::ElfValid(elf); printf("is_valid: %d\n", is_valid);
	auto is_x64 = UNONE::ElfX64(elf); printf("is_x64: %d\n", is_x64);
	auto oep = UNONE::ElfGetEntryPoint(elf); printf("oep: 0x%llx\n", oep);

	//std::cin >> argc;
	return 0;
}

// Test Entry
int main(int argc, char* argv[])
{
	_wsetlocale(LC_ALL, L"");
	UNONE::SeEnableDebugPrivilege();
	
	MiniTest(argc, argv);

	//UnitTest(argc, argv);
}

