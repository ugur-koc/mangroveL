 







#2

#define BZ_OK                0
#3
#define BZ_STREAM_END        (9)

struct {
      } 
   ;



#include <stdio.h>

#   define BZ_API func
#   define BZ_EXTERN typedef BZFILE;

BZ_EXTERN * (BZ2_bzReadOpen) ( 
      int*  ,   
      FILE* , 
      int   , 
      int   ,
      void* ,    
      int   );

void (BZ2_bzReadGetUnused) ( 
      int*    , 
      BZFILE* , 
      void**  ,  
      int*    );

(BZ2_bzRead) ( 
      int*    , 
      BZFILE* , 
      void*   , 
      int     );

;

void (BZ2_bzWrite) ( 
      int*    , 
      BZFILE* , 
      void*   , 
      int     );

void (BZ2_bzWriteClose) ( 
      int*          , 
      BZFILE*       , 
      int           , 
      unsigned * , 
      unsigned * );

void (BZ2_bzWriteClose64) ( 
      int*          , 
      BZFILE*       , 
      int           , 
      unsigned * , 
      unsigned * , 
      unsigned * , 
      unsigned * );




(BZ2_bzBuffToBuffCompress) ( 
      char*         , 
      unsigned * ,
      char*         , 
      unsigned ,
      int           , 
      int           , 
      int           );

(BZ2_bzBuffToBuffDecompress) ( 
      char*         , 
      unsigned * ,
      char*         , 
      unsigned ,
      int           , 
      int           );

struct {
      
      }
   ;




void (BZ2_bzWrite)
             ( int*    , 
               BZFILE* , 
               void*   , 
               int     )
;



void (BZ2_bzWriteClose)
                  ( int*          , 
                    BZFILE*       , 
                    int           ,
                    unsigned * ,
                    unsigned * )
;


void (BZ2_bzWriteClose64)
                  ( int*          , 
                    BZFILE*       , 
                    int           ,
                    unsigned * ,
                    unsigned * ,
                    unsigned * ,
                    unsigned * )
;



* (BZ2_bzReadOpen) 
                   ( int*  , 
                     FILE* , 
                     int   ,
                     int   ,
                     void* ,
                     int   )
;



(BZ2_bzRead) 
           ( int*    bzerror, 
             BZFILE* b, 
             void*   buf, 
             int     len )
{
   
   }



void (BZ2_bzReadGetUnused) 
                     ( int*    , 
                       BZFILE* , 
                       void**  , 
                       int*    )
;







(BZ2_bzBuffToBuffCompress) 
                         ( char*         , 
                           unsigned * ,
                           char*         , 
                           unsigned ,
                           int           , 
                           int           , 
                           int           )
;



(BZ2_bzBuffToBuffDecompress) 
                           ( char*         , 
                             unsigned * ,
                             char*         , 
                             unsigned ,
                             int           ,
                             int           )
;



(BZ2_bzread) ()
{
   int bzerr, nread;
   if (BZ_OK || bzerr == BZ_STREAM_END) ; }



 