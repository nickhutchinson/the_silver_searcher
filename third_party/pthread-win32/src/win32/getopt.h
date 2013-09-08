#ifndef AG_SHIMS_GETOPT_H
#define AG_SHIMS_GETOPT_H
  
#include "defines.h"

AG_BEGIN_DECLS
 
extern char *optarg;
extern int optind;
extern int optopt;
extern int opterr;
extern int optreset;

int getopt(int argc, char * const *argv, const char *ostr);

int
getopt_long(int argc, char * const *argv, const char *optstring,
  const struct option *longopts, int *longindex);

int
getopt_long_only(int argc, char * const *argv, const char *optstring,
  const struct option *longopts, int *longindex);

AG_END_DECLS
 
#endif /* AG_SHIMS_GETOPT_H */
