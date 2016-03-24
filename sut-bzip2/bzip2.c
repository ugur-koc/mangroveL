 

#define _BZLIB_H

#define BZ_RUN               0
#define BZ_FLUSH             1
#define BZ_FINISH            2

#define BZ_OK                0
#define BZ_RUN_OK            1
#define BZ_FLUSH_OK          2
#define BZ_FINISH_OK         3
#define BZ_STREAM_END        4
#define BZ_SEQUENCE_ERROR    (-1)
#define BZ_PARAM_ERROR       (-2)
#define BZ_MEM_ERROR         (-3)
#define BZ_DATA_ERROR        (-4)
#define BZ_DATA_ERROR_MAGIC  (-5)
#define BZ_IO_ERROR          (-6)
#define BZ_UNEXPECTED_EOF    (-7)
#define BZ_OUTBUFF_FULL      (-8)
#define BZ_CONFIG_ERROR      (-9)

typedef 
   struct {
      char *next_in;
      unsigned int avail_in;
      unsigned int total_in_lo32;
      unsigned int total_in_hi32;

      char *next_out;
      unsigned int avail_out;
      unsigned int total_out_lo32;
      unsigned int total_out_hi32;

      void *state;

      void *(*bzalloc)(void *,int,int);
      void (*bzfree)(void *,void *);
      void *opaque;
   } 
   bz_stream;

#include <stdio.h>

#   define BZ_API(func) func
#   define BZ_EXTERN extern
BZ_EXTERN int BZ_API(BZ2_bzCompressInit) ( 
      bz_stream* strm, 
      int        blockSize100k, 
      int        verbosity, 
      int        workFactor 
   );

BZ_EXTERN int BZ_API(BZ2_bzCompress) ( 
      bz_stream* strm, 
      int action 
   );

BZ_EXTERN int BZ_API(BZ2_bzCompressEnd) ( 
      bz_stream* strm 
   );

BZ_EXTERN int BZ_API(BZ2_bzDecompressInit) ( 
      bz_stream *strm, 
      int       verbosity, 
      int       small
   );

BZ_EXTERN int BZ_API(BZ2_bzDecompress) ( 
      bz_stream* strm 
   );

BZ_EXTERN int BZ_API(BZ2_bzDecompressEnd) ( 
      bz_stream *strm 
   );

#define BZ_MAX_UNUSED 5000

typedef void BZFILE;

BZ_EXTERN BZFILE* BZ_API(BZ2_bzReadOpen) ( 
      int*  bzerror,   
      FILE* f, 
      int   verbosity, 
      int   small,
      void* unused,    
      int   nUnused 
   );

BZ_EXTERN void BZ_API(BZ2_bzReadClose) ( 
      int*    bzerror, 
      BZFILE* b 
   );

BZ_EXTERN void BZ_API(BZ2_bzReadGetUnused) ( 
      int*    bzerror, 
      BZFILE* b, 
      void**  unused,  
      int*    nUnused 
   );

BZ_EXTERN int BZ_API(BZ2_bzRead) ( 
      int*    bzerror, 
      BZFILE* b, 
      void*   buf, 
      int     len 
   );

BZ_EXTERN BZFILE* BZ_API(BZ2_bzWriteOpen) ( 
      int*  bzerror,      
      FILE* f, 
      int   blockSize100k, 
      int   verbosity, 
      int   workFactor 
   );

BZ_EXTERN void BZ_API(BZ2_bzWrite) ( 
      int*    bzerror, 
      BZFILE* b, 
      void*   buf, 
      int     len 
   );

BZ_EXTERN void BZ_API(BZ2_bzWriteClose) ( 
      int*          bzerror, 
      BZFILE*       b, 
      int           abandon, 
      unsigned int* nbytes_in, 
      unsigned int* nbytes_out 
   );

BZ_EXTERN void BZ_API(BZ2_bzWriteClose64) ( 
      int*          bzerror, 
      BZFILE*       b, 
      int           abandon, 
      unsigned int* nbytes_in_lo32, 
      unsigned int* nbytes_in_hi32, 
      unsigned int* nbytes_out_lo32, 
      unsigned int* nbytes_out_hi32
   );
BZ_EXTERN int BZ_API(BZ2_bzBuffToBuffCompress) ( 
      char*         dest, 
      unsigned int* destLen,
      char*         source, 
      unsigned int  sourceLen,
      int           blockSize100k, 
      int           verbosity, 
      int           workFactor 
   );

BZ_EXTERN int BZ_API(BZ2_bzBuffToBuffDecompress) ( 
      char*         dest, 
      unsigned int* destLen,
      char*         source, 
      unsigned int  sourceLen,
      int           small, 
      int           verbosity 
   );
BZ_EXTERN const char * BZ_API(BZ2_bzlibVersion) (
      void
   );

BZ_EXTERN BZFILE * BZ_API(BZ2_bzopen) (
      const char *path,
      const char *mode
   );

BZ_EXTERN BZFILE * BZ_API(BZ2_bzdopen) (
      int        fd,
      const char *mode
   );
         
BZ_EXTERN int BZ_API(BZ2_bzread) (
      BZFILE* b, 
      void* buf, 
      int len 
   );

BZ_EXTERN int BZ_API(BZ2_bzwrite) (
      BZFILE* b, 
      void*   buf, 
      int     len 
   );

BZ_EXTERN int BZ_API(BZ2_bzflush) (
      BZFILE* b
   );

BZ_EXTERN void BZ_API(BZ2_bzclose) (
      BZFILE* b
   );

BZ_EXTERN const char * BZ_API(BZ2_bzerror) (
      BZFILE *b, 
      int    *errnum
   );

#define _BZLIB_PRIVATE_H

#define BZ_VERSION  "1.0.2, 30-Dec-2001"

typedef char            Char;
typedef unsigned char   Bool;
typedef unsigned char   UChar;
typedef int             Int32;
typedef unsigned int    UInt32;
typedef short           Int16;
typedef unsigned short  UInt16;

#define True  ((Bool)1)
#define False ((Bool)0)

#define __inline__  

extern void BZ2_bz__AssertH__fail ( int errcode );
#define AssertH(cond,errcode) \
   { if (!(cond)) BZ2_bz__AssertH__fail ( errcode ); }
#define AssertD(cond,msg) \
   { if (!(cond)) {       \
      fprintf ( stderr,   \
        "\n\nlibbzip2(debug build): internal error\n\t%s\n", msg );\
      exit(1); \
   }}
#define VPrintf0(zf) \
   fprintf(stderr,zf)
#define VPrintf1(zf,za1) \
   fprintf(stderr,zf,za1)
#define VPrintf2(zf,za1,za2) \
   fprintf(stderr,zf,za1,za2)
#define VPrintf3(zf,za1,za2,za3) \
   fprintf(stderr,zf,za1,za2,za3)
#define VPrintf4(zf,za1,za2,za3,za4) \
   fprintf(stderr,zf,za1,za2,za3,za4)
#define VPrintf5(zf,za1,za2,za3,za4,za5) \
   fprintf(stderr,zf,za1,za2,za3,za4,za5)
#define BZALLOC(nnn) (strm->bzalloc)(strm->opaque,(nnn),1)
#define BZFREE(ppp)  (strm->bzfree)(strm->opaque,(ppp))
#define BZ_HDR_B 0x42   
#define BZ_HDR_Z 0x5a   
#define BZ_HDR_h 0x68   
#define BZ_HDR_0 0x30   
  
#define BZ_MAX_ALPHA_SIZE 258
#define BZ_MAX_CODE_LEN    23

#define BZ_RUNA 0
#define BZ_RUNB 1

#define BZ_N_GROUPS 6
#define BZ_G_SIZE   50
#define BZ_N_ITERS  4

#define BZ_MAX_SELECTORS (2 + (900000 / BZ_G_SIZE))

#define BZ_RAND_DECLS                          \
   Int32 rNToGo;                               \
   Int32 rTPos                                 \

#define BZ_RAND_INIT_MASK                      \
   s->rNToGo = 0;                              \
   s->rTPos  = 0                               \

#define BZ_RAND_MASK ((s->rNToGo == 1) ? 1 : 0)

#define BZ_RAND_UPD_MASK                       \
   if (s->rNToGo == 0) {                       \
      s->rNToGo = BZ2_rNums[s->rTPos];         \
      s->rTPos++;                              \
      if (s->rTPos == 512) s->rTPos = 0;       \
   }                                           \
   s->rNToGo--;

#define BZ_INITIALISE_CRC(crcVar)              \
{                                              \
   crcVar = 0xffffffffL;                       \
}

#define BZ_FINALISE_CRC(crcVar)                \
{                                              \
   crcVar = ~(crcVar);                         \
}

#define BZ_UPDATE_CRC(crcVar,cha)              \
{                                              \
   crcVar = (crcVar << 8) ^                    \
            BZ2_crc32Table[(crcVar >> 24) ^    \
                           ((UChar)cha)];      \
}

#define BZ_M_IDLE      1
#define BZ_M_RUNNING   2
#define BZ_M_FLUSHING  3
#define BZ_M_FINISHING 4

#define BZ_S_OUTPUT    1
#define BZ_S_INPUT     2

#define BZ_N_RADIX 2
#define BZ_N_QSORT 12
#define BZ_N_SHELL 18
#define BZ_N_OVERSHOOT (BZ_N_RADIX + BZ_N_QSORT + BZ_N_SHELL + 2)
typedef
   struct {
      
      bz_stream* strm;

      
      
      Int32    mode;
      Int32    state;

      
      UInt32   avail_in_expect;

      
      UInt32*  arr1;
      UInt32*  arr2;
      UInt32*  ftab;
      

      
      UInt32*  ptr;
      UChar*   block;
      UInt16*  mtfv;
      UChar*   zbits;

      
      Int32    workFactor;

      
      
      
      BZ_RAND_DECLS;

      
      
      Int32    nblockMAX;
      Int32    numZ;
      Int32    state_out_pos;

      
      
      
      

      
      
      

      
      
      UInt32   combinedCRC;

      
      Int32    verbosity;
      Int32    blockNo;
      Int32    blockSize100k;

      
      
      
      
      

      
      
      
      
      

   }
   EState;

;

;

#define BZ_X_IDLE        1
#define BZ_X_OUTPUT      2

#define BZ_X_MAGIC_1     10
#define BZ_X_MAGIC_2     11
#define BZ_X_MAGIC_3     12
#define BZ_X_MAGIC_4     13
#define BZ_X_BLKHDR_1    14
#define BZ_X_BLKHDR_2    15
#define BZ_X_BLKHDR_3    16
#define BZ_X_BLKHDR_4    17
#define BZ_X_BLKHDR_5    18
#define BZ_X_BLKHDR_6    19
#define BZ_X_BCRC_1      20
#define BZ_X_BCRC_2      21
#define BZ_X_BCRC_3      22
#define BZ_X_BCRC_4      23
#define BZ_X_RANDBIT     24
#define BZ_X_ORIGPTR_1   25
#define BZ_X_ORIGPTR_2   26
#define BZ_X_ORIGPTR_3   27
#define BZ_X_MAPPING_1   28
#define BZ_X_MAPPING_2   29
#define BZ_X_SELECTOR_1  30
#define BZ_X_SELECTOR_2  31
#define BZ_X_SELECTOR_3  32
#define BZ_X_CODING_1    33
#define BZ_X_CODING_2    34
#define BZ_X_CODING_3    35
#define BZ_X_MTF_1       36
#define BZ_X_MTF_2       37
#define BZ_X_MTF_3       38
#define BZ_X_MTF_4       39
#define BZ_X_MTF_5       40
#define BZ_X_MTF_6       41
#define BZ_X_ENDHDR_2    42
#define BZ_X_ENDHDR_3    43
#define BZ_X_ENDHDR_4    44
#define BZ_X_ENDHDR_5    45
#define BZ_X_ENDHDR_6    46
#define BZ_X_CCRC_1      47
#define BZ_X_CCRC_2      48
#define BZ_X_CCRC_3      49
#define BZ_X_CCRC_4      50

#define MTFA_SIZE 4096
#define MTFL_SIZE 16

typedef
   struct {
      
      bz_stream* strm;

      
      Int32    state;

      
      
      Int32    state_out_len;
      
      BZ_RAND_DECLS;

      
      UInt32   bsBuff;
      Int32    bsLive;

      
      
      Bool     smallDecompress;
      Int32    currBlockNo;
      Int32    verbosity;

      
      
      
      
      
      Int32    nblock_used;
      
      

      
      UInt32   *tt;

      
      UInt16   *ll16;
      UChar    *ll4;

      
      UInt32   storedBlockCRC;
      UInt32   storedCombinedCRC;
      UInt32   calculatedBlockCRC;
      UInt32   calculatedCombinedCRC;

      
      
      
      
      

      
      
      
      
      
      

      
      
      
      

      
      
      
      
      
      
      
      
      
      
      
      
      Int32    save_nblock;
      
      
      
      
       
      
      
      
      
      
      
      

   }
   DState;

#define BZ_GET_FAST(cccc)                     \
    s->tPos = s->tt[s->tPos];                 \
    cccc = (UChar)(s->tPos & 0xff);           \
    s->tPos >>= 8;

#define BZ_GET_FAST_C(cccc)                   \
    c_tPos = c_tt[c_tPos];                    \
    cccc = (UChar)(c_tPos & 0xff);            \
    c_tPos >>= 8;

#define SET_LL4(i,n)                                          \
   { if (((i) & 0x1) == 0)                                    \
        s->ll4[(i) >> 1] = (s->ll4[(i) >> 1] & 0xf0) | (n); else    \
        s->ll4[(i) >> 1] = (s->ll4[(i) >> 1] & 0x0f) | ((n) << 4);  \
   }

#define GET_LL4(i)                             \
   ((((UInt32)(s->ll4[(i) >> 1])) >> (((i) << 2) & 0x4)) & 0xF)

#define SET_LL(i,n)                          \
   { s->ll16[i] = (UInt16)(n & 0x0000ffff);  \
     SET_LL4(i, n >> 16);                    \
   }

#define GET_LL(i) \
   (((UInt32)s->ll16[i]) | (GET_LL4(i) << 16))

#define BZ_GET_SMALL(cccc)                            \
      cccc = BZ2_indexIntoF ( s->tPos, s->cftab );    \
      s->tPos = GET_LL(s->tPos);
;

;


#define fswap(zz1, zz2) \
   { Int32 zztmp = zz1; zz1 = zz2; zz2 = zztmp; }

#define fvswap(zzp1, zzp2, zzn)       \
{                                     \
   Int32 yyp1 = (zzp1);               \
   Int32 yyp2 = (zzp2);               \
   Int32 yyn  = (zzn);                \
   while (yyn > 0) {                  \
      fswap(fmap[yyp1], fmap[yyp2]);  \
      yyp1++; yyp2++; yyn--;          \
   }                                  \
}
#define fmin(a,b) ((a) < (b)) ? (a) : (b)

#define fpush(lz,hz) { stackLo[sp] = lz; \
                       stackHi[sp] = hz; \
                       sp++; }

#define fpop(lz,hz) { sp--;              \
                      lz = stackLo[sp];  \
                      hz = stackHi[sp]; }

#define FALLBACK_QSORT_SMALL_THRESH 10
#define FALLBACK_QSORT_STACK_SIZE   100
#undef fmin
#undef fpush
#undef fpop
#undef fswap
#undef fvswap
#undef FALLBACK_QSORT_SMALL_THRESH
#undef FALLBACK_QSORT_STACK_SIZE

#define       SET_BH(zz)  bhtab[(zz) >> 5] |= (1 << ((zz) & 31))
#define     CLEAR_BH(zz)  bhtab[(zz) >> 5] &= ~(1 << ((zz) & 31))
#define     ISSET_BH(zz)  (bhtab[(zz) >> 5] & (1 << ((zz) & 31)))
#define      WORD_BH(zz)  bhtab[(zz) >> 5]
#define UNALIGNED_BH(zz)  ((zz) & 0x01f)

#undef       SET_BH
#undef     CLEAR_BH
#undef     ISSET_BH
#undef      WORD_BH
#undef UNALIGNED_BH


#define mswap(zz1, zz2) \
   { Int32 zztmp = zz1; zz1 = zz2; zz2 = zztmp; }

#define mvswap(zzp1, zzp2, zzn)       \
{                                     \
   Int32 yyp1 = (zzp1);               \
   Int32 yyp2 = (zzp2);               \
   Int32 yyn  = (zzn);                \
   while (yyn > 0) {                  \
      mswap(ptr[yyp1], ptr[yyp2]);    \
      yyp1++; yyp2++; yyn--;          \
   }                                  \
}

#define mmin(a,b) ((a) < (b)) ? (a) : (b)

#define mpush(lz,hz,dz) { stackLo[sp] = lz; \
                          stackHi[sp] = hz; \
                          stackD [sp] = dz; \
                          sp++; }

#define mpop(lz,hz,dz) { sp--;             \
                         lz = stackLo[sp]; \
                         hz = stackHi[sp]; \
                         dz = stackD [sp]; }
#define mnextsize(az) (nextHi[az]-nextLo[az])

#define mnextswap(az,bz)                                        \
   { Int32 tz;                                                  \
     tz = nextLo[az]; nextLo[az] = nextLo[bz]; nextLo[bz] = tz; \
     tz = nextHi[az]; nextHi[az] = nextHi[bz]; nextHi[bz] = tz; \
     tz = nextD [az]; nextD [az] = nextD [bz]; nextD [bz] = tz; }
#define MAIN_QSORT_SMALL_THRESH 20
#define MAIN_QSORT_DEPTH_THRESH (BZ_N_RADIX + BZ_N_QSORT)
#define MAIN_QSORT_STACK_SIZE 100

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

#define BIGFREQ(b) (ftab[((b)+1) << 8] - ftab[(b) << 8])
#define SETMASK (1 << 21)
#define CLEARMASK (~(SETMASK))

#undef BIGFREQ
#undef SETMASK
#undef CLEARMASK


#define WEIGHTOF(zz0)  ((zz0) & 0xffffff00)
#define DEPTHOF(zz1)   ((zz1) & 0x000000ff)
#define MYMAX(zz2,zz3) ((zz2) > (zz3) ? (zz2) : (zz3))

#define ADDWEIGHTS(zw1,zw2)                           \
   (WEIGHTOF(zw1)+WEIGHTOF(zw2)) |                    \
   (1 + MYMAX(DEPTHOF(zw1),DEPTHOF(zw2)))

#define UPHEAP(z)                                     \
{                                                     \
   Int32 zz, tmp;                                     \
   zz = z; tmp = heap[zz];                            \
   while (weight[tmp] < weight[heap[zz >> 1]]) {      \
      heap[zz] = heap[zz >> 1];                       \
      zz >>= 1;                                       \
   }                                                  \
   heap[zz] = tmp;                                    \
}

#define DOWNHEAP(z)                                   \
{                                                     \
   Int32 zz, yy, tmp;                                 \
   zz = z; tmp = heap[zz];                            \
   while (True) {                                     \
      yy = zz << 1;                                   \
      if (yy > nHeap) break;                          \
      if (yy < nHeap &&                               \
          weight[heap[yy+1]] < weight[heap[yy]])      \
         yy++;                                        \
      if (weight[tmp] < weight[heap[yy]]) break;      \
      heap[zz] = heap[yy];                            \
      zz = yy;                                        \
   }                                                  \
   heap[zz] = tmp;                                    \
}




#define bsNEEDW(nz)                           \
{                                             \
   while (s->bsLive >= 8) {                   \
      s->zbits[s->numZ]                       \
         = (UChar)(s->bsBuff >> 24);          \
      s->numZ++;                              \
      s->bsBuff <<= 8;                        \
      s->bsLive -= 8;                         \
   }                                          \
}

#define BZ_LESSER_ICOST  0
#define BZ_GREATER_ICOST 15

#define RETURN(rrr)                               \
   { retVal = rrr; goto save_state_and_return; };

#define GET_BITS(lll,vvv,nnn)                     \
   case lll: s->state = lll;                      \
   while (True) {                                 \
      if (s->bsLive >= nnn) {                     \
         UInt32 v;                                \
         v = (s->bsBuff >>                        \
             (s->bsLive-nnn)) & ((1 << nnn)-1);   \
         s->bsLive -= nnn;                        \
         vvv = v;                                 \
         break;                                   \
      }                                           \
      if (s->strm->avail_in == 0) RETURN(BZ_OK);  \
      s->bsBuff                                   \
         = (s->bsBuff << 8) |                     \
           ((UInt32)                              \
              (*((UChar*)(s->strm->next_in))));   \
      s->bsLive += 8;                             \
      s->strm->next_in++;                         \
      s->strm->avail_in--;                        \
      s->strm->total_in_lo32++;                   \
      if (s->strm->total_in_lo32 == 0)            \
         s->strm->total_in_hi32++;                \
   }

#define GET_UCHAR(lll,uuu)                        \
   GET_BITS(lll,uuu,8)

#define GET_BIT(lll,uuu)                          \
   GET_BITS(lll,uuu,1)
#define GET_MTF_VAL(label1,label2,lval)           \
{                                                 \
   if (groupPos == 0) {                           \
      groupNo++;                                  \
      if (groupNo >= nSelectors)                  \
         RETURN(BZ_DATA_ERROR);                   \
      groupPos = BZ_G_SIZE;                       \
      gSel = s->selector[groupNo];                \
      gMinlen = s->minLens[gSel];                 \
      gLimit = &(s->limit[gSel][0]);              \
      gPerm = &(s->perm[gSel][0]);                \
      gBase = &(s->base[gSel][0]);                \
   }                                              \
   groupPos--;                                    \
   zn = gMinlen;                                  \
   GET_BITS(label1, zvec, zn);                    \
   while (1) {                                    \
      if (zn > 20 )         \
         RETURN(BZ_DATA_ERROR);                   \
      if (zvec <= gLimit[zn]) break;              \
      zn++;                                       \
      GET_BIT(label2, zj);                        \
      zvec = (zvec << 1) | zj;                    \
   };                                             \
   if (zvec - gBase[zn] < 0                       \
       || zvec - gBase[zn] >= BZ_MAX_ALPHA_SIZE)  \
      RETURN(BZ_DATA_ERROR);                      \
   lval = gPerm[zvec - gBase[zn]];                \
}

void BZ2_bz__AssertH__fail ( int errcode )
;

static
void* default_bzalloc ( void* opaque, Int32 items, Int32 size )
;

static
void default_bzfree ( void* opaque, void* addr )
;
int BZ_API(BZ2_bzCompressInit) 
                    ( bz_stream* strm, 
                     int        blockSize100k,
                     int        verbosity,
                     int        workFactor )
{
   Int32   n;
   EState* s;

   if (!0) return BZ_CONFIG_ERROR;

   if (strm == NULL || 
       blockSize100k < 1 || blockSize100k > 9 ||
       workFactor < 0 || workFactor > 250)
     return BZ_PARAM_ERROR;

   if (workFactor == 0) workFactor = 30;
   if (strm->bzalloc == NULL) strm->bzalloc = default_bzalloc;
   if (strm->bzfree == NULL) strm->bzfree = default_bzfree;

   s = BZALLOC( sizeof(EState) );
   if (s == NULL) return BZ_MEM_ERROR;
   s->strm = strm;

   s->arr1 = NULL;
   s->arr2 = NULL;
   s->ftab = NULL;

   n       = 100000 * blockSize100k;
   s->arr1 = BZALLOC( n                  * sizeof(UInt32) );
   s->arr2 = BZALLOC( (n+BZ_N_OVERSHOOT) * sizeof(UInt32) );
   s->ftab = BZALLOC( 65537              * sizeof(UInt32) );

   if (s->arr1 == NULL || s->arr2 == NULL || s->ftab == NULL) {
      if (s->arr1 != NULL) BZFREE(s->arr1);
      if (s->arr2 != NULL) BZFREE(s->arr2);
      if (s->ftab != NULL) BZFREE(s->ftab);
      if (s       != NULL) BZFREE(s);
      return BZ_MEM_ERROR;
   }

   s->blockNo           = 0;
   s->state             = BZ_S_INPUT;
   s->mode              = BZ_M_RUNNING;
   s->combinedCRC       = 0;
   s->blockSize100k     = blockSize100k;
   s->nblockMAX         = 100000 * blockSize100k - 19;
   s->verbosity         = verbosity;
   s->workFactor        = workFactor;

   s->block             = (UChar*)s->arr2;
   s->mtfv              = (UInt16*)s->arr1;
   s->zbits             = NULL;
   s->ptr               = (UInt32*)s->arr1;

   strm->state          = s;
   strm->total_in_lo32  = 0;
   strm->total_in_hi32  = 0;
   strm->total_out_lo32 = 0;
   strm->total_out_hi32 = 0;
   ;
   ;
   return BZ_OK;
}

#define ADD_CHAR_TO_BLOCK(zs,zchh0)               \
{                                                 \
   UInt32 zchh = (UInt32)(zchh0);                 \
              \
   if (zchh != zs->state_in_ch &&                 \
       zs->state_in_len == 1) {                   \
      UChar ch = (UChar)(zs->state_in_ch);        \
      BZ_UPDATE_CRC( zs->blockCRC, ch );          \
      zs->inUse[zs->state_in_ch] = True;          \
      zs->block[zs->nblock] = (UChar)ch;          \
      zs->nblock++;                               \
      zs->state_in_ch = zchh;                     \
   }                                              \
   else                                           \
                 \
   if (zchh != zs->state_in_ch ||                 \
      zs->state_in_len == 255) {                  \
      if (zs->state_in_ch < 256)                  \
         add_pair_to_block ( zs );                \
      zs->state_in_ch = zchh;                     \
      zs->state_in_len = 1;                       \
   } else {                                       \
      zs->state_in_len++;                         \
   }                                              \
}

int BZ_API(BZ2_bzCompress) ( bz_stream *strm, int action )
{
   Bool progress;
   EState* s;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (s->strm != strm) return BZ_PARAM_ERROR;

   preswitch:
   switch (s->mode) {

      case BZ_M_IDLE:
         return BZ_SEQUENCE_ERROR;

      case BZ_M_RUNNING:
         if (action == BZ_RUN) {
            progress = 0;
            return progress ? BZ_RUN_OK : BZ_PARAM_ERROR;
         } 
         else
	 if (action == BZ_FLUSH) {
            s->avail_in_expect = strm->avail_in;
            s->mode = BZ_M_FLUSHING;
            goto preswitch;
         }
         else
         if (action == BZ_FINISH) {
            s->avail_in_expect = strm->avail_in;
            s->mode = BZ_M_FINISHING;
            goto preswitch;
         }
         else 
            return BZ_PARAM_ERROR;

      case BZ_M_FLUSHING:
         if (action != BZ_FLUSH) return BZ_SEQUENCE_ERROR;
         if (s->avail_in_expect != s->strm->avail_in) 
            return BZ_SEQUENCE_ERROR;
         progress = 0;
         if (s->avail_in_expect > 0 || !0 ||
             s->state_out_pos < s->numZ) return BZ_FLUSH_OK;
         s->mode = BZ_M_RUNNING;
         return BZ_RUN_OK;

      case BZ_M_FINISHING:
         if (action != BZ_FINISH) return BZ_SEQUENCE_ERROR;
         if (s->avail_in_expect != s->strm->avail_in) 
            return BZ_SEQUENCE_ERROR;
         progress = 0;
         if (!progress) return BZ_SEQUENCE_ERROR;
         if (s->avail_in_expect > 0 || !0 ||
             s->state_out_pos < s->numZ) return BZ_FINISH_OK;
         s->mode = BZ_M_IDLE;
         return BZ_STREAM_END;
   }
   return BZ_OK; 
}

int BZ_API(BZ2_bzCompressEnd)  ( bz_stream *strm )
{
   EState* s;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (s->strm != strm) return BZ_PARAM_ERROR;

   if (s->arr1 != NULL) BZFREE(s->arr1);
   if (s->arr2 != NULL) BZFREE(s->arr2);
   if (s->ftab != NULL) BZFREE(s->ftab);
   BZFREE(strm->state);

   strm->state = NULL;   

   return BZ_OK;
}

int BZ_API(BZ2_bzDecompressInit) 
                     ( bz_stream* strm, 
                       int        verbosity,
                       int        small )
{
   DState* s;

   if (!0) return BZ_CONFIG_ERROR;

   if (strm == NULL) return BZ_PARAM_ERROR;
   if (small != 0 && small != 1) return BZ_PARAM_ERROR;
   if (verbosity < 0 || verbosity > 4) return BZ_PARAM_ERROR;

   if (strm->bzalloc == NULL) strm->bzalloc = default_bzalloc;
   if (strm->bzfree == NULL) strm->bzfree = default_bzfree;

   s = BZALLOC( sizeof(DState) );
   if (s == NULL) return BZ_MEM_ERROR;
   s->strm                  = strm;
   strm->state              = s;
   s->state                 = BZ_X_MAGIC_1;
   s->bsLive                = 0;
   s->bsBuff                = 0;
   s->calculatedCombinedCRC = 0;
   strm->total_in_lo32      = 0;
   strm->total_in_hi32      = 0;
   strm->total_out_lo32     = 0;
   strm->total_out_hi32     = 0;
   s->smallDecompress       = (Bool)small;
   s->ll4                   = NULL;
   s->ll16                  = NULL;
   s->tt                    = NULL;
   s->currBlockNo           = 0;
   s->verbosity             = verbosity;

   return BZ_OK;
}


int BZ_API(BZ2_bzDecompress) ( bz_stream *strm )
{
   DState* s;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (s->strm != strm) return BZ_PARAM_ERROR;

   while (True) {
      if (s->state == BZ_X_IDLE) return BZ_SEQUENCE_ERROR;
      if (s->state == BZ_X_OUTPUT) {
         if (s->smallDecompress)
            ; else
            ;
         if (s->nblock_used == s->save_nblock+1 && s->state_out_len == 0) {
            BZ_FINALISE_CRC ( s->calculatedBlockCRC );
            if (s->verbosity >= 3) 
               VPrintf2 ( " {0x%x, 0x%x}", s->storedBlockCRC, 
                          s->calculatedBlockCRC );
            if (s->verbosity >= 2) VPrintf0 ( "]" );
            if (s->calculatedBlockCRC != s->storedBlockCRC)
               return BZ_DATA_ERROR;
            s->calculatedCombinedCRC 
               = (s->calculatedCombinedCRC << 1) | 
                    (s->calculatedCombinedCRC >> 31);
            s->calculatedCombinedCRC ^= s->calculatedBlockCRC;
            s->state = BZ_X_BLKHDR_1;
         } else {
            return BZ_OK;
         }
      }
      if (s->state >= BZ_X_MAGIC_1) {
         Int32 r = 0;
         if (r == BZ_STREAM_END) {
            if (s->verbosity >= 3)
               VPrintf2 ( "\n    combined CRCs: stored = 0x%x, computed = 0x%x", 
                          s->storedCombinedCRC, s->calculatedCombinedCRC );
            if (s->calculatedCombinedCRC != s->storedCombinedCRC)
               return BZ_DATA_ERROR;
            return r;
         }
         if (s->state != BZ_X_OUTPUT) return r;
      }
   }

   AssertH ( 0, 6001 );

   return 0;  
}

int BZ_API(BZ2_bzDecompressEnd)  ( bz_stream *strm )
{
   DState* s;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (s->strm != strm) return BZ_PARAM_ERROR;

   if (s->tt   != NULL) BZFREE(s->tt);
   if (s->ll16 != NULL) BZFREE(s->ll16);
   if (s->ll4  != NULL) BZFREE(s->ll4);

   BZFREE(strm->state);
   strm->state = NULL;

   return BZ_OK;
}
#define BZ_SETERR(eee)                    \
{                                         \
   if (bzerror != NULL) *bzerror = eee;   \
   if (bzf != NULL) bzf->lastErr = eee;   \
}

typedef 
   struct {
      FILE*     handle;
      Char      buf[BZ_MAX_UNUSED];
      Int32     bufN;
      Bool      writing;
      bz_stream strm;
      Int32     lastErr;
      Bool      initialisedOk;
   }
   bzFile;

BZFILE* BZ_API(BZ2_bzWriteOpen) 
                    ( int*  bzerror,      
                      FILE* f, 
                      int   blockSize100k, 
                      int   verbosity,
                      int   workFactor )
{
   Int32   ret;
   bzFile* bzf = NULL;

   BZ_SETERR(BZ_OK);

   if (f == NULL ||
       (blockSize100k < 1 || blockSize100k > 9) ||
       (workFactor < 0 || workFactor > 250) ||
       (verbosity < 0 || verbosity > 4))
      { BZ_SETERR(BZ_PARAM_ERROR); return NULL; };

   if (0)
      { BZ_SETERR(BZ_IO_ERROR); return NULL; };

   bzf = 0;
   if (bzf == NULL)
      { BZ_SETERR(BZ_MEM_ERROR); return NULL; };

   BZ_SETERR(BZ_OK);
   bzf->initialisedOk = False;
   bzf->bufN          = 0;
   bzf->handle        = f;
   bzf->writing       = True;
   bzf->strm.bzalloc  = NULL;
   bzf->strm.bzfree   = NULL;
   bzf->strm.opaque   = NULL;

   if (workFactor == 0) workFactor = 30;
   ret = 0;
   if (ret != BZ_OK)
      { BZ_SETERR(ret); ; return NULL; };

   bzf->strm.avail_in = 0;
   bzf->initialisedOk = True;
   return bzf;   
}
void BZ_API(BZ2_bzWrite)
             ( int*    bzerror, 
               BZFILE* b, 
               void*   buf, 
               int     len )
{
   Int32 n, n2, ret;
   bzFile* bzf = (bzFile*)b;

   BZ_SETERR(BZ_OK);
   if (bzf == NULL || buf == NULL || len < 0)
      { BZ_SETERR(BZ_PARAM_ERROR); return; };
   if (!(bzf->writing))
      { BZ_SETERR(BZ_SEQUENCE_ERROR); return; };
   if (0)
      { BZ_SETERR(BZ_IO_ERROR); return; };

   if (len == 0)
      { BZ_SETERR(BZ_OK); return; };

   bzf->strm.avail_in = len;
   bzf->strm.next_in  = buf;

   while (True) {
      bzf->strm.avail_out = BZ_MAX_UNUSED;
      bzf->strm.next_out = bzf->buf;
      ret = 0;
      if (ret != BZ_RUN_OK)
         { BZ_SETERR(ret); return; };

      if (bzf->strm.avail_out < BZ_MAX_UNUSED) {
         n = BZ_MAX_UNUSED - bzf->strm.avail_out;
         n2 = 0;
         if (n != n2 || 0)
            { BZ_SETERR(BZ_IO_ERROR); return; };
      }

      if (bzf->strm.avail_in == 0)
         { BZ_SETERR(BZ_OK); return; };
   }
}

void BZ_API(BZ2_bzWriteClose)
                  ( int*          bzerror, 
                    BZFILE*       b, 
                    int           abandon,
                    unsigned int* nbytes_in,
                    unsigned int* nbytes_out )
{
   ;
}
void BZ_API(BZ2_bzWriteClose64)
                  ( int*          bzerror, 
                    BZFILE*       b, 
                    int           abandon,
                    unsigned int* nbytes_in_lo32,
                    unsigned int* nbytes_in_hi32,
                    unsigned int* nbytes_out_lo32,
                    unsigned int* nbytes_out_hi32 )
{
   Int32   n, n2, ret;
   bzFile* bzf = (bzFile*)b;

   if (bzf == NULL)
      { BZ_SETERR(BZ_OK); return; };
   if (!(bzf->writing))
      { BZ_SETERR(BZ_SEQUENCE_ERROR); return; };
   if (0)
      { BZ_SETERR(BZ_IO_ERROR); return; };

   if (nbytes_in_lo32 != NULL) *nbytes_in_lo32 = 0;
   if (nbytes_in_hi32 != NULL) *nbytes_in_hi32 = 0;
   if (nbytes_out_lo32 != NULL) *nbytes_out_lo32 = 0;
   if (nbytes_out_hi32 != NULL) *nbytes_out_hi32 = 0;

   if ((!abandon) && bzf->lastErr == BZ_OK) {
      while (True) {
         bzf->strm.avail_out = BZ_MAX_UNUSED;
         bzf->strm.next_out = bzf->buf;
         ret = 0;
         if (ret != BZ_FINISH_OK && ret != BZ_STREAM_END)
            { BZ_SETERR(ret); return; };

         if (bzf->strm.avail_out < BZ_MAX_UNUSED) {
            n = BZ_MAX_UNUSED - bzf->strm.avail_out;
            n2 = 0;
            if (n != n2 || 0)
               { BZ_SETERR(BZ_IO_ERROR); return; };
         }

         if (ret == BZ_STREAM_END) break;
      }
   }

   if ( !abandon && !0 ) {
      0;
      if (0)
         { BZ_SETERR(BZ_IO_ERROR); return; };
   }

   if (nbytes_in_lo32 != NULL)
      *nbytes_in_lo32 = bzf->strm.total_in_lo32;
   if (nbytes_in_hi32 != NULL)
      *nbytes_in_hi32 = bzf->strm.total_in_hi32;
   if (nbytes_out_lo32 != NULL)
      *nbytes_out_lo32 = bzf->strm.total_out_lo32;
   if (nbytes_out_hi32 != NULL)
      *nbytes_out_hi32 = bzf->strm.total_out_hi32;

   BZ_SETERR(BZ_OK);
   0;
   ;
}

BZFILE* BZ_API(BZ2_bzReadOpen) 
                   ( int*  bzerror, 
                     FILE* f, 
                     int   verbosity,
                     int   small,
                     void* unused,
                     int   nUnused )
{
   bzFile* bzf = NULL;
   int     ret;

   BZ_SETERR(BZ_OK);

   if (f == NULL || 
       (small != 0 && small != 1) ||
       (verbosity < 0 || verbosity > 4) ||
       (unused == NULL && nUnused != 0) ||
       (unused != NULL && (nUnused < 0 || nUnused > BZ_MAX_UNUSED)))
      { BZ_SETERR(BZ_PARAM_ERROR); return NULL; };

   if (0)
      { BZ_SETERR(BZ_IO_ERROR); return NULL; };

   bzf = 0;
   if (bzf == NULL) 
      { BZ_SETERR(BZ_MEM_ERROR); return NULL; };

   BZ_SETERR(BZ_OK);

   bzf->initialisedOk = False;
   bzf->handle        = f;
   bzf->bufN          = 0;
   bzf->writing       = False;
   bzf->strm.bzalloc  = NULL;
   bzf->strm.bzfree   = NULL;
   bzf->strm.opaque   = NULL;
   
   while (nUnused > 0) {
      bzf->buf[bzf->bufN] = *((UChar*)(unused)); bzf->bufN++;
      unused = ((void*)( 1 + ((UChar*)(unused))  ));
      nUnused--;
   }

   ret = 0;
   if (ret != BZ_OK)
      { BZ_SETERR(ret); ; return NULL; };

   bzf->strm.avail_in = bzf->bufN;
   bzf->strm.next_in  = bzf->buf;

   bzf->initialisedOk = True;
   return bzf;   
}

void BZ_API(BZ2_bzReadClose) ( int *bzerror, BZFILE *b )
{
   bzFile* bzf = (bzFile*)b;

   BZ_SETERR(BZ_OK);
   if (bzf == NULL)
      { BZ_SETERR(BZ_OK); return; };

   if (bzf->writing)
      { BZ_SETERR(BZ_SEQUENCE_ERROR); return; };

   if (bzf->initialisedOk)
      (void)0;
   ;
}

int BZ_API(BZ2_bzRead) 
           ( int*    bzerror, 
             BZFILE* b, 
             void*   buf, 
             int     len )
{
   Int32   n, ret;
   bzFile* bzf = (bzFile*)b;

   BZ_SETERR(BZ_OK);

   if (bzf == NULL || buf == NULL || len < 0)
      { BZ_SETERR(BZ_PARAM_ERROR); return 0; };

   if (bzf->writing)
      { BZ_SETERR(BZ_SEQUENCE_ERROR); return 0; };

   if (len == 0)
      { BZ_SETERR(BZ_OK); return 0; };

   bzf->strm.avail_out = len;
   bzf->strm.next_out = buf;

   while (True) {

      if (0) 
         { BZ_SETERR(BZ_IO_ERROR); return 0; };

      if (bzf->strm.avail_in == 0 && !0) {
         n = 0;
         if (0)
            { BZ_SETERR(BZ_IO_ERROR); return 0; };
         bzf->bufN = n;
         bzf->strm.avail_in = bzf->bufN;
         bzf->strm.next_in = bzf->buf;
      }

      ret = 0;

      if (ret != BZ_OK && ret != BZ_STREAM_END)
         { BZ_SETERR(ret); return 0; };

      if (ret == BZ_OK && 0 && 
          bzf->strm.avail_in == 0 && bzf->strm.avail_out > 0)
         { BZ_SETERR(BZ_UNEXPECTED_EOF); return 0; };

      if (ret == BZ_STREAM_END)
         { BZ_SETERR(BZ_STREAM_END);
           return len - bzf->strm.avail_out; };
      if (bzf->strm.avail_out == 0)
         { BZ_SETERR(BZ_OK); return len; };
      
   }

   return 0; 
}

void BZ_API(BZ2_bzReadGetUnused) 
                     ( int*    bzerror, 
                       BZFILE* b, 
                       void**  unused, 
                       int*    nUnused )
{
   bzFile* bzf = (bzFile*)b;
   if (bzf == NULL)
      { BZ_SETERR(BZ_PARAM_ERROR); return; };
   if (bzf->lastErr != BZ_STREAM_END)
      { BZ_SETERR(BZ_SEQUENCE_ERROR); return; };
   if (unused == NULL || nUnused == NULL)
      { BZ_SETERR(BZ_PARAM_ERROR); return; };

   BZ_SETERR(BZ_OK);
   *nUnused = bzf->strm.avail_in;
   *unused = bzf->strm.next_in;
}

int BZ_API(BZ2_bzBuffToBuffCompress) 
                         ( char*         dest, 
                           unsigned int* destLen,
                           char*         source, 
                           unsigned int  sourceLen,
                           int           blockSize100k, 
                           int           verbosity, 
                           int           workFactor )
{
   bz_stream strm;
   int ret;

   if (dest == NULL || destLen == NULL || 
       source == NULL ||
       blockSize100k < 1 || blockSize100k > 9 ||
       verbosity < 0 || verbosity > 4 ||
       workFactor < 0 || workFactor > 250) 
      return BZ_PARAM_ERROR;

   if (workFactor == 0) workFactor = 30;
   strm.bzalloc = NULL;
   strm.bzfree = NULL;
   strm.opaque = NULL;
   ret = 0;
   if (ret != BZ_OK) return ret;

   strm.next_in = source;
   strm.next_out = dest;
   strm.avail_in = sourceLen;
   strm.avail_out = *destLen;

   ret = 0;
   if (ret == BZ_FINISH_OK) goto output_overflow;
   if (ret != BZ_STREAM_END) goto errhandler;

   
   *destLen -= strm.avail_out;   
   0;
   return BZ_OK;

   output_overflow:
   0;
   return BZ_OUTBUFF_FULL;

   errhandler:
   0;
   return ret;
}

int BZ_API(BZ2_bzBuffToBuffDecompress) 
                           ( char*         dest, 
                             unsigned int* destLen,
                             char*         source, 
                             unsigned int  sourceLen,
                             int           small,
                             int           verbosity )
{
   bz_stream strm;
   int ret;

   if (dest == NULL || destLen == NULL || 
       source == NULL ||
       (small != 0 && small != 1) ||
       verbosity < 0 || verbosity > 4) 
          return BZ_PARAM_ERROR;

   strm.bzalloc = NULL;
   strm.bzfree = NULL;
   strm.opaque = NULL;
   ret = 0;
   if (ret != BZ_OK) return ret;

   strm.next_in = source;
   strm.next_out = dest;
   strm.avail_in = sourceLen;
   strm.avail_out = *destLen;

   ret = 0;
   if (ret == BZ_OK) goto output_overflow_or_eof;
   if (ret != BZ_STREAM_END) goto errhandler;

   
   *destLen -= strm.avail_out;
   0;
   return BZ_OK;

   output_overflow_or_eof:
   if (strm.avail_out > 0) {
      0;
      return BZ_UNEXPECTED_EOF;
   } else {
      0;
      return BZ_OUTBUFF_FULL;
   };      

   errhandler:
   0;
   return ret; 
}
const char * BZ_API(BZ2_bzlibVersion)(void)
{
   return BZ_VERSION;
}

BZFILE * BZ_API(BZ2_bzopen)
               ( const char *path,
                 const char *mode )
{
   return 0;
}

BZFILE * BZ_API(BZ2_bzdopen)
               ( int fd,
                 const char *mode )
{
   return 0;
}

int BZ_API(BZ2_bzread) (BZFILE* b, void* buf, int len )
{
   int bzerr, nread;
   if (((bzFile*)b)->lastErr == BZ_STREAM_END) return 0;
   nread = 0;
   if (bzerr == BZ_OK || bzerr == BZ_STREAM_END) {
      return nread;
   } else {
      return -1;
   }
}

int BZ_API(BZ2_bzwrite) (BZFILE* b, void* buf, int len )
{
   int bzerr;

   ;
   if(bzerr == BZ_OK){
      return len;
   }else{
      return -1;
   }
}

int BZ_API(BZ2_bzflush) (BZFILE *b)
{
   
   return 0;
}

void BZ_API(BZ2_bzclose) (BZFILE* b)
{
   int bzerr;
   FILE *fp = ((bzFile *)b)->handle;
   
   if (b==NULL) {return;}
   if(((bzFile*)b)->writing){
      ;
      if(bzerr != BZ_OK){
         ;
      }
   }else{
      ;
   }
   if(fp!=stdin && fp!=stdout){
      0;
   }
}
static char *bzerrorstrings[] = {
       "OK"
      ,"SEQUENCE_ERROR"
      ,"PARAM_ERROR"
      ,"MEM_ERROR"
      ,"DATA_ERROR"
      ,"DATA_ERROR_MAGIC"
      ,"IO_ERROR"
      ,"UNEXPECTED_EOF"
      ,"OUTBUFF_FULL"
      ,"CONFIG_ERROR"
      ,"???"   
      ,"???"   
      ,"???"   
      ,"???"   
      ,"???"   
      ,"???"   
};
const char * BZ_API(BZ2_bzerror) (BZFILE *b, int *errnum)
{
   int err = ((bzFile *)b)->lastErr;

   if(err>0) err = 0;
   *errnum = err;
   return bzerrorstrings[err*-1];
}


#define BZ_UNIX      1
#define BZ_LCCWIN32  0
#define ERROR_IF_EOF(i)       { if ((i) == EOF)  ioError(); }
#define ERROR_IF_NOT_ZERO(i)  { if ((i) != 0)    ioError(); }
#define ERROR_IF_MINUS_ONE(i) { if ((i) == (-1)) ioError(); }

#   define NORETURN       
#   define PATH_SEP       '\\'
#   define MY_LSTAT       _stat
#   define MY_STAT        _stat
#   define MY_S_ISREG(x)  ((x) & _S_IFREG)
#   define MY_S_ISDIR(x)  ((x) & _S_IFDIR)

#   define APPEND_FLAG(root, name) \
      root=snocString((root), (name))

#   define APPEND_FILESPEC(root, name)                \
      root = snocString ((root), (name))

#   define SET_BINARY_MODE(fd)                        \
      do {                                            \
         int retVal = setmode ( fileno ( fd ),        \
                                O_BINARY );           \
         ERROR_IF_MINUS_ONE ( retVal );               \
      } while ( 0 )
                                       
#define True  ((Bool)1)
#define False ((Bool)0)
typedef int IntNative;

#define SM_I2O           1
#define SM_F2O           2
#define SM_F2F           3
#define OM_Z             1
#define OM_UNZ           2
#define OM_TEST          3
#define FILE_NAME_LEN 1034


typedef
   struct {  } 
   UInt64;













#define BZ_N_SUFFIX_PAIRS 4




typedef
   struct zzzz {
      
      
   }
   Cell;



#define ISFLAG(s) (strcmp(aa->name, (s))==0)

IntNative main ( IntNative argc, Char *argv[] )
;
 