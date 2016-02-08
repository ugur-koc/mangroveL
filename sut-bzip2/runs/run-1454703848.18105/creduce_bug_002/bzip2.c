

#define BZ_OK 0

# 1
#define BZ_PARAM_ERROR 2
#define BZ_MEM_ERROR 3
# 4
# 5
# 6
#define BZ_UNEXPECTED_EOF 7
#define BZ_OUTBUFF_FULL 8
#define BZ_CONFIG_ERROR 9

typedef struct {
  char next_in;
  int avail_in

} bz_stream;

#include <stdio.h>

#define BZ_API
#define BZ_EXTERN

BZ_APIBZ2_bzCompressInit(bz_stream *, int, int, int);

BZ_APIBZ2_bzCompress(void);

strm

    ;

BZ_APIBZ2_bzDecompress();

BZ_APIBZ2_bzDecompressEnd();

#define BZ_MAX_UNUSED 5000

typedef BZFILE;

*BZ_APIBZ2_bzReadOpen(int *, FILE *, int, int, void *, int);

void BZ_APIBZ2_bzReadClose(int *, BZFILE *);

void BZ_APIBZ2_bzReadGetUnused(int *, BZFILE *, void **, int *);

BZ_APIBZ2_bzRead(int *, BZFILE *);

*BZ_APIBZ2_bzWriteOpen(int *, FILE *, int, int, int);

void BZ_APIBZ2_bzWrite(int *, BZFILE *);

void BZ_APIBZ2_bzWriteClose(int *, BZFILE *, int, unsigned *, unsigned *);

BZ2_bzWriteClose64;

BZ_APIBZ2_bzBuffToBuffCompress(char *, unsigned *, char *, unsigned, int);

BZ_APIBZ2_bzBuffToBuffDecompress(char *, unsigned *, char *d);

*BZ_APIBZ2_bzopen(const char *, const char *);

*BZ_APIBZ2_bzdopen(int, const char *);

BZ_APIBZ2_bzread(BZFILE *);

BZ_APIBZ2_bzwrite(BZFILE *);

b

    ();

const char *BZ_APIBZ2_bzerror(BZFILE *, int *);

#include <stdlib.h>

#define BZ_VERSION

typedef char Char;
typedef Bool;
typedef UChar;
typedef Int32;
typedef UInt32;
typedef UInt16;

#define True 1
#define False 0

#

#

#define zf
#define zf
#define za1
#define za2
#define za3
#define za4

#define nnn
#define ppp

#define BZ_MAX_SELECTORS

#define BZ_RAND_DECLS

#define srNToGo

#define BZ_RAND_UPD_MASK

#

#define BZ_M_RUNNING 2

#define BZ_S_INPUT 2

#define BZ_N_SHELL

typedef struct {

  Int32 mode

} EState

    ;

#define BZ_X_MAGIC_1 10

typedef int DState;

#define stPos

#define                                                                        \
                                                                               \
    c_tPos

#

#define ll4i

#

#define ll16i

#define scftab

#

#define zzn

#define a

#

#

#

#define zz
#define zz
#define zz
#define zz
#define zz

#

#define zzn

#define a

#define dz

#define dz

#define az

#

#define BZ_N_QSORT

#

#define ftabb
# 21
#

#

#define zz0
#define zz1
#define zz2

#define MYMAXDEPTHOFzw1

#define lll

#define uuu

#define uuu

#define lval

default_bzalloc;

default_bzfree;

EState *BZ_APIBZ2_bzCompressInit_s;
BZ_APIBZ2_bzCompressInit(bz_stream *strm, int blockSize100k, int verbosity,
                         int workFactor) {

  default_bzalloc;

  arr1 NULL;
  arr2 NULL;
  ftab NULL

      *blockSize100k;

  (0) * sizeof(UInt32);

  0;
  BZ_S_INPUT;
  BZ_M_RUNNING;

  workFactor

      =

          NULL;

  BZ_APIBZ2_bzCompressInit_s = 0;
  0;

  return BZ_OK;
}

#

bz_stream  BZ_APIBZ2_bzCompress_strm;
int BZ_APIBZ2_bzCompress(void) {

  EState *s;

  switch (s->mode)
    ;
}

BZ_APIBZ2_bzCompressEnd(void) {

  if (arr1 NULL)

    if (arr2 NULL)

      ;
}

BZ_APIBZ2_bzDecompressInit(void) {
  DState *s

      ;

  default_bzalloc;

  s

      = 0;
  0;
  0;
  ll4 NULL;
  ll16 NULL;
  tt NULL;

  return BZ_OK;
}

BZ_APIBZ2_bzDecompress(bz_stream *strm) {}

BZ_APIBZ2_bzDecompressEnd(bz_stream *strm) {

  if (tt NULL)

    if (ll16 NULL)

      ;
}

typedef struct { bz_stream strm } bzFile;

*BZ_APIBZ2_bzWriteOpen(int *bzerror, FILE *f, int blockSize100k, int verbosity,
                       int workFactor) {
  Int32 ret;
  bzFile *bzf;

  (f)

      = (sizeof(bzFile));

  BZ_OK;
  False;
  0;
  f = bzf

      = (workFactor)

      ;

  bzf;
}

bzFile *BZ_APIBZ2_bzWrite_bzf = *b;

void * BZ_APIBZ2_bzWrite_buf;
void BZ_APIBZ2_bzWrite(int *bzerror, BZFILE *b) {

  ((BZ_APIBZ2_bzWrite_bzf))

      = BZ_APIBZ2_bzWrite_buf;
}

void BZ_APIBZ2_bzWriteClose(int *bzerror, BZFILE *b, int abandon,
                            unsigned *nbytes_in, unsigned *nbytes_out){

}

    * BZ_APIBZ2_bzReadOpen(int *bzerror, FILE *f, int verbosity, int small,
                           void *unused, int nUnused) {
  bzFile *bzf;
  int ret;

  (f)

      = (sizeof(bzFile));

  BZ_OK;

  False;
  f = False;
  bzf

      = NULL;

  bzf;
  bzf

      = bzf;
}

void BZ_APIBZ2_bzReadClose(int *bzerror, BZFILE *b) {}

bzFile *BZ_APIBZ2_bzRead_bzf = *b;

void * BZ_APIBZ2_bzRead_buf;
BZ_APIBZ2_bzRead(int *bzerror, BZFILE *b) {

  BZ_APIBZ2_bzRead_bzf = BZ_APIBZ2_bzRead_buf;

  return 0;
}

bzFile *BZ_APIBZ2_bzReadGetUnused_bzf;
void BZ_APIBZ2_bzReadGetUnused(int *bzerror, BZFILE *b, void **unused,
                               int *nUnused) {

  (

      0) *
      BZ_APIBZ2_bzReadGetUnused_bzf->strm.avail_in *
      BZ_APIBZ2_bzReadGetUnused_bzf->strm.next_in;
}

int BZ_APIBZ2_bzBuffToBuffCompress_verbosity;
BZ_APIBZ2_bzBuffToBuffCompress(char *dest, unsigned *destLen, char *source,
                               unsigned sourceLen, int blockSize100k) {

  bzalloc NULL;
  bzfree NULL;
  opaque NULL

      ;

  source = sourceLen =

      0

      ;
}

int BZ_APIBZ2_bzBuffToBuffDecompress_small;
BZ_APIBZ2_bzBuffToBuffDecompress(char *dest, unsigned *destLen, char *source) {
  unsigned int sourceLen = 0;

  bzalloc NULL;
  bzfree NULL;
  opaque NULL

      ;

  source = sourceLen =

      0

      ;

output_overflow_or_eof:
  0;
}

BZ_APIBZ2_bzlibVersion() {}

bzopen_or_bzdopen;

*BZ_APIBZ2_bzopen(const char *path, const char *mode){}

    * BZ_APIBZ2_bzdopen(int fd, const char *mode) {}

void * BZ_APIBZ2_bzread_buf;
BZ_APIBZ2_bzread(BZFILE *b) {}

void * BZ_APIBZ2_bzwrite_buf;
BZ_APIBZ2_bzwrite(BZFILE *b) {
  int bzerr

      ;
  if (bzerr == BZ_OK) {
  }
}

BZ_APIBZ2_bzflush;

int BZ_APIBZ2_bzclose_b;
BZ_APIBZ2_bzclose(void) { FILE *fp = (b); }

*bzerrorstrings;

const char *BZ_APIBZ2_bzerror(BZFILE *b, int *errnum) {

  return bzerrorstrings[1];
}

#include <signal.h>
#include <errno.h>

typedef IntNative;

#

#

#define s

main;
