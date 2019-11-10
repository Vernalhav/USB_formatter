#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USB_PATH			"/dev/sdb"

#define OS_NAME 			"myformat"		// 8 BYTES
#define BYTES_PER_SEC 		 512			// 2 BYTES
#define SECTORS_PER_CLUSTER  16				// 1 BYTE
#define RESERVED_SECTORS 	 2				// 2 BYTES
#define FAT_COPIES 			 1				// 1 BYTE
#define MEDIA_DESCRIPTOR 	 0xf8			// 1 BYTE
#define SECTORS_PER_TRACK 	 512			// 2 BYTES
#define DISK_HEADS			 4				// 2 BYTES
#define FAT_SECTOR_OFFSET	 2??			// 4 BYTES
#define SECTORS_IN_PARTITION 512??			// 4 BYTES
#define SECTORS_PER_FAT		 512??			// 4 BYTES
#define FAT_FLAGS			 ??				// 2 BYTES
#define DRIVE_VERSION		 ??				// 2 BYTES
#define ROOT_CLUSTER		 ??				// 4 BYTES
#define LOGIC_INFO_CSECTOR	 ??				// 2 BYTES
#define LOGIC_BACKUP_SECTOR	 ??				// 2 BYTES
#define LOGIC_DRIVE_NUMBER	 0x80			// 1 BYTE
#define CURRENT_HEAD		 ??				// 1 BYTE
#define SIGNATURE			 0x28				// 1 BYTE
#define SERIAL_NUMBER		 ?? 			// 4 BYTES
#define VOLUME_LABEL		"USPSTICK   "	// 11 BYTES
#define SYSTEM_ID			"FAT32   "		// 8 BYTES

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