#ifndef AG_SHIMS_DIRENT_H_
#define AG_SHIMS_DIRENT_H_

#include <minwindef.h>
#include <stdint.h>

/* MAX_PATH utf-16 chars === MAX_PATH*3 in utf8 */
#define AG__DIRENT_MAX_PATH MAX_PATH*3+1

typedef struct ag_dir_enumerator_s DIR;

struct dirent {
  unsigned int d_fileno; /* file number of entry; always 0 on windows */
  uint16_t d_reclen;     /* length of this record */
  uint16_t d_namlen;     /* length of string in d_name */
  uint8_t  d_type;       /* file type, see below */
  uint32_t d_w32attrs;   /* this is the dwFileAttributes member from WIN32_FIND_DATA */
  char d_name[AG__DIRENT_MAX_PATH]; 
};

DIR* opendir(const char*);
struct dirent* readdir(DIR*);
int closedir(DIR*);


#endif // AG_SHIMS_DIRENT_H_
