 

#define BZ_OK 0
#define BZ_RUN_OK 1

#define BZ_FINISH_OK 3
#define BZ_STREAM_END 4

#define BZ_PARAM_ERROR -2
#define BZ_MEM_ERROR -3

#define BZ_UNEXPECTED_EOF -7
#define BZ_OUTBUFF_FULL -8
#define BZ_CONFIG_ERROR -9

typedef struct {
  char next_in;
  int avail_in;
  int total_in_lo32;
  int total_in_hi32;

  char next_out;
  int avail_out;
  int total_out_lo32;
  int total_out_hi32;

  void *state;

  void (*bzalloc);
  void (*bzfree)(void);
  void *opaque
} bz_stream;

#include <stdio.h>

#define BZ_API
#define BZ_EXTERN

BZ2_bzCompressInit(bz_stream *, int);

BZ2_bzCompressvoid;

;

BZ2_bzDecompressInit(bz_stream *);

;

strm;

#define BZ_MAX_UNUSED 0

typedef BZFILE;

*BZ2_bzReadOpen(int *, FILE *, int, int, void *, int);

void BZ2_bzReadClose(int *, BZFILE *);

void BZ2_bzReadGetUnused(int *, BZFILE *, void **, int *);

BZ2_bzRead(int *, BZFILE *);

*BZ2_bzWriteOpen(int *, FILE *, int, int, int);

void BZ2_bzWrite(int *, BZFILE *);



void BZ2_bzWriteClose64(int *, BZFILE *, int, unsigned *, unsigned *,
                        unsigned *, unsigned *);

BZ2_bzBuffToBuffCompress(char *, unsigned *, char *, unsigned, int);

BZ2_bzBuffToBuffDecompress(char *, unsigned *, char *, unsigned);

const char BZ2_bzlibVersionvoid;

*BZ2_bzopen(const char *, const char *);

*BZ2_bzdopen(int, const char *);

BZ2_bzread(BZFILE *);

BZ2_bzwrite(BZFILE *);

;

void;

const char *BZ2_bzerror(BZFILE *, int *);

#include <stdlib.h>

#define BZ_VERSION "1.0.2, 30-Dec-2001"

typedef Int32;
typedef UInt32;

#define True 1
#define False 0

void;
#define AssertH

#define AssertD

#define nnn
#define ppp

#define BZ_MAX_ALPHA_SIZE 8

#define BZ_N_GROUPS 6
#define BZ_G_SIZE 0

#define BZ_MAX_SELECTORS BZ_G_SIZE

#define BZ_RAND_DECLS

#define srNToGo

#define BZ_RAND_UPD_MASK

#define BZ_M_RUNNING 2

#define BZ_S_INPUT 2

#define BZ_N_RADIX
#define BZ_N_QSORT
#define BZ_N_SHELL
#define BZ_N_OVERSHOOT 2

typedef struct {

  bz_stream strm;

  Int32 mode;
  Int32 state

      ;

  UInt32 arr1;
  UInt32 arr2;
  UInt32 ftab;

  UInt32 ptr;
  char block;
  short mtfv;
  char zbits;

  Int32 workFactor

      ;

  Int32 nblock;
  Int32 nblockMAX

      ;

  Int32 nInUse;
  char inUse[6];
  char unseqToSeq[6]

      ;
  UInt32 combinedCRC;

  Int32 verbosity;
  Int32 blockNo;
  Int32 blockSize100k;

  Int32 nMTF;
  Int32 mtfFreq[BZ_MAX_ALPHA_SIZE];
  char;
  char;

  char lenBZ_N_GROUPSBZ_MAX_ALPHA_SIZE

} EState

    ;

#define BZ_X_MAGIC_1 0

#define MTFA_SIZE 6
#define MTFL_SIZE 6

typedef struct {

  bz_stream strm;

  Int32 state

      ;

  ;

  UInt32 bsBuff;
  Int32 bsLive

      ;
  char smallDecompress;
  Int32 currBlockNo;
  Int32 verbosity

      ;
  Int32;
  ;
  Int32;
  Int32;

  UInt32 tt;

  short ll16;
  char ll4

      ;
  UInt32 calculatedCombinedCRC

      ;
  char;
  char;
  char;

  char;
  Int32
      mtfbase[MTFL_SIZE][BZ_MAX_SELECTORS][BZ_MAX_SELECTORS][BZ_MAX_ALPHA_SIZE]

      ;

} DState;

#define stPos

#define                                                                        \
                                                                               \
    c_tPos

#define BZ2_indexIntoF

void BZ2_decompress();

#

#

#

#define bhtab
#define bhtab

#define bhtab

#

#

#

#

#

EState makeMaps_e_s;
makeMaps_e() {
  Int32 i

      = 0;

  for (;;) ;
}

EState generateMTFValues_s;
generateMTFValues() {
  unsigned char yy;
  Int32 i, j;
  Int32 zPend;
  Int32 wr;
  Int32 EOB;

  UInt32 ptr;
  char *block = block;
  short mtfv = mtfv

      = 0;

  for (;;)
    generateMTFValues_s.mtfFreq[0]

        ;

  for (;;)

    for (;;) 

    ;
  generateMTFValues_s.mtfFreq;

  0;
}

#define lll

#

s

    ;

default_bzalloc;

default_bzfree

    ;

void

    ;

BZ2_bzCompressInit(bz_stream *strm, int blockSize100k) {
  int verbosity = 0;
  int workFactor = 0;
  Int32 n;
  EState *s;

  if (0)

    if (0)

      if (0)

        if (bzalloc NULL)
          default_bzalloc;
  if (bzfree NULL)

    BZALLOC();
  if NULL

    *

        NULL;
  arr2 NULL;
  ftab NULL

      *blockSize100k;
  ;
  0,0;
  ;

  if (arr1 NULL == NULL)

    0;
  BZ_S_INPUT;
  BZ_M_RUNNING;

  0;

  ;
  ;
  zbits NULL;

  s = 0;
  0;

  return BZ_OK;
}

int BZ2_bzCompress(void) {
  bz_stream * strm = 0;
  int action = 0;

  EState *s;
  if NULL

    ;
  if NULL

    if (strm)

      switch (s->mode)
        ;
}

BZ2_bzCompressEnd(void) {
  bz_stream *strm = 0;
  EState s;
  if NULL

    ;
  if NULL

    if (strm)

      if (arr1 NULL)
        arr1;
  if (arr2 NULL)
    arr2;
  if (ftab NULL)
    ftab;

  ;
}

BZ2_bzDecompressInit(bz_stream *strm) {
  int verbosity = 0;
  int small = 0;
  DState *s;

  if (0)

    if NULL

      if (1)

        if (4)

          if (bzalloc NULL)
            default_bzalloc;
  if (bzfree NULL)

    BZALLOC();
  if NULL

    *strm;
  s

      = 0;
  0;
  0;
  small = ll16 NULL;
  tt NULL;

  return BZ_OK;
}

static

    BZ2_bzDecompress(void) {
  bz_stream *strm = 0;
  DState s;
  if NULL

    ;
  if NULL

    if (strm)

      1

          ;
}

BZ2_bzDecompressEnd(void) {
  bz_stream *strm = 0;
  DState s;
  if NULL

    ;
  if NULL

    if (strm)

      if (tt NULL)
        tt;
  if (ll16 NULL)
    ll16;
  if (ll4 NULL)
    ll4

        ;
  ;
}

#define BZ_SETERR

typedef struct {
  FILE handle;
  char buf;
  Int32 bufN;
  char writing;
  bz_stream strm;
  Int32 lastErr;
  char initialisedOk
} bzFile;

*BZ2_bzWriteOpen(int *bzerror, FILE *f, int blockSize100k, int verbosity,
                 int workFactor) {
  Int32 ret;
  bzFile *bzf

      ;

  workFactor;

  NULL

      ;
  False;
  0;
  f = bzf

      = NULL;

  0;

  bzf;
}

void BZ2_bzWrite(int *bzerror, BZFILE *b) {
  void * buf = 0;
  int len = 0;
  Int32 ret;
  bzFile *bzf

      ;
  0;
  bzf;

  bzf = buf;

  bzf

      ;
  BZ_RUN_OK;

  bzf <

          bzf ==
      0;

  ;
}



void BZ2_bzWriteClose64(int *bzerror, BZFILE *b, int abandon,
                        unsigned *nbytes_in_lo32, unsigned *nbytes_in_hi32,
                        unsigned *nbytes_out_lo32, unsigned *nbytes_out_hi32) {

  bzFile bzf;

  NULL;
  &bzf;
  ferror;

  if NULL

    if NULL

      if NULL

        if NULL

          if (!

              nbytes_in_lo32)
            bzf;
  if NULL
    bzf;
  if NULL
    bzf;
  if NULL
    bzf

        ;
}

*BZ2_bzReadOpen(int *bzerror, FILE *f, int verbosity, int small, void *unused,
                int nUnused) {
  bzFile *bzf;
  int ret

      ;

  verbosity != BZ_MAX_UNUSED;

  NULL

      ;

  False;
  f = False;
  bzf

      = NULL;

  while (0)

    bzf;
  bzf

      = malloc;
}

void BZ2_bzReadClose(int *bzerror, BZFILE *b) {
  bzFile bzf

      ;
  NULL;

  &bzf;

  &bzf;

  ;
}

BZ2_bzRead(int *bzerror, BZFILE *b) {
  void * buf = 0;
  int len = 0;

  bzFile *bzf

      ;

  0;

  bzf;

  0;

  bzf = buf;

  return 0;
}

void BZ2_bzReadGetUnused(int *bzerror, BZFILE *b, void **unused, int *nUnused) {
  bzFile bzf;
  NULL;
  BZ_STREAM_END;
  NULL

      ;
  &bzf;
  &bzf;
}

BZ2_bzBuffToBuffCompress(char *dest, unsigned *destLen, char *source,
                         unsigned sourceLen, int blockSize100k) {
  int verbosity = 0;
  int workFactor = 0;
  bz_stream strm;
  int ret;

  if (

      0)

    if (0)

      bzalloc NULL;
  bzfree NULL;
  opaque NULL;
  ;

  source = sourceLen =

      0;
  ;

  ;
  ;

  ;
}

BZ2_bzBuffToBuffDecompress(char *dest, unsigned *destLen, char *source,
                           unsigned sourceLen) {
  int small = 0;
  int verbosity = 0;
  bz_stream strm;
  int ret;

  if (1)

    bzalloc NULL;
  bzfree NULL;
  opaque NULL;
  ;

  source = sourceLen =

      0;
  ;

  ;
  ;

output_overflow_or_eof:
  0;

  
}

BZ2_bzlibVersion() {}

bzopen_or_bzdopen;

*BZ2_bzopen(const char *path, const char *mode){}

    * BZ2_bzdopen(int d, const char *mode) {}

BZ2_bzread(BZFILE *b) {
  void * buf = 0;
  int len = 0;
  int bzerr, nread;
  (bzFile *)b;

  ;

  ;
}

BZ2_bzwrite(BZFILE *b) {
  void * buf = 0;
  int len = 0;
  int bzerr

      ;
  if (bzerr == BZ_OK)

    ;
}

BZ2_bzflush;

BZ2_bzclose(void) {
  int b = 0;
  int bzerr;
  FILE *fp = (bzFile *)b;

  if ((bzFile *)b)

    if (BZ_OK)

      if (stdout)
        ;
}

*bzerrorstrings = 

    "???";

const char *BZ2_bzerror(BZFILE *b, int *errnum) {
  int err = (bzFile *)b;

  (bzFile *)b;

  "OK";
}

#include <signal.h>
#include <errno.h>

#

#
 