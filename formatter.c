#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define USB_PATH			"/dev/sdb"	// MAKE SURE THIS IS THE CORRECT PATH
#define MAX_STORAGE_GIG		4

#define BYTES_IN_GIG		1073741824	// Should not be changed
#define MAX_BYTES			MAX_STORAGE_GIG*BYTES_IN_GIG

#define OS_NAME 		 	"myformat"	// 8 BYTES
#define BYTES_PER_SEC 		512			// 2 BYTES
#define SECTORS_PER_CLUSTER 16			// 1 BYTE
#define RESERVED_SECTORS 	2			// 2 BYTES
#define NUM_FATS 		 	2			// 1 BYTE
#define ROOT_DIR_ENTRIES	0			// 2 BYTES (must be 0)
#define TOTAL_SECTORS_16	0			// 2 BYTES (must be 0)

#define MEDIA_DESCRIPTOR 	0xf8		// 1 BYTE
#define FAT16_SIZE			0			// 2 BYTES (must be 0)

#define SECTORS_PER_TRACK 	512			// 2 BYTES
#define DISK_HEADS		 	4			// 2 BYTES
#define HIDDEN_SECTORS	 	0			// 4 BYTES
#define TOTAL_SECTORS_32 	MAX_BYTES/BYTES_PER_SEC	// 4 BYTES

#define FAT32_SIZE			TOTAL_SECTORS_32/2 - 1	// 4 BYTES
#define FAT_FLAGS		 	0x80		// 2 BYTES
#define FAT_VERSION			0			// 2 BYTES
#define ROOT_CLUSTER		1 + RESERVED_SECTORS// 4 BYTES
#define LOGIC_INFO_SECTOR	1			// 2 BYTES
#define LOGIC_BACKUP_SECTOR	0			// 2 BYTES
#define RESERVED 			(long long)0// 12 BYTES (must be 0)

#define LOGIC_DRIVE_NUMBER	0x80		// 1 BYTE
#define SIGNATURE		 	0x29		// 1 BYTE
#define SERIAL_NUMBER		0x1010 		// 4 BYTES
#define VOLUME_LABEL		"USPSTICK   "// 11 BYTES
#define SYSTEM_ID			"FAT32   "	// 8 BYTES

/*
	Specification Links
	http://www.cs.fsu.edu/~cop4610t/assignments/project3/spec/fatspec.pdf
	http://www.maverick-os.dk/FileSystemFormats/FAT32_FileSystem.html#FATHandlingFlags
	http://www.ntfs.com/fat-boot-modif.htm
*/

void format_usb(){

}


int main(){
	format_usb();
}
