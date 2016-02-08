 







#define _BZLIB_H

#define BZ_RUN               0
#define BZ_FLUSH             1
#define BZ_FINISH            2

#define BZ_OK                0
#define BZ_RUN_OK            1
#define BZ_FLUSH_OK          2
#define BZ_FINISH_OK         3
#define BZ_STREAM_END        4
#define BZ_SEQUENCE_ERROR    -1
#define BZ_PARAM_ERROR       -2
#define BZ_MEM_ERROR         -3
#define BZ_DATA_ERROR        -4
#define BZ_DATA_ERROR_MAGIC  -5
#define BZ_IO_ERROR          -6
#define BZ_UNEXPECTED_EOF    -7
#define BZ_OUTBUFF_FULL      -8
#define BZ_CONFIG_ERROR      -9

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




BZ_EXTERN int BZ_APIBZ2_bzCompressInit ( 
      bz_stream* strm, 
      int        blockSize100k, 
      int        verbosity, 
      int        workFactor 
   );

BZ_EXTERN int BZ_APIBZ2_bzCompress ( 
      bz_stream* strm, 
      int action 
   );

BZ_EXTERN int BZ_APIBZ2_bzCompressEnd ( 
      bz_stream* strm 
   );

BZ_EXTERN int BZ_APIBZ2_bzDecompressInit ( 
      bz_stream *strm, 
      int       verbosity, 
      int       small
   );

BZ_EXTERN int BZ_APIBZ2_bzDecompress ( 
      bz_stream* strm 
   );

BZ_EXTERN int BZ_APIBZ2_bzDecompressEnd ( 
      bz_stream *strm 
   );





#define BZ_MAX_UNUSED 5000

typedef void BZFILE;

BZ_EXTERN BZFILE* BZ_APIBZ2_bzReadOpen ( 
      int*  bzerror,   
      FILE* f, 
      int   verbosity, 
      int   small,
      void* unused,    
      int   nUnused 
   );

BZ_EXTERN void BZ_APIBZ2_bzReadClose ( 
      int*    bzerror, 
      BZFILE* b 
   );

BZ_EXTERN void BZ_APIBZ2_bzReadGetUnused ( 
      int*    bzerror, 
      BZFILE* b, 
      void**  unused,  
      int*    nUnused 
   );

BZ_EXTERN int BZ_APIBZ2_bzRead ( 
      int*    bzerror, 
      BZFILE* b, 
      void*   buf, 
      int     len 
   );

BZ_EXTERN BZFILE* BZ_APIBZ2_bzWriteOpen ( 
      int*  bzerror,      
      FILE* f, 
      int   blockSize100k, 
      int   verbosity, 
      int   workFactor 
   );

BZ_EXTERN void BZ_APIBZ2_bzWrite ( 
      int*    bzerror, 
      BZFILE* b, 
      void*   buf, 
      int     len 
   );

BZ_EXTERN void BZ_APIBZ2_bzWriteClose ( 
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




BZ_EXTERN int BZ_APIBZ2_bzBuffToBuffCompress ( 
      char*         dest, 
      unsigned int* destLen,
      char*         source, 
      unsigned int  sourceLen,
      int           blockSize100k, 
      int           verbosity, 
      int           workFactor 
   );

BZ_EXTERN int BZ_APIBZ2_bzBuffToBuffDecompress ( 
      char*         dest, 
      unsigned int* destLen,
      char*         source, 
      unsigned int  sourceLen,
      int           small, 
      int           verbosity 
   );




BZ_EXTERN const char * BZ_APIBZ2_bzlibVersion (
      void
   );

BZ_EXTERN BZFILE * BZ_APIBZ2_bzopen (
      const char *path,
      const char *mode
   );

BZ_EXTERN BZFILE * BZ_APIBZ2_bzdopen (
      int        fd,
      const char *mode
   );
         
BZ_EXTERN int BZ_APIBZ2_bzread (
      BZFILE* b, 
      void* buf, 
      int len 
   );

BZ_EXTERN int BZ_APIBZ2_bzwrite (
      BZFILE* b, 
      void*   buf, 
      int     len 
   );

BZ_EXTERN int BZ_APIBZ2_bzflush (
      BZFILE* b
   );

BZ_EXTERN void BZ_APIBZ2_bzclose (
      BZFILE* b
   );

BZ_EXTERN const char * BZ_APIBZ2_bzerror (
      BZFILE *b, 
      int    *errnum
   );









#define _BZLIB_PRIVATE_H

#include <stdlib.h>




#define BZ_VERSION  "1.0.2, 30-Dec-2001"

typedef char            Char;
typedef unsigned char   Bool;
typedef unsigned char   UChar;
typedef int             Int32;
typedef unsigned int    UInt32;
typedef short           Int16;
typedef unsigned short  UInt16;

#define True  (Bool)1
#define False (Bool)0

#define __inline__  

extern void BZ2_bz__AssertH__fail ( int errcode );
#define AssertHcond,errcode \
   
#define AssertDcond,msg \
   
#define VPrintf0zf \
   fprintfstderr,zf
#define VPrintf1zf,za1 \
   fprintfstderr,zf,za1
#define VPrintf2zf,za1,za2 \
   fprintfstderr,zf,za1,za2
#define VPrintf3zf,za1,za2,za3 \
   fprintfstderr,zf,za1,za2,za3
#define VPrintf4zf,za1,za2,za3,za4 \
   fprintfstderr,zf,za1,za2,za3,za4
#define VPrintf5zf,za1,za2,za3,za4,za5 \
   fprintfstderr,zf,za1,za2,za3,za4,za5


#define BZALLOCnnn strm->bzallocstrm->opaque,nnn,1
#define BZFREEppp  strm->bzfreestrm->opaque,ppp




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

#define BZ_MAX_SELECTORS 2 + 900000 / BZ_G_SIZE







#define BZ_RAND_DECLS                          \
   Int32 rNToGo;                               \
   Int32 rTPos                                 \

#define BZ_RAND_INIT_MASK                      \
   s->rNToGo = 0;                              \
   s->rTPos  = 0                               \

#define BZ_RAND_MASK s->rNToGo == 1 ? 1 : 0

#define BZ_RAND_UPD_MASK                       \
   if s->rNToGo == 0                                            \
   s->rNToGo--;







#define BZ_INITIALISE_CRCcrcVar              \


#define BZ_FINALISE_CRCcrcVar                \


#define BZ_UPDATE_CRCcrcVar,cha              \






#define BZ_M_IDLE      1
#define BZ_M_RUNNING   2
#define BZ_M_FLUSHING  3
#define BZ_M_FINISHING 4

#define BZ_S_OUTPUT    1
#define BZ_S_INPUT     2

#define BZ_N_RADIX 2
#define BZ_N_QSORT 12
#define BZ_N_SHELL 18
#define BZ_N_OVERSHOOT BZ_N_RADIX + BZ_N_QSORT + BZ_N_SHELL + 2






typedef
   struct {
      
      bz_stream* strm;

      
      
      Int32    mode;
      Int32    state;

      
      UInt32   avail_in_expect;

      
      UInt32*  arr1;
      UInt32*  arr2;
      UInt32*  ftab;
      Int32    origPtr;

      
      UInt32*  ptr;
      UChar*   block;
      UInt16*  mtfv;
      UChar*   zbits;

      
      Int32    workFactor;

      
      UInt32   state_in_ch;
      Int32    state_in_len;
      BZ_RAND_DECLS;

      
      Int32    nblock;
      Int32    nblockMAX;
      Int32    numZ;
      Int32    state_out_pos;

      
      Int32    nInUse;
      Bool     inUse[256];
      UChar    unseqToSeq[256];

      
      UInt32   bsBuff;
      Int32    bsLive;

      
      UInt32   blockCRC;
      UInt32   combinedCRC;

      
      Int32    verbosity;
      Int32    blockNo;
      Int32    blockSize100k;

      
      Int32    nMTF;
      Int32    mtfFreq    [BZ_MAX_ALPHA_SIZE];
      UChar    selector   [BZ_MAX_SELECTORS];
      UChar    selectorMtf[BZ_MAX_SELECTORS];

      UChar    len     [BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
      Int32    code    [BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
      Int32    rfreq   [BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
      
      UInt32   len_pack[BZ_MAX_ALPHA_SIZE][4];

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

      
      UChar    state_out_ch;
      Int32    state_out_len;
      Bool     blockRandomised;
      BZ_RAND_DECLS;

      
      UInt32   bsBuff;
      Int32    bsLive;

      
      Int32    blockSize100k;
      Bool     smallDecompress;
      Int32    currBlockNo;
      Int32    verbosity;

      
      Int32    origPtr;
      UInt32   tPos;
      Int32    k0;
      Int32    unzftab[256];
      Int32    nblock_used;
      Int32    cftab[257];
      Int32    cftabCopy[257];

      
      UInt32   *tt;

      
      UInt16   *ll16;
      UChar    *ll4;

      
      UInt32   storedBlockCRC;
      UInt32   storedCombinedCRC;
      UInt32   calculatedBlockCRC;
      UInt32   calculatedCombinedCRC;

      
      Int32    nInUse;
      Bool     inUse[256];
      Bool     inUse16[16];
      UChar    seqToUnseq[256];

      
      UChar    mtfa   [MTFA_SIZE];
      Int32    mtfbase[256 / MTFL_SIZE];
      UChar    selector   [BZ_MAX_SELECTORS];
      UChar    selectorMtf[BZ_MAX_SELECTORS];
      UChar    len  [BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];

      Int32    limit  [BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
      Int32    base   [BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
      Int32    perm   [BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
      Int32    minLens[BZ_N_GROUPS];

      
      Int32    save_i;
      Int32    save_j;
      Int32    save_t;
      Int32    save_alphaSize;
      Int32    save_nGroups;
      Int32    save_nSelectors;
      Int32    save_EOB;
      Int32    save_groupNo;
      Int32    save_groupPos;
      Int32    save_nextSym;
      Int32    save_nblockMAX;
      Int32    save_nblock;
      Int32    save_es;
      Int32    save_N;
      Int32    save_curr;
      Int32    save_zt;
      Int32    save_zn; 
      Int32    save_zvec;
      Int32    save_zj;
      Int32    save_gSel;
      Int32    save_gMinlen;
      Int32*   save_gLimit;
      Int32*   save_gBase;
      Int32*   save_gPerm;

   }
   DState;





#define BZ_GET_FASTcccc                     \
    s->tPos = s->tt[s->tPos];                 \
    cccc = UChars->tPos & 0xff;           \
    s->tPos >>= 8;

#define BZ_GET_FAST_Ccccc                   \
    c_tPos = c_tt[c_tPos];                    \
    cccc = UCharc_tPos & 0xff;            \
    c_tPos >>= 8;

#define SET_LL4i,n                                          \
   

#define GET_LL4i                             \
   UInt32s->ll4[i >> 1] >> i  2 & 0x4 & 0xF

#define SET_LLi,n                          \
   

#define GET_LLi \
   UInt32s-ll16[i] | GET_LL4i  16

#define BZ_GET_SMALLcccc                            \
      cccc = BZ2_indexIntoF  s-tPos, s-cftab ;    \
      s-tPos = GET_LLs->tPos;






extern Int32 
BZ2_decompress ( DState* );




























#define fswapzz1, zz2 \
   

#define fvswapzzp1, zzp2, zzn       \



#define fmina,b a  b ? a : b

#define fpushlz,hz 

#define fpoplz,hz 

#define FALLBACK_QSORT_SMALL_THRESH 10
#define FALLBACK_QSORT_STACK_SIZE   100




#undef fmin
#undef fpush
#undef fpop
#undef fswap
#undef fvswap
#undef FALLBACK_QSORT_SMALL_THRESH
#undef FALLBACK_QSORT_STACK_SIZE





#define       SET_BHzz  bhtab[zz > 5] |= 1  zz & 31
#define     CLEAR_BHzz  bhtab[zz  5] &= ~1  zz & 31
#define     ISSET_BHzz  bhtab[zz  5] & 1  zz & 31
#define      WORD_BHzz  bhtab[zz  5]
#define UNALIGNED_BHzz  zz & 0x01f



#undef       SET_BH
#undef     CLEAR_BH
#undef     ISSET_BH
#undef      WORD_BH
#undef UNALIGNED_BH






















#define mswapzz1, zz2 \
   

#define mvswapzzp1, zzp2, zzn       \




#define mmina,b a < b ? a : b

#define mpushlz,hz,dz 

#define mpoplz,hz,dz 


#define mnextsizeaz nextHi[az]-nextLo[az]

#define mnextswapaz,bz                                        \
   


#define MAIN_QSORT_SMALL_THRESH 20
#define MAIN_QSORT_DEPTH_THRESH BZ_N_RADIX + BZ_N_QSORT
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





#define BIGFREQb ftab[b+1 << 8] - ftab[b << 8]
#define SETMASK 1 < 21
#define CLEARMASK ~SETMASK



#undef BIGFREQ
#undef SETMASK
#undef CLEARMASK


















#define WEIGHTOFzz0  zz0 & 0xffffff00
#define DEPTHOFzz1   zz1 & 0x000000ff
#define MYMAXzz2,zz3 zz2  zz3 ? zz2 : zz3

#define ADDWEIGHTSzw1,zw2                           \
   WEIGHTOFzw1+WEIGHTOFzw2 |                    \
   1 + MYMAXDEPTHOFzw1,DEPTHOFzw2

#define UPHEAPz                                     \


#define DOWNHEAPz                                   \



































































#define bsNEEDWnz                           \




















static
void makeMaps_e ( EState* s )
{
   Int32 i;
   s->nInUse = 0;
   for (i = 0; i < 256; i++)
      if (s->inUse[i]) {
         s->unseqToSeq[i] = s->nInUse;
         s->nInUse++;
      }
}



static
void generateMTFValues ( EState* s )
{
   UChar   yy[256];
   Int32   i, j;
   Int32   zPend;
   Int32   wr;
   Int32   EOB;

   
   UInt32* ptr   = s->ptr;
   UChar* block  = s->block;
   UInt16* mtfv  = s->mtfv;

   ;
   EOB = s->nInUse+1;

   for (i = 0; i <= EOB; i++) s->mtfFreq[i] = 0;

   wr = 0;
   zPend = 0;
   for (i = 0; i < s->nInUse; i++) yy[i] = (UChar) i;

   for (i = 0; i < s->nblock; i++) {
      UChar ll_i;
      AssertD ( wr <= i, "generateMTFValues1" );
      j = ptr[i]-1; if (j < 0) j += s->nblock;
      ll_i = s->unseqToSeq[block[j]];
      AssertD ( ll_i < s->nInUse, "generateMTFValues2a" );

      if (yy[0] == ll_i) { 
         zPend++;
      } else {

         if (zPend > 0) 
         {
            register UChar  rtmp;
            register UChar* ryy_j;
            register UChar  rll_i;
            rtmp  = yy[1];
            yy[1] = yy[0];
            ryy_j = &yy[1];
            rll_i = ll_i;
            while ( rll_i != rtmp ) ;
            yy[0] = rtmp;
            j = ryy_j - &yy[0];
            mtfv[wr] = j+1; wr++; s->mtfFreq[j+1]++;
         }

      }
   }

   if (zPend > 0) 

   mtfv[wr] = EOB; wr++; s->mtfFreq[EOB]++;

   s->nMTF = wr;
}



#define BZ_LESSER_ICOST  0
#define BZ_GREATER_ICOST 15























#define RETURNrrr                               \
   ;

#define GET_BITSlll,vvv,nnn                     \
   case lll: s->state = lll;                      \
   while True 

#define GET_UCHARlll,uuu                        \
   GET_BITSlll,uuu,8

#define GET_BITlll,uuu                          \
   GET_BITSlll,uuu,1


#define GET_MTF_VALlabel1,label2,lval           \




Int32 BZ2_decompress ( DState* s )
;

















void BZ2_bz__AssertH__fail ( int errcode )
;



static
int bz_config_ok ( void )
;



static
void* default_bzalloc ( void* opaque, Int32 items, Int32 size )
;

static
void default_bzfree ( void* opaque, void* addr )
;



static
void prepare_new_block ( EState* s )
;



static
void init_RL ( EState* s )
;


static
Bool isempty_RL ( EState* s )
;



int BZ_APIBZ2_bzCompressInit 
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
   s->arr2 = BZALLOC (n+BZ_N_OVERSHOOT) * sizeof(UInt32) ;
   s->ftab = BZALLOC( 65537              * sizeof(UInt32) );

   if (s->arr1 == NULL || s->arr2 == NULL || s->ftab == NULL) 

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











#define ADD_CHAR_TO_BLOCKzs,zchh0               \












static
Bool handle_compress ( bz_stream* strm )
;



int BZ_APIBZ2_bzCompress ( bz_stream *strm, int action )
{
   
   EState* s;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (s->strm != strm) return BZ_PARAM_ERROR;

   preswitch:
   switch (s->mode) 
   return BZ_OK; 
}



int BZ_APIBZ2_bzCompressEnd  ( bz_stream *strm )
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







int BZ_APIBZ2_bzDecompressInit 
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



static
void unRLE_obuf_to_output_FAST ( DState* s )
;








static
void unRLE_obuf_to_output_SMALL ( DState* s )
;



int BZ_APIBZ2_bzDecompress ( bz_stream *strm )
{
   DState* s;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (s->strm != strm) return BZ_PARAM_ERROR;

   while (True) 

   AssertH ( 0, 6001 );

   return 0;  
}



int BZ_APIBZ2_bzDecompressEnd  ( bz_stream *strm )
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






#define BZ_SETERReee                    \


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







BZFILE* BZ_APIBZ2_bzWriteOpen 
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
       blockSize100k < 1 || blockSize100k > 9 ||
       workFactor < 0 || workFactor > 250 ||
       verbosity < 0 || verbosity > 4)
      ;

   if (ferror(f))
      ;

   bzf = malloc ( sizeof(bzFile) );
   if (bzf == NULL)
      ;

   BZ_SETERR(BZ_OK);
   bzf->initialisedOk = False;
   bzf->bufN          = 0;
   bzf->handle        = f;
   bzf->writing       = True;
   bzf->strm.bzalloc  = NULL;
   bzf->strm.bzfree   = NULL;
   bzf->strm.opaque   = NULL;

   if (workFactor == 0) workFactor = 30;
   ret = BZ2_bzCompressInit ( &bzf->strm, blockSize100k, 
                              verbosity, workFactor );
   if (ret != BZ_OK)
      ;

   bzf->strm.avail_in = 0;
   bzf->initialisedOk = True;
   return bzf;   
}




void BZ_APIBZ2_bzWrite
             ( int*    bzerror, 
               BZFILE* b, 
               void*   buf, 
               int     len )
{
   Int32   ret;
   bzFile* bzf = (bzFile*)b;

   BZ_SETERR(BZ_OK);
   if (bzf == NULL || buf == NULL || len < 0)
      ;
   if (!bzf->writing)
      ;
   if (ferror(bzf->handle))
      ;

   if (len == 0)
      ;

   bzf->strm.avail_in = len;
   bzf->strm.next_in  = buf;

   while (True) {
      bzf->strm.avail_out = BZ_MAX_UNUSED;
      bzf->strm.next_out = bzf->buf;
      ret = 0;
      if (ret != BZ_RUN_OK)
         ;

      if (bzf->strm.avail_out < BZ_MAX_UNUSED) 

      if (bzf->strm.avail_in == 0)
         ;
   }
}



void BZ_APIBZ2_bzWriteClose
                  ( int*          bzerror, 
                    BZFILE*       b, 
                    int           abandon,
                    unsigned int* nbytes_in,
                    unsigned int* nbytes_out )
{
   BZ2_bzWriteClose64 ( bzerror, b, abandon, 
                        nbytes_in, NULL, nbytes_out, NULL );
}


void BZ_APIBZ2_bzWriteClose64
                  ( int*          bzerror, 
                    BZFILE*       b, 
                    int           abandon,
                    unsigned int* nbytes_in_lo32,
                    unsigned int* nbytes_in_hi32,
                    unsigned int* nbytes_out_lo32,
                    unsigned int* nbytes_out_hi32 )
{
   
   bzFile* bzf = (bzFile*)b;

   if (bzf == NULL)
      ;
   if (!bzf->writing)
      ;
   if (ferror(bzf->handle))
      ;

   if (nbytes_in_lo32 != NULL) *nbytes_in_lo32 = 0;
   if (nbytes_in_hi32 != NULL) *nbytes_in_hi32 = 0;
   if (nbytes_out_lo32 != NULL) *nbytes_out_lo32 = 0;
   if (nbytes_out_hi32 != NULL) *nbytes_out_hi32 = 0;

   if (!abandon && bzf->lastErr == BZ_OK) 

   if ( !abandon && !ferror ( bzf->handle ) ) 

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
   0;
}



BZFILE* BZ_APIBZ2_bzReadOpen 
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
       small != 0 && small != 1 ||
       verbosity < 0 || verbosity > 4 ||
       unused == NULL && nUnused != 0 ||
       unused != NULL && nUnused < 0 || nUnused > BZ_MAX_UNUSED)
      ;

   if (ferror(f))
      ;

   bzf = malloc ( sizeof(bzFile) );
   if (bzf == NULL) 
      ;

   BZ_SETERR(BZ_OK);

   bzf->initialisedOk = False;
   bzf->handle        = f;
   bzf->bufN          = 0;
   bzf->writing       = False;
   bzf->strm.bzalloc  = NULL;
   bzf->strm.bzfree   = NULL;
   bzf->strm.opaque   = NULL;
   
   while (nUnused > 0) 

   ret = BZ2_bzDecompressInit ( &bzf->strm, verbosity, small );
   if (ret != BZ_OK)
      ;

   bzf->strm.avail_in = bzf->bufN;
   bzf->strm.next_in  = bzf->buf;

   bzf->initialisedOk = True;
   return bzf;   
}



void BZ_APIBZ2_bzReadClose ( int *bzerror, BZFILE *b )
{
   bzFile* bzf = (bzFile*)b;

   BZ_SETERR(BZ_OK);
   if (bzf == NULL)
      ;

   if (bzf->writing)
      ;

   if (bzf->initialisedOk)
      (void)0;
   0;
}



int BZ_APIBZ2_bzRead 
           ( int*    bzerror, 
             BZFILE* b, 
             void*   buf, 
             int     len )
{
   
   bzFile* bzf = (bzFile*)b;

   BZ_SETERR(BZ_OK);

   if (bzf == NULL || buf == NULL || len < 0)
      ;

   if (bzf->writing)
      ;

   if (len == 0)
      ;

   bzf->strm.avail_out = len;
   bzf->strm.next_out = buf;

   while (True) 

   return 0; 
}



void BZ_APIBZ2_bzReadGetUnused 
                     ( int*    bzerror, 
                       BZFILE* b, 
                       void**  unused, 
                       int*    nUnused )
{
   bzFile* bzf = (bzFile*)b;
   if (bzf == NULL)
      ;
   if (bzf->lastErr != BZ_STREAM_END)
      ;
   if (unused == NULL || nUnused == NULL)
      ;

   BZ_SETERR(BZ_OK);
   *nUnused = bzf->strm.avail_in;
   *unused = bzf->strm.next_in;
}







int BZ_APIBZ2_bzBuffToBuffCompress 
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



int BZ_APIBZ2_bzBuffToBuffDecompress 
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
       small != 0 && small != 1 ||
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
   } else ;      

   errhandler:
   0;
   return ret; 
}








const char * BZ_APIBZ2_bzlibVersion(void)
{
   return BZ_VERSION;
}




static
BZFILE * bzopen_or_bzdopen
               ( const char *path,   
                 int fd,             
                 const char *mode,
                 int open_mode)      
;




BZFILE * BZ_APIBZ2_bzopen
               ( const char *path,
                 const char *mode )
{
   return 0;
}



BZFILE * BZ_APIBZ2_bzdopen
               ( int fd,
                 const char *mode )
{
   return bzopen_or_bzdopen(NULL,fd,mode,1);
}



int BZ_APIBZ2_bzread (BZFILE* b, void* buf, int len )
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



int BZ_APIBZ2_bzwrite (BZFILE* b, void* buf, int len )
{
   int bzerr;

   ;
   if(bzerr == BZ_OK){
      return len;
   }else{
      return -1;
   }
}



int BZ_APIBZ2_bzflush (BZFILE *b)
{
   
   return 0;
}



void BZ_APIBZ2_bzclose (BZFILE* b)
{
   int bzerr;
   FILE *fp = ((bzFile *)b)->handle;
   
   if (b==NULL) 
   if(((bzFile*)b)->writing){
      BZ2_bzWriteClose(&bzerr,b,0,NULL,NULL);
      if(bzerr != BZ_OK){
         BZ2_bzWriteClose(NULL,b,1,NULL,NULL);
      }
   }else
   if(fp!=stdin && fp!=stdout){
      fclose(fp);
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


const char * BZ_APIBZ2_bzerror (BZFILE *b, int *errnum)
{
   int err = ((bzFile *)b)->lastErr;

   if(err>0) err = 0;
   *errnum = err;
   return bzerrorstrings[err*-1];
}




























#define BZ_UNIX      1


#define BZ_LCCWIN32  0





#include <signal.h>
#include <errno.h>

#define ERROR_IF_EOFi       
#define ERROR_IF_NOT_ZEROi  
#define ERROR_IF_MINUS_ONEi 





#if BZ_UNIX
#   include <fcntl.h>
#   include <utime.h>

#   define PATH_SEP    '/'
#   define MY_LSTAT    lstat
#   define MY_STAT     stat
#   define MY_S_ISREG  S_ISREG
#   define MY_S_ISDIR  S_ISDIR

#   define APPEND_FILESPECroot, name \
      root=snocStringroot, name

#   define APPEND_FLAGroot, name \
      root=snocStringroot, name

#   define SET_BINARY_MODEfd 

#      define NORETURN 

#endif 





                                       
#define True  Bool1
#define False Bool0


typedef int IntNative;













#define SM_I2O           1
#define SM_F2O           2
#define SM_F2F           3


#define OM_Z             1
#define OM_UNZ           2
#define OM_TEST          3




#define FILE_NAME_LEN 1034




























typedef
   struct  
   UInt64;





























































































































#if BZ_UNIX

#endif












#define BZ_N_SUFFIX_PAIRS 4




































typedef
   struct zzzz 
   Cell;



















#define ISFLAGs strcmpaa->name, s==0

IntNative main ( IntNative argc, Char *argv[] )
;




 