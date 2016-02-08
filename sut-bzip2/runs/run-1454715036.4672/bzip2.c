
#define _BZLIB_H

#define BZ_RUN 0
#define BZ_FLUSH 1
#define BZ_FINISH 2

#define BZ_OK 0
#define BZ_RUN_OK 1
#define BZ_FLUSH_OK 2
#define BZ_FINISH_OK 3
#define BZ_STREAM_END 4
#define BZ_SEQUENCE_ERROR 1
#define BZ_PARAM_ERROR 2
#define BZ_MEM_ERROR 3
#define BZ_DATA_ERROR 4
#define BZ_DATA_ERROR_MAGIC 5
#define BZ_IO_ERROR 6
#define BZ_UNEXPECTED_EOF 7
#define BZ_OUTBUFF_FULL 8
#define BZ_CONFIG_ERROR 9

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

BZ_EXTERN int BZ_APIBZ2_bzCompressInit(void);

BZ_EXTERN int BZ_APIBZ2_bzCompress(void);

BZ_EXTERN int BZ_APIBZ2_bzCompressEnd(void);

BZ_EXTERN int BZ_APIBZ2_bzDecompressInit(void);

BZ_EXTERN int BZ_APIBZ2_bzDecompress(void);

BZ_EXTERN int BZ_APIBZ2_bzDecompressEnd(void);

#define BZ_MAX_UNUSED 0

typedef void BZFILE;

BZ_EXTERN BZFILE *BZ_APIBZ2_bzReadOpen(int *p1, FILE *p2, int p3, int p4,
                                       void *p5, int p6);

BZ_EXTERN void BZ_APIBZ2_bzReadClose(void);

BZ_EXTERN void BZ_APIBZ2_bzReadGetUnused(void);

BZ_EXTERN int BZ_APIBZ2_bzRead(void);

BZ_EXTERN BZFILE *BZ_APIBZ2_bzWriteOpen(int *p1, FILE *p2, int p3, int p4,
                                        int p5);

BZ_EXTERN void BZ_APIBZ2_bzWrite(void);

BZ_EXTERN void BZ_APIBZ2_bzWriteClose(void);

BZ_EXTERN void BZ_API(BZ2_bzWriteClose64)(int *p1, BZFILE *p2, int p3,
                                          unsigned int *p4, unsigned int *p5,
                                          unsigned int *p6, unsigned int *p7);

BZ_EXTERN int BZ_APIBZ2_bzBuffToBuffCompress(void);

BZ_EXTERN int BZ_APIBZ2_bzBuffToBuffDecompress(void);
int BZ_APIBZ2_bzBuffToBuffDecompress_ret, BZ_APIBZ2_bzread_nread, makeMaps_e_i,
    generateMTFValues_i, generateMTFValues_j, generateMTFValues_zPend,
    generateMTFValues_wr, generateMTFValues_EOB, BZ_APIBZ2_bzCompressInit_n,
    BZ_APIBZ2_bzBuffToBuffCompress_ret;
int BZ_APIBZ2_bzBuffToBuffDecompress(void) {

  unsigned int sourceLen = 0;
  char *source = 0, *dest = 0;
  unsigned int *destLen = 0;

  bz_stream strm;

  return BZ_PARAM_ERROR;

  strm.bzalloc = NULL;
  strm.bzfree = NULL;
  strm.opaque = NULL;
  BZ_APIBZ2_bzBuffToBuffDecompress_ret = 0;

  return BZ_APIBZ2_bzBuffToBuffDecompress_ret;

  strm.next_in = source;
  strm.next_out = dest;
  strm.avail_in = sourceLen;
  strm.avail_out = *destLen;

  BZ_APIBZ2_bzBuffToBuffDecompress_ret = 0;

  goto output_overflow_or_eof;

  goto errhandler;

  *destLen = strm.avail_out;
  0;
  return BZ_OK;

output_overflow_or_eof:
  strm.avail_out > 0;

errhandler:
  0;
  return BZ_APIBZ2_bzBuffToBuffDecompress_ret;
}

BZ_EXTERN const char *BZ_APIBZ2_bzlibVersion(void);

BZ_EXTERN BZFILE *BZ_APIBZ2_bzopen(void);
BZFILE *BZ_APIBZ2_bzopen(void) { return 0; }

BZ_EXTERN BZFILE *BZ_APIBZ2_bzdopen(void);

BZ_EXTERN int BZ_APIBZ2_bzread(void);

int BZ_APIBZ2_bzread(void) {

  return 0;
  BZ_APIBZ2_bzread_nread = 0;
}

BZ_EXTERN int BZ_APIBZ2_bzwrite(void);

int BZ_APIBZ2_bzwrite(void) {}

BZ_EXTERN int BZ_APIBZ2_bzflush(void);

BZ_EXTERN void BZ_APIBZ2_bzclose(void);

BZ_EXTERN const char *BZ_APIBZ2_bzerror(void);

#define _BZLIB_PRIVATE_H

#include <stdlib.h>

#define BZ_VERSION ""

typedef unsigned char Bool;
typedef unsigned char UChar;
typedef int Int32;
typedef unsigned int UInt32;

typedef unsigned short UInt16;

#define True 1
#define False 0

#define __inline__

#define AssertHconderrcode

#define AssertDcondmsg

#define VPrintf0zf fprintfstderrzf
#define VPrintf1zfza1 fprintfstderrzfza1
#define VPrintf2zfza1za2 fprintfstderrzfza1za2
#define VPrintf3zfza1za2za3 fprintfstderrzfza1za2za3
#define VPrintf4zfza1za2za3za4 fprintfstderrzfza1za2za3za4
#define VPrintf5zfza1za2za3za4za5 fprintfstderrzfza1za2za3za4za5

#define BZALLOCnnn strm > bzallocstrm > opaquennn1
#define BZFREEppp strm > bzfreestrm > opaqueppp

#define BZ_HDR_B 2
#define BZ_HDR_Z 10
#define BZ_HDR_h 8
#define BZ_HDR_0 0

#define BZ_MAX_ALPHA_SIZE 8
#define BZ_MAX_CODE_LEN 3

#define BZ_RUNA 0
#define BZ_RUNB 1

#define BZ_N_GROUPS 6
#define BZ_G_SIZE 50
#define BZ_N_ITERS 4

#define BZ_MAX_SELECTORS 2 + 0 / BZ_G_SIZE

#define BZ_RAND_DECLS                                                          \
  Int32 rNToGo;                                                                \
  Int32 rTPos

#define BZ_RAND_INIT_MASK s > rNToGo = 0 s > rTPos = 0

#define BZ_RAND_MASK s > rNToGo == 1 ? 1 0

#define BZ_RAND_UPD_MASK                                                       \
  if                                                                           \
    s > rNToGo == 0 s > rNToGo;

#define BZ_INITIALISE_CRCcrcVar

#define BZ_FINALISE_CRCcrcVar

#define BZ_UPDATE_CRCcrcVarcha

#define BZ_M_IDLE 1
#define BZ_M_RUNNING 2
#define BZ_M_FLUSHING 3
#define BZ_M_FINISHING 4

#define BZ_S_OUTPUT 1
#define BZ_S_INPUT 2

#define BZ_N_RADIX 2
#define BZ_N_QSORT 2
#define BZ_N_SHELL 8
#define BZ_N_OVERSHOOT BZ_N_RADIX BZ_N_QSORT BZ_N_SHELL 2

typedef struct {

  bz_stream *strm;

  Int32 mode;
  Int32 state;

  UInt32 avail_in_expect;

  UInt32 *arr1;
  UInt32 *arr2;
  UInt32 *ftab;
  Int32 origPtr;

  UInt32 *ptr;
  UChar *block;
  UInt16 *mtfv;
  UChar *zbits;

  Int32 workFactor;

  UInt32 state_in_ch;
  Int32 state_in_len;
  BZ_RAND_DECLS;

  Int32 nblock;
  Int32 nblockMAX;
  Int32 numZ;
  Int32 state_out_pos;

  Int32 nInUse;
  Bool inUse[6];
  UChar unseqToSeq[6];

  UInt32 bsBuff;
  Int32 bsLive;

  UInt32 blockCRC;
  UInt32 combinedCRC;

  Int32 verbosity;
  Int32 blockNo;
  Int32 blockSize100k;

  Int32 nMTF;
  Int32 mtfFreq[BZ_MAX_ALPHA_SIZE];
  UChar selector[BZ_MAX_SELECTORS];
  UChar selectorMtf[BZ_MAX_SELECTORS];

  UChar len[BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
  Int32 code[BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
  Int32 rfreq[BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];

  UInt32 len_pack[BZ_MAX_ALPHA_SIZE][4]
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

#define MTFA_SIZE 4096
#define MTFL_SIZE 6

typedef struct {

  bz_stream *strm;

  Int32 state;

  UChar state_out_ch;
  Int32 state_out_len;
  Bool blockRandomised;
  BZ_RAND_DECLS;

  UInt32 bsBuff;
  Int32 bsLive;

  Int32 blockSize100k;
  Bool smallDecompress;
  Int32 currBlockNo;
  Int32 verbosity;

  Int32 origPtr;
  UInt32 tPos;
  Int32 k0;
  Int32 unzftab[6];
  Int32 nblock_used;
  Int32 cftab[7];
  Int32 cftabCopy[7];

  UInt32 *tt;

  UInt16 *ll16;
  UChar *ll4;

  UInt32 storedBlockCRC;
  UInt32 storedCombinedCRC;
  UInt32 calculatedBlockCRC;
  UInt32 calculatedCombinedCRC;

  Int32 nInUse;
  Bool inUse[6];
  Bool inUse16[6];
  UChar seqToUnseq[6];

  UChar mtfa[MTFA_SIZE];
  Int32 mtfbase[6 / MTFL_SIZE];
  UChar selector[BZ_MAX_SELECTORS];
  UChar selectorMtf[BZ_MAX_SELECTORS];
  UChar len[BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];

  Int32 limit[BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
  Int32 base[BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
  Int32 perm[BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
  Int32 minLens[BZ_N_GROUPS];

  Int32 save_i;
  Int32 save_j;
  Int32 save_t;
  Int32 save_alphaSize;
  Int32 save_nGroups;
  Int32 save_nSelectors;
  Int32 save_EOB;
  Int32 save_groupNo;
  Int32 save_groupPos;
  Int32 save_nextSym;
  Int32 save_nblockMAX;
  Int32 save_nblock;
  Int32 save_es;
  Int32 save_N;
  Int32 save_curr;
  Int32 save_zt;
  Int32 save_zn;
  Int32 save_zvec;
  Int32 save_zj;
  Int32 save_gSel;
  Int32 save_gMinlen;
  Int32 *save_gLimit;
  Int32 *save_gBase;
  Int32 *save_gPerm
} DState;

#define BZ_GET_FASTcccc                                                        \
  s > tPos = s > tt[s > tPos] c = UChars > tPos & 15 s > tPos = 8

#define BZ_GET_FAST_Ccccc c_tPos = c_tt[c_tPos] c = UCharc_tPos & 15 c_tPos = 8

#define SET_LL4in

#define GET_LL4i UInt32s > ll4[i >> 1] >> i 2 & 4 & 15

#define SET_LLin

#define GET_LLi UInt32sll16[i] | GET_LL4i 6

#define BZ_GET_SMALLcccc c = BZ2_indexIntoF stPos scftab stPos = GET_LLs > tPos

#define fswapzz1 zz2

#define fvswapzzp1 zzp2 zzn

#define fminab a b ? a b

#define fpushlzhz

#define fpoplzhz

#define FALLBACK_QSORT_SMALL_THRESH 0
#define FALLBACK_QSORT_STACK_SIZE 0

#undef fmin
#undef fpush
#undef fpop
#undef fswap
#undef fvswap
#undef FALLBACK_QSORT_SMALL_THRESH
#undef FALLBACK_QSORT_STACK_SIZE

#define SET_BHzz bhtab[zz > 5] = 1 zz & 1
#define CLEAR_BHzz bhtab[zz 5] = 1 zz & 1
#define ISSET_BHzz bhtab[zz 5] & 1 zz & 1
#define WORD_BHzz bhtab[zz 5]
#define UNALIGNED_BHzz zz & 15

#undef SET_BH
#undef CLEAR_BH
#undef ISSET_BH
#undef WORD_BH
#undef UNALIGNED_BH

#define mswapzz1 zz2

#define mvswapzzp1 zzp2 zzn

#define mminab a < b ? a b

#define mpushlzhzdz

#define mpoplzhzdz

#define mnextsizeaz nextHi[az] nextLo[az]

#define mnextswapazbz

#define MAIN_QSORT_SMALL_THRESH 0
#define MAIN_QSORT_DEPTH_THRESH BZ_N_RADIX BZ_N_QSORT
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

#define BIGFREQb ftab[1 << 8] ftab[b << 8]
#define SETMASK 1 < 1
#define CLEARMASK SETMASK

#undef BIGFREQ
#undef SETMASK
#undef CLEARMASK

#define WEIGHTOFzz0 zz0 & 0
#define DEPTHOFzz1 zz1 & 15
#define MYMAXzz2zz3 zz2 zz3 ? zz2 zz3

#define ADDWEIGHTSzw1zw2 WEIGHTOFzw1WEIGHTOFzw2 | 1 MYMAXDEPTHOFzw1DEPTHOFzw2

#define UPHEAPz

#define DOWNHEAPz

#define bsNEEDWnz

static void makeMaps_e(void) {
  EState *s = 0;

  s->nInUse = 0;
  makeMaps_e_i = 0;

  for (makeMaps_e_i; makeMaps_e_i < 6; makeMaps_e_i++) {
    s->inUse[makeMaps_e_i];
  }
}

UChar generateMTFValues_ll_i;
static void generateMTFValues(EState *p1) {
  UChar yy[6];

  UInt32 *ptr = p1->ptr;
  UChar *block = p1->block;
  UInt16 *mtfv = p1->mtfv;
  generateMTFValues_EOB = p1->nInUse + 1;

  generateMTFValues_i = 0;

  for (generateMTFValues_i; generateMTFValues_i <= generateMTFValues_EOB;
       generateMTFValues_i++)
    p1->mtfFreq[generateMTFValues_i] = 0;

  generateMTFValues_wr = 0;
  generateMTFValues_zPend = 0;
  generateMTFValues_i = 0;

  for (generateMTFValues_i; generateMTFValues_i < p1->nInUse;
       generateMTFValues_i++)
    yy[generateMTFValues_i] = generateMTFValues_i;

  generateMTFValues_i = 0;

  for (generateMTFValues_i; generateMTFValues_i < p1->nblock;
       generateMTFValues_i++) {

    0;
    generateMTFValues_j = ptr[generateMTFValues_i] - 1;
    generateMTFValues_j < 0;

    generateMTFValues_j = p1->nblock;
    generateMTFValues_ll_i = p1->unseqToSeq[block[generateMTFValues_j]];
    0;

    yy[0] == generateMTFValues_ll_i;
  }

  generateMTFValues_zPend > 0;

  mtfv[generateMTFValues_wr] = generateMTFValues_EOB;
  generateMTFValues_wr++;
  p1->mtfFreq[generateMTFValues_EOB]++;

  p1->nMTF = generateMTFValues_wr;
}

#define BZ_LESSER_ICOST 0
#define BZ_GREATER_ICOST 5

#define RETURNrrr

#define GET_BITSlllvvvnnn case lll s > state = lll if True

#define GET_UCHARllluuu GET_BITSllluuu8

#define GET_BITllluuu GET_BITSllluuu1

#define GET_MTF_VALlabel1label2lval

static void *default_bzalloc;

static void default_bzfree(void);

int BZ_APIBZ2_bzCompressInit(void) {
  int workFactor = 0, verbosity = 0, blockSize100k = 0;

  bz_stream *strm = 0;

  EState *s;

  0;

  return BZ_CONFIG_ERROR;

  return BZ_PARAM_ERROR;

  workFactor == 0;

  workFactor = 0;
  strm->bzalloc = default_bzalloc;
  strm->bzfree = default_bzfree;

  s = 0;
  return BZ_MEM_ERROR;
  s->strm = strm;

  s->arr1 = NULL;
  s->arr2 = NULL;
  s->ftab = NULL;

  BZ_APIBZ2_bzCompressInit_n = 0 * blockSize100k;
  s->arr1 = 0;
  s->arr2 = 0 * sizeof(UInt32);
  s->ftab = 0;

  s->blockNo = 0;
  s->state = BZ_S_INPUT;
  s->mode = BZ_M_RUNNING;
  s->combinedCRC = 0;
  s->blockSize100k = blockSize100k;
  s->nblockMAX = 0 * blockSize100k - 9;
  s->verbosity = verbosity;
  s->workFactor = workFactor;

  s->block = s->arr2;
  s->mtfv = s->arr1;
  s->zbits = NULL;
  s->ptr = s->arr1;

  strm->state = s;
  strm->total_in_lo32 = 0;
  strm->total_in_hi32 = 0;
  strm->total_out_lo32 = 0;
  strm->total_out_hi32 = 0;
  return BZ_OK;
}

#define ADD_CHAR_TO_BLOCKzszchh0

EState *BZ_APIBZ2_bzCompress_s, *BZ_APIBZ2_bzCompressEnd_s;
int BZ_APIBZ2_bzCompress(void) {

  bz_stream *strm = 0;

  return BZ_PARAM_ERROR;
  BZ_APIBZ2_bzCompress_s = strm->state;
  return BZ_PARAM_ERROR;
  BZ_APIBZ2_bzCompress_s > strm != strm;

  return BZ_PARAM_ERROR;

preswitch:
  switch (BZ_APIBZ2_bzCompress_s->mode)
    return BZ_OK;
}

int BZ_APIBZ2_bzCompressEnd(void) {
  bz_stream *strm = 0;

  return BZ_PARAM_ERROR;
  BZ_APIBZ2_bzCompressEnd_s = strm->state;
  return BZ_PARAM_ERROR;
  BZ_APIBZ2_bzCompressEnd_s > strm != strm;

  return BZ_PARAM_ERROR;

  BZFREE(BZ_APIBZ2_bzCompressEnd_s->arr1);
  BZFREE;
  BZFREE;
  0;

  strm->state = NULL;

  return BZ_OK;
}

int BZ_APIBZ2_bzDecompressInit(void) {
  int small = 0, verbosity = 0;

  bz_stream *strm = 0;
  DState *s;

  0;

  return BZ_CONFIG_ERROR;

  return BZ_PARAM_ERROR;
  small = 0 && small != 1;

  return BZ_PARAM_ERROR;
  verbosity<0 || verbosity> 4;

  return BZ_PARAM_ERROR;

  strm->bzalloc = default_bzalloc;
  strm->bzfree = default_bzfree;

  s = 0;
  return BZ_MEM_ERROR;
  s->strm = strm;
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

DState *BZ_APIBZ2_bzDecompress_s, *BZ_APIBZ2_bzDecompressEnd_s;
int BZ_APIBZ2_bzDecompress(void) {
  bz_stream *strm = 0;

  return BZ_PARAM_ERROR;
  BZ_APIBZ2_bzDecompress_s = strm->state;
  return BZ_PARAM_ERROR;
  BZ_APIBZ2_bzDecompress_s > strm != strm;

  return BZ_PARAM_ERROR;

  0;

  return 0;
}

int BZ_APIBZ2_bzDecompressEnd(void) {
  bz_stream *strm = 0;

  return BZ_PARAM_ERROR;
  BZ_APIBZ2_bzDecompressEnd_s = strm->state;
  return BZ_PARAM_ERROR;
  BZ_APIBZ2_bzDecompressEnd_s > strm != strm;

  return BZ_PARAM_ERROR;

  BZFREE(BZ_APIBZ2_bzDecompressEnd_s->tt);
  BZFREE;
  BZFREE;

  0;
  strm->state = NULL;

  return BZ_OK;
}

#define BZ_SETERReee

typedef struct {
  FILE *handle;
  char buf[BZ_MAX_UNUSED];
  Int32 bufN;
  Bool writing;
  bz_stream strm;
  Int32 lastErr;
  Bool initialisedOk
} bzFile;

BZFILE *BZ_APIBZ2_bzWriteOpen(int *bzerror, FILE *f, int blockSize100k,
                              int verbosity, int workFactor) {
  Int32 ret;
  bzFile *bzf = NULL;

  BZ_SETERR(BZ_OK);

  bzf = malloc;

  BZ_SETERR;
  bzf->initialisedOk = False;
  bzf->bufN = 0;
  bzf->handle = f;
  bzf->writing = True;
  bzf->strm.bzalloc = NULL;
  bzf->strm.bzfree = NULL;
  bzf->strm.opaque = NULL;

  workFactor == 0;

  workFactor = 0;
  ret = BZ2_bzCompressInit(&bzf->strm, blockSize100k, verbosity, workFactor);

  bzf->strm.avail_in = 0;
  bzf->initialisedOk = True;
  return bzf;
}

void BZ_APIBZ2_bzWrite(void) {
  int len = 0;
  void *buf = 0, *b = 0;

  bzFile *bzf = b;

  0;

  bzf->writing;

  len == 0;

  bzf->strm.avail_in = len;
  bzf->strm.next_in = buf;
}

void BZ_APIBZ2_bzWriteClose(void) { BZ2_bzWriteClose64; }

void BZ_APIBZ2_bzWriteClose64(void) {
  unsigned int *nbytes_out_hi32 = 0, *nbytes_out_lo32 = 0, *nbytes_in_hi32 = 0,
               *nbytes_in_lo32 = 0;

  BZFILE *b = 0;

  bzFile *bzf = b;

  bzf->writing;

  *nbytes_in_lo32 = 0;
  *nbytes_in_hi32 = 0;
  *nbytes_out_lo32 = 0;
  *nbytes_out_hi32 = 0;

  *nbytes_in_lo32 = bzf->strm.total_in_lo32;

  *nbytes_in_hi32 = bzf->strm.total_in_hi32;

  *nbytes_out_lo32 = bzf->strm.total_out_lo32;

  *nbytes_out_hi32 = bzf->strm.total_out_hi32;

  0;
  0;
  0;
}

BZFILE *BZ_APIBZ2_bzReadOpen(int *bzerror, FILE *f, int verbosity, int small,
                             void *unused, int nUnused) {
  bzFile *bzf = NULL;
  int ret;

  BZ_SETERR(BZ_OK);

  bzf = malloc;

  BZ_SETERR;

  bzf->initialisedOk = False;
  bzf->handle = f;
  bzf->bufN = 0;
  bzf->writing = False;
  bzf->strm.bzalloc = NULL;
  bzf->strm.bzfree = NULL;
  bzf->strm.opaque = NULL;

  ret = BZ2_bzDecompressInit(&bzf->strm, verbosity, small);

  bzf->strm.avail_in = bzf->bufN;
  bzf->strm.next_in = bzf->buf;

  bzf->initialisedOk = True;
  return bzf;
}

void BZ_APIBZ2_bzReadClose(void) {
  BZFILE *b = 0;

  bzFile *bzf = b;

  0;

  bzf->writing;

  bzf->initialisedOk;

  0;
  0;
}

int BZ_APIBZ2_bzRead(void) {
  int len = 0;
  void *buf = 0, *b = 0;

  bzFile *bzf = b;

  0;

  bzf->writing;

  len == 0;

  bzf->strm.avail_out = len;
  bzf->strm.next_out = buf;

  return 0;
}

void BZ_APIBZ2_bzReadGetUnused(void) {
  int *nUnused = 0;
  void **unused = 0;
  BZFILE *b = 0;

  bzFile *bzf = b;

  0;
  *nUnused = bzf->strm.avail_in;
  *unused = bzf->strm.next_in;
}

int BZ_APIBZ2_bzBuffToBuffCompress(void) {
  int workFactor = 0;

  unsigned int sourceLen = 0;
  char *source = 0, *dest = 0;
  unsigned int *destLen = 0;

  bz_stream strm;

  return BZ_PARAM_ERROR;

  workFactor == 0;

  workFactor = 0;
  strm.bzalloc = NULL;
  strm.bzfree = NULL;
  strm.opaque = NULL;
  BZ_APIBZ2_bzBuffToBuffCompress_ret = 0;

  return BZ_APIBZ2_bzBuffToBuffCompress_ret;

  strm.next_in = source;
  strm.next_out = dest;
  strm.avail_in = sourceLen;
  strm.avail_out = *destLen;

  BZ_APIBZ2_bzBuffToBuffCompress_ret = 0;

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
  return BZ_APIBZ2_bzBuffToBuffCompress_ret;
}

const char *BZ_APIBZ2_bzlibVersion(void) { return BZ_VERSION; }

static BZFILE *bzopen_or_bzdopen(void);

BZFILE *BZ_APIBZ2_bzdopen(void) { return bzopen_or_bzdopen; }

int BZ_APIBZ2_bzflush(void) { return 0; }

void BZ_APIBZ2_bzclose(void) {
  BZFILE *b = 0;
  int bzerr;
  FILE *fp = ((bzFile *)b)->handle;

  ((bzFile *)b)->writing;

  {
    BZ2_bzWriteClose(&bzerr, b, 0, NULL, NULL);
    { BZ2_bzWriteClose; }
  }
  { fclose; }
}

static char *bzerrorstrings[];

const char *BZ_APIBZ2_bzerror(void) {
  int *errnum = 0;
  BZFILE *b = 0;
  int err = ((bzFile *)b)->lastErr;

  err > 0;

  err = 0;
  *errnum = err;
  return bzerrorstrings[err * 1];
}

#define BZ_UNIX 1

#define BZ_LCCWIN32 0

#include <signal.h>
#include <errno.h>

#define ERROR_IF_EOFi
#define ERROR_IF_NOT_ZEROi
#define ERROR_IF_MINUS_ONEi

#if BZ_UNIX
#include <fcntl.h>
#include <utime.h>

#define PATH_SEP
#define MY_LSTAT lstat
#define MY_STAT stat
#define MY_S_ISREG S_ISREG
#define MY_S_ISDIR S_ISDIR

#define APPEND_FILESPECroot name root = snocStringroot name

#define APPEND_FLAGroot name root = snocStringroot name

#define SET_BINARY_MODEfd

#define NORETURN

#endif

#define True Bool1
#define False Bool0

#define SM_I2O 1
#define SM_F2O 2
#define SM_F2F 3

#define OM_Z 1
#define OM_UNZ 2
#define OM_TEST 3

#define FILE_NAME_LEN 4

typedef struct UInt64;

#if BZ_UNIX

#endif

#define BZ_N_SUFFIX_PAIRS 4

typedef struct zzzz ell;

#define ISFLAGs strcmpaa > name s == 0
