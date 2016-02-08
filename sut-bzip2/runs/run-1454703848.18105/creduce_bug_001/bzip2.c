

 

  
  
  

#define BZ_OK 0
  
  
  
  
#  1
#define BZ_PARAM_ERROR 2
#define BZ_MEM_ERROR 3
#  4
#  5
#  6
#define BZ_UNEXPECTED_EOF 7
#define BZ_OUTBUFF_FULL 8
#define BZ_CONFIG_ERROR 9

typedef struct {
  char next_in;
   int avail_in;
   int total_in_lo32;
   int total_in_hi32;

  char next_out;
   int avail_out;
   int total_out_lo32;
   int total_out_hi32;

  void *state;

  void (*bzalloc)(   );
  void (*bzfree)(  void );
  void *opaque
} bz_stream;

#include <stdio.h>

#define BZ_API 
#define BZ_EXTERN 

  BZ_APIBZ2_bzCompressInit(bz_stream *, int ,
                                       int , int );

  BZ_APIBZ2_bzCompress(bz_stream *t );

   strm

  (  int 
                                          );

  BZ_APIBZ2_bzDecompress( );

  BZ_APIBZ2_bzDecompressEnd( );

#define BZ_MAX_UNUSED 5000

typedef  BZFILE;

  *BZ_APIBZ2_bzReadOpen(int *, FILE *, int ,
                                       int , void *, int );

 void BZ_APIBZ2_bzReadClose(int *, BZFILE *);

 void BZ_APIBZ2_bzReadGetUnused(int *, BZFILE *, void **,
                                         int *);

  BZ_APIBZ2_bzRead(int *, BZFILE *, void *t );

  *BZ_APIBZ2_bzWriteOpen(int *, FILE *,
                                        int , int ,
                                        int );

 void BZ_APIBZ2_bzWrite(int *, BZFILE *, void *t );

 void BZ_APIBZ2_bzWriteClose(int *, BZFILE *, int ,
                                      unsigned  *,
                                      unsigned  *);

  BZ2_bzWriteClose64(int , BZFILE , int ,
                                           int ,
                                           int ,
                                           int ,
                                           int );

  BZ_APIBZ2_bzBuffToBuffCompress(char *, unsigned  *,
                                             char *,
                                             unsigned  ,
                                             int , int t );

  BZ_APIBZ2_bzBuffToBuffDecompress(char *,
                                               unsigned  *,
                                               char *,
                                               unsigned  ,
                                               int t );

 const char BZ_APIBZ2_bzlibVersionvoid;

  *BZ_APIBZ2_bzopen(const char *, const char *);

  *BZ_APIBZ2_bzdopen(int , const char *);

  BZ_APIBZ2_bzread(BZFILE *, void *t );

  BZ_APIBZ2_bzwrite(BZFILE *, void *t );

   b

  ( );

 const char *BZ_APIBZ2_bzerror(BZFILE *, int *);

 

#include <stdlib.h>

#define BZ_VERSION "1.0.2, 30-Dec-2001"

typedef char Char;
typedef   Bool;
typedef   UChar;
typedef  Int32;
typedef   UInt32
  ;
typedef   UInt16;

#define True 1
#define False 0

 

#   

#   

#define   zf
#define     zf 
#define       za1 
#define         za2 
#define           za3 
#define                                                              \
             za4 

#define   nnn 
#define   ppp

  
  
  
  

  
  

  
  

  
  
  

#define BZ_MAX_SELECTORS     

#define BZ_RAND_DECLS                                                          \
                                                                   \
   

#define                                                       \
  srNToGo                                                                 \
    

  

#define BZ_RAND_UPD_MASK                                                       \
                                                                             \
       

 

 

#   

  
#define BZ_M_RUNNING 2
  
  

  
#define BZ_S_INPUT 2

  
  
  
#define      BZ_N_SHELL  

typedef struct {

  bz_stream strm;

  Int32 mode;
  Int32 state;

  UInt32 arr1;
  UInt32 arr2;
  UInt32 ftab;

  UInt32 ptr;
  UChar block;
  UInt16 mtfv;
  UChar zbits;

  Int32 workFactor

  ;

  Int32 nblockMAX;

  UInt32 combinedCRC;

  Int32 verbosity;
  Int32 blockNo;
  Int32 blockSize100k

} EState



;

  
  

#define BZ_X_MAGIC_1 10
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

  
  

typedef struct {

  bz_stream strm;

  Int32 state

  ;

  UInt32 bsBuff;
  Int32 bsLive;

  Bool smallDecompress;
  Int32 currBlockNo;
  Int32 verbosity;

  UInt32 tt;

  UInt16 ll16;
  UChar ll4;

  UInt32 calculatedCombinedCRC

} DState;

#define                                                         \
    stPos                                                    \
                                                        \
    

#define                                                       \
                                                           \
                                                         \
  c_tPos  

#   

#define  ll4i          

#   

#define  ll16i    

#define                                                        \
      scftab                                     \
    

#   

#define    zzn

#define        a  

#   

#   

  
  

# 
 
 
 
 
 
 

#define  zz        
#define  zz        
#define  zz        
#define  zz  
#define  zz  

 
 
 
 
 

#   

#define    zzn

#define        a  

#define    dz

#define    dz

#define    az

#   

  
#define    BZ_N_QSORT
  

# 
 
 
 
 
 
 
 
 
 

#define  ftabb        
#    21
#  

# 
 
 

#define  zz0  
#define  zz1  
#define        zz2  

#define                                                           \
          MYMAXDEPTHOFzw1 

 

 

 

  
  

  

#define                                                             \
          lll                                        
                                                                          \
  

#define     uuu 

#define     uuu 

#define    lval

  default_bzalloc(  Int32   );

  default_bzfree(  void );

 Int32 BZ_APIBZ2_bzCompressInit_n;
EState *BZ_APIBZ2_bzCompressInit_s;
BZ_APIBZ2_bzCompressInit(bz_stream *strm, int blockSize100k, int verbosity,
                             int workFactor) {
  
  

  if (           
            250)
     

    

    
  if (bzalloc  NULL)
      default_bzalloc;
  if (bzfree  NULL)
      

    ( 0);
  if (  NULL)
     
    

  arr1  NULL;
  arr2  NULL;
  ftab  NULL

     * blockSize100k;
     
    ( 0) * sizeof(UInt32);
     

  if (          NULL)

      0;
    BZ_S_INPUT;
    BZ_M_RUNNING;
    
    
        
    
    workFactor

   =  
     
    NULL;
     

    BZ_APIBZ2_bzCompressInit_s
   = 
    0;
    0;
    
  
  
  return BZ_OK;
}

#   

int BZ_APIBZ2_bzCompress_action;
int BZ_APIBZ2_bzCompress(bz_stream *strm) {

  EState *s;
  if (  NULL)
     
    ;
  if (  NULL)
     
    

   


  switch (s->mode)
     ;
}

 EState BZ_APIBZ2_bzCompressEnd_s;
bz_stream  BZ_APIBZ2_bzCompressEnd_strm;
BZ_APIBZ2_bzCompressEnd(void) {
  
  if (  NULL)
     
    ;
  if (  NULL)
     
    

   ;

  if (arr1  NULL)
    (arr1);
  if (arr2  NULL)
    (arr2);
  if (ftab  NULL)
    (
  0 );

    ;

   
}

 bz_stream  BZ_APIBZ2_bzDecompressInit_strm;
int BZ_APIBZ2_bzDecompressInit_verbosity;
int BZ_APIBZ2_bzDecompressInit_small;
BZ_APIBZ2_bzDecompressInit(  void) {
  DState *s

  

   ;

  if (  NULL)
     
        

   
     

   ;

  if (bzalloc  NULL)
      default_bzalloc;
  if (bzfree  NULL)
      

    ( 0);
  if (  NULL)
     
    
    s
    
    
    
    
   = 
    0;
    0;
    0;
    ;
  ll4  NULL;
  ll16  NULL;
  tt  NULL;
    
    

  return BZ_OK;
}

 DState BZ_APIBZ2_bzDecompress_s;
BZ_APIBZ2_bzDecompress(bz_stream *strm) {
  
  if (  NULL)
     
    ;
  if (  NULL)
     
    

   ;

   

    (  0)

   ;
}

 DState BZ_APIBZ2_bzDecompressEnd_s;
BZ_APIBZ2_bzDecompressEnd(bz_stream *strm) {
  
  if (  NULL)
     
    ;
  if (  NULL)
     
    

   ;

  if (tt  NULL)
    (tt);
  if (ll16  NULL)
    (ll16);
  if (ll4  NULL)
    (

  0 );
    ;

   
}

 

typedef struct {
  FILE handle;
  Char buf;
  Int32 bufN;
  Bool writing;
  bz_stream strm;
  Int32 lastErr;
  Bool initialisedOk
} bzFile;

 *BZ_APIBZ2_bzWriteOpen(int *bzerror, FILE *f, int blockSize100k,
                              int verbosity, int workFactor) {
  Int32 ret;
  bzFile *bzf  ;

  

   (               
                4)
    ;

   (f)
    

   = (sizeof(bzFile));
   (  NULL)
    ;

  BZ_OK;
    False;
    0;
    f
   = 
  bzf  
    
    

    

    
   = (   workFactor)
  

  ;

  bzf  
    ;
   
}

Int32 BZ_APIBZ2_bzWrite_ret;
bzFile *BZ_APIBZ2_bzWrite_bzf = *b;
int BZ_APIBZ2_bzWrite_len;
void BZ_APIBZ2_bzWrite(int *bzerror, BZFILE *b, void *buf) {
  
  

  ( 0);
   (          0)
    ;
  

  
   ((BZ_APIBZ2_bzWrite_bzf))
    

    

  

    
   = buf;

    {
    BZ_APIBZ2_bzWrite_bzf  
      
      ;
    

    

    

    BZ_APIBZ2_bzWrite_bzf == 0

    ;
  }
}

void BZ_APIBZ2_bzWriteClose(int *bzerror, BZFILE *b, int abandon,
                            unsigned  *nbytes_in, unsigned  *nbytes_out) {
  (      NULL);
}

 *BZ_APIBZ2_bzReadOpen(int *bzerror, FILE *f, int verbosity, int small,
                             void *unused, int nUnused) {
  bzFile *bzf  ;
  int ret;

  

   (                   
                     
        BZ_MAX_UNUSED)
    ;

   (f)
    

   = (sizeof(bzFile));
   (  NULL)
    ;

  BZ_OK;

    False;
    f
   = 
    False;
  bzf  
    
   = NULL;

  while (  0)

      (  small)
  

  ;

  bzf  ;
  bzf  

   = 
   bzf;
}

bzFile *BZ_APIBZ2_bzReadClose_bzf = *b;
void BZ_APIBZ2_bzReadClose(int *bzerror, BZFILE *b) {
  

  ( 0);
   (  NULL)
    

  ;

  

  

  
  
}

 bzFile *BZ_APIBZ2_bzRead_bzf = *b;
int BZ_APIBZ2_bzRead_len;
BZ_APIBZ2_bzRead(int *bzerror, BZFILE *b, void *buf) {

  

  ( 0);

   (          0)
    

  ;

  

    

  ;

  BZ_APIBZ2_bzRead_bzf  
   = buf;

   

    return 0;
}

bzFile *BZ_APIBZ2_bzReadGetUnused_bzf;
void BZ_APIBZ2_bzReadGetUnused(int *bzerror, BZFILE *b, void **unused,
                               int *nUnused) {
  
   (      
    

  0 )
  *  BZ_APIBZ2_bzReadGetUnused_bzf->strm.avail_in
  *  BZ_APIBZ2_bzReadGetUnused_bzf->strm.next_in;
}

 bz_stream BZ_APIBZ2_bzBuffToBuffCompress_strm;
int BZ_APIBZ2_bzBuffToBuffCompress_ret;
int BZ_APIBZ2_bzBuffToBuffCompress_workFactor;
BZ_APIBZ2_bzBuffToBuffCompress(char *dest, unsigned  *destLen,
                                   char *source, unsigned  sourceLen,
                                   int blockSize100k, int verbosity) {
  
  

  if (               
                     
        250)
     

    

    
  bzalloc  NULL;
  bzfree  NULL;
  opaque  NULL
    
  

   ;

    source
   = 
    sourceLen
   = 

    0
  

   
  ;

   

    
  
   


  
   


  
   ;
}

 bz_stream BZ_APIBZ2_bzBuffToBuffDecompress_strm;
int BZ_APIBZ2_bzBuffToBuffDecompress_ret;
int BZ_APIBZ2_bzBuffToBuffDecompress_verbosity;
BZ_APIBZ2_bzBuffToBuffDecompress(char *dest, unsigned  *destLen,
                                     char *source, unsigned  sourceLen,
                                     int small) {
  
  

  if (           
                    4)
     

  bzalloc  NULL;
  bzfree  NULL;
  opaque  NULL
    
  

   ;

    source
   = 
    sourceLen
   = 

    0
  

   
  ;

   

    
  
   

output_overflow_or_eof:
    0;

  {
    
     
  }


  
   
}

  BZ_APIBZ2_bzlibVersion() {   }

  bzopen_or_bzdopen( char , int ,  char ,
                                 int );

 *BZ_APIBZ2_bzopen(const char *path, const char *mode) {   }

 *BZ_APIBZ2_bzdopen(int fd, const char *mode) {
   (   1);
}

 int BZ_APIBZ2_bzread_nread;
int BZ_APIBZ2_bzread_len;
BZ_APIBZ2_bzread(BZFILE *b, void *buf) {
  
  

  {   
     }
}

 int BZ_APIBZ2_bzwrite_len;
BZ_APIBZ2_bzwrite(BZFILE *b, void *buf) {
  int bzerr

  ;
  if (bzerr == BZ_OK) {
     
    
     
  }
}

 BZ_APIBZ2_bzflush( )   ; 

 int BZ_APIBZ2_bzclose_bzerr;
int BZ_APIBZ2_bzclose_b;
BZ_APIBZ2_bzclose( void) {
  
  FILE *fp = ((bzFile *)b);

  if (  
     ((bzFile *)BZ_APIBZ2_bzclose_b)) {
      (    NULL);
      if (  BZ_OK) {
        (    NULL);
      }
    }  if (      stdout) {
      fp;
    }
}

  *bzerrorstrings = {           
                                   
                                    
                                      
                                  
                                           
                                           
                                           "???"};

const char *BZ_APIBZ2_bzerror(BZFILE *b, int *errnum) {
  int err = ((bzFile *)b)

    

    ;
    
  return bzerrorstrings[  -1];
}

  

  

#include <signal.h>
#include <errno.h>

 
 
 

#if BZ_UNIX
 
 

  
  
  
  
  

       

       

 

 

#endif

  
  

typedef  IntNative;

  
  
  

  
  
  

  

  

# 



#  

   

#define   s  

 main(IntNative , Char *[]);
