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
void k2c_embedding(l_struct_OC_k2c_tensor *llvm_cbe_outputs, l_struct_OC_k2c_tensor *llvm_cbe_inputs, l_struct_OC_k2c_tensor *llvm_cbe_kernel);


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

void k2c_embedding(l_struct_OC_k2c_tensor *llvm_cbe_outputs, l_struct_OC_k2c_tensor *llvm_cbe_inputs, l_struct_OC_k2c_tensor *llvm_cbe_kernel) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  signed long long *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  unsigned long long llvm_cbe_tmp__2;
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
  signed long long *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned long long llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge12_2e_us;
  unsigned long long llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  float llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  float *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  float llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  float *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge3_2e_us;
  unsigned long long llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  float *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
  unsigned long long llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_embedding\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 1, !dbg !5 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_9_count);
  llvm_cbe_tmp__1 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !5 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__2 = (unsigned long long )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%inputs, i64 0, i32 2, !dbg !5 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__3 = (signed long long *)(&llvm_cbe_inputs->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !5 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__4 = (unsigned long long )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__4);
  if (((llvm_cbe_tmp__4&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__21;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if (((llvm_cbe_tmp__2&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe_tmp__22;
  } else {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.us = phi i64 [ %%8, %%7 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_storemerge3_2e_us_count);
  llvm_cbe_storemerge3_2e_us = (unsigned long long )llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%I64X",llvm_cbe_storemerge3_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__5);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.k2c_tensor* %%inputs, i64 0, i32 0, i64 %%storemerge3.us, !dbg !4 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__17 = (float *)(&llvm_cbe_inputs->field0[(((signed long long )llvm_cbe_storemerge3_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%I64X",((signed long long )llvm_cbe_storemerge3_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = mul i64 %%storemerge3.us, %%2, !dbg !4 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__18 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__18&18446744073709551615ull)));
  llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__23;

llvm_cbe_tmp__24:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i64 %%storemerge3.us, 1, !dbg !6 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__5 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__5&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%3, align 8, !dbg !5 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__6 = (unsigned long long )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__6);
  if ((((unsigned long long )llvm_cbe_tmp__5&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__6&18446744073709551615ULL))) {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__5;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge4;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__23:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i64 [ 0, %%.lr.ph.us ], [ %%21, %%11  for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned long long )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%I64X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__16);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%22, align 4, !dbg !4 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__7 = (float )*llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__7, *(int*)(&llvm_cbe_tmp__7));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = fptosi float %%12 to i32, !dbg !4 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__8 = (unsigned int )((signed int )llvm_cbe_tmp__7&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i32 %%13 to i64, !dbg !4 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__9 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = mul i64 %%14, %%2, !dbg !4 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__10 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__10&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i64 %%15, %%storemerge12.us, !dbg !4 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__11 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__10&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge12_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__11&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 0, i64 %%16, !dbg !4 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__12 = (float *)(&llvm_cbe_kernel->field0[(((signed long long )llvm_cbe_tmp__11))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__11));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* %%17, align 4, !dbg !4 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__13 = (float )*llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__13, *(int*)(&llvm_cbe_tmp__13));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%storemerge12.us, %%23, !dbg !4 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__14 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__18&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__14&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.k2c_tensor* %%outputs, i64 0, i32 0, i64 %%19, !dbg !4 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__15 = (float *)(&llvm_cbe_outputs->field0[(((signed long long )llvm_cbe_tmp__14))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__14));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%18, float* %%20, align 4, !dbg !4 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_44_count);
  *llvm_cbe_tmp__15 = llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add i64 %%storemerge12.us, 1, !dbg !6 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__16 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__16&18446744073709551615ull)));
  if (((llvm_cbe_tmp__16&18446744073709551615ULL) == (llvm_cbe_tmp__2&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__24;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__16;   /* for PHI node */
    goto llvm_cbe_tmp__23;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__22:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i64 [ %%25, %%24 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
printf("\n = 0x%I64X",llvm_cbe_tmp__19);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i64 %%storemerge3, 1, !dbg !6 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__19 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__19&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i64* %%3, align 8, !dbg !5 for 0x%I64xth hint within @k2c_embedding  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__20 = (unsigned long long )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__20);
  if ((((unsigned long long )llvm_cbe_tmp__19&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__20&18446744073709551615ULL))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__19;   /* for PHI node */
    goto llvm_cbe_tmp__22;
  } else {
    goto llvm_cbe__2e__crit_edge4;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge4:
  goto llvm_cbe_tmp__21;

llvm_cbe_tmp__21:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_embedding}\n");
  return;
}

