 







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
#define BZ_PARAM_ERROR       2
#define BZ_MEM_ERROR         3
#define BZ_DATA_ERROR        
#define BZ_DATA_ERROR_MAGIC  
#define BZ_IO_ERROR          
#define BZ_UNEXPECTED_EOF    7
#define BZ_OUTBUFF_FULL      8
#define BZ_CONFIG_ERROR      9

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

      void *(*bzalloc);
      void (*bzfree);
      void *opaque
   } 
   bz_stream;



#include <stdio.h>

#   define BZ_API(func) func
#   define BZ_EXTERN extern




BZ_EXTERN int BZ_APIBZ2_bzCompressInit ;

BZ_EXTERN int BZ_APIBZ2_bzCompress ( 
       
      void 
   );

BZ_EXTERN int BZ_APIBZ2_bzCompressEnd ( 
      void 
   );

BZ_EXTERN int BZ_APIBZ2_bzDecompressInit ;

BZ_EXTERN int BZ_APIBZ2_bzDecompress ( 
      void 
   );

BZ_EXTERN int BZ_APIBZ2_bzDecompressEnd ( 
      void 
   );





#define BZ_MAX_UNUSED 5000

typedef void BZFILE;

BZ_EXTERN BZFILE* BZ_APIBZ2_bzReadOpen ( 
      int*  p1,   
      FILE* p2, 
      int   p3, 
      int   p4,
      void* p5,    
      int   p6 
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
      int*  p1,      
      FILE* p2, 
      int   p3, 
      int   p4, 
      int   p5 
   );

BZ_EXTERN void BZ_APIBZ2_bzWrite ( 
       
       
       
      void 
   );

BZ_EXTERN void BZ_APIBZ2_bzWriteClose ;

BZ_EXTERN void BZ_API(BZ2_bzWriteClose64) ;




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




#define BZ_VERSION  "1.0.2 30Dec2001"

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


#define BZALLOCnnn strm>opaquennn1
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

#define BZ_MAX_SELECTORS 2  900000 / BZ_G_SIZE







#define BZ_RAND_DECLS                          \
   Int32 rNToGo;                               \
   Int32 rTPos                                 \

#define BZ_RAND_INIT_MASK                      \
   s>rNToGo = 0                              \
   s>rTPos  = 0                               \

#define BZ_RAND_MASK 

#define BZ_RAND_UPD_MASK                       \
   if                                             \
   s>rNToGo;







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
#define BZ_N_OVERSHOOT BZ_N_RADIX  BZ_N_QSORT  BZ_N_SHELL  2






typedef
   struct {
      
      bz_stream* strm;

      
      
      Int32    mode;
      Int32    state;

      
      

      
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
      
      

      
      
      
      

      
      
      

      
      
      UInt32   combinedCRC;

      
      Int32    verbosity;
      Int32    blockNo;
      Int32    blockSize100k

      
      
      
      
      

      
      
      
      
      

   }
   EState;



















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

      
      
      
      
      BZ_RAND_DECLS;

      
      UInt32   bsBuff;
      Int32    bsLive;

      
      
      Bool     smallDecompress;
      Int32    currBlockNo;
      Int32    verbosity;

      
      
      
      
      
      
      
      

      
      UInt32   *tt;

      
      UInt16   *ll16;
      UChar    *ll4;

      
      
      
      
      UInt32   calculatedCombinedCRC

      
      
      
      
      

      
      
      
      
      
      

      
      
      
      

      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
       
      
      
      
      
      
      
      

   }
   DState;





#define BZ_GET_FAST                     \
    s>tPos = s>tt[s>tPos]                 \
    cccc =            \
    s>tPos = 8

#define BZ_GET_FAST_C                   \
    c_tPos = c_tt[c_tPos]                    \
    cccc =             \
    c_tPos = 8

#define SET_LL4                                          \
   

#define GET_LL4                             \
   

#define SET_LL                          \
   

#define GET_LL \
   

#define BZ_GET_SMALL                            \
      cccc = BZ2_indexIntoF     \
      s>tPos = GET_LL



































#define fswap \
   

#define fvswap       \



#define fmin  ?   

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





#define       SET_BH  bhtab[ >> 5] = 
#define     CLEAR_BH  bhtab[ >> 5] = 
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




#define mmin  ?   

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






























#define BZ_LESSER_ICOST  0
#define BZ_GREATER_ICOST 15























#define RETURN                               \
   

#define GET_BITS                     \
   case lll s>state = lll                      \
   if  

#define GET_UCHAR                        \
   GET_BITS

#define GET_BIT                          \
   GET_BITS


#define GET_MTF_VAL           \






























static
void* default_bzalloc,  *BZ_APIBZ2_bzWrite_buf = 0,  *BZ_APIBZ2_bzWrite_b = 0,  *BZ_APIBZ2_bzReadClose_b = 0,  *BZ_APIBZ2_bzRead_buf = 0,  *BZ_APIBZ2_bzRead_b = 0,  *BZ_APIBZ2_bzReadGetUnused_b = 0,  * bzopen_or_bzdopen,  *BZ_APIBZ2_bzread_b = 0,  *BZ_APIBZ2_bzerror_b = 0
                     
 
;

static
void default_bzfree (  void )
;














Int32 BZ2_bzCompressInit_n;
int BZ_API(BZ2_bzCompressInit) 
                    ( bz_stream* p1, 
                     int        p2,
                     int        p3,
                     int        p4 )
{
   
   EState* s;

    return BZ_CONFIG_ERROR;

   
     return BZ_PARAM_ERROR;

    p4 = 30;
    p1->bzalloc = default_bzalloc;
    p1->bzfree = default_bzfree;

   s = 0;
    return BZ_MEM_ERROR;
   s->strm = p1;

   s->arr1 = NULL;
   s->arr2 = NULL;
   s->ftab = NULL;

   BZ2_bzCompressInit_n       = 100000 * p2;
   s->arr1 = 0;
   s->arr2 = 0 * sizeof(UInt32) ;
   s->ftab = 0;

    

   s->blockNo           = 0;
   s->state             = BZ_S_INPUT;
   s->mode              = BZ_M_RUNNING;
   s->combinedCRC       = 0;
   s->blockSize100k     = p2;
   s->nblockMAX         = 100000 * p2 - 19;
   s->verbosity         = p3;
   s->workFactor        = p4;

   s->block             = s->arr2;
   s->mtfv              = s->arr1;
   s->zbits             = NULL;
   s->ptr               = s->arr1;

   p1->state          = s;
   p1->total_in_lo32  = 0;
   p1->total_in_hi32  = 0;
   p1->total_out_lo32 = 0;
   p1->total_out_hi32 = 0
   
   ;
   return BZ_OK;
}











#define ADD_CHAR_TO_BLOCK               \
















bz_stream *BZ_APIBZ2_bzCompress_strm = 0,  *BZ_APIBZ2_bzDecompress_strm = 0;
EState *BZ_APIBZ2_bzCompress_s,  *BZ_APIBZ2_bzCompressEnd_s;
int BZ_APIBZ2_bzCompress (  void )
{
   
   
   
   
    return BZ_PARAM_ERROR;
   BZ_APIBZ2_bzCompress_s = BZ_APIBZ2_bzCompress_strm->state;
    return BZ_PARAM_ERROR;
    return BZ_PARAM_ERROR;

   preswitch:
   switch (BZ_APIBZ2_bzCompress_s->mode) 
   return BZ_OK; 
}




int BZ_APIBZ2_bzCompressEnd  ( void )
{
   bz_stream * strm = 0;
   
    return BZ_PARAM_ERROR;
   BZ_APIBZ2_bzCompressEnd_s = strm->state;
    return BZ_PARAM_ERROR;
    return BZ_PARAM_ERROR;

    BZFREE(BZ_APIBZ2_bzCompressEnd_s->arr1);
    BZFREE;
    BZFREE;
   0;

   strm->state = NULL;   

   return BZ_OK;
}







int BZ_API(BZ2_bzDecompressInit) 
                     ( bz_stream* p1, 
                       int        p2,
                       int        p3 )
{
   DState* s;

    return BZ_CONFIG_ERROR;

    return BZ_PARAM_ERROR;
    return BZ_PARAM_ERROR;
    return BZ_PARAM_ERROR;

    p1->bzalloc = default_bzalloc;
    p1->bzfree = default_bzfree;

   s = 0;
    return BZ_MEM_ERROR;
   s->strm                  = p1;
   p1->state              = s;
   s->state                 = BZ_X_MAGIC_1;
   s->bsLive                = 0;
   s->bsBuff                = 0;
   s->calculatedCombinedCRC = 0;
   p1->total_in_lo32      = 0;
   p1->total_in_hi32      = 0;
   p1->total_out_lo32     = 0;
   p1->total_out_hi32     = 0;
   s->smallDecompress       = p3;
   s->ll4                   = NULL;
   s->ll16                  = NULL;
   s->tt                    = NULL;
   s->currBlockNo           = 0;
   s->verbosity             = p2;

   return BZ_OK;
}

















DState *BZ_APIBZ2_bzDecompress_s,  *BZ_APIBZ2_bzDecompressEnd_s;
int BZ_APIBZ2_bzDecompress ( void )
{
   
   
    return BZ_PARAM_ERROR;
   BZ_APIBZ2_bzDecompress_s = BZ_APIBZ2_bzDecompress_strm->state;
    return BZ_PARAM_ERROR;
    return BZ_PARAM_ERROR;

   0;
   
   if  

   AssertH (  6001 )

   return 0;  
}




int BZ_APIBZ2_bzDecompressEnd  ( void )
{
   bz_stream * strm = 0;
   
    return BZ_PARAM_ERROR;
   BZ_APIBZ2_bzDecompressEnd_s = strm->state;
    return BZ_PARAM_ERROR;
    return BZ_PARAM_ERROR;

    BZFREE(BZ_APIBZ2_bzDecompressEnd_s->tt);
    BZFREE;
    BZFREE;

   0;
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
      Bool      initialisedOk
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
   bzFile* bzf = NULL

   BZ_SETERR;

   
      

   
      

   bzf = malloc ;
   
      

   BZ_SETERR
   bzf->initialisedOk = False;
   bzf->bufN          = 0;
   bzf->handle        = f;
   bzf->writing       = True;
   bzf->strm.bzalloc  = NULL;
   bzf->strm.bzfree   = NULL;
   bzf->strm.opaque   = NULL;

    workFactor = 30;
   ret = BZ2_bzCompressInit ;
   
      

   bzf->strm.avail_in = 0;
   bzf->initialisedOk = True;
   return bzf;   
}




int BZ_APIBZ2_bzWrite_len = 0;


int *BZ_APIBZ2_bzWrite_bzerror = 0,  *BZ_APIBZ2_bzReadGetUnused_nUnused = 0,  *BZ_APIBZ2_bzerror_errnum = 0;
Int32 BZ_APIBZ2_bzWrite_ret;
void BZ_APIBZ2_bzWrite
             (  
                
                
               void )
{
   
   
   
   
   
   bzFile* bzf = BZ_APIBZ2_bzWrite_b

   BZ_SETERR;
   
      
   
      
   
      

   
      

   bzf->strm.avail_in = BZ_APIBZ2_bzWrite_len;
   bzf->strm.next_in  = BZ_APIBZ2_bzWrite_buf;

    
}



void BZ_API(BZ2_bzWriteClose)
                  ( int*          p1, 
                    BZFILE*       p2, 
                    int           p3,
                    unsigned int* p4,
                    unsigned int* p5 )
{
   BZ2_bzWriteClose64 ;
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
   int     ret

   BZ_SETERR;

   
      

   
      

   bzf = malloc ;
    
      

   BZ_SETERR

   bzf->initialisedOk = False;
   bzf->handle        = f;
   bzf->bufN          = 0;
   bzf->writing       = False;
   bzf->strm.bzalloc  = NULL;
   bzf->strm.bzfree   = NULL;
   bzf->strm.opaque   = NULL;
   
    

   ret = BZ2_bzDecompressInit ;
   
      

   bzf->strm.avail_in = bzf->bufN;
   bzf->strm.next_in  = bzf->buf;

   bzf->initialisedOk = True;
   return bzf;   
}




void BZ_APIBZ2_bzReadClose (  void )
{
   
   
   bzFile* bzf = BZ_APIBZ2_bzReadClose_b

   BZ_SETERR;
   
      

   
      

   
      0;
   0;
}



int BZ_APIBZ2_bzRead_len = 0;


int BZ_APIBZ2_bzRead 
           (  
              
              
             void )
{
   
   
   
   
   
   bzFile* bzf = BZ_APIBZ2_bzRead_b

   BZ_SETERR;

   
      

   
      

   
      

   bzf->strm.avail_out = BZ_APIBZ2_bzRead_len;
   bzf->strm.next_out = BZ_APIBZ2_bzRead_buf;

    

   return 0; 
}




void **BZ_APIBZ2_bzReadGetUnused_unused = 0;

void BZ_APIBZ2_bzReadGetUnused 
                     (  
                        
                        
                       void )
{
   
   
   
   
   bzFile* bzf = BZ_APIBZ2_bzReadGetUnused_b;
   
      
   
      
   
      

   BZ_SETERR
   *BZ_APIBZ2_bzReadGetUnused_nUnused = bzf->strm.avail_in;
   *BZ_APIBZ2_bzReadGetUnused_unused = bzf->strm.next_in;
}







int BZ_APIBZ2_bzBuffToBuffCompress_workFactor = 0;
int BZ_APIBZ2_bzBuffToBuffCompress_verbosity = 0;
int BZ_APIBZ2_bzBuffToBuffCompress_blockSize100k = 0;
unsigned int BZ_APIBZ2_bzBuffToBuffCompress_sourceLen = 0,  BZ_APIBZ2_bzBuffToBuffDecompress_sourceLen = 0;
char *BZ_APIBZ2_bzBuffToBuffCompress_source = 0,  *BZ_APIBZ2_bzBuffToBuffCompress_dest = 0,  *BZ_APIBZ2_bzBuffToBuffDecompress_source = 0,  *BZ_APIBZ2_bzBuffToBuffDecompress_dest = 0;
unsigned int *BZ_APIBZ2_bzBuffToBuffCompress_destLen = 0,  *BZ_APIBZ2_bzBuffToBuffDecompress_destLen = 0;

int BZ_APIBZ2_bzBuffToBuffCompress_ret;
int BZ_APIBZ2_bzBuffToBuffCompress 
                         (  
                           
                            
                           
                            
                            
                           void )
{
   
   
   
   
   
   
   
   bz_stream strm;
   

    
      return BZ_PARAM_ERROR;

    BZ_APIBZ2_bzBuffToBuffCompress_workFactor = 30;
   strm.bzalloc = NULL;
   strm.bzfree = NULL;
   strm.opaque = NULL;
   BZ_APIBZ2_bzBuffToBuffCompress_ret = 0;
    return BZ_APIBZ2_bzBuffToBuffCompress_ret;

   strm.next_in = BZ_APIBZ2_bzBuffToBuffCompress_source;
   strm.next_out = BZ_APIBZ2_bzBuffToBuffCompress_dest;
   strm.avail_in = BZ_APIBZ2_bzBuffToBuffCompress_sourceLen;
   strm.avail_out = *BZ_APIBZ2_bzBuffToBuffCompress_destLen;

   BZ_APIBZ2_bzBuffToBuffCompress_ret = 0;
    goto output_overflow;
    goto errhandler;

   
   *BZ_APIBZ2_bzBuffToBuffCompress_destLen = strm.avail_out;   
   0;
   return BZ_OK;

   output_overflow:
   0;
   return BZ_OUTBUFF_FULL;

   errhandler:
   0;
   return BZ_APIBZ2_bzBuffToBuffCompress_ret;
}



int BZ_APIBZ2_bzBuffToBuffDecompress_verbosity = 0;
int BZ_APIBZ2_bzBuffToBuffDecompress_small = 0;




int BZ_APIBZ2_bzBuffToBuffDecompress_ret;
int BZ_APIBZ2_bzBuffToBuffDecompress 
                           (  
                             
                              
                             
                             
                             void )
{
   
   
   
   
   
   
   bz_stream strm;
   

    
          return BZ_PARAM_ERROR;

   strm.bzalloc = NULL;
   strm.bzfree = NULL;
   strm.opaque = NULL;
   BZ_APIBZ2_bzBuffToBuffDecompress_ret = 0;
    return BZ_APIBZ2_bzBuffToBuffDecompress_ret;

   strm.next_in = BZ_APIBZ2_bzBuffToBuffDecompress_source;
   strm.next_out = BZ_APIBZ2_bzBuffToBuffDecompress_dest;
   strm.avail_in = BZ_APIBZ2_bzBuffToBuffDecompress_sourceLen;
   strm.avail_out = *BZ_APIBZ2_bzBuffToBuffDecompress_destLen;

   BZ_APIBZ2_bzBuffToBuffDecompress_ret = 0;
    goto output_overflow_or_eof;
    goto errhandler;

   
   *BZ_APIBZ2_bzBuffToBuffDecompress_destLen = strm.avail_out;
   0;
   return BZ_OK;

   output_overflow_or_eof:
   if (strm.avail_out > 0) {
      0;
      return BZ_UNEXPECTED_EOF;
   } else       

   errhandler:
   0;
   return BZ_APIBZ2_bzBuffToBuffDecompress_ret; 
}








const char * BZ_APIBZ2_bzlibVersion(void)
{
   return BZ_VERSION;
}









BZFILE * BZ_APIBZ2_bzopen
               ( 
                 void )
{
   
   
   return 0;
}



BZFILE * BZ_APIBZ2_bzdopen
               ( 
                 void )
{
   
   
   return bzopen_or_bzdopen;
}




int BZ_APIBZ2_bzread_bzerr;
int BZ_APIBZ2_bzread_nread;
int BZ_APIBZ2_bzread (  void )
{
   
   
   
   
    return 0;
   BZ_APIBZ2_bzread_nread = 0;
   if (BZ_APIBZ2_bzread_bzerr == BZ_OK || BZ_APIBZ2_bzread_bzerr == BZ_STREAM_END) {
      return BZ_APIBZ2_bzread_nread;
   } else {
      return 1;
   }
}



int BZ_APIBZ2_bzwrite_len = 0;
int BZ_APIBZ2_bzwrite (  void )
{
   
   
   
   int bzerr

   ;
   if(bzerr == BZ_OK){
      return BZ_APIBZ2_bzwrite_len;
   }else{
      return 1;
   }
}



int BZ_APIBZ2_bzflush (void)
{
   
   
   return 0;
}



int BZ_APIBZ2_bzclose_bzerr;
void BZ_APIBZ2_bzclose (void)
{
   BZFILE * b = 0;
   
   FILE *fp = ((bzFile *)b)->handle;
   
    
   if(((bzFile*)b)->writing){
      BZ2_bzWriteClose;
      {
         BZ2_bzWriteClose;
      }
   }else
   {
      fclose;
   }
}




static char *bzerrorstrings[] ;




const char * BZ_APIBZ2_bzerror ( void)
{
   
   
   int err = ((bzFile *)BZ_APIBZ2_bzerror_b)->lastErr;

    err = 0;
   *BZ_APIBZ2_bzerror_errnum = err;
   return bzerrorstrings[err*1];
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

#   define PATH_SEP    
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





























































































































#define BZ_N_SUFFIX_PAIRS 4




































typedef
   struct zzzz 
   Ce;



















#define ISFLAG 






 