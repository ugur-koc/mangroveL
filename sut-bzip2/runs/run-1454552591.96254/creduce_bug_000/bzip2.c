 







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

BZ_EXTERN void BZ_APIBZ2_bzWriteClose64 ( 
       
       
       
       
       
       
      void
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

#define True  Bool1
#define False Bool0

#define __inline__  


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

#define BZ_RAND_MASK 1

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
   UInt32s->ll4[i >> 1] >> i << 2 & 0x4 & 0xF

#define SET_LLi,n                          \
   

#define GET_LLi \
   UInt32s->ll16[i] | GET_LL4i << 16

#define BZ_GET_SMALLcccc                            \
      cccc = BZ2_indexIntoF  s->tPos, s->cftab ;    \
      s->tPos = GET_LLs->tPos;



































#define fswapzz1, zz2 \
   

#define fvswapzzp1, zzp2, zzn       \



#define fmina,b a < b ? a : b

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





#define       SET_BHzz  bhtab[zz >> 5] |= 1 << zz & 31
#define     CLEAR_BHzz  bhtab[zz >> 5] &= ~1 << zz & 31
#define     ISSET_BHzz  bhtab[zz >> 5] & 1 << zz & 31
#define      WORD_BHzz  bhtab[zz >> 5]
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
#define SETMASK 1 << 21
#define CLEARMASK ~SETMASK



#undef BIGFREQ
#undef SETMASK
#undef CLEARMASK


















#define WEIGHTOFzz0  zz0 & 0xffffff00
#define DEPTHOFzz1   zz1 & 0x000000ff
#define MYMAXzz2,zz3 zz2 > zz3 ? zz2 : zz3

#define ADDWEIGHTSzw1,zw2                           \
   WEIGHTOFzw1+WEIGHTOFzw2 |                    \
   1 + MYMAXDEPTHOFzw1,DEPTHOFzw2

#define UPHEAPz                                     \


#define DOWNHEAPz                                   \



































































#define bsNEEDWnz                           \




























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















































int BZ_APIBZ2_bzCompressInit 
                    (  
                     
                     
                     void )
;











#define ADD_CHAR_TO_BLOCKzs,zchh0               \
















int BZ_APIBZ2_bzCompress (  void )
;



int BZ_APIBZ2_bzCompressEnd  ( void )
;







int BZ_APIBZ2_bzDecompressInit 
                     (  
                       
                       void )
;
















int BZ_APIBZ2_bzDecompress ( void )
;



int BZ_APIBZ2_bzDecompressEnd  ( void )
;






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
;




void BZ_APIBZ2_bzWrite
             (  
                
                
               void )
;



void BZ_APIBZ2_bzWriteClose
                  (  
                     
                    
                    
                    void )
;


void BZ_APIBZ2_bzWriteClose64
                  (  
                     
                    
                    
                    
                    
                    void )
;



BZFILE* BZ_APIBZ2_bzReadOpen 
                   ( int*  bzerror, 
                     FILE* f, 
                     int   verbosity,
                     int   small,
                     void* unused,
                     int   nUnused )
;



void BZ_APIBZ2_bzReadClose (  void )
;



int BZ_APIBZ2_bzRead 
           (  
              
              
             void )
;



void BZ_APIBZ2_bzReadGetUnused 
                     (  
                        
                        
                       void )
;







int BZ_APIBZ2_bzBuffToBuffCompress 
                         (  
                           
                            
                           
                            
                            
                           void )
;



int BZ_APIBZ2_bzBuffToBuffDecompress 
                           (  
                             
                              
                             
                             
                             void )
;








const char * BZ_APIBZ2_bzlibVersionvoid
;









BZFILE * BZ_APIBZ2_bzopen
               ( 
                 void )
;



BZFILE * BZ_APIBZ2_bzdopen
               ( 
                 void )
;



BZFILE * BZ_APIBZ2_bzread_b;
void * BZ_APIBZ2_bzread_buf;
int BZ_APIBZ2_bzread_len;
int BZ_APIBZ2_bzread (  void )
{
   int bzerr, nread;
   if (((bzFile*)BZ_APIBZ2_bzread_b)->lastErr == BZ_STREAM_END) return 0;
   nread = 0;
   if (bzerr == BZ_OK || bzerr == BZ_STREAM_END) ; else ;
}



int BZ_APIBZ2_bzwrite (  void )
;



int BZ_APIBZ2_bzflush (void)
;



void BZ_APIBZ2_bzclose (void)
;







const char * BZ_APIBZ2_bzerror ( void)
;




























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
    int 
   Cell;



















#define ISFLAGs strcmpaa->name, s==0

IntNative main ( void )
;




 