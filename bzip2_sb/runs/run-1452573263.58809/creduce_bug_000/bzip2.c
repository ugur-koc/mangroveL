 #ifndef _BZLIB_H
#define BZ_OK                0
#define BZ_STREAM_END        4
#define BZ_PARAM_ERROR       -2
typedef 
   struct {
      unsigned int avail_in;
      unsigned int avail_out;
      void *state;
   } 
   bz_stream;
#include <stdio.h>
#ifdef _WIN32
#else
#   define BZ_API(func) func
#   define BZ_EXTERN extern
#endif
BZ_EXTERN int BZ_APIBZ2_bzCompressInit ( 
      bz_stream* strm, 
      int        blockSize100k, 
      int        verbosity, 
      int        workFactor 
   );
#ifndef BZ_NO_STDIO
typedef void BZFILE;
BZ_EXTERN BZFILE* BZ_APIBZ2_bzReadOpen ( 
      int*  bzerror,   
      FILE* f, 
      int   verbosity, 
      int   small,
      void* unused,    
      int   nUnused 
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
#endif
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
/*--
--*/
BZ_EXTERN const char * BZ_APIBZ2_bzlibVersion 
   ;
#ifndef BZ_NO_STDIO
BZ_EXTERN BZFILE * BZ_APIBZ2_bzopen ;
BZ_EXTERN int BZ_API ;
BZ_EXTERN void BZ_API (
   );
#endif
#ifdef __cplusplus
#endif
#endif
#ifndef _BZLIB_PRIVATE_H
typedef unsigned char   Bool;
typedef unsigned char   UChar;
typedef int             Int32;
typedef unsigned int    UInt32;
#define True  1
#ifndef __GNUC__
#endif 
#ifndef BZ_NO_STDIO

#define AssertH \
   { if  BZ2_bz__AssertH__fail ; }
#endif
#define BZ_RUNA 0
#define BZ_RUNB 1
#define BZ_RAND_DECLS                          \
   s->rNToGo--;
#define BZ_M_RUNNING   2
#define BZ_M_FINISHING 4
#define BZ_S_OUTPUT    1
#define BZ_S_INPUT     2
typedef
   struct {
      bz_stream* strm;
      Int32    mode;
      Int32    state;
      UInt32   avail_in_expect;
      Int32    state_in_len;
      Int32    nblock;
      Int32    nInUse;
      Int32    nMTF;
   }
   EState;
#define BZ_X_MAGIC_1     10
#define MTFL_SIZE 16
typedef
   struct {
      Int32    state;
      Bool     blockRandomised;
      Bool     smallDecompress;
      Bool     inUse[256];
      Int32    mtfbase[256 / MTFL_SIZE];
   }
   DState;
#endif
#ifdef BZ_NO_STDIO
#ifndef NULL
#endif
#endif

/* Pre:
*/


/*--
*/
#define SETMASK 
#define CLEARMASK 

/* Pre:
*/







#define GET_BITS                     \
   }

#ifndef BZ_NO_STDIO

#endif

EState *BZ_APIBZ2_bzCompressInit_s;
Int32 BZ_APIBZ2_bzCompressInit_i;
int BZ_APIBZ2_bzCompressInit 
                    ( bz_stream* strm, 
                     int        blockSize100k,
                     int        verbosity,
                     int        workFactor )
{
   
   
   for (BZ_APIBZ2_bzCompressInit_i = 0; BZ_APIBZ2_bzCompressInit_i < BZ_APIBZ2_bzCompressInit_s->state_in_len; BZ_APIBZ2_bzCompressInit_i++) {
   }
   switch (BZ_APIBZ2_bzCompressInit_s->state_in_len) {
   }
}



int BZ_APIBZ2_bzDecompressInit 
                     ( bz_stream* strm, 
                       int        small )
{
}

int BZ_APIBZ2_bzDecompress ( bz_stream *strm )
{
}
#ifndef BZ_NO_STDIO
#define BZ_SETERR                    \
{                                         \
}
typedef 
   struct {
      FILE*     handle;
      bz_stream strm;
      Int32     lastErr;
   }
   bzFile;
BZFILE* BZ_APIBZ2_bzWriteOpen 
                    ( int*  bzerror,      
                      FILE* f, 
                      int   blockSize100k, 
                      int   verbosity,
                      int   workFactor )
{
   bzFile* bzf = NULL;
   if (f == NULL ||
       verbosity < 0 || verbosity > 4)
   return bzf;   
}
void BZ_APIBZ2_bzWrite
             ( int*    bzerror, 
               BZFILE* b, 
               void*   buf, 
               int     len )
{
   while (True) {
   }
}
void BZ_APIBZ2_bzWriteClose
                  ( int*          bzerror, 
                    BZFILE*       b, 
                    int           abandon,
                    unsigned int* nbytes_in,
                    unsigned int* nbytes_out )
{
   BZ2_bzWriteClose64 ;
}
Int32 BZ_APIBZ2_bzWriteClose64_n;
Int32 BZ_APIBZ2_bzWriteClose64_n2;
void BZ_APIBZ2_bzWriteClose64
                  ( int*          bzerror, 
                    BZFILE*       b, 
                    int           abandon,
                    unsigned int* nbytes_in_lo32,
                    unsigned int* nbytes_in_hi32,
                    unsigned int* nbytes_out_lo32,
                    unsigned int* nbytes_out_hi32 )
{
   Int32     ret;
   bzFile* bzf = b;
   if (!abandon && bzf->lastErr == BZ_OK) {
      while (True) {
         if (ret == BZ_STREAM_END) break;
      }
   }
}
BZFILE* BZ_APIBZ2_bzReadOpen 
                   ( int*  bzerror, 
                     FILE* f, 
                     int   verbosity,
                     int   small,
                     void* unused,
                     int   nUnused )
{
}
int BZ_APIBZ2_bzRead 
           ( int*    bzerror, 
             BZFILE* b, 
             void*   buf, 
             int     len )
{
   bzFile* bzf = b;
   while (True) {
      if (bzf->strm.avail_in == 0 && !myfeof(bzf->handle)) {
      }
         { BZ_SETERR;
           return len - bzf->strm.avail_out; };
   }
}
void BZ_APIBZ2_bzReadGetUnused 
                     ( int*    bzerror, 
                       BZFILE* b, 
                       void**  unused, 
                       int*    nUnused )
{
}
#endif
int BZ_APIBZ2_bzBuffToBuffCompress 
                         ( char*         dest, 
                           unsigned int* destLen,
                           char*         source, 
                           unsigned int  sourceLen,
                           int           blockSize100k, 
                           int           verbosity, 
                           int           workFactor )
{
   if (dest == NULL || destLen == NULL || 
       workFactor < 0 || workFactor > 250) 
      return BZ_PARAM_ERROR;
}
bz_stream BZ_APIBZ2_bzBuffToBuffDecompress_strm;
int BZ_APIBZ2_bzBuffToBuffDecompress 
                           ( char*         dest, 
                             unsigned int* destLen,
                             char*         source, 
                             unsigned int  sourceLen,
                             int           small,
                             int           verbosity )
{
   
   if (BZ_APIBZ2_bzBuffToBuffDecompress_strm.avail_out > 0) {
   };      
}
/*--
--*/
const char * BZ_API(BZ2_bzlibVersion)(void)
{
}
#ifndef BZ_NO_STDIO

/*--
--*/
static char *bzerrorstrings[] ;
const char * BZ_APIBZ2_bzerror (BZFILE *b, int *errnum)
{
}
#endif
/*--
#endif /* BZ_LCCWIN32 */
 