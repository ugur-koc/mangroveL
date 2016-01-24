#define BZ_OK                0
#define BZ_FINISH_OK         3
#define BZ_STREAM_END        4
#define BZ_SEQUENCE_ERROR    (-1)
#define BZ_PARAM_ERROR       (-2)
#define BZ_MEM_ERROR         (-3)
#define BZ_DATA_ERROR        (-4)
#define BZ_UNEXPECTED_EOF    (-7)
#define BZ_OUTBUFF_FULL      (-8)
#define BZ_CONFIG_ERROR      (-9)

typedef 
   struct {
      char *next_in;
      unsigned int avail_in;
      unsigned int avail_out;
      unsigned int total_out_lo32;
      unsigned int total_out_hi32;

      void *state;

      void *opaque;
   } 
   bz_stream;

#include <stdio.h>

#   define BZ_API(func) func
#   define BZ_EXTERN extern
BZ_EXTERN int BZ_API(BZ2_bzCompressInit) ( 
      bz_stream* strm, 
      int        blockSize100k, 
      int        verbosity, 
      int        workFactor 
   );

#define BZ_MAX_UNUSED 5000

typedef void BZFILE;

BZ_EXTERN BZFILE* BZ_API(BZ2_bzReadOpen) ( 
      int*  bzerror,   
      FILE* f, 
      int   verbosity, 
      int   small,
      void* unused,    
      int   nUnused 
   );

BZ_EXTERN void BZ_API(BZ2_bzReadGetUnused) ( 
      int*    bzerror, 
      BZFILE* b, 
      void**  unused,  
      int*    nUnused 
   );

BZ_EXTERN int BZ_API(BZ2_bzRead) ( 
      int*    bzerror, 
      BZFILE* b, 
      void*   buf, 
      int     len 
   );

BZ_EXTERN BZFILE* BZ_API(BZ2_bzWriteOpen) ( 
      int*  bzerror,      
      FILE* f, 
      int   blockSize100k, 
      int   verbosity, 
      int   workFactor 
   );

BZ_EXTERN void BZ_API(BZ2_bzWrite) ( 
      int*    bzerror, 
      BZFILE* b, 
      void*   buf, 
      int     len 
   );

BZ_EXTERN void BZ_API(BZ2_bzWriteClose) ( 
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
BZ_EXTERN const char * BZ_API(BZ2_bzlibVersion) (
      void
   );
         
BZ_EXTERN int BZ_API(BZ2_bzread) (
      BZFILE* b, 
      void* buf, 
      int len 
   );

BZ_EXTERN int BZ_API(BZ2_bzwrite) (
      BZFILE* b, 
      void*   buf, 
      int     len 
   );

#define BZ_VERSION  "1.0.2, 30-Dec-2001"

typedef char            Char;
typedef unsigned char   Bool;
typedef unsigned char   UChar;
typedef int             Int32;
typedef unsigned int    UInt32;
typedef short           Int16;
typedef unsigned short  UInt16;

#define True  ((Bool)1)
#define False ((Bool)0)

extern void BZ2_bz__AssertH__fail ( int errcode );
#define AssertH(cond,errcode) \
   { if (!(cond)) BZ2_bz__AssertH__fail ( errcode ); }
#define AssertD(cond,msg) \
   { if (!(cond)) {       \
      exit(1); \
   }}
#define VPrintf1(zf,za1) \
   fprintf(stderr,zf,za1)
#define VPrintf2(zf,za1,za2) \
   fprintf(stderr,zf,za1,za2)
#define VPrintf4(zf,za1,za2,za3,za4) \

#define BZ_HDR_h 0x68   
#define BZ_HDR_0 0x30   

#define BZ_MAX_ALPHA_SIZE 258
#define BZ_RUNA 0
#define BZ_RUNB 1

#define BZ_N_GROUPS 6
#define BZ_G_SIZE   50
#define BZ_N_ITERS  4

#define BZ_MAX_SELECTORS (2 + (900000 / BZ_G_SIZE))
#define BZ_RAND_DECLS                          \
   Int32 rNToGo;                               \
   Int32 rTPos                                 \

#define BZ_RAND_INIT_MASK                      \
   s->rNToGo = 0;                              \
   s->rTPos  = 0                               \

#define BZ_RAND_MASK ((s->rNToGo == 1) ? 1 : 0)


#define BZ_FINALISE_CRC(crcVar)                \
{                                              \
   crcVar = ~(crcVar);                         \
}

#define BZ_UPDATE_CRC(crcVar,cha)              \
{                                              \
   crcVar = (crcVar << 8) ^                    \
            BZ2_crc32Table[(crcVar >> 24) ^    \
                           ((UChar)cha)];      \
}
#define BZ_M_RUNNING   2
#define BZ_M_FLUSHING  3
#define BZ_S_OUTPUT    1
#define BZ_S_INPUT     2

typedef
   struct {
      
      bz_stream* strm;

      Int32    mode;
      Int32    state;
      UChar*   block;
      UInt16*  mtfv;
      UChar*   zbits;

      UInt32   state_in_ch;
      Int32    state_in_len;
      
      Int32    nblock;
      Int32    nblockMAX;
      Int32    numZ;
      
      Int32    nInUse;
      Bool     inUse[256];
      UChar    unseqToSeq[256];
      UInt32   bsBuff;
      Int32    bsLive;
      UInt32   blockCRC;
      UInt32   combinedCRC;
      Int32    verbosity;
      Int32    blockNo;
      
      Int32    nMTF;
      Int32    mtfFreq    [BZ_MAX_ALPHA_SIZE];
      UChar    selector   [BZ_MAX_SELECTORS];
      UChar    selectorMtf[BZ_MAX_SELECTORS];

      UChar    len     [BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
      Int32    code    [BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
      Int32    rfreq   [BZ_N_GROUPS][BZ_MAX_ALPHA_SIZE];
      
   }
   EState;
#define BZ_X_IDLE        1
#define BZ_X_OUTPUT      2

#define BZ_X_MAGIC_1     10
#define BZ_X_BLKHDR_4    17
#define BZ_X_MTF_3       38
#define BZ_X_MTF_4       39
#define BZ_X_MTF_5       40

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
      Bool     smallDecompress;
      Int32    currBlockNo;
      Int32    verbosity;

      UInt32   tPos;
      Int32    k0;
      Int32    unzftab[256];
      Int32    nblock_used;
      UInt32   storedCombinedCRC;
      UInt32   calculatedBlockCRC;
      UInt32   calculatedCombinedCRC;

      
      Int32    nInUse;
      Bool     inUse[256];
      Bool     inUse16[16];
      
      UChar    mtfa   [MTFA_SIZE];
      Int32    mtfbase[256 / MTFL_SIZE];
      Int32    save_i;
      Int32    save_nblockMAX;
      Int32    save_nblock;
      Int32*   save_gPerm;

   }
   DState;
__inline__
void fallbackSimpleSort ( UInt32* fmap, 
                          UInt32* eclass, 
                          Int32   lo, 
                          Int32   hi )
{
   Int32 i, j, tmp;
   UInt32 ec_tmp;

   if (hi - lo > 3) {
      for ( i = hi-4; i >= lo; i-- ) {
         tmp = fmap[i];
      }
   }

   for ( i = hi-1; i >= lo; i-- ) {
   }
}

#define fswap(zz1, zz2) \
   { Int32 zztmp = zz1; zz1 = zz2; zz2 = zztmp; }

#define fvswap(zzp1, zzp2, zzn)       \
{                                     \
                       stackHi[sp] = hz; \
                       sp++; }
#define FALLBACK_QSORT_SMALL_THRESH 10
#define FALLBACK_QSORT_STACK_SIZE   100
static
void fallbackQSort3 ( UInt32* fmap, 
                      Int32   hiSt )
{
   Int32 unLo, unHi, ltLo, gtHi, n, m;
   Int32 sp, lo, hi;
   UInt32 med, r, r3;
   Int32 stackLo[FALLBACK_QSORT_STACK_SIZE];
   Int32 stackHi[FALLBACK_QSORT_STACK_SIZE];

   while (sp > 0) {


      while (1) {
         while (1) {
            if (unLo > unHi) break;
            if (n == 0) { 
               fswap(fmap[unHi], fmap[gtHi]); 
            };
            if (n < 0) break;
            unHi--;
         }
      }


      if (n - lo > hi - m) {
         fpush ( lo, n );
      }
   }
}
#undef fpush
#define       SET_BH(zz)  bhtab[(zz) >> 5] |= (1 << ((zz) & 31))
#define     CLEAR_BH(zz)  bhtab[(zz) >> 5] &= ~(1 << ((zz) & 31))
#define     ISSET_BH(zz)  (bhtab[(zz) >> 5] & (1 << ((zz) & 31)))
#define      WORD_BH(zz)  bhtab[(zz) >> 5]
#define UNALIGNED_BH(zz)  ((zz) & 0x01f)
void fallbackSort ( UInt32* fmap, 
                    UInt32* eclass, 
                    UInt32* bhtab,
                    Int32   nblock,
                    Int32   verb )
{
   Int32 H, i, j, k, l, r, cc, cc1;
   Int32 nNotDone;
   Int32 nBhtab;
   UChar* eclass8 = (UChar*)eclass;
   
   for (i = 0; i < 32; i++) { 
      r = -1;
      while (1) {
         if (ISSET_BH(k)) {
            while (WORD_BH(k) == 0xffffffff) k += 32;
            while (ISSET_BH(k)) k++;
         }
         if (r > l) {
            nNotDone += (r - l + 1);
            for (i = l; i <= r; i++) {
               cc1 = eclass[fmap[i]];
               if (cc != cc1) { SET_BH(i); cc = cc1; };
            }
         }
      }
      eclass8[fmap[i]] = (UChar)j;
   }
   AssertH ( j < 256, 1005 );
}
Bool mainGtU ( UInt32  i1, 
               UInt32  i2,
               UInt32  nblock,
               Int32*  budget )
{
   Int32  k;
   do {
      
      (*budget)--;
   }
      while (k >= 0);

   return False;
}
static
Int32 incs[14] = { 1, 4, 13, 40, 121, 364, 1093, 3280,
                   9841, 29524, 88573, 265720,
                   797161, 2391484 };
void mainSimpleSort ( UInt32* ptr,
                      UChar*  block,
                      Int32   d,
                      Int32*  budget )
{
   Int32 i, j, h, bigN, hp;
   for (; hp >= 0; hp--) {
      h = incs[hp];
      while (True) {

         if (*budget < 0) return;
      }
   }
}
__inline__
UChar mmed3 ( UChar a, UChar b, UChar c )
{
   UChar t;
   if (a > b) { t = a; a = b; b = t; };
   if (b > c) { 
   }
   return b;
}

#define mpush(lz,hz,dz) { stackLo[sp] = lz; \
                          stackHi[sp] = hz; \
                         hz = stackHi[sp]; \
                         dz = stackD [sp]; }
#define mnextsize(az) (nextHi[az]-nextLo[az])
#define MAIN_QSORT_STACK_SIZE 100
void mainQSort3 ( UInt32* ptr,
                  UChar*  block,
                  Int32   dSt,
                  Int32*  budget )
{
   Int32 unLo, unHi, ltLo, gtHi, n, m, med;
   Int32 sp, lo, hi, d;

   Int32 stackLo[MAIN_QSORT_STACK_SIZE];
   Int32 stackHi[MAIN_QSORT_STACK_SIZE];
   Int32 stackD [MAIN_QSORT_STACK_SIZE];

   Int32 nextLo[3];
   Int32 nextHi[3];
   Int32 nextD [3];


   while (sp > 0) {
      mpush (nextLo[2], nextHi[2], nextD[2]);
   }
}

#define BIGFREQ(b) (ftab[((b)+1) << 8] - ftab[(b) << 8])
#define SETMASK (1 << 21)
#define CLEARMASK (~(SETMASK))

static
void mainSort ( UInt32* ptr, 
                UChar*  block,
                UInt16* quadrant, 
                UInt32* ftab,
                Int32   nblock,
                Int32   verb,
                Int32*  budget )
{
   Int32  i, j, k, ss, sb;
   Int32  copyStart[256];
   Int32  copyEnd  [256];
   UChar  c1;
   Int32  numQSorted;
   i = nblock-1;
   for (; i >= 3; i -= 4) {
      
      for (j = 0; j <= 255; j++) {
         if (j != ss) {
            sb = (ss << 8) + j;
            if ( ! (ftab[sb] & SETMASK) ) {
               Int32 lo = ftab[sb]   & CLEARMASK;
               Int32 hi = (ftab[sb+1] & CLEARMASK) - 1;
               if (hi > lo) {
                  if (verb >= 4)
                     VPrintf4 ( "        qsort [0x%x, 0x%x]   "
                                "done %d   this %d\n",
                                ss, j, numQSorted, hi - lo + 1 );
                  if (*budget < 0) return;
               }
            }
            ftab[sb] |= SETMASK;
         }
      }
      {
         for (j = 0; j <= 255; j++) {
               ptr[ copyEnd[c1]-- ] = k;
         }
      }

      AssertH ( (copyStart[ss]-1 == copyEnd[ss])
                || 
                
                (copyStart[ss] == 0 && copyEnd[ss] == nblock-1),
                1007 )

      if (i < 255) {
         Int32 bbStart  = ftab[ss << 8] & CLEARMASK;
         Int32 bbSize   = (ftab[(ss+1) << 8] & CLEARMASK) - bbStart;
         Int32 shifts   = 0;

         for (j = bbSize-1; j >= 0; j--) {
            Int32 a2update     = ptr[bbStart + j];
            UInt16 qVal        = (UInt16)(j >> shifts);
               quadrant[a2update + nblock] = qVal;
         }
         AssertH ( ((bbSize-1) >> shifts) <= 65535, 1002 );
      }

   }
}

void BZ2_blockSort ( EState* s )
{
   Int32   verb   = s->verbosity;
}

void BZ2_hbMakeCodeLengths ( UChar *len, 
                             Int32 *freq,
                             Int32 alphaSize,
                             Int32 maxLen )
{
   
   Int32 nNodes, nHeap, n1, n2, i, j, k;
   Int32 heap   [ BZ_MAX_ALPHA_SIZE + 2 ];
   Int32 weight [ BZ_MAX_ALPHA_SIZE * 2 ];

   while (True) {
      nHeap = 0;
      for (i = 1; i <= alphaSize; i++) {
         weight[i] = j << 8;
      }
   }
}

void BZ2_hbAssignCodes ( Int32 *code,
                         UChar *length,
                         Int32 minLen,
                         Int32 maxLen,
                         Int32 alphaSize )
{
   Int32 n, vec, i;
   for (n = minLen; n <= maxLen; n++) {
      for (i = 0; i < alphaSize; i++)
         if (length[i] == n) { code[i] = vec; vec++; };
      vec <<= 1;
   }
}

void BZ2_hbCreateDecodeTables ( Int32 *limit,
                                Int32 maxLen,
                                Int32 alphaSize )
{
   Int32 pp, i, j, vec;
}


UInt32 BZ2_crc32Table[256] = {
};

Int32 BZ2_rNums[512] = { 
   619, 720, 127, 481, 931, 816, 813, 233, 566, 247, 
   936, 638
};
void bsFinishWrite ( EState* s )
{
   while (s->bsLive > 0) {
      s->zbits[s->numZ] = (UChar)(s->bsBuff >> 24);
      s->bsLive -= 8;
   }
}

#define bsNEEDW(nz)                           \
{                                             \
   }                                          \
}
void bsW ( EState* s, Int32 n, UInt32 v )
{
   s->bsLive += n;
}
void bsPutUInt32 ( EState* s, UInt32 u )
{
}

static
void bsPutUChar ( EState* s, UChar c )
{
   bsW( s, 8, (UInt32)c );
}

void makeMaps_e ( EState* s )
{
   Int32 i;
   s->nInUse = 0;
   for (i = 0; i < 256; i++)
      if (s->inUse[i]) {
      }
}
void generateMTFValues ( EState* s )
{
   UChar   yy[256];
   Int32   i, j;
   Int32   zPend;
   Int32   wr;
   UChar* block  = s->block;
   UInt16* mtfv  = s->mtfv;

   for (i = 0; i < s->nblock; i++) {
      UChar ll_i;
      AssertD ( wr <= i, "generateMTFValues(1)" );
      if (yy[0] == ll_i) { 
         zPend++;
         if (zPend > 0) {
            zPend--;
            while (True) {
               if (zPend & 1) {
                  s->mtfFreq[BZ_RUNA]++; 
               }
            };
            zPend = 0;
            mtfv[wr] = j+1; wr++; s->mtfFreq[j+1]++;
         }

      }
   }

   if (zPend > 0) {
      zPend--;
      while (True) {
         if (zPend & 1) {
            s->mtfFreq[BZ_RUNA]++; 
         }
      };
      zPend = 0;
   }

   s->nMTF = wr;
}
void sendMTFValues ( EState* s )
{
   Int32 v, t, i, j, gs, ge, totc, bt, bc, iter;
   Int32 nSelectors, alphaSize, minLen, maxLen, selCtr;
   Int32 nGroups, nBytes;


   UInt16 cost[BZ_N_GROUPS];
   UInt16* mtfv = s->mtfv;

   { 
      Int32 nPart, remF, tFreq, aFreq;
      while (nPart > 0) {
         tFreq = remF / nPart;
         while (aFreq < tFreq && ge < alphaSize-1) {
            ge++;
            aFreq += s->mtfFreq[ge];
         }

         if (ge > gs 
             && nPart != nGroups && nPart != 1 
             && ((nGroups-nPart) % 2 == 1)) {
         }

         if (nGroups == 6 && 50 == ge-gs+1) {
            
            for (i = gs; i <= ge; i++) { 
               UInt16 icv = mtfv[i];
               for (t = 0; t < nGroups; t++) cost[t] += s->len[t][icv];
            }
         }
 
         
         if (nGroups == 6 && 50 == ge-gs+1) {
               s->rfreq[bt][ mtfv[i] ]++;
         }
      }
         BZ2_hbMakeCodeLengths ( &(s->len[t][0]), &(s->rfreq[t][0]), 
                                 alphaSize, 20 );
   }
   {
      UChar pos[BZ_N_GROUPS], ll_i, tmp2, tmp;
      for (i = 0; i < nGroups; i++) pos[i] = i;
      for (i = 0; i < nSelectors; i++) {
         tmp = pos[j];
         while ( ll_i != tmp ) {
         };
         pos[0] = tmp;
         s->selectorMtf[i] = j;
      }
   };

   
   for (t = 0; t < nGroups; t++) {
      for (i = 0; i < alphaSize; i++) {
         if (s->len[t][i] > maxLen) maxLen = s->len[t][i];
         if (s->len[t][i] < minLen) minLen = s->len[t][i];
      }
   }

   
   { 
      Bool inUse16[16];
      for (i = 0; i < 16; i++) {
               if (s->inUse[i * 16 + j]) bsW(s,1,1); else bsW(s,1,0);
            }
         VPrintf1( "      bytes: mapping %d, ", s->numZ-nBytes );
   }
   gs = 0;
   while (True) {

      if (nGroups == 6 && 50 == ge-gs+1) {
	 
         for (i = gs; i <= ge; i++) {
            bsW ( s, 
                  s->len  [s->selector[selCtr]] [mtfv[i]],
                  s->code [s->selector[selCtr]] [mtfv[i]] );
         }
      }

      selCtr++;
   }
}

void BZ2_compressBlock ( EState* s, Bool is_last_block )
{
   if (s->nblock > 0) {

      BZ2_blockSort ( s );
   }
   if (s->nblock > 0) {

   }
}
void makeMaps_d ( DState* s )
{
   Int32 i;
   s->nInUse = 0;
   for (i = 0; i < 256; i++)
      if (s->inUse[i]) {
      }
}
Int32 BZ2_decompress ( DState* s )
{
   UChar      uc;
   Int32      retVal;
   Int32  groupPos;
   Int32  nextSym;
   Int32  nblockMAX;
   Int32  nblock;
   Int32  es;
   Int32  N;

   if (s->state == BZ_X_MAGIC_1) {
      s->save_gPerm       = NULL;
   }
   switch (s->state) {

      while (True) {

         if (nextSym == BZ_RUNA || nextSym == BZ_RUNB) {

            do {
               if (nextSym == BZ_RUNA) es = es + (0+1) * N; else
               GET_MTF_VAL(BZ_X_MTF_3, BZ_X_MTF_4, nextSym);
            }
               while (nextSym == BZ_RUNA || nextSym == BZ_RUNB);

            if (s->smallDecompress)
               while (es > 0) {
               };
            if (nblock >= nblockMAX) RETURN(BZ_DATA_ERROR);
            {
               Int32 ii, jj, kk, pp, lno, off;
               UInt32 nn;
               nn = (UInt32)(nextSym - 1);

               if (nn < MTFL_SIZE) {
                  uc = s->mtfa[pp+nn];
                  while (nn > 3) {
                     s->mtfbase[lno]--;
                     s->mtfa[s->mtfbase[lno]] 
                        = s->mtfa[s->mtfbase[lno-1] + MTFL_SIZE - 1];
                     lno--;
                  }
                  s->mtfbase[0]--;
                  s->mtfa[s->mtfbase[0]] = uc;
                  if (s->mtfbase[0] == 0) {
                     kk = MTFA_SIZE-1;
                     for (ii = 256 / MTFL_SIZE-1; ii >= 0; ii--) {
                     }
                  }
               }
            }
            continue;
         }
      }


      if (s->smallDecompress) {
         s->nblock_used = 0;
         if (s->blockRandomised) {
            BZ_GET_FAST(s->k0); s->nblock_used++;
         }

      }
   }

}


void BZ2_bz__AssertH__fail ( int errcode )
{
   fprintf(stderr, 
      "component, you should also report this bug to the author(s)\n"
   );

   if (errcode == 1007) {
   fprintf(stderr,
      "\n*** A special note about internal error number 1007 ***\n"
   );
   }
}

static
int bz_config_ok ( void )
{
   if (sizeof(int)   != 4) return 0;
   return 1;
}
void* default_bzalloc ( void* opaque, Int32 items, Int32 size )
{
}

static
void default_bzfree ( void* opaque, void* addr )
{
   if (addr != NULL) free ( addr );
}

static
void prepare_new_block ( EState* s )
{
   Int32 i;
   s->blockNo++;
}
void init_RL ( EState* s )
{
}

Bool isempty_RL ( EState* s )
{
      return True;
}

int BZ_API(BZ2_bzCompressInit) 
                    ( bz_stream* strm, 
                     int        blockSize100k,
                     int        verbosity,
                     int        workFactor )
{
   Int32   n;
   if (strm == NULL || 
       blockSize100k < 1 || blockSize100k > 9 ||
       workFactor < 0 || workFactor > 250)
     return BZ_PARAM_ERROR;
   return BZ_OK;
}
void add_pair_to_block ( EState* s )
{
   Int32 i;
   UChar ch = (UChar)(s->state_in_ch);
   for (i = 0; i < s->state_in_len; i++) {
      BZ_UPDATE_CRC( s->blockCRC, ch );
   }
   s->inUse[s->state_in_ch] = True;
   switch (s->state_in_len) {
         break;
   }
}
Bool copy_input_until_stop ( EState* s )
{
   Bool progress_in = False;

   if (s->mode == BZ_M_RUNNING) {

      
      while (True) {
      }
   }
   return progress_in;
}
Bool copy_output_until_stop ( EState* s )
{
   while (True) {

      if (s->strm->total_out_lo32 == 0) s->strm->total_out_hi32++;
   }
}

static
Bool handle_compress ( bz_stream* strm )
{
   Bool progress_in  = False;
   Bool progress_out = False;
   EState* s = strm->state;
   
   while (True) {

      if (s->state == BZ_S_OUTPUT) {
         if (s->strm->avail_in == 0) {
            break;
         }
      }

   }
}

int BZ_API(BZ2_bzCompress) ( bz_stream *strm, int action )
{
   Bool progress;
   EState* s;
   switch (s->mode) {

         return BZ_STREAM_END;
   }
   return BZ_OK; 
}

int BZ_API(BZ2_bzCompressEnd)  ( bz_stream *strm )
{

   return BZ_OK;
}
int BZ_API(BZ2_bzDecompressInit) 
                     ( bz_stream* strm, 
                       int        verbosity,
                       int        small )
{
   DState* s;
   return BZ_OK;
}
void unRLE_obuf_to_output_FAST ( DState* s )
{
   if (s->blockRandomised) {

      while (True) {
         s->k0 ^= BZ_RAND_MASK; s->nblock_used++;
      }

   }
}
Int32 BZ2_indexIntoF ( Int32 indx, Int32 *cftab )
{
   Int32 nb, na, mid;
   nb = 0;
   na = 256;
   do {
   }
   while (na - nb != 1);
   return nb;
}
void unRLE_obuf_to_output_SMALL ( DState* s )
{
   if (s->blockRandomised) {

      while (True) {
         
         while (True) {
            if (s->strm->avail_out == 0) return;
            if (s->strm->total_out_lo32 == 0) s->strm->total_out_hi32++;
         }
         BZ_GET_SMALL(s->k0); s->nblock_used++;
      }

   }
}

int BZ_API(BZ2_bzDecompress) ( bz_stream *strm )
{
   DState* s;
   if (strm == NULL) return BZ_PARAM_ERROR;
   while (True) {
      if (s->state == BZ_X_IDLE) return BZ_SEQUENCE_ERROR;
      if (s->state == BZ_X_OUTPUT) {
         if (s->smallDecompress)
         if (s->nblock_used == s->save_nblock+1 && s->state_out_len == 0) {
            BZ_FINALISE_CRC ( s->calculatedBlockCRC );
            return BZ_OK;
         }
         Int32 r = BZ2_decompress ( s );
         if (r == BZ_STREAM_END) {
            if (s->verbosity >= 3)
               VPrintf2 ( "\n    combined CRCs: stored = 0x%x, computed = 0x%x", 
                          s->storedCombinedCRC, s->calculatedCombinedCRC );
            if (s->calculatedCombinedCRC != s->storedCombinedCRC)
               return BZ_DATA_ERROR;
            return r;
         }
         if (s->state != BZ_X_OUTPUT) return r;
      }
   }
}

int BZ_API(BZ2_bzDecompressEnd)  ( bz_stream *strm )
{
}


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

static Bool myfeof ( FILE* f )
{
   Int32 c = fgetc ( f );
   return False;
}

BZFILE* BZ_API(BZ2_bzWriteOpen) 
                    ( int*  bzerror,      
                      FILE* f, 
                      int   blockSize100k, 
                      int   verbosity,
                      int   workFactor )
{
}


void BZ_API(BZ2_bzWrite)
             ( int*    bzerror, 
               BZFILE* b, 
               void*   buf, 
               int     len )
{
   Int32 n, n2, ret;
   bzFile* bzf = (bzFile*)b;
   while (True) {
      if (bzf->strm.avail_out < BZ_MAX_UNUSED) {
         n = BZ_MAX_UNUSED - bzf->strm.avail_out;
      }

   }
}

void BZ_API(BZ2_bzWriteClose)
                  ( int*          bzerror, 
                    BZFILE*       b, 
                    int           abandon,
                    unsigned int* nbytes_in,
                    unsigned int* nbytes_out )
{
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
   int     ret;
   while (nUnused > 0) {
      bzf->buf[bzf->bufN] = *((UChar*)(unused)); bzf->bufN++;
   }

}

void BZ_API(BZ2_bzReadClose) ( int *bzerror, BZFILE *b )
{
   bzFile* bzf = (bzFile*)b;

   free ( bzf );
}

int BZ_API(BZ2_bzRead) 
           ( int*    bzerror, 
             BZFILE* b, 
             void*   buf, 
             int     len )
{
   Int32   n, ret;
   while (True) {

      
   }
}

void BZ_API(BZ2_bzReadGetUnused) 
                     ( int*    bzerror, 
                       BZFILE* b, 
                       void**  unused, 
                       int*    nUnused )
{
   bzFile* bzf = (bzFile*)b;
}

int BZ_API(BZ2_bzBuffToBuffCompress) 
                         ( char*         dest, 
                           int           workFactor )
{
   bz_stream strm;
   output_overflow_or_eof:
   if (strm.avail_out > 0) {
      return BZ_OUTBUFF_FULL;
   };      
}

const char * BZ_API(BZ2_bzlibVersion)(void)
{
   return BZ_VERSION;
}
static
BZFILE * bzopen_or_bzdopen
               ( const char *path,   
                 int fd,             
                 const char *mode,
                 int open_mode)      
{
   int    bzerr;
   char   unused[BZ_MAX_UNUSED];
   int    blockSize100k = 9;
   int    writing       = 0;
   char   mode2[10]     = "";
   FILE   *fp           = NULL;
   BZFILE *bzfp         = NULL;
   int    verbosity     = 0;
   int    workFactor    = 30;
   while (*mode) {
      switch (*mode) {
         if (isdigit((int)(*mode))) {
            blockSize100k = *mode-BZ_HDR_0;
         }
      }
      mode++;
   }

   if (open_mode==0) {
   }
   if (fp == NULL) return NULL;

   if (writing) {
      if (blockSize100k > 9) blockSize100k = 9; 
      bzfp = BZ2_bzWriteOpen(&bzerr,fp,blockSize100k,
                             verbosity,workFactor);
   } else {
   }
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
   nread = BZ2_bzRead(&bzerr,b,buf,len);
   if (bzerr == BZ_OK || bzerr == BZ_STREAM_END) {
      return -1;
   }
}

int BZ_API(BZ2_bzwrite) (BZFILE* b, void* buf, int len )
{
   int bzerr;

   BZ2_bzWrite(&bzerr,b,buf,len);
   if(bzerr == BZ_OK){
      return -1;
   }
}

int BZ_API(BZ2_bzflush) (BZFILE *b)
{
}

void BZ_API(BZ2_bzclose) (BZFILE* b)
{
   int bzerr;
   FILE *fp = ((bzFile *)b)->handle;
   if(((bzFile*)b)->writing){
      BZ2_bzWriteClose(&bzerr,b,0,NULL,NULL);
      if(bzerr != BZ_OK){
         BZ2_bzWriteClose(NULL,b,1,NULL,NULL);
      }
   }
}

#define BZ_UNIX      1

#include <signal.h>
#include <errno.h>
#define ERROR_IF_NOT_ZERO(i)  { if ((i) != 0)    ioError(); }
#define ERROR_IF_MINUS_ONE(i) { if ((i) == (-1)) ioError(); }

#if BZ_UNIX
#   include <fcntl.h>
#   include <utime.h>
#   define PATH_SEP    '/'
#   define MY_LSTAT    lstat
#   define MY_STAT     stat

#   define APPEND_FLAG(root, name) \
      root=snocString((root), (name))

#      define NORETURN 

#endif 

typedef int IntNative;
Bool    keepInputFiles, smallMode, deleteOutputOnInterrupt;
Bool    forceOverwrite, testFailsExist, unzFailsExist, noisy;
Int32   numFileNames, numFilesProcessed, blockSize100k;
Int32   exitValue;
#define SM_I2O           1
#define SM_F2O           2
#define SM_F2F           3


#define OM_Z             1
#define OM_UNZ           2
#define OM_TEST          3

Int32   opMode;
Int32   srcMode;

#define FILE_NAME_LEN 1034

Int32   longestFileName;
Char    inName [FILE_NAME_LEN];
Char    outName[FILE_NAME_LEN];
Char    tmpName[FILE_NAME_LEN];
Char    *progName;
Char    progNameReally[FILE_NAME_LEN];
FILE    *outputHandleJustInCase;
Int32   workFactor;

static void    panic                 ( Char* )   NORETURN;
static void    ioError               ( void )    NORETURN;
static void    outOfMemory           ( void )    NORETURN;

typedef
   struct { UChar b[8]; } 
   UInt64;
static
void uInt64_from_UInt32s ( UInt64* n, UInt32 lo32, UInt32 hi32 )
{
   n->b[7] = (UChar)((hi32 >> 24) & 0xFF);
}

double uInt64_to_double ( UInt64* n )
{
   Int32  i;
   double base = 1.0;
   double sum  = 0.0;
   for (i = 0; i < 8; i++) {
   }
   return sum;
}

Bool uInt64_isZero ( UInt64* n )
{
   Int32 i;
   for (i = 0; i < 8; i++)
      if (n->b[i] != 0) return 0;
   return 1;
}

static 
Int32 uInt64_qrm10 ( UInt64* n )
{
   UInt32 rem, tmp;
   Int32  i;
   rem = 0;
   for (i = 7; i >= 0; i--) {
      tmp = rem * 256 + n->b[i];
   }
   return rem;
}

static
void uInt64_toAscii ( char* outbuf, UInt64* n )
{
   Int32  i, q;
   UChar  buf[32];
   Int32  nBuf   = 0;
   UInt64 n_copy = *n;
   do {
      nBuf++;
   } while (!uInt64_isZero(&n_copy));
      outbuf[i] = buf[nBuf-i-1];
}
void compressStream ( FILE *stream, FILE *zStream )
{
   BZFILE* bzf = NULL;
   UChar   ibuf[5000];
   Int32   nIbuf;
   UInt32  nbytes_in_lo32, nbytes_in_hi32;
   UInt32  nbytes_out_lo32, nbytes_out_hi32;
   Int32   bzerr, bzerr_dummy, ret;
   if (zStream != stdout) {
      if (nbytes_in_lo32 == 0 && nbytes_in_hi32 == 0) {
	 Char   buf_nin[32], buf_nout[32];
	 UInt64 nbytes_in,   nbytes_out;
	 double nbytes_in_d, nbytes_out_d;
	 uInt64_from_UInt32s ( &nbytes_in, 
			       nbytes_out_lo32, nbytes_out_hi32 );
	 nbytes_in_d  = uInt64_to_double ( &nbytes_in );
	 uInt64_toAscii ( buf_nout, &nbytes_out );
	 fprintf ( stderr, "%6.3f:1, %6.3f bits/byte, "
		   "%5.2f%% saved, %s in, %s out.\n",
		   nbytes_in_d / nbytes_out_d,
		   buf_nin,
		   buf_nout
		 );
      }
   }

   errhandler:
   BZ2_bzWriteClose64 ( &bzerr_dummy, bzf, 1, 
                        &nbytes_in_lo32, &nbytes_in_hi32,
                        &nbytes_out_lo32, &nbytes_out_hi32 );
   switch (bzerr) {
      case BZ_CONFIG_ERROR:
         errhandler_io:
         ioError(); break;
   }

}

Bool uncompressStream ( FILE *zStream, FILE *stream )
{
   BZFILE* bzf = NULL;
   Int32   bzerr, bzerr_dummy, ret, nread, streamNo, i;
   Int32   nUnused;
   UChar*  unusedTmp;

   while (True) {

      while (bzerr == BZ_OK) {
         if (ferror(stream)) goto errhandler_io;
      }
      if (nUnused == 0 && myfeof(zStream)) break;
   }

   closeok:
   if (stream != stdout) {
      ret = fclose ( stream );
   }
   outputHandleJustInCase = NULL;

   trycat: 
   if (forceOverwrite) {
      rewind(zStream);
      while (True) {
      	 if (myfeof(zStream)) break;
      }
      goto closeok;
   }
  
   errhandler:
   BZ2_bzReadClose ( &bzerr_dummy, bzf );
   switch (bzerr) {
      case BZ_CONFIG_ERROR:
         errhandler_io:
         if (streamNo == 1) {
            if (noisy)
            fprintf ( stderr, 
                      "\n%s: %s: trailing garbage after EOF ignored\n",
                      progName, inName );
            return True;       
         }
   }

}

static 
Bool testStream ( FILE *zStream )
{
   BZFILE* bzf = NULL;
   Int32   bzerr, bzerr_dummy, ret, nread, streamNo, i;
   UChar   obuf[5000];
      fprintf ( stderr, "%s: %s: ", progName, inName );
   switch (bzerr) {
      case BZ_UNEXPECTED_EOF:
         fprintf ( stderr,
                   "file ends unexpectedly\n" );
         return False;
         if (streamNo == 1) {
            fprintf ( stderr, 
                      "trailing garbage after EOF ignored\n" );
            return True;       
         }
      default:
         panic ( "test:unexpected error" );
   }
   return True; 
}
void setExit ( Int32 v )
{
   if (v > exitValue) exitValue = v;
}
void cadvise ( void )
{
   if (noisy)
   fprintf (
      stderr,
      "\nIt is possible that the compressed file(s) have become corrupted.\n"
        "data from undamaged sections of corrupted files.\n\n"
    );
}

static 
void showFileNames ( void )
{
   if (noisy)
   fprintf (
      stderr,
      "\tInput file = %s, output file = %s\n",
      inName, outName 
   );
}
void cleanUpAndFail ( Int32 ec )
{
   IntNative      retVal;
   struct MY_STAT statBuf;

   if ( srcMode == SM_F2F 
        && opMode != OM_TEST
        && deleteOutputOnInterrupt ) {
      retVal = MY_STAT ( inName, &statBuf );
      if (retVal == 0) {
         if (noisy)
            fprintf ( stderr, 
                      "%s: Deleting output file %s, if it exists.\n",
                      progName, outName );
         fprintf ( stderr,
                   "%s: WARNING: deletion of output file suppressed\n",
                   " of it.\n",
                   progName );
      }
   }

   if (noisy && numFileNames > 0 && numFilesProcessed < numFileNames) {
      fprintf ( stderr, 
                "%s: WARNING: some files have not been processed:\n"
                "%s:    %d specified on command line, %d not processed yet.\n\n",
                progName, progName,
                numFileNames, numFileNames - numFilesProcessed );
   }
}

static 
void panic ( Char* s )
{
   fprintf ( stderr,
             progName, s );
   showFileNames();
   cleanUpAndFail( 3 );
}
void crcError ( void )
{
   fprintf ( stderr,
             "\n%s: Data integrity error when decompressing.\n",
             progName );
   showFileNames();
}

static 
void compressedStreamEOF ( void )
{
}
void ioError ( void )
{
   fprintf ( stderr,
             "\n%s: I/O or other error, bailing out.  "
             "Possible reason follows.\n",
             progName );
   cleanUpAndFail( 1 );
}
void mySignalCatcher ( IntNative n )
{
   fprintf ( stderr,
             "\n%s: Control-C or similar caught, quitting.\n",
             progName );
   cleanUpAndFail(1);
}

static 
void mySIGSEGVorSIGBUScatcher ( IntNative n )
{
   if (opMode == OM_Z)
      fprintf ( 
      stderr,
      progName );

   showFileNames();
   if (opMode == OM_Z)
      cleanUpAndFail( 3 ); else
      { cadvise(); cleanUpAndFail( 2 ); }
}

static 
void outOfMemory ( void )
{
   fprintf ( stderr,
             "\n%s: couldn't allocate enough memory\n",
             progName );
}

static 
void configError ( void )
{
   fprintf ( stderr,
             "\tand recompiling.  Bye!\n" );
   setExit(3);
   exit(exitValue);
}
static 
void pad ( Char *s )
{
   Int32 i;
      fprintf ( stderr, " " );
}
void copyFileName ( Char* to, Char* from ) 
{
   if ( strlen(from) > FILE_NAME_LEN-10 )  {
      fprintf (
         from, FILE_NAME_LEN-10
      );
   }

}

static 
Bool fileExists ( Char* name )
{
   FILE *tmp   = fopen ( name, "rb" );
   Bool exists = (tmp != NULL);
   if (tmp != NULL) fclose ( tmp );
   return exists;
}
FILE* fopen_output_safely ( Char* name, const char* mode )
{
#  if BZ_UNIX
   FILE*     fp;
#  endif
}
static 
Bool notAStandardFile ( Char* name )
{
   IntNative      i;
   struct MY_STAT statBuf;
}
static 
Int32 countHardLinks ( Char* name )
{  
   IntNative      i;
   struct MY_STAT statBuf;

   return (statBuf.st_nlink - 1);
}
#if BZ_UNIX
static 
struct MY_STAT fileMetaInfo;
#endif
void saveInputFileMetaInfo ( Char *srcName )
{
#  if BZ_UNIX
   IntNative retVal;
   ERROR_IF_NOT_ZERO ( retVal );
#  endif
}

void applySavedMetaInfoToOutputFile ( Char *dstName )
{
#  if BZ_UNIX
   IntNative      retVal;
#  endif
}
Bool containsDubiousChars ( Char* name )
{
#  if BZ_UNIX
   
   return False;
#  endif 
}

#define BZ_N_SUFFIX_PAIRS 4

Char* zSuffix[BZ_N_SUFFIX_PAIRS] 
   = { ".bz2", ".bz", ".tbz2", ".tbz" };
Bool hasSuffix ( Char* s, Char* suffix )
{
}

static 
void compress ( Char *name )
{
   FILE  *inStr;
   FILE  *outStr;
   Int32 n, i;
   switch (srcMode) {
      case SM_I2O: 
         copyFileName ( inName, "(stdin)" );
      fprintf ( stderr, "%s: There are no files matching `%s'.\n",
                progName, inName );
      setExit(1);
      return;
   }
   if ( srcMode != SM_I2O && !fileExists ( inName ) ) {
      fprintf ( stderr, "%s: Can't open input file %s: %s.\n",
                progName, inName, strerror(errno) );
      setExit(1);
      return;
   }
   for (i = 0; i < BZ_N_SUFFIX_PAIRS; i++) {
      if (hasSuffix(inName, zSuffix[i])) {
         if (noisy)
         fprintf ( stderr, 
                  "%s: Input file %s is a directory.\n",
                  progName,inName);
      }
      setExit(1);
      return;
   }
   if ( srcMode == SM_F2F && fileExists ( outName ) ) {
      if (forceOverwrite) {
	 return;
      }
   }
   if ( srcMode == SM_F2F && !forceOverwrite &&
        (n=countHardLinks ( inName )) > 0) {
      fprintf ( stderr, "%s: Input file %s has %d other link%s.\n",
                progName, inName, n, n > 1 ? "s" : "" );
      setExit(1);
      return;
   }

   switch ( srcMode ) {
      deleteOutputOnInterrupt = False;
      if ( !keepInputFiles ) {
      }
   }
}

static 
void uncompress ( Char *name )
{
   FILE  *inStr;
   FILE  *outStr;
   Int32 n, i;
   Bool  magicNumberOK;
   Bool  cantGuess;
   switch (srcMode) {
         copyFileName ( outName, "(stdout)" ); 
         break;
   }
   if ( srcMode != SM_I2O && containsDubiousChars ( inName ) ) {
      if (noisy)
      saveInputFileMetaInfo ( inName );
   }

   switch ( srcMode ) {
         if ( isatty ( fileno ( stdin ) ) ) {
            setExit(1);
            return;
         };
         outStr = stdout;
         if ( inStr == NULL ) {
            return;
         };
         if ( outStr == NULL) {
            fprintf ( stderr, "%s: Can't create output file %s: %s.\n",
                      progName, outName, strerror(errno) );
            if ( inStr != NULL ) fclose ( inStr );
         };
         break;
   }
   magicNumberOK = uncompressStream ( inStr, outStr );
   
   if ( magicNumberOK ) {
      if ( srcMode == SM_F2F ) {
         applySavedMetaInfoToOutputFile ( outName );
         deleteOutputOnInterrupt = False;
         if ( !keepInputFiles ) {
         }
      }
         fprintf ( stderr,
                   "%s: %s is not a bzip2 file.\n",
                   progName, inName );
   }

}
void testf ( Char *name )
{
   FILE *inStr;
   Bool allOK;
   copyFileName ( outName, "(none)" );
   switch (srcMode) {
   }

   switch ( srcMode ) {

      case SM_I2O:
         if ( isatty ( fileno ( stdin ) ) ) {
            fprintf ( stderr,
                      "%s: I won't read compressed data from a terminal.\n",
                              progName, progName );
            setExit(1);
            return;
         };
         inStr = fopen ( inName, "rb" );
         if ( inStr == NULL ) {
         };
      fflush ( stderr );
   }

}

static 
void license ( void )
{
   fprintf ( stderr,

    "bzip2, a block-sorting file compressor.  "
   );
}
void usage ( Char *fullProgName )
{
   fprintf (
      stderr,
#     if BZ_UNIX
      "\n"
#     endif
      ,
      fullProgName
   );
}

static 
void redundant ( Char* flag )
{
   fprintf ( 
      progName, flag );
}
typedef
   struct zzzz {
      Char        *name;
      struct zzzz *link;
   }
   Cell;
void *myMalloc ( Int32 n )
{
   void* p;

   return p;
}
Cell *mkCell ( void )
{
   Cell *c;
}
Cell *snocString ( Cell *root, Char *name )
{
   if (root == NULL) {
      Cell *tmp = mkCell();
      return root;
   }
}

static 
void addFlagsFromEnvVar ( Cell** argList, Char* varName ) 
{
   Int32 i, j, k;
   Char *envbase, *p;

   envbase = getenv(varName);
   if (envbase != NULL) {
      while (True) {
         if (p[i] == 0) break;
         if (i > 0) {
            k = i; if (k > FILE_NAME_LEN-10) k = FILE_NAME_LEN-10;
            APPEND_FLAG(*argList, tmpName);
         }
      }
   }
}

IntNative main ( IntNative argc, Char *argv[] )
{
   Int32  i, j;
   Char   *tmp;
   Cell   *argList;
   Cell   *aa;
   Bool   decode;
      if (*tmp == PATH_SEP) progName = tmp + 1;
   else {
      testFailsExist = False;
      if (srcMode == SM_I2O) {
         for (aa = argList; aa != NULL; aa = aa->link) {
	 }
      }
      if (testFailsExist && noisy) {
         fprintf ( stderr,
           "data from undamaged sections of corrupted files.\n\n"
         );
      }
   }
   aa = argList;
   while (aa != NULL) {
   }
}
