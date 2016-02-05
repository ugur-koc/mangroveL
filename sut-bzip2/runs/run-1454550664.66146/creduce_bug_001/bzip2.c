 







 

                
              
             

#define BZ_OK                0
             
           
          
#define BZ_STREAM_END        4
#define     BZ_OUTBUFF_FULL      
#define BZ_CONFIG_ERROR      

typedef 
   struct {
       
        
        
        

       

      void (*bzalloc)
       ;
   } 
   bz_stream;



#include <stdio.h>

#   define BZ_API 
#   define BZ_EXTERN 




  BZ2_bzCompressInit ;

    
       strm 
   

  ;





#define BZ_MAX_UNUSED 5000

typedef  BZFILE;

 * BZ2_bzReadOpen ( 
      int*  ,   
      FILE* , 
      int   , 
      int   ,
      void* ,    
      int    
   );

 void   
      ;

   
   

 void  BZ2_bzWriteOpen ( 
      );

  BZ2_bzWrite ;

  BZ2_bzWriteClose ;

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




 const char * BZ2_bzlibVersion 

  


         
  

  ;

   b
   

 ;









 

#include <stdlib.h>




   

typedef             Char;
typedef     Bool;
typedef     UChar;
typedef              Int32;
typedef      UInt32
            ;
    

#define True  
#       
     
  


  
     

  
  

  
#define BZ_G_SIZE   50
   

#define BZ_MAX_SELECTORS 







#define                           \
                                   \
    rTPos                                 



#define                          BZ_N_SHELL  






typedef
   struct {
      
      
         
          
      UChar    

          
          ;

   }
   EState









;









       
       
       





#define MTFA_SIZE 4096
#define MTFL_SIZE 16






   struct {
      
      
          
          
         ;
      UChar    ;

      
      UChar       ;
      Int32    mtfbase[  MTFL_SIZE]
             
          
          
          
          
          
          ;
          
         
         

   }
   





   (  s )




  
;











#define ADD_CHAR_TO_BLOCKBZ_API                        


typedef 
   struct {
           ;
      Char      ;
           
            
      bz_stream 
           
            initialisedOk
   }
   bzFile;







void  BZ2_bzWriteOpen 
                    (     
               int      
                               
                      
                    unsigned   )
;


void BZ2_bzWriteClose64
                  ( int*          , 
                    BZFILE*       , 
                    int           ,
                    unsigned * ,
                    unsigned * ,
                    unsigned * ,
                    unsigned *  )
;



* BZ2_bzReadOpen 
                   ( int*  , 
                     FILE* , 
                     int   ,
                     int   ,
                     void* ,
                     int   )
;



 BZ2_bzRead 
           (      
               
             void*   buf, 
             int     len )
{
   
      
      ;

     

   return 0; 
}



  
                      








 (BZ2_bzBuffToBuffCompress) 
                         ( char*         , 
                           unsigned * ,
                           char*         , 
                           unsigned   ,
                           int           , 
                           int           , 
                           int            )
;



 BZ2_bzBuffToBuffDecompress 
                           ( char*         , 
                             unsigned * ,
                             char*         , 
                             unsigned   ,
                             int           ,
                             int            )
;








const char * BZ2_bzlibVersionvoid
;





  bzopen_or_bzdopen
                     





 ;



 BZ2_bzread (    int len )
{
   int bzerr, 
   
   nread  ;
   if (    bzerr == BZ_STREAM_END)   ;
}



 



 BZ2_bzflusherrnum
;




























#define  i 





#if BZ_UNIX
 

        

#endif 





                                       
#define   Bool1
#define  Bool0


  













# 














  