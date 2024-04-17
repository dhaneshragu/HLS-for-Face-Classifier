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

/* Structure contents */
struct l_struct_OC_k2c_tensor {
  float field0[262200];
  unsigned long long field1;
  unsigned long long field2;
  signed long long field3[5];
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void k2c_global_max_pooling(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input);
void k2c_global_avg_pooling(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input);
void k2c_maxpool1d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long llvm_cbe_pool_size, signed long long llvm_cbe_stride);
void k2c_maxpool2d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_pool_size, signed long long *llvm_cbe_stride);
void k2c_avgpool1d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long llvm_cbe_pool_size, signed long long llvm_cbe_stride);
void k2c_avgpool2d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_pool_size, signed long long *llvm_cbe_stride);


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

void k2c_global_max_pooling(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input) {
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
  signed long long *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  signed long long *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  unsigned long long llvm_cbe_tmp__5;
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
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  signed long long *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge23_2e_us;
  unsigned long long llvm_cbe_storemerge23_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  float *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  float llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  float *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  float llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge15_2e_us;
  unsigned long long llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned long long llvm_cbe_storemerge7;
  unsigned long long llvm_cbe_storemerge7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  float *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  float llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  float *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond10_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_pr_count = 0;
  unsigned long long llvm_cbe__2e_pr;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_global_max_pooling\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 1, !dbg !8 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__1 = (signed long long *)(&llvm_cbe_input->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !8 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__2 = (unsigned long long )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add i64 %%2, -1, !dbg !8 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__3 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__3&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 %%3, !dbg !8 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__4 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )llvm_cbe_tmp__3))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__3));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i64* %%4, align 8, !dbg !8 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__5 = (unsigned long long )*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__5);
  if (((llvm_cbe_tmp__5&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader4;
  } else {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph9;
  }

llvm_cbe__2e_preheader4:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 2, !dbg !8 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__6 = (signed long long *)(&llvm_cbe_input->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i64* %%7, align 8, !dbg !8 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__7 = (unsigned long long )*llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__7);
  if (((llvm_cbe_tmp__7&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__20;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if (((llvm_cbe_tmp__5&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_thread_2d_pre_2d_split;
  } else {
    llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15.us = phi i64 [ %%11, %%10 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_storemerge15_2e_us_count);
  llvm_cbe_storemerge15_2e_us = (unsigned long long )llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15.us = 0x%I64X",llvm_cbe_storemerge15_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__8);
printf("\n = 0x%I64X",0ull);
}
  llvm_cbe_storemerge23_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__21;

llvm_cbe_tmp__22:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i64 %%storemerge15.us, %%5, !dbg !8 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__8 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge15_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__5&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__8&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i64* %%7, align 8, !dbg !8 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__9 = (unsigned long long )*llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__9);
  if ((((unsigned long long )llvm_cbe_tmp__8&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__9&18446744073709551615ULL))) {
    llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__8;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge6;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__21:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23.us = phi i64 [ 0, %%.lr.ph.us ], [ %%15, %%14  for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_storemerge23_2e_us_count);
  llvm_cbe_storemerge23_2e_us = (unsigned long long )llvm_cbe_storemerge23_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23.us = 0x%I64X",llvm_cbe_storemerge23_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__10);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge23.us, !dbg !7 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__11 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge23_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23.us = 0x%I64X",((signed long long )llvm_cbe_storemerge23_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load float* %%18, align 4, !dbg !7 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__12 = (float )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__12, *(int*)(&llvm_cbe_tmp__12));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add i64 %%storemerge23.us, %%storemerge15.us, !dbg !7 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__13 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge15_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__13&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%20, !dbg !7 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__14 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__13))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__13));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load float* %%21, align 4, !dbg !7 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__15 = (float )*llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__15, *(int*)(&llvm_cbe_tmp__15));
  if ((llvm_fcmp_olt(llvm_cbe_tmp__12, llvm_cbe_tmp__15))) {
    goto llvm_cbe_tmp__23;
  } else {
    goto llvm_cbe_tmp__24;
  }

llvm_cbe_tmp__24:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i64 %%storemerge23.us, 1, !dbg !9 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__10 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__10&18446744073709551615ull)));
  if (((llvm_cbe_tmp__10&18446744073709551615ULL) == (llvm_cbe_tmp__5&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__22;
  } else {
    llvm_cbe_storemerge23_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__10;   /* for PHI node */
    goto llvm_cbe_tmp__21;
  }

llvm_cbe_tmp__23:
if (AESL_DEBUG_TRACE)
printf("\n  store float %%22, float* %%18, align 4, !dbg !7 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_67_count);
  *llvm_cbe_tmp__11 = llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__15);
  goto llvm_cbe_tmp__24;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  do {     /* Syntactic loop '.lr.ph9' to make GCC happy */
llvm_cbe__2e_lr_2e_ph9:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = phi i64 [ %%27, %%.lr.ph9 ], [ 0, %%0  for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned long long )llvm_cbe_storemerge7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",llvm_cbe_storemerge7);
printf("\n = 0x%I64X",llvm_cbe_tmp__19);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%storemerge7, !dbg !6 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__16 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_storemerge7))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",((signed long long )llvm_cbe_storemerge7));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load float* %%24, align 4, !dbg !6 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__17 = (float )*llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__17, *(int*)(&llvm_cbe_tmp__17));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge7, !dbg !6 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__18 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge7))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",((signed long long )llvm_cbe_storemerge7));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%25, float* %%26, align 4, !dbg !6 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_86_count);
  *llvm_cbe_tmp__18 = llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add i64 %%storemerge7, 1, !dbg !8 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__19 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__19&18446744073709551615ull)));
  if (((llvm_cbe_tmp__19&18446744073709551615ULL) == (llvm_cbe_tmp__5&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader4;
  } else {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__19;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph9;
  }

  } while (1); /* end of syntactic loop '.lr.ph9' */
llvm_cbe_thread_2d_pre_2d_split:
if (AESL_DEBUG_TRACE)
printf("\n  %%.pr = load i64* %%7, align 8, !dbg !8 for 0x%I64xth hint within @k2c_global_max_pooling  --> \n", ++aesl_llvm_cbe__2e_pr_count);
  llvm_cbe__2e_pr = (unsigned long long )*llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n.pr = 0x%I64X\n", llvm_cbe__2e_pr);
  goto llvm_cbe_tmp__25;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__25:
  if (((llvm_cbe__2e_pr&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    goto llvm_cbe_tmp__25;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge6:
  goto llvm_cbe_tmp__20;

llvm_cbe_tmp__20:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_global_max_pooling}\n");
  return;
}


void k2c_global_avg_pooling(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input) {
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
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
  signed long long *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  unsigned long long llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  unsigned long long llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  signed long long *llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  unsigned long long llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
   char *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  signed long long *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned long long llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned long long llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
   char *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  signed long long *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned long long llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  float llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  float llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  unsigned long long llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge12_2e_us;
  unsigned long long llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  unsigned long long llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  float *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  float llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  float llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  float *llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  float llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  float llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  unsigned long long llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge3_2e_us;
  unsigned long long llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_pr_count = 0;
  unsigned long long llvm_cbe__2e_pr;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_global_avg_pooling\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 1, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__26 = (signed long long *)(&llvm_cbe_input->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__27 = (unsigned long long )*llvm_cbe_tmp__26;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add i64 %%2, -1, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__28 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__27&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__28&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 %%3, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__29 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )llvm_cbe_tmp__28))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__28));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i64* %%4, align 8, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__30 = (unsigned long long )*llvm_cbe_tmp__29;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = bitcast %%struct.k2c_tensor* %%output to i8*, !dbg !6 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__31 = ( char *)(( char *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !6 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__32 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i64* %%7, align 8, !dbg !6 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__33 = (unsigned long long )*llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = shl i64 %%8, 2, !dbg !6 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__34 = (unsigned long long )llvm_cbe_tmp__33 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i8* @memset(i8* %%6, i32 0, i64 %%9 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_141_count);
  ( char *)memset(( char *)llvm_cbe_tmp__31, 0u, llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__34);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__35);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 2, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__36 = (signed long long *)(&llvm_cbe_input->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i64* %%11, align 8, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__37 = (unsigned long long )*llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = udiv i64 %%12, %%5, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__38 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__37&18446744073709551615ull)) / ((unsigned long long )(llvm_cbe_tmp__30&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__38&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = uitofp i64 %%13 to float, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__39 = (float )((float )(unsigned long long )llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__39, *(int*)(&llvm_cbe_tmp__39));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fdiv float 1.000000e+00, %%14, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__40 = (float )((float )(0x1p0 / llvm_cbe_tmp__39));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__40, *(int*)(&llvm_cbe_tmp__40));
  if (((llvm_cbe_tmp__37&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__51;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if (((llvm_cbe_tmp__30&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_thread_2d_pre_2d_split;
  } else {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.us = phi i64 [ %%19, %%18 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_storemerge3_2e_us_count);
  llvm_cbe_storemerge3_2e_us = (unsigned long long )llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%I64X",llvm_cbe_storemerge3_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__41);
printf("\n = 0x%I64X",0ull);
}
  llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__52;

llvm_cbe_tmp__53:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%storemerge3.us, %%5, !dbg !8 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__41 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__30&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__41&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i64* %%11, align 8, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__42 = (unsigned long long )*llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__42);
  if ((((unsigned long long )llvm_cbe_tmp__41&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__42&18446744073709551615ULL))) {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__41;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge4;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__52:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i64 [ 0, %%.lr.ph.us ], [ %%30, %%22  for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned long long )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%I64X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__50);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add i64 %%storemerge12.us, %%storemerge3.us, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__43 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge3_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__43&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%23, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__44 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__43))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__43));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load float* %%24, align 4, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__45 = (float )*llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__45, *(int*)(&llvm_cbe_tmp__45));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = fmul float %%25, %%15, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__46 = (float )((float )(llvm_cbe_tmp__45 * llvm_cbe_tmp__40));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__46, *(int*)(&llvm_cbe_tmp__46));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge12.us, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__47 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge12_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%I64X",((signed long long )llvm_cbe_storemerge12_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load float* %%27, align 4, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__48 = (float )*llvm_cbe_tmp__47;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__48, *(int*)(&llvm_cbe_tmp__48));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = fadd float %%28, %%26, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__49 = (float )((float )(llvm_cbe_tmp__48 + llvm_cbe_tmp__46));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__49, *(int*)(&llvm_cbe_tmp__49));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%29, float* %%27, align 4, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_172_count);
  *llvm_cbe_tmp__47 = llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add i64 %%storemerge12.us, 1, !dbg !8 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__50 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__50&18446744073709551615ull)));
  if (((llvm_cbe_tmp__50&18446744073709551615ULL) == (llvm_cbe_tmp__30&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__53;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__50;   /* for PHI node */
    goto llvm_cbe_tmp__52;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe_thread_2d_pre_2d_split:
if (AESL_DEBUG_TRACE)
printf("\n  %%.pr = load i64* %%11, align 8, !dbg !7 for 0x%I64xth hint within @k2c_global_avg_pooling  --> \n", ++aesl_llvm_cbe__2e_pr_count);
  llvm_cbe__2e_pr = (unsigned long long )*llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n.pr = 0x%I64X\n", llvm_cbe__2e_pr);
  goto llvm_cbe_tmp__54;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__54:
  if (((llvm_cbe__2e_pr&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge4;
  } else {
    goto llvm_cbe_tmp__54;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge4:
  goto llvm_cbe_tmp__51;

llvm_cbe_tmp__51:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_global_avg_pooling}\n");
  return;
}


void k2c_maxpool1d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long llvm_cbe_pool_size, signed long long llvm_cbe_stride) {
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  signed long long *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  unsigned long long llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
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
  signed long long *llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  unsigned long long llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  unsigned long long llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned long long llvm_cbe_storemerge7;
  unsigned long long llvm_cbe_storemerge7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  unsigned long long llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  unsigned long long llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  unsigned long long llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  unsigned long long llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  float llvm_cbe_tmp__66;
  float llvm_cbe_tmp__66__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  unsigned long long llvm_cbe_tmp__67;
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
  float llvm_cbe_tmp__68;
  float llvm_cbe_tmp__68__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge23_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge23_2e_us;
  unsigned long long llvm_cbe_storemerge23_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  unsigned long long llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  float *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  float llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge14_2e_us;
  unsigned long long llvm_cbe_storemerge14_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  unsigned long long llvm_cbe_tmp__72;
  unsigned long long llvm_cbe_tmp__72__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  unsigned long long llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  float *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  float llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  unsigned long long llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  float *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned long long llvm_cbe_storemerge14;
  unsigned long long llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  unsigned long long llvm_cbe_tmp__78__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  unsigned long long llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  float *llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  float llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  unsigned long long llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  float *llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  unsigned long long llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  unsigned long long llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  unsigned long long llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  unsigned long long llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  unsigned long long llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_maxpool1d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !8 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__55 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !8 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__56 = (unsigned long long )*llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__56);
  if (((llvm_cbe_tmp__56&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge10;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 0, !dbg !6 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_232_count);
  llvm_cbe_tmp__57 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = mul i64 %%2, %%pool_size, !dbg !8 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_233_count);
  llvm_cbe_tmp__58 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__56&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_pool_size&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__58&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = mul i64 %%2, %%stride, !dbg !8 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_235_count);
  llvm_cbe_tmp__59 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__56&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_stride&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__59&18446744073709551615ull)));
  llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = phi i64 [ 0, %%.preheader.lr.ph ], [ %%47, %%46  for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned long long )llvm_cbe_storemerge7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",llvm_cbe_storemerge7);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__88);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i64* %%4, align 8, !dbg !6 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_241_count);
  llvm_cbe_tmp__60 = (unsigned long long )*llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul i64 %%8, %%2, !dbg !6 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__61 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__60&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__56&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__61&18446744073709551615ull)));
  if (((llvm_cbe_tmp__61&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__89;
  } else {
    goto llvm_cbe__2e_lr_2e_ph5;
  }

llvm_cbe_tmp__89:
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = add i64 %%storemerge7, 1, !dbg !9 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_323_count);
  llvm_cbe_tmp__88 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__88&18446744073709551615ull)));
  if (((llvm_cbe_tmp__88&18446744073709551615ULL) == (llvm_cbe_tmp__56&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge10;
  } else {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__88;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe__2e__crit_edge6:
  goto llvm_cbe_tmp__89;

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14.us = phi i64 [ %%13, %%11 ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_storemerge14_2e_us_count);
  llvm_cbe_storemerge14_2e_us = (unsigned long long )llvm_cbe_storemerge14_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14.us = 0x%I64X",llvm_cbe_storemerge14_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__63);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = phi i64 [ %%12, %%11 ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_280_count);
  llvm_cbe_tmp__72 = (unsigned long long )llvm_cbe_tmp__72__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__72);
printf("\n = 0x%I64X",llvm_cbe_tmp__62);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i64 %%storemerge14.us, %%storemerge7, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_281_count);
  llvm_cbe_tmp__73 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__73&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%29, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__74 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__73))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__73));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load float* %%30, align 4, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_283_count);
  llvm_cbe_tmp__75 = (float )*llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__75, *(int*)(&llvm_cbe_tmp__75));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i64 %%28, %%storemerge7, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_284_count);
  llvm_cbe_tmp__76 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__72&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__76&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%32, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_285_count);
  llvm_cbe_tmp__77 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__76))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__76));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%31, float* %%33, align 4, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_286_count);
  *llvm_cbe_tmp__77 = llvm_cbe_tmp__75;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__75);
  llvm_cbe_tmp__68__PHI_TEMPORARY = (float )llvm_cbe_tmp__75;   /* for PHI node */
  llvm_cbe_storemerge23_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__90;

llvm_cbe_tmp__91:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i64 %%28, %%2, !dbg !8 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__62 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__72&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__56&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__62&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i64 %%storemerge14.us, %%7, !dbg !8 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_253_count);
  llvm_cbe_tmp__63 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__59&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__63&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%4, align 8, !dbg !6 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_259_count);
  llvm_cbe_tmp__64 = (unsigned long long )*llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = mul i64 %%14, %%2, !dbg !6 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_260_count);
  llvm_cbe_tmp__65 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__64&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__56&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__65&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__62&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__65&18446744073709551615ULL))) {
    llvm_cbe_storemerge14_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__63;   /* for PHI node */
    llvm_cbe_tmp__72__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__62;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge6;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__90:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = phi float [ %%31, %%.lr.ph.us ], [ %%18, %%17 ], !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_274_count);
  llvm_cbe_tmp__68 = (float )llvm_cbe_tmp__68__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__68);
printf("\n = %f",llvm_cbe_tmp__75);
printf("\n = %f",llvm_cbe_tmp__66);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23.us = phi i64 [ 0, %%.lr.ph.us ], [ %%19, %%17  for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_storemerge23_2e_us_count);
  llvm_cbe_storemerge23_2e_us = (unsigned long long )llvm_cbe_storemerge23_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23.us = 0x%I64X",llvm_cbe_storemerge23_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__67);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i64 %%storemerge23.us, %%29, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__69 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__73&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__69&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%24, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_276_count);
  llvm_cbe_tmp__70 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__69))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__69));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load float* %%25, align 4, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_277_count);
  llvm_cbe_tmp__71 = (float )*llvm_cbe_tmp__70;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__71, *(int*)(&llvm_cbe_tmp__71));
  if ((llvm_fcmp_olt(llvm_cbe_tmp__68, llvm_cbe_tmp__71))) {
    goto llvm_cbe_tmp__92;
  } else {
    llvm_cbe_tmp__66__PHI_TEMPORARY = (float )llvm_cbe_tmp__68;   /* for PHI node */
    goto llvm_cbe_tmp__93;
  }

llvm_cbe_tmp__93:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = phi float [ %%23, %%22 ], [ %%26, %%21  for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__66 = (float )llvm_cbe_tmp__66__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__66);
printf("\n = %f",llvm_cbe_tmp__68);
printf("\n = %f",llvm_cbe_tmp__71);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%storemerge23.us, %%2, !dbg !9 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_264_count);
  llvm_cbe_tmp__67 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__56&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__67&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__67&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__58&18446744073709551615ULL))) {
    llvm_cbe_tmp__68__PHI_TEMPORARY = (float )llvm_cbe_tmp__66;   /* for PHI node */
    llvm_cbe_storemerge23_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__67;   /* for PHI node */
    goto llvm_cbe_tmp__90;
  } else {
    goto llvm_cbe_tmp__91;
  }

llvm_cbe_tmp__92:
if (AESL_DEBUG_TRACE)
printf("\n  store float %%26, float* %%33, align 4, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_272_count);
  *llvm_cbe_tmp__77 = llvm_cbe_tmp__71;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__71);
  llvm_cbe_tmp__66__PHI_TEMPORARY = (float )llvm_cbe_tmp__71;   /* for PHI node */
  goto llvm_cbe_tmp__93;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e_lr_2e_ph5:
  if (((llvm_cbe_tmp__58&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__78__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe_tmp__94;
  } else {
    llvm_cbe_storemerge14_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__72__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__94:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i64 [ %%42, %%34 ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned long long )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%I64X",llvm_cbe_storemerge14);
printf("\n = 0x%I64X",llvm_cbe_tmp__85);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = phi i64 [ %%41, %%34 ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_293_count);
  llvm_cbe_tmp__78 = (unsigned long long )llvm_cbe_tmp__78__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__78);
printf("\n = 0x%I64X",llvm_cbe_tmp__84);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = add i64 %%storemerge14, %%storemerge7, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_294_count);
  llvm_cbe_tmp__79 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__79&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%36, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_295_count);
  llvm_cbe_tmp__80 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__79))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__79));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load float* %%37, align 4, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_296_count);
  llvm_cbe_tmp__81 = (float )*llvm_cbe_tmp__80;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__81, *(int*)(&llvm_cbe_tmp__81));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i64 %%35, %%storemerge7, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_297_count);
  llvm_cbe_tmp__82 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__78&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__82&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%39, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_298_count);
  llvm_cbe_tmp__83 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__82))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__82));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%38, float* %%40, align 4, !dbg !7 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_299_count);
  *llvm_cbe_tmp__83 = llvm_cbe_tmp__81;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add i64 %%35, %%2, !dbg !8 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__84 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__78&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__56&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__84&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add i64 %%storemerge14, %%7, !dbg !8 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__85 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__59&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__85&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i64* %%4, align 8, !dbg !6 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__86 = (unsigned long long )*llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = mul i64 %%43, %%2, !dbg !6 for 0x%I64xth hint within @k2c_maxpool1d  --> \n", ++aesl_llvm_cbe_319_count);
  llvm_cbe_tmp__87 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__86&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__56&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__87&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__84&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__87&18446744073709551615ULL))) {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__85;   /* for PHI node */
    llvm_cbe_tmp__78__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__84;   /* for PHI node */
    goto llvm_cbe_tmp__94;
  } else {
    goto llvm_cbe__2e__crit_edge6;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge10:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_maxpool1d}\n");
  return;
}


void k2c_maxpool2d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_pool_size, signed long long *llvm_cbe_stride) {
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
  signed long long *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  unsigned long long llvm_cbe_tmp__96;
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
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  signed long long *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  signed long long *llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  signed long long *llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  signed long long *llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  signed long long *llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_count = 0;
  unsigned long long llvm_cbe_storemerge15;
  unsigned long long llvm_cbe_storemerge15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  unsigned long long llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  unsigned long long llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge113_count = 0;
  unsigned long long llvm_cbe_storemerge113;
  unsigned long long llvm_cbe_storemerge113__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  unsigned long long llvm_cbe_tmp__104__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  unsigned long long llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  unsigned long long llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  unsigned long long llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge29_count = 0;
  unsigned long long llvm_cbe_storemerge29;
  unsigned long long llvm_cbe_storemerge29__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  unsigned long long llvm_cbe_tmp__108;
  unsigned long long llvm_cbe_tmp__108__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  unsigned long long llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  float *llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  float llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  unsigned long long llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  float *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  unsigned long long llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  unsigned long long llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  float llvm_cbe_tmp__116;
  float llvm_cbe_tmp__116__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge36_count = 0;
  unsigned long long llvm_cbe_storemerge36;
  unsigned long long llvm_cbe_storemerge36__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  unsigned long long llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  unsigned long long llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  unsigned long long llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  unsigned long long llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  unsigned long long llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  float llvm_cbe_tmp__122;
  float llvm_cbe_tmp__122__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge45_count = 0;
  unsigned long long llvm_cbe_storemerge45;
  unsigned long long llvm_cbe_storemerge45__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  unsigned long long llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  float *llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  float llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  float llvm_cbe_tmp__126;
  float llvm_cbe_tmp__126__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  unsigned long long llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  unsigned long long llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  unsigned long long llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  unsigned long long llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  unsigned long long llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  unsigned long long llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  float llvm_cbe_tmp__133;
  float llvm_cbe_tmp__133__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  unsigned long long llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  unsigned long long llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  unsigned long long llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  unsigned long long llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  unsigned long long llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  unsigned long long llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  unsigned long long llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  unsigned long long llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  unsigned long long llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  unsigned long long llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  unsigned long long llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  unsigned long long llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  unsigned long long llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  unsigned long long llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  unsigned long long llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  unsigned long long llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  unsigned long long llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  unsigned long long llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  unsigned long long llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_maxpool2d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 2, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_356_count);
  llvm_cbe_tmp__95 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__96 = (unsigned long long )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__96);
  if (((llvm_cbe_tmp__96&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge16;
  } else {
    goto llvm_cbe__2e_preheader12_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader12_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 1, !dbg !6 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_380_count);
  llvm_cbe_tmp__97 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_381_count);
  llvm_cbe_tmp__98 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds i64* %%stride, i64 1, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_382_count);
  llvm_cbe_tmp__99 = (signed long long *)(&llvm_cbe_stride[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i64* %%pool_size, i64 1, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_383_count);
  llvm_cbe_tmp__100 = (signed long long *)(&llvm_cbe_pool_size[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_384_count);
  llvm_cbe_tmp__101 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader12;

  do {     /* Syntactic loop '.preheader12' to make GCC happy */
llvm_cbe__2e_preheader12:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15 = phi i64 [ 0, %%.preheader12.lr.ph ], [ %%72, %%._crit_edge14  for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_storemerge15_count);
  llvm_cbe_storemerge15 = (unsigned long long )llvm_cbe_storemerge15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",llvm_cbe_storemerge15);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__152);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%4, align 8, !dbg !6 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_390_count);
  llvm_cbe_tmp__102 = (unsigned long long )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = mul i64 %%9, %%2, !dbg !6 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_391_count);
  llvm_cbe_tmp__103 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__102&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__103&18446744073709551615ull)));
  if (((llvm_cbe_tmp__103&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge14;
  } else {
    llvm_cbe_storemerge113__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__104__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader8;
  }

llvm_cbe__2e__crit_edge14:
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = add i64 %%storemerge15, 1, !dbg !10 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_508_count);
  llvm_cbe_tmp__152 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge15&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__152&18446744073709551615ull)));
  if (((llvm_cbe_tmp__152&18446744073709551615ULL) == (llvm_cbe_tmp__96&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge16;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__152;   /* for PHI node */
    goto llvm_cbe__2e_preheader12;
  }

  do {     /* Syntactic loop '.preheader8' to make GCC happy */
llvm_cbe__2e_preheader8:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge113 = phi i64 [ %%68, %%._crit_edge11 ], [ 0, %%.preheader12  for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_storemerge113_count);
  llvm_cbe_storemerge113 = (unsigned long long )llvm_cbe_storemerge113__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge113 = 0x%I64X",llvm_cbe_storemerge113);
printf("\n = 0x%I64X",llvm_cbe_tmp__149);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = phi i64 [ %%65, %%._crit_edge11 ], [ 0, %%.preheader12  for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_394_count);
  llvm_cbe_tmp__104 = (unsigned long long )llvm_cbe_tmp__104__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__104);
printf("\n = 0x%I64X",llvm_cbe_tmp__146);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i64* %%5, align 8, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_399_count);
  llvm_cbe_tmp__105 = (unsigned long long )*llvm_cbe_tmp__98;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__105);
  if (((llvm_cbe_tmp__105&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge11;
  } else {
    goto llvm_cbe__2e_lr_2e_ph10;
  }

llvm_cbe__2e__crit_edge11:
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = add i64 %%12, %%2, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_489_count);
  llvm_cbe_tmp__146 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__104&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__146&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = load i64* %%6, align 8, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_496_count);
  llvm_cbe_tmp__147 = (unsigned long long )*llvm_cbe_tmp__99;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__147);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = mul i64 %%66, %%2, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_497_count);
  llvm_cbe_tmp__148 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__147&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__148&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = add i64 %%67, %%storemerge113, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_498_count);
  llvm_cbe_tmp__149 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__148&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge113&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__149&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = load i64* %%4, align 8, !dbg !6 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_504_count);
  llvm_cbe_tmp__150 = (unsigned long long )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__150);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = mul i64 %%69, %%2, !dbg !6 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_505_count);
  llvm_cbe_tmp__151 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__150&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__151&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__146&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__151&18446744073709551615ULL))) {
    llvm_cbe_storemerge113__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__149;   /* for PHI node */
    llvm_cbe_tmp__104__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__146;   /* for PHI node */
    goto llvm_cbe__2e_preheader8;
  } else {
    goto llvm_cbe__2e__crit_edge14;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__153:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge29 = phi i64 [ 0, %%.lr.ph10 ], [ %%62, %%._crit_edge7  for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_storemerge29_count);
  llvm_cbe_storemerge29 = (unsigned long long )llvm_cbe_storemerge29__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge29 = 0x%I64X",llvm_cbe_storemerge29);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__144);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = phi i64 [ 0, %%.lr.ph10 ], [ %%57, %%._crit_edge7  for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_405_count);
  llvm_cbe_tmp__108 = (unsigned long long )llvm_cbe_tmp__108__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__108);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__139);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%15, %%storemerge29, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_406_count);
  llvm_cbe_tmp__109 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__106&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge29&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__109&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%19, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_407_count);
  llvm_cbe_tmp__110 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__109))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__109));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load float* %%20, align 4, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_408_count);
  llvm_cbe_tmp__111 = (float )*llvm_cbe_tmp__110;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__111, *(int*)(&llvm_cbe_tmp__111));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add i64 %%16, %%18, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_409_count);
  llvm_cbe_tmp__112 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__107&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__108&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__112&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%22, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_410_count);
  llvm_cbe_tmp__113 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__112))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__112));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%21, float* %%23, align 4, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_411_count);
  *llvm_cbe_tmp__113 = llvm_cbe_tmp__111;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i64* %%7, align 8, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_417_count);
  llvm_cbe_tmp__114 = (unsigned long long )*llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = mul i64 %%24, %%2, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_418_count);
  llvm_cbe_tmp__115 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__114&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__115&18446744073709551615ull)));
  if (((llvm_cbe_tmp__115&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge7;
  } else {
    llvm_cbe_tmp__116__PHI_TEMPORARY = (float )llvm_cbe_tmp__111;   /* for PHI node */
    llvm_cbe_storemerge36__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe__2e__crit_edge7:
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = load i64* %%4, align 8, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_467_count);
  llvm_cbe_tmp__137 = (unsigned long long )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = mul i64 %%55, %%2, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_468_count);
  llvm_cbe_tmp__138 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__137&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__138&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = add i64 %%56, %%18, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_469_count);
  llvm_cbe_tmp__139 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__138&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__108&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__139&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = load i64* %%8, align 8, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_476_count);
  llvm_cbe_tmp__140 = (unsigned long long )*llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i64* %%stride, align 8, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_477_count);
  llvm_cbe_tmp__141 = (unsigned long long )*llvm_cbe_stride;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__141);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = mul i64 %%58, %%2, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_478_count);
  llvm_cbe_tmp__142 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__140&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__142&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = mul i64 %%60, %%59, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_479_count);
  llvm_cbe_tmp__143 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__142&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__141&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__143&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = add i64 %%61, %%storemerge29, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_480_count);
  llvm_cbe_tmp__144 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__143&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge29&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__144&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i64* %%5, align 8, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_486_count);
  llvm_cbe_tmp__145 = (unsigned long long )*llvm_cbe_tmp__98;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__145);
  if ((((unsigned long long )llvm_cbe_tmp__139&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__145&18446744073709551615ULL))) {
    llvm_cbe_storemerge29__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__144;   /* for PHI node */
    llvm_cbe_tmp__108__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__139;   /* for PHI node */
    goto llvm_cbe_tmp__153;
  } else {
    goto llvm_cbe__2e__crit_edge11;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = phi float [ %%50, %%._crit_edge ], [ %%21, %%17  for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_421_count);
  llvm_cbe_tmp__116 = (float )llvm_cbe_tmp__116__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__116);
printf("\n = %f",llvm_cbe_tmp__133);
printf("\n = %f",llvm_cbe_tmp__111);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge36 = phi i64 [ %%51, %%._crit_edge ], [ 0, %%17  for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_storemerge36_count);
  llvm_cbe_storemerge36 = (unsigned long long )llvm_cbe_storemerge36__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge36 = 0x%I64X",llvm_cbe_storemerge36);
printf("\n = 0x%I64X",llvm_cbe_tmp__134);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i64* %%pool_size, align 8, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_426_count);
  llvm_cbe_tmp__117 = (unsigned long long )*llvm_cbe_pool_size;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__117);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i64* %%8, align 8, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_427_count);
  llvm_cbe_tmp__118 = (unsigned long long )*llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__118);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = mul i64 %%28, %%2, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_428_count);
  llvm_cbe_tmp__119 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__117&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__119&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = mul i64 %%30, %%29, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_429_count);
  llvm_cbe_tmp__120 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__119&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__118&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__120&18446744073709551615ull)));
  if (((llvm_cbe_tmp__120&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe_tmp__133__PHI_TEMPORARY = (float )llvm_cbe_tmp__116;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = phi float [ %%27, %%.preheader ], [ %%42, %%41  for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_456_count);
  llvm_cbe_tmp__133 = (float )llvm_cbe_tmp__133__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__133);
printf("\n = %f",llvm_cbe_tmp__116);
printf("\n = %f",llvm_cbe_tmp__126);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = add i64 %%storemerge36, %%2, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_457_count);
  llvm_cbe_tmp__134 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge36&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__134&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i64* %%7, align 8, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_463_count);
  llvm_cbe_tmp__135 = (unsigned long long )*llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = mul i64 %%52, %%2, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_464_count);
  llvm_cbe_tmp__136 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__135&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__136&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__134&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__136&18446744073709551615ULL))) {
    llvm_cbe_tmp__116__PHI_TEMPORARY = (float )llvm_cbe_tmp__133;   /* for PHI node */
    llvm_cbe_storemerge36__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__134;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e__crit_edge7;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__154:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = phi float [ %%27, %%.lr.ph ], [ %%42, %%41 ], !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_434_count);
  llvm_cbe_tmp__122 = (float )llvm_cbe_tmp__122__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__122);
printf("\n = %f",llvm_cbe_tmp__116);
printf("\n = %f",llvm_cbe_tmp__126);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge45 = phi i64 [ 0, %%.lr.ph ], [ %%45, %%41  for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_storemerge45_count);
  llvm_cbe_storemerge45 = (unsigned long long )llvm_cbe_storemerge45__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge45 = 0x%I64X",llvm_cbe_storemerge45);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__129);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = add i64 %%33, %%storemerge45, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_435_count);
  llvm_cbe_tmp__123 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__121&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge45&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__123&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%36, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_436_count);
  llvm_cbe_tmp__124 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__123))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__123));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load float* %%37, align 4, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_437_count);
  llvm_cbe_tmp__125 = (float )*llvm_cbe_tmp__124;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__125, *(int*)(&llvm_cbe_tmp__125));
  if ((llvm_fcmp_olt(llvm_cbe_tmp__122, llvm_cbe_tmp__125))) {
    goto llvm_cbe_tmp__155;
  } else {
    llvm_cbe_tmp__126__PHI_TEMPORARY = (float )llvm_cbe_tmp__122;   /* for PHI node */
    goto llvm_cbe_tmp__156;
  }

llvm_cbe_tmp__156:
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = phi float [ %%35, %%34 ], [ %%38, %%40  for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_442_count);
  llvm_cbe_tmp__126 = (float )llvm_cbe_tmp__126__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__126);
printf("\n = %f",llvm_cbe_tmp__122);
printf("\n = %f",llvm_cbe_tmp__125);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i64* %%8, align 8, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_443_count);
  llvm_cbe_tmp__127 = (unsigned long long )*llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__127);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = mul i64 %%43, %%2, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_444_count);
  llvm_cbe_tmp__128 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__127&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__128&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add i64 %%44, %%storemerge45, !dbg !9 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_445_count);
  llvm_cbe_tmp__129 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__128&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge45&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__129&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i64* %%pool_size, align 8, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_451_count);
  llvm_cbe_tmp__130 = (unsigned long long )*llvm_cbe_pool_size;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = mul i64 %%46, %%2, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_452_count);
  llvm_cbe_tmp__131 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__130&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__131&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = mul i64 %%47, %%43, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_453_count);
  llvm_cbe_tmp__132 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__131&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__127&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__132&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__129&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__132&18446744073709551615ULL))) {
    llvm_cbe_tmp__122__PHI_TEMPORARY = (float )llvm_cbe_tmp__126;   /* for PHI node */
    llvm_cbe_storemerge45__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__129;   /* for PHI node */
    goto llvm_cbe_tmp__154;
  } else {
    llvm_cbe_tmp__133__PHI_TEMPORARY = (float )llvm_cbe_tmp__126;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe_tmp__155:
if (AESL_DEBUG_TRACE)
printf("\n  store float %%38, float* %%23, align 4, !dbg !8 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_440_count);
  *llvm_cbe_tmp__113 = llvm_cbe_tmp__125;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__125);
  llvm_cbe_tmp__126__PHI_TEMPORARY = (float )llvm_cbe_tmp__125;   /* for PHI node */
  goto llvm_cbe_tmp__156;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add i64 %%storemerge36, %%19, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_432_count);
  llvm_cbe_tmp__121 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge36&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__109&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__121&18446744073709551615ull)));
  llvm_cbe_tmp__122__PHI_TEMPORARY = (float )llvm_cbe_tmp__116;   /* for PHI node */
  llvm_cbe_storemerge45__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__154;

  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph10:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i64 %%storemerge113, %%storemerge15, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_402_count);
  llvm_cbe_tmp__106 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge113&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge15&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__106&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i64 %%12, %%storemerge15, !dbg !7 for 0x%I64xth hint within @k2c_maxpool2d  --> \n", ++aesl_llvm_cbe_403_count);
  llvm_cbe_tmp__107 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__104&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge15&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__107&18446744073709551615ull)));
  llvm_cbe_storemerge29__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__108__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__153;

  } while (1); /* end of syntactic loop '.preheader8' */
  } while (1); /* end of syntactic loop '.preheader12' */
llvm_cbe__2e__crit_edge16:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_maxpool2d}\n");
  return;
}

static const ConstantFloatTy FPConstant0 = 0xFF800000U;    /* -inf */

void k2c_avgpool1d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long llvm_cbe_pool_size, signed long long llvm_cbe_stride) {
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
  signed long long *llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  unsigned long long llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
   char *llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  signed long long *llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  unsigned long long llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  unsigned long long llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
   char *llvm_cbe_tmp__163;
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
  unsigned long long llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  unsigned long long llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned long long llvm_cbe_storemerge7;
  unsigned long long llvm_cbe_storemerge7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  unsigned long long llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  float llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  unsigned long long llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  float *llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  float llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  float llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  unsigned long long llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  unsigned long long llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  unsigned long long llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  unsigned int llvm_cbe_tmp__175;
  unsigned int llvm_cbe_tmp__175__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  unsigned long long llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  float llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  float llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  unsigned int llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge23_2e_us;
  unsigned long long llvm_cbe_storemerge23_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  unsigned int llvm_cbe_tmp__180;
  unsigned int llvm_cbe_tmp__180__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  unsigned long long llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  float *llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  float llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge15_2e_us;
  unsigned long long llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  unsigned long long llvm_cbe_tmp__184;
  unsigned long long llvm_cbe_tmp__184__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  unsigned long long llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  unsigned long long llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  float *llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  unsigned long long llvm_cbe_tmp__188;
  unsigned long long llvm_cbe_tmp__188__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  unsigned long long llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  float *llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  float llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  float llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  unsigned long long llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  unsigned long long llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  unsigned long long llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_avgpool1d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !8 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_534_count);
  llvm_cbe_tmp__157 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !8 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_535_count);
  llvm_cbe_tmp__158 = (unsigned long long )*llvm_cbe_tmp__157;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__158);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast %%struct.k2c_tensor* %%output to i8*, !dbg !6 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_542_count);
  llvm_cbe_tmp__159 = ( char *)(( char *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !6 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_543_count);
  llvm_cbe_tmp__160 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i64* %%4, align 8, !dbg !6 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__161 = (unsigned long long )*llvm_cbe_tmp__160;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = shl i64 %%5, 2, !dbg !6 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_545_count);
  llvm_cbe_tmp__162 = (unsigned long long )llvm_cbe_tmp__161 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__162);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = call i8* @memset(i8* %%3, i32 0, i64 %%6 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_546_count);
  ( char *)memset(( char *)llvm_cbe_tmp__159, 0u, llvm_cbe_tmp__162);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__162);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__163);
}
  if (((llvm_cbe_tmp__158&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge10;
  } else {
    goto llvm_cbe__2e_preheader4_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader4_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul i64 %%2, %%pool_size, !dbg !8 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_556_count);
  llvm_cbe_tmp__164 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__158&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_pool_size&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__164&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = mul i64 %%2, %%stride, !dbg !8 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_558_count);
  llvm_cbe_tmp__165 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__158&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_stride&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__165&18446744073709551615ull)));
  llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader4;

  do {     /* Syntactic loop '.preheader4' to make GCC happy */
llvm_cbe__2e_preheader4:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = phi i64 [ 0, %%.preheader4.lr.ph ], [ %%52, %%51  for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned long long )llvm_cbe_storemerge7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",llvm_cbe_storemerge7);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__195);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i64* %%4, align 8, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_563_count);
  llvm_cbe_tmp__166 = (unsigned long long )*llvm_cbe_tmp__160;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__166);
  if (((llvm_cbe_tmp__166&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__196;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe_tmp__196:
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = add i64 %%storemerge7, 1, !dbg !9 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_639_count);
  llvm_cbe_tmp__195 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__195&18446744073709551615ull)));
  if (((llvm_cbe_tmp__195&18446744073709551615ULL) == (llvm_cbe_tmp__158&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge10;
  } else {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__195;   /* for PHI node */
    goto llvm_cbe__2e_preheader4;
  }

llvm_cbe__2e__crit_edge6:
  goto llvm_cbe_tmp__196;

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15.us = phi i64 [ %%21, %%14 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_storemerge15_2e_us_count);
  llvm_cbe_storemerge15_2e_us = (unsigned long long )llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15.us = 0x%I64X",llvm_cbe_storemerge15_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__173);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = phi i64 [ %%20, %%14 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_610_count);
  llvm_cbe_tmp__184 = (unsigned long long )llvm_cbe_tmp__184__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__184);
printf("\n = 0x%I64X",llvm_cbe_tmp__172);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i64 %%storemerge15.us, %%storemerge7, !dbg !8 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_615_count);
  llvm_cbe_tmp__185 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge15_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__185&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add i64 %%38, %%storemerge7, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_616_count);
  llvm_cbe_tmp__186 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__184&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__186&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%40, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_617_count);
  llvm_cbe_tmp__187 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__186))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__186));
}
  llvm_cbe_storemerge23_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__180__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__197;

llvm_cbe_tmp__198:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sitofp i32 %%25 to float, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_567_count);
  llvm_cbe_tmp__167 = (float )((float )(signed int )llvm_cbe_tmp__175);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__167, *(int*)(&llvm_cbe_tmp__167));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i64 %%38, %%storemerge7, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_568_count);
  llvm_cbe_tmp__168 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__184&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__168&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%16, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_569_count);
  llvm_cbe_tmp__169 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__168))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__168));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* %%17, align 4, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_570_count);
  llvm_cbe_tmp__170 = (float )*llvm_cbe_tmp__169;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__170, *(int*)(&llvm_cbe_tmp__170));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = fdiv float %%18, %%15, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_571_count);
  llvm_cbe_tmp__171 = (float )((float )(llvm_cbe_tmp__170 / llvm_cbe_tmp__167));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__171, *(int*)(&llvm_cbe_tmp__171));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%19, float* %%17, align 4, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_572_count);
  *llvm_cbe_tmp__169 = llvm_cbe_tmp__171;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__171);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add i64 %%38, %%2, !dbg !8 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_573_count);
  llvm_cbe_tmp__172 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__184&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__158&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__172&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add i64 %%storemerge15.us, %%11, !dbg !8 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_579_count);
  llvm_cbe_tmp__173 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge15_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__165&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__173&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i64* %%4, align 8, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_584_count);
  llvm_cbe_tmp__174 = (unsigned long long )*llvm_cbe_tmp__160;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__174);
  if ((((unsigned long long )llvm_cbe_tmp__172&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__174&18446744073709551615ULL))) {
    llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__173;   /* for PHI node */
    llvm_cbe_tmp__184__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__172;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge6;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__197:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23.us = phi i64 [ 0, %%.lr.ph.us ], [ %%26, %%24  for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_storemerge23_2e_us_count);
  llvm_cbe_storemerge23_2e_us = (unsigned long long )llvm_cbe_storemerge23_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23.us = 0x%I64X",llvm_cbe_storemerge23_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__176);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = phi i32 [ 0, %%.lr.ph.us ], [ %%25, %%24  for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_604_count);
  llvm_cbe_tmp__180 = (unsigned int )llvm_cbe_tmp__180__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__180);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__175);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add i64 %%39, %%storemerge23.us, !dbg !8 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_605_count);
  llvm_cbe_tmp__181 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__185&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge23_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__181&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%34, !dbg !8 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_606_count);
  llvm_cbe_tmp__182 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__181))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__181));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load float* %%35, align 4, !dbg !8 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_607_count);
  llvm_cbe_tmp__183 = (float )*llvm_cbe_tmp__182;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__183, *(int*)(&llvm_cbe_tmp__183));
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__183, (*(float*)&FPConstant0)))) {
    goto llvm_cbe_tmp__199;
  } else {
    llvm_cbe_tmp__175__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__180;   /* for PHI node */
    goto llvm_cbe_tmp__200;
  }

llvm_cbe_tmp__200:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = phi i32 [ %%33, %%32 ], [ %%31, %%28  for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_587_count);
  llvm_cbe_tmp__175 = (unsigned int )llvm_cbe_tmp__175__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__175);
printf("\n = 0x%X",llvm_cbe_tmp__180);
printf("\n = 0x%X",llvm_cbe_tmp__179);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i64 %%storemerge23.us, %%2, !dbg !9 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_588_count);
  llvm_cbe_tmp__176 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__158&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__176&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__176&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__164&18446744073709551615ULL))) {
    llvm_cbe_storemerge23_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__176;   /* for PHI node */
    llvm_cbe_tmp__180__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__175;   /* for PHI node */
    goto llvm_cbe_tmp__197;
  } else {
    goto llvm_cbe_tmp__198;
  }

llvm_cbe_tmp__199:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load float* %%41, align 4, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_596_count);
  llvm_cbe_tmp__177 = (float )*llvm_cbe_tmp__187;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__177, *(int*)(&llvm_cbe_tmp__177));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = fadd float %%29, %%36, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_597_count);
  llvm_cbe_tmp__178 = (float )((float )(llvm_cbe_tmp__177 + llvm_cbe_tmp__183));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__178, *(int*)(&llvm_cbe_tmp__178));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%30, float* %%41, align 4, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_598_count);
  *llvm_cbe_tmp__187 = llvm_cbe_tmp__178;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__178);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%33, 1, !dbg !9 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_599_count);
  llvm_cbe_tmp__179 = (unsigned int )((unsigned int )(llvm_cbe_tmp__180&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__179&4294967295ull)));
  llvm_cbe_tmp__175__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__179;   /* for PHI node */
  goto llvm_cbe_tmp__200;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if (((llvm_cbe_tmp__164&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe_tmp__188__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe_tmp__201;
  } else {
    llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__184__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__201:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = phi i64 [ %%48, %%42 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_619_count);
  llvm_cbe_tmp__188 = (unsigned long long )llvm_cbe_tmp__188__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__188);
printf("\n = 0x%I64X",llvm_cbe_tmp__193);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = add i64 %%43, %%storemerge7, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_624_count);
  llvm_cbe_tmp__189 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__188&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__189&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%44, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_625_count);
  llvm_cbe_tmp__190 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__189))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__189));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load float* %%45, align 4, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_626_count);
  llvm_cbe_tmp__191 = (float )*llvm_cbe_tmp__190;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__191, *(int*)(&llvm_cbe_tmp__191));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = fdiv float %%46, 0.000000e+00, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_627_count);
  llvm_cbe_tmp__192 = (float )((float )(llvm_cbe_tmp__191 / 0x0p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__192, *(int*)(&llvm_cbe_tmp__192));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%47, float* %%45, align 4, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_628_count);
  *llvm_cbe_tmp__190 = llvm_cbe_tmp__192;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__192);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = add i64 %%43, %%2, !dbg !8 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_629_count);
  llvm_cbe_tmp__193 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__188&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__158&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__193&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load i64* %%4, align 8, !dbg !7 for 0x%I64xth hint within @k2c_avgpool1d  --> \n", ++aesl_llvm_cbe_635_count);
  llvm_cbe_tmp__194 = (unsigned long long )*llvm_cbe_tmp__160;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__194);
  if ((((unsigned long long )llvm_cbe_tmp__193&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__194&18446744073709551615ULL))) {
    llvm_cbe_tmp__188__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__193;   /* for PHI node */
    goto llvm_cbe_tmp__201;
  } else {
    goto llvm_cbe__2e__crit_edge6;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader4' */
llvm_cbe__2e__crit_edge10:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_avgpool1d}\n");
  return;
}


void k2c_avgpool2d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_pool_size, signed long long *llvm_cbe_stride) {
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
   char *llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  signed long long *llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  unsigned long long llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  unsigned long long llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
   char *llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  signed long long *llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  unsigned long long llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
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
  signed long long *llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  signed long long *llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  signed long long *llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  signed long long *llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned long long llvm_cbe_storemerge17;
  unsigned long long llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  unsigned long long llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  unsigned long long llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge115_count = 0;
  unsigned long long llvm_cbe_storemerge115;
  unsigned long long llvm_cbe_storemerge115__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  unsigned long long llvm_cbe_tmp__215;
  unsigned long long llvm_cbe_tmp__215__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  unsigned long long llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  unsigned long long llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  unsigned long long llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge212_count = 0;
  unsigned long long llvm_cbe_storemerge212;
  unsigned long long llvm_cbe_storemerge212__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  unsigned long long llvm_cbe_tmp__219;
  unsigned long long llvm_cbe_tmp__219__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  unsigned long long llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  unsigned long long llvm_cbe_tmp__221;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  unsigned long long llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  unsigned long long llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  float *llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge38_count = 0;
  unsigned long long llvm_cbe_storemerge38;
  unsigned long long llvm_cbe_storemerge38__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  unsigned long long llvm_cbe_tmp__225;
  unsigned long long llvm_cbe_tmp__225__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  unsigned long long llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  unsigned long long llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  unsigned long long llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  unsigned long long llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  unsigned long long llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge45_count = 0;
  unsigned long long llvm_cbe_storemerge45;
  unsigned long long llvm_cbe_storemerge45__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  unsigned long long llvm_cbe_tmp__231;
  unsigned long long llvm_cbe_tmp__231__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  unsigned long long llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  float *llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  float llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  float llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  float llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  unsigned long long llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  unsigned long long llvm_cbe_tmp__238;
  unsigned long long llvm_cbe_tmp__238__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  unsigned long long llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  unsigned long long llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  unsigned long long llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  unsigned long long llvm_cbe_tmp__242;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  unsigned long long llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  unsigned long long llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned long long llvm_cbe__2e_lcssa;
  unsigned long long llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  unsigned long long llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  unsigned long long llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  unsigned long long llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa7_count = 0;
  unsigned long long llvm_cbe__2e_lcssa7;
  unsigned long long llvm_cbe__2e_lcssa7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  float llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  unsigned long long llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  float *llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  float llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  float llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  unsigned long long llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  unsigned long long llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  unsigned long long llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  unsigned long long llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  unsigned long long llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  unsigned long long llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  unsigned long long llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  unsigned long long llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  unsigned long long llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  unsigned long long llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  unsigned long long llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  unsigned long long llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  unsigned long long llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  unsigned long long llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  unsigned long long llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  unsigned long long llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_avgpool2d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast %%struct.k2c_tensor* %%output to i8*, !dbg !6 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_670_count);
  llvm_cbe_tmp__202 = ( char *)(( char *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !6 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_671_count);
  llvm_cbe_tmp__203 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i64* %%2, align 8, !dbg !6 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_672_count);
  llvm_cbe_tmp__204 = (unsigned long long )*llvm_cbe_tmp__203;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__204);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = shl i64 %%3, 2, !dbg !6 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_673_count);
  llvm_cbe_tmp__205 = (unsigned long long )llvm_cbe_tmp__204 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__205);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @memset(i8* %%1, i32 0, i64 %%4 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_674_count);
  ( char *)memset(( char *)llvm_cbe_tmp__202, 0u, llvm_cbe_tmp__205);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__205);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__206);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 2, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_675_count);
  llvm_cbe_tmp__207 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%6, align 8, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_676_count);
  llvm_cbe_tmp__208 = (unsigned long long )*llvm_cbe_tmp__207;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__208);
  if (((llvm_cbe_tmp__208&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge18;
  } else {
    goto llvm_cbe__2e_preheader14_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader14_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 1, !dbg !7 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_697_count);
  llvm_cbe_tmp__209 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i64* %%stride, i64 1, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_698_count);
  llvm_cbe_tmp__210 = (signed long long *)(&llvm_cbe_stride[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i64* %%pool_size, i64 1, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_699_count);
  llvm_cbe_tmp__211 = (signed long long *)(&llvm_cbe_pool_size[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_700_count);
  llvm_cbe_tmp__212 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader14;

  do {     /* Syntactic loop '.preheader14' to make GCC happy */
llvm_cbe__2e_preheader14:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i64 [ 0, %%.preheader14.lr.ph ], [ %%80, %%._crit_edge16  for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned long long )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%I64X",llvm_cbe_storemerge17);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__268);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i64* %%9, align 8, !dbg !7 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_705_count);
  llvm_cbe_tmp__213 = (unsigned long long )*llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__213);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = mul i64 %%13, %%7, !dbg !7 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_706_count);
  llvm_cbe_tmp__214 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__213&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__214&18446744073709551615ull)));
  if (((llvm_cbe_tmp__214&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge16;
  } else {
    llvm_cbe_storemerge115__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__215__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader11;
  }

llvm_cbe__2e__crit_edge16:
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = add i64 %%storemerge17, 1, !dbg !10 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_826_count);
  llvm_cbe_tmp__268 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge17&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__268&18446744073709551615ull)));
  if (((llvm_cbe_tmp__268&18446744073709551615ULL) == (llvm_cbe_tmp__208&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge18;
  } else {
    llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__268;   /* for PHI node */
    goto llvm_cbe__2e_preheader14;
  }

  do {     /* Syntactic loop '.preheader11' to make GCC happy */
llvm_cbe__2e_preheader11:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge115 = phi i64 [ %%76, %%._crit_edge13 ], [ 0, %%.preheader14  for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_storemerge115_count);
  llvm_cbe_storemerge115 = (unsigned long long )llvm_cbe_storemerge115__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge115 = 0x%I64X",llvm_cbe_storemerge115);
printf("\n = 0x%I64X",llvm_cbe_tmp__265);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = phi i64 [ %%73, %%._crit_edge13 ], [ 0, %%.preheader14  for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_709_count);
  llvm_cbe_tmp__215 = (unsigned long long )llvm_cbe_tmp__215__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__215);
printf("\n = 0x%I64X",llvm_cbe_tmp__262);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i64* %%2, align 8, !dbg !7 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_713_count);
  llvm_cbe_tmp__216 = (unsigned long long )*llvm_cbe_tmp__203;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__216);
  if (((llvm_cbe_tmp__216&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge13;
  } else {
    goto llvm_cbe__2e_preheader6_2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge13:
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = add i64 %%16, %%7, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_809_count);
  llvm_cbe_tmp__262 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__215&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__262&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = load i64* %%10, align 8, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_815_count);
  llvm_cbe_tmp__263 = (unsigned long long )*llvm_cbe_tmp__210;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__263);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = mul i64 %%74, %%7, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_816_count);
  llvm_cbe_tmp__264 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__263&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__264&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = add i64 %%75, %%storemerge115, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_817_count);
  llvm_cbe_tmp__265 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__264&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge115&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__265&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = load i64* %%9, align 8, !dbg !7 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_822_count);
  llvm_cbe_tmp__266 = (unsigned long long )*llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__266);
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = mul i64 %%77, %%7, !dbg !7 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_823_count);
  llvm_cbe_tmp__267 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__266&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__267&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__262&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__267&18446744073709551615ULL))) {
    llvm_cbe_storemerge115__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__265;   /* for PHI node */
    llvm_cbe_tmp__215__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__262;   /* for PHI node */
    goto llvm_cbe__2e_preheader11;
  } else {
    goto llvm_cbe__2e__crit_edge16;
  }

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge212 = phi i64 [ 0, %%.preheader6.lr.ph ], [ %%70, %%._crit_edge9  for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_storemerge212_count);
  llvm_cbe_storemerge212 = (unsigned long long )llvm_cbe_storemerge212__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge212 = 0x%I64X",llvm_cbe_storemerge212);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__260);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = phi i64 [ 0, %%.preheader6.lr.ph ], [ %%65, %%._crit_edge9  for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_719_count);
  llvm_cbe_tmp__219 = (unsigned long long )llvm_cbe_tmp__219__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__219);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__255);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i64* %%11, align 8, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_724_count);
  llvm_cbe_tmp__220 = (unsigned long long )*llvm_cbe_tmp__211;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__220);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = mul i64 %%22, %%7, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_725_count);
  llvm_cbe_tmp__221 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__220&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__221&18446744073709551615ull)));
  if (((llvm_cbe_tmp__221&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa7__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge9;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge9:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa7 = phi i64 [ 0, %%.preheader6 ], [ %%.lcssa, %%._crit_edge  for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe__2e_lcssa7_count);
  llvm_cbe__2e_lcssa7 = (unsigned long long )llvm_cbe__2e_lcssa7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa7 = 0x%I64X",llvm_cbe__2e_lcssa7);
printf("\n = 0x%I64X",0ull);
printf("\n.lcssa = 0x%I64X",llvm_cbe__2e_lcssa);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = uitofp i64 %%.lcssa7 to float, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_783_count);
  llvm_cbe_tmp__248 = (float )((float )(unsigned long long )llvm_cbe__2e_lcssa7);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__248, *(int*)(&llvm_cbe_tmp__248));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add i64 %%19, %%21, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_784_count);
  llvm_cbe_tmp__249 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__217&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__219&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__249&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%59, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_785_count);
  llvm_cbe_tmp__250 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__249))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__249));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = load float* %%60, align 4, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_786_count);
  llvm_cbe_tmp__251 = (float )*llvm_cbe_tmp__250;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__251, *(int*)(&llvm_cbe_tmp__251));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = fdiv float %%61, %%58, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_787_count);
  llvm_cbe_tmp__252 = (float )((float )(llvm_cbe_tmp__251 / llvm_cbe_tmp__248));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__252, *(int*)(&llvm_cbe_tmp__252));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%62, float* %%60, align 4, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_788_count);
  *llvm_cbe_tmp__250 = llvm_cbe_tmp__252;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__252);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i64* %%9, align 8, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_789_count);
  llvm_cbe_tmp__253 = (unsigned long long )*llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__253);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = mul i64 %%63, %%7, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_790_count);
  llvm_cbe_tmp__254 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__253&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__254&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = add i64 %%64, %%21, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_791_count);
  llvm_cbe_tmp__255 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__254&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__219&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__255&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = load i64* %%12, align 8, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_797_count);
  llvm_cbe_tmp__256 = (unsigned long long )*llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__256);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = load i64* %%stride, align 8, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_798_count);
  llvm_cbe_tmp__257 = (unsigned long long )*llvm_cbe_stride;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__257);
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = mul i64 %%66, %%7, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_799_count);
  llvm_cbe_tmp__258 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__256&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__258&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = mul i64 %%68, %%67, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_800_count);
  llvm_cbe_tmp__259 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__258&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__257&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__259&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = add i64 %%69, %%storemerge212, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_801_count);
  llvm_cbe_tmp__260 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__259&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge212&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__260&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = load i64* %%2, align 8, !dbg !7 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_806_count);
  llvm_cbe_tmp__261 = (unsigned long long )*llvm_cbe_tmp__203;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__261);
  if ((((unsigned long long )llvm_cbe_tmp__255&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__261&18446744073709551615ULL))) {
    llvm_cbe_storemerge212__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__260;   /* for PHI node */
    llvm_cbe_tmp__219__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__255;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  } else {
    goto llvm_cbe__2e__crit_edge13;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge38 = phi i64 [ 0, %%.preheader.lr.ph ], [ %%54, %%._crit_edge  for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_storemerge38_count);
  llvm_cbe_storemerge38 = (unsigned long long )llvm_cbe_storemerge38__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge38 = 0x%I64X",llvm_cbe_storemerge38);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__245);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = phi i64 [ 0, %%.preheader.lr.ph ], [ %%.lcssa, %%._crit_edge  for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_732_count);
  llvm_cbe_tmp__225 = (unsigned long long )llvm_cbe_tmp__225__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__225);
printf("\n = 0x%I64X",0ull);
printf("\n.lcssa = 0x%I64X",llvm_cbe__2e_lcssa);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i64* %%pool_size, align 8, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_737_count);
  llvm_cbe_tmp__226 = (unsigned long long )*llvm_cbe_pool_size;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__226);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i64* %%12, align 8, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_738_count);
  llvm_cbe_tmp__227 = (unsigned long long )*llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__227);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = mul i64 %%29, %%7, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_739_count);
  llvm_cbe_tmp__228 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__226&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__228&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = mul i64 %%31, %%30, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_740_count);
  llvm_cbe_tmp__229 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__228&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__227&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__229&18446744073709551615ull)));
  if (((llvm_cbe_tmp__229&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__225;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i64 [ %%28, %%.preheader ], [ %%46, %%45  for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned long long )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%I64X",llvm_cbe__2e_lcssa);
printf("\n = 0x%I64X",llvm_cbe_tmp__225);
printf("\n = 0x%I64X",llvm_cbe_tmp__238);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = add i64 %%storemerge38, %%7, !dbg !10 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_773_count);
  llvm_cbe_tmp__245 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge38&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__245&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = load i64* %%11, align 8, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_779_count);
  llvm_cbe_tmp__246 = (unsigned long long )*llvm_cbe_tmp__211;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__246);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = mul i64 %%55, %%7, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_780_count);
  llvm_cbe_tmp__247 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__246&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__247&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__245&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__247&18446744073709551615ULL))) {
    llvm_cbe_storemerge38__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__245;   /* for PHI node */
    llvm_cbe_tmp__225__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_lcssa;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe__2e_lcssa7__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_lcssa;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge9;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__269:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge45 = phi i64 [ 0, %%.lr.ph ], [ %%49, %%45  for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_storemerge45_count);
  llvm_cbe_storemerge45 = (unsigned long long )llvm_cbe_storemerge45__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge45 = 0x%I64X",llvm_cbe_storemerge45);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__241);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = phi i64 [ %%28, %%.lr.ph ], [ %%46, %%45  for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_745_count);
  llvm_cbe_tmp__231 = (unsigned long long )llvm_cbe_tmp__231__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__231);
printf("\n = 0x%I64X",llvm_cbe_tmp__225);
printf("\n = 0x%I64X",llvm_cbe_tmp__238);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add i64 %%34, %%storemerge45, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_746_count);
  llvm_cbe_tmp__232 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__230&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge45&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__232&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%37, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_747_count);
  llvm_cbe_tmp__233 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__232))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__232));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load float* %%38, align 4, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_748_count);
  llvm_cbe_tmp__234 = (float )*llvm_cbe_tmp__233;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__234, *(int*)(&llvm_cbe_tmp__234));
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__234, (*(float*)&FPConstant0)))) {
    goto llvm_cbe_tmp__270;
  } else {
    llvm_cbe_tmp__238__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__231;   /* for PHI node */
    goto llvm_cbe_tmp__271;
  }

llvm_cbe_tmp__271:
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = phi i64 [ %%36, %%35 ], [ %%44, %%41  for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_759_count);
  llvm_cbe_tmp__238 = (unsigned long long )llvm_cbe_tmp__238__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__238);
printf("\n = 0x%I64X",llvm_cbe_tmp__231);
printf("\n = 0x%I64X",llvm_cbe_tmp__237);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i64* %%12, align 8, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_760_count);
  llvm_cbe_tmp__239 = (unsigned long long )*llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__239);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = mul i64 %%47, %%7, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_761_count);
  llvm_cbe_tmp__240 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__239&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__240&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add i64 %%48, %%storemerge45, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_762_count);
  llvm_cbe_tmp__241 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__240&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge45&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__241&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load i64* %%pool_size, align 8, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_768_count);
  llvm_cbe_tmp__242 = (unsigned long long )*llvm_cbe_pool_size;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__242);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = mul i64 %%50, %%7, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_769_count);
  llvm_cbe_tmp__243 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__242&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__243&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = mul i64 %%51, %%47, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_770_count);
  llvm_cbe_tmp__244 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__243&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__239&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__244&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__241&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__244&18446744073709551615ULL))) {
    llvm_cbe_storemerge45__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__241;   /* for PHI node */
    llvm_cbe_tmp__231__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__238;   /* for PHI node */
    goto llvm_cbe_tmp__269;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__238;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe_tmp__270:
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load float* %%27, align 4, !dbg !7 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_751_count);
  llvm_cbe_tmp__235 = (float )*llvm_cbe_tmp__224;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__235, *(int*)(&llvm_cbe_tmp__235));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = fadd float %%42, %%39, !dbg !7 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_752_count);
  llvm_cbe_tmp__236 = (float )((float )(llvm_cbe_tmp__235 + llvm_cbe_tmp__234));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__236, *(int*)(&llvm_cbe_tmp__236));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%43, float* %%27, align 4, !dbg !7 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_753_count);
  *llvm_cbe_tmp__224 = llvm_cbe_tmp__236;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__236);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = add i64 %%36, 1, !dbg !10 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_754_count);
  llvm_cbe_tmp__237 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__231&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__237&18446744073709551615ull)));
  llvm_cbe_tmp__238__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__237;   /* for PHI node */
  goto llvm_cbe_tmp__271;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add i64 %%25, %%storemerge38, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_743_count);
  llvm_cbe_tmp__230 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__222&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge38&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__230&18446744073709551615ull)));
  llvm_cbe_storemerge45__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__231__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__225;   /* for PHI node */
  goto llvm_cbe_tmp__269;

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i64 %%20, %%storemerge212, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_728_count);
  llvm_cbe_tmp__222 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__218&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge212&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__222&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i64 %%19, %%21, !dbg !7 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_729_count);
  llvm_cbe_tmp__223 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__217&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__219&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__223&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%26, !dbg !7 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_730_count);
  llvm_cbe_tmp__224 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__223))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__223));
}
  llvm_cbe_storemerge38__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__225__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  } while (1); /* end of syntactic loop '.preheader6' */
llvm_cbe__2e_preheader6_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%16, %%storemerge17, !dbg !8 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_716_count);
  llvm_cbe_tmp__217 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__215&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge17&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__217&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add i64 %%storemerge115, %%storemerge17, !dbg !9 for 0x%I64xth hint within @k2c_avgpool2d  --> \n", ++aesl_llvm_cbe_717_count);
  llvm_cbe_tmp__218 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge115&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge17&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__218&18446744073709551615ull)));
  llvm_cbe_storemerge212__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__219__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  } while (1); /* end of syntactic loop '.preheader11' */
  } while (1); /* end of syntactic loop '.preheader14' */
llvm_cbe__2e__crit_edge18:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_avgpool2d}\n");
  return;
}

