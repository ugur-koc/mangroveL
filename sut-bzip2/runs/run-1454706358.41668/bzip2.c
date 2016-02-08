
#define BZ_OK 0
#define BZ_RUN_OK 1

#define BZ_FINISH_OK 3
#define BZ_STREAM_END 4
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
  int avail_in;
  int total_in_lo32;
  int total_in_hi32;
  int total_out_lo32;
  int total_out_hi32;

  void *state;

  void (*bzalloc)();
  void (*bzfree)(void);
  void *opaque
} bz_stream, *BZ_APIBZ2_bzCompressEnd_strm, *BZ_APIBZ2_bzDecompressInit_strm;

#include <stdio.h>

#define BZ_API
#define BZ_EXTERN

typedef BZFILE;
int BZ_APIBZ2_bzBuffToBuffDecompress_verbosity, BZ_APIBZ2_bzwrite_len,
    BZ_APIBZ2_bzCompressInit_workFactor, BZ_APIBZ2_bzCompress_action,
    BZ_APIBZ2_bzDecompressInit_verbosity, BZ_APIBZ2_bzDecompressInit_small,
    BZ_APIBZ2_bzWrite_len, BZ_APIBZ2_bzWriteClose64_abandon,
    BZ_APIBZ2_bzRead_len, BZ_APIBZ2_bzBuffToBuffCompress_workFactor,
    BZ_APIBZ2_bzread_len, bzerrorstrings_0;
typedef Bool;
typedef Int32;
typedef UInt32;
;

#define lll

#define GET_BITSllluuu8

#define GET_BITSllluuu1

#define lval

int *BZ_APIBZ2_bzWriteClose64_nbytes_in_lo32,
    *BZ_APIBZ2_bzWriteClose64_nbytes_in_hi32,
    *BZ_APIBZ2_bzWriteClose64_nbytes_out_lo32,
    *BZ_APIBZ2_bzWriteClose64_nbytes_out_hi32, *bzerrorstrings = {

                                                   ""};
static default_bzalloc(Int32);
BZ_APIBZ2_bzCompressInit(bz_stream *, int, int p3);

BZ_APIBZ2_bzCompress(bz_stream *p1);

strm(int);

BZ_APIBZ2_bzDecompress();

BZ_APIBZ2_bzDecompressEnd();

#define BZ_MAX_UNUSED 0

*BZ_APIBZ2_bzReadOpen(int *, FILE *, int, int, void *, int);

void BZ_APIBZ2_bzReadClose(int *, BZFILE *);

void BZ_APIBZ2_bzReadGetUnused(int *, BZFILE *, void **, int *);

BZ_APIBZ2_bzRead(int *, BZFILE *, void *p3);

*BZ_APIBZ2_bzWriteOpen(int *, FILE *, int, int, int);

void BZ_APIBZ2_bzWrite(int *, BZFILE *, void *p3);

void BZ_APIBZ2_bzWriteClose(int *, BZFILE *, int, unsigned *, unsigned *);

BZ2_bzWriteClose64(int, BZFILE, int, int, int, int, int);

BZ_APIBZ2_bzBuffToBuffCompress(char *, unsigned *, char *, unsigned, int,
                               int p6);

BZ_APIBZ2_bzBuffToBuffDecompress(char *, unsigned *, char *, unsigned, int p5);

BZ_APIBZ2_bzBuffToBuffDecompress(char *p1, unsigned *p2, char *p3, unsigned p4,
                                 int p5) {
  bz_stream strm;
  int strm_5, strm_1, ret;

  char strm_4, strm_0;

  if (4)

    bzalloc NULL;
  bzfree NULL;
  opaque NULL;
  if (BZ_OK)

    0;
  if (BZ_OK)
    ;
  if (BZ_STREAM_END)

    if (0) {
    }
}

const char *BZ_APIBZ2_bzlibVersion();

*BZ_APIBZ2_bzopen(const char *, const char *);
*BZ_APIBZ2_bzopen(const char *p1, const char *p2){

}

    * BZ_APIBZ2_bzdopen(int, const char *);

BZ_APIBZ2_bzread(BZFILE *, void *p2);

BZ_APIBZ2_bzwrite(BZFILE *, void *p2);

BZ_APIBZ2_bzwrite(BZFILE *p1, void *p2) {
  int bzerr;
  if (BZ_OK) {
  }
}

b();

void BZ_APIBZ2_bzclose();

const char *BZ_APIBZ2_bzerror(BZFILE *, int *);

#include <stdlib.h>

#define BZ_VERSION ""

#define True 1
#define False 0

#

#

#define zf
#define za1
#define za2
#define za3
#define za4
#define za5

#define opaquennn1
#define opaqueppp

#define BZ_MAX_ALPHA_SIZE 8

#define BZ_N_GROUPS 6
#define BZ_G_SIZE 50

#define BZ_MAX_SELECTORS BZ_G_SIZE

#define BZ_RAND_DECLS

#define srNToGo

#define BZ_RAND_UPD_MASK

#

#

#define BZ_M_RUNNING 2

#define BZ_S_INPUT 2

#define BZ_N_RADIX
#define BZ_N_QSORT
#define BZ_N_SHELL
#define BZ_N_OVERSHOOT 2

typedef struct {

  ;

  UInt32 arr1;
  UInt32 arr2;
  UInt32 ftab;

  UInt32 ptr;
  char block;
  short mtfv;
  char zbits;

  Int32 nblock;

  Int32 nInUse;
  Bool inUse[6];
  char unseqToSeq[6];
  Int32 blockNo;

  Int32 nMTF;
  Int32 mtfFreq[BZ_MAX_ALPHA_SIZE];
  char;
  char;

  char len
} EState;

#define BZ_X_MAGIC_1 0

#define MTFA_SIZE 4096
#define MTFL_SIZE 6

typedef struct {

  char;
  ;
  Int32;
  Int32;

  UInt32 tt;

  short ll16;
  char ll4;
  Bool;
  Bool;
  char;

  char;
  Int32
      mtfbase[MTFL_SIZE][BZ_MAX_SELECTORS][BZ_MAX_SELECTORS][BZ_MAX_ALPHA_SIZE];

} DState;

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

#define ftabb1
# 1
#

#

#define zz0
#define zz1
#define zz3

#define WEIGHTOFzw1WEIGHTOFzw2

#

EState *makeMaps_e_s, *generateMTFValues_s;
makeMaps_e(void) {
  Int32 i = 0;
  for (;; makeMaps_e_s) {
    makeMaps_e_s->unseqToSeq[i]++;
  }
}

generateMTFValues(void) {

  char yy_1;
  unsigned char yy_0;
  Int32 i, j, zPend, wr, EOB, ptr_0;

  unsigned block_0, mtfv_0 = +1;

  for (;;)
    generateMTFValues_s->mtfFreq[i];
  for (;;)
    i;

  for (;;) {
    char ll_i;
    ("") - 1;
    if (0)
      generateMTFValues_s;
    ("");

    if (ll_i) {
    }
    {

      if (0) {
        char rtmp, rll_i;
        unsigned char *ryy_j;

        (rtmp);
        ;
        generateMTFValues_s->mtfFreq[1];
      }
    }
  }

  if (0)

    ;
  generateMTFValues_s->mtfFreq;

  wr;
}

default_bzfree(void);

s();

BZ_APIBZ2_bzCompressInit(bz_stream *p1, int p2, int p3) {
  Int32 n, s_8, s_12, s_28, s_18, s_30, s_27, s_1, s_2, s_6, s_5, s_4;
  EState *s;

  short s_10;
  char s_9;

  bz_stream *s_0;

  if (0)

    if (0)

      if (0)
        if (bzalloc NULL)
          default_bzalloc;
  if (bzfree NULL)

    BZALLOC();
  if (NULL)

    arr1 NULL;
  arr2 NULL;
  ftab NULL *BZALLOC();
  +sizeof(UInt32);
  (sizeof(UInt32));

  if (NULL)

    (char)(short)s_4;
  zbits NULL;
  s_4 = 0;
  0;
  0;

  return BZ_OK;
}

#

handle_compress();

BZ_APIBZ2_bzCompress(bz_stream *p1) {

  EState *s;
  Int32 s_1;
  bz_stream *s_0;
  if (NULL)
    ;
  if (NULL)
    if (strm)

      return BZ_OK;
}

BZ_APIBZ2_bzCompressEnd(void) {
  EState *s;
  bz_stream *s_0;
  if (NULL)
    ;
  if (NULL)
    if (strm)

      if (arr1 NULL)
        (arr1);
  if (arr2 NULL)
    (arr2);
  if (ftab NULL)
    (ftab)();

  ;
}

BZ_APIBZ2_bzDecompressInit(void) {
  DState *s;
  Int32 s_12, s_11, s_10, s_26, s_7, s_8, s_1;

  bz_stream *s_0;

  if (0)

    if (NULL)
      if (1)
        if (4)

          if (bzalloc NULL)
            default_bzalloc;
  if (bzfree NULL)

    BZALLOC();
  if (NULL)

    0;
  0;
  0;
  0;

  ;
  ll4 NULL;
  ll16 NULL;
  tt NULL;
}

unRLE_obuf_to_output_FAST();

BZ_APIBZ2_bzDecompress(bz_stream *p1) {
  DState *s;
  bz_stream *s_0;
  if (NULL)
    ;
  if (NULL)
    if (strm)

      AssertH();
}

BZ_APIBZ2_bzDecompressEnd(bz_stream *p1) {
  DState *s;
  bz_stream *s_0;
  if (NULL)
    ;
  if (NULL)
    if (strm)

      if (tt NULL)
        (tt);
  if (ll16 NULL)
    (ll16);
  if (ll4 NULL)
    (ll4)();
  ;
}

typedef struct {
  FILE *handle;
  char buf;
  Int32 bufN;
  Bool writing;
  bz_stream strm;
  Int32 lastErr;
  Bool initialisedOk
} bzFile;

*BZ_APIBZ2_bzWriteOpen(int *bzerror, FILE *f, int blockSize100k, int verbosity,
                       int workFactor) {
  Int32 ret;
  bzFile *bzf;

  (4);

  (f) = (sizeof(bzFile));
  (NULL);

  BZ_OK;
  False;
  0;
  f = bzf = NULL;

  if (0)
    (workFactor);
  (BZ_OK);

  bzf;
}

void BZ_APIBZ2_bzWrite(int *p1, BZFILE *p2, void *p3) {
  Int32 ret, bzf_4_5, bzf_4_1;
  bzFile *bzf = *p2;
  char bzf_4_4, bzf_4_0;

  0;

  ;
  ((bzf));

  (0);

  {

    if (bzf_4_1)
      ;
  }
}

void BZ_APIBZ2_bzWriteClose(int *p1, BZFILE *p2, int p3, unsigned *p4,
                            unsigned *p5) {
  (NULL);
}

BZ_APIBZ2_bzWriteClose64(void) {

  bzFile *bzf = *b;
  0;
  ((bzf));

  if (NULL)
    if (NULL)
      if (NULL)
        if (NULL)

          if (ferror(bzf) != NULL)
            bzf;
  if (NULL)
    bzf;
  if (NULL)
    bzf;
  if (NULL)
    bzf;

  ;
}

*BZ_APIBZ2_bzReadOpen(int *bzerror, FILE *f, int verbosity, int small,
                      void *unused, int nUnused) {
  bzFile *bzf;
  char bzf_4_0;
  int bzf_4_1, bzf_3, bzf_2, bzf_6, ret;

  (BZ_MAX_UNUSED);

  (f) = (sizeof(bzFile));
  (NULL);

  ;

  False;
  bzf = NULL;

  while (0)

    (small);
  (BZ_OK);

  bzf;
}

void BZ_APIBZ2_bzReadClose(int *p1, BZFILE *p2) {
  bzFile *bzf = *p2;
  Bool bzf_6;
  bzf_3(bzf);

  bzf_3;

  ;
}

BZ_APIBZ2_bzRead(int *p1, BZFILE *p2, void *p3) {

  bzFile *bzf = *p2;
  char bzf_4_4;
  int bzf_4_5;
  0;

  return 0;
}

void BZ_APIBZ2_bzReadGetUnused(int *p1, BZFILE *p2, void **p3, int *p4) {
  bzFile *bzf = *p2;
  char bzf_4_0;
  int bzf_4_1;
  0;
  (BZ_STREAM_END);
  (NULL);

  ;
}

BZ_APIBZ2_bzBuffToBuffCompress(char *p1, unsigned *p2, char *p3, unsigned p4,
                               int p5, int p6) {
  bz_stream strm;
  int strm_5, strm_1, ret;

  char strm_4, strm_0;

  if (0)

    if (0)
      bzalloc NULL;
  bzfree NULL;
  opaque NULL;
  if (BZ_OK)

    0;
  if (BZ_FINISH_OK)
    ;
  if (BZ_STREAM_END)

    ret;
}

const char *BZ_APIBZ2_bzlibVersion() {}

bzopen_or_bzdopen(char, int, char, int);

*BZ_APIBZ2_bzdopen(int p1, const char *p2) { (1); }

BZ_APIBZ2_bzread(BZFILE *p1, void *p2) {
  int bzerr, nread;
  if (((bzFile *)p1))

    if (bzerr == BZ_STREAM_END) {

      ;
    }
}

void BZ_APIBZ2_bzclose(p1) {
  int bzerr;
  FILE *fp = ((bzFile *)b);

  if (((bzFile *)p1)) {
    (NULL);
    if (BZ_OK) {
      (NULL);
    }
  }
  if (stdout) {
    fp;
  }
}

const char *BZ_APIBZ2_bzerror(BZFILE *p1, int *p2) {
  int err = ((bzFile *)p1);

  if (0)

    bzerrorstrings_0;
}

#include <signal.h>
#include <errno.h>

#include <fcntl.h>
#include <utime.h>

#define name

#define name

#define s0

main(int, char *[]);
