/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_struct_OC_k2c_tensor l_struct_OC_k2c_tensor;
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;

/* Structure contents */
struct l_struct_OC_k2c_tensor {
  float field0[300000];
  unsigned long long field1;
  unsigned long long field2;
  signed long long field3[5];
};

struct l_struct_OC__iobuf {
   char *field0;
  unsigned int field1;
   char *field2;
  unsigned int field3;
  unsigned int field4;
  unsigned int field5;
  unsigned int field6;
   char *field7;
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void k2c_affine_matmul(float *llvm_cbe_C, float *llvm_cbe_A, float *llvm_cbe_B, float *llvm_cbe_d, signed long long llvm_cbe_outrows, signed long long llvm_cbe_outcols, signed long long llvm_cbe_innerdim);
signed long long k2c_sub2idx(signed long long *llvm_cbe_sub, signed long long *llvm_cbe_shape, signed long long llvm_cbe_ndim);
void k2c_idx2sub(signed long long llvm_cbe_idx, signed long long *llvm_cbe_sub, signed long long *llvm_cbe_shape, signed long long llvm_cbe_ndim);
void k2c_dot(l_struct_OC_k2c_tensor *llvm_cbe_C, l_struct_OC_k2c_tensor *llvm_cbe_Ar, l_struct_OC_k2c_tensor *llvm_cbe_B, signed long long *llvm_cbe_axesA, signed long long *llvm_cbe_axesB, signed long long llvm_cbe_naxes, signed int llvm_cbe_normalize, float *llvm_cbe_fwork);
void k2c_bias_add(l_struct_OC_k2c_tensor *llvm_cbe_A, l_struct_OC_k2c_tensor *llvm_cbe_b);
void k2c_flip(l_struct_OC_k2c_tensor *llvm_cbe_A, signed long long llvm_cbe_axis);
float *k2c_read_array( char *llvm_cbe_filename, signed long long llvm_cbe_array_size);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[28] = "cannot allocate memory %s \n";
static  char aesl_internal__OC_str1[2] = "r";
static  char aesl_internal__OC_str2[25] = "Unable to open file %s \n";
static  char aesl_internal__OC_str3[4] = "%f,";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void k2c_affine_matmul(float *llvm_cbe_C, float *llvm_cbe_A, float *llvm_cbe_B, float *llvm_cbe_d, signed long long llvm_cbe_outrows, signed long long llvm_cbe_outcols, signed long long llvm_cbe_innerdim) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond20_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_2e_us12_count = 0;
  unsigned long long llvm_cbe_storemerge14_2e_us12;
  unsigned long long llvm_cbe_storemerge14_2e_us12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  float *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  float *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  float llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  float llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond19_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge8_2e_us;
  unsigned long long llvm_cbe_storemerge8_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  float *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  float llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  float llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond18_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_2e_us_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge14_2e_us_2e_us;
  unsigned long long llvm_cbe_storemerge14_2e_us_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  float *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  float llvm_cbe_tmp__16;
  float llvm_cbe_tmp__16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge23_2e_us_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge23_2e_us_2e_us;
  unsigned long long llvm_cbe_storemerge23_2e_us_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  float *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  float llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned long long llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  float *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  float llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  float llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  float llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_affine_matmul\n");
  if (((llvm_cbe_outrows&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__27;
  } else {
    goto llvm_cbe__2e_lr_2e_ph10;
  }

llvm_cbe__2e_lr_2e_ph10:
  if (((llvm_cbe_outcols&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge11;
  } else {
    llvm_cbe_storemerge8_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph6_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph6.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph6_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8.us = phi i64 [ %%4, %%._crit_edge7.us-lcssa.us17 ], [ 0, %%.lr.ph10  for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_storemerge8_2e_us_count);
  llvm_cbe_storemerge8_2e_us = (unsigned long long )llvm_cbe_storemerge8_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8.us = 0x%I64X",llvm_cbe_storemerge8_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__1);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = mul i64 %%storemerge8.us, %%outcols, !dbg !12 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__8 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge8_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_outcols&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__8&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = mul i64 %%storemerge8.us, %%innerdim, !dbg !13 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__9 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge8_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_innerdim&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull)));
  if (((llvm_cbe_innerdim&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge14_2e_us12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe_tmp__28;
  } else {
    llvm_cbe_storemerge14_2e_us_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us_2e_us;
  }

llvm_cbe__2e__crit_edge7_2e_us_2d_lcssa_2e_us17:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i64 %%storemerge8.us, 1, !dbg !13 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__1 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge8_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__1&18446744073709551615ull)));
  if (((llvm_cbe_tmp__1&18446744073709551615ULL) == (llvm_cbe_outrows&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge11;
  } else {
    llvm_cbe_storemerge8_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__1;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph6_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__28:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14.us12 = phi i64 [ %%11, %%5 ], [ 0, %%.lr.ph6.us  for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_storemerge14_2e_us12_count);
  llvm_cbe_storemerge14_2e_us12 = (unsigned long long )llvm_cbe_storemerge14_2e_us12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14.us12 = 0x%I64X",llvm_cbe_storemerge14_2e_us12);
printf("\n = 0x%I64X",llvm_cbe_tmp__7);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i64 %%storemerge14.us12, %%12, !dbg !10 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__2 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14_2e_us12&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__8&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds float* %%C, i64 %%6, !dbg !10 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__3 = (float *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__2))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%7, align 4, !dbg !10 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_39_count);
  *llvm_cbe_tmp__3 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds float* %%d, i64 %%storemerge14.us12, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__4 = (float *)(&llvm_cbe_d[(((signed long long )llvm_cbe_storemerge14_2e_us12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14.us12 = 0x%I64X",((signed long long )llvm_cbe_storemerge14_2e_us12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load float* %%8, align 4, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__5 = (float )*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__5, *(int*)(&llvm_cbe_tmp__5));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = fadd float %%9, 0.000000e+00, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__6 = (float )((float )(llvm_cbe_tmp__5 + 0x0p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__6, *(int*)(&llvm_cbe_tmp__6));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%10, float* %%7, align 4, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_48_count);
  *llvm_cbe_tmp__3 = llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i64 %%storemerge14.us12, 1, !dbg !13 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__7 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14_2e_us12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__7&18446744073709551615ull)));
  if (((llvm_cbe_tmp__7&18446744073709551615ULL) == (llvm_cbe_outcols&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge7_2e_us_2d_lcssa_2e_us17;
  } else {
    llvm_cbe_storemerge14_2e_us12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__7;   /* for PHI node */
    goto llvm_cbe_tmp__28;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.lr.ph.us.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14.us.us = phi i64 [ %%18, %%14 ], [ 0, %%.lr.ph6.us  for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_storemerge14_2e_us_2e_us_count);
  llvm_cbe_storemerge14_2e_us_2e_us = (unsigned long long )llvm_cbe_storemerge14_2e_us_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14.us.us = 0x%I64X",llvm_cbe_storemerge14_2e_us_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__13);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%storemerge14.us.us, %%12, !dbg !10 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__14 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14_2e_us_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__8&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__14&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds float* %%C, i64 %%19, !dbg !10 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__15 = (float *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__14))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__14));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%20, align 4, !dbg !10 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_92_count);
  *llvm_cbe_tmp__15 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  llvm_cbe_tmp__16__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge23_2e_us_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__29;

llvm_cbe_tmp__30:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds float* %%d, i64 %%storemerge14.us.us, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__10 = (float *)(&llvm_cbe_d[(((signed long long )llvm_cbe_storemerge14_2e_us_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14.us.us = 0x%I64X",((signed long long )llvm_cbe_storemerge14_2e_us_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load float* %%15, align 4, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__11 = (float )*llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__11, *(int*)(&llvm_cbe_tmp__11));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = fadd float %%31, %%16, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__12 = (float )((float )(llvm_cbe_tmp__25 + llvm_cbe_tmp__11));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__12, *(int*)(&llvm_cbe_tmp__12));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%17, float* %%20, align 4, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_79_count);
  *llvm_cbe_tmp__15 = llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i64 %%storemerge14.us.us, 1, !dbg !13 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__13 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14_2e_us_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__13&18446744073709551615ull)));
  if (((llvm_cbe_tmp__13&18446744073709551615ULL) == (llvm_cbe_outcols&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge7_2e_us_2d_lcssa_2e_us17;
  } else {
    llvm_cbe_storemerge14_2e_us_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__13;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__29:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = phi float [ 0.000000e+00, %%.lr.ph.us.us ], [ %%31, %%21 ], !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__16 = (float )llvm_cbe_tmp__16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__16);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23.us.us = phi i64 [ 0, %%.lr.ph.us.us ], [ %%32, %%21  for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_storemerge23_2e_us_2e_us_count);
  llvm_cbe_storemerge23_2e_us_2e_us = (unsigned long long )llvm_cbe_storemerge23_2e_us_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23.us.us = 0x%I64X",llvm_cbe_storemerge23_2e_us_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__26);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add i64 %%storemerge23.us.us, %%13, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__17 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23_2e_us_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__17&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds float* %%A, i64 %%23, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__18 = (float *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__17))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__17));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load float* %%24, align 4, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__19 = (float )*llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__19, *(int*)(&llvm_cbe_tmp__19));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = mul i64 %%storemerge23.us.us, %%outcols, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__20 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23_2e_us_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_outcols&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__20&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add i64 %%26, %%storemerge14.us.us, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__21 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__20&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge14_2e_us_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__21&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds float* %%B, i64 %%27, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__22 = (float *)(&llvm_cbe_B[(((signed long long )llvm_cbe_tmp__21))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__21));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load float* %%28, align 4, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__23 = (float )*llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__23, *(int*)(&llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = fmul float %%25, %%29, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__24 = (float )((float )(llvm_cbe_tmp__19 * llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__24, *(int*)(&llvm_cbe_tmp__24));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = fadd float %%22, %%30, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__25 = (float )((float )(llvm_cbe_tmp__16 + llvm_cbe_tmp__24));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__25, *(int*)(&llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%31, float* %%20, align 4, !dbg !11 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_109_count);
  *llvm_cbe_tmp__15 = llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i64 %%storemerge23.us.us, 1, !dbg !13 for 0x%I64xth hint within @k2c_affine_matmul  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__26 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23_2e_us_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__26&18446744073709551615ull)));
  if (((llvm_cbe_tmp__26&18446744073709551615ULL) == (llvm_cbe_innerdim&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__30;
  } else {
    llvm_cbe_tmp__16__PHI_TEMPORARY = (float )llvm_cbe_tmp__25;   /* for PHI node */
    llvm_cbe_storemerge23_2e_us_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__26;   /* for PHI node */
    goto llvm_cbe_tmp__29;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us.us' */
  } while (1); /* end of syntactic loop '.lr.ph6.us' */
llvm_cbe__2e__crit_edge11:
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__27:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_affine_matmul}\n");
  return;
}


signed long long k2c_sub2idx(signed long long *llvm_cbe_sub, signed long long *llvm_cbe_shape, signed long long llvm_cbe_ndim) {
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge5_count = 0;
  unsigned long long llvm_cbe_storemerge5;
  unsigned long long llvm_cbe_storemerge5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned long long llvm_cbe_tmp__31;
  unsigned long long llvm_cbe_tmp__31__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  signed long long *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  unsigned long long llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge13_count = 0;
  unsigned long long llvm_cbe_storemerge13;
  unsigned long long llvm_cbe_storemerge13__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  unsigned long long llvm_cbe_tmp__34;
  unsigned long long llvm_cbe_tmp__34__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  signed long long *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  unsigned long long llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned long long llvm_cbe__2e_lcssa;
  unsigned long long llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  unsigned long long llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  unsigned long long llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa4_count = 0;
  unsigned long long llvm_cbe__2e_lcssa4;
  unsigned long long llvm_cbe__2e_lcssa4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_sub2idx\n");
  if (((llvm_cbe_ndim&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa4__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge8;
  } else {
    goto llvm_cbe__2e_lr_2e_ph7;
  }

llvm_cbe__2e_lr_2e_ph7:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = add i64 %%ndim, -1, !dbg !11 for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )((unsigned long long )(llvm_cbe_ndim&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge12 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)));
  llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__31__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__40;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__40:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge5 = phi i64 [ 0, %%.lr.ph7 ], [ %%13, %%._crit_edge  for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_storemerge5_count);
  llvm_cbe_storemerge5 = (unsigned long long )llvm_cbe_storemerge5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5 = 0x%I64X",llvm_cbe_storemerge5);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = phi i64 [ 0, %%.lr.ph7 ], [ %%12, %%._crit_edge  for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__31 = (unsigned long long )llvm_cbe_tmp__31__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__31);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__38);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i64* %%sub, i64 %%storemerge5, !dbg !10 for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__32 = (signed long long *)(&llvm_cbe_sub[(((signed long long )llvm_cbe_storemerge5))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5 = 0x%I64X",((signed long long )llvm_cbe_storemerge5));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i64* %%4, align 8, !dbg !10 for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__33 = (unsigned long long )*llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__33);
  if ((((unsigned long long )llvm_cbe_storemerge12&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_storemerge5&18446744073709551615ULL))) {
    llvm_cbe_storemerge13__PHI_TEMPORARY = (unsigned long long )llvm_cbe_storemerge12;   /* for PHI node */
    llvm_cbe_tmp__34__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__33;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__33;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i64 [ %%5, %%2 ], [ %%10, %%.lr.ph  for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned long long )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%I64X",llvm_cbe__2e_lcssa);
printf("\n = 0x%I64X",llvm_cbe_tmp__33);
printf("\n = 0x%I64X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i64 %%.lcssa, %%3, !dbg !12 for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__38 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_lcssa&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__38&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i64 %%storemerge5, 1, !dbg !12 for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__39 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge5&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__39&18446744073709551615ull)));
  if (((llvm_cbe_tmp__39&18446744073709551615ULL) == (llvm_cbe_ndim&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa4__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__38;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge8;
  } else {
    llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__39;   /* for PHI node */
    llvm_cbe_tmp__31__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__38;   /* for PHI node */
    goto llvm_cbe_tmp__40;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge13 = phi i64 [ %%storemerge1, %%.lr.ph ], [ %%storemerge12, %%2  for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_storemerge13_count);
  llvm_cbe_storemerge13 = (unsigned long long )llvm_cbe_storemerge13__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge13 = 0x%I64X",llvm_cbe_storemerge13);
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = phi i64 [ %%10, %%.lr.ph ], [ %%5, %%2  for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__34 = (unsigned long long )llvm_cbe_tmp__34__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__34);
printf("\n = 0x%I64X",llvm_cbe_tmp__37);
printf("\n = 0x%I64X",llvm_cbe_tmp__33);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i64* %%shape, i64 %%storemerge13, !dbg !11 for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_153_count);
  llvm_cbe_tmp__35 = (signed long long *)(&llvm_cbe_shape[(((signed long long )llvm_cbe_storemerge13))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge13 = 0x%I64X",((signed long long )llvm_cbe_storemerge13));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%8, align 8, !dbg !11 for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__36 = (unsigned long long )*llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = mul i64 %%9, %%7, !dbg !11 for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__37 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__36&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__34&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__37&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = add i64 %%storemerge13, -1, !dbg !11 for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge13&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge1 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_storemerge1&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_storemerge5&18446744073709551615ULL))) {
    llvm_cbe_storemerge13__PHI_TEMPORARY = (unsigned long long )llvm_cbe_storemerge1;   /* for PHI node */
    llvm_cbe_tmp__34__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__37;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__37;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge8:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa4 = phi i64 [ 0, %%0 ], [ %%12, %%._crit_edge  for 0x%I64xth hint within @k2c_sub2idx  --> \n", ++aesl_llvm_cbe__2e_lcssa4_count);
  llvm_cbe__2e_lcssa4 = (unsigned long long )llvm_cbe__2e_lcssa4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa4 = 0x%I64X",llvm_cbe__2e_lcssa4);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__38);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_sub2idx}\n");
  return llvm_cbe__2e_lcssa4;
}


void k2c_idx2sub(signed long long llvm_cbe_idx, signed long long *llvm_cbe_sub, signed long long *llvm_cbe_shape, signed long long llvm_cbe_ndim) {
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned int llvm_cbe_storemerge2;
  unsigned int llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  unsigned long long llvm_cbe_tmp__42__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  unsigned long long llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  signed long long *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  unsigned long long llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  unsigned long long llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  signed long long *llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_idx2sub\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = trunc i64 %%ndim to i32, !dbg !12 for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__41 = (unsigned int )((unsigned int )llvm_cbe_ndim&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = add i32 %%1, -1, !dbg !12 for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )((unsigned int )(llvm_cbe_tmp__41&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge1 = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge1&4294967295ull)));
  if ((((signed int )llvm_cbe_storemerge1) > ((signed int )4294967295u))) {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge1;   /* for PHI node */
    llvm_cbe_tmp__42__PHI_TEMPORARY = (unsigned long long )llvm_cbe_idx;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi i32 [ %%storemerge, %%.lr.ph ], [ %%storemerge1, %%0  for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned int )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%X",llvm_cbe_storemerge2);
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = phi i64 [ %%10, %%.lr.ph ], [ %%idx, %%0  for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__42 = (unsigned long long )llvm_cbe_tmp__42__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__42);
printf("\n = 0x%I64X",llvm_cbe_tmp__49);
printf("\nidx = 0x%I64X",llvm_cbe_idx);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%storemerge2 to i64, !dbg !10 for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__43 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i64* %%shape, i64 %%4, !dbg !10 for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__44 = (signed long long *)(&llvm_cbe_shape[(((signed long long )llvm_cbe_tmp__43))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__43));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !10 for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__45 = (unsigned long long )*llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = urem i64 %%3, %%6, !dbg !10 for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__46 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__42&18446744073709551615ull)) % ((unsigned long long )(llvm_cbe_tmp__45&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__46&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i64* %%sub, i64 %%4, !dbg !10 for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__47 = (signed long long *)(&llvm_cbe_sub[(((signed long long )llvm_cbe_tmp__43))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__43));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%7, i64* %%8, align 8, !dbg !10 for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_204_count);
  *llvm_cbe_tmp__47 = llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%5, align 8, !dbg !11 for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__48 = (unsigned long long )*llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = udiv i64 %%3, %%9, !dbg !11 for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__49 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__42&18446744073709551615ull)) / ((unsigned long long )(llvm_cbe_tmp__48&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__49&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = add i32 %%storemerge2, -1, !dbg !12 for 0x%I64xth hint within @k2c_idx2sub  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )((unsigned int )(llvm_cbe_storemerge2&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge&4294967295ull)));
  if ((((signed int )llvm_cbe_storemerge) > ((signed int )4294967295u))) {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge;   /* for PHI node */
    llvm_cbe_tmp__42__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__49;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_idx2sub}\n");
  return;
}


void k2c_dot(l_struct_OC_k2c_tensor *llvm_cbe_C, l_struct_OC_k2c_tensor *llvm_cbe_Ar, l_struct_OC_k2c_tensor *llvm_cbe_B, signed long long *llvm_cbe_axesA, signed long long *llvm_cbe_axesB, signed long long llvm_cbe_naxes, signed int llvm_cbe_normalize, float *llvm_cbe_fwork) {
  static  unsigned long long aesl_llvm_cbe_permA_count = 0;
  signed long long llvm_cbe_permA[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_permB_count = 0;
  signed long long llvm_cbe_permB[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_freeA_count = 0;
  signed long long llvm_cbe_freeA[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_freeB_count = 0;
  signed long long llvm_cbe_freeB[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_newshpA_count = 0;
  signed long long llvm_cbe_newshpA[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_newshpB_count = 0;
  signed long long llvm_cbe_newshpB[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_Asub_count = 0;
  signed long long llvm_cbe_Asub[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_Bsub_count = 0;
  signed long long llvm_cbe_Bsub[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  signed long long *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  unsigned long long llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  signed long long *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  unsigned long long llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  signed long long *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  unsigned long long llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge121_count = 0;
  unsigned long long llvm_cbe_storemerge121;
  unsigned long long llvm_cbe_storemerge121__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  unsigned long long llvm_cbe_tmp__56;
  unsigned long long llvm_cbe_tmp__56__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge24117_count = 0;
  unsigned long long llvm_cbe_storemerge24117;
  unsigned long long llvm_cbe_storemerge24117__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  unsigned int llvm_cbe_tmp__57;
  unsigned int llvm_cbe_tmp__57__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  signed long long *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  unsigned long long llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond142_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_phitmp_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  signed long long *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  unsigned long long llvm_cbe_tmp__63;
  unsigned long long llvm_cbe_tmp__63__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  unsigned long long llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond143_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1114_count = 0;
  unsigned long long llvm_cbe_storemerge1114;
  unsigned long long llvm_cbe_storemerge1114__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  unsigned long long llvm_cbe_tmp__65;
  unsigned long long llvm_cbe_tmp__65__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23109_count = 0;
  unsigned long long llvm_cbe_storemerge23109;
  unsigned long long llvm_cbe_storemerge23109__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  unsigned int llvm_cbe_tmp__66;
  unsigned int llvm_cbe_tmp__66__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  signed long long *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  unsigned long long llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_27_count = 0;
  unsigned int llvm_cbe__2e_27;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  unsigned long long llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond140_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_phitmp122_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  signed long long *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  unsigned long long llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  unsigned long long llvm_cbe_tmp__72;
  unsigned long long llvm_cbe_tmp__72__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  unsigned long long llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond141_count = 0;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2104_count = 0;
  unsigned long long llvm_cbe_storemerge2104;
  unsigned long long llvm_cbe_storemerge2104__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  unsigned long long llvm_cbe_tmp__74;
  unsigned long long llvm_cbe_tmp__74__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  signed long long *llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  unsigned long long llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  signed long long *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  unsigned long long llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  unsigned long long llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond139_count = 0;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge398_count = 0;
  unsigned long long llvm_cbe_storemerge398;
  unsigned long long llvm_cbe_storemerge398__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  unsigned long long llvm_cbe_tmp__81;
  unsigned long long llvm_cbe_tmp__81__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  signed long long *llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  unsigned long long llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  signed long long *llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  unsigned long long llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  unsigned long long llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  unsigned long long llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond137_count = 0;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa103145_count = 0;
  unsigned long long llvm_cbe__2e_lcssa103145;
  unsigned long long llvm_cbe__2e_lcssa103145__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa97_count = 0;
  unsigned long long llvm_cbe__2e_lcssa97;
  unsigned long long llvm_cbe__2e_lcssa97__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  unsigned long long llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  signed long long *llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  unsigned long long llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  unsigned long long llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
  unsigned long long llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge492_count = 0;
  unsigned long long llvm_cbe_storemerge492;
  unsigned long long llvm_cbe_storemerge492__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  signed long long *llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  unsigned long long llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  signed long long *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  unsigned long long llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge589_count = 0;
  unsigned long long llvm_cbe_storemerge589;
  unsigned long long llvm_cbe_storemerge589__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge122688_count = 0;
  unsigned long long llvm_cbe_storemerge122688;
  unsigned long long llvm_cbe_storemerge122688__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  signed long long *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  unsigned long long llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  signed long long *llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  unsigned long long llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
  static  unsigned long long aesl_llvm_cbe_1075_count = 0;
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  unsigned long long llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond135_count = 0;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  unsigned long long llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge685_count = 0;
  unsigned long long llvm_cbe_storemerge685;
  unsigned long long llvm_cbe_storemerge685__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  signed long long *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
  signed long long *llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;
  unsigned long long llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;
  static  unsigned long long aesl_llvm_cbe_1122_count = 0;
  static  unsigned long long aesl_llvm_cbe_1123_count = 0;
  static  unsigned long long aesl_llvm_cbe_1124_count = 0;
  static  unsigned long long aesl_llvm_cbe_1125_count = 0;
  static  unsigned long long aesl_llvm_cbe_1126_count = 0;
  static  unsigned long long aesl_llvm_cbe_1127_count = 0;
  static  unsigned long long aesl_llvm_cbe_1128_count = 0;
  static  unsigned long long aesl_llvm_cbe_1129_count = 0;
  static  unsigned long long aesl_llvm_cbe_1130_count = 0;
  static  unsigned long long aesl_llvm_cbe_1131_count = 0;
  static  unsigned long long aesl_llvm_cbe_1132_count = 0;
  static  unsigned long long aesl_llvm_cbe_1133_count = 0;
  static  unsigned long long aesl_llvm_cbe_1134_count = 0;
  static  unsigned long long aesl_llvm_cbe_1135_count = 0;
  static  unsigned long long aesl_llvm_cbe_1136_count = 0;
  static  unsigned long long aesl_llvm_cbe_1137_count = 0;
  static  unsigned long long aesl_llvm_cbe_1138_count = 0;
  static  unsigned long long aesl_llvm_cbe_1139_count = 0;
  static  unsigned long long aesl_llvm_cbe_1140_count = 0;
  static  unsigned long long aesl_llvm_cbe_1141_count = 0;
  static  unsigned long long aesl_llvm_cbe_1142_count = 0;
  static  unsigned long long aesl_llvm_cbe_1143_count = 0;
  static  unsigned long long aesl_llvm_cbe_1144_count = 0;
  static  unsigned long long aesl_llvm_cbe_1145_count = 0;
  static  unsigned long long aesl_llvm_cbe_1146_count = 0;
  static  unsigned long long aesl_llvm_cbe_1147_count = 0;
  static  unsigned long long aesl_llvm_cbe_1148_count = 0;
  static  unsigned long long aesl_llvm_cbe_1149_count = 0;
  static  unsigned long long aesl_llvm_cbe_1150_count = 0;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond134_count = 0;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  static  unsigned long long aesl_llvm_cbe_1174_count = 0;
  static  unsigned long long aesl_llvm_cbe_1175_count = 0;
  static  unsigned long long aesl_llvm_cbe_1176_count = 0;
  static  unsigned long long aesl_llvm_cbe_1177_count = 0;
  static  unsigned long long aesl_llvm_cbe_1178_count = 0;
  static  unsigned long long aesl_llvm_cbe_1179_count = 0;
  static  unsigned long long aesl_llvm_cbe_1180_count = 0;
  static  unsigned long long aesl_llvm_cbe_1181_count = 0;
  static  unsigned long long aesl_llvm_cbe_1182_count = 0;
  static  unsigned long long aesl_llvm_cbe_1183_count = 0;
  static  unsigned long long aesl_llvm_cbe_1184_count = 0;
  static  unsigned long long aesl_llvm_cbe_1185_count = 0;
  static  unsigned long long aesl_llvm_cbe_1186_count = 0;
  static  unsigned long long aesl_llvm_cbe_1187_count = 0;
  static  unsigned long long aesl_llvm_cbe_1188_count = 0;
  static  unsigned long long aesl_llvm_cbe_1189_count = 0;
  static  unsigned long long aesl_llvm_cbe_1190_count = 0;
  static  unsigned long long aesl_llvm_cbe_1191_count = 0;
  static  unsigned long long aesl_llvm_cbe_1192_count = 0;
  static  unsigned long long aesl_llvm_cbe_1193_count = 0;
  static  unsigned long long aesl_llvm_cbe_1194_count = 0;
  static  unsigned long long aesl_llvm_cbe_1195_count = 0;
  static  unsigned long long aesl_llvm_cbe_1196_count = 0;
  static  unsigned long long aesl_llvm_cbe_1197_count = 0;
  static  unsigned long long aesl_llvm_cbe_1198_count = 0;
  static  unsigned long long aesl_llvm_cbe_1199_count = 0;
  static  unsigned long long aesl_llvm_cbe_1200_count = 0;
  static  unsigned long long aesl_llvm_cbe_1201_count = 0;
  static  unsigned long long aesl_llvm_cbe_1202_count = 0;
  static  unsigned long long aesl_llvm_cbe_1203_count = 0;
  static  unsigned long long aesl_llvm_cbe_1204_count = 0;
  static  unsigned long long aesl_llvm_cbe_1205_count = 0;
  static  unsigned long long aesl_llvm_cbe_1206_count = 0;
  static  unsigned long long aesl_llvm_cbe_1207_count = 0;
  static  unsigned long long aesl_llvm_cbe_1208_count = 0;
  static  unsigned long long aesl_llvm_cbe_1209_count = 0;
  static  unsigned long long aesl_llvm_cbe_1210_count = 0;
  static  unsigned long long aesl_llvm_cbe_1211_count = 0;
  static  unsigned long long aesl_llvm_cbe_1212_count = 0;
  static  unsigned long long aesl_llvm_cbe_1213_count = 0;
  static  unsigned long long aesl_llvm_cbe_1214_count = 0;
  static  unsigned long long aesl_llvm_cbe_1215_count = 0;
  static  unsigned long long aesl_llvm_cbe_1216_count = 0;
  static  unsigned long long aesl_llvm_cbe_1217_count = 0;
  static  unsigned long long aesl_llvm_cbe_1218_count = 0;
  static  unsigned long long aesl_llvm_cbe_1219_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge782_count = 0;
  unsigned long long llvm_cbe_storemerge782;
  unsigned long long llvm_cbe_storemerge782__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge122581_count = 0;
  unsigned long long llvm_cbe_storemerge122581;
  unsigned long long llvm_cbe_storemerge122581__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1220_count = 0;
  signed long long *llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_1221_count = 0;
  unsigned long long llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_1222_count = 0;
  signed long long *llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_1223_count = 0;
  static  unsigned long long aesl_llvm_cbe_1224_count = 0;
  unsigned long long llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_1225_count = 0;
  static  unsigned long long aesl_llvm_cbe_1226_count = 0;
  static  unsigned long long aesl_llvm_cbe_1227_count = 0;
  static  unsigned long long aesl_llvm_cbe_1228_count = 0;
  static  unsigned long long aesl_llvm_cbe_1229_count = 0;
  static  unsigned long long aesl_llvm_cbe_1230_count = 0;
  static  unsigned long long aesl_llvm_cbe_1231_count = 0;
  static  unsigned long long aesl_llvm_cbe_1232_count = 0;
  static  unsigned long long aesl_llvm_cbe_1233_count = 0;
  static  unsigned long long aesl_llvm_cbe_1234_count = 0;
  static  unsigned long long aesl_llvm_cbe_1235_count = 0;
  static  unsigned long long aesl_llvm_cbe_1236_count = 0;
  static  unsigned long long aesl_llvm_cbe_1237_count = 0;
  static  unsigned long long aesl_llvm_cbe_1238_count = 0;
  static  unsigned long long aesl_llvm_cbe_1239_count = 0;
  static  unsigned long long aesl_llvm_cbe_1240_count = 0;
  static  unsigned long long aesl_llvm_cbe_1241_count = 0;
  static  unsigned long long aesl_llvm_cbe_1242_count = 0;
  static  unsigned long long aesl_llvm_cbe_1243_count = 0;
  static  unsigned long long aesl_llvm_cbe_1244_count = 0;
  static  unsigned long long aesl_llvm_cbe_1245_count = 0;
  static  unsigned long long aesl_llvm_cbe_1246_count = 0;
  static  unsigned long long aesl_llvm_cbe_1247_count = 0;
  static  unsigned long long aesl_llvm_cbe_1248_count = 0;
  static  unsigned long long aesl_llvm_cbe_1249_count = 0;
  static  unsigned long long aesl_llvm_cbe_1250_count = 0;
  static  unsigned long long aesl_llvm_cbe_1251_count = 0;
  static  unsigned long long aesl_llvm_cbe_1252_count = 0;
  static  unsigned long long aesl_llvm_cbe_1253_count = 0;
  static  unsigned long long aesl_llvm_cbe_1254_count = 0;
  static  unsigned long long aesl_llvm_cbe_1255_count = 0;
  static  unsigned long long aesl_llvm_cbe_1256_count = 0;
  static  unsigned long long aesl_llvm_cbe_1257_count = 0;
  static  unsigned long long aesl_llvm_cbe_1258_count = 0;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;
  unsigned long long llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond133_count = 0;
  static  unsigned long long aesl_llvm_cbe_1281_count = 0;
  static  unsigned long long aesl_llvm_cbe_1282_count = 0;
  static  unsigned long long aesl_llvm_cbe_1283_count = 0;
  static  unsigned long long aesl_llvm_cbe_1284_count = 0;
  static  unsigned long long aesl_llvm_cbe_1285_count = 0;
  static  unsigned long long aesl_llvm_cbe_1286_count = 0;
  static  unsigned long long aesl_llvm_cbe_1287_count = 0;
  static  unsigned long long aesl_llvm_cbe_1288_count = 0;
  static  unsigned long long aesl_llvm_cbe_1289_count = 0;
  static  unsigned long long aesl_llvm_cbe_1290_count = 0;
  static  unsigned long long aesl_llvm_cbe_1291_count = 0;
  static  unsigned long long aesl_llvm_cbe_1292_count = 0;
  static  unsigned long long aesl_llvm_cbe_1293_count = 0;
  static  unsigned long long aesl_llvm_cbe_1294_count = 0;
  static  unsigned long long aesl_llvm_cbe_1295_count = 0;
  static  unsigned long long aesl_llvm_cbe_1296_count = 0;
  static  unsigned long long aesl_llvm_cbe_1297_count = 0;
  static  unsigned long long aesl_llvm_cbe_1298_count = 0;
  static  unsigned long long aesl_llvm_cbe_1299_count = 0;
  static  unsigned long long aesl_llvm_cbe_1300_count = 0;
  static  unsigned long long aesl_llvm_cbe_1301_count = 0;
  static  unsigned long long aesl_llvm_cbe_1302_count = 0;
  static  unsigned long long aesl_llvm_cbe_1303_count = 0;
  static  unsigned long long aesl_llvm_cbe_1304_count = 0;
  static  unsigned long long aesl_llvm_cbe_1305_count = 0;
  static  unsigned long long aesl_llvm_cbe_1306_count = 0;
  static  unsigned long long aesl_llvm_cbe_1307_count = 0;
  static  unsigned long long aesl_llvm_cbe_1308_count = 0;
  static  unsigned long long aesl_llvm_cbe_1309_count = 0;
  static  unsigned long long aesl_llvm_cbe_1310_count = 0;
  static  unsigned long long aesl_llvm_cbe_1311_count = 0;
  static  unsigned long long aesl_llvm_cbe_1312_count = 0;
  static  unsigned long long aesl_llvm_cbe_1313_count = 0;
  static  unsigned long long aesl_llvm_cbe_1314_count = 0;
  static  unsigned long long aesl_llvm_cbe_1315_count = 0;
  static  unsigned long long aesl_llvm_cbe_1316_count = 0;
  static  unsigned long long aesl_llvm_cbe_1317_count = 0;
  static  unsigned long long aesl_llvm_cbe_1318_count = 0;
  static  unsigned long long aesl_llvm_cbe_1319_count = 0;
  static  unsigned long long aesl_llvm_cbe_1320_count = 0;
  static  unsigned long long aesl_llvm_cbe_1321_count = 0;
  static  unsigned long long aesl_llvm_cbe_1322_count = 0;
  static  unsigned long long aesl_llvm_cbe_1323_count = 0;
  static  unsigned long long aesl_llvm_cbe_1324_count = 0;
  static  unsigned long long aesl_llvm_cbe_1325_count = 0;
  static  unsigned long long aesl_llvm_cbe_1326_count = 0;
  static  unsigned long long aesl_llvm_cbe_1327_count = 0;
  static  unsigned long long aesl_llvm_cbe_1328_count = 0;
  static  unsigned long long aesl_llvm_cbe_1329_count = 0;
  static  unsigned long long aesl_llvm_cbe_1330_count = 0;
  static  unsigned long long aesl_llvm_cbe_1331_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge878_count = 0;
  unsigned long long llvm_cbe_storemerge878;
  unsigned long long llvm_cbe_storemerge878__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1332_count = 0;
  signed long long *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_1333_count = 0;
  unsigned long long llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_1334_count = 0;
  signed long long *llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_1335_count = 0;
  unsigned long long llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_1336_count = 0;
  signed long long *llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_1337_count = 0;
  static  unsigned long long aesl_llvm_cbe_1338_count = 0;
  unsigned long long llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_1339_count = 0;
  static  unsigned long long aesl_llvm_cbe_1340_count = 0;
  static  unsigned long long aesl_llvm_cbe_1341_count = 0;
  static  unsigned long long aesl_llvm_cbe_1342_count = 0;
  static  unsigned long long aesl_llvm_cbe_1343_count = 0;
  static  unsigned long long aesl_llvm_cbe_1344_count = 0;
  static  unsigned long long aesl_llvm_cbe_1345_count = 0;
  static  unsigned long long aesl_llvm_cbe_1346_count = 0;
  static  unsigned long long aesl_llvm_cbe_1347_count = 0;
  static  unsigned long long aesl_llvm_cbe_1348_count = 0;
  static  unsigned long long aesl_llvm_cbe_1349_count = 0;
  static  unsigned long long aesl_llvm_cbe_1350_count = 0;
  static  unsigned long long aesl_llvm_cbe_1351_count = 0;
  static  unsigned long long aesl_llvm_cbe_1352_count = 0;
  static  unsigned long long aesl_llvm_cbe_1353_count = 0;
  static  unsigned long long aesl_llvm_cbe_1354_count = 0;
  static  unsigned long long aesl_llvm_cbe_1355_count = 0;
  static  unsigned long long aesl_llvm_cbe_1356_count = 0;
  static  unsigned long long aesl_llvm_cbe_1357_count = 0;
  static  unsigned long long aesl_llvm_cbe_1358_count = 0;
  static  unsigned long long aesl_llvm_cbe_1359_count = 0;
  static  unsigned long long aesl_llvm_cbe_1360_count = 0;
  static  unsigned long long aesl_llvm_cbe_1361_count = 0;
  static  unsigned long long aesl_llvm_cbe_1362_count = 0;
  static  unsigned long long aesl_llvm_cbe_1363_count = 0;
  static  unsigned long long aesl_llvm_cbe_1364_count = 0;
  static  unsigned long long aesl_llvm_cbe_1365_count = 0;
  static  unsigned long long aesl_llvm_cbe_1366_count = 0;
  static  unsigned long long aesl_llvm_cbe_1367_count = 0;
  static  unsigned long long aesl_llvm_cbe_1368_count = 0;
  static  unsigned long long aesl_llvm_cbe_1369_count = 0;
  static  unsigned long long aesl_llvm_cbe_1370_count = 0;
  static  unsigned long long aesl_llvm_cbe_1371_count = 0;
  static  unsigned long long aesl_llvm_cbe_1372_count = 0;
  static  unsigned long long aesl_llvm_cbe_1373_count = 0;
  static  unsigned long long aesl_llvm_cbe_1374_count = 0;
  static  unsigned long long aesl_llvm_cbe_1375_count = 0;
  static  unsigned long long aesl_llvm_cbe_1376_count = 0;
  static  unsigned long long aesl_llvm_cbe_1377_count = 0;
  static  unsigned long long aesl_llvm_cbe_1378_count = 0;
  static  unsigned long long aesl_llvm_cbe_1379_count = 0;
  static  unsigned long long aesl_llvm_cbe_1380_count = 0;
  static  unsigned long long aesl_llvm_cbe_1381_count = 0;
  static  unsigned long long aesl_llvm_cbe_1382_count = 0;
  static  unsigned long long aesl_llvm_cbe_1383_count = 0;
  static  unsigned long long aesl_llvm_cbe_1384_count = 0;
  static  unsigned long long aesl_llvm_cbe_1385_count = 0;
  static  unsigned long long aesl_llvm_cbe_1386_count = 0;
  static  unsigned long long aesl_llvm_cbe_1387_count = 0;
  static  unsigned long long aesl_llvm_cbe_1388_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond132_count = 0;
  static  unsigned long long aesl_llvm_cbe_1389_count = 0;
  static  unsigned long long aesl_llvm_cbe_1390_count = 0;
  static  unsigned long long aesl_llvm_cbe_1391_count = 0;
  static  unsigned long long aesl_llvm_cbe_1392_count = 0;
  static  unsigned long long aesl_llvm_cbe_1393_count = 0;
  static  unsigned long long aesl_llvm_cbe_1394_count = 0;
  static  unsigned long long aesl_llvm_cbe_1395_count = 0;
  static  unsigned long long aesl_llvm_cbe_1396_count = 0;
  static  unsigned long long aesl_llvm_cbe_1397_count = 0;
  static  unsigned long long aesl_llvm_cbe_1398_count = 0;
  static  unsigned long long aesl_llvm_cbe_1399_count = 0;
  static  unsigned long long aesl_llvm_cbe_1400_count = 0;
  static  unsigned long long aesl_llvm_cbe_1401_count = 0;
  static  unsigned long long aesl_llvm_cbe_1402_count = 0;
  static  unsigned long long aesl_llvm_cbe_1403_count = 0;
  static  unsigned long long aesl_llvm_cbe_1404_count = 0;
  static  unsigned long long aesl_llvm_cbe_1405_count = 0;
  static  unsigned long long aesl_llvm_cbe_1406_count = 0;
  static  unsigned long long aesl_llvm_cbe_1407_count = 0;
  static  unsigned long long aesl_llvm_cbe_1408_count = 0;
  static  unsigned long long aesl_llvm_cbe_1409_count = 0;
  static  unsigned long long aesl_llvm_cbe_1410_count = 0;
  static  unsigned long long aesl_llvm_cbe_1411_count = 0;
  static  unsigned long long aesl_llvm_cbe_1412_count = 0;
  static  unsigned long long aesl_llvm_cbe_1413_count = 0;
  static  unsigned long long aesl_llvm_cbe_1414_count = 0;
  static  unsigned long long aesl_llvm_cbe_1415_count = 0;
  static  unsigned long long aesl_llvm_cbe_1416_count = 0;
  static  unsigned long long aesl_llvm_cbe_1417_count = 0;
  static  unsigned long long aesl_llvm_cbe_1418_count = 0;
  static  unsigned long long aesl_llvm_cbe_1419_count = 0;
  static  unsigned long long aesl_llvm_cbe_1420_count = 0;
  static  unsigned long long aesl_llvm_cbe_1421_count = 0;
  static  unsigned long long aesl_llvm_cbe_1422_count = 0;
  static  unsigned long long aesl_llvm_cbe_1423_count = 0;
  static  unsigned long long aesl_llvm_cbe_1424_count = 0;
  static  unsigned long long aesl_llvm_cbe_1425_count = 0;
  static  unsigned long long aesl_llvm_cbe_1426_count = 0;
  static  unsigned long long aesl_llvm_cbe_1427_count = 0;
  static  unsigned long long aesl_llvm_cbe_1428_count = 0;
  static  unsigned long long aesl_llvm_cbe_1429_count = 0;
  static  unsigned long long aesl_llvm_cbe_1430_count = 0;
  static  unsigned long long aesl_llvm_cbe_1431_count = 0;
  static  unsigned long long aesl_llvm_cbe_1432_count = 0;
  static  unsigned long long aesl_llvm_cbe_1433_count = 0;
  static  unsigned long long aesl_llvm_cbe_1434_count = 0;
  static  unsigned long long aesl_llvm_cbe_1435_count = 0;
  static  unsigned long long aesl_llvm_cbe_1436_count = 0;
  static  unsigned long long aesl_llvm_cbe_1437_count = 0;
  static  unsigned long long aesl_llvm_cbe_1438_count = 0;
  static  unsigned long long aesl_llvm_cbe_1439_count = 0;
  static  unsigned long long aesl_llvm_cbe_1440_count = 0;
  static  unsigned long long aesl_llvm_cbe_1441_count = 0;
  signed long long *llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_1442_count = 0;
  signed long long *llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_1443_count = 0;
  signed long long *llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_1444_count = 0;
  signed long long *llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_1445_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge975_count = 0;
  unsigned long long llvm_cbe_storemerge975;
  unsigned long long llvm_cbe_storemerge975__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1446_count = 0;
  signed long long *llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_1447_count = 0;
  unsigned long long llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_1448_count = 0;
  signed long long *llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_1449_count = 0;
  unsigned long long llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_1450_count = 0;
  signed long long *llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_1451_count = 0;
  static  unsigned long long aesl_llvm_cbe_1452_count = 0;
  unsigned long long llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_1453_count = 0;
  static  unsigned long long aesl_llvm_cbe_1454_count = 0;
  static  unsigned long long aesl_llvm_cbe_1455_count = 0;
  static  unsigned long long aesl_llvm_cbe_1456_count = 0;
  static  unsigned long long aesl_llvm_cbe_1457_count = 0;
  static  unsigned long long aesl_llvm_cbe_1458_count = 0;
  static  unsigned long long aesl_llvm_cbe_1459_count = 0;
  static  unsigned long long aesl_llvm_cbe_1460_count = 0;
  static  unsigned long long aesl_llvm_cbe_1461_count = 0;
  static  unsigned long long aesl_llvm_cbe_1462_count = 0;
  static  unsigned long long aesl_llvm_cbe_1463_count = 0;
  static  unsigned long long aesl_llvm_cbe_1464_count = 0;
  static  unsigned long long aesl_llvm_cbe_1465_count = 0;
  static  unsigned long long aesl_llvm_cbe_1466_count = 0;
  static  unsigned long long aesl_llvm_cbe_1467_count = 0;
  static  unsigned long long aesl_llvm_cbe_1468_count = 0;
  static  unsigned long long aesl_llvm_cbe_1469_count = 0;
  static  unsigned long long aesl_llvm_cbe_1470_count = 0;
  static  unsigned long long aesl_llvm_cbe_1471_count = 0;
  static  unsigned long long aesl_llvm_cbe_1472_count = 0;
  static  unsigned long long aesl_llvm_cbe_1473_count = 0;
  static  unsigned long long aesl_llvm_cbe_1474_count = 0;
  static  unsigned long long aesl_llvm_cbe_1475_count = 0;
  static  unsigned long long aesl_llvm_cbe_1476_count = 0;
  static  unsigned long long aesl_llvm_cbe_1477_count = 0;
  static  unsigned long long aesl_llvm_cbe_1478_count = 0;
  static  unsigned long long aesl_llvm_cbe_1479_count = 0;
  static  unsigned long long aesl_llvm_cbe_1480_count = 0;
  static  unsigned long long aesl_llvm_cbe_1481_count = 0;
  static  unsigned long long aesl_llvm_cbe_1482_count = 0;
  static  unsigned long long aesl_llvm_cbe_1483_count = 0;
  static  unsigned long long aesl_llvm_cbe_1484_count = 0;
  static  unsigned long long aesl_llvm_cbe_1485_count = 0;
  static  unsigned long long aesl_llvm_cbe_1486_count = 0;
  static  unsigned long long aesl_llvm_cbe_1487_count = 0;
  static  unsigned long long aesl_llvm_cbe_1488_count = 0;
  static  unsigned long long aesl_llvm_cbe_1489_count = 0;
  static  unsigned long long aesl_llvm_cbe_1490_count = 0;
  static  unsigned long long aesl_llvm_cbe_1491_count = 0;
  static  unsigned long long aesl_llvm_cbe_1492_count = 0;
  static  unsigned long long aesl_llvm_cbe_1493_count = 0;
  static  unsigned long long aesl_llvm_cbe_1494_count = 0;
  static  unsigned long long aesl_llvm_cbe_1495_count = 0;
  static  unsigned long long aesl_llvm_cbe_1496_count = 0;
  static  unsigned long long aesl_llvm_cbe_1497_count = 0;
  static  unsigned long long aesl_llvm_cbe_1498_count = 0;
  static  unsigned long long aesl_llvm_cbe_1499_count = 0;
  static  unsigned long long aesl_llvm_cbe_1500_count = 0;
  static  unsigned long long aesl_llvm_cbe_1501_count = 0;
  static  unsigned long long aesl_llvm_cbe_1502_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond131_count = 0;
  static  unsigned long long aesl_llvm_cbe_1503_count = 0;
  static  unsigned long long aesl_llvm_cbe_1504_count = 0;
  static  unsigned long long aesl_llvm_cbe_1505_count = 0;
  static  unsigned long long aesl_llvm_cbe_1506_count = 0;
  static  unsigned long long aesl_llvm_cbe_1507_count = 0;
  static  unsigned long long aesl_llvm_cbe_1508_count = 0;
  static  unsigned long long aesl_llvm_cbe_1509_count = 0;
  static  unsigned long long aesl_llvm_cbe_1510_count = 0;
  static  unsigned long long aesl_llvm_cbe_1511_count = 0;
  static  unsigned long long aesl_llvm_cbe_1512_count = 0;
  static  unsigned long long aesl_llvm_cbe_1513_count = 0;
  static  unsigned long long aesl_llvm_cbe_1514_count = 0;
  static  unsigned long long aesl_llvm_cbe_1515_count = 0;
  static  unsigned long long aesl_llvm_cbe_1516_count = 0;
  static  unsigned long long aesl_llvm_cbe_1517_count = 0;
  static  unsigned long long aesl_llvm_cbe_1518_count = 0;
  static  unsigned long long aesl_llvm_cbe_1519_count = 0;
  static  unsigned long long aesl_llvm_cbe_1520_count = 0;
  static  unsigned long long aesl_llvm_cbe_1521_count = 0;
  static  unsigned long long aesl_llvm_cbe_1522_count = 0;
  static  unsigned long long aesl_llvm_cbe_1523_count = 0;
  static  unsigned long long aesl_llvm_cbe_1524_count = 0;
  static  unsigned long long aesl_llvm_cbe_1525_count = 0;
  static  unsigned long long aesl_llvm_cbe_1526_count = 0;
  static  unsigned long long aesl_llvm_cbe_1527_count = 0;
  static  unsigned long long aesl_llvm_cbe_1528_count = 0;
  static  unsigned long long aesl_llvm_cbe_1529_count = 0;
  static  unsigned long long aesl_llvm_cbe_1530_count = 0;
  static  unsigned long long aesl_llvm_cbe_1531_count = 0;
  static  unsigned long long aesl_llvm_cbe_1532_count = 0;
  static  unsigned long long aesl_llvm_cbe_1533_count = 0;
  static  unsigned long long aesl_llvm_cbe_1534_count = 0;
  static  unsigned long long aesl_llvm_cbe_1535_count = 0;
  static  unsigned long long aesl_llvm_cbe_1536_count = 0;
  static  unsigned long long aesl_llvm_cbe_1537_count = 0;
  static  unsigned long long aesl_llvm_cbe_1538_count = 0;
  static  unsigned long long aesl_llvm_cbe_1539_count = 0;
  static  unsigned long long aesl_llvm_cbe_1540_count = 0;
  static  unsigned long long aesl_llvm_cbe_1541_count = 0;
  static  unsigned long long aesl_llvm_cbe_1542_count = 0;
  static  unsigned long long aesl_llvm_cbe_1543_count = 0;
  static  unsigned long long aesl_llvm_cbe_1544_count = 0;
  static  unsigned long long aesl_llvm_cbe_1545_count = 0;
  static  unsigned long long aesl_llvm_cbe_1546_count = 0;
  static  unsigned long long aesl_llvm_cbe_1547_count = 0;
  static  unsigned long long aesl_llvm_cbe_1548_count = 0;
  static  unsigned long long aesl_llvm_cbe_1549_count = 0;
  static  unsigned long long aesl_llvm_cbe_1550_count = 0;
  static  unsigned long long aesl_llvm_cbe_1551_count = 0;
  static  unsigned long long aesl_llvm_cbe_1552_count = 0;
  static  unsigned long long aesl_llvm_cbe_1553_count = 0;
  unsigned long long llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_1554_count = 0;
  static  unsigned long long aesl_llvm_cbe_1555_count = 0;
  static  unsigned long long aesl_llvm_cbe_1556_count = 0;
  signed long long *llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_1557_count = 0;
  signed long long *llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_1558_count = 0;
  signed long long *llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_1559_count = 0;
  signed long long *llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_1560_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1072_count = 0;
  unsigned long long llvm_cbe_storemerge1072;
  unsigned long long llvm_cbe_storemerge1072__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1561_count = 0;
  static  unsigned long long aesl_llvm_cbe_1562_count = 0;
  static  unsigned long long aesl_llvm_cbe_1563_count = 0;
  static  unsigned long long aesl_llvm_cbe_1564_count = 0;
  static  unsigned long long aesl_llvm_cbe_1565_count = 0;
  static  unsigned long long aesl_llvm_cbe_1566_count = 0;
  static  unsigned long long aesl_llvm_cbe_1567_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2267_count = 0;
  unsigned long long llvm_cbe_storemerge2267;
  unsigned long long llvm_cbe_storemerge2267__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1568_count = 0;
  signed long long *llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_1569_count = 0;
  unsigned long long llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_1570_count = 0;
  signed long long *llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_1571_count = 0;
  unsigned long long llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_1572_count = 0;
  signed long long *llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_1573_count = 0;
  static  unsigned long long aesl_llvm_cbe_1574_count = 0;
  unsigned long long llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_1575_count = 0;
  static  unsigned long long aesl_llvm_cbe_1576_count = 0;
  static  unsigned long long aesl_llvm_cbe_1577_count = 0;
  static  unsigned long long aesl_llvm_cbe_1578_count = 0;
  static  unsigned long long aesl_llvm_cbe_1579_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond130_count = 0;
  static  unsigned long long aesl_llvm_cbe_1580_count = 0;
  static  unsigned long long aesl_llvm_cbe_1581_count = 0;
  unsigned long long llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_1582_count = 0;
  static  unsigned long long aesl_llvm_cbe_1583_count = 0;
  float *llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_1584_count = 0;
  float llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_1585_count = 0;
  static  unsigned long long aesl_llvm_cbe_1586_count = 0;
  float *llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_1587_count = 0;
  static  unsigned long long aesl_llvm_cbe_1588_count = 0;
  unsigned long long llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_1589_count = 0;
  static  unsigned long long aesl_llvm_cbe_1590_count = 0;
  static  unsigned long long aesl_llvm_cbe_1591_count = 0;
  static  unsigned long long aesl_llvm_cbe_1592_count = 0;
  static  unsigned long long aesl_llvm_cbe_1593_count = 0;
  static  unsigned long long aesl_llvm_cbe_1594_count = 0;
  static  unsigned long long aesl_llvm_cbe_1595_count = 0;
  static  unsigned long long aesl_llvm_cbe_1596_count = 0;
  static  unsigned long long aesl_llvm_cbe_1597_count = 0;
  static  unsigned long long aesl_llvm_cbe_1598_count = 0;
  static  unsigned long long aesl_llvm_cbe_1599_count = 0;
  static  unsigned long long aesl_llvm_cbe_1600_count = 0;
  static  unsigned long long aesl_llvm_cbe_1601_count = 0;
  static  unsigned long long aesl_llvm_cbe_1602_count = 0;
  static  unsigned long long aesl_llvm_cbe_1603_count = 0;
  static  unsigned long long aesl_llvm_cbe_1604_count = 0;
  static  unsigned long long aesl_llvm_cbe_1605_count = 0;
  static  unsigned long long aesl_llvm_cbe_1606_count = 0;
  static  unsigned long long aesl_llvm_cbe_1607_count = 0;
  static  unsigned long long aesl_llvm_cbe_1608_count = 0;
  static  unsigned long long aesl_llvm_cbe_1609_count = 0;
  static  unsigned long long aesl_llvm_cbe_1610_count = 0;
  static  unsigned long long aesl_llvm_cbe_1611_count = 0;
  static  unsigned long long aesl_llvm_cbe_1612_count = 0;
  static  unsigned long long aesl_llvm_cbe_1613_count = 0;
  static  unsigned long long aesl_llvm_cbe_1614_count = 0;
  static  unsigned long long aesl_llvm_cbe_1615_count = 0;
  static  unsigned long long aesl_llvm_cbe_1616_count = 0;
  static  unsigned long long aesl_llvm_cbe_1617_count = 0;
  static  unsigned long long aesl_llvm_cbe_1618_count = 0;
  static  unsigned long long aesl_llvm_cbe_1619_count = 0;
  static  unsigned long long aesl_llvm_cbe_1620_count = 0;
  static  unsigned long long aesl_llvm_cbe_1621_count = 0;
  static  unsigned long long aesl_llvm_cbe_1622_count = 0;
  static  unsigned long long aesl_llvm_cbe_1623_count = 0;
  static  unsigned long long aesl_llvm_cbe_1624_count = 0;
  static  unsigned long long aesl_llvm_cbe_1625_count = 0;
  static  unsigned long long aesl_llvm_cbe_1626_count = 0;
  static  unsigned long long aesl_llvm_cbe_1627_count = 0;
  static  unsigned long long aesl_llvm_cbe_1628_count = 0;
  static  unsigned long long aesl_llvm_cbe_1629_count = 0;
  static  unsigned long long aesl_llvm_cbe_1630_count = 0;
  static  unsigned long long aesl_llvm_cbe_1631_count = 0;
  static  unsigned long long aesl_llvm_cbe_1632_count = 0;
  static  unsigned long long aesl_llvm_cbe_1633_count = 0;
  static  unsigned long long aesl_llvm_cbe_1634_count = 0;
  static  unsigned long long aesl_llvm_cbe_1635_count = 0;
  static  unsigned long long aesl_llvm_cbe_1636_count = 0;
  static  unsigned long long aesl_llvm_cbe_1637_count = 0;
  static  unsigned long long aesl_llvm_cbe_1638_count = 0;
  static  unsigned long long aesl_llvm_cbe_1639_count = 0;
  unsigned long long llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_1640_count = 0;
  static  unsigned long long aesl_llvm_cbe_1641_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1164_count = 0;
  unsigned long long llvm_cbe_storemerge1164;
  unsigned long long llvm_cbe_storemerge1164__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1642_count = 0;
  static  unsigned long long aesl_llvm_cbe_1643_count = 0;
  static  unsigned long long aesl_llvm_cbe_1644_count = 0;
  static  unsigned long long aesl_llvm_cbe_1645_count = 0;
  static  unsigned long long aesl_llvm_cbe_1646_count = 0;
  static  unsigned long long aesl_llvm_cbe_1647_count = 0;
  static  unsigned long long aesl_llvm_cbe_1648_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2159_count = 0;
  unsigned long long llvm_cbe_storemerge2159;
  unsigned long long llvm_cbe_storemerge2159__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1649_count = 0;
  signed long long *llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_1650_count = 0;
  unsigned long long llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_1651_count = 0;
  signed long long *llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_1652_count = 0;
  unsigned long long llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_1653_count = 0;
  signed long long *llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_1654_count = 0;
  static  unsigned long long aesl_llvm_cbe_1655_count = 0;
  unsigned long long llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_1656_count = 0;
  static  unsigned long long aesl_llvm_cbe_1657_count = 0;
  static  unsigned long long aesl_llvm_cbe_1658_count = 0;
  static  unsigned long long aesl_llvm_cbe_1659_count = 0;
  static  unsigned long long aesl_llvm_cbe_1660_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond129_count = 0;
  static  unsigned long long aesl_llvm_cbe_1661_count = 0;
  static  unsigned long long aesl_llvm_cbe_1662_count = 0;
  unsigned long long llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_1663_count = 0;
  static  unsigned long long aesl_llvm_cbe_1664_count = 0;
  float *llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_1665_count = 0;
  float llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_1666_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_sum30_count = 0;
  unsigned long long llvm_cbe__2e_sum30;
  static  unsigned long long aesl_llvm_cbe_1667_count = 0;
  float *llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_1668_count = 0;
  static  unsigned long long aesl_llvm_cbe_1669_count = 0;
  unsigned long long llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_1670_count = 0;
  static  unsigned long long aesl_llvm_cbe_1671_count = 0;
  static  unsigned long long aesl_llvm_cbe_1672_count = 0;
  static  unsigned long long aesl_llvm_cbe_1673_count = 0;
  static  unsigned long long aesl_llvm_cbe_1674_count = 0;
  static  unsigned long long aesl_llvm_cbe_1675_count = 0;
  static  unsigned long long aesl_llvm_cbe_1676_count = 0;
  static  unsigned long long aesl_llvm_cbe_1677_count = 0;
  static  unsigned long long aesl_llvm_cbe_1678_count = 0;
  static  unsigned long long aesl_llvm_cbe_1679_count = 0;
  static  unsigned long long aesl_llvm_cbe_1680_count = 0;
  static  unsigned long long aesl_llvm_cbe_1681_count = 0;
  static  unsigned long long aesl_llvm_cbe_1682_count = 0;
  static  unsigned long long aesl_llvm_cbe_1683_count = 0;
  static  unsigned long long aesl_llvm_cbe_1684_count = 0;
  static  unsigned long long aesl_llvm_cbe_1685_count = 0;
  static  unsigned long long aesl_llvm_cbe_1686_count = 0;
  static  unsigned long long aesl_llvm_cbe_1687_count = 0;
  static  unsigned long long aesl_llvm_cbe_1688_count = 0;
  static  unsigned long long aesl_llvm_cbe_1689_count = 0;
  static  unsigned long long aesl_llvm_cbe_1690_count = 0;
  static  unsigned long long aesl_llvm_cbe_1691_count = 0;
  static  unsigned long long aesl_llvm_cbe_1692_count = 0;
  static  unsigned long long aesl_llvm_cbe_1693_count = 0;
  static  unsigned long long aesl_llvm_cbe_1694_count = 0;
  static  unsigned long long aesl_llvm_cbe_1695_count = 0;
  static  unsigned long long aesl_llvm_cbe_1696_count = 0;
  static  unsigned long long aesl_llvm_cbe_1697_count = 0;
  static  unsigned long long aesl_llvm_cbe_1698_count = 0;
  static  unsigned long long aesl_llvm_cbe_1699_count = 0;
  static  unsigned long long aesl_llvm_cbe_1700_count = 0;
  static  unsigned long long aesl_llvm_cbe_1701_count = 0;
  static  unsigned long long aesl_llvm_cbe_1702_count = 0;
  static  unsigned long long aesl_llvm_cbe_1703_count = 0;
  static  unsigned long long aesl_llvm_cbe_1704_count = 0;
  static  unsigned long long aesl_llvm_cbe_1705_count = 0;
  static  unsigned long long aesl_llvm_cbe_1706_count = 0;
  static  unsigned long long aesl_llvm_cbe_1707_count = 0;
  static  unsigned long long aesl_llvm_cbe_1708_count = 0;
  static  unsigned long long aesl_llvm_cbe_1709_count = 0;
  static  unsigned long long aesl_llvm_cbe_1710_count = 0;
  static  unsigned long long aesl_llvm_cbe_1711_count = 0;
  static  unsigned long long aesl_llvm_cbe_1712_count = 0;
  static  unsigned long long aesl_llvm_cbe_1713_count = 0;
  static  unsigned long long aesl_llvm_cbe_1714_count = 0;
  static  unsigned long long aesl_llvm_cbe_1715_count = 0;
  static  unsigned long long aesl_llvm_cbe_1716_count = 0;
  static  unsigned long long aesl_llvm_cbe_1717_count = 0;
  static  unsigned long long aesl_llvm_cbe_1718_count = 0;
  static  unsigned long long aesl_llvm_cbe_1719_count = 0;
  static  unsigned long long aesl_llvm_cbe_1720_count = 0;
  unsigned long long llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_1721_count = 0;
  static  unsigned long long aesl_llvm_cbe_1722_count = 0;
  static  unsigned long long aesl_llvm_cbe_1723_count = 0;
  static  unsigned long long aesl_llvm_cbe_1724_count = 0;
  static  unsigned long long aesl_llvm_cbe_1725_count = 0;
  static  unsigned long long aesl_llvm_cbe_1726_count = 0;
  static  unsigned long long aesl_llvm_cbe_1727_count = 0;
  static  unsigned long long aesl_llvm_cbe_1728_count = 0;
  static  unsigned long long aesl_llvm_cbe_1729_count = 0;
  static  unsigned long long aesl_llvm_cbe_1730_count = 0;
  static  unsigned long long aesl_llvm_cbe_1731_count = 0;
  static  unsigned long long aesl_llvm_cbe_1732_count = 0;
  static  unsigned long long aesl_llvm_cbe_1733_count = 0;
  static  unsigned long long aesl_llvm_cbe_1734_count = 0;
  static  unsigned long long aesl_llvm_cbe_1735_count = 0;
  static  unsigned long long aesl_llvm_cbe_1736_count = 0;
  static  unsigned long long aesl_llvm_cbe_1737_count = 0;
  static  unsigned long long aesl_llvm_cbe_1738_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1558_count = 0;
  unsigned long long llvm_cbe_storemerge1558;
  unsigned long long llvm_cbe_storemerge1558__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1739_count = 0;
  static  unsigned long long aesl_llvm_cbe_1740_count = 0;
  static  unsigned long long aesl_llvm_cbe_1741_count = 0;
  static  unsigned long long aesl_llvm_cbe_1742_count = 0;
  static  unsigned long long aesl_llvm_cbe_1743_count = 0;
  static  unsigned long long aesl_llvm_cbe_1744_count = 0;
  static  unsigned long long aesl_llvm_cbe_1745_count = 0;
  static  unsigned long long aesl_llvm_cbe_1746_count = 0;
  static  unsigned long long aesl_llvm_cbe_1747_count = 0;
  unsigned long long llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_1748_count = 0;
  static  unsigned long long aesl_llvm_cbe_1749_count = 0;
  static  unsigned long long aesl_llvm_cbe_1750_count = 0;
  static  unsigned long long aesl_llvm_cbe_1751_count = 0;
  static  unsigned long long aesl_llvm_cbe_1752_count = 0;
  static  unsigned long long aesl_llvm_cbe_1753_count = 0;
  static  unsigned long long aesl_llvm_cbe_1754_count = 0;
  static  unsigned long long aesl_llvm_cbe_1755_count = 0;
  static  unsigned long long aesl_llvm_cbe_1756_count = 0;
  static  unsigned long long aesl_llvm_cbe_1757_count = 0;
  static  unsigned long long aesl_llvm_cbe_1758_count = 0;
  static  unsigned long long aesl_llvm_cbe_1759_count = 0;
  static  unsigned long long aesl_llvm_cbe_1760_count = 0;
  static  unsigned long long aesl_llvm_cbe_1761_count = 0;
  static  unsigned long long aesl_llvm_cbe_1762_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1953_count = 0;
  unsigned long long llvm_cbe_storemerge1953;
  unsigned long long llvm_cbe_storemerge1953__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1763_count = 0;
  float llvm_cbe_tmp__158;
  float llvm_cbe_tmp__158__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1764_count = 0;
  unsigned long long llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_1765_count = 0;
  float *llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_1766_count = 0;
  float llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_1767_count = 0;
  float llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_1768_count = 0;
  float llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_1769_count = 0;
  static  unsigned long long aesl_llvm_cbe_1770_count = 0;
  static  unsigned long long aesl_llvm_cbe_1771_count = 0;
  static  unsigned long long aesl_llvm_cbe_1772_count = 0;
  static  unsigned long long aesl_llvm_cbe_1773_count = 0;
  static  unsigned long long aesl_llvm_cbe_1774_count = 0;
  unsigned long long llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_1775_count = 0;
  static  unsigned long long aesl_llvm_cbe_1776_count = 0;
  static  unsigned long long aesl_llvm_cbe_1777_count = 0;
  static  unsigned long long aesl_llvm_cbe_1778_count = 0;
  static  unsigned long long aesl_llvm_cbe_1779_count = 0;
  static  unsigned long long aesl_llvm_cbe_1780_count = 0;
  static  unsigned long long aesl_llvm_cbe_1781_count = 0;
  static  unsigned long long aesl_llvm_cbe_1782_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond128_count = 0;
  static  unsigned long long aesl_llvm_cbe_1783_count = 0;
  static  unsigned long long aesl_llvm_cbe_1784_count = 0;
  float llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_1785_count = 0;
  float llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_1786_count = 0;
  static  unsigned long long aesl_llvm_cbe_1787_count = 0;
  static  unsigned long long aesl_llvm_cbe_1788_count = 0;
  static  unsigned long long aesl_llvm_cbe_1789_count = 0;
  static  unsigned long long aesl_llvm_cbe_1790_count = 0;
  static  unsigned long long aesl_llvm_cbe_1791_count = 0;
  static  unsigned long long aesl_llvm_cbe_1792_count = 0;
  static  unsigned long long aesl_llvm_cbe_1793_count = 0;
  static  unsigned long long aesl_llvm_cbe_1794_count = 0;
  static  unsigned long long aesl_llvm_cbe_1795_count = 0;
  static  unsigned long long aesl_llvm_cbe_1796_count = 0;
  static  unsigned long long aesl_llvm_cbe_1797_count = 0;
  static  unsigned long long aesl_llvm_cbe_1798_count = 0;
  static  unsigned long long aesl_llvm_cbe_1799_count = 0;
  static  unsigned long long aesl_llvm_cbe_1800_count = 0;
  static  unsigned long long aesl_llvm_cbe_1801_count = 0;
  unsigned long long llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_1802_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2047_count = 0;
  unsigned long long llvm_cbe_storemerge2047;
  unsigned long long llvm_cbe_storemerge2047__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1803_count = 0;
  unsigned long long llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_1804_count = 0;
  float *llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_1805_count = 0;
  float llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_1806_count = 0;
  float llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_1807_count = 0;
  static  unsigned long long aesl_llvm_cbe_1808_count = 0;
  unsigned long long llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_1809_count = 0;
  static  unsigned long long aesl_llvm_cbe_1810_count = 0;
  static  unsigned long long aesl_llvm_cbe_1811_count = 0;
  static  unsigned long long aesl_llvm_cbe_1812_count = 0;
  static  unsigned long long aesl_llvm_cbe_1813_count = 0;
  static  unsigned long long aesl_llvm_cbe_1814_count = 0;
  static  unsigned long long aesl_llvm_cbe_1815_count = 0;
  static  unsigned long long aesl_llvm_cbe_1816_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond126_count = 0;
  static  unsigned long long aesl_llvm_cbe_1817_count = 0;
  static  unsigned long long aesl_llvm_cbe_1818_count = 0;
  unsigned long long llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_1819_count = 0;
  static  unsigned long long aesl_llvm_cbe_1820_count = 0;
  static  unsigned long long aesl_llvm_cbe_1821_count = 0;
  static  unsigned long long aesl_llvm_cbe_1822_count = 0;
  static  unsigned long long aesl_llvm_cbe_1823_count = 0;
  static  unsigned long long aesl_llvm_cbe_1824_count = 0;
  static  unsigned long long aesl_llvm_cbe_1825_count = 0;
  static  unsigned long long aesl_llvm_cbe_1826_count = 0;
  static  unsigned long long aesl_llvm_cbe_1827_count = 0;
  static  unsigned long long aesl_llvm_cbe_1828_count = 0;
  static  unsigned long long aesl_llvm_cbe_1829_count = 0;
  static  unsigned long long aesl_llvm_cbe_1830_count = 0;
  static  unsigned long long aesl_llvm_cbe_1831_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1646_count = 0;
  unsigned long long llvm_cbe_storemerge1646;
  unsigned long long llvm_cbe_storemerge1646__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1832_count = 0;
  static  unsigned long long aesl_llvm_cbe_1833_count = 0;
  static  unsigned long long aesl_llvm_cbe_1834_count = 0;
  static  unsigned long long aesl_llvm_cbe_1835_count = 0;
  static  unsigned long long aesl_llvm_cbe_1836_count = 0;
  static  unsigned long long aesl_llvm_cbe_1837_count = 0;
  static  unsigned long long aesl_llvm_cbe_1838_count = 0;
  static  unsigned long long aesl_llvm_cbe_1839_count = 0;
  static  unsigned long long aesl_llvm_cbe_1840_count = 0;
  unsigned long long llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_1841_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1742_count = 0;
  unsigned long long llvm_cbe_storemerge1742;
  unsigned long long llvm_cbe_storemerge1742__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1842_count = 0;
  float llvm_cbe_tmp__175;
  float llvm_cbe_tmp__175__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1843_count = 0;
  unsigned long long llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe__2e_sum29_count = 0;
  unsigned long long llvm_cbe__2e_sum29;
  static  unsigned long long aesl_llvm_cbe_1844_count = 0;
  float *llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_1845_count = 0;
  float llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_1846_count = 0;
  float llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_1847_count = 0;
  float llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_1848_count = 0;
  static  unsigned long long aesl_llvm_cbe_1849_count = 0;
  static  unsigned long long aesl_llvm_cbe_1850_count = 0;
  static  unsigned long long aesl_llvm_cbe_1851_count = 0;
  static  unsigned long long aesl_llvm_cbe_1852_count = 0;
  static  unsigned long long aesl_llvm_cbe_1853_count = 0;
  unsigned long long llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_1854_count = 0;
  static  unsigned long long aesl_llvm_cbe_1855_count = 0;
  static  unsigned long long aesl_llvm_cbe_1856_count = 0;
  static  unsigned long long aesl_llvm_cbe_1857_count = 0;
  static  unsigned long long aesl_llvm_cbe_1858_count = 0;
  static  unsigned long long aesl_llvm_cbe_1859_count = 0;
  static  unsigned long long aesl_llvm_cbe_1860_count = 0;
  static  unsigned long long aesl_llvm_cbe_1861_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond125_count = 0;
  static  unsigned long long aesl_llvm_cbe_1862_count = 0;
  static  unsigned long long aesl_llvm_cbe_1863_count = 0;
  float llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_1864_count = 0;
  float llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_1865_count = 0;
  static  unsigned long long aesl_llvm_cbe_1866_count = 0;
  static  unsigned long long aesl_llvm_cbe_1867_count = 0;
  static  unsigned long long aesl_llvm_cbe_1868_count = 0;
  static  unsigned long long aesl_llvm_cbe_1869_count = 0;
  static  unsigned long long aesl_llvm_cbe_1870_count = 0;
  static  unsigned long long aesl_llvm_cbe_1871_count = 0;
  static  unsigned long long aesl_llvm_cbe_1872_count = 0;
  static  unsigned long long aesl_llvm_cbe_1873_count = 0;
  static  unsigned long long aesl_llvm_cbe_1874_count = 0;
  static  unsigned long long aesl_llvm_cbe_1875_count = 0;
  static  unsigned long long aesl_llvm_cbe_1876_count = 0;
  static  unsigned long long aesl_llvm_cbe_1877_count = 0;
  static  unsigned long long aesl_llvm_cbe_1878_count = 0;
  static  unsigned long long aesl_llvm_cbe_1879_count = 0;
  static  unsigned long long aesl_llvm_cbe_1880_count = 0;
  unsigned long long llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_1881_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1837_count = 0;
  unsigned long long llvm_cbe_storemerge1837;
  unsigned long long llvm_cbe_storemerge1837__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1882_count = 0;
  unsigned long long llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe__2e_sum28_count = 0;
  unsigned long long llvm_cbe__2e_sum28;
  static  unsigned long long aesl_llvm_cbe_1883_count = 0;
  float *llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_1884_count = 0;
  float llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_1885_count = 0;
  float llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_1886_count = 0;
  static  unsigned long long aesl_llvm_cbe_1887_count = 0;
  unsigned long long llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_1888_count = 0;
  static  unsigned long long aesl_llvm_cbe_1889_count = 0;
  static  unsigned long long aesl_llvm_cbe_1890_count = 0;
  static  unsigned long long aesl_llvm_cbe_1891_count = 0;
  static  unsigned long long aesl_llvm_cbe_1892_count = 0;
  static  unsigned long long aesl_llvm_cbe_1893_count = 0;
  static  unsigned long long aesl_llvm_cbe_1894_count = 0;
  static  unsigned long long aesl_llvm_cbe_1895_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond123_count = 0;
  static  unsigned long long aesl_llvm_cbe_1896_count = 0;
  static  unsigned long long aesl_llvm_cbe_1897_count = 0;
  unsigned long long llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_1898_count = 0;
  static  unsigned long long aesl_llvm_cbe_1899_count = 0;
  static  unsigned long long aesl_llvm_cbe_1900_count = 0;
  static  unsigned long long aesl_llvm_cbe_1901_count = 0;
  static  unsigned long long aesl_llvm_cbe_1902_count = 0;
  static  unsigned long long aesl_llvm_cbe_1903_count = 0;
  static  unsigned long long aesl_llvm_cbe_1904_count = 0;
  static  unsigned long long aesl_llvm_cbe_1905_count = 0;
  static  unsigned long long aesl_llvm_cbe_1906_count = 0;
  static  unsigned long long aesl_llvm_cbe_1907_count = 0;
  static  unsigned long long aesl_llvm_cbe_1908_count = 0;
  static  unsigned long long aesl_llvm_cbe_1909_count = 0;
  static  unsigned long long aesl_llvm_cbe_1910_count = 0;
  static  unsigned long long aesl_llvm_cbe_1911_count = 0;
  static  unsigned long long aesl_llvm_cbe_1912_count = 0;
  static  unsigned long long aesl_llvm_cbe_1913_count = 0;
  static  unsigned long long aesl_llvm_cbe_1914_count = 0;
  static  unsigned long long aesl_llvm_cbe_1915_count = 0;
  static  unsigned long long aesl_llvm_cbe_1916_count = 0;
  static  unsigned long long aesl_llvm_cbe_1917_count = 0;
  static  unsigned long long aesl_llvm_cbe_1918_count = 0;
  static  unsigned long long aesl_llvm_cbe_1919_count = 0;
  static  unsigned long long aesl_llvm_cbe_1920_count = 0;
  static  unsigned long long aesl_llvm_cbe_1921_count = 0;
  static  unsigned long long aesl_llvm_cbe_1922_count = 0;
  static  unsigned long long aesl_llvm_cbe_1923_count = 0;
  static  unsigned long long aesl_llvm_cbe_1924_count = 0;
  static  unsigned long long aesl_llvm_cbe_1925_count = 0;
  static  unsigned long long aesl_llvm_cbe_1926_count = 0;
  static  unsigned long long aesl_llvm_cbe_1927_count = 0;
  static  unsigned long long aesl_llvm_cbe_1928_count = 0;
  static  unsigned long long aesl_llvm_cbe_1929_count = 0;
  static  unsigned long long aesl_llvm_cbe_1930_count = 0;
  static  unsigned long long aesl_llvm_cbe_1931_count = 0;
  static  unsigned long long aesl_llvm_cbe_1932_count = 0;
  static  unsigned long long aesl_llvm_cbe_1933_count = 0;
  static  unsigned long long aesl_llvm_cbe_1934_count = 0;
  static  unsigned long long aesl_llvm_cbe_1935_count = 0;
  static  unsigned long long aesl_llvm_cbe_1936_count = 0;
  static  unsigned long long aesl_llvm_cbe_1937_count = 0;
  static  unsigned long long aesl_llvm_cbe_1938_count = 0;
  static  unsigned long long aesl_llvm_cbe_1939_count = 0;
  static  unsigned long long aesl_llvm_cbe_1940_count = 0;
  static  unsigned long long aesl_llvm_cbe_1941_count = 0;
  static  unsigned long long aesl_llvm_cbe_1942_count = 0;
  static  unsigned long long aesl_llvm_cbe_1943_count = 0;
  static  unsigned long long aesl_llvm_cbe_1944_count = 0;
  static  unsigned long long aesl_llvm_cbe_1945_count = 0;
  static  unsigned long long aesl_llvm_cbe_1946_count = 0;
  static  unsigned long long aesl_llvm_cbe_1947_count = 0;
  static  unsigned long long aesl_llvm_cbe_1948_count = 0;
  static  unsigned long long aesl_llvm_cbe_1949_count = 0;
  static  unsigned long long aesl_llvm_cbe_1950_count = 0;
  static  unsigned long long aesl_llvm_cbe_1951_count = 0;
  static  unsigned long long aesl_llvm_cbe_1952_count = 0;
  static  unsigned long long aesl_llvm_cbe_1953_count = 0;
  static  unsigned long long aesl_llvm_cbe_1954_count = 0;
  static  unsigned long long aesl_llvm_cbe_1955_count = 0;
  static  unsigned long long aesl_llvm_cbe_1956_count = 0;
  static  unsigned long long aesl_llvm_cbe_1957_count = 0;
  static  unsigned long long aesl_llvm_cbe_1958_count = 0;
  static  unsigned long long aesl_llvm_cbe_1959_count = 0;
  static  unsigned long long aesl_llvm_cbe_1960_count = 0;
  static  unsigned long long aesl_llvm_cbe_1961_count = 0;
  static  unsigned long long aesl_llvm_cbe_1962_count = 0;
  static  unsigned long long aesl_llvm_cbe_1963_count = 0;
  static  unsigned long long aesl_llvm_cbe_1964_count = 0;
  static  unsigned long long aesl_llvm_cbe_1965_count = 0;
  static  unsigned long long aesl_llvm_cbe_1966_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1235_count = 0;
  unsigned long long llvm_cbe_storemerge1235;
  unsigned long long llvm_cbe_storemerge1235__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1967_count = 0;
  static  unsigned long long aesl_llvm_cbe_1968_count = 0;
  static  unsigned long long aesl_llvm_cbe_1969_count = 0;
  static  unsigned long long aesl_llvm_cbe_1970_count = 0;
  static  unsigned long long aesl_llvm_cbe_1971_count = 0;
  static  unsigned long long aesl_llvm_cbe_1972_count = 0;
  static  unsigned long long aesl_llvm_cbe_1973_count = 0;
  unsigned long long llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_1974_count = 0;
  unsigned long long llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_1975_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1332_count = 0;
  unsigned long long llvm_cbe_storemerge1332;
  unsigned long long llvm_cbe_storemerge1332__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1976_count = 0;
  unsigned long long llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_1977_count = 0;
  float *llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_1978_count = 0;
  static  unsigned long long aesl_llvm_cbe_1979_count = 0;
  static  unsigned long long aesl_llvm_cbe_1980_count = 0;
  static  unsigned long long aesl_llvm_cbe_1981_count = 0;
  static  unsigned long long aesl_llvm_cbe_1982_count = 0;
  static  unsigned long long aesl_llvm_cbe_1983_count = 0;
  static  unsigned long long aesl_llvm_cbe_1984_count = 0;
  static  unsigned long long aesl_llvm_cbe_1985_count = 0;
  unsigned long long llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_1986_count = 0;
  static  unsigned long long aesl_llvm_cbe_1987_count = 0;
  float llvm_cbe_tmp__196;
  float llvm_cbe_tmp__196__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1431_count = 0;
  unsigned long long llvm_cbe_storemerge1431;
  unsigned long long llvm_cbe_storemerge1431__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1988_count = 0;
  unsigned long long llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_1989_count = 0;
  float *llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_1990_count = 0;
  float llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_1991_count = 0;
  unsigned long long llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_1992_count = 0;
  float *llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_1993_count = 0;
  float llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_1994_count = 0;
  float llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_1995_count = 0;
  float llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_1996_count = 0;
  static  unsigned long long aesl_llvm_cbe_1997_count = 0;
  unsigned long long llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_1998_count = 0;
  static  unsigned long long aesl_llvm_cbe_1999_count = 0;
  static  unsigned long long aesl_llvm_cbe_2000_count = 0;
  static  unsigned long long aesl_llvm_cbe_2001_count = 0;
  static  unsigned long long aesl_llvm_cbe_2002_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_2003_count = 0;
  static  unsigned long long aesl_llvm_cbe_2004_count = 0;
  unsigned long long llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_2005_count = 0;
  static  unsigned long long aesl_llvm_cbe_2006_count = 0;
  static  unsigned long long aesl_llvm_cbe_2007_count = 0;
  static  unsigned long long aesl_llvm_cbe_2008_count = 0;
  static  unsigned long long aesl_llvm_cbe_2009_count = 0;
  static  unsigned long long aesl_llvm_cbe_2010_count = 0;
  static  unsigned long long aesl_llvm_cbe_2011_count = 0;
  static  unsigned long long aesl_llvm_cbe_2012_count = 0;
  static  unsigned long long aesl_llvm_cbe_2013_count = 0;
  unsigned long long llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_2014_count = 0;
  static  unsigned long long aesl_llvm_cbe_2015_count = 0;
  static  unsigned long long aesl_llvm_cbe_2016_count = 0;
  static  unsigned long long aesl_llvm_cbe_2017_count = 0;
  static  unsigned long long aesl_llvm_cbe_2018_count = 0;
  static  unsigned long long aesl_llvm_cbe_2019_count = 0;
  static  unsigned long long aesl_llvm_cbe_2020_count = 0;
  static  unsigned long long aesl_llvm_cbe_2021_count = 0;
  static  unsigned long long aesl_llvm_cbe_2022_count = 0;
  static  unsigned long long aesl_llvm_cbe_2023_count = 0;
  static  unsigned long long aesl_llvm_cbe_2024_count = 0;
  static  unsigned long long aesl_llvm_cbe_2025_count = 0;
  static  unsigned long long aesl_llvm_cbe_2026_count = 0;
  static  unsigned long long aesl_llvm_cbe_2027_count = 0;
  static  unsigned long long aesl_llvm_cbe_2028_count = 0;
  static  unsigned long long aesl_llvm_cbe_2029_count = 0;
  static  unsigned long long aesl_llvm_cbe_2030_count = 0;
  static  unsigned long long aesl_llvm_cbe_2031_count = 0;
  static  unsigned long long aesl_llvm_cbe_2032_count = 0;
  static  unsigned long long aesl_llvm_cbe_2033_count = 0;
  static  unsigned long long aesl_llvm_cbe_2034_count = 0;
  static  unsigned long long aesl_llvm_cbe_2035_count = 0;
  static  unsigned long long aesl_llvm_cbe_2036_count = 0;
  static  unsigned long long aesl_llvm_cbe_2037_count = 0;
  static  unsigned long long aesl_llvm_cbe_2038_count = 0;
  static  unsigned long long aesl_llvm_cbe_2039_count = 0;
  static  unsigned long long aesl_llvm_cbe_2040_count = 0;
  static  unsigned long long aesl_llvm_cbe_2041_count = 0;
  static  unsigned long long aesl_llvm_cbe_2042_count = 0;
  static  unsigned long long aesl_llvm_cbe_2043_count = 0;
  static  unsigned long long aesl_llvm_cbe_2044_count = 0;
  static  unsigned long long aesl_llvm_cbe_2045_count = 0;
  static  unsigned long long aesl_llvm_cbe_2046_count = 0;
  static  unsigned long long aesl_llvm_cbe_2047_count = 0;
  static  unsigned long long aesl_llvm_cbe_2048_count = 0;
  static  unsigned long long aesl_llvm_cbe_2049_count = 0;
  static  unsigned long long aesl_llvm_cbe_2050_count = 0;
  static  unsigned long long aesl_llvm_cbe_2051_count = 0;
  static  unsigned long long aesl_llvm_cbe_2052_count = 0;
  static  unsigned long long aesl_llvm_cbe_2053_count = 0;
  static  unsigned long long aesl_llvm_cbe_2054_count = 0;
  static  unsigned long long aesl_llvm_cbe_2055_count = 0;
  static  unsigned long long aesl_llvm_cbe_2056_count = 0;
  static  unsigned long long aesl_llvm_cbe_2057_count = 0;
  static  unsigned long long aesl_llvm_cbe_2058_count = 0;
  static  unsigned long long aesl_llvm_cbe_2059_count = 0;
  static  unsigned long long aesl_llvm_cbe_2060_count = 0;
  static  unsigned long long aesl_llvm_cbe_2061_count = 0;
  static  unsigned long long aesl_llvm_cbe_2062_count = 0;
  static  unsigned long long aesl_llvm_cbe_2063_count = 0;
  static  unsigned long long aesl_llvm_cbe_2064_count = 0;
  static  unsigned long long aesl_llvm_cbe_2065_count = 0;
  static  unsigned long long aesl_llvm_cbe_2066_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_dot\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%Ar, i64 0, i32 1, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__50 = (signed long long *)(&llvm_cbe_Ar->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_283_count);
  llvm_cbe_tmp__51 = (unsigned long long )*llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%B, i64 0, i32 1, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_293_count);
  llvm_cbe_tmp__52 = (signed long long *)(&llvm_cbe_B->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_294_count);
  llvm_cbe_tmp__53 = (unsigned long long )*llvm_cbe_tmp__52;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%Ar, i64 0, i32 2, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_308_count);
  llvm_cbe_tmp__54 = (signed long long *)(&llvm_cbe_Ar->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_309_count);
  llvm_cbe_tmp__55 = (unsigned long long )*llvm_cbe_tmp__54;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__55);
  if (((llvm_cbe_tmp__51&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader113;
  } else {
    goto llvm_cbe__2e_preheader115_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader115_2e_lr_2e_ph:
  llvm_cbe_storemerge121__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__56__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader115;

  do {     /* Syntactic loop '.preheader115' to make GCC happy */
llvm_cbe__2e_preheader115:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge121 = phi i64 [ 0, %%.preheader115.lr.ph ], [ %%22, %%20  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge121_count);
  llvm_cbe_storemerge121 = (unsigned long long )llvm_cbe_storemerge121__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge121 = 0x%I64X",llvm_cbe_storemerge121);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__64);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = phi i64 [ 0, %%.preheader115.lr.ph ], [ %%21, %%20  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_371_count);
  llvm_cbe_tmp__56 = (unsigned long long )llvm_cbe_tmp__56__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__56);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__63);
}
  if (((llvm_cbe_naxes&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_thread;
  } else {
    llvm_cbe_storemerge24117__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__57__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph118;
  }

llvm_cbe_tmp__208:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = phi i64 [ %%19, %%.thread ], [ %%9, %%17  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_449_count);
  llvm_cbe_tmp__63 = (unsigned long long )llvm_cbe_tmp__63__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__63);
printf("\n = 0x%I64X",llvm_cbe_tmp__62);
printf("\n = 0x%I64X",llvm_cbe_tmp__56);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add i64 %%storemerge121, 1, !dbg !24 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_450_count);
  llvm_cbe_tmp__64 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge121&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__64&18446744073709551615ull)));
  if (((llvm_cbe_tmp__64&18446744073709551615ULL) == (llvm_cbe_tmp__51&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader113;
  } else {
    llvm_cbe_storemerge121__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__64;   /* for PHI node */
    llvm_cbe_tmp__56__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__63;   /* for PHI node */
    goto llvm_cbe__2e_preheader115;
  }

llvm_cbe_tmp__209:
  if (((llvm_cbe__2e_&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_thread;
  } else {
    llvm_cbe_tmp__63__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__56;   /* for PHI node */
    goto llvm_cbe_tmp__208;
  }

  do {     /* Syntactic loop '.lr.ph118' to make GCC happy */
llvm_cbe__2e_lr_2e_ph118:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge24117 = phi i64 [ %%16, %%.lr.ph118 ], [ 0, %%.preheader115  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge24117_count);
  llvm_cbe_storemerge24117 = (unsigned long long )llvm_cbe_storemerge24117__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge24117 = 0x%I64X",llvm_cbe_storemerge24117);
printf("\n = 0x%I64X",llvm_cbe_tmp__60);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = phi i32 [ %%., %%.lr.ph118 ], [ 0, %%.preheader115  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_429_count);
  llvm_cbe_tmp__57 = (unsigned int )llvm_cbe_tmp__57__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__57);
printf("\n. = 0x%X",llvm_cbe__2e_);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i64* %%axesA, i64 %%storemerge24117, !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_430_count);
  llvm_cbe_tmp__58 = (signed long long *)(&llvm_cbe_axesA[(((signed long long )llvm_cbe_storemerge24117))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge24117 = 0x%I64X",((signed long long )llvm_cbe_storemerge24117));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%13, align 8, !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_431_count);
  llvm_cbe_tmp__59 = (unsigned long long )*llvm_cbe_tmp__58;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%15, i32 1, i32 %%12, !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((((llvm_cbe_storemerge121&18446744073709551615ULL) == (llvm_cbe_tmp__59&18446744073709551615ULL))) ? ((unsigned int )1u) : ((unsigned int )llvm_cbe_tmp__57));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i64 %%storemerge24117, 1, !dbg !26 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_433_count);
  llvm_cbe_tmp__60 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge24117&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__60&18446744073709551615ull)));
  if (((llvm_cbe_tmp__60&18446744073709551615ULL) == (llvm_cbe_naxes&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__209;
  } else {
    llvm_cbe_storemerge24117__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__60;   /* for PHI node */
    llvm_cbe_tmp__57__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph118;
  }

  } while (1); /* end of syntactic loop '.lr.ph118' */
llvm_cbe__2e_thread:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [5 x i64]* %%freeA, i64 0, i64 %%9, !dbg !23 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__61 = (signed long long *)(&llvm_cbe_freeA[(((signed long long )llvm_cbe_tmp__56))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__56));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__56) < 5 && "Write access out of array 'freeA' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%storemerge121, i64* %%18, align 8, !dbg !23 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_441_count);
  *llvm_cbe_tmp__61 = llvm_cbe_storemerge121;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge121 = 0x%I64X\n", llvm_cbe_storemerge121);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%9, 1, !dbg !24 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_442_count);
  llvm_cbe_tmp__62 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__56&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__62&18446744073709551615ull)));
  llvm_cbe_tmp__63__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__62;   /* for PHI node */
  goto llvm_cbe_tmp__208;

  } while (1); /* end of syntactic loop '.preheader115' */
llvm_cbe__2e_preheader113:
  if (((llvm_cbe_tmp__53&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader102;
  } else {
    goto llvm_cbe__2e_preheader107_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader107_2e_lr_2e_ph:
  llvm_cbe_storemerge1114__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__65__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader107;

  do {     /* Syntactic loop '.preheader107' to make GCC happy */
llvm_cbe__2e_preheader107:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1114 = phi i64 [ 0, %%.preheader107.lr.ph ], [ %%35, %%33  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge1114_count);
  llvm_cbe_storemerge1114 = (unsigned long long )llvm_cbe_storemerge1114__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1114 = 0x%I64X",llvm_cbe_storemerge1114);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__73);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = phi i64 [ 0, %%.preheader107.lr.ph ], [ %%34, %%33  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_502_count);
  llvm_cbe_tmp__65 = (unsigned long long )llvm_cbe_tmp__65__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__65);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__72);
}
  if (((llvm_cbe_naxes&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_thread144;
  } else {
    llvm_cbe_storemerge23109__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__66__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph110;
  }

llvm_cbe_tmp__210:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = phi i64 [ %%32, %%.thread144 ], [ %%23, %%30  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_578_count);
  llvm_cbe_tmp__72 = (unsigned long long )llvm_cbe_tmp__72__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__72);
printf("\n = 0x%I64X",llvm_cbe_tmp__71);
printf("\n = 0x%I64X",llvm_cbe_tmp__65);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add i64 %%storemerge1114, 1, !dbg !24 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_579_count);
  llvm_cbe_tmp__73 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1114&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__73&18446744073709551615ull)));
  if (((llvm_cbe_tmp__73&18446744073709551615ULL) == (llvm_cbe_tmp__53&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader102;
  } else {
    llvm_cbe_storemerge1114__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__73;   /* for PHI node */
    llvm_cbe_tmp__65__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__72;   /* for PHI node */
    goto llvm_cbe__2e_preheader107;
  }

llvm_cbe_tmp__211:
  if (((llvm_cbe__2e_27&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_thread144;
  } else {
    llvm_cbe_tmp__72__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__65;   /* for PHI node */
    goto llvm_cbe_tmp__210;
  }

  do {     /* Syntactic loop '.lr.ph110' to make GCC happy */
llvm_cbe__2e_lr_2e_ph110:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23109 = phi i64 [ %%29, %%.lr.ph110 ], [ 0, %%.preheader107  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge23109_count);
  llvm_cbe_storemerge23109 = (unsigned long long )llvm_cbe_storemerge23109__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23109 = 0x%I64X",llvm_cbe_storemerge23109);
printf("\n = 0x%I64X",llvm_cbe_tmp__69);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = phi i32 [ %%.27, %%.lr.ph110 ], [ 0, %%.preheader107  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_558_count);
  llvm_cbe_tmp__66 = (unsigned int )llvm_cbe_tmp__66__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__66);
printf("\n.27 = 0x%X",llvm_cbe__2e_27);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds i64* %%axesB, i64 %%storemerge23109, !dbg !15 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_559_count);
  llvm_cbe_tmp__67 = (signed long long *)(&llvm_cbe_axesB[(((signed long long )llvm_cbe_storemerge23109))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23109 = 0x%I64X",((signed long long )llvm_cbe_storemerge23109));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i64* %%26, align 8, !dbg !15 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_560_count);
  llvm_cbe_tmp__68 = (unsigned long long )*llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%.27 = select i1 %%28, i32 1, i32 %%25, !dbg !15 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe__2e_27_count);
  llvm_cbe__2e_27 = (unsigned int )((((llvm_cbe_storemerge1114&18446744073709551615ULL) == (llvm_cbe_tmp__68&18446744073709551615ULL))) ? ((unsigned int )1u) : ((unsigned int )llvm_cbe_tmp__66));
if (AESL_DEBUG_TRACE)
printf("\n.27 = 0x%X\n", llvm_cbe__2e_27);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i64 %%storemerge23109, 1, !dbg !26 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_562_count);
  llvm_cbe_tmp__69 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23109&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__69&18446744073709551615ull)));
  if (((llvm_cbe_tmp__69&18446744073709551615ULL) == (llvm_cbe_naxes&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__211;
  } else {
    llvm_cbe_storemerge23109__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__69;   /* for PHI node */
    llvm_cbe_tmp__66__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_27;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph110;
  }

  } while (1); /* end of syntactic loop '.lr.ph110' */
llvm_cbe__2e_thread144:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds [5 x i64]* %%freeB, i64 0, i64 %%23, !dbg !24 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_569_count);
  llvm_cbe_tmp__70 = (signed long long *)(&llvm_cbe_freeB[(((signed long long )llvm_cbe_tmp__65))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__65));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__65) < 5 && "Write access out of array 'freeB' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%storemerge1114, i64* %%31, align 8, !dbg !24 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_570_count);
  *llvm_cbe_tmp__70 = llvm_cbe_storemerge1114;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge1114 = 0x%I64X\n", llvm_cbe_storemerge1114);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i64 %%23, 1, !dbg !24 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_571_count);
  llvm_cbe_tmp__71 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__65&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__71&18446744073709551615ull)));
  llvm_cbe_tmp__72__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__71;   /* for PHI node */
  goto llvm_cbe_tmp__210;

  } while (1); /* end of syntactic loop '.preheader107' */
llvm_cbe__2e_preheader102:
  if (((llvm_cbe_naxes&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa103145__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
    llvm_cbe__2e_lcssa97__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge100;
  } else {
    llvm_cbe_storemerge2104__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__74__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph105;
  }

llvm_cbe__2e_preheader96:
  if (((llvm_cbe_naxes&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa103145__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__79;   /* for PHI node */
    llvm_cbe__2e_lcssa97__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge100;
  } else {
    llvm_cbe_storemerge398__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__81__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph99;
  }

  do {     /* Syntactic loop '.lr.ph105' to make GCC happy */
llvm_cbe__2e_lr_2e_ph105:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2104 = phi i64 [ %%42, %%.lr.ph105 ], [ 0, %%.preheader102  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge2104_count);
  llvm_cbe_storemerge2104 = (unsigned long long )llvm_cbe_storemerge2104__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2104 = 0x%I64X",llvm_cbe_storemerge2104);
printf("\n = 0x%I64X",llvm_cbe_tmp__80);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = phi i64 [ %%41, %%.lr.ph105 ], [ 1, %%.preheader102  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_681_count);
  llvm_cbe_tmp__74 = (unsigned long long )llvm_cbe_tmp__74__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__74);
printf("\n = 0x%I64X",llvm_cbe_tmp__79);
printf("\n = 0x%I64X",1ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds i64* %%axesA, i64 %%storemerge2104, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_682_count);
  llvm_cbe_tmp__75 = (signed long long *)(&llvm_cbe_axesA[(((signed long long )llvm_cbe_storemerge2104))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2104 = 0x%I64X",((signed long long )llvm_cbe_storemerge2104));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i64* %%37, align 8, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_683_count);
  llvm_cbe_tmp__76 = (unsigned long long )*llvm_cbe_tmp__75;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds %%struct.k2c_tensor* %%Ar, i64 0, i32 3, i64 %%38, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_684_count);
  llvm_cbe_tmp__77 = (signed long long *)(&llvm_cbe_Ar->field3[(((signed long long )llvm_cbe_tmp__76))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__76));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i64* %%39, align 8, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_685_count);
  llvm_cbe_tmp__78 = (unsigned long long )*llvm_cbe_tmp__77;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = mul i64 %%40, %%36, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_686_count);
  llvm_cbe_tmp__79 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__78&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__74&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__79&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add i64 %%storemerge2104, 1, !dbg !24 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_697_count);
  llvm_cbe_tmp__80 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge2104&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__80&18446744073709551615ull)));
  if (((llvm_cbe_tmp__80&18446744073709551615ULL) == (llvm_cbe_naxes&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader96;
  } else {
    llvm_cbe_storemerge2104__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__80;   /* for PHI node */
    llvm_cbe_tmp__74__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__79;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph105;
  }

  } while (1); /* end of syntactic loop '.lr.ph105' */
  do {     /* Syntactic loop '.lr.ph99' to make GCC happy */
llvm_cbe__2e_lr_2e_ph99:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge398 = phi i64 [ %%49, %%.lr.ph99 ], [ 0, %%.preheader96  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge398_count);
  llvm_cbe_storemerge398 = (unsigned long long )llvm_cbe_storemerge398__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge398 = 0x%I64X",llvm_cbe_storemerge398);
printf("\n = 0x%I64X",llvm_cbe_tmp__87);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = phi i64 [ %%48, %%.lr.ph99 ], [ 1, %%.preheader96  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_749_count);
  llvm_cbe_tmp__81 = (unsigned long long )llvm_cbe_tmp__81__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__81);
printf("\n = 0x%I64X",llvm_cbe_tmp__86);
printf("\n = 0x%I64X",1ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds i64* %%axesB, i64 %%storemerge398, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_750_count);
  llvm_cbe_tmp__82 = (signed long long *)(&llvm_cbe_axesB[(((signed long long )llvm_cbe_storemerge398))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge398 = 0x%I64X",((signed long long )llvm_cbe_storemerge398));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i64* %%44, align 8, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_751_count);
  llvm_cbe_tmp__83 = (unsigned long long )*llvm_cbe_tmp__82;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds %%struct.k2c_tensor* %%B, i64 0, i32 3, i64 %%45, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_752_count);
  llvm_cbe_tmp__84 = (signed long long *)(&llvm_cbe_B->field3[(((signed long long )llvm_cbe_tmp__83))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__83));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i64* %%46, align 8, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_753_count);
  llvm_cbe_tmp__85 = (unsigned long long )*llvm_cbe_tmp__84;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = mul i64 %%47, %%43, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_754_count);
  llvm_cbe_tmp__86 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__85&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__81&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__86&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add i64 %%storemerge398, 1, !dbg !24 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_760_count);
  llvm_cbe_tmp__87 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge398&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__87&18446744073709551615ull)));
  if (((llvm_cbe_tmp__87&18446744073709551615ULL) == (llvm_cbe_naxes&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa103145__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__79;   /* for PHI node */
    llvm_cbe__2e_lcssa97__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__86;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge100;
  } else {
    llvm_cbe_storemerge398__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__87;   /* for PHI node */
    llvm_cbe_tmp__81__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__86;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph99;
  }

  } while (1); /* end of syntactic loop '.lr.ph99' */
llvm_cbe__2e__crit_edge100:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa103145 = phi i64 [ %%41, %%.preheader96 ], [ %%41, %%.lr.ph99 ], [ 1, %%.preheader102  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe__2e_lcssa103145_count);
  llvm_cbe__2e_lcssa103145 = (unsigned long long )llvm_cbe__2e_lcssa103145__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa103145 = 0x%I64X",llvm_cbe__2e_lcssa103145);
printf("\n = 0x%I64X",llvm_cbe_tmp__79);
printf("\n = 0x%I64X",llvm_cbe_tmp__79);
printf("\n = 0x%I64X",1ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa97 = phi i64 [ 1, %%.preheader96 ], [ %%48, %%.lr.ph99 ], [ 1, %%.preheader102  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe__2e_lcssa97_count);
  llvm_cbe__2e_lcssa97 = (unsigned long long )llvm_cbe__2e_lcssa97__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa97 = 0x%I64X",llvm_cbe__2e_lcssa97);
printf("\n = 0x%I64X",1ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__86);
printf("\n = 0x%I64X",1ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = udiv i64 %%6, %%.lcssa103145, !dbg !12 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_812_count);
  llvm_cbe_tmp__88 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__55&18446744073709551615ull)) / ((unsigned long long )(llvm_cbe__2e_lcssa103145&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__88&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds %%struct.k2c_tensor* %%B, i64 0, i32 2, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_816_count);
  llvm_cbe_tmp__89 = (signed long long *)(&llvm_cbe_B->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i64* %%51, align 8, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_817_count);
  llvm_cbe_tmp__90 = (unsigned long long )*llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = udiv i64 %%52, %%.lcssa97, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_818_count);
  llvm_cbe_tmp__91 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__90&18446744073709551615ull)) / ((unsigned long long )(llvm_cbe__2e_lcssa97&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__91&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = sub i64 %%2, %%naxes, !dbg !17 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_878_count);
  llvm_cbe_tmp__92 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__51&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_naxes&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__92&18446744073709551615ull)));
  if (((llvm_cbe_tmp__51&18446744073709551615ULL) == (llvm_cbe_naxes&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader87;
  } else {
    llvm_cbe_storemerge492__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph94;
  }

llvm_cbe__2e_preheader87:
  if ((((unsigned long long )llvm_cbe_tmp__92&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__51&18446744073709551615ULL))) {
    llvm_cbe_storemerge589__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_storemerge122688__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__92;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph90;
  } else {
    goto llvm_cbe__2e_preheader84;
  }

  do {     /* Syntactic loop '.lr.ph94' to make GCC happy */
llvm_cbe__2e_lr_2e_ph94:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge492 = phi i64 [ %%60, %%.lr.ph94 ], [ 0, %%._crit_edge100  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge492_count);
  llvm_cbe_storemerge492 = (unsigned long long )llvm_cbe_storemerge492__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge492 = 0x%I64X",llvm_cbe_storemerge492);
printf("\n = 0x%I64X",llvm_cbe_tmp__96);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds [5 x i64]* %%freeA, i64 0, i64 %%storemerge492, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_887_count);
  llvm_cbe_tmp__93 = (signed long long *)(&llvm_cbe_freeA[(((signed long long )llvm_cbe_storemerge492))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge492 = 0x%I64X",((signed long long )llvm_cbe_storemerge492));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_storemerge492) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'freeA' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = load i64* %%57, align 8, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_888_count);
  llvm_cbe_tmp__94 = (unsigned long long )*llvm_cbe_tmp__93;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = getelementptr inbounds [5 x i64]* %%permA, i64 0, i64 %%storemerge492, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_889_count);
  llvm_cbe_tmp__95 = (signed long long *)(&llvm_cbe_permA[(((signed long long )llvm_cbe_storemerge492))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge492 = 0x%I64X",((signed long long )llvm_cbe_storemerge492));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_storemerge492) < 5 && "Write access out of array 'permA' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%58, i64* %%59, align 8, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_890_count);
  *llvm_cbe_tmp__95 = llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = add i64 %%storemerge492, 1, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_891_count);
  llvm_cbe_tmp__96 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge492&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__96&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__92&18446744073709551615ULL))) {
    llvm_cbe_storemerge492__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__96;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph94;
  } else {
    goto llvm_cbe__2e_preheader87;
  }

  } while (1); /* end of syntactic loop '.lr.ph94' */
llvm_cbe__2e_preheader84:
  if (((llvm_cbe_naxes&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader80;
  } else {
    llvm_cbe_storemerge685__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph86;
  }

  do {     /* Syntactic loop '.lr.ph90' to make GCC happy */
llvm_cbe__2e_lr_2e_ph90:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge589 = phi i64 [ %%66, %%.lr.ph90 ], [ 0, %%.preheader87  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge589_count);
  llvm_cbe_storemerge589 = (unsigned long long )llvm_cbe_storemerge589__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge589 = 0x%I64X",llvm_cbe_storemerge589);
printf("\n = 0x%I64X",llvm_cbe_tmp__101);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge122688 = phi i64 [ %%65, %%.lr.ph90 ], [ %%54, %%.preheader87  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge122688_count);
  llvm_cbe_storemerge122688 = (unsigned long long )llvm_cbe_storemerge122688__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge122688 = 0x%I64X",llvm_cbe_storemerge122688);
printf("\n = 0x%I64X",llvm_cbe_tmp__100);
printf("\n = 0x%I64X",llvm_cbe_tmp__92);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = getelementptr inbounds i64* %%axesA, i64 %%storemerge589, !dbg !15 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1044_count);
  llvm_cbe_tmp__97 = (signed long long *)(&llvm_cbe_axesA[(((signed long long )llvm_cbe_storemerge589))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge589 = 0x%I64X",((signed long long )llvm_cbe_storemerge589));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i64* %%62, align 8, !dbg !15 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1045_count);
  llvm_cbe_tmp__98 = (unsigned long long )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds [5 x i64]* %%permA, i64 0, i64 %%storemerge122688, !dbg !15 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1046_count);
  llvm_cbe_tmp__99 = (signed long long *)(&llvm_cbe_permA[(((signed long long )llvm_cbe_storemerge122688))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge122688 = 0x%I64X",((signed long long )llvm_cbe_storemerge122688));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_storemerge122688) < 5 && "Write access out of array 'permA' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%63, i64* %%64, align 8, !dbg !15 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1047_count);
  *llvm_cbe_tmp__99 = llvm_cbe_tmp__98;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = add i64 %%storemerge122688, 1, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1048_count);
  llvm_cbe_tmp__100 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge122688&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__100&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = add i64 %%storemerge589, 1, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1099_count);
  llvm_cbe_tmp__101 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge589&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__101&18446744073709551615ull)));
  if (((llvm_cbe_tmp__101&18446744073709551615ULL) == (llvm_cbe_naxes&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader84;
  } else {
    llvm_cbe_storemerge589__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__101;   /* for PHI node */
    llvm_cbe_storemerge122688__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__100;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph90;
  }

  } while (1); /* end of syntactic loop '.lr.ph90' */
llvm_cbe__2e_preheader80:
  if ((((unsigned long long )llvm_cbe_tmp__53&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_naxes&18446744073709551615ULL))) {
    goto llvm_cbe__2e_lr_2e_ph83;
  } else {
    goto llvm_cbe__2e_preheader77;
  }

llvm_cbe__2e_lr_2e_ph83:
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = sub i64 %%4, %%naxes, !dbg !17 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1112_count);
  llvm_cbe_tmp__102 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__53&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_naxes&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__102&18446744073709551615ull)));
  llvm_cbe_storemerge782__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_storemerge122581__PHI_TEMPORARY = (unsigned long long )llvm_cbe_naxes;   /* for PHI node */
  goto llvm_cbe_tmp__212;

  do {     /* Syntactic loop '.lr.ph86' to make GCC happy */
llvm_cbe__2e_lr_2e_ph86:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge685 = phi i64 [ %%72, %%.lr.ph86 ], [ 0, %%.preheader84  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge685_count);
  llvm_cbe_storemerge685 = (unsigned long long )llvm_cbe_storemerge685__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge685 = 0x%I64X",llvm_cbe_storemerge685);
printf("\n = 0x%I64X",llvm_cbe_tmp__106);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = getelementptr inbounds i64* %%axesB, i64 %%storemerge685, !dbg !16 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1114_count);
  llvm_cbe_tmp__103 = (signed long long *)(&llvm_cbe_axesB[(((signed long long )llvm_cbe_storemerge685))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge685 = 0x%I64X",((signed long long )llvm_cbe_storemerge685));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load i64* %%69, align 8, !dbg !16 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1115_count);
  llvm_cbe_tmp__104 = (unsigned long long )*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds [5 x i64]* %%permB, i64 0, i64 %%storemerge685, !dbg !16 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1116_count);
  llvm_cbe_tmp__105 = (signed long long *)(&llvm_cbe_permB[(((signed long long )llvm_cbe_storemerge685))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge685 = 0x%I64X",((signed long long )llvm_cbe_storemerge685));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_storemerge685) < 5 && "Write access out of array 'permB' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%70, i64* %%71, align 8, !dbg !16 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1117_count);
  *llvm_cbe_tmp__105 = llvm_cbe_tmp__104;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = add i64 %%storemerge685, 1, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1118_count);
  llvm_cbe_tmp__106 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge685&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__106&18446744073709551615ull)));
  if (((llvm_cbe_tmp__106&18446744073709551615ULL) == (llvm_cbe_naxes&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader80;
  } else {
    llvm_cbe_storemerge685__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__106;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph86;
  }

  } while (1); /* end of syntactic loop '.lr.ph86' */
llvm_cbe__2e_preheader77:
  if (((llvm_cbe_tmp__51&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader74;
  } else {
    llvm_cbe_storemerge878__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph79;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__212:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge782 = phi i64 [ 0, %%.lr.ph83 ], [ %%78, %%73  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge782_count);
  llvm_cbe_storemerge782 = (unsigned long long )llvm_cbe_storemerge782__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge782 = 0x%I64X",llvm_cbe_storemerge782);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__111);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge122581 = phi i64 [ %%naxes, %%.lr.ph83 ], [ %%77, %%73  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge122581_count);
  llvm_cbe_storemerge122581 = (unsigned long long )llvm_cbe_storemerge122581__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge122581 = 0x%I64X",llvm_cbe_storemerge122581);
printf("\nnaxes = 0x%I64X",llvm_cbe_naxes);
printf("\n = 0x%I64X",llvm_cbe_tmp__110);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = getelementptr inbounds [5 x i64]* %%freeB, i64 0, i64 %%storemerge782, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1220_count);
  llvm_cbe_tmp__107 = (signed long long *)(&llvm_cbe_freeB[(((signed long long )llvm_cbe_storemerge782))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge782 = 0x%I64X",((signed long long )llvm_cbe_storemerge782));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_storemerge782) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'freeB' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = load i64* %%74, align 8, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1221_count);
  llvm_cbe_tmp__108 = (unsigned long long )*llvm_cbe_tmp__107;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = getelementptr inbounds [5 x i64]* %%permB, i64 0, i64 %%storemerge122581, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1222_count);
  llvm_cbe_tmp__109 = (signed long long *)(&llvm_cbe_permB[(((signed long long )llvm_cbe_storemerge122581))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge122581 = 0x%I64X",((signed long long )llvm_cbe_storemerge122581));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_storemerge122581) < 5 && "Write access out of array 'permB' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%75, i64* %%76, align 8, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1223_count);
  *llvm_cbe_tmp__109 = llvm_cbe_tmp__108;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = add i64 %%storemerge122581, 1, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1224_count);
  llvm_cbe_tmp__110 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge122581&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__110&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = add i64 %%storemerge782, 1, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1275_count);
  llvm_cbe_tmp__111 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge782&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__111&18446744073709551615ull)));
  if (((llvm_cbe_tmp__111&18446744073709551615ULL) == (llvm_cbe_tmp__102&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader77;
  } else {
    llvm_cbe_storemerge782__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__111;   /* for PHI node */
    llvm_cbe_storemerge122581__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__110;   /* for PHI node */
    goto llvm_cbe_tmp__212;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader74:
  if (((llvm_cbe_tmp__53&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader71;
  } else {
    llvm_cbe_storemerge975__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph76;
  }

  do {     /* Syntactic loop '.lr.ph79' to make GCC happy */
llvm_cbe__2e_lr_2e_ph79:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge878 = phi i64 [ %%84, %%.lr.ph79 ], [ 0, %%.preheader77  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge878_count);
  llvm_cbe_storemerge878 = (unsigned long long )llvm_cbe_storemerge878__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge878 = 0x%I64X",llvm_cbe_storemerge878);
printf("\n = 0x%I64X",llvm_cbe_tmp__117);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds [5 x i64]* %%permA, i64 0, i64 %%storemerge878, !dbg !12 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1332_count);
  llvm_cbe_tmp__112 = (signed long long *)(&llvm_cbe_permA[(((signed long long )llvm_cbe_storemerge878))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge878 = 0x%I64X",((signed long long )llvm_cbe_storemerge878));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_storemerge878) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'permA' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load i64* %%79, align 8, !dbg !12 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1333_count);
  llvm_cbe_tmp__113 = (unsigned long long )*llvm_cbe_tmp__112;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = getelementptr inbounds %%struct.k2c_tensor* %%Ar, i64 0, i32 3, i64 %%80, !dbg !12 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1334_count);
  llvm_cbe_tmp__114 = (signed long long *)(&llvm_cbe_Ar->field3[(((signed long long )llvm_cbe_tmp__113))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__113));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = load i64* %%81, align 8, !dbg !12 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1335_count);
  llvm_cbe_tmp__115 = (unsigned long long )*llvm_cbe_tmp__114;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = getelementptr inbounds [5 x i64]* %%newshpA, i64 0, i64 %%storemerge878, !dbg !12 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1336_count);
  llvm_cbe_tmp__116 = (signed long long *)(&llvm_cbe_newshpA[(((signed long long )llvm_cbe_storemerge878))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge878 = 0x%I64X",((signed long long )llvm_cbe_storemerge878));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_storemerge878) < 5 && "Write access out of array 'newshpA' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%82, i64* %%83, align 8, !dbg !12 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1337_count);
  *llvm_cbe_tmp__116 = llvm_cbe_tmp__115;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = add i64 %%storemerge878, 1, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1338_count);
  llvm_cbe_tmp__117 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge878&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__117&18446744073709551615ull)));
  if (((llvm_cbe_tmp__117&18446744073709551615ULL) == (llvm_cbe_tmp__51&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader74;
  } else {
    llvm_cbe_storemerge878__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__117;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph79;
  }

  } while (1); /* end of syntactic loop '.lr.ph79' */
llvm_cbe__2e_preheader71:
  if (((llvm_cbe_tmp__55&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader63;
  } else {
    goto llvm_cbe__2e_lr_2e_ph73;
  }

llvm_cbe__2e_lr_2e_ph73:
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = getelementptr inbounds [5 x i64]* %%Asub, i64 0, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1441_count);
  llvm_cbe_tmp__118 = (signed long long *)(&llvm_cbe_Asub[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = getelementptr inbounds %%struct.k2c_tensor* %%Ar, i64 0, i32 3, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1442_count);
  llvm_cbe_tmp__119 = (signed long long *)(&llvm_cbe_Ar->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = getelementptr inbounds [5 x i64]* %%Bsub, i64 0, i64 0, !dbg !22 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1443_count);
  llvm_cbe_tmp__120 = (signed long long *)(&llvm_cbe_Bsub[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = getelementptr inbounds [5 x i64]* %%newshpA, i64 0, i64 0, !dbg !22 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1444_count);
  llvm_cbe_tmp__121 = (signed long long *)(&llvm_cbe_newshpA[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1072__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__213;

  do {     /* Syntactic loop '.lr.ph76' to make GCC happy */
llvm_cbe__2e_lr_2e_ph76:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge975 = phi i64 [ %%95, %%.lr.ph76 ], [ 0, %%.preheader74  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge975_count);
  llvm_cbe_storemerge975 = (unsigned long long )llvm_cbe_storemerge975__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge975 = 0x%I64X",llvm_cbe_storemerge975);
printf("\n = 0x%I64X",llvm_cbe_tmp__127);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = getelementptr inbounds [5 x i64]* %%permB, i64 0, i64 %%storemerge975, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1446_count);
  llvm_cbe_tmp__122 = (signed long long *)(&llvm_cbe_permB[(((signed long long )llvm_cbe_storemerge975))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge975 = 0x%I64X",((signed long long )llvm_cbe_storemerge975));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_storemerge975) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'permB' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = load i64* %%90, align 8, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1447_count);
  llvm_cbe_tmp__123 = (unsigned long long )*llvm_cbe_tmp__122;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = getelementptr inbounds %%struct.k2c_tensor* %%B, i64 0, i32 3, i64 %%91, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1448_count);
  llvm_cbe_tmp__124 = (signed long long *)(&llvm_cbe_B->field3[(((signed long long )llvm_cbe_tmp__123))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__123));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = load i64* %%92, align 8, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1449_count);
  llvm_cbe_tmp__125 = (unsigned long long )*llvm_cbe_tmp__124;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__125);
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = getelementptr inbounds [5 x i64]* %%newshpB, i64 0, i64 %%storemerge975, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1450_count);
  llvm_cbe_tmp__126 = (signed long long *)(&llvm_cbe_newshpB[(((signed long long )llvm_cbe_storemerge975))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge975 = 0x%I64X",((signed long long )llvm_cbe_storemerge975));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_storemerge975) < 5 && "Write access out of array 'newshpB' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%93, i64* %%94, align 8, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1451_count);
  *llvm_cbe_tmp__126 = llvm_cbe_tmp__125;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__125);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = add i64 %%storemerge975, 1, !dbg !25 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1452_count);
  llvm_cbe_tmp__127 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge975&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__127&18446744073709551615ull)));
  if (((llvm_cbe_tmp__127&18446744073709551615ULL) == (llvm_cbe_tmp__53&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader71;
  } else {
    llvm_cbe_storemerge975__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__127;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph76;
  }

  } while (1); /* end of syntactic loop '.lr.ph76' */
llvm_cbe__2e_preheader63:
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = load i64* %%51, align 8, !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1553_count);
  llvm_cbe_tmp__128 = (unsigned long long )*llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__128);
  if (((llvm_cbe_tmp__128&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge66;
  } else {
    goto llvm_cbe__2e_lr_2e_ph65;
  }

llvm_cbe__2e_lr_2e_ph65:
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = getelementptr inbounds [5 x i64]* %%Bsub, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1556_count);
  llvm_cbe_tmp__129 = (signed long long *)(&llvm_cbe_Bsub[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = getelementptr inbounds %%struct.k2c_tensor* %%B, i64 0, i32 3, i64 0, !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1557_count);
  llvm_cbe_tmp__130 = (signed long long *)(&llvm_cbe_B->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = getelementptr inbounds [5 x i64]* %%Asub, i64 0, i64 0, !dbg !23 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1558_count);
  llvm_cbe_tmp__131 = (signed long long *)(&llvm_cbe_Asub[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = getelementptr inbounds [5 x i64]* %%newshpB, i64 0, i64 0, !dbg !23 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1559_count);
  llvm_cbe_tmp__132 = (signed long long *)(&llvm_cbe_newshpB[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1164__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__214;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__213:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1072 = phi i64 [ 0, %%.lr.ph73 ], [ %%113, %%._crit_edge70  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge1072_count);
  llvm_cbe_storemerge1072 = (unsigned long long )llvm_cbe_storemerge1072__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1072 = 0x%I64X",llvm_cbe_storemerge1072);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__143);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @k2c_idx2sub(i64 %%storemerge1072, i64* %%86, i64* %%87, i64 %%2), !dbg !12 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1561_count);
  k2c_idx2sub(llvm_cbe_storemerge1072, (signed long long *)llvm_cbe_tmp__118, (signed long long *)llvm_cbe_tmp__119, llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge1072 = 0x%I64X",llvm_cbe_storemerge1072);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__51);
}
  if (((llvm_cbe_tmp__51&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge70;
  } else {
    llvm_cbe_storemerge2267__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph69;
  }

llvm_cbe__2e__crit_edge70:
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = call i64 @k2c_sub2idx(i64* %%88, i64* %%89, i64 %%2), !dbg !22 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1581_count);
  llvm_cbe_tmp__139 = (unsigned long long )k2c_sub2idx((signed long long *)llvm_cbe_tmp__120, (signed long long *)llvm_cbe_tmp__121, llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__51);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__139);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = getelementptr inbounds %%struct.k2c_tensor* %%Ar, i64 0, i32 0, i64 %%storemerge1072, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1583_count);
  llvm_cbe_tmp__140 = (float *)(&llvm_cbe_Ar->field0[(((signed long long )llvm_cbe_storemerge1072))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1072 = 0x%I64X",((signed long long )llvm_cbe_storemerge1072));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = load float* %%110, align 4, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1584_count);
  llvm_cbe_tmp__141 = (float )*llvm_cbe_tmp__140;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__141, *(int*)(&llvm_cbe_tmp__141));
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = getelementptr inbounds float* %%fwork, i64 %%109, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1586_count);
  llvm_cbe_tmp__142 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__139))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__139));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%111, float* %%112, align 4, !dbg !13 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1587_count);
  *llvm_cbe_tmp__142 = llvm_cbe_tmp__141;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__141);
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = add i64 %%storemerge1072, 1, !dbg !26 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1588_count);
  llvm_cbe_tmp__143 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1072&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__143&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = load i64* %%5, align 8, !dbg !12 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1639_count);
  llvm_cbe_tmp__144 = (unsigned long long )*llvm_cbe_tmp__54;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__144);
  if ((((unsigned long long )llvm_cbe_tmp__143&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__144&18446744073709551615ULL))) {
    llvm_cbe_storemerge1072__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__143;   /* for PHI node */
    goto llvm_cbe_tmp__213;
  } else {
    goto llvm_cbe__2e_preheader63;
  }

  do {     /* Syntactic loop '.lr.ph69' to make GCC happy */
llvm_cbe__2e_lr_2e_ph69:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2267 = phi i64 [ %%108, %%.lr.ph69 ], [ 0, %%102  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge2267_count);
  llvm_cbe_storemerge2267 = (unsigned long long )llvm_cbe_storemerge2267__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2267 = 0x%I64X",llvm_cbe_storemerge2267);
printf("\n = 0x%I64X",llvm_cbe_tmp__138);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = getelementptr inbounds [5 x i64]* %%permA, i64 0, i64 %%storemerge2267, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1568_count);
  llvm_cbe_tmp__133 = (signed long long *)(&llvm_cbe_permA[(((signed long long )llvm_cbe_storemerge2267))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2267 = 0x%I64X",((signed long long )llvm_cbe_storemerge2267));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_storemerge2267) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'permA' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = load i64* %%103, align 8, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1569_count);
  llvm_cbe_tmp__134 = (unsigned long long )*llvm_cbe_tmp__133;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__134);
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = getelementptr inbounds [5 x i64]* %%Asub, i64 0, i64 %%104, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1570_count);
  llvm_cbe_tmp__135 = (signed long long *)(&llvm_cbe_Asub[(((signed long long )llvm_cbe_tmp__134))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__134));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__134) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'Asub' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = load i64* %%105, align 8, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1571_count);
  llvm_cbe_tmp__136 = (unsigned long long )*llvm_cbe_tmp__135;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__136);
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = getelementptr inbounds [5 x i64]* %%Bsub, i64 0, i64 %%storemerge2267, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1572_count);
  llvm_cbe_tmp__137 = (signed long long *)(&llvm_cbe_Bsub[(((signed long long )llvm_cbe_storemerge2267))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2267 = 0x%I64X",((signed long long )llvm_cbe_storemerge2267));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_storemerge2267) < 5 && "Write access out of array 'Bsub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%106, i64* %%107, align 8, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1573_count);
  *llvm_cbe_tmp__137 = llvm_cbe_tmp__136;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__136);
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = add i64 %%storemerge2267, 1, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1574_count);
  llvm_cbe_tmp__138 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge2267&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__138&18446744073709551615ull)));
  if (((llvm_cbe_tmp__138&18446744073709551615ULL) == (llvm_cbe_tmp__51&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge70;
  } else {
    llvm_cbe_storemerge2267__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__138;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph69;
  }

  } while (1); /* end of syntactic loop '.lr.ph69' */
  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__214:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1164 = phi i64 [ 0, %%.lr.ph65 ], [ %%127, %%._crit_edge62  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge1164_count);
  llvm_cbe_storemerge1164 = (unsigned long long )llvm_cbe_storemerge1164__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1164 = 0x%I64X",llvm_cbe_storemerge1164);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__155);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @k2c_idx2sub(i64 %%storemerge1164, i64* %%98, i64* %%99, i64 %%4), !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1642_count);
  k2c_idx2sub(llvm_cbe_storemerge1164, (signed long long *)llvm_cbe_tmp__129, (signed long long *)llvm_cbe_tmp__130, llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge1164 = 0x%I64X",llvm_cbe_storemerge1164);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__53);
}
  if (((llvm_cbe_tmp__53&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge62;
  } else {
    llvm_cbe_storemerge2159__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph61;
  }

llvm_cbe__2e__crit_edge62:
if (AESL_DEBUG_TRACE)
printf("\n  %%123 = call i64 @k2c_sub2idx(i64* %%100, i64* %%101, i64 %%4), !dbg !23 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1662_count);
  llvm_cbe_tmp__151 = (unsigned long long )k2c_sub2idx((signed long long *)llvm_cbe_tmp__131, (signed long long *)llvm_cbe_tmp__132, llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__53);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__151);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%124 = getelementptr inbounds %%struct.k2c_tensor* %%B, i64 0, i32 0, i64 %%storemerge1164, !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1664_count);
  llvm_cbe_tmp__152 = (float *)(&llvm_cbe_B->field0[(((signed long long )llvm_cbe_storemerge1164))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1164 = 0x%I64X",((signed long long )llvm_cbe_storemerge1164));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%125 = load float* %%124, align 4, !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1665_count);
  llvm_cbe_tmp__153 = (float )*llvm_cbe_tmp__152;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__153, *(int*)(&llvm_cbe_tmp__153));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum30 = add i64 %%123, %%6, !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe__2e_sum30_count);
  llvm_cbe__2e_sum30 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__151&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__55&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum30 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum30&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%126 = getelementptr inbounds float* %%fwork, i64 %%.sum30, !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1667_count);
  llvm_cbe_tmp__154 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum30))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum30 = 0x%I64X",((signed long long )llvm_cbe__2e_sum30));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%125, float* %%126, align 4, !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1668_count);
  *llvm_cbe_tmp__154 = llvm_cbe_tmp__153;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__153);
if (AESL_DEBUG_TRACE)
printf("\n  %%127 = add i64 %%storemerge1164, 1, !dbg !26 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1669_count);
  llvm_cbe_tmp__155 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1164&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__155&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%128 = load i64* %%51, align 8, !dbg !14 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1720_count);
  llvm_cbe_tmp__156 = (unsigned long long )*llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__156);
  if ((((unsigned long long )llvm_cbe_tmp__155&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__156&18446744073709551615ULL))) {
    llvm_cbe_storemerge1164__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__155;   /* for PHI node */
    goto llvm_cbe_tmp__214;
  } else {
    goto llvm_cbe__2e__crit_edge66;
  }

  do {     /* Syntactic loop '.lr.ph61' to make GCC happy */
llvm_cbe__2e_lr_2e_ph61:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2159 = phi i64 [ %%122, %%.lr.ph61 ], [ 0, %%116  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge2159_count);
  llvm_cbe_storemerge2159 = (unsigned long long )llvm_cbe_storemerge2159__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2159 = 0x%I64X",llvm_cbe_storemerge2159);
printf("\n = 0x%I64X",llvm_cbe_tmp__150);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%117 = getelementptr inbounds [5 x i64]* %%permB, i64 0, i64 %%storemerge2159, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1649_count);
  llvm_cbe_tmp__145 = (signed long long *)(&llvm_cbe_permB[(((signed long long )llvm_cbe_storemerge2159))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2159 = 0x%I64X",((signed long long )llvm_cbe_storemerge2159));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_storemerge2159) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'permB' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%118 = load i64* %%117, align 8, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1650_count);
  llvm_cbe_tmp__146 = (unsigned long long )*llvm_cbe_tmp__145;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__146);
if (AESL_DEBUG_TRACE)
printf("\n  %%119 = getelementptr inbounds [5 x i64]* %%Bsub, i64 0, i64 %%118, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1651_count);
  llvm_cbe_tmp__147 = (signed long long *)(&llvm_cbe_Bsub[(((signed long long )llvm_cbe_tmp__146))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__146));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__146) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'Bsub' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%120 = load i64* %%119, align 8, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1652_count);
  llvm_cbe_tmp__148 = (unsigned long long )*llvm_cbe_tmp__147;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__148);
if (AESL_DEBUG_TRACE)
printf("\n  %%121 = getelementptr inbounds [5 x i64]* %%Asub, i64 0, i64 %%storemerge2159, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1653_count);
  llvm_cbe_tmp__149 = (signed long long *)(&llvm_cbe_Asub[(((signed long long )llvm_cbe_storemerge2159))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2159 = 0x%I64X",((signed long long )llvm_cbe_storemerge2159));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_storemerge2159) < 5 && "Write access out of array 'Asub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%120, i64* %%121, align 8, !dbg !28 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1654_count);
  *llvm_cbe_tmp__149 = llvm_cbe_tmp__148;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__148);
if (AESL_DEBUG_TRACE)
printf("\n  %%122 = add i64 %%storemerge2159, 1, !dbg !29 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1655_count);
  llvm_cbe_tmp__150 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge2159&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__150&18446744073709551615ull)));
  if (((llvm_cbe_tmp__150&18446744073709551615ULL) == (llvm_cbe_tmp__53&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge62;
  } else {
    llvm_cbe_storemerge2159__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__150;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph61;
  }

  } while (1); /* end of syntactic loop '.lr.ph61' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge66:
  if (((llvm_cbe_normalize&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__215;
  } else {
    goto llvm_cbe__2e_preheader57;
  }

llvm_cbe__2e_preheader57:
  if (((llvm_cbe_tmp__88&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader45;
  } else {
    goto llvm_cbe__2e_preheader51_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader51_2e_lr_2e_ph:
  llvm_cbe_storemerge1558__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader51;

  do {     /* Syntactic loop '.preheader51' to make GCC happy */
llvm_cbe__2e_preheader51:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1558 = phi i64 [ 0, %%.preheader51.lr.ph ], [ %%153, %%._crit_edge50  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge1558_count);
  llvm_cbe_storemerge1558 = (unsigned long long )llvm_cbe_storemerge1558__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1558 = 0x%I64X",llvm_cbe_storemerge1558);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__173);
}
  if (((llvm_cbe__2e_lcssa103145&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge50;
  } else {
    goto llvm_cbe__2e_lr_2e_ph54;
  }

llvm_cbe__2e__crit_edge50:
if (AESL_DEBUG_TRACE)
printf("\n  %%153 = add i64 %%storemerge1558, 1, !dbg !29 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1818_count);
  llvm_cbe_tmp__173 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1558&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__173&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__173&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__88&18446744073709551615ULL))) {
    llvm_cbe_storemerge1558__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__173;   /* for PHI node */
    goto llvm_cbe__2e_preheader51;
  } else {
    goto llvm_cbe__2e_preheader45;
  }

llvm_cbe__2e__crit_edge55:
if (AESL_DEBUG_TRACE)
printf("\n  %%144 = call float @sqrtf(float %%142) nounwind readnone, !dbg !30 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1784_count);
  llvm_cbe_tmp__165 = (float )sqrtf(llvm_cbe_tmp__163);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__163, *(int*)(&llvm_cbe_tmp__163));
printf("\nReturn  = %f",llvm_cbe_tmp__165);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%145 = fdiv float 1.000000e+00, %%144, !dbg !30 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1785_count);
  llvm_cbe_tmp__166 = (float )((float )(0x1p0 / llvm_cbe_tmp__165));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__166, *(int*)(&llvm_cbe_tmp__166));
  if (((llvm_cbe__2e_lcssa103145&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge50;
  } else {
    goto llvm_cbe__2e_lr_2e_ph49;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__216:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1953 = phi i64 [ 0, %%.lr.ph54 ], [ %%143, %%136  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge1953_count);
  llvm_cbe_storemerge1953 = (unsigned long long )llvm_cbe_storemerge1953__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1953 = 0x%I64X",llvm_cbe_storemerge1953);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__164);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%137 = phi float [ 0.000000e+00, %%.lr.ph54 ], [ %%142, %%136  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1763_count);
  llvm_cbe_tmp__158 = (float )llvm_cbe_tmp__158__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__158);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__163);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%138 = add i64 %%storemerge1953, %%133, !dbg !19 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1764_count);
  llvm_cbe_tmp__159 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1953&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__157&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__159&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%139 = getelementptr inbounds float* %%fwork, i64 %%138, !dbg !19 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1765_count);
  llvm_cbe_tmp__160 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__159))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__159));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%140 = load float* %%139, align 4, !dbg !19 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1766_count);
  llvm_cbe_tmp__161 = (float )*llvm_cbe_tmp__160;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__161, *(int*)(&llvm_cbe_tmp__161));
if (AESL_DEBUG_TRACE)
printf("\n  %%141 = fmul float %%140, %%140, !dbg !19 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1767_count);
  llvm_cbe_tmp__162 = (float )((float )(llvm_cbe_tmp__161 * llvm_cbe_tmp__161));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__162, *(int*)(&llvm_cbe_tmp__162));
if (AESL_DEBUG_TRACE)
printf("\n  %%142 = fadd float %%137, %%141, !dbg !19 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1768_count);
  llvm_cbe_tmp__163 = (float )((float )(llvm_cbe_tmp__158 + llvm_cbe_tmp__162));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__163, *(int*)(&llvm_cbe_tmp__163));
if (AESL_DEBUG_TRACE)
printf("\n  %%143 = add i64 %%storemerge1953, 1, !dbg !29 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1774_count);
  llvm_cbe_tmp__164 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1953&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__164&18446744073709551615ull)));
  if (((llvm_cbe_tmp__164&18446744073709551615ULL) == (llvm_cbe__2e_lcssa103145&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge55;
  } else {
    llvm_cbe_storemerge1953__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__164;   /* for PHI node */
    llvm_cbe_tmp__158__PHI_TEMPORARY = (float )llvm_cbe_tmp__163;   /* for PHI node */
    goto llvm_cbe_tmp__216;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph54:
if (AESL_DEBUG_TRACE)
printf("\n  %%133 = mul i64 %%storemerge1558, %%.lcssa103145, !dbg !19 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1747_count);
  llvm_cbe_tmp__157 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1558&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe__2e_lcssa103145&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__157&18446744073709551615ull)));
  llvm_cbe_storemerge1953__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__158__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  goto llvm_cbe_tmp__216;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__217:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2047 = phi i64 [ 0, %%.lr.ph49 ], [ %%152, %%147  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge2047_count);
  llvm_cbe_storemerge2047 = (unsigned long long )llvm_cbe_storemerge2047__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2047 = 0x%I64X",llvm_cbe_storemerge2047);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__172);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%148 = add i64 %%storemerge2047, %%146, !dbg !20 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1803_count);
  llvm_cbe_tmp__168 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge2047&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__167&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__168&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%149 = getelementptr inbounds float* %%fwork, i64 %%148, !dbg !20 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1804_count);
  llvm_cbe_tmp__169 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__168))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__168));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%150 = load float* %%149, align 4, !dbg !20 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1805_count);
  llvm_cbe_tmp__170 = (float )*llvm_cbe_tmp__169;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__170, *(int*)(&llvm_cbe_tmp__170));
if (AESL_DEBUG_TRACE)
printf("\n  %%151 = fmul float %%150, %%145, !dbg !20 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1806_count);
  llvm_cbe_tmp__171 = (float )((float )(llvm_cbe_tmp__170 * llvm_cbe_tmp__166));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__171, *(int*)(&llvm_cbe_tmp__171));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%151, float* %%149, align 4, !dbg !20 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1807_count);
  *llvm_cbe_tmp__169 = llvm_cbe_tmp__171;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__171);
if (AESL_DEBUG_TRACE)
printf("\n  %%152 = add i64 %%storemerge2047, 1, !dbg !29 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1808_count);
  llvm_cbe_tmp__172 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge2047&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__172&18446744073709551615ull)));
  if (((llvm_cbe_tmp__172&18446744073709551615ULL) == (llvm_cbe__2e_lcssa103145&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge50;
  } else {
    llvm_cbe_storemerge2047__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__172;   /* for PHI node */
    goto llvm_cbe_tmp__217;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph49:
if (AESL_DEBUG_TRACE)
printf("\n  %%146 = mul i64 %%storemerge1558, %%.lcssa103145, !dbg !20 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1801_count);
  llvm_cbe_tmp__167 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1558&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe__2e_lcssa103145&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__167&18446744073709551615ull)));
  llvm_cbe_storemerge2047__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__217;

  } while (1); /* end of syntactic loop '.preheader51' */
llvm_cbe__2e_preheader45:
  if (((llvm_cbe_tmp__91&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    goto llvm_cbe__2e_preheader41_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader41_2e_lr_2e_ph:
  llvm_cbe_storemerge1646__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader41;

  do {     /* Syntactic loop '.preheader41' to make GCC happy */
llvm_cbe__2e_preheader41:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1646 = phi i64 [ 0, %%.preheader41.lr.ph ], [ %%173, %%._crit_edge40  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge1646_count);
  llvm_cbe_storemerge1646 = (unsigned long long )llvm_cbe_storemerge1646__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1646 = 0x%I64X",llvm_cbe_storemerge1646);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__190);
}
  if (((llvm_cbe__2e_lcssa97&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge40;
  } else {
    goto llvm_cbe__2e_lr_2e_ph43;
  }

llvm_cbe__2e__crit_edge40:
if (AESL_DEBUG_TRACE)
printf("\n  %%173 = add i64 %%storemerge1646, 1, !dbg !29 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1897_count);
  llvm_cbe_tmp__190 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1646&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__190&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__190&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__91&18446744073709551615ULL))) {
    llvm_cbe_storemerge1646__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__190;   /* for PHI node */
    goto llvm_cbe__2e_preheader41;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe__2e__crit_edge44:
if (AESL_DEBUG_TRACE)
printf("\n  %%164 = call float @sqrtf(float %%162) nounwind readnone, !dbg !30 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1863_count);
  llvm_cbe_tmp__182 = (float )sqrtf(llvm_cbe_tmp__180);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__180, *(int*)(&llvm_cbe_tmp__180));
printf("\nReturn  = %f",llvm_cbe_tmp__182);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%165 = fdiv float 1.000000e+00, %%164, !dbg !30 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1864_count);
  llvm_cbe_tmp__183 = (float )((float )(0x1p0 / llvm_cbe_tmp__182));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__183, *(int*)(&llvm_cbe_tmp__183));
  if (((llvm_cbe__2e_lcssa97&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge40;
  } else {
    goto llvm_cbe__2e_lr_2e_ph39;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__218:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1742 = phi i64 [ 0, %%.lr.ph43 ], [ %%163, %%156  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge1742_count);
  llvm_cbe_storemerge1742 = (unsigned long long )llvm_cbe_storemerge1742__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1742 = 0x%I64X",llvm_cbe_storemerge1742);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__181);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%157 = phi float [ 0.000000e+00, %%.lr.ph43 ], [ %%162, %%156  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1842_count);
  llvm_cbe_tmp__175 = (float )llvm_cbe_tmp__175__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__175);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__180);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%158 = mul i64 %%storemerge1742, %%53, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1843_count);
  llvm_cbe_tmp__176 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1742&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__91&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__176&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum29 = add i64 %%155, %%158, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe__2e_sum29_count);
  llvm_cbe__2e_sum29 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__174&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__176&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum29 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum29&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%159 = getelementptr inbounds float* %%fwork, i64 %%.sum29, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1844_count);
  llvm_cbe_tmp__177 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum29))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum29 = 0x%I64X",((signed long long )llvm_cbe__2e_sum29));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%160 = load float* %%159, align 4, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1845_count);
  llvm_cbe_tmp__178 = (float )*llvm_cbe_tmp__177;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__178, *(int*)(&llvm_cbe_tmp__178));
if (AESL_DEBUG_TRACE)
printf("\n  %%161 = fmul float %%160, %%160, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1846_count);
  llvm_cbe_tmp__179 = (float )((float )(llvm_cbe_tmp__178 * llvm_cbe_tmp__178));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__179, *(int*)(&llvm_cbe_tmp__179));
if (AESL_DEBUG_TRACE)
printf("\n  %%162 = fadd float %%157, %%161, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1847_count);
  llvm_cbe_tmp__180 = (float )((float )(llvm_cbe_tmp__175 + llvm_cbe_tmp__179));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__180, *(int*)(&llvm_cbe_tmp__180));
if (AESL_DEBUG_TRACE)
printf("\n  %%163 = add i64 %%storemerge1742, 1, !dbg !30 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1853_count);
  llvm_cbe_tmp__181 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1742&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__181&18446744073709551615ull)));
  if (((llvm_cbe_tmp__181&18446744073709551615ULL) == (llvm_cbe__2e_lcssa97&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge44;
  } else {
    llvm_cbe_storemerge1742__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__181;   /* for PHI node */
    llvm_cbe_tmp__175__PHI_TEMPORARY = (float )llvm_cbe_tmp__180;   /* for PHI node */
    goto llvm_cbe_tmp__218;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph43:
if (AESL_DEBUG_TRACE)
printf("\n  %%155 = add i64 %%storemerge1646, %%6, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1840_count);
  llvm_cbe_tmp__174 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1646&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__55&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__174&18446744073709551615ull)));
  llvm_cbe_storemerge1742__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__175__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  goto llvm_cbe_tmp__218;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__219:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1837 = phi i64 [ 0, %%.lr.ph39 ], [ %%172, %%167  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge1837_count);
  llvm_cbe_storemerge1837 = (unsigned long long )llvm_cbe_storemerge1837__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1837 = 0x%I64X",llvm_cbe_storemerge1837);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__189);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%168 = mul i64 %%storemerge1837, %%53, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1882_count);
  llvm_cbe_tmp__185 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1837&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__91&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__185&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum28 = add i64 %%166, %%168, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe__2e_sum28_count);
  llvm_cbe__2e_sum28 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__184&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__185&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum28 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum28&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%169 = getelementptr inbounds float* %%fwork, i64 %%.sum28, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1883_count);
  llvm_cbe_tmp__186 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum28))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum28 = 0x%I64X",((signed long long )llvm_cbe__2e_sum28));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%170 = load float* %%169, align 4, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1884_count);
  llvm_cbe_tmp__187 = (float )*llvm_cbe_tmp__186;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__187, *(int*)(&llvm_cbe_tmp__187));
if (AESL_DEBUG_TRACE)
printf("\n  %%171 = fmul float %%170, %%165, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1885_count);
  llvm_cbe_tmp__188 = (float )((float )(llvm_cbe_tmp__187 * llvm_cbe_tmp__183));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__188, *(int*)(&llvm_cbe_tmp__188));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%171, float* %%169, align 4, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1886_count);
  *llvm_cbe_tmp__186 = llvm_cbe_tmp__188;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__188);
if (AESL_DEBUG_TRACE)
printf("\n  %%172 = add i64 %%storemerge1837, 1, !dbg !30 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1887_count);
  llvm_cbe_tmp__189 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1837&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__189&18446744073709551615ull)));
  if (((llvm_cbe_tmp__189&18446744073709551615ULL) == (llvm_cbe__2e_lcssa97&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge40;
  } else {
    llvm_cbe_storemerge1837__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__189;   /* for PHI node */
    goto llvm_cbe_tmp__219;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph39:
if (AESL_DEBUG_TRACE)
printf("\n  %%166 = add i64 %%storemerge1646, %%6, !dbg !27 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1880_count);
  llvm_cbe_tmp__184 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1646&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__55&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__184&18446744073709551615ull)));
  llvm_cbe_storemerge1837__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__219;

  } while (1); /* end of syntactic loop '.preheader41' */
llvm_cbe__2e_loopexit:
  goto llvm_cbe_tmp__215;

llvm_cbe_tmp__215:
  if (((llvm_cbe_tmp__88&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge36;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  llvm_cbe_storemerge1235__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1235 = phi i64 [ 0, %%.preheader.lr.ph ], [ %%198, %%._crit_edge34  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge1235_count);
  llvm_cbe_storemerge1235 = (unsigned long long )llvm_cbe_storemerge1235__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1235 = 0x%I64X",llvm_cbe_storemerge1235);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__207);
}
  if (((llvm_cbe_tmp__91&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge34;
  } else {
    goto llvm_cbe__2e_lr_2e_ph33;
  }

llvm_cbe__2e__crit_edge34:
if (AESL_DEBUG_TRACE)
printf("\n  %%198 = add i64 %%storemerge1235, 1, !dbg !26 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_2013_count);
  llvm_cbe_tmp__207 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1235&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__207&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__207&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__88&18446744073709551615ULL))) {
    llvm_cbe_storemerge1235__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__207;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e__crit_edge36;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__220:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1332 = phi i64 [ 0, %%.lr.ph33 ], [ %%196, %%._crit_edge  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge1332_count);
  llvm_cbe_storemerge1332 = (unsigned long long )llvm_cbe_storemerge1332__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1332 = 0x%I64X",llvm_cbe_storemerge1332);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__206);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%182 = add i64 %%storemerge1332, %%179, !dbg !10 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1976_count);
  llvm_cbe_tmp__193 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1332&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__191&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__193&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%183 = getelementptr inbounds %%struct.k2c_tensor* %%C, i64 0, i32 0, i64 %%182, !dbg !10 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1977_count);
  llvm_cbe_tmp__194 = (float *)(&llvm_cbe_C->field0[(((signed long long )llvm_cbe_tmp__193))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__193));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%183, align 4, !dbg !10 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1978_count);
  *llvm_cbe_tmp__194 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  if (((llvm_cbe__2e_lcssa103145&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%196 = add i64 %%storemerge1332, 1, !dbg !30 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_2004_count);
  llvm_cbe_tmp__206 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1332&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__206&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__206&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__91&18446744073709551615ULL))) {
    llvm_cbe_storemerge1332__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__206;   /* for PHI node */
    goto llvm_cbe_tmp__220;
  } else {
    goto llvm_cbe__2e__crit_edge34;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__221:
if (AESL_DEBUG_TRACE)
printf("\n  %%186 = phi float [ 0.000000e+00, %%.lr.ph ], [ %%194, %%185 ], !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1987_count);
  llvm_cbe_tmp__196 = (float )llvm_cbe_tmp__196__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__196);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__204);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1431 = phi i64 [ 0, %%.lr.ph ], [ %%195, %%185  for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_storemerge1431_count);
  llvm_cbe_storemerge1431 = (unsigned long long )llvm_cbe_storemerge1431__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1431 = 0x%I64X",llvm_cbe_storemerge1431);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__205);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%187 = add i64 %%storemerge1431, %%180, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1988_count);
  llvm_cbe_tmp__197 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1431&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__192&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__197&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%188 = getelementptr inbounds float* %%fwork, i64 %%187, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1989_count);
  llvm_cbe_tmp__198 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__197))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__197));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%189 = load float* %%188, align 4, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1990_count);
  llvm_cbe_tmp__199 = (float )*llvm_cbe_tmp__198;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__199, *(int*)(&llvm_cbe_tmp__199));
if (AESL_DEBUG_TRACE)
printf("\n  %%190 = mul i64 %%storemerge1431, %%53, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1991_count);
  llvm_cbe_tmp__200 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1431&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__91&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__200&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%184, %%190, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__195&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__200&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%191 = getelementptr inbounds float* %%fwork, i64 %%.sum, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1992_count);
  llvm_cbe_tmp__201 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%192 = load float* %%191, align 4, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1993_count);
  llvm_cbe_tmp__202 = (float )*llvm_cbe_tmp__201;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__202, *(int*)(&llvm_cbe_tmp__202));
if (AESL_DEBUG_TRACE)
printf("\n  %%193 = fmul float %%189, %%192, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1994_count);
  llvm_cbe_tmp__203 = (float )((float )(llvm_cbe_tmp__199 * llvm_cbe_tmp__202));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__203, *(int*)(&llvm_cbe_tmp__203));
if (AESL_DEBUG_TRACE)
printf("\n  %%194 = fadd float %%186, %%193, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1995_count);
  llvm_cbe_tmp__204 = (float )((float )(llvm_cbe_tmp__196 + llvm_cbe_tmp__203));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__204, *(int*)(&llvm_cbe_tmp__204));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%194, float* %%183, align 4, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1996_count);
  *llvm_cbe_tmp__194 = llvm_cbe_tmp__204;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__204);
if (AESL_DEBUG_TRACE)
printf("\n  %%195 = add i64 %%storemerge1431, 1, !dbg !30 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1997_count);
  llvm_cbe_tmp__205 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1431&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__205&18446744073709551615ull)));
  if (((llvm_cbe_tmp__205&18446744073709551615ULL) == (llvm_cbe__2e_lcssa103145&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_tmp__196__PHI_TEMPORARY = (float )llvm_cbe_tmp__204;   /* for PHI node */
    llvm_cbe_storemerge1431__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__205;   /* for PHI node */
    goto llvm_cbe_tmp__221;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%184 = add i64 %%storemerge1332, %%6, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1985_count);
  llvm_cbe_tmp__195 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1332&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__55&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__195&18446744073709551615ull)));
  llvm_cbe_tmp__196__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge1431__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__221;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph33:
if (AESL_DEBUG_TRACE)
printf("\n  %%179 = mul i64 %%storemerge1235, %%53, !dbg !10 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1973_count);
  llvm_cbe_tmp__191 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1235&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__91&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__191&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%180 = mul i64 %%storemerge1235, %%.lcssa103145, !dbg !11 for 0x%I64xth hint within @k2c_dot  --> \n", ++aesl_llvm_cbe_1974_count);
  llvm_cbe_tmp__192 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1235&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe__2e_lcssa103145&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__192&18446744073709551615ull)));
  llvm_cbe_storemerge1332__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__220;

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge36:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_dot}\n");
  return;
}


void k2c_bias_add(l_struct_OC_k2c_tensor *llvm_cbe_A, l_struct_OC_k2c_tensor *llvm_cbe_b) {
  static  unsigned long long aesl_llvm_cbe_2067_count = 0;
  static  unsigned long long aesl_llvm_cbe_2068_count = 0;
  static  unsigned long long aesl_llvm_cbe_2069_count = 0;
  static  unsigned long long aesl_llvm_cbe_2070_count = 0;
  static  unsigned long long aesl_llvm_cbe_2071_count = 0;
  static  unsigned long long aesl_llvm_cbe_2072_count = 0;
  static  unsigned long long aesl_llvm_cbe_2073_count = 0;
  static  unsigned long long aesl_llvm_cbe_2074_count = 0;
  static  unsigned long long aesl_llvm_cbe_2075_count = 0;
  static  unsigned long long aesl_llvm_cbe_2076_count = 0;
  static  unsigned long long aesl_llvm_cbe_2077_count = 0;
  static  unsigned long long aesl_llvm_cbe_2078_count = 0;
  signed long long *llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_2079_count = 0;
  unsigned long long llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_2080_count = 0;
  static  unsigned long long aesl_llvm_cbe_2081_count = 0;
  static  unsigned long long aesl_llvm_cbe_2082_count = 0;
  signed long long *llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_2083_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
  unsigned long long llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2084_count = 0;
  static  unsigned long long aesl_llvm_cbe_2085_count = 0;
  static  unsigned long long aesl_llvm_cbe_2086_count = 0;
  static  unsigned long long aesl_llvm_cbe_2087_count = 0;
  static  unsigned long long aesl_llvm_cbe_2088_count = 0;
  unsigned long long llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_2089_count = 0;
  static  unsigned long long aesl_llvm_cbe_2090_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2091_count = 0;
  float *llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_2092_count = 0;
  float llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_2093_count = 0;
  unsigned long long llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_2094_count = 0;
  float *llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_2095_count = 0;
  float llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_2096_count = 0;
  float llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_2097_count = 0;
  static  unsigned long long aesl_llvm_cbe_2098_count = 0;
  unsigned long long llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_2099_count = 0;
  static  unsigned long long aesl_llvm_cbe_2100_count = 0;
  static  unsigned long long aesl_llvm_cbe_2101_count = 0;
  static  unsigned long long aesl_llvm_cbe_2102_count = 0;
  static  unsigned long long aesl_llvm_cbe_2103_count = 0;
  static  unsigned long long aesl_llvm_cbe_2104_count = 0;
  unsigned long long llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_2105_count = 0;
  static  unsigned long long aesl_llvm_cbe_2106_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned long long llvm_cbe__2e_lcssa;
  unsigned long long llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2107_count = 0;
  unsigned long long llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_2108_count = 0;
  static  unsigned long long aesl_llvm_cbe_2109_count = 0;
  static  unsigned long long aesl_llvm_cbe_2110_count = 0;
  static  unsigned long long aesl_llvm_cbe_2111_count = 0;
  static  unsigned long long aesl_llvm_cbe_2112_count = 0;
  unsigned long long llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_2113_count = 0;
  static  unsigned long long aesl_llvm_cbe_2114_count = 0;
  static  unsigned long long aesl_llvm_cbe_2115_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_bias_add\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%A, i64 0, i32 2, !dbg !10 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2078_count);
  llvm_cbe_tmp__222 = (signed long long *)(&llvm_cbe_A->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !10 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2079_count);
  llvm_cbe_tmp__223 = (unsigned long long )*llvm_cbe_tmp__222;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__223);
  if (((llvm_cbe_tmp__223&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge4;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.k2c_tensor* %%b, i64 0, i32 2, !dbg !11 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2082_count);
  llvm_cbe_tmp__224 = (signed long long *)(&llvm_cbe_b->field2);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i64 [ 0, %%.preheader.lr.ph ], [ %%16, %%._crit_edge  for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__234);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i64* %%4, align 8, !dbg !11 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2088_count);
  llvm_cbe_tmp__225 = (unsigned long long )*llvm_cbe_tmp__224;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__225);
  if (((llvm_cbe_tmp__225&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i64 [ 0, %%.preheader ], [ %%14, %%.lr.ph  for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned long long )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%I64X",llvm_cbe__2e_lcssa);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__233);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i64 %%.lcssa, %%storemerge3, !dbg !11 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2107_count);
  llvm_cbe_tmp__234 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_lcssa&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__234&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i64* %%1, align 8, !dbg !10 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2112_count);
  llvm_cbe_tmp__235 = (unsigned long long )*llvm_cbe_tmp__222;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__235);
  if ((((unsigned long long )llvm_cbe_tmp__234&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__235&18446744073709551615ULL))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__234;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e__crit_edge4;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ %%13, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",llvm_cbe_tmp__232);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.k2c_tensor* %%b, i64 0, i32 0, i64 %%storemerge12, !dbg !10 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2091_count);
  llvm_cbe_tmp__226 = (float *)(&llvm_cbe_b->field0[(((signed long long )llvm_cbe_storemerge12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",((signed long long )llvm_cbe_storemerge12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 4, !dbg !10 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2092_count);
  llvm_cbe_tmp__227 = (float )*llvm_cbe_tmp__226;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__227, *(int*)(&llvm_cbe_tmp__227));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i64 %%storemerge12, %%storemerge3, !dbg !10 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2093_count);
  llvm_cbe_tmp__228 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__228&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.k2c_tensor* %%A, i64 0, i32 0, i64 %%9, !dbg !10 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2094_count);
  llvm_cbe_tmp__229 = (float *)(&llvm_cbe_A->field0[(((signed long long )llvm_cbe_tmp__228))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__228));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load float* %%10, align 4, !dbg !10 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2095_count);
  llvm_cbe_tmp__230 = (float )*llvm_cbe_tmp__229;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__230, *(int*)(&llvm_cbe_tmp__230));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = fadd float %%11, %%8, !dbg !10 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2096_count);
  llvm_cbe_tmp__231 = (float )((float )(llvm_cbe_tmp__230 + llvm_cbe_tmp__227));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__231, *(int*)(&llvm_cbe_tmp__231));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* %%10, align 4, !dbg !10 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2097_count);
  *llvm_cbe_tmp__229 = llvm_cbe_tmp__231;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__231);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i64 %%storemerge12, 1, !dbg !12 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2098_count);
  llvm_cbe_tmp__232 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__232&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%4, align 8, !dbg !11 for 0x%I64xth hint within @k2c_bias_add  --> \n", ++aesl_llvm_cbe_2104_count);
  llvm_cbe_tmp__233 = (unsigned long long )*llvm_cbe_tmp__224;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__233);
  if ((((unsigned long long )llvm_cbe_tmp__232&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__233&18446744073709551615ULL))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__232;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__233;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge4:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_bias_add}\n");
  return;
}


void k2c_flip(l_struct_OC_k2c_tensor *llvm_cbe_A, signed long long llvm_cbe_axis) {
  static  unsigned long long aesl_llvm_cbe_sub_count = 0;
  signed long long llvm_cbe_sub[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_2116_count = 0;
  static  unsigned long long aesl_llvm_cbe_2117_count = 0;
  static  unsigned long long aesl_llvm_cbe_2118_count = 0;
  static  unsigned long long aesl_llvm_cbe_2119_count = 0;
  static  unsigned long long aesl_llvm_cbe_2120_count = 0;
  static  unsigned long long aesl_llvm_cbe_2121_count = 0;
  static  unsigned long long aesl_llvm_cbe_2122_count = 0;
  static  unsigned long long aesl_llvm_cbe_2123_count = 0;
  static  unsigned long long aesl_llvm_cbe_2124_count = 0;
  static  unsigned long long aesl_llvm_cbe_2125_count = 0;
  static  unsigned long long aesl_llvm_cbe_2126_count = 0;
  static  unsigned long long aesl_llvm_cbe_2127_count = 0;
  static  unsigned long long aesl_llvm_cbe_2128_count = 0;
  static  unsigned long long aesl_llvm_cbe_2129_count = 0;
  signed long long *llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_2130_count = 0;
  unsigned long long llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_2131_count = 0;
  static  unsigned long long aesl_llvm_cbe_2132_count = 0;
  static  unsigned long long aesl_llvm_cbe_2133_count = 0;
  static  unsigned long long aesl_llvm_cbe_2134_count = 0;
  static  unsigned long long aesl_llvm_cbe_2135_count = 0;
  signed long long *llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_2136_count = 0;
  static  unsigned long long aesl_llvm_cbe_2137_count = 0;
  static  unsigned long long aesl_llvm_cbe_2138_count = 0;
  static  unsigned long long aesl_llvm_cbe_2139_count = 0;
  static  unsigned long long aesl_llvm_cbe_2140_count = 0;
  static  unsigned long long aesl_llvm_cbe_2141_count = 0;
  signed long long *llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_2142_count = 0;
  unsigned long long llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_2143_count = 0;
  static  unsigned long long aesl_llvm_cbe_2144_count = 0;
  static  unsigned long long aesl_llvm_cbe_2145_count = 0;
  static  unsigned long long aesl_llvm_cbe_2146_count = 0;
   char *llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_2147_count = 0;
   char *llvm_cbe_tmp__242;
  static  unsigned long long aesl_llvm_cbe_2148_count = 0;
  static  unsigned long long aesl_llvm_cbe_2149_count = 0;
  static  unsigned long long aesl_llvm_cbe_2150_count = 0;
  static  unsigned long long aesl_llvm_cbe_2151_count = 0;
  static  unsigned long long aesl_llvm_cbe_2152_count = 0;
  static  unsigned long long aesl_llvm_cbe_2153_count = 0;
  static  unsigned long long aesl_llvm_cbe_2154_count = 0;
  static  unsigned long long aesl_llvm_cbe_2155_count = 0;
  static  unsigned long long aesl_llvm_cbe_2156_count = 0;
  static  unsigned long long aesl_llvm_cbe_2157_count = 0;
  static  unsigned long long aesl_llvm_cbe_2158_count = 0;
  static  unsigned long long aesl_llvm_cbe_2159_count = 0;
  static  unsigned long long aesl_llvm_cbe_2160_count = 0;
  static  unsigned long long aesl_llvm_cbe_2161_count = 0;
  static  unsigned long long aesl_llvm_cbe_2162_count = 0;
  static  unsigned long long aesl_llvm_cbe_2163_count = 0;
  static  unsigned long long aesl_llvm_cbe_2164_count = 0;
  static  unsigned long long aesl_llvm_cbe_2165_count = 0;
  static  unsigned long long aesl_llvm_cbe_2166_count = 0;
  static  unsigned long long aesl_llvm_cbe_2167_count = 0;
  static  unsigned long long aesl_llvm_cbe_2168_count = 0;
  static  unsigned long long aesl_llvm_cbe_2169_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge5_count = 0;
  unsigned long long llvm_cbe_storemerge5;
  unsigned long long llvm_cbe_storemerge5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2170_count = 0;
  unsigned long long llvm_cbe_tmp__243;
  unsigned long long llvm_cbe_tmp__243__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2171_count = 0;
  signed long long *llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_2172_count = 0;
  unsigned long long llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_2173_count = 0;
  unsigned long long llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_2174_count = 0;
  static  unsigned long long aesl_llvm_cbe_2175_count = 0;
  static  unsigned long long aesl_llvm_cbe_2176_count = 0;
  static  unsigned long long aesl_llvm_cbe_2177_count = 0;
  static  unsigned long long aesl_llvm_cbe_2178_count = 0;
  unsigned long long llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_2179_count = 0;
  static  unsigned long long aesl_llvm_cbe_2180_count = 0;
  static  unsigned long long aesl_llvm_cbe_2181_count = 0;
  static  unsigned long long aesl_llvm_cbe_2182_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_2183_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned long long llvm_cbe__2e_lcssa;
  unsigned long long llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2184_count = 0;
  unsigned long long llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_2185_count = 0;
  static  unsigned long long aesl_llvm_cbe_2186_count = 0;
  static  unsigned long long aesl_llvm_cbe_2187_count = 0;
  static  unsigned long long aesl_llvm_cbe_2188_count = 0;
  static  unsigned long long aesl_llvm_cbe_2189_count = 0;
  static  unsigned long long aesl_llvm_cbe_2190_count = 0;
  static  unsigned long long aesl_llvm_cbe_2191_count = 0;
  static  unsigned long long aesl_llvm_cbe_2192_count = 0;
  static  unsigned long long aesl_llvm_cbe_2193_count = 0;
  signed long long *llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_2194_count = 0;
  signed long long *llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_2195_count = 0;
  signed long long *llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_2196_count = 0;
  unsigned long long llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_2197_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge124_count = 0;
  unsigned long long llvm_cbe_storemerge124;
  unsigned long long llvm_cbe_storemerge124__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2198_count = 0;
  static  unsigned long long aesl_llvm_cbe_2199_count = 0;
  unsigned long long llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_2200_count = 0;
  unsigned long long llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_2201_count = 0;
  unsigned long long llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_2202_count = 0;
  unsigned long long llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_2203_count = 0;
  static  unsigned long long aesl_llvm_cbe_2204_count = 0;
  unsigned long long llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_2205_count = 0;
  static  unsigned long long aesl_llvm_cbe_2206_count = 0;
  static  unsigned long long aesl_llvm_cbe_2207_count = 0;
  static  unsigned long long aesl_llvm_cbe_2208_count = 0;
  float *llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_2209_count = 0;
  float llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_2210_count = 0;
  static  unsigned long long aesl_llvm_cbe_2211_count = 0;
  static  unsigned long long aesl_llvm_cbe_2212_count = 0;
  float *llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_2213_count = 0;
  float llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_2214_count = 0;
  static  unsigned long long aesl_llvm_cbe_2215_count = 0;
  static  unsigned long long aesl_llvm_cbe_2216_count = 0;
  unsigned long long llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_2217_count = 0;
  static  unsigned long long aesl_llvm_cbe_2218_count = 0;
  unsigned long long llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_2219_count = 0;
  static  unsigned long long aesl_llvm_cbe_2220_count = 0;
  unsigned long long llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_2221_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_be_count = 0;
  unsigned long long llvm_cbe_storemerge12_2e_be;
  static  unsigned long long aesl_llvm_cbe_2222_count = 0;
  static  unsigned long long aesl_llvm_cbe_2223_count = 0;
  static  unsigned long long aesl_llvm_cbe_2224_count = 0;
  static  unsigned long long aesl_llvm_cbe_2225_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_flip\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%A, i64 0, i32 1, !dbg !10 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2129_count);
  llvm_cbe_tmp__236 = (signed long long *)(&llvm_cbe_A->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !10 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2130_count);
  llvm_cbe_tmp__237 = (unsigned long long )*llvm_cbe_tmp__236;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%A, i64 0, i32 3, i64 0, !dbg !10 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2135_count);
  llvm_cbe_tmp__238 = (signed long long *)(&llvm_cbe_A->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.k2c_tensor* %%A, i64 0, i32 2, !dbg !10 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2141_count);
  llvm_cbe_tmp__239 = (signed long long *)(&llvm_cbe_A->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i64* %%4, align 8, !dbg !10 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2142_count);
  llvm_cbe_tmp__240 = (unsigned long long )*llvm_cbe_tmp__239;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__240);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = bitcast [5 x i64]* %%sub to i8*, !dbg !12 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2146_count);
  llvm_cbe_tmp__241 = ( char *)(( char *)(&llvm_cbe_sub));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = call i8* @memset(i8* %%6, i32 0, i64 40 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2147_count);
  ( char *)memset(( char *)llvm_cbe_tmp__241, 0u, 40ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",40ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__242);
}
  if ((((unsigned long long )llvm_cbe_tmp__237&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_axis&18446744073709551615ULL))) {
    llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned long long )llvm_cbe_axis;   /* for PHI node */
    llvm_cbe_tmp__243__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph7;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge8;
  }

  do {     /* Syntactic loop '.lr.ph7' to make GCC happy */
llvm_cbe__2e_lr_2e_ph7:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge5 = phi i64 [ %%13, %%.lr.ph7 ], [ %%axis, %%0  for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_storemerge5_count);
  llvm_cbe_storemerge5 = (unsigned long long )llvm_cbe_storemerge5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5 = 0x%I64X",llvm_cbe_storemerge5);
printf("\n = 0x%I64X",llvm_cbe_tmp__247);
printf("\naxis = 0x%I64X",llvm_cbe_axis);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = phi i64 [ %%12, %%.lr.ph7 ], [ 1, %%0  for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2170_count);
  llvm_cbe_tmp__243 = (unsigned long long )llvm_cbe_tmp__243__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__243);
printf("\n = 0x%I64X",llvm_cbe_tmp__246);
printf("\n = 0x%I64X",1ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.k2c_tensor* %%A, i64 0, i32 3, i64 %%storemerge5, !dbg !12 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2171_count);
  llvm_cbe_tmp__244 = (signed long long *)(&llvm_cbe_A->field3[(((signed long long )llvm_cbe_storemerge5))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5 = 0x%I64X",((signed long long )llvm_cbe_storemerge5));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%10, align 8, !dbg !12 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2172_count);
  llvm_cbe_tmp__245 = (unsigned long long )*llvm_cbe_tmp__244;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__245);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = mul i64 %%11, %%9, !dbg !12 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2173_count);
  llvm_cbe_tmp__246 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__245&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__243&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__246&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i64 %%storemerge5, 1, !dbg !14 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2178_count);
  llvm_cbe_tmp__247 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge5&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__247&18446744073709551615ull)));
  if (((llvm_cbe_tmp__247&18446744073709551615ULL) == (llvm_cbe_tmp__237&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__246;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge8;
  } else {
    llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__247;   /* for PHI node */
    llvm_cbe_tmp__243__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__246;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph7;
  }

  } while (1); /* end of syntactic loop '.lr.ph7' */
llvm_cbe__2e__crit_edge8:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i64 [ 1, %%0 ], [ %%12, %%.lr.ph7  for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned long long )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%I64X",llvm_cbe__2e_lcssa);
printf("\n = 0x%I64X",1ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__246);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = lshr i64 %%.lcssa, 1, !dbg !14 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2184_count);
  llvm_cbe_tmp__248 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe__2e_lcssa&18446744073709551615ull)) >> ((unsigned long long )(1ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__248&18446744073709551615ull)));
  if (((llvm_cbe_tmp__240&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds [5 x i64]* %%sub, i64 0, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2193_count);
  llvm_cbe_tmp__249 = (signed long long *)(&llvm_cbe_sub[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.k2c_tensor* %%A, i64 0, i32 3, i64 %%axis, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2194_count);
  llvm_cbe_tmp__250 = (signed long long *)(&llvm_cbe_A->field3[(((signed long long )llvm_cbe_axis))]);
if (AESL_DEBUG_TRACE) {
printf("\naxis = 0x%I64X",((signed long long )llvm_cbe_axis));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [5 x i64]* %%sub, i64 0, i64 %%axis, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2195_count);
  llvm_cbe_tmp__251 = (signed long long *)(&llvm_cbe_sub[(((signed long long )llvm_cbe_axis))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\naxis = 0x%I64X",((signed long long )llvm_cbe_axis));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sub i64 %%.lcssa, %%14, !dbg !13 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2196_count);
  llvm_cbe_tmp__252 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_lcssa&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__248&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__252&18446744073709551615ull)));
  llvm_cbe_storemerge124__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_backedge;

  do {     /* Syntactic loop '.backedge' to make GCC happy */
llvm_cbe__2e_backedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge124 = phi i64 [ 0, %%.lr.ph ], [ %%storemerge12.be, %%.backedge  for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_storemerge124_count);
  llvm_cbe_storemerge124 = (unsigned long long )llvm_cbe_storemerge124__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge124 = 0x%I64X",llvm_cbe_storemerge124);
printf("\n = 0x%I64X",0ull);
printf("\nstoremerge12.be = 0x%I64X",llvm_cbe_storemerge12_2e_be);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @k2c_idx2sub(i64 %%storemerge124, i64* %%16, i64* %%3, i64 %%2), !dbg !12 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2198_count);
  k2c_idx2sub(llvm_cbe_storemerge124, (signed long long *)llvm_cbe_tmp__249, (signed long long *)llvm_cbe_tmp__238, llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge124 = 0x%I64X",llvm_cbe_storemerge124);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__237);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i64* %%17, align 8, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2199_count);
  llvm_cbe_tmp__253 = (unsigned long long )*llvm_cbe_tmp__250;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__253);

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_axis) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'sub' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i64* %%18, align 8, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2200_count);
  llvm_cbe_tmp__254 = (unsigned long long )*llvm_cbe_tmp__251;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__254);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add i64 %%20, -1, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2201_count);
  llvm_cbe_tmp__255 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__253&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__255&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sub i64 %%22, %%21, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2202_count);
  llvm_cbe_tmp__256 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__255&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__254&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__256&18446744073709551615ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_axis) < 5 && "Write access out of array 'sub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%23, i64* %%18, align 8, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2203_count);
  *llvm_cbe_tmp__251 = llvm_cbe_tmp__256;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__256);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call i64 @k2c_sub2idx(i64* %%16, i64* %%3, i64 %%2), !dbg !12 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2204_count);
  llvm_cbe_tmp__257 = (unsigned long long )k2c_sub2idx((signed long long *)llvm_cbe_tmp__249, (signed long long *)llvm_cbe_tmp__238, llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__237);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__257);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.k2c_tensor* %%A, i64 0, i32 0, i64 %%storemerge124, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2208_count);
  llvm_cbe_tmp__258 = (float *)(&llvm_cbe_A->field0[(((signed long long )llvm_cbe_storemerge124))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge124 = 0x%I64X",((signed long long )llvm_cbe_storemerge124));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load float* %%25, align 4, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2209_count);
  llvm_cbe_tmp__259 = (float )*llvm_cbe_tmp__258;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__259, *(int*)(&llvm_cbe_tmp__259));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.k2c_tensor* %%A, i64 0, i32 0, i64 %%24, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2212_count);
  llvm_cbe_tmp__260 = (float *)(&llvm_cbe_A->field0[(((signed long long )llvm_cbe_tmp__257))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__257));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load float* %%27, align 4, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2213_count);
  llvm_cbe_tmp__261 = (float )*llvm_cbe_tmp__260;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__261, *(int*)(&llvm_cbe_tmp__261));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%28, float* %%25, align 4, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2214_count);
  *llvm_cbe_tmp__258 = llvm_cbe_tmp__261;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__261);
if (AESL_DEBUG_TRACE)
printf("\n  store float %%26, float* %%27, align 4, !dbg !11 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2215_count);
  *llvm_cbe_tmp__260 = llvm_cbe_tmp__259;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__259);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i64 %%storemerge124, 1, !dbg !13 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2216_count);
  llvm_cbe_tmp__262 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge124&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__262&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = urem i64 %%29, %%.lcssa, !dbg !13 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2218_count);
  llvm_cbe_tmp__263 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__262&18446744073709551615ull)) % ((unsigned long long )(llvm_cbe__2e_lcssa&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__263&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i64 %%19, %%29, !dbg !13 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_2220_count);
  llvm_cbe_tmp__264 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__252&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__262&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__264&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.be = select i1 %%31, i64 %%29, i64 %%32, !dbg !13 for 0x%I64xth hint within @k2c_flip  --> \n", ++aesl_llvm_cbe_storemerge12_2e_be_count);
  llvm_cbe_storemerge12_2e_be = (unsigned long long )(((((unsigned long long )llvm_cbe_tmp__263&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__248&18446744073709551615ULL))) ? ((unsigned long long )llvm_cbe_tmp__262) : ((unsigned long long )llvm_cbe_tmp__264));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge12.be = 0x%I64X\n", llvm_cbe_storemerge12_2e_be);
  if ((((unsigned long long )llvm_cbe_storemerge12_2e_be&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__240&18446744073709551615ULL))) {
    llvm_cbe_storemerge124__PHI_TEMPORARY = (unsigned long long )llvm_cbe_storemerge12_2e_be;   /* for PHI node */
    goto llvm_cbe__2e_backedge;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.backedge' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_flip}\n");
  return;
}


float *k2c_read_array( char *llvm_cbe_filename, signed long long llvm_cbe_array_size) {
  static  unsigned long long aesl_llvm_cbe_2226_count = 0;
  static  unsigned long long aesl_llvm_cbe_2227_count = 0;
  static  unsigned long long aesl_llvm_cbe_2228_count = 0;
  static  unsigned long long aesl_llvm_cbe_2229_count = 0;
  static  unsigned long long aesl_llvm_cbe_2230_count = 0;
  static  unsigned long long aesl_llvm_cbe_2231_count = 0;
  static  unsigned long long aesl_llvm_cbe_2232_count = 0;
  static  unsigned long long aesl_llvm_cbe_2233_count = 0;
  unsigned long long llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_2234_count = 0;
   char *llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_2235_count = 0;
  float *llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_2236_count = 0;
  static  unsigned long long aesl_llvm_cbe_2237_count = 0;
  static  unsigned long long aesl_llvm_cbe_2238_count = 0;
  static  unsigned long long aesl_llvm_cbe_2239_count = 0;
  static  unsigned long long aesl_llvm_cbe_2240_count = 0;
  static  unsigned long long aesl_llvm_cbe_2241_count = 0;
  static  unsigned long long aesl_llvm_cbe_2242_count = 0;
  unsigned int llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_2243_count = 0;
  static  unsigned long long aesl_llvm_cbe_2244_count = 0;
  static  unsigned long long aesl_llvm_cbe_2245_count = 0;
  static  unsigned long long aesl_llvm_cbe_2246_count = 0;
  static  unsigned long long aesl_llvm_cbe_2247_count = 0;
  static  unsigned long long aesl_llvm_cbe_2248_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__269;
  static  unsigned long long aesl_llvm_cbe_2249_count = 0;
  static  unsigned long long aesl_llvm_cbe_2250_count = 0;
  static  unsigned long long aesl_llvm_cbe_2251_count = 0;
  static  unsigned long long aesl_llvm_cbe_2252_count = 0;
  static  unsigned long long aesl_llvm_cbe_2253_count = 0;
  static  unsigned long long aesl_llvm_cbe_2254_count = 0;
  static  unsigned long long aesl_llvm_cbe_2255_count = 0;
  static  unsigned long long aesl_llvm_cbe_2256_count = 0;
  unsigned int llvm_cbe_tmp__270;
  static  unsigned long long aesl_llvm_cbe_2257_count = 0;
  static  unsigned long long aesl_llvm_cbe_2258_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond1_count = 0;
  bool llvm_cbe_or_2e_cond1;
  static  unsigned long long aesl_llvm_cbe_2259_count = 0;
  static  unsigned long long aesl_llvm_cbe_2260_count = 0;
  unsigned int llvm_cbe_tmp__271;
  static  unsigned long long aesl_llvm_cbe_2261_count = 0;
  static  unsigned long long aesl_llvm_cbe_2262_count = 0;
  static  unsigned long long aesl_llvm_cbe_2263_count = 0;
  unsigned long long llvm_cbe_tmp__272;
  unsigned long long llvm_cbe_tmp__272__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2264_count = 0;
  unsigned long long llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_2265_count = 0;
  static  unsigned long long aesl_llvm_cbe_2266_count = 0;
  static  unsigned long long aesl_llvm_cbe_2267_count = 0;
  static  unsigned long long aesl_llvm_cbe_2268_count = 0;
  float *llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_2269_count = 0;
  unsigned int llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_2270_count = 0;
  static  unsigned long long aesl_llvm_cbe_2271_count = 0;
  unsigned int llvm_cbe_tmp__276;
  static  unsigned long long aesl_llvm_cbe_2272_count = 0;
  static  unsigned long long aesl_llvm_cbe_2273_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_2274_count = 0;
  static  unsigned long long aesl_llvm_cbe_2275_count = 0;
  unsigned int llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_2276_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_read_array\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = shl i64 %%array_size, 2, !dbg !11 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2233_count);
  llvm_cbe_tmp__265 = (unsigned long long )llvm_cbe_array_size << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__265);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call i8* @malloc(i64 %%1), !dbg !11 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2234_count);
  llvm_cbe_tmp__266 = ( char *) /*tail*/ ( char *)malloc(llvm_cbe_tmp__265);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__265);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__266);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast i8* %%2 to float*, !dbg !11 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2235_count);
  llvm_cbe_tmp__267 = (float *)((float *)llvm_cbe_tmp__266);
  if (((llvm_cbe_tmp__266) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__278;
  } else {
    goto llvm_cbe_tmp__279;
  }

llvm_cbe_tmp__278:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([28 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* %%filename) nounwind, !dbg !10 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2242_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
])), ( char *)llvm_cbe_filename);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__268);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @exit(i32 -1) noreturn nounwind, !dbg !12 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2243_count);
   /*tail*/ exit(4294967295u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",4294967295u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__279:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call %%struct._iobuf* @fopen(i8* %%filename, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str1, i64 0, i64 0)) nounwind, !dbg !10 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2248_count);
  llvm_cbe_tmp__269 = (l_struct_OC__iobuf *) /*tail*/ aesl_fopen(( char *)llvm_cbe_filename, ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__269);
}
  if (((llvm_cbe_tmp__269) == (((l_struct_OC__iobuf *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__280;
  } else {
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call i32 @feof(%%struct._iobuf* %%8) nounwind, !dbg !11 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2256_count);
  llvm_cbe_tmp__270 = (unsigned int ) /*tail*/ feof((l_struct_OC__iobuf *)llvm_cbe_tmp__269);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__270);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond1 = and i1 %%11, %%1 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_or_2e_cond1_count);
  llvm_cbe_or_2e_cond1 = (bool )((((llvm_cbe_tmp__270&4294967295U) == (0u&4294967295U)) & ((llvm_cbe_array_size&18446744073709551615ULL) != (0ull&18446744073709551615ULL)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond1 = 0x%X\n", llvm_cbe_or_2e_cond1);
  if (llvm_cbe_or_2e_cond1) {
    llvm_cbe_tmp__272__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_critedge;
  }

llvm_cbe_tmp__280:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([25 x i8]* @aesl_internal_.str2, i64 0, i64 0), i8* %%filename) nounwind, !dbg !11 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2260_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 25
#endif
])), ( char *)llvm_cbe_filename);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__271);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @exit(i32 -1) noreturn nounwind, !dbg !14 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2261_count);
   /*tail*/ exit(4294967295u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",4294967295u);
}
  /*UNREACHABLE*/;
  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = phi i64 [ %%16, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2263_count);
  llvm_cbe_tmp__272 = (unsigned long long )llvm_cbe_tmp__272__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__272);
printf("\n = 0x%I64X",llvm_cbe_tmp__273);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i64 %%15, 1, !dbg !11 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2264_count);
  llvm_cbe_tmp__273 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__272&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__273&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds float* %%3, i64 %%15, !dbg !11 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2268_count);
  llvm_cbe_tmp__274 = (float *)(&llvm_cbe_tmp__267[(((signed long long )llvm_cbe_tmp__272))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__272));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%8, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str3, i64 0, i64 0), float* %%17) nounwind, !dbg !11 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2269_count);
   /*tail*/ fscanf((l_struct_OC__iobuf *)llvm_cbe_tmp__269, ( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), (float *)llvm_cbe_tmp__274);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__275);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = tail call i32 @feof(%%struct._iobuf* %%8) nounwind, !dbg !11 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2271_count);
  llvm_cbe_tmp__276 = (unsigned int ) /*tail*/ feof((l_struct_OC__iobuf *)llvm_cbe_tmp__269);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__276);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = and i1 %%20, %%2 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )((((llvm_cbe_tmp__276&4294967295U) == (0u&4294967295U)) & (((unsigned long long )llvm_cbe_tmp__273&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_array_size&18446744073709551615ULL)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    llvm_cbe_tmp__272__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__273;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_critedge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e_critedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = tail call i32 @fclose(%%struct._iobuf* %%8) nounwind, !dbg !14 for 0x%I64xth hint within @k2c_read_array  --> \n", ++aesl_llvm_cbe_2275_count);
   /*tail*/ fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__269);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__277);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_read_array}\n");
  return llvm_cbe_tmp__267;
}

