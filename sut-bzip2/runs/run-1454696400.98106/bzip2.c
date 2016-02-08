 







 

                
              
             

#define BZ_OK                0
#define BZ_RUN_OK            1
           
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
       
       int avail_in;
       int total_in_lo32;
       int total_in_hi32

       
        ;
       int total_out_lo32;
       int total_out_hi32;

      void *state;

      void *(*bzalloc)(void *,int,int);
      void (*bzfree)(void *,void *);
      void *opaque
   } 
   bz_stream;



#include <stdio.h>

#   define BZ_API 
#   define BZ_EXTERN 




  BZ2_bzCompressInit ( 
      bz_stream* , 
      int        , 
      int        , 
      int         
   );

  BZ2_bzCompress ( 
      bz_stream* , 
      int  
   );

    
        
   ;

  BZ2_bzDecompressInit ( 
      bz_stream *, 
      int       , 
      int       
   );

    
        
   ;

    
       *strm 
   ;





#define BZ_MAX_UNUSED 0

typedef  BZFILE;

 * BZ2_bzReadOpen ( 
      int*  ,   
      FILE* , 
      int   , 
      int   ,
      void* ,    
      int    
   );

 void BZ2_bzReadClose ( 
      int*    , 
      BZFILE*  
   );

 void BZ2_bzReadGetUnused ( 
      int*    , 
      BZFILE* , 
      void**  ,  
      int*     
   );

  BZ2_bzRead ( 
      int*    , 
      BZFILE* , 
      void*   , 
      int      
   );

 * BZ2_bzWriteOpen ( 
      int*  ,      
      FILE* , 
      int   , 
      int   , 
      int    
   );

 void BZ2_bzWrite ( 
      int*    , 
      BZFILE* , 
      void*   , 
      int      
   );

 void BZ2_bzWriteClose ( 
      int*          , 
      BZFILE*       , 
      int           , 
      unsigned * , 
      unsigned *  
   );

 void BZ2_bzWriteClose64 ( 
      int*          , 
      BZFILE*       , 
      int           , 
      unsigned * , 
      unsigned * , 
      unsigned * , 
      unsigned * 
   );




  BZ2_bzBuffToBuffCompress ( 
      char*         , 
      unsigned * ,
      char*         , 
      unsigned   ,
      int           , 
      int           , 
      int            
   );

  BZ2_bzBuffToBuffDecompress ( 
      char*         , 
      unsigned * ,
      char*         , 
      unsigned   ,
      int           , 
      int            
   );




 const char * BZ2_bzlibVersion (
      
   );

  * BZ2_bzopen (
      const char *,
      const char *
   );

  * BZ2_bzdopen (
      int        ,
      const char *
   );
         
  BZ2_bzread (
      BZFILE* , 
      void* , 
      int  
   );

  BZ2_bzwrite (
      BZFILE* , 
      void*   , 
      int      
   );

   
       
   ;

 void  
       
   ;

 const char * BZ2_bzerror (
      BZFILE *, 
      int    *
   );









 

#include <stdlib.h>




#define BZ_VERSION  "1.0.2, 30-Dec-2001"


typedef     Bool;

typedef              Int32;
typedef      UInt32;



#define True  (1)
#define False (0)

   

 void    ;
#define errcode 
   
#define msg 
   
#define  \
   zf
#define  \
   za1
#define  \
   za2
#define  \
   za3
#define  \
   za4
#define  \
   za5


#define nnn 
#define ppp  




     
     
     
     
  


#define BZ_MAX_ALPHA_SIZE 8
     

  
  

#define BZ_N_GROUPS 6
#define BZ_G_SIZE   50
   

#define BZ_MAX_SELECTORS (  (  BZ_G_SIZE))







#define BZ_RAND_DECLS                          \
                                   \
                                     

#define                       \
   srNToGo                                \
                                     

#define BZ_RAND_MASK       

#define BZ_RAND_UPD_MASK                       \
                                                  \
   







#define crcVar              


#define crcVar                


#define cha              






       
#define BZ_M_RUNNING   2
   
  

     
#define BZ_S_INPUT     2

#define BZ_N_RADIX 
#define BZ_N_QSORT 
#define BZ_N_SHELL 
#define BZ_N_OVERSHOOT (      2)






typedef
   struct {
      
       

      
      
          
          

      
         ;

      
      UInt32  arr1;
      UInt32  arr2;
      UInt32  ftab
          ;

      
      UInt32  ptr;
       char   block;
       short  mtfv;
       char   zbits

      
          

      
         
          ;
      

      
      Int32    nblock
          
          
          ;

      
      Int32    nInUse;
      Bool     ;
       char    ;

      
         
          

      
      UInt32   
         

      
          
          blockNo
          ;

      
      Int32    nMTF;
      Int32    mtfFreq    [BZ_MAX_ALPHA_SIZE];
       char       ;
       char    ;

       char    len     
              
             
      
         

   }
   EState









;









         
       

#define BZ_X_MAGIC_1     0
      
      
      
     
     
     
     
     
     
       
       
       
       
      
    
    
    
    
    
   
   
   
     
     
     
        
        
        
        
        
        
     
     
     
     
     
       
       
       
       





#define MTFA_SIZE 4096
#define MTFL_SIZE 6





typedef
   struct {
      
       

      
          

      
           
          
           
      

      
         
      Int32    

      
          
           
          
          

      
          
         
          
          ;
          ;
      Int32    ;
      Int32    ;

      
      UInt32   tt;

      
       short   ll16;
       char    ll4

      
         
         
         
         

      
          ;
      Bool     ;
      Bool     ;
       char    ;

      
       char       ;
      Int32    mtfbase[  MTFL_SIZE]
              [BZ_MAX_SELECTORS]
           [BZ_MAX_SELECTORS]
             [BZ_MAX_ALPHA_SIZE]

            
             
             
          

      
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
           
          
          
          
          
         
         
         ;

   }
   DState;





#define c                     \
                       \
                   \
      

#define                    \
                          \
      c_tPos              
    c_tPos  

#define in                                          
   

#define GET_LL4i                             \
             

#define in                          
   

#define GET_LLi \
       

#define                             \
           scftab     \
        






void  
BZ2_decompress (  );




























#define  zz2 
   

#define   zzn       



#define ab       

#define hz 

#define hz 

  
    




# 
 
 
 
 
 
 





#define         zz        
#define       zz        
#define       zz        
#define        zz  
#define   zz  



       
     
     
      
 






















#define  zz2 
   

#define   zzn       




#define ab       

#define dz 

#define dz 


#define  nextLoaz

#define bz                                        
   


  
#define    BZ_N_QSORT
  



# 
 
 
 
 
 
 
 
 
 





#define BIGFREQb       
#define SETMASK   
#define  SETMASK



 
 
 


















#define   zz0  
#define    zz1  
#define        zz3

#define                            \
   zw2                     \
     

#define z                                     


#define z                                   



































































#define nz                           




















EState * makeMaps_e_s;

 makeMaps_e (  )
{
   Int32 i
     
    = 0;
   
   for (;   ; )
      
         ;
      
}



EState  generateMTFValues_s;

 generateMTFValues (  )
{
    char   
     ;
    char yy_0;
   Int32   i ;
   Int32   zPend;
   Int32   wr;
   Int32   EOB

   
       = (generateMTFValues_s.ptr)
    ;
        
     
        (generateMTFValues_s);
    short mtfv_0

   
    = 

   i  ;
   
   for (;   ; ) generateMTFValues_s.mtfFreq[0]  

     
     
     ;
   
   for (;   ; )     

     0;
   
   for (;   ; ) 

     
   
       ; generateMTFValues_s.mtfFreq;

     0;
}



   
  























#define rrr                               
   

#define                      \
       lll                      \
     

#define uuu                        \
   

#define uuu                          \
   


#define lval           




     s 


















    




     
;



  default_bzalloc     
;


 default_bzfree    





  (  )
;




   void 



     
;



 BZ2_bzCompressInit 
                    ( bz_stream* strm, 
                     int        blockSize100k,
                     int        verbosity,
                     int        workFactor )
{
   Int32   n;
   EState* s;
   UInt32 s_8;
    short s_10;
    char s_9;
   Int32 s_12;
   Int32 s_28;
   Int32 s_18;
   Int32 s_30;
   UInt32 s_27;
   Int32 s_1;
   Int32 s_2;
   UInt32 s_6;
   UInt32 s_5;
   UInt32 s_4;
   bz_stream *s_0;

   if (0)  

   if (    
              
             0)
      

   if (  0)   
   if (bzalloc  NULL)   default_bzalloc;
   if (bzfree  NULL)   

     BZALLOC(  );
   if (  NULL)  
     

   arr1  NULL;
   arr2  NULL;
   ftab  NULL

            * 
     BZALLOC(                     );
     ( +  sizeof(UInt32) );
     (                sizeof(UInt32) );

   if (          NULL) 

               
                 
                  
           
         
                 9
             
            ;

   s_9             = (unsigned char*)s_5;
   s_10              = *(unsigned short*)s_4;
   s->zbits             = NULL;
   s_8               = *(UInt32*)s_4;

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












void  handle_compress ( void )
;



int BZ_API(BZ2_bzCompress) ( bz_stream *strm, int action )
{
   
   EState* s;
   Int32 s_1;
   bz_stream s_0;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (&s_0 != strm) return BZ_PARAM_ERROR;

   preswitch:
   switch (s_1) 
   return BZ_OK; 
}



int BZ_API(BZ2_bzCompressEnd)  ( bz_stream *strm )
{
   EState* s;
   bz_stream s_0;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (&s_0 != strm) return BZ_PARAM_ERROR;

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
   Int32 s_12;
   Int32 s_11;
   Bool s_10;
   UInt32 s_26;
   UInt32 s_7;
   Int32 s_8;
   Int32 s_1;
   bz_stream *s_0;

   if (!0) return BZ_CONFIG_ERROR;

   if (strm == NULL) return BZ_PARAM_ERROR;
   if (small != 0 && small != 1) return BZ_PARAM_ERROR;
   if (verbosity < 0 || verbosity > 4) return BZ_PARAM_ERROR;

   if (strm->bzalloc == NULL) strm->bzalloc = default_bzalloc;
   if (strm->bzfree == NULL) strm->bzfree = default_bzfree;

   s = BZALLOC( sizeof(DState) );
   if (s == NULL) return BZ_MEM_ERROR;
   s_0                  = strm;
   strm->state              = s;
   s_1                 = BZ_X_MAGIC_1;
   s_8                = 0;
   s_7                = 0;
   s_26 = 0;
   strm->total_in_lo32      = 0;
   strm->total_in_hi32      = 0;
   strm->total_out_lo32     = 0;
   strm->total_out_hi32     = 0;
   s_10       = (Bool)small;
   s->ll4                   = NULL;
   s->ll16                  = NULL;
   s->tt                    = NULL;
   s_11           = 0;
   s_12             = verbosity;

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
   bz_stream *s_0;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (s_0 != strm) return BZ_PARAM_ERROR;

   while (True) 

   AssertH ( 0, 1 );

   return 0;  
}



int BZ_API(BZ2_bzDecompressEnd)  ( bz_stream *strm )
{
   DState* s;
   bz_stream s_0;
   if (strm == NULL) return BZ_PARAM_ERROR;
   s = strm->state;
   if (s == NULL) return BZ_PARAM_ERROR;
   if (&s_0 != strm) return BZ_PARAM_ERROR;

   if (s->tt   != NULL) BZFREE(s->tt);
   if (s->ll16 != NULL) BZFREE(s->ll16);
   if (s->ll4  != NULL) BZFREE(s->ll4);

   BZFREE(strm->state);
   strm->state = NULL;

   return BZ_OK;
}






#define BZ_SETERR(e)                    \


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

   BZ_SETERR(BZ_OK);

   if (f == NULL ||
       (blockSize100k < 1 || blockSize100k > 9) ||
       (workFactor < 0 || workFactor > 0) ||
       (verbosity < 0 || verbosity > 4))
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

   if (workFactor == 0) workFactor = 0;
   ret = BZ2_bzCompressInit ( &(bzf->strm), blockSize100k, 
                              verbosity, workFactor );
   if (ret != BZ_OK)
      ;

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
   Int32   ret;
   bzFile* bzf = (bzFile*)b;
   char bzf_4_4;
   unsigned int bzf_4_5;
   char *bzf_4_0;
   unsigned int bzf_4_1;
   Bool bzf_3;

   BZ_SETERR(BZ_OK);
   if (bzf == NULL || buf == NULL || len < 0)
      ;
   if (!(bzf_3))
      ;
   if (ferror(bzf->handle))
      ;

   if (len == 0)
      ;

   bzf_4_1 = len;
   bzf_4_0  = buf;

   while (True) 
      bzf_4_5 = BZ_MAX_UNUSED;
      bzf_4_4 = *bzf->buf;
      ret = 0;
      if (0 != BZ_RUN_OK)
         ;

      if (bzf_4_5 < BZ_MAX_UNUSED) 

      if (len == 0)
         ;
   
}



void BZ_API(BZ2_bzWriteClose)
                  ( int*          bzerror, 
                    BZFILE*       b, 
                    int           abandon,
                    unsigned int* nbytes_in,
                    unsigned int* nbytes_out )
{
   BZ2_bzWriteClose64 ( bzerror, b, abandon, 
                        nbytes_in, NULL, nbytes_out, NULL );
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
   
   bzFile* bzf = (bzFile*)b;
   Bool bzf_3;

   if (bzf == NULL)
      ;
   if (!(bzf_3))
      ;
   if (ferror(bzf->handle))
      ;

   if (nbytes_in_lo32 != NULL) *nbytes_in_lo32 = 0;
   if (nbytes_in_hi32 != NULL) *nbytes_in_hi32 = 0;
   if (nbytes_out_lo32 != NULL) *nbytes_out_lo32 = 0;
   if (nbytes_out_hi32 != NULL) *nbytes_out_hi32 = 0;

   if ((!abandon) && bzf->lastErr == BZ_OK) 

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



BZFILE* BZ_API(BZ2_bzReadOpen) 
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

   BZ_SETERR(BZ_OK);

   if (f == NULL || 
       (small != 0 && small != 1) ||
       (verbosity < 0 || verbosity > 4) ||
       (unused == NULL && nUnused != 0) ||
       (unused != NULL && (nUnused < 0 || nUnused > BZ_MAX_UNUSED)))
      ;

   if (ferror(f))
      ;

   bzf = malloc ( sizeof(bzFile) );
   if (bzf == NULL) 
      ;

   BZ_SETERR(BZ_OK);

   bzf_6 = False;
   bzf->handle        = f;
   bzf_2          = 0;
   bzf_3       = False;
   bzf->strm.bzalloc  = NULL;
   bzf->strm.bzfree   = NULL;
   bzf->strm.opaque   = NULL;
   
   while (nUnused > 0) 

   ret = BZ2_bzDecompressInit ( &(bzf->strm), verbosity, small );
   if (ret != BZ_OK)
      ;

   bzf_4_1 = 0;
   bzf_4_0  = bzf->buf;

   bzf_6 = True;
   return bzf;   
}



void BZ_API(BZ2_bzReadClose) ( int *bzerror, BZFILE *b )
{
   bzFile* bzf = (bzFile*)b;
   Bool bzf_6;
   Bool bzf_3;

   BZ_SETERR(BZ_OK);
   if (bzf == NULL)
      ;

   if (bzf_3)
      ;

   if (bzf_6)
      (void)0;
   0;
}



int BZ_API(BZ2_bzRead) 
           ( int*    bzerror, 
             BZFILE* b, 
             void*   buf, 
             int     len )
{
   
   bzFile* bzf = (bzFile*)b;
   char *bzf_4_4;
   unsigned int bzf_4_5;
   Bool bzf_3;

   BZ_SETERR(BZ_OK);

   if (bzf == NULL || buf == NULL || len < 0)
      ;

   if (bzf_3)
      ;

   if (len == 0)
      ;

   bzf_4_5 = len;
   bzf_4_4 = buf;

   while (True) 

   return 0; 
}



void BZ_API(BZ2_bzReadGetUnused) 
                     ( int*    bzerror, 
                       BZFILE* b, 
                       void**  unused, 
                       int*    nUnused )
{
   bzFile* bzf = (bzFile*)b;
   char bzf_4_0;
   unsigned int bzf_4_1;
   Int32 bzf_5;
   if (bzf == NULL)
      ;
   if (bzf_5 != BZ_STREAM_END)
      ;
   if (unused == NULL || nUnused == NULL)
      ;

   BZ_SETERR(BZ_OK);
   *nUnused = bzf_4_1;
   *unused = &bzf_4_0;
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
   unsigned int strm_5;
   unsigned int strm_1;
   char strm_4;
   char strm_0;
   int ret;

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
   ret = 0;
   if (0 != BZ_OK) return 0;

   strm_0 = *source;
   strm_4 = *dest;
   strm_1 = sourceLen;
   strm_5 = *destLen;

   ret = 0;
   if (0 == BZ_FINISH_OK) goto output_overflow;
   if (0 != BZ_STREAM_END) goto errhandler;

   
   *destLen -= strm_5;   
   0;
   return BZ_OK;

   output_overflow:
   0;
   return BZ_OUTBUFF_FULL;

   errhandler:
   0;
   return 0;
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
   unsigned int strm_5;
   unsigned int strm_1;
   char strm_4;
   char strm_0;
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
   if (0 != BZ_OK) return 0;

   strm_0 = *source;
   strm_4 = *dest;
   strm_1 = sourceLen;
   strm_5 = *destLen;

   ret = 0;
   if (0 == BZ_OK) goto output_overflow_or_eof;
   if (0 != BZ_STREAM_END) goto errhandler;

   
   *destLen -= strm_5;
   0;
   return BZ_OK;

   output_overflow_or_eof:
   if (strm_5 > 0) {
      0;
      return BZ_UNEXPECTED_EOF;
   } else ;      

   errhandler:
   0;
   return 0; 
}








const char * BZ_API(BZ2_bzlibVersion)(void)
{
   return BZ_VERSION;
}




static
BZFILE * bzopen_or_bzdopen
               ( const char *path,   
                 int d,             
                 const char *mode,
                 int open_mode)      
;




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
   return bzopen_or_bzdopen(NULL,fd,mode,1);
}



int BZ_API(BZ2_bzread) (BZFILE* b, void* buf, int len )
{
   int bzerr, nread;
   if (((bzFile*)b)->lastErr == BZ_STREAM_END) return 0;
   nread = 0;
   if (bzerr == BZ_OK || bzerr == BZ_STREAM_END) 
      return 0;
    else 
      return -1;
   
}



int BZ_API(BZ2_bzwrite) (BZFILE* b, void* buf, int len )
{
   int bzerr;

   ;
   if(bzerr == BZ_OK)
      return len;
   else
      return -1;
   
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
   if(((bzFile*)b)->writing)
      BZ2_bzWriteClose(&bzerr,b,0,NULL,NULL);
      if(bzerr != BZ_OK)
         BZ2_bzWriteClose(NULL,b,1,NULL,NULL);
      
   else
   if(fp!=stdin && fp!=stdout)
      fclose(fp);
   
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


const char * BZ_API(BZ2_bzerror) (BZFILE *b, int *errnum)
{
   int err = ((bzFile *)b)->lastErr;

   if(((bzFile *)b)->lastErr>0) err = 0;
   *errnum = 0;
   return "OK";
}




























#define BZ_UNIX      1


#define BZ_LCCWIN32  0





#include <signal.h>
#include <errno.h>

#define ERROR_IF_EOF(i)       
#define ERROR_IF_NOT_ZERO(i)  
#define ERROR_IF_MINUS_ONE(i) 





#if BZ_UNIX
#   include <fcntl.h>
#   include <utime.h>

#   define PATH_SEP    '/'
#   define MY_LSTAT    lstat
#   define MY_STAT     stat
#   define MY_S_ISREG  S_ISREG
#   define MY_S_ISDIR  S_ISDIR

#   define APPEND_FILESPEC(root, name) \
      root=snocString((root), (name))

#   define APPEND_FLAG(root, name) \
      root=snocString((root), (name))

#   define SET_BINARY_MODE(d) 

#      define NORETURN 

#endif 





                                       
#define True  ((Bool)1)
#define False ((Bool)0)
















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





























































































































#if BZ_UNIX

#endif












#define BZ_N_SUFFIX_PAIRS 4
























































#define ISFLAG(s) (strcmp(aa->name, (s))==0)

void  main ( void )
;




 