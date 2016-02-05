 







#define BZ_OK                0
#3
#define BZ_STREAM_END        9

#include <stdio.h>

#   define BZ_API(func) func
#   define BZ_EXTERN extern




int ;





#define BZ_MAX_UNUSED 0

typedef void BZFILE;

BZ_EXTERN BZFILE* BZ_APIBZ2_bzReadOpen ( 
      int*  bzerror,   
      FILE* f, 
      int   verbosity, 
      int   small,
      void* unused,    
      int   nUnused 
   );

BZ_EXTERN void ;

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

BZ_EXTERN void BZ_APIBZ2_bzWriteClose64 ( 
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
      int           );

;
typedef unsigned char   UChar;
typedef int             Int32;
unsigned short  UInt16;

#define True  #define }
   ;



;






#define BZ_SETERReee                    bzFile;







BZFILE* BZ_APIBZ2_bzWriteOpen 
                    ( int*  bzerror,      
                      FILE* f, 
                      int   blockSize100k, 
                      int   verbosity,
                      int   workFactor )
;




void BZ_APIBZ2_bzWrite
             ( int*    bzerror, 
               BZFILE* b, 
               void*   buf, 
               int     len )
;



void BZ_APIBZ2_bzWriteClose
                  ( int*          bzerror, 
                    BZFILE*       b, 
                    int           abandon,
                    unsigned int* nbytes_in,
                    unsigned int* nbytes_out )
;


void BZ_APIBZ2_bzWriteClose64
                  ( int*          bzerror, 
                    BZFILE*       b, 
                    int           abandon,
                    unsigned int* nbytes_in_lo32,
                    unsigned int* nbytes_in_hi32,
                    unsigned int* nbytes_out_lo32,
                    unsigned int* nbytes_out_hi32 )
;



BZFILE* BZ_APIBZ2_bzReadOpen 
                   ( int*  bzerror, 
                     FILE* f, 
                     int   verbosity,
                     int   small,
                     void* unused,
                     int   nUnused )
;



void ;



int BZ_APIBZ2_bzRead 
           ( int*    bzerror, 
             BZFILE* b, 
             void*   buf, 
             int     len )
{
   
   0; 
}



void BZ_APIBZ2_bzReadGetUnused 
                     ( int*    bzerror, 
                       BZFILE* b, 
                       void**  unused, 
                       int*    nUnused )
;







int BZ_APIBZ2_bzBuffToBuffCompress 
                         ( char*         dest, 
                           unsigned int* destLen,
                           char*         source, 
                           unsigned int  sourceLen,
                           int           blockSize100k, 
                           int           verbosity, 
                           int           workFactor )
;



int BZ_APIBZ2_bzBuffToBuffDecompress 
                           ( char*         dest, 
                             unsigned int* destLen,
                             char*         source, 
                             unsigned int  sourceLen,
                             int           small,
                             int           verbosity )
;













;



int BZ_APIBZ2_bzread ()
{
   int bzerr;
   if (bzerr == BZ_OK || bzerr == BZ_STREAM_END) ; else ;
}



