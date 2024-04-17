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
typedef struct l_struct_OC_k2c_tensor2 l_struct_OC_k2c_tensor2;

/* Structure contents */
struct l_struct_OC_k2c_tensor {
  float field0[262200];
  unsigned long long field1;
  unsigned long long field2;
  signed long long field3[5];
};

struct l_struct_OC_k2c_tensor2 {
  float field0[2622];
  unsigned long long field1;
  unsigned long long field2;
  signed long long field3[5];
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void k2c_pad1d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, float llvm_cbe_fill, signed long long *llvm_cbe_pad);
void k2c_pad2d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, float llvm_cbe_fill, signed long long *llvm_cbe_pad);
void k2c_pad3d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, float llvm_cbe_fill, signed long long *llvm_cbe_pad);
void k2c_conv1d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, signed long long llvm_cbe_stride, signed long long llvm_cbe_dilation, void  (*llvm_cbe_activation) (float *, unsigned long long ));
void k2c_bias_add(l_struct_OC_k2c_tensor2 *, l_struct_OC_k2c_tensor2 *);
void k2c_conv2d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, signed long long *llvm_cbe_stride, signed long long *llvm_cbe_dilation, void  (*llvm_cbe_activation) (float *, unsigned long long ));
void k2c_conv3d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, signed long long *llvm_cbe_stride, signed long long *llvm_cbe_dilation, void  (*llvm_cbe_activation) (float *, unsigned long long ));
void k2c_crop1d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_crop);
void k2c_crop2d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_crop);
void k2c_crop3d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_crop);
void k2c_upsampling1d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long llvm_cbe_size);
void k2c_upsampling2d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_size);
signed long long k2c_sub2idx(signed long long *, signed long long *, signed long long );
void k2c_upsampling3d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_size);


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

void k2c_pad1d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, float llvm_cbe_fill, signed long long *llvm_cbe_pad) {
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
  signed long long *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  double llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  double llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  signed long long *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  signed long long *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
   char *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  float *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  float *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
   char *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
   char *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  signed long long *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned long long llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned long long llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
   char *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_pad1d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__1 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__2 = (unsigned long long )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i64* %%pad, align 8, !dbg !12 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__3 = (unsigned long long )*llvm_cbe_pad;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = fpext float %%fill to double, !dbg !12 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__4 = (double )((double )llvm_cbe_fill);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__4, *(long long*)(&llvm_cbe_tmp__4));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call double @fabs(double %%4) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__5 = (double ) /*tail*/ fabs(llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__4, *(long long*)(&llvm_cbe_tmp__4));
printf("\nReturn  = %lf",llvm_cbe_tmp__5);
}
  if ((llvm_fcmp_olt(llvm_cbe_tmp__5, 0x1.0c6f7a0b5ed8dp-20))) {
    goto llvm_cbe_tmp__24;
  } else {
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__6 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i64* %%7, align 8, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__7 = (unsigned long long )*llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__7);
  if (((llvm_cbe_tmp__7&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__24:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = bitcast %%struct.k2c_tensor* %%output to i8*, !dbg !10 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__8 = ( char *)(( char *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !10 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__9 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i64* %%12, align 8, !dbg !10 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__10 = (unsigned long long )*llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = shl i64 %%13, 2, !dbg !10 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__11 = (unsigned long long )llvm_cbe_tmp__10 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = call i8* @memset(i8* %%11, i32 0, i64 %%14 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_38_count);
  ( char *)memset(( char *)llvm_cbe_tmp__8, 0u, llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__11);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__12);
}
  goto llvm_cbe_tmp__25;

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%17, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__14);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge1, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__13 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%fill, float* %%16, align 4, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_41_count);
  *llvm_cbe_tmp__13 = llvm_cbe_fill;
if (AESL_DEBUG_TRACE)
printf("\nfill = %f\n", llvm_cbe_fill);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add i64 %%storemerge1, 1, !dbg !13 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__14 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__14&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i64* %%7, align 8, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__15 = (unsigned long long )*llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__15);
  if ((((unsigned long long )llvm_cbe_tmp__14&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__15&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__14;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e_loopexit:
  goto llvm_cbe_tmp__25;

llvm_cbe_tmp__25:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = mul i64 %%3, %%2, !dbg !12 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__16 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__3&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__16&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%21, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__17 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__16))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__16));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = bitcast float* %%22 to i8*, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__18 = ( char *)(( char *)llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = bitcast %%struct.k2c_tensor* %%input to i8*, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__19 = ( char *)(( char *)llvm_cbe_input);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 2, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__20 = (signed long long *)(&llvm_cbe_input->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i64* %%25, align 8, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__21 = (unsigned long long )*llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = shl i64 %%26, 2, !dbg !11 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__22 = (unsigned long long )llvm_cbe_tmp__21 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = call i8* @memcpy(i8* %%23, i8* %%24, i64 %%27 for 0x%I64xth hint within @k2c_pad1d  --> \n", ++aesl_llvm_cbe_60_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__18, ( char *)llvm_cbe_tmp__19, llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__22);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__23);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_pad1d}\n");
  return;
}


void k2c_pad2d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, float llvm_cbe_fill, signed long long *llvm_cbe_pad) {
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
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  signed long long *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned long long llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  signed long long *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned long long llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  signed long long *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned long long llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  signed long long *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  unsigned long long llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  signed long long *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  unsigned long long llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  double llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  double llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  signed long long *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned long long llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
   char *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  signed long long *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned long long llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  unsigned long long llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
   char *llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned long long llvm_cbe_storemerge4;
  unsigned long long llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  float *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  unsigned long long llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned long long llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned long long llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_tmp_count = 0;
  unsigned long long llvm_cbe_tmp;
  static  unsigned long long aesl_llvm_cbe_tmp2_count = 0;
  unsigned long long llvm_cbe_tmp2;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned long long llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  unsigned long long llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  unsigned long long llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge13_count = 0;
  unsigned long long llvm_cbe_storemerge13;
  unsigned long long llvm_cbe_storemerge13__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  unsigned long long llvm_cbe_tmp__55;
  unsigned long long llvm_cbe_tmp__55__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  float *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
   char *llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  unsigned long long llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  float *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
   char *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
   char *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  unsigned long long llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_pad2d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__26 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !12 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__27 = (unsigned long long )*llvm_cbe_tmp__26;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !12 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__28 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !12 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__29 = (unsigned long long )*llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 2, !dbg !12 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__30 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !12 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__31 = (unsigned long long )*llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%pad, align 8, !dbg !12 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__32 = (unsigned long long )*llvm_cbe_pad;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i64* %%pad, i64 2, !dbg !13 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__33 = (signed long long *)(&llvm_cbe_pad[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%8, align 8, !dbg !13 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__34 = (unsigned long long )*llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i64* %%pad, i64 3, !dbg !13 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__35 = (signed long long *)(&llvm_cbe_pad[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%10, align 8, !dbg !13 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__36 = (unsigned long long )*llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = fpext float %%fill to double, !dbg !12 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__37 = (double )((double )llvm_cbe_fill);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__37, *(long long*)(&llvm_cbe_tmp__37));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = tail call double @fabs(double %%12) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__38 = (double ) /*tail*/ fabs(llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__37, *(long long*)(&llvm_cbe_tmp__37));
printf("\nReturn  = %lf",llvm_cbe_tmp__38);
}
  if ((llvm_fcmp_olt(llvm_cbe_tmp__38, 0x1.0c6f7a0b5ed8dp-20))) {
    goto llvm_cbe_tmp__64;
  } else {
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !11 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__39 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i64* %%15, align 8, !dbg !11 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__40 = (unsigned long long )*llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__40);
  if (((llvm_cbe_tmp__40&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  }

llvm_cbe_tmp__64:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = bitcast %%struct.k2c_tensor* %%output to i8*, !dbg !10 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__41 = ( char *)(( char *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !10 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__42 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i64* %%20, align 8, !dbg !10 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__43 = (unsigned long long )*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = shl i64 %%21, 2, !dbg !10 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__44 = (unsigned long long )llvm_cbe_tmp__43 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = call i8* @memset(i8* %%19, i32 0, i64 %%22 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_125_count);
  ( char *)memset(( char *)llvm_cbe_tmp__41, 0u, llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__44);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__45);
}
  goto llvm_cbe_tmp__65;

  do {     /* Syntactic loop '.lr.ph5' to make GCC happy */
llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i64 [ %%25, %%.lr.ph5 ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned long long )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%I64X",llvm_cbe_storemerge4);
printf("\n = 0x%I64X",llvm_cbe_tmp__47);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge4, !dbg !11 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__46 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge4))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%I64X",((signed long long )llvm_cbe_storemerge4));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%fill, float* %%24, align 4, !dbg !11 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_128_count);
  *llvm_cbe_tmp__46 = llvm_cbe_fill;
if (AESL_DEBUG_TRACE)
printf("\nfill = %f\n", llvm_cbe_fill);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i64 %%storemerge4, 1, !dbg !14 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__47 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge4&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__47&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i64* %%15, align 8, !dbg !11 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__48 = (unsigned long long )*llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
  if ((((unsigned long long )llvm_cbe_tmp__47&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__48&18446744073709551615ULL))) {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__47;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

  } while (1); /* end of syntactic loop '.lr.ph5' */
llvm_cbe__2e_loopexit:
  goto llvm_cbe_tmp__65;

llvm_cbe_tmp__65:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i64 %%11, %%9, !dbg !13 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__49 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__36&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__34&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__49&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add i64 %%29, %%4, !dbg !13 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__50 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__49&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__29&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__50&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = mul i64 %%7, %%30, !dbg !13 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__51 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__32&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__50&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__51&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp = add i64 %%31, %% for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_tmp_count);
  llvm_cbe_tmp = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__51&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__34&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp2 = mul i64 %%tmp, %%6, !dbg !13 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_tmp2_count);
  llvm_cbe_tmp2 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp2 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp2&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = mul i64 %%6, %%4, !dbg !13 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__52 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__29&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__52&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = mul i64 %%30, %%6, !dbg !13 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__53 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__50&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__53&18446744073709551615ull)));
  if (((llvm_cbe_tmp__27&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = shl i64 %%32, 2, !dbg !11 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__54 = (unsigned long long )llvm_cbe_tmp__52 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__54);
  llvm_cbe_storemerge13__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__55__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp2;   /* for PHI node */
  goto llvm_cbe_tmp__66;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__66:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge13 = phi i64 [ 0, %%.lr.ph ], [ %%45, %%36  for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_storemerge13_count);
  llvm_cbe_storemerge13 = (unsigned long long )llvm_cbe_storemerge13__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge13 = 0x%I64X",llvm_cbe_storemerge13);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__63);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = phi i64 [ %%tmp2, %%.lr.ph ], [ %%44, %%36  for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_160_count);
  llvm_cbe_tmp__55 = (unsigned long long )llvm_cbe_tmp__55__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__55);
printf("\ntmp2 = 0x%I64X",llvm_cbe_tmp2);
printf("\n = 0x%I64X",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%37, !dbg !11 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__56 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__55))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__55));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = bitcast float* %%38 to i8*, !dbg !11 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__57 = ( char *)(( char *)llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = mul i64 %%storemerge13, %%32, !dbg !11 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__58 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge13&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__52&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__58&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%40, !dbg !11 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__59 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__58))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__58));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = bitcast float* %%41 to i8*, !dbg !11 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__60 = ( char *)(( char *)llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = call i8* @memcpy(i8* %%39, i8* %%42, i64 %%35 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_166_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__57, ( char *)llvm_cbe_tmp__60, llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__54);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__61);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = add i64 %%37, %%33, !dbg !14 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__62 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__55&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__53&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__62&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add i64 %%storemerge13, 1, !dbg !15 for 0x%I64xth hint within @k2c_pad2d  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__63 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge13&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__63&18446744073709551615ull)));
  if (((llvm_cbe_tmp__63&18446744073709551615ULL) == (llvm_cbe_tmp__27&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge13__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__63;   /* for PHI node */
    llvm_cbe_tmp__55__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__62;   /* for PHI node */
    goto llvm_cbe_tmp__66;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_pad2d}\n");
  return;
}


void k2c_pad3d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, float llvm_cbe_fill, signed long long *llvm_cbe_pad) {
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
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  signed long long *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  unsigned long long llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  signed long long *llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  unsigned long long llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  signed long long *llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  unsigned long long llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  signed long long *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  unsigned long long llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  signed long long *llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  unsigned long long llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  unsigned long long llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  signed long long *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  unsigned long long llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  signed long long *llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  unsigned long long llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  unsigned long long llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  unsigned long long llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  signed long long *llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  unsigned long long llvm_cbe_tmp__86;
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
  double llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  double llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  signed long long *llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  unsigned long long llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
   char *llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  signed long long *llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  unsigned long long llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  unsigned long long llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
   char *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge19_count = 0;
  unsigned long long llvm_cbe_storemerge19;
  unsigned long long llvm_cbe_storemerge19__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  float *llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  unsigned long long llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  unsigned long long llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  unsigned long long llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  unsigned long long llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  unsigned long long llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  unsigned long long llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  unsigned long long llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_tmp13_count = 0;
  unsigned long long llvm_cbe_tmp13;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  unsigned long long llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  unsigned long long llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  unsigned long long llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond21_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge215_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge215_2e_us;
  unsigned long long llvm_cbe_storemerge215_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  unsigned long long llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_tmp4_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp4_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp5_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp5_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp10_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp10_2e_us;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  float *llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
   char *llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_tmp12_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp12_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp14_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp14_2e_us;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  float *llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
   char *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
   char *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  unsigned long long llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge116_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge116_2e_us;
  unsigned long long llvm_cbe_storemerge116_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_tmp6_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp6_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp7_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp7_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp8_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp8_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp9_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp9_2e_us;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  unsigned long long llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_pad3d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__67 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !12 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__68 = (unsigned long long )*llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !12 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__69 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !12 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__70 = (unsigned long long )*llvm_cbe_tmp__69;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 2, !dbg !12 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__71 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !12 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__72 = (unsigned long long )*llvm_cbe_tmp__71;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i64* %%pad, i64 2, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_223_count);
  llvm_cbe_tmp__73 = (signed long long *)(&llvm_cbe_pad[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i64* %%7, align 8, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_224_count);
  llvm_cbe_tmp__74 = (unsigned long long )*llvm_cbe_tmp__73;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i64* %%pad, i64 3, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_225_count);
  llvm_cbe_tmp__75 = (signed long long *)(&llvm_cbe_pad[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i64* %%9, align 8, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__76 = (unsigned long long )*llvm_cbe_tmp__75;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i64 %%8, %%4, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__77 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__74&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__70&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__77&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i64 %%11, %%10, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__78 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__77&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__76&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__78&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i64* %%pad, i64 4, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_232_count);
  llvm_cbe_tmp__79 = (signed long long *)(&llvm_cbe_pad[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%13, align 8, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_233_count);
  llvm_cbe_tmp__80 = (unsigned long long )*llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds i64* %%pad, i64 5, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_234_count);
  llvm_cbe_tmp__81 = (signed long long *)(&llvm_cbe_pad[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i64* %%15, align 8, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_235_count);
  llvm_cbe_tmp__82 = (unsigned long long )*llvm_cbe_tmp__81;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add i64 %%14, %%6, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_236_count);
  llvm_cbe_tmp__83 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__80&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__72&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__83&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i64 %%17, %%16, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_237_count);
  llvm_cbe_tmp__84 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__83&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__82&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__84&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 3, !dbg !12 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__85 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i64* %%19, align 8, !dbg !12 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_243_count);
  llvm_cbe_tmp__86 = (unsigned long long )*llvm_cbe_tmp__85;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = fpext float %%fill to double, !dbg !12 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_253_count);
  llvm_cbe_tmp__87 = (double )((double )llvm_cbe_fill);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__87, *(long long*)(&llvm_cbe_tmp__87));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = tail call double @fabs(double %%21) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_254_count);
  llvm_cbe_tmp__88 = (double ) /*tail*/ fabs(llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__87, *(long long*)(&llvm_cbe_tmp__87));
printf("\nReturn  = %lf",llvm_cbe_tmp__88);
}
  if ((llvm_fcmp_olt(llvm_cbe_tmp__88, 0x1.0c6f7a0b5ed8dp-20))) {
    goto llvm_cbe_tmp__116;
  } else {
    goto llvm_cbe__2e_preheader18;
  }

llvm_cbe__2e_preheader18:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_260_count);
  llvm_cbe_tmp__89 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i64* %%24, align 8, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_261_count);
  llvm_cbe_tmp__90 = (unsigned long long )*llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__90);
  if (((llvm_cbe_tmp__90&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge19__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph20;
  }

llvm_cbe_tmp__116:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = bitcast %%struct.k2c_tensor* %%output to i8*, !dbg !10 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_264_count);
  llvm_cbe_tmp__91 = ( char *)(( char *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !10 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_265_count);
  llvm_cbe_tmp__92 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i64* %%29, align 8, !dbg !10 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_266_count);
  llvm_cbe_tmp__93 = (unsigned long long )*llvm_cbe_tmp__92;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__93);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = shl i64 %%30, 2, !dbg !10 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_267_count);
  llvm_cbe_tmp__94 = (unsigned long long )llvm_cbe_tmp__93 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = call i8* @memset(i8* %%28, i32 0, i64 %%31 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_268_count);
  ( char *)memset(( char *)llvm_cbe_tmp__91, 0u, llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__94);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__95);
}
  goto llvm_cbe_tmp__117;

  do {     /* Syntactic loop '.lr.ph20' to make GCC happy */
llvm_cbe__2e_lr_2e_ph20:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge19 = phi i64 [ %%34, %%.lr.ph20 ], [ 0, %%.preheader18  for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_storemerge19_count);
  llvm_cbe_storemerge19 = (unsigned long long )llvm_cbe_storemerge19__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge19 = 0x%I64X",llvm_cbe_storemerge19);
printf("\n = 0x%I64X",llvm_cbe_tmp__97);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge19, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_270_count);
  llvm_cbe_tmp__96 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge19))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge19 = 0x%I64X",((signed long long )llvm_cbe_storemerge19));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%fill, float* %%33, align 4, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_271_count);
  *llvm_cbe_tmp__96 = llvm_cbe_fill;
if (AESL_DEBUG_TRACE)
printf("\nfill = %f\n", llvm_cbe_fill);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add i64 %%storemerge19, 1, !dbg !15 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_272_count);
  llvm_cbe_tmp__97 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge19&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__97&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i64* %%24, align 8, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_277_count);
  llvm_cbe_tmp__98 = (unsigned long long )*llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__98);
  if ((((unsigned long long )llvm_cbe_tmp__97&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__98&18446744073709551615ULL))) {
    llvm_cbe_storemerge19__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__97;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph20;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

  } while (1); /* end of syntactic loop '.lr.ph20' */
llvm_cbe__2e_loopexit:
  goto llvm_cbe_tmp__117;

llvm_cbe_tmp__117:
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i64* %%pad, align 8, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_281_count);
  llvm_cbe_tmp__99 = (unsigned long long )*llvm_cbe_pad;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i64* %%7, align 8, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__100 = (unsigned long long )*llvm_cbe_tmp__73;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i64* %%13, align 8, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_283_count);
  llvm_cbe_tmp__101 = (unsigned long long )*llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load i64* %%15, align 8, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_284_count);
  llvm_cbe_tmp__102 = (unsigned long long )*llvm_cbe_tmp__81;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add i64 %%40, %%6, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_285_count);
  llvm_cbe_tmp__103 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__101&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__72&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__103&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add i64 %%42, %%41, !dbg !13 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_286_count);
  llvm_cbe_tmp__104 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__103&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__102&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__104&18446744073709551615ull)));
  if (((llvm_cbe_tmp__68&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__118;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp13 = mul i64 %%20, %% for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_tmp13_count);
  llvm_cbe_tmp13 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__86&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__72&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp13 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp13&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = shl i64 %%6, 2, !dbg !14 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_295_count);
  llvm_cbe_tmp__105 = (unsigned long long )llvm_cbe_tmp__72 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = mul i64 %%46, %%20, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_296_count);
  llvm_cbe_tmp__106 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__105&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__86&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__106&18446744073709551615ull)));
  if (((llvm_cbe_tmp__70&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge17;
  } else {
    llvm_cbe_storemerge116_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge116.us = phi i64 [ %%49, %%48 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_storemerge116_2e_us_count);
  llvm_cbe_storemerge116_2e_us = (unsigned long long )llvm_cbe_storemerge116_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge116.us = 0x%I64X",llvm_cbe_storemerge116_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__107);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp6.us = add i64 %%storemerge116.us, %%3 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_tmp6_2e_us_count);
  llvm_cbe_tmp6_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge116_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__99&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp6.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp6_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp7.us = mul i64 %%12, %%tmp6.u for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_tmp7_2e_us_count);
  llvm_cbe_tmp7_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__78&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp6_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp7.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp7_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp8.us = add i64 %%tmp7.us, %%3 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_tmp8_2e_us_count);
  llvm_cbe_tmp8_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp7_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__100&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp8.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp8_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp9.us = mul i64 %%tmp8.us, %%1 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_tmp9_2e_us_count);
  llvm_cbe_tmp9_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp8_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__84&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp9.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp9_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = mul i64 %%4, %%storemerge116.us, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_322_count);
  llvm_cbe_tmp__115 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__70&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge116_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__115&18446744073709551615ull)));
  llvm_cbe_storemerge215_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__119;

llvm_cbe_tmp__120:
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add i64 %%storemerge116.us, 1, !dbg !15 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_298_count);
  llvm_cbe_tmp__107 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge116_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__107&18446744073709551615ull)));
  if (((llvm_cbe_tmp__107&18446744073709551615ULL) == (llvm_cbe_tmp__68&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge17;
  } else {
    llvm_cbe_storemerge116_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__107;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__119:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge215.us = phi i64 [ 0, %%.lr.ph.us ], [ %%57, %%50  for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_storemerge215_2e_us_count);
  llvm_cbe_storemerge215_2e_us = (unsigned long long )llvm_cbe_storemerge215_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge215.us = 0x%I64X",llvm_cbe_storemerge215_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__114);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = mul i64 %%43, %%storemerge215.us, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__108 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__104&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge215_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__108&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp4.us = add i64 %%51, %%4 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_tmp4_2e_us_count);
  llvm_cbe_tmp4_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__108&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__101&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp4.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp4_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp5.us = add i64 %%tmp4.us, %%tmp9.u for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_tmp5_2e_us_count);
  llvm_cbe_tmp5_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp4_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp9_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp5.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp5_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp10.us = mul i64 %%tmp5.us, %%20, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_tmp10_2e_us_count);
  llvm_cbe_tmp10_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp5_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__86&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp10.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp10_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%tmp10.us, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_306_count);
  llvm_cbe_tmp__109 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp10_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\ntmp10.us = 0x%I64X",((signed long long )llvm_cbe_tmp10_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = bitcast float* %%52 to i8*, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_307_count);
  llvm_cbe_tmp__110 = ( char *)(( char *)llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp12.us = add i64 %%storemerge215.us, %%5 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_tmp12_2e_us_count);
  llvm_cbe_tmp12_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge215_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__115&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp12.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp12_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp14.us = mul i64 %%tmp13, %%tmp12.us, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_tmp14_2e_us_count);
  llvm_cbe_tmp14_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp13&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp12_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp14.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp14_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%tmp14.us, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_308_count);
  llvm_cbe_tmp__111 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp14_2e_us))]);
if (AESL_DEBUG_TRACE) {
printf("\ntmp14.us = 0x%I64X",((signed long long )llvm_cbe_tmp14_2e_us));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = bitcast float* %%54 to i8*, !dbg !11 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_309_count);
  llvm_cbe_tmp__112 = ( char *)(( char *)llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = call i8* @memcpy(i8* %%53, i8* %%55, i64 %%47 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_310_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__110, ( char *)llvm_cbe_tmp__112, llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__106);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__113);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = add i64 %%storemerge215.us, 1, !dbg !15 for 0x%I64xth hint within @k2c_pad3d  --> \n", ++aesl_llvm_cbe_311_count);
  llvm_cbe_tmp__114 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge215_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__114&18446744073709551615ull)));
  if (((llvm_cbe_tmp__114&18446744073709551615ULL) == (llvm_cbe_tmp__70&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__120;
  } else {
    llvm_cbe_storemerge215_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__114;   /* for PHI node */
    goto llvm_cbe_tmp__119;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e__crit_edge17:
  goto llvm_cbe_tmp__118;

llvm_cbe_tmp__118:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_pad3d}\n");
  return;
}


void k2c_conv1d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, signed long long llvm_cbe_stride, signed long long llvm_cbe_dilation, void  (*llvm_cbe_activation) (float *, unsigned long long )) {
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
   char *llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  signed long long *llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  unsigned long long llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  unsigned long long llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
   char *llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  signed long long *llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  unsigned long long llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  signed long long *llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  unsigned long long llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  signed long long *llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  unsigned long long llvm_cbe_tmp__131;
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
  signed long long *llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  signed long long *llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  signed long long *llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned long long llvm_cbe_storemerge14;
  unsigned long long llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  unsigned long long llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  unsigned long long llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  unsigned long long llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge110_count = 0;
  unsigned long long llvm_cbe_storemerge110;
  unsigned long long llvm_cbe_storemerge110__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  unsigned long long llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  unsigned long long llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  unsigned long long llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  unsigned long long llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond16_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge35_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge35_2e_us;
  unsigned long long llvm_cbe_storemerge35_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  unsigned long long llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  unsigned long long llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  unsigned long long llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_tmp_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp4_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp4_2e_us;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  unsigned long long llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  float *llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  float llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  float llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  float llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  unsigned long long llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  float *llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  float llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  float llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  unsigned long long llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge27_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge27_2e_us;
  unsigned long long llvm_cbe_storemerge27_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  unsigned long long llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  float *llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  unsigned long long llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  unsigned long long llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  unsigned long long llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond18_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  l_struct_OC_k2c_tensor2 *llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  l_struct_OC_k2c_tensor2 *llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  float *llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  unsigned long long llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_conv1d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast %%struct.k2c_tensor* %%output to i8*, !dbg !10 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__121 = ( char *)(( char *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !10 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__122 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i64* %%2, align 8, !dbg !10 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_354_count);
  llvm_cbe_tmp__123 = (unsigned long long )*llvm_cbe_tmp__122;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = shl i64 %%3, 2, !dbg !10 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_355_count);
  llvm_cbe_tmp__124 = (unsigned long long )llvm_cbe_tmp__123 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @memset(i8* %%1, i32 0, i64 %%4 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_356_count);
  ( char *)memset(( char *)llvm_cbe_tmp__121, 0u, llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__124);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__125);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 0, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__126 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%6, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__127 = (unsigned long long )*llvm_cbe_tmp__126;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__127);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_361_count);
  llvm_cbe_tmp__128 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%8, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_362_count);
  llvm_cbe_tmp__129 = (unsigned long long )*llvm_cbe_tmp__128;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !12 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_366_count);
  llvm_cbe_tmp__130 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%10, align 8, !dbg !12 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_367_count);
  llvm_cbe_tmp__131 = (unsigned long long )*llvm_cbe_tmp__130;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__131);
  if (((llvm_cbe_tmp__127&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge15;
  } else {
    goto llvm_cbe__2e_preheader9_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader9_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_378_count);
  llvm_cbe_tmp__132 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 2, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_381_count);
  llvm_cbe_tmp__133 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_382_count);
  llvm_cbe_tmp__134 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader9;

  do {     /* Syntactic loop '.preheader9' to make GCC happy */
llvm_cbe__2e_preheader9:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i64 [ 0, %%.preheader9.lr.ph ], [ %%47, %%._crit_edge13  for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned long long )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%I64X",llvm_cbe_storemerge14);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__159);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i64* %%13, align 8, !dbg !12 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_388_count);
  llvm_cbe_tmp__135 = (unsigned long long )*llvm_cbe_tmp__132;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__135);
  if (((llvm_cbe_tmp__135&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge13;
  } else {
    goto llvm_cbe__2e_preheader6_2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge13:
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = add i64 %%storemerge14, 1, !dbg !14 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_447_count);
  llvm_cbe_tmp__159 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__159&18446744073709551615ull)));
  if (((llvm_cbe_tmp__159&18446744073709551615ULL) == (llvm_cbe_tmp__127&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge15;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__159;   /* for PHI node */
    goto llvm_cbe__2e_preheader9;
  }

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge110 = phi i64 [ 0, %%.preheader6.lr.ph ], [ %%44, %%43  for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_storemerge110_count);
  llvm_cbe_storemerge110 = (unsigned long long )llvm_cbe_storemerge110__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge110 = 0x%I64X",llvm_cbe_storemerge110);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__157);
}
  if (((llvm_cbe_tmp__131&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__164;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe_tmp__164:
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = add i64 %%storemerge110, 1, !dbg !14 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_438_count);
  llvm_cbe_tmp__157 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge110&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__157&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i64* %%13, align 8, !dbg !12 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_444_count);
  llvm_cbe_tmp__158 = (unsigned long long )*llvm_cbe_tmp__132;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__158);
  if ((((unsigned long long )llvm_cbe_tmp__157&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__158&18446744073709551615ULL))) {
    llvm_cbe_storemerge110__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__157;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  } else {
    goto llvm_cbe__2e__crit_edge13;
  }

llvm_cbe__2e__crit_edge8:
  goto llvm_cbe_tmp__164;

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = mul i64 %%storemerge110, %%dilation, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_399_count);
  llvm_cbe_tmp__138 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge110&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_dilation&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__138&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add i64 %%22, %%20, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_400_count);
  llvm_cbe_tmp__139 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__138&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__136&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__139&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = mul i64 %%23, %%11, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_401_count);
  llvm_cbe_tmp__140 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__139&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__131&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__140&18446744073709551615ull)));
  if (((llvm_cbe_tmp__129&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge8;
  } else {
    llvm_cbe_storemerge27_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge27.us = phi i64 [ %%26, %%25 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_storemerge27_2e_us_count);
  llvm_cbe_storemerge27_2e_us = (unsigned long long )llvm_cbe_storemerge27_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge27.us = 0x%I64X",llvm_cbe_storemerge27_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__141);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add i64 %%storemerge27.us, %%24, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_434_count);
  llvm_cbe_tmp__155 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge27_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__140&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__155&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%41, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_435_count);
  llvm_cbe_tmp__156 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__155))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__155));
}
  llvm_cbe_storemerge35_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__165;

llvm_cbe_tmp__166:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i64 %%storemerge27.us, 1, !dbg !14 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_403_count);
  llvm_cbe_tmp__141 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge27_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__141&18446744073709551615ull)));
  if (((llvm_cbe_tmp__141&18446744073709551615ULL) == (llvm_cbe_tmp__131&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge8;
  } else {
    llvm_cbe_storemerge27_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__141;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__165:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge35.us = phi i64 [ 0, %%.lr.ph.us ], [ %%40, %%27  for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_storemerge35_2e_us_count);
  llvm_cbe_storemerge35_2e_us = (unsigned long long )llvm_cbe_storemerge35_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge35.us = 0x%I64X",llvm_cbe_storemerge35_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__154);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i64* %%16, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_410_count);
  llvm_cbe_tmp__142 = (unsigned long long )*llvm_cbe_tmp__133;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__142);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i64* %%17, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_411_count);
  llvm_cbe_tmp__143 = (unsigned long long )*llvm_cbe_tmp__134;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__143);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = mul i64 %%storemerge110, %%29, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_412_count);
  llvm_cbe_tmp__144 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge110&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__143&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__144&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp.us = add i64 %%30, %%storemerge27.u for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_tmp_2e_us_count);
  llvm_cbe_tmp_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__144&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge27_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp4.us = mul i64 %%tmp.us, %%2 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_tmp4_2e_us_count);
  llvm_cbe_tmp4_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__142&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp4.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp4_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add i64 %%tmp4.us, %%storemerge35.us, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_413_count);
  llvm_cbe_tmp__145 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp4_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge35_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__145&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 0, i64 %%31, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_414_count);
  llvm_cbe_tmp__146 = (float *)(&llvm_cbe_kernel->field0[(((signed long long )llvm_cbe_tmp__145))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__145));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load float* %%32, align 4, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_415_count);
  llvm_cbe_tmp__147 = (float )*llvm_cbe_tmp__146;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__147, *(int*)(&llvm_cbe_tmp__147));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load float* %%42, align 4, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_416_count);
  llvm_cbe_tmp__148 = (float )*llvm_cbe_tmp__156;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__148, *(int*)(&llvm_cbe_tmp__148));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = fmul float %%33, %%34, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_417_count);
  llvm_cbe_tmp__149 = (float )((float )(llvm_cbe_tmp__147 * llvm_cbe_tmp__148));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__149, *(int*)(&llvm_cbe_tmp__149));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = add i64 %%storemerge35.us, %%21, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_418_count);
  llvm_cbe_tmp__150 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge35_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__137&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__150&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%36, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_419_count);
  llvm_cbe_tmp__151 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__150))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__150));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load float* %%37, align 4, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_420_count);
  llvm_cbe_tmp__152 = (float )*llvm_cbe_tmp__151;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__152, *(int*)(&llvm_cbe_tmp__152));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = fadd float %%38, %%35, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_421_count);
  llvm_cbe_tmp__153 = (float )((float )(llvm_cbe_tmp__152 + llvm_cbe_tmp__149));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__153, *(int*)(&llvm_cbe_tmp__153));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%39, float* %%37, align 4, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_422_count);
  *llvm_cbe_tmp__151 = llvm_cbe_tmp__153;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__153);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add i64 %%storemerge35.us, 1, !dbg !15 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_423_count);
  llvm_cbe_tmp__154 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge35_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__154&18446744073709551615ull)));
  if (((llvm_cbe_tmp__154&18446744073709551615ULL) == (llvm_cbe_tmp__129&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__166;
  } else {
    llvm_cbe_storemerge35_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__154;   /* for PHI node */
    goto llvm_cbe_tmp__165;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  } while (1); /* end of syntactic loop '.preheader6' */
llvm_cbe__2e_preheader6_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = mul i64 %%storemerge14, %%stride, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_391_count);
  llvm_cbe_tmp__136 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_stride&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__136&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = mul i64 %%storemerge14, %%9, !dbg !11 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_392_count);
  llvm_cbe_tmp__137 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__129&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__137&18446744073709551615ull)));
  llvm_cbe_storemerge110__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  } while (1); /* end of syntactic loop '.preheader9' */
llvm_cbe__2e__crit_edge15:
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = bitcast %%struct.k2c_tensor* %%output to %%struct.k2c_tensor2*, !dbg !12 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_454_count);
  llvm_cbe_tmp__160 = (l_struct_OC_k2c_tensor2 *)((l_struct_OC_k2c_tensor2 *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = bitcast %%struct.k2c_tensor* %%bias to %%struct.k2c_tensor2*, !dbg !12 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_455_count);
  llvm_cbe_tmp__161 = (l_struct_OC_k2c_tensor2 *)((l_struct_OC_k2c_tensor2 *)llvm_cbe_bias);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @k2c_bias_add(%%struct.k2c_tensor2* %%48, %%struct.k2c_tensor2* %%49) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_456_count);
   /*tail*/ k2c_bias_add((l_struct_OC_k2c_tensor2 *)llvm_cbe_tmp__160, (l_struct_OC_k2c_tensor2 *)llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_457_count);
  llvm_cbe_tmp__162 = (float *)(&llvm_cbe_output->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i64* %%2, align 8, !dbg !12 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_458_count);
  llvm_cbe_tmp__163 = (unsigned long long )*llvm_cbe_tmp__122;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__163);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%activation(float* %%50, i64 %%51) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_conv1d  --> \n", ++aesl_llvm_cbe_459_count);
   /*tail*/ llvm_cbe_activation((float *)llvm_cbe_tmp__162, llvm_cbe_tmp__163);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__163);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_conv1d}\n");
  return;
}


void k2c_conv2d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, signed long long *llvm_cbe_stride, signed long long *llvm_cbe_dilation, void  (*llvm_cbe_activation) (float *, unsigned long long )) {
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
   char *llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  signed long long *llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  unsigned long long llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  unsigned long long llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
   char *llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  signed long long *llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  unsigned long long llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  signed long long *llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  unsigned long long llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  signed long long *llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  unsigned long long llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  signed long long *llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  unsigned long long llvm_cbe_tmp__179;
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
  signed long long *llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  signed long long *llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  signed long long *llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  signed long long *llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  signed long long *llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  signed long long *llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  signed long long *llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge30_count = 0;
  unsigned long long llvm_cbe_storemerge30;
  unsigned long long llvm_cbe_storemerge30__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge127_count = 0;
  unsigned long long llvm_cbe_storemerge127;
  unsigned long long llvm_cbe_storemerge127__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  unsigned long long llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge223_count = 0;
  unsigned long long llvm_cbe_storemerge223;
  unsigned long long llvm_cbe_storemerge223__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  unsigned long long llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge318_count = 0;
  unsigned long long llvm_cbe_storemerge318;
  unsigned long long llvm_cbe_storemerge318__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  unsigned long long llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond33_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge513_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge513_2e_us;
  unsigned long long llvm_cbe_storemerge513_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  unsigned long long llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  unsigned long long llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  unsigned long long llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  unsigned long long llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_tmp_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp6_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp6_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp7_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp7_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp8_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp8_2e_us;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  unsigned long long llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  float *llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  float llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  unsigned long long llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  unsigned long long llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  unsigned long long llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  unsigned long long llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  unsigned long long llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  unsigned long long llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  unsigned long long llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  unsigned long long llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  unsigned long long llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  unsigned long long llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  unsigned long long llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  unsigned long long llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  unsigned long long llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_tmp9_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp9_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp10_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp10_2e_us;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  unsigned long long llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  float *llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  float llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  float llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  unsigned long long llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  unsigned long long llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  unsigned long long llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_tmp11_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp11_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp12_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp12_2e_us;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  unsigned long long llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  float *llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  float llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  float llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  unsigned long long llvm_cbe_tmp__221;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge415_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge415_2e_us;
  unsigned long long llvm_cbe_storemerge415_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  unsigned long long llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  unsigned long long llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  unsigned long long llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  unsigned long long llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  unsigned long long llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond35_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  unsigned long long llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond36_count = 0;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  l_struct_OC_k2c_tensor2 *llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  l_struct_OC_k2c_tensor2 *llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  float *llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  unsigned long long llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_conv2d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast %%struct.k2c_tensor* %%output to i8*, !dbg !10 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_500_count);
  llvm_cbe_tmp__167 = ( char *)(( char *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !10 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_501_count);
  llvm_cbe_tmp__168 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i64* %%2, align 8, !dbg !10 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_502_count);
  llvm_cbe_tmp__169 = (unsigned long long )*llvm_cbe_tmp__168;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__169);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = shl i64 %%3, 2, !dbg !10 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_503_count);
  llvm_cbe_tmp__170 = (unsigned long long )llvm_cbe_tmp__169 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__170);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @memset(i8* %%1, i32 0, i64 %%4 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_504_count);
  ( char *)memset(( char *)llvm_cbe_tmp__167, 0u, llvm_cbe_tmp__170);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__170);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__171);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 0, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_505_count);
  llvm_cbe_tmp__172 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%6, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_506_count);
  llvm_cbe_tmp__173 = (unsigned long long )*llvm_cbe_tmp__172;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__173);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_509_count);
  llvm_cbe_tmp__174 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%8, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_510_count);
  llvm_cbe_tmp__175 = (unsigned long long )*llvm_cbe_tmp__174;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__175);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 2, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_513_count);
  llvm_cbe_tmp__176 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%10, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_514_count);
  llvm_cbe_tmp__177 = (unsigned long long )*llvm_cbe_tmp__176;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 2, !dbg !13 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_517_count);
  llvm_cbe_tmp__178 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i64* %%12, align 8, !dbg !13 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_518_count);
  llvm_cbe_tmp__179 = (unsigned long long )*llvm_cbe_tmp__178;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__179);
  if (((llvm_cbe_tmp__173&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge32;
  } else {
    goto llvm_cbe__2e_preheader26_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader26_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 0, !dbg !13 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_529_count);
  llvm_cbe_tmp__180 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 1, !dbg !13 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_530_count);
  llvm_cbe_tmp__181 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 3, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_533_count);
  llvm_cbe_tmp__182 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 2, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_534_count);
  llvm_cbe_tmp__183 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_535_count);
  llvm_cbe_tmp__184 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds i64* %%stride, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_536_count);
  llvm_cbe_tmp__185 = (signed long long *)(&llvm_cbe_stride[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds i64* %%dilation, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_537_count);
  llvm_cbe_tmp__186 = (signed long long *)(&llvm_cbe_dilation[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge30__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader26;

  do {     /* Syntactic loop '.preheader26' to make GCC happy */
llvm_cbe__2e_preheader26:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge30 = phi i64 [ 0, %%.preheader26.lr.ph ], [ %%72, %%._crit_edge29  for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_storemerge30_count);
  llvm_cbe_storemerge30 = (unsigned long long )llvm_cbe_storemerge30__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge30 = 0x%I64X",llvm_cbe_storemerge30);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__227);
}
  if (((llvm_cbe_tmp__175&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge29;
  } else {
    llvm_cbe_storemerge127__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader22;
  }

llvm_cbe__2e__crit_edge29:
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = add i64 %%storemerge30, 1, !dbg !15 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_641_count);
  llvm_cbe_tmp__227 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge30&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__227&18446744073709551615ull)));
  if (((llvm_cbe_tmp__227&18446744073709551615ULL) == (llvm_cbe_tmp__173&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge32;
  } else {
    llvm_cbe_storemerge30__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__227;   /* for PHI node */
    goto llvm_cbe__2e_preheader26;
  }

  do {     /* Syntactic loop '.preheader22' to make GCC happy */
llvm_cbe__2e_preheader22:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge127 = phi i64 [ %%71, %%._crit_edge25 ], [ 0, %%.preheader26  for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_storemerge127_count);
  llvm_cbe_storemerge127 = (unsigned long long )llvm_cbe_storemerge127__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge127 = 0x%I64X",llvm_cbe_storemerge127);
printf("\n = 0x%I64X",llvm_cbe_tmp__226);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i64* %%16, align 8, !dbg !13 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_548_count);
  llvm_cbe_tmp__187 = (unsigned long long )*llvm_cbe_tmp__180;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__187);
  if (((llvm_cbe_tmp__187&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge25;
  } else {
    llvm_cbe_storemerge223__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader17;
  }

llvm_cbe__2e__crit_edge25:
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = add i64 %%storemerge127, 1, !dbg !15 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_634_count);
  llvm_cbe_tmp__226 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge127&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__226&18446744073709551615ull)));
  if (((llvm_cbe_tmp__226&18446744073709551615ULL) == (llvm_cbe_tmp__175&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge29;
  } else {
    llvm_cbe_storemerge127__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__226;   /* for PHI node */
    goto llvm_cbe__2e_preheader22;
  }

  do {     /* Syntactic loop '.preheader17' to make GCC happy */
llvm_cbe__2e_preheader17:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge223 = phi i64 [ %%68, %%._crit_edge21 ], [ 0, %%.preheader22  for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_storemerge223_count);
  llvm_cbe_storemerge223 = (unsigned long long )llvm_cbe_storemerge223__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge223 = 0x%I64X",llvm_cbe_storemerge223);
printf("\n = 0x%I64X",llvm_cbe_tmp__224);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i64* %%17, align 8, !dbg !13 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_555_count);
  llvm_cbe_tmp__188 = (unsigned long long )*llvm_cbe_tmp__181;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__188);
  if (((llvm_cbe_tmp__188&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge21;
  } else {
    llvm_cbe_storemerge318__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader14;
  }

llvm_cbe__2e__crit_edge21:
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = add i64 %%storemerge223, 1, !dbg !15 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_625_count);
  llvm_cbe_tmp__224 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge223&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__224&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = load i64* %%16, align 8, !dbg !13 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_631_count);
  llvm_cbe_tmp__225 = (unsigned long long )*llvm_cbe_tmp__180;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__225);
  if ((((unsigned long long )llvm_cbe_tmp__224&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__225&18446744073709551615ULL))) {
    llvm_cbe_storemerge223__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__224;   /* for PHI node */
    goto llvm_cbe__2e_preheader17;
  } else {
    goto llvm_cbe__2e__crit_edge25;
  }

  do {     /* Syntactic loop '.preheader14' to make GCC happy */
llvm_cbe__2e_preheader14:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge318 = phi i64 [ %%65, %%64 ], [ 0, %%.preheader17  for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_storemerge318_count);
  llvm_cbe_storemerge318 = (unsigned long long )llvm_cbe_storemerge318__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge318 = 0x%I64X",llvm_cbe_storemerge318);
printf("\n = 0x%I64X",llvm_cbe_tmp__222);
printf("\n = 0x%I64X",0ull);
}
  if (((llvm_cbe_tmp__179&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__232;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe_tmp__232:
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = add i64 %%storemerge318, 1, !dbg !15 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_616_count);
  llvm_cbe_tmp__222 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge318&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__222&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = load i64* %%17, align 8, !dbg !13 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_622_count);
  llvm_cbe_tmp__223 = (unsigned long long )*llvm_cbe_tmp__181;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__223);
  if ((((unsigned long long )llvm_cbe_tmp__222&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__223&18446744073709551615ULL))) {
    llvm_cbe_storemerge318__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__222;   /* for PHI node */
    goto llvm_cbe__2e_preheader14;
  } else {
    goto llvm_cbe__2e__crit_edge21;
  }

llvm_cbe__2e__crit_edge16:
  goto llvm_cbe_tmp__232;

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if (((llvm_cbe_tmp__177&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge16;
  } else {
    llvm_cbe_storemerge415_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge415.us = phi i64 [ %%30, %%29 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_storemerge415_2e_us_count);
  llvm_cbe_storemerge415_2e_us = (unsigned long long )llvm_cbe_storemerge415_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge415.us = 0x%I64X",llvm_cbe_storemerge415_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__189);
printf("\n = 0x%I64X",0ull);
}
  llvm_cbe_storemerge513_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__233;

llvm_cbe_tmp__234:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add i64 %%storemerge415.us, 1, !dbg !16 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_564_count);
  llvm_cbe_tmp__189 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge415_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__189&18446744073709551615ull)));
  if (((llvm_cbe_tmp__189&18446744073709551615ULL) == (llvm_cbe_tmp__179&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge16;
  } else {
    llvm_cbe_storemerge415_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__189;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__233:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge513.us = phi i64 [ 0, %%.lr.ph.us ], [ %%63, %%31  for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_storemerge513_2e_us_count);
  llvm_cbe_storemerge513_2e_us = (unsigned long long )llvm_cbe_storemerge513_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge513.us = 0x%I64X",llvm_cbe_storemerge513_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__221);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i64* %%20, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_571_count);
  llvm_cbe_tmp__190 = (unsigned long long )*llvm_cbe_tmp__182;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__190);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i64* %%21, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_572_count);
  llvm_cbe_tmp__191 = (unsigned long long )*llvm_cbe_tmp__183;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__191);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i64* %%17, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_573_count);
  llvm_cbe_tmp__192 = (unsigned long long )*llvm_cbe_tmp__181;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__192);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = mul i64 %%34, %%storemerge223, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_574_count);
  llvm_cbe_tmp__193 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__192&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge223&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__193&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp.us = add i64 %%35, %%storemerge31 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_tmp_2e_us_count);
  llvm_cbe_tmp_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__193&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge318&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp6.us = mul i64 %%33, %%tmp.u for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_tmp6_2e_us_count);
  llvm_cbe_tmp6_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__191&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp6.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp6_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp7.us = add i64 %%tmp6.us, %%storemerge415.u for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_tmp7_2e_us_count);
  llvm_cbe_tmp7_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp6_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge415_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp7.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp7_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp8.us = mul i64 %%tmp7.us, %%3 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_tmp8_2e_us_count);
  llvm_cbe_tmp8_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp7_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__190&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp8.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp8_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = add i64 %%tmp8.us, %%storemerge513.us, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_575_count);
  llvm_cbe_tmp__194 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp8_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge513_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__194&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 0, i64 %%36, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_576_count);
  llvm_cbe_tmp__195 = (float *)(&llvm_cbe_kernel->field0[(((signed long long )llvm_cbe_tmp__194))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__194));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load float* %%37, align 4, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_577_count);
  llvm_cbe_tmp__196 = (float )*llvm_cbe_tmp__195;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__196, *(int*)(&llvm_cbe_tmp__196));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i64* %%stride, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_578_count);
  llvm_cbe_tmp__197 = (unsigned long long )*llvm_cbe_stride;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__197);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = mul i64 %%39, %%storemerge30, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_579_count);
  llvm_cbe_tmp__198 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__197&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge30&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__198&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load i64* %%dilation, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_580_count);
  llvm_cbe_tmp__199 = (unsigned long long )*llvm_cbe_dilation;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__199);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = mul i64 %%41, %%storemerge223, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_581_count);
  llvm_cbe_tmp__200 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__199&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge223&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__200&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add i64 %%42, %%40, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_582_count);
  llvm_cbe_tmp__201 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__200&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__198&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__201&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load i64* %%12, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_583_count);
  llvm_cbe_tmp__202 = (unsigned long long )*llvm_cbe_tmp__178;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__202);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i64* %%22, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_584_count);
  llvm_cbe_tmp__203 = (unsigned long long )*llvm_cbe_tmp__184;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__203);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = mul i64 %%43, %%45, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_585_count);
  llvm_cbe_tmp__204 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__201&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__203&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__204&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i64* %%23, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_586_count);
  llvm_cbe_tmp__205 = (unsigned long long )*llvm_cbe_tmp__185;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__205);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = mul i64 %%47, %%storemerge127, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_587_count);
  llvm_cbe_tmp__206 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__205&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge127&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__206&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load i64* %%24, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_588_count);
  llvm_cbe_tmp__207 = (unsigned long long )*llvm_cbe_tmp__186;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__207);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = mul i64 %%49, %%storemerge318, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_589_count);
  llvm_cbe_tmp__208 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__207&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge318&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = add i64 %%48, %%46, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_590_count);
  llvm_cbe_tmp__209 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__206&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__204&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__209&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp9.us = add i64 %%51, %%5 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_tmp9_2e_us_count);
  llvm_cbe_tmp9_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__209&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__208&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp9.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp9_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp10.us = mul i64 %%tmp9.us, %%4 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_tmp10_2e_us_count);
  llvm_cbe_tmp10_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp9_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__202&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp10.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp10_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = add i64 %%tmp10.us, %%storemerge415.us, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_591_count);
  llvm_cbe_tmp__210 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp10_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge415_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__210&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%52, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_592_count);
  llvm_cbe_tmp__211 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__210))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__210));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load float* %%53, align 4, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_593_count);
  llvm_cbe_tmp__212 = (float )*llvm_cbe_tmp__211;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__212, *(int*)(&llvm_cbe_tmp__212));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = fmul float %%38, %%54, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_594_count);
  llvm_cbe_tmp__213 = (float )((float )(llvm_cbe_tmp__196 * llvm_cbe_tmp__212));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__213, *(int*)(&llvm_cbe_tmp__213));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = load i64* %%10, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_595_count);
  llvm_cbe_tmp__214 = (unsigned long long )*llvm_cbe_tmp__176;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__214);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = load i64* %%8, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_596_count);
  llvm_cbe_tmp__215 = (unsigned long long )*llvm_cbe_tmp__174;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__215);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = mul i64 %%storemerge30, %%57, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_597_count);
  llvm_cbe_tmp__216 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge30&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__215&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__216&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp11.us = add i64 %%58, %%storemerge12 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_tmp11_2e_us_count);
  llvm_cbe_tmp11_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__216&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge127&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp11.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp11_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp12.us = mul i64 %%tmp11.us, %%5 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_tmp12_2e_us_count);
  llvm_cbe_tmp12_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp11_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__214&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp12.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp12_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add i64 %%tmp12.us, %%storemerge513.us, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_598_count);
  llvm_cbe_tmp__217 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp12_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge513_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__217&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%59, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_599_count);
  llvm_cbe_tmp__218 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__217))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__217));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = load float* %%60, align 4, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_600_count);
  llvm_cbe_tmp__219 = (float )*llvm_cbe_tmp__218;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__219, *(int*)(&llvm_cbe_tmp__219));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = fadd float %%61, %%55, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_601_count);
  llvm_cbe_tmp__220 = (float )((float )(llvm_cbe_tmp__219 + llvm_cbe_tmp__213));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__220, *(int*)(&llvm_cbe_tmp__220));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%62, float* %%60, align 4, !dbg !11 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_602_count);
  *llvm_cbe_tmp__218 = llvm_cbe_tmp__220;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__220);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = add i64 %%storemerge513.us, 1, !dbg !16 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_603_count);
  llvm_cbe_tmp__221 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge513_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__221&18446744073709551615ull)));
  if (((llvm_cbe_tmp__221&18446744073709551615ULL) == (llvm_cbe_tmp__177&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__234;
  } else {
    llvm_cbe_storemerge513_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__221;   /* for PHI node */
    goto llvm_cbe_tmp__233;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  } while (1); /* end of syntactic loop '.preheader14' */
  } while (1); /* end of syntactic loop '.preheader17' */
  } while (1); /* end of syntactic loop '.preheader22' */
  } while (1); /* end of syntactic loop '.preheader26' */
llvm_cbe__2e__crit_edge32:
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = bitcast %%struct.k2c_tensor* %%output to %%struct.k2c_tensor2*, !dbg !12 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_648_count);
  llvm_cbe_tmp__228 = (l_struct_OC_k2c_tensor2 *)((l_struct_OC_k2c_tensor2 *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = bitcast %%struct.k2c_tensor* %%bias to %%struct.k2c_tensor2*, !dbg !12 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_649_count);
  llvm_cbe_tmp__229 = (l_struct_OC_k2c_tensor2 *)((l_struct_OC_k2c_tensor2 *)llvm_cbe_bias);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @k2c_bias_add(%%struct.k2c_tensor2* %%73, %%struct.k2c_tensor2* %%74) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_650_count);
   /*tail*/ k2c_bias_add((l_struct_OC_k2c_tensor2 *)llvm_cbe_tmp__228, (l_struct_OC_k2c_tensor2 *)llvm_cbe_tmp__229);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_651_count);
  llvm_cbe_tmp__230 = (float *)(&llvm_cbe_output->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = load i64* %%2, align 8, !dbg !12 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_652_count);
  llvm_cbe_tmp__231 = (unsigned long long )*llvm_cbe_tmp__168;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__231);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%activation(float* %%75, i64 %%76) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_conv2d  --> \n", ++aesl_llvm_cbe_653_count);
   /*tail*/ llvm_cbe_activation((float *)llvm_cbe_tmp__230, llvm_cbe_tmp__231);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__231);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_conv2d}\n");
  return;
}


void k2c_conv3d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, signed long long *llvm_cbe_stride, signed long long *llvm_cbe_dilation, void  (*llvm_cbe_activation) (float *, unsigned long long )) {
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
   char *llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  signed long long *llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  unsigned long long llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  unsigned long long llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
   char *llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  signed long long *llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  unsigned long long llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  signed long long *llvm_cbe_tmp__242;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  unsigned long long llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  signed long long *llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  unsigned long long llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  signed long long *llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  unsigned long long llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  signed long long *llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  unsigned long long llvm_cbe_tmp__249;
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
  signed long long *llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  signed long long *llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  signed long long *llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  signed long long *llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  signed long long *llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  signed long long *llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  signed long long *llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  signed long long *llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  signed long long *llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  signed long long *llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  signed long long *llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge46_count = 0;
  unsigned long long llvm_cbe_storemerge46;
  unsigned long long llvm_cbe_storemerge46__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge143_count = 0;
  unsigned long long llvm_cbe_storemerge143;
  unsigned long long llvm_cbe_storemerge143__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge239_count = 0;
  unsigned long long llvm_cbe_storemerge239;
  unsigned long long llvm_cbe_storemerge239__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  unsigned long long llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge335_count = 0;
  unsigned long long llvm_cbe_storemerge335;
  unsigned long long llvm_cbe_storemerge335__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  unsigned long long llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge431_count = 0;
  unsigned long long llvm_cbe_storemerge431;
  unsigned long long llvm_cbe_storemerge431__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  unsigned long long llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge526_count = 0;
  unsigned long long llvm_cbe_storemerge526;
  unsigned long long llvm_cbe_storemerge526__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  unsigned long long llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond49_count = 0;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge721_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge721_2e_us;
  unsigned long long llvm_cbe_storemerge721_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  unsigned long long llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  unsigned long long llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  unsigned long long llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  unsigned long long llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  unsigned long long llvm_cbe_tmp__269;
  static  unsigned long long aesl_llvm_cbe_tmp_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp8_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp8_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp9_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp9_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp10_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp10_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp11_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp11_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp12_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp12_2e_us;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  unsigned long long llvm_cbe_tmp__270;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  float *llvm_cbe_tmp__271;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  float llvm_cbe_tmp__272;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  unsigned long long llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  unsigned long long llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  unsigned long long llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  unsigned long long llvm_cbe_tmp__276;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  unsigned long long llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  unsigned long long llvm_cbe_tmp__278;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  unsigned long long llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  unsigned long long llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  unsigned long long llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  unsigned long long llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  unsigned long long llvm_cbe_tmp__283;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  unsigned long long llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  unsigned long long llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  unsigned long long llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  unsigned long long llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  unsigned long long llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  unsigned long long llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  unsigned long long llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_tmp13_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp13_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp14_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp14_2e_us;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  unsigned long long llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_tmp15_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp15_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp16_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp16_2e_us;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  unsigned long long llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  float *llvm_cbe_tmp__293;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  float llvm_cbe_tmp__294;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  float llvm_cbe_tmp__295;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  unsigned long long llvm_cbe_tmp__296;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  unsigned long long llvm_cbe_tmp__297;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  unsigned long long llvm_cbe_tmp__298;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  unsigned long long llvm_cbe_tmp__299;
  static  unsigned long long aesl_llvm_cbe_tmp17_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp17_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp18_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp18_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp19_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp19_2e_us;
  static  unsigned long long aesl_llvm_cbe_tmp20_2e_us_count = 0;
  unsigned long long llvm_cbe_tmp20_2e_us;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  unsigned long long llvm_cbe_tmp__300;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  float *llvm_cbe_tmp__301;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  float llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  float llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  unsigned long long llvm_cbe_tmp__304;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge623_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge623_2e_us;
  unsigned long long llvm_cbe_storemerge623_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  unsigned long long llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  unsigned long long llvm_cbe_tmp__306;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  unsigned long long llvm_cbe_tmp__307;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  unsigned long long llvm_cbe_tmp__308;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  unsigned long long llvm_cbe_tmp__309;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  unsigned long long llvm_cbe_tmp__310;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  unsigned long long llvm_cbe_tmp__311;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond51_count = 0;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  unsigned long long llvm_cbe_tmp__312;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond52_count = 0;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  unsigned long long llvm_cbe_tmp__313;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond53_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  l_struct_OC_k2c_tensor2 *llvm_cbe_tmp__314;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  l_struct_OC_k2c_tensor2 *llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  float *llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  unsigned long long llvm_cbe_tmp__317;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_conv3d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast %%struct.k2c_tensor* %%output to i8*, !dbg !10 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_708_count);
  llvm_cbe_tmp__235 = ( char *)(( char *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !10 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_709_count);
  llvm_cbe_tmp__236 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i64* %%2, align 8, !dbg !10 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_710_count);
  llvm_cbe_tmp__237 = (unsigned long long )*llvm_cbe_tmp__236;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = shl i64 %%3, 2, !dbg !10 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_711_count);
  llvm_cbe_tmp__238 = (unsigned long long )llvm_cbe_tmp__237 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__238);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @memset(i8* %%1, i32 0, i64 %%4 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_712_count);
  ( char *)memset(( char *)llvm_cbe_tmp__235, 0u, llvm_cbe_tmp__238);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__238);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__239);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 0, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_713_count);
  llvm_cbe_tmp__240 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%6, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_714_count);
  llvm_cbe_tmp__241 = (unsigned long long )*llvm_cbe_tmp__240;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__241);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_717_count);
  llvm_cbe_tmp__242 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%8, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_718_count);
  llvm_cbe_tmp__243 = (unsigned long long )*llvm_cbe_tmp__242;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__243);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 2, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_721_count);
  llvm_cbe_tmp__244 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%10, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_722_count);
  llvm_cbe_tmp__245 = (unsigned long long )*llvm_cbe_tmp__244;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__245);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 3, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_725_count);
  llvm_cbe_tmp__246 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i64* %%12, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_726_count);
  llvm_cbe_tmp__247 = (unsigned long long )*llvm_cbe_tmp__246;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__247);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 3, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_729_count);
  llvm_cbe_tmp__248 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i64* %%14, align 8, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_730_count);
  llvm_cbe_tmp__249 = (unsigned long long )*llvm_cbe_tmp__248;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__249);
  if (((llvm_cbe_tmp__241&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge48;
  } else {
    goto llvm_cbe__2e_preheader42_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader42_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 0, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_742_count);
  llvm_cbe_tmp__250 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 1, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_743_count);
  llvm_cbe_tmp__251 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 2, !dbg !14 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_744_count);
  llvm_cbe_tmp__252 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 4, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_747_count);
  llvm_cbe_tmp__253 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 3, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_748_count);
  llvm_cbe_tmp__254 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 2, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_749_count);
  llvm_cbe_tmp__255 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_750_count);
  llvm_cbe_tmp__256 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds i64* %%stride, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_751_count);
  llvm_cbe_tmp__257 = (signed long long *)(&llvm_cbe_stride[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds i64* %%dilation, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_752_count);
  llvm_cbe_tmp__258 = (signed long long *)(&llvm_cbe_dilation[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds i64* %%stride, i64 2, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_753_count);
  llvm_cbe_tmp__259 = (signed long long *)(&llvm_cbe_stride[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i64* %%dilation, i64 2, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_754_count);
  llvm_cbe_tmp__260 = (signed long long *)(&llvm_cbe_dilation[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge46__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader42;

  do {     /* Syntactic loop '.preheader42' to make GCC happy */
llvm_cbe__2e_preheader42:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge46 = phi i64 [ 0, %%.preheader42.lr.ph ], [ %%93, %%._crit_edge45  for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_storemerge46_count);
  llvm_cbe_storemerge46 = (unsigned long long )llvm_cbe_storemerge46__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge46 = 0x%I64X",llvm_cbe_storemerge46);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__313);
}
  if (((llvm_cbe_tmp__243&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge45;
  } else {
    llvm_cbe_storemerge143__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader38;
  }

llvm_cbe__2e__crit_edge45:
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = add i64 %%storemerge46, 1, !dbg !16 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_894_count);
  llvm_cbe_tmp__313 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge46&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__313&18446744073709551615ull)));
  if (((llvm_cbe_tmp__313&18446744073709551615ULL) == (llvm_cbe_tmp__241&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge48;
  } else {
    llvm_cbe_storemerge46__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__313;   /* for PHI node */
    goto llvm_cbe__2e_preheader42;
  }

  do {     /* Syntactic loop '.preheader38' to make GCC happy */
llvm_cbe__2e_preheader38:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge143 = phi i64 [ %%92, %%._crit_edge41 ], [ 0, %%.preheader42  for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_storemerge143_count);
  llvm_cbe_storemerge143 = (unsigned long long )llvm_cbe_storemerge143__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge143 = 0x%I64X",llvm_cbe_storemerge143);
printf("\n = 0x%I64X",llvm_cbe_tmp__312);
printf("\n = 0x%I64X",0ull);
}
  if (((llvm_cbe_tmp__245&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge41;
  } else {
    llvm_cbe_storemerge239__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader34;
  }

llvm_cbe__2e__crit_edge41:
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = add i64 %%storemerge143, 1, !dbg !16 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_887_count);
  llvm_cbe_tmp__312 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge143&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__312&18446744073709551615ull)));
  if (((llvm_cbe_tmp__312&18446744073709551615ULL) == (llvm_cbe_tmp__243&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge45;
  } else {
    llvm_cbe_storemerge143__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__312;   /* for PHI node */
    goto llvm_cbe__2e_preheader38;
  }

  do {     /* Syntactic loop '.preheader34' to make GCC happy */
llvm_cbe__2e_preheader34:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge239 = phi i64 [ %%91, %%._crit_edge37 ], [ 0, %%.preheader38  for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_storemerge239_count);
  llvm_cbe_storemerge239 = (unsigned long long )llvm_cbe_storemerge239__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge239 = 0x%I64X",llvm_cbe_storemerge239);
printf("\n = 0x%I64X",llvm_cbe_tmp__311);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i64* %%19, align 8, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_770_count);
  llvm_cbe_tmp__261 = (unsigned long long )*llvm_cbe_tmp__250;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__261);
  if (((llvm_cbe_tmp__261&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge37;
  } else {
    llvm_cbe_storemerge335__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader30;
  }

llvm_cbe__2e__crit_edge37:
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = add i64 %%storemerge239, 1, !dbg !16 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_880_count);
  llvm_cbe_tmp__311 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge239&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__311&18446744073709551615ull)));
  if (((llvm_cbe_tmp__311&18446744073709551615ULL) == (llvm_cbe_tmp__245&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge41;
  } else {
    llvm_cbe_storemerge239__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__311;   /* for PHI node */
    goto llvm_cbe__2e_preheader34;
  }

  do {     /* Syntactic loop '.preheader30' to make GCC happy */
llvm_cbe__2e_preheader30:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge335 = phi i64 [ %%88, %%._crit_edge33 ], [ 0, %%.preheader34  for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_storemerge335_count);
  llvm_cbe_storemerge335 = (unsigned long long )llvm_cbe_storemerge335__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge335 = 0x%I64X",llvm_cbe_storemerge335);
printf("\n = 0x%I64X",llvm_cbe_tmp__309);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i64* %%20, align 8, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_777_count);
  llvm_cbe_tmp__262 = (unsigned long long )*llvm_cbe_tmp__251;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__262);
  if (((llvm_cbe_tmp__262&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge33;
  } else {
    llvm_cbe_storemerge431__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader25;
  }

llvm_cbe__2e__crit_edge33:
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = add i64 %%storemerge335, 1, !dbg !16 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_871_count);
  llvm_cbe_tmp__309 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge335&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__309&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = load i64* %%19, align 8, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_877_count);
  llvm_cbe_tmp__310 = (unsigned long long )*llvm_cbe_tmp__250;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__310);
  if ((((unsigned long long )llvm_cbe_tmp__309&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__310&18446744073709551615ULL))) {
    llvm_cbe_storemerge335__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__309;   /* for PHI node */
    goto llvm_cbe__2e_preheader30;
  } else {
    goto llvm_cbe__2e__crit_edge37;
  }

  do {     /* Syntactic loop '.preheader25' to make GCC happy */
llvm_cbe__2e_preheader25:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge431 = phi i64 [ %%85, %%._crit_edge29 ], [ 0, %%.preheader30  for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_storemerge431_count);
  llvm_cbe_storemerge431 = (unsigned long long )llvm_cbe_storemerge431__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge431 = 0x%I64X",llvm_cbe_storemerge431);
printf("\n = 0x%I64X",llvm_cbe_tmp__307);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i64* %%21, align 8, !dbg !14 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_784_count);
  llvm_cbe_tmp__263 = (unsigned long long )*llvm_cbe_tmp__252;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__263);
  if (((llvm_cbe_tmp__263&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge29;
  } else {
    llvm_cbe_storemerge526__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader22;
  }

llvm_cbe__2e__crit_edge29:
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = add i64 %%storemerge431, 1, !dbg !16 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_862_count);
  llvm_cbe_tmp__307 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge431&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__307&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = load i64* %%20, align 8, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_868_count);
  llvm_cbe_tmp__308 = (unsigned long long )*llvm_cbe_tmp__251;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__308);
  if ((((unsigned long long )llvm_cbe_tmp__307&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__308&18446744073709551615ULL))) {
    llvm_cbe_storemerge431__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__307;   /* for PHI node */
    goto llvm_cbe__2e_preheader25;
  } else {
    goto llvm_cbe__2e__crit_edge33;
  }

  do {     /* Syntactic loop '.preheader22' to make GCC happy */
llvm_cbe__2e_preheader22:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge526 = phi i64 [ %%82, %%81 ], [ 0, %%.preheader25  for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_storemerge526_count);
  llvm_cbe_storemerge526 = (unsigned long long )llvm_cbe_storemerge526__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge526 = 0x%I64X",llvm_cbe_storemerge526);
printf("\n = 0x%I64X",llvm_cbe_tmp__305);
printf("\n = 0x%I64X",0ull);
}
  if (((llvm_cbe_tmp__249&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__318;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe_tmp__318:
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = add i64 %%storemerge526, 1, !dbg !17 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_853_count);
  llvm_cbe_tmp__305 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge526&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__305&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = load i64* %%21, align 8, !dbg !14 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_859_count);
  llvm_cbe_tmp__306 = (unsigned long long )*llvm_cbe_tmp__252;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__306);
  if ((((unsigned long long )llvm_cbe_tmp__305&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__306&18446744073709551615ULL))) {
    llvm_cbe_storemerge526__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__305;   /* for PHI node */
    goto llvm_cbe__2e_preheader22;
  } else {
    goto llvm_cbe__2e__crit_edge29;
  }

llvm_cbe__2e__crit_edge24:
  goto llvm_cbe_tmp__318;

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if (((llvm_cbe_tmp__247&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge24;
  } else {
    llvm_cbe_storemerge623_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge623.us = phi i64 [ %%39, %%38 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_storemerge623_2e_us_count);
  llvm_cbe_storemerge623_2e_us = (unsigned long long )llvm_cbe_storemerge623_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge623.us = 0x%I64X",llvm_cbe_storemerge623_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__264);
printf("\n = 0x%I64X",0ull);
}
  llvm_cbe_storemerge721_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__319;

llvm_cbe_tmp__320:
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i64 %%storemerge623.us, 1, !dbg !17 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_793_count);
  llvm_cbe_tmp__264 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge623_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__264&18446744073709551615ull)));
  if (((llvm_cbe_tmp__264&18446744073709551615ULL) == (llvm_cbe_tmp__249&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge24;
  } else {
    llvm_cbe_storemerge623_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__264;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__319:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge721.us = phi i64 [ 0, %%.lr.ph.us ], [ %%80, %%40  for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_storemerge721_2e_us_count);
  llvm_cbe_storemerge721_2e_us = (unsigned long long )llvm_cbe_storemerge721_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge721.us = 0x%I64X",llvm_cbe_storemerge721_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__304);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load i64* %%24, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_800_count);
  llvm_cbe_tmp__265 = (unsigned long long )*llvm_cbe_tmp__253;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__265);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i64* %%25, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_801_count);
  llvm_cbe_tmp__266 = (unsigned long long )*llvm_cbe_tmp__254;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__266);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i64* %%21, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_802_count);
  llvm_cbe_tmp__267 = (unsigned long long )*llvm_cbe_tmp__252;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__267);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load i64* %%20, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_803_count);
  llvm_cbe_tmp__268 = (unsigned long long )*llvm_cbe_tmp__251;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__268);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = mul i64 %%44, %%storemerge335, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_804_count);
  llvm_cbe_tmp__269 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__268&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge335&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__269&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp.us = add i64 %%45, %%storemerge43 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp_2e_us_count);
  llvm_cbe_tmp_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__269&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge431&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp8.us = mul i64 %%43, %%tmp.u for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp8_2e_us_count);
  llvm_cbe_tmp8_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__267&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp8.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp8_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp9.us = add i64 %%tmp8.us, %%storemerge52 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp9_2e_us_count);
  llvm_cbe_tmp9_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp8_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge526&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp9.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp9_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp10.us = mul i64 %%42, %%tmp9.u for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp10_2e_us_count);
  llvm_cbe_tmp10_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__266&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp9_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp10.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp10_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp11.us = add i64 %%tmp10.us, %%storemerge623.u for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp11_2e_us_count);
  llvm_cbe_tmp11_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp10_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge623_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp11.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp11_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp12.us = mul i64 %%tmp11.us, %%4 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp12_2e_us_count);
  llvm_cbe_tmp12_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp11_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__265&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp12.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp12_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add i64 %%tmp12.us, %%storemerge721.us, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_805_count);
  llvm_cbe_tmp__270 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp12_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge721_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__270&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 0, i64 %%46, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_806_count);
  llvm_cbe_tmp__271 = (float *)(&llvm_cbe_kernel->field0[(((signed long long )llvm_cbe_tmp__270))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__270));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load float* %%47, align 4, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_807_count);
  llvm_cbe_tmp__272 = (float )*llvm_cbe_tmp__271;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__272, *(int*)(&llvm_cbe_tmp__272));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load i64* %%stride, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_808_count);
  llvm_cbe_tmp__273 = (unsigned long long )*llvm_cbe_stride;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__273);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = mul i64 %%49, %%storemerge46, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_809_count);
  llvm_cbe_tmp__274 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__273&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge46&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__274&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i64* %%dilation, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_810_count);
  llvm_cbe_tmp__275 = (unsigned long long )*llvm_cbe_dilation;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__275);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = mul i64 %%51, %%storemerge335, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_811_count);
  llvm_cbe_tmp__276 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__275&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge335&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__276&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = add i64 %%52, %%50, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_812_count);
  llvm_cbe_tmp__277 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__276&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__274&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__277&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i64* %%14, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_813_count);
  llvm_cbe_tmp__278 = (unsigned long long )*llvm_cbe_tmp__248;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__278);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = load i64* %%26, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_814_count);
  llvm_cbe_tmp__279 = (unsigned long long )*llvm_cbe_tmp__255;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__279);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = load i64* %%27, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_815_count);
  llvm_cbe_tmp__280 = (unsigned long long )*llvm_cbe_tmp__256;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__280);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = mul i64 %%56, %%53, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_816_count);
  llvm_cbe_tmp__281 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__280&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__277&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__281&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = load i64* %%28, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_817_count);
  llvm_cbe_tmp__282 = (unsigned long long )*llvm_cbe_tmp__257;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__282);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = mul i64 %%58, %%storemerge143, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_818_count);
  llvm_cbe_tmp__283 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__282&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge143&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__283&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load i64* %%29, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_819_count);
  llvm_cbe_tmp__284 = (unsigned long long )*llvm_cbe_tmp__258;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__284);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = mul i64 %%60, %%storemerge431, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_820_count);
  llvm_cbe_tmp__285 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__284&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge431&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__285&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = load i64* %%30, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_821_count);
  llvm_cbe_tmp__286 = (unsigned long long )*llvm_cbe_tmp__259;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__286);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = mul i64 %%62, %%storemerge239, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_822_count);
  llvm_cbe_tmp__287 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__286&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge239&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__287&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load i64* %%31, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_823_count);
  llvm_cbe_tmp__288 = (unsigned long long )*llvm_cbe_tmp__260;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__288);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = mul i64 %%64, %%storemerge526, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_824_count);
  llvm_cbe_tmp__289 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__288&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge526&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__289&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = add i64 %%59, %%57, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_825_count);
  llvm_cbe_tmp__290 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__283&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__281&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__290&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp13.us = add i64 %%66, %%6 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp13_2e_us_count);
  llvm_cbe_tmp13_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__290&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__285&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp13.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp13_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp14.us = mul i64 %%55, %%tmp13.u for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp14_2e_us_count);
  llvm_cbe_tmp14_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__279&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp13_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp14.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp14_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = add i64 %%65, %%63, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_826_count);
  llvm_cbe_tmp__291 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__289&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__287&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__291&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp15.us = add i64 %%67, %%tmp14.u for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp15_2e_us_count);
  llvm_cbe_tmp15_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__291&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp14_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp15.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp15_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp16.us = mul i64 %%tmp15.us, %%5 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp16_2e_us_count);
  llvm_cbe_tmp16_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp15_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__278&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp16.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp16_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = add i64 %%tmp16.us, %%storemerge623.us, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_827_count);
  llvm_cbe_tmp__292 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp16_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge623_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__292&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%68, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_828_count);
  llvm_cbe_tmp__293 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__292))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__292));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load float* %%69, align 4, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_829_count);
  llvm_cbe_tmp__294 = (float )*llvm_cbe_tmp__293;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__294, *(int*)(&llvm_cbe_tmp__294));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = fmul float %%48, %%70, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_830_count);
  llvm_cbe_tmp__295 = (float )((float )(llvm_cbe_tmp__272 * llvm_cbe_tmp__294));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__295, *(int*)(&llvm_cbe_tmp__295));
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = load i64* %%12, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_831_count);
  llvm_cbe_tmp__296 = (unsigned long long )*llvm_cbe_tmp__246;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__296);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = load i64* %%10, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_832_count);
  llvm_cbe_tmp__297 = (unsigned long long )*llvm_cbe_tmp__244;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__297);
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = load i64* %%8, align 8, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_833_count);
  llvm_cbe_tmp__298 = (unsigned long long )*llvm_cbe_tmp__242;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__298);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = mul i64 %%74, %%storemerge46, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_834_count);
  llvm_cbe_tmp__299 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__298&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge46&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__299&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp17.us = add i64 %%75, %%storemerge14 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp17_2e_us_count);
  llvm_cbe_tmp17_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__299&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge143&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp17.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp17_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp18.us = mul i64 %%73, %%tmp17.u for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp18_2e_us_count);
  llvm_cbe_tmp18_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__297&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp17_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp18.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp18_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp19.us = add i64 %%tmp18.us, %%storemerge23 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp19_2e_us_count);
  llvm_cbe_tmp19_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp18_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge239&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp19.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp19_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp20.us = mul i64 %%tmp19.us, %%7 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_tmp20_2e_us_count);
  llvm_cbe_tmp20_2e_us = (unsigned long long )((unsigned long long )(llvm_cbe_tmp19_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__296&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp20.us = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp20_2e_us&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = add i64 %%tmp20.us, %%storemerge721.us, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_835_count);
  llvm_cbe_tmp__300 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp20_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge721_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__300&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%76, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_836_count);
  llvm_cbe_tmp__301 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__300))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__300));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = load float* %%77, align 4, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_837_count);
  llvm_cbe_tmp__302 = (float )*llvm_cbe_tmp__301;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__302, *(int*)(&llvm_cbe_tmp__302));
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = fadd float %%78, %%71, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_838_count);
  llvm_cbe_tmp__303 = (float )((float )(llvm_cbe_tmp__302 + llvm_cbe_tmp__295));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__303, *(int*)(&llvm_cbe_tmp__303));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%79, float* %%77, align 4, !dbg !11 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_839_count);
  *llvm_cbe_tmp__301 = llvm_cbe_tmp__303;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__303);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = add i64 %%storemerge721.us, 1, !dbg !17 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_840_count);
  llvm_cbe_tmp__304 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge721_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__304&18446744073709551615ull)));
  if (((llvm_cbe_tmp__304&18446744073709551615ULL) == (llvm_cbe_tmp__247&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__320;
  } else {
    llvm_cbe_storemerge721_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__304;   /* for PHI node */
    goto llvm_cbe_tmp__319;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  } while (1); /* end of syntactic loop '.preheader22' */
  } while (1); /* end of syntactic loop '.preheader25' */
  } while (1); /* end of syntactic loop '.preheader30' */
  } while (1); /* end of syntactic loop '.preheader34' */
  } while (1); /* end of syntactic loop '.preheader38' */
  } while (1); /* end of syntactic loop '.preheader42' */
llvm_cbe__2e__crit_edge48:
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = bitcast %%struct.k2c_tensor* %%output to %%struct.k2c_tensor2*, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_901_count);
  llvm_cbe_tmp__314 = (l_struct_OC_k2c_tensor2 *)((l_struct_OC_k2c_tensor2 *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = bitcast %%struct.k2c_tensor* %%bias to %%struct.k2c_tensor2*, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_902_count);
  llvm_cbe_tmp__315 = (l_struct_OC_k2c_tensor2 *)((l_struct_OC_k2c_tensor2 *)llvm_cbe_bias);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @k2c_bias_add(%%struct.k2c_tensor2* %%94, %%struct.k2c_tensor2* %%95) nounwind, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_903_count);
   /*tail*/ k2c_bias_add((l_struct_OC_k2c_tensor2 *)llvm_cbe_tmp__314, (l_struct_OC_k2c_tensor2 *)llvm_cbe_tmp__315);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 0, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_904_count);
  llvm_cbe_tmp__316 = (float *)(&llvm_cbe_output->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = load i64* %%2, align 8, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_905_count);
  llvm_cbe_tmp__317 = (unsigned long long )*llvm_cbe_tmp__236;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__317);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%activation(float* %%96, i64 %%97) nounwind, !dbg !13 for 0x%I64xth hint within @k2c_conv3d  --> \n", ++aesl_llvm_cbe_906_count);
   /*tail*/ llvm_cbe_activation((float *)llvm_cbe_tmp__316, llvm_cbe_tmp__317);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__317);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_conv3d}\n");
  return;
}


void k2c_crop1d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_crop) {
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  unsigned long long llvm_cbe_tmp__321;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  signed long long *llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  unsigned long long llvm_cbe_tmp__323;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  unsigned long long llvm_cbe_tmp__324;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
   char *llvm_cbe_tmp__325;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  float *llvm_cbe_tmp__326;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
   char *llvm_cbe_tmp__327;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  signed long long *llvm_cbe_tmp__328;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
  unsigned long long llvm_cbe_tmp__329;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  unsigned long long llvm_cbe_tmp__330;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
   char *llvm_cbe_tmp__331;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_crop1d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i64* %%crop, align 8, !dbg !11 for 0x%I64xth hint within @k2c_crop1d  --> \n", ++aesl_llvm_cbe_912_count);
  llvm_cbe_tmp__321 = (unsigned long long )*llvm_cbe_crop;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__321);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_crop1d  --> \n", ++aesl_llvm_cbe_914_count);
  llvm_cbe_tmp__322 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i64* %%2, align 8, !dbg !11 for 0x%I64xth hint within @k2c_crop1d  --> \n", ++aesl_llvm_cbe_915_count);
  llvm_cbe_tmp__323 = (unsigned long long )*llvm_cbe_tmp__322;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__323);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = mul i64 %%3, %%1, !dbg !11 for 0x%I64xth hint within @k2c_crop1d  --> \n", ++aesl_llvm_cbe_916_count);
  llvm_cbe_tmp__324 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__323&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__321&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__324&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = bitcast %%struct.k2c_tensor* %%output to i8*, !dbg !11 for 0x%I64xth hint within @k2c_crop1d  --> \n", ++aesl_llvm_cbe_919_count);
  llvm_cbe_tmp__325 = ( char *)(( char *)llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%4, !dbg !11 for 0x%I64xth hint within @k2c_crop1d  --> \n", ++aesl_llvm_cbe_922_count);
  llvm_cbe_tmp__326 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__324))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__324));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = bitcast float* %%6 to i8*, !dbg !11 for 0x%I64xth hint within @k2c_crop1d  --> \n", ++aesl_llvm_cbe_923_count);
  llvm_cbe_tmp__327 = ( char *)(( char *)llvm_cbe_tmp__326);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 2, !dbg !11 for 0x%I64xth hint within @k2c_crop1d  --> \n", ++aesl_llvm_cbe_925_count);
  llvm_cbe_tmp__328 = (signed long long *)(&llvm_cbe_output->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%8, align 8, !dbg !11 for 0x%I64xth hint within @k2c_crop1d  --> \n", ++aesl_llvm_cbe_926_count);
  llvm_cbe_tmp__329 = (unsigned long long )*llvm_cbe_tmp__328;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__329);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = shl i64 %%9, 2, !dbg !11 for 0x%I64xth hint within @k2c_crop1d  --> \n", ++aesl_llvm_cbe_927_count);
  llvm_cbe_tmp__330 = (unsigned long long )llvm_cbe_tmp__329 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__330);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call i8* @memcpy(i8* %%5, i8* %%7, i64 %%10 for 0x%I64xth hint within @k2c_crop1d  --> \n", ++aesl_llvm_cbe_928_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__325, ( char *)llvm_cbe_tmp__327, llvm_cbe_tmp__330);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__330);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__331);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_crop1d}\n");
  return;
}


void k2c_crop2d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_crop) {
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
  signed long long *llvm_cbe_tmp__332;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  unsigned long long llvm_cbe_tmp__333;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  signed long long *llvm_cbe_tmp__334;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  unsigned long long llvm_cbe_tmp__335;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  signed long long *llvm_cbe_tmp__336;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  unsigned long long llvm_cbe_tmp__337;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  unsigned long long llvm_cbe_tmp__338;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  signed long long *llvm_cbe_tmp__339;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  unsigned long long llvm_cbe_tmp__340;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  signed long long *llvm_cbe_tmp__341;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  unsigned long long llvm_cbe_tmp__342;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  unsigned long long llvm_cbe_tmp__343;
  static  unsigned long long aesl_llvm_cbe_tmp_count = 0;
  unsigned long long llvm_cbe_tmp;
  static  unsigned long long aesl_llvm_cbe_tmp1_count = 0;
  unsigned long long llvm_cbe_tmp1;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  unsigned long long llvm_cbe_tmp__344;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  unsigned long long llvm_cbe_tmp__345;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  unsigned long long llvm_cbe_tmp__346;
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
  unsigned long long llvm_cbe_tmp__347;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  unsigned long long llvm_cbe_tmp__348;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
  unsigned long long llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  unsigned long long llvm_cbe_tmp__349;
  unsigned long long llvm_cbe_tmp__349__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  unsigned long long llvm_cbe_tmp__350;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  float *llvm_cbe_tmp__351;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
   char *llvm_cbe_tmp__352;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  float *llvm_cbe_tmp__353;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
   char *llvm_cbe_tmp__354;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
   char *llvm_cbe_tmp__355;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  unsigned long long llvm_cbe_tmp__356;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  unsigned long long llvm_cbe_tmp__357;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_crop2d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 0, !dbg !10 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_941_count);
  llvm_cbe_tmp__332 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !10 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_942_count);
  llvm_cbe_tmp__333 = (unsigned long long )*llvm_cbe_tmp__332;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__333);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_945_count);
  llvm_cbe_tmp__334 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !11 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_946_count);
  llvm_cbe_tmp__335 = (unsigned long long )*llvm_cbe_tmp__334;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__335);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 2, !dbg !11 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_951_count);
  llvm_cbe_tmp__336 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !11 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_952_count);
  llvm_cbe_tmp__337 = (unsigned long long )*llvm_cbe_tmp__336;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__337);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%crop, align 8, !dbg !11 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_958_count);
  llvm_cbe_tmp__338 = (unsigned long long )*llvm_cbe_crop;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__338);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i64* %%crop, i64 2, !dbg !12 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_961_count);
  llvm_cbe_tmp__339 = (signed long long *)(&llvm_cbe_crop[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%8, align 8, !dbg !12 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_962_count);
  llvm_cbe_tmp__340 = (unsigned long long )*llvm_cbe_tmp__339;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__340);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i64* %%crop, i64 3, !dbg !12 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_966_count);
  llvm_cbe_tmp__341 = (signed long long *)(&llvm_cbe_crop[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%10, align 8, !dbg !12 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_967_count);
  llvm_cbe_tmp__342 = (unsigned long long )*llvm_cbe_tmp__341;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__342);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = mul i64 %%4, %%7, !dbg !12 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_970_count);
  llvm_cbe_tmp__343 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__335&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__338&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__343&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp = add i64 %%9, %%1 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_tmp_count);
  llvm_cbe_tmp = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__340&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__343&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp1 = mul i64 %%tmp, %%6, !dbg !12 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_tmp1_count);
  llvm_cbe_tmp1 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__337&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp1 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp1&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sub i64 %%4, %%9, !dbg !12 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_974_count);
  llvm_cbe_tmp__344 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__335&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__340&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__344&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sub i64 %%13, %%11, !dbg !12 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_975_count);
  llvm_cbe_tmp__345 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__344&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__342&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__345&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = mul i64 %%14, %%6, !dbg !12 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_976_count);
  llvm_cbe_tmp__346 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__345&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__337&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__346&18446744073709551615ull)));
  if (((llvm_cbe_tmp__333&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = shl i64 %%15, 2, !dbg !11 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_986_count);
  llvm_cbe_tmp__347 = (unsigned long long )llvm_cbe_tmp__346 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__347);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = mul i64 %%6, %%4, !dbg !12 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_987_count);
  llvm_cbe_tmp__348 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__337&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__335&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__348&18446744073709551615ull)));
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__349__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp1;   /* for PHI node */
  goto llvm_cbe_tmp__358;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__358:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i64 [ 0, %%.lr.ph ], [ %%28, %%19  for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__357);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = phi i64 [ %%tmp1, %%.lr.ph ], [ %%27, %%19  for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_989_count);
  llvm_cbe_tmp__349 = (unsigned long long )llvm_cbe_tmp__349__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__349);
printf("\ntmp1 = 0x%I64X",llvm_cbe_tmp1);
printf("\n = 0x%I64X",llvm_cbe_tmp__356);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = mul i64 %%storemerge3, %%15, !dbg !11 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_990_count);
  llvm_cbe_tmp__350 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__346&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__350&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%21, !dbg !11 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_991_count);
  llvm_cbe_tmp__351 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__350))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__350));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = bitcast float* %%22 to i8*, !dbg !11 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_992_count);
  llvm_cbe_tmp__352 = ( char *)(( char *)llvm_cbe_tmp__351);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%20, !dbg !11 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_993_count);
  llvm_cbe_tmp__353 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__349))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__349));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = bitcast float* %%24 to i8*, !dbg !11 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_994_count);
  llvm_cbe_tmp__354 = ( char *)(( char *)llvm_cbe_tmp__353);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i8* @memcpy(i8* %%23, i8* %%25, i64 %%17 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_995_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__352, ( char *)llvm_cbe_tmp__354, llvm_cbe_tmp__347);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__347);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__355);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add i64 %%20, %%18, !dbg !12 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_996_count);
  llvm_cbe_tmp__356 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__349&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__348&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__356&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i64 %%storemerge3, 1, !dbg !13 for 0x%I64xth hint within @k2c_crop2d  --> \n", ++aesl_llvm_cbe_1000_count);
  llvm_cbe_tmp__357 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__357&18446744073709551615ull)));
  if (((llvm_cbe_tmp__357&18446744073709551615ULL) == (llvm_cbe_tmp__333&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__357;   /* for PHI node */
    llvm_cbe_tmp__349__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__356;   /* for PHI node */
    goto llvm_cbe_tmp__358;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_crop2d}\n");
  return;
}


void k2c_crop3d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_crop) {
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
  signed long long *llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  unsigned long long llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  signed long long *llvm_cbe_tmp__361;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  unsigned long long llvm_cbe_tmp__362;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  signed long long *llvm_cbe_tmp__363;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  unsigned long long llvm_cbe_tmp__364;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  unsigned long long llvm_cbe_tmp__365;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  signed long long *llvm_cbe_tmp__366;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  unsigned long long llvm_cbe_tmp__367;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  unsigned long long llvm_cbe_tmp__368;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  unsigned long long llvm_cbe_tmp__369;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  signed long long *llvm_cbe_tmp__370;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  unsigned long long llvm_cbe_tmp__371;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  unsigned long long llvm_cbe_tmp__372;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  signed long long *llvm_cbe_tmp__373;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  unsigned long long llvm_cbe_tmp__374;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  unsigned long long llvm_cbe_tmp__375;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  signed long long *llvm_cbe_tmp__376;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  unsigned long long llvm_cbe_tmp__377;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  unsigned long long llvm_cbe_tmp__378;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  signed long long *llvm_cbe_tmp__379;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  unsigned long long llvm_cbe_tmp__380;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  unsigned long long llvm_cbe_tmp__381;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
  signed long long *llvm_cbe_tmp__382;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  unsigned long long llvm_cbe_tmp__383;
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
  static  unsigned long long aesl_llvm_cbe_tmp6_count = 0;
  unsigned long long llvm_cbe_tmp6;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  unsigned long long llvm_cbe_tmp__384;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  unsigned long long llvm_cbe_tmp__385;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge20_count = 0;
  unsigned long long llvm_cbe_storemerge20;
  unsigned long long llvm_cbe_storemerge20__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  unsigned long long llvm_cbe_tmp__386;
  static  unsigned long long aesl_llvm_cbe_tmp10_count = 0;
  unsigned long long llvm_cbe_tmp10;
  static  unsigned long long aesl_llvm_cbe_tmp11_count = 0;
  unsigned long long llvm_cbe_tmp11;
  static  unsigned long long aesl_llvm_cbe_tmp13_count = 0;
  unsigned long long llvm_cbe_tmp13;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge119_count = 0;
  unsigned long long llvm_cbe_storemerge119;
  unsigned long long llvm_cbe_storemerge119__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_tmp5_count = 0;
  unsigned long long llvm_cbe_tmp5;
  static  unsigned long long aesl_llvm_cbe_tmp7_count = 0;
  unsigned long long llvm_cbe_tmp7;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  float *llvm_cbe_tmp__387;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
   char *llvm_cbe_tmp__388;
  static  unsigned long long aesl_llvm_cbe_tmp16_count = 0;
  unsigned long long llvm_cbe_tmp16;
  static  unsigned long long aesl_llvm_cbe_tmp17_count = 0;
  unsigned long long llvm_cbe_tmp17;
  static  unsigned long long aesl_llvm_cbe_tmp15_count = 0;
  unsigned long long llvm_cbe_tmp15;
  static  unsigned long long aesl_llvm_cbe_tmp18_count = 0;
  unsigned long long llvm_cbe_tmp18;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  float *llvm_cbe_tmp__389;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
   char *llvm_cbe_tmp__390;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
   char *llvm_cbe_tmp__391;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
  unsigned long long llvm_cbe_tmp__392;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  unsigned long long llvm_cbe_tmp__393;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_crop3d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 0, !dbg !11 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1027_count);
  llvm_cbe_tmp__359 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !11 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1028_count);
  llvm_cbe_tmp__360 = (unsigned long long )*llvm_cbe_tmp__359;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__360);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1031_count);
  llvm_cbe_tmp__361 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !11 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1032_count);
  llvm_cbe_tmp__362 = (unsigned long long )*llvm_cbe_tmp__361;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__362);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 2, !dbg !11 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1037_count);
  llvm_cbe_tmp__363 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !11 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1038_count);
  llvm_cbe_tmp__364 = (unsigned long long )*llvm_cbe_tmp__363;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__364);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%crop, align 8, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1044_count);
  llvm_cbe_tmp__365 = (unsigned long long )*llvm_cbe_crop;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__365);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i64* %%crop, i64 1, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1045_count);
  llvm_cbe_tmp__366 = (signed long long *)(&llvm_cbe_crop[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%8, align 8, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1046_count);
  llvm_cbe_tmp__367 = (unsigned long long )*llvm_cbe_tmp__366;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__367);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sub i64 %%2, %%7, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1047_count);
  llvm_cbe_tmp__368 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__360&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__365&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__368&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sub i64 %%10, %%9, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1048_count);
  llvm_cbe_tmp__369 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__368&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__367&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__369&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds i64* %%crop, i64 2, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1051_count);
  llvm_cbe_tmp__370 = (signed long long *)(&llvm_cbe_crop[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i64* %%12, align 8, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1052_count);
  llvm_cbe_tmp__371 = (unsigned long long )*llvm_cbe_tmp__370;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__371);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sub i64 %%4, %%13, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1053_count);
  llvm_cbe_tmp__372 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__362&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__371&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__372&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds i64* %%crop, i64 3, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1054_count);
  llvm_cbe_tmp__373 = (signed long long *)(&llvm_cbe_crop[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i64* %%15, align 8, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1055_count);
  llvm_cbe_tmp__374 = (unsigned long long )*llvm_cbe_tmp__373;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__374);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = sub i64 %%14, %%16, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1056_count);
  llvm_cbe_tmp__375 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__372&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__374&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__375&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds i64* %%crop, i64 4, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1060_count);
  llvm_cbe_tmp__376 = (signed long long *)(&llvm_cbe_crop[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i64* %%18, align 8, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1061_count);
  llvm_cbe_tmp__377 = (unsigned long long )*llvm_cbe_tmp__376;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__377);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sub i64 %%6, %%19, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1062_count);
  llvm_cbe_tmp__378 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__364&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__377&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__378&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds i64* %%crop, i64 5, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1063_count);
  llvm_cbe_tmp__379 = (signed long long *)(&llvm_cbe_crop[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i64* %%21, align 8, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1064_count);
  llvm_cbe_tmp__380 = (unsigned long long )*llvm_cbe_tmp__379;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__380);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sub i64 %%20, %%22, !dbg !12 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1065_count);
  llvm_cbe_tmp__381 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__378&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__380&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__381&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 3, !dbg !11 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1070_count);
  llvm_cbe_tmp__382 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i64* %%24, align 8, !dbg !11 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1071_count);
  llvm_cbe_tmp__383 = (unsigned long long )*llvm_cbe_tmp__382;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__383);
  if (((llvm_cbe_tmp__368&18446744073709551615ULL) == (llvm_cbe_tmp__367&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge21;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp6 = mul i64 %%25, %%2 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_tmp6_count);
  llvm_cbe_tmp6 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__383&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__381&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp6 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp6&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = shl i64 %%23, 2, !dbg !13 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1089_count);
  llvm_cbe_tmp__384 = (unsigned long long )llvm_cbe_tmp__381 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__384);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = mul i64 %%28, %%25, !dbg !10 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1090_count);
  llvm_cbe_tmp__385 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__384&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__383&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__385&18446744073709551615ull)));
  llvm_cbe_storemerge20__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge20 = phi i64 [ 0, %%.preheader.lr.ph ], [ %%39, %%._crit_edge  for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_storemerge20_count);
  llvm_cbe_storemerge20 = (unsigned long long )llvm_cbe_storemerge20__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge20 = 0x%I64X",llvm_cbe_storemerge20);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__393);
}
  if (((llvm_cbe_tmp__372&18446744073709551615ULL) == (llvm_cbe_tmp__374&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i64 %%storemerge20, 1, !dbg !14 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1112_count);
  llvm_cbe_tmp__393 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge20&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__393&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__393&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__369&18446744073709551615ULL))) {
    llvm_cbe_storemerge20__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__393;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e__crit_edge21;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__394:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge119 = phi i64 [ 0, %%.lr.ph ], [ %%37, %%31  for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_storemerge119_count);
  llvm_cbe_storemerge119 = (unsigned long long )llvm_cbe_storemerge119__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge119 = 0x%I64X",llvm_cbe_storemerge119);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__392);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp5 = add i64 %%storemerge119, %%3 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_tmp5_count);
  llvm_cbe_tmp5 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge119&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__386&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp5 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp5&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp7 = mul i64 %%tmp6, %%tmp5, !dbg !10 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_tmp7_count);
  llvm_cbe_tmp7 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp6&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp5&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp7 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp7&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%tmp7, !dbg !10 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1099_count);
  llvm_cbe_tmp__387 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp7))]);
if (AESL_DEBUG_TRACE) {
printf("\ntmp7 = 0x%I64X",((signed long long )llvm_cbe_tmp7));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = bitcast float* %%32 to i8*, !dbg !10 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1100_count);
  llvm_cbe_tmp__388 = ( char *)(( char *)llvm_cbe_tmp__387);
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp16 = add i64 %%tmp13, %%storemerge11 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_tmp16_count);
  llvm_cbe_tmp16 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp13&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge119&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp16 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp16&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp17 = mul i64 %%tmp16, %% for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_tmp17_count);
  llvm_cbe_tmp17 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp16&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__364&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp17 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp17&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp15 = add i64 %%tmp17, %%1 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_tmp15_count);
  llvm_cbe_tmp15 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp17&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__377&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp15 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp15&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp18 = mul i64 %%tmp15, %%25, !dbg !10 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_tmp18_count);
  llvm_cbe_tmp18 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp15&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__383&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp18 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp18&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%tmp18, !dbg !10 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1101_count);
  llvm_cbe_tmp__389 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp18))]);
if (AESL_DEBUG_TRACE) {
printf("\ntmp18 = 0x%I64X",((signed long long )llvm_cbe_tmp18));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = bitcast float* %%34 to i8*, !dbg !10 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1102_count);
  llvm_cbe_tmp__390 = ( char *)(( char *)llvm_cbe_tmp__389);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = call i8* @memcpy(i8* %%33, i8* %%35, i64 %%29 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1103_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__388, ( char *)llvm_cbe_tmp__390, llvm_cbe_tmp__385);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__385);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__391);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add i64 %%storemerge119, 1, !dbg !14 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1104_count);
  llvm_cbe_tmp__392 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge119&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__392&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__392&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__375&18446744073709551615ULL))) {
    llvm_cbe_storemerge119__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__392;   /* for PHI node */
    goto llvm_cbe_tmp__394;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = mul i64 %%17, %%storemerge20, !dbg !10 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_1097_count);
  llvm_cbe_tmp__386 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__375&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge20&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__386&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp10 = add i64 %%storemerge20, %% for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_tmp10_count);
  llvm_cbe_tmp10 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge20&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__365&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp10 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp10&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp11 = mul i64 %%4, %%tmp1 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_tmp11_count);
  llvm_cbe_tmp11 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__362&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp10&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp11 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp11&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%tmp13 = add i64 %%tmp11, %%1 for 0x%I64xth hint within @k2c_crop3d  --> \n", ++aesl_llvm_cbe_tmp13_count);
  llvm_cbe_tmp13 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp11&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__371&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\ntmp13 = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp13&18446744073709551615ull)));
  llvm_cbe_storemerge119__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__394;

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge21:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_crop3d}\n");
  return;
}


void k2c_upsampling1d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long llvm_cbe_size) {
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
  signed long long *llvm_cbe_tmp__395;
  static  unsigned long long aesl_llvm_cbe_1131_count = 0;
  unsigned long long llvm_cbe_tmp__396;
  static  unsigned long long aesl_llvm_cbe_1132_count = 0;
  static  unsigned long long aesl_llvm_cbe_1133_count = 0;
  static  unsigned long long aesl_llvm_cbe_1134_count = 0;
  signed long long *llvm_cbe_tmp__397;
  static  unsigned long long aesl_llvm_cbe_1135_count = 0;
  unsigned long long llvm_cbe_tmp__398;
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
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned long long llvm_cbe_storemerge7;
  unsigned long long llvm_cbe_storemerge7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1150_count = 0;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  unsigned long long llvm_cbe_tmp__399;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  unsigned long long llvm_cbe_tmp__400;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_count = 0;
  unsigned long long llvm_cbe_storemerge15;
  unsigned long long llvm_cbe_storemerge15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  unsigned long long llvm_cbe_tmp__401;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  unsigned long long llvm_cbe_tmp__402;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_count = 0;
  unsigned long long llvm_cbe_storemerge23;
  unsigned long long llvm_cbe_storemerge23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  unsigned long long llvm_cbe_tmp__403;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  float *llvm_cbe_tmp__404;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  float llvm_cbe_tmp__405;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  unsigned long long llvm_cbe_tmp__406;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  float *llvm_cbe_tmp__407;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  unsigned long long llvm_cbe_tmp__408;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  static  unsigned long long aesl_llvm_cbe_1174_count = 0;
  static  unsigned long long aesl_llvm_cbe_1175_count = 0;
  static  unsigned long long aesl_llvm_cbe_1176_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1177_count = 0;
  static  unsigned long long aesl_llvm_cbe_1178_count = 0;
  unsigned long long llvm_cbe_tmp__409;
  static  unsigned long long aesl_llvm_cbe_1179_count = 0;
  static  unsigned long long aesl_llvm_cbe_1180_count = 0;
  static  unsigned long long aesl_llvm_cbe_1181_count = 0;
  static  unsigned long long aesl_llvm_cbe_1182_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond9_count = 0;
  static  unsigned long long aesl_llvm_cbe_1183_count = 0;
  static  unsigned long long aesl_llvm_cbe_1184_count = 0;
  unsigned long long llvm_cbe_tmp__410;
  static  unsigned long long aesl_llvm_cbe_1185_count = 0;
  static  unsigned long long aesl_llvm_cbe_1186_count = 0;
  static  unsigned long long aesl_llvm_cbe_1187_count = 0;
  static  unsigned long long aesl_llvm_cbe_1188_count = 0;
  static  unsigned long long aesl_llvm_cbe_1189_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond10_count = 0;
  static  unsigned long long aesl_llvm_cbe_1190_count = 0;
  static  unsigned long long aesl_llvm_cbe_1191_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_upsampling1d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 0, !dbg !11 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1130_count);
  llvm_cbe_tmp__395 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !11 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1131_count);
  llvm_cbe_tmp__396 = (unsigned long long )*llvm_cbe_tmp__395;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__396);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1134_count);
  llvm_cbe_tmp__397 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !11 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1135_count);
  llvm_cbe_tmp__398 = (unsigned long long )*llvm_cbe_tmp__397;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__398);
  if (((llvm_cbe_tmp__396&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge8;
  } else {
    goto llvm_cbe__2e_preheader4_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader4_2e_lr_2e_ph:
  llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader4;

  do {     /* Syntactic loop '.preheader4' to make GCC happy */
llvm_cbe__2e_preheader4:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = phi i64 [ 0, %%.preheader4.lr.ph ], [ %%20, %%._crit_edge6  for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned long long )llvm_cbe_storemerge7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",llvm_cbe_storemerge7);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__410);
}
  if (((llvm_cbe_size&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge6:
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add i64 %%storemerge7, 1, !dbg !12 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1184_count);
  llvm_cbe_tmp__410 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__410&18446744073709551615ull)));
  if (((llvm_cbe_tmp__410&18446744073709551615ULL) == (llvm_cbe_tmp__396&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge8;
  } else {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__410;   /* for PHI node */
    goto llvm_cbe__2e_preheader4;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15 = phi i64 [ 0, %%.preheader.lr.ph ], [ %%19, %%._crit_edge  for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_storemerge15_count);
  llvm_cbe_storemerge15 = (unsigned long long )llvm_cbe_storemerge15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",llvm_cbe_storemerge15);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__409);
}
  if (((llvm_cbe_tmp__398&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%storemerge15, 1, !dbg !13 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1178_count);
  llvm_cbe_tmp__409 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge15&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__409&18446744073709551615ull)));
  if (((llvm_cbe_tmp__409&18446744073709551615ULL) == (llvm_cbe_size&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__409;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__411:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23 = phi i64 [ 0, %%.lr.ph ], [ %%18, %%12  for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_storemerge23_count);
  llvm_cbe_storemerge23 = (unsigned long long )llvm_cbe_storemerge23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",llvm_cbe_storemerge23);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__408);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i64 %%storemerge23, %%8, !dbg !10 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1165_count);
  llvm_cbe_tmp__403 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__399&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__403&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%13, !dbg !10 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1166_count);
  llvm_cbe_tmp__404 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__403))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__403));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load float* %%14, align 4, !dbg !10 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1167_count);
  llvm_cbe_tmp__405 = (float )*llvm_cbe_tmp__404;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__405, *(int*)(&llvm_cbe_tmp__405));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i64 %%storemerge23, %%11, !dbg !10 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1168_count);
  llvm_cbe_tmp__406 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__402&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__406&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%16, !dbg !10 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1169_count);
  llvm_cbe_tmp__407 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__406))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__406));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* %%17, align 4, !dbg !10 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1170_count);
  *llvm_cbe_tmp__407 = llvm_cbe_tmp__405;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__405);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i64 %%storemerge23, 1, !dbg !13 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1171_count);
  llvm_cbe_tmp__408 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__408&18446744073709551615ull)));
  if (((llvm_cbe_tmp__408&18446744073709551615ULL) == (llvm_cbe_tmp__398&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__408;   /* for PHI node */
    goto llvm_cbe_tmp__411;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i64 %%storemerge15, %%9, !dbg !10 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1162_count);
  llvm_cbe_tmp__401 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge15&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__400&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__401&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = mul i64 %%10, %%4, !dbg !10 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1163_count);
  llvm_cbe_tmp__402 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__401&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__398&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__402&18446744073709551615ull)));
  llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__411;

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = mul i64 %%storemerge7, %%4, !dbg !10 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1154_count);
  llvm_cbe_tmp__399 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__398&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__399&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul i64 %%storemerge7, %%size, !dbg !10 for 0x%I64xth hint within @k2c_upsampling1d  --> \n", ++aesl_llvm_cbe_1155_count);
  llvm_cbe_tmp__400 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_size&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__400&18446744073709551615ull)));
  llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  } while (1); /* end of syntactic loop '.preheader4' */
llvm_cbe__2e__crit_edge8:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_upsampling1d}\n");
  return;
}


void k2c_upsampling2d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_size) {
  static  unsigned long long aesl_llvm_cbe_insub_count = 0;
  signed long long llvm_cbe_insub[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_outsub_count = 0;
  signed long long llvm_cbe_outsub[5];    /* Address-exposed local */
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
  signed long long *llvm_cbe_tmp__412;
  static  unsigned long long aesl_llvm_cbe_1207_count = 0;
  unsigned long long llvm_cbe_tmp__413;
  static  unsigned long long aesl_llvm_cbe_1208_count = 0;
  static  unsigned long long aesl_llvm_cbe_1209_count = 0;
  static  unsigned long long aesl_llvm_cbe_1210_count = 0;
  signed long long *llvm_cbe_tmp__414;
  static  unsigned long long aesl_llvm_cbe_1211_count = 0;
  unsigned long long llvm_cbe_tmp__415;
  static  unsigned long long aesl_llvm_cbe_1212_count = 0;
  static  unsigned long long aesl_llvm_cbe_1213_count = 0;
  static  unsigned long long aesl_llvm_cbe_1214_count = 0;
  signed long long *llvm_cbe_tmp__416;
  static  unsigned long long aesl_llvm_cbe_1215_count = 0;
  unsigned long long llvm_cbe_tmp__417;
  static  unsigned long long aesl_llvm_cbe_1216_count = 0;
  static  unsigned long long aesl_llvm_cbe_1217_count = 0;
  static  unsigned long long aesl_llvm_cbe_1218_count = 0;
  static  unsigned long long aesl_llvm_cbe_1219_count = 0;
  static  unsigned long long aesl_llvm_cbe_1220_count = 0;
  static  unsigned long long aesl_llvm_cbe_1221_count = 0;
  static  unsigned long long aesl_llvm_cbe_1222_count = 0;
  static  unsigned long long aesl_llvm_cbe_1223_count = 0;
  static  unsigned long long aesl_llvm_cbe_1224_count = 0;
  static  unsigned long long aesl_llvm_cbe_1225_count = 0;
  static  unsigned long long aesl_llvm_cbe_1226_count = 0;
  signed long long *llvm_cbe_tmp__418;
  static  unsigned long long aesl_llvm_cbe_1227_count = 0;
  signed long long *llvm_cbe_tmp__419;
  static  unsigned long long aesl_llvm_cbe_1228_count = 0;
  signed long long *llvm_cbe_tmp__420;
  static  unsigned long long aesl_llvm_cbe_1229_count = 0;
  signed long long *llvm_cbe_tmp__421;
  static  unsigned long long aesl_llvm_cbe_1230_count = 0;
  signed long long *llvm_cbe_tmp__422;
  static  unsigned long long aesl_llvm_cbe_1231_count = 0;
  signed long long *llvm_cbe_tmp__423;
  static  unsigned long long aesl_llvm_cbe_1232_count = 0;
  signed long long *llvm_cbe_tmp__424;
  static  unsigned long long aesl_llvm_cbe_1233_count = 0;
  signed long long *llvm_cbe_tmp__425;
  static  unsigned long long aesl_llvm_cbe_1234_count = 0;
  signed long long *llvm_cbe_tmp__426;
  static  unsigned long long aesl_llvm_cbe_1235_count = 0;
  signed long long *llvm_cbe_tmp__427;
  static  unsigned long long aesl_llvm_cbe_1236_count = 0;
  unsigned long long llvm_cbe_tmp__428;
  static  unsigned long long aesl_llvm_cbe_1237_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
  unsigned long long llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1238_count = 0;
  static  unsigned long long aesl_llvm_cbe_1239_count = 0;
  static  unsigned long long aesl_llvm_cbe_1240_count = 0;
  static  unsigned long long aesl_llvm_cbe_1241_count = 0;
  static  unsigned long long aesl_llvm_cbe_1242_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1243_count = 0;
  static  unsigned long long aesl_llvm_cbe_1244_count = 0;
  unsigned long long llvm_cbe_tmp__429;
  static  unsigned long long aesl_llvm_cbe_1245_count = 0;
  unsigned long long llvm_cbe_tmp__430;
  static  unsigned long long aesl_llvm_cbe_1246_count = 0;
  static  unsigned long long aesl_llvm_cbe_1247_count = 0;
  unsigned long long llvm_cbe_tmp__431;
  static  unsigned long long aesl_llvm_cbe_1248_count = 0;
  unsigned long long llvm_cbe_tmp__432;
  static  unsigned long long aesl_llvm_cbe_1249_count = 0;
  static  unsigned long long aesl_llvm_cbe_1250_count = 0;
  static  unsigned long long aesl_llvm_cbe_1251_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec6_count = 0;
  unsigned long long llvm_cbe__2e_rec6;
  unsigned long long llvm_cbe__2e_rec6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_1252_count = 0;
  signed long long *llvm_cbe_tmp__433;
  static  unsigned long long aesl_llvm_cbe_1253_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec7_count = 0;
  unsigned long long llvm_cbe__2e_rec7;
  static  unsigned long long aesl_llvm_cbe_1254_count = 0;
  static  unsigned long long aesl_llvm_cbe_1255_count = 0;
  static  unsigned long long aesl_llvm_cbe_1256_count = 0;
  static  unsigned long long aesl_llvm_cbe_1257_count = 0;
  static  unsigned long long aesl_llvm_cbe_1258_count = 0;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum10_count = 0;
  unsigned long long llvm_cbe__2e_sum10;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
  signed long long *llvm_cbe_tmp__434;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec5_count = 0;
  unsigned long long llvm_cbe__2e_rec5;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  unsigned long long llvm_cbe_tmp__435;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
  unsigned long long llvm_cbe_tmp__436;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
  float *llvm_cbe_tmp__437;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
   char *llvm_cbe_tmp__438;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  unsigned long long llvm_cbe_tmp__439;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
  unsigned long long llvm_cbe_tmp__440;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  float *llvm_cbe_tmp__441;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
   char *llvm_cbe_tmp__442;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
   char *llvm_cbe_tmp__443;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
  unsigned long long llvm_cbe_tmp__444;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
  static  unsigned long long aesl_llvm_cbe_1281_count = 0;
  unsigned long long llvm_cbe_tmp__445;
  static  unsigned long long aesl_llvm_cbe_1282_count = 0;
  static  unsigned long long aesl_llvm_cbe_1283_count = 0;
  static  unsigned long long aesl_llvm_cbe_1284_count = 0;
  static  unsigned long long aesl_llvm_cbe_1285_count = 0;
  static  unsigned long long aesl_llvm_cbe_1286_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond8_count = 0;
  static  unsigned long long aesl_llvm_cbe_1287_count = 0;
  static  unsigned long long aesl_llvm_cbe_1288_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_upsampling2d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 0, !dbg !10 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1206_count);
  llvm_cbe_tmp__412 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !10 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1207_count);
  llvm_cbe_tmp__413 = (unsigned long long )*llvm_cbe_tmp__412;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__413);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1210_count);
  llvm_cbe_tmp__414 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1211_count);
  llvm_cbe_tmp__415 = (unsigned long long )*llvm_cbe_tmp__414;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__415);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 2, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1214_count);
  llvm_cbe_tmp__416 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1215_count);
  llvm_cbe_tmp__417 = (unsigned long long )*llvm_cbe_tmp__416;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__417);
  if (((llvm_cbe_tmp__413&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge4;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [5 x i64]* %%insub, i64 0, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1226_count);
  llvm_cbe_tmp__418 = (signed long long *)(&llvm_cbe_insub[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [5 x i64]* %%insub, i64 0, i64 1, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1227_count);
  llvm_cbe_tmp__419 = (signed long long *)(&llvm_cbe_insub[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i64* %%size, i64 1, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1228_count);
  llvm_cbe_tmp__420 = (signed long long *)(&llvm_cbe_size[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [5 x i64]* %%insub, i64 0, i64 2, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1229_count);
  llvm_cbe_tmp__421 = (signed long long *)(&llvm_cbe_insub[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [5 x i64]* %%outsub, i64 0, i64 0, !dbg !13 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1230_count);
  llvm_cbe_tmp__422 = (signed long long *)(&llvm_cbe_outsub[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [5 x i64]* %%outsub, i64 0, i64 1, !dbg !13 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1231_count);
  llvm_cbe_tmp__423 = (signed long long *)(&llvm_cbe_outsub[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [5 x i64]* %%outsub, i64 0, i64 2, !dbg !13 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1232_count);
  llvm_cbe_tmp__424 = (signed long long *)(&llvm_cbe_outsub[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 1, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1233_count);
  llvm_cbe_tmp__425 = (signed long long *)(&llvm_cbe_output->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 0, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1234_count);
  llvm_cbe_tmp__426 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 1, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1235_count);
  llvm_cbe_tmp__427 = (signed long long *)(&llvm_cbe_input->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = shl i64 %%6, 2, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1236_count);
  llvm_cbe_tmp__428 = (unsigned long long )llvm_cbe_tmp__417 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__428);
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i64 [ 0, %%.preheader.lr.ph ], [ %%42, %%._crit_edge  for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__445);
}
  if (((llvm_cbe_tmp__415&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add i64 %%storemerge3, 1, !dbg !13 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1281_count);
  llvm_cbe_tmp__445 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__445&18446744073709551615ull)));
  if (((llvm_cbe_tmp__445&18446744073709551615ULL) == (llvm_cbe_tmp__413&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge4;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__445;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ %%41, %%31 ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",llvm_cbe_tmp__444);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i64* %%size, align 8, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1244_count);
  llvm_cbe_tmp__429 = (unsigned long long )*llvm_cbe_size;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__429);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = udiv i64 %%storemerge3, %%20, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1245_count);
  llvm_cbe_tmp__430 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) / ((unsigned long long )(llvm_cbe_tmp__429&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__430&18446744073709551615ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 5 && "Write access out of array 'insub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%21, i64* %%9, align 16, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1246_count);
  *llvm_cbe_tmp__418 = llvm_cbe_tmp__430;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__430);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i64* %%11, align 8, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1247_count);
  llvm_cbe_tmp__431 = (unsigned long long )*llvm_cbe_tmp__420;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__431);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = udiv i64 %%storemerge12, %%22, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1248_count);
  llvm_cbe_tmp__432 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) / ((unsigned long long )(llvm_cbe_tmp__431&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__432&18446744073709551615ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 5 && "Write access out of array 'insub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%23, i64* %%10, align 8, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1249_count);
  *llvm_cbe_tmp__419 = llvm_cbe_tmp__432;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__432);

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 5 && "Write access out of array 'insub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%12, align 16, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1250_count);
  *llvm_cbe_tmp__421 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
  llvm_cbe__2e_rec6__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__446;

llvm_cbe_tmp__447:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i64* %%16, align 8, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1265_count);
  llvm_cbe_tmp__435 = (unsigned long long )*llvm_cbe_tmp__425;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__435);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = call i64 @k2c_sub2idx(i64* %%13, i64* %%1, i64 %%32) nounwind, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1266_count);
  llvm_cbe_tmp__436 = (unsigned long long )k2c_sub2idx((signed long long *)llvm_cbe_tmp__422, (signed long long *)llvm_cbe_tmp__412, llvm_cbe_tmp__435);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__435);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__436);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%33, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1267_count);
  llvm_cbe_tmp__437 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__436))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__436));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = bitcast float* %%34 to i8*, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1268_count);
  llvm_cbe_tmp__438 = ( char *)(( char *)llvm_cbe_tmp__437);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i64* %%18, align 8, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1269_count);
  llvm_cbe_tmp__439 = (unsigned long long )*llvm_cbe_tmp__427;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__439);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = call i64 @k2c_sub2idx(i64* %%9, i64* %%17, i64 %%36) nounwind, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1270_count);
  llvm_cbe_tmp__440 = (unsigned long long )k2c_sub2idx((signed long long *)llvm_cbe_tmp__418, (signed long long *)llvm_cbe_tmp__426, llvm_cbe_tmp__439);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__439);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__440);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%37, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1271_count);
  llvm_cbe_tmp__441 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__440))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__440));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = bitcast float* %%38 to i8*, !dbg !11 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1272_count);
  llvm_cbe_tmp__442 = ( char *)(( char *)llvm_cbe_tmp__441);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = call i8* @memcpy(i8* %%35, i8* %%39, i64 %%19 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1273_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__438, ( char *)llvm_cbe_tmp__442, llvm_cbe_tmp__428);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__428);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__443);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add i64 %%storemerge12, 1, !dbg !13 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1274_count);
  llvm_cbe_tmp__444 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__444&18446744073709551615ull)));
  if (((llvm_cbe_tmp__444&18446744073709551615ULL) == (llvm_cbe_tmp__415&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__444;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__448:
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ 0, %%27 ], [ %%.rec5, %%28  for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n.rec5 = 0x%I64X",llvm_cbe__2e_rec5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum10 = add i64 %%.rec,  for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe__2e_sum10_count);
  llvm_cbe__2e_sum10 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(3ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum10 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum10&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr [5 x i64]* %%outsub, i64 0, i64 %%.sum1 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1261_count);
  llvm_cbe_tmp__434 = (signed long long *)(&llvm_cbe_outsub[(((signed long long )llvm_cbe__2e_sum10))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum10 = 0x%I64X",((signed long long )llvm_cbe__2e_sum10));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe__2e_sum10) < 5 && "Write access out of array 'outsub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%29, align 8, !dbg !13 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1262_count);
  *llvm_cbe_tmp__434 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec5 = add i64 %%.rec, 1, !dbg !13 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe__2e_rec5_count);
  llvm_cbe__2e_rec5 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec5 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec5&18446744073709551615ull)));
  if (((llvm_cbe__2e_rec&18446744073709551615ULL) == (1ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__447;
  } else {
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec5;   /* for PHI node */
    goto llvm_cbe_tmp__448;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__449:

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 5 && "Write access out of array 'outsub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%storemerge3, i64* %%13, align 16, !dbg !13 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1257_count);
  *llvm_cbe_tmp__422 = llvm_cbe_storemerge3;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge3 = 0x%I64X\n", llvm_cbe_storemerge3);

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 5 && "Write access out of array 'outsub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%storemerge12, i64* %%14, align 8, !dbg !13 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1258_count);
  *llvm_cbe_tmp__423 = llvm_cbe_storemerge12;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge12 = 0x%I64X\n", llvm_cbe_storemerge12);

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 5 && "Write access out of array 'outsub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%15, align 16, !dbg !13 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1259_count);
  *llvm_cbe_tmp__424 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__448;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__446:
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec6 = phi i64 [ 0, %%.lr.ph ], [ %%.rec7, %%24  for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe__2e_rec6_count);
  llvm_cbe__2e_rec6 = (unsigned long long )llvm_cbe__2e_rec6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec6 = 0x%I64X",llvm_cbe__2e_rec6);
printf("\n = 0x%I64X",0ull);
printf("\n.rec7 = 0x%I64X",llvm_cbe__2e_rec7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%.rec6,  for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec6&18446744073709551615ull)) + ((unsigned long long )(3ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr [5 x i64]* %%insub, i64 0, i64 %%.su for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1252_count);
  llvm_cbe_tmp__433 = (signed long long *)(&llvm_cbe_insub[(((signed long long )llvm_cbe__2e_sum))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe__2e_sum) < 5 && "Write access out of array 'insub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%25, align 8, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe_1253_count);
  *llvm_cbe_tmp__433 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec7 = add i64 %%.rec6, 1, !dbg !12 for 0x%I64xth hint within @k2c_upsampling2d  --> \n", ++aesl_llvm_cbe__2e_rec7_count);
  llvm_cbe__2e_rec7 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec6&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec7 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec7&18446744073709551615ull)));
  if (((llvm_cbe__2e_rec6&18446744073709551615ULL) == (1ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__449;
  } else {
    llvm_cbe__2e_rec6__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec7;   /* for PHI node */
    goto llvm_cbe_tmp__446;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge4:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_upsampling2d}\n");
  return;
}


void k2c_upsampling3d(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, signed long long *llvm_cbe_size) {
  static  unsigned long long aesl_llvm_cbe_insub_count = 0;
  signed long long llvm_cbe_insub[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_outsub_count = 0;
  signed long long llvm_cbe_outsub[5];    /* Address-exposed local */
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
  signed long long *llvm_cbe_tmp__450;
  static  unsigned long long aesl_llvm_cbe_1306_count = 0;
  unsigned long long llvm_cbe_tmp__451;
  static  unsigned long long aesl_llvm_cbe_1307_count = 0;
  static  unsigned long long aesl_llvm_cbe_1308_count = 0;
  static  unsigned long long aesl_llvm_cbe_1309_count = 0;
  signed long long *llvm_cbe_tmp__452;
  static  unsigned long long aesl_llvm_cbe_1310_count = 0;
  unsigned long long llvm_cbe_tmp__453;
  static  unsigned long long aesl_llvm_cbe_1311_count = 0;
  static  unsigned long long aesl_llvm_cbe_1312_count = 0;
  static  unsigned long long aesl_llvm_cbe_1313_count = 0;
  signed long long *llvm_cbe_tmp__454;
  static  unsigned long long aesl_llvm_cbe_1314_count = 0;
  unsigned long long llvm_cbe_tmp__455;
  static  unsigned long long aesl_llvm_cbe_1315_count = 0;
  static  unsigned long long aesl_llvm_cbe_1316_count = 0;
  static  unsigned long long aesl_llvm_cbe_1317_count = 0;
  signed long long *llvm_cbe_tmp__456;
  static  unsigned long long aesl_llvm_cbe_1318_count = 0;
  unsigned long long llvm_cbe_tmp__457;
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
  signed long long *llvm_cbe_tmp__458;
  static  unsigned long long aesl_llvm_cbe_1331_count = 0;
  signed long long *llvm_cbe_tmp__459;
  static  unsigned long long aesl_llvm_cbe_1332_count = 0;
  signed long long *llvm_cbe_tmp__460;
  static  unsigned long long aesl_llvm_cbe_1333_count = 0;
  signed long long *llvm_cbe_tmp__461;
  static  unsigned long long aesl_llvm_cbe_1334_count = 0;
  signed long long *llvm_cbe_tmp__462;
  static  unsigned long long aesl_llvm_cbe_1335_count = 0;
  signed long long *llvm_cbe_tmp__463;
  static  unsigned long long aesl_llvm_cbe_1336_count = 0;
  signed long long *llvm_cbe_tmp__464;
  static  unsigned long long aesl_llvm_cbe_1337_count = 0;
  signed long long *llvm_cbe_tmp__465;
  static  unsigned long long aesl_llvm_cbe_1338_count = 0;
  signed long long *llvm_cbe_tmp__466;
  static  unsigned long long aesl_llvm_cbe_1339_count = 0;
  signed long long *llvm_cbe_tmp__467;
  static  unsigned long long aesl_llvm_cbe_1340_count = 0;
  signed long long *llvm_cbe_tmp__468;
  static  unsigned long long aesl_llvm_cbe_1341_count = 0;
  signed long long *llvm_cbe_tmp__469;
  static  unsigned long long aesl_llvm_cbe_1342_count = 0;
  signed long long *llvm_cbe_tmp__470;
  static  unsigned long long aesl_llvm_cbe_1343_count = 0;
  unsigned long long llvm_cbe_tmp__471;
  static  unsigned long long aesl_llvm_cbe_1344_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned long long llvm_cbe_storemerge7;
  unsigned long long llvm_cbe_storemerge7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1345_count = 0;
  static  unsigned long long aesl_llvm_cbe_1346_count = 0;
  static  unsigned long long aesl_llvm_cbe_1347_count = 0;
  static  unsigned long long aesl_llvm_cbe_1348_count = 0;
  static  unsigned long long aesl_llvm_cbe_1349_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_count = 0;
  unsigned long long llvm_cbe_storemerge15;
  unsigned long long llvm_cbe_storemerge15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1350_count = 0;
  static  unsigned long long aesl_llvm_cbe_1351_count = 0;
  static  unsigned long long aesl_llvm_cbe_1352_count = 0;
  static  unsigned long long aesl_llvm_cbe_1353_count = 0;
  static  unsigned long long aesl_llvm_cbe_1354_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_count = 0;
  unsigned long long llvm_cbe_storemerge23;
  unsigned long long llvm_cbe_storemerge23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1355_count = 0;
  static  unsigned long long aesl_llvm_cbe_1356_count = 0;
  unsigned long long llvm_cbe_tmp__472;
  static  unsigned long long aesl_llvm_cbe_1357_count = 0;
  unsigned long long llvm_cbe_tmp__473;
  static  unsigned long long aesl_llvm_cbe_1358_count = 0;
  static  unsigned long long aesl_llvm_cbe_1359_count = 0;
  unsigned long long llvm_cbe_tmp__474;
  static  unsigned long long aesl_llvm_cbe_1360_count = 0;
  unsigned long long llvm_cbe_tmp__475;
  static  unsigned long long aesl_llvm_cbe_1361_count = 0;
  static  unsigned long long aesl_llvm_cbe_1362_count = 0;
  unsigned long long llvm_cbe_tmp__476;
  static  unsigned long long aesl_llvm_cbe_1363_count = 0;
  unsigned long long llvm_cbe_tmp__477;
  static  unsigned long long aesl_llvm_cbe_1364_count = 0;
  static  unsigned long long aesl_llvm_cbe_1365_count = 0;
  static  unsigned long long aesl_llvm_cbe_1366_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec10_count = 0;
  unsigned long long llvm_cbe__2e_rec10;
  unsigned long long llvm_cbe__2e_rec10__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_1367_count = 0;
  signed long long *llvm_cbe_tmp__478;
  static  unsigned long long aesl_llvm_cbe_1368_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec11_count = 0;
  unsigned long long llvm_cbe__2e_rec11;
  static  unsigned long long aesl_llvm_cbe_1369_count = 0;
  static  unsigned long long aesl_llvm_cbe_1370_count = 0;
  static  unsigned long long aesl_llvm_cbe_1371_count = 0;
  static  unsigned long long aesl_llvm_cbe_1372_count = 0;
  static  unsigned long long aesl_llvm_cbe_1373_count = 0;
  static  unsigned long long aesl_llvm_cbe_1374_count = 0;
  static  unsigned long long aesl_llvm_cbe_1375_count = 0;
  static  unsigned long long aesl_llvm_cbe_1376_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum15_count = 0;
  unsigned long long llvm_cbe__2e_sum15;
  static  unsigned long long aesl_llvm_cbe_1377_count = 0;
  signed long long *llvm_cbe_tmp__479;
  static  unsigned long long aesl_llvm_cbe_1378_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec9_count = 0;
  unsigned long long llvm_cbe__2e_rec9;
  static  unsigned long long aesl_llvm_cbe_1379_count = 0;
  static  unsigned long long aesl_llvm_cbe_1380_count = 0;
  static  unsigned long long aesl_llvm_cbe_1381_count = 0;
  unsigned long long llvm_cbe_tmp__480;
  static  unsigned long long aesl_llvm_cbe_1382_count = 0;
  unsigned long long llvm_cbe_tmp__481;
  static  unsigned long long aesl_llvm_cbe_1383_count = 0;
  float *llvm_cbe_tmp__482;
  static  unsigned long long aesl_llvm_cbe_1384_count = 0;
   char *llvm_cbe_tmp__483;
  static  unsigned long long aesl_llvm_cbe_1385_count = 0;
  unsigned long long llvm_cbe_tmp__484;
  static  unsigned long long aesl_llvm_cbe_1386_count = 0;
  unsigned long long llvm_cbe_tmp__485;
  static  unsigned long long aesl_llvm_cbe_1387_count = 0;
  float *llvm_cbe_tmp__486;
  static  unsigned long long aesl_llvm_cbe_1388_count = 0;
   char *llvm_cbe_tmp__487;
  static  unsigned long long aesl_llvm_cbe_1389_count = 0;
   char *llvm_cbe_tmp__488;
  static  unsigned long long aesl_llvm_cbe_1390_count = 0;
  unsigned long long llvm_cbe_tmp__489;
  static  unsigned long long aesl_llvm_cbe_1391_count = 0;
  static  unsigned long long aesl_llvm_cbe_1392_count = 0;
  static  unsigned long long aesl_llvm_cbe_1393_count = 0;
  static  unsigned long long aesl_llvm_cbe_1394_count = 0;
  static  unsigned long long aesl_llvm_cbe_1395_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1396_count = 0;
  static  unsigned long long aesl_llvm_cbe_1397_count = 0;
  unsigned long long llvm_cbe_tmp__490;
  static  unsigned long long aesl_llvm_cbe_1398_count = 0;
  static  unsigned long long aesl_llvm_cbe_1399_count = 0;
  static  unsigned long long aesl_llvm_cbe_1400_count = 0;
  static  unsigned long long aesl_llvm_cbe_1401_count = 0;
  static  unsigned long long aesl_llvm_cbe_1402_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond12_count = 0;
  static  unsigned long long aesl_llvm_cbe_1403_count = 0;
  static  unsigned long long aesl_llvm_cbe_1404_count = 0;
  unsigned long long llvm_cbe_tmp__491;
  static  unsigned long long aesl_llvm_cbe_1405_count = 0;
  static  unsigned long long aesl_llvm_cbe_1406_count = 0;
  static  unsigned long long aesl_llvm_cbe_1407_count = 0;
  static  unsigned long long aesl_llvm_cbe_1408_count = 0;
  static  unsigned long long aesl_llvm_cbe_1409_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond13_count = 0;
  static  unsigned long long aesl_llvm_cbe_1410_count = 0;
  static  unsigned long long aesl_llvm_cbe_1411_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_upsampling3d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 0, !dbg !10 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1305_count);
  llvm_cbe_tmp__450 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !10 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1306_count);
  llvm_cbe_tmp__451 = (unsigned long long )*llvm_cbe_tmp__450;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__451);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 1, !dbg !11 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1309_count);
  llvm_cbe_tmp__452 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !11 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1310_count);
  llvm_cbe_tmp__453 = (unsigned long long )*llvm_cbe_tmp__452;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__453);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 3, i64 2, !dbg !11 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1313_count);
  llvm_cbe_tmp__454 = (signed long long *)(&llvm_cbe_output->field3[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !11 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1314_count);
  llvm_cbe_tmp__455 = (unsigned long long )*llvm_cbe_tmp__454;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__455);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 3, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1317_count);
  llvm_cbe_tmp__456 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i64* %%7, align 8, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1318_count);
  llvm_cbe_tmp__457 = (unsigned long long )*llvm_cbe_tmp__456;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__457);
  if (((llvm_cbe_tmp__451&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge8;
  } else {
    goto llvm_cbe__2e_preheader4_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader4_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [5 x i64]* %%insub, i64 0, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1330_count);
  llvm_cbe_tmp__458 = (signed long long *)(&llvm_cbe_insub[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [5 x i64]* %%insub, i64 0, i64 1, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1331_count);
  llvm_cbe_tmp__459 = (signed long long *)(&llvm_cbe_insub[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i64* %%size, i64 1, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1332_count);
  llvm_cbe_tmp__460 = (signed long long *)(&llvm_cbe_size[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [5 x i64]* %%insub, i64 0, i64 2, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1333_count);
  llvm_cbe_tmp__461 = (signed long long *)(&llvm_cbe_insub[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds i64* %%size, i64 2, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1334_count);
  llvm_cbe_tmp__462 = (signed long long *)(&llvm_cbe_size[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds [5 x i64]* %%insub, i64 0, i64 3, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1335_count);
  llvm_cbe_tmp__463 = (signed long long *)(&llvm_cbe_insub[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [5 x i64]* %%outsub, i64 0, i64 0, !dbg !13 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1336_count);
  llvm_cbe_tmp__464 = (signed long long *)(&llvm_cbe_outsub[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds [5 x i64]* %%outsub, i64 0, i64 1, !dbg !13 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1337_count);
  llvm_cbe_tmp__465 = (signed long long *)(&llvm_cbe_outsub[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [5 x i64]* %%outsub, i64 0, i64 2, !dbg !13 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1338_count);
  llvm_cbe_tmp__466 = (signed long long *)(&llvm_cbe_outsub[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds [5 x i64]* %%outsub, i64 0, i64 3, !dbg !13 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1339_count);
  llvm_cbe_tmp__467 = (signed long long *)(&llvm_cbe_outsub[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 1, !dbg !11 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1340_count);
  llvm_cbe_tmp__468 = (signed long long *)(&llvm_cbe_output->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1341_count);
  llvm_cbe_tmp__469 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 1, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1342_count);
  llvm_cbe_tmp__470 = (signed long long *)(&llvm_cbe_input->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = shl i64 %%8, 2, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1343_count);
  llvm_cbe_tmp__471 = (unsigned long long )llvm_cbe_tmp__457 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__471);
  llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader4;

  do {     /* Syntactic loop '.preheader4' to make GCC happy */
llvm_cbe__2e_preheader4:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = phi i64 [ 0, %%.preheader4.lr.ph ], [ %%51, %%._crit_edge6  for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned long long )llvm_cbe_storemerge7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",llvm_cbe_storemerge7);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__491);
}
  if (((llvm_cbe_tmp__453&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe__2e__crit_edge6:
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = add i64 %%storemerge7, 1, !dbg !13 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1404_count);
  llvm_cbe_tmp__491 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__491&18446744073709551615ull)));
  if (((llvm_cbe_tmp__491&18446744073709551615ULL) == (llvm_cbe_tmp__451&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge8;
  } else {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__491;   /* for PHI node */
    goto llvm_cbe__2e_preheader4;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15 = phi i64 [ %%50, %%._crit_edge ], [ 0, %%.preheader4  for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_storemerge15_count);
  llvm_cbe_storemerge15 = (unsigned long long )llvm_cbe_storemerge15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",llvm_cbe_storemerge15);
printf("\n = 0x%I64X",llvm_cbe_tmp__490);
printf("\n = 0x%I64X",0ull);
}
  if (((llvm_cbe_tmp__455&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = add i64 %%storemerge15, 1, !dbg !13 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1397_count);
  llvm_cbe_tmp__490 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge15&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__490&18446744073709551615ull)));
  if (((llvm_cbe_tmp__490&18446744073709551615ULL) == (llvm_cbe_tmp__453&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__490;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23 = phi i64 [ %%49, %%39 ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_storemerge23_count);
  llvm_cbe_storemerge23 = (unsigned long long )llvm_cbe_storemerge23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",llvm_cbe_storemerge23);
printf("\n = 0x%I64X",llvm_cbe_tmp__489);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i64* %%size, align 8, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1356_count);
  llvm_cbe_tmp__472 = (unsigned long long )*llvm_cbe_size;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__472);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = udiv i64 %%storemerge7, %%26, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1357_count);
  llvm_cbe_tmp__473 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull)) / ((unsigned long long )(llvm_cbe_tmp__472&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__473&18446744073709551615ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 5 && "Write access out of array 'insub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%27, i64* %%12, align 16, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1358_count);
  *llvm_cbe_tmp__458 = llvm_cbe_tmp__473;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__473);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i64* %%14, align 8, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1359_count);
  llvm_cbe_tmp__474 = (unsigned long long )*llvm_cbe_tmp__460;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__474);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = udiv i64 %%storemerge15, %%28, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1360_count);
  llvm_cbe_tmp__475 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_storemerge15&18446744073709551615ull)) / ((unsigned long long )(llvm_cbe_tmp__474&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__475&18446744073709551615ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 5 && "Write access out of array 'insub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%29, i64* %%13, align 8, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1361_count);
  *llvm_cbe_tmp__459 = llvm_cbe_tmp__475;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__475);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i64* %%16, align 8, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1362_count);
  llvm_cbe_tmp__476 = (unsigned long long )*llvm_cbe_tmp__462;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__476);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = udiv i64 %%storemerge23, %%30, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1363_count);
  llvm_cbe_tmp__477 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) / ((unsigned long long )(llvm_cbe_tmp__476&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__477&18446744073709551615ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 5 && "Write access out of array 'insub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%31, i64* %%15, align 16, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1364_count);
  *llvm_cbe_tmp__461 = llvm_cbe_tmp__477;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__477);

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 5 && "Write access out of array 'insub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%17, align 8, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1365_count);
  *llvm_cbe_tmp__463 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
  llvm_cbe__2e_rec10__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__492;

llvm_cbe_tmp__493:
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i64* %%22, align 8, !dbg !11 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1381_count);
  llvm_cbe_tmp__480 = (unsigned long long )*llvm_cbe_tmp__468;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__480);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = call i64 @k2c_sub2idx(i64* %%18, i64* %%1, i64 %%40) nounwind, !dbg !11 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1382_count);
  llvm_cbe_tmp__481 = (unsigned long long )k2c_sub2idx((signed long long *)llvm_cbe_tmp__464, (signed long long *)llvm_cbe_tmp__450, llvm_cbe_tmp__480);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__480);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__481);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%41, !dbg !11 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1383_count);
  llvm_cbe_tmp__482 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__481))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__481));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = bitcast float* %%42 to i8*, !dbg !11 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1384_count);
  llvm_cbe_tmp__483 = ( char *)(( char *)llvm_cbe_tmp__482);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load i64* %%24, align 8, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1385_count);
  llvm_cbe_tmp__484 = (unsigned long long )*llvm_cbe_tmp__470;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__484);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = call i64 @k2c_sub2idx(i64* %%12, i64* %%23, i64 %%44) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1386_count);
  llvm_cbe_tmp__485 = (unsigned long long )k2c_sub2idx((signed long long *)llvm_cbe_tmp__458, (signed long long *)llvm_cbe_tmp__469, llvm_cbe_tmp__484);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__484);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__485);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%45, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1387_count);
  llvm_cbe_tmp__486 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__485))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__485));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = bitcast float* %%46 to i8*, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1388_count);
  llvm_cbe_tmp__487 = ( char *)(( char *)llvm_cbe_tmp__486);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = call i8* @memcpy(i8* %%43, i8* %%47, i64 %%25 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1389_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__483, ( char *)llvm_cbe_tmp__487, llvm_cbe_tmp__471);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__471);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__488);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add i64 %%storemerge23, 1, !dbg !14 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1390_count);
  llvm_cbe_tmp__489 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__489&18446744073709551615ull)));
  if (((llvm_cbe_tmp__489&18446744073709551615ULL) == (llvm_cbe_tmp__455&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__489;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__494:
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ 0, %%35 ], [ %%.rec9, %%36  for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n.rec9 = 0x%I64X",llvm_cbe__2e_rec9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum15 = add i64 %%.rec,  for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe__2e_sum15_count);
  llvm_cbe__2e_sum15 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(4ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum15 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum15&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr [5 x i64]* %%outsub, i64 0, i64 %%.sum1 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1377_count);
  llvm_cbe_tmp__479 = (signed long long *)(&llvm_cbe_outsub[(((signed long long )llvm_cbe__2e_sum15))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum15 = 0x%I64X",((signed long long )llvm_cbe__2e_sum15));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe__2e_sum15) < 5 && "Write access out of array 'outsub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%37, align 8, !dbg !13 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1378_count);
  *llvm_cbe_tmp__479 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec9 = add i64 %%.rec, 1, !dbg !13 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe__2e_rec9_count);
  llvm_cbe__2e_rec9 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec9 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec9&18446744073709551615ull)));
  if (((llvm_cbe__2e_rec&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__493;
  } else {
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec9;   /* for PHI node */
    goto llvm_cbe_tmp__494;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__495:

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 5 && "Write access out of array 'outsub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%storemerge7, i64* %%18, align 16, !dbg !13 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1372_count);
  *llvm_cbe_tmp__464 = llvm_cbe_storemerge7;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge7 = 0x%I64X\n", llvm_cbe_storemerge7);

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 5 && "Write access out of array 'outsub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%storemerge15, i64* %%19, align 8, !dbg !13 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1373_count);
  *llvm_cbe_tmp__465 = llvm_cbe_storemerge15;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge15 = 0x%I64X\n", llvm_cbe_storemerge15);

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 5 && "Write access out of array 'outsub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%storemerge23, i64* %%20, align 16, !dbg !13 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1374_count);
  *llvm_cbe_tmp__466 = llvm_cbe_storemerge23;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge23 = 0x%I64X\n", llvm_cbe_storemerge23);

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 5 && "Write access out of array 'outsub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%21, align 8, !dbg !13 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1375_count);
  *llvm_cbe_tmp__467 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__494;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__492:
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec10 = phi i64 [ 0, %%.lr.ph ], [ %%.rec11, %%32  for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe__2e_rec10_count);
  llvm_cbe__2e_rec10 = (unsigned long long )llvm_cbe__2e_rec10__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec10 = 0x%I64X",llvm_cbe__2e_rec10);
printf("\n = 0x%I64X",0ull);
printf("\n.rec11 = 0x%I64X",llvm_cbe__2e_rec11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%.rec10,  for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec10&18446744073709551615ull)) + ((unsigned long long )(4ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr [5 x i64]* %%insub, i64 0, i64 %%.su for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1367_count);
  llvm_cbe_tmp__478 = (signed long long *)(&llvm_cbe_insub[(((signed long long )llvm_cbe__2e_sum))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe__2e_sum) < 5 && "Write access out of array 'insub' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%33, align 8, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe_1368_count);
  *llvm_cbe_tmp__478 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec11 = add i64 %%.rec10, 1, !dbg !12 for 0x%I64xth hint within @k2c_upsampling3d  --> \n", ++aesl_llvm_cbe__2e_rec11_count);
  llvm_cbe__2e_rec11 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec10&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec11 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec11&18446744073709551615ull)));
  if (((llvm_cbe__2e_rec10&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__495;
  } else {
    llvm_cbe__2e_rec10__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec11;   /* for PHI node */
    goto llvm_cbe_tmp__492;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '.preheader4' */
llvm_cbe__2e__crit_edge8:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_upsampling3d}\n");
  return;
}

