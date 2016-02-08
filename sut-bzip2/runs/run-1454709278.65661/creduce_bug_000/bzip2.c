 







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
#define BZ_PARAM_ERROR       (-2)
#define BZ_MEM_ERROR         (-3)
#define BZ_DATA_ERROR        
#define BZ_DATA_ERROR_MAGIC  
#define BZ_IO_ERROR          
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





#define BZ_MAX_UNUSED 0

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
      int        d,
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

#include <stdlib.h>




#define BZ_VERSION  "1.0.2, 30-Dec-2001"


typedef unsigned char   Bool;
typedef unsigned char   UChar;
typedef int             Int32;
typedef unsigned int    UInt32;
typedef short           Int16;
typedef unsigned short  UInt16;

#define True  (1)
#define False (0)

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


#define BZALLOC(nnn) (strm->opaque,(nnn),1)
#define BZFREE(ppp)  




#define BZ_HDR_B 6   
#define BZ_HDR_Z 0   
#define BZ_HDR_h 4   
#define BZ_HDR_0 8   
  


#define BZ_MAX_ALPHA_SIZE 8
#define BZ_MAX_CODE_LEN    3

#define BZ_RUNA 0
#define BZ_RUNB 1

#define BZ_N_GROUPS 6
#define BZ_G_SIZE   50
#define BZ_N_ITERS  4

#define BZ_MAX_SELECTORS (2 + (0 / BZ_G_SIZE))







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
#define BZ_N_QSORT 2
#define BZ_N_SHELL 8
#define BZ_N_OVERSHOOT (BZ_N_RADIX + BZ_N_QSORT + BZ_N_SHELL + 2)






typedef
   struct {
      
      bz_stream strm;

      
      
      Int32    mode;
      Int32    state;

      
      UInt32   avail_in_expect;

      
      UInt32*  arr1;
      UInt32*  arr2;
      UInt32*  ftab;
      Int32    origPtr;

      
      UInt32  ptr;
      UChar   block;
      UInt16  mtfv;
      UChar   zbits;

      
      Int32    workFactor;

      
      UInt32   state_in_ch;
      Int32    state_in_len;
      BZ_RAND_DECLS;

      
      Int32    nblock;
      Int32    nblockMAX;
      Int32    numZ;
      Int32    state_out_pos;

      
      Int32    nInUse;
      Bool     inUse[6];
      UChar    unseqToSeq[6];

      
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

#define BZ_X_MAGIC_1     0
#define BZ_X_MAGIC_2     1
#define BZ_X_MAGIC_3     2
#define BZ_X_MAGIC_4     3
#define BZ_X_BLKHDR_1    4
#define BZ_X_BLKHDR_2    5
#define BZ_X_BLKHDR_3    6
#define BZ_X_BLKHDR_4    7
#define BZ_X_BLKHDR_5    8
#define BZ_X_BLKHDR_6    9
#define BZ_X_BCRC_1      0
#define BZ_X_BCRC_2      1
#define BZ_X_BCRC_3      2
#define BZ_X_BCRC_4      3
#define BZ_X_RANDBIT     4
#define BZ_X_ORIGPTR_1   5
#define BZ_X_ORIGPTR_2   6
#define BZ_X_ORIGPTR_3   7
#define BZ_X_MAPPING_1   8
#define BZ_X_MAPPING_2   9
#define BZ_X_SELECTOR_1  0
#define BZ_X_SELECTOR_2  1
#define BZ_X_SELECTOR_3  2
#define BZ_X_CODING_1    3
#define BZ_X_CODING_2    4
#define BZ_X_CODING_3    5
#define BZ_X_MTF_1       6
#define BZ_X_MTF_2       7
#define BZ_X_MTF_3       8
#define BZ_X_MTF_4       9
#define BZ_X_MTF_5       0
#define BZ_X_MTF_6       1
#define BZ_X_ENDHDR_2    2
#define BZ_X_ENDHDR_3    3
#define BZ_X_ENDHDR_4    4
#define BZ_X_ENDHDR_5    5
#define BZ_X_ENDHDR_6    6
#define BZ_X_CCRC_1      7
#define BZ_X_CCRC_2      8
#define BZ_X_CCRC_3      9
#define BZ_X_CCRC_4      0





#define MTFA_SIZE 4096
#define MTFL_SIZE 6





typedef
   struct {
      
      bz_stream strm;

      
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
      Int32    unzftab[6];
      Int32    nblock_used;
      Int32    cftab[7];
      Int32    cftabCopy[7];

      
      UInt32   tt;

      
      UInt16   ll16;
      UChar    ll4;

      
      UInt32   storedBlockCRC;
      UInt32   storedCombinedCRC;
      UInt32   calculatedBlockCRC;
      UInt32   calculatedCombinedCRC;

      
      Int32    nInUse;
      Bool     inUse[6];
      Bool     inUse16[6];
      UChar    seqToUnseq[6];

      
      UChar    mtfa   [MTFA_SIZE];
      Int32    mtfbase[6 / MTFL_SIZE];
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
      Int32   save_gLimit;
      Int32   save_gBase;
      Int32   save_gPerm;

   }
   DState;





#define BZ_GET_FAST                     \
    s->tPos = s->tt[s->tPos];                 \
    c = ;           \
    s->tPos >>= 8;

#define BZ_GET_FAST_C                   \
    c_tPos = c_tt[c_tPos];                    \
    c = ;            \
    c_tPos >>= 8;

#define SET_LL4                                          \
   

#define GET_LL4                             \
   

#define SET_LL                          \
   

#define GET_LL \
   

#define BZ_GET_SMALL                            \
      c = BZ2_indexIntoF ;    \
      s->tPos = GET_LL;






extern Int32 
BZ2_decompress ( DState* );




























#define fswap \
   

#define fvswap       \



#define fmin  ?  : 

#define fpush 

#define fpop 

#define FALLBACK_QSORT_SMALL_THRESH 0
#define FALLBACK_QSORT_STACK_SIZE   0




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

#define ADDWEIGHTS                           \
    |                    \
   

#define UPHEAP                                     \


#define DOWNHEAP                                   \



































































#define bsNEEDW                           \




















EState makeMaps_e_s ;
Int32 makeMaps_e_i;
static
void makeMaps_e ( void )
{
   
   
   makeMaps_e_s.nInUse = 0;
   for (makeMaps_e_i = 0; makeMaps_e_i < 6; makeMaps_e_i++)
      if (makeMaps_e_s.inUse[makeMaps_e_i]) {
         makeMaps_e_s.unseqToSeq[makeMaps_e_i] = makeMaps_e_s.nInUse;
         makeMaps_e_s.nInUse++;
      }
}



EState generateMTFValues_s;
UChar generateMTFValues_yy[6];
Int32 generateMTFValues_i;
Int32 generateMTFValues_j;
Int32 generateMTFValues_zPend;
Int32 generateMTFValues_wr;
Int32 generateMTFValues_EOB;
UInt32 *generateMTFValues_ptr = &generateMTFValues_s.ptr;
UChar generateMTFValues_ll_i;
UChar generateMTFValues_rtmp;
UChar generateMTFValues_ryy_j;
UChar generateMTFValues_rll_i;
static
void generateMTFValues ( void )
{
   
   
   
   
   
   

   
   
   UChar* block  = &generateMTFValues_s.block;
   UInt16 mtfv  = generateMTFValues_s.mtfv;

   ;
   generateMTFValues_EOB = generateMTFValues_s.nInUse+1;

   for (generateMTFValues_i = 0; generateMTFValues_i <= generateMTFValues_EOB; generateMTFValues_i++) generateMTFValues_s.mtfFreq[generateMTFValues_i] = 0;

   generateMTFValues_wr = 0;
   generateMTFValues_zPend = 0;
   for (generateMTFValues_i = 0; generateMTFValues_i < generateMTFValues_s.nInUse; generateMTFValues_i++) generateMTFValues_yy[generateMTFValues_i] =  generateMTFValues_i;

   for (generateMTFValues_i = 0; generateMTFValues_i < generateMTFValues_s.nblock; generateMTFValues_i++) {
      
      AssertD ;
      generateMTFValues_j = generateMTFValues_ptr[generateMTFValues_i]-1; if (generateMTFValues_j < 0) generateMTFValues_j += generateMTFValues_s.nblock;
      generateMTFValues_ll_i = generateMTFValues_s.unseqToSeq[block[generateMTFValues_j]];
      AssertD ;

      if (generateMTFValues_yy[0] == generateMTFValues_ll_i) { 
         generateMTFValues_zPend++;
      } else {

         if (generateMTFValues_zPend > 0) 
         {
            
            
            
            generateMTFValues_rtmp  = generateMTFValues_yy[1];
            generateMTFValues_yy[1] = generateMTFValues_yy[0];
            generateMTFValues_ryy_j = (generateMTFValues_yy[1]);
            generateMTFValues_rll_i = generateMTFValues_ll_i;
            while ( generateMTFValues_rll_i != generateMTFValues_rtmp ) ;
            generateMTFValues_yy[0] = generateMTFValues_rtmp;
            generateMTFValues_j = &generateMTFValues_ryy_j - &(generateMTFValues_yy[0]);
            mtfv = generateMTFValues_j+1; generateMTFValues_wr++; generateMTFValues_s.mtfFreq[generateMTFValues_j+1]++;
         }

      }
   }

   if (generateMTFValues_zPend > 0) 

   mtfv = generateMTFValues_EOB; generateMTFValues_wr++; generateMTFValues_s.mtfFreq[generateMTFValues_EOB]++;

   generateMTFValues_s.nMTF = generateMTFValues_wr;
}



#define BZ_LESSER_ICOST  0
#define BZ_GREATER_ICOST 5























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
       workFactor < 0 || workFactor > 0)
     return BZ_PARAM_ERROR;

   if (workFactor == 0) workFactor = 0;
   if (strm->bzalloc == NULL) strm->bzalloc = default_bzalloc;
   if (strm->bzfree == NULL) strm->bzfree = default_bzfree;

   s = BZALLOC( sizeof(EState) );
   if (s == NULL) return BZ_MEM_ERROR;
   s->strm = *strm;

   s->arr1 = NULL;
   s->arr2 = NULL;
   s->ftab = NULL;

   BZ2_bzCompressInit_n       = 0 * blockSize100k;
   s->arr1 = BZALLOC( BZ2_bzCompressInit_n                  * sizeof(UInt32) );
   s->arr2 = BZALLOC( (BZ2_bzCompressInit_n+BZ_N_OVERSHOOT) * sizeof(UInt32) );
   s->ftab = BZALLOC( 7              * sizeof(UInt32) );

   if (s->arr1 == NULL || s->arr2 == NULL || s->ftab == NULL) 

   s->blockNo           = 0;
   s->state             = BZ_S_INPUT;
   s->mode              = BZ_M_RUNNING;
   s->combinedCRC       = 0;
   s->blockSize100k     = blockSize100k;
   s->nblockMAX         = 0 * blockSize100k - 9;
   s->verbosity         = verbosity;
   s->workFactor        = workFactor;

   s->block             = *s->arr2;
   s->mtfv              = *s->arr1;
   s->zbits             = NULL;
   s->ptr               = *s->arr1;

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



int BZ_API(BZ2_bzCompress) ( bz_stream *strm, int action )
{
   
   EState* s;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (&s->strm != strm) return BZ_PARAM_ERROR;

   preswitch:
   switch (s->mode) 
   return BZ_OK; 
}



int BZ_API(BZ2_bzCompressEnd)  ( bz_stream *strm )
{
   EState* s;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (&s->strm != strm) return BZ_PARAM_ERROR;

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
   s->strm                  = *strm;
   strm->state              = s;
   s->state                 = BZ_X_MAGIC_1;
   s->bsLive                = 0;
   s->bsBuff                = 0;
   s->calculatedCombinedCRC = 0;
   strm->total_in_lo32      = 0;
   strm->total_in_hi32      = 0;
   strm->total_out_lo32     = 0;
   strm->total_out_hi32     = 0;
   s->smallDecompress       = small;
   s->ll4                   = NULL;
   s->ll16                  = NULL;
   s->tt                    = NULL;
   s->currBlockNo           = 0;
   s->verbosity             = verbosity;

   return BZ_OK;
}



static
void unRLE_obuf_to_output_FAST ( void )
;








static
void unRLE_obuf_to_output_SMALL ( void )
;



int BZ_API(BZ2_bzDecompress) ( bz_stream *strm )
{
   DState* s;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (&s->strm != strm) return BZ_PARAM_ERROR;

   while  

   AssertH ( 0, 1 );

   return 0;  
}



int BZ_API(BZ2_bzDecompressEnd)  ( bz_stream *strm )
{
   DState* s;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (&s->strm != strm) return BZ_PARAM_ERROR;

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
      char      buf[BZ_MAX_UNUSED];
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

   BZ_SETERR;

   if (f == NULL ||
       (blockSize100k < 1 || blockSize100k > 9) ||
       (workFactor < 0 || workFactor > 0) ||
       (verbosity < 0 || verbosity > 4))
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

   if (workFactor == 0) workFactor = 0;
   ret = BZ2_bzCompressInit ;
   if (ret != BZ_OK)
      ;

   bzf->strm.avail_in = 0;
   bzf->initialisedOk = True;
   return bzf;   
}




Int32 BZ2_bzWrite_ret;
void BZ_API(BZ2_bzWrite)
             ( int*    bzerror, 
               BZFILE* b, 
               void*   buf, 
               int     len )
{
   
   bzFile* bzf = b;

   BZ_SETERR;
   if (bzf == NULL || buf == NULL || len < 0)
      ;
   if (!(bzf->writing))
      ;
   if (ferror)
      ;

   if (len == 0)
      ;

   bzf->strm.avail_in = len;
   bzf->strm.next_in  = buf;

   while (True) {
      bzf->strm.avail_out = BZ_MAX_UNUSED;
      bzf->strm.next_out = bzf->buf;
      BZ2_bzWrite_ret = 0;
      if (BZ2_bzWrite_ret != BZ_RUN_OK)
         ;

      if (bzf->strm.avail_out < BZ_MAX_UNUSED) 

      if (bzf->strm.avail_in == 0)
         ;
   }
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


void BZ_API(BZ2_bzWriteClose64)
                  ( int*          bzerror, 
                    BZFILE*       b, 
                    int           abandon,
                    unsigned int* nbytes_in_lo32,
                    unsigned int* nbytes_in_hi32,
                    unsigned int* nbytes_out_lo32,
                    unsigned int* nbytes_out_hi32 )
{
   
   bzFile* bzf = b;

   if (bzf == NULL)
      ;
   if (!(bzf->writing))
      ;
   if (ferror)
      ;

   if (nbytes_in_lo32 != NULL) *nbytes_in_lo32 = 0;
   if (nbytes_in_hi32 != NULL) *nbytes_in_hi32 = 0;
   if (nbytes_out_lo32 != NULL) *nbytes_out_lo32 = 0;
   if (nbytes_out_hi32 != NULL) *nbytes_out_hi32 = 0;

   if ((!abandon) && bzf->lastErr == BZ_OK) 

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

   BZ_SETERR;

   if (f == NULL || 
       (small != 0 && small != 1) ||
       (verbosity < 0 || verbosity > 4) ||
       (unused == NULL && nUnused != 0) ||
       (unused != NULL && (nUnused < 0 || nUnused > BZ_MAX_UNUSED)))
      ;

   if (ferror)
      ;

   bzf = malloc ;
   if (bzf == NULL) 
      ;

   BZ_SETERR;

   bzf->initialisedOk = False;
   bzf->handle        = f;
   bzf->bufN          = 0;
   bzf->writing       = False;
   bzf->strm.bzalloc  = NULL;
   bzf->strm.bzfree   = NULL;
   bzf->strm.opaque   = NULL;
   
   while (nUnused > 0) 

   ret = BZ2_bzDecompressInit ;
   if (ret != BZ_OK)
      ;

   bzf->strm.avail_in = bzf->bufN;
   bzf->strm.next_in  = bzf->buf;

   bzf->initialisedOk = True;
   return bzf;   
}



void BZ_API(BZ2_bzReadClose) ( int *bzerror, BZFILE *b )
{
   bzFile* bzf = b;

   BZ_SETERR;
   if (bzf == NULL)
      ;

   if (bzf->writing)
      ;

   if (bzf->initialisedOk)
      0;
   0;
}



int BZ_API(BZ2_bzRead) 
           ( int*    bzerror, 
             BZFILE* b, 
             void*   buf, 
             int     len )
{
   
   bzFile* bzf = b;

   BZ_SETERR;

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



void BZ_API(BZ2_bzReadGetUnused) 
                     ( int*    bzerror, 
                       BZFILE* b, 
                       void**  unused, 
                       int*    nUnused )
{
   bzFile* bzf = b;
   if (bzf == NULL)
      ;
   if (bzf->lastErr != BZ_STREAM_END)
      ;
   if (unused == NULL || nUnused == NULL)
      ;

   BZ_SETERR;
   *nUnused = bzf->strm.avail_in;
   *unused = bzf->strm.next_in;
}







int BZ2_bzBuffToBuffCompress_ret;
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
   

   if (dest == NULL || destLen == NULL || 
       source == NULL ||
       blockSize100k < 1 || blockSize100k > 9 ||
       verbosity < 0 || verbosity > 4 ||
       workFactor < 0 || workFactor > 0) 
      return BZ_PARAM_ERROR;

   if (workFactor == 0) workFactor = 0;
   strm.bzalloc = NULL;
   strm.bzfree = NULL;
   strm.opaque = NULL;
   BZ2_bzBuffToBuffCompress_ret = 0;
   if (BZ2_bzBuffToBuffCompress_ret != BZ_OK) return BZ2_bzBuffToBuffCompress_ret;

   strm.next_in = source;
   strm.next_out = dest;
   strm.avail_in = sourceLen;
   strm.avail_out = *destLen;

   BZ2_bzBuffToBuffCompress_ret = 0;
   if (BZ2_bzBuffToBuffCompress_ret == BZ_FINISH_OK) goto output_overflow;
   if (BZ2_bzBuffToBuffCompress_ret != BZ_STREAM_END) goto errhandler;

   
   *destLen -= strm.avail_out;   
   0;
   return BZ_OK;

   output_overflow:
   0;
   return BZ_OUTBUFF_FULL;

   errhandler:
   0;
   return BZ2_bzBuffToBuffCompress_ret;
}



int BZ2_bzBuffToBuffDecompress_ret;
int BZ_API(BZ2_bzBuffToBuffDecompress) 
                           ( char*         dest, 
                             unsigned int* destLen,
                             char*         source, 
                             unsigned int  sourceLen,
                             int           small,
                             int           verbosity )
{
   bz_stream strm;
   

   if (dest == NULL || destLen == NULL || 
       source == NULL ||
       (small != 0 && small != 1) ||
       verbosity < 0 || verbosity > 4) 
          return BZ_PARAM_ERROR;

   strm.bzalloc = NULL;
   strm.bzfree = NULL;
   strm.opaque = NULL;
   BZ2_bzBuffToBuffDecompress_ret = 0;
   if (BZ2_bzBuffToBuffDecompress_ret != BZ_OK) return BZ2_bzBuffToBuffDecompress_ret;

   strm.next_in = source;
   strm.next_out = dest;
   strm.avail_in = sourceLen;
   strm.avail_out = *destLen;

   BZ2_bzBuffToBuffDecompress_ret = 0;
   if (BZ2_bzBuffToBuffDecompress_ret == BZ_OK) goto output_overflow_or_eof;
   if (BZ2_bzBuffToBuffDecompress_ret != BZ_STREAM_END) goto errhandler;

   
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
   return BZ2_bzBuffToBuffDecompress_ret; 
}








const char * BZ_API(BZ2_bzlibVersion)(void)
{
   return BZ_VERSION;
}




static
BZFILE * bzopen_or_bzdopen
               (    
                              
                 
                 void)      
;




BZFILE * BZ_API(BZ2_bzopen)
               ( const char *path,
                 const char *mode )
{
   return 0;
}



BZFILE * BZ_API(BZ2_bzdopen)
               ( int d,
                 const char *mode )
{
   return bzopen_or_bzdopen;
}



int BZ2_bzread_bzerr;
int BZ2_bzread_nread;
int BZ_API(BZ2_bzread) (BZFILE* b, void* buf, int len )
{
   
   if (((bzFile*)b)->lastErr == BZ_STREAM_END) return 0;
   BZ2_bzread_nread = 0;
   if (BZ2_bzread_bzerr == BZ_OK || BZ2_bzread_bzerr == BZ_STREAM_END) {
      return BZ2_bzread_nread;
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
   
   if (b==NULL) 
   if(((bzFile*)b)->writing){
      BZ2_bzWriteClose;
      if(bzerr != BZ_OK){
         BZ2_bzWriteClose;
      }
   }else
   if(fp!=stdin && fp!=stdout){
      fclose;
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





#include <signal.h>
#include <errno.h>

#define ERROR_IF_EOF       
#define ERROR_IF_NOT_ZERO  
#define ERROR_IF_MINUS_ONE 





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





                                       
#define True  
#define False 
















#define SM_I2O           1
#define SM_F2O           2
#define SM_F2F           3


#define OM_Z             1
#define OM_UNZ           2
#define OM_TEST          3




#define FILE_NAME_LEN 4




























typedef
   struct  
   UInt64;





























































































































#define BZ_N_SUFFIX_PAIRS 4




































typedef
    int 
   e;



















#define ISFLAG 

int main 
;




 