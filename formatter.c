#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Victor Giovannoni - ICMC/USP */
/* FAT32 Specification Link http://www.cs.fsu.edu/~cop4610t/assignments/project3/spec/fatspec.pdf */


#define USB_PATH            "/dev/sdb"  // MAKE SURE THIS IS THE CORRECT PATH
#define MAX_STORAGE_GIG	    4

#define BYTES_IN_GIG        1073741824  // Should not be changed
#define MAX_BYTES           MAX_STORAGE_GIG*BYTES_IN_GIG

#define JMP_INSTRUCTION     0xeb0090    // MIGHT BE WRONG DUE TO ENDIANNESS
#define OS_NAME             "MYFORMAT"  // 8 BYTES
#define BYTES_PER_SEC       512	        // 2 BYTES
#define SECTORS_PER_CLUSTER 16          // 1 BYTE
#define RESERVED_SECTORS    2           // 2 BYTES
#define NUM_FATS            2           // 1 BYTE
#define ROOT_DIR_ENTRIES    0           // 2 BYTES (must be 0)
#define TOTAL_SECTORS_16    0           // 2 BYTES (must be 0)

#define MEDIA_DESCRIPTOR    0xf8        // 1 BYTE
#define FAT16_SIZE          0           // 2 BYTES (must be 0)

#define SECTORS_PER_TRACK   512	        // 2 BYTES
#define DISK_HEADS          4           // 2 BYTES
#define HIDDEN_SECTORS      0           // 4 BYTES
#define TOTAL_SECTORS_32    MAX_BYTES/BYTES_PER_SEC // 4 BYTES

#define FAT32_SIZE          TOTAL_SECTORS_32/2 - RESERVED_SECTORS  // 4 BYTES
#define FAT_FLAGS           0x80        // 2 BYTES
#define FAT_VERSION         0           // 2 BYTES
#define ROOT_CLUSTER        2           // 4 BYTES
#define LOGIC_INFO_SECTOR   1           // 2 BYTES
#define LOGIC_BACKUP_SECTOR 0           // 2 BYTES
#define RESERVED            0           // 12 BYTES (must be 0)

#define LOGIC_DRIVE_NUMBER  0x80        // 1 BYTE
#define SIGNATURE           0x29        // 1 BYTE
#define SERIAL_NUMBEER      0x1010      // 4 BYTES
#define VOLUME_LABEL        "USPSTICK   "// 11 BYTES
#define SYSTEM_ID           "FAT32   "  // 8 BYTES



void format_usb(){
    FILE *usb = fopen(USB_PATH, 'r+');
    fseek(usb, 0L, SEEK_START);

    int jmp_inst = JMP_INSTRUCTION;
    fwrite(&jmp_inst, 1, 3, usb);

    fwrite(OS_NAME, 1, 8, usb);

    int bytes_sec = BYTES_PER_SEC;
    fwrite(&bytes_sec, 1, 2, usb);

    int sec_cluster = SECTORS_PER_CLUSTER;
    fwrite(&sec_cluster, 1, 1, usb);

    int reserved_sec = RESERVED_SECTORS;
    fwrite(&reserved_sec, 1, 1, usb);

    char num_fats = NUM_FATS;
    fwrite(&num_fats, 1, 1, usb);

    int root_entries = ROOT_DIR_ENTRIES;
    fwrite(&root_entries, 1, 2, usb);

    int sec_16 = TOTAL_SECTORS_16;
    fwrite(&sec_16, 1, 2, usb);

    int media_desc = MEDIA_DESCRIPTOR;
    fwrite(&media_desc, 1, 1, usb);

    int size_16 = FAT16_SIZE;
    fwrite(&size_16, 1, 2, usb);

    int sectors_track = SECTORS_PER_TRACK;
    fwrite(&sectors_track, 1, 2, usb);

    int num_heads = DISK_HEADS;
    fwrite(&num_heads, 1, 2, usb);

    int hidden_sec = HIDDEN_SECTORS;
    fwrite(&hidden_sec, 1, 4, usb);

    int sec_32 = TOTAL_SECTORS_32;
    fwrite(&sec_32, 1, 4, usb);

    int size_32 = FAT32_SIZE;
    fwrite(&size_32, 1, 4, usb);

    int flags = FAT_FLAGS;
    fwrite(&flags, 1, 2, usb);

    int fat_ver = FAT_VERSION;
    fwrite(&fat_ver, 1, 2, usb);

    int root_cluster = ROOT_CLUSTER;
    fwrite(&root_cluster, 1, 4, usb);

    int fat_info_sec = LOGIC_INFO_SECTOR;
    fwrite(&fat_info_sec, 1, 2, usb);

}


int main(){
	format_usb();
}
