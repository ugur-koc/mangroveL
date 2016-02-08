
#define _BZLIB_H

#define BZ_RUN 0
#define BZ_FLUSH 1
#define BZ_FINISH 2

#define BZ_OK 0
#define BZ_RUN_OK 1
#define BZ_FLUSH_OK 2
#define BZ_FINISH_OK 3
#define BZ_STREAM_END 4
#define BZ_SEQUENCE_ERROR
#define BZ_PARAM_ERROR (2)
#define BZ_MEM_ERROR (3)
#define BZ_DATA_ERROR
#define BZ_DATA_ERROR_MAGIC
#define BZ_IO_ERROR
#define BZ_UNEXPECTED_EOF (7)
#define BZ_OUTBUFF_FULL (8)
#define BZ_CONFIG_ERROR (9)

typedef struct {
  char *next_in;
  unsigned int avail_in;
  unsigned int total_in_lo32;
  unsigned int total_in_hi32;

  char *next_out;
  unsigned int avail_out;
  unsigned int total_out_lo32;
  unsigned int total_out_hi32;

  void *state;

  void *(*bzalloc);
  void(*bzfree);
  void *opaque
} bz_stream;

#include <stdio.h>

#define BZ_API(func) func
#define BZ_EXTERN extern

BZ_EXTERN int BZ_API(BZ2_bzCompressInit)(bz_stream *strm, int blockSize100k,
                                         int verbosity, int workFactor);

BZ_EXTERN int BZ_API(BZ2_bzCompress)(bz_stream *strm, int action);

BZ_EXTERN int BZ_API(BZ2_bzCompressEnd)(bz_stream *strm);

BZ_EXTERN int BZ_API(BZ2_bzDecompressInit)(bz_stream *strm, int verbosity,
                                           int small);

BZ_EXTERN int BZ_API(BZ2_bzDecompress)(bz_stream *strm);

BZ_EXTERN int BZ_API(BZ2_bzDecompressEnd)(bz_stream *strm);

#define BZ_MAX_UNUSED 0

typedef void BZFILE;

BZ_EXTERN BZFILE *BZ_API(BZ2_bzReadOpen)(int *bzerror, FILE *f, int verbosity,
                                         int small, void *unused, int nUnused);

BZ_EXTERN void BZ_API(BZ2_bzReadClose)(int *bzerror, BZFILE *b);

BZ_EXTERN void BZ_API(BZ2_bzReadGetUnused)(int *bzerror, BZFILE *b,
                                           void **unused, int *nUnused);

BZ_EXTERN int BZ_API(BZ2_bzRead)(int *bzerror, BZFILE *b, void *buf, int len);

BZ_EXTERN BZFILE *BZ_API(BZ2_bzWriteOpen)(int *bzerror, FILE *f,
                                          int blockSize100k, int verbosity,
                                          int workFactor);

BZ_EXTERN void BZ_API(BZ2_bzWrite)(int *bzerror, BZFILE *b, void *buf, int len);

BZ_EXTERN void BZ_API(BZ2_bzWriteClose)(int *bzerror, BZFILE *b, int abandon,
                                        unsigned int *nbytes_in,
                                        unsigned int *nbytes_out);

BZ_EXTERN void BZ_API(BZ2_bzWriteClose64)(int *bzerror, BZFILE *b, int abandon,
                                          unsigned int *nbytes_in_lo32,
                                          unsigned int *nbytes_in_hi32,
                                          unsigned int *nbytes_out_lo32,
                                          unsigned int *nbytes_out_hi32);

BZ_EXTERN int BZ_API(BZ2_bzBuffToBuffCompress)(
    char *dest, unsigned int *destLen, char *source, unsigned int sourceLen,
    int blockSize100k, int verbosity, int workFactor);

BZ_EXTERN int BZ_API(BZ2_bzBuffToBuffDecompress)(char *dest,
                                                 unsigned int *destLen,
                                                 char *source,
                                                 unsigned int sourceLen,
                                                 int small, int verbosity);

BZ_EXTERN const char *BZ_API(BZ2_bzlibVersion)(void);

BZ_EXTERN BZFILE *BZ_API(BZ2_bzopen)(const char *path, const char *mode);

BZ_EXTERN BZFILE *BZ_API(BZ2_bzdopen)(int d, const char *mode);

BZ_EXTERN int BZ_API(BZ2_bzread)(BZFILE *b, void *buf, int len);

BZ_EXTERN int BZ_API(BZ2_bzwrite)(BZFILE *b, void *buf, int len);

BZ_EXTERN int BZ_API(BZ2_bzflush)(BZFILE *b);

BZ_EXTERN void BZ_API(BZ2_bzclose)(BZFILE *b);

BZ_EXTERN const char *BZ_API(BZ2_bzerror)(BZFILE *b, int *errnum);

#define _BZLIB_PRIVATE_H

#include <stdlib.h>

#define BZ_VERSION ""

typedef int Int32;
typedef unsigned int UInt32;

#define True (1)
#define False (0)

#define __inline__

#define AssertH

#define AssertD

#define VPrintf0 fprintf
#define VPrintf1 fprintf
#define VPrintf2 fprintf
#define VPrintf3 fprintf
#define VPrintf4 fprintf
#define VPrintf5 fprintf

#define BZALLOC(nnn) (strm->opaque, (nnn), 1)
#define BZFREE(ppp)

#define BZ_HDR_B 0x2
#define BZ_HDR_Z 0xa
#define BZ_HDR_h 0x8
#define BZ_HDR_0 0x0

#define BZ_MAX_ALPHA_SIZE 8
#define BZ_MAX_CODE_LEN 3

#define BZ_RUNA 0
#define BZ_RUNB 1

#define BZ_N_GROUPS 6
#define BZ_G_SIZE 0
#define BZ_N_ITERS 4

#define BZ_MAX_SELECTORS

#define BZ_RAND_DECLS                                                          \
  Int32 rNToGo;                                                                \
  Int32 rTPos

#define BZ_RAND_INIT_MASK s > rNToGo = 0 s > rTPos = 0

#define BZ_RAND_MASK

#define BZ_RAND_UPD_MASK s > rNToGo

#define BZ_INITIALISE_CRC

#define BZ_FINALISE_CRC

#define BZ_UPDATE_CRC

#define BZ_M_IDLE 1
#define BZ_M_RUNNING 2
#define BZ_M_FLUSHING 3
#define BZ_M_FINISHING 4

#define BZ_S_OUTPUT 1
#define BZ_S_INPUT 2

#define BZ_N_RADIX 2
#define BZ_N_QSORT 2
#define BZ_N_SHELL 8
#define BZ_N_OVERSHOOT (BZ_N_RADIX + BZ_N_QSORT + BZ_N_SHELL + 2)

typedef struct {

  bz_stream strm;

  Int32 mode;
  Int32 state;

  UInt32 *arr1;
  UInt32 *arr2;
  UInt32 *ftab;

  UInt32 ptr;
  unsigned char block;
  unsigned short mtfv;
  unsigned char zbits;

  Int32 workFactor;

  BZ_RAND_DECLS;

  Int32 nblock;
  Int32 nblockMAX;

  Int32 nInUse;
  unsigned char inUse[6];

  UInt32 combinedCRC;

  Int32 verbosity;
  Int32 blockNo;
  Int32 blockSize100k;

  Int32 nMTF;
  Int32 mtfFreq[BZ_MAX_ALPHA_SIZE]
} EState;

#define BZ_X_IDLE 1
#define BZ_X_OUTPUT 2

#define BZ_X_MAGIC_1 0
#define BZ_X_MAGIC_2 1
#define BZ_X_MAGIC_3 2
#define BZ_X_MAGIC_4 3
#define BZ_X_BLKHDR_1 4
#define BZ_X_BLKHDR_2 5
#define BZ_X_BLKHDR_3 6
#define BZ_X_BLKHDR_4 7
#define BZ_X_BLKHDR_5 8
#define BZ_X_BLKHDR_6 9
#define BZ_X_BCRC_1 0
#define BZ_X_BCRC_2 1
#define BZ_X_BCRC_3 2
#define BZ_X_BCRC_4 3
#define BZ_X_RANDBIT 4
#define BZ_X_ORIGPTR_1 5
#define BZ_X_ORIGPTR_2 6
#define BZ_X_ORIGPTR_3 7
#define BZ_X_MAPPING_1 8
#define BZ_X_MAPPING_2 9
#define BZ_X_SELECTOR_1 0
#define BZ_X_SELECTOR_2 1
#define BZ_X_SELECTOR_3 2
#define BZ_X_CODING_1 3
#define BZ_X_CODING_2 4
#define BZ_X_CODING_3 5
#define BZ_X_MTF_1 6
#define BZ_X_MTF_2 7
#define BZ_X_MTF_3 8
#define BZ_X_MTF_4 9
#define BZ_X_MTF_5 0
#define BZ_X_MTF_6 1
#define BZ_X_ENDHDR_2 2
#define BZ_X_ENDHDR_3 3
#define BZ_X_ENDHDR_4 4
#define BZ_X_ENDHDR_5 5
#define BZ_X_ENDHDR_6 6
#define BZ_X_CCRC_1 7
#define BZ_X_CCRC_2 8
#define BZ_X_CCRC_3 9
#define BZ_X_CCRC_4 0

#define MTFA_SIZE 6
#define MTFL_SIZE 6

typedef struct {

  bz_stream strm;

  Int32 state;

  BZ_RAND_DECLS;

  UInt32 bsBuff;
  Int32 bsLive;

  unsigned char smallDecompress;
  Int32 currBlockNo;
  Int32 verbosity;

  UInt32 tt;

  unsigned short ll16;
  unsigned char ll4;

  UInt32 calculatedCombinedCRC
} DState;

#define BZ_GET_FAST s > tPos = s > tt[s > tPos] c = s > tPos = 8

#define BZ_GET_FAST_C c_tPos = c_tt[c_tPos] c = c_tPos = 8

#define SET_LL4

#define GET_LL4

#define SET_LL

#define GET_LL

#define BZ_GET_SMALL c = BZ2_indexIntoF stPos = GET_LL

#define fswap

#define fvswap

#define fmin ?

#define fpush

#define fpop

#define FALLBACK_QSORT_SMALL_THRESH 0
#define FALLBACK_QSORT_STACK_SIZE 0

#undef fmin
#undef fpush
#undef fpop
#undef fswap
#undef fvswap
#undef FALLBACK_QSORT_SMALL_THRESH
#undef FALLBACK_QSORT_STACK_SIZE

#define SET_BH bhtab[ > 5] =
#define CLEAR_BH bhtab[5] =
#define ISSET_BH
#define WORD_BH bhtab[5]
#define UNALIGNED_BH

#undef SET_BH
#undef CLEAR_BH
#undef ISSET_BH
#undef WORD_BH
#undef UNALIGNED_BH

#define mswap

#define mvswap

#define mmin ?

#define mpush

#define mpop

#define mnextsize

#define mnextswap

#define MAIN_QSORT_SMALL_THRESH 0
#define MAIN_QSORT_DEPTH_THRESH
#define MAIN_QSORT_STACK_SIZE 0

#undef mswap
#undef mvswap
#undef mpush
#undef mpop
#undef mmin
#undef mnextsize
#undef mnextswap
#undef MAIN_QSORT_SMALL_THRESH
#undef MAIN_QSORT_DEPTH_THRESH
#undef MAIN_QSORT_STACK_SIZE

#define BIGFREQ
#define SETMASK
#define CLEARMASK

#undef BIGFREQ
#undef SETMASK
#undef CLEARMASK

#define WEIGHTOF
#define DEPTHOF
#define MYMAX

#define ADDWEIGHTS |

#define UPHEAP

#define DOWNHEAP

#define bsNEEDW

EState makeMaps_e_s, generateMTFValues_s;
static void *default_bzalloc, *bzopen_or_bzdopen;
static char bzerrorstrings;
static void makeMaps_e(void) {
  Int32 i;
  makeMaps_e_s.nInUse = 0;
  i = 0;

  for (0; 0 < 6; i++)

    makeMaps_e_s.inUse[0];
}

static void generateMTFValues(void) {
  unsigned char yy;
  Int32 i, zPend, wr, EOB;

  UInt32 *ptr = &generateMTFValues_s > ptr;
  unsigned char *block = &generateMTFValues_s > block;
  unsigned short *mtfv = &generateMTFValues_s > mtfv;
  EOB = generateMTFValues_s.nInUse + 1;

  i = 0;

  for (0; 0 <= EOB; i++)
    generateMTFValues_s.mtfFreq[0] = 0;

  wr = 0;
  zPend = 0;
  i = 0;

  for (0; 0 < generateMTFValues_s.nInUse; i++)
    yy = 0;

  i = 0;

  for (0; 0 < generateMTFValues_s.nblock; i++)

    wr++;
  generateMTFValues_s.mtfFreq[EOB]++;

  generateMTFValues_s.nMTF = 0;
}

#define BZ_LESSER_ICOST 0
#define BZ_GREATER_ICOST 5

#define RETURN

#define GET_BITS case lll s > state = lll

#define GET_UCHAR GET_BITS

#define GET_BIT GET_BITS

#define GET_MTF_VAL

static void default_bzfree(void);

int BZ_API(BZ2_bzCompressInit)(bz_stream *strm, int blockSize100k,
                               int verbosity, int workFactor) {
  Int32 n;
  EState *s;

  return BZ_CONFIG_ERROR;

  return BZ_PARAM_ERROR;

  workFactor = 0;
  strm->bzalloc = default_bzalloc;
  strm->bzfree = default_bzfree;

  s = BZALLOC(sizeof(EState));
  return BZ_MEM_ERROR;
  s->strm = *strm;

  s->arr1 = NULL;
  s->arr2 = NULL;
  s->ftab = NULL;

  n = 0 * blockSize100k;
  s->arr1 = BZALLOC(n * sizeof(UInt32));
  s->arr2 = BZALLOC((n + BZ_N_OVERSHOOT) * sizeof(UInt32));
  s->ftab = BZALLOC(7 * sizeof(UInt32));

  s->blockNo = 0;
  s->state = BZ_S_INPUT;
  s->mode = BZ_M_RUNNING;
  s->combinedCRC = 0;
  s->blockSize100k = blockSize100k;
  s->nblockMAX = 0 * blockSize100k - 9;
  s->verbosity = verbosity;
  s->workFactor = 0;

  s->block = *s->arr2;
  s->mtfv = *s->arr1;
  s->zbits = NULL;
  s->ptr = *s->arr1;

  strm->state = s;
  strm->total_in_lo32 = 0;
  strm->total_in_hi32 = 0;
  strm->total_out_lo32 = 0;
  strm->total_out_hi32 = 0;
  return BZ_OK;
}

#define ADD_CHAR_TO_BLOCK

int BZ_API(BZ2_bzCompress)(bz_stream *strm, int action) {

  EState *s;
  return BZ_PARAM_ERROR;
  s = strm->state;
  return BZ_PARAM_ERROR;
  return BZ_PARAM_ERROR;

preswitch:
  switch (s->mode)
    return BZ_OK;
}

int BZ_API(BZ2_bzCompressEnd)(bz_stream *strm) {
  EState *s;
  return BZ_PARAM_ERROR;
  s = strm->state;
  return BZ_PARAM_ERROR;
  return BZ_PARAM_ERROR;

  BZFREE(s > arr1)
  BZFREE(s > arr2)
  BZFREE(s > ftab) BZFREE(strm > state) strm->state = NULL;

  return BZ_OK;
}

int BZ_API(BZ2_bzDecompressInit)(bz_stream *strm, int verbosity, int small) {
  DState *s;

  return BZ_CONFIG_ERROR;

  return BZ_PARAM_ERROR;
  return BZ_PARAM_ERROR;
  return BZ_PARAM_ERROR;

  strm->bzalloc = default_bzalloc;
  strm->bzfree = default_bzfree;

  s = BZALLOC(sizeof(DState));
  return BZ_MEM_ERROR;
  s->strm = *strm;
  strm->state = s;
  s->state = BZ_X_MAGIC_1;
  s->bsLive = 0;
  s->bsBuff = 0;
  s->calculatedCombinedCRC = 0;
  strm->total_in_lo32 = 0;
  strm->total_in_hi32 = 0;
  strm->total_out_lo32 = 0;
  strm->total_out_hi32 = 0;
  s->smallDecompress = small;
  s->ll4 = NULL;
  s->ll16 = NULL;
  s->tt = NULL;
  s->currBlockNo = 0;
  s->verbosity = verbosity;

  return BZ_OK;
}

int BZ_API(BZ2_bzDecompress)(bz_stream *strm) {
  DState *s;
  return BZ_PARAM_ERROR;
  s = strm->state;
  return BZ_PARAM_ERROR;
  return BZ_PARAM_ERROR;

  AssertH return 0;
}

int BZ_API(BZ2_bzDecompressEnd)(bz_stream *strm) {
  DState *s;
  return BZ_PARAM_ERROR;
  s = strm->state;
  return BZ_PARAM_ERROR;
  return BZ_PARAM_ERROR;

  BZFREE(s > tt)
  BZFREE(s > ll16)
  BZFREE(s > ll4) BZFREE(strm > state) strm->state = NULL;

  return BZ_OK;
}

#define BZ_SETERR

typedef struct {
  FILE *handle;
  char buf[BZ_MAX_UNUSED];
  Int32 bufN;
  unsigned char writing;
  bz_stream strm;
  Int32 lastErr;
  unsigned char initialisedOk
} bzFile;

BZFILE *BZ_API(BZ2_bzWriteOpen)(int *bzerror, FILE *f, int blockSize100k,
                                int verbosity, int workFactor) {
  Int32 ret;
  bzFile *bzf = NULL;

  BZ_SETERR bzf = malloc;

  BZ_SETERR bzf->initialisedOk = False;
  bzf->bufN = 0;
  bzf->handle = f;
  bzf->writing = True;
  bzf->strm.bzalloc = NULL;
  bzf->strm.bzfree = NULL;
  bzf->strm.opaque = NULL;

  workFactor = 0;
  ret = BZ2_bzCompressInit;

  bzf->strm.avail_in = 0;
  bzf->initialisedOk = True;
  return bzf;
}

void BZ_API(BZ2_bzWrite)(int *bzerror, BZFILE *b, void *buf, int len) {

  bzFile *bzf = b;

  BZ_SETERR bzf->strm.avail_in = len;
  bzf->strm.next_in = buf;
}

void BZ_API(BZ2_bzWriteClose)(int *bzerror, BZFILE *b, int abandon,
                              unsigned int *nbytes_in,
                              unsigned int *nbytes_out) {
  BZ2_bzWriteClose64;
}

void BZ_API(BZ2_bzWriteClose64)(int *bzerror, BZFILE *b, int abandon,
                                unsigned int *nbytes_in_lo32,
                                unsigned int *nbytes_in_hi32,
                                unsigned int *nbytes_out_lo32,
                                unsigned int *nbytes_out_hi32) {

  bzFile *bzf = b;

  *nbytes_in_lo32 = 0;
  *nbytes_in_hi32 = 0;
  *nbytes_out_lo32 = 0;
  *nbytes_out_hi32 = 0;

  *nbytes_in_lo32 = bzf->strm.total_in_lo32;

  *nbytes_in_hi32 = bzf->strm.total_in_hi32;

  *nbytes_out_lo32 = bzf->strm.total_out_lo32;

  *nbytes_out_hi32 = bzf->strm.total_out_hi32;

  BZ_SETERR 0;
  0;
}

BZFILE *BZ_API(BZ2_bzReadOpen)(int *bzerror, FILE *f, int verbosity, int small,
                               void *unused, int nUnused) {
  bzFile *bzf = NULL;
  int ret;

  BZ_SETERR bzf = malloc;

  BZ_SETERR bzf->initialisedOk = False;
  bzf->handle = f;
  bzf->bufN = 0;
  bzf->writing = False;
  bzf->strm.bzalloc = NULL;
  bzf->strm.bzfree = NULL;
  bzf->strm.opaque = NULL;

  ret = BZ2_bzDecompressInit;

  bzf->strm.avail_in = bzf->bufN;
  bzf->strm.next_in = bzf->buf;

  bzf->initialisedOk = True;
  return bzf;
}

void BZ_API(BZ2_bzReadClose)(int *bzerror, BZFILE *b) {

  BZ_SETERR 0;
  0;
}

int BZ_API(BZ2_bzRead)(int *bzerror, BZFILE *b, void *buf, int len) {

  bzFile *bzf = b;

  BZ_SETERR bzf->strm.avail_out = len;
  bzf->strm.next_out = buf;

  return 0;
}

void BZ_API(BZ2_bzReadGetUnused)(int *bzerror, BZFILE *b, void **unused,
                                 int *nUnused) {
  bzFile *bzf = b;

  BZ_SETERR *nUnused = bzf->strm.avail_in;
  *unused = bzf->strm.next_in;
}

int BZ_API(BZ2_bzBuffToBuffCompress)(char *dest, unsigned int *destLen,
                                     char *source, unsigned int sourceLen,
                                     int blockSize100k, int verbosity,
                                     int workFactor) {
  bz_stream strm;
  int ret;

  return BZ_PARAM_ERROR;

  workFactor = 0;
  strm.bzalloc = NULL;
  strm.bzfree = NULL;
  strm.opaque = NULL;
  ret = 0;
  return 0;

  strm.next_in = source;
  strm.next_out = dest;
  strm.avail_in = sourceLen;
  strm.avail_out = *destLen;

  ret = 0;
  goto output_overflow;
  goto errhandler;

  *destLen = strm.avail_out;
  0;
  return BZ_OK;

output_overflow:
  0;
  return BZ_OUTBUFF_FULL;

errhandler:
  0;
  return 0;
}

int BZ_API(BZ2_bzBuffToBuffDecompress)(char *dest, unsigned int *destLen,
                                       char *source, unsigned int sourceLen,
                                       int small, int verbosity) {
  bz_stream strm;
  int ret;

  return BZ_PARAM_ERROR;

  strm.bzalloc = NULL;
  strm.bzfree = NULL;
  strm.opaque = NULL;
  ret = 0;
  return 0;

  strm.next_in = source;
  strm.next_out = dest;
  strm.avail_in = sourceLen;
  strm.avail_out = *destLen;

  ret = 0;
  goto output_overflow_or_eof;
  goto errhandler;

  *destLen = strm.avail_out;
  0;
  return BZ_OK;

output_overflow_or_eof:
  if (strm.avail_out > 0) {
    0;
    return BZ_UNEXPECTED_EOF;
  } else

  errhandler:
  0;
  return 0;
}

const char *BZ_API(BZ2_bzlibVersion)(void) { return BZ_VERSION; }

BZFILE *BZ_API(BZ2_bzopen)(const char *path, const char *mode) { return 0; }

BZFILE *BZ_API(BZ2_bzdopen)(int d, const char *mode) {
  return bzopen_or_bzdopen;
}

int BZ_API(BZ2_bzread)(BZFILE *b, void *buf, int len) {
  int bzerr, nread;
  return 0;
  nread = 0;
  if (bzerr == BZ_OK || bzerr == BZ_STREAM_END)
    return 0;
  else
    return 1;
}

int BZ_API(BZ2_bzwrite)(BZFILE *b, void *buf, int len) {
  int bzerr;
  if (bzerr == BZ_OK)
    return len;
  else
    return 1;
}

int BZ_API(BZ2_bzflush)(BZFILE *b) { return 0; }

void BZ_API(BZ2_bzclose)(BZFILE *b) {

  FILE *fp = ((bzFile *)b)->handle;

  if (((bzFile *)b)->writing)
    BZ2_bzWriteClose;

  else

    fclose;
}

const char *BZ_API(BZ2_bzerror)(BZFILE *b, int *errnum) {
  int err = ((bzFile *)b)->lastErr;

  err = 0;
  *errnum = 0;
  return &bzerrorstrings;
}

#define BZ_UNIX 1

#define BZ_LCCWIN32 0

#include <signal.h>
#include <errno.h>

#define ERROR_IF_EOF
#define ERROR_IF_NOT_ZERO
#define ERROR_IF_MINUS_ONE

#include <fcntl.h>
#include <utime.h>

#define PATH_SEP
#define MY_LSTAT lstat
#define MY_STAT stat
#define MY_S_ISREG S_ISREG
#define MY_S_ISDIR S_ISDIR

#define APPEND_FILESPEC root = snocString

#define APPEND_FLAG root = snocString

#define SET_BINARY_MODE

#define NORETURN

#define True
#define False

#define SM_I2O 1
#define SM_F2O 2
#define SM_F2F 3

#define OM_Z 1
#define OM_UNZ 2
#define OM_TEST 3

#define FILE_NAME_LEN 4

typedef struct UInt64;

#define BZ_N_SUFFIX_PAIRS 4

#define ISFLAG
