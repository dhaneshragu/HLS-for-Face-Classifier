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
void k2c_lstmcell(float *llvm_cbe_state, float *llvm_cbe_input, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_recurrent_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, float *llvm_cbe_fwork, void  (*llvm_cbe_recurrent_activation) (float *, unsigned long long ), void  (*llvm_cbe_output_activation) (float *, unsigned long long ));
signed int k2c_affine_matmul();
void k2c_lstm(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, float *llvm_cbe_state, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_recurrent_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, float *llvm_cbe_fwork, signed int llvm_cbe_go_backwards, signed int llvm_cbe_return_sequences, void  (*llvm_cbe_recurrent_activation) (float *, unsigned long long ), void  (*llvm_cbe_output_activation) (float *, unsigned long long ));
void k2c_simpleRNNcell(float *llvm_cbe_state, float *llvm_cbe_input, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_recurrent_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, float *llvm_cbe_fwork, void  (*llvm_cbe_output_activation) (float *, unsigned long long ));
void k2c_simpleRNN(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, float *llvm_cbe_state, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_recurrent_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, float *llvm_cbe_fwork, signed int llvm_cbe_go_backwards, signed int llvm_cbe_return_sequences, void  (*llvm_cbe_output_activation) (float *, unsigned long long ));
void k2c_grucell(float *llvm_cbe_state, float *llvm_cbe_input, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_recurrent_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, float *llvm_cbe_fwork, signed int llvm_cbe_reset_after, void  (*llvm_cbe_recurrent_activation) (float *, unsigned long long ), void  (*llvm_cbe_output_activation) (float *, unsigned long long ));
void k2c_gru(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, float *llvm_cbe_state, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_recurrent_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, float *llvm_cbe_fwork, signed int llvm_cbe_reset_after, signed int llvm_cbe_go_backwards, signed int llvm_cbe_return_sequences, void  (*llvm_cbe_recurrent_activation) (float *, unsigned long long ), void  (*llvm_cbe_output_activation) (float *, unsigned long long ));


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

void k2c_lstmcell(float *llvm_cbe_state, float *llvm_cbe_input, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_recurrent_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, float *llvm_cbe_fwork, void  (*llvm_cbe_recurrent_activation) (float *, unsigned long long ), void  (*llvm_cbe_output_activation) (float *, unsigned long long )) {
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
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  signed long long *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned long long llvm_cbe_tmp__2;
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
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  signed long long *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  float *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  float *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  float *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  float *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  float *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  float *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  float *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  unsigned long long llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  float *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  float *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  float *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  float *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  float *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  float *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  float *llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  float *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  unsigned long long llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  float *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  unsigned long long llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  float *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned long long llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  float *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  float *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  unsigned int llvm_cbe_tmp__45;
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
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned long long llvm_cbe_storemerge14;
  unsigned long long llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum5_count = 0;
  unsigned long long llvm_cbe__2e_sum5;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  float *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  float llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe__2e_sum6_count = 0;
  unsigned long long llvm_cbe__2e_sum6;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  float *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  float llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  float llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe__2e_sum7_count = 0;
  unsigned long long llvm_cbe__2e_sum7;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  float *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  float llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe__2e_sum8_count = 0;
  unsigned long long llvm_cbe__2e_sum8;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  float *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  float llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  float llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  float llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  unsigned long long llvm_cbe_tmp__57;
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
  static  unsigned long long aesl_llvm_cbe_exitcond19_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  unsigned int llvm_cbe_tmp__58;
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
  unsigned int llvm_cbe_tmp__59;
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
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge110_count = 0;
  unsigned long long llvm_cbe_storemerge110;
  unsigned long long llvm_cbe_storemerge110__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum4_count = 0;
  unsigned long long llvm_cbe__2e_sum4;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  float *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  float llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  float *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  unsigned long long llvm_cbe_tmp__64;
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
  static  unsigned long long aesl_llvm_cbe_exitcond18_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge29_count = 0;
  unsigned long long llvm_cbe_storemerge29;
  unsigned long long llvm_cbe_storemerge29__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  float *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  float llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe__2e_sum3_count = 0;
  unsigned long long llvm_cbe__2e_sum3;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  float *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  float llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  float llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  float *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  unsigned long long llvm_cbe_tmp__71;
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
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_lstmcell\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 3, i64 1, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__1 = (signed long long *)(&llvm_cbe_recurrent_kernel->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__2 = (unsigned long long )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__3 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !12 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__4 = (unsigned long long )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = lshr i64 %%4, 2, !dbg !12 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__5 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__4&18446744073709551615ull)) >> ((unsigned long long )(2ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__5&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 0, i64 0, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__6 = (float *)(&llvm_cbe_kernel->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = mul i64 %%5, %%2, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__7 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__5&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__7&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 0, i64 %%7, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__8 = (float *)(&llvm_cbe_kernel->field0[(((signed long long )llvm_cbe_tmp__7))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__7));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = lshr i64 %%4, 1, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__9 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__4&18446744073709551615ull)) >> ((unsigned long long )(1ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = and i64 %%9, 9223372036854775806, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__10 = (unsigned long long )llvm_cbe_tmp__9 & 9223372036854775806ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = mul i64 %%10, %%2, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__11 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__10&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__11&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 0, i64 %%11, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__12 = (float *)(&llvm_cbe_kernel->field0[(((signed long long )llvm_cbe_tmp__11))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__11));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = mul i64 %%2, 3, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__13 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull)) * ((unsigned long long )(3ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__13&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = mul i64 %%13, %%5, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__14 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__13&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__5&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__14&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 0, i64 %%14, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__15 = (float *)(&llvm_cbe_kernel->field0[(((signed long long )llvm_cbe_tmp__14))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__14));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 0, i64 0, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__16 = (float *)(&llvm_cbe_recurrent_kernel->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = mul i64 %%2, %%2, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__17 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__17&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 0, i64 %%17, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__18 = (float *)(&llvm_cbe_recurrent_kernel->field0[(((signed long long )llvm_cbe_tmp__17))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__17));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = shl i64 %%2, 1, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__19 = (unsigned long long )llvm_cbe_tmp__2 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = mul i64 %%19, %%2, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__20 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__19&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__20&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 0, i64 %%20, !dbg !13 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__21 = (float *)(&llvm_cbe_recurrent_kernel->field0[(((signed long long )llvm_cbe_tmp__20))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__20));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = mul i64 %%13, %%2, !dbg !14 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__22 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__13&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__22&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 0, i64 %%22, !dbg !14 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__23 = (float *)(&llvm_cbe_recurrent_kernel->field0[(((signed long long )llvm_cbe_tmp__22))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__22));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.k2c_tensor* %%bias, i64 0, i32 0, i64 0, !dbg !14 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__24 = (float *)(&llvm_cbe_bias->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.k2c_tensor* %%bias, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__25 = (float *)(&llvm_cbe_bias->field0[(((signed long long )llvm_cbe_tmp__2))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.k2c_tensor* %%bias, i64 0, i32 0, i64 %%19, !dbg !14 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__26 = (float *)(&llvm_cbe_bias->field0[(((signed long long )llvm_cbe_tmp__19))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__19));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.k2c_tensor* %%bias, i64 0, i32 0, i64 %%13, !dbg !14 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__27 = (float *)(&llvm_cbe_bias->field0[(((signed long long )llvm_cbe_tmp__13))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__13));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds float* %%fwork, i64 %%2, !dbg !15 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__28 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__2))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds float* %%fwork, i64 %%19, !dbg !15 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__29 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__19))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__19));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds float* %%fwork, i64 %%13, !dbg !15 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__30 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__13))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__13));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = shl i64 %%2, 2, !dbg !15 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__31 = (unsigned long long )llvm_cbe_tmp__2 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds float* %%fwork, i64 %%31, !dbg !15 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__32 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__31))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__31));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = mul i64 %%2, 5, !dbg !15 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__33 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull)) * ((unsigned long long )(5ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__33&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds float* %%fwork, i64 %%33, !dbg !15 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__34 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__33))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__33));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = mul i64 %%2, 6, !dbg !15 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__35 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull)) * ((unsigned long long )(6ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__35&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds float* %%fwork, i64 %%35, !dbg !15 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__36 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__35))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__35));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = mul i64 %%2, 7, !dbg !15 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_188_count);
  llvm_cbe_tmp__37 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull)) * ((unsigned long long )(7ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__37&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds float* %%fwork, i64 %%37, !dbg !15 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__38 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__37))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__37));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%fwork, float* %%input, float* %%6, float* %%24, i64 1, i64 %%2, i64 %%5) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_194_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_fwork, (float *)llvm_cbe_input, (float *)llvm_cbe_tmp__6, (float *)llvm_cbe_tmp__24, 1ull, llvm_cbe_tmp__2, llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__5);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%28, float* %%input, float* %%8, float* %%25, i64 1, i64 %%2, i64 %%5) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_195_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__28, (float *)llvm_cbe_input, (float *)llvm_cbe_tmp__8, (float *)llvm_cbe_tmp__25, 1ull, llvm_cbe_tmp__2, llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__5);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__40);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%29, float* %%input, float* %%12, float* %%26, i64 1, i64 %%2, i64 %%5) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_196_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__29, (float *)llvm_cbe_input, (float *)llvm_cbe_tmp__12, (float *)llvm_cbe_tmp__26, 1ull, llvm_cbe_tmp__2, llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__5);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__41);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%30, float* %%input, float* %%15, float* %%27, i64 1, i64 %%2, i64 %%5) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_197_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__30, (float *)llvm_cbe_input, (float *)llvm_cbe_tmp__15, (float *)llvm_cbe_tmp__27, 1ull, llvm_cbe_tmp__2, llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__5);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%32, float* %%state, float* %%16, float* %%fwork, i64 1, i64 %%2, i64 %%2) nounwind, !dbg !16 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_198_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__32, (float *)llvm_cbe_state, (float *)llvm_cbe_tmp__16, (float *)llvm_cbe_fwork, 1ull, llvm_cbe_tmp__2, llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__43);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%recurrent_activation(float* %%32, i64 %%2) nounwind, !dbg !15 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_199_count);
   /*tail*/ llvm_cbe_recurrent_activation((float *)llvm_cbe_tmp__32, llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%34, float* %%state, float* %%18, float* %%28, i64 1, i64 %%2, i64 %%2) nounwind, !dbg !16 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_200_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__34, (float *)llvm_cbe_state, (float *)llvm_cbe_tmp__18, (float *)llvm_cbe_tmp__28, 1ull, llvm_cbe_tmp__2, llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__44);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%recurrent_activation(float* %%34, i64 %%2) nounwind, !dbg !16 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_201_count);
   /*tail*/ llvm_cbe_recurrent_activation((float *)llvm_cbe_tmp__34, llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%36, float* %%state, float* %%21, float* %%29, i64 1, i64 %%2, i64 %%2) nounwind, !dbg !16 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_202_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__36, (float *)llvm_cbe_state, (float *)llvm_cbe_tmp__21, (float *)llvm_cbe_tmp__29, 1ull, llvm_cbe_tmp__2, llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__45);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%output_activation(float* %%36, i64 %%2) nounwind, !dbg !16 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_203_count);
   /*tail*/ llvm_cbe_output_activation((float *)llvm_cbe_tmp__36, llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
}
  if (((llvm_cbe_tmp__2&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge13_2e_thread_2e_critedge;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph16;
  }

  do {     /* Syntactic loop '.lr.ph16' to make GCC happy */
llvm_cbe__2e_lr_2e_ph16:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i64 [ %%58, %%.lr.ph16 ], [ 0, %%0  for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned long long )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%I64X",llvm_cbe_storemerge14);
printf("\n = 0x%I64X",llvm_cbe_tmp__57);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum5 = add i64 %%storemerge14, %%33, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe__2e_sum5_count);
  llvm_cbe__2e_sum5 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__33&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum5 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum5&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds float* %%fwork, i64 %%.sum5, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_223_count);
  llvm_cbe_tmp__46 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum5))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum5 = 0x%I64X",((signed long long )llvm_cbe__2e_sum5));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load float* %%47, align 4, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_224_count);
  llvm_cbe_tmp__47 = (float )*llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__47, *(int*)(&llvm_cbe_tmp__47));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum6 = add i64 %%storemerge14, %%2, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe__2e_sum6_count);
  llvm_cbe__2e_sum6 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum6 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum6&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds float* %%state, i64 %%.sum6, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_225_count);
  llvm_cbe_tmp__48 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe__2e_sum6))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum6 = 0x%I64X",((signed long long )llvm_cbe__2e_sum6));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load float* %%49, align 4, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__49 = (float )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__49, *(int*)(&llvm_cbe_tmp__49));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = fmul float %%48, %%50, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__50 = (float )((float )(llvm_cbe_tmp__47 * llvm_cbe_tmp__49));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__50, *(int*)(&llvm_cbe_tmp__50));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum7 = add i64 %%storemerge14, %%31, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe__2e_sum7_count);
  llvm_cbe__2e_sum7 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__31&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum7 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum7&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = getelementptr inbounds float* %%fwork, i64 %%.sum7, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__51 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum7))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum7 = 0x%I64X",((signed long long )llvm_cbe__2e_sum7));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = load float* %%52, align 4, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__52 = (float )*llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__52, *(int*)(&llvm_cbe_tmp__52));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum8 = add i64 %%storemerge14, %%35, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe__2e_sum8_count);
  llvm_cbe__2e_sum8 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__35&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum8 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum8&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = getelementptr inbounds float* %%fwork, i64 %%.sum8, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_230_count);
  llvm_cbe_tmp__53 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum8))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum8 = 0x%I64X",((signed long long )llvm_cbe__2e_sum8));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = load float* %%54, align 4, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_231_count);
  llvm_cbe_tmp__54 = (float )*llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__54, *(int*)(&llvm_cbe_tmp__54));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = fmul float %%53, %%55, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_232_count);
  llvm_cbe_tmp__55 = (float )((float )(llvm_cbe_tmp__52 * llvm_cbe_tmp__54));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__55, *(int*)(&llvm_cbe_tmp__55));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = fadd float %%51, %%56, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_233_count);
  llvm_cbe_tmp__56 = (float )((float )(llvm_cbe_tmp__50 + llvm_cbe_tmp__55));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__56, *(int*)(&llvm_cbe_tmp__56));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%57, float* %%54, align 4, !dbg !19 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_234_count);
  *llvm_cbe_tmp__53 = llvm_cbe_tmp__56;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add i64 %%storemerge14, 1, !dbg !20 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_235_count);
  llvm_cbe_tmp__57 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__57&18446744073709551615ull)));
  if (((llvm_cbe_tmp__57&18446744073709551615ULL) == (llvm_cbe_tmp__2&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge17;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__57;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph16;
  }

  } while (1); /* end of syntactic loop '.lr.ph16' */
llvm_cbe__2e__crit_edge17:
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%38, float* %%state, float* %%23, float* %%30, i64 1, i64 %%2, i64 %%2) nounwind, !dbg !17 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_254_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__38, (float *)llvm_cbe_state, (float *)llvm_cbe_tmp__23, (float *)llvm_cbe_tmp__30, 1ull, llvm_cbe_tmp__2, llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__58);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%recurrent_activation(float* %%38, i64 %%2) nounwind, !dbg !16 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_255_count);
   /*tail*/ llvm_cbe_recurrent_activation((float *)llvm_cbe_tmp__38, llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
}
  if (((llvm_cbe_tmp__2&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge13_2e_thread;
  } else {
    llvm_cbe_storemerge110__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph12;
  }

llvm_cbe__2e__crit_edge13_2e_thread_2e_critedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%38, float* %%state, float* %%23, float* %%30, i64 1, i64 %%2, i64 %%2) nounwind, !dbg !17 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_274_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__38, (float *)llvm_cbe_state, (float *)llvm_cbe_tmp__23, (float *)llvm_cbe_tmp__30, 1ull, llvm_cbe_tmp__2, llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__59);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%recurrent_activation(float* %%38, i64 %%2) nounwind, !dbg !16 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_275_count);
   /*tail*/ llvm_cbe_recurrent_activation((float *)llvm_cbe_tmp__38, llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
}
  goto llvm_cbe__2e__crit_edge13_2e_thread;

llvm_cbe__2e__crit_edge13_2e_thread:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%output_activation(float* %%36, i64 %%2) nounwind, !dbg !16 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_294_count);
   /*tail*/ llvm_cbe_output_activation((float *)llvm_cbe_tmp__36, llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
}
  goto llvm_cbe__2e__crit_edge;

  do {     /* Syntactic loop '.lr.ph12' to make GCC happy */
llvm_cbe__2e_lr_2e_ph12:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge110 = phi i64 [ %%65, %%.lr.ph12 ], [ 0, %%._crit_edge17  for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_storemerge110_count);
  llvm_cbe_storemerge110 = (unsigned long long )llvm_cbe_storemerge110__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge110 = 0x%I64X",llvm_cbe_storemerge110);
printf("\n = 0x%I64X",llvm_cbe_tmp__64);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum4 = add i64 %%storemerge110, %%35, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe__2e_sum4_count);
  llvm_cbe__2e_sum4 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge110&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__35&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum4 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum4&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds float* %%fwork, i64 %%.sum4, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__60 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum4))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum4 = 0x%I64X",((signed long long )llvm_cbe__2e_sum4));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = load float* %%61, align 4, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__61 = (float )*llvm_cbe_tmp__60;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__61, *(int*)(&llvm_cbe_tmp__61));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = add i64 %%storemerge110, %%2, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__62 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge110&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__62&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds float* %%state, i64 %%63, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_316_count);
  llvm_cbe_tmp__63 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_tmp__62))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__62));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%62, float* %%64, align 4, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_317_count);
  *llvm_cbe_tmp__63 = llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = add i64 %%storemerge110, 1, !dbg !20 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__64 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge110&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__64&18446744073709551615ull)));
  if (((llvm_cbe_tmp__64&18446744073709551615ULL) == (llvm_cbe_tmp__2&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge13;
  } else {
    llvm_cbe_storemerge110__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__64;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph12;
  }

  } while (1); /* end of syntactic loop '.lr.ph12' */
llvm_cbe__2e__crit_edge13:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%output_activation(float* %%36, i64 %%2) nounwind, !dbg !16 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_337_count);
   /*tail*/ llvm_cbe_output_activation((float *)llvm_cbe_tmp__36, llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__2);
}
  if (((llvm_cbe_tmp__2&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge29__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge29 = phi i64 [ %%72, %%.lr.ph ], [ 0, %%._crit_edge13  for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_storemerge29_count);
  llvm_cbe_storemerge29 = (unsigned long long )llvm_cbe_storemerge29__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge29 = 0x%I64X",llvm_cbe_storemerge29);
printf("\n = 0x%I64X",llvm_cbe_tmp__71);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%storemerge29, %%37, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge29&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__37&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = getelementptr inbounds float* %%fwork, i64 %%.sum, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_356_count);
  llvm_cbe_tmp__65 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = load float* %%66, align 4, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__66 = (float )*llvm_cbe_tmp__65;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__66, *(int*)(&llvm_cbe_tmp__66));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum3 = add i64 %%storemerge29, %%35, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe__2e_sum3_count);
  llvm_cbe__2e_sum3 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge29&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__35&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum3 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum3&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = getelementptr inbounds float* %%fwork, i64 %%.sum3, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__67 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum3))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum3 = 0x%I64X",((signed long long )llvm_cbe__2e_sum3));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = load float* %%68, align 4, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_359_count);
  llvm_cbe_tmp__68 = (float )*llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__68, *(int*)(&llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = fmul float %%67, %%69, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_360_count);
  llvm_cbe_tmp__69 = (float )((float )(llvm_cbe_tmp__66 * llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__69, *(int*)(&llvm_cbe_tmp__69));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds float* %%state, i64 %%storemerge29, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_361_count);
  llvm_cbe_tmp__70 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge29))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge29 = 0x%I64X",((signed long long )llvm_cbe_storemerge29));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%70, float* %%71, align 4, !dbg !11 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_362_count);
  *llvm_cbe_tmp__70 = llvm_cbe_tmp__69;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = add i64 %%storemerge29, 1, !dbg !20 for 0x%I64xth hint within @k2c_lstmcell  --> \n", ++aesl_llvm_cbe_363_count);
  llvm_cbe_tmp__71 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge29&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__71&18446744073709551615ull)));
  if (((llvm_cbe_tmp__71&18446744073709551615ULL) == (llvm_cbe_tmp__2&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge29__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__71;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_lstmcell}\n");
  return;
}


void k2c_lstm(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, float *llvm_cbe_state, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_recurrent_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, float *llvm_cbe_fwork, signed int llvm_cbe_go_backwards, signed int llvm_cbe_return_sequences, void  (*llvm_cbe_recurrent_activation) (float *, unsigned long long ), void  (*llvm_cbe_output_activation) (float *, unsigned long long )) {
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
  signed long long *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  unsigned long long llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  signed long long *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  unsigned long long llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  signed long long *llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  unsigned long long llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge12_2e_us_2e_us;
  unsigned long long llvm_cbe_storemerge12_2e_us_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  float *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  unsigned long long llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge12_2e_us;
  unsigned long long llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  unsigned long long llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  float *llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  unsigned long long llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond30_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  unsigned long long llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond29_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge28_2e_us15_count = 0;
  unsigned long long llvm_cbe_storemerge28_2e_us15;
  unsigned long long llvm_cbe_storemerge28_2e_us15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  float *llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  float llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  unsigned long long llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  float *llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  unsigned long long llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond28_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us14_count = 0;
  unsigned long long llvm_cbe_storemerge12_2e_us14;
  unsigned long long llvm_cbe_storemerge12_2e_us14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  unsigned long long llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  float *llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  unsigned long long llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  unsigned int llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_storemerge325_count = 0;
  unsigned int llvm_cbe_storemerge325;
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
  unsigned long long llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge326_count = 0;
  unsigned int llvm_cbe_storemerge326;
  unsigned int llvm_cbe_storemerge326__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  unsigned long long llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  unsigned long long llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  float *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  unsigned long long llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  unsigned long long llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge422_count = 0;
  unsigned long long llvm_cbe_storemerge422;
  unsigned long long llvm_cbe_storemerge422__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  float *llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  float llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  unsigned long long llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  float *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond33_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  unsigned long long llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  float *llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  unsigned long long llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond32_count = 0;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_count = 0;
  unsigned long long llvm_cbe_storemerge15;
  unsigned long long llvm_cbe_storemerge15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  float *llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  float llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  float *llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  unsigned long long llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond31_count = 0;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_lstm\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 0, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_423_count);
  llvm_cbe_tmp__72 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_424_count);
  llvm_cbe_tmp__73 = (unsigned long long )*llvm_cbe_tmp__72;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_429_count);
  llvm_cbe_tmp__74 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_430_count);
  llvm_cbe_tmp__75 = (unsigned long long )*llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 3, i64 1, !dbg !14 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_434_count);
  llvm_cbe_tmp__76 = (signed long long *)(&llvm_cbe_recurrent_kernel->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !14 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_435_count);
  llvm_cbe_tmp__77 = (unsigned long long )*llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__77);
  if (((llvm_cbe_go_backwards&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_preheader10;
  } else {
    goto llvm_cbe_tmp__112;
  }

llvm_cbe__2e_preheader10:
  if (((llvm_cbe_tmp__73&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit11;
  } else {
    goto llvm_cbe__2e_lr_2e_ph13;
  }

llvm_cbe__2e_lr_2e_ph13:
  if (((llvm_cbe_return_sequences&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_lr_2e_ph13_2e_split_2e_us;
  } else {
    goto llvm_cbe__2e_lr_2e_ph13_2e__2e_lr_2e_ph13_2e_split_crit_edge;
  }

llvm_cbe__2e_lr_2e_ph13_2e__2e_lr_2e_ph13_2e_split_crit_edge:
  if (((llvm_cbe_tmp__77&18446744073709551615ULL) != (0ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge12_2e_us14__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph9_2e_us18;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe_tmp__113;
  }

llvm_cbe__2e_lr_2e_ph13_2e_split_2e_us:
  if (((llvm_cbe_tmp__77&18446744073709551615ULL) != (0ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge12_2e_us_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe_tmp__114;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe_tmp__115;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__114:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us.us = phi i64 [ %%14, %%11 ], [ 0, %%.lr.ph13.split.us  for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_2e_us_count);
  llvm_cbe_storemerge12_2e_us_2e_us = (unsigned long long )llvm_cbe_storemerge12_2e_us_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us.us = 0x%I64X",llvm_cbe_storemerge12_2e_us_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__80);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = mul i64 %%storemerge12.us.us, %%4, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_455_count);
  llvm_cbe_tmp__78 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12_2e_us_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__75&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__78&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%12, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_456_count);
  llvm_cbe_tmp__79 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__78))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__78));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @k2c_lstmcell(float* %%state, float* %%13, %%struct.k2c_tensor* %%kernel, %%struct.k2c_tensor* %%recurrent_kernel, %%struct.k2c_tensor* %%bias, float* %%fwork, void (float*, i64)* %%recurrent_activation, void (float*, i64)* %%output_activation), !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_457_count);
   /*tail*/ k2c_lstmcell((float *)llvm_cbe_state, (float *)llvm_cbe_tmp__79, (l_struct_OC_k2c_tensor *)llvm_cbe_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_recurrent_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_bias, (float *)llvm_cbe_fwork, llvm_cbe_recurrent_activation, llvm_cbe_output_activation);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add i64 %%storemerge12.us.us, 1, !dbg !17 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_458_count);
  llvm_cbe_tmp__80 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12_2e_us_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__80&18446744073709551615ull)));
  if (((llvm_cbe_tmp__80&18446744073709551615ULL) == (llvm_cbe_tmp__73&18446744073709551615ULL))) {
    goto llvm_cbe__2e__2e_loopexit11_crit_edge_2e_us_2d_lcssa_2e_us;
  } else {
    llvm_cbe_storemerge12_2e_us_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__80;   /* for PHI node */
    goto llvm_cbe_tmp__114;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__115:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i64 [ %%18, %%15 ], [ 0, %%.lr.ph13.split.us  for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned long long )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%I64X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__83);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = mul i64 %%storemerge12.us, %%4, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_465_count);
  llvm_cbe_tmp__81 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__75&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__81&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%16, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_466_count);
  llvm_cbe_tmp__82 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__81))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__81));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @k2c_lstmcell(float* %%state, float* %%17, %%struct.k2c_tensor* %%kernel, %%struct.k2c_tensor* %%recurrent_kernel, %%struct.k2c_tensor* %%bias, float* %%fwork, void (float*, i64)* %%recurrent_activation, void (float*, i64)* %%output_activation), !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_467_count);
   /*tail*/ k2c_lstmcell((float *)llvm_cbe_state, (float *)llvm_cbe_tmp__82, (l_struct_OC_k2c_tensor *)llvm_cbe_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_recurrent_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_bias, (float *)llvm_cbe_fwork, llvm_cbe_recurrent_activation, llvm_cbe_output_activation);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i64 %%storemerge12.us, 1, !dbg !17 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_468_count);
  llvm_cbe_tmp__83 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__83&18446744073709551615ull)));
  if (((llvm_cbe_tmp__83&18446744073709551615ULL) == (llvm_cbe_tmp__73&18446744073709551615ULL))) {
    goto llvm_cbe__2e__2e_loopexit11_crit_edge_2e_us_2d_lcssa_2e_us;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__83;   /* for PHI node */
    goto llvm_cbe_tmp__115;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__2e_loopexit11_crit_edge_2e_us_2d_lcssa_2e_us:
  goto llvm_cbe__2e__2e_loopexit11_crit_edge;

  do {     /* Syntactic loop '.lr.ph9.us18' to make GCC happy */
llvm_cbe__2e_lr_2e_ph9_2e_us18:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us14 = phi i64 [ %%19, %%..loopexit7_crit_edge.us19 ], [ 0, %%.lr.ph13..lr.ph13.split_crit_edge  for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us14_count);
  llvm_cbe_storemerge12_2e_us14 = (unsigned long long )llvm_cbe_storemerge12_2e_us14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us14 = 0x%I64X",llvm_cbe_storemerge12_2e_us14);
printf("\n = 0x%I64X",llvm_cbe_tmp__84);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = mul i64 %%storemerge12.us14, %%4, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_495_count);
  llvm_cbe_tmp__90 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12_2e_us14&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__75&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__90&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%26, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_496_count);
  llvm_cbe_tmp__91 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__90))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__90));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @k2c_lstmcell(float* %%state, float* %%27, %%struct.k2c_tensor* %%kernel, %%struct.k2c_tensor* %%recurrent_kernel, %%struct.k2c_tensor* %%bias, float* %%fwork, void (float*, i64)* %%recurrent_activation, void (float*, i64)* %%output_activation), !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_497_count);
   /*tail*/ k2c_lstmcell((float *)llvm_cbe_state, (float *)llvm_cbe_tmp__91, (l_struct_OC_k2c_tensor *)llvm_cbe_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_recurrent_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_bias, (float *)llvm_cbe_fwork, llvm_cbe_recurrent_activation, llvm_cbe_output_activation);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = mul i64 %%storemerge12.us14, %%6, !dbg !12 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_502_count);
  llvm_cbe_tmp__92 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12_2e_us14&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__77&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__92&18446744073709551615ull)));
  llvm_cbe_storemerge28_2e_us15__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__116;

llvm_cbe__2e__2e_loopexit7_crit_edge_2e_us19:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%storemerge12.us14, 1, !dbg !17 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_476_count);
  llvm_cbe_tmp__84 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12_2e_us14&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__84&18446744073709551615ull)));
  if (((llvm_cbe_tmp__84&18446744073709551615ULL) == (llvm_cbe_tmp__73&18446744073709551615ULL))) {
    goto llvm_cbe__2e__2e_loopexit11_crit_edge_2e_us_2d_lcssa;
  } else {
    llvm_cbe_storemerge12_2e_us14__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__84;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph9_2e_us18;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__116:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge28.us15 = phi i64 [ 0, %%.lr.ph9.us18 ], [ %%25, %%20  for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_storemerge28_2e_us15_count);
  llvm_cbe_storemerge28_2e_us15 = (unsigned long long )llvm_cbe_storemerge28_2e_us15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge28.us15 = 0x%I64X",llvm_cbe_storemerge28_2e_us15);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__89);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds float* %%state, i64 %%storemerge28.us15, !dbg !12 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_483_count);
  llvm_cbe_tmp__85 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge28_2e_us15))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge28.us15 = 0x%I64X",((signed long long )llvm_cbe_storemerge28_2e_us15));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load float* %%21, align 4, !dbg !12 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_484_count);
  llvm_cbe_tmp__86 = (float )*llvm_cbe_tmp__85;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__86, *(int*)(&llvm_cbe_tmp__86));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add i64 %%storemerge28.us15, %%28, !dbg !12 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_485_count);
  llvm_cbe_tmp__87 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge28_2e_us15&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__92&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__87&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%23, !dbg !12 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_486_count);
  llvm_cbe_tmp__88 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__87))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__87));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%22, float* %%24, align 4, !dbg !12 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_487_count);
  *llvm_cbe_tmp__88 = llvm_cbe_tmp__86;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i64 %%storemerge28.us15, 1, !dbg !17 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_488_count);
  llvm_cbe_tmp__89 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge28_2e_us15&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__89&18446744073709551615ull)));
  if (((llvm_cbe_tmp__89&18446744073709551615ULL) == (llvm_cbe_tmp__77&18446744073709551615ULL))) {
    goto llvm_cbe__2e__2e_loopexit7_crit_edge_2e_us19;
  } else {
    llvm_cbe_storemerge28_2e_us15__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__89;   /* for PHI node */
    goto llvm_cbe_tmp__116;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph9.us18' */
llvm_cbe_tmp__112:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = trunc i64 %%2 to i32, !dbg !16 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_504_count);
  llvm_cbe_tmp__93 = (unsigned int )((unsigned int )llvm_cbe_tmp__73&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__93);
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge325 = add i32 %%30, -1, !dbg !16 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_storemerge325_count);
  llvm_cbe_storemerge325 = (unsigned int )((unsigned int )(llvm_cbe_tmp__93&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge325 = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge325&4294967295ull)));
  if ((((signed int )llvm_cbe_storemerge325) > ((signed int )4294967295u))) {
    goto llvm_cbe__2e_lr_2e_ph27;
  } else {
    goto llvm_cbe__2e_loopexit24;
  }

llvm_cbe__2e_lr_2e_ph27:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add i64 %%2, -1, !dbg !11 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_514_count);
  llvm_cbe_tmp__94 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__73&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__94&18446744073709551615ull)));
  llvm_cbe_storemerge326__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge325;   /* for PHI node */
  goto llvm_cbe_tmp__117;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__117:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge326 = phi i32 [ %%storemerge325, %%.lr.ph27 ], [ %%storemerge3, %%47  for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_storemerge326_count);
  llvm_cbe_storemerge326 = (unsigned int )llvm_cbe_storemerge326__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge326 = 0x%X",llvm_cbe_storemerge326);
printf("\nstoremerge325 = 0x%X",llvm_cbe_storemerge325);
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sext i32 %%storemerge326 to i64, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_516_count);
  llvm_cbe_tmp__95 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge326);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__95);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = mul i64 %%36, %%4, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_517_count);
  llvm_cbe_tmp__96 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__95&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__75&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%37, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_518_count);
  llvm_cbe_tmp__97 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__96))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__96));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @k2c_lstmcell(float* %%state, float* %%38, %%struct.k2c_tensor* %%kernel, %%struct.k2c_tensor* %%recurrent_kernel, %%struct.k2c_tensor* %%bias, float* %%fwork, void (float*, i64)* %%recurrent_activation, void (float*, i64)* %%output_activation), !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_519_count);
   /*tail*/ k2c_lstmcell((float *)llvm_cbe_state, (float *)llvm_cbe_tmp__97, (l_struct_OC_k2c_tensor *)llvm_cbe_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_recurrent_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_bias, (float *)llvm_cbe_fwork, llvm_cbe_recurrent_activation, llvm_cbe_output_activation);
if (AESL_DEBUG_TRACE) {
}
  if (((llvm_cbe_return_sequences&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__118;
  } else {
    goto llvm_cbe__2e_preheader20;
  }

llvm_cbe_tmp__118:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = add i32 %%storemerge326, -1, !dbg !16 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )((unsigned int )(llvm_cbe_storemerge326&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge3 = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge3&4294967295ull)));
  if ((((signed int )llvm_cbe_storemerge3) > ((signed int )4294967295u))) {
    llvm_cbe_storemerge326__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge3;   /* for PHI node */
    goto llvm_cbe_tmp__117;
  } else {
    goto llvm_cbe__2e_loopexit24;
  }

llvm_cbe__2e_loopexit21:
  goto llvm_cbe_tmp__118;

llvm_cbe__2e_preheader20:
  if (((llvm_cbe_tmp__77&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit21;
  } else {
    goto llvm_cbe__2e_lr_2e_ph23;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__119:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge422 = phi i64 [ 0, %%.lr.ph23 ], [ %%46, %%41  for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_storemerge422_count);
  llvm_cbe_storemerge422 = (unsigned long long )llvm_cbe_storemerge422__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge422 = 0x%I64X",llvm_cbe_storemerge422);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__104);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds float* %%state, i64 %%storemerge422, !dbg !11 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_529_count);
  llvm_cbe_tmp__100 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge422))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge422 = 0x%I64X",((signed long long )llvm_cbe_storemerge422));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load float* %%42, align 4, !dbg !11 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_530_count);
  llvm_cbe_tmp__101 = (float )*llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__101, *(int*)(&llvm_cbe_tmp__101));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = add i64 %%storemerge422, %%40, !dbg !11 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_531_count);
  llvm_cbe_tmp__102 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge422&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__99&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__102&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%44, !dbg !11 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_532_count);
  llvm_cbe_tmp__103 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__102))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__102));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%43, float* %%45, align 4, !dbg !11 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_533_count);
  *llvm_cbe_tmp__103 = llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add i64 %%storemerge422, 1, !dbg !17 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_534_count);
  llvm_cbe_tmp__104 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge422&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__104&18446744073709551615ull)));
  if (((llvm_cbe_tmp__104&18446744073709551615ULL) == (llvm_cbe_tmp__77&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit21;
  } else {
    llvm_cbe_storemerge422__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__104;   /* for PHI node */
    goto llvm_cbe_tmp__119;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph23:
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = sub i64 %%34, %%36, !dbg !11 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_526_count);
  llvm_cbe_tmp__98 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__94&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__95&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__98&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = mul i64 %%39, %%6, !dbg !11 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_527_count);
  llvm_cbe_tmp__99 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__98&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__77&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__99&18446744073709551615ull)));
  llvm_cbe_storemerge422__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__119;

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__113:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ %%52, %%49 ], [ 0, %%.lr.ph13..lr.ph13.split_crit_edge  for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",llvm_cbe_tmp__107);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = mul i64 %%storemerge12, %%4, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_549_count);
  llvm_cbe_tmp__105 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__75&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__105&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%50, !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_550_count);
  llvm_cbe_tmp__106 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__105))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__105));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @k2c_lstmcell(float* %%state, float* %%51, %%struct.k2c_tensor* %%kernel, %%struct.k2c_tensor* %%recurrent_kernel, %%struct.k2c_tensor* %%bias, float* %%fwork, void (float*, i64)* %%recurrent_activation, void (float*, i64)* %%output_activation), !dbg !13 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_551_count);
   /*tail*/ k2c_lstmcell((float *)llvm_cbe_state, (float *)llvm_cbe_tmp__106, (l_struct_OC_k2c_tensor *)llvm_cbe_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_recurrent_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_bias, (float *)llvm_cbe_fwork, llvm_cbe_recurrent_activation, llvm_cbe_output_activation);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = add i64 %%storemerge12, 1, !dbg !17 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_556_count);
  llvm_cbe_tmp__107 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__107&18446744073709551615ull)));
  if (((llvm_cbe_tmp__107&18446744073709551615ULL) == (llvm_cbe_tmp__73&18446744073709551615ULL))) {
    goto llvm_cbe__2e__2e_loopexit11_crit_edge_2e_us_2d_lcssa;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__107;   /* for PHI node */
    goto llvm_cbe_tmp__113;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__2e_loopexit11_crit_edge_2e_us_2d_lcssa:
  goto llvm_cbe__2e__2e_loopexit11_crit_edge;

llvm_cbe__2e__2e_loopexit11_crit_edge:
  goto llvm_cbe__2e_loopexit11;

llvm_cbe__2e_loopexit11:
  goto llvm_cbe_tmp__120;

llvm_cbe__2e_loopexit24:
  goto llvm_cbe_tmp__120;

llvm_cbe_tmp__120:
  if (((llvm_cbe_return_sequences&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe_tmp__121;
  }

llvm_cbe__2e_preheader:
  if (((llvm_cbe_tmp__77&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15 = phi i64 [ %%59, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_storemerge15_count);
  llvm_cbe_storemerge15 = (unsigned long long )llvm_cbe_storemerge15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",llvm_cbe_storemerge15);
printf("\n = 0x%I64X",llvm_cbe_tmp__111);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = getelementptr inbounds float* %%state, i64 %%storemerge15, !dbg !12 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_575_count);
  llvm_cbe_tmp__108 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge15))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",((signed long long )llvm_cbe_storemerge15));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = load float* %%56, align 4, !dbg !12 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_576_count);
  llvm_cbe_tmp__109 = (float )*llvm_cbe_tmp__108;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__109, *(int*)(&llvm_cbe_tmp__109));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge15, !dbg !12 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_577_count);
  llvm_cbe_tmp__110 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge15))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",((signed long long )llvm_cbe_storemerge15));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%57, float* %%58, align 4, !dbg !12 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_578_count);
  *llvm_cbe_tmp__110 = llvm_cbe_tmp__109;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add i64 %%storemerge15, 1, !dbg !17 for 0x%I64xth hint within @k2c_lstm  --> \n", ++aesl_llvm_cbe_579_count);
  llvm_cbe_tmp__111 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge15&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__111&18446744073709551615ull)));
  if (((llvm_cbe_tmp__111&18446744073709551615ULL) == (llvm_cbe_tmp__77&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__111;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e_loopexit:
  goto llvm_cbe_tmp__121;

llvm_cbe_tmp__121:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_lstm}\n");
  return;
}


void k2c_simpleRNNcell(float *llvm_cbe_state, float *llvm_cbe_input, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_recurrent_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, float *llvm_cbe_fwork, void  (*llvm_cbe_output_activation) (float *, unsigned long long )) {
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
  signed long long *llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  unsigned long long llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  signed long long *llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  unsigned long long llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  float *llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  float *llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  float *llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  unsigned int llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  float *llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  unsigned int llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  float *llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  float llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  float *llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  unsigned long long llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_simpleRNNcell\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 3, i64 1, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_606_count);
  llvm_cbe_tmp__122 = (signed long long *)(&llvm_cbe_recurrent_kernel->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_607_count);
  llvm_cbe_tmp__123 = (unsigned long long )*llvm_cbe_tmp__122;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_615_count);
  llvm_cbe_tmp__124 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_616_count);
  llvm_cbe_tmp__125 = (unsigned long long )*llvm_cbe_tmp__124;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__125);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds float* %%fwork, i64 %%2, !dbg !13 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_623_count);
  llvm_cbe_tmp__126 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__123))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__123));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 0, i64 0, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_628_count);
  llvm_cbe_tmp__127 = (float *)(&llvm_cbe_kernel->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.k2c_tensor* %%bias, i64 0, i32 0, i64 0, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_629_count);
  llvm_cbe_tmp__128 = (float *)(&llvm_cbe_bias->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%fwork, float* %%input, float* %%6, float* %%7, i64 1, i64 %%2, i64 %%4) nounwind, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_630_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_fwork, (float *)llvm_cbe_input, (float *)llvm_cbe_tmp__127, (float *)llvm_cbe_tmp__128, 1ull, llvm_cbe_tmp__123, llvm_cbe_tmp__125);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__123);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__125);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__129);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 0, i64 0, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_631_count);
  llvm_cbe_tmp__130 = (float *)(&llvm_cbe_recurrent_kernel->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%5, float* %%state, float* %%9, float* %%fwork, i64 1, i64 %%2, i64 %%2) nounwind, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_632_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__126, (float *)llvm_cbe_state, (float *)llvm_cbe_tmp__130, (float *)llvm_cbe_fwork, 1ull, llvm_cbe_tmp__123, llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__123);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__123);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__131);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%output_activation(float* %%5, i64 %%2) nounwind, !dbg !13 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_633_count);
   /*tail*/ llvm_cbe_output_activation((float *)llvm_cbe_tmp__126, llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__123);
}
  if (((llvm_cbe_tmp__123&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%15, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__135);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%storemerge1, %%2, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__123&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds float* %%fwork, i64 %%.sum, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_641_count);
  llvm_cbe_tmp__132 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load float* %%12, align 4, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_642_count);
  llvm_cbe_tmp__133 = (float )*llvm_cbe_tmp__132;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__133, *(int*)(&llvm_cbe_tmp__133));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds float* %%state, i64 %%storemerge1, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_643_count);
  llvm_cbe_tmp__134 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%13, float* %%14, align 4, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_644_count);
  *llvm_cbe_tmp__134 = llvm_cbe_tmp__133;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i64 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @k2c_simpleRNNcell  --> \n", ++aesl_llvm_cbe_645_count);
  llvm_cbe_tmp__135 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__135&18446744073709551615ull)));
  if (((llvm_cbe_tmp__135&18446744073709551615ULL) == (llvm_cbe_tmp__123&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__135;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_simpleRNNcell}\n");
  return;
}


void k2c_simpleRNN(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, float *llvm_cbe_state, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_recurrent_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, float *llvm_cbe_fwork, signed int llvm_cbe_go_backwards, signed int llvm_cbe_return_sequences, void  (*llvm_cbe_output_activation) (float *, unsigned long long )) {
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
  signed long long *llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  unsigned long long llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  signed long long *llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  unsigned long long llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  signed long long *llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  unsigned long long llvm_cbe_tmp__141;
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
  unsigned int llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_storemerge319_count = 0;
  unsigned int llvm_cbe_storemerge319;
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
  unsigned long long llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge320_count = 0;
  unsigned int llvm_cbe_storemerge320;
  unsigned int llvm_cbe_storemerge320__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  unsigned long long llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  unsigned long long llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  float *llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  unsigned long long llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  unsigned long long llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge416_count = 0;
  unsigned long long llvm_cbe_storemerge416;
  unsigned long long llvm_cbe_storemerge416__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  float *llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  float llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  unsigned long long llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  float *llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  unsigned long long llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond24_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  unsigned long long llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  float *llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  unsigned long long llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge28_count = 0;
  unsigned long long llvm_cbe_storemerge28;
  unsigned long long llvm_cbe_storemerge28__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  float *llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  float llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  unsigned long long llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  float *llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  unsigned long long llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond22_count = 0;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  unsigned long long llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond23_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge15_count = 0;
  unsigned long long llvm_cbe_storemerge15;
  unsigned long long llvm_cbe_storemerge15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  float *llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  float llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  float *llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  unsigned long long llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_simpleRNN\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !13 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_690_count);
  llvm_cbe_tmp__136 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_691_count);
  llvm_cbe_tmp__137 = (unsigned long long )*llvm_cbe_tmp__136;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 0, !dbg !13 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_695_count);
  llvm_cbe_tmp__138 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !13 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_696_count);
  llvm_cbe_tmp__139 = (unsigned long long )*llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__139);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 3, i64 1, !dbg !14 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_701_count);
  llvm_cbe_tmp__140 = (signed long long *)(&llvm_cbe_recurrent_kernel->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !14 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_702_count);
  llvm_cbe_tmp__141 = (unsigned long long )*llvm_cbe_tmp__140;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__141);
  if (((llvm_cbe_go_backwards&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_preheader10;
  } else {
    goto llvm_cbe_tmp__167;
  }

llvm_cbe__2e_preheader10:
  if (((llvm_cbe_tmp__139&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit11;
  } else {
    goto llvm_cbe__2e_lr_2e_ph13;
  }

llvm_cbe__2e_lr_2e_ph13:
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__168;

llvm_cbe_tmp__167:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = trunc i64 %%4 to i32, !dbg !16 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_720_count);
  llvm_cbe_tmp__142 = (unsigned int )((unsigned int )llvm_cbe_tmp__139&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__142);
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge319 = add i32 %%12, -1, !dbg !16 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_storemerge319_count);
  llvm_cbe_storemerge319 = (unsigned int )((unsigned int )(llvm_cbe_tmp__142&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge319 = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge319&4294967295ull)));
  if ((((signed int )llvm_cbe_storemerge319) > ((signed int )4294967295u))) {
    goto llvm_cbe__2e_lr_2e_ph21;
  } else {
    goto llvm_cbe__2e_loopexit18;
  }

llvm_cbe__2e_lr_2e_ph21:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i64 %%4, -1, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_730_count);
  llvm_cbe_tmp__143 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__139&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__143&18446744073709551615ull)));
  llvm_cbe_storemerge320__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge319;   /* for PHI node */
  goto llvm_cbe_tmp__169;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__169:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge320 = phi i32 [ %%storemerge319, %%.lr.ph21 ], [ %%storemerge3, %%29  for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_storemerge320_count);
  llvm_cbe_storemerge320 = (unsigned int )llvm_cbe_storemerge320__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge320 = 0x%X",llvm_cbe_storemerge320);
printf("\nstoremerge319 = 0x%X",llvm_cbe_storemerge319);
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sext i32 %%storemerge320 to i64, !dbg !13 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_732_count);
  llvm_cbe_tmp__144 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge320);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__144);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = mul i64 %%18, %%2, !dbg !13 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_733_count);
  llvm_cbe_tmp__145 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__144&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__137&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__145&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%19, !dbg !13 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_734_count);
  llvm_cbe_tmp__146 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__145))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__145));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @k2c_simpleRNNcell(float* %%state, float* %%20, %%struct.k2c_tensor* %%kernel, %%struct.k2c_tensor* %%recurrent_kernel, %%struct.k2c_tensor* %%bias, float* %%fwork, void (float*, i64)* %%output_activation), !dbg !13 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_735_count);
   /*tail*/ k2c_simpleRNNcell((float *)llvm_cbe_state, (float *)llvm_cbe_tmp__146, (l_struct_OC_k2c_tensor *)llvm_cbe_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_recurrent_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_bias, (float *)llvm_cbe_fwork, llvm_cbe_output_activation);
if (AESL_DEBUG_TRACE) {
}
  if (((llvm_cbe_return_sequences&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__170;
  } else {
    goto llvm_cbe__2e_preheader14;
  }

llvm_cbe_tmp__170:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = add i32 %%storemerge320, -1, !dbg !16 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )((unsigned int )(llvm_cbe_storemerge320&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge3 = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge3&4294967295ull)));
  if ((((signed int )llvm_cbe_storemerge3) > ((signed int )4294967295u))) {
    llvm_cbe_storemerge320__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge3;   /* for PHI node */
    goto llvm_cbe_tmp__169;
  } else {
    goto llvm_cbe__2e_loopexit18;
  }

llvm_cbe__2e_loopexit15:
  goto llvm_cbe_tmp__170;

llvm_cbe__2e_preheader14:
  if (((llvm_cbe_tmp__141&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit15;
  } else {
    goto llvm_cbe__2e_lr_2e_ph17;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__171:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge416 = phi i64 [ 0, %%.lr.ph17 ], [ %%28, %%23  for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_storemerge416_count);
  llvm_cbe_storemerge416 = (unsigned long long )llvm_cbe_storemerge416__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge416 = 0x%I64X",llvm_cbe_storemerge416);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__153);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds float* %%state, i64 %%storemerge416, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_745_count);
  llvm_cbe_tmp__149 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge416))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge416 = 0x%I64X",((signed long long )llvm_cbe_storemerge416));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load float* %%24, align 4, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_746_count);
  llvm_cbe_tmp__150 = (float )*llvm_cbe_tmp__149;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__150, *(int*)(&llvm_cbe_tmp__150));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i64 %%storemerge416, %%22, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_747_count);
  llvm_cbe_tmp__151 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge416&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__148&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__151&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%26, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_748_count);
  llvm_cbe_tmp__152 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__151))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__151));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%25, float* %%27, align 4, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_749_count);
  *llvm_cbe_tmp__152 = llvm_cbe_tmp__150;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__150);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i64 %%storemerge416, 1, !dbg !17 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_750_count);
  llvm_cbe_tmp__153 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge416&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__153&18446744073709551615ull)));
  if (((llvm_cbe_tmp__153&18446744073709551615ULL) == (llvm_cbe_tmp__141&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit15;
  } else {
    llvm_cbe_storemerge416__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__153;   /* for PHI node */
    goto llvm_cbe_tmp__171;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph17:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sub i64 %%16, %%18, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_742_count);
  llvm_cbe_tmp__147 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__143&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__144&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__147&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = mul i64 %%21, %%6, !dbg !11 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_743_count);
  llvm_cbe_tmp__148 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__147&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__141&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__148&18446744073709551615ull)));
  llvm_cbe_storemerge416__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__171;

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__168:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ 0, %%.lr.ph13 ], [ %%42, %%41  for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__162);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = mul i64 %%storemerge12, %%2, !dbg !13 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_765_count);
  llvm_cbe_tmp__154 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__137&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__154&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%32, !dbg !13 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_766_count);
  llvm_cbe_tmp__155 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__154))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__154));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @k2c_simpleRNNcell(float* %%state, float* %%33, %%struct.k2c_tensor* %%kernel, %%struct.k2c_tensor* %%recurrent_kernel, %%struct.k2c_tensor* %%bias, float* %%fwork, void (float*, i64)* %%output_activation), !dbg !13 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_767_count);
   /*tail*/ k2c_simpleRNNcell((float *)llvm_cbe_state, (float *)llvm_cbe_tmp__155, (l_struct_OC_k2c_tensor *)llvm_cbe_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_recurrent_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_bias, (float *)llvm_cbe_fwork, llvm_cbe_output_activation);
if (AESL_DEBUG_TRACE) {
}
  if (((llvm_cbe_return_sequences&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__172;
  } else {
    goto llvm_cbe__2e_preheader6;
  }

llvm_cbe_tmp__172:
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add i64 %%storemerge12, 1, !dbg !16 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_789_count);
  llvm_cbe_tmp__162 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__162&18446744073709551615ull)));
  if (((llvm_cbe_tmp__162&18446744073709551615ULL) == (llvm_cbe_tmp__139&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit11;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__162;   /* for PHI node */
    goto llvm_cbe_tmp__168;
  }

llvm_cbe__2e_loopexit7:
  goto llvm_cbe_tmp__172;

llvm_cbe__2e_preheader6:
  if (((llvm_cbe_tmp__141&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit7;
  } else {
    goto llvm_cbe__2e_lr_2e_ph9;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__173:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge28 = phi i64 [ 0, %%.lr.ph9 ], [ %%40, %%35  for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_storemerge28_count);
  llvm_cbe_storemerge28 = (unsigned long long )llvm_cbe_storemerge28__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge28 = 0x%I64X",llvm_cbe_storemerge28);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__161);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds float* %%state, i64 %%storemerge28, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_776_count);
  llvm_cbe_tmp__157 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge28))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge28 = 0x%I64X",((signed long long )llvm_cbe_storemerge28));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load float* %%36, align 4, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_777_count);
  llvm_cbe_tmp__158 = (float )*llvm_cbe_tmp__157;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__158, *(int*)(&llvm_cbe_tmp__158));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add i64 %%storemerge28, %%34, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_778_count);
  llvm_cbe_tmp__159 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge28&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__156&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__159&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%38, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_779_count);
  llvm_cbe_tmp__160 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__159))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__159));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%37, float* %%39, align 4, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_780_count);
  *llvm_cbe_tmp__160 = llvm_cbe_tmp__158;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__158);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add i64 %%storemerge28, 1, !dbg !17 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_781_count);
  llvm_cbe_tmp__161 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge28&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__161&18446744073709551615ull)));
  if (((llvm_cbe_tmp__161&18446744073709551615ULL) == (llvm_cbe_tmp__141&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit7;
  } else {
    llvm_cbe_storemerge28__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__161;   /* for PHI node */
    goto llvm_cbe_tmp__173;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph9:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = mul i64 %%storemerge12, %%6, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_774_count);
  llvm_cbe_tmp__156 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__141&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__156&18446744073709551615ull)));
  llvm_cbe_storemerge28__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__173;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_loopexit11:
  goto llvm_cbe_tmp__174;

llvm_cbe__2e_loopexit18:
  goto llvm_cbe_tmp__174;

llvm_cbe_tmp__174:
  if (((llvm_cbe_return_sequences&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe_tmp__175;
  }

llvm_cbe__2e_preheader:
  if (((llvm_cbe_tmp__141&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15 = phi i64 [ %%49, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_storemerge15_count);
  llvm_cbe_storemerge15 = (unsigned long long )llvm_cbe_storemerge15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",llvm_cbe_storemerge15);
printf("\n = 0x%I64X",llvm_cbe_tmp__166);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds float* %%state, i64 %%storemerge15, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_806_count);
  llvm_cbe_tmp__163 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge15))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",((signed long long )llvm_cbe_storemerge15));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load float* %%46, align 4, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_807_count);
  llvm_cbe_tmp__164 = (float )*llvm_cbe_tmp__163;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__164, *(int*)(&llvm_cbe_tmp__164));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge15, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_808_count);
  llvm_cbe_tmp__165 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge15))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",((signed long long )llvm_cbe_storemerge15));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%47, float* %%48, align 4, !dbg !12 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_809_count);
  *llvm_cbe_tmp__165 = llvm_cbe_tmp__164;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__164);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add i64 %%storemerge15, 1, !dbg !17 for 0x%I64xth hint within @k2c_simpleRNN  --> \n", ++aesl_llvm_cbe_810_count);
  llvm_cbe_tmp__166 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge15&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__166&18446744073709551615ull)));
  if (((llvm_cbe_tmp__166&18446744073709551615ULL) == (llvm_cbe_tmp__141&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__166;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e_loopexit:
  goto llvm_cbe_tmp__175;

llvm_cbe_tmp__175:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_simpleRNN}\n");
  return;
}


void k2c_grucell(float *llvm_cbe_state, float *llvm_cbe_input, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_recurrent_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, float *llvm_cbe_fwork, signed int llvm_cbe_reset_after, void  (*llvm_cbe_recurrent_activation) (float *, unsigned long long ), void  (*llvm_cbe_output_activation) (float *, unsigned long long )) {
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
  signed long long *llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  unsigned long long llvm_cbe_tmp__177;
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
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  signed long long *llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  unsigned long long llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  unsigned long long llvm_cbe_tmp__180;
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
  float *llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  unsigned long long llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  float *llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
  unsigned long long llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  unsigned long long llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  float *llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  float *llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  unsigned long long llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  float *llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  unsigned long long llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  float *llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  float *llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  float *llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  float *llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  unsigned long long llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  float *llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  unsigned long long llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  float *llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  unsigned long long llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  float *llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  float *llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  float *llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  float *llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  float *llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  float *llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  unsigned int llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  unsigned int llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  unsigned int llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  unsigned int llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  unsigned int llvm_cbe_tmp__210;
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
  static  unsigned long long aesl_llvm_cbe_storemerge47_count = 0;
  unsigned long long llvm_cbe_storemerge47;
  unsigned long long llvm_cbe_storemerge47__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  float *llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  float llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe__2e_sum20_count = 0;
  unsigned long long llvm_cbe__2e_sum20;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  float *llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  float llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  float llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_sum21_count = 0;
  unsigned long long llvm_cbe__2e_sum21;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  float *llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  float llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe__2e_sum22_count = 0;
  unsigned long long llvm_cbe__2e_sum22;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  float *llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  float llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  float llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  unsigned long long llvm_cbe_tmp__221;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_exitcond57_count = 0;
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
  unsigned int llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge844_count = 0;
  unsigned long long llvm_cbe_storemerge844;
  unsigned long long llvm_cbe_storemerge844__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum13_count = 0;
  unsigned long long llvm_cbe__2e_sum13;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
  float *llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  float llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe__2e_sum14_count = 0;
  unsigned long long llvm_cbe__2e_sum14;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  float *llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
  float llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  float llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  unsigned long long llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond56_count = 0;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;
  static  unsigned long long aesl_llvm_cbe_1122_count = 0;
  static  unsigned long long aesl_llvm_cbe_1123_count = 0;
  static  unsigned long long aesl_llvm_cbe_1124_count = 0;
  static  unsigned long long aesl_llvm_cbe_1125_count = 0;
  static  unsigned long long aesl_llvm_cbe_1126_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge141_count = 0;
  unsigned long long llvm_cbe_storemerge141;
  unsigned long long llvm_cbe_storemerge141__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum18_count = 0;
  unsigned long long llvm_cbe__2e_sum18;
  static  unsigned long long aesl_llvm_cbe_1127_count = 0;
  float *llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_1128_count = 0;
  float llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_1129_count = 0;
  float *llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_1130_count = 0;
  float llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_1131_count = 0;
  float llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe__2e_sum19_count = 0;
  unsigned long long llvm_cbe__2e_sum19;
  static  unsigned long long aesl_llvm_cbe_1132_count = 0;
  float *llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_1133_count = 0;
  static  unsigned long long aesl_llvm_cbe_1134_count = 0;
  unsigned long long llvm_cbe_tmp__235;
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
  static  unsigned long long aesl_llvm_cbe_exitcond55_count = 0;
  static  unsigned long long aesl_llvm_cbe_1150_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge635_count = 0;
  unsigned long long llvm_cbe_storemerge635;
  unsigned long long llvm_cbe_storemerge635__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  float *llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  unsigned long long llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  float llvm_cbe_tmp__238;
  float llvm_cbe_tmp__238__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge730_count = 0;
  unsigned long long llvm_cbe_storemerge730;
  unsigned long long llvm_cbe_storemerge730__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum16_count = 0;
  unsigned long long llvm_cbe__2e_sum16;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
  float *llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  float llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  unsigned long long llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe__2e_sum17_count = 0;
  unsigned long long llvm_cbe__2e_sum17;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  float *llvm_cbe_tmp__242;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  float llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  float llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  float llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  unsigned long long llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  static  unsigned long long aesl_llvm_cbe_1174_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond53_count = 0;
  static  unsigned long long aesl_llvm_cbe_1175_count = 0;
  static  unsigned long long aesl_llvm_cbe_1176_count = 0;
  unsigned long long llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_1177_count = 0;
  static  unsigned long long aesl_llvm_cbe_1178_count = 0;
  static  unsigned long long aesl_llvm_cbe_1179_count = 0;
  static  unsigned long long aesl_llvm_cbe_1180_count = 0;
  static  unsigned long long aesl_llvm_cbe_1181_count = 0;
  static  unsigned long long aesl_llvm_cbe_1182_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond54_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1220_count = 0;
  static  unsigned long long aesl_llvm_cbe_1221_count = 0;
  static  unsigned long long aesl_llvm_cbe_1222_count = 0;
  static  unsigned long long aesl_llvm_cbe_1223_count = 0;
  static  unsigned long long aesl_llvm_cbe_1224_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge328_count = 0;
  unsigned long long llvm_cbe_storemerge328;
  unsigned long long llvm_cbe_storemerge328__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1244_count = 0;
  float *llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_1245_count = 0;
  float llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe__2e_sum15_count = 0;
  unsigned long long llvm_cbe__2e_sum15;
  static  unsigned long long aesl_llvm_cbe_1246_count = 0;
  float *llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_1247_count = 0;
  static  unsigned long long aesl_llvm_cbe_1248_count = 0;
  unsigned long long llvm_cbe_tmp__251;
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
  static  unsigned long long aesl_llvm_cbe_exitcond52_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge424_count = 0;
  unsigned long long llvm_cbe_storemerge424;
  unsigned long long llvm_cbe_storemerge424__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum10_count = 0;
  unsigned long long llvm_cbe__2e_sum10;
  static  unsigned long long aesl_llvm_cbe_1312_count = 0;
  float *llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_1313_count = 0;
  float llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe__2e_sum11_count = 0;
  unsigned long long llvm_cbe__2e_sum11;
  static  unsigned long long aesl_llvm_cbe_1314_count = 0;
  float *llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_1315_count = 0;
  float llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_1316_count = 0;
  float llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe__2e_sum12_count = 0;
  unsigned long long llvm_cbe__2e_sum12;
  static  unsigned long long aesl_llvm_cbe_1317_count = 0;
  float *llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_1318_count = 0;
  static  unsigned long long aesl_llvm_cbe_1319_count = 0;
  unsigned long long llvm_cbe_tmp__258;
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
  static  unsigned long long aesl_llvm_cbe_1332_count = 0;
  static  unsigned long long aesl_llvm_cbe_1333_count = 0;
  static  unsigned long long aesl_llvm_cbe_1334_count = 0;
  static  unsigned long long aesl_llvm_cbe_1335_count = 0;
  static  unsigned long long aesl_llvm_cbe_1336_count = 0;
  static  unsigned long long aesl_llvm_cbe_1337_count = 0;
  static  unsigned long long aesl_llvm_cbe_1338_count = 0;
  static  unsigned long long aesl_llvm_cbe_1339_count = 0;
  static  unsigned long long aesl_llvm_cbe_1340_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond51_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge523_count = 0;
  unsigned long long llvm_cbe_storemerge523;
  unsigned long long llvm_cbe_storemerge523__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_1365_count = 0;
  float *llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_1366_count = 0;
  float llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_1367_count = 0;
  float *llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_1368_count = 0;
  float llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_1369_count = 0;
  float llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_1370_count = 0;
  float llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe__2e_sum9_count = 0;
  unsigned long long llvm_cbe__2e_sum9;
  static  unsigned long long aesl_llvm_cbe_1371_count = 0;
  float *llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_1372_count = 0;
  float llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_1373_count = 0;
  float llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_1374_count = 0;
  float llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_1375_count = 0;
  static  unsigned long long aesl_llvm_cbe_1376_count = 0;
  unsigned long long llvm_cbe_tmp__269;
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
  static  unsigned long long aesl_llvm_cbe_1389_count = 0;
  static  unsigned long long aesl_llvm_cbe_1390_count = 0;
  static  unsigned long long aesl_llvm_cbe_1391_count = 0;
  static  unsigned long long aesl_llvm_cbe_1392_count = 0;
  static  unsigned long long aesl_llvm_cbe_1393_count = 0;
  static  unsigned long long aesl_llvm_cbe_1394_count = 0;
  static  unsigned long long aesl_llvm_cbe_1395_count = 0;
  static  unsigned long long aesl_llvm_cbe_1396_count = 0;
  static  unsigned long long aesl_llvm_cbe_1397_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1398_count = 0;
  static  unsigned long long aesl_llvm_cbe_1399_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_grucell\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 3, i64 1, !dbg !13 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_857_count);
  llvm_cbe_tmp__176 = (signed long long *)(&llvm_cbe_recurrent_kernel->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_858_count);
  llvm_cbe_tmp__177 = (unsigned long long )*llvm_cbe_tmp__176;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 3, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_900_count);
  llvm_cbe_tmp__178 = (signed long long *)(&llvm_cbe_kernel->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !12 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_901_count);
  llvm_cbe_tmp__179 = (unsigned long long )*llvm_cbe_tmp__178;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__179);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = udiv i64 %%4, 3, !dbg !12 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_902_count);
  llvm_cbe_tmp__180 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__179&18446744073709551615ull)) / ((unsigned long long )(3ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__180&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 0, i64 0, !dbg !12 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_916_count);
  llvm_cbe_tmp__181 = (float *)(&llvm_cbe_kernel->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = mul i64 %%5, %%2, !dbg !12 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_919_count);
  llvm_cbe_tmp__182 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__180&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__182&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 0, i64 %%7, !dbg !12 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_920_count);
  llvm_cbe_tmp__183 = (float *)(&llvm_cbe_kernel->field0[(((signed long long )llvm_cbe_tmp__182))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__182));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = shl i64 %%2, 1, !dbg !12 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_923_count);
  llvm_cbe_tmp__184 = (unsigned long long )llvm_cbe_tmp__177 << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__184);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = mul i64 %%9, %%5, !dbg !12 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_924_count);
  llvm_cbe_tmp__185 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__184&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__180&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__185&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.k2c_tensor* %%kernel, i64 0, i32 0, i64 %%10, !dbg !12 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_925_count);
  llvm_cbe_tmp__186 = (float *)(&llvm_cbe_kernel->field0[(((signed long long )llvm_cbe_tmp__185))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__185));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 0, i64 0, !dbg !13 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_928_count);
  llvm_cbe_tmp__187 = (float *)(&llvm_cbe_recurrent_kernel->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = mul i64 %%2, %%2, !dbg !13 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_931_count);
  llvm_cbe_tmp__188 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__188&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 0, i64 %%13, !dbg !13 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_932_count);
  llvm_cbe_tmp__189 = (float *)(&llvm_cbe_recurrent_kernel->field0[(((signed long long )llvm_cbe_tmp__188))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__188));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = mul i64 %%9, %%2, !dbg !13 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_935_count);
  llvm_cbe_tmp__190 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__184&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__190&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 0, i64 %%15, !dbg !13 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_936_count);
  llvm_cbe_tmp__191 = (float *)(&llvm_cbe_recurrent_kernel->field0[(((signed long long )llvm_cbe_tmp__190))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__190));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.k2c_tensor* %%bias, i64 0, i32 0, i64 0, !dbg !13 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_940_count);
  llvm_cbe_tmp__192 = (float *)(&llvm_cbe_bias->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds %%struct.k2c_tensor* %%bias, i64 0, i32 0, i64 %%2, !dbg !13 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_943_count);
  llvm_cbe_tmp__193 = (float *)(&llvm_cbe_bias->field0[(((signed long long )llvm_cbe_tmp__177))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__177));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.k2c_tensor* %%bias, i64 0, i32 0, i64 %%9, !dbg !13 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_946_count);
  llvm_cbe_tmp__194 = (float *)(&llvm_cbe_bias->field0[(((signed long long )llvm_cbe_tmp__184))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__184));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = mul i64 %%2, 3, !dbg !13 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_949_count);
  llvm_cbe_tmp__195 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull)) * ((unsigned long long )(3ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__195&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.k2c_tensor* %%bias, i64 0, i32 0, i64 %%20, !dbg !13 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_950_count);
  llvm_cbe_tmp__196 = (float *)(&llvm_cbe_bias->field0[(((signed long long )llvm_cbe_tmp__195))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__195));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = shl i64 %%2, 2, !dbg !14 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_953_count);
  llvm_cbe_tmp__197 = (unsigned long long )llvm_cbe_tmp__177 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__197);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.k2c_tensor* %%bias, i64 0, i32 0, i64 %%22, !dbg !14 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_954_count);
  llvm_cbe_tmp__198 = (float *)(&llvm_cbe_bias->field0[(((signed long long )llvm_cbe_tmp__197))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__197));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = mul i64 %%2, 5, !dbg !14 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_957_count);
  llvm_cbe_tmp__199 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull)) * ((unsigned long long )(5ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__199&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.k2c_tensor* %%bias, i64 0, i32 0, i64 %%24, !dbg !14 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_958_count);
  llvm_cbe_tmp__200 = (float *)(&llvm_cbe_bias->field0[(((signed long long )llvm_cbe_tmp__199))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__199));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds float* %%fwork, i64 %%2, !dbg !14 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_967_count);
  llvm_cbe_tmp__201 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__177))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__177));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds float* %%fwork, i64 %%9, !dbg !14 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_974_count);
  llvm_cbe_tmp__202 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__184))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__184));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds float* %%fwork, i64 %%20, !dbg !14 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_978_count);
  llvm_cbe_tmp__203 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__195))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__195));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds float* %%fwork, i64 %%22, !dbg !14 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_986_count);
  llvm_cbe_tmp__204 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__197))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__197));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds float* %%fwork, i64 %%24, !dbg !14 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_994_count);
  llvm_cbe_tmp__205 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_tmp__199))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__199));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%fwork, float* %%input, float* %%6, float* %%17, i64 1, i64 %%2, i64 %%5) nounwind, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1003_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_fwork, (float *)llvm_cbe_input, (float *)llvm_cbe_tmp__181, (float *)llvm_cbe_tmp__192, 1ull, llvm_cbe_tmp__177, llvm_cbe_tmp__180);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__180);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__206);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%26, float* %%input, float* %%8, float* %%18, i64 1, i64 %%2, i64 %%5) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1004_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__201, (float *)llvm_cbe_input, (float *)llvm_cbe_tmp__183, (float *)llvm_cbe_tmp__193, 1ull, llvm_cbe_tmp__177, llvm_cbe_tmp__180);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__180);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__207);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%27, float* %%input, float* %%11, float* %%19, i64 1, i64 %%2, i64 %%5) nounwind, !dbg !12 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1005_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__202, (float *)llvm_cbe_input, (float *)llvm_cbe_tmp__186, (float *)llvm_cbe_tmp__194, 1ull, llvm_cbe_tmp__177, llvm_cbe_tmp__180);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__180);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__208);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%28, float* %%state, float* %%12, float* %%21, i64 1, i64 %%2, i64 %%2) nounwind, !dbg !16 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1006_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__203, (float *)llvm_cbe_state, (float *)llvm_cbe_tmp__187, (float *)llvm_cbe_tmp__196, 1ull, llvm_cbe_tmp__177, llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__209);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%29, float* %%state, float* %%14, float* %%23, i64 1, i64 %%2, i64 %%2) nounwind, !dbg !16 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1007_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__204, (float *)llvm_cbe_state, (float *)llvm_cbe_tmp__189, (float *)llvm_cbe_tmp__198, 1ull, llvm_cbe_tmp__177, llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__210);
}
  if (((llvm_cbe_tmp__177&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge50;
  } else {
    llvm_cbe_storemerge47__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph49;
  }

  do {     /* Syntactic loop '.lr.ph49' to make GCC happy */
llvm_cbe__2e_lr_2e_ph49:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge47 = phi i64 [ %%47, %%.lr.ph49 ], [ 0, %%0  for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_storemerge47_count);
  llvm_cbe_storemerge47 = (unsigned long long )llvm_cbe_storemerge47__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge47 = 0x%I64X",llvm_cbe_storemerge47);
printf("\n = 0x%I64X",llvm_cbe_tmp__221);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds float* %%fwork, i64 %%storemerge47, !dbg !20 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1031_count);
  llvm_cbe_tmp__211 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_storemerge47))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge47 = 0x%I64X",((signed long long )llvm_cbe_storemerge47));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load float* %%37, align 4, !dbg !20 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1032_count);
  llvm_cbe_tmp__212 = (float )*llvm_cbe_tmp__211;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__212, *(int*)(&llvm_cbe_tmp__212));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum20 = add i64 %%storemerge47, %%20, !dbg !20 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum20_count);
  llvm_cbe__2e_sum20 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge47&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__195&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum20 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum20&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds float* %%fwork, i64 %%.sum20, !dbg !20 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1033_count);
  llvm_cbe_tmp__213 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum20))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum20 = 0x%I64X",((signed long long )llvm_cbe__2e_sum20));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load float* %%39, align 4, !dbg !20 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1034_count);
  llvm_cbe_tmp__214 = (float )*llvm_cbe_tmp__213;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__214, *(int*)(&llvm_cbe_tmp__214));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = fadd float %%38, %%40, !dbg !20 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1035_count);
  llvm_cbe_tmp__215 = (float )((float )(llvm_cbe_tmp__212 + llvm_cbe_tmp__214));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__215, *(int*)(&llvm_cbe_tmp__215));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%41, float* %%39, align 4, !dbg !20 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1036_count);
  *llvm_cbe_tmp__213 = llvm_cbe_tmp__215;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__215);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum21 = add i64 %%storemerge47, %%2, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum21_count);
  llvm_cbe__2e_sum21 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge47&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum21 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum21&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds float* %%fwork, i64 %%.sum21, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1037_count);
  llvm_cbe_tmp__216 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum21))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum21 = 0x%I64X",((signed long long )llvm_cbe__2e_sum21));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load float* %%42, align 4, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1038_count);
  llvm_cbe_tmp__217 = (float )*llvm_cbe_tmp__216;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__217, *(int*)(&llvm_cbe_tmp__217));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum22 = add i64 %%storemerge47, %%22, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum22_count);
  llvm_cbe__2e_sum22 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge47&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__197&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum22 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum22&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds float* %%fwork, i64 %%.sum22, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1039_count);
  llvm_cbe_tmp__218 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum22))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum22 = 0x%I64X",((signed long long )llvm_cbe__2e_sum22));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load float* %%44, align 4, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1040_count);
  llvm_cbe_tmp__219 = (float )*llvm_cbe_tmp__218;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__219, *(int*)(&llvm_cbe_tmp__219));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = fadd float %%43, %%45, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1041_count);
  llvm_cbe_tmp__220 = (float )((float )(llvm_cbe_tmp__217 + llvm_cbe_tmp__219));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__220, *(int*)(&llvm_cbe_tmp__220));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%46, float* %%44, align 4, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1042_count);
  *llvm_cbe_tmp__218 = llvm_cbe_tmp__220;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__220);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = add i64 %%storemerge47, 1, !dbg !22 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1043_count);
  llvm_cbe_tmp__221 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge47&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__221&18446744073709551615ull)));
  if (((llvm_cbe_tmp__221&18446744073709551615ULL) == (llvm_cbe_tmp__177&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge50;
  } else {
    llvm_cbe_storemerge47__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__221;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph49;
  }

  } while (1); /* end of syntactic loop '.lr.ph49' */
llvm_cbe__2e__crit_edge50:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%recurrent_activation(float* %%28, i64 %%2) nounwind, !dbg !15 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1066_count);
   /*tail*/ llvm_cbe_recurrent_activation((float *)llvm_cbe_tmp__203, llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%recurrent_activation(float* %%29, i64 %%2) nounwind, !dbg !15 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1067_count);
   /*tail*/ llvm_cbe_recurrent_activation((float *)llvm_cbe_tmp__204, llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
}
  if (((llvm_cbe_reset_after&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_preheader40;
  } else {
    goto llvm_cbe_tmp__270;
  }

llvm_cbe__2e_preheader40:
  if (((llvm_cbe_tmp__177&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader_2e_thread;
  } else {
    llvm_cbe_storemerge141__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph42;
  }

llvm_cbe_tmp__270:
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = tail call i32 bitcast (i32 (...)* @k2c_affine_matmul to i32 (float*, float*, float*, float*, i64, i64, i64)*)(float* %%30, float* %%state, float* %%16, float* %%25, i64 1, i64 %%2, i64 %%2) nounwind, !dbg !16 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1085_count);
   /*tail*/ k2c_affine_matmul((float *)llvm_cbe_tmp__205, (float *)llvm_cbe_state, (float *)llvm_cbe_tmp__191, (float *)llvm_cbe_tmp__200, 1ull, llvm_cbe_tmp__177, llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__222);
}
  if (((llvm_cbe_tmp__177&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit43;
  } else {
    llvm_cbe_storemerge844__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph46;
  }

  do {     /* Syntactic loop '.lr.ph46' to make GCC happy */
llvm_cbe__2e_lr_2e_ph46:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge844 = phi i64 [ %%56, %%.lr.ph46 ], [ 0, %%49  for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_storemerge844_count);
  llvm_cbe_storemerge844 = (unsigned long long )llvm_cbe_storemerge844__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge844 = 0x%I64X",llvm_cbe_storemerge844);
printf("\n = 0x%I64X",llvm_cbe_tmp__228);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum13 = add i64 %%storemerge844, %%22, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum13_count);
  llvm_cbe__2e_sum13 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge844&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__197&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum13 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum13&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds float* %%fwork, i64 %%.sum13, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1093_count);
  llvm_cbe_tmp__223 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum13))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum13 = 0x%I64X",((signed long long )llvm_cbe__2e_sum13));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load float* %%51, align 4, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1094_count);
  llvm_cbe_tmp__224 = (float )*llvm_cbe_tmp__223;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__224, *(int*)(&llvm_cbe_tmp__224));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum14 = add i64 %%storemerge844, %%24, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum14_count);
  llvm_cbe__2e_sum14 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge844&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__199&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum14 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum14&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds float* %%fwork, i64 %%.sum14, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1095_count);
  llvm_cbe_tmp__225 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum14))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum14 = 0x%I64X",((signed long long )llvm_cbe__2e_sum14));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load float* %%53, align 4, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1096_count);
  llvm_cbe_tmp__226 = (float )*llvm_cbe_tmp__225;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__226, *(int*)(&llvm_cbe_tmp__226));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = fmul float %%52, %%54, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1097_count);
  llvm_cbe_tmp__227 = (float )((float )(llvm_cbe_tmp__224 * llvm_cbe_tmp__226));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__227, *(int*)(&llvm_cbe_tmp__227));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%55, float* %%53, align 4, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1098_count);
  *llvm_cbe_tmp__225 = llvm_cbe_tmp__227;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__227);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = add i64 %%storemerge844, 1, !dbg !23 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1099_count);
  llvm_cbe_tmp__228 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge844&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__228&18446744073709551615ull)));
  if (((llvm_cbe_tmp__228&18446744073709551615ULL) == (llvm_cbe_tmp__177&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit43;
  } else {
    llvm_cbe_storemerge844__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__228;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph46;
  }

  } while (1); /* end of syntactic loop '.lr.ph46' */
llvm_cbe__2e_preheader38:
  if (((llvm_cbe_tmp__177&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader_2e_thread;
  } else {
    llvm_cbe_storemerge635__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph32;
  }

  do {     /* Syntactic loop '.lr.ph42' to make GCC happy */
llvm_cbe__2e_lr_2e_ph42:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge141 = phi i64 [ %%63, %%.lr.ph42 ], [ 0, %%.preheader40  for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_storemerge141_count);
  llvm_cbe_storemerge141 = (unsigned long long )llvm_cbe_storemerge141__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge141 = 0x%I64X",llvm_cbe_storemerge141);
printf("\n = 0x%I64X",llvm_cbe_tmp__235);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum18 = add i64 %%storemerge141, %%22, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum18_count);
  llvm_cbe__2e_sum18 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge141&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__197&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum18 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum18&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds float* %%fwork, i64 %%.sum18, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1127_count);
  llvm_cbe_tmp__229 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum18))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum18 = 0x%I64X",((signed long long )llvm_cbe__2e_sum18));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = load float* %%57, align 4, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1128_count);
  llvm_cbe_tmp__230 = (float )*llvm_cbe_tmp__229;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__230, *(int*)(&llvm_cbe_tmp__230));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = getelementptr inbounds float* %%state, i64 %%storemerge141, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1129_count);
  llvm_cbe_tmp__231 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge141))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge141 = 0x%I64X",((signed long long )llvm_cbe_storemerge141));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load float* %%59, align 4, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1130_count);
  llvm_cbe_tmp__232 = (float )*llvm_cbe_tmp__231;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__232, *(int*)(&llvm_cbe_tmp__232));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = fmul float %%58, %%60, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1131_count);
  llvm_cbe_tmp__233 = (float )((float )(llvm_cbe_tmp__230 * llvm_cbe_tmp__232));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__233, *(int*)(&llvm_cbe_tmp__233));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum19 = add i64 %%storemerge141, %%24, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum19_count);
  llvm_cbe__2e_sum19 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge141&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__199&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum19 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum19&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = getelementptr inbounds float* %%fwork, i64 %%.sum19, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1132_count);
  llvm_cbe_tmp__234 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum19))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum19 = 0x%I64X",((signed long long )llvm_cbe__2e_sum19));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%61, float* %%62, align 4, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1133_count);
  *llvm_cbe_tmp__234 = llvm_cbe_tmp__233;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__233);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = add i64 %%storemerge141, 1, !dbg !22 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1134_count);
  llvm_cbe_tmp__235 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge141&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__235&18446744073709551615ull)));
  if (((llvm_cbe_tmp__235&18446744073709551615ULL) == (llvm_cbe_tmp__177&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader38;
  } else {
    llvm_cbe_storemerge141__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__235;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph42;
  }

  } while (1); /* end of syntactic loop '.lr.ph42' */
  do {     /* Syntactic loop '.lr.ph32' to make GCC happy */
llvm_cbe__2e_lr_2e_ph32:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge635 = phi i64 [ %%76, %%._crit_edge33 ], [ 0, %%.preheader38  for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_storemerge635_count);
  llvm_cbe_storemerge635 = (unsigned long long )llvm_cbe_storemerge635__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge635 = 0x%I64X",llvm_cbe_storemerge635);
printf("\n = 0x%I64X",llvm_cbe_tmp__247);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds float* %%fwork, i64 %%storemerge635, !dbg !17 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1151_count);
  llvm_cbe_tmp__236 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_storemerge635))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge635 = 0x%I64X",((signed long long )llvm_cbe_storemerge635));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%64, align 4, !dbg !17 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1152_count);
  *llvm_cbe_tmp__236 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = add i64 %%storemerge635, %%15, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1158_count);
  llvm_cbe_tmp__237 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge635&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__190&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__237&18446744073709551615ull)));
  llvm_cbe_tmp__238__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge730__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__271;

llvm_cbe__2e__crit_edge33:
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = add i64 %%storemerge635, 1, !dbg !23 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1176_count);
  llvm_cbe_tmp__247 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge635&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__247&18446744073709551615ull)));
  if (((llvm_cbe_tmp__247&18446744073709551615ULL) == (llvm_cbe_tmp__177&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge635__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__247;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph32;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__271:
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = phi float [ 0.000000e+00, %%.lr.ph32 ], [ %%74, %%66 ], !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1160_count);
  llvm_cbe_tmp__238 = (float )llvm_cbe_tmp__238__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__238);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__245);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge730 = phi i64 [ 0, %%.lr.ph32 ], [ %%75, %%66  for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_storemerge730_count);
  llvm_cbe_storemerge730 = (unsigned long long )llvm_cbe_storemerge730__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge730 = 0x%I64X",llvm_cbe_storemerge730);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__246);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum16 = add i64 %%24, %%storemerge730, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum16_count);
  llvm_cbe__2e_sum16 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__199&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge730&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum16 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum16&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = getelementptr inbounds float* %%fwork, i64 %%.sum16, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1161_count);
  llvm_cbe_tmp__239 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum16))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum16 = 0x%I64X",((signed long long )llvm_cbe__2e_sum16));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = load float* %%68, align 4, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1162_count);
  llvm_cbe_tmp__240 = (float )*llvm_cbe_tmp__239;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__240, *(int*)(&llvm_cbe_tmp__240));
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = mul i64 %%storemerge730, %%2, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1163_count);
  llvm_cbe_tmp__241 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge730&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__241&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum17 = add i64 %%65, %%70, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum17_count);
  llvm_cbe__2e_sum17 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__237&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__241&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum17 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum17&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 0, i64 %%.sum17, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1164_count);
  llvm_cbe_tmp__242 = (float *)(&llvm_cbe_recurrent_kernel->field0[(((signed long long )llvm_cbe__2e_sum17))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum17 = 0x%I64X",((signed long long )llvm_cbe__2e_sum17));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = load float* %%71, align 4, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1165_count);
  llvm_cbe_tmp__243 = (float )*llvm_cbe_tmp__242;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__243, *(int*)(&llvm_cbe_tmp__243));
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = fmul float %%69, %%72, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1166_count);
  llvm_cbe_tmp__244 = (float )((float )(llvm_cbe_tmp__240 * llvm_cbe_tmp__243));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__244, *(int*)(&llvm_cbe_tmp__244));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = fadd float %%67, %%73, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1167_count);
  llvm_cbe_tmp__245 = (float )((float )(llvm_cbe_tmp__238 + llvm_cbe_tmp__244));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__245, *(int*)(&llvm_cbe_tmp__245));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%74, float* %%64, align 4, !dbg !18 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1168_count);
  *llvm_cbe_tmp__236 = llvm_cbe_tmp__245;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__245);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = add i64 %%storemerge730, 1, !dbg !23 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1169_count);
  llvm_cbe_tmp__246 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge730&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__246&18446744073709551615ull)));
  if (((llvm_cbe_tmp__246&18446744073709551615ULL) == (llvm_cbe_tmp__177&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge33;
  } else {
    llvm_cbe_tmp__238__PHI_TEMPORARY = (float )llvm_cbe_tmp__245;   /* for PHI node */
    llvm_cbe_storemerge730__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__246;   /* for PHI node */
    goto llvm_cbe_tmp__271;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph32' */
llvm_cbe__2e_preheader_2e_thread:
  goto llvm_cbe__2e_loopexit;

llvm_cbe__2e_preheader:
  if (((llvm_cbe_tmp__177&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge328__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph29;
  }

  do {     /* Syntactic loop '.lr.ph29' to make GCC happy */
llvm_cbe__2e_lr_2e_ph29:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge328 = phi i64 [ %%80, %%.lr.ph29 ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_storemerge328_count);
  llvm_cbe_storemerge328 = (unsigned long long )llvm_cbe_storemerge328__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge328 = 0x%I64X",llvm_cbe_storemerge328);
printf("\n = 0x%I64X",llvm_cbe_tmp__251);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds float* %%fwork, i64 %%storemerge328, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1244_count);
  llvm_cbe_tmp__248 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe_storemerge328))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge328 = 0x%I64X",((signed long long )llvm_cbe_storemerge328));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = load float* %%77, align 4, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1245_count);
  llvm_cbe_tmp__249 = (float )*llvm_cbe_tmp__248;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__249, *(int*)(&llvm_cbe_tmp__249));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum15 = add i64 %%storemerge328, %%24, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum15_count);
  llvm_cbe__2e_sum15 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge328&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__199&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum15 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum15&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds float* %%fwork, i64 %%.sum15, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1246_count);
  llvm_cbe_tmp__250 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum15))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum15 = 0x%I64X",((signed long long )llvm_cbe__2e_sum15));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%78, float* %%79, align 4, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1247_count);
  *llvm_cbe_tmp__250 = llvm_cbe_tmp__249;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__249);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = add i64 %%storemerge328, 1, !dbg !23 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1248_count);
  llvm_cbe_tmp__251 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge328&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__251&18446744073709551615ull)));
  if (((llvm_cbe_tmp__251&18446744073709551615ULL) == (llvm_cbe_tmp__177&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge328__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__251;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph29;
  }

  } while (1); /* end of syntactic loop '.lr.ph29' */
llvm_cbe__2e_loopexit:
  goto llvm_cbe_tmp__272;

llvm_cbe__2e_loopexit43:
  goto llvm_cbe_tmp__272;

llvm_cbe_tmp__272:
  if (((llvm_cbe_tmp__177&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge27_2e_thread;
  } else {
    llvm_cbe_storemerge424__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph26;
  }

llvm_cbe__2e__crit_edge27_2e_thread:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%output_activation(float* %%26, i64 %%2) nounwind, !dbg !15 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1289_count);
   /*tail*/ llvm_cbe_output_activation((float *)llvm_cbe_tmp__201, llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
}
  goto llvm_cbe__2e__crit_edge;

  do {     /* Syntactic loop '.lr.ph26' to make GCC happy */
llvm_cbe__2e_lr_2e_ph26:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge424 = phi i64 [ %%88, %%.lr.ph26 ], [ 0, %%81  for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_storemerge424_count);
  llvm_cbe_storemerge424 = (unsigned long long )llvm_cbe_storemerge424__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge424 = 0x%I64X",llvm_cbe_storemerge424);
printf("\n = 0x%I64X",llvm_cbe_tmp__258);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum10 = add i64 %%storemerge424, %%9, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum10_count);
  llvm_cbe__2e_sum10 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge424&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__184&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum10 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum10&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = getelementptr inbounds float* %%fwork, i64 %%.sum10, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1312_count);
  llvm_cbe_tmp__252 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum10))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum10 = 0x%I64X",((signed long long )llvm_cbe__2e_sum10));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = load float* %%82, align 4, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1313_count);
  llvm_cbe_tmp__253 = (float )*llvm_cbe_tmp__252;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__253, *(int*)(&llvm_cbe_tmp__253));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum11 = add i64 %%storemerge424, %%24, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum11_count);
  llvm_cbe__2e_sum11 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge424&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__199&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum11 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum11&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = getelementptr inbounds float* %%fwork, i64 %%.sum11, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1314_count);
  llvm_cbe_tmp__254 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum11))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum11 = 0x%I64X",((signed long long )llvm_cbe__2e_sum11));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = load float* %%84, align 4, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1315_count);
  llvm_cbe_tmp__255 = (float )*llvm_cbe_tmp__254;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__255, *(int*)(&llvm_cbe_tmp__255));
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = fadd float %%83, %%85, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1316_count);
  llvm_cbe_tmp__256 = (float )((float )(llvm_cbe_tmp__253 + llvm_cbe_tmp__255));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__256, *(int*)(&llvm_cbe_tmp__256));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum12 = add i64 %%storemerge424, %%2, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum12_count);
  llvm_cbe__2e_sum12 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge424&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum12 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum12&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = getelementptr inbounds float* %%fwork, i64 %%.sum12, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1317_count);
  llvm_cbe_tmp__257 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum12))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum12 = 0x%I64X",((signed long long )llvm_cbe__2e_sum12));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%86, float* %%87, align 4, !dbg !21 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1318_count);
  *llvm_cbe_tmp__257 = llvm_cbe_tmp__256;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__256);
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = add i64 %%storemerge424, 1, !dbg !22 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1319_count);
  llvm_cbe_tmp__258 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge424&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__258&18446744073709551615ull)));
  if (((llvm_cbe_tmp__258&18446744073709551615ULL) == (llvm_cbe_tmp__177&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge27;
  } else {
    llvm_cbe_storemerge424__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__258;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph26;
  }

  } while (1); /* end of syntactic loop '.lr.ph26' */
llvm_cbe__2e__crit_edge27:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void %%output_activation(float* %%26, i64 %%2) nounwind, !dbg !15 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1342_count);
   /*tail*/ llvm_cbe_output_activation((float *)llvm_cbe_tmp__201, llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__177);
}
  if (((llvm_cbe_tmp__177&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge523__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge523 = phi i64 [ %%99, %%.lr.ph ], [ 0, %%._crit_edge27  for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_storemerge523_count);
  llvm_cbe_storemerge523 = (unsigned long long )llvm_cbe_storemerge523__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge523 = 0x%I64X",llvm_cbe_storemerge523);
printf("\n = 0x%I64X",llvm_cbe_tmp__269);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%storemerge523, %%20, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge523&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__195&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = getelementptr inbounds float* %%fwork, i64 %%.sum, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1365_count);
  llvm_cbe_tmp__259 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = load float* %%89, align 4, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1366_count);
  llvm_cbe_tmp__260 = (float )*llvm_cbe_tmp__259;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__260, *(int*)(&llvm_cbe_tmp__260));
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = getelementptr inbounds float* %%state, i64 %%storemerge523, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1367_count);
  llvm_cbe_tmp__261 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge523))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge523 = 0x%I64X",((signed long long )llvm_cbe_storemerge523));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = load float* %%91, align 4, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1368_count);
  llvm_cbe_tmp__262 = (float )*llvm_cbe_tmp__261;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__262, *(int*)(&llvm_cbe_tmp__262));
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = fmul float %%90, %%92, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1369_count);
  llvm_cbe_tmp__263 = (float )((float )(llvm_cbe_tmp__260 * llvm_cbe_tmp__262));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__263, *(int*)(&llvm_cbe_tmp__263));
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = fsub float 1.000000e+00, %%90, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1370_count);
  llvm_cbe_tmp__264 = (float )((float )(0x1p0 - llvm_cbe_tmp__260));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__264, *(int*)(&llvm_cbe_tmp__264));
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum9 = add i64 %%storemerge523, %%2, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe__2e_sum9_count);
  llvm_cbe__2e_sum9 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge523&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum9 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum9&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = getelementptr inbounds float* %%fwork, i64 %%.sum9, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1371_count);
  llvm_cbe_tmp__265 = (float *)(&llvm_cbe_fwork[(((signed long long )llvm_cbe__2e_sum9))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum9 = 0x%I64X",((signed long long )llvm_cbe__2e_sum9));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = load float* %%95, align 4, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1372_count);
  llvm_cbe_tmp__266 = (float )*llvm_cbe_tmp__265;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__266, *(int*)(&llvm_cbe_tmp__266));
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = fmul float %%94, %%96, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1373_count);
  llvm_cbe_tmp__267 = (float )((float )(llvm_cbe_tmp__264 * llvm_cbe_tmp__266));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__267, *(int*)(&llvm_cbe_tmp__267));
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = fadd float %%93, %%97, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1374_count);
  llvm_cbe_tmp__268 = (float )((float )(llvm_cbe_tmp__263 + llvm_cbe_tmp__267));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__268, *(int*)(&llvm_cbe_tmp__268));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%98, float* %%91, align 4, !dbg !11 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1375_count);
  *llvm_cbe_tmp__261 = llvm_cbe_tmp__268;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__268);
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = add i64 %%storemerge523, 1, !dbg !22 for 0x%I64xth hint within @k2c_grucell  --> \n", ++aesl_llvm_cbe_1376_count);
  llvm_cbe_tmp__269 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge523&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__269&18446744073709551615ull)));
  if (((llvm_cbe_tmp__269&18446744073709551615ULL) == (llvm_cbe_tmp__177&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge523__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__269;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_grucell}\n");
  return;
}


void k2c_gru(l_struct_OC_k2c_tensor *llvm_cbe_output, l_struct_OC_k2c_tensor *llvm_cbe_input, float *llvm_cbe_state, l_struct_OC_k2c_tensor *llvm_cbe_kernel, l_struct_OC_k2c_tensor *llvm_cbe_recurrent_kernel, l_struct_OC_k2c_tensor *llvm_cbe_bias, float *llvm_cbe_fwork, signed int llvm_cbe_reset_after, signed int llvm_cbe_go_backwards, signed int llvm_cbe_return_sequences, void  (*llvm_cbe_recurrent_activation) (float *, unsigned long long ), void  (*llvm_cbe_output_activation) (float *, unsigned long long )) {
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
  static  unsigned long long aesl_llvm_cbe_1442_count = 0;
  static  unsigned long long aesl_llvm_cbe_1443_count = 0;
  signed long long *llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_1444_count = 0;
  unsigned long long llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_1445_count = 0;
  static  unsigned long long aesl_llvm_cbe_1446_count = 0;
  static  unsigned long long aesl_llvm_cbe_1447_count = 0;
  static  unsigned long long aesl_llvm_cbe_1448_count = 0;
  signed long long *llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_1449_count = 0;
  unsigned long long llvm_cbe_tmp__276;
  static  unsigned long long aesl_llvm_cbe_1450_count = 0;
  static  unsigned long long aesl_llvm_cbe_1451_count = 0;
  static  unsigned long long aesl_llvm_cbe_1452_count = 0;
  static  unsigned long long aesl_llvm_cbe_1453_count = 0;
  static  unsigned long long aesl_llvm_cbe_1454_count = 0;
  signed long long *llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_1455_count = 0;
  unsigned long long llvm_cbe_tmp__278;
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
  unsigned int llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe_storemerge319_count = 0;
  unsigned int llvm_cbe_storemerge319;
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
  unsigned long long llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_1484_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge320_count = 0;
  unsigned int llvm_cbe_storemerge320;
  unsigned int llvm_cbe_storemerge320__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1485_count = 0;
  unsigned long long llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_1486_count = 0;
  unsigned long long llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_1487_count = 0;
  float *llvm_cbe_tmp__283;
  static  unsigned long long aesl_llvm_cbe_1488_count = 0;
  static  unsigned long long aesl_llvm_cbe_1489_count = 0;
  static  unsigned long long aesl_llvm_cbe_1490_count = 0;
  static  unsigned long long aesl_llvm_cbe_1491_count = 0;
  static  unsigned long long aesl_llvm_cbe_1492_count = 0;
  static  unsigned long long aesl_llvm_cbe_1493_count = 0;
  static  unsigned long long aesl_llvm_cbe_1494_count = 0;
  static  unsigned long long aesl_llvm_cbe_1495_count = 0;
  unsigned long long llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_1496_count = 0;
  unsigned long long llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_1497_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge416_count = 0;
  unsigned long long llvm_cbe_storemerge416;
  unsigned long long llvm_cbe_storemerge416__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1498_count = 0;
  float *llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_1499_count = 0;
  float llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_1500_count = 0;
  unsigned long long llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_1501_count = 0;
  float *llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_1502_count = 0;
  static  unsigned long long aesl_llvm_cbe_1503_count = 0;
  unsigned long long llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_1504_count = 0;
  static  unsigned long long aesl_llvm_cbe_1505_count = 0;
  static  unsigned long long aesl_llvm_cbe_1506_count = 0;
  static  unsigned long long aesl_llvm_cbe_1507_count = 0;
  static  unsigned long long aesl_llvm_cbe_1508_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond24_count = 0;
  static  unsigned long long aesl_llvm_cbe_1509_count = 0;
  static  unsigned long long aesl_llvm_cbe_1510_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  static  unsigned long long aesl_llvm_cbe_1511_count = 0;
  static  unsigned long long aesl_llvm_cbe_1512_count = 0;
  static  unsigned long long aesl_llvm_cbe_1513_count = 0;
  static  unsigned long long aesl_llvm_cbe_1514_count = 0;
  static  unsigned long long aesl_llvm_cbe_1515_count = 0;
  static  unsigned long long aesl_llvm_cbe_1516_count = 0;
  static  unsigned long long aesl_llvm_cbe_1517_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1518_count = 0;
  unsigned long long llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_1519_count = 0;
  float *llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_1520_count = 0;
  static  unsigned long long aesl_llvm_cbe_1521_count = 0;
  static  unsigned long long aesl_llvm_cbe_1522_count = 0;
  static  unsigned long long aesl_llvm_cbe_1523_count = 0;
  static  unsigned long long aesl_llvm_cbe_1524_count = 0;
  static  unsigned long long aesl_llvm_cbe_1525_count = 0;
  static  unsigned long long aesl_llvm_cbe_1526_count = 0;
  static  unsigned long long aesl_llvm_cbe_1527_count = 0;
  unsigned long long llvm_cbe_tmp__293;
  static  unsigned long long aesl_llvm_cbe_1528_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge28_count = 0;
  unsigned long long llvm_cbe_storemerge28;
  unsigned long long llvm_cbe_storemerge28__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1529_count = 0;
  float *llvm_cbe_tmp__294;
  static  unsigned long long aesl_llvm_cbe_1530_count = 0;
  float llvm_cbe_tmp__295;
  static  unsigned long long aesl_llvm_cbe_1531_count = 0;
  unsigned long long llvm_cbe_tmp__296;
  static  unsigned long long aesl_llvm_cbe_1532_count = 0;
  float *llvm_cbe_tmp__297;
  static  unsigned long long aesl_llvm_cbe_1533_count = 0;
  static  unsigned long long aesl_llvm_cbe_1534_count = 0;
  unsigned long long llvm_cbe_tmp__298;
  static  unsigned long long aesl_llvm_cbe_1535_count = 0;
  static  unsigned long long aesl_llvm_cbe_1536_count = 0;
  static  unsigned long long aesl_llvm_cbe_1537_count = 0;
  static  unsigned long long aesl_llvm_cbe_1538_count = 0;
  static  unsigned long long aesl_llvm_cbe_1539_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond22_count = 0;
  static  unsigned long long aesl_llvm_cbe_1540_count = 0;
  static  unsigned long long aesl_llvm_cbe_1541_count = 0;
  static  unsigned long long aesl_llvm_cbe_1542_count = 0;
  unsigned long long llvm_cbe_tmp__299;
  static  unsigned long long aesl_llvm_cbe_1543_count = 0;
  static  unsigned long long aesl_llvm_cbe_1544_count = 0;
  static  unsigned long long aesl_llvm_cbe_1545_count = 0;
  static  unsigned long long aesl_llvm_cbe_1546_count = 0;
  static  unsigned long long aesl_llvm_cbe_1547_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond23_count = 0;
  static  unsigned long long aesl_llvm_cbe_1548_count = 0;
  static  unsigned long long aesl_llvm_cbe_1549_count = 0;
  static  unsigned long long aesl_llvm_cbe_1550_count = 0;
  static  unsigned long long aesl_llvm_cbe_1551_count = 0;
  static  unsigned long long aesl_llvm_cbe_1552_count = 0;
  static  unsigned long long aesl_llvm_cbe_1553_count = 0;
  static  unsigned long long aesl_llvm_cbe_1554_count = 0;
  static  unsigned long long aesl_llvm_cbe_1555_count = 0;
  static  unsigned long long aesl_llvm_cbe_1556_count = 0;
  static  unsigned long long aesl_llvm_cbe_1557_count = 0;
  static  unsigned long long aesl_llvm_cbe_1558_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_count = 0;
  unsigned long long llvm_cbe_storemerge15;
  unsigned long long llvm_cbe_storemerge15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1559_count = 0;
  float *llvm_cbe_tmp__300;
  static  unsigned long long aesl_llvm_cbe_1560_count = 0;
  float llvm_cbe_tmp__301;
  static  unsigned long long aesl_llvm_cbe_1561_count = 0;
  float *llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_1562_count = 0;
  static  unsigned long long aesl_llvm_cbe_1563_count = 0;
  unsigned long long llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_1564_count = 0;
  static  unsigned long long aesl_llvm_cbe_1565_count = 0;
  static  unsigned long long aesl_llvm_cbe_1566_count = 0;
  static  unsigned long long aesl_llvm_cbe_1567_count = 0;
  static  unsigned long long aesl_llvm_cbe_1568_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1569_count = 0;
  static  unsigned long long aesl_llvm_cbe_1570_count = 0;
  static  unsigned long long aesl_llvm_cbe_1571_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @k2c_gru\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 1, !dbg !13 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1443_count);
  llvm_cbe_tmp__273 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1444_count);
  llvm_cbe_tmp__274 = (unsigned long long )*llvm_cbe_tmp__273;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__274);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 3, i64 0, !dbg !13 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1448_count);
  llvm_cbe_tmp__275 = (signed long long *)(&llvm_cbe_input->field3[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !13 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1449_count);
  llvm_cbe_tmp__276 = (unsigned long long )*llvm_cbe_tmp__275;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__276);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%recurrent_kernel, i64 0, i32 3, i64 1, !dbg !14 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1454_count);
  llvm_cbe_tmp__277 = (signed long long *)(&llvm_cbe_recurrent_kernel->field3[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !14 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1455_count);
  llvm_cbe_tmp__278 = (unsigned long long )*llvm_cbe_tmp__277;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__278);
  if (((llvm_cbe_go_backwards&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_preheader10;
  } else {
    goto llvm_cbe_tmp__304;
  }

llvm_cbe__2e_preheader10:
  if (((llvm_cbe_tmp__276&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit11;
  } else {
    goto llvm_cbe__2e_lr_2e_ph13;
  }

llvm_cbe__2e_lr_2e_ph13:
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__305;

llvm_cbe_tmp__304:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = trunc i64 %%4 to i32, !dbg !16 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1473_count);
  llvm_cbe_tmp__279 = (unsigned int )((unsigned int )llvm_cbe_tmp__276&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__279);
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge319 = add i32 %%12, -1, !dbg !16 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_storemerge319_count);
  llvm_cbe_storemerge319 = (unsigned int )((unsigned int )(llvm_cbe_tmp__279&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge319 = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge319&4294967295ull)));
  if ((((signed int )llvm_cbe_storemerge319) > ((signed int )4294967295u))) {
    goto llvm_cbe__2e_lr_2e_ph21;
  } else {
    goto llvm_cbe__2e_loopexit18;
  }

llvm_cbe__2e_lr_2e_ph21:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i64 %%4, -1, !dbg !11 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1483_count);
  llvm_cbe_tmp__280 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__276&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__280&18446744073709551615ull)));
  llvm_cbe_storemerge320__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge319;   /* for PHI node */
  goto llvm_cbe_tmp__306;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__306:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge320 = phi i32 [ %%storemerge319, %%.lr.ph21 ], [ %%storemerge3, %%29  for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_storemerge320_count);
  llvm_cbe_storemerge320 = (unsigned int )llvm_cbe_storemerge320__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge320 = 0x%X",llvm_cbe_storemerge320);
printf("\nstoremerge319 = 0x%X",llvm_cbe_storemerge319);
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sext i32 %%storemerge320 to i64, !dbg !13 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1485_count);
  llvm_cbe_tmp__281 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge320);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__281);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = mul i64 %%18, %%2, !dbg !13 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1486_count);
  llvm_cbe_tmp__282 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__281&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__274&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__282&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%19, !dbg !13 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1487_count);
  llvm_cbe_tmp__283 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__282))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__282));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @k2c_grucell(float* %%state, float* %%20, %%struct.k2c_tensor* %%kernel, %%struct.k2c_tensor* %%recurrent_kernel, %%struct.k2c_tensor* %%bias, float* %%fwork, i32 %%reset_after, void (float*, i64)* %%recurrent_activation, void (float*, i64)* %%output_activation), !dbg !13 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1488_count);
   /*tail*/ k2c_grucell((float *)llvm_cbe_state, (float *)llvm_cbe_tmp__283, (l_struct_OC_k2c_tensor *)llvm_cbe_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_recurrent_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_bias, (float *)llvm_cbe_fwork, llvm_cbe_reset_after, llvm_cbe_recurrent_activation, llvm_cbe_output_activation);
if (AESL_DEBUG_TRACE) {
printf("\nArgument reset_after = 0x%X",llvm_cbe_reset_after);
}
  if (((llvm_cbe_return_sequences&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__307;
  } else {
    goto llvm_cbe__2e_preheader14;
  }

llvm_cbe_tmp__307:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = add i32 %%storemerge320, -1, !dbg !16 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )((unsigned int )(llvm_cbe_storemerge320&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge3 = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge3&4294967295ull)));
  if ((((signed int )llvm_cbe_storemerge3) > ((signed int )4294967295u))) {
    llvm_cbe_storemerge320__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge3;   /* for PHI node */
    goto llvm_cbe_tmp__306;
  } else {
    goto llvm_cbe__2e_loopexit18;
  }

llvm_cbe__2e_loopexit15:
  goto llvm_cbe_tmp__307;

llvm_cbe__2e_preheader14:
  if (((llvm_cbe_tmp__278&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit15;
  } else {
    goto llvm_cbe__2e_lr_2e_ph17;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__308:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge416 = phi i64 [ 0, %%.lr.ph17 ], [ %%28, %%23  for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_storemerge416_count);
  llvm_cbe_storemerge416 = (unsigned long long )llvm_cbe_storemerge416__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge416 = 0x%I64X",llvm_cbe_storemerge416);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__290);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds float* %%state, i64 %%storemerge416, !dbg !11 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1498_count);
  llvm_cbe_tmp__286 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge416))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge416 = 0x%I64X",((signed long long )llvm_cbe_storemerge416));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load float* %%24, align 4, !dbg !11 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1499_count);
  llvm_cbe_tmp__287 = (float )*llvm_cbe_tmp__286;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__287, *(int*)(&llvm_cbe_tmp__287));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i64 %%storemerge416, %%22, !dbg !11 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1500_count);
  llvm_cbe_tmp__288 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge416&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__285&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__288&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%26, !dbg !11 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1501_count);
  llvm_cbe_tmp__289 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__288))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__288));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%25, float* %%27, align 4, !dbg !11 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1502_count);
  *llvm_cbe_tmp__289 = llvm_cbe_tmp__287;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__287);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i64 %%storemerge416, 1, !dbg !17 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1503_count);
  llvm_cbe_tmp__290 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge416&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__290&18446744073709551615ull)));
  if (((llvm_cbe_tmp__290&18446744073709551615ULL) == (llvm_cbe_tmp__278&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit15;
  } else {
    llvm_cbe_storemerge416__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__290;   /* for PHI node */
    goto llvm_cbe_tmp__308;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph17:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sub i64 %%16, %%18, !dbg !11 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1495_count);
  llvm_cbe_tmp__284 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__280&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__281&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__284&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = mul i64 %%21, %%6, !dbg !11 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1496_count);
  llvm_cbe_tmp__285 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__284&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__278&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__285&18446744073709551615ull)));
  llvm_cbe_storemerge416__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__308;

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__305:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ 0, %%.lr.ph13 ], [ %%42, %%41  for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__299);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = mul i64 %%storemerge12, %%2, !dbg !13 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1518_count);
  llvm_cbe_tmp__291 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__274&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__291&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct.k2c_tensor* %%input, i64 0, i32 0, i64 %%32, !dbg !13 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1519_count);
  llvm_cbe_tmp__292 = (float *)(&llvm_cbe_input->field0[(((signed long long )llvm_cbe_tmp__291))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__291));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @k2c_grucell(float* %%state, float* %%33, %%struct.k2c_tensor* %%kernel, %%struct.k2c_tensor* %%recurrent_kernel, %%struct.k2c_tensor* %%bias, float* %%fwork, i32 %%reset_after, void (float*, i64)* %%recurrent_activation, void (float*, i64)* %%output_activation), !dbg !13 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1520_count);
   /*tail*/ k2c_grucell((float *)llvm_cbe_state, (float *)llvm_cbe_tmp__292, (l_struct_OC_k2c_tensor *)llvm_cbe_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_recurrent_kernel, (l_struct_OC_k2c_tensor *)llvm_cbe_bias, (float *)llvm_cbe_fwork, llvm_cbe_reset_after, llvm_cbe_recurrent_activation, llvm_cbe_output_activation);
if (AESL_DEBUG_TRACE) {
printf("\nArgument reset_after = 0x%X",llvm_cbe_reset_after);
}
  if (((llvm_cbe_return_sequences&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__309;
  } else {
    goto llvm_cbe__2e_preheader6;
  }

llvm_cbe_tmp__309:
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add i64 %%storemerge12, 1, !dbg !17 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1542_count);
  llvm_cbe_tmp__299 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__299&18446744073709551615ull)));
  if (((llvm_cbe_tmp__299&18446744073709551615ULL) == (llvm_cbe_tmp__276&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit11;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__299;   /* for PHI node */
    goto llvm_cbe_tmp__305;
  }

llvm_cbe__2e_loopexit7:
  goto llvm_cbe_tmp__309;

llvm_cbe__2e_preheader6:
  if (((llvm_cbe_tmp__278&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit7;
  } else {
    goto llvm_cbe__2e_lr_2e_ph9;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__310:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge28 = phi i64 [ 0, %%.lr.ph9 ], [ %%40, %%35  for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_storemerge28_count);
  llvm_cbe_storemerge28 = (unsigned long long )llvm_cbe_storemerge28__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge28 = 0x%I64X",llvm_cbe_storemerge28);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__298);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds float* %%state, i64 %%storemerge28, !dbg !12 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1529_count);
  llvm_cbe_tmp__294 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge28))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge28 = 0x%I64X",((signed long long )llvm_cbe_storemerge28));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load float* %%36, align 4, !dbg !12 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1530_count);
  llvm_cbe_tmp__295 = (float )*llvm_cbe_tmp__294;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__295, *(int*)(&llvm_cbe_tmp__295));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add i64 %%storemerge28, %%34, !dbg !12 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1531_count);
  llvm_cbe_tmp__296 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge28&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__293&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__296&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%38, !dbg !12 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1532_count);
  llvm_cbe_tmp__297 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_tmp__296))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__296));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%37, float* %%39, align 4, !dbg !12 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1533_count);
  *llvm_cbe_tmp__297 = llvm_cbe_tmp__295;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__295);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add i64 %%storemerge28, 1, !dbg !17 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1534_count);
  llvm_cbe_tmp__298 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge28&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__298&18446744073709551615ull)));
  if (((llvm_cbe_tmp__298&18446744073709551615ULL) == (llvm_cbe_tmp__278&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit7;
  } else {
    llvm_cbe_storemerge28__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__298;   /* for PHI node */
    goto llvm_cbe_tmp__310;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph9:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = mul i64 %%storemerge12, %%6, !dbg !12 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1527_count);
  llvm_cbe_tmp__293 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__278&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__293&18446744073709551615ull)));
  llvm_cbe_storemerge28__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__310;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_loopexit11:
  goto llvm_cbe_tmp__311;

llvm_cbe__2e_loopexit18:
  goto llvm_cbe_tmp__311;

llvm_cbe_tmp__311:
  if (((llvm_cbe_return_sequences&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe_tmp__312;
  }

llvm_cbe__2e_preheader:
  if (((llvm_cbe_tmp__278&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15 = phi i64 [ %%49, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_storemerge15_count);
  llvm_cbe_storemerge15 = (unsigned long long )llvm_cbe_storemerge15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",llvm_cbe_storemerge15);
printf("\n = 0x%I64X",llvm_cbe_tmp__303);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds float* %%state, i64 %%storemerge15, !dbg !12 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1559_count);
  llvm_cbe_tmp__300 = (float *)(&llvm_cbe_state[(((signed long long )llvm_cbe_storemerge15))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",((signed long long )llvm_cbe_storemerge15));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load float* %%46, align 4, !dbg !12 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1560_count);
  llvm_cbe_tmp__301 = (float )*llvm_cbe_tmp__300;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__301, *(int*)(&llvm_cbe_tmp__301));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds %%struct.k2c_tensor* %%output, i64 0, i32 0, i64 %%storemerge15, !dbg !12 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1561_count);
  llvm_cbe_tmp__302 = (float *)(&llvm_cbe_output->field0[(((signed long long )llvm_cbe_storemerge15))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",((signed long long )llvm_cbe_storemerge15));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%47, float* %%48, align 4, !dbg !12 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1562_count);
  *llvm_cbe_tmp__302 = llvm_cbe_tmp__301;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__301);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add i64 %%storemerge15, 1, !dbg !18 for 0x%I64xth hint within @k2c_gru  --> \n", ++aesl_llvm_cbe_1563_count);
  llvm_cbe_tmp__303 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge15&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__303&18446744073709551615ull)));
  if (((llvm_cbe_tmp__303&18446744073709551615ULL) == (llvm_cbe_tmp__278&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__303;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e_loopexit:
  goto llvm_cbe_tmp__312;

llvm_cbe_tmp__312:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @k2c_gru}\n");
  return;
}

