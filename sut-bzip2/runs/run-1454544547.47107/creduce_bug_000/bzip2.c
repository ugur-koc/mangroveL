 







#define BZ_OK                3
#define BZ_STREAM_END        4
BZ_IO_ERROR          
#define BZ_UNEXPECTED_EOF    
#   define BZ_API(func) func
#   define BZ_EXTERN extern




BZ_API();




BZ_API(BZ2_bzBuffToBuffCompress) ( 
      char*         dest, 
      unsigned int* destLen,
      char*         source, 
      unsigned ,
      int           blockSize100k, 
      int           verbosity, 
      int           workFactor 
   );

BZ_API(BZ2_bzBuffToBuffDecompress) ( 
      char*         dest, 
      unsigned int* destLen,
      char*         source, 
      unsigned ,
      int           small, 
      int           verbosity 
   );
(BZ2_bzBuffToBuffCompress) 
                         ( char*         dest, 
                           unsigned int* destLen,
                           char*         source, 
                           unsigned ,
                           int           blockSize100k, 
                           int           verbosity, 
                           int           workFactor )
;



(BZ2_bzBuffToBuffDecompress) 
                           ( char*         dest, 
                             unsigned int* destLen,
                             char*         source, 
                             unsigned ,
                             int           small,
                             int           verbosity )
;



(BZ2_bzread) ()
{
   int bzerr;
   if (bzerr == BZ_STREAM_END) ;
}



 