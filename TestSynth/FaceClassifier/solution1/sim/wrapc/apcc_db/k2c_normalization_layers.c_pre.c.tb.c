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
  float field0[300000];
  unsigned long long field1;
  unsigned long long field2;
  signed long long field3[5];
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void k2c_batch_norm(l_struct_OC_k2c_tensor *llvm_cbe_outputs, l_struct_OC_k2c_tensor *llvm_cbe_inputs, l_struct_OC_k2c_tensor *llvm_cbe_mean, l_struct_OC_k2c_tensor *llvm_cbe_stdev, l_struct_OC_k2c_tensor *llvm_cbe_gamma, l_struct_OC_k2c_tensor *llvm_cbe_beta, signed long long llvm_cbe_axis);


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

void k2c_batch_norm(l_struct_OC_k2c_tensor *llvm_cbe_outputs, l_struct_OC_k2c_tensor *llvm_cbe_inputs, l_struct_OC_k2c_tensor *llvm_cbe_mean, l_struct_OC_k2c_tensor *llvm_cbe_stdev, l_struct_OC_k2c_tensor *llvm_cbe_gamma, l_struct_OC_k2c_tensor *llvm_cbe_beta, signed long long llvm_cbe_axis) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
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
  signed long long *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned long long llvm_cbe_storemerge4;
  unsigned long long llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  unsigned long long llvm_cbe_tmp__3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  signed long long *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned long long llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned long long llvm_cbe_storemerge;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned long long llvm_cbe__2e_lcssa;
  unsigned long long llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  signed long long *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  signed long long *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  unsigned long long llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  float *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  float llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  float *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  float llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  float llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  float *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  float llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  float llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  float *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  float llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  float llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  float *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  float llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  float llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  float *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  unsigned long long llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned long long llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_batch_norm\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = add i64 %%axis, 1, !dbg !5 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )((unsigned long long )(llvm_cbe_axis&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge3 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%inputs, i64 0, i32 1, !dbg !5 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__1 = (signed long long *)(&llvm_cbe_inputs->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !5 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__2 = (unsigned long long )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
  if ((((unsigned long long )llvm_cbe_storemerge3&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__2&18446744073709551615ULL))) {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned long long )llvm_cbe_storemerge3;   /* for PHI node */
    llvm_cbe_tmp__3__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph6;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge7;
  }

  do {     /* Syntactic loop '.lr.ph6' to make GCC happy */
llvm_cbe__2e_lr_2e_ph6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i64 [ %%storemerge, %%.lr.ph6 ], [ %%storemerge3, %%0  for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned long long )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%I64X",llvm_cbe_storemerge4);
printf("\nstoremerge = 0x%I64X",llvm_cbe_storemerge);
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = phi i64 [ %%7, %%.lr.ph6 ], [ 1, %%0  for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__3 = (unsigned long long )llvm_cbe_tmp__3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__3);
printf("\n = 0x%I64X",llvm_cbe_tmp__6);
printf("\n = 0x%I64X",1ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%inputs, i64 0, i32 3, i64 %%storemerge4, !dbg !5 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__4 = (signed long long *)(&llvm_cbe_inputs->field3[(((signed long long )llvm_cbe_storemerge4))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%I64X",((signed long long )llvm_cbe_storemerge4));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !5 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__5 = (unsigned long long )*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = mul i64 %%6, %%4, !dbg !5 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__6 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__5&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__3&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__6&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = add i64 %%storemerge4, 1, !dbg !5 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge4&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge = 0x%I64X\n", ((unsigned long long )(llvm_cbe_storemerge&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_storemerge&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__2&18446744073709551615ULL))) {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned long long )llvm_cbe_storemerge;   /* for PHI node */
    llvm_cbe_tmp__3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__6;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph6;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__6;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge7;
  }

  } while (1); /* end of syntactic loop '.lr.ph6' */
llvm_cbe__2e__crit_edge7:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i64 [ 1, %%0 ], [ %%7, %%.lr.ph6  for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned long long )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%I64X",llvm_cbe__2e_lcssa);
printf("\n = 0x%I64X",1ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.k2c_tensor* %%inputs, i64 0, i32 3, i64 %%axis, !dbg !5 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__7 = (signed long long *)(&llvm_cbe_inputs->field3[(((signed long long )llvm_cbe_axis))]);
if (AESL_DEBUG_TRACE) {
printf("\naxis = 0x%I64X",((signed long long )llvm_cbe_axis));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i64* %%9, align 8, !dbg !5 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__8 = (unsigned long long )*llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.k2c_tensor* %%inputs, i64 0, i32 2, !dbg !5 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__9 = (signed long long *)(&llvm_cbe_inputs->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i64* %%11, align 8, !dbg !5 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__10 = (unsigned long long )*llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__10);
  if (((llvm_cbe_tmp__10&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ %%31, %%.lr.ph ], [ 0, %%._crit_edge7  for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",llvm_cbe_tmp__28);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = udiv i64 %%storemerge12, %%.lcssa, !dbg !7 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__11 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) / ((unsigned long long )(llvm_cbe__2e_lcssa&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__11&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = urem i64 %%14, %%10, !dbg !7 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__12 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__11&18446744073709551615ull)) % ((unsigned long long )(llvm_cbe_tmp__8&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__12&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.k2c_tensor* %%inputs, i64 0, i32 0, i64 %%storemerge12, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__13 = (float *)(&llvm_cbe_inputs->field0[(((signed long long )llvm_cbe_storemerge12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",((signed long long )llvm_cbe_storemerge12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load float* %%16, align 4, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__14 = (float )*llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__14, *(int*)(&llvm_cbe_tmp__14));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds %%struct.k2c_tensor* %%mean, i64 0, i32 0, i64 %%15, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__15 = (float *)(&llvm_cbe_mean->field0[(((signed long long )llvm_cbe_tmp__12))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load float* %%18, align 4, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__16 = (float )*llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__16, *(int*)(&llvm_cbe_tmp__16));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = fsub float %%17, %%19, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__17 = (float )((float )(llvm_cbe_tmp__14 - llvm_cbe_tmp__16));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__17, *(int*)(&llvm_cbe_tmp__17));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.k2c_tensor* %%stdev, i64 0, i32 0, i64 %%15, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__18 = (float *)(&llvm_cbe_stdev->field0[(((signed long long )llvm_cbe_tmp__12))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load float* %%21, align 4, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__19 = (float )*llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__19, *(int*)(&llvm_cbe_tmp__19));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = fdiv float %%20, %%22, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__20 = (float )((float )(llvm_cbe_tmp__17 / llvm_cbe_tmp__19));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__20, *(int*)(&llvm_cbe_tmp__20));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.k2c_tensor* %%gamma, i64 0, i32 0, i64 %%15, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__21 = (float *)(&llvm_cbe_gamma->field0[(((signed long long )llvm_cbe_tmp__12))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load float* %%24, align 4, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__22 = (float )*llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__22, *(int*)(&llvm_cbe_tmp__22));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = fmul float %%23, %%25, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__23 = (float )((float )(llvm_cbe_tmp__20 * llvm_cbe_tmp__22));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__23, *(int*)(&llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.k2c_tensor* %%beta, i64 0, i32 0, i64 %%15, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__24 = (float *)(&llvm_cbe_beta->field0[(((signed long long )llvm_cbe_tmp__12))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load float* %%27, align 4, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__25 = (float )*llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__25, *(int*)(&llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = fadd float %%26, %%28, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__26 = (float )((float )(llvm_cbe_tmp__23 + llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__26, *(int*)(&llvm_cbe_tmp__26));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.k2c_tensor* %%outputs, i64 0, i32 0, i64 %%storemerge12, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__27 = (float *)(&llvm_cbe_outputs->field0[(((signed long long )llvm_cbe_storemerge12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",((signed long long )llvm_cbe_storemerge12));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%29, float* %%30, align 4, !dbg !4 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_93_count);
  *llvm_cbe_tmp__27 = llvm_cbe_tmp__26;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add i64 %%storemerge12, 1, !dbg !7 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__28 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__28&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i64* %%11, align 8, !dbg !5 for 0x%I64xth hint within @k2c_batch_norm  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__29 = (unsigned long long )*llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__29);
  if ((((unsigned long long )llvm_cbe_tmp__28&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__29&18446744073709551615ULL))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__28;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_batch_norm}\n");
  return;
}

