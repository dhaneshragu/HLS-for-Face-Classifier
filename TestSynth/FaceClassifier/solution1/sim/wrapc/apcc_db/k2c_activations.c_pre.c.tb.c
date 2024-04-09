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

/* External Global Variable Declarations */
extern void  (*k2c_linear) (float *, unsigned long long );
extern void  (*k2c_exponential) (float *, unsigned long long );
extern void  (*k2c_relu) (float *, unsigned long long );
extern void  (*k2c_hard_sigmoid) (float *, unsigned long long );
extern void  (*k2c_tanh) (float *, unsigned long long );
extern void  (*k2c_sigmoid) (float *, unsigned long long );
extern void  (*k2c_softmax) (float *, unsigned long long );
extern void  (*k2c_softplus) (float *, unsigned long long );
extern void  (*k2c_softsign) (float *, unsigned long long );

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void k2c_linear_func(float *llvm_cbe_x, signed long long llvm_cbe_size);
void k2c_exponential_func(float *llvm_cbe_x, signed long long llvm_cbe_size);
void k2c_relu_func(float *llvm_cbe_x, signed long long llvm_cbe_size);
void k2c_hard_sigmoid_func(float *llvm_cbe_x, signed long long llvm_cbe_size);
void k2c_tanh_func(float *llvm_cbe_x, signed long long llvm_cbe_size);
void k2c_sigmoid_func(float *llvm_cbe_x, signed long long llvm_cbe_size);
void k2c_softmax_func(float *llvm_cbe_x, signed long long llvm_cbe_size);
void k2c_softplus_func(float *llvm_cbe_x, signed long long llvm_cbe_size);
void k2c_softsign_func(float *llvm_cbe_x, signed long long llvm_cbe_size);
float fabsf(float );
void k2c_LeakyReLU(float *llvm_cbe_x, signed long long llvm_cbe_size, float llvm_cbe_alpha);
void k2c_PReLU(float *llvm_cbe_x, signed long long llvm_cbe_size, float *llvm_cbe_alpha);
void k2c_ELU(float *llvm_cbe_x, signed long long llvm_cbe_size, float llvm_cbe_alpha);
void k2c_ThresholdedReLU(float *llvm_cbe_x, signed long long llvm_cbe_size, float llvm_cbe_theta);
void k2c_ReLU(float *llvm_cbe_x, signed long long llvm_cbe_size, float llvm_cbe_max_value, float llvm_cbe_alpha, float llvm_cbe_theta);


/* Global Variable Definitions and Initialization */
void  (*k2c_exponential) (float *, unsigned long long ) = k2c_exponential_func;
void  (*k2c_relu) (float *, unsigned long long ) = k2c_relu_func;
void  (*k2c_linear) (float *, unsigned long long ) = k2c_linear_func;
void  (*k2c_hard_sigmoid) (float *, unsigned long long ) = k2c_hard_sigmoid_func;
void  (*k2c_tanh) (float *, unsigned long long ) = k2c_tanh_func;
void  (*k2c_sigmoid) (float *, unsigned long long ) = k2c_sigmoid_func;
void  (*k2c_softmax) (float *, unsigned long long ) = k2c_softmax_func;
void  (*k2c_softplus) (float *, unsigned long long ) = k2c_softplus_func;
void  (*k2c_softsign) (float *, unsigned long long ) = k2c_softsign_func;


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

void k2c_linear_func(float *llvm_cbe_x, signed long long llvm_cbe_size) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_linear_func\n");
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_linear_func}\n");
  return;
}


void k2c_exponential_func(float *llvm_cbe_x, signed long long llvm_cbe_size) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  float *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  float llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  float llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_exponential_func\n");
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%5, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @k2c_exponential_func  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__4);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%x, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @k2c_exponential_func  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__1 = (float *)(&llvm_cbe_x[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_exponential_func  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__2 = (float )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__2, *(int*)(&llvm_cbe_tmp__2));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call float @expf(float %%3) nounwind, !dbg !9 for 0x%I64xth hint within @k2c_exponential_func  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__3 = (float ) /*tail*/ expf(llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__2, *(int*)(&llvm_cbe_tmp__2));
printf("\nReturn  = %f",llvm_cbe_tmp__3);
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%4, float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_exponential_func  --> \n", ++aesl_llvm_cbe_19_count);
  *llvm_cbe_tmp__1 = llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add i64 %%storemerge1, 1, !dbg !10 for 0x%I64xth hint within @k2c_exponential_func  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__4 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__4&18446744073709551615ull)));
  if (((llvm_cbe_tmp__4&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__4;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_exponential_func}\n");
  return;
}


void k2c_relu_func(float *llvm_cbe_x, signed long long llvm_cbe_size) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  float *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  float llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_relu_func\n");
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%7, %%6 ], [ 0, %%0  for 0x%I64xth hint within @k2c_relu_func  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__7);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%x, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @k2c_relu_func  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__5 = (float *)(&llvm_cbe_x[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_relu_func  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__6 = (float )*llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__6, *(int*)(&llvm_cbe_tmp__6));
  if ((llvm_fcmp_ugt(llvm_cbe_tmp__6, 0x0p0))) {
    goto llvm_cbe_tmp__8;
  } else {
    goto llvm_cbe_tmp__9;
  }

llvm_cbe_tmp__8:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%storemerge1, 1, !dbg !10 for 0x%I64xth hint within @k2c_relu_func  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__7 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__7&18446744073709551615ull)));
  if (((llvm_cbe_tmp__7&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__7;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__9:
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%2, align 4, !dbg !10 for 0x%I64xth hint within @k2c_relu_func  --> \n", ++aesl_llvm_cbe_44_count);
  *llvm_cbe_tmp__5 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  goto llvm_cbe_tmp__8;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_relu_func}\n");
  return;
}


void k2c_hard_sigmoid_func(float *llvm_cbe_x, signed long long llvm_cbe_size) {
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
  unsigned long long llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  float *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  float llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  float llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  float llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  float llvm_cbe_storemerge2;
  float llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_hard_sigmoid_func\n");
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i64 [ %%11, %%10 ], [ 0, %%0  for 0x%I64xth hint within @k2c_hard_sigmoid_func  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
printf("\n = 0x%I64X",llvm_cbe_tmp__14);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%x, i64 %%storemerge3, !dbg !9 for 0x%I64xth hint within @k2c_hard_sigmoid_func  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__10 = (float *)(&llvm_cbe_x[(((signed long long )llvm_cbe_storemerge3))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",((signed long long )llvm_cbe_storemerge3));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_hard_sigmoid_func  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__11 = (float )*llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__11, *(int*)(&llvm_cbe_tmp__11));
  if ((llvm_fcmp_ugt(llvm_cbe_tmp__11, -0x1.4p1))) {
    goto llvm_cbe_tmp__15;
  } else {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
    goto llvm_cbe_tmp__16;
  }

llvm_cbe_tmp__16:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi float [ 0.000000e+00, %%.lr.ph ], [ %%9, %%7 ], [ 1.000000e+00, %%5  for 0x%I64xth hint within @k2c_hard_sigmoid_func  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (float )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = %f",llvm_cbe_storemerge2);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__13);
printf("\n = %f",0x1p0);
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%storemerge2, float* %%2, align 4, !dbg !10 for 0x%I64xth hint within @k2c_hard_sigmoid_func  --> \n", ++aesl_llvm_cbe_83_count);
  *llvm_cbe_tmp__10 = llvm_cbe_storemerge2;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge2 = %f\n", llvm_cbe_storemerge2);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i64 %%storemerge3, 1, !dbg !11 for 0x%I64xth hint within @k2c_hard_sigmoid_func  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__14 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__14&18446744073709551615ull)));
  if (((llvm_cbe_tmp__14&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__14;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__15:
  if ((llvm_fcmp_ult(llvm_cbe_tmp__11, 0x1.4p1))) {
    goto llvm_cbe_tmp__17;
  } else {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (float )0x1p0;   /* for PHI node */
    goto llvm_cbe_tmp__16;
  }

llvm_cbe_tmp__17:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = fmul float %%3, 0x3FC99999A0000000, !dbg !10 for 0x%I64xth hint within @k2c_hard_sigmoid_func  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__12 = (float )((float )(llvm_cbe_tmp__11 * 0x1.99999ap-3));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__12, *(int*)(&llvm_cbe_tmp__12));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fadd float %%8, 5.000000e-01, !dbg !10 for 0x%I64xth hint within @k2c_hard_sigmoid_func  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__13 = (float )((float )(llvm_cbe_tmp__12 + 0x1p-1));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__13, *(int*)(&llvm_cbe_tmp__13));
  llvm_cbe_storemerge2__PHI_TEMPORARY = (float )llvm_cbe_tmp__13;   /* for PHI node */
  goto llvm_cbe_tmp__16;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_hard_sigmoid_func}\n");
  return;
}


void k2c_tanh_func(float *llvm_cbe_x, signed long long llvm_cbe_size) {
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  float *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  float llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  float llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  unsigned long long llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_tanh_func\n");
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%5, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @k2c_tanh_func  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__21);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%x, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @k2c_tanh_func  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__18 = (float *)(&llvm_cbe_x[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_tanh_func  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__19 = (float )*llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__19, *(int*)(&llvm_cbe_tmp__19));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call float @tanhf(float %%3) nounwind, !dbg !9 for 0x%I64xth hint within @k2c_tanh_func  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__20 = (float ) /*tail*/ tanhf(llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__19, *(int*)(&llvm_cbe_tmp__19));
printf("\nReturn  = %f",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%4, float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_tanh_func  --> \n", ++aesl_llvm_cbe_111_count);
  *llvm_cbe_tmp__18 = llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add i64 %%storemerge1, 1, !dbg !10 for 0x%I64xth hint within @k2c_tanh_func  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__21 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__21&18446744073709551615ull)));
  if (((llvm_cbe_tmp__21&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__21;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_tanh_func}\n");
  return;
}


void k2c_sigmoid_func(float *llvm_cbe_x, signed long long llvm_cbe_size) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  float *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  float llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  float llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  float llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  float llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  float llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned long long llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_sigmoid_func\n");
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%8, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @k2c_sigmoid_func  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__28);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%x, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @k2c_sigmoid_func  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__22 = (float *)(&llvm_cbe_x[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_sigmoid_func  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__23 = (float )*llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__23, *(int*)(&llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = fsub float -0.000000e+00, %%3, !dbg !9 for 0x%I64xth hint within @k2c_sigmoid_func  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__24 = (float )((float )(-(llvm_cbe_tmp__23)));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__24, *(int*)(&llvm_cbe_tmp__24));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call float @expf(float %%4) nounwind, !dbg !9 for 0x%I64xth hint within @k2c_sigmoid_func  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__25 = (float ) /*tail*/ expf(llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__24, *(int*)(&llvm_cbe_tmp__24));
printf("\nReturn  = %f",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = fadd float %%5, 1.000000e+00, !dbg !9 for 0x%I64xth hint within @k2c_sigmoid_func  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__26 = (float )((float )(llvm_cbe_tmp__25 + 0x1p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__26, *(int*)(&llvm_cbe_tmp__26));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = fdiv float 1.000000e+00, %%6, !dbg !9 for 0x%I64xth hint within @k2c_sigmoid_func  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__27 = (float )((float )(0x1p0 / llvm_cbe_tmp__26));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__27, *(int*)(&llvm_cbe_tmp__27));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%7, float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_sigmoid_func  --> \n", ++aesl_llvm_cbe_138_count);
  *llvm_cbe_tmp__22 = llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i64 %%storemerge1, 1, !dbg !10 for 0x%I64xth hint within @k2c_sigmoid_func  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__28 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__28&18446744073709551615ull)));
  if (((llvm_cbe_tmp__28&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__28;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_sigmoid_func}\n");
  return;
}


void k2c_softmax_func(float *llvm_cbe_x, signed long long llvm_cbe_size) {
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
  float llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  float *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  float llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  float llvm_cbe_tmp__32;
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
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  float *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  float llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  float llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
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
  float *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  float llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  float llvm_cbe_tmp__38;
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
  float *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  float llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  float llvm_cbe_tmp__41;
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
  float *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  float llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  float llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  float llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  float llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  float llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
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
  float llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  float llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  float llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  float llvm_cbe_tmp__51;
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
  float llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  float llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  float llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  float llvm_cbe_tmp__55;
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
  float llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  float llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  float llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  float llvm_cbe_tmp__59;
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
  float llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  float llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  float llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  float llvm_cbe_tmp__63;
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
  float llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  float llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  float llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  float llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  float llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  float llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  float llvm_cbe_tmp__70;
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
  float llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  float llvm_cbe_tmp__72;
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
  float llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  float llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  float llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  float llvm_cbe_tmp__76;
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
  float llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  float llvm_cbe_tmp__78;
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
  float llvm_cbe_tmp__79;
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
  static  unsigned long long aesl_llvm_cbe_558_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_softmax_func\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = load float* %%x, align 4, !dbg !9 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__29 = (float )*llvm_cbe_x;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__29, *(int*)(&llvm_cbe_tmp__29));
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds float* %%x, i64 1, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__30 = (float *)(&llvm_cbe_x[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load float* %%1, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__31 = (float )*llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__31, *(int*)(&llvm_cbe_tmp__31));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = select i1 %%3, float %%2, float %%0, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__32 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__31, llvm_cbe_tmp__29))) ? ((float )llvm_cbe_tmp__31) : ((float )llvm_cbe_tmp__29));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__32, *(int*)(&llvm_cbe_tmp__32));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds float* %%x, i64 2, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__33 = (float *)(&llvm_cbe_x[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%5, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__34 = (float )*llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__34, *(int*)(&llvm_cbe_tmp__34));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = select i1 %%7, float %%6, float %%4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__35 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__34, llvm_cbe_tmp__32))) ? ((float )llvm_cbe_tmp__34) : ((float )llvm_cbe_tmp__32));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__35, *(int*)(&llvm_cbe_tmp__35));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds float* %%x, i64 3, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_223_count);
  llvm_cbe_tmp__36 = (float *)(&llvm_cbe_x[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* %%9, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_224_count);
  llvm_cbe_tmp__37 = (float )*llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__37, *(int*)(&llvm_cbe_tmp__37));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = select i1 %%11, float %%10, float %%8, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__38 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__37, llvm_cbe_tmp__35))) ? ((float )llvm_cbe_tmp__37) : ((float )llvm_cbe_tmp__35));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__38, *(int*)(&llvm_cbe_tmp__38));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds float* %%x, i64 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__39 = (float *)(&llvm_cbe_x[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load float* %%13, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__40 = (float )*llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__40, *(int*)(&llvm_cbe_tmp__40));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = select i1 %%15, float %%14, float %%12, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__41 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__40, llvm_cbe_tmp__38))) ? ((float )llvm_cbe_tmp__40) : ((float )llvm_cbe_tmp__38));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__41, *(int*)(&llvm_cbe_tmp__41));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds float* %%x, i64 5, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_267_count);
  llvm_cbe_tmp__42 = (float *)(&llvm_cbe_x[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* %%17, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_268_count);
  llvm_cbe_tmp__43 = (float )*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__43, *(int*)(&llvm_cbe_tmp__43));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = select i1 %%19, float %%18, float %%16, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_273_count);
  llvm_cbe_tmp__44 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__43, llvm_cbe_tmp__41))) ? ((float )llvm_cbe_tmp__43) : ((float )llvm_cbe_tmp__41));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__44, *(int*)(&llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = fsub float %%0, %%20, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__45 = (float )((float )(llvm_cbe_tmp__29 - llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__45, *(int*)(&llvm_cbe_tmp__45));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = tail call float @expf(float %%21) nounwind, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_303_count);
  llvm_cbe_tmp__46 = (float ) /*tail*/ expf(llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__45, *(int*)(&llvm_cbe_tmp__45));
printf("\nReturn  = %f",llvm_cbe_tmp__46);
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%22, float* %%x, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_304_count);
  *llvm_cbe_x = llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = fadd float %%22, 0.000000e+00, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__47 = (float )((float )(llvm_cbe_tmp__46 + 0x0p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__47, *(int*)(&llvm_cbe_tmp__47));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load float* %%1, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__48 = (float )*llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__48, *(int*)(&llvm_cbe_tmp__48));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = fsub float %%24, %%20, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_325_count);
  llvm_cbe_tmp__49 = (float )((float )(llvm_cbe_tmp__48 - llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__49, *(int*)(&llvm_cbe_tmp__49));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = tail call float @expf(float %%25) nounwind, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__50 = (float ) /*tail*/ expf(llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__49, *(int*)(&llvm_cbe_tmp__49));
printf("\nReturn  = %f",llvm_cbe_tmp__50);
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%26, float* %%1, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_327_count);
  *llvm_cbe_tmp__30 = llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = fadd float %%23, %%26, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__51 = (float )((float )(llvm_cbe_tmp__47 + llvm_cbe_tmp__50));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__51, *(int*)(&llvm_cbe_tmp__51));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load float* %%5, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__52 = (float )*llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__52, *(int*)(&llvm_cbe_tmp__52));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = fsub float %%28, %%20, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_348_count);
  llvm_cbe_tmp__53 = (float )((float )(llvm_cbe_tmp__52 - llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__53, *(int*)(&llvm_cbe_tmp__53));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = tail call float @expf(float %%29) nounwind, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__54 = (float ) /*tail*/ expf(llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__53, *(int*)(&llvm_cbe_tmp__53));
printf("\nReturn  = %f",llvm_cbe_tmp__54);
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%30, float* %%5, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_350_count);
  *llvm_cbe_tmp__33 = llvm_cbe_tmp__54;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = fadd float %%27, %%30, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__55 = (float )((float )(llvm_cbe_tmp__51 + llvm_cbe_tmp__54));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__55, *(int*)(&llvm_cbe_tmp__55));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load float* %%9, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_370_count);
  llvm_cbe_tmp__56 = (float )*llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__56, *(int*)(&llvm_cbe_tmp__56));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = fsub float %%32, %%20, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_371_count);
  llvm_cbe_tmp__57 = (float )((float )(llvm_cbe_tmp__56 - llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__57, *(int*)(&llvm_cbe_tmp__57));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = tail call float @expf(float %%33) nounwind, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_372_count);
  llvm_cbe_tmp__58 = (float ) /*tail*/ expf(llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__57, *(int*)(&llvm_cbe_tmp__57));
printf("\nReturn  = %f",llvm_cbe_tmp__58);
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%34, float* %%9, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_373_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__58;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = fadd float %%31, %%34, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__59 = (float )((float )(llvm_cbe_tmp__55 + llvm_cbe_tmp__58));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__59, *(int*)(&llvm_cbe_tmp__59));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load float* %%13, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_393_count);
  llvm_cbe_tmp__60 = (float )*llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__60, *(int*)(&llvm_cbe_tmp__60));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = fsub float %%36, %%20, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_394_count);
  llvm_cbe_tmp__61 = (float )((float )(llvm_cbe_tmp__60 - llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__61, *(int*)(&llvm_cbe_tmp__61));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = tail call float @expf(float %%37) nounwind, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_395_count);
  llvm_cbe_tmp__62 = (float ) /*tail*/ expf(llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__61, *(int*)(&llvm_cbe_tmp__61));
printf("\nReturn  = %f",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%38, float* %%13, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_396_count);
  *llvm_cbe_tmp__39 = llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = fadd float %%35, %%38, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_397_count);
  llvm_cbe_tmp__63 = (float )((float )(llvm_cbe_tmp__59 + llvm_cbe_tmp__62));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__63, *(int*)(&llvm_cbe_tmp__63));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load float* %%17, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_416_count);
  llvm_cbe_tmp__64 = (float )*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__64, *(int*)(&llvm_cbe_tmp__64));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = fsub float %%40, %%20, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_417_count);
  llvm_cbe_tmp__65 = (float )((float )(llvm_cbe_tmp__64 - llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__65, *(int*)(&llvm_cbe_tmp__65));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = tail call float @expf(float %%41) nounwind, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_418_count);
  llvm_cbe_tmp__66 = (float ) /*tail*/ expf(llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__65, *(int*)(&llvm_cbe_tmp__65));
printf("\nReturn  = %f",llvm_cbe_tmp__66);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = fadd float %%39, %%42, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_419_count);
  llvm_cbe_tmp__67 = (float )((float )(llvm_cbe_tmp__63 + llvm_cbe_tmp__66));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__67, *(int*)(&llvm_cbe_tmp__67));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = fdiv float 1.000000e+00, %%43, !dbg !11 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_438_count);
  llvm_cbe_tmp__68 = (float )((float )(0x1p0 / llvm_cbe_tmp__67));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__68, *(int*)(&llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load float* %%x, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_457_count);
  llvm_cbe_tmp__69 = (float )*llvm_cbe_x;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__69, *(int*)(&llvm_cbe_tmp__69));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = fmul float %%45, %%44, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_458_count);
  llvm_cbe_tmp__70 = (float )((float )(llvm_cbe_tmp__69 * llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__70, *(int*)(&llvm_cbe_tmp__70));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%46, float* %%x, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_459_count);
  *llvm_cbe_x = llvm_cbe_tmp__70;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load float* %%1, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_474_count);
  llvm_cbe_tmp__71 = (float )*llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__71, *(int*)(&llvm_cbe_tmp__71));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = fmul float %%47, %%44, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_475_count);
  llvm_cbe_tmp__72 = (float )((float )(llvm_cbe_tmp__71 * llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__72, *(int*)(&llvm_cbe_tmp__72));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%48, float* %%1, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_476_count);
  *llvm_cbe_tmp__30 = llvm_cbe_tmp__72;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load float* %%5, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_491_count);
  llvm_cbe_tmp__73 = (float )*llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__73, *(int*)(&llvm_cbe_tmp__73));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = fmul float %%49, %%44, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_492_count);
  llvm_cbe_tmp__74 = (float )((float )(llvm_cbe_tmp__73 * llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__74, *(int*)(&llvm_cbe_tmp__74));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%50, float* %%5, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_493_count);
  *llvm_cbe_tmp__33 = llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load float* %%9, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_508_count);
  llvm_cbe_tmp__75 = (float )*llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__75, *(int*)(&llvm_cbe_tmp__75));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = fmul float %%51, %%44, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_509_count);
  llvm_cbe_tmp__76 = (float )((float )(llvm_cbe_tmp__75 * llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__76, *(int*)(&llvm_cbe_tmp__76));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%52, float* %%9, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_510_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = load float* %%13, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_525_count);
  llvm_cbe_tmp__77 = (float )*llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__77, *(int*)(&llvm_cbe_tmp__77));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = fmul float %%53, %%44, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_526_count);
  llvm_cbe_tmp__78 = (float )((float )(llvm_cbe_tmp__77 * llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__78, *(int*)(&llvm_cbe_tmp__78));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%54, float* %%13, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_527_count);
  *llvm_cbe_tmp__39 = llvm_cbe_tmp__78;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = fmul float %%42, %%44, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_542_count);
  llvm_cbe_tmp__79 = (float )((float )(llvm_cbe_tmp__66 * llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__79, *(int*)(&llvm_cbe_tmp__79));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%55, float* %%17, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softmax_func  --> \n", ++aesl_llvm_cbe_543_count);
  *llvm_cbe_tmp__42 = llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__79);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_softmax_func}\n");
  return;
}


void k2c_softplus_func(float *llvm_cbe_x, signed long long llvm_cbe_size) {
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  float *llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  float llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  float llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  float llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  unsigned long long llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_softplus_func\n");
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%6, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @k2c_softplus_func  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__84);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%x, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @k2c_softplus_func  --> \n", ++aesl_llvm_cbe_571_count);
  llvm_cbe_tmp__80 = (float *)(&llvm_cbe_x[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_softplus_func  --> \n", ++aesl_llvm_cbe_572_count);
  llvm_cbe_tmp__81 = (float )*llvm_cbe_tmp__80;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__81, *(int*)(&llvm_cbe_tmp__81));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call float @expf(float %%3) nounwind, !dbg !9 for 0x%I64xth hint within @k2c_softplus_func  --> \n", ++aesl_llvm_cbe_573_count);
  llvm_cbe_tmp__82 = (float ) /*tail*/ expf(llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__81, *(int*)(&llvm_cbe_tmp__81));
printf("\nReturn  = %f",llvm_cbe_tmp__82);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call float @log1pf(float %%4) nounwind, !dbg !9 for 0x%I64xth hint within @k2c_softplus_func  --> \n", ++aesl_llvm_cbe_574_count);
  llvm_cbe_tmp__83 = (float ) /*tail*/ log1pf(llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__82, *(int*)(&llvm_cbe_tmp__82));
printf("\nReturn  = %f",llvm_cbe_tmp__83);
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%5, float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_softplus_func  --> \n", ++aesl_llvm_cbe_575_count);
  *llvm_cbe_tmp__80 = llvm_cbe_tmp__83;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i64 %%storemerge1, 1, !dbg !10 for 0x%I64xth hint within @k2c_softplus_func  --> \n", ++aesl_llvm_cbe_576_count);
  llvm_cbe_tmp__84 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__84&18446744073709551615ull)));
  if (((llvm_cbe_tmp__84&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__84;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_softplus_func}\n");
  return;
}


void k2c_softsign_func(float *llvm_cbe_x, signed long long llvm_cbe_size) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  float *llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  float llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  float llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  float llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  float llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  unsigned long long llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_softsign_func\n");
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%7, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @k2c_softsign_func  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__90);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%x, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @k2c_softsign_func  --> \n", ++aesl_llvm_cbe_598_count);
  llvm_cbe_tmp__85 = (float *)(&llvm_cbe_x[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_softsign_func  --> \n", ++aesl_llvm_cbe_599_count);
  llvm_cbe_tmp__86 = (float )*llvm_cbe_tmp__85;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__86, *(int*)(&llvm_cbe_tmp__86));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call float @fabsf(float %%3) nounwind, !dbg !10 for 0x%I64xth hint within @k2c_softsign_func  --> \n", ++aesl_llvm_cbe_600_count);
  llvm_cbe_tmp__87 = (float ) /*tail*/ fabsf(llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__86, *(int*)(&llvm_cbe_tmp__86));
printf("\nReturn  = %f",llvm_cbe_tmp__87);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = fadd float %%4, 1.000000e+00, !dbg !10 for 0x%I64xth hint within @k2c_softsign_func  --> \n", ++aesl_llvm_cbe_601_count);
  llvm_cbe_tmp__88 = (float )((float )(llvm_cbe_tmp__87 + 0x1p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__88, *(int*)(&llvm_cbe_tmp__88));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = fdiv float %%3, %%5, !dbg !10 for 0x%I64xth hint within @k2c_softsign_func  --> \n", ++aesl_llvm_cbe_602_count);
  llvm_cbe_tmp__89 = (float )((float )(llvm_cbe_tmp__86 / llvm_cbe_tmp__88));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__89, *(int*)(&llvm_cbe_tmp__89));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%6, float* %%2, align 4, !dbg !10 for 0x%I64xth hint within @k2c_softsign_func  --> \n", ++aesl_llvm_cbe_603_count);
  *llvm_cbe_tmp__85 = llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%storemerge1, 1, !dbg !10 for 0x%I64xth hint within @k2c_softsign_func  --> \n", ++aesl_llvm_cbe_604_count);
  llvm_cbe_tmp__90 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__90&18446744073709551615ull)));
  if (((llvm_cbe_tmp__90&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__90;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_softsign_func}\n");
  return;
}


void k2c_LeakyReLU(float *llvm_cbe_x, signed long long llvm_cbe_size, float llvm_cbe_alpha) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  float *llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  float llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  float llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  unsigned long long llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_LeakyReLU\n");
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%8, %%7 ], [ 0, %%0  for 0x%I64xth hint within @k2c_LeakyReLU  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__94);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%x, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @k2c_LeakyReLU  --> \n", ++aesl_llvm_cbe_629_count);
  llvm_cbe_tmp__91 = (float *)(&llvm_cbe_x[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_LeakyReLU  --> \n", ++aesl_llvm_cbe_630_count);
  llvm_cbe_tmp__92 = (float )*llvm_cbe_tmp__91;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__92, *(int*)(&llvm_cbe_tmp__92));
  if ((llvm_fcmp_olt(llvm_cbe_tmp__92, 0x0p0))) {
    goto llvm_cbe_tmp__95;
  } else {
    goto llvm_cbe_tmp__96;
  }

llvm_cbe_tmp__96:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i64 %%storemerge1, 1, !dbg !11 for 0x%I64xth hint within @k2c_LeakyReLU  --> \n", ++aesl_llvm_cbe_636_count);
  llvm_cbe_tmp__94 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__94&18446744073709551615ull)));
  if (((llvm_cbe_tmp__94&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__94;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__95:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = fmul float %%3, %%alpha, !dbg !10 for 0x%I64xth hint within @k2c_LeakyReLU  --> \n", ++aesl_llvm_cbe_633_count);
  llvm_cbe_tmp__93 = (float )((float )(llvm_cbe_tmp__92 * llvm_cbe_alpha));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__93, *(int*)(&llvm_cbe_tmp__93));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%6, float* %%2, align 4, !dbg !10 for 0x%I64xth hint within @k2c_LeakyReLU  --> \n", ++aesl_llvm_cbe_634_count);
  *llvm_cbe_tmp__91 = llvm_cbe_tmp__93;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__93);
  goto llvm_cbe_tmp__96;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_LeakyReLU}\n");
  return;
}


void k2c_PReLU(float *llvm_cbe_x, signed long long llvm_cbe_size, float *llvm_cbe_alpha) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  float *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  float llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  float *llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  float llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  float llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  unsigned long long llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_PReLU\n");
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%10, %%9 ], [ 0, %%0  for 0x%I64xth hint within @k2c_PReLU  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__102);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%x, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @k2c_PReLU  --> \n", ++aesl_llvm_cbe_662_count);
  llvm_cbe_tmp__97 = (float *)(&llvm_cbe_x[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_PReLU  --> \n", ++aesl_llvm_cbe_663_count);
  llvm_cbe_tmp__98 = (float )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__98, *(int*)(&llvm_cbe_tmp__98));
  if ((llvm_fcmp_olt(llvm_cbe_tmp__98, 0x0p0))) {
    goto llvm_cbe_tmp__103;
  } else {
    goto llvm_cbe_tmp__104;
  }

llvm_cbe_tmp__104:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i64 %%storemerge1, 1, !dbg !11 for 0x%I64xth hint within @k2c_PReLU  --> \n", ++aesl_llvm_cbe_671_count);
  llvm_cbe_tmp__102 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__102&18446744073709551615ull)));
  if (((llvm_cbe_tmp__102&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__102;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__103:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds float* %%alpha, i64 %%storemerge1, !dbg !10 for 0x%I64xth hint within @k2c_PReLU  --> \n", ++aesl_llvm_cbe_666_count);
  llvm_cbe_tmp__99 = (float *)(&llvm_cbe_alpha[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load float* %%6, align 4, !dbg !10 for 0x%I64xth hint within @k2c_PReLU  --> \n", ++aesl_llvm_cbe_667_count);
  llvm_cbe_tmp__100 = (float )*llvm_cbe_tmp__99;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__100, *(int*)(&llvm_cbe_tmp__100));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = fmul float %%3, %%7, !dbg !10 for 0x%I64xth hint within @k2c_PReLU  --> \n", ++aesl_llvm_cbe_668_count);
  llvm_cbe_tmp__101 = (float )((float )(llvm_cbe_tmp__98 * llvm_cbe_tmp__100));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__101, *(int*)(&llvm_cbe_tmp__101));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%8, float* %%2, align 4, !dbg !10 for 0x%I64xth hint within @k2c_PReLU  --> \n", ++aesl_llvm_cbe_669_count);
  *llvm_cbe_tmp__97 = llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__101);
  goto llvm_cbe_tmp__104;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_PReLU}\n");
  return;
}


void k2c_ELU(float *llvm_cbe_x, signed long long llvm_cbe_size, float llvm_cbe_alpha) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  float *llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  float llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  float llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  float llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  unsigned long long llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_ELU\n");
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%9, %%8 ], [ 0, %%0  for 0x%I64xth hint within @k2c_ELU  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__109);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%x, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @k2c_ELU  --> \n", ++aesl_llvm_cbe_697_count);
  llvm_cbe_tmp__105 = (float *)(&llvm_cbe_x[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_ELU  --> \n", ++aesl_llvm_cbe_698_count);
  llvm_cbe_tmp__106 = (float )*llvm_cbe_tmp__105;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__106, *(int*)(&llvm_cbe_tmp__106));
  if ((llvm_fcmp_ugt(llvm_cbe_tmp__106, 0x0p0))) {
    goto llvm_cbe_tmp__110;
  } else {
    goto llvm_cbe_tmp__111;
  }

llvm_cbe_tmp__110:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i64 %%storemerge1, 1, !dbg !11 for 0x%I64xth hint within @k2c_ELU  --> \n", ++aesl_llvm_cbe_705_count);
  llvm_cbe_tmp__109 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__109&18446744073709551615ull)));
  if (((llvm_cbe_tmp__109&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__109;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__111:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call float @expm1f(float %%3) nounwind, !dbg !10 for 0x%I64xth hint within @k2c_ELU  --> \n", ++aesl_llvm_cbe_701_count);
  llvm_cbe_tmp__107 = (float ) /*tail*/ expm1f(llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__106, *(int*)(&llvm_cbe_tmp__106));
printf("\nReturn  = %f",llvm_cbe_tmp__107);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = fmul float %%6, %%alpha, !dbg !10 for 0x%I64xth hint within @k2c_ELU  --> \n", ++aesl_llvm_cbe_702_count);
  llvm_cbe_tmp__108 = (float )((float )(llvm_cbe_tmp__107 * llvm_cbe_alpha));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__108, *(int*)(&llvm_cbe_tmp__108));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%7, float* %%2, align 4, !dbg !10 for 0x%I64xth hint within @k2c_ELU  --> \n", ++aesl_llvm_cbe_703_count);
  *llvm_cbe_tmp__105 = llvm_cbe_tmp__108;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__108);
  goto llvm_cbe_tmp__110;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_ELU}\n");
  return;
}


void k2c_ThresholdedReLU(float *llvm_cbe_x, signed long long llvm_cbe_size, float llvm_cbe_theta) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  float *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  float llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  unsigned long long llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_ThresholdedReLU\n");
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%7, %%6 ], [ 0, %%0  for 0x%I64xth hint within @k2c_ThresholdedReLU  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__114);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%x, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @k2c_ThresholdedReLU  --> \n", ++aesl_llvm_cbe_728_count);
  llvm_cbe_tmp__112 = (float *)(&llvm_cbe_x[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_ThresholdedReLU  --> \n", ++aesl_llvm_cbe_729_count);
  llvm_cbe_tmp__113 = (float )*llvm_cbe_tmp__112;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__113, *(int*)(&llvm_cbe_tmp__113));
  if ((llvm_fcmp_ugt(llvm_cbe_tmp__113, llvm_cbe_theta))) {
    goto llvm_cbe_tmp__115;
  } else {
    goto llvm_cbe_tmp__116;
  }

llvm_cbe_tmp__115:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%storemerge1, 1, !dbg !11 for 0x%I64xth hint within @k2c_ThresholdedReLU  --> \n", ++aesl_llvm_cbe_734_count);
  llvm_cbe_tmp__114 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__114&18446744073709551615ull)));
  if (((llvm_cbe_tmp__114&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__114;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__116:
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%2, align 4, !dbg !10 for 0x%I64xth hint within @k2c_ThresholdedReLU  --> \n", ++aesl_llvm_cbe_732_count);
  *llvm_cbe_tmp__112 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  goto llvm_cbe_tmp__115;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_ThresholdedReLU}\n");
  return;
}


void k2c_ReLU(float *llvm_cbe_x, signed long long llvm_cbe_size, float llvm_cbe_max_value, float llvm_cbe_alpha, float llvm_cbe_theta) {
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  float *llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  float llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  float llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  float llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  unsigned long long llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_ReLU\n");
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%13, %%12 ], [ 0, %%0  for 0x%I64xth hint within @k2c_ReLU  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__121);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%x, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @k2c_ReLU  --> \n", ++aesl_llvm_cbe_768_count);
  llvm_cbe_tmp__117 = (float *)(&llvm_cbe_x[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !9 for 0x%I64xth hint within @k2c_ReLU  --> \n", ++aesl_llvm_cbe_769_count);
  llvm_cbe_tmp__118 = (float )*llvm_cbe_tmp__117;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__118, *(int*)(&llvm_cbe_tmp__118));
  if ((llvm_fcmp_ult(llvm_cbe_tmp__118, llvm_cbe_max_value))) {
    goto llvm_cbe_tmp__122;
  } else {
    goto llvm_cbe_tmp__123;
  }

llvm_cbe_tmp__124:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i64 %%storemerge1, 1, !dbg !11 for 0x%I64xth hint within @k2c_ReLU  --> \n", ++aesl_llvm_cbe_781_count);
  llvm_cbe_tmp__121 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__121&18446744073709551615ull)));
  if (((llvm_cbe_tmp__121&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__121;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__123:
if (AESL_DEBUG_TRACE)
printf("\n  store float %%max_value, float* %%2, align 4, !dbg !10 for 0x%I64xth hint within @k2c_ReLU  --> \n", ++aesl_llvm_cbe_772_count);
  *llvm_cbe_tmp__117 = llvm_cbe_max_value;
if (AESL_DEBUG_TRACE)
printf("\nmax_value = %f\n", llvm_cbe_max_value);
  goto llvm_cbe_tmp__124;

llvm_cbe_tmp__125:
  goto llvm_cbe_tmp__124;

llvm_cbe_tmp__122:
  if ((llvm_fcmp_olt(llvm_cbe_tmp__118, llvm_cbe_theta))) {
    goto llvm_cbe_tmp__126;
  } else {
    goto llvm_cbe_tmp__125;
  }

llvm_cbe_tmp__126:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fsub float %%3, %%theta, !dbg !10 for 0x%I64xth hint within @k2c_ReLU  --> \n", ++aesl_llvm_cbe_776_count);
  llvm_cbe_tmp__119 = (float )((float )(llvm_cbe_tmp__118 - llvm_cbe_theta));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__119, *(int*)(&llvm_cbe_tmp__119));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = fmul float %%9, %%alpha, !dbg !10 for 0x%I64xth hint within @k2c_ReLU  --> \n", ++aesl_llvm_cbe_777_count);
  llvm_cbe_tmp__120 = (float )((float )(llvm_cbe_tmp__119 * llvm_cbe_alpha));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__120, *(int*)(&llvm_cbe_tmp__120));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%10, float* %%2, align 4, !dbg !10 for 0x%I64xth hint within @k2c_ReLU  --> \n", ++aesl_llvm_cbe_778_count);
  *llvm_cbe_tmp__117 = llvm_cbe_tmp__120;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__120);
  goto llvm_cbe_tmp__125;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_ReLU}\n");
  return;
}

