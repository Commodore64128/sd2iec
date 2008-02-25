/* sd2iec - SD/MMC to Commodore serial bus interface/controller
   Copyright (C) 2007,2008  Ingo Korb <ingo@akana.de>

   Inspiration and low-level SD/MMC access based on code from MMC2IEC
     by Lars Pontoppidan et al., see sdcard.c|h and config.h.

   FAT filesystem access based on code from ChaN and Jim Brain, see ff.c|h.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License only.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


   fatops.h: Definitions for the FAT operations

*/

#ifndef FATOPS_H
#define FATOPS_H

#include "buffers.h"
#include "dirent.h"
#include "wrapops.h"
#include "ff.h"

extern FATFS fatfs;

/* API */
void     init_fatops(void);
void     parse_error(FRESULT res, uint8_t readflag);
uint8_t  fat_delete(path_t *path, char *filename);
void     fat_chdir(path_t *path, char *dirname);
void     fat_mkdir(path_t *path, char *dirname);
void     fat_open_read(path_t *path, char *filename, buffer_t *buf);
void     fat_open_write(path_t *path, char *filename, uint8_t type, buffer_t *buf, uint8_t append);
uint8_t  fat_getlabel(char *label);
uint8_t  fat_getid(char *id);
uint16_t fat_freeblocks(void);
uint8_t  fat_opendir(dh_t *dh, path_t *dir);
int8_t   fat_readdir(dh_t *dh, struct cbmdirent *dent);
void     fat_sectordummy(buffer_t *buf, uint8_t track, uint8_t sector);

extern const fileops_t fatops;

/* Generic helpers */
void    image_unmount(void);
void    image_chdir(path_t *path, char *dirname);
uint8_t image_read(DWORD offset, void *buffer, uint16_t bytes);
uint8_t image_write(DWORD offset, void *buffer, uint16_t bytes, uint8_t flush);

#endif
