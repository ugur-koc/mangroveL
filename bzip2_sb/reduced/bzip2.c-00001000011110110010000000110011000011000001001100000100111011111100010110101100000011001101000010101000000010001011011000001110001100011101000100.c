#ifndef _BZLIB_H
#define BZ_OK                0
#define BZ_STREAM_END        4
#endif
#ifndef BZ_NO_STDIO
  void BZ2_bz__AssertH__fail ( void ) {
              int a;
              if (a == BZ_OK || a == BZ_STREAM_END) ;
           }
#endif /* BZ_UNIX */
