
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
  ;

} bz_stream, default_bzfree_strm, default_bzfree_s_0, BZ_APIBZ2_bzCompress_strm,
    BZ_APIBZ2_bzCompress_s_0, BZ_APIBZ2_bzCompressEnd_strm,
    BZ_APIBZ2_bzCompressEnd_s_0, BZ_APIBZ2_bzDecompressInit_strm,
    BZ_APIBZ2_bzDecompressInit_s_0, BZ_APIBZ2_bzDecompress_strm,
    BZ_APIBZ2_bzDecompress_s_0, BZ_APIBZ2_bzDecompressEnd_strm,
    BZ_APIBZ2_bzDecompressEnd_s_0, BZ_APIBZ2_bzBuffToBuffCompress_strm,
    BZ_APIBZ2_bzBuffToBuffDecompress_strm;

#include <stdio.h>

#define BZ_API
#define BZ_EXTERN

BZ_EXTERN BZ_EXTERN void;

#define BZ_MAX_UNUSED 0

typedef BZFILE;

int BZ_APIBZ2_bzerror_errnum, BZ_APIBZ2_bzerror_b,
    makeMaps_e_i = 0, generateMTFValues_s_0_0, generateMTFValues_yy_1,
    generateMTFValues_yy_0, generateMTFValues_i, generateMTFValues_j,
    generateMTFValues_zPend, generateMTFValues_wr, generateMTFValues_EOB,
    generateMTFValues_ptr_0, generateMTFValues_block_0, default_bzalloc,
    default_bzfree_workFactor, default_bzfree_verbosity,
    default_bzfree_blockSize100k, default_bzfree_n, default_bzfree_s_8,
    default_bzfree_s_10, default_bzfree_s_9, default_bzfree_s_12,
    default_bzfree_s_28, default_bzfree_s_18, default_bzfree_s_30,
    default_bzfree_s_27, default_bzfree_s_1, default_bzfree_s_2,
    default_bzfree_s_6, default_bzfree_s_5, BZ_APIBZ2_bzCompress_s_1,
    BZ_APIBZ2_bzDecompressInit_verbosity, BZ_APIBZ2_bzDecompressInit_s_12,
    BZ_APIBZ2_bzDecompressInit_s_11, BZ_APIBZ2_bzDecompressInit_s_10,
    BZ_APIBZ2_bzDecompressInit_s_26, BZ_APIBZ2_bzDecompressInit_s_7,
    BZ_APIBZ2_bzDecompressInit_s_8, BZ_APIBZ2_bzDecompressInit_s_1,
    BZ_APIBZ2_bzWrite_len, BZ_APIBZ2_bzWrite_b = 0, BZ_APIBZ2_bzWrite_ret,
    BZ_APIBZ2_bzWrite_bzf_4_5, BZ_APIBZ2_bzWrite_bzf_4_1,
    BZ_APIBZ2_bzWrite_bzf_3, BZ_APIBZ2_bzWriteClose,
    BZ_APIBZ2_bzWriteClose64_nbytes_out_hi32,
    BZ_APIBZ2_bzWriteClose64_nbytes_out_lo32,
    BZ_APIBZ2_bzWriteClose64_nbytes_in_hi32, BZ_APIBZ2_bzWriteClose64_abandon,
    BZ_APIBZ2_bzWriteClose64_b = 0, BZ_APIBZ2_bzReadClose_b,
    BZ_APIBZ2_bzReadClose_bzf_6, BZ_APIBZ2_bzReadClose_bzf_3,
    BZ_APIBZ2_bzRead_len, BZ_APIBZ2_bzRead_b, BZ_APIBZ2_bzRead_bzf_4_5,
    BZ_APIBZ2_bzRead_bzf_3, BZ_APIBZ2_bzReadGetUnused_nUnused,
    BZ_APIBZ2_bzReadGetUnused_b, BZ_APIBZ2_bzBuffToBuffCompress_workFactor,
    BZ_APIBZ2_bzBuffToBuffCompress_verbosity,
    BZ_APIBZ2_bzBuffToBuffCompress_blockSize100k,
    BZ_APIBZ2_bzBuffToBuffCompress_sourceLen,
    BZ_APIBZ2_bzBuffToBuffCompress_destLen,
    BZ_APIBZ2_bzBuffToBuffCompress_strm_5,
    BZ_APIBZ2_bzBuffToBuffCompress_strm_1, BZ_APIBZ2_bzBuffToBuffCompress_ret,
    BZ_APIBZ2_bzBuffToBuffDecompress_verbosity,
    BZ_APIBZ2_bzBuffToBuffDecompress_small,
    BZ_APIBZ2_bzBuffToBuffDecompress_sourceLen,
    BZ_APIBZ2_bzBuffToBuffDecompress_destLen,
    BZ_APIBZ2_bzBuffToBuffDecompress_strm_5,
    BZ_APIBZ2_bzBuffToBuffDecompress_strm_1,
    BZ_APIBZ2_bzBuffToBuffDecompress_ret, bzopen_or_bzdopen,
    BZ_APIBZ2_bzread_nread, BZ_APIBZ2_bzwrite_len, BZ_APIBZ2_bzclose_bzerr,
    bzerrorstrings_0;
typedef Char;
typedef Bool;
typedef UChar;
typedef Int32;
typedef UInt32;
typedef UInt16;
void *BZ_APIBZ2_bzWrite_buf, *BZ_APIBZ2_bzRead_buf,
    *BZ_APIBZ2_bzReadGetUnused_unused;
char BZ_APIBZ2_bzWrite_bzf_4_4, BZ_APIBZ2_bzWrite_bzf_4_0,
    BZ_APIBZ2_bzRead_bzf_4_4, BZ_APIBZ2_bzReadGetUnused_bzf_4_0,
    BZ_APIBZ2_bzBuffToBuffCompress_source, BZ_APIBZ2_bzBuffToBuffCompress_dest,
    BZ_APIBZ2_bzBuffToBuffCompress_strm_4,
    BZ_APIBZ2_bzBuffToBuffCompress_strm_0,
    BZ_APIBZ2_bzBuffToBuffDecompress_source,
    BZ_APIBZ2_bzBuffToBuffDecompress_dest,
    BZ_APIBZ2_bzBuffToBuffDecompress_strm_4,
    BZ_APIBZ2_bzBuffToBuffDecompress_strm_0;
*fn1(int *, FILE *, int, int, void *, int);

void;

void;

BZ_EXTERN *fn2(int *, FILE *, int, int, int);

void;

void(fn3)(unsigned int);

BZ_EXTERN BZ_EXTERN void fn4();
void fn4() {}

void fn5();
void fn5() {}

BZ_EXTERN void;

void fn6();

void fn6() {

  int err = (BZ_APIBZ2_bzerror_b);

  ;
}

#include <stdlib.h>

#define BZ_VERSION ""

#define True 1
#define False 0

#

#define AssertD

#define zf
#define zf
#define za1
#define za2
#define za3
#define za4

#define nnn
#define ppp

#define BZ_MAX_ALPHA_SIZE 8

#define BZ_N_GROUPS 6
#define BZ_G_SIZE 50

#define BZ_MAX_SELECTORS BZ_G_SIZE

#define BZ_RAND_DECLS

#define srNToGo

#define BZ_RAND_UPD_MASK

#

#define BZ_M_RUNNING 2

#define BZ_S_INPUT 2

#define BZ_N_SHELL

typedef struct {

  ;

  Int32 mtfFreq[BZ_MAX_ALPHA_SIZE];
  UChar;
  UChar;

} EState;

#define BZ_X_MAGIC_1 0

#define MTFA_SIZE 4096
#define MTFL_SIZE 6

typedef struct {

  Int32;
  ;
  Int32;
  Int32;

  Bool;
  Bool;
  UChar;

  UChar;

} DState, BZ_APIBZ2_bzDecompressInit_s, BZ_APIBZ2_bzDecompress_s,
    BZ_APIBZ2_bzDecompressEnd_s;

#define stPos

#define                                                                        \
                                                                               \
    c_tPos

#

#define ll4i

#

#define zzn

#define a
#

#

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
#define zz2

#define MYMAXDEPTHOFzw1

EState makeMaps_e_s, generateMTFValues_s, BZ_APIBZ2_bzCompress_s,
    BZ_APIBZ2_bzCompressEnd_s;

void fn7() {

  for (;;) {
    &makeMaps_e_s;
  }
}

fn8() {

  UInt16 mtfv_0 = generateMTFValues_i;

  for (;;)
    generateMTFValues_s_0_0;

  for (;;)

    for (;;)

      ;
  generateMTFValues_s.mtfFreq;

  generateMTFValues_wr;
}

#define lll

#define uuu

#define uuu

#define lval

fn9() {

  EState *s;

  UInt32 s_4;

  if (0)

    if (bzalloc NULL)
      default_bzalloc;
  if (bzfree NULL)

    0;
  if (NULL)

    arr1 NULL;
  arr2 NULL;
  ftab NULL * 0 * sizeof(UInt32);

  if (NULL)

    s_4 = s = 0;
  0;

  return BZ_OK;
}

#

int fn10() {

  if (NULL)

    ;
  if (NULL)

    return BZ_OK;
}

fn11() {

  if (NULL)

    ;
  if (NULL)

    ;

  if (arr1 NULL)
    BZFREE(arr1);
  if (arr2 NULL)

    if (ftab NULL)

      ;
}

fn12() {
  int small;

  if (NULL)

    ;

  if (bzalloc NULL)
    default_bzalloc;
  if (bzfree NULL)

    0;
  if (NULL)

    0;
  0;
  0;
  0;

  small = ll16 NULL;
  tt NULL;
}

fn13() {

  if (NULL)

    ;
  if (NULL)

    ;

  ;
}

fn14() {

  if (NULL)

    ;
  if (NULL)

    ;

  if (tt NULL)
    BZFREE(tt);
  if (ll16 NULL)

    if (ll4 NULL)

      ;
}

typedef struct {

} bzFile, BZ_APIBZ2_bzWrite_bzf, BZ_APIBZ2_bzReadClose_bzf,
    BZ_APIBZ2_bzRead_bzf, BZ_APIBZ2_bzReadGetUnused_bzf;

*fn15(int *bzerror, FILE *f, int blockSize100k, int verbosity, int workFactor) {
  Int32 ret;
  bzFile *bzf;

  fn16(verbosity);

  fn16;
  False;
  0;
  f = bzf = (workFactor);

  bzf;
}

fn17() { ; }

fn18() {

  int nbytes_in_lo32;

  bzFile bzf;
  fn19();

  if (NULL)

    if (NULL)

      if (NULL)

        if (NULL)

          if (nbytes_in_lo32)
            bzf;
  if (NULL)
    bzf;
  if (NULL)
    bzf;
  if (NULL)
    bzf;
}

*fn20(int *bzerror, FILE *f, int verbosity, int small, void *unused,
      int nUnused) {
  bzFile *bzf;
  char bzf_4_0;
  int bzf_4_1, bzf_3, bzf_2, bzf_6, ret;

  fn16(nUnused);

  False;

  False;
  bzf = NULL;

  while (0)

    fn21(verbosity);

  ;
}

fn22() { ; }

fn23() {

  ;

  return 0;
}

fn24() {

  fn25();

  ;

  ;
}

fn26() {

  if (0)

    bzalloc NULL;
  bzfree NULL;
  opaque NULL;

  return 0;
}

fn27() {

  if (4)

    bzalloc NULL;
  bzfree NULL;
  opaque NULL;

  return BZ_APIBZ2_bzBuffToBuffDecompress_strm_5;
}

fn28() {}

fn29() {}

fn30() {

  int bzerr;
  if (bzerr == BZ_OK) {
  }
}

fn31() {}

fn32() {
  BZFILE b;

  FILE *fp = (b);

  if ((b))
    if (stdout)
      ;
}

#include <signal.h>
#include <errno.h>

#include <fcntl.h>
#include <utime.h>

#define snocStringroot

#define snocStringroot

;

#define s
