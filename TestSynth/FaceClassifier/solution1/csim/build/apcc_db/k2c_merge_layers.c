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
void k2c_add(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_num_tensors, ...);
void k2c_subtract(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_num_tensors, l_struct_OC_k2c_tensor *llvm_cbe_tensor1, l_struct_OC_k2c_tensor *llvm_cbe_tensor2);
void k2c_multiply(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_num_tensors, ...);
void k2c_average(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_num_tensors, ...);
void k2c_max(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_num_tensors, ...);
void k2c_min(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_num_tensors, ...);
void k2c_concatenate(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_axis, signed long long llvm_cbe_num_tensors, ...);
signed int k2c_idx2sub();
signed int k2c_sub2idx();


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

void k2c_add(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_num_tensors, ...) {
  static  unsigned long long aesl_llvm_cbe_args_count = 0;
   char *llvm_cbe_args;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
   char *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
   char *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  signed long long *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
   char *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
  unsigned long long llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
   char *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  l_struct_OC_k2c_tensor **llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
   char *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  l_struct_OC_k2c_tensor *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  float *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  float llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  float *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  float llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  float llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_add\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8** %%args to i8*, !dbg !8 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_9_count);
  llvm_cbe_tmp__1 = ( char *)(( char *)(&llvm_cbe_args));
if (AESL_DEBUG_TRACE)
printf("\n  call void @llvm.va_start(i8* %%1), !dbg !8 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_10_count);
  0; va_start(*(va_list*)llvm_cbe_tmp__1, llvm_cbe_num_tensors);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = bitcast %%struct.k2c_tensor* %%output to i8*, !dbg !7 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__2 = ( char *)(( char *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !7 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__3 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !7 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__4 = (unsigned long long )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = shl i64 %%4, 2, !dbg !7 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__5 = (unsigned long long )llvm_cbe_tmp__4 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call i8* @memset(i8* %%2, i32 0, i64 %%5 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_15_count);
  ( char *)memset(( char *)llvm_cbe_tmp__2, 0u, llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__5);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__6);
}
  if (((llvm_cbe_num_tensors&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  do {     /* Syntactic loop '.lr.ph5' to make GCC happy */
llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i64 [ %%22, %%._crit_edge ], [ 0, %%0  for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
printf("\n = 0x%I64X",llvm_cbe_tmp__19);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8** %%args, align 8, !dbg !9 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__7 = ( char *)*(&llvm_cbe_args);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = bitcast i8* %%8 to %%struct.k2c_tensor**, !dbg !9 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__8 = (l_struct_OC_k2c_tensor **)((l_struct_OC_k2c_tensor **)llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr i8* %%8, i64 8, !dbg !9 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__9 = ( char *)(&llvm_cbe_tmp__7[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%10, i8** %%args, align 8, !dbg !9 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_36_count);
  *(&llvm_cbe_args) = ( char *)llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load %%struct.k2c_tensor** %%9, align 8, !dbg !9 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__10 = (l_struct_OC_k2c_tensor *)*llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i64* %%3, align 8, !dbg !7 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__11 = (unsigned long long )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__11);
  if (((llvm_cbe_tmp__11&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add i64 %%storemerge3, 1, !dbg !9 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__19 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__19&18446744073709551615ull)));
  if (((llvm_cbe_tmp__19&18446744073709551615ULL) == (llvm_cbe_num_tensors&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__19;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ %%19, %%.lr.ph ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",llvm_cbe_tmp__17);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.k2c_tensor* %%11, i64 0, i32 0, i64 %%storemerge12, !dbg !7 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__12 = (float *)(&llvm_cbe_tmp__10->field0[(((signed long long )llvm_cbe_storemerge12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",((signed long long )llvm_cbe_storemerge12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load float* %%14, align 4, !dbg !7 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__13 = (float )*llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__13, *(int*)(&llvm_cbe_tmp__13));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge12, !dbg !7 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__14 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",((signed long long )llvm_cbe_storemerge12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load float* %%16, align 4, !dbg !7 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__15 = (float )*llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__15, *(int*)(&llvm_cbe_tmp__15));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = fadd float %%17, %%15, !dbg !7 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__16 = (float )((float )(llvm_cbe_tmp__15 + llvm_cbe_tmp__13));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__16, *(int*)(&llvm_cbe_tmp__16));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%18, float* %%16, align 4, !dbg !7 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_53_count);
  *llvm_cbe_tmp__14 = llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%storemerge12, 1, !dbg !9 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__17 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__17&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i64* %%3, align 8, !dbg !7 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__18 = (unsigned long long )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__18);
  if ((((unsigned long long )llvm_cbe_tmp__17&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__18&18446744073709551615ULL))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__17;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.lr.ph5' */
llvm_cbe__2e__crit_edge6:
if (AESL_DEBUG_TRACE)
printf("\n  call void @llvm.va_end(i8* %%1), !dbg !9 for 0x%I64xth hint within @k2c_add  --> \n", ++aesl_llvm_cbe_68_count);
  0; va_end(*(va_list*)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_add}\n");
  return;
}


void k2c_subtract(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_num_tensors, l_struct_OC_k2c_tensor *llvm_cbe_tensor1, l_struct_OC_k2c_tensor *llvm_cbe_tensor2) {
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  signed long long *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned long long llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  float *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  float llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  float *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  float llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  float llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  float *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  unsigned long long llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  unsigned long long llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_subtract\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !7 for 0x%I64xth hint within @k2c_subtract  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__20 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !7 for 0x%I64xth hint within @k2c_subtract  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__21 = (unsigned long long )*llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__21);
  if (((llvm_cbe_tmp__21&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%10, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @k2c_subtract  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__28);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.k2c_tensor* %%tensor1, i64 0, i32 0, i64 %%storemerge1, !dbg !7 for 0x%I64xth hint within @k2c_subtract  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__22 = (float *)(&llvm_cbe_tensor1->field0[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load float* %%4, align 4, !dbg !7 for 0x%I64xth hint within @k2c_subtract  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__23 = (float )*llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__23, *(int*)(&llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* %%tensor2, i64 0, i32 0, i64 %%storemerge1, !dbg !7 for 0x%I64xth hint within @k2c_subtract  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__24 = (float *)(&llvm_cbe_tensor2->field0[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load float* %%6, align 4, !dbg !7 for 0x%I64xth hint within @k2c_subtract  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__25 = (float )*llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__25, *(int*)(&llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = fsub float %%5, %%7, !dbg !7 for 0x%I64xth hint within @k2c_subtract  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__26 = (float )((float )(llvm_cbe_tmp__23 - llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__26, *(int*)(&llvm_cbe_tmp__26));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge1, !dbg !7 for 0x%I64xth hint within @k2c_subtract  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__27 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%8, float* %%9, align 4, !dbg !7 for 0x%I64xth hint within @k2c_subtract  --> \n", ++aesl_llvm_cbe_94_count);
  *llvm_cbe_tmp__27 = llvm_cbe_tmp__26;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i64 %%storemerge1, 1, !dbg !8 for 0x%I64xth hint within @k2c_subtract  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__28 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__28&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%1, align 8, !dbg !7 for 0x%I64xth hint within @k2c_subtract  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__29 = (unsigned long long )*llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__29);
  if ((((unsigned long long )llvm_cbe_tmp__28&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__29&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__28;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_subtract}\n");
  return;
}


void k2c_multiply(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_num_tensors, ...) {
  static  unsigned long long aesl_llvm_cbe_args_count = 0;
   char *llvm_cbe_args;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
   char *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  signed long long *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned long long llvm_cbe_storemerge7;
  unsigned long long llvm_cbe_storemerge7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  float *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  unsigned long long llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  unsigned long long llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned long long llvm_cbe_storemerge14;
  unsigned long long llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
   char *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  l_struct_OC_k2c_tensor **llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
   char *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  l_struct_OC_k2c_tensor *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  unsigned long long llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_count = 0;
  unsigned long long llvm_cbe_storemerge23;
  unsigned long long llvm_cbe_storemerge23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  float *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  float llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  float *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  float llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  float llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned long long llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  unsigned long long llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_multiply\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8** %%args to i8*, !dbg !9 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__30 = ( char *)(( char *)(&llvm_cbe_args));
if (AESL_DEBUG_TRACE)
printf("\n  call void @llvm.va_start(i8* %%1), !dbg !9 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_115_count);
  0; va_start(*(va_list*)llvm_cbe_tmp__30, llvm_cbe_num_tensors);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !7 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__31 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i64* %%2, align 8, !dbg !7 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__32 = (unsigned long long )*llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
  if (((llvm_cbe_tmp__32&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph9;
  }

llvm_cbe__2e_preheader:
  if (((llvm_cbe_num_tensors&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  do {     /* Syntactic loop '.lr.ph9' to make GCC happy */
llvm_cbe__2e_lr_2e_ph9:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = phi i64 [ %%7, %%.lr.ph9 ], [ 0, %%0  for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned long long )llvm_cbe_storemerge7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",llvm_cbe_storemerge7);
printf("\n = 0x%I64X",llvm_cbe_tmp__34);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge7, !dbg !7 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__33 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge7))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",((signed long long )llvm_cbe_storemerge7));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 1.000000e+00, float* %%6, align 4, !dbg !7 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_134_count);
  *llvm_cbe_tmp__33 = 0x1p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x1p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%storemerge7, 1, !dbg !9 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__34 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__34&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i64* %%2, align 8, !dbg !7 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__35 = (unsigned long long )*llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__35);
  if ((((unsigned long long )llvm_cbe_tmp__34&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__35&18446744073709551615ULL))) {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__34;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph9;
  } else {
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.lr.ph9' */
  do {     /* Syntactic loop '.lr.ph5' to make GCC happy */
llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i64 [ %%24, %%._crit_edge ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned long long )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%I64X",llvm_cbe_storemerge14);
printf("\n = 0x%I64X",llvm_cbe_tmp__48);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8** %%args, align 8, !dbg !9 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__36 = ( char *)*(&llvm_cbe_args);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = bitcast i8* %%10 to %%struct.k2c_tensor**, !dbg !9 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__37 = (l_struct_OC_k2c_tensor **)((l_struct_OC_k2c_tensor **)llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr i8* %%10, i64 8, !dbg !9 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_153_count);
  llvm_cbe_tmp__38 = ( char *)(&llvm_cbe_tmp__36[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%12, i8** %%args, align 8, !dbg !9 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_160_count);
  *(&llvm_cbe_args) = ( char *)llvm_cbe_tmp__38;
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load %%struct.k2c_tensor** %%11, align 8, !dbg !9 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__39 = (l_struct_OC_k2c_tensor *)*llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%2, align 8, !dbg !7 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__40 = (unsigned long long )*llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__40);
  if (((llvm_cbe_tmp__40&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i64 %%storemerge14, 1, !dbg !9 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__48 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__48&18446744073709551615ull)));
  if (((llvm_cbe_tmp__48&18446744073709551615ULL) == (llvm_cbe_num_tensors&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__48;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23 = phi i64 [ %%21, %%.lr.ph ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_storemerge23_count);
  llvm_cbe_storemerge23 = (unsigned long long )llvm_cbe_storemerge23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",llvm_cbe_storemerge23);
printf("\n = 0x%I64X",llvm_cbe_tmp__46);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.k2c_tensor* %%13, i64 0, i32 0, i64 %%storemerge23, !dbg !8 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__41 = (float *)(&llvm_cbe_tmp__39->field0[(((signed long long )llvm_cbe_storemerge23))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",((signed long long )llvm_cbe_storemerge23));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load float* %%16, align 4, !dbg !8 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__42 = (float )*llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__42, *(int*)(&llvm_cbe_tmp__42));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge23, !dbg !8 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_174_count);
  llvm_cbe_tmp__43 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge23))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",((signed long long )llvm_cbe_storemerge23));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load float* %%18, align 4, !dbg !8 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__44 = (float )*llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__44, *(int*)(&llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = fmul float %%19, %%17, !dbg !8 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__45 = (float )((float )(llvm_cbe_tmp__44 * llvm_cbe_tmp__42));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__45, *(int*)(&llvm_cbe_tmp__45));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%20, float* %%18, align 4, !dbg !8 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_177_count);
  *llvm_cbe_tmp__43 = llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add i64 %%storemerge23, 1, !dbg !10 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__46 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__46&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i64* %%2, align 8, !dbg !7 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__47 = (unsigned long long )*llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__47);
  if ((((unsigned long long )llvm_cbe_tmp__46&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__47&18446744073709551615ULL))) {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__46;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.lr.ph5' */
llvm_cbe__2e__crit_edge6:
if (AESL_DEBUG_TRACE)
printf("\n  call void @llvm.va_end(i8* %%1), !dbg !10 for 0x%I64xth hint within @k2c_multiply  --> \n", ++aesl_llvm_cbe_195_count);
  0; va_end(*(va_list*)llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_multiply}\n");
  return;
}


void k2c_average(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_num_tensors, ...) {
  static  unsigned long long aesl_llvm_cbe_args_count = 0;
   char *llvm_cbe_args;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  float llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  float llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
   char *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
   char *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  signed long long *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned long long llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  unsigned long long llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
   char *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
  unsigned long long llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
   char *llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  l_struct_OC_k2c_tensor **llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
   char *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  l_struct_OC_k2c_tensor *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  unsigned long long llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  float *llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  float llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  float llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  float *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  float llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  float llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  unsigned long long llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  unsigned long long llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  unsigned long long llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_average\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = uitofp i64 %%num_tensors to float, !dbg !8 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__49 = (float )((float )(unsigned long long )llvm_cbe_num_tensors);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__49, *(int*)(&llvm_cbe_tmp__49));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = fdiv float 1.000000e+00, %%1, !dbg !8 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__50 = (float )((float )(0x1p0 / llvm_cbe_tmp__49));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__50, *(int*)(&llvm_cbe_tmp__50));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast i8** %%args to i8*, !dbg !9 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__51 = ( char *)(( char *)(&llvm_cbe_args));
if (AESL_DEBUG_TRACE)
printf("\n  call void @llvm.va_start(i8* %%3), !dbg !9 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_211_count);
  0; va_start(*(va_list*)llvm_cbe_tmp__51, llvm_cbe_num_tensors);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = bitcast %%struct.k2c_tensor* %%output to i8*, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__52 = ( char *)(( char *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__53 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__54 = (unsigned long long )*llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = shl i64 %%6, 2, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_215_count);
  llvm_cbe_tmp__55 = (unsigned long long )llvm_cbe_tmp__54 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i8* @memset(i8* %%4, i32 0, i64 %%7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_216_count);
  ( char *)memset(( char *)llvm_cbe_tmp__52, 0u, llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__55);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__56);
}
  if (((llvm_cbe_num_tensors&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  do {     /* Syntactic loop '.lr.ph5' to make GCC happy */
llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i64 [ %%25, %%._crit_edge ], [ 0, %%0  for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
printf("\n = 0x%I64X",llvm_cbe_tmp__70);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8** %%args, align 8, !dbg !9 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__57 = ( char *)*(&llvm_cbe_args);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = bitcast i8* %%10 to %%struct.k2c_tensor**, !dbg !9 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__58 = (l_struct_OC_k2c_tensor **)((l_struct_OC_k2c_tensor **)llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr i8* %%10, i64 8, !dbg !9 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_230_count);
  llvm_cbe_tmp__59 = ( char *)(&llvm_cbe_tmp__57[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%12, i8** %%args, align 8, !dbg !9 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_237_count);
  *(&llvm_cbe_args) = ( char *)llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load %%struct.k2c_tensor** %%11, align 8, !dbg !9 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__60 = (l_struct_OC_k2c_tensor *)*llvm_cbe_tmp__58;
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%5, align 8, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__61 = (unsigned long long )*llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__61);
  if (((llvm_cbe_tmp__61&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i64 %%storemerge3, 1, !dbg !9 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_265_count);
  llvm_cbe_tmp__70 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__70&18446744073709551615ull)));
  if (((llvm_cbe_tmp__70&18446744073709551615ULL) == (llvm_cbe_num_tensors&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__70;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ %%22, %%.lr.ph ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",llvm_cbe_tmp__68);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.k2c_tensor* %%13, i64 0, i32 0, i64 %%storemerge12, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_249_count);
  llvm_cbe_tmp__62 = (float *)(&llvm_cbe_tmp__60->field0[(((signed long long )llvm_cbe_storemerge12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",((signed long long )llvm_cbe_storemerge12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load float* %%16, align 4, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__63 = (float )*llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__63, *(int*)(&llvm_cbe_tmp__63));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = fmul float %%17, %%2, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__64 = (float )((float )(llvm_cbe_tmp__63 * llvm_cbe_tmp__50));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__64, *(int*)(&llvm_cbe_tmp__64));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge12, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__65 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",((signed long long )llvm_cbe_storemerge12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load float* %%19, align 4, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_253_count);
  llvm_cbe_tmp__66 = (float )*llvm_cbe_tmp__65;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__66, *(int*)(&llvm_cbe_tmp__66));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = fadd float %%20, %%18, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_254_count);
  llvm_cbe_tmp__67 = (float )((float )(llvm_cbe_tmp__66 + llvm_cbe_tmp__64));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__67, *(int*)(&llvm_cbe_tmp__67));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%21, float* %%19, align 4, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_255_count);
  *llvm_cbe_tmp__65 = llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add i64 %%storemerge12, 1, !dbg !9 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__68 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__68&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i64* %%5, align 8, !dbg !7 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_262_count);
  llvm_cbe_tmp__69 = (unsigned long long )*llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__69);
  if ((((unsigned long long )llvm_cbe_tmp__68&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__69&18446744073709551615ULL))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__68;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.lr.ph5' */
llvm_cbe__2e__crit_edge6:
if (AESL_DEBUG_TRACE)
printf("\n  call void @llvm.va_end(i8* %%3), !dbg !10 for 0x%I64xth hint within @k2c_average  --> \n", ++aesl_llvm_cbe_270_count);
  0; va_end(*(va_list*)llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_average}\n");
  return;
}


void k2c_max(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_num_tensors, ...) {
  static  unsigned long long aesl_llvm_cbe_args_count = 0;
   char *llvm_cbe_args;    /* Address-exposed local */
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
   char *llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
   char *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  l_struct_OC_k2c_tensor **llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
   char *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  l_struct_OC_k2c_tensor *llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  signed long long *llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  unsigned long long llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned long long llvm_cbe_storemerge7;
  unsigned long long llvm_cbe_storemerge7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  float *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  float llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  float *llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  unsigned long long llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  unsigned long long llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
   char *llvm_cbe_tmp__84;
   char *llvm_cbe_tmp__84__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned long long llvm_cbe_storemerge14;
  unsigned long long llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  l_struct_OC_k2c_tensor **llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
   char *llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  l_struct_OC_k2c_tensor *llvm_cbe_tmp__87;
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
  unsigned long long llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_count = 0;
  unsigned long long llvm_cbe_storemerge23;
  unsigned long long llvm_cbe_storemerge23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  float *llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  float llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  float *llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  float llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  unsigned long long llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  unsigned long long llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  unsigned long long llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_max\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8** %%args to i8*, !dbg !9 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_281_count);
  llvm_cbe_tmp__71 = ( char *)(( char *)(&llvm_cbe_args));
if (AESL_DEBUG_TRACE)
printf("\n  call void @llvm.va_start(i8* %%1), !dbg !9 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_282_count);
  0; va_start(*(va_list*)llvm_cbe_tmp__71, llvm_cbe_num_tensors);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i8** %%args, align 8, !dbg !9 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_289_count);
  llvm_cbe_tmp__72 = ( char *)*(&llvm_cbe_args);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast i8* %%2 to %%struct.k2c_tensor**, !dbg !9 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_290_count);
  llvm_cbe_tmp__73 = (l_struct_OC_k2c_tensor **)((l_struct_OC_k2c_tensor **)llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr i8* %%2, i64 8, !dbg !9 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_291_count);
  llvm_cbe_tmp__74 = ( char *)(&llvm_cbe_tmp__72[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%4, i8** %%args, align 8, !dbg !9 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_298_count);
  *(&llvm_cbe_args) = ( char *)llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load %%struct.k2c_tensor** %%3, align 8, !dbg !9 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_299_count);
  llvm_cbe_tmp__75 = (l_struct_OC_k2c_tensor *)*llvm_cbe_tmp__73;
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !7 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_311_count);
  llvm_cbe_tmp__76 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%6, align 8, !dbg !7 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__77 = (unsigned long long )*llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__77);
  if (((llvm_cbe_tmp__77&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph9;
  }

llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i64 %%num_tensors, -1, !dbg !8 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_321_count);
  llvm_cbe_tmp__78 = (unsigned long long )((unsigned long long )(llvm_cbe_num_tensors&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__78&18446744073709551615ull)));
  if (((llvm_cbe_tmp__78&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_tmp__84__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__74;   /* for PHI node */
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  do {     /* Syntactic loop '.lr.ph9' to make GCC happy */
llvm_cbe__2e_lr_2e_ph9:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = phi i64 [ %%14, %%.lr.ph9 ], [ 0, %%0  for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned long long )llvm_cbe_storemerge7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",llvm_cbe_storemerge7);
printf("\n = 0x%I64X",llvm_cbe_tmp__82);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.k2c_tensor* %%5, i64 0, i32 0, i64 %%storemerge7, !dbg !7 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__79 = (float *)(&llvm_cbe_tmp__75->field0[(((signed long long )llvm_cbe_storemerge7))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",((signed long long )llvm_cbe_storemerge7));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !7 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_325_count);
  llvm_cbe_tmp__80 = (float )*llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__80, *(int*)(&llvm_cbe_tmp__80));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge7, !dbg !7 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__81 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge7))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",((signed long long )llvm_cbe_storemerge7));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* %%13, align 4, !dbg !7 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_327_count);
  *llvm_cbe_tmp__81 = llvm_cbe_tmp__80;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add i64 %%storemerge7, 1, !dbg !9 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__82 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__82&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i64* %%6, align 8, !dbg !7 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_336_count);
  llvm_cbe_tmp__83 = (unsigned long long )*llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__83);
  if ((((unsigned long long )llvm_cbe_tmp__82&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__83&18446744073709551615ULL))) {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__82;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph9;
  } else {
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.lr.ph9' */
  do {     /* Syntactic loop '.lr.ph5' to make GCC happy */
llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = phi i8* [ %%19, %%._crit_edge ], [ %%4, %%.preheader ], !dbg !10 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_339_count);
  llvm_cbe_tmp__84 = ( char *)llvm_cbe_tmp__84__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i64 [ %%33, %%._crit_edge ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned long long )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%I64X",llvm_cbe_storemerge14);
printf("\n = 0x%I64X",llvm_cbe_tmp__95);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = bitcast i8* %%17 to %%struct.k2c_tensor**, !dbg !10 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_343_count);
  llvm_cbe_tmp__85 = (l_struct_OC_k2c_tensor **)((l_struct_OC_k2c_tensor **)llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr i8* %%17, i64 8, !dbg !10 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_344_count);
  llvm_cbe_tmp__86 = ( char *)(&llvm_cbe_tmp__84[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%19, i8** %%args, align 8, !dbg !10 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_351_count);
  *(&llvm_cbe_args) = ( char *)llvm_cbe_tmp__86;
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load %%struct.k2c_tensor** %%18, align 8, !dbg !10 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__87 = (l_struct_OC_k2c_tensor *)*llvm_cbe_tmp__85;
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i64* %%6, align 8, !dbg !7 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__88 = (unsigned long long )*llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__88);
  if (((llvm_cbe_tmp__88&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add i64 %%storemerge14, 1, !dbg !10 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_386_count);
  llvm_cbe_tmp__95 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__95&18446744073709551615ull)));
  if (((llvm_cbe_tmp__95&18446744073709551615ULL) == (llvm_cbe_tmp__78&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_tmp__84__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__86;   /* for PHI node */
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__95;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23 = phi i64 [ %%30, %%29 ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_storemerge23_count);
  llvm_cbe_storemerge23 = (unsigned long long )llvm_cbe_storemerge23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",llvm_cbe_storemerge23);
printf("\n = 0x%I64X",llvm_cbe_tmp__93);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge23, !dbg !8 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_367_count);
  llvm_cbe_tmp__89 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge23))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",((signed long long )llvm_cbe_storemerge23));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load float* %%23, align 4, !dbg !8 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_368_count);
  llvm_cbe_tmp__90 = (float )*llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__90, *(int*)(&llvm_cbe_tmp__90));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.k2c_tensor* %%20, i64 0, i32 0, i64 %%storemerge23, !dbg !8 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__91 = (float *)(&llvm_cbe_tmp__87->field0[(((signed long long )llvm_cbe_storemerge23))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",((signed long long )llvm_cbe_storemerge23));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load float* %%25, align 4, !dbg !8 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_370_count);
  llvm_cbe_tmp__92 = (float )*llvm_cbe_tmp__91;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__92, *(int*)(&llvm_cbe_tmp__92));
  if ((llvm_fcmp_olt(llvm_cbe_tmp__90, llvm_cbe_tmp__92))) {
    goto llvm_cbe_tmp__96;
  } else {
    goto llvm_cbe_tmp__97;
  }

llvm_cbe_tmp__97:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add i64 %%storemerge23, 1, !dbg !10 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__93 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__93&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i64* %%6, align 8, !dbg !7 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_383_count);
  llvm_cbe_tmp__94 = (unsigned long long )*llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__94);
  if ((((unsigned long long )llvm_cbe_tmp__93&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__94&18446744073709551615ULL))) {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__93;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe_tmp__96:
if (AESL_DEBUG_TRACE)
printf("\n  store float %%26, float* %%23, align 4, !dbg !8 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_373_count);
  *llvm_cbe_tmp__89 = llvm_cbe_tmp__92;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__92);
  goto llvm_cbe_tmp__97;

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.lr.ph5' */
llvm_cbe__2e__crit_edge6:
if (AESL_DEBUG_TRACE)
printf("\n  call void @llvm.va_end(i8* %%1), !dbg !10 for 0x%I64xth hint within @k2c_max  --> \n", ++aesl_llvm_cbe_395_count);
  0; va_end(*(va_list*)llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_max}\n");
  return;
}


void k2c_min(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_num_tensors, ...) {
  static  unsigned long long aesl_llvm_cbe_args_count = 0;
   char *llvm_cbe_args;    /* Address-exposed local */
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
   char *llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
   char *llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  l_struct_OC_k2c_tensor **llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
   char *llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  l_struct_OC_k2c_tensor *llvm_cbe_tmp__102;
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
  signed long long *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  unsigned long long llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned long long llvm_cbe_storemerge7;
  unsigned long long llvm_cbe_storemerge7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  float *llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  float llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  float *llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  unsigned long long llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  unsigned long long llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
   char *llvm_cbe_tmp__111;
   char *llvm_cbe_tmp__111__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned long long llvm_cbe_storemerge14;
  unsigned long long llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  l_struct_OC_k2c_tensor **llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
   char *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  l_struct_OC_k2c_tensor *llvm_cbe_tmp__114;
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
  unsigned long long llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_count = 0;
  unsigned long long llvm_cbe_storemerge23;
  unsigned long long llvm_cbe_storemerge23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  float *llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  float llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  float *llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  float llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  unsigned long long llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  unsigned long long llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  unsigned long long llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_min\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8** %%args to i8*, !dbg !9 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_406_count);
  llvm_cbe_tmp__98 = ( char *)(( char *)(&llvm_cbe_args));
if (AESL_DEBUG_TRACE)
printf("\n  call void @llvm.va_start(i8* %%1), !dbg !9 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_407_count);
  0; va_start(*(va_list*)llvm_cbe_tmp__98, llvm_cbe_num_tensors);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i8** %%args, align 8, !dbg !9 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_414_count);
  llvm_cbe_tmp__99 = ( char *)*(&llvm_cbe_args);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast i8* %%2 to %%struct.k2c_tensor**, !dbg !9 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_415_count);
  llvm_cbe_tmp__100 = (l_struct_OC_k2c_tensor **)((l_struct_OC_k2c_tensor **)llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr i8* %%2, i64 8, !dbg !9 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_416_count);
  llvm_cbe_tmp__101 = ( char *)(&llvm_cbe_tmp__99[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%4, i8** %%args, align 8, !dbg !9 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_423_count);
  *(&llvm_cbe_args) = ( char *)llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load %%struct.k2c_tensor** %%3, align 8, !dbg !9 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_424_count);
  llvm_cbe_tmp__102 = (l_struct_OC_k2c_tensor *)*llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !7 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_436_count);
  llvm_cbe_tmp__103 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%6, align 8, !dbg !7 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_437_count);
  llvm_cbe_tmp__104 = (unsigned long long )*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__104);
  if (((llvm_cbe_tmp__104&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph9;
  }

llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i64 %%num_tensors, -1, !dbg !8 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_446_count);
  llvm_cbe_tmp__105 = (unsigned long long )((unsigned long long )(llvm_cbe_num_tensors&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__105&18446744073709551615ull)));
  if (((llvm_cbe_tmp__105&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_tmp__111__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__101;   /* for PHI node */
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  do {     /* Syntactic loop '.lr.ph9' to make GCC happy */
llvm_cbe__2e_lr_2e_ph9:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = phi i64 [ %%14, %%.lr.ph9 ], [ 0, %%0  for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned long long )llvm_cbe_storemerge7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",llvm_cbe_storemerge7);
printf("\n = 0x%I64X",llvm_cbe_tmp__109);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.k2c_tensor* %%5, i64 0, i32 0, i64 %%storemerge7, !dbg !7 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_449_count);
  llvm_cbe_tmp__106 = (float *)(&llvm_cbe_tmp__102->field0[(((signed long long )llvm_cbe_storemerge7))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",((signed long long )llvm_cbe_storemerge7));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !7 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_450_count);
  llvm_cbe_tmp__107 = (float )*llvm_cbe_tmp__106;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__107, *(int*)(&llvm_cbe_tmp__107));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge7, !dbg !7 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_451_count);
  llvm_cbe_tmp__108 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge7))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",((signed long long )llvm_cbe_storemerge7));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* %%13, align 4, !dbg !7 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_452_count);
  *llvm_cbe_tmp__108 = llvm_cbe_tmp__107;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add i64 %%storemerge7, 1, !dbg !9 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_453_count);
  llvm_cbe_tmp__109 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__109&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i64* %%6, align 8, !dbg !7 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_461_count);
  llvm_cbe_tmp__110 = (unsigned long long )*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__110);
  if ((((unsigned long long )llvm_cbe_tmp__109&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__110&18446744073709551615ULL))) {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__109;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph9;
  } else {
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.lr.ph9' */
  do {     /* Syntactic loop '.lr.ph5' to make GCC happy */
llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = phi i8* [ %%19, %%._crit_edge ], [ %%4, %%.preheader ], !dbg !10 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_464_count);
  llvm_cbe_tmp__111 = ( char *)llvm_cbe_tmp__111__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i64 [ %%33, %%._crit_edge ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned long long )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%I64X",llvm_cbe_storemerge14);
printf("\n = 0x%I64X",llvm_cbe_tmp__122);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = bitcast i8* %%17 to %%struct.k2c_tensor**, !dbg !10 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_468_count);
  llvm_cbe_tmp__112 = (l_struct_OC_k2c_tensor **)((l_struct_OC_k2c_tensor **)llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr i8* %%17, i64 8, !dbg !10 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_469_count);
  llvm_cbe_tmp__113 = ( char *)(&llvm_cbe_tmp__111[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%19, i8** %%args, align 8, !dbg !10 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_476_count);
  *(&llvm_cbe_args) = ( char *)llvm_cbe_tmp__113;
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load %%struct.k2c_tensor** %%18, align 8, !dbg !10 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_477_count);
  llvm_cbe_tmp__114 = (l_struct_OC_k2c_tensor *)*llvm_cbe_tmp__112;
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i64* %%6, align 8, !dbg !7 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_489_count);
  llvm_cbe_tmp__115 = (unsigned long long )*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__115);
  if (((llvm_cbe_tmp__115&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add i64 %%storemerge14, 1, !dbg !10 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_511_count);
  llvm_cbe_tmp__122 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__122&18446744073709551615ull)));
  if (((llvm_cbe_tmp__122&18446744073709551615ULL) == (llvm_cbe_tmp__105&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_tmp__111__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__113;   /* for PHI node */
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__122;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23 = phi i64 [ %%30, %%29 ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_storemerge23_count);
  llvm_cbe_storemerge23 = (unsigned long long )llvm_cbe_storemerge23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",llvm_cbe_storemerge23);
printf("\n = 0x%I64X",llvm_cbe_tmp__120);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge23, !dbg !8 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_492_count);
  llvm_cbe_tmp__116 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge23))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",((signed long long )llvm_cbe_storemerge23));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load float* %%23, align 4, !dbg !8 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_493_count);
  llvm_cbe_tmp__117 = (float )*llvm_cbe_tmp__116;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__117, *(int*)(&llvm_cbe_tmp__117));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.k2c_tensor* %%20, i64 0, i32 0, i64 %%storemerge23, !dbg !8 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_494_count);
  llvm_cbe_tmp__118 = (float *)(&llvm_cbe_tmp__114->field0[(((signed long long )llvm_cbe_storemerge23))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",((signed long long )llvm_cbe_storemerge23));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load float* %%25, align 4, !dbg !8 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_495_count);
  llvm_cbe_tmp__119 = (float )*llvm_cbe_tmp__118;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__119, *(int*)(&llvm_cbe_tmp__119));
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__117, llvm_cbe_tmp__119))) {
    goto llvm_cbe_tmp__123;
  } else {
    goto llvm_cbe_tmp__124;
  }

llvm_cbe_tmp__124:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add i64 %%storemerge23, 1, !dbg !10 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_500_count);
  llvm_cbe_tmp__120 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__120&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i64* %%6, align 8, !dbg !7 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_508_count);
  llvm_cbe_tmp__121 = (unsigned long long )*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__121);
  if ((((unsigned long long )llvm_cbe_tmp__120&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__121&18446744073709551615ULL))) {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__120;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe_tmp__123:
if (AESL_DEBUG_TRACE)
printf("\n  store float %%26, float* %%23, align 4, !dbg !8 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_498_count);
  *llvm_cbe_tmp__116 = llvm_cbe_tmp__119;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__119);
  goto llvm_cbe_tmp__124;

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.lr.ph5' */
llvm_cbe__2e__crit_edge6:
if (AESL_DEBUG_TRACE)
printf("\n  call void @llvm.va_end(i8* %%1), !dbg !10 for 0x%I64xth hint within @k2c_min  --> \n", ++aesl_llvm_cbe_520_count);
  0; va_end(*(va_list*)llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_min}\n");
  return;
}


void k2c_concatenate(l_struct_OC_k2c_tensor *llvm_cbe_output, signed long long llvm_cbe_axis, signed long long llvm_cbe_num_tensors, ...) {
  static  unsigned long long aesl_llvm_cbe_args_count = 0;
   char *llvm_cbe_args;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_insub_count = 0;
  signed long long llvm_cbe_insub[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_outsub_count = 0;
  signed long long llvm_cbe_outsub[5];    /* Address-exposed local */
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
   char *llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  signed long long *llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
   char *llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
   char *llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  signed long long *llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  signed long long *llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  signed long long *llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  signed long long *llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
  unsigned long long llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  unsigned long long llvm_cbe_tmp__133;
  unsigned long long llvm_cbe_tmp__133__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
   char *llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  l_struct_OC_k2c_tensor **llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
   char *llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  l_struct_OC_k2c_tensor *llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  signed long long *llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  unsigned long long llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  signed long long *llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  signed long long *llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  unsigned long long llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  unsigned int llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
   char *llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  unsigned long long llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  unsigned long long llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  unsigned long long llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  unsigned int llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  unsigned long long llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  float *llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  float llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  float *llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  unsigned long long llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  unsigned long long llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  signed long long *llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  unsigned long long llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  unsigned long long llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  unsigned long long llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_concatenate\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i8** %%args to i8*, !dbg !9 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_537_count);
  llvm_cbe_tmp__125 = ( char *)(( char *)(&llvm_cbe_args));
if (AESL_DEBUG_TRACE)
printf("\n  call void @llvm.va_start(i8* %%1), !dbg !9 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_538_count);
  0; va_start(*(va_list*)llvm_cbe_tmp__125, llvm_cbe_num_tensors);
if (AESL_DEBUG_TRACE) {
}
  if (((llvm_cbe_num_tensors&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    goto llvm_cbe__2e_lr_2e_ph5;
  }

llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [5 x i64]* %%insub, i64 0, i64 0, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__126 = (signed long long *)(&llvm_cbe_insub[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = bitcast [5 x i64]* %%outsub to i8*, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_545_count);
  llvm_cbe_tmp__127 = ( char *)(( char *)(&llvm_cbe_outsub));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = bitcast [5 x i64]* %%insub to i8*, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_546_count);
  llvm_cbe_tmp__128 = ( char *)(( char *)(&llvm_cbe_insub));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [5 x i64]* %%outsub, i64 0, i64 %%axis, !dbg !8 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_547_count);
  llvm_cbe_tmp__129 = (signed long long *)(&llvm_cbe_outsub[(((signed long long )llvm_cbe_axis))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\naxis = 0x%I64X",((signed long long )llvm_cbe_axis));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [5 x i64]* %%outsub, i64 0, i64 0, !dbg !7 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_548_count);
  llvm_cbe_tmp__130 = (signed long long *)(&llvm_cbe_outsub[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 0, !dbg !7 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_549_count);
  llvm_cbe_tmp__131 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 1, !dbg !7 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_550_count);
  llvm_cbe_tmp__132 = (signed long long *)(&llvm_cbe_output->field1);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__133__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__159;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__159:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i64 [ 0, %%.lr.ph5 ], [ %%39, %%._crit_edge  for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__158);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = phi i64 [ 0, %%.lr.ph5 ], [ %%38, %%._crit_edge  for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_552_count);
  llvm_cbe_tmp__133 = (unsigned long long )llvm_cbe_tmp__133__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__133);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__157);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i8** %%args, align 8, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_559_count);
  llvm_cbe_tmp__134 = ( char *)*(&llvm_cbe_args);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = bitcast i8* %%12 to %%struct.k2c_tensor**, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_560_count);
  llvm_cbe_tmp__135 = (l_struct_OC_k2c_tensor **)((l_struct_OC_k2c_tensor **)llvm_cbe_tmp__134);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr i8* %%12, i64 8, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_561_count);
  llvm_cbe_tmp__136 = ( char *)(&llvm_cbe_tmp__134[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%14, i8** %%args, align 8, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_568_count);
  *(&llvm_cbe_args) = ( char *)llvm_cbe_tmp__136;
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load %%struct.k2c_tensor** %%13, align 8, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_569_count);
  llvm_cbe_tmp__137 = (l_struct_OC_k2c_tensor *)*llvm_cbe_tmp__135;
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.k2c_tensor* %%15, i64 0, i32 2, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_581_count);
  llvm_cbe_tmp__138 = (signed long long *)(&llvm_cbe_tmp__137->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i64* %%16, align 8, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_582_count);
  llvm_cbe_tmp__139 = (unsigned long long )*llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__139);
  if (((llvm_cbe_tmp__139&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct.k2c_tensor* %%15, i64 0, i32 3, i64 %%axis, !dbg !8 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_612_count);
  llvm_cbe_tmp__155 = (signed long long *)(&llvm_cbe_tmp__137->field3[(((signed long long )llvm_cbe_axis))]);
if (AESL_DEBUG_TRACE) {
printf("\naxis = 0x%I64X",((signed long long )llvm_cbe_axis));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i64* %%36, align 8, !dbg !8 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_613_count);
  llvm_cbe_tmp__156 = (unsigned long long )*llvm_cbe_tmp__155;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__156);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add i64 %%37, %%11, !dbg !8 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_614_count);
  llvm_cbe_tmp__157 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__156&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__133&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__157&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i64 %%storemerge3, 1, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_618_count);
  llvm_cbe_tmp__158 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__158&18446744073709551615ull)));
  if (((llvm_cbe_tmp__158&18446744073709551615ULL) == (llvm_cbe_num_tensors&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__158;   /* for PHI node */
    llvm_cbe_tmp__133__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__157;   /* for PHI node */
    goto llvm_cbe_tmp__159;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__160:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ 0, %%.lr.ph ], [ %%33, %%21  for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__153);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i64* %%20, align 8, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_588_count);
  llvm_cbe_tmp__142 = (unsigned long long )*llvm_cbe_tmp__141;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__142);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = call i32 bitcast (i32 (...)* @k2c_idx2sub to i32 (i64, i64*, i64*, i64)*)(i64 %%storemerge12, i64* %%3, i64* %%19, i64 %%22) nounwind, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_589_count);
  k2c_idx2sub(llvm_cbe_storemerge12, (signed long long *)llvm_cbe_tmp__126, (signed long long *)llvm_cbe_tmp__140, llvm_cbe_tmp__142);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__142);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__143);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call i8* @memcpy(i8* %%4, i8* %%5, i64 40 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_590_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__127, ( char *)llvm_cbe_tmp__128, 40ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__144);
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_axis) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'outsub' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i64* %%6, align 8, !dbg !8 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_591_count);
  llvm_cbe_tmp__145 = (unsigned long long )*llvm_cbe_tmp__129;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__145);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i64 %%25, %%11, !dbg !8 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_592_count);
  llvm_cbe_tmp__146 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__145&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__133&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__146&18446744073709551615ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_axis) < 5 && "Write access out of array 'outsub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%26, i64* %%6, align 8, !dbg !8 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_593_count);
  *llvm_cbe_tmp__129 = llvm_cbe_tmp__146;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__146);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i64* %%9, align 8, !dbg !7 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_594_count);
  llvm_cbe_tmp__147 = (unsigned long long )*llvm_cbe_tmp__132;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__147);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = call i32 bitcast (i32 (...)* @k2c_sub2idx to i32 (i64*, i64*, i64)*)(i64* %%7, i64* %%8, i64 %%27) nounwind, !dbg !7 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_595_count);
  llvm_cbe_tmp__148 = (unsigned int )k2c_sub2idx((signed long long *)llvm_cbe_tmp__130, (signed long long *)llvm_cbe_tmp__131, llvm_cbe_tmp__147);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__147);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__148);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = sext i32 %%28 to i64, !dbg !7 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_596_count);
  llvm_cbe_tmp__149 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__148);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__149);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.k2c_tensor* %%15, i64 0, i32 0, i64 %%storemerge12, !dbg !7 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_598_count);
  llvm_cbe_tmp__150 = (float *)(&llvm_cbe_tmp__137->field0[(((signed long long )llvm_cbe_storemerge12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",((signed long long )llvm_cbe_storemerge12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load float* %%30, align 4, !dbg !7 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_599_count);
  llvm_cbe_tmp__151 = (float )*llvm_cbe_tmp__150;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__151, *(int*)(&llvm_cbe_tmp__151));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%29, !dbg !7 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_601_count);
  llvm_cbe_tmp__152 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__149))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__149));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%31, float* %%32, align 4, !dbg !7 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_602_count);
  *llvm_cbe_tmp__152 = llvm_cbe_tmp__151;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__151);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add i64 %%storemerge12, 1, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_603_count);
  llvm_cbe_tmp__153 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__153&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i64* %%16, align 8, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_609_count);
  llvm_cbe_tmp__154 = (unsigned long long )*llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__154);
  if ((((unsigned long long )llvm_cbe_tmp__153&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__154&18446744073709551615ULL))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__153;   /* for PHI node */
    goto llvm_cbe_tmp__160;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.k2c_tensor* %%15, i64 0, i32 3, i64 0, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_585_count);
  llvm_cbe_tmp__140 = (signed long long *)(&llvm_cbe_tmp__137->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.k2c_tensor* %%15, i64 0, i32 1, !dbg !10 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_586_count);
  llvm_cbe_tmp__141 = (signed long long *)(&llvm_cbe_tmp__137->field1);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__160;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge6:
if (AESL_DEBUG_TRACE)
printf("\n  call void @llvm.va_end(i8* %%1), !dbg !11 for 0x%I64xth hint within @k2c_concatenate  --> \n", ++aesl_llvm_cbe_623_count);
  0; va_end(*(va_list*)llvm_cbe_tmp__125);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_concatenate}\n");
  return;
}

