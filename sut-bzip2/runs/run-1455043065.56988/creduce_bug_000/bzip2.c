 







#define _BZLIB_H

#define BZ_RUN               0
#define BZ_FLUSH             1
#define BZ_FINISH            2

#define BZ_OK                0
#define BZ_RUN_OK            1
#define BZ_FLUSH_OK          2
#define BZ_FINISH_OK         3
#define BZ_STREAM_END        4
#define BZ_SEQUENCE_ERROR    
#define BZ_PARAM_ERROR       -2
#define BZ_MEM_ERROR         -3
#define BZ_DATA_ERROR        
#define BZ_DATA_ERROR_MAGIC  
#define BZ_IO_ERROR          
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
       
       
       
      void 
   );

BZ_EXTERN int BZ_APIBZ2_bzCompress ( 
      void 
   );

BZ_EXTERN int BZ_APIBZ2_bzCompressEnd ( 
      void 
   );

BZ_EXTERN int BZ_APIBZ2_bzDecompressInit ( 
       
       
      void
   );

BZ_EXTERN int BZ_APIBZ2_bzDecompress ( 
      void 
   );

BZ_EXTERN int BZ_APIBZ2_bzDecompressEnd ( 
      void 
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
       
      void 
   );

BZ_EXTERN void BZ_APIBZ2_bzReadGetUnused ( 
       
       
        
      void 
   );

BZ_EXTERN int BZ_APIBZ2_bzRead ( 
       
       
       
      void 
   );

BZ_EXTERN BZFILE* BZ_APIBZ2_bzWriteOpen ( 
      int*  bzerror,      
      FILE* f, 
      int   blockSize100k, 
      int   verbosity, 
      int   workFactor 
   );

BZ_EXTERN void BZ_APIBZ2_bzWrite ( 
       
       
       
      void 
   );

BZ_EXTERN void BZ_APIBZ2_bzWriteClose ( 
       
       
       
       
      void 
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
       
      
       
      
       
       
      void 
   );

BZ_EXTERN int BZ_APIBZ2_bzBuffToBuffDecompress ( 
       
      
       
      
       
      void 
   );




BZ_EXTERN const char * BZ_APIBZ2_bzlibVersion (
      void
   );

BZ_EXTERN BZFILE * BZ_APIBZ2_bzopen (
      
      void
   );

BZ_EXTERN BZFILE * BZ_APIBZ2_bzdopen (
      
      void
   );
         
BZ_EXTERN int BZ_APIBZ2_bzread (
       
       
      void 
   );

BZ_EXTERN int BZ_APIBZ2_bzwrite (
       
       
      void 
   );

BZ_EXTERN int BZ_APIBZ2_bzflush (
      void
   );

BZ_EXTERN void BZ_APIBZ2_bzclose (
      void
   );

BZ_EXTERN const char * BZ_APIBZ2_bzerror (
       
      void
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

#define True  1
#define False 0

#define __inline__  

extern void BZ2_bz__AssertH__fail ( void );
#define AssertH \
   
#define AssertD \
   
#define VPrintf0 \
   fprintf
#define VPrintf1 \
   fprintf
#define VPrintf2 \
   fprintf
#define VPrintf3 \
   fprintf
#define VPrintf4 \
   fprintf
#define VPrintf5 \
   fprintf


#define BZALLOCnnn strm->opaque,nnn,1
#define BZFREEppp  




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

#define BZ_RAND_MASK 

#define BZ_RAND_UPD_MASK                       \
   if                                             \
   s->rNToGo--;







#define BZ_INITIALISE_CRC              \


#define BZ_FINALISE_CRC                \


#define BZ_UPDATE_CRC              \






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





#define BZ_GET_FAST                     \
    s->tPos = s->tt[s->tPos];                 \
    cccc = ;           \
    s->tPos >>= 8;

#define BZ_GET_FAST_C                   \
    c_tPos = c_tt[c_tPos];                    \
    cccc = ;            \
    c_tPos >>= 8;

#define SET_LL4                                          \
   

#define GET_LL4                             \
   

#define SET_LL                          \
   

#define GET_LL \
   

#define BZ_GET_SMALL                            \
      cccc = BZ2_indexIntoF ;    \
      s->tPos = GET_LL;






extern Int32 
BZ2_decompress ( DState* );




























#define fswap \
   

#define fvswap       \



#define fmin 

#define fpush 

#define fpop 

#define FALLBACK_QSORT_SMALL_THRESH 10
#define FALLBACK_QSORT_STACK_SIZE   100




#undef fmin
#undef fpush
#undef fpop
#undef fswap
#undef fvswap
#undef FALLBACK_QSORT_SMALL_THRESH
#undef FALLBACK_QSORT_STACK_SIZE





#define       SET_BH  bhtab[ >> 5] |= 
#define     CLEAR_BH  bhtab[ >> 5] &= ~
#define     ISSET_BH  
#define      WORD_BH  bhtab[ >> 5]
#define UNALIGNED_BH  



#undef       SET_BH
#undef     CLEAR_BH
#undef     ISSET_BH
#undef      WORD_BH
#undef UNALIGNED_BH






















#define mswap \
   

#define mvswap       \




#define mmin  ?  : 

#define mpush 

#define mpop 


#define mnextsize 

#define mnextswap                                        \
   


#define MAIN_QSORT_SMALL_THRESH 20
#define MAIN_QSORT_DEPTH_THRESH 
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





#define BIGFREQ 
#define SETMASK 
#define CLEARMASK 



#undef BIGFREQ
#undef SETMASK
#undef CLEARMASK


















#define WEIGHTOF  
#define DEPTHOF   
#define MYMAX 

#define ADDWEIGHTS                           \
    |                    \
   

#define UPHEAP                                     \


#define DOWNHEAP                                   \



































































#define bsNEEDW                           \




















Int32 makeMaps_e_i;
EState * makeMaps_e_s;
static
void makeMaps_e ( void )
{
   
   makeMaps_e_s->nInUse = 0;
   for (makeMaps_e_i = 0; makeMaps_e_i < 256; makeMaps_e_i++)
      if (makeMaps_e_s->inUse[makeMaps_e_i]) 
         makeMaps_e_s->unseqToSeq[makeMaps_e_i] = makeMaps_e_s->nInUse;
         makeMaps_e_s->nInUse++;
      
}



UChar generateMTFValues_yy[256];
UChar generateMTFValues_yy_0;
Int32 generateMTFValues_i;
Int32 generateMTFValues_j;
Int32 generateMTFValues_zPend;
Int32 generateMTFValues_wr;
Int32 generateMTFValues_EOB;
UInt16 generateMTFValues_mtfv_0;
EState * generateMTFValues_s;
static
void generateMTFValues ( void )
{
   
   
   
   
   
   

   
   UInt32* ptr   = generateMTFValues_s->ptr;
   UChar* block  = generateMTFValues_s->block;
   UInt16* mtfv  = generateMTFValues_s->mtfv;
   

   ;
   generateMTFValues_EOB = generateMTFValues_s->nInUse+1;

   for (generateMTFValues_i = 0; generateMTFValues_i <= generateMTFValues_EOB; generateMTFValues_i++) generateMTFValues_s->mtfFreq[generateMTFValues_i] = 0;

   generateMTFValues_wr = 0;
   generateMTFValues_zPend = 0;
   for (generateMTFValues_i = 0; generateMTFValues_i < generateMTFValues_s->nInUse; generateMTFValues_i++) generateMTFValues_yy_0 =  generateMTFValues_i;

   for (generateMTFValues_i = 0; generateMTFValues_i < generateMTFValues_s->nblock; generateMTFValues_i++) 

   if (generateMTFValues_zPend > 0) 

   generateMTFValues_mtfv_0 = generateMTFValues_EOB; generateMTFValues_wr++; generateMTFValues_s->mtfFreq[generateMTFValues_EOB]++;

   generateMTFValues_s->nMTF = generateMTFValues_wr;
}



#define BZ_LESSER_ICOST  0
#define BZ_GREATER_ICOST 15























#define RETURN                               \
   ;

#define GET_BITS                     \
   case lll: s->state = lll;                      \
   while  

#define GET_UCHAR                        \
   GET_BITS

#define GET_BIT                          \
   GET_BITS


#define GET_MTF_VAL           \




Int32 BZ2_decompress ( DState* s )
;

















void BZ2_bz__AssertH__fail ( void )
;



static
int bz_config_ok 
;



static
void* default_bzalloc 
;

static
void default_bzfree (  void )
;



static
void prepare_new_block ( void )
;



static
void init_RL ( void )
;


static
Bool isempty_RL 
;



Int32 BZ2_bzCompressInit_n;
UInt32 *BZ2_bzCompressInit_s_8;
UInt16 *BZ2_bzCompressInit_s_10;
UChar *BZ2_bzCompressInit_s_9;
Int32 BZ2_bzCompressInit_s_12;
Int32 BZ2_bzCompressInit_s_28;
Int32 BZ2_bzCompressInit_s_18;
Int32 BZ2_bzCompressInit_s_30;
UInt32 BZ2_bzCompressInit_s_27;
Int32 BZ2_bzCompressInit_s_1;
Int32 BZ2_bzCompressInit_s_2;
UInt32 *BZ2_bzCompressInit_s_6;
UInt32 *BZ2_bzCompressInit_s_5;
UInt32 *BZ2_bzCompressInit_s_4;
bz_stream *BZ2_bzCompressInit_s_0;
int BZ_API(BZ2_bzCompressInit) 
                    ( bz_stream* strm, 
                     int        blockSize100k,
                     int        verbosity,
                     int        workFactor )
{
   
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
   BZ2_bzCompressInit_s_0 = strm;

   s->arr1 = NULL;
   s->arr2 = NULL;
   s->ftab = NULL;

   BZ2_bzCompressInit_n       = 100000 * blockSize100k;
   BZ2_bzCompressInit_s_4 = BZALLOC( BZ2_bzCompressInit_n                  * sizeof(UInt32) );
   BZ2_bzCompressInit_s_5 = BZALLOC (BZ2_bzCompressInit_n+BZ_N_OVERSHOOT) * sizeof(UInt32) ;
   BZ2_bzCompressInit_s_6 = BZALLOC( 65537              * sizeof(UInt32) );

   if (s->arr1 == NULL || s->arr2 == NULL || s->ftab == NULL) 

   s->blockNo           = 0;
   BZ2_bzCompressInit_s_2             = BZ_S_INPUT;
   BZ2_bzCompressInit_s_1              = BZ_M_RUNNING;
   BZ2_bzCompressInit_s_27       = 0;
   BZ2_bzCompressInit_s_30     = blockSize100k;
   BZ2_bzCompressInit_s_18         = 100000 * blockSize100k - 19;
   BZ2_bzCompressInit_s_28         = verbosity;
   BZ2_bzCompressInit_s_12        = workFactor;

   BZ2_bzCompressInit_s_9             = BZ2_bzCompressInit_s_5;
   BZ2_bzCompressInit_s_10              = BZ2_bzCompressInit_s_4;
   s->zbits             = NULL;
   BZ2_bzCompressInit_s_8               = BZ2_bzCompressInit_s_4;

   strm->state          = s;
   strm->total_in_lo32  = 0;
   strm->total_in_hi32  = 0;
   strm->total_out_lo32 = 0;
   strm->total_out_hi32 = 0;
   ;
   ;
   return BZ_OK;
}











#define ADD_CHAR_TO_BLOCK               \












static
Bool handle_compress 
;



Int32 BZ_APIBZ2_bzCompress_s_1;
bz_stream *BZ_APIBZ2_bzCompress_s_0;
int BZ_APIBZ2_bzCompress_action;
int BZ_APIBZ2_bzCompress ( void )
{
   bz_stream * strm = 0;
   
   EState* s;
   
   
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (BZ_APIBZ2_bzCompress_s_0 != strm) return BZ_PARAM_ERROR;

   preswitch:
   switch (BZ_APIBZ2_bzCompress_s_1) 
   return BZ_OK; 
}



bz_stream *BZ_APIBZ2_bzCompressEnd_s_0;
int BZ_APIBZ2_bzCompressEnd  ( void )
{
   bz_stream * strm = 0;
   EState* s;
   
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (BZ_APIBZ2_bzCompressEnd_s_0 != strm) return BZ_PARAM_ERROR;

   if (s->arr1 != NULL) BZFREE(s->arr1);
   if (s->arr2 != NULL) BZFREE(s->arr2);
   if (s->ftab != NULL) BZFREE(s->ftab);
   BZFREE(strm->state);

   strm->state = NULL;   

   return BZ_OK;
}







Int32 BZ2_bzDecompressInit_s_12;
Int32 BZ2_bzDecompressInit_s_11;
Bool BZ2_bzDecompressInit_s_10;
UInt32 BZ2_bzDecompressInit_s_26;
UInt32 BZ2_bzDecompressInit_s_7;
Int32 BZ2_bzDecompressInit_s_8;
Int32 BZ2_bzDecompressInit_s_1;
bz_stream *BZ2_bzDecompressInit_s_0;
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
   BZ2_bzDecompressInit_s_0                  = strm;
   strm->state              = s;
   BZ2_bzDecompressInit_s_1                 = BZ_X_MAGIC_1;
   BZ2_bzDecompressInit_s_8                = 0;
   BZ2_bzDecompressInit_s_7                = 0;
   BZ2_bzDecompressInit_s_26 = 0;
   strm->total_in_lo32      = 0;
   strm->total_in_hi32      = 0;
   strm->total_out_lo32     = 0;
   strm->total_out_hi32     = 0;
   BZ2_bzDecompressInit_s_10       = small;
   s->ll4                   = NULL;
   s->ll16                  = NULL;
   s->tt                    = NULL;
   BZ2_bzDecompressInit_s_11           = 0;
   BZ2_bzDecompressInit_s_12             = verbosity;

   return BZ_OK;
}



static
void unRLE_obuf_to_output_FAST ( void )
;








static
void unRLE_obuf_to_output_SMALL ( void )
;



bz_stream *BZ_APIBZ2_bzDecompress_s_0;
int BZ_APIBZ2_bzDecompress ( void )
{
   bz_stream * strm = 0;
   DState* s;
   
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (BZ_APIBZ2_bzDecompress_s_0 != strm) return BZ_PARAM_ERROR;

   while  

   AssertH ( 0, 6001 );

   return 0;  
}



bz_stream *BZ_APIBZ2_bzDecompressEnd_s_0;
int BZ_APIBZ2_bzDecompressEnd  ( void )
{
   bz_stream * strm = 0;
   DState* s;
   
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (BZ_APIBZ2_bzDecompressEnd_s_0 != strm) return BZ_PARAM_ERROR;

   if (s->tt   != NULL) BZFREE(s->tt);
   if (s->ll16 != NULL) BZFREE(s->ll16);
   if (s->ll4  != NULL) BZFREE(s->ll4);

   BZFREE(strm->state);
   strm->state = NULL;

   return BZ_OK;
}






#define BZ_SETERR                    \


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

   BZ_SETERR;

   if (f == NULL ||
       blockSize100k < 1 || blockSize100k > 9 ||
       workFactor < 0 || workFactor > 250 ||
       verbosity < 0 || verbosity > 4)
      ;

   if (ferror)
      ;

   bzf = malloc ;
   if (bzf == NULL)
      ;

   BZ_SETERR;
   bzf->initialisedOk = False;
   bzf->bufN          = 0;
   bzf->handle        = f;
   bzf->writing       = True;
   bzf->strm.bzalloc  = NULL;
   bzf->strm.bzfree   = NULL;
   bzf->strm.opaque   = NULL;

   if (workFactor == 0) workFactor = 30;
   ret = BZ2_bzCompressInit ;
   if (ret != BZ_OK)
      ;

   bzf->strm.avail_in = 0;
   bzf->initialisedOk = True;
   return bzf;   
}




Int32 BZ_APIBZ2_bzWrite_ret;
char *BZ_APIBZ2_bzWrite_bzf_4_4;
unsigned int BZ_APIBZ2_bzWrite_bzf_4_5;
char *BZ_APIBZ2_bzWrite_bzf_4_0;
unsigned int BZ_APIBZ2_bzWrite_bzf_4_1;
Bool BZ_APIBZ2_bzWrite_bzf_3;
int * BZ_APIBZ2_bzWrite_bzerror;
BZFILE * BZ_APIBZ2_bzWrite_b;
void BZ_APIBZ2_bzWrite
             (  
                
                
               void )
{
   int len = 0;
   void * buf = 0;
   
   bzFile* bzf = BZ_APIBZ2_bzWrite_b;
   
   
   
   
   

   BZ_SETERR;
   if (bzf == NULL || buf == NULL || len < 0)
      ;
   if (!BZ_APIBZ2_bzWrite_bzf_3)
      ;
   if (BZ_APIBZ2_bzWrite_bzerror)
      ;

   if (len == 0)
      ;

   BZ_APIBZ2_bzWrite_bzf_4_1 = len;
   BZ_APIBZ2_bzWrite_bzf_4_0  = buf;

   while (True) 
      BZ_APIBZ2_bzWrite_bzf_4_5 = BZ_MAX_UNUSED;
      BZ_APIBZ2_bzWrite_bzf_4_4 = bzf->buf;
      BZ_APIBZ2_bzWrite_ret = 0;
      if (BZ_APIBZ2_bzWrite_ret != BZ_RUN_OK)
         ;

      if (BZ_APIBZ2_bzWrite_bzf_4_5 < BZ_MAX_UNUSED) 

      if (BZ_APIBZ2_bzWrite_bzf_4_1 == 0)
         ;
   
}



void BZ_API(BZ2_bzWriteClose)
                  ( int*          bzerror, 
                    BZFILE*       b, 
                    int           abandon,
                    unsigned int* nbytes_in,
                    unsigned int* nbytes_out )
{
   BZ2_bzWriteClose64 ;
}


Bool BZ_APIBZ2_bzWriteClose64_bzf_3;
int * BZ_APIBZ2_bzWriteClose64_bzerror;
BZFILE * BZ_APIBZ2_bzWriteClose64_b;
void BZ_APIBZ2_bzWriteClose64
                  (  
                     
                    
                    
                    
                    
                    void )
{
   unsigned int * nbytes_out_hi32 = 0;
   unsigned int * nbytes_out_lo32 = 0;
   unsigned int * nbytes_in_hi32 = 0;
   unsigned int * nbytes_in_lo32 = 0;
   int abandon = 0;
   
   bzFile* bzf = BZ_APIBZ2_bzWriteClose64_b;
   

   if (bzf == NULL)
      ;
   if (!BZ_APIBZ2_bzWriteClose64_bzf_3)
      ;
   if (BZ_APIBZ2_bzWriteClose64_bzerror)
      ;

   if (nbytes_in_lo32 != NULL) *nbytes_in_lo32 = 0;
   if (nbytes_in_hi32 != NULL) *nbytes_in_hi32 = 0;
   if (nbytes_out_lo32 != NULL) *nbytes_out_lo32 = 0;
   if (nbytes_out_hi32 != NULL) *nbytes_out_hi32 = 0;

   if (!abandon && bzf->lastErr == BZ_OK) 

   if ( !abandon && !ferror  ) 

   if (nbytes_in_lo32 != NULL)
      *nbytes_in_lo32 = bzf->strm.total_in_lo32;
   if (nbytes_in_hi32 != NULL)
      *nbytes_in_hi32 = bzf->strm.total_in_hi32;
   if (nbytes_out_lo32 != NULL)
      *nbytes_out_lo32 = bzf->strm.total_out_lo32;
   if (nbytes_out_hi32 != NULL)
      *nbytes_out_hi32 = bzf->strm.total_out_hi32;

   BZ_SETERR;
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
   char *bzf_4_0;
   unsigned int bzf_4_1;
   Bool bzf_3;
   Int32 bzf_2;
   Bool bzf_6;
   int     ret;

   BZ_SETERR;

   if (f == NULL || 
       small != 0 && small != 1 ||
       verbosity < 0 || verbosity > 4 ||
       unused == NULL && nUnused != 0 ||
       unused != NULL && nUnused < 0 || nUnused > BZ_MAX_UNUSED)
      ;

   if (ferror)
      ;

   bzf = malloc ;
   if (bzf == NULL) 
      ;

   BZ_SETERR;

   bzf_6 = False;
   bzf->handle        = f;
   bzf_2          = 0;
   bzf_3       = False;
   bzf->strm.bzalloc  = NULL;
   bzf->strm.bzfree   = NULL;
   bzf->strm.opaque   = NULL;
   
   while (nUnused > 0) 

   ret = BZ2_bzDecompressInit ;
   if (ret != BZ_OK)
      ;

   bzf_4_1 = bzf_2;
   bzf_4_0  = bzf->buf;

   bzf_6 = True;
   return bzf;   
}



Bool BZ_APIBZ2_bzReadClose_bzf_6;
Bool BZ_APIBZ2_bzReadClose_bzf_3;
int * BZ_APIBZ2_bzReadClose_bzerror;
BZFILE * BZ_APIBZ2_bzReadClose_b;
void BZ_APIBZ2_bzReadClose (  void )
{
   bzFile* bzf = BZ_APIBZ2_bzReadClose_b;
   
   

   BZ_SETERR;
   if (bzf == NULL)
      ;

   if (BZ_APIBZ2_bzReadClose_bzf_3)
      ;

   if (BZ_APIBZ2_bzReadClose_bzf_6)
      0;
   0;
}



char *BZ_APIBZ2_bzRead_bzf_4_4;
unsigned int BZ_APIBZ2_bzRead_bzf_4_5;
Bool BZ_APIBZ2_bzRead_bzf_3;
int * BZ_APIBZ2_bzRead_bzerror;
BZFILE * BZ_APIBZ2_bzRead_b;
int BZ_APIBZ2_bzRead 
           (  
              
              
             void )
{
   int len = 0;
   void * buf = 0;
   
   bzFile* bzf = BZ_APIBZ2_bzRead_b;
   
   
   

   BZ_SETERR;

   if (bzf == NULL || buf == NULL || len < 0)
      ;

   if (BZ_APIBZ2_bzRead_bzf_3)
      ;

   if (len == 0)
      ;

   BZ_APIBZ2_bzRead_bzf_4_5 = len;
   BZ_APIBZ2_bzRead_bzf_4_4 = buf;

   while (True) 

   return 0; 
}



char *BZ_APIBZ2_bzReadGetUnused_bzf_4_0;
unsigned int BZ_APIBZ2_bzReadGetUnused_bzf_4_1;
Int32 BZ_APIBZ2_bzReadGetUnused_bzf_5;
int * BZ_APIBZ2_bzReadGetUnused_bzerror;
BZFILE * BZ_APIBZ2_bzReadGetUnused_b;
void BZ_APIBZ2_bzReadGetUnused 
                     (  
                        
                        
                       void )
{
   int * nUnused = 0;
   void ** unused = 0;
   bzFile* bzf = BZ_APIBZ2_bzReadGetUnused_b;
   
   
   
   if (bzf == NULL)
      ;
   if (BZ_APIBZ2_bzReadGetUnused_bzf_5 != BZ_STREAM_END)
      ;
   if (unused == NULL || nUnused == NULL)
      ;

   BZ_SETERR;
   *nUnused = BZ_APIBZ2_bzReadGetUnused_bzf_4_1;
   *unused = BZ_APIBZ2_bzReadGetUnused_bzf_4_0;
}







unsigned int BZ_APIBZ2_bzBuffToBuffCompress_strm_5;
unsigned int BZ_APIBZ2_bzBuffToBuffCompress_strm_1;
char *BZ_APIBZ2_bzBuffToBuffCompress_strm_4;
char *BZ_APIBZ2_bzBuffToBuffCompress_strm_0;
int BZ_APIBZ2_bzBuffToBuffCompress_ret;
unsigned int BZ_APIBZ2_bzBuffToBuffCompress_sourceLen;
int BZ_APIBZ2_bzBuffToBuffCompress 
                         (  
                           
                            
                           
                            
                            
                           void )
{
   int workFactor = 0;
   int verbosity = 0;
   int blockSize100k = 0;
   char * source = 0;
   unsigned int * destLen = 0;
   char * dest = 0;
   bz_stream strm;
   
   
   
   
   

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
   BZ_APIBZ2_bzBuffToBuffCompress_ret = 0;
   if (BZ_APIBZ2_bzBuffToBuffCompress_ret != BZ_OK) return BZ_APIBZ2_bzBuffToBuffCompress_ret;

   BZ_APIBZ2_bzBuffToBuffCompress_strm_0 = source;
   BZ_APIBZ2_bzBuffToBuffCompress_strm_4 = dest;
   BZ_APIBZ2_bzBuffToBuffCompress_strm_1 = BZ_APIBZ2_bzBuffToBuffCompress_sourceLen;
   BZ_APIBZ2_bzBuffToBuffCompress_strm_5 = *destLen;

   BZ_APIBZ2_bzBuffToBuffCompress_ret = 0;
   if (BZ_APIBZ2_bzBuffToBuffCompress_ret == BZ_FINISH_OK) goto output_overflow;
   if (BZ_APIBZ2_bzBuffToBuffCompress_ret != BZ_STREAM_END) goto errhandler;

   
   *destLen -= BZ_APIBZ2_bzBuffToBuffCompress_strm_5;   
   0;
   return BZ_OK;

   output_overflow:
   0;
   return BZ_OUTBUFF_FULL;

   errhandler:
   0;
   return BZ_APIBZ2_bzBuffToBuffCompress_ret;
}



unsigned int BZ_APIBZ2_bzBuffToBuffDecompress_strm_5;
unsigned int BZ_APIBZ2_bzBuffToBuffDecompress_strm_1;
char *BZ_APIBZ2_bzBuffToBuffDecompress_strm_4;
char *BZ_APIBZ2_bzBuffToBuffDecompress_strm_0;
int BZ_APIBZ2_bzBuffToBuffDecompress_ret;
unsigned int BZ_APIBZ2_bzBuffToBuffDecompress_sourceLen;
int BZ_APIBZ2_bzBuffToBuffDecompress 
                           (  
                             
                              
                             
                             
                             void )
{
   int verbosity = 0;
   int small = 0;
   char * source = 0;
   unsigned int * destLen = 0;
   char * dest = 0;
   bz_stream strm;
   
   
   
   
   

   if (dest == NULL || destLen == NULL || 
       source == NULL ||
       small != 0 && small != 1 ||
       verbosity < 0 || verbosity > 4) 
          return BZ_PARAM_ERROR;

   strm.bzalloc = NULL;
   strm.bzfree = NULL;
   strm.opaque = NULL;
   BZ_APIBZ2_bzBuffToBuffDecompress_ret = 0;
   if (BZ_APIBZ2_bzBuffToBuffDecompress_ret != BZ_OK) return BZ_APIBZ2_bzBuffToBuffDecompress_ret;

   BZ_APIBZ2_bzBuffToBuffDecompress_strm_0 = source;
   BZ_APIBZ2_bzBuffToBuffDecompress_strm_4 = dest;
   BZ_APIBZ2_bzBuffToBuffDecompress_strm_1 = BZ_APIBZ2_bzBuffToBuffDecompress_sourceLen;
   BZ_APIBZ2_bzBuffToBuffDecompress_strm_5 = *destLen;

   BZ_APIBZ2_bzBuffToBuffDecompress_ret = 0;
   if (BZ_APIBZ2_bzBuffToBuffDecompress_ret == BZ_OK) goto output_overflow_or_eof;
   if (BZ_APIBZ2_bzBuffToBuffDecompress_ret != BZ_STREAM_END) goto errhandler;

   
   *destLen -= BZ_APIBZ2_bzBuffToBuffDecompress_strm_5;
   0;
   return BZ_OK;

   output_overflow_or_eof:
   if (BZ_APIBZ2_bzBuffToBuffDecompress_strm_5 > 0) {
      0;
      return BZ_UNEXPECTED_EOF;
   } else ;      

   errhandler:
   0;
   return BZ_APIBZ2_bzBuffToBuffDecompress_ret; 
}








const char * BZ_APIBZ2_bzlibVersion(void)
{
   return BZ_VERSION;
}




static
BZFILE * bzopen_or_bzdopen
               (    
                              
                 
                 void)      
;




const char * BZ_APIBZ2_bzopen_path;
const char * BZ_APIBZ2_bzopen_mode;
BZFILE * BZ_APIBZ2_bzopen
               ( 
                 void )
{
   return 0;
}



int BZ_APIBZ2_bzdopen_fd;
const char * BZ_APIBZ2_bzdopen_mode;
BZFILE * BZ_APIBZ2_bzdopen
               ( 
                 void )
{
   return bzopen_or_bzdopen;
}



int BZ_APIBZ2_bzread_bzerr;
int BZ_APIBZ2_bzread_nread;
BZFILE * BZ_APIBZ2_bzread_b;
void * BZ_APIBZ2_bzread_buf;
int BZ_APIBZ2_bzread_len;
int BZ_APIBZ2_bzread (  void )
{
   
   if (((bzFile*)BZ_APIBZ2_bzread_b)->lastErr == BZ_STREAM_END) return 0;
   BZ_APIBZ2_bzread_nread = 0;
   if (BZ_APIBZ2_bzread_bzerr == BZ_OK || BZ_APIBZ2_bzread_bzerr == BZ_STREAM_END) 
      return BZ_APIBZ2_bzread_nread;
    else 
      return -1;
   
}



BZFILE * BZ_APIBZ2_bzwrite_b;
void * BZ_APIBZ2_bzwrite_buf;
int BZ_APIBZ2_bzwrite_len;
int BZ_APIBZ2_bzwrite (  void )
{
   int bzerr;

   ;
   if(bzerr == BZ_OK)
      return BZ_APIBZ2_bzwrite_len;
   else
      return -1;
   
}



BZFILE * BZ_APIBZ2_bzflush_b;
int BZ_APIBZ2_bzflush (void)
{
   
   return 0;
}



int BZ_APIBZ2_bzclose_bzerr;
void BZ_APIBZ2_bzclose (void)
{
      BZFILE * b = 0;
   
   FILE *fp = ((bzFile *)b)->handle;
   
   if (b==NULL) 
   if(((bzFile*)b)->writing)
      BZ2_bzWriteClose;
      if(BZ_APIBZ2_bzclose_bzerr != BZ_OK)
         BZ2_bzWriteClose;
      
   else
   if(fp!=stdin && fp!=stdout)
      fclose;
   
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
static char *bzerrorstrings_0 = "OK";


BZFILE * BZ_APIBZ2_bzerror_b;
int * BZ_APIBZ2_bzerror_errnum;
const char * BZ_APIBZ2_bzerror ( void)
{
   int err = ((bzFile *)BZ_APIBZ2_bzerror_b)->lastErr;

   if(err>0) err = 0;
   *BZ_APIBZ2_bzerror_errnum = err;
   return bzerrorstrings_0;
}




























#define BZ_UNIX      1


#define BZ_LCCWIN32  0





#include <signal.h>
#include <errno.h>

#define ERROR_IF_EOF       
#define ERROR_IF_NOT_ZERO  
#define ERROR_IF_MINUS_ONE 





#if BZ_UNIX
#   include <fcntl.h>
#   include <utime.h>

#   define PATH_SEP    '/'
#   define MY_LSTAT    lstat
#   define MY_STAT     stat
#   define MY_S_ISREG  S_ISREG
#   define MY_S_ISDIR  S_ISDIR

#   define APPEND_FILESPEC \
      root=snocString

#   define APPEND_FLAG \
      root=snocString

#   define SET_BINARY_MODE 

#      define NORETURN 

#endif 





                                       
#define True  
#define False 


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



















#define ISFLAG 

IntNative main 
;




 