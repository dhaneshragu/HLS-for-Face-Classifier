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


/* External Global Variable Declarations */
extern float test1_dense_input_input_array[2622];
extern float keras_activation_3_test1_array[6];
extern float c_activation_3_test1_array[6];
extern float test2_dense_input_input_array[2622];
extern float keras_activation_3_test2_array[6];
extern float c_activation_3_test2_array[6];
extern float test3_dense_input_input_array[2622];
extern float keras_activation_3_test3_array[6];
extern float c_activation_3_test3_array[6];
extern float test4_dense_input_input_array[2622];
extern float keras_activation_3_test4_array[6];
extern float c_activation_3_test4_array[6];
extern float test5_dense_input_input_array[2622];
extern float keras_activation_3_test5_array[6];
extern float c_activation_3_test5_array[6];
extern float test6_dense_input_input_array[2622];
extern float keras_activation_3_test6_array[6];
extern float c_activation_3_test6_array[6];
extern float test7_dense_input_input_array[2622];
extern float keras_activation_3_test7_array[6];
extern float c_activation_3_test7_array[6];
extern float test8_dense_input_input_array[2622];
extern float keras_activation_3_test8_array[6];
extern float c_activation_3_test8_array[6];
extern float test9_dense_input_input_array[2622];
extern float keras_activation_3_test9_array[6];
extern float c_activation_3_test9_array[6];
extern float test10_dense_input_input_array[2622];
extern float keras_activation_3_test10_array[6];
extern float c_activation_3_test10_array[6];
extern l_struct_OC_k2c_tensor test1_dense_input_input;
extern unsigned int j;
extern l_struct_OC_k2c_tensor keras_activation_3_test1;
extern l_struct_OC_k2c_tensor c_activation_3_test1;
extern l_struct_OC_k2c_tensor test2_dense_input_input;
extern l_struct_OC_k2c_tensor keras_activation_3_test2;
extern l_struct_OC_k2c_tensor c_activation_3_test2;
extern l_struct_OC_k2c_tensor test3_dense_input_input;
extern l_struct_OC_k2c_tensor keras_activation_3_test3;
extern l_struct_OC_k2c_tensor c_activation_3_test3;
extern l_struct_OC_k2c_tensor test4_dense_input_input;
extern l_struct_OC_k2c_tensor keras_activation_3_test4;
extern l_struct_OC_k2c_tensor c_activation_3_test4;
extern l_struct_OC_k2c_tensor test5_dense_input_input;
extern l_struct_OC_k2c_tensor keras_activation_3_test5;
extern l_struct_OC_k2c_tensor c_activation_3_test5;
extern l_struct_OC_k2c_tensor test6_dense_input_input;
extern l_struct_OC_k2c_tensor keras_activation_3_test6;
extern l_struct_OC_k2c_tensor c_activation_3_test6;
extern l_struct_OC_k2c_tensor test7_dense_input_input;
extern l_struct_OC_k2c_tensor keras_activation_3_test7;
extern l_struct_OC_k2c_tensor c_activation_3_test7;
extern l_struct_OC_k2c_tensor test8_dense_input_input;
extern l_struct_OC_k2c_tensor keras_activation_3_test8;
extern l_struct_OC_k2c_tensor c_activation_3_test8;
extern l_struct_OC_k2c_tensor test9_dense_input_input;
extern l_struct_OC_k2c_tensor keras_activation_3_test9;
extern l_struct_OC_k2c_tensor c_activation_3_test9;
extern l_struct_OC_k2c_tensor test10_dense_input_input;
extern l_struct_OC_k2c_tensor keras_activation_3_test10;
extern l_struct_OC_k2c_tensor c_activation_3_test10;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int main(void);
void face_classifier_c_initialize();
void face_classifier_c(l_struct_OC_k2c_tensor *, l_struct_OC_k2c_tensor *);
float maxabs(l_struct_OC_k2c_tensor *llvm_cbe_tensor1, l_struct_OC_k2c_tensor *llvm_cbe_tensor2);
void face_classifier_c_terminate();
float fabsf(float );


/* Global Variable Definitions and Initialization */
float keras_activation_3_test1_array[6] = { 0x1.f75064p-3, 0x1.214cfcp-4, 0x1.bab6f2p-6, 0x1.d66c34p-4, 0x1.07d79p-1, 0x1.b0ef8p-6 };
float c_activation_3_test1_array[6];
float test2_dense_input_input_array[2622] = { 0x1.8fbccap-1, -0x1.5edbc4p0, 0x1.f4613ep0, -0x1.e949bp0, -0x1.67465ep0, 0x1.c91f26p-1, -0x1.d056bep-5, -0x1.364fp0, 0x1.6204a8p0, -0x1.da3366p0, 0x1.59a468p-4, 0x1.e1d684p-1, -0x1.4c450ap-1, -0x1.04799cp-5, 0x1.94fdd2p-3, -0x1.daaeb4p-2, -0x1.a4d14p-2, 0x1.16246p-4, 0x1.817ffp-2, -0x1.3bd71p0, 0x1.5b9a6ep0, 0x1.a00056p0, -0x1.d8e0fep-1, 0x1.d6a84ap0, 0x1.7deb32p0, 0x1.a6f7aap0, -0x1.b5c838p0, -0x1.f90276p0, -0x1.9f589p-2, -0x1.6e5e74p0, -0x1.4f356cp-2, -0x1.a33d9p0, -0x1.3238bap0, 0x1.df7004p0, 0x1.1dccd2p0, 0x1.b07a38p0, -0x1.70608cp0, -0x1.aa887ap0, -0x1.b8bbb4p-2, 0x1.04c28ep0, 0x1.70f63ep-1, -0x1.c55d44p0, 0x1.d04ad8p-2, -0x1.9a1704p0, 0x1.6894ap-1, -0x1.566d3cp0, 0x1.be091p0, 0x1.119124p0, 0x1.dd8238p-1, -0x1.322f26p0, 0x1.a70c0ep0, 0x1.ddb39p0, 0x1.11d144p0, 0x1.1ba8b8p0, -0x1.8e4466p-2, -0x1.34029ep-5, 0x1.67fc1p-3, -0x1.227038p0, 0x1.e9bb32p0, 0x1.b32118p-3, 0x1.241d6cp0, -0x1.e285bcp-3, 0x1.8510d6p-1, 0x1.a335dp-2, -0x1.5dc3ap0, 0x1.3f9266p0, 0x1.e5e3f2p-1, 0x1.c27d4p0, 0x1.d7a08ep0, 0x1.6c94cp0, -0x1.cb3b28p0, -0x1.b528fp-1, -0x1.ea2364p-1, -0x1.b2ac06p-1, -0x1.2a37bap-1, -0x1.2d6184p-6, -0x1.4ebcaep-5, -0x1.f65534p0, 0x1.8bdb76p0, 0x1.e95e9ep0, -0x1.0c9c1ep-3, 0x1.ef7e2cp-2, -0x1.450922p0, -0x1.8365c4p0, -0x1.3d7cfp0, 0x1.777feap0, 0x1.1b6a64p-1, -0x1.07233cp0, -0x1.95ffbep-4, 0x1.99d43ep-1, 0x1.100a1ep0, 0x1.1e01bep-1, -0x1.9ac5a2p-4, -0x1.c9781p0, -0x1.d91d0cp0, -0x1.e9ce16p0, -0x1.c5d5cep0, -0x1.f5cd74p0, -0x1.52bc5cp0, -0x1.a6b0e6p-1, 0x1.2c74e4p0, -0x1.8281b2p0, -0x1.2cdab6p-7, -0x1.334692p0, 0x1.30ca0ep-1, -0x1.8ec5d2p-1, -0x1.06ac8p0, -0x1.467b6p0, -0x1.d8bdd6p-1, -0x1.754364p-3, 0x1.73faeap-1, -0x1.18dbb4p-4, -0x1.924e88p-1, -0x1.54062ap0, -0x1.3ccbdap0, -0x1.73e4e6p-2, 0x1.3cc6cp0, 0x1.4d6208p0, -0x1.a0da9p-5, 0x1.3c5244p0, -0x1.352266p0, 0x1.cca9a2p-2, -0x1.42fb8ep-1, 0x1.fba162p-5, 0x1.7f70fep-1, 0x1.06a712p0, 0x1.bea892p-1, 0x1.486828p0, 0x1.790896p-1, -0x1.4b4026p-1, 0x1.de0f1ap-4, 0x1.47e66ap0, -0x1.fb4722p-3, -0x1.e6a41cp0, -0x1.f3727ap0, -0x1.f5b304p0, -0x1.e13326p0, -0x1.ad1fa8p-1, -0x1.7f8afap0, -0x1.2f9afep-2, -0x1.80a2f6p-1, 0x1.91d174p-1, 0x1.f75ee4p0, -0x1.4e9094p0, -0x1.c4713p-3, 0x1.aa5668p0, 0x1.db62b8p0, -0x1.ab1e58p0, 0x1.c3980ep0, 0x1.1e486ep0, -0x1.f2277cp0, -0x1.497c26p-4, 0x1.55c15p0, -0x1.957e26p-2, 0x1.e0bcb8p0, 0x1.d2ff3p0, 0x1.b2fc24p0, -0x1.29dffap0, -0x1.dbbc7cp-2, -0x1.dd502p-1, -0x1.943e08p0, 0x1.79acaep-4, 0x1.9793aap-3, 0x1.3bf7a8p0, 0x1.da8ffp0, -0x1.f8f136p0, 0x1.3cea8cp-2, -0x1.bf761cp-4, -0x1.a9b3eep0, -0x1.99964cp-1, 0x1.a261c4p-2, -0x1.6e7e5ep-1, 0x1.0080ccp-3, -0x1.ee3a9ep-1, 0x1.cb839cp0, -0x1.809078p-2, 0x1.5320e2p0, 0x1.83e8aap0, -0x1.776b4p-1, 0x1.8c9fp-1, -0x1.880064p0, -0x1.36fc1p-1, -0x1.1c97c4p-3, -0x1.5895aep0, -0x1.1cf1b4p-2, -0x1.f8716p-4, 0x1.b32c04p0, -0x1.faec94p0, 0x1.c0f662p0, 0x1.a02b6ap-2, 0x1.0be258p0, 0x1.5ba9dcp0, -0x1.09075p-2, -0x1.d611e2p0, 0x1.7f06e2p-1, 0x1.219d4p-1, -0x1.f19ea4p0, 0x1.ae9e5p0, -0x1.e643b2p0, 0x1.5fa528p0, 0x1.5e8a3p0, -0x1.752528p-2, -0x1.2a37e8p0, 0x1.fd7b1ap0, -0x1.73915p0, 0x1.a27908p-3, 0x1.7dd2aap-3, 0x1.477288p0, 0x1.f0128p0, 0x1.765246p-2, -0x1.b0ed4p-2, -0x1.bd4976p-1, 0x1.73ddp-4, 0x1.8c87f4p0, -0x1.2f4bc2p-3, -0x1.1df426p0, -0x1.eff0dcp-1, -0x1.e11c02p-1, -0x1.cf1e98p-2, 0x1.a0f4dep-1, 0x1.7d525ep-4, -0x1.86bd02p-5, -0x1.34b3dcp0, 0x1.b7ba4p-2, 0x1.12ebc6p-2, 0x1.cc37d4p-2, -0x1.33886ap0, 0x1.b56366p0, -0x1.854234p0, -0x1.22477cp-2, -0x1.a2bebcp0, 0x1.14c09cp-1, -0x1.08ebf8p-1, -0x1.8ffc1cp0, 0x1.66de7p-1, -0x1.c8a6ap0, 0x1.b08c2ep-1, -0x1.a2852cp-1, 0x1.787b62p0, 0x1.55db7ap0, 0x1.4d7d0ep0, -0x1.b421bp0, 0x1.31d1aep-1, -0x1.391d3p0, 0x1.069544p0, 0x1.77734ap-4, 0x1.0487ap-2, 0x1.62e468p0, -0x1.59a9f6p0, -0x1.df8ba6p0, 0x1.0d89d6p0, -0x1.6e346ap-1, 0x1.ac7ap-1, -0x1.56bb4p-1, 0x1.636892p-1, 0x1.e25266p0, 0x1.91174p-1, -0x1.52a2c2p-1, -0x1.10af1cp0, -0x1.e4e41ap-1, 0x1.4487eep0, -0x1.bebb54p-1, -0x1.04ddd8p0, 0x1.22d80ep-1, -0x1.04a886p0, 0x1.8a4bc6p0, 0x1.87aea4p0, 0x1.4c981ap0, 0x1.c5f35cp-1, -0x1.92ba86p-2, 0x1.b53f6cp-2, 0x1.311bc8p0, -0x1.d0ba3p0, 0x1.0168e4p0, -0x1.041306p0, 0x1.a00de4p0, -0x1.05f9d6p0, 0x1.590552p0, 0x1.01ad38p-1, 0x1.fcec6ap-2, -0x1.e3e88ep0, -0x1.4a4decp-4, 0x1.85cedcp0, 0x1.40f6cap-1, 0x1.e074b4p-2, -0x1.49423cp0, 0x1.32a568p0, -0x1.c98092p-1, -0x1.e56bd8p-4, -0x1.fa5ca8p-1, 0x1.2b9f18p0, 0x1.78d99ap0, -0x1.c7f02p0, 0x1.123334p0, 0x1.28b1e8p-3, 0x1.3af668p0, -0x1.eb1598p-1, -0x1.b0c29ep0, 0x1.2d5fcp-1, 0x1.69752ap0, 0x1.a3c17cp-1, -0x1.2f960cp0, 0x1.f65894p-2, 0x1.2b4f3ep-1, 0x1.58aa2ep0, -0x1.d05f9ep-1, -0x1.df7afap0, 0x1.6ee0aap-1, 0x1.8d4d1cp0, 0x1.640746p-3, -0x1.a737cap-1, 0x1.1a8768p-1, 0x1.ebd772p0, -0x1.8cd0ep-5, -0x1.6dfa3ap-2, 0x1.0386a8p0, -0x1.b26ab8p0, -0x1.1e926p0, 0x1.99e9a4p-1, 0x1.1cb2fp0, -0x1.187332p-3, 0x1.b36496p0, 0x1.0c7ed4p-4, 0x1.9e8dd6p0, -0x1.a076cap-1, 0x1.c6d04ep0, 0x1.774f24p0, -0x1.3afb4ep-1, -0x1.52a9e2p-2, -0x1.0ec27cp0, -0x1.a78a8p0, -0x1.fca0c6p-1, 0x1.e8d782p0, -0x1.193d4p-1, 0x1.f83dcep0, -0x1.59408p-1, 0x1.86394p-1, -0x1.c37364p0, 0x1.e3ec1p0, 0x1.e8023p-2, 0x1.5c9962p-3, 0x1.4ae812p-3, -0x1.a79de6p-1, 0x1.636292p-2, -0x1.142094p0, 0x1.ab5506p-4, 0x1.5d3ae2p-4, -0x1.9de1c6p-1, -0x1.9dc056p0, -0x1.8a90dap-1, 0x1.e871acp-2, 0x1.cb02f4p0, -0x1.7d8be2p0, 0x1.b94d16p-1, 0x1.31f124p-1, 0x1.fe5272p0, -0x1.fc6e48p-2, -0x1.7771c4p-1, -0x1.9ba46ep0, 0x1.4f302ep0, 0x1.89e3c8p0, -0x1.797628p0, -0x1.b7c3dep0, 0x1.fbd018p-3, -0x1.9a7676p0, -0x1.c5842ap-1, 0x1.8435cap-2, 0x1.c78718p0, 0x1.a12eb8p0, 0x1.bf5638p-2, -0x1.473bc6p-2, 0x1.62e8b4p-4, -0x1.39b716p0, 0x1.14bcf8p0, 0x1.573df4p0, -0x1.8d3274p-1, 0x1.075a4ep0, 0x1.0eb472p-1, 0x1.35942ep-1, -0x1.c94f6p0, -0x1.2d9214p-1, 0x1.3085bp-1, -0x1.48bbacp-1, 0x1.a881bcp0, 0x1.bc8a24p0, 0x1.b3b158p0, 0x1.ddb444p-1, -0x1.122b14p-1, -0x1.00b994p0, -0x1.8ec7f2p-4, 0x1.0ebe82p-3, -0x1.d9e52ap0, 0x1.b092d2p-1, -0x1.d7f352p0, -0x1.521d76p-1, 0x1.883362p0, -0x1.c4c776p0, -0x1.a3997ep0, -0x1.ed0918p0, 0x1.7bc038p-2, -0x1.de8244p-7, 0x1.cf84aap-3, 0x1.e96026p-2, -0x1.7617f6p-1, -0x1.c3bcb8p0, 0x1.ddccf4p0, 0x1.10265ep-1, 0x1.4c61d6p-1, 0x1.3a5042p-2, 0x1.0f6ee8p0, -0x1.8e80f6p0, 0x1.dc7ef8p0, 0x1.0bfd38p0, 0x1.e8d672p0, -0x1.4e23cap-1, -0x1.c5159cp0, -0x1.22f7e4p0, 0x1.bb215cp0, -0x1.7d46a4p-2, -0x1.2aee1cp0, 0x1.e19d98p-3, 0x1.4c5a94p0, 0x1.9bff8cp0, -0x1.37a972p0, -0x1.6323fcp-5, -0x1.f12b0ap0, -0x1.61a5d6p-2, 0x1.82e486p0, -0x1.7a9aap-1, -0x1.f667e6p0, 0x1.36a3p0, -0x1.ebe9cap-1, -0x1.0de066p0, 0x1.7e7ad2p0, 0x1.885ce6p-4, 0x1.fc6d12p-3, 0x1.0e2b08p-1, -0x1.ee2dp0, 0x1.5cc8fep0, 0x1.a235aap0, 0x1.67c2bep0, 0x1.a68268p0, -0x1.611a3ep-5, 0x1.bfb04cp0, -0x1.4473a2p-3, -0x1.141654p0, 0x1.0e706cp0, 0x1.cf2c8ap0, -0x1.f9caf8p-1, 0x1.ccb1a2p-5, -0x1.0156ccp0, 0x1.286df6p-1, 0x1.15bb02p-2, 0x1.fedc6cp0, 0x1.008bp-3, -0x1.5f48b8p-1, 0x1.72ebdcp-1, -0x1.aa10acp-2, -0x1.ea7292p0, 0x1.a54b04p0, 0x1.6e98f6p-2, 0x1.7cdd7ep-1, -0x1.0a6a36p-2, 0x1.8d26cap-1, -0x1.2d3fc2p0, -0x1.0ee9d2p0, 0x1.f6289cp-2, 0x1.f3c29cp0, 0x1.22e55ap-2, 0x1.8f90f8p0, 0x1.78ab36p-1, -0x1.933932p-1, 0x1.62ae98p0, 0x1.fcdc1cp0, -0x1.908938p-5, -0x1.b1af68p0, -0x1.e011ep0, -0x1.f3490ep-2, 0x1.75f69p0, 0x1.5f0b3cp0, 0x1.05ba96p0, 0x1.fef78cp0, -0x1.35f64cp0, -0x1.f2a774p-1, 0x1.30be72p0, 0x1.b957e2p0, -0x1.dde776p0, -0x1.9e436cp0, 0x1.a2d2c8p0, 0x1.38cf66p-5, -0x1.fe38fp0, -0x1.602c7cp-1, 0x1.b596e8p-2, -0x1.27645p0, 0x1.025fcp0, -0x1.e866bp0, 0x1.3ba9cp-1, 0x1.6c1434p0, 0x1.13009cp0, -0x1.a3e1fap0, 0x1.82c5a8p0, -0x1.afe7bcp-1, 0x1.c62f18p-6, 0x1.ce232ap0, 0x1.6e5fcep0, 0x1.98aa9p0, 0x1.bd6b28p-1, 0x1.6418acp-1, 0x1.63bc24p-2, -0x1.fa31f4p0, 0x1.4d64c4p-1, -0x1.8a9402p-2, -0x1.f8d43ep-2, -0x1.f92b66p-1, 0x1.d071b6p-1, 0x1.610a06p0, 0x1.1a161cp0, 0x1.525502p0, -0x1.189f64p0, 0x1.61b336p0, 0x1.78c65p0, -0x1.956bfcp0, 0x1.7f5222p0, 0x1.837ec6p0, -0x1.faf224p-1, -0x1.707e2ap0, 0x1.8fdac2p-1, 0x1.5aa89p-1, 0x1.23c682p-1, -0x1.716afap0, 0x1.09863cp0, 0x1.974accp0, -0x1.7ddfacp0, 0x1.a68786p-3, 0x1.ab097ep-3, 0x1.ef899ap-7, 0x1.fa6106p-3, -0x1.62bf5ap0, 0x1.33f484p-1, -0x1.3f3d9cp0, 0x1.c5e3e6p-1, 0x1.7dfa98p0, 0x1.3f836ap0, 0x1.706d62p0, -0x1.6d3fdp-1, -0x1.bdb44ep0, 0x1.6827e4p-3, -0x1.9406f4p-2, 0x1.2150fap0, -0x1.7d9a2ap-1, 0x1.1cfbe6p0, -0x1.c93d42p-4, -0x1.172172p-1, 0x1.b31a84p-1, 0x1.8e6c1p-1, 0x1.68d714p-4, 0x1.ac42ep0, 0x1.5450ep0, -0x1.419976p0, -0x1.f9f3cp-1, 0x1.ef43bep-2, -0x1.8f0178p0, 0x1.0c3df8p-3, 0x1.6eb20ap-2, 0x1.390702p0, 0x1.c610a4p-2, -0x1.6687b6p0, 0x1.7c64bcp-1, 0x1.0631a4p-1, 0x1.d051bap-5, -0x1.c4ddaep-1, 0x1.390b6cp-4, 0x1.94d4c4p0, -0x1.5a255ap-2, -0x1.a903aep0, 0x1.dc7524p0, -0x1.64a306p0, -0x1.ca0fc2p0, -0x1.5be15cp0, 0x1.bf949cp-1, 0x1.0879dap0, -0x1.2e9c3ep-1, 0x1.4dc64ap0, -0x1.ef293ap0, 0x1.a4947ep0, 0x1.af5f44p0, 0x1.c6ed3ap0, 0x1.5b3afcp0, -0x1.ec89f4p0, 0x1.ac235cp0, -0x1.b97e4ep-2, 0x1.bb61ccp-5, 0x1.75f6e6p-2, 0x1.20d892p0, -0x1.aaef54p0, -0x1.4c807ep-6, -0x1.573492p-1, 0x1.c32602p-3, 0x1.73d86cp0, 0x1.f54f28p-1, -0x1.6f9b2ap-2, 0x1.d4febap-2, 0x1.4640c2p0, 0x1.f1bf28p-1, -0x1.9c28cep-1, 0x1.b886e8p-2, 0x1.c35e8ap-1, 0x1.0768a4p0, -0x1.49e032p0, 0x1.84a09ap-2, -0x1.4e779ep-2, 0x1.051968p-1, -0x1.49b99p0, -0x1.beda08p-1, -0x1.fdbbc4p-1, -0x1.3043e6p-1, 0x1.c85024p-2, -0x1.cab6a8p-2, -0x1.74fdep-3, -0x1.04062cp0, -0x1.70f2bap-2, -0x1.03682ap-1, 0x1.809eeap-1, 0x1.123342p-1, 0x1.e94142p-2, -0x1.881172p0, 0x1.0b65cep0, -0x1.565734p0, -0x1.c03dep-2, 0x1.6b1a8cp-1, 0x1.8298e8p0, 0x1.29ffcap0, -0x1.4c63c2p-1, -0x1.a6d9dcp0, -0x1.131426p0, 0x1.8ab28p0, 0x1.0c334ep-1, -0x1.0c8e22p0, 0x1.ed1a8cp-2, 0x1.ab45bcp0, -0x1.286b8p-1, 0x1.51e776p0, 0x1.7ea8eap0, 0x1.72d81p0, -0x1.2d4a1ap-1, 0x1.10c764p0, 0x1.9aca2ap-1, 0x1.eb2e5ap0, 0x1.c3183ep0, -0x1.493266p-1, -0x1.93d464p0, -0x1.49fc4ep0, -0x1.1c8f6ep0, 0x1.bbfaa4p-2, -0x1.524e4cp0, 0x1.95ec82p0, 0x1.91dd5ep-1, 0x1.6607d4p0, -0x1.0a552p0, -0x1.715198p0, 0x1.6b4646p-4, 0x1.9ec3e8p-1, -0x1.d25e78p0, -0x1.acb402p-4, -0x1.ac5da6p-3, -0x1.202136p0, -0x1.07db54p-2, -0x1.42d556p0, -0x1.e646acp0, 0x1.751ac2p-2, -0x1.a8ec1p-1, -0x1.d12c52p0, 0x1.c3564p0, 0x1.9d8324p0, -0x1.57ca12p0, 0x1.e34428p-4, -0x1.27c77cp-2, 0x1.75d87p-1, 0x1.834f38p0, 0x1.fa1154p0, 0x1.586736p-3, -0x1.bfedap0, 0x1.32ba88p-1, -0x1.5f8afep0, -0x1.5b8db2p-1, -0x1.57c2d2p0, -0x1.3ebdbep-2, 0x1.d27d42p0, -0x1.76cabp-3, -0x1.862762p-2, 0x1.f7601ep-1, -0x1.548efep-2, -0x1.62a3a4p0, -0x1.3b271ap0, 0x1.204e6p0, 0x1.e147bcp0, 0x1.3ecee8p0, 0x1.59f9c6p-1, 0x1.00e30cp0, 0x1.cb8abcp-1, 0x1.0607c8p0, 0x1.4d477ap-1, 0x1.8ebd92p0, -0x1.d3fbeap-1, -0x1.72ecf4p0, -0x1.c4fa36p0, 0x1.971fc8p-1, -0x1.20b972p-3, -0x1.824ad2p-3, -0x1.00de4ep0, -0x1.7e2082p0, 0x1.28555p-2, -0x1.02cebap-1, -0x1.4c054ap-1, -0x1.80d1aap-4, -0x1.027746p0, -0x1.cdd99ap0, -0x1.cfcd42p0, -0x1.696c88p-2, -0x1.b610e6p-1, 0x1.bb51f2p-1, -0x1.58e854p-1, -0x1.2922eap-1, -0x1.a9919p0, 0x1.753e9cp0, 0x1.bca2c4p-1, 0x1.c64382p0, -0x1.7aecaap-3, 0x1.750f8p0, -0x1.5a660cp0, -0x1.464176p0, 0x1.dd80bap0, -0x1.62b57ep0, -0x1.6e3eb8p0, -0x1.d827ecp0, -0x1.30340cp0, 0x1.34e1bcp0, 0x1.ea7c6ep0, -0x1.a6e3e4p0, 0x1.006bcp0, -0x1.613108p0, -0x1.51bd96p-1, -0x1.26858ep0, 0x1.47486ap0, 0x1.47d18cp0, 0x1.0caaaap-2, -0x1.ca7de4p-2, 0x1.392d9ep-2, -0x1.f1b07ep0, -0x1.1f7d9cp-2, 0x1.b56fd6p-4, -0x1.23f4ap-1, 0x1.c3ee1p-2, -0x1.e04036p-1, 0x1.db9fc6p-4, -0x1.f6edep-1, -0x1.4db708p0, -0x1.0ab736p-4, -0x1.dbd0bp0, 0x1.cdff94p-2, 0x1.206cap0, -0x1.0c833cp-3, 0x1.c3ae16p0, 0x1.42595p-5, -0x1.7e2062p-2, 0x1.a5d7dap0, 0x1.972aeep-5, -0x1.9cb0c8p-6, -0x1.c4f97ap0, 0x1.8f348cp0, -0x1.518292p-1, 0x1.d68db6p0, 0x1.946658p0, -0x1.5a16fep-5, 0x1.6a6a8ep0, -0x1.9010d4p0, -0x1.3aeb4cp-5, 0x1.02fdaap-4, 0x1.6f36bep-1, 0x1.d1e0bap0, 0x1.f68738p0, 0x1.4ffc78p0, -0x1.e0c1eep0, -0x1.745afep0, -0x1.fe323ep0, 0x1.c326dep0, 0x1.109476p0, 0x1.177f2p0, -0x1.d593b8p-2, 0x1.f54864p-1, 0x1.701dacp-1, -0x1.b7d23cp-1, 0x1.a81a74p0, 0x1.4bc2b2p0, -0x1.454b3ap0, 0x1.0b3494p0, -0x1.b2c868p0, -0x1.3fa64p0, 0x1.818c76p-1, 0x1.d376bcp0, -0x1.b19408p0, -0x1.7f5e6ep-1, 0x1.c5cf98p-1, -0x1.dc4794p0, 0x1.393936p-1, -0x1.b17ebep-1, -0x1.74ef36p-2, 0x1.b9d46p-2, 0x1.97517ap-2, -0x1.49ab7cp0, -0x1.534db6p-1, 0x1.e04a92p0, 0x1.888fe4p0, -0x1.e2b896p0, -0x1.bd2fc4p-1, -0x1.071098p-3, -0x1.10db42p-1, -0x1.f89f38p0, 0x1.64bb88p-1, 0x1.1bf3dp-1, -0x1.6bab14p0, -0x1.75ded2p-1, -0x1.62e0aap-1, 0x1.e50504p-1, 0x1.eb2d32p0, 0x1.8f9a7ap-1, 0x1.67716p0, 0x1.c7a4f2p-1, 0x1.18f828p0, -0x1.c91e24p-1, 0x1.d3f06ep-1, -0x1.3a8a8cp0, -0x1.aa8094p0, 0x1.6adaaap-1, 0x1.740a2p0, 0x1.f00d4ap0, 0x1.29fde6p0, 0x1.33a236p0, 0x1.720262p0, 0x1.a55d38p0, 0x1.687c98p-1, -0x1.9cddeap-4, -0x1.5770e4p-1, -0x1.3fdc0ep-1, 0x1.900ee6p-7, -0x1.e08dcp-1, 0x1.73e54ep-1, 0x1.e3d15ap0, -0x1.054a26p-1, 0x1.b09ee4p-8, 0x1.f1b124p0, 0x1.ecee78p0, -0x1.8dd8e4p0, 0x1.18cec6p0, -0x1.bd7516p-2, -0x1.4b7ca6p0, 0x1.27cfdp-1, 0x1.3c3778p0, -0x1.f6d2c8p0, -0x1.5c844p0, -0x1.c38edp0, -0x1.53affap-1, -0x1.ab9f44p-4, -0x1.51e91cp-1, -0x1.e6f184p-1, -0x1.4c1d7ap-3, -0x1.0df72ep0, -0x1.b3ed82p0, -0x1.3c0adcp-4, 0x1.95f5f2p-3, 0x1.943816p0, 0x1.82fdf2p0, 0x1.268a2ap-1, -0x1.2ce898p-1, -0x1.7be0dcp-2, 0x1.a5a182p-4, 0x1.08d6d8p0, -0x1.6efe4cp-1, -0x1.2a4742p-1, 0x1.4fc784p0, -0x1.3220fcp-1, -0x1.b5443p-2, -0x1.6721ecp0, 0x1.9da54ep-4, -0x1.612152p0, 0x1.ee70a8p0, 0x1.33a8c8p0, 0x1.f001ccp0, -0x1.f2e824p0, -0x1.a8faa2p0, -0x1.83e042p0, -0x1.20197p-1, -0x1.552558p0, 0x1.328d04p0, 0x1.584ecp0, -0x1.b1cfap0, 0x1.0cd914p-1, -0x1.0a852p0, 0x1.e31118p0, 0x1.789b04p-1, -0x1.f2d832p0, -0x1.6ccd94p0, -0x1.0a1f8ap0, -0x1.f89464p0, -0x1.b716c6p0, 0x1.c23ddcp-3, 0x1.d933ccp0, 0x1.977186p0, -0x1.61438ap-1, -0x1.52fd7p0, 0x1.a8f306p0, 0x1.426ebcp0, 0x1.2cb362p-1, 0x1.e6d6acp0, 0x1.5e5afcp-1, -0x1.e8eafep-6, -0x1.23bc2p0, 0x1.11f39ap-2, 0x1.335e96p-1, -0x1.f53a86p0, -0x1.3c11d4p-3, 0x1.38a6d2p0, 0x1.da8698p0, 0x1.be1f9cp-2, 0x1.e6b7dcp-2, 0x1.496df2p-1, 0x1.7cfc4p-4, 0x1.9f0c62p-1, 0x1.4e49b4p0, 0x1.776f88p0, 0x1.19463ap-2, -0x1.57afeap-2, 0x1.17ff72p0, -0x1.c98ec6p-2, 0x1.90a088p0, -0x1.28b3ccp0, -0x1.cd195cp0, 0x1.f79346p-1, 0x1.1a4fd2p-2, -0x1.38caa6p-1, -0x1.9443cep-1, 0x1.20c2e4p-3, -0x1.a29ebp-2, 0x1.d03edcp0, 0x1.4398dp-1, 0x1.fe49bcp-1, -0x1.96a67p-1, 0x1.d1bb9ap-1, 0x1.03f5aep-2, -0x1.99ab74p-2, -0x1.c71842p-1, -0x1.20cbc4p0, -0x1.384c7ep0, 0x1.6f72ecp-2, 0x1.48a06ap0, -0x1.ad7c18p-1, -0x1.4e7f2ep0, 0x1.e2e3eap-4, -0x1.f2e00ep0, 0x1.e7c11p-3, -0x1.572372p-1, 0x1.0d8d2p-3, 0x1.6df01ep-2, 0x1.ffea6p0, -0x1.db943ep0, -0x1.915e52p-2, 0x1.388faap0, 0x1.8593d2p0, -0x1.c356c8p-2, 0x1.e8f13ap-2, 0x1.07729p0, 0x1.fce124p-2, 0x1.b67b12p0, 0x1.eb1216p0, -0x1.152bc2p-1, -0x1.04b972p0, -0x1.f7f48ap0, -0x1.c42fdap0, -0x1.5b8fd8p0, -0x1.dc29e4p-1, 0x1.444518p-3, 0x1.118504p0, 0x1.4725c8p-3, 0x1.6894c8p0, -0x1.e86c98p-2, -0x1.d017e2p-1, 0x1.7c7054p0, 0x1.76c0ecp0, 0x1.ed3e78p0, 0x1.34e66cp0, 0x1.a83938p0, 0x1.a4f33ap-1, 0x1.ef2f56p-2, -0x1.33a89ap-1, -0x1.08df56p0, -0x1.478f5ep0, -0x1.1e86f6p0, 0x1.8a1d18p0, 0x1.c21916p0, -0x1.d7d6e4p0, 0x1.7b5d26p0, -0x1.d7f23p0, 0x1.918d94p0, -0x1.a8abccp0, -0x1.fcb7cap-4, 0x1.391c76p-3, -0x1.29c6eep0, -0x1.f1cf8ap0, -0x1.879e16p0, 0x1.1af0eap-1, 0x1.820214p0, 0x1.d3fc1cp-3, -0x1.e7243p0, 0x1.eac7a4p-1, 0x1.f07f26p-2, 0x1.8ea964p-1, -0x1.d91f78p-8, 0x1.93b3aep-1, -0x1.9e6128p-1, 0x1.3d5538p-4, 0x1.c2cd46p-2, 0x1.a8ffdp-2, -0x1.8f0e9cp0, -0x1.c6feb8p0, 0x1.7f7a2p-1, 0x1.0da2fap-5, -0x1.5c45bcp0, 0x1.e2629p-2, -0x1.56b228p0, 0x1.aaac5p0, 0x1.16be9p0, 0x1.26270ep-1, -0x1.083952p-1, -0x1.ded65p-1, 0x1.483744p-1, -0x1.11397ep0, 0x1.ff94a6p0, 0x1.772464p0, -0x1.28bcp-2, -0x1.5eeb88p0, 0x1.ac7fb6p0, -0x1.02ca12p0, -0x1.df702cp0, -0x1.2196cap-1, -0x1.e71bdp0, -0x1.b6a26cp-1, -0x1.6aec22p-1, 0x1.b92dep-4, -0x1.b13ef4p-1, -0x1.b41af4p0, 0x1.bdf1ap0, 0x1.4d7f44p-2, 0x1.53c554p0, -0x1.f1dd8ep-4, 0x1.b035e2p-1, -0x1.8880e2p0, 0x1.8cedbp0, -0x1.0c042cp-1, 0x1.05ec96p0, 0x1.428b22p-1, 0x1.2c017ep-1, -0x1.42f514p0, -0x1.f5ee02p-1, 0x1.59c22cp-1, -0x1.41bdf2p-1, 0x1.efafaap-1, -0x1.8ce32cp0, -0x1.245534p0, 0x1.82010ap-1, 0x1.35f154p-3, 0x1.5aa692p-1, -0x1.bb7ddp0, 0x1.26fcb6p0, -0x1.9b70dp0, -0x1.cc17fep-2, -0x1.39f95cp-4, -0x1.e236f2p0, -0x1.9ce152p-2, 0x1.9b3aa4p0, 0x1.0a24a8p0, 0x1.697d0cp0, -0x1.b3905p-2, 0x1.c69678p-1, 0x1.08d25ep-1, -0x1.323348p-1, 0x1.e111d8p0, 0x1.a9aac6p0, -0x1.7189c4p0, 0x1.9421c2p-2, 0x1.60c436p0, -0x1.68206ep0, 0x1.34b66cp-2, 0x1.8df34p-2, 0x1.e7cc0cp-2, -0x1.a36cf8p-1, -0x1.2c367ep0, 0x1.117e06p-4, -0x1.1b63ccp0, -0x1.e8d642p-2, -0x1.99f5aep-3, -0x1.4e3816p-2, -0x1.4c85e6p-3, 0x1.a92e88p0, 0x1.f88916p0, 0x1.11d7acp0, 0x1.718c9p0, 0x1.5377dcp0, 0x1.2968dep0, -0x1.96afc2p-2, -0x1.7865bep-1, 0x1.04b0aap-1, 0x1.3c7d84p-1, -0x1.fb4314p0, -0x1.50c67cp0, -0x1.a0d25ep-2, 0x1.0c2cf8p-2, 0x1.43451ap0, 0x1.3dac58p-3, 0x1.a4094ap-1, -0x1.515ab6p-1, -0x1.b89cfep-6, -0x1.cfcdb4p-4, 0x1.d2090ep0, 0x1.2dd2d2p0, 0x1.561e24p0, 0x1.d011fap-3, 0x1.497962p0, -0x1.107e48p-2, 0x1.212e16p0, 0x1.34adc2p0, 0x1.a3416cp-2, -0x1.1bac08p-1, -0x1.151442p0, 0x1.77b96p0, 0x1.73f02cp0, 0x1.408178p0, 0x1.9776d8p0, -0x1.b6302ep-2, 0x1.af066p-5, -0x1.7ba314p0, -0x1.e2dbeap-1, 0x1.50fab6p-1, -0x1.612058p-4, -0x1.2380dp0, 0x1.6203fp0, -0x1.993e3cp-4, 0x1.10b856p0, -0x1.6d2196p0, 0x1.99cf16p-2, 0x1.0297b2p-1, -0x1.90398ap-1, 0x1.64c32ep0, 0x1.5f85f8p0, 0x1.197bdap-3, 0x1.126accp0, 0x1.fd6282p0, 0x1.67bbccp-1, -0x1.5b73bap-1, 0x1.dcce46p0, 0x1.de3cf2p-1, 0x1.fef33p-2, -0x1.546c6p0, -0x1.2302a2p-1, 0x1.f4a66cp0, 0x1.8c36d2p-1, 0x1.7cf45cp0, -0x1.3b275p0, 0x1.8b8fcap0, 0x1.4564dap0, 0x1.9dd1f8p-1, -0x1.2d9edp-1, 0x1.ecc436p-1, 0x1.dd3e22p-1, -0x1.0952d6p0, 0x1.b9abbap-1, 0x1.e789a8p0, -0x1.dcc4f2p0, 0x1.e4eaf8p0, -0x1.b76bap0, -0x1.b0add2p-1, -0x1.7c7d3ep-3, 0x1.3929d4p0, -0x1.33f0e6p0, 0x1.514c3ap0, 0x1.9b19fap0, -0x1.08174ap-1, -0x1.c3be32p-1, -0x1.2d827cp0, 0x1.3537ccp-2, -0x1.918e5cp0, -0x1.e19286p0, 0x1.81c4d8p-1, 0x1.fd5de8p-2, 0x1.e18dbap-3, -0x1.144672p-2, -0x1.0cc368p-1, -0x1.820f08p-3, 0x1.2ba58ap0, -0x1.21f45p0, -0x1.29066p0, -0x1.6e004ap-1, 0x1.a8cac6p-1, 0x1.2e24f4p0, 0x1.c5c2aap-2, 0x1.bcc1f4p0, 0x1.8feda6p-2, 0x1.294592p-2, 0x1.a7409p0, 0x1.796cfep-3, -0x1.3688bap0, -0x1.a4ba9ep-1, -0x1.845ddap-3, -0x1.ba671ap0, -0x1.78562ap-1, -0x1.6d86ep-1, -0x1.48c31ep0, 0x1.af2a04p-1, -0x1.fdb238p0, -0x1.65c9cep0, -0x1.8317e2p0, -0x1.01a00ap-1, 0x1.44eb4p-3, -0x1.b4fb28p-1, 0x1.634b32p-1, -0x1.d4299ap0, 0x1.0f1436p-1, 0x1.1f6432p-1, 0x1.361b8ap-1, -0x1.71b77p0, -0x1.15da26p-1, -0x1.b855fep-3, -0x1.489d84p-1, -0x1.0debc6p-1, 0x1.45a062p-3, -0x1.4648aep0, 0x1.6d10cp0, 0x1.6231bep-1, -0x1.3a73a6p0, -0x1.91447cp-4, -0x1.fa820cp0, 0x1.a18816p-1, -0x1.bfe5d4p0, 0x1.39fe84p0, 0x1.ae45a6p-1, -0x1.26144ep0, -0x1.39cd2ap-5, 0x1.bf4efcp-1, -0x1.dde09ap-3, -0x1.054a64p0, -0x1.d228a4p0, -0x1.30698cp0, -0x1.f3905ap-2, -0x1.add1d4p-2, 0x1.7959e2p0, -0x1.1423f2p-3, -0x1.d76942p-7, -0x1.1b4dcp0, -0x1.c52c78p-1, 0x1.69e91cp-2, 0x1.23a574p-1, 0x1.eb3c64p-1, -0x1.d26c2ep0, 0x1.f8267cp0, 0x1.b2bd72p0, 0x1.2cd19ap-1, 0x1.0f2adp-1, 0x1.7fbeeep0, 0x1.664c8p0, 0x1.641a8ep0, 0x1.5db66ep0, -0x1.926374p-1, 0x1.df269ap0, -0x1.755a44p-4, 0x1.d92e5ap-4, 0x1.ee72cep-1, 0x1.18a8eep-1, -0x1.0ce26ap-1, -0x1.457d68p-1, 0x1.7a8ab2p-2, -0x1.0e4142p-1, -0x1.1aa148p-4, -0x1.a1a6eep-1, -0x1.89fd78p0, -0x1.3b4748p-2, 0x1.4a6484p-1, -0x1.fbad9cp0, 0x1.091152p-5, 0x1.19ff44p-2, 0x1.ae61aep0, 0x1.29aee4p-1, 0x1.b6b29ep0, -0x1.3cedfap0, 0x1.0870fep-1, -0x1.148a78p-1, -0x1.1b9fecp0, -0x1.d068c4p-1, -0x1.9b8abcp0, 0x1.545142p0, -0x1.c69fb4p0, -0x1.f1991cp0, 0x1.11a1dp0, 0x1.ee5a5cp-3, -0x1.94e6dp0, 0x1.66396cp-1, -0x1.4d054p-1, -0x1.bd8ad8p0, 0x1.6d5d3ap-3, 0x1.ca0a14p0, 0x1.004758p0, 0x1.2d9d22p0, -0x1.4c0a66p0, 0x1.b0e064p-1, 0x1.666f38p0, 0x1.eff7b4p-1, -0x1.1d0efp0, 0x1.589aa4p-1, -0x1.0ed54ap0, 0x1.358fdep-1, -0x1.28dee4p-1, -0x1.46b62ep0, -0x1.b40b06p0, -0x1.60fed2p0, 0x1.0a84f4p-4, -0x1.914ef8p-1, 0x1.9d9428p0, -0x1.5e8beep0, 0x1.5d376p-4, -0x1.869696p-2, 0x1.4e27aap-1, 0x1.2eb8aap-2, -0x1.af38ep-2, -0x1.2fb012p-3, -0x1.4eed2cp-1, -0x1.efc46cp-2, 0x1.923dd2p0, 0x1.a8dfc8p-1, 0x1.f28eb6p-2, -0x1.6de188p0, -0x1.c6ca8p0, -0x1.57bbc6p-1, 0x1.9a49b4p0, 0x1.08a2eep0, -0x1.9695fp0, -0x1.2c692ep-2, -0x1.457206p0, -0x1.743944p-2, -0x1.78118ep0, 0x1.ca6eccp0, -0x1.fa8d58p-1, -0x1.ca334p-1, 0x1.066702p0, 0x1.4724aep0, -0x1.edfa3cp0, 0x1.ad3798p-1, -0x1.9a7606p-2, 0x1.e2bde4p-1, 0x1.8923d2p0, 0x1.c8af36p0, 0x1.adf6a6p-2, 0x1.4e0c0ap0, -0x1.047062p-1, 0x1.872876p0, -0x1.dc13c6p0, -0x1.472af8p-3, 0x1.948c8ap-1, -0x1.5f35f2p0, 0x1.60a062p0, -0x1.1933a6p-1, 0x1.83434p-1, -0x1.60276p0, 0x1.7c8708p0, 0x1.6d5cbep-1, 0x1.1c08d6p-4, -0x1.8d0e42p-2, 0x1.58c182p0, 0x1.b5507cp0, 0x1.682ecp-5, 0x1.9ea5p-3, -0x1.3e20a6p-3, 0x1.997e3p-5, -0x1.c00d64p0, 0x1.574956p0, -0x1.33df64p0, -0x1.1b79e6p-1, -0x1.302d08p-2, -0x1.b78b3ap-2, 0x1.827e8ap0, 0x1.53b33cp0, -0x1.d708fp0, -0x1.d4892p0, -0x1.18183ap0, -0x1.f78ec2p-2, -0x1.05d13p0, 0x1.aee2cep-7, -0x1.4053aap0, -0x1.573e16p0, 0x1.0c1c98p-1, 0x1.b1ef1cp-1, -0x1.34df9ep0, 0x1.a84048p-1, -0x1.81f49cp-1, 0x1.e5b494p-1, -0x1.4f22acp0, 0x1.7a7322p0, -0x1.85d788p-7, 0x1.c110dap-2, -0x1.621284p-5, 0x1.7ba786p0, -0x1.7cc2dp-1, -0x1.6145d2p0, 0x1.f064c2p-7, -0x1.dcc106p0, -0x1.507dep-1, 0x1.f2b9c6p0, -0x1.eb97dap0, 0x1.101a72p-1, -0x1.0c35bp-1, 0x1.d77fcp-5, 0x1.0dcc0ep-1, 0x1.264d98p0, -0x1.e7f89cp0, -0x1.1f5c0cp0, -0x1.246a14p0, -0x1.8b358p-2, 0x1.18ecf6p0, -0x1.3f2ed8p0, -0x1.dc06d6p-1, 0x1.d01b4ap0, -0x1.1f41acp-5, 0x1.52871ep-1, -0x1.fc78cep0, 0x1.8231f8p0, -0x1.ea1cb2p-1, -0x1.2aba04p0, 0x1.370976p-2, -0x1.838936p0, 0x1.eb3ae4p-1, 0x1.afb666p0, -0x1.a30a5cp-2, 0x1.0e81ep0, -0x1.bfad34p0, 0x1.b3ba7p-1, -0x1.11695ap-5, -0x1.88663cp0, 0x1.86c22p0, 0x1.a7545ep0, -0x1.a67ep-2, 0x1.d72a28p0, 0x1.59a66ep0, 0x1.9d4f96p0, 0x1.941ac8p-1, -0x1.e8d5aap0, -0x1.4e0232p-3, -0x1.7510d2p-2, 0x1.b6b8d8p0, -0x1.f1b7bp0, -0x1.ebac82p-1, 0x1.14b236p-1, -0x1.724356p-1, -0x1.04b388p-1, 0x1.a49b02p-1, -0x1.31802ep0, -0x1.4238cp0, -0x1.58d4cp-2, -0x1.565444p0, -0x1.6e5adep0, -0x1.cd5754p0, -0x1.f70934p0, 0x1.4fcf5cp-1, -0x1.2fb402p-1, 0x1.5444bap0, -0x1.9df142p-1, 0x1.b83032p-3, 0x1.11ae5cp-1, -0x1.925fd8p-1, -0x1.0860a8p0, -0x1.e96a46p0, -0x1.842802p-2, -0x1.c99c5cp-3, 0x1.c56bfp0, 0x1.c1b094p-2, -0x1.d2ec4cp0, 0x1.a668e8p-2, 0x1.730b8ap0, 0x1.03a21p-1, -0x1.6f4cc2p0, -0x1.1d1352p-3, 0x1.cc6c92p0, 0x1.d1994p0, 0x1.1e0d2cp0, 0x1.699eeap0, -0x1.2d5a34p0, -0x1.3a7ddap0, 0x1.9f84e2p0, -0x1.dc14c8p-1, -0x1.46228cp0, -0x1.10bed8p0, 0x1.15dc9ep-2, 0x1.5e2e44p0, 0x1.4bfd52p-2, 0x1.67a16ap-1, 0x1.81f9ccp-3, 0x1.a2e71ap-2, 0x1.a6a5ccp-1, 0x1.eac9c2p-3, -0x1.ebad46p0, 0x1.5da636p0, 0x1.c2eb24p-2, -0x1.709658p-1, -0x1.f22204p0, 0x1.c9b394p0, -0x1.d449b2p0, 0x1.8ab32cp-2, -0x1.d4dd2cp0, -0x1.bcbc6p-2, 0x1.5fa096p-2, 0x1.dd4522p-5, 0x1.248966p0, -0x1.a965a4p0, -0x1.33546cp-2, 0x1.654df8p0, 0x1.3ba72cp-1, -0x1.75ef8p0, -0x1.c34592p-2, -0x1.db1a9ep0, -0x1.0ceacap0, -0x1.9b7786p0, -0x1.eddf4p-1, -0x1.a82378p-1, -0x1.d5101ep0, 0x1.e8f59cp-1, -0x1.14bbccp-3, -0x1.8e1aap-1, -0x1.eeda72p0, -0x1.8a073cp-1, 0x1.59a024p-1, 0x1.39ca46p-4, 0x1.bc8444p0, 0x1.0baa48p0, -0x1.9753fep0, -0x1.e6638cp0, -0x1.dd27e8p-5, -0x1.c9ec2ap-2, -0x1.8a1cbep-1, 0x1.3482a8p-1, 0x1.0a5f7ep-1, -0x1.28e886p0, -0x1.cd2398p-4, 0x1.e68468p0, -0x1.bbeec4p0, -0x1.6c91bap0, 0x1.e9fa5ep-1, -0x1.7ce558p0, -0x1.780a8cp-1, 0x1.8857ep-1, 0x1.730a7ap0, 0x1.6b0e8ep-1, -0x1.0f05cep-2, -0x1.1a8a44p-1, 0x1.61dcc8p-1, 0x1.07450cp0, -0x1.8e6eep-1, 0x1.86516p0, 0x1.f43664p0, 0x1.363fe8p-2, -0x1.58b5c8p0, 0x1.684256p-8, -0x1.180d2ep-1, -0x1.9cf1bcp0, -0x1.57d528p-5, 0x1.c71c6ap-1, 0x1.11e20ep0, 0x1.5dc41p0, 0x1.9fe45ep0, -0x1.438eecp0, 0x1.01553ap0, -0x1.300dd4p0, -0x1.3eae2ap0, 0x1.6ddfbep-1, 0x1.cd6e68p0, -0x1.29c772p0, -0x1.6f1054p-1, 0x1.4d1b84p0, 0x1.58095cp0, 0x1.58cddp-2, 0x1.8033p0, -0x1.f92ebap0, 0x1.aadb84p0, 0x1.5fd5acp-2, 0x1.dfb418p0, -0x1.6034f8p0, 0x1.064b12p-1, -0x1.68e8fep0, 0x1.0ff986p0, 0x1.9400f2p0, 0x1.0f5932p-2, -0x1.35f3ccp0, -0x1.13f3ecp0, 0x1.eb5254p-2, -0x1.07bc52p-1, 0x1.744a68p-2, 0x1.973bcep-2, -0x1.4e9364p-2, -0x1.27c4p-1, 0x1.1ef2aap-2, -0x1.2877ep-4, -0x1.b6c932p-4, 0x1.19d05ap-1, 0x1.349366p0, 0x1.c2844cp0, -0x1.ee65cep0, 0x1.07edeep0, 0x1.1cad0ap0, 0x1.216b88p0, -0x1.c26938p0, 0x1.7ba21ep-3, -0x1.bfc09cp0, -0x1.f2989ap-7, 0x1.f68df6p0, -0x1.9e3c7ap-1, -0x1.fddccp0, -0x1.7d4a84p0, -0x1.570962p0, -0x1.a4fc3p0, 0x1.3b56acp-7, -0x1.8b77bcp0, -0x1.499b7p0, 0x1.1fbe56p0, 0x1.58f9eap-1, -0x1.2f855ap-1, 0x1.f1c1dcp-2, -0x1.2a6aa2p0, 0x1.c66622p-1, -0x1.addbdp-3, -0x1.3a9e04p0, -0x1.d4e574p-1, 0x1.3b9e7cp0, 0x1.17b17p-2, -0x1.078038p0, -0x1.a27c66p0, -0x1.d4a892p0, 0x1.f9352p0, -0x1.199592p-4, 0x1.992b36p0, -0x1.1ca27p0, -0x1.055b68p0, -0x1.abce9p-2, 0x1.20b9cep0, 0x1.787cdcp-1, -0x1.38e7p-1, 0x1.63ee0ep-1, -0x1.ae2534p-1, -0x1.59e598p-1, 0x1.0b4cbcp0, -0x1.e089cp0, 0x1.b057a2p-2, 0x1.13dd9ep-3, -0x1.156436p0, -0x1.26a922p0, -0x1.f6b298p-1, -0x1.986a5ep0, -0x1.47013cp0, 0x1.cb20f2p-1, -0x1.b3b7bp-2, -0x1.7c5426p-2, -0x1.f3fc04p0, 0x1.905b4p-1, -0x1.1dd4acp-2, 0x1.ca5e1p-5, -0x1.255254p0, 0x1.0de6b6p0, -0x1.8b7b2cp0, 0x1.c89e6cp0, -0x1.30d884p-2, -0x1.3bf4f8p0, 0x1.d3babcp-1, 0x1.dc1c76p0, 0x1.b5319cp0, 0x1.dc8ae6p-1, -0x1.a25942p-2, -0x1.5da718p-4, 0x1.75bfa8p0, 0x1.74c396p0, 0x1.5ecb2cp0, 0x1.fafcaap0, 0x1.c2e8b6p0, -0x1.59d9fep-1, -0x1.b61e66p-4, -0x1.a6ecd6p0, 0x1.364de2p0, -0x1.7503aap0, -0x1.821914p0, 0x1.a60058p-1, 0x1.1cb68ap-2, 0x1.34bad6p0, 0x1.8d2aaep0, -0x1.33ca7ap-2, -0x1.bb1436p-1, -0x1.fb2fd2p-3, -0x1.1ca2c8p-5, 0x1.c2936p-1, -0x1.59cdaap-2, 0x1.ad98c6p0, 0x1.c6ecfep-1, -0x1.6ec6c8p-2, 0x1.81a3eep-4, -0x1.ecefbp-1, -0x1.263748p-1, 0x1.161c52p0, 0x1.0031fp0, -0x1.d9bf7cp0, -0x1.b98c4ap0, 0x1.dfb388p0, -0x1.0f373p-1, 0x1.ec13bcp0, 0x1.30e76ap0, -0x1.7d8d26p-1, -0x1.e43de8p-1, -0x1.34b13p-4, -0x1.1030c2p-1, -0x1.04b72cp-1, -0x1.281d74p-4, -0x1.40c6fep0, -0x1.9c6faap0, -0x1.4b3ffp0, 0x1.d449d2p-1, -0x1.c3244ap0, -0x1.25540ap-1, 0x1.742166p-4, 0x1.8e6db4p-2, 0x1.9c728ep0, 0x1.14cf04p0, -0x1.f14296p-3, 0x1.d4389cp-2, 0x1.160158p-3, -0x1.0e3a8ap-1, 0x1.acdb4cp0, -0x1.ad9922p0, 0x1.177858p0, 0x1.0197a8p-1, 0x1.def5bp-2, -0x1.1c3144p0, -0x1.abb0bap0, -0x1.66443ap0, -0x1.d31f9p0, -0x1.380392p0, -0x1.4af3d6p0, -0x1.17526p-3, -0x1.836548p0, 0x1.df9ce2p-2, -0x1.d77a0ep0, -0x1.23da74p0, 0x1.4acdf4p0, -0x1.1ffd36p-1, -0x1.b712eap-2, -0x1.b50816p-3, 0x1.b7f302p0, 0x1.20fbe2p0, 0x1.ff0904p0, 0x1.65596ep-1, 0x1.db73acp-1, -0x1.172294p0, -0x1.526a5p-1, -0x1.dff1a2p-3, -0x1.45cc04p-5, 0x1.4fdf5ep0, -0x1.b7353ap-2, -0x1.efc9ap-3, 0x1.809a46p0, 0x1.cdc272p-6, 0x1.3eb684p0, -0x1.4b76cap0, -0x1.9c7a64p-3, -0x1.885a2ap-1, 0x1.0f95d4p-1, 0x1.4ce938p0, -0x1.a56f54p0, 0x1.445eecp-1, -0x1.87d3bap0, -0x1.09627p0, -0x1.7fffd4p-4, 0x1.5a55bap-6, 0x1.6c6612p-2, -0x1.c80822p-2, 0x1.c3afe4p-2, 0x1.1bccccp0, -0x1.f38398p0, 0x1.205cap0, 0x1.530716p0, -0x1.2f03fep-3, 0x1.eb53fp0, -0x1.90bcdap0, 0x1.39a8acp0, -0x1.a6aa92p-1, 0x1.585372p0, 0x1.142c2ep0, -0x1.05047p-3, -0x1.6f6b34p0, 0x1.fd780ep0, -0x1.22d5fp-1, -0x1.5dff58p-1, -0x1.9f89fep0, 0x1.4622a2p-1, 0x1.b10c3cp-4, 0x1.6d9756p-4, -0x1.ab3f36p0, -0x1.846408p-2, 0x1.7f891ap0, 0x1.61bb7p-3, 0x1.34e8fp0, 0x1.49496ep0, 0x1.e87d2cp0, -0x1.400ff8p0, -0x1.afc15ep-1, -0x1.fe0346p0, 0x1.3127cap0, -0x1.582996p-2, 0x1.cf5a26p-3, -0x1.bd5c22p-2, -0x1.82490ep0, -0x1.c8d284p0, 0x1.a6a314p0, 0x1.78d76cp0, -0x1.28f846p0, 0x1.5d9fb4p0, -0x1.2d59e2p-1, 0x1.a5dccap-1, -0x1.fe8984p0, -0x1.50dacp-1, -0x1.ed45a6p0, 0x1.e3ef7ep0, 0x1.0d35dap-1, -0x1.ab00aep0, -0x1.874e46p0, -0x1.8a8a64p0, -0x1.98f178p0, 0x1.a6df22p0, -0x1.69e534p-1, -0x1.c6018ep0, 0x1.60954ep0, 0x1.e47afap0, -0x1.b1d7a6p0, 0x1.bd563p0, 0x1.ee6906p0, 0x1.ce5068p0, -0x1.9ad934p0, -0x1.e299b8p-2, -0x1.579e46p0, -0x1.ccfe06p0, 0x1.b479ccp-4, -0x1.574a24p0, 0x1.6391f8p-1, 0x1.6a44ccp-1, 0x1.d4207ep-1, -0x1.7f0096p-3, -0x1.b24f1ap0, -0x1.7998p0, 0x1.38b0dap-5, -0x1.11a2b6p0, 0x1.5d0e66p0, -0x1.761d3p-2, 0x1.30619ap0, 0x1.c2fb3cp-1, -0x1.e5f45ep0, -0x1.280eecp0, 0x1.391f44p-1, -0x1.82a952p-1, -0x1.bb8eb6p-1, 0x1.c5b95cp-2, 0x1.b497fcp0, -0x1.e6a4fcp0, -0x1.c94768p0, 0x1.1ccda4p-1, -0x1.03585cp0, 0x1.3b28fcp-1, 0x1.0e7946p-1, -0x1.2da4bp0, 0x1.2431ccp0, -0x1.27f18p-1, -0x1.54494cp0, 0x1.3291d8p0, -0x1.974448p0, -0x1.1f0734p0, -0x1.bc1b4ap0, -0x1.600de8p-1, 0x1.7ae3acp-1, 0x1.fe384cp-1, -0x1.caaefep-1, 0x1.9be61ep0, 0x1.7309a8p0, 0x1.d33e3ap-4, 0x1.b3d9d6p0, -0x1.2b50c6p0, -0x1.738ed6p-1, 0x1.cdcf5cp-1, 0x1.cc2c5ap0, 0x1.e3daap0, 0x1.f5d892p0, -0x1.eafa94p-1, 0x1.4c00dap0, 0x1.11190ep0, -0x1.cefab8p-1, -0x1.7957dp0, 0x1.f98474p0, 0x1.87819p-1, 0x1.2ec47p-3, -0x1.3a41c8p0, 0x1.60d7ccp-1, -0x1.308824p-1, 0x1.f73344p-2, 0x1.43dff4p0, 0x1.3df75cp-1, -0x1.38457ep-4, 0x1.64ba32p-3, -0x1.c9ada4p-7, -0x1.0cf5fap0, 0x1.863858p0, 0x1.7ae3c6p0, -0x1.a0edbp0, -0x1.ea52dcp-4, 0x1.ebfaacp0, 0x1.56fbb4p0, 0x1.891804p-2, 0x1.ce19ecp-1, 0x1.80afb4p0, 0x1.1806fep0, 0x1.9f0f7ep0, -0x1.035bf6p-1, -0x1.ec010cp-2, -0x1.494e74p-10, 0x1.9b64cep0, -0x1.e3e89ap-3, 0x1.881612p0, -0x1.ab2fdcp0, -0x1.2034ccp-3, 0x1.5d3f8ap0, -0x1.57ecf8p-2, 0x1.576268p-1, -0x1.484872p-2, -0x1.5c7c0ap0, 0x1.58262cp-1, 0x1.79a292p0, 0x1.aa086ap0, 0x1.5290e6p0, -0x1.18f81cp-4, 0x1.d8c452p0, 0x1.7aa1p-2, 0x1.d9b7f4p0, 0x1.16ce7ep-4, 0x1.e664dap-1, -0x1.cc236cp0, -0x1.be5d64p-2, -0x1.260452p0, 0x1.d63c16p-1, -0x1.24ccd6p-1, 0x1.2d92ecp-1, -0x1.53781p-4, -0x1.f98154p-1, 0x1.617dfep0, 0x1.bc3e9ep0, -0x1.8707aap-2, -0x1.e6cd0ep0, 0x1.dcfb5cp-1, -0x1.c1f73cp0, -0x1.ebb5d8p0, 0x1.d053ecp0, -0x1.1a0594p-1, 0x1.b1cf5ep0, -0x1.73b014p-2, -0x1.2ce586p-2, 0x1.28a38cp-1, -0x1.9b8988p0, -0x1.01c91ap0, 0x1.d03a8ap-1, 0x1.9daa3cp0, 0x1.7fb4aap-2, -0x1.29dd14p-3, 0x1.36e4b4p0, 0x1.d86138p-1, 0x1.24ea7ap0, -0x1.0fe8c6p-3, 0x1.bfe6b8p0, -0x1.b2b75ap0, 0x1.f7df0ep-1, -0x1.11ab2cp-2, 0x1.794678p-1, -0x1.3f98e2p-3, 0x1.5dba36p0, -0x1.dd611ep0, 0x1.3e260cp0, 0x1.dcb6fp0, -0x1.17eb36p0, 0x1.eac0fap-1, -0x1.edf622p-2, 0x1.318cf2p0, -0x1.5ca8aap-1, -0x1.c0252ep-2, 0x1.ee31b8p0, 0x1.15ac98p0, 0x1.be0704p0, 0x1.1f2a68p0, -0x1.df458p-2, 0x1.363e9ep0, 0x1.b4174ap-1, 0x1.daf9ccp-2, -0x1.c8a5dap0, -0x1.b500bep0, -0x1.6e7baap0, 0x1.734aaep-5, 0x1.0dd48ep-1, 0x1.8fd08p0, 0x1.4824d6p-4, 0x1.095512p0, -0x1.eff652p0, -0x1.9e71bcp0, -0x1.03efbep0, -0x1.8cae24p0, -0x1.fe92e4p0, -0x1.15eb84p0, -0x1.30dd1ap0, 0x1.e29b16p-1, 0x1.622adcp-5, 0x1.dd4762p0, 0x1.35eb6p-2, 0x1.1d44a4p0, 0x1.5929p-3, 0x1.867278p0, 0x1.e5f5b4p-3, -0x1.b959dap0, -0x1.c1edacp-1, 0x1.715048p0, 0x1.3989d2p0, 0x1.c4bfccp-1, 0x1.dfa3ep-4, 0x1.cee7bcp-2, 0x1.d6584ep0, 0x1.d754c4p0, 0x1.4da81ep-3, -0x1.7d815ep0, 0x1.b3d2a8p0, -0x1.a6b42ap0, -0x1.dab6bcp0, -0x1.900f06p-3, 0x1.3c4e86p0, 0x1.fc97ecp-2, 0x1.8b553ap0, -0x1.38499ap-1, -0x1.bccb38p-1, -0x1.99b36cp0, -0x1.94b83ap0, 0x1.050766p-3, 0x1.5ef9eep0, -0x1.21c2aep-1, 0x1.29d5cp-5, -0x1.54f9f6p-1, -0x1.a32a44p-5, 0x1.1e79ecp0, 0x1.fbef04p-2, 0x1.65dc2cp-6, -0x1.6a8f48p-3, 0x1.d18a54p-2, -0x1.2b14e4p-2, 0x1.90887ap-1, 0x1.ac333p-1, -0x1.4e2d86p-1, 0x1.a80bc8p0, 0x1.0ca8e4p-1, -0x1.34a5cap-4, -0x1.0f0252p-2, 0x1.82b294p-1, -0x1.8c4cfcp0, 0x1.fd97c2p0, 0x1.b7037ep-1, -0x1.e46848p0, -0x1.c09b94p-5, -0x1.5b9bd8p-4, -0x1.478c12p0, 0x1.4e297ap0, -0x1.4d04a2p0, 0x1.8eb08cp-4, -0x1.0c2e38p-1, 0x1.49bbcap0, 0x1.ac3ba2p-1, 0x1.d76716p-3, -0x1.43f0d4p-1, -0x1.47f904p0, -0x1.f11fe4p0, 0x1.ef26c8p0, -0x1.f3a4bap0, 0x1.3a56a8p0, 0x1.d68bfp0, 0x1.6ed20ep0, 0x1.61b8dcp-4, -0x1.a19efcp-3, 0x1.439b82p-2, 0x1.018798p0, -0x1.528246p0, 0x1.ae29ep-4, 0x1.ad435cp-2, 0x1.aba6f4p0, -0x1.38743cp0, 0x1.e31c12p-1, 0x1.9df348p0, 0x1.a1b5e6p-1, -0x1.52e25ap0, 0x1.027e7cp0, -0x1.48c1fap0, 0x1.2cebbcp-2, 0x1.c9db18p-1, 0x1.e0f83ep-3, 0x1.c2be7cp0, 0x1.bb6bd2p-1, 0x1.22532ep-1, 0x1.aa98a2p0, -0x1.f70e3p0, -0x1.bc48a4p0, -0x1.3c3f88p-2, 0x1.c38f54p-1, -0x1.1aeadp0, -0x1.6b4178p-1, 0x1.234abap0, -0x1.3a0ceep-1, 0x1.489328p-2, 0x1.4dd9cp0, 0x1.edd5fcp-2, -0x1.46b924p0, -0x1.46ca7ap0, 0x1.53221cp0, 0x1.954d8ap-1, 0x1.244668p0, 0x1.d7aceap-4, 0x1.d24cccp0, 0x1.803fa2p0, 0x1.54406ap0, 0x1.e36908p-2, -0x1.de0956p-2, -0x1.b2cc28p0, -0x1.fd4296p-2, -0x1.f538eep0, -0x1.100ec8p-2, -0x1.b1d02ap-1, 0x1.99b232p-2, -0x1.3ec36cp0, -0x1.8bb55p-2, -0x1.30334ep0, -0x1.0de88ap0, 0x1.918328p-1, 0x1.b8556ep-1, -0x1.76cfbp-1, -0x1.65c04p-1, -0x1.7de6fcp-2, -0x1.1c3a12p0, 0x1.c395bep-2, 0x1.fdb892p0, 0x1.3117aap0, 0x1.0dcb9cp0, 0x1.6b3d6cp0, 0x1.2004d6p0, -0x1.87ec78p-1, 0x1.6b04f4p-4, 0x1.7f4daap0, 0x1.904964p0, -0x1.0e9cfp0, 0x1.bc800cp-1, -0x1.85d75ep-5, -0x1.f58a4p0, 0x1.4ff8f8p-2, -0x1.ef655cp0, 0x1.b64d6p0, 0x1.cc32c4p0, 0x1.7b0734p-1, -0x1.2f074cp-2, -0x1.19d674p0, 0x1.f7afc6p0, 0x1.29dfep-2, 0x1.3c7a72p-1, 0x1.9578eap-4, 0x1.41ca9cp0, -0x1.08eefep0, 0x1.cba2aap0, 0x1.cbdb6p-1, 0x1.fe38cep0, 0x1.0322c4p0, 0x1.1bbbe2p0, -0x1.947122p-1, 0x1.402604p-3, 0x1.f8b6acp-1, 0x1.281544p-2, 0x1.fda0ep0, 0x1.0aaedap0, 0x1.230918p0, -0x1.772d0ap0, 0x1.915fbep-1, -0x1.3da854p0, 0x1.10599ap-1, -0x1.85ec26p-1, 0x1.339cfep-1, 0x1.e1fcdp0, 0x1.7e4cf8p-3, 0x1.ec6bf8p0, -0x1.002e1cp0, 0x1.897482p0, -0x1.9ea0f4p0, 0x1.976ab8p-2, -0x1.964afap-1, 0x1.ed0bfp-3, -0x1.c31a7cp0, -0x1.548dbcp0, 0x1.ec8548p0, -0x1.43fc94p-2, -0x1.b6152ep-2, -0x1.b0f1e8p-1, 0x1.307736p0, -0x1.25e478p-3, -0x1.15e68p-1, -0x1.ab4eacp0, 0x1.d1c20ep0, -0x1.0099aep-1, 0x1.faa7ecp0, -0x1.c52298p-1, 0x1.3b07dap0, 0x1.11db38p-2, -0x1.ce9252p-1, -0x1.c2131p-1, -0x1.5657p0, 0x1.c512acp-1, 0x1.84ab34p-3, -0x1.5a9022p0, 0x1.10eb36p0, -0x1.df094p0, 0x1.059d2p-4, -0x1.767842p-4, -0x1.3fa7ap0, 0x1.369c26p0, -0x1.7e18p-2, -0x1.a2702ap-1, 0x1.88cd04p-1, 0x1.f451cep-2, 0x1.1a70d8p-1, 0x1.f0b41ep-6, -0x1.4b2e5cp-2, -0x1.02bc98p-3, -0x1.4ac7f2p0, 0x1.0ae0b8p-6, 0x1.5fff92p-3, 0x1.b57072p-1, -0x1.f0c1d4p0, 0x1.da428ap-3, -0x1.03383p0, -0x1.d5810ep-2, 0x1.9d490cp0, 0x1.32fb86p0, -0x1.770764p0, 0x1.ef0c0ap0, -0x1.0a07eep-2, -0x1.b4cab6p-1, 0x1.40ef88p0, 0x1.bde2f6p-3, -0x1.85cea4p-3, 0x1.688ad6p-1, 0x1.396a44p-5, 0x1.84076p-5, 0x1.99caecp0, 0x1.f058d2p-1, -0x1.12e2b6p-4, 0x1.5bb1b6p0, 0x1.d966b6p-1, -0x1.f7de58p0, 0x1.716beep-2, -0x1.ebcea8p0, 0x1.0109a4p0, 0x1.4f1c3cp0, 0x1.aea16p0, 0x1.791c04p0, 0x1.395b36p-2, 0x1.482118p-2, 0x1.a15024p-1, -0x1.aa14eap-2, 0x1.6324b2p0, 0x1.91b308p-1, 0x1.f9d662p-1, 0x1.c31ac4p-1, -0x1.5fa784p-1, 0x1.d751b8p0, -0x1.42575ap0, 0x1.1adf0cp0, -0x1.ec1a4p-1, -0x1.738d4cp-2, 0x1.15d894p0, 0x1.724142p-2, 0x1.259474p0, -0x1.d7c166p-4, 0x1.8f4a1p-2, -0x1.328682p0, 0x1.3a8c28p-1, 0x1.236e7cp-1, 0x1.e7c04ap-1, 0x1.1718dcp-7, 0x1.2355acp-5, -0x1.f699dep0, 0x1.680694p-1, -0x1.f565f2p-1, -0x1.75a558p-3, 0x1.51700ap0, 0x1.5e95c4p-1, -0x1.bb4efp-1, -0x1.2c52a6p-5, -0x1.628f74p0, -0x1.34abf6p0, 0x1.ddc894p-2, -0x1.856a24p0, -0x1.de90ccp0, -0x1.61cd68p-2, -0x1.b3ccb8p0, -0x1.a9a26p0, 0x1.c1a3a4p0, -0x1.7fd1ap0, -0x1.5c031ap0, -0x1.c60f34p-1, 0x1.3592dp-2, -0x1.f616a8p0, 0x1.6c2ca8p-2, 0x1.94ed74p-2, 0x1.25af4cp0, 0x1.b27aa8p0, 0x1.81d1eep-1, 0x1.b66b1cp0, 0x1.7888f8p0, -0x1.4d52c2p0, -0x1.23687ap-2, 0x1.e02b32p-1, -0x1.236c1p-2, 0x1.4768bp-1, -0x1.ccebf4p0, -0x1.26f43ap-2, -0x1.28a25p0, 0x1.fa4aa4p-1, -0x1.7f7be8p-4, 0x1.46255cp0, -0x1.660204p-2, -0x1.378632p-2, -0x1.90812ep0, -0x1.119b4ap0, -0x1.199b9p0, -0x1.ba0a04p0, -0x1.e16f88p-2, 0x1.805a7ap-2, 0x1.ccd0b8p0, 0x1.52c744p0, -0x1.4d0508p0, -0x1.4752bep0, -0x1.c6bb52p-1, -0x1.c2b3a6p0, 0x1.1a3d8cp-3, -0x1.410c8ep0, 0x1.ff14cep-1, -0x1.95a28ap0, 0x1.02739cp0, -0x1.915038p0, 0x1.7820f4p-3, -0x1.b3168ep0, 0x1.a8247ep-4, -0x1.4d1bc2p0, -0x1.5d2104p0, 0x1.bf9a4ep0, 0x1.d25c3cp0, -0x1.6c3d5ep0, 0x1.21a6eep-1, 0x1.a18eb8p0, -0x1.c47d3ap0, -0x1.996a66p0, 0x1.33d972p-1, -0x1.114d36p0, -0x1.84dfa4p-1, 0x1.671b26p-1, -0x1.b9d89p0, 0x1.ff756p0, 0x1.ae685ep0, 0x1.1d69dep0, 0x1.c05e98p0, 0x1.79394ep-2, -0x1.959226p-2, -0x1.40aa5ep-2, 0x1.7c770cp0, 0x1.f557cp-2, 0x1.95be04p-3, 0x1.454816p0, 0x1.1da982p-1, -0x1.b5fbfep-4, -0x1.29b748p0, -0x1.e7768ep0, 0x1.d410f8p-1, 0x1.54cccep0, -0x1.725588p-1, -0x1.c0c076p0, 0x1.6d683ap-1, 0x1.dcf456p-1, 0x1.ecf96ap0, 0x1.951c4cp-3, 0x1.055a32p0, 0x1.411142p0, -0x1.3aabd6p0, 0x1.298b0cp0, -0x1.f25bdp0, 0x1.8bf5cp0, -0x1.414bd4p-1, -0x1.1d0bf8p-2, -0x1.62c452p0, -0x1.97ece2p0, 0x1.8a3524p-1, -0x1.c396aap0, 0x1.0ea91ap-2, 0x1.433558p0, -0x1.ec4d34p-1, -0x1.b9fbcp0, -0x1.5ec7b4p0, -0x1.7ebed8p-1, -0x1.4e2b32p-1, 0x1.496f34p0, 0x1.455778p0, 0x1.8cb818p0, -0x1.6e392cp-1, 0x1.7f247ap0, 0x1.6a911p0, -0x1.2f3eb4p-1, 0x1.f40f94p0, -0x1.34cbdp0, 0x1.ae721p-3, -0x1.8dcfep0, 0x1.43046ep-2, 0x1.a65588p-1, -0x1.8725c8p-1, 0x1.b8aa44p-1, -0x1.21641ep0, 0x1.6113b2p-2, 0x1.7392eap-1, 0x1.106fdcp0, -0x1.329e02p-1, 0x1.d800a8p-1, -0x1.33c0ap-1, 0x1.9ad578p0, 0x1.03f188p-3, 0x1.12200ap0, 0x1.cf615p0, -0x1.33a1ep-3, 0x1.546c1cp0, 0x1.00690ep-1, 0x1.51e742p0, -0x1.b6e278p-1, 0x1.9ca14ap-1, -0x1.55534cp0, -0x1.fcbab6p-5, 0x1.69109ap0, 0x1.d2fbcp-1, 0x1.ad23dep0, -0x1.0a63b4p0, 0x1.8e98bcp-3, -0x1.4da5ccp-3, 0x1.ba057ap0, 0x1.050554p0, 0x1.752b7cp0, 0x1.9b6cecp-1, 0x1.5db648p0, 0x1.c4b808p-1, 0x1.e232fp-1, -0x1.82023cp-2, -0x1.1d35e6p0, 0x1.9723ap-1, 0x1.988e14p0, -0x1.bffc8ep0, 0x1.eaa9a4p0, -0x1.6cddb2p0, -0x1.d617e6p0, -0x1.3738cp0, -0x1.5e56b6p-1, -0x1.90df9cp0, 0x1.bd882ap-1, -0x1.a21964p-1, 0x1.4634aap0, 0x1.3d705ap-1, -0x1.937362p0, 0x1.734f0cp-2, 0x1.02a3c8p-1, 0x1.c38dfep0, 0x1.cbfe42p0, 0x1.e6d248p-5, 0x1.67c29ap0, -0x1.5084a2p-1, 0x1.691f46p-5, 0x1.2da736p0, 0x1.90be1cp-1, -0x1.852142p-1, -0x1.1d4a1p0, 0x1.d860e6p0, -0x1.7ddc5cp0, -0x1.990a72p0, -0x1.44f66cp0, -0x1.df7eaap0, -0x1.ab3136p0, 0x1.3cdfcp0, 0x1.fe3f4p0, -0x1.8cf41p0, 0x1.58d5c6p0, 0x1.62d366p0, -0x1.1969b4p-6, -0x1.098ed4p-4, -0x1.a8acfep0, -0x1.3ce82p0, 0x1.a9e03p0, -0x1.723bfp0, 0x1.446fcp-1, 0x1.352986p-1, -0x1.d8841ep-9, -0x1.3a2888p0, -0x1.3e71ccp-3, 0x1.5fad18p0, -0x1.a2121cp-4, -0x1.95f36ep-2, -0x1.688108p-2, 0x1.bebacap-1, 0x1.02318p-1, 0x1.62129p0, -0x1.bfdc18p0, -0x1.9bb996p-3, 0x1.cc09acp0, 0x1.e622d4p-2, 0x1.0b1784p-1, -0x1.118c5ep0, 0x1.c0f0cp0, 0x1.75c512p0, 0x1.247f4ap-1, 0x1.911a5ep-1, 0x1.73fc6cp0, -0x1.a99004p0, 0x1.828c3p-3, 0x1.74a94p-2, -0x1.9134ccp0, -0x1.bb7a2cp0, 0x1.3ad4eap-1, 0x1.67ee38p0, -0x1.d751ap-2, -0x1.1863eap0, 0x1.768c3p0, 0x1.5d776p0, 0x1.ecdf4p-1, 0x1.1eec48p0, 0x1.88b688p0, 0x1.fb9872p-2, -0x1.282936p-1, -0x1.703956p-4, -0x1.d343dep0, -0x1.7b5dc4p-2, 0x1.f4d5c4p-1, 0x1.f08d36p0, 0x1.812058p0, 0x1.00781ep-1, 0x1.51492p-2, 0x1.5a4b04p-4, 0x1.f89ffcp-5, -0x1.53d494p-1, 0x1.a53d8p-5, 0x1.3ac2ep-1, 0x1.8e2792p0, -0x1.66d6e2p0, -0x1.ce5958p0, 0x1.fe74e2p-1, -0x1.5999a2p0, -0x1.a915fcp-1, 0x1.44403ap0, -0x1.768eap-1, -0x1.47550ap0, 0x1.261d62p0, 0x1.e76484p-1, 0x1.6297f6p0, 0x1.0c5962p-1, -0x1.c20786p0, -0x1.2f26eep0, 0x1.4c457cp-1, -0x1.ef4e3ap-4, -0x1.58e9dp0, -0x1.efe826p-2, -0x1.9bb2c4p0, -0x1.cffa02p-2, -0x1.d4776ep0, 0x1.167e4p0, 0x1.76e99cp-2, -0x1.6f0cep-2, -0x1.84b0cap-1, -0x1.690328p-1, -0x1.70c752p-2, -0x1.691c86p0, -0x1.c02b84p0, 0x1.abc2cp0, 0x1.62c95cp0, -0x1.998332p-1, 0x1.c7735cp-3, 0x1.0f1d4ep0, -0x1.3fe09ep0, 0x1.61096ep-1, -0x1.c44f7ep-5, -0x1.3792ecp-2, 0x1.37752cp-1, -0x1.66532ep0, 0x1.1889eep-1, -0x1.9dc3f6p0, -0x1.e53d74p-1, 0x1.d0b636p0, -0x1.e6be22p-1, -0x1.2c010ep-3, 0x1.b78c3cp-4, 0x1.a24ed6p0, 0x1.397f5ep0, -0x1.c7f204p0, 0x1.e6dd36p-1, 0x1.7e23eep-2, 0x1.f0c3f6p0, 0x1.12bbccp0, 0x1.9f513cp-1, 0x1.ba9cd8p0, 0x1.019f56p0, -0x1.b04bb2p0, 0x1.f26c0cp-2 };
float keras_activation_3_test2_array[6] = { 0x1.c65434p-3, 0x1.7d7a3ep-5, 0x1.a05032p-6, 0x1.2d338p-4, 0x1.38972ep-1, 0x1.6a65dep-6 };
float keras_activation_3_test4_array[6] = { 0x1.407714p-2, 0x1.82bfacp-4, 0x1.be72a4p-6, 0x1.b4e42cp-5, 0x1.edad06p-2, 0x1.ea8522p-6 };
float c_activation_3_test2_array[6];
float test3_dense_input_input_array[2622] = { -0x1.e169d8p0, -0x1.f11e5cp-2, -0x1.f5a2bcp0, 0x1.2f98ccp-1, 0x1.802db4p0, -0x1.2d58cp0, 0x1.01359cp-2, -0x1.5efda2p0, 0x1.574eb8p0, 0x1.b12afcp-3, -0x1.69e022p0, 0x1.7b66f8p0, -0x1.b3e5ep0, 0x1.04e2bep0, 0x1.1c36d4p0, -0x1.022e38p0, 0x1.412012p-2, 0x1.6a986ep-1, 0x1.8f7ebap0, -0x1.be379p0, -0x1.190e78p0, 0x1.b4a464p0, -0x1.6d83aap0, -0x1.b1afdep-2, -0x1.d7376p-1, -0x1.aae60ap0, 0x1.4ac56ep-10, -0x1.e3d8aep0, -0x1.636f24p-2, 0x1.a14b2ep-1, 0x1.f2ba42p-2, -0x1.f2386ap-4, 0x1.91a93ep-2, -0x1.d2f4b2p-1, -0x1.1cb3cp-1, 0x1.1f3a8cp0, -0x1.7c2ea2p0, 0x1.2a6006p0, -0x1.717e5ap0, 0x1.9c0b64p0, -0x1.8693f8p-1, 0x1.7c2a34p0, 0x1.3adcc2p-1, 0x1.32b34ap-2, -0x1.a81d9ep0, -0x1.20b85ap0, 0x1.730a42p0, 0x1.5887b8p-2, -0x1.d7c282p0, -0x1.ac512ep0, 0x1.5ed7b8p0, -0x1.b32596p-3, 0x1.a604aap-2, -0x1.dbd662p-8, 0x1.55761ap-1, -0x1.0e54d6p0, -0x1.84313ap0, -0x1.cdcff4p0, 0x1.664206p0, -0x1.bcda4ap-1, 0x1.48110ep0, 0x1.09aa82p0, -0x1.7fc014p0, 0x1.1c262ap0, -0x1.ce704ap0, -0x1.1b5dp0, -0x1.037abp-2, -0x1.90c626p-1, -0x1.48822ep-5, 0x1.625e84p0, 0x1.bfd714p-2, -0x1.265b2ep-3, 0x1.e8b212p0, 0x1.48636ep0, -0x1.e7f5d4p-2, 0x1.0f3e4ep0, -0x1.097f4ep0, -0x1.2ddc9ep-2, -0x1.6c75b4p-7, 0x1.4793ap0, -0x1.b9007ap0, 0x1.758808p0, 0x1.3f10c6p-1, -0x1.11b5ep-1, -0x1.3f52ccp-1, 0x1.31e5a8p-1, 0x1.69ff08p0, -0x1.5b78cap0, -0x1.71642ap-1, 0x1.414fd6p-2, -0x1.a714a8p-1, -0x1.3d01d8p-2, 0x1.c5dbf6p-1, -0x1.c60e0cp-1, 0x1.f9f84ap0, -0x1.707e2ap-3, 0x1.c43f7cp-7, -0x1.c365b8p-2, -0x1.55ec7ep0, -0x1.bed266p-3, -0x1.b1b6f8p0, 0x1.e1d554p-5, -0x1.c6b86ep0, 0x1.26ea8ap-2, 0x1.ccc854p0, -0x1.d3f43cp-1, -0x1.184fa6p0, 0x1.d1198ep-2, -0x1.91b2fcp0, -0x1.efb96ap-1, -0x1.b8647p-1, -0x1.82131ap-4, -0x1.32057ep0, 0x1.89e57cp0, -0x1.a352e4p0, 0x1.08faa6p0, -0x1.9fa962p0, -0x1.881a12p-1, -0x1.db3b1cp0, 0x1.64a906p-3, -0x1.020d9ap0, 0x1.1badp-4, 0x1.e5ebf6p0, 0x1.2d321ap-1, -0x1.3d9082p-1, 0x1.383bd4p-1, 0x1.dcb2c4p-1, 0x1.0452cap-4, 0x1.d715a4p0, 0x1.8a24a8p-5, 0x1.7515bp-4, 0x1.85322ap0, -0x1.98f224p-3, 0x1.5a4202p-3, -0x1.f1c606p-1, 0x1.5db332p0, -0x1.39e48p-2, -0x1.865f9ap-3, 0x1.bd77fap0, 0x1.d17c38p-2, 0x1.149b8ep-3, -0x1.a0c71ep0, 0x1.47b076p0, 0x1.2fce36p0, 0x1.31e26p-2, 0x1.8d8a1ep-1, -0x1.6cdd1p0, 0x1.a8705ap0, -0x1.47a5e2p0, 0x1.6dcbecp-1, 0x1.79a9b6p0, -0x1.9c8e68p-1, -0x1.23bc3ap0, 0x1.3a72d8p-2, -0x1.9ccbe4p0, 0x1.e7a206p0, -0x1.9a62b6p-2, -0x1.50a7e4p-1, 0x1.cb635cp0, 0x1.1500fep-1, -0x1.cfbe36p-1, -0x1.210468p-2, -0x1.e1adap0, 0x1.6ff064p0, -0x1.109268p-1, -0x1.16bfb6p-1, 0x1.622768p0, 0x1.93353cp0, 0x1.3fb15cp-3, 0x1.b65f46p0, -0x1.4881c6p0, 0x1.ac083ep0, -0x1.fa1122p0, -0x1.d39dcap-2, 0x1.34a7eap-1, 0x1.fc34c8p0, -0x1.4bb572p0, -0x1.e5385cp-4, -0x1.177c7ep0, -0x1.c6d6aap0, -0x1.b43f62p0, 0x1.40a2d4p0, -0x1.8b1596p-1, 0x1.6119cp-3, 0x1.2d6022p-2, -0x1.44e2e6p-6, -0x1.3cf7e6p-2, -0x1.604e4ap-1, -0x1.b2af68p0, -0x1.bdc56p0, 0x1.bc45fcp0, 0x1.1ae11p0, -0x1.0b6932p-1, 0x1.008a14p0, -0x1.a83e16p0, 0x1.f6ccf8p-3, -0x1.62f7fep0, -0x1.c0542ep-1, 0x1.a5176cp0, 0x1.6d868cp0, -0x1.4061c2p-1, -0x1.eeb57p-2, -0x1.0a65d6p0, -0x1.ec0cacp-1, 0x1.e47484p0, -0x1.1d316p-2, 0x1.cbaaep0, -0x1.4ba4a4p-1, -0x1.75e37cp0, -0x1.46c204p-2, 0x1.b1ae02p-2, -0x1.7a55c6p-1, -0x1.a8c3f6p0, -0x1.7a24dep0, -0x1.9054acp-1, 0x1.9a2f7ap-4, 0x1.3d680cp0, -0x1.1402b4p0, -0x1.7b5314p0, -0x1.65d49p-10, -0x1.4496e2p-6, 0x1.47a72ap0, -0x1.fbb9c8p-3, 0x1.5366aep-1, 0x1.2e6fd2p0, 0x1.924a84p0, 0x1.998f5ap0, -0x1.2482ap-2, -0x1.03e2d6p-1, -0x1.f49936p-2, 0x1.d1448ap0, -0x1.f6e9dep-1, -0x1.f4e66cp-3, -0x1.090d72p0, 0x1.7307cep0, -0x1.98271ep-4, 0x1.8e1726p-2, -0x1.f416ccp-2, 0x1.0311d2p0, 0x1.ad45f2p-3, 0x1.600b02p-3, -0x1.8fda9cp0, 0x1.9cd28ap-1, -0x1.b152f6p-1, 0x1.bd65e4p0, -0x1.8bae76p-1, 0x1.5101e4p0, -0x1.44cfd8p-2, -0x1.894362p-3, -0x1.c68cdp-1, -0x1.b6e41p-2, 0x1.8da49ep0, -0x1.dbb8acp0, 0x1.a80bfp-1, -0x1.f2d3f8p-2, 0x1.a7543ap-2, -0x1.813c48p-1, 0x1.097f42p0, 0x1.bffcdep0, -0x1.c6c9bep0, -0x1.8af6e4p-1, -0x1.35ac28p-1, 0x1.cb8dd4p-1, 0x1.0648d8p-2, -0x1.1cc832p0, -0x1.25202cp0, 0x1.9b983ep0, -0x1.81166cp-1, -0x1.982b4cp-3, -0x1.e8a3cap0, -0x1.f0cae6p0, 0x1.f028dep0, 0x1.841c3cp-2, 0x1.2d4808p-1, -0x1.efe8e6p0, -0x1.d15e4ep0, -0x1.b23238p-3, 0x1.509cap0, 0x1.38a1p0, 0x1.de04ecp-2, -0x1.7ed7b4p-1, 0x1.82415cp-1, -0x1.075d9p-1, 0x1.4e711ep-3, -0x1.1d2b92p-1, -0x1.bd7398p-3, -0x1.2bbdp0, -0x1.3ff2bcp0, 0x1.444da8p0, 0x1.ed1af6p-6, -0x1.2d0e84p-6, 0x1.c918eep-1, 0x1.9bb226p-2, -0x1.6874fcp-1, 0x1.91992ap0, 0x1.f37692p0, 0x1.a71834p0, 0x1.b9a1f4p0, -0x1.a6e3aep0, 0x1.db796p-1, 0x1.6017f8p-1, 0x1.cc1982p-4, -0x1.6de10cp0, -0x1.7f55cep0, 0x1.434108p0, -0x1.1ea898p-3, -0x1.bb256cp-3, 0x1.d963eep-4, -0x1.994ef6p-1, -0x1.e73c8p-1, -0x1.17c512p-2, -0x1.18b426p0, -0x1.de597ep0, 0x1.b69b68p0, 0x1.232b0ap0, -0x1.9dceaep-1, -0x1.82040ep0, 0x1.567fbcp-1, 0x1.b538a6p-1, -0x1.8d27f4p0, 0x1.99807p-1, -0x1.89a56cp0, 0x1.dd5264p0, 0x1.d012aep0, 0x1.ccdd54p-1, 0x1.67e7d6p0, -0x1.13e92ap0, -0x1.488862p0, -0x1.b14892p0, -0x1.9be33ep0, -0x1.ee9734p-2, 0x1.668e4ep-1, 0x1.37ca86p-1, -0x1.c42ea6p0, -0x1.fbf282p-4, 0x1.9db028p-3, -0x1.24e73ap-1, -0x1.7c1276p0, -0x1.ba2e06p0, -0x1.66ae04p0, 0x1.d3afe2p-2, 0x1.7de9d6p-3, 0x1.a6faa8p-1, 0x1.0d3d46p-2, -0x1.21f116p-3, -0x1.66a07ap-1, -0x1.6d4b56p0, -0x1.3ac172p0, -0x1.b520acp0, -0x1.bd4152p0, -0x1.0f9bd4p-1, 0x1.805ca4p-1, 0x1.63ff28p0, -0x1.c39d34p0, 0x1.ddf0bp0, -0x1.2d75b4p-4, -0x1.fd462cp-2, 0x1.ea3546p0, -0x1.fcf7f2p-1, 0x1.6391ecp0, 0x1.242852p-1, 0x1.f0c328p0, -0x1.2259f6p0, 0x1.aafb4p0, 0x1.8eb49cp-1, -0x1.fec598p-4, 0x1.c0d102p0, -0x1.ef73fep0, -0x1.dd3f7ap-1, 0x1.505cdep0, 0x1.8085ccp0, -0x1.bc96p-3, -0x1.864604p-1, -0x1.1cbb0ap-1, 0x1.726b8p0, -0x1.ef008ep0, -0x1.b0ed5ap0, -0x1.75e2dap0, -0x1.4eb012p-2, -0x1.0f769ep-4, 0x1.b729e2p-7, -0x1.a8866ap0, 0x1.fa4394p0, 0x1.d6a0cp0, -0x1.7f6672p0, 0x1.fb429cp-1, 0x1.46d5fcp-3, 0x1.95201ap0, -0x1.e3b4f4p-2, -0x1.f27e98p0, 0x1.ccc752p0, -0x1.f20432p-1, 0x1.e3e88ep0, 0x1.75285ap0, 0x1.0bc1c8p-3, 0x1.22e4bap0, -0x1.5f6c62p0, -0x1.07fe4cp0, -0x1.9b04b2p-1, 0x1.7be616p-2, -0x1.0b0b48p-1, -0x1.dc71f6p0, 0x1.3cf0ap0, 0x1.1c1f94p0, -0x1.740d9cp-4, -0x1.22dc7ap0, 0x1.7272bep-1, 0x1.a0261ep-1, -0x1.dd2864p-1, -0x1.23504ap-1, -0x1.f10e48p-2, 0x1.495b16p0, 0x1.c30c7ap0, 0x1.85bde2p0, -0x1.c2e426p-2, 0x1.e20636p0, -0x1.9e854ep-2, -0x1.6a6b8ep-2, -0x1.ed9ecap0, -0x1.b10ef6p-1, 0x1.c7bcf6p0, 0x1.74c17cp0, 0x1.2a0c4p-2, -0x1.febf04p-3, -0x1.50c03ep0, -0x1.047626p0, -0x1.cebe2p0, 0x1.dca9dep0, 0x1.4b3562p-1, 0x1.f9b3e6p0, -0x1.39f64p-1, -0x1.e4ab2ap0, -0x1.bc9642p0, 0x1.0ee36cp-1, -0x1.bca8bcp0, -0x1.327b7ap-3, 0x1.094ca2p0, -0x1.8c2a3ap0, 0x1.7a0144p-1, 0x1.027eb8p0, -0x1.c8795ep0, 0x1.12ec76p0, -0x1.5c2a3ap0, -0x1.fcf8f4p-1, -0x1.aa2c9cp0, -0x1.a22294p0, 0x1.99d29cp-1, 0x1.af873p0, -0x1.d726ecp0, -0x1.3e3dc6p-1, -0x1.376a1cp-3, 0x1.bacf78p-1, 0x1.728d86p-2, 0x1.54b476p0, 0x1.e829cp0, 0x1.f0e70cp-1, 0x1.c3e4dep-4, -0x1.ee2f0cp0, -0x1.b69972p0, -0x1.635afcp0, 0x1.d58724p0, -0x1.6cfa6ap-3, -0x1.cfbcdp-4, 0x1.bcba2ep0, -0x1.d887fcp0, -0x1.616556p-1, -0x1.09b86ep0, -0x1.bc5fd2p0, -0x1.a2587ap-5, 0x1.6012eep-2, 0x1.28c7e6p0, -0x1.b622a6p-2, 0x1.d76766p-2, -0x1.090d9ep0, 0x1.f73082p-1, -0x1.dc6e08p-1, 0x1.1ebd3p0, 0x1.ca144ap0, 0x1.bb623ep0, -0x1.022ba4p-1, -0x1.ed259cp0, -0x1.27b9ep-1, -0x1.1824ep0, 0x1.c2202ep-1, -0x1.aab254p-3, 0x1.38e8d6p-5, -0x1.8808fp-2, 0x1.dcdadp0, 0x1.e28d58p0, -0x1.1a13bap0, -0x1.0fa7acp0, 0x1.837622p-3, -0x1.6c06c8p0, -0x1.f0000cp0, 0x1.1c90fep-1, 0x1.4cebf4p-1, -0x1.6fce8ep-2, 0x1.c4c24p-2, -0x1.fa9808p-5, 0x1.6dac9cp0, 0x1.e7f598p0, -0x1.f9a442p0, 0x1.99b5ap-1, 0x1.42e056p-1, 0x1.ade52ap0, -0x1.e79afap-2, -0x1.246ee8p0, 0x1.e659fap-3, -0x1.7e1044p-1, 0x1.ed45acp-1, -0x1.6d258cp-5, -0x1.389244p0, 0x1.91353ap0, -0x1.d78654p0, 0x1.761446p0, -0x1.5cb9c2p0, -0x1.c43f5ap0, -0x1.e4558cp-1, 0x1.b6cd9ep0, 0x1.919816p-1, -0x1.b04a2p0, 0x1.7da354p0, 0x1.c9360ep0, 0x1.6501fep0, 0x1.4eb26p-2, -0x1.174e0cp-2, 0x1.1865f6p0, 0x1.09351cp0, -0x1.1fb764p0, 0x1.827026p-2, 0x1.8418e8p0, 0x1.1863c4p-1, 0x1.d4745ep0, 0x1.625c88p0, 0x1.7ff7c2p0, 0x1.e3e0bep-2, -0x1.0e40dcp0, 0x1.114ecp-2, 0x1.c1b56cp0, 0x1.b55fp-1, -0x1.a2a1bp-1, 0x1.8415d6p0, -0x1.3b50f6p-1, -0x1.458e32p0, -0x1.8cee76p0, 0x1.9ea3fp-1, -0x1.6d53b2p0, -0x1.2b37cp-3, -0x1.2cc0e2p0, -0x1.20a194p0, 0x1.b1d37cp-1, 0x1.f3d218p-2, 0x1.3515aep0, -0x1.918e1cp-2, -0x1.07ee12p-1, -0x1.07d89ep0, 0x1.86a088p-3, 0x1.c96e0ap-1, -0x1.84500cp-1, 0x1.bcfc24p-1, -0x1.08c2eep-2, 0x1.c9bb54p0, -0x1.53bcc6p-1, -0x1.d6211cp0, -0x1.a3cc78p-2, -0x1.fd868cp0, 0x1.f7cff4p0, 0x1.fa025cp0, 0x1.d77724p0, -0x1.821128p-2, -0x1.620c7cp0, 0x1.3247bap0, 0x1.d69148p-3, 0x1.25dd98p-1, 0x1.cdae84p0, -0x1.ade9ap0, 0x1.068902p0, 0x1.b7658cp0, 0x1.2a31aap0, -0x1.81ab3cp-1, -0x1.590e26p-2, 0x1.ce2caep0, -0x1.2c3e68p0, 0x1.bcf58ap-3, -0x1.686cc4p-1, -0x1.31562ap-1, 0x1.ac34a2p-2, 0x1.718b4ap0, -0x1.95dafep-2, -0x1.644c96p-2, -0x1.39e20cp-2, 0x1.f6609p0, -0x1.a5f0b4p-3, -0x1.de1dfp0, -0x1.ae33p-1, 0x1.dbfc12p0, 0x1.bd240ap0, -0x1.9b2214p-2, -0x1.c3e044p-2, -0x1.ca412ap0, -0x1.b2051cp-1, 0x1.3ed352p-1, 0x1.3fa0b2p-3, -0x1.8b9c7ap-1, 0x1.c30b9ep-1, 0x1.294708p0, -0x1.7b44dp-1, 0x1.93b39p0, -0x1.15f19ep-2, -0x1.6c3338p0, -0x1.112694p0, -0x1.949fa6p-3, -0x1.fb55fp-1, -0x1.3b3102p-1, 0x1.82bfb4p-2, -0x1.22f128p0, -0x1.46d61p0, 0x1.25c922p-1, 0x1.7bfe3p0, -0x1.8381ap-1, -0x1.b41644p-2, -0x1.459c68p-1, 0x1.76f3f4p-3, -0x1.d8ccacp0, -0x1.2f669ap-1, 0x1.920e0ap0, -0x1.efd8bap0, 0x1.587e86p0, 0x1.d4242ep0, 0x1.d0bceep0, -0x1.814082p-3, -0x1.af1744p0, -0x1.df8532p0, -0x1.f39aa6p-5, 0x1.58d156p-1, 0x1.884db2p0, 0x1.ffc3e4p-1, -0x1.6af03cp-1, 0x1.60ea98p-1, 0x1.48c2a2p-1, -0x1.979738p-1, -0x1.3ae7cep0, 0x1.85f268p-1, -0x1.d8c77p-4, 0x1.514938p-1, -0x1.458304p-1, 0x1.dce492p-2, 0x1.449aeep0, -0x1.8c187ep-1, -0x1.f9fdacp-1, -0x1.f5ee1ep0, -0x1.a86314p0, 0x1.0226a2p-1, 0x1.6748e8p0, -0x1.8c91eep-1, 0x1.16cb76p-6, 0x1.d9f59ep0, 0x1.1fa3bap-1, 0x1.9ad52cp-1, -0x1.81057ep0, 0x1.72a69p0, 0x1.f17ccep0, -0x1.a7b384p0, -0x1.66501p-1, -0x1.5285b6p0, -0x1.0f5098p-1, 0x1.fb28a4p0, -0x1.11dc9ap0, -0x1.a7410cp-1, -0x1.c111bap0, 0x1.d01e64p0, 0x1.9d7a14p-4, 0x1.475dcp-2, 0x1.6125fap0, -0x1.de9bbap0, -0x1.bdbbaap-2, -0x1.8d87d8p-1, 0x1.0df3dap-1, 0x1.1d0c38p0, -0x1.07b0e2p0, -0x1.d9d564p-2, -0x1.ff0322p-6, -0x1.8a8376p0, 0x1.531258p0, -0x1.b71aep0, -0x1.061d4p-1, -0x1.6fb0aep-1, -0x1.53a392p-1, 0x1.34f63ep-2, -0x1.d883cp0, -0x1.0fe8f8p-1, -0x1.13c22cp-1, -0x1.dc6c3ep0, -0x1.f4fa4p0, -0x1.9079d4p0, 0x1.789c24p0, 0x1.fff164p0, -0x1.94c974p0, 0x1.a81ce6p-2, 0x1.eaf3f4p-2, -0x1.cb6dbap0, -0x1.16b3a8p-2, 0x1.a45302p-2, -0x1.74e596p0, -0x1.1a424ap-1, 0x1.c2f528p0, -0x1.15a5b6p0, -0x1.12652ep0, 0x1.349c64p-2, 0x1.307e5cp-1, 0x1.7850b8p0, 0x1.b86176p0, -0x1.53689ap0, 0x1.5f5ee2p-1, -0x1.b70832p-1, 0x1.b628fep-1, 0x1.dd13acp0, -0x1.c1ec84p0, 0x1.7205bep0, 0x1.025784p0, -0x1.306a84p0, -0x1.053f42p-1, 0x1.64ffdp-3, 0x1.d17adap0, -0x1.8cee34p-1, -0x1.fcc13ep-3, 0x1.ec7882p-1, -0x1.ce9af6p-2, 0x1.09c942p0, -0x1.2f4d86p-3, -0x1.91bc8ep0, -0x1.f096d6p-1, -0x1.e9db1cp0, 0x1.a799aap-5, 0x1.c14536p-1, -0x1.c9b936p-4, 0x1.99057ap-1, -0x1.0801e6p-3, 0x1.602df2p0, 0x1.172cb6p0, -0x1.aa7c7p-3, -0x1.741618p-1, 0x1.8dcf58p-2, -0x1.2dfefap-3, 0x1.dca80ap-3, -0x1.087b16p0, 0x1.2b4814p0, -0x1.6b6cd6p0, 0x1.134b22p-5, 0x1.51909cp-2, -0x1.016d82p0, 0x1.85c3dep-1, 0x1.457624p-2, -0x1.e8abbap0, -0x1.ec7b6ep-1, -0x1.b7b6bp-4, 0x1.2d1182p-2, 0x1.e349c6p-4, -0x1.9452a8p-1, -0x1.d67b2cp-5, -0x1.83d292p0, 0x1.bcaa3cp0, -0x1.e9ffcap-1, 0x1.df366cp-1, -0x1.4174f2p0, 0x1.264818p0, -0x1.5a8e06p0, -0x1.33d806p-7, -0x1.8cd702p-2, -0x1.5e6b92p-1, -0x1.17576cp0, -0x1.b93744p-1, -0x1.a23a14p-4, -0x1.357bf2p0, 0x1.5192fp0, -0x1.cfad66p-5, -0x1.4e63eap-1, -0x1.06cafcp0, -0x1.995948p0, 0x1.17aa58p0, 0x1.1d92ccp0, 0x1.38ebb6p0, 0x1.4f15bp0, 0x1.c58742p0, -0x1.d706eap0, 0x1.9d115ep-1, -0x1.f93424p0, -0x1.a5280ap-1, 0x1.fae91cp0, -0x1.cb872ap-1, 0x1.c5585ap0, 0x1.fde8e2p0, 0x1.c59d0cp0, 0x1.01e528p0, -0x1.754018p0, -0x1.3627cp0, 0x1.103b74p0, 0x1.6d70f2p0, -0x1.9107a8p-3, -0x1.a79e8cp0, -0x1.841beep0, 0x1.1ff11ap-4, 0x1.db80cp0, 0x1.165c52p-1, 0x1.ef5d06p-2, 0x1.ad4d3ep-4, -0x1.95e428p-1, 0x1.c04f0cp-1, -0x1.6c212cp-1, 0x1.53ac14p-3, 0x1.771696p0, -0x1.d8ed18p0, -0x1.1e2b6p-1, -0x1.a4d412p0, -0x1.88ce34p0, -0x1.34fd2ap0, -0x1.88a1e4p0, -0x1.c3116ap-1, 0x1.dd27fep0, 0x1.8da4cp-2, -0x1.03a1b8p0, 0x1.916332p0, -0x1.e338b6p0, 0x1.49b68ep-2, 0x1.6ac39cp-5, 0x1.6f0b3cp-2, -0x1.7d15a4p-2, 0x1.6a2ccp0, 0x1.16159ap-2, 0x1.3e3182p0, 0x1.90fcecp-2, -0x1.e8e3ccp0, -0x1.f2a6ap0, 0x1.84bf52p-3, 0x1.365facp0, 0x1.80e43ap-1, -0x1.6f69a2p0, 0x1.ef2e52p-3, -0x1.41d87cp-2, -0x1.113774p-2, 0x1.4fda92p0, 0x1.6d5ca4p0, -0x1.af81d6p0, 0x1.46d866p-2, -0x1.947c0ap-2, -0x1.698c6p0, -0x1.b04d3ap0, -0x1.e5b108p0, 0x1.2aa1fep0, 0x1.b4fd9ep-1, 0x1.07905ep0, -0x1.f3cb36p-2, -0x1.eb0a82p-1, -0x1.aa1d82p0, -0x1.36984ap0, 0x1.86c2dcp0, 0x1.af10ap-4, -0x1.bf9f18p-1, 0x1.ddcaa8p-1, 0x1.ccba0ep0, 0x1.25034ep0, -0x1.755796p0, -0x1.0e08fp-4, 0x1.5c2b0ap-2, 0x1.73dcf4p-1, 0x1.81ea3p-1, 0x1.784cacp0, 0x1.5521d2p0, -0x1.613a04p-4, 0x1.a4fae6p-1, 0x1.2b2878p0, -0x1.c3b704p0, -0x1.e9f79ap0, 0x1.8085acp0, -0x1.bd93a4p0, 0x1.7ac33p-1, 0x1.125992p0, 0x1.902728p-2, -0x1.2b127ep-3, 0x1.f3406p0, 0x1.ca2248p0, 0x1.b8dba8p0, 0x1.b833d6p0, 0x1.e70dc6p0, -0x1.3baebep0, -0x1.54a894p-1, 0x1.356eacp0, -0x1.166c54p-1, -0x1.d0028ep-1, -0x1.dd5c56p-7, 0x1.8a8ad2p-1, 0x1.52626p0, -0x1.6e2dc4p-2, -0x1.537aa8p0, -0x1.372c56p-3, -0x1.cb0042p0, 0x1.26abf2p0, -0x1.8f5a7ap-2, 0x1.8bdb9ep0, 0x1.307526p0, 0x1.0855a4p0, -0x1.8e1d8p0, 0x1.601e36p-5, -0x1.3d8edap0, -0x1.4e222ap-2, 0x1.4edab6p-1, -0x1.77495p0, 0x1.f3f2p0, -0x1.3c34a2p-1, 0x1.634148p-1, -0x1.bd323p0, 0x1.22f192p-1, 0x1.2d4096p0, -0x1.ba20aep0, 0x1.1ad7eep-1, -0x1.3f53cep-1, -0x1.801f24p-1, -0x1.900f4ep0, -0x1.abd4aep0, -0x1.128652p0, 0x1.e03f74p0, 0x1.1c508ep0, -0x1.7b4082p-3, 0x1.08fdcp0, 0x1.69a756p0, -0x1.df9552p-3, -0x1.0086p-2, 0x1.17feaep0, 0x1.49fc5ep-2, 0x1.9d0e9cp-1, 0x1.d2b06p-1, 0x1.a8ec64p0, 0x1.b71f18p0, 0x1.d1405ep0, 0x1.1299ecp0, 0x1.9688cap0, 0x1.ae2ebp0, -0x1.91208p-1, 0x1.ecdb08p0, -0x1.4ac1dap-5, -0x1.65cc84p0, -0x1.a80c06p-2, 0x1.001d52p0, -0x1.c8c6e8p0, -0x1.63ec8p-2, -0x1.b75c46p-1, 0x1.bb61fep-2, -0x1.7aaf2p0, -0x1.ba0054p-1, 0x1.9e5a9ep-1, 0x1.a026fap-1, -0x1.144dd6p0, 0x1.230464p0, 0x1.e955ap0, -0x1.39f15p0, 0x1.6cf114p0, 0x1.be7eap-3, 0x1.836f9cp0, 0x1.e274ap-3, 0x1.e3c9fap-2, 0x1.3e2dcp0, 0x1.a4bbe8p0, 0x1.a421dap0, 0x1.6ab844p-1, -0x1.ca582ap0, 0x1.bfc3dep0, 0x1.ac537p0, -0x1.0bd2a8p0, 0x1.44d1f2p0, -0x1.add8bap-4, -0x1.b6ca1p0, -0x1.5070bp0, 0x1.bb87fep-1, -0x1.ef674cp-2, -0x1.e27c72p-1, 0x1.f95c8ap-4, 0x1.8ad3b2p-1, -0x1.663aa8p-2, 0x1.6affd2p0, 0x1.498ecp-1, -0x1.96179ap-1, -0x1.60a9aap0, 0x1.63b824p0, 0x1.8259bap-6, 0x1.f5a02ap0, -0x1.319becp-2, -0x1.7c06c6p-1, -0x1.b2c3ecp-3, 0x1.9e0096p0, 0x1.f00fdep0, -0x1.56c93ap0, -0x1.1487bp-3, 0x1.7a5c66p0, -0x1.82b0c2p-2, 0x1.cfbebap0, -0x1.5dfdf2p0, 0x1.1ddc4ap0, -0x1.e6a1b2p0, 0x1.3e7f08p0, 0x1.6aef0ap0, 0x1.16de82p0, 0x1.e49a2ap0, 0x1.c50318p0, -0x1.be3206p0, 0x1.7b94dep0, 0x1.d3bc8ap0, -0x1.6b9058p0, 0x1.2015fcp-3, -0x1.8354b2p0, 0x1.be2274p-1, 0x1.8cfc66p-1, -0x1.5b4f6p0, -0x1.509bb8p-1, -0x1.eeb7cep-1, 0x1.7efc8cp-1, 0x1.e2b756p0, 0x1.4eb986p-1, 0x1.8e03dep-4, 0x1.97bab2p0, -0x1.16cf08p-4, 0x1.f5404p-2, 0x1.aade5ep0, -0x1.4b4ff8p0, 0x1.f7ddcep0, 0x1.ab62fp-1, 0x1.93ffb2p0, 0x1.dbea86p-5, -0x1.105942p0, -0x1.d200d8p0, -0x1.288b9cp0, 0x1.645f22p-1, 0x1.a8fe22p-4, 0x1.90d6cp-1, 0x1.a874eep-1, 0x1.32a816p-1, 0x1.b263c8p0, -0x1.efbb82p0, -0x1.811c0ap0, -0x1.89473ap-2, 0x1.f91054p0, -0x1.36be7p0, -0x1.d3e406p0, -0x1.2bde4p0, 0x1.2738aap0, -0x1.56d9d4p0, -0x1.949962p0, 0x1.9ca606p-4, -0x1.18692cp0, 0x1.0ca00cp0, 0x1.fcaba6p0, 0x1.1a2fc8p-3, 0x1.d602e6p0, -0x1.fed3fep-3, 0x1.068e56p-1, 0x1.5e4eacp0, -0x1.962e72p0, -0x1.ba3de2p-3, -0x1.6daaf2p0, 0x1.4d76e6p0, -0x1.80d334p-1, 0x1.7c0b1ap-1, -0x1.b3f9dep-1, -0x1.f384c6p0, -0x1.7a7f3ap0, 0x1.f95332p-2, 0x1.4054e6p-2, -0x1.0e86fep-1, -0x1.0f8944p-2, 0x1.a343fp-16, 0x1.ea3d28p-3, 0x1.582776p-1, 0x1.9563c4p-4, -0x1.faa88p-2, -0x1.90dde8p0, -0x1.6371b6p0, 0x1.1494c8p-1, -0x1.2e86ap0, 0x1.26112ap0, -0x1.e10656p0, -0x1.09ab0cp-1, 0x1.0a5594p0, -0x1.e19882p0, 0x1.920092p0, 0x1.f4edb8p0, -0x1.fcebaap0, -0x1.38b054p0, -0x1.73052p-1, -0x1.1accf8p-5, -0x1.f3370ep-3, -0x1.54ae54p0, 0x1.579eeap0, -0x1.1ce688p-5, 0x1.de2f9p-8, -0x1.990d66p0, -0x1.9ac474p0, -0x1.71b4f8p-5, 0x1.a253b2p0, -0x1.7de852p0, 0x1.5a2a3ap0, 0x1.7745acp0, -0x1.fc9bfap-2, 0x1.680952p-2, -0x1.e59244p-6, -0x1.0aea3ep0, -0x1.318c4ep0, -0x1.2a1498p0, 0x1.e21078p0, 0x1.86e9a8p-2, 0x1.fb738p0, 0x1.a9fce4p0, -0x1.3c8052p-2, -0x1.080f8cp0, -0x1.233a66p0, -0x1.0289c4p-1, 0x1.bb532p-1, -0x1.9a4034p-4, -0x1.7d8cdp-1, -0x1.fe6f2ap0, -0x1.cd0a74p0, 0x1.deb91p-2, -0x1.cbe7eap0, 0x1.abb504p0, -0x1.bc5314p0, 0x1.75e5e2p-1, 0x1.1e2d7cp0, 0x1.bf1cdcp-1, -0x1.78088p0, -0x1.d5db2cp-1, 0x1.b91b94p0, 0x1.6fd286p-2, -0x1.157e06p0, -0x1.c3bf5cp0, -0x1.9867d6p0, -0x1.40ad4p-3, 0x1.e91f9ep0, 0x1.73ad52p0, 0x1.7949eap-1, -0x1.875114p0, -0x1.a538c8p-1, -0x1.7ad494p0, 0x1.c143b4p0, -0x1.8633aep-1, 0x1.4f373ep-1, 0x1.122fa4p0, -0x1.fdebecp-1, -0x1.c94d6ep0, -0x1.8f9b5p0, -0x1.37904cp-2, 0x1.9218aap0, 0x1.50ac3ap0, 0x1.de074p-2, -0x1.99a91ep0, -0x1.a7e786p0, -0x1.a89456p0, 0x1.6deab2p0, -0x1.7086acp-1, -0x1.30709p-2, -0x1.04312ep-6, -0x1.ab7d1ep0, 0x1.a3d68ap-2, -0x1.3fa92ep-1, -0x1.e0f14p-8, -0x1.ab3a64p0, 0x1.55399ep-3, 0x1.6b40e4p-1, 0x1.fbebe2p-2, 0x1.629abap-1, 0x1.5f07bap0, 0x1.7fcb72p0, -0x1.c5c826p0, -0x1.05a2b6p0, -0x1.16add4p0, 0x1.7990dap0, 0x1.733e1ap0, 0x1.b1b31p0, 0x1.36fbcap-3, 0x1.8bf626p-1, 0x1.e35c42p0, -0x1.d30d62p0, -0x1.f01d42p0, 0x1.2a0a16p0, 0x1.3aab6ap-2, 0x1.4d4efp0, -0x1.6f1428p0, -0x1.f9c1b4p-2, -0x1.c630ap0, 0x1.ba9bbap-4, 0x1.850b8cp0, -0x1.b217d8p0, 0x1.ec5934p0, 0x1.3aa91cp-1, 0x1.685b92p0, 0x1.557d18p0, 0x1.8fb564p-1, -0x1.58203p-1, 0x1.6f745cp-1, -0x1.33fb54p0, 0x1.07330ap-2, -0x1.d618f4p-1, 0x1.6b35eep0, 0x1.82515cp-10, 0x1.24eaeap-1, 0x1.119ap0, -0x1.dc01a8p0, 0x1.8c8f46p-4, 0x1.7134d6p0, 0x1.2252e4p0, 0x1.30f39cp0, -0x1.0b56aep0, 0x1.7e12aap-1, -0x1.0f758p-1, 0x1.cc1058p0, 0x1.a6fda6p0, 0x1.9537a4p-1, 0x1.65a1c8p-2, 0x1.4bcd98p0, -0x1.2da2a6p-1, 0x1.b43fd6p-2, 0x1.b75ec6p0, 0x1.d4c48p-2, -0x1.6baf8ep-1, -0x1.594f4ep0, 0x1.6b30d6p-1, -0x1.878628p-1, -0x1.b629bcp-1, 0x1.c1bc42p0, 0x1.36f67ap0, 0x1.adc7bep-2, -0x1.045db8p0, 0x1.7afca2p-1, -0x1.4c8348p-1, -0x1.a50e48p-5, 0x1.486b72p-1, -0x1.ed574cp0, -0x1.938ebp0, -0x1.eb089ep0, -0x1.831cap0, -0x1.b6f7b4p-1, 0x1.66ee88p0, -0x1.2f16a8p-2, 0x1.b4bd7ap-1, -0x1.c8179ep0, -0x1.371bd4p0, -0x1.08fe9p-1, -0x1.1d509cp-2, 0x1.f622bep-3, 0x1.dfe2e2p-5, -0x1.7dd84p-1, -0x1.533feep-1, -0x1.761f12p0, 0x1.4f8c1cp0, -0x1.5c605p0, -0x1.b97fdap0, -0x1.2f699ap-1, -0x1.8d564cp0, 0x1.aa22f4p-1, 0x1.4830aep-4, 0x1.2e552cp-1, 0x1.44e68ep0, -0x1.f1fcdep-1, 0x1.6c48ap0, -0x1.23407ap0, 0x1.9f772p-6, 0x1.d6f9b6p0, 0x1.dd4b7ep0, -0x1.545bf8p-1, 0x1.1f8c9ap0, 0x1.08983ap0, -0x1.f70a82p0, 0x1.59848ep-1, 0x1.f60176p0, -0x1.eae924p-2, -0x1.236b1ap0, -0x1.3147ecp-6, 0x1.f68648p0, -0x1.42273ep-1, 0x1.8cb5acp-1, -0x1.7afc3p0, -0x1.478662p-1, 0x1.1cf8dep-1, -0x1.2ccd4ap0, -0x1.9d2b1ap0, -0x1.f3b70ap-3, -0x1.c4830ep0, 0x1.f95f08p-4, -0x1.1446dep0, 0x1.9868e6p-2, 0x1.34f542p0, 0x1.494546p-8, -0x1.277bbp0, -0x1.dee3fep0, -0x1.f4e0e2p-1, 0x1.9b7b08p-2, 0x1.aece02p-3, 0x1.58c2ecp0, 0x1.49aa08p0, -0x1.098bc4p0, -0x1.2c8434p-3, 0x1.920a6p0, 0x1.7e701p-1, -0x1.c4a1f8p0, -0x1.045d08p-7, 0x1.61ebf6p-1, -0x1.0f02a4p-6, -0x1.28bf3p-2, 0x1.f37264p-1, 0x1.78bb46p-3, -0x1.b07e0ep-3, 0x1.b7048ap0, -0x1.c83476p0, 0x1.08763ap-1, 0x1.e5b9ap-1, 0x1.b81144p0, -0x1.d4194p-2, 0x1.3613bcp0, -0x1.838074p0, -0x1.201474p-1, 0x1.66dd5ap0, -0x1.18d874p0, -0x1.224934p0, 0x1.bf312ep-1, -0x1.9dbd2ap-1, -0x1.1e18c8p0, -0x1.3c318cp-2, -0x1.9ff0d8p0, 0x1.d1046cp0, -0x1.cc804ap-3, -0x1.10dbf4p-3, 0x1.c0c8b2p-2, 0x1.039942p-1, -0x1.f2fdbep0, -0x1.8dc1bap0, -0x1.d8c0dap-1, 0x1.49d078p0, -0x1.b6512p-3, -0x1.3d949ap0, -0x1.da5488p-1, -0x1.46a3ecp0, -0x1.dbe1e6p0, 0x1.c2ff3p-1, -0x1.be2516p0, 0x1.5e9dp-3, 0x1.023caap0, 0x1.690916p0, -0x1.e1cd1cp0, 0x1.ffa11ep-1, -0x1.d081aep0, -0x1.91d3dep0, -0x1.f0bfa6p-1, -0x1.f0769ap-1, -0x1.2a95b4p0, 0x1.2ce622p0, -0x1.47cbe2p0, 0x1.7b97ap0, 0x1.c17baap-2, 0x1.ce6792p-1, -0x1.72a498p0, -0x1.4b0e96p0, 0x1.5501aap-4, -0x1.c9f4bp-1, -0x1.97952ap0, -0x1.f317f8p-1, -0x1.2c9c36p0, -0x1.806ebcp-4, -0x1.46d23cp0, -0x1.76373ap-2, 0x1.a13ce6p0, 0x1.a0bb96p0, 0x1.bdf5bcp-1, -0x1.e448ecp-4, 0x1.00ed68p0, 0x1.60d044p0, -0x1.9b5d7p0, -0x1.773a2ap-2, -0x1.521368p0, -0x1.d8f72p-1, 0x1.acca16p0, 0x1.e0132ep-9, -0x1.444018p-1, 0x1.979fdap0, -0x1.cbc844p0, 0x1.450a3cp0, 0x1.3fbd0cp-2, -0x1.a720b2p-1, 0x1.8a702ap0, -0x1.81553ep-2, 0x1.915982p-3, -0x1.dfe8f4p-1, 0x1.18b1c2p-1, 0x1.2ee564p0, 0x1.f6482cp0, -0x1.c4f1fcp-1, -0x1.5ea8f4p-3, -0x1.c732dep-1, 0x1.78915p-1, 0x1.5b491ep0, 0x1.98bb4p0, -0x1.d7a82cp-1, -0x1.98dc4ep0, 0x1.329254p0, 0x1.77969ep-1, -0x1.531f8ap-1, -0x1.9dd3fep-2, -0x1.311bd4p0, 0x1.10213ep-1, 0x1.af3054p-1, -0x1.8ca8ecp0, 0x1.93ea56p-1, -0x1.15dbep0, 0x1.126a04p0, 0x1.71aecap-2, 0x1.836264p0, -0x1.0a7756p-1, 0x1.86a782p-1, 0x1.39c702p-2, 0x1.d402e2p0, 0x1.234c3p-1, -0x1.f5bc76p-2, -0x1.2438dp0, 0x1.ab1b9ep0, -0x1.2eefeap-1, -0x1.bf0518p-1, 0x1.514096p-6, -0x1.62f67p-1, -0x1.04da1ep0, 0x1.c6561ep-6, 0x1.24f56p0, 0x1.51562ap-1, -0x1.f21438p0, 0x1.cbdc8ap-1, -0x1.59a43ap-2, -0x1.ff072p0, 0x1.b0b954p-1, 0x1.84836ep0, 0x1.d1367ep-4, -0x1.5b2448p-1, 0x1.41ce84p0, 0x1.2359e4p-5, 0x1.1beeb4p0, 0x1.e742c6p-5, 0x1.40952p0, -0x1.1b5d54p-3, 0x1.ba2adp0, 0x1.397d2p-4, 0x1.a7e37ep0, -0x1.2ce566p0, -0x1.25392ap-3, 0x1.858726p0, -0x1.92e642p-2, 0x1.ee7f86p0, 0x1.d7084cp-1, 0x1.55594ep-5, 0x1.4aa8b2p-2, -0x1.25c29ep0, -0x1.f7c288p0, 0x1.3cbb7ap-1, -0x1.7b5298p0, 0x1.183f7cp0, 0x1.322dc8p0, 0x1.2b6076p0, 0x1.e382a6p-1, 0x1.89ed3ap-1, -0x1.f2a27p-4, 0x1.e5cdbp-6, 0x1.40e3cap0, 0x1.37e00ap-3, 0x1.a84554p-2, -0x1.143f8p-2, 0x1.49eb5cp0, 0x1.c4fc08p0, -0x1.7f38e6p0, -0x1.5668b8p-1, -0x1.7babf8p0, 0x1.cb6b2ep0, -0x1.1f7e7cp0, -0x1.39193ep-2, 0x1.62a182p0, -0x1.1b99cep-1, 0x1.f39998p-1, 0x1.2c0e98p-2, -0x1.8123bep0, -0x1.c1f308p-4, 0x1.2cd164p-1, 0x1.e3e67cp-2, -0x1.6fd41cp-5, -0x1.af602cp0, -0x1.d6063ep-3, -0x1.e019b8p-2, -0x1.ef5678p-1, 0x1.eeaf82p0, 0x1.504edp-3, 0x1.323ac6p-3, 0x1.7a6374p-2, 0x1.6141c6p0, -0x1.a61aeep-1, -0x1.4d5f8cp-1, 0x1.03cf44p0, -0x1.22ee7ep-1, -0x1.eabaeep-1, 0x1.b5c262p0, -0x1.d6bc1cp-2, 0x1.4da326p0, 0x1.9a292ap-4, 0x1.9a1172p0, -0x1.418d12p-3, -0x1.aa95bp0, -0x1.1da42ap0, -0x1.6c8d58p0, 0x1.eda576p-1, 0x1.ca9cap-1, -0x1.668ca4p-1, 0x1.b26056p-1, -0x1.c8b90ep-1, -0x1.103d12p0, -0x1.42a37ap-2, 0x1.bf7576p-2, 0x1.594968p-1, 0x1.e7bcb6p-2, -0x1.c7c786p-1, 0x1.c0515ap-4, -0x1.20759ap-3, -0x1.f15e4p0, -0x1.a9e91p0, 0x1.4e88e8p0, -0x1.63012cp0, 0x1.2b4b5ep0, -0x1.d4dc6ap-1, 0x1.f40cf8p-1, -0x1.cc736ap-2, 0x1.13079p-6, 0x1.b0b21ep0, 0x1.61cdp-1, -0x1.f56b2ep0, 0x1.95da76p0, -0x1.112aa2p0, 0x1.10ddcp0, -0x1.31d898p0, -0x1.9f4d8p-4, -0x1.8a810ep0, -0x1.378664p-1, -0x1.6c5c64p-1, -0x1.07e07cp-1, -0x1.2ea3p0, 0x1.7eb8fp0, -0x1.8f3a88p-1, -0x1.ef93b6p-1, 0x1.548876p0, 0x1.818864p-6, 0x1.3eeeaap-8, -0x1.d4f918p0, 0x1.c33636p-6, -0x1.229718p0, -0x1.9f9562p-1, -0x1.eac446p-1, 0x1.27485p-3, 0x1.7568c2p0, 0x1.3747d4p0, 0x1.8c2084p0, 0x1.e7d3d8p-2, -0x1.9b8f82p-1, -0x1.8cef06p-2, 0x1.b0d1c2p-1, 0x1.933f18p-1, 0x1.1408ecp0, 0x1.af9d56p-1, -0x1.9acff6p0, 0x1.50c558p-1, -0x1.490a58p0, -0x1.3c61b6p0, -0x1.6ed288p0, -0x1.f161aep-2, 0x1.a70fd2p-1, 0x1.de55ep-1, -0x1.454018p-1, -0x1.aff63ap0, -0x1.d8f386p-1, 0x1.6a484cp0, 0x1.04932p0, 0x1.f3fe56p-1, -0x1.6cb0eep-4, -0x1.dd80c6p-2, 0x1.f25c06p0, 0x1.a00022p0, -0x1.ee069p0, 0x1.e756cep-1, -0x1.25e716p0, 0x1.f15a3p-1, 0x1.8727bcp0, 0x1.851e7ap-1, 0x1.5a21fcp0, 0x1.09c558p-1, 0x1.54e418p0, 0x1.7b3a64p0, -0x1.a9d12ep-1, 0x1.6bde1ap0, -0x1.7a6c6ep0, -0x1.f79a98p-1, 0x1.a2857p0, 0x1.c1c438p-1, 0x1.59507p-4, -0x1.8b3f64p-1, 0x1.d89e84p0, 0x1.b451ap-2, -0x1.8c8b32p0, -0x1.8f9bccp0, 0x1.20845cp0, -0x1.25efb2p0, -0x1.f7437ap0, 0x1.62605ap-1, -0x1.e73948p0, -0x1.a6f342p-1, -0x1.aa406cp0, 0x1.321dd4p0, -0x1.f1519p0, 0x1.7c21c6p0, -0x1.d56ffep0, -0x1.1c7ee2p0, 0x1.8371a8p0, -0x1.703b46p0, 0x1.78686ep0, -0x1.e8186cp-5, 0x1.ec4a0ep0, 0x1.c6659p0, 0x1.c88e84p0, -0x1.98eea8p0, -0x1.64c9d2p0, 0x1.b74646p-4, -0x1.07981ep0, 0x1.69dba2p-1, 0x1.27173p0, -0x1.c81a2ap-1, 0x1.af5078p-1, -0x1.a92e1ap0, -0x1.5454a8p-4, -0x1.f47b12p0, 0x1.146828p0, 0x1.0b5f22p0, 0x1.ff4268p0, 0x1.cdd512p-1, 0x1.38a7b8p-1, 0x1.d5311ep-1, 0x1.04385ap0, 0x1.d462f8p-1, -0x1.d2803ep0, 0x1.87c6a6p0, -0x1.8d6932p-1, -0x1.ae71eap0, -0x1.aac998p0, -0x1.c54214p0, -0x1.23ff6ap-1, -0x1.805ce8p0, 0x1.28a64p-3, 0x1.78321p-1, 0x1.3538f2p0, -0x1.db670ap-1, -0x1.7bbfe2p-1, -0x1.d9c9d2p0, -0x1.8fbf38p0, 0x1.5611c4p0, 0x1.9de8b4p0, -0x1.4689c8p-1, 0x1.7fa01cp-8, 0x1.a1e412p0, -0x1.f35e56p-2, 0x1.3fe24p0, -0x1.0e2c8ep0, -0x1.4aba3cp0, -0x1.ed28e4p0, -0x1.aae50cp-4, 0x1.7174e2p-2, 0x1.1ffcap-2, 0x1.eddb6ap0, 0x1.7893cap0, -0x1.ad8a4ap0, -0x1.c0979ap-2, -0x1.d8af4p-1, -0x1.bdb078p0, 0x1.7f2cfp0, 0x1.85a7f2p0, -0x1.a6bd6cp0, 0x1.e8abdep0, 0x1.51f2c2p-1, 0x1.037d98p-2, -0x1.cdd6c4p0, 0x1.145e48p-2, 0x1.b10e78p0, -0x1.792002p0, 0x1.3bf76p-4, 0x1.a033aap-2, 0x1.35ec0ep0, -0x1.d8029cp-1, -0x1.c8097ap-1, -0x1.b0dab2p-4, 0x1.f94722p-2, 0x1.c7dc1ap-1, -0x1.09925p0, 0x1.ac03fep0, 0x1.1f5118p-3, -0x1.0d36dep0, 0x1.d3b9b4p0, -0x1.1be10ap0, -0x1.bc827ap-1, 0x1.76a4dap0, -0x1.7abaeep0, 0x1.6c144p0, -0x1.2a1cf4p0, -0x1.0def9cp0, -0x1.0c7106p-1, 0x1.d947c4p0, 0x1.8d6b2p-4, -0x1.24bd8cp0, -0x1.430cap0, -0x1.ea04c6p-5, 0x1.c5bd4p0, 0x1.808768p0, 0x1.ff315ep-1, -0x1.17e314p0, -0x1.808448p-2, -0x1.53753cp-1, 0x1.878828p-1, 0x1.a4b62p0, 0x1.0a27dep0, 0x1.0cd5f2p0, -0x1.eccb12p0, 0x1.2f1b6cp-2, -0x1.6b8f56p0, -0x1.4cb15p-4, -0x1.027f0ep-1, -0x1.cc72d6p0, 0x1.21dbdep-2, 0x1.44dee2p-2, 0x1.f9f802p0, 0x1.9c2becp0, -0x1.21bb96p0, -0x1.4e9f4p0, -0x1.a5ab2ap-4, 0x1.c0bc84p0, 0x1.a1f264p-1, 0x1.24aadcp-4, -0x1.b99e08p-2, -0x1.8709fp-2, 0x1.e67becp0, 0x1.3a6e88p0, -0x1.303888p0, -0x1.612048p0, 0x1.daa4d8p0, -0x1.344444p-3, -0x1.63a38ep0, 0x1.0d9aa4p-2, 0x1.db4fecp0, 0x1.817866p-1, -0x1.a1629cp0, 0x1.b37f2p0, -0x1.33f4d2p-2, 0x1.d1685ap-3, -0x1.1e4ce2p0, 0x1.01ba86p0, 0x1.e92f46p-2, 0x1.34b372p-2, -0x1.dd76ecp-1, -0x1.19f772p-1, -0x1.8e409cp-1, 0x1.7b6a24p0, -0x1.f20d4ap0, -0x1.e27558p-2, -0x1.1ef8bcp0, -0x1.756d12p-3, 0x1.ff5b7ep-1, 0x1.7e3eb8p0, -0x1.e0882ep0, 0x1.df942p-7, 0x1.212e78p0, 0x1.71c2cp0, -0x1.08090cp0, -0x1.a5f9aep0, -0x1.73dc9cp0, 0x1.cd07b8p-1, -0x1.109754p-4, 0x1.0aa222p-1, 0x1.a50b44p-5, 0x1.e72192p-1, -0x1.6d4c86p0, 0x1.9e98e8p0, 0x1.0a8decp-2, -0x1.0bcadap-5, 0x1.823984p0, 0x1.e5ebe8p-3, -0x1.d3a2c4p0, 0x1.c6e008p0, 0x1.14f7b8p-3, -0x1.022c68p0, -0x1.c7ff34p0, -0x1.8493a8p-4, 0x1.719edap0, -0x1.6a24bep0, -0x1.a70fccp-3, -0x1.4f9ad2p-3, 0x1.a40ab8p0, 0x1.d00236p0, -0x1.6e4214p0, 0x1.256628p-1, 0x1.5a87ccp-1, 0x1.28529cp-1, -0x1.142616p-2, -0x1.05b4d4p0, 0x1.7cf59ap0, -0x1.4081dcp-1, -0x1.3d83cap0, 0x1.f2e4b6p0, 0x1.248854p-1, 0x1.b7e25p0, -0x1.b4fc68p-2, -0x1.b78926p0, -0x1.5b821ep-1, 0x1.dd102ep0, -0x1.fed33cp0, -0x1.ce5e82p-1, 0x1.4878ecp-1, 0x1.1019f8p0, -0x1.ae7448p0, -0x1.2324a2p0, -0x1.bbf0bep0, 0x1.3a044ap-4, -0x1.345a32p0, 0x1.34f774p0, -0x1.7ac3ccp0, -0x1.33568cp0, -0x1.029a8ep0, -0x1.eb4ceep0, -0x1.ed37bap0, -0x1.8d2abap-2, 0x1.bf2df8p0, 0x1.7a286cp-2, 0x1.f0d686p0, 0x1.7d2cdap-1, -0x1.7eb4fcp-1, 0x1.c78b22p-2, -0x1.84f35p-1, -0x1.b728ap-1, 0x1.eb365cp0, 0x1.850232p0, -0x1.faf156p-3, -0x1.6b15fp-1, 0x1.a29b1p-1, 0x1.98536ep-1, -0x1.e3606ap0, 0x1.72434ep0, -0x1.742312p0, 0x1.e9726ep-1, 0x1.1fb154p-2, 0x1.053bb4p-1, -0x1.7dd63ep0, 0x1.29a512p0, -0x1.f207dap-1, -0x1.119baap-1, 0x1.c041b2p-1, -0x1.0dd47ep-1, 0x1.44551p0, -0x1.f59668p-2, 0x1.d72d98p-1, -0x1.38e2e8p-1, -0x1.671516p-3, -0x1.73872p-1, -0x1.94b2dap0, 0x1.c9117ap0, 0x1.2cbafep0, -0x1.cbccd8p0, 0x1.0e79fap-3, 0x1.2ed158p0, 0x1.27a9e2p0, 0x1.f499fap-1, -0x1.d9ea9cp0, 0x1.1867eep0, 0x1.eafdfep0, 0x1.71c00ep-2, -0x1.3e9016p0, -0x1.807548p0, 0x1.7f4936p-1, -0x1.3141ep-1, -0x1.33f5bp-1, 0x1.996cb4p-1, -0x1.ee9408p0, -0x1.8d0cc8p0, -0x1.acbf64p-1, -0x1.a2a9eep0, 0x1.681afcp-2, 0x1.221838p-4, -0x1.a6a09p-1, 0x1.5f4af8p-1, 0x1.5ab08p-2, -0x1.9e9fd2p0, -0x1.7e8cfp-1, -0x1.d7fe56p0, -0x1.8dd55ep0, -0x1.8003a4p-1, -0x1.5d6a56p-1, 0x1.1b21ap0, -0x1.e4d686p0, -0x1.06b40cp0, -0x1.b54846p-2, -0x1.922084p0, 0x1.59748ap0, 0x1.525d7cp-1, 0x1.296ec8p0, -0x1.b3d52p-1, 0x1.25420cp-2, 0x1.3d2924p-2, 0x1.e98fe8p0, -0x1.c85b6ap-3, 0x1.b8fbc4p-1, -0x1.62179ep-1, -0x1.2a5aeap0, 0x1.012722p0, -0x1.8f92c8p-1, 0x1.ea1da4p-3, -0x1.7d030cp0, 0x1.2b4c1p0, -0x1.7d3dd4p-1, -0x1.eb9512p0, 0x1.11efeap0, 0x1.98359ap-2, 0x1.b683eap-1, -0x1.bca47ap0, 0x1.bf10d8p-7, -0x1.eda994p0, 0x1.6951c6p-1, -0x1.bb803p-1, 0x1.dd3078p0, 0x1.34d716p0, -0x1.f0d4fcp-2, -0x1.c9aeecp-2, -0x1.6892f4p-1, -0x1.597102p0, -0x1.5c9632p-1, -0x1.c4eda6p0, -0x1.c7c9a8p-1, 0x1.fe68e6p0, 0x1.9b6a2p0, -0x1.b9c97ap0, 0x1.e8cc38p-2, 0x1.70a67cp-1, -0x1.5371e8p-1, -0x1.8320ecp-2, -0x1.5ffeap-1, -0x1.08aebp-1, -0x1.d7a4cp-2, 0x1.0f3eaap0, 0x1.e307bap-1, 0x1.5f5be8p-1, -0x1.822806p0, -0x1.84c8p-1, -0x1.1c856ap-4, 0x1.e4cc14p-1, -0x1.19a7dap-2, 0x1.287b48p0, 0x1.61f46ep-2, 0x1.096bbcp0, -0x1.c76944p-1, -0x1.d9d8b6p0, 0x1.f0a13cp-1, -0x1.81b286p-2, -0x1.21d6b4p0, -0x1.02d576p-2, -0x1.e1473ap0, 0x1.58c4ap-3, 0x1.251fd4p-2, -0x1.616ddcp0, 0x1.7a9936p-1, -0x1.4b67c4p0, 0x1.c4b22p0, -0x1.6b47bcp-1, -0x1.fb9048p0, -0x1.d783d6p0, 0x1.6ec576p0, -0x1.477032p0, 0x1.2056c2p0, 0x1.393834p-2, -0x1.637096p0, 0x1.c24658p0, -0x1.2d9a36p-2, -0x1.c144eep-2, 0x1.30ca7ep-1, 0x1.94ef6ap-1, 0x1.34dc54p0, -0x1.1aec6p-3, -0x1.44284cp-1, -0x1.3ac854p0, 0x1.c918fcp0, -0x1.df67a8p0, 0x1.8cea28p0, 0x1.9d3bdp-2, 0x1.59e5e4p-1, 0x1.5305ap-7, 0x1.8f6accp0, -0x1.07d106p-1, 0x1.dd6868p0, -0x1.8a9974p0, 0x1.597de4p-2, 0x1.389326p0, 0x1.ea1d78p0, 0x1.062a1cp0, 0x1.438a74p0, 0x1.12969ap-1, -0x1.c27014p0, 0x1.d515dp-5, 0x1.3c0d9p0, -0x1.7c123cp-2, -0x1.1d9462p-9, 0x1.bdac12p-1, 0x1.d13a78p0, 0x1.6243acp0, 0x1.7a7172p0, -0x1.d5fb02p-2, -0x1.6c644ap0, -0x1.ef4e3p0, 0x1.aee5d4p-3, 0x1.a79076p0, 0x1.71595ap-2, -0x1.22f88cp-1, 0x1.52a1acp-1, -0x1.90d15cp0, -0x1.541024p-1, -0x1.eb4b2cp0, 0x1.a8a1e4p-1, -0x1.b294a2p0, 0x1.efb7b2p0, -0x1.087334p0, 0x1.e20644p0, -0x1.e1aeap-3, -0x1.dd96dap0, 0x1.ac4482p-3, -0x1.c679bcp0, 0x1.06bdap-2, -0x1.47960cp0, -0x1.aa6622p-1, 0x1.d3bbb4p0, 0x1.9e25dap0, -0x1.4b0312p0, 0x1.61c5b8p0, 0x1.b7e7bcp0, 0x1.bd0752p0, -0x1.ae3298p0, 0x1.a5e9f8p-4, -0x1.d0ef26p0, 0x1.308c34p0, -0x1.391394p-1, -0x1.b3184ap-2, 0x1.e72d44p-3, 0x1.990788p-1, -0x1.87608ep-1, 0x1.47fcaap0, 0x1.81aa34p-2, 0x1.6f3524p0, -0x1.9c406ap0, 0x1.7d4b9p0, 0x1.16ba6cp-4, 0x1.e19efep-1, 0x1.050336p0, 0x1.ddcab8p0, 0x1.b24f2ap-1, -0x1.ac70dep-1, 0x1.773ce8p0, 0x1.3779d6p0, -0x1.a06d9ep-1, -0x1.f6ed36p-1, 0x1.69633cp-1, -0x1.947f8ap-2, 0x1.bab5a6p-1, 0x1.b9e5dp-1, 0x1.06a0dcp0, 0x1.a92c08p-2, -0x1.80d63ep0, -0x1.adb9fcp0, -0x1.e851ccp-2, 0x1.f1ae98p0, -0x1.8967acp0, -0x1.85c8cep-2, 0x1.59edaap-1, -0x1.4f524ap0, -0x1.f4fc7p0, 0x1.c97d1ep0, 0x1.a6b2e4p0, -0x1.6b17fep0, 0x1.e4692ap0, -0x1.7a50a4p0, -0x1.bc8e48p-4, 0x1.83d434p-1, -0x1.8543f4p0, 0x1.e8b95ap-6, 0x1.d7df3ap-1, 0x1.2218d2p0, -0x1.35bc12p-5, -0x1.33ccf2p0, -0x1.b4ce62p0, 0x1.4d89a2p-1, -0x1.7fa94ap0, -0x1.52b442p-1, 0x1.d0f0c8p-6, 0x1.bff2fep0, -0x1.bbd956p-1, -0x1.9da75ep0, -0x1.12522cp-1, 0x1.3638d2p0, 0x1.26e69cp-1, -0x1.b144f4p0, -0x1.dcc1f6p0, 0x1.1853aap0, -0x1.fb0654p0, -0x1.40478ap0, 0x1.8e4644p0, -0x1.60f7dcp-1, -0x1.6d0ff6p0, -0x1.69b322p0, -0x1.32fdf6p-4, 0x1.3da6c8p0, -0x1.673cc2p-1, 0x1.1aaf36p0, -0x1.54a49ep-2, 0x1.03f8bp-3, 0x1.7b0caep0, -0x1.9f983ap-1, 0x1.aae062p-3, -0x1.003fb8p-6, 0x1.08cd64p-1, 0x1.233344p-4, -0x1.64c1cep-1, 0x1.f19a1cp0, 0x1.43328ap-1, -0x1.f80558p0, 0x1.b57558p0, 0x1.e29d3ep0, -0x1.f6c91p0, 0x1.005ebap-1, -0x1.006a62p0, 0x1.10fbc6p-2, -0x1.d65e88p0, 0x1.679858p-3, -0x1.75da52p-1, 0x1.1ccb1p-2, 0x1.242872p0, 0x1.1260c4p0, 0x1.ca23bp0, 0x1.b6325ap0, -0x1.d41462p-1, 0x1.3c33b8p0, -0x1.39e74ep-3, 0x1.248e82p0, 0x1.338cb2p-3, 0x1.06eea8p-1, 0x1.c4ca04p0, 0x1.153de4p0, -0x1.936862p-1, -0x1.a1b0e4p0, 0x1.1c1bdp0, -0x1.19ba6ap-6, 0x1.1e26f6p-1, -0x1.1d82fcp0, 0x1.bc3996p0, 0x1.8bd84cp-3, -0x1.6fbc36p-3, 0x1.249ff4p0, -0x1.40aaap-3, -0x1.a3d0f8p0, 0x1.336b04p-1, 0x1.c75cd4p0, 0x1.ff2022p-1, -0x1.a2601cp-2, 0x1.d58f3ep-1, 0x1.4fd326p0, 0x1.489afcp-1, -0x1.87554ap-1, 0x1.806ccp0, 0x1.1e24ecp0, 0x1.ec738p0, -0x1.c1dfdep-1, 0x1.44fea6p0, 0x1.190648p0, -0x1.4f508ep-2, -0x1.22f6f2p-1, -0x1.9110a2p0, -0x1.a12d84p-1, -0x1.e36278p-3, 0x1.c8e59ap-2, -0x1.f20e34p-4, -0x1.d09cc6p0, -0x1.67d368p0, 0x1.214edep0, -0x1.f63072p0, 0x1.f15988p0, 0x1.1563acp-2, 0x1.b9294ap0, -0x1.52d856p-2, 0x1.d2adcep-1, 0x1.67077p0, -0x1.3d9082p-4, -0x1.76e352p0, -0x1.2cdffap0, -0x1.a79ee2p0, -0x1.1a83dp-1, 0x1.c714ccp0, 0x1.8c96dap0, -0x1.c19592p0, 0x1.2628ep0, -0x1.abfbdp0, -0x1.41f4ccp0, 0x1.52ad78p0, -0x1.6579cep-1, -0x1.4a4ce8p0, -0x1.65de7ep0, -0x1.0a45eap-1, -0x1.13579p-2, 0x1.a9a166p0, -0x1.31d6bap-1, 0x1.08c912p-1, -0x1.aa5366p-1, 0x1.d80e6p-5, -0x1.566884p0, 0x1.96a1d8p-3, -0x1.b4eca6p-1, -0x1.422becp-2, -0x1.b4fefap0, 0x1.74a5fp-2, 0x1.7395bep-2, 0x1.1041b4p-2, -0x1.5ac74ep-2, -0x1.2ba526p-2, -0x1.9adb0ap0, -0x1.ca256cp-4, 0x1.4a0934p0, -0x1.315e3ep0, -0x1.1ce208p-4, -0x1.e68bf2p-2, 0x1.006d2ap0, -0x1.284a72p-1, 0x1.03153ap0, -0x1.7d2436p-2, 0x1.23017p-1, -0x1.46577p-3, 0x1.012e0cp0, -0x1.a63ea8p0, -0x1.1290bap-1, 0x1.79a528p0, 0x1.76d706p-1, -0x1.d7834ap-2, -0x1.f338bep-5, -0x1.29fb14p0, -0x1.aa8534p-7, 0x1.85430ap-4, 0x1.953b2ep-2, -0x1.4fce4ap-1, 0x1.acd662p0, -0x1.53b1cep0, -0x1.e22c7ap0, 0x1.a08de4p0, 0x1.2fd466p0, 0x1.2c3ee8p0, 0x1.c57d36p0, 0x1.4ec5c4p0, 0x1.3996c2p-2, -0x1.892b7ap-4, -0x1.e5458p-1, -0x1.8b7bf2p0, 0x1.1ef65ap0, 0x1.3127f4p0, -0x1.411b64p0, 0x1.e13eb2p0, -0x1.3a30d2p-1, 0x1.b73588p-1, -0x1.caa06p-2, -0x1.331d52p0, 0x1.20ffb2p-1, 0x1.c0432cp0, -0x1.fbdbaap0, -0x1.b4f9aap0, 0x1.1a14c8p0, -0x1.86c2aap0, 0x1.68897p-2, -0x1.b927a8p0, 0x1.254d8cp-1, -0x1.27d2p-7, 0x1.c6fd4ap0, 0x1.02b89ep0, 0x1.e6e07p-6, -0x1.996956p-1, 0x1.fbd706p-1, -0x1.7ecd1cp-3, -0x1.6e2baap0, -0x1.5bb53cp-3, -0x1.132856p-1, 0x1.c195c6p-3, 0x1.0a9d2ap-2, 0x1.a780dap0, 0x1.6f0758p-1, 0x1.a8ae6p-1, -0x1.122e28p0, -0x1.0d125ap-3, 0x1.61ed1ap-1, 0x1.ec02c4p0, 0x1.0f641cp0, 0x1.43e4ccp-2, 0x1.c5722cp0, 0x1.af431ap0, 0x1.46c762p0, -0x1.5c9c14p-5, -0x1.d2c39cp0, -0x1.e72a9ep0, -0x1.364f38p0, -0x1.17eb62p-1, 0x1.2a0e6p-1, 0x1.40507ep-4, 0x1.7255f8p0, 0x1.15135ap-1, -0x1.a9a456p-3, -0x1.11c2d4p0, 0x1.8ac60ap-1, 0x1.e42712p0, -0x1.6feb64p-1, 0x1.60f06cp0, 0x1.2c0efp0, 0x1.2580a8p-1, 0x1.bff78ap-3, 0x1.7b3fc4p-2, -0x1.11b14ep-4, -0x1.9d4eb2p-3, 0x1.e5a94cp0, 0x1.c14c9cp-4, 0x1.589124p-1, 0x1.192d3ep0, -0x1.a8899ap-1, -0x1.3a3ea2p-2, -0x1.aa637cp-2, 0x1.ed7606p-1, -0x1.8035d2p-2, -0x1.32c902p0, 0x1.840394p0, -0x1.3bdd16p0, -0x1.5a9a8cp-1, -0x1.fc1962p0, 0x1.b1dffcp0, -0x1.7ef004p-2, 0x1.db473ap0, 0x1.8ac1e8p-1, -0x1.9c0272p-1, -0x1.4cdd5ap-3, -0x1.6554dp0, 0x1.ca0448p0, -0x1.536762p-1, -0x1.dcc70cp-2, -0x1.e8a362p0, -0x1.cc767ap-2, -0x1.fc53d8p-5, 0x1.d7263ap0, 0x1.d19a2ap0, 0x1.0306d2p-2, 0x1.db9eb6p-1, 0x1.764ebcp0, 0x1.660f46p0, -0x1.3ddb42p0, -0x1.f89b54p0, -0x1.d4f526p0, -0x1.a7514ap-2, -0x1.5b2666p0, 0x1.7deda4p0, 0x1.81ce3cp-1, 0x1.ee11f6p-1, 0x1.3d6c74p-1, -0x1.f5bab2p-2, 0x1.76c08ep-1, 0x1.7231bp0, 0x1.78bd6ap-1, -0x1.285a78p-1, 0x1.826316p0, -0x1.991ef6p-1, 0x1.65af6p-1, 0x1.4647fap-3, 0x1.d7ebc6p-2, 0x1.6fe18cp0, -0x1.3951acp-1, 0x1.5f51c4p-1, 0x1.e533p-1, 0x1.130b52p0, -0x1.ad30c6p0, -0x1.222544p-4, 0x1.9588eap0, 0x1.97b4ap-1, -0x1.80ab8cp0, -0x1.374c6ep0, 0x1.a6cb54p0, 0x1.2b7ec6p0, 0x1.d45e68p0, -0x1.427ee2p0, -0x1.115f74p0, -0x1.0263a6p0, -0x1.371c82p0, -0x1.b2e85cp0, 0x1.4adccp0, -0x1.45cb88p0, 0x1.967acap-3, -0x1.256a2p-1, -0x1.cf5622p-1, 0x1.89cf4ep0, 0x1.ed6a4ap-7, 0x1.ed5cp-1, -0x1.7f1b24p0, -0x1.efeacap0, -0x1.0f4ac8p-3, 0x1.b65204p-1, 0x1.967fc6p-2, 0x1.888a48p-1, 0x1.274472p-2, 0x1.058be4p0, -0x1.a623cap-2, 0x1.a1925p-5, -0x1.70a072p0, 0x1.253216p0, -0x1.682a5cp0, -0x1.660a46p0, -0x1.0f3bc4p-1, -0x1.d97652p-3, -0x1.25ff24p-2, 0x1.5306d4p0, -0x1.d4817p-1, 0x1.c1423ap-1, 0x1.31a84cp-1, -0x1.040f1ap0, 0x1.d495dp0, 0x1.c9741ep-1, 0x1.874e24p0, -0x1.186d44p-1, -0x1.fe64fcp-2, -0x1.eabee8p0, 0x1.63538p0, -0x1.b61406p0, 0x1.d21124p0, 0x1.60eaf4p0, -0x1.8d8f96p0, -0x1.2c0866p-1, 0x1.694c96p0, -0x1.4916eap-1, -0x1.43c11ep0, -0x1.6ccfbcp-1, -0x1.503bfcp0, 0x1.a9b292p0, -0x1.c3e09p-5, 0x1.9d33cep-2, 0x1.783246p-1, -0x1.5e5dc6p-1, 0x1.72d5aap-2, 0x1.66b302p0, 0x1.081368p0, -0x1.1810e4p-3, -0x1.0f977ep0, 0x1.61d4ecp-2, -0x1.66fe2ep0, 0x1.35d27ep-1, -0x1.71d224p-5, 0x1.d9d7fap0, 0x1.7748c6p0, 0x1.7193c6p0, -0x1.48fcdp0, 0x1.360f6ap-2, -0x1.382948p-1, 0x1.71e2dep0, 0x1.d15698p-1, 0x1.8a48d2p0, 0x1.315562p0, 0x1.f9c7a8p0, -0x1.d6d6c4p-1, 0x1.4c3f9ep-3, -0x1.3a9a62p-3, 0x1.6f7bp-2, 0x1.977d94p0, -0x1.93a568p0, 0x1.b8d332p0, 0x1.5c3876p0, 0x1.29dae2p0, -0x1.090d3p0, -0x1.b6fbccp0, -0x1.eda1f6p0, -0x1.2cde2ep-1, 0x1.f4e3b4p-2, 0x1.c34be2p0, -0x1.d12b1cp0, 0x1.d10d88p-1, -0x1.b5d2dp0, 0x1.bebfc4p0, -0x1.386bb4p0, 0x1.daa288p0, -0x1.c2c80cp-2, -0x1.9cf1d8p0, -0x1.596268p0, 0x1.f3de12p0, -0x1.b2a784p0, -0x1.4e465ep-1, 0x1.2a59b2p0, 0x1.7a1aa6p0, 0x1.60495ap0, 0x1.15dc42p-3, -0x1.54ab9cp0, 0x1.16bccap-2, 0x1.8dfff8p-1, 0x1.764938p0, 0x1.f27138p-1, -0x1.30e516p-1, 0x1.fc2804p-1, 0x1.996256p-1, 0x1.64b698p0, -0x1.a28668p-2, -0x1.6c5404p0, 0x1.5d1dacp0, 0x1.665906p0, -0x1.2c968ap0, -0x1.4597e8p-1, 0x1.9bdea8p0, -0x1.68d4e2p0, 0x1.b1f634p0, 0x1.aab04ap0, 0x1.f08d86p-1, 0x1.c6396cp-2, -0x1.a6eb04p-2, 0x1.7858bap-3, -0x1.18dbc6p-1, -0x1.58ab2ep0, 0x1.5f9d78p0, 0x1.3eb4dep0, -0x1.a0c4e8p0, 0x1.ca62ep0, 0x1.c8f30ap0, -0x1.33144ep-4, -0x1.b1bfeep0, -0x1.4e1b28p0, -0x1.59a686p0, 0x1.d330aap0, 0x1.60fd3ep0, -0x1.4b7eep-3, 0x1.b3641cp-3, 0x1.c7a09ep0, -0x1.2abddep-2, -0x1.bbe518p-1, 0x1.f825aep-3, -0x1.afb99ep-1, 0x1.29919ap-5, 0x1.e2aceap0, -0x1.f15cc2p0, 0x1.10b89cp-1, 0x1.878a0cp-1, 0x1.2b1af6p0, 0x1.ab221cp-1, -0x1.fdf99cp-1, -0x1.524adep-2, 0x1.6371f4p0, -0x1.1d4394p-2, 0x1.7658e4p-1, 0x1.ee360ap-5, -0x1.1cbdbep0, 0x1.45b576p0, 0x1.8808ccp0, -0x1.01468p0, 0x1.547dfap-1, 0x1.1d1926p0, 0x1.70b9c4p0, -0x1.8358a4p-1, -0x1.9784bap0, -0x1.b6b38p-1, -0x1.3c00bcp0, -0x1.8cca26p-1, 0x1.22c36ap0, -0x1.14430ep0, -0x1.307e9ep-1, 0x1.ee9e16p-3, 0x1.1e16a6p-1, -0x1.b993e4p-1, -0x1.68d5c4p0, 0x1.14e40cp0, 0x1.1230d8p-2, 0x1.192b98p-1, -0x1.182756p0, -0x1.5f60f6p-2, -0x1.efce22p-1, 0x1.1d8baep0, 0x1.ff387ap0, 0x1.c7103ep-5, -0x1.3ed15ep-1, -0x1.483d8cp0, 0x1.881d16p-2, -0x1.2f31d8p-1, -0x1.08ae9ep-1, -0x1.db8d68p-2, 0x1.78934ep-1, -0x1.f30a0ap0, 0x1.ec4e6ap0, 0x1.4fd9aap-1, -0x1.a235aep0, 0x1.f06be6p0, -0x1.166d5p-1, -0x1.ae4926p-4, 0x1.78fda2p0, -0x1.bed77ep-1, -0x1.5e47a4p0, 0x1.36c6fep0, 0x1.89399ap-3, -0x1.5fea0cp0, -0x1.fb5d82p-1, 0x1.b62246p0, -0x1.2323ep0, -0x1.cee61ap-1, 0x1.ad9ea4p-1, -0x1.b2ce0ap-2, -0x1.f1a736p0, 0x1.2c6ee8p-4, 0x1.4d2d86p-1, -0x1.34aa6ap0, -0x1.f07528p-2, 0x1.2f5afcp0, -0x1.566502p-1, -0x1.f6d554p0, 0x1.137d72p-1, -0x1.790a52p-6, 0x1.972ce6p-1, 0x1.04ce58p0, 0x1.067572p0, -0x1.d30a1ap-2 };
float c_activation_3_test5_array[6];
float keras_activation_3_test3_array[6] = { 0x1.9408a6p-3, 0x1.5419f6p-5, 0x1.1eb0b2p-5, 0x1.ed3674p-4, 0x1.1e971cp-1, 0x1.793422p-5 };
float c_activation_3_test3_array[6];
float test4_dense_input_input_array[2622] = { -0x1.5c38bap0, -0x1.05103ep-3, 0x1.137fdcp-1, -0x1.afb7dp0, 0x1.727d8ap-1, -0x1.e13458p0, -0x1.2296cep0, -0x1.c11d26p0, 0x1.afa2p-3, 0x1.673cd8p-1, -0x1.0a51eep0, 0x1.a2d4b4p0, 0x1.2fd88p-4, 0x1.23c27cp-3, -0x1.294f88p-1, 0x1.831d0ep-1, -0x1.88a5c4p-1, 0x1.ad3c9ep-5, -0x1.5e0b6ep-1, -0x1.6ba7dp0, 0x1.c3b102p0, 0x1.33bbfep0, 0x1.f5ca5p0, 0x1.5fc3fcp0, -0x1.7fcfcp0, 0x1.6c5f68p0, -0x1.09ac3cp-1, 0x1.7e88bcp-3, -0x1.ce166p-3, -0x1.6f8092p0, -0x1.9f9ffap0, -0x1.76340ap0, 0x1.3c1d96p0, 0x1.8e3422p0, 0x1.9b193ap-2, 0x1.bfb686p0, 0x1.879eaep-1, 0x1.fae15ep-3, 0x1.67a53ap0, -0x1.1f88d8p0, -0x1.a5e04ap-1, -0x1.b7d61ep-7, 0x1.972df2p0, 0x1.c25ea8p0, -0x1.37867ap-1, 0x1.b6d3bap-5, 0x1.7382e2p-1, 0x1.2ec8b2p0, -0x1.fc8afap-1, 0x1.c8b502p-2, -0x1.a5819ap0, 0x1.0db958p-1, 0x1.5e08acp0, 0x1.293366p0, 0x1.6aff9cp-3, 0x1.9e46a8p0, -0x1.bc47ap0, 0x1.9d23dcp-2, -0x1.7d4d84p0, 0x1.75f0b2p0, -0x1.ee18b8p-2, -0x1.b11a7ap0, -0x1.cdae18p-2, 0x1.551324p-2, -0x1.2333dap0, -0x1.4ed18cp-1, 0x1.97dbfcp0, 0x1.ae9baap-2, 0x1.0dbc9ep0, 0x1.e1301cp-2, -0x1.9f222ap0, -0x1.f5a462p-2, -0x1.8b9972p-2, 0x1.d6c06ap0, -0x1.6e1682p0, 0x1.8c0706p0, 0x1.514de4p0, 0x1.d810a2p-1, -0x1.11734cp-2, -0x1.41794ap0, 0x1.a44618p0, -0x1.b799ecp-6, 0x1.f4c00ap-2, 0x1.8cac02p-6, -0x1.58d474p-1, -0x1.929948p0, 0x1.af70cap-3, 0x1.33e97ep-1, -0x1.07fb86p0, 0x1.2e5a68p0, -0x1.38f524p-2, -0x1.effbdap0, -0x1.cf64b8p-1, 0x1.3855fp0, 0x1.0ceaaep0, -0x1.72aa1ep-1, -0x1.37b7b6p-2, 0x1.09b524p-1, -0x1.2f31fap0, 0x1.89fa76p-3, 0x1.8bde6cp0, -0x1.6efd5cp-2, 0x1.f10e52p-1, -0x1.d3099p0, -0x1.0fb5fp-1, 0x1.45e23ep0, 0x1.87ad66p-6, 0x1.f8143ep0, 0x1.cd53d8p0, -0x1.2f109cp-3, -0x1.4b454cp-1, 0x1.d5bc36p-3, -0x1.55ep-1, -0x1.0dc04ep-3, -0x1.de4b38p-4, -0x1.bd6284p0, -0x1.30b196p0, 0x1.29dd0ep0, -0x1.c88e2ap0, 0x1.43d63ap-1, -0x1.3d66bcp-1, -0x1.d14528p-3, -0x1.dc1af6p0, -0x1.a341fap-1, 0x1.687a6ep0, 0x1.2bbbbap0, -0x1.e5973ep0, 0x1.91a7ep-3, 0x1.0dee3ap-1, 0x1.a2846ep-2, 0x1.4c0324p-1, -0x1.2366f6p0, -0x1.7b82a4p0, 0x1.9cfddep-1, 0x1.d6bd0ep-1, 0x1.ebbd62p-1, 0x1.361e84p-3, -0x1.f79c9ap-2, -0x1.cea6b4p0, -0x1.2a4e6cp0, -0x1.32d3e8p0, 0x1.a343d6p0, -0x1.8e5bdap0, -0x1.cf743ap-2, 0x1.cc0a8cp-2, -0x1.bd9626p0, -0x1.9e021ep-1, 0x1.7cab34p0, -0x1.af5ddp0, -0x1.94519cp-1, 0x1.2ac26ep-2, 0x1.5136dcp-2, 0x1.67ed2ap-1, -0x1.402704p0, -0x1.4d990ep0, -0x1.2293a2p-1, -0x1.b9fd34p0, -0x1.6fd61cp0, 0x1.465e88p-3, 0x1.a9514ap0, 0x1.c8e508p0, 0x1.3eec14p0, -0x1.68c926p-1, -0x1.752626p0, -0x1.584d44p0, -0x1.5100aap0, 0x1.e82262p0, -0x1.99635ap0, 0x1.1ae8dap-2, 0x1.057e76p0, -0x1.784954p0, 0x1.a74b6ep0, -0x1.f2fc1ap0, 0x1.3ca0b2p-2, -0x1.793804p-1, 0x1.a37b5ap0, -0x1.0ae03ep-1, -0x1.3e4c12p0, -0x1.9e375ap-1, 0x1.60c172p0, -0x1.b132bep-1, -0x1.3f83dp-3, 0x1.f9d7ep-1, -0x1.d33592p-4, -0x1.ae747cp-2, -0x1.241c8cp0, 0x1.c67ae6p0, -0x1.1142ecp-3, 0x1.85646ep-2, -0x1.189322p0, 0x1.6410fep-5, 0x1.f45e7cp0, 0x1.e57a96p-1, 0x1.775ecp-1, 0x1.f39decp0, 0x1.7a8fdp0, 0x1.3881cap0, 0x1.8c05a2p0, -0x1.2a1924p-1, -0x1.fbeae4p-1, 0x1.fff538p-3, 0x1.7939b4p-2, -0x1.63d82p-2, -0x1.b0d53ap-1, -0x1.617696p-5, 0x1.7aecbp-3, -0x1.29f498p-1, -0x1.61392p0, 0x1.db0394p0, -0x1.4cb69cp0, 0x1.97747cp-1, 0x1.c009dap0, 0x1.29f5bp0, -0x1.d5061ap-10, 0x1.caf758p-3, 0x1.fc3044p0, -0x1.6f9f24p0, 0x1.76bbeap-2, 0x1.d92ae8p-2, -0x1.7932bep0, 0x1.04a0c8p-1, -0x1.1f799ep-1, -0x1.8b406p0, -0x1.d1aa1ep0, 0x1.2ba956p0, -0x1.e740e6p0, 0x1.a1864ap0, 0x1.40db9ap-1, 0x1.680996p-2, -0x1.3e7146p-1, 0x1.36ff9ep0, -0x1.7ffb52p-1, 0x1.168832p0, -0x1.6d43ap-2, -0x1.76cbcp0, -0x1.2aa91cp-2, -0x1.443e6ap-2, 0x1.ba6bf8p0, 0x1.8af362p-1, 0x1.145878p0, -0x1.14341cp-1, 0x1.1c89bep-2, 0x1.65e77ep-1, -0x1.d9e032p-1, -0x1.3b645cp-1, -0x1.f725e2p-2, -0x1.eaf6b8p0, 0x1.2227a2p0, -0x1.26b4bap0, -0x1.cd99c6p0, -0x1.21a7ccp0, -0x1.f42e2p-1, -0x1.51c69ep-2, 0x1.a693fp-2, 0x1.e12c12p-1, -0x1.7ed3dep0, 0x1.beb426p0, 0x1.80cdbap0, -0x1.78af22p0, 0x1.771502p-1, -0x1.f23a12p0, -0x1.32004ap-3, 0x1.ec20c8p0, -0x1.5849a6p0, 0x1.1202cap0, 0x1.58322cp0, 0x1.350372p0, -0x1.8c4fdcp0, -0x1.bb4aaep-1, 0x1.25edb2p-2, 0x1.102602p0, -0x1.41cbc4p-1, -0x1.ebb276p0, 0x1.6ef41ep0, 0x1.229186p-3, -0x1.64c242p0, -0x1.82fd0ap0, 0x1.bc04ecp-2, -0x1.b59ccep-3, 0x1.5593cp-4, 0x1.887e22p-1, 0x1.5c4f4ap-4, -0x1.6aa9d8p0, -0x1.666f64p0, 0x1.868b42p0, -0x1.06436cp0, -0x1.4de304p-3, -0x1.747876p0, 0x1.234e9p-1, -0x1.5f8b7ep0, 0x1.ebb42cp0, 0x1.a63ddcp-2, 0x1.f3279ap0, 0x1.e3ea1p0, 0x1.23f0dap-3, -0x1.515572p-1, 0x1.895756p0, -0x1.d07ebcp-6, 0x1.55f886p0, -0x1.500e76p0, 0x1.291e38p0, -0x1.ab4c72p-1, 0x1.2e3c7cp-4, -0x1.5bf138p-2, 0x1.4e5316p-2, -0x1.0c5aap0, -0x1.5406c2p-1, -0x1.3205e6p-6, 0x1.d14b9ep0, 0x1.16a788p0, 0x1.b6e0b4p0, -0x1.0a061ep0, -0x1.92df3p-9, -0x1.50475cp-1, 0x1.9bc8fap-4, -0x1.f1e26cp0, -0x1.2d1bp-2, -0x1.e47794p0, 0x1.0e3b94p0, -0x1.b91d9cp-3, -0x1.761d58p-1, 0x1.16d60ep0, 0x1.55bc92p0, 0x1.2d7b2ap-1, 0x1.104216p-1, 0x1.b3451ap-1, -0x1.5c3422p-1, -0x1.1e9476p0, -0x1.1e1076p-2, -0x1.876e9ap0, 0x1.49390cp-1, 0x1.b7e906p0, -0x1.634dd4p0, -0x1.8e625ap0, 0x1.6b9cbcp-4, -0x1.5de2dap-1, 0x1.6e95c2p-5, -0x1.285294p-3, -0x1.d3df06p0, -0x1.05a23p-3, 0x1.71d3e6p0, 0x1.bd4ee8p-1, -0x1.7f36f6p0, -0x1.37f578p-2, 0x1.1db402p-4, 0x1.c14586p-1, 0x1.e5196p-3, -0x1.618abp-1, -0x1.62e408p0, 0x1.480d9ep0, 0x1.b40426p0, -0x1.716eb2p-1, 0x1.9f69bp-2, -0x1.96049ap0, 0x1.0dc78cp-1, -0x1.5697c8p0, -0x1.dbc2cp0, 0x1.5f00eep-1, 0x1.4e6dcap0, -0x1.2a2dcap0, -0x1.80d81cp-1, 0x1.88e22p0, 0x1.c673d2p-2, 0x1.1c1e9ap0, 0x1.ac30b6p0, 0x1.e6296ep-1, 0x1.27df8ap-1, -0x1.585cecp0, 0x1.f31b94p0, 0x1.37ba9ap0, 0x1.2305eap0, -0x1.197e36p0, -0x1.d9d5bcp-1, -0x1.a3ac48p-2, 0x1.90b59ep0, 0x1.21fbdcp-4, 0x1.bd4c86p-2, 0x1.145d3cp-1, 0x1.a10f2p0, -0x1.909946p-1, 0x1.0bff5p0, -0x1.ecebccp0, 0x1.ef031cp0, 0x1.219a04p-1, 0x1.a7244ep0, -0x1.791c52p0, 0x1.2f5054p-1, -0x1.7a83c6p-1, -0x1.38b99ap-1, 0x1.491e6ep0, -0x1.ea8772p-1, 0x1.2fc11ep0, 0x1.acba8ep0, 0x1.82a80cp-3, 0x1.931f62p-1, -0x1.d898bap0, -0x1.91945p-1, -0x1.d792bp-4, -0x1.1c24b6p0, 0x1.d58df6p-1, -0x1.fcde56p-1, -0x1.98a6fep0, 0x1.bea4cp-3, -0x1.b7b2c2p-3, 0x1.c5cc4ap0, 0x1.22fff8p-2, -0x1.29a30ap-1, 0x1.dc1ec6p-1, 0x1.4995aap0, 0x1.22c7fep-1, -0x1.58b64ap-1, -0x1.dc340cp-5, -0x1.03a234p-3, 0x1.c8519cp-1, 0x1.d6edbap-1, -0x1.814bdep-1, 0x1.d95f14p0, 0x1.581932p-1, -0x1.baf6f4p0, 0x1.20753ap0, 0x1.6cac96p-1, 0x1.ed2258p0, 0x1.17505cp0, -0x1.a52508p-1, 0x1.344718p-3, -0x1.0f7cp0, 0x1.c4dd76p0, -0x1.0049d8p-3, 0x1.5b8ca2p0, -0x1.a1be08p0, -0x1.d515c8p-2, 0x1.de8344p-1, 0x1.492572p0, 0x1.055fe4p-3, 0x1.7f82bap-3, 0x1.0b364cp0, 0x1.daed76p-1, 0x1.34719p-1, 0x1.18aecep0, 0x1.029edcp-2, 0x1.40da06p-2, -0x1.cf15bap0, 0x1.b43cd4p-1, 0x1.60d78cp0, 0x1.22fb74p-1, 0x1.48a2d6p0, -0x1.40be58p-4, -0x1.4df11cp0, 0x1.b77bfep0, 0x1.c4a6c4p-2, 0x1.fbd2f2p0, -0x1.efd36ep0, 0x1.82748ep0, -0x1.7f1d48p0, 0x1.e8599p-1, -0x1.4234dp-1, 0x1.4edfc8p0, -0x1.00968p-1, 0x1.75c2dcp0, 0x1.3831fap-1, 0x1.962366p0, 0x1.82971ap0, -0x1.e8e9eap-1, 0x1.9a8068p0, -0x1.c87e1ap0, -0x1.270b96p-1, 0x1.db4c76p0, -0x1.7d20a6p0, 0x1.82a628p0, 0x1.48272p0, 0x1.5f5812p0, -0x1.64c396p-1, 0x1.61013ep0, -0x1.26d44cp-6, 0x1.08dd9cp-2, -0x1.c555c8p-1, -0x1.255ad6p-6, -0x1.a0ce38p0, 0x1.b9a078p-1, 0x1.0150b6p-2, 0x1.27ee2ap-2, -0x1.7c8248p0, -0x1.4a1adp-1, -0x1.1b4202p0, -0x1.fc9694p-1, -0x1.15762cp0, -0x1.efb1ecp-2, 0x1.b51c32p-2, 0x1.d6c2ep0, -0x1.6d4d88p0, -0x1.1ada0ap-1, -0x1.0c57fp0, 0x1.29daep-2, 0x1.2591dep-4, -0x1.681f8p-1, 0x1.1a22a4p-3, -0x1.f5d66cp-8, -0x1.aa4a24p0, -0x1.4e34bep-2, -0x1.32eb62p0, -0x1.5b14b6p-3, -0x1.b1bddep-1, -0x1.cfb05p0, -0x1.7ee45cp-1, 0x1.ff1d24p0, 0x1.bd51e6p0, -0x1.74e89cp-2, 0x1.b46becp0, 0x1.07280ap-1, -0x1.859428p0, 0x1.5ab05ap0, -0x1.9fb5d2p-2, 0x1.4e981cp0, -0x1.86f22cp0, 0x1.dd719ep0, 0x1.fa364p-2, 0x1.44e9acp0, 0x1.1daep0, 0x1.49b7acp0, -0x1.d004b4p-1, 0x1.f69ba2p-6, -0x1.316bdep0, 0x1.54569cp-1, -0x1.0fe074p-3, -0x1.6e0d66p-1, 0x1.5850e2p0, -0x1.f6930ep-1, 0x1.f1b59ep-5, -0x1.2794eap0, 0x1.b66822p-1, 0x1.e308c8p-1, 0x1.f85b5ap-5, -0x1.5ab0d2p0, -0x1.15b32cp0, -0x1.cd492ap0, 0x1.eb876ep-2, -0x1.be6f2ap-1, 0x1.a3e3f6p-1, -0x1.c72a08p-1, 0x1.69e3fcp-3, 0x1.9cc0e6p0, -0x1.b34266p0, -0x1.5a8ca6p-1, 0x1.40a2ep0, 0x1.d7b436p-1, -0x1.87fd14p-1, -0x1.ae59a2p-1, 0x1.b8b8b4p-1, 0x1.78183ep-2, 0x1.1376cp-1, -0x1.2b3234p-2, 0x1.e0622ep0, -0x1.25a9d4p-2, 0x1.5c8a3ap0, 0x1.a7463p-1, -0x1.dc063ep-2, -0x1.84ca9p0, -0x1.2ec986p0, -0x1.747ce6p-1, -0x1.5816b4p-1, 0x1.6366c2p-1, 0x1.2952c8p0, 0x1.1ae6c2p-3, -0x1.19436p0, -0x1.afa5b6p0, 0x1.cb52fcp-2, 0x1.cd46eep-3, 0x1.055226p-1, 0x1.86e614p0, -0x1.8d7e12p-3, -0x1.2f930ap-1, -0x1.21138ap-1, -0x1.b4db36p-3, -0x1.5fe7bp-3, -0x1.93a318p0, -0x1.042464p-1, 0x1.22c7p-1, -0x1.c72e44p0, 0x1.e86e88p0, 0x1.744104p0, 0x1.f5856ap-2, 0x1.6dd56ep-1, 0x1.a158c8p0, 0x1.1540b4p-2, 0x1.3ac742p-2, 0x1.04801ep-4, 0x1.a1a1eep-3, -0x1.8fd202p0, 0x1.ab2438p-1, -0x1.a76b58p-1, 0x1.e3eeb4p0, -0x1.d51c06p0, 0x1.a8ac32p-4, -0x1.16d6cap-1, -0x1.f5c25ep-1, 0x1.06e28cp0, -0x1.263aaap-1, -0x1.237facp-2, -0x1.7d5c08p-1, 0x1.c6f5b6p0, 0x1.e1df9cp0, -0x1.70414ep0, -0x1.0a8b1p-1, -0x1.7ae14p0, -0x1.5b1ca4p-1, -0x1.dfe628p-1, 0x1.624decp-1, -0x1.b298eep-4, -0x1.a87162p-5, 0x1.4bc35ap0, -0x1.809312p-1, -0x1.af5f0ap-1, 0x1.9a161p0, 0x1.717f38p-1, -0x1.1e059ap-2, -0x1.395e76p-5, 0x1.1c277ap-2, -0x1.0c988cp-1, -0x1.a1b3acp-1, 0x1.d5021p0, 0x1.4211cap0, 0x1.1a0fe6p-1, -0x1.7a14bp0, 0x1.834fdp-4, -0x1.64c81cp0, -0x1.3a1164p0, 0x1.b758a4p0, -0x1.bc8ebcp-2, -0x1.e14f64p0, -0x1.a493fp-2, -0x1.8f0bfp-2, -0x1.69142ep-1, 0x1.9471d4p-3, -0x1.573244p0, 0x1.c1b856p-1, -0x1.ce3ecp0, -0x1.732aeep0, -0x1.0b0e0cp-1, 0x1.ff60dcp-3, -0x1.500314p0, -0x1.45e09p0, -0x1.d91616p0, -0x1.172bf6p-2, 0x1.fb7a04p0, 0x1.98f648p0, 0x1.fe6068p-1, 0x1.0ab294p0, 0x1.0ac87cp0, -0x1.7e45bp-1, -0x1.b00e76p0, -0x1.cef504p-1, 0x1.3af5ccp0, -0x1.704052p0, 0x1.8c3304p-3, -0x1.1a1d1ep-1, -0x1.ffc6d6p0, 0x1.fdf408p-1, 0x1.ed47aep0, -0x1.0fa5bp-4, -0x1.26aca6p0, -0x1.ff2acap0, 0x1.bbb9b8p-2, -0x1.23cd0cp-1, 0x1.a87834p0, -0x1.da7e94p0, -0x1.906ccap0, -0x1.399458p-2, 0x1.bcf0d4p0, -0x1.22d74p0, -0x1.d5c536p0, 0x1.191daap-1, -0x1.fa52e2p-1, -0x1.a275eap-1, -0x1.636376p0, 0x1.073856p0, -0x1.eef50ep-1, 0x1.9c0986p-2, -0x1.75417p0, 0x1.1ae7ccp0, -0x1.0a8bd6p-1, -0x1.e8846cp-2, -0x1.b385eap-2, 0x1.fe372cp0, -0x1.99714ap-1, -0x1.8e6076p0, 0x1.906afp0, -0x1.8d88aap0, 0x1.8d420cp0, 0x1.1959a2p-1, -0x1.cb6c78p0, -0x1.906b5ap-1, -0x1.08de06p-1, -0x1.ebc288p0, 0x1.8ff158p-4, 0x1.eee81ep0, -0x1.2eaa44p-1, -0x1.d20e66p-1, -0x1.db0baap-3, 0x1.8ff07ep0, 0x1.7b197ap0, -0x1.751906p0, 0x1.80fb52p-1, -0x1.96a64ap0, -0x1.015eb6p-3, 0x1.18e868p-1, -0x1.4c7318p0, 0x1.8fb11ap-1, 0x1.d9f682p0, 0x1.4c6b34p-1, 0x1.2bab2ap-1, 0x1.7cf476p0, -0x1.270522p0, 0x1.780bfcp0, -0x1.ca5fdp0, -0x1.697118p0, 0x1.7beb22p-2, -0x1.4f84bp0, 0x1.d15598p0, 0x1.c8423cp0, -0x1.d5a31ap0, -0x1.24d7dcp0, -0x1.4d98d6p-1, 0x1.0139a4p-1, -0x1.21df6ap0, -0x1.857a4p-3, -0x1.447398p-1, 0x1.8907aap-1, 0x1.0890ecp0, -0x1.5ade08p0, -0x1.81cbbcp-4, 0x1.0c5c74p0, 0x1.43bd6ap-1, 0x1.c040cap0, 0x1.458cc4p-1, -0x1.396a34p0, -0x1.b4e706p0, -0x1.07ebb2p-1, -0x1.610dcp0, 0x1.8cbb5ep0, 0x1.b92b8ap0, -0x1.4d442ep-1, 0x1.d779d4p0, -0x1.f4d4e4p-1, -0x1.b4b7f4p0, -0x1.58feep0, -0x1.1c0abap-2, -0x1.407bb8p0, 0x1.a8c1fp-1, 0x1.b05d2ap0, 0x1.21d63ep-1, 0x1.18ad08p0, -0x1.5c8224p0, 0x1.45d6eep0, -0x1.2954a8p-3, 0x1.9f977p-1, 0x1.c78e8p0, 0x1.258d82p-3, 0x1.a0d3dcp0, 0x1.1fac16p0, -0x1.5b1104p0, -0x1.ac5154p-3, -0x1.9a620ep0, -0x1.6e98ccp0, 0x1.c79968p-4, -0x1.77da6ap0, 0x1.4b0a28p-1, 0x1.7a7edep-3, 0x1.c4b292p-3, 0x1.85261ap0, 0x1.8690b6p0, -0x1.7d4974p0, -0x1.13cf3ap-8, 0x1.3d75e8p-2, -0x1.82868cp0, 0x1.cd0784p-4, 0x1.d9f884p0, 0x1.ffae8p-5, -0x1.d1b968p0, -0x1.148deap0, 0x1.806bbcp0, -0x1.3fbed4p-1, -0x1.b3f5a8p0, 0x1.bf4b8cp-1, -0x1.166f22p-2, 0x1.0180b6p0, 0x1.53ba0ep-2, -0x1.c153acp-4, 0x1.2f072p-1, -0x1.dcf514p0, 0x1.e6a036p0, 0x1.9f98bcp-1, 0x1.d8d234p0, 0x1.c79828p-3, -0x1.f3ea62p0, 0x1.ed2692p0, -0x1.35b6e6p-3, 0x1.27ba9ap0, 0x1.40fa7cp0, -0x1.2b2412p0, -0x1.9dfc8cp0, 0x1.7a3e24p-1, -0x1.0ffb88p-3, 0x1.77f774p0, 0x1.e6104ep-1, 0x1.e00aecp0, -0x1.d9ef0ap-5, 0x1.6d7518p-2, -0x1.ea3596p0, -0x1.13ec62p0, -0x1.77131p0, -0x1.e29f34p-5, 0x1.bb2cc2p-3, 0x1.5c2d56p0, -0x1.782108p0, -0x1.923122p-1, 0x1.631092p-1, -0x1.a22436p0, -0x1.ed1daap0, -0x1.0e43ep-7, 0x1.48219p0, -0x1.dc130ep0, -0x1.0c4f8cp-1, -0x1.b38328p0, -0x1.725b6ap-2, -0x1.8de1cap-4, 0x1.b0e376p0, 0x1.4dd1dap0, -0x1.e42308p-1, 0x1.1066fap-1, -0x1.bd3db8p0, 0x1.ce56ccp0, -0x1.58c9c8p-1, 0x1.c16662p0, 0x1.d2986ap0, 0x1.9657c4p0, -0x1.359a98p-2, -0x1.fd1324p-2, 0x1.1bf264p0, 0x1.8a0fa2p-2, -0x1.0395c4p-2, 0x1.197704p0, 0x1.903bc4p0, -0x1.0d0fd4p0, -0x1.11c1bap0, -0x1.a889c4p-1, -0x1.5d0696p-1, 0x1.b7f816p0, 0x1.76fda8p-1, 0x1.8d657cp-2, 0x1.9c1522p0, -0x1.96e4c8p0, 0x1.5e12f8p-2, 0x1.ba0e98p-2, -0x1.71e26ep-5, 0x1.eca09ep-4, 0x1.bd314cp-2, -0x1.6ecc4p-1, 0x1.cb429ap0, -0x1.3e8006p-2, 0x1.156cdap-5, 0x1.255f64p-3, -0x1.2df39ep-4, -0x1.52f10ap-1, 0x1.5363e8p-1, -0x1.3c48e2p0, -0x1.c076dp0, -0x1.ff5b86p0, -0x1.0f47d2p0, 0x1.6b6bc6p-2, -0x1.b3b78p-1, 0x1.eb5e24p-2, -0x1.d238d4p0, -0x1.0f73f6p-2, -0x1.56d3dap0, -0x1.3bf0aap-1, 0x1.2af132p0, -0x1.308c8ep-1, 0x1.453066p-1, -0x1.3b1cf2p0, -0x1.2bf90cp-2, -0x1.4f8628p-1, 0x1.fc1686p0, -0x1.7d084p0, 0x1.369414p-2, -0x1.17ca14p0, 0x1.304842p-2, 0x1.605228p0, 0x1.f81676p0, 0x1.4d818p-1, -0x1.aab8f4p-2, -0x1.cca92ep0, 0x1.908d12p-2, 0x1.8ef6p0, 0x1.5d5f94p-1, -0x1.a2e74ep0, -0x1.47baccp-1, 0x1.31947p0, -0x1.0b7aa8p-3, 0x1.5cba62p-1, -0x1.7ceeaap-1, -0x1.f56606p0, -0x1.8e2508p-5, 0x1.3f8ecap-3, 0x1.12a2dcp0, -0x1.371bd2p-3, -0x1.109e7cp0, -0x1.438ee6p-3, -0x1.62ece6p0, -0x1.94d49cp-1, 0x1.4a33cep0, 0x1.054898p-3, 0x1.19b8f2p0, -0x1.f8c3b4p0, 0x1.9376ccp0, -0x1.9ecd98p-1, 0x1.31b302p0, -0x1.435ab2p-5, 0x1.55b00cp0, -0x1.97a60ep-4, -0x1.33063p0, -0x1.7b64bp0, 0x1.e3a4e6p-2, 0x1.75614p-5, -0x1.f6d8c8p-4, -0x1.fd9698p-1, 0x1.34aee8p0, -0x1.8b576cp-1, 0x1.02c856p0, 0x1.d98eb2p0, -0x1.cc3462p0, 0x1.8a9c6cp0, -0x1.5839fp0, -0x1.54cbfp0, -0x1.e5f596p-1, -0x1.775cb2p0, 0x1.1f424ap-1, -0x1.f9a994p0, -0x1.3e05b6p-2, -0x1.c40862p-2, 0x1.4e85b8p-1, -0x1.e0434cp-1, -0x1.39c3dcp0, 0x1.8d1fccp-1, -0x1.bb19bcp-1, -0x1.9c6b04p0, -0x1.671472p-2, -0x1.986a7ap-3, 0x1.029d1cp-1, -0x1.51e29ap0, 0x1.36f6ep0, 0x1.99ebcp0, -0x1.2957cp0, 0x1.f21da2p0, -0x1.11e7ccp-2, -0x1.c751cep0, 0x1.cdab0ap-1, 0x1.b0cf8ep0, 0x1.b89a6cp0, -0x1.f4df6cp0, 0x1.114dc8p0, 0x1.2ba57ap0, -0x1.f8c24ap-1, 0x1.7a21cap-1, 0x1.b89612p-1, -0x1.9f3c5ep0, 0x1.a09714p0, 0x1.853236p0, 0x1.e521dp0, -0x1.1d0a42p0, -0x1.dafb9cp-1, 0x1.9e7d2ap0, 0x1.7b7812p0, -0x1.29d198p0, 0x1.afe58p0, 0x1.7219fep0, -0x1.4c0b46p-2, 0x1.b02f8ep0, -0x1.553f96p-3, -0x1.9e4214p0, 0x1.5d68bap0, 0x1.d61ab4p0, -0x1.13039cp-2, 0x1.3bfab6p-1, 0x1.dcc9d8p-2, -0x1.46da32p0, 0x1.36f76ap0, 0x1.3dfcd8p0, 0x1.2d4246p0, 0x1.e1ca4p0, -0x1.9df8e6p-2, -0x1.3fc01ap0, 0x1.b4a50ep-1, 0x1.81b79cp-1, 0x1.35e7b6p0, -0x1.e48e44p-1, -0x1.e4c68ap-1, 0x1.24b3bp0, -0x1.44781ep0, 0x1.69da6p0, -0x1.cc7faap0, 0x1.af841p0, 0x1.97fa0ep-5, 0x1.c95c1ap0, 0x1.d2d6ecp0, -0x1.3aabbp-3, 0x1.3e2144p0, -0x1.db2af6p0, -0x1.e6e2a8p-1, -0x1.c8c852p0, 0x1.959bc6p-1, 0x1.aad12p0, 0x1.5dac14p0, -0x1.989606p-1, -0x1.a6f324p-3, 0x1.e179d8p0, 0x1.030e9p0, -0x1.3d28a4p-3, 0x1.12d626p-2, 0x1.8e52ecp-2, -0x1.367378p0, 0x1.301096p0, -0x1.ab0866p-2, -0x1.063a68p0, -0x1.01488p0, 0x1.fb9026p0, 0x1.ef292p0, -0x1.8ffee2p-2, -0x1.2f455p0, -0x1.a1eadp0, 0x1.0ba7e8p0, 0x1.20c392p0, 0x1.6f73dep-1, -0x1.f1795p-4, 0x1.9701ep-4, 0x1.d5903p0, -0x1.5ea3d4p0, -0x1.578e54p0, -0x1.fb3ab8p-1, 0x1.ceaf4cp0, 0x1.2efd86p-7, 0x1.61625cp0, 0x1.a366e2p0, -0x1.c77f5ep0, 0x1.127044p-5, 0x1.7bccbep-1, -0x1.da02dep0, 0x1.6ad5c2p-1, 0x1.b27ea4p-1, 0x1.7c3582p0, -0x1.704944p0, -0x1.49e066p0, 0x1.826b04p0, -0x1.3f29p-1, 0x1.bf24a6p-2, 0x1.5e27aap0, 0x1.36ab3p-3, 0x1.6a66f6p-1, -0x1.f446b8p-2, -0x1.267372p0, 0x1.27716cp-1, -0x1.42d664p0, -0x1.df10fep-1, 0x1.21b0bap-1, 0x1.7ac952p0, 0x1.26b8d8p-4, -0x1.3f90b8p-3, -0x1.e430c6p0, -0x1.501364p0, 0x1.a04ce4p-1, 0x1.ef6d7ep-1, 0x1.5f9f44p0, 0x1.a24522p0, -0x1.c6e634p0, 0x1.aae6d4p-2, -0x1.176e9ap-3, -0x1.809cc8p-1, -0x1.96f3b8p0, -0x1.7271b2p0, -0x1.be037ap-1, -0x1.ee0748p-4, 0x1.c00974p0, -0x1.476adcp0, -0x1.6a3e3cp0, -0x1.be685ep-4, -0x1.5ec81p-2, 0x1.8137e8p-1, 0x1.5bd91ap0, -0x1.b087aep-3, -0x1.1fc9dcp0, 0x1.ee6254p-2, 0x1.84936ep0, -0x1.4230dep-1, -0x1.975d22p0, -0x1.179d02p-3, -0x1.4f506p0, -0x1.47eb4ep-2, 0x1.59acdep0, 0x1.75726cp0, -0x1.04b588p0, 0x1.23ef5p0, 0x1.a505ap0, -0x1.ee5f16p0, -0x1.675958p0, -0x1.3bcf76p-1, 0x1.e24f56p0, -0x1.f1a07cp0, 0x1.cb026p0, 0x1.af4dfap-2, -0x1.1f035cp-1, 0x1.0920f2p0, 0x1.b2055ep-1, 0x1.a169dcp0, 0x1.434392p0, 0x1.356ac6p0, -0x1.266ee6p-1, 0x1.cfb8ep-1, -0x1.5b4a5p0, 0x1.bdca3ep0, -0x1.d6c522p0, 0x1.e876bap0, -0x1.650eaep0, 0x1.9d91bep-1, 0x1.7c1854p-3, -0x1.1b0528p-4, 0x1.9fa1d6p-2, -0x1.501dcep0, 0x1.da3438p0, -0x1.ad846cp0, -0x1.b1635p0, 0x1.279922p-1, -0x1.af1a5ap0, -0x1.b19c5ep0, 0x1.0b2566p-1, 0x1.7f4d9p0, -0x1.eb2122p0, -0x1.281506p0, 0x1.d326cep-3, -0x1.bc0054p-1, -0x1.a9d6fep0, -0x1.0d6172p-1, 0x1.2ea86p0, 0x1.35e4a2p-1, 0x1.8c4232p0, 0x1.5a08b4p-2, -0x1.dc1ad4p-1, 0x1.c09532p-1, -0x1.5a2196p0, 0x1.a85bdp0, 0x1.42b3eap-3, -0x1.0a39fep0, -0x1.3991cep-1, -0x1.3ba7d8p-2, -0x1.e18bf4p-2, -0x1.3b2e9ep0, -0x1.f5aeeap-3, -0x1.ce4124p0, -0x1.a00f78p0, 0x1.071a9ap0, -0x1.cc0d8p0, 0x1.379bdep0, -0x1.1c73e6p0, 0x1.2b645p0, -0x1.67fc5ep0, -0x1.223a8ap-2, 0x1.84ac72p0, 0x1.868142p-2, -0x1.a40622p-1, -0x1.eca2c6p-1, 0x1.5efbf6p-1, -0x1.f95d1p0, -0x1.bfdaa8p-7, 0x1.379172p-1, -0x1.708d6ep-1, 0x1.b34b08p-1, -0x1.3b6ebep-1, -0x1.e4e9fcp0, -0x1.ea9bd2p-3, -0x1.5aab2ep0, 0x1.229204p0, 0x1.c6c862p-4, 0x1.804ef8p-1, 0x1.ef18eep0, 0x1.9b6ddp-3, -0x1.ed9204p-3, 0x1.244d96p-3, -0x1.0d7e5p-1, 0x1.d034bcp-5, 0x1.3deb9ap-2, -0x1.72c67ep0, 0x1.94c37ap-1, 0x1.0ba91cp0, 0x1.a7b0d8p0, 0x1.07223ep-1, -0x1.65578ep0, -0x1.954d6ap0, 0x1.bc759ep-4, 0x1.14eea6p-1, -0x1.718918p-3, -0x1.cba152p-4, 0x1.9a9888p-1, -0x1.d8892p-1, 0x1.737302p0, 0x1.1a03fp0, 0x1.a9d142p-1, -0x1.1e9566p-2, -0x1.56b17cp0, -0x1.6107cp-1, 0x1.a37392p0, 0x1.709986p0, -0x1.f138c6p-1, 0x1.00d606p-1, 0x1.1d9f8cp0, -0x1.3653b6p0, -0x1.70382ep-1, -0x1.726daap0, -0x1.34bec8p-2, -0x1.27a914p-3, -0x1.e185e8p-1, -0x1.4268a6p-1, -0x1.50ea28p0, -0x1.79bec4p-3, 0x1.49d678p-1, -0x1.5a36d2p-1, 0x1.c9f632p-1, 0x1.3a4ec6p0, 0x1.b1ff88p0, 0x1.e1ce7ap0, 0x1.054158p0, 0x1.40289ep0, -0x1.7aea1ap-2, 0x1.656e48p0, 0x1.30aaccp-1, 0x1.09964ap-2, -0x1.30524ap0, 0x1.7af9d2p-2, -0x1.385dbcp0, 0x1.f0541p0, -0x1.b466c4p-2, -0x1.fcb7fp-4, -0x1.270c7ep0, 0x1.2744bap0, -0x1.a61cd2p-1, -0x1.50d3c6p-3, 0x1.cc4648p0, -0x1.074e38p0, 0x1.b27b46p0, 0x1.919a76p0, -0x1.d4b8e8p-1, 0x1.692a9cp0, 0x1.ea3d42p0, 0x1.0486fap-2, 0x1.f52d52p0, -0x1.f7d5d4p-1, -0x1.8ce556p-1, -0x1.63e86cp-1, -0x1.9b4ebep-1, -0x1.b82e9ap0, 0x1.275b68p-2, 0x1.b40388p0, 0x1.5c7e0ap-4, 0x1.7dc496p-2, -0x1.e3f836p-1, -0x1.d43108p-1, 0x1.ff49b2p-1, -0x1.a6c8e4p-1, 0x1.59f604p0, -0x1.6148eep-5, 0x1.5361a6p0, 0x1.b885fp-1, 0x1.9ed3e8p-2, 0x1.6ef5ccp0, -0x1.fe715cp0, 0x1.941ffep0, -0x1.48bb2cp-2, -0x1.775a78p0, 0x1.d6901ap0, -0x1.a77cc6p-3, 0x1.c17648p-1, 0x1.190138p-3, -0x1.97c8dp0, -0x1.aab7bcp-1, -0x1.b48edep0, -0x1.cde73ep-3, -0x1.3db0dep-3, -0x1.8bc2d6p-1, 0x1.8fac2ep0, 0x1.79becep0, -0x1.479132p-2, -0x1.a69de2p0, 0x1.36df16p-3, 0x1.a89364p0, 0x1.e343a8p0, -0x1.8996a4p0, -0x1.f2fe32p0, 0x1.e5dfp-2, 0x1.bc6b28p0, -0x1.111fb2p0, 0x1.a13ab2p-1, -0x1.fe3b7ap-3, 0x1.f09b68p-2, -0x1.2e2c4ep-1, 0x1.6f6a76p-3, -0x1.5b0bd2p-1, -0x1.bb66ap-1, 0x1.9ce01cp-1, 0x1.31cab6p-6, 0x1.e7750cp-1, -0x1.03aaa2p0, 0x1.59a508p0, -0x1.78bf86p0, 0x1.028548p0, 0x1.47d206p0, 0x1.443032p-2, -0x1.796a0cp-2, 0x1.0306acp-2, -0x1.710e2p-3, -0x1.05c772p0, 0x1.d24c2cp0, 0x1.b683eap0, 0x1.8d5554p0, -0x1.31365ep0, -0x1.dc060ep0, 0x1.9fd1f4p0, 0x1.18594ap0, 0x1.34d96p-3, -0x1.ad1ap-1, -0x1.73c17p-2, -0x1.fbceb8p-2, 0x1.84680cp0, -0x1.5d4398p-4, -0x1.bbcd4p0, -0x1.733756p0, 0x1.ffe56ep0, 0x1.73fe06p0, -0x1.efaecap0, 0x1.9f5224p-1, -0x1.e3f0f2p0, -0x1.5de222p0, 0x1.5c801p0, 0x1.f6f064p0, 0x1.116a6ep-2, 0x1.5f59e4p0, 0x1.83a40ep-5, 0x1.5b8c1cp0, 0x1.a56d88p-1, -0x1.1c0a5ap0, -0x1.e90976p-1, -0x1.5d2df2p0, -0x1.bce484p-1, 0x1.775fd4p0, -0x1.d41f42p0, -0x1.7c1f1ep0, 0x1.0509fep-2, -0x1.3c1446p-1, 0x1.5e3ddep-3, -0x1.835108p0, 0x1.a0f36ap0, 0x1.83b928p0, 0x1.ad2108p0, 0x1.9f1406p0, 0x1.5db8dep-2, 0x1.d3771cp-3, -0x1.bf51dp0, 0x1.c8a7f4p0, -0x1.b5b0a8p-1, -0x1.cb447p-3, -0x1.ee4ce2p0, 0x1.9aa832p0, 0x1.c386b2p-1, -0x1.3e6b82p-3, 0x1.cad95cp0, -0x1.6ae81ep0, 0x1.d1126cp-3, 0x1.f50658p-2, 0x1.414abep0, -0x1.16f6fp-2, -0x1.bf1a0ep-4, -0x1.a4777p0, 0x1.60fb46p0, 0x1.f5f886p0, 0x1.dfea7cp-3, 0x1.a9b7b6p0, -0x1.e0fdc6p0, -0x1.796844p0, -0x1.e5edb4p0, -0x1.1ae89ap-1, -0x1.40efecp0, -0x1.975924p-1, -0x1.00c60ap0, -0x1.2a52ap0, 0x1.a95d6ep0, -0x1.f4a76ap-2, 0x1.9f9aaep-3, 0x1.3c55ap-3, -0x1.4adc4ap0, 0x1.ba7b9ap0, -0x1.17152p0, 0x1.f645ccp-1, -0x1.fec6f6p0, 0x1.28f7eap-2, 0x1.6f6e22p0, -0x1.e0221ap-2, -0x1.6fcb6cp-5, 0x1.a5a96p-2, 0x1.481382p0, 0x1.c68062p0, -0x1.abfcap0, 0x1.8c2c18p-1, -0x1.c4ef34p0, 0x1.115088p-3, -0x1.42cb94p-4, -0x1.cd442cp0, 0x1.907952p0, -0x1.be938cp-1, -0x1.5cb014p-1, -0x1.158086p0, 0x1.d249cap0, 0x1.aaefb2p-2, 0x1.2c42a8p0, -0x1.489ba2p0, 0x1.5fb2d4p-1, -0x1.9606c2p0, -0x1.11ddb8p-3, -0x1.00a68ap0, -0x1.0a2236p0, 0x1.b135ecp-5, 0x1.a2db3ap0, -0x1.fbb912p0, 0x1.84f49ap-2, 0x1.d292dep0, 0x1.b0bc72p-2, -0x1.6d3efap0, -0x1.bb262p0, -0x1.5a3142p0, -0x1.8197eap0, 0x1.00e792p0, -0x1.293546p-1, 0x1.1bd9fep-1, -0x1.2ca9bep0, -0x1.a8d466p0, -0x1.240584p0, -0x1.f32ca2p-1, 0x1.ccbbbcp0, 0x1.7ba4a2p-1, 0x1.d9a7dcp-2, -0x1.0b7b6ep0, 0x1.7f7d7p0, -0x1.575ebp-7, 0x1.de1feap-1, -0x1.53eddcp-2, -0x1.45ab06p-1, -0x1.41c15cp-3, -0x1.3ec552p-2, -0x1.db35c8p-1, 0x1.0c64bap0, -0x1.fa2e4ep0, -0x1.846e72p-2, 0x1.9e0beap-2, -0x1.3a4c84p-1, 0x1.f84e1cp0, 0x1.421394p-5, 0x1.4311e8p0, 0x1.c75c82p-1, 0x1.e4f7cap0, 0x1.bcd93ep0, -0x1.c1e94ep-2, 0x1.06a886p0, 0x1.0da802p0, -0x1.083d2ap-2, -0x1.7bcccep-1, 0x1.685bf4p0, 0x1.11dc12p0, 0x1.bc99b2p-3, 0x1.4b838cp0, -0x1.3afa62p0, -0x1.02c414p0, 0x1.e35a3ep0, -0x1.453734p0, -0x1.6c804ep0, 0x1.0e1faap0, -0x1.3fe84cp0, -0x1.4e44fap0, 0x1.2ff4acp-3, 0x1.338574p-2, -0x1.8b5f0ep-1, -0x1.7d9612p0, -0x1.9b198p0, 0x1.f157cp0, 0x1.6fd908p0, -0x1.2305dep0, 0x1.5bfd2ap-1, 0x1.aef10cp-1, 0x1.45e866p-3, -0x1.6946b6p0, 0x1.be2b0ap0, -0x1.68e6d2p-1, 0x1.c6b7c6p-1, -0x1.10ae1ep0, 0x1.b332bep-1, 0x1.571084p0, 0x1.88e4a4p0, 0x1.94c2eep0, 0x1.cd70f2p-1, 0x1.5008d2p0, 0x1.b6c2dap0, 0x1.ddeff6p-1, -0x1.ba96fep0, -0x1.971fcap-5, -0x1.15bd88p-2, 0x1.5d930ep-3, -0x1.e6c68p-3, 0x1.bdf35cp0, 0x1.7f3434p-2, -0x1.71827cp0, -0x1.4ec098p0, 0x1.7a959ep-4, -0x1.8ae532p-2, 0x1.b7d6f2p-1, -0x1.de2614p0, 0x1.56871cp-3, 0x1.6f272ap0, -0x1.8ec1d6p-1, -0x1.6e5914p0, 0x1.1f1fc8p0, 0x1.c67686p0, 0x1.4f225ep0, -0x1.c77832p0, -0x1.92f4bep-2, -0x1.ae219p-2, -0x1.e14b02p-5, 0x1.34a6fap0, -0x1.73bb4p0, 0x1.b0e9c2p-1, -0x1.b6b0d2p0, -0x1.23455p-1, 0x1.636d2ap0, -0x1.3291c6p-3, 0x1.31783p0, 0x1.5b25dp-1, 0x1.c5603cp-1, 0x1.43c2fep-2, 0x1.a79936p-5, -0x1.3bc6a4p0, -0x1.e3b724p-2, 0x1.36ad7ap0, -0x1.fc8316p0, -0x1.faffccp0, 0x1.8c644ap0, 0x1.05288p0, -0x1.6f8f6cp-2, 0x1.4160fap-2, -0x1.d089fap0, -0x1.65e31cp0, -0x1.ed5376p0, -0x1.f6af74p0, -0x1.eabcaep-1, -0x1.29ba8p-1, -0x1.1feda6p0, 0x1.0a8086p-2, -0x1.db279cp0, -0x1.4b13e4p-1, 0x1.eaf6aap0, -0x1.f930f6p0, 0x1.8dbc5ep0, 0x1.0d067p0, 0x1.afad9ap0, -0x1.59be92p0, -0x1.258de2p-1, 0x1.46dd14p-6, -0x1.373a5cp-4, 0x1.1b73b6p0, 0x1.78a99ap0, 0x1.0d298p0, -0x1.caca56p-1, 0x1.7c12d6p0, -0x1.cd9b0cp0, -0x1.e10302p0, 0x1.5b9ab4p0, -0x1.581d38p0, -0x1.f02b84p-4, -0x1.90dea8p0, 0x1.bc5d94p0, -0x1.66366ap-1, -0x1.04a5d8p-2, -0x1.c38ea4p0, 0x1.910b1ep0, 0x1.ff49dep-1, -0x1.86d3fp0, 0x1.763cdcp-1, -0x1.24f2fcp-4, -0x1.9452fcp0, 0x1.6e352p-2, 0x1.62f346p0, 0x1.b537bap-6, -0x1.d7e2dp-1, -0x1.0d68bcp0, -0x1.69992p0, 0x1.e21ea4p-1, -0x1.21af1p0, -0x1.ef4decp0, 0x1.a38f9cp0, -0x1.b39f92p0, 0x1.9c677p-1, -0x1.f2a608p-1, 0x1.f492c2p0, 0x1.51f56cp0, 0x1.c98b58p0, 0x1.a02b5ap0, -0x1.3acc54p-5, -0x1.330b4ap-4, -0x1.c00ffcp0, 0x1.60b80ap0, -0x1.225eecp-1, 0x1.eec928p-3, 0x1.9eadbcp-2, 0x1.c3fa16p-2, -0x1.56a5d4p-2, 0x1.bcf544p0, 0x1.9c4fbap-2, -0x1.3cf4fep0, -0x1.2ad42ep-4, 0x1.38aaaap0, 0x1.111b3cp-1, 0x1.6a06fcp-1, -0x1.e7b812p0, 0x1.a5a706p-3, -0x1.475164p0, -0x1.f736bcp0, 0x1.7a7bbap-1, -0x1.13f156p-2, -0x1.70d3aep0, -0x1.4749b6p-3, 0x1.89d65p-1, -0x1.d77e9p0, 0x1.170b24p0, -0x1.fc077ep0, -0x1.db101ep0, -0x1.b3c93p-1, -0x1.bc94a6p-3, -0x1.f8b5e8p-1, -0x1.2189ap0, -0x1.62c81ep0, -0x1.f46588p-3, 0x1.fcf61ap-3, 0x1.dd536ap-2, 0x1.d9d1ap0, 0x1.e5a864p0, -0x1.677606p-1, 0x1.7f924cp-2, 0x1.da16f4p-3, -0x1.53e534p0, 0x1.a354d4p-1, -0x1.be6008p-3, 0x1.80b6ep0, 0x1.841a64p0, 0x1.45c4e4p-1, -0x1.223c58p-3, 0x1.1f1ef2p-1, 0x1.3e5234p-2, -0x1.f46a36p0, 0x1.5e9c9cp0, 0x1.742d6cp0, -0x1.bafa72p-6, 0x1.f524dp-2, -0x1.f3fca6p-1, -0x1.3ea6acp0, 0x1.b35b88p-2, 0x1.df6966p-2, 0x1.b63a2ep0, -0x1.31931cp0, -0x1.9d7db2p0, -0x1.76bbf8p-2, 0x1.62ebdap0, -0x1.fc88dap0, 0x1.015d7p-2, -0x1.fe971ap0, 0x1.29d4e8p-1, 0x1.7fc522p0, -0x1.e39778p0, -0x1.88e3e2p0, 0x1.afa326p-3, 0x1.acddb4p0, -0x1.0f2914p0, -0x1.9f6978p-1, -0x1.51401ep-2, 0x1.017b5p-3, 0x1.181442p-1, -0x1.e8cd42p0, -0x1.39a09ap0, -0x1.18f55cp-1, -0x1.773b92p-2, 0x1.f4a3c4p0, 0x1.29cbaep-2, 0x1.63fad2p-1, -0x1.435c64p0, 0x1.560676p0, -0x1.aff502p-2, -0x1.670c22p-1, -0x1.fec41ap-2, -0x1.cb7d1p0, -0x1.a7312cp0, -0x1.e2e78ep-1, -0x1.5eaf18p-1, -0x1.a58454p-1, -0x1.ac638p-3, -0x1.c29a66p-1, -0x1.c14cecp0, -0x1.cb7c1ep0, -0x1.03a964p0, 0x1.0f732ep-1, 0x1.ad2b86p-1, -0x1.ec9914p-2, 0x1.221b3ep0, 0x1.88d80cp-3, 0x1.3a3886p-2, 0x1.8f8fb4p0, -0x1.180512p-1, 0x1.698c56p0, -0x1.9e8fb8p0, -0x1.07762ep0, 0x1.54b77cp0, 0x1.9a53ap-1, 0x1.ca17d6p0, 0x1.477ae8p0, -0x1.573c3p0, 0x1.4658c8p0, -0x1.165d8ep-1, -0x1.ba5726p-4, 0x1.f254b2p-1, -0x1.88b4ecp0, 0x1.b2e178p0, 0x1.52ccbap-2, 0x1.3c42e6p0, -0x1.684622p0, 0x1.7d35b4p0, -0x1.af12a8p0, 0x1.14c748p-1, -0x1.d77f16p-2, -0x1.6e8864p0, -0x1.f37032p0, 0x1.f268bep0, -0x1.586928p-5, -0x1.a7129cp0, -0x1.62b036p-1, -0x1.1da57p0, -0x1.f0fdfp0, -0x1.380968p0, 0x1.358636p0, -0x1.767c62p0, 0x1.d4650ap0, 0x1.d7820ap-1, -0x1.b937b2p0, -0x1.8ac2c6p-1, -0x1.fa40f8p-1, -0x1.f405dap-1, -0x1.67d4fap0, 0x1.4b1704p0, -0x1.26053p0, -0x1.1e83e8p0, -0x1.e931e8p0, -0x1.c0d924p0, 0x1.8214f8p0, 0x1.a15f18p-1, -0x1.65ed14p0, -0x1.8252dep0, -0x1.cfa06p0, 0x1.e00afcp0, -0x1.e13c6cp-7, 0x1.e4855p-2, 0x1.7f1b18p0, 0x1.9c4a4ep0, -0x1.ad7764p-9, 0x1.93038ap0, 0x1.0938e4p-1, 0x1.9dca9cp-2, -0x1.62230ep-1, 0x1.1badb6p0, 0x1.f3f7dp-1, -0x1.bd221p-1, -0x1.626c68p0, 0x1.892facp0, 0x1.34bdbep-1, -0x1.5112cep0, -0x1.5a0c5p0, 0x1.e415f6p-1, -0x1.f2069ap0, 0x1.a082aap0, 0x1.ad5cp0, 0x1.572dd8p0, 0x1.322986p0, -0x1.40d544p-1, -0x1.4d14bcp-1, -0x1.427ec4p-1, -0x1.c7113cp-1, 0x1.47e75ep-3, 0x1.61de3p-1, -0x1.b82fd8p-1, 0x1.1aa50cp-1, 0x1.145a34p0, -0x1.95fcfp0, -0x1.7504bcp-1, -0x1.fe202p-1, -0x1.d3300cp0, -0x1.36e4cap0, -0x1.21a5e2p-3, -0x1.a3cd1ap0, 0x1.6df548p-3, -0x1.0fb722p-2, -0x1.d512bp0, 0x1.fcb72cp0, -0x1.acd5fcp0, -0x1.41658cp0, 0x1.f61a1ep0, 0x1.53dbaep0, 0x1.797592p0, -0x1.983274p0, -0x1.6a604cp-2, 0x1.11691ap0, 0x1.e8c4eep0, 0x1.9cbf74p-1, 0x1.3b3e72p-1, 0x1.27287cp0, -0x1.062de2p0, 0x1.b589b2p0, -0x1.538b48p-2, 0x1.6eab5cp-4, 0x1.ff2feap0, -0x1.923774p0, -0x1.d19098p-4, 0x1.ea0632p-3, -0x1.15eb86p-1, 0x1.e849d4p-1, -0x1.016784p0, -0x1.f89cd8p0, -0x1.4759f4p-1, -0x1.e16454p0, 0x1.a10876p-2, -0x1.1ee708p0, -0x1.81767ap-1, 0x1.e01f2ap-1, -0x1.d3026ep-4, -0x1.f72192p0, 0x1.e83998p0, -0x1.e92024p-1, -0x1.d36d82p-1, -0x1.335a16p-2, 0x1.cd5678p0, -0x1.1f4166p-1, -0x1.84ab38p0, 0x1.cca556p-2, 0x1.735026p-1, 0x1.c1e75ap0, -0x1.9ea9c6p0, 0x1.8d5efep0, 0x1.5f3cbp0, -0x1.7633f8p-1, 0x1.54882ap0, -0x1.e63898p-3, 0x1.8c4cf2p0, -0x1.7bc57cp0, -0x1.1f9b48p0, 0x1.fc22p-1, 0x1.cbd5c6p-1, -0x1.9c7a98p-1, -0x1.4d4e86p0, 0x1.061f2cp-3, -0x1.08c088p-1, 0x1.0e51bcp-1, -0x1.eb89ecp0, 0x1.acd746p0, 0x1.611254p0, 0x1.0cadfp-2, -0x1.c8a9ep-1, -0x1.981b62p-3, -0x1.db3426p-2, -0x1.7fbbfp-4, 0x1.c1a14ep-1, 0x1.a0bdcap-3, -0x1.ed6a12p0, -0x1.9149eep-2, -0x1.0f626ep-1, -0x1.279d74p-4, 0x1.c3c1cap-1, 0x1.010ba8p0, -0x1.3eedc2p0, 0x1.fcf772p0, 0x1.6349e4p-2, -0x1.1af81ap-3, 0x1.dceefap-4, -0x1.720b4cp-2, 0x1.56e6ep-1, 0x1.8e66f8p0, 0x1.a74f9cp-4, 0x1.7cf4e6p0, -0x1.523eecp0, 0x1.b40d0ap-1, -0x1.6b760cp0, -0x1.1aa2f2p0, 0x1.ad9e8cp0, 0x1.4df78ep0, 0x1.ac5542p0, -0x1.a3ad08p0, 0x1.7a3a96p0, 0x1.0d7d8cp-2, -0x1.1b1878p-3, -0x1.0b3198p0, 0x1.a9fceap0, 0x1.a04486p0, -0x1.05d0a2p0, 0x1.d0ddc4p-1, -0x1.6850aap-1, -0x1.80fb76p-2, 0x1.11669cp0, -0x1.27aff4p0, -0x1.4d66dp0, -0x1.15e0f8p0, 0x1.4a2fcp-1, -0x1.5bea72p0, 0x1.c3ab3cp0, -0x1.fdf514p-1, -0x1.51ee58p0, -0x1.b63cd8p-1, 0x1.23e9c8p0, -0x1.9da456p0, -0x1.fdd0fap-3, -0x1.6a9de6p0, -0x1.3f04fep-2, 0x1.4252aap-3, 0x1.66d23p0, 0x1.fc582cp-1, 0x1.090a68p0, 0x1.2a1728p0, 0x1.75141ap-1, 0x1.217b9p-2, -0x1.cf352p-1, -0x1.49dcap-1, 0x1.99fc98p0, -0x1.d7a362p-1, 0x1.74c6acp0, 0x1.f5dcd8p-1, 0x1.634d3ep0, 0x1.e40952p-1, 0x1.6b2b22p-1, -0x1.86d524p-1, 0x1.5228bp-1, 0x1.d4dadep0, 0x1.8180aep-1, 0x1.9cbda8p0, -0x1.58a82ap0, 0x1.7e4e8cp-1, -0x1.28558ep-1, -0x1.cb1aaap-1, -0x1.fa423ep0, -0x1.4f290cp0, 0x1.c85528p0, -0x1.679056p-1, -0x1.46d85ap-1, -0x1.719eap-1, -0x1.eeb524p0, 0x1.4e3154p0, 0x1.0f6ca4p-2, -0x1.71ca6cp-2, -0x1.029d92p0, 0x1.9e47b6p-5, 0x1.0a358ap0, -0x1.228d22p0, 0x1.ff1036p-2, 0x1.405d02p0, 0x1.d1695ap-2, 0x1.7d168ap-1, 0x1.158a76p-2, 0x1.344556p-2, 0x1.6a7f14p0, -0x1.40cb6ap0, 0x1.851d78p0, -0x1.e95f94p0, 0x1.ee2e5p-1, 0x1.b91f9ap-1, 0x1.00d478p0, 0x1.e6758cp-3, -0x1.979b06p0, -0x1.edc132p-1, 0x1.d371b6p0, -0x1.72db6p-1, -0x1.0cebe8p0, 0x1.137266p-3, -0x1.39dd7ep0, -0x1.bc973p-1, 0x1.94750ap-2, 0x1.86a61cp0, 0x1.656186p-2, 0x1.478642p0, -0x1.7e96fep0, -0x1.dcacbp0, 0x1.367c9ap0, -0x1.c3cbb8p0, 0x1.9eaa6ap-1, 0x1.d770a4p0, -0x1.30ef7p0, 0x1.2d51dap-2, -0x1.6e7d2ep0, -0x1.27f42cp0, 0x1.0ab5f8p0, 0x1.054bfcp-1, 0x1.ac987cp-3, 0x1.e8af14p-1, 0x1.1dfb86p-5, -0x1.b14f56p0, 0x1.201646p0, -0x1.36288ap0, 0x1.d4bb8cp-1, -0x1.f5dfa4p0, 0x1.53a9dap0, -0x1.7dd898p0, -0x1.2de63ep-1, -0x1.c940e8p-2, 0x1.a49016p0, -0x1.a811e6p-2, 0x1.6adb4p-2, -0x1.048dbep0, 0x1.db3f7p0, -0x1.5852dap-2, 0x1.1c381cp0, 0x1.75c43ep-1, -0x1.d13f26p0, 0x1.ebb5f8p-2, -0x1.74386cp-1, 0x1.4252fcp0, 0x1.78ce7cp0, 0x1.3697ccp-3, -0x1.46ce1ep0, -0x1.0ec334p-1, 0x1.3a74a4p0, 0x1.ce1b78p-3, 0x1.2c9c5ap0, -0x1.877decp0, 0x1.7767b8p-1, 0x1.805246p-1, -0x1.c0971ap0, -0x1.8bbe1p0, 0x1.cc115p-3, -0x1.68e83cp-1, 0x1.14fc48p0, -0x1.16d2a4p-1, -0x1.2b83c8p-5, 0x1.42c3cp0, -0x1.74df5ep-1, -0x1.58d51p0, -0x1.291738p0, 0x1.ae303p0, -0x1.137076p-2, 0x1.926b6ap-2, -0x1.9ba85p0, 0x1.3a9104p0, -0x1.6ba00ep0, -0x1.952318p0, 0x1.0d633p0, -0x1.36889ep0, 0x1.26b3e6p-4, -0x1.aeb6b8p0, 0x1.6cb6aep-2, -0x1.6ed0d8p-2, -0x1.cc17eap0, -0x1.beb792p0, 0x1.12ce2cp-1, -0x1.613ae6p0, 0x1.d18a6ep0, -0x1.84902cp-6, 0x1.7e6cd2p-3, -0x1.a88f6ap-1, 0x1.745c08p0, 0x1.263c7p-1, 0x1.f2e1ep0, -0x1.df7bccp0, -0x1.d47868p0, -0x1.4141dp0, 0x1.741472p0, 0x1.e09b8ep-3, 0x1.238b5cp0, -0x1.c77bf8p-1, 0x1.f2160ep-1, 0x1.a862f8p0, 0x1.d9b65p0, 0x1.183b08p0, -0x1.ffc0d6p-1, 0x1.684a3p0, -0x1.9bf56ep-1, -0x1.4fd28ap-4, 0x1.e0c09cp-1, -0x1.1396bap0, -0x1.00301ap-2, 0x1.7fddeap-3, -0x1.263206p-2, 0x1.e61182p-1, -0x1.172f6cp-1, 0x1.88cc1ep0, -0x1.a6d69ep0, -0x1.27a9dap-3, -0x1.929dfcp-1, -0x1.dfead8p-5, -0x1.f1c62cp0, -0x1.5d26f6p-2, 0x1.e61c1cp-1, 0x1.e86278p-3, -0x1.6e0cc8p-2, 0x1.4dbfep0, 0x1.637b4ep0, -0x1.f5c96ep0, 0x1.bf78fep0, 0x1.40b514p0, 0x1.222814p0, -0x1.d33fdp0, 0x1.89e4d8p0, -0x1.fd95dcp-1, -0x1.f016a6p-1, 0x1.08ce96p0, -0x1.cb4f8ep0, -0x1.fe61d8p-1, -0x1.9476ccp0, 0x1.3ec06ep0, 0x1.8eafa6p-2, 0x1.8b8d5cp-1, -0x1.697dacp0, 0x1.99664ep0, 0x1.2bda5cp-1, 0x1.3b6fc4p0, 0x1.dbe3cap0, -0x1.e827f4p-1, 0x1.ee74c4p0, -0x1.31a946p-1, -0x1.5fe5dcp-1, 0x1.863686p-4, -0x1.862e66p0, 0x1.60245ep0, -0x1.33c284p-1, 0x1.66154ap-1, -0x1.2d8d8p-1, 0x1.50acfp0, 0x1.0d6252p-2, 0x1.a34192p-3, 0x1.cc2768p0, -0x1.5777b8p-1, -0x1.4476fep0, 0x1.a3a35cp0, 0x1.9e41fap0, -0x1.03518cp0, 0x1.f89cf6p-1, -0x1.f954fp0, -0x1.4f85d6p-1, -0x1.76eceap-2, 0x1.bca758p-1, -0x1.1cb5f6p0, 0x1.500cfap0, 0x1.2492dep0, 0x1.4f6c2ep-2, 0x1.dc434ap-3, -0x1.7ddcf2p-5, -0x1.2a4c16p0, -0x1.679844p0, 0x1.2108a8p-1, 0x1.e210ecp0, -0x1.33b7c4p-4, 0x1.2ea03ap0, 0x1.497f9ap0, -0x1.016d1ep-1, 0x1.0df5bep0, 0x1.909924p-1, 0x1.568a1p0, 0x1.118b8ap-2, -0x1.434cd6p0, -0x1.db472ep-2, 0x1.484c26p-1, 0x1.0a7e6ep-4, 0x1.145a3ep0, -0x1.28818cp-2, 0x1.7a3e22p0, 0x1.280064p0, -0x1.4cbbcp-1, -0x1.d0ee08p0, -0x1.c53d8p0, -0x1.db52fp0, -0x1.c64c04p-2, 0x1.fbcc8ap-1, -0x1.6aa7ep-1, 0x1.3301b6p0, 0x1.07aafp-2, -0x1.09d60ap-1, 0x1.47418p-1, 0x1.3d5bfp0, 0x1.5d79d4p0, 0x1.41125p-1, 0x1.569af2p-1, -0x1.62ac5p-2, -0x1.0211bp0, 0x1.a7bc38p0, 0x1.380d64p-2, 0x1.beb3eap-1, -0x1.7a0d6ap0, -0x1.213e6ep-1, 0x1.d58dd8p-7, -0x1.6391fp0, 0x1.26652ep-7, 0x1.7a92a6p0, 0x1.84f28p-1, -0x1.c77d2p-1, -0x1.ce455p0, -0x1.01c5e4p-2, -0x1.43b106p0, -0x1.5d3e54p-1, 0x1.d34bf8p-2, 0x1.9235acp0, 0x1.24f16cp0, 0x1.8472a4p-3, -0x1.29cb6ap0, 0x1.441deep-1, -0x1.1ddf2ep-1, 0x1.c7314ap0, 0x1.7e3ep0, 0x1.02feep0, -0x1.c7644cp-5, 0x1.a48c9cp-1, -0x1.016a7ap-2, -0x1.189676p-1, -0x1.d435f8p0, 0x1.39abd4p-1, -0x1.5241cep0, 0x1.28bc64p-1, 0x1.a08faep-2, -0x1.7be05cp-1, 0x1.331446p0, 0x1.5605p-1, 0x1.390e66p-1, -0x1.afa278p0, 0x1.26b3a4p0, 0x1.038e46p0, 0x1.0de228p-1, 0x1.c84ab4p0, -0x1.25d71ap0, 0x1.482862p0, 0x1.9588a4p-1, 0x1.a7b2a6p0, -0x1.61766cp-2, 0x1.e42ac2p0, -0x1.3f7deap0, 0x1.5fc7c2p0, -0x1.cdd5ecp-3, 0x1.66326p-1, 0x1.85b39ep0, -0x1.10373ep-1, 0x1.59ee5ap-3, 0x1.3de21p0, -0x1.fef048p-2, -0x1.9fdb9ap0, 0x1.fcca1ep-1, 0x1.893a6ep-1, -0x1.09b5c8p-5, -0x1.ea48e6p0, -0x1.acb3ep-1, -0x1.9469ccp0, -0x1.dd9f56p0, 0x1.971da6p0, 0x1.c12a2cp0, 0x1.827c8ep0, 0x1.6dcb62p0, -0x1.bfac82p0, -0x1.c14686p0, -0x1.8838dap0, -0x1.46db7p0, 0x1.46008ap-4, 0x1.0cae02p0, 0x1.613098p-2, 0x1.5c7942p0, -0x1.748004p0, -0x1.8bfecep-1, 0x1.24715ap-1, -0x1.6eaa24p-2, 0x1.1e1f3ep-1, 0x1.d7a7e8p0, 0x1.79a2d8p-1, -0x1.2d1d7ep0, -0x1.99bae8p0, -0x1.7e16fcp-4, 0x1.f1e1fap-5, -0x1.4a4d7p0, -0x1.1fccf2p0, -0x1.a67742p0, -0x1.f8fe94p-3, 0x1.37151p-1, 0x1.76bc14p0, -0x1.8e8c64p0, -0x1.6170eap-2, 0x1.8f3b64p-1, 0x1.ed56a2p0, 0x1.d627cp0, -0x1.b6bb76p0, 0x1.90811p0, -0x1.3b990ap0, -0x1.f0e556p-1, 0x1.ec5d3ap0, 0x1.feaa32p0, -0x1.848384p-1, 0x1.6cf062p-3, -0x1.4fe2b8p-2, 0x1.d6d37p0, -0x1.36a018p-2, -0x1.bbc6cep0, 0x1.fc51d4p-2, 0x1.e98e4ep-2, -0x1.a928dcp-1, 0x1.c8b6cep-2, -0x1.7756bap0, -0x1.eb9dc4p0, 0x1.052c36p-1, -0x1.39f0aap0, 0x1.5cf934p-1, 0x1.b3f7eep-2, 0x1.d4c70ap-3, 0x1.e57784p-1, 0x1.cfad66p0, -0x1.3ded58p-2, 0x1.29c7ep-1, -0x1.4f553cp0, 0x1.742992p-6, 0x1.44e602p-1, 0x1.2b0c7p-1, 0x1.bd1356p-5, -0x1.167c14p0, -0x1.b5a0ap0, -0x1.a8b344p-3, -0x1.bc80c4p0, 0x1.5a77dep0, -0x1.087ac6p0, -0x1.0485bep-1, 0x1.187434p0, -0x1.c0c64cp0, -0x1.0a7a8ap-3, -0x1.2071cp-1, 0x1.05c5dep0, -0x1.f36cfp-1, 0x1.8ae29ep0, 0x1.cf0ce4p-3, -0x1.fd0bc6p-3, -0x1.be53acp0, 0x1.31f89ep-3, 0x1.56b1eep-1, -0x1.86db04p-3, 0x1.5c9daep0, 0x1.5e29dcp-2, -0x1.632362p-1, -0x1.ef6af6p-2, 0x1.ef5986p0, 0x1.543fe6p-2, -0x1.3b44acp-1, 0x1.36c3a2p0, -0x1.788b42p0, -0x1.267f1cp0, -0x1.ea738cp0, -0x1.e122d4p-2, 0x1.4c2ceap-1, 0x1.a8651ap-3, -0x1.de3bb6p-3, -0x1.06a3dcp-2, 0x1.fb54f8p-1, -0x1.9c593ep-1, 0x1.5346ap0, 0x1.2e85ap-1, 0x1.0965fp-1, -0x1.37e584p-1, -0x1.b0a148p0, 0x1.57b24p0, 0x1.e39eccp0, 0x1.2ef83ep0, 0x1.1a0fcp0, 0x1.6430bep-1, -0x1.c228f2p0, -0x1.7ccc2ep-2, -0x1.48c312p-2, -0x1.ec00bcp0, 0x1.5f4878p0, -0x1.46b09p-1, -0x1.c9ce2ep-1, -0x1.a1f442p0, 0x1.bca738p-2, -0x1.fc4c2ep-5, 0x1.96793cp0, 0x1.d21d2p-4, 0x1.0493d6p-1, 0x1.12abe4p-1, 0x1.98899ep0, -0x1.1ea6f2p-2, 0x1.4ef9f8p-1, -0x1.e5dbf2p0, -0x1.3b8c52p-1, -0x1.71ef04p0, -0x1.bce0e4p-2, 0x1.10dcc4p-2, -0x1.a665c2p-1, -0x1.65e6fap-1, -0x1.a0b4dap0, -0x1.851f86p0, -0x1.7a91cap-1, 0x1.c4a91ap-1, 0x1.d00ebep0, -0x1.5e03ap0, 0x1.39be36p-1, 0x1.dc992ap0, 0x1.195a52p0, -0x1.902c6p0, 0x1.c7c132p0, -0x1.51f48cp0, 0x1.32b242p-1, -0x1.85d572p-1, -0x1.01c498p-3, -0x1.88905p-3, -0x1.10833ap-1, 0x1.276354p-1, -0x1.2f2d5p-2, 0x1.cbc85cp0, 0x1.6d8ce4p0, 0x1.48e4b2p-1, 0x1.7de8b8p-5, -0x1.b98516p-1, -0x1.f68bacp-1, -0x1.cb6ac8p0, 0x1.74b7b4p0, -0x1.68cf38p-2, 0x1.10e4fap0, 0x1.fac12ep0, -0x1.477a1ap0, -0x1.bca964p-3, 0x1.0f15eap-1, 0x1.3bb376p-6, 0x1.9361d2p-1, -0x1.13f12ep-1, -0x1.20a7b6p0, 0x1.45a1bap0, 0x1.55feeep-1, 0x1.e38ef2p-2, 0x1.eac038p-1, 0x1.66d8ecp0, 0x1.ed18b4p-2, 0x1.924f74p-1, 0x1.f9f586p-2, 0x1.1c67c2p0, 0x1.1189e8p-1, -0x1.a1a116p-4, -0x1.f81ce6p-1, -0x1.508b14p0, 0x1.494a8p-1, 0x1.2643c2p0, -0x1.939cccp0, -0x1.1e8274p0, -0x1.1a87f6p-1, 0x1.432ab6p-2, -0x1.6c6e1ep-6, 0x1.259e1ep-1, -0x1.115eecp0, 0x1.39cc64p-3, 0x1.c2c7aap-3, -0x1.19e1ecp-1, 0x1.4bb584p-1, -0x1.e8f846p-1, -0x1.fba12ep-1, 0x1.1e4c16p-2, -0x1.e34c8ep0, 0x1.f61208p-1, -0x1.18d1c2p0, 0x1.640196p0, 0x1.7c6acp-2, -0x1.d1836ep0, -0x1.d6a94ep0, 0x1.4f3968p-1, 0x1.6c9638p-3, -0x1.6d5e2ap0, -0x1.798918p-3, -0x1.868d08p0, 0x1.412316p0, 0x1.63df4ep-6, -0x1.6d72c2p-2, -0x1.c57b9ap-1, -0x1.5deda2p-2, 0x1.8fb6eep-4, 0x1.c88c2cp0, -0x1.901c3p-3, 0x1.3f65e4p-3, 0x1.e192aep-1, 0x1.8e8eaep0, -0x1.754e5cp-3, 0x1.1a6276p-2, 0x1.b5854ep0, -0x1.298198p-2, -0x1.de8c6p-2, 0x1.b57c5p-1, -0x1.eca09ap-1, 0x1.a1a29cp0, 0x1.2c8bb8p-4, -0x1.da78eap-2, -0x1.7373c6p0, -0x1.e52816p-2, -0x1.60f846p-2, -0x1.6a7f12p-1, -0x1.0ea2dcp-2, 0x1.7e8388p0, -0x1.234e64p-1, -0x1.85c56cp0, 0x1.81d10ap0, 0x1.f91bc4p0, -0x1.cd3404p-1, 0x1.ccb5c4p-1, -0x1.9bc42ap-3, 0x1.9b2a5p0, 0x1.ed1c86p-1, 0x1.e59e3ep0, 0x1.3264f4p-4, -0x1.99c626p-1, -0x1.ddcc74p0, -0x1.4fe436p-1, 0x1.47928ep-1, -0x1.6d4b28p-3, -0x1.81f656p-3, -0x1.de5d52p-1, -0x1.57ed84p-1, 0x1.878e84p0, 0x1.63e41cp-1, -0x1.7a8a64p-1, 0x1.6ea724p-1, 0x1.e781ccp0, -0x1.2ad8ap0, -0x1.117914p-1, -0x1.9ac596p-3, 0x1.9e2d5p0, -0x1.a92296p0, -0x1.a1bd6cp0, -0x1.8679cap0, -0x1.ccf8a4p0, -0x1.8c25c4p0, -0x1.305fa6p-1, -0x1.71591ap-1, 0x1.dfed66p-2, -0x1.899362p-1, 0x1.5c5b4ap-1, 0x1.ac40c4p-3, -0x1.db348ap0, -0x1.6e8c52p-11, -0x1.e9979ep0, 0x1.ab588ep-2, -0x1.ee20b6p0, -0x1.f7bd84p-1, -0x1.8a22b4p0, 0x1.12b3e8p-4, -0x1.fd9204p-2, -0x1.cb98bap0, 0x1.afd582p0, 0x1.c927f8p-1, 0x1.92acd2p-1, 0x1.a9dd9ap0, -0x1.e08d24p0, 0x1.9859fap0, -0x1.ca6284p0, -0x1.50f786p-1, 0x1.d3d2dap0, -0x1.97c99cp-1, 0x1.89a5c6p-1, -0x1.ac73c8p-1, 0x1.7d95bcp-1, 0x1.bf10a4p-1, -0x1.bdb3d8p0, 0x1.bc2fb2p-2, 0x1.291fdep-1, -0x1.e509e8p0, 0x1.e253dap-3, 0x1.97c62p-1, -0x1.5e0db4p-1, -0x1.23c506p-3, -0x1.2afbd2p-2, -0x1.07fbc8p0, -0x1.75391ep0, 0x1.305f08p-3, -0x1.32f85ap-2, 0x1.49e572p-1, 0x1.eaca94p0, 0x1.e3bf82p0, -0x1.59b45ep-1, -0x1.c0976cp0, 0x1.a529d4p0, 0x1.7ee376p-1, -0x1.1292e6p-1, 0x1.7cceaap-1, -0x1.ba813ap0, -0x1.d4c672p0, -0x1.39bd46p-4, -0x1.717c08p-2, -0x1.e5a686p-1, 0x1.806678p-1, -0x1.cc46eep0, 0x1.de2d2p-1, -0x1.895a7cp0, 0x1.45c53cp-1, -0x1.8ea43cp0, -0x1.36b372p0, -0x1.105d16p-1, -0x1.fe953p-1, -0x1.021986p0, 0x1.617deep0, 0x1.e11e12p0, -0x1.c7ecfcp-1, -0x1.4b0898p-4, -0x1.00fc52p0, -0x1.64ceaep0, 0x1.cba604p0, -0x1.1fc11cp0, 0x1.c25456p-1, 0x1.417404p0, 0x1.dcf88p0, 0x1.ed2f04p0, 0x1.75addp-4, 0x1.1c0a54p0, 0x1.61f79cp0, -0x1.295a84p-4, -0x1.921b56p-3, -0x1.f9815ep0, -0x1.16361ep0 };
float c_activation_3_test4_array[6];
float test5_dense_input_input_array[2622] = { 0x1.90a12p0, 0x1.c166cep-1, 0x1.e5b7eap0, -0x1.ed495cp-1, 0x1.7f828p0, 0x1.08ac64p0, 0x1.a99b28p0, 0x1.7aee28p0, 0x1.59e7fp-1, 0x1.9e55ccp0, -0x1.671c88p0, -0x1.acee16p0, -0x1.16e3e2p-3, -0x1.f368a6p-1, 0x1.fcee72p0, -0x1.86ae8ap-1, -0x1.07eb4ap-3, 0x1.cecb3ap-1, -0x1.e2c732p-1, -0x1.f9a35cp0, -0x1.cc28e6p-1, 0x1.dcd546p-1, 0x1.0411e8p-1, -0x1.e6bdc8p-4, -0x1.dc4dc6p-1, 0x1.5dc54cp0, -0x1.8bc552p-1, 0x1.c8f402p-1, 0x1.8de6acp-1, -0x1.a0da9ap-1, -0x1.4dbf18p0, 0x1.a2c398p0, 0x1.74df5ep-1, -0x1.feb672p0, 0x1.554f3ap-1, -0x1.5a99f8p0, -0x1.e3255cp0, -0x1.99e1b8p-5, -0x1.1f9d9ap0, -0x1.5f43b6p-1, -0x1.0fabb4p0, 0x1.c800ep0, 0x1.3705ep-5, 0x1.72c308p0, 0x1.879b56p0, -0x1.c7f7f8p0, -0x1.03f17p-4, 0x1.f3425cp0, 0x1.2a0ce2p-1, -0x1.16ae88p-3, 0x1.1ddd68p-6, 0x1.346dc4p-1, 0x1.c0a4ccp0, -0x1.577dc8p-4, -0x1.8613fep0, 0x1.f22022p0, -0x1.262e2ep-1, 0x1.1c68f6p-5, 0x1.61736p0, -0x1.847264p-1, 0x1.268ep-1, 0x1.b11cdep0, 0x1.caae22p0, 0x1.a2d638p-3, -0x1.700f7ap-1, -0x1.c591fp-3, 0x1.9794b2p-1, -0x1.6e0c32p-1, -0x1.6ba736p0, 0x1.0701c6p0, -0x1.a480bp-1, 0x1.e21b12p-1, 0x1.46faa4p-3, 0x1.bd1784p0, -0x1.a3cf32p-5, 0x1.cdb196p0, -0x1.1638c4p-1, -0x1.a2a4bp0, 0x1.5fcb8cp-1, -0x1.1ae0d4p0, 0x1.a04d84p-1, -0x1.730698p0, 0x1.8059f4p0, -0x1.21ef1ap0, 0x1.8d4b6cp0, -0x1.7fbde2p0, -0x1.b6afb4p-1, -0x1.edd67p0, -0x1.3fc006p0, -0x1.a58ed6p0, 0x1.977558p0, 0x1.46e626p0, 0x1.ec7d0cp-2, 0x1.e8a9p0, 0x1.7bc236p-1, 0x1.ff8338p0, 0x1.f575e2p-2, 0x1.1a9662p0, 0x1.7a80eep0, 0x1.da2bf8p-1, -0x1.c35666p-5, -0x1.4a6f5cp0, 0x1.b2951p0, -0x1.1e72a6p0, 0x1.3326ecp-1, -0x1.d834a4p0, 0x1.adeb06p0, -0x1.b4fabcp-1, -0x1.4e8abcp0, 0x1.b664a8p-1, -0x1.844c3p0, -0x1.9a85bap-1, 0x1.29e112p-2, 0x1.ef757ep-1, -0x1.61d982p0, -0x1.89e52p-2, -0x1.5949f6p-1, 0x1.d3fa1ep0, 0x1.3e5cbep0, 0x1.4d383ep-1, -0x1.96e634p-1, -0x1.c88706p-1, 0x1.ed351ap-1, -0x1.6d5fc6p0, -0x1.1e822cp0, -0x1.0c1988p0, -0x1.66ca4p0, -0x1.be1f14p0, 0x1.7e4964p0, 0x1.265122p-4, -0x1.1e56c8p-1, 0x1.8fe3b4p-1, -0x1.d5b622p-1, -0x1.04776p-1, -0x1.543598p0, -0x1.dc2af2p0, 0x1.d9936cp0, 0x1.1e453p0, 0x1.2deda4p-1, -0x1.c6bb16p-2, -0x1.0365fep-1, 0x1.1b5408p0, 0x1.6b25e4p0, 0x1.01dc1ep0, 0x1.34ec4cp0, -0x1.c71a8ep0, -0x1.48582ep-4, -0x1.09ccb6p-1, 0x1.ddb492p-1, 0x1.1af3a4p0, -0x1.9c7c44p0, 0x1.b39056p-4, -0x1.190152p-3, 0x1.39d3c6p0, 0x1.0280aap0, 0x1.a6d044p0, 0x1.43ab98p0, -0x1.fd82ccp0, -0x1.549048p-2, 0x1.1099f6p0, -0x1.8972ap0, -0x1.0dba12p0, -0x1.ddf958p-1, -0x1.4867b4p-3, -0x1.78104ap-2, -0x1.78683ap-7, -0x1.1de7bap-1, 0x1.61f19ap-1, -0x1.4d1f0ap0, -0x1.568702p0, 0x1.bd0c92p0, -0x1.61beb8p-1, 0x1.68b5c8p-2, -0x1.91c0ep-2, -0x1.a5091p0, -0x1.cd85ep-3, -0x1.132b44p-2, -0x1.e72d1ap-1, -0x1.1b1096p-1, -0x1.0db484p0, -0x1.855f74p0, 0x1.e89a4ep0, -0x1.3f3d48p-3, -0x1.e1adc6p-3, 0x1.00a6ccp0, -0x1.7ad3fp-1, 0x1.d048d8p-3, 0x1.3f71p0, 0x1.f74434p-1, 0x1.62384ep0, -0x1.7769cp0, -0x1.34e212p0, 0x1.cb6072p0, 0x1.932d7ap0, 0x1.fd5f84p0, 0x1.e017ap-1, -0x1.fa8592p0, -0x1.96f002p-2, -0x1.64290ap-1, 0x1.ceeff4p0, 0x1.e6c904p-2, -0x1.255562p-5, -0x1.3c4f88p-2, 0x1.1e2608p-2, -0x1.23eb38p0, 0x1.ab7aecp0, -0x1.ce9a42p0, 0x1.9cc2e2p-1, -0x1.ae8568p0, -0x1.c05c5ap0, 0x1.cb3dacp0, 0x1.f995bcp-3, 0x1.5d428ap-5, 0x1.53de6ap-1, -0x1.eb1218p-1, 0x1.2ff08cp0, -0x1.caf75cp0, 0x1.0c8e2p0, 0x1.dd1f02p-3, 0x1.771b18p-1, 0x1.c3978p0, 0x1.ee8e1ap-2, 0x1.cf2e4ep-4, -0x1.bdfee2p0, -0x1.6dcd8ep-1, 0x1.22f70ap0, -0x1.f26304p-2, -0x1.13afe2p-1, -0x1.5d4b38p-1, 0x1.2128ecp-3, 0x1.a220d6p0, 0x1.b73a04p-1, -0x1.3e2dd2p0, -0x1.d30e3p-1, -0x1.265b7ap-1, 0x1.79846ap-1, -0x1.0e3f8cp-2, -0x1.f21962p-3, -0x1.228d38p0, 0x1.7cfafp-1, -0x1.b24eap-1, -0x1.d073cp0, 0x1.b95324p-1, -0x1.59059ap-1, 0x1.4a0202p-5, 0x1.265a24p0, -0x1.d379fp-2, -0x1.0eb96p0, -0x1.5f88e4p-2, -0x1.d307e4p-2, -0x1.affb22p-5, 0x1.0fc842p-2, 0x1.2ae75ep-2, 0x1.9f51bap0, -0x1.f62c02p-1, 0x1.8b357ap-7, -0x1.960e2ap-3, 0x1.274cc6p0, 0x1.55b20ep0, -0x1.eec372p0, 0x1.0398d8p-2, -0x1.897b72p-1, -0x1.16ea0cp0, 0x1.881804p0, 0x1.74968ap-3, -0x1.25584cp0, -0x1.b8ba36p-2, 0x1.c4b228p0, -0x1.3725f6p0, -0x1.5c1098p-2, 0x1.bae6b8p0, -0x1.342406p-1, -0x1.93e174p-1, -0x1.0bf0c2p0, -0x1.f5fa64p0, -0x1.64833ep0, 0x1.21bfeap0, -0x1.890f6ap-1, -0x1.03c744p0, -0x1.730b04p-1, -0x1.bb0458p-1, 0x1.3854f6p0, -0x1.d2c308p-1, 0x1.873fcep-2, 0x1.ea857p-1, -0x1.b7bbfcp-1, -0x1.330862p-1, 0x1.3f4f14p0, -0x1.b26a1ep-1, 0x1.3adb76p0, -0x1.22bd4ep-2, -0x1.b2abcep-3, 0x1.fe525ep0, 0x1.33f382p0, 0x1.fbe9eep0, 0x1.8c45b2p-2, -0x1.45f3fep0, -0x1.224d46p-1, 0x1.d7733ep-1, -0x1.344118p-3, 0x1.6ec8f4p-1, 0x1.5b1dbcp0, 0x1.ad581ep0, -0x1.96fce4p0, 0x1.7dc638p0, 0x1.aabec2p-1, 0x1.ada716p-1, 0x1.0983e6p0, 0x1.4b68f8p-1, -0x1.13ee52p-1, -0x1.9faf1ep0, 0x1.4b276cp0, -0x1.8582cep-1, 0x1.c9986ap0, -0x1.717616p-3, -0x1.e9b338p0, -0x1.b6368ap0, 0x1.44d44ap0, -0x1.cac322p-1, -0x1.cdc0b6p-2, -0x1.08a96ap0, -0x1.f4aaaap0, 0x1.22056cp-1, -0x1.cb121cp0, 0x1.5347c8p0, -0x1.ea14dcp-4, -0x1.aa2cc8p0, -0x1.d44a32p0, -0x1.fdaef2p-4, 0x1.de351ap0, 0x1.fe0a3cp0, -0x1.c530bap0, -0x1.0de686p0, 0x1.17d1dp-3, -0x1.3929d8p-2, -0x1.7357b8p0, -0x1.90de54p0, -0x1.93c5ep-1, -0x1.af99fep-1, 0x1.91d85p-1, -0x1.480f1cp0, -0x1.65edcp0, -0x1.8da7c6p-1, -0x1.7116c2p-2, -0x1.fc9f18p-2, 0x1.4ff726p-2, 0x1.3408fp-1, -0x1.f13338p0, -0x1.75d658p0, 0x1.7bbe02p0, 0x1.8085c4p-1, -0x1.4fd664p0, 0x1.529b4cp0, 0x1.f2414cp0, 0x1.f0bdd4p0, -0x1.d5d358p0, -0x1.7c0d6ap-2, -0x1.b3722p-1, 0x1.b7129cp-1, -0x1.03f6bcp0, -0x1.cca88cp0, -0x1.6906dep-2, -0x1.b4f21ep-1, 0x1.be80f6p0, 0x1.08f57p-1, 0x1.90c668p-1, 0x1.904286p-1, 0x1.e2f968p-2, -0x1.d86d0ep0, 0x1.bc00d8p-2, -0x1.8c97d6p-1, 0x1.447f8cp0, -0x1.3ad78ep-2, 0x1.be0e24p-1, 0x1.4ba34cp0, 0x1.5124b8p0, -0x1.c390dep0, 0x1.8b9eap0, -0x1.5736dap0, 0x1.7da40cp0, -0x1.489c12p-2, -0x1.28689p0, -0x1.7bf092p0, -0x1.eef4ep0, -0x1.c81ae8p0, -0x1.c904eep-1, 0x1.384b2ep-1, -0x1.08f37p-2, -0x1.308122p0, -0x1.52d7dp0, -0x1.7af81ep-2, -0x1.88b8eap-1, -0x1.c3ffaep0, 0x1.0c73d6p0, 0x1.574d8cp0, 0x1.50232ap-1, -0x1.ad77f2p-2, 0x1.19dfaep-2, -0x1.4c3d4p-2, -0x1.c7f41ep-5, 0x1.daf2eap-3, 0x1.5d4e02p-2, 0x1.d50306p-2, 0x1.e5521ap0, -0x1.196d78p-1, -0x1.28ff22p-3, 0x1.65ff6ep-3, -0x1.84c68cp0, -0x1.8e56e4p0, 0x1.3d02a2p0, -0x1.5b960cp-4, -0x1.0fa18p-1, 0x1.089b5ep-2, 0x1.504b1ep-2, -0x1.495108p-3, 0x1.89eefp0, 0x1.e0f2ccp-1, -0x1.fd0bap0, -0x1.58d23p0, -0x1.1c81dap-3, 0x1.c7af9p-4, -0x1.336c14p0, 0x1.feb59ep-5, 0x1.6ba718p0, 0x1.dbc878p0, 0x1.b69714p0, -0x1.042f86p-2, -0x1.1f421ep0, 0x1.e51eacp0, 0x1.e033a6p0, 0x1.974a7p0, 0x1.c561d2p-1, 0x1.6274dap-2, -0x1.1461d6p-4, 0x1.ad32dep0, 0x1.6e21aap-2, -0x1.7b9f1cp0, -0x1.44c8f8p-3, -0x1.5cde72p0, 0x1.1b0f18p0, 0x1.b7b406p-2, -0x1.e60b82p-1, 0x1.a0a154p0, 0x1.0ff5p-1, 0x1.c11ab2p0, -0x1.8482cep0, -0x1.76749ap0, 0x1.3d6fa8p0, -0x1.8741eep-1, -0x1.27766cp-3, -0x1.fafa5ap0, 0x1.fe9ce4p-1, -0x1.328004p-1, -0x1.1a7bbcp0, -0x1.d6654cp0, -0x1.335d4p0, 0x1.4abb62p-2, 0x1.bf5196p0, -0x1.0bb26p0, 0x1.ed2d6cp-4, 0x1.6d7f88p-3, -0x1.1e8af2p-1, -0x1.e3a55ep-3, -0x1.2a93c4p-4, 0x1.376eep0, -0x1.8ca60ep-3, -0x1.1189c8p-2, -0x1.ef8bc2p0, -0x1.14362ap-3, 0x1.e0cc02p0, -0x1.dac4cp0, 0x1.91f41p-3, 0x1.bbb48p-1, 0x1.a36cbcp-3, 0x1.fdb972p0, -0x1.ddeba6p-1, 0x1.134028p-4, -0x1.605c74p-1, 0x1.2a59e2p-5, 0x1.065646p0, 0x1.d6195cp-2, 0x1.50e082p-1, 0x1.a771acp0, -0x1.6d0e54p-3, -0x1.0b878ap-1, -0x1.392cfep-1, 0x1.6d037cp0, 0x1.c089a6p0, 0x1.9db8eep-3, 0x1.06ef38p0, 0x1.cac87cp-2, -0x1.2cc40cp0, -0x1.1b5c6ep0, 0x1.478a24p-1, 0x1.81cac4p-2, 0x1.63f978p0, 0x1.1550f6p-8, -0x1.dc4fc8p-1, 0x1.465472p0, -0x1.9b6faep-1, -0x1.224beap-1, 0x1.39c07p0, -0x1.b73394p-1, 0x1.fa8f66p0, -0x1.220cbp-4, -0x1.ab934ap-1, 0x1.fac6cep-3, -0x1.e200cap0, 0x1.469884p0, -0x1.84b398p-3, 0x1.43897cp-2, -0x1.d4c304p0, -0x1.214a78p-1, -0x1.99c09p0, 0x1.2bd6c4p0, -0x1.87b19ap-2, 0x1.e1424ep-2, -0x1.45864ep0, -0x1.017642p0, 0x1.4b15ep-5, -0x1.c9fad8p0, 0x1.dfad7ap-1, -0x1.6362a6p-1, 0x1.2b4118p0, 0x1.1a600ep0, 0x1.fb341cp0, 0x1.63f388p0, -0x1.752f4ep0, -0x1.13313ap-2, 0x1.be27c2p-1, -0x1.d22e52p0, 0x1.bfb00ap0, 0x1.36307ep0, 0x1.6f1628p-7, 0x1.a962f2p-1, 0x1.8e6b8ap0, -0x1.133e98p-2, -0x1.ad7446p-2, 0x1.b382c4p-2, 0x1.31eef2p-2, -0x1.5d21c8p0, 0x1.d814f8p0, 0x1.21d232p-1, -0x1.79ac68p-2, -0x1.6b41bep0, -0x1.2154a8p0, -0x1.8d0ba6p0, -0x1.26f2cp-2, -0x1.aeaad2p0, -0x1.3ea2e8p-2, 0x1.9c3bdap0, -0x1.fbdc08p-1, -0x1.b0dcc6p0, -0x1.eaaf3ap-1, 0x1.9fb1aap0, -0x1.61ef6ap0, -0x1.794e5p-1, 0x1.7a9a98p0, -0x1.e427c6p-2, 0x1.b8a79ep0, 0x1.38e27ap-4, 0x1.508d5p-1, -0x1.470e5cp0, 0x1.c88becp0, 0x1.9dcc54p-5, 0x1.8b9e3cp0, -0x1.eb6202p0, -0x1.83a444p0, -0x1.3ee80cp0, 0x1.6dee5ap0, 0x1.b29b76p0, 0x1.28848ap-1, -0x1.91895ep0, 0x1.10a464p-2, 0x1.b34dep0, -0x1.ba3d68p0, -0x1.4ca566p0, 0x1.86b13ep0, 0x1.3e33cap0, -0x1.6b0828p0, 0x1.7f0eb2p0, -0x1.2f3286p-1, 0x1.aa7cccp-4, 0x1.2cc752p0, 0x1.950e74p0, 0x1.3bb44ep0, 0x1.a3ef1cp-2, 0x1.06a03cp0, 0x1.de9972p0, 0x1.8ac6e4p0, 0x1.0cb7dep-3, 0x1.9c0ed8p0, 0x1.20736cp0, -0x1.20db0ep0, 0x1.9303e4p-1, 0x1.55705p0, -0x1.6ff966p-1, -0x1.3ddbbap-5, 0x1.26d67ep0, -0x1.2ac1c8p-2, 0x1.14c028p0, 0x1.09088ep-1, 0x1.73d096p0, -0x1.611308p0, -0x1.d2849p0, -0x1.7bb08cp-2, 0x1.976d1ap0, 0x1.5653e2p-1, -0x1.4dc728p0, 0x1.10fab6p0, 0x1.451906p-3, -0x1.f12452p0, 0x1.c3ea56p-2, -0x1.305afap0, -0x1.d847c8p0, 0x1.9e2fb4p-3, -0x1.ea388p0, 0x1.d53b2ep-2, 0x1.436d96p0, -0x1.00d736p-6, -0x1.79bfb6p-1, 0x1.047262p0, -0x1.aadbp0, 0x1.dd42bap0, 0x1.da3314p0, -0x1.05b3e4p-1, 0x1.b5806p-2, 0x1.6eaba2p-2, -0x1.8d66b4p0, 0x1.2dd4dcp-2, 0x1.48f1f8p-1, 0x1.ba9b74p0, 0x1.31f186p0, -0x1.3ffd1ep0, 0x1.4b48dp0, -0x1.c98a1p0, 0x1.35f96p-2, 0x1.0b6388p0, -0x1.f309f6p0, 0x1.955b7ep0, 0x1.bb19dp0, 0x1.6a3924p0, -0x1.8ece7p-2, 0x1.d89b3p-1, 0x1.34771cp0, -0x1.2a64eep-1, 0x1.b13094p-1, -0x1.d44cd4p-4, -0x1.f6f27p0, 0x1.f863dp-1, 0x1.3d0f9ap-1, -0x1.b144c2p0, 0x1.44056ap-1, 0x1.6e3d9p0, -0x1.d3a568p-1, 0x1.fea126p-3, -0x1.d774ccp0, 0x1.5f22f4p0, 0x1.dbaf18p0, 0x1.422bdap-2, -0x1.f3b4d8p-1, 0x1.c31426p-4, -0x1.ad55e4p0, 0x1.2e12f8p-3, 0x1.d56996p-2, 0x1.2f0f8p0, 0x1.f3c5e6p0, 0x1.65770cp-1, -0x1.85c7a8p0, -0x1.958e2cp0, 0x1.b14528p-1, 0x1.457026p0, -0x1.04fd74p0, -0x1.923d04p0, -0x1.206b82p-3, 0x1.0e094p-4, 0x1.889ea8p-2, 0x1.e74c52p0, -0x1.48f824p0, -0x1.5e55c4p-6, -0x1.aab468p-7, -0x1.c4ef04p-2, 0x1.63cb64p-1, -0x1.3df0bep-1, 0x1.f718e4p0, -0x1.4fd6f6p0, 0x1.dd7ae2p-1, 0x1.4b4162p-1, 0x1.ad6d3cp-2, 0x1.009eep-1, 0x1.982a0ap0, -0x1.3302cep-2, -0x1.a62b9p-4, -0x1.a185aep0, 0x1.915356p-1, -0x1.06df78p0, -0x1.2ea5dp0, 0x1.7a0bf6p-2, 0x1.35ee92p0, 0x1.be57bep-2, -0x1.76d82ap-2, 0x1.083442p-1, 0x1.a8a4c6p-5, 0x1.3190b8p0, 0x1.402c78p0, 0x1.58a244p-2, 0x1.9c136ap0, -0x1.6a75a6p0, 0x1.5a638p0, 0x1.71da98p-5, -0x1.a69d44p-1, -0x1.737a48p0, -0x1.62d2b2p-1, -0x1.4ea67ap0, 0x1.feb0bp-1, 0x1.7fbe4ap-2, -0x1.b6776cp0, 0x1.24f49p-2, -0x1.fff8bap-4, 0x1.9442fp-3, -0x1.00b486p0, 0x1.9e59e2p-1, -0x1.99cd2ep0, 0x1.770edep-1, 0x1.6ef8c4p0, -0x1.bd4862p0, -0x1.9aeeep0, -0x1.40d72p0, -0x1.97e4bep-3, -0x1.c54d3p0, -0x1.86a3ap-1, -0x1.957e94p0, -0x1.fee91p0, -0x1.9fa942p0, 0x1.587b24p-5, 0x1.6b6c38p-6, 0x1.8b939cp-2, 0x1.eacf06p-1, -0x1.441b4ap-2, 0x1.d3a148p-1, 0x1.e3ff66p0, 0x1.a0294p-1, 0x1.03eb1cp0, -0x1.72afbap-4, 0x1.53d4aap-1, 0x1.aec1dap0, -0x1.486372p-2, -0x1.1802p0, 0x1.b2962ap0, -0x1.8290cep-3, -0x1.336e1ap0, 0x1.c4f406p0, -0x1.bd9p0, -0x1.ad3fc2p-1, 0x1.c7b0dap-2, 0x1.2754f6p-4, -0x1.b9e388p0, -0x1.b7a812p-4, 0x1.3b0562p0, 0x1.1eaacep0, -0x1.60390ap0, -0x1.ce6b1ep-1, -0x1.24faacp-2, -0x1.212abp0, 0x1.cabf2ep0, 0x1.4fad54p-1, -0x1.d278dap0, 0x1.337afp-9, 0x1.2b4394p0, -0x1.35e9c8p0, 0x1.a90816p0, 0x1.124418p0, 0x1.246b7ap0, -0x1.3a68b2p-1, -0x1.3e53cap-1, -0x1.67ee3ep-1, 0x1.32d308p-3, -0x1.71f972p-1, 0x1.f5b502p0, 0x1.21c40ap0, 0x1.e661fcp0, -0x1.1fda56p0, 0x1.cc9c66p0, 0x1.3b3514p-2, 0x1.9c1eb6p0, 0x1.26ae6ap0, 0x1.5374e2p-4, -0x1.bc94aep0, -0x1.dd522ap0, -0x1.482c44p0, 0x1.d75b6p-1, 0x1.db9942p0, 0x1.f7541p-6, 0x1.c1df44p0, 0x1.dc090cp0, -0x1.1512fap-1, -0x1.551bfp-2, -0x1.444bfap0, -0x1.4924ccp0, -0x1.9bc408p0, -0x1.022e2ep-5, 0x1.881176p0, -0x1.3911eap-1, -0x1.db8452p0, 0x1.e08392p-2, -0x1.45dd5cp-1, 0x1.72c162p-1, 0x1.bda362p0, -0x1.d1818ap0, -0x1.0211bep0, 0x1.d2de6p-1, 0x1.bcf76ap-7, -0x1.61bf42p0, 0x1.fdc12ap-3, -0x1.3bc45ap-2, -0x1.0ce96ap0, -0x1.cb632ap-6, 0x1.d1694cp-2, -0x1.cd4914p0, -0x1.130342p-1, 0x1.a4f52ap-3, -0x1.c9f60ep-1, -0x1.1076ecp-2, 0x1.4a58d8p-2, 0x1.2d4684p0, -0x1.89e542p0, -0x1.a7764ep-1, 0x1.c22246p0, -0x1.d7d1cep0, -0x1.14ae2cp-2, 0x1.a37af6p-1, 0x1.959f2ap0, -0x1.bb06e4p0, -0x1.686a14p0, -0x1.68200cp0, 0x1.a7ac82p0, -0x1.4d9d22p0, 0x1.1175c8p0, 0x1.cae842p0, -0x1.8efe68p-3, -0x1.dcbe16p-1, 0x1.eacap-2, 0x1.5245bap0, -0x1.458cb2p0, -0x1.4ddab6p-1, -0x1.5c7692p-1, 0x1.b4f92ep0, 0x1.d3f548p-1, -0x1.e15974p-1, -0x1.fb830ap0, -0x1.729db8p0, -0x1.14776p-1, 0x1.4b5bf4p-1, 0x1.fe187cp-6, 0x1.14f3ep0, 0x1.b4636p0, 0x1.0cf31ap0, -0x1.5f951p0, 0x1.a99336p-2, 0x1.4e7d3ep-5, 0x1.65ad66p-2, -0x1.d5458ap-2, 0x1.ae143ep0, -0x1.c16d6ep0, -0x1.80d1a4p-1, -0x1.4e12a2p0, 0x1.b28f78p0, 0x1.586922p-1, -0x1.f63782p-1, -0x1.ddd736p-1, -0x1.c22662p-1, 0x1.cb1664p-1, -0x1.6b28aep0, -0x1.398a2p0, 0x1.b9d46ep-1, 0x1.fa134cp-4, 0x1.faddc8p0, 0x1.5ba1eep0, 0x1.2ffa42p-3, 0x1.5caf02p0, -0x1.9b6ffcp0, 0x1.973478p-1, 0x1.c42d26p0, -0x1.b6f1bcp-2, 0x1.3de362p0, -0x1.8c496p-3, -0x1.aa83bep0, 0x1.10e794p-2, -0x1.61b7f6p0, 0x1.7b8cfcp0, 0x1.0cc546p-1, -0x1.88a236p-2, 0x1.85d668p-2, 0x1.0e781ap0, 0x1.ba7e06p-2, 0x1.69a76cp0, 0x1.2399cep0, 0x1.0783bap0, 0x1.9f30eep-1, 0x1.7b1b1ep-1, -0x1.74f95cp0, 0x1.22f5d2p-2, -0x1.1a247ep-5, 0x1.7501ap-1, 0x1.419142p-7, 0x1.e4da12p-4, 0x1.e0fc78p-3, 0x1.3f1f82p-1, 0x1.258104p0, 0x1.0f3eaep-1, -0x1.a4ebdep-1, -0x1.de5c4cp0, 0x1.4c6ef8p-5, 0x1.a15998p-2, 0x1.8a251ep0, -0x1.edf4fp-5, 0x1.04fd62p-1, -0x1.41d51cp0, 0x1.ed1dbcp-1, -0x1.b79de2p-3, 0x1.531a92p-2, -0x1.113e46p-2, -0x1.e735e4p-3, 0x1.635d9ep0, 0x1.b3410cp-1, -0x1.77edd8p-4, 0x1.f774bp-1, -0x1.f3e38ap0, 0x1.29def2p-5, -0x1.52028p0, 0x1.a8a166p0, -0x1.1c9812p-1, -0x1.6a68ap0, -0x1.cbf20ap-1, 0x1.f87a3p0, 0x1.f24808p-1, -0x1.778356p-2, 0x1.e576d2p0, 0x1.b111aap-2, 0x1.fedd62p0, 0x1.2c062p-1, -0x1.4f95d2p-3, 0x1.12047p0, 0x1.91b124p-1, -0x1.446da4p-5, 0x1.22d52cp0, -0x1.03203cp-2, -0x1.29c624p0, -0x1.0ce4bcp-1, -0x1.aca1acp-1, -0x1.f62ec4p-1, 0x1.a08e16p-2, 0x1.b6556ep-2, -0x1.287724p0, -0x1.c64996p-1, -0x1.0f7beep0, 0x1.50d594p0, -0x1.87aad2p0, 0x1.8c2784p0, 0x1.83a22ep0, -0x1.a1c21ap0, -0x1.a42d36p0, 0x1.934fcep0, 0x1.340e86p0, 0x1.a93462p0, -0x1.e3c368p-1, -0x1.d46938p0, -0x1.08f678p0, -0x1.80a9p0, 0x1.f1fa1cp0, 0x1.f88392p-1, -0x1.799d1cp0, -0x1.2e522cp-1, 0x1.1f0d28p-2, -0x1.2ebbcap0, -0x1.7507cp0, -0x1.681c1ep0, -0x1.b60648p0, 0x1.45653cp0, -0x1.14562ap-1, -0x1.6cef74p0, 0x1.340f1ep0, -0x1.8b1742p0, 0x1.9c8a6ap0, -0x1.dbbcd4p-1, -0x1.f62562p-1, -0x1.875ddcp0, -0x1.9c8fdcp0, 0x1.ffcddep-2, -0x1.f413f6p-1, 0x1.c4b6fap-4, 0x1.f14a9ap0, -0x1.ecff3ap-1, -0x1.8a4ff6p-2, -0x1.5e99c6p-3, 0x1.5d3812p-1, 0x1.ec2cd8p-1, -0x1.bd27c2p0, -0x1.457d44p0, 0x1.ed59dep0, 0x1.f9a7c2p0, -0x1.04ce84p-3, 0x1.103ae2p-1, -0x1.0e596p0, 0x1.14ea0ep0, -0x1.f7d1ecp0, 0x1.85988ep0, 0x1.b60546p-1, -0x1.57986ep-2, 0x1.90c40cp0, 0x1.f63d82p-5, -0x1.e11844p0, -0x1.e4ec38p0, 0x1.5c48fcp-3, 0x1.69b206p0, -0x1.d87d0ep0, -0x1.223b28p-1, 0x1.5dc1b8p0, -0x1.f32092p-1, 0x1.4c4b74p-2, -0x1.be6b02p-2, -0x1.249cd6p-1, 0x1.edb014p0, 0x1.47703ep0, -0x1.c0c62cp0, 0x1.c219fap0, 0x1.f747ap0, -0x1.bd5b3ep0, -0x1.0c5124p0, 0x1.5bb93ep0, 0x1.eecb0ep0, 0x1.2db0c8p0, -0x1.2046c2p-1, 0x1.c57a9ep-1, -0x1.b49b12p-1, -0x1.49aa08p0, 0x1.8b14ap-2, 0x1.e7001ep0, -0x1.7faee6p-1, 0x1.f5604cp0, -0x1.46106cp-4, -0x1.7c5116p0, 0x1.ec63dap0, -0x1.3ad158p0, -0x1.0cbeccp-4, 0x1.aef286p-1, -0x1.961426p-1, -0x1.6ff98ap-1, 0x1.58a89cp-6, -0x1.19eac2p0, 0x1.15d628p0, -0x1.e840b6p-1, 0x1.3e7b7p-1, 0x1.78540cp-3, -0x1.55c812p0, 0x1.7a513ep-1, -0x1.dd0f8cp-1, 0x1.8e5daap0, -0x1.ba8146p-3, 0x1.c989cp0, 0x1.9b578ap0, 0x1.8dc47ap-2, -0x1.c36336p0, 0x1.365d32p0, -0x1.2d554ep-2, 0x1.f5c1ecp-2, 0x1.3d28cep-3, -0x1.95e7f8p0, 0x1.6da116p0, 0x1.29ec26p0, -0x1.e0fa02p-1, -0x1.44b2fcp0, 0x1.871934p0, -0x1.c3bc42p-1, 0x1.1cc614p-1, 0x1.5ffb6ap0, -0x1.d59174p0, -0x1.6c2d18p0, 0x1.4598f4p-3, -0x1.71af42p0, -0x1.60610ep-2, 0x1.e1f3fcp-1, 0x1.a8752cp-1, 0x1.45dbb6p0, 0x1.3a6b94p-1, 0x1.46e46ap-4, -0x1.9caa1p0, 0x1.03ed7cp-1, 0x1.b1a6cp0, 0x1.ef7808p0, -0x1.ba9362p-9, 0x1.205bfap0, 0x1.c47fe2p-1, -0x1.5e63c4p0, -0x1.17406ep-2, -0x1.9764acp-1, 0x1.5a3b8ap0, -0x1.25c378p0, -0x1.1bead4p-2, 0x1.7f0d5p-1, 0x1.bbb40ep0, 0x1.629ea6p0, -0x1.255fc8p-1, -0x1.4d896p0, -0x1.2d7f2ap-2, -0x1.e040f4p-1, -0x1.4103a8p-1, -0x1.7741eep-1, 0x1.1584p0, 0x1.0116a2p0, 0x1.ff6b6p0, 0x1.ddf55ap-1, 0x1.96db1cp-2, -0x1.954816p0, 0x1.8cf2cp-1, -0x1.06a81cp-2, -0x1.d33ac4p-2, 0x1.1f65fcp-2, -0x1.88895p-1, 0x1.be55ap0, -0x1.09d306p0, -0x1.af97b2p0, 0x1.771c16p-1, -0x1.1f8662p-1, -0x1.8d96d4p0, -0x1.8c2bep0, 0x1.410976p0, 0x1.15d2aep0, 0x1.928086p0, -0x1.19711ap0, -0x1.1fec62p0, -0x1.5009cep-2, -0x1.0eb692p0, 0x1.e4a01ap-3, -0x1.1006aep0, 0x1.5b5c86p0, 0x1.40ffb2p-6, 0x1.5e4c68p0, 0x1.6cf71cp-1, -0x1.5ad816p0, 0x1.6a3a4ap0, -0x1.bbb916p0, 0x1.27d1b4p-1, -0x1.c14b0ep-1, 0x1.3fc48cp-3, -0x1.4e5e32p0, 0x1.5b05f4p0, 0x1.d8e296p0, 0x1.191aa6p0, 0x1.c48a7ep0, 0x1.40e9ep0, -0x1.924182p-2, 0x1.66d506p0, 0x1.159e84p-1, -0x1.2a978ap0, -0x1.dd471cp-1, -0x1.a1a1eap-4, -0x1.4e9276p-1, 0x1.5c3ef6p-2, 0x1.89ce4cp-3, 0x1.9c58fep0, 0x1.66a872p-1, 0x1.80e346p-1, -0x1.72a716p-4, 0x1.8c4ac2p-2, -0x1.7c2046p0, 0x1.40f562p0, -0x1.ee09b4p0, -0x1.e29d2ep0, 0x1.2c4026p-2, -0x1.1c62eep-1, 0x1.a17f18p0, -0x1.bc6fccp-3, -0x1.a5de5ep-2, 0x1.901c6ap0, -0x1.7a9bb6p0, -0x1.3986p0, 0x1.ea59dp-3, -0x1.db8714p-2, 0x1.780238p-1, 0x1.9333aap0, 0x1.4386cap-4, 0x1.201c12p-1, 0x1.5628f2p-1, -0x1.d0c12cp0, -0x1.f9591ap-1, 0x1.bda0dcp0, 0x1.4b2cc8p-4, 0x1.fca1b2p-1, -0x1.2fcf98p-1, 0x1.ce5e6cp0, 0x1.fe64f8p-3, -0x1.5bb87cp-1, 0x1.61cf98p0, -0x1.f5eafp0, 0x1.f4a606p-1, -0x1.87ccap-2, -0x1.21befep0, -0x1.18fd3cp-1, 0x1.f0acb8p0, -0x1.07a754p0, 0x1.06535p0, -0x1.a3a1b4p-3, 0x1.65fdc2p-3, 0x1.40d096p0, 0x1.eb51d2p-1, 0x1.d317aep0, -0x1.0ac8ccp0, 0x1.9bc872p0, -0x1.627e9ep0, 0x1.c3817ap0, -0x1.85a0a4p-1, -0x1.039e2ep0, -0x1.b2a2f8p-1, 0x1.dc7e12p0, 0x1.36de6p-2, -0x1.6e53bcp-2, 0x1.be5b58p0, -0x1.b44348p-1, 0x1.eb6c78p-2, -0x1.af5bacp-1, -0x1.3fe0cp0, 0x1.bcc6dep0, -0x1.238c42p-1, -0x1.bf33b4p-2, 0x1.89f90ap0, 0x1.8557p0, 0x1.b60d52p0, 0x1.120c1ep0, 0x1.4403f8p-3, 0x1.cdfee4p-1, -0x1.c1b96ep0, 0x1.fd4d1cp-2, -0x1.7a5d0ep0, -0x1.8fa076p-7, 0x1.2aa3fap-1, 0x1.25656p0, -0x1.2c053p-1, 0x1.a0154p0, 0x1.cf1a8ep0, -0x1.64bdaap-3, 0x1.de5ad6p-1, -0x1.c79034p-2, -0x1.a9c99ap-4, -0x1.d60182p-2, -0x1.f08a18p0, -0x1.bb0764p0, -0x1.55193p0, -0x1.53c8d4p0, -0x1.9a632p0, -0x1.fa02e2p0, 0x1.0a8046p-1, -0x1.6d70eep0, -0x1.c8a39ep-2, 0x1.c0afc8p-2, -0x1.a033fp-7, -0x1.c741aap0, -0x1.f49eap-1, 0x1.51237cp-1, -0x1.56ecc8p-3, -0x1.3bb8b2p0, -0x1.0896e4p-1, -0x1.d4eecap0, 0x1.7d141p-4, -0x1.e6160ep0, 0x1.d07ed8p-1, 0x1.80f072p0, -0x1.15ccbap0, 0x1.6dc23ap-1, -0x1.f0be8ep0, -0x1.758bf2p0, 0x1.1be8a6p0, 0x1.ebfa9p-1, 0x1.cad9dap0, -0x1.473b82p-3, -0x1.d4bc52p-1, -0x1.7997fep-2, 0x1.dc225ep-1, 0x1.369056p0, 0x1.dab574p0, -0x1.65ad5ep0, -0x1.856686p-2, -0x1.b63322p0, -0x1.032e8cp-2, 0x1.59d9eep0, 0x1.b8c7cp0, -0x1.65ca46p-1, -0x1.db0662p-1, 0x1.35d6p0, -0x1.9fb152p0, -0x1.5f796p-1, -0x1.fed864p-2, 0x1.27661p0, 0x1.18110cp-1, -0x1.1be634p-2, -0x1.60d32ap-1, 0x1.2476a6p0, 0x1.543ffap-1, 0x1.b462c8p0, 0x1.d1e346p-2, -0x1.63050ap0, -0x1.69e86ap-4, -0x1.c591bp0, 0x1.95ebbap0, -0x1.6bfe58p0, -0x1.9b44b6p-1, 0x1.6702a2p-2, -0x1.59c896p-2, -0x1.8ff0b2p0, -0x1.e931c8p-1, -0x1.9aef74p-3, -0x1.11bc6p0, -0x1.cbd90cp-1, 0x1.658f92p-2, -0x1.4d0d5cp0, -0x1.1d43ecp-1, -0x1.b75bf4p-2, 0x1.381462p-2, 0x1.311aeap0, 0x1.384edcp-1, 0x1.11ef26p0, -0x1.10c9dap0, -0x1.1bbe4ep0, -0x1.a90efp0, 0x1.87a732p-1, 0x1.53f6dp-2, 0x1.7c8bfp0, 0x1.f5be48p-7, -0x1.0f67b4p0, 0x1.5d4a1p-1, 0x1.311ecap-2, -0x1.d619ep-2, 0x1.259dbp0, -0x1.964e68p-2, -0x1.ff36dcp-3, -0x1.243fdep-1, -0x1.eba2f2p0, 0x1.236d4cp-2, 0x1.feda68p-1, -0x1.d4d2b6p0, 0x1.5c64bep-1, 0x1.e80f7ep-6, 0x1.530612p0, -0x1.6e3618p0, 0x1.3e74e4p-2, -0x1.6a9e72p0, -0x1.349b3cp-3, -0x1.740042p0, 0x1.258036p-1, -0x1.3cd642p-1, 0x1.5e0f76p0, 0x1.2a146ap0, -0x1.e380d8p-1, -0x1.b87ae2p0, 0x1.763feep-1, 0x1.1f094p0, 0x1.09628ep0, 0x1.33fbb2p-2, -0x1.f07c3ap0, 0x1.d78caep-3, -0x1.cdd36p-2, 0x1.11da7ep-2, -0x1.7dd99ap-1, -0x1.014d0ep0, -0x1.25ca1cp0, -0x1.f08874p-1, -0x1.b1f822p0, 0x1.288f78p-2, -0x1.63c85ep0, -0x1.e9eb5ap0, 0x1.1d8514p0, -0x1.e0a25ap0, 0x1.c3cebap-1, 0x1.e5389p0, -0x1.c518fap0, -0x1.1a1056p0, 0x1.26c8b4p-5, -0x1.84d53ap-1, -0x1.ed56d6p-1, 0x1.d9320ap0, -0x1.0252b6p-1, 0x1.7d0f18p-1, -0x1.1e9e38p-1, -0x1.2503ap-2, 0x1.dea9ep0, 0x1.0af9f6p0, 0x1.abd3fep0, 0x1.8b1f6p0, -0x1.2fb3ccp-1, 0x1.5f7d06p0, 0x1.5099dcp-2, -0x1.389364p-6, -0x1.dfdd8ap-1, -0x1.601c9ap-2, -0x1.4577a6p0, 0x1.89e5b8p0, -0x1.545e1ep-11, 0x1.41aaf2p0, 0x1.531908p0, -0x1.91f68ep-1, 0x1.fd6988p-2, -0x1.89ef46p0, -0x1.9fc0d4p0, -0x1.0cc6dp-2, 0x1.31a1c4p-3, -0x1.3acfdap-1, -0x1.00ec3p0, 0x1.90eaacp-1, -0x1.e9ffeep0, -0x1.29c3f8p0, -0x1.b5abdap0, -0x1.7f861cp0, 0x1.0daa28p0, -0x1.74f5b8p-1, 0x1.515b6ap-2, 0x1.7d6b9ap0, 0x1.ac3abap-1, 0x1.090224p0, 0x1.dfc62ap-1, -0x1.f2c58ap-2, -0x1.42f5f6p0, 0x1.6c426cp-1, 0x1.7ca62ep-2, -0x1.926a8cp0, 0x1.695fe6p0, -0x1.5ffd5ep0, -0x1.9c2c08p-2, -0x1.f3e37ap-3, 0x1.17527ep0, 0x1.19f9e4p-2, -0x1.2767cp-5, -0x1.e8174cp0, 0x1.50a91cp0, -0x1.362a28p0, -0x1.db5968p-1, 0x1.c0882ep0, -0x1.42ba84p-2, -0x1.e525dap0, 0x1.f1bd82p-1, -0x1.8cf2bcp0, -0x1.9174a4p0, 0x1.53608ep0, -0x1.b8c95p0, -0x1.fcbc3cp-1, 0x1.f9750ep0, 0x1.bcb64ap0, 0x1.8621p0, 0x1.e6a0f8p-1, -0x1.945478p-1, 0x1.6ebbbp-2, -0x1.325c88p0, 0x1.853322p0, -0x1.756138p0, -0x1.1a555ap-1, 0x1.73ddap-1, -0x1.2a5968p0, 0x1.fa7214p0, 0x1.fe01bp0, 0x1.10fd28p0, 0x1.3f2p-2, 0x1.b90a92p-1, -0x1.55e96p0, -0x1.4884fcp0, -0x1.533b06p-3, 0x1.96068ap-5, -0x1.24a82ep0, 0x1.a1a12p0, 0x1.b99252p0, 0x1.ce6126p0, 0x1.39298ep-3, 0x1.b78614p0, -0x1.20e544p-1, 0x1.44c864p0, -0x1.bf7ff2p-1, -0x1.66752cp0, -0x1.05458cp-1, -0x1.8d7418p0, -0x1.68783p-1, 0x1.39553ep-1, -0x1.c0c238p-5, -0x1.949d44p0, -0x1.829d24p-1, 0x1.a7e9ccp-1, -0x1.a5ba1cp0, 0x1.d63d5ap-1, -0x1.62d4a4p0, 0x1.40b958p0, 0x1.fce912p-5, 0x1.31ee7ap0, 0x1.839932p0, -0x1.fad152p-4, 0x1.c84f3p0, -0x1.3cd24ep-1, 0x1.3fa7a2p-5, 0x1.b7e22p0, -0x1.0ac994p0, 0x1.ff6712p-2, 0x1.136e28p-1, 0x1.a4f5bcp-3, 0x1.4a3224p-1, 0x1.01bda8p-3, 0x1.5f35ecp0, 0x1.1e239ep0, -0x1.e0573p-2, -0x1.f4c5bp-1, -0x1.87987ep-13, 0x1.e52398p-1, 0x1.28ee9ep-3, -0x1.ee8b1ep-9, 0x1.ff2518p0, -0x1.5cb854p-4, 0x1.8918e8p0, 0x1.2cdddep0, -0x1.80e3d6p-1, 0x1.4bb7a2p-1, 0x1.0785dp0, -0x1.60b93ep-2, -0x1.114b6ap0, -0x1.bcbab4p0, -0x1.06984ap0, 0x1.4686d4p-1, -0x1.8a0bf6p-1, -0x1.abe522p-1, 0x1.547a7cp0, -0x1.19ce42p-3, 0x1.df16a6p-1, -0x1.fe5e12p-4, -0x1.aab982p0, 0x1.28cadep0, -0x1.77551ap0, 0x1.c765eap-2, 0x1.3cd1a2p-2, 0x1.44ce5cp-3, -0x1.13b83ep-2, 0x1.38a39p-1, 0x1.a38c52p-1, 0x1.50689ap-1, 0x1.d0c0d4p0, -0x1.c5e656p0, 0x1.308a18p0, 0x1.b6da4cp0, 0x1.593edp-2, -0x1.5ffbeep0, -0x1.9e6e08p-1, -0x1.39124ap0, -0x1.8423dep0, 0x1.082218p-1, 0x1.922966p0, 0x1.ab4baep-2, 0x1.a296bp-2, 0x1.f891cp0, 0x1.80ff04p0, -0x1.eee3e4p0, 0x1.99b79p0, -0x1.eb4f88p-1, 0x1.858128p0, 0x1.0db71ap-2, -0x1.624346p0, -0x1.45a6b4p-1, 0x1.928d1p0, -0x1.d5991cp0, 0x1.3cd8fap0, 0x1.48951ap-3, 0x1.77fc5p0, -0x1.063844p0, -0x1.541774p0, 0x1.236084p0, 0x1.db49b8p-2, 0x1.233976p-3, -0x1.ee3e2ap-2, -0x1.059844p0, -0x1.89a15ep0, 0x1.41c2fep0, -0x1.cc5662p-1, 0x1.251e9ap0, 0x1.d6c002p0, -0x1.54ba52p0, 0x1.62d0c6p0, -0x1.c4afp0, 0x1.47383ap0, 0x1.561b9ap0, -0x1.901b1p0, 0x1.e792fap0, 0x1.61794cp-1, 0x1.ded866p0, 0x1.9950dcp0, -0x1.921ab8p-1, 0x1.1aed92p0, -0x1.ef6214p-1, -0x1.0241acp-3, -0x1.e49e84p-1, 0x1.0ea6d2p0, 0x1.8a030cp-2, 0x1.3f8e72p-1, -0x1.b8ea5cp-1, -0x1.dd16e4p-2, 0x1.afcdbep0, -0x1.7bc1dep-6, 0x1.36f708p0, 0x1.e561eap-1, 0x1.e99592p0, -0x1.9514c8p0, 0x1.c18c0ep-1, 0x1.60234p-3, -0x1.c9d626p0, -0x1.af042cp0, -0x1.c341acp0, 0x1.2fd9e2p-3, -0x1.0cbd2ap-4, -0x1.1cfd9p-1, -0x1.c10326p-1, 0x1.84086ap0, -0x1.ba286p-5, -0x1.343692p-1, 0x1.b5b5a4p0, -0x1.3e97bcp-1, 0x1.543916p0, -0x1.115158p0, 0x1.9710cap-1, -0x1.477176p0, -0x1.565506p-2, -0x1.6cdc82p-1, 0x1.bef59cp0, 0x1.945b4ep0, -0x1.16c486p-1, -0x1.42f046p0, 0x1.2bff7ep-3, -0x1.a97b5p-1, 0x1.24298ep0, -0x1.519bdep-1, 0x1.84607ap0, -0x1.903156p0, -0x1.71ebaep0, -0x1.7e952ep0, -0x1.c2971p-2, -0x1.71da8cp-1, 0x1.786d8ep0, 0x1.c94848p0, 0x1.3e8364p-1, 0x1.662252p-2, -0x1.b16eaap0, -0x1.906952p0, 0x1.a74008p0, -0x1.c150dp-1, 0x1.a01622p-8, -0x1.33060ap0, -0x1.62620cp-1, -0x1.94aa64p-2, 0x1.6dd958p0, 0x1.bbace2p-1, 0x1.965e54p-2, -0x1.c2221cp-1, -0x1.ee2a08p0, 0x1.c2bfd8p-1, -0x1.87bd06p0, 0x1.ef6266p-1, -0x1.9e5cf4p-1, -0x1.b858e8p0, 0x1.ab4d1cp0, -0x1.c9523ep-4, -0x1.939c0ap0, 0x1.04f5fp-1, -0x1.17c20ap0, 0x1.d2c30ap0, -0x1.e09e4cp-1, -0x1.21971p0, 0x1.827494p-1, 0x1.e6bd1ap-1, 0x1.7cec98p0, -0x1.8300b2p-6, 0x1.e8e8d8p0, -0x1.267f88p0, 0x1.694868p0, 0x1.a5f0ecp-2, 0x1.1726c2p0, -0x1.9b5a28p0, 0x1.2ee00ap0, -0x1.2dbc84p-1, 0x1.e20566p0, -0x1.1fb13ep-3, 0x1.25c95cp-1, 0x1.c96706p0, -0x1.6b1afcp-1, 0x1.e108a2p0, 0x1.1072a8p0, -0x1.bcc86cp-2, 0x1.f1a3dep0, 0x1.e02edp0, -0x1.104822p-3, -0x1.b7e1acp0, -0x1.ad5cbp-1, -0x1.45e272p-1, 0x1.4b1096p-1, -0x1.02dea2p0, 0x1.2a4a6ap-3, -0x1.e1d85cp0, -0x1.9c90dcp-1, -0x1.5236a8p0, 0x1.1b601ep0, 0x1.85e15cp-1, -0x1.e28962p0, -0x1.d8d198p-1, -0x1.8de75ep-1, 0x1.836dd8p-4, -0x1.498046p-1, 0x1.bcbad8p-1, 0x1.1d3384p0, -0x1.719126p0, -0x1.a1cafap-1, 0x1.ab3694p0, -0x1.af032ap-1, 0x1.b1d71cp0, -0x1.3e80b6p0, -0x1.1b62c2p0, 0x1.1bc6cap0, 0x1.8a1eacp-2, -0x1.2e854cp0, 0x1.a6c73ap-1, 0x1.95e978p0, -0x1.15e12cp-1, -0x1.93220ep-4, -0x1.a9b56cp0, -0x1.7a6c3p0, 0x1.6226d8p0, -0x1.7d4792p0, -0x1.a7a9ap0, 0x1.18af8ap-2, -0x1.4899d2p-1, 0x1.8d3cfcp-2, 0x1.aed21ap-3, 0x1.ffd634p-4, -0x1.2fef64p-3, -0x1.4b20c4p0, 0x1.541b22p0, -0x1.ee92bp-1, -0x1.14cb28p-1, -0x1.c7dbbcp0, -0x1.edc926p-1, 0x1.342b9p0, -0x1.fe197ap-1, -0x1.4e6daap-1, 0x1.468e36p0, -0x1.2b9e82p0, 0x1.9cc4a4p-2, 0x1.9e3caap-2, -0x1.605a2ap0, -0x1.fce83p-1, -0x1.76edf4p-5, 0x1.dbc94ap-7, -0x1.d4df4p-2, 0x1.332caep0, -0x1.a25fep0, -0x1.d99da8p0, 0x1.59383ep0, -0x1.a3c4ccp0, 0x1.2bb486p0, 0x1.0285e4p-2, -0x1.796122p-2, 0x1.470432p0, 0x1.796cbep-1, 0x1.4d093ap-2, -0x1.e0e23cp0, -0x1.f5ec94p0, -0x1.bdf4d6p-5, -0x1.1989bep-2, 0x1.001978p0, -0x1.593f84p-1, -0x1.520746p0, 0x1.2b5d82p-1, 0x1.4ecb98p0, 0x1.ec6d4ap-1, -0x1.f738b4p0, 0x1.5a0678p-1, -0x1.cf212cp0, -0x1.58769cp0, 0x1.4297e2p0, 0x1.208fd6p-5, -0x1.c12264p-2, -0x1.1ce514p0, 0x1.d57ee4p0, -0x1.509e9cp-1, 0x1.40d05ap0, 0x1.78f622p0, 0x1.e5d0ap0, -0x1.895b64p0, 0x1.03c928p-2, 0x1.cb7156p0, -0x1.f6c9aep-1, 0x1.b19c16p-7, 0x1.62b49ap0, 0x1.fda752p-1, -0x1.1b1136p-1, 0x1.204aecp-1, -0x1.ae4a7ap0, 0x1.3fa73cp-1, 0x1.2439c2p0, -0x1.e36f7cp-4, -0x1.cc5c6cp0, 0x1.4dfe72p0, 0x1.831f14p0, -0x1.eb5da2p-1, 0x1.307562p0, -0x1.1e0cp-3, 0x1.4670d4p0, -0x1.65c6c4p0, 0x1.719bbcp0, -0x1.507f6cp0, 0x1.dd015p-2, -0x1.a346fep0, -0x1.fc7cc2p0, 0x1.61a148p0, -0x1.26de26p0, 0x1.3096p-3, -0x1.2dacep0, 0x1.06b794p-1, -0x1.dec71cp-2, 0x1.b37874p-4, -0x1.cbf01ep-1, 0x1.a12656p-7, -0x1.68e9c6p-1, 0x1.962e5cp0, 0x1.2f1d3ep-2, 0x1.6a31fcp-1, 0x1.4163dcp-1, -0x1.351bfep0, 0x1.546cdcp-3, 0x1.e1032ep0, -0x1.456b9ap0, 0x1.5e72b2p0, 0x1.601758p-1, -0x1.e10b68p-2, -0x1.36a0dep-2, -0x1.927c8ap-1, 0x1.53bad8p0, 0x1.46b5a2p0, 0x1.e0ca84p0, -0x1.f262bap-1, 0x1.c89c44p-1, -0x1.b4509ap0, -0x1.c720dcp0, -0x1.2197fcp-1, 0x1.af0c12p0, 0x1.1fe02p-1, -0x1.7554bcp0, -0x1.1a1cbcp0, -0x1.05cbd8p-4, 0x1.f0155ap0, 0x1.b6f65ap-2, 0x1.a20318p0, -0x1.2b013ap0, 0x1.21fd5ep0, 0x1.c4c42ep0, -0x1.89774ap0, 0x1.34b33ep0, -0x1.eb1538p-6, 0x1.dc1a6ep-1, 0x1.f81a34p-1, -0x1.75464p0, -0x1.0c4724p0, 0x1.030ae6p0, -0x1.472092p-1, -0x1.fe9df4p-1, 0x1.33c7dap-1, -0x1.14eac8p0, 0x1.0b3c18p-1, 0x1.dca256p-1, -0x1.ae3718p0, -0x1.e30d78p0, 0x1.4ad942p0, 0x1.0c200cp0, 0x1.61c988p0, -0x1.710284p0, 0x1.860434p-2, -0x1.7b0334p0, -0x1.b5d3fap0, 0x1.9a5aa4p0, -0x1.74d99ep0, -0x1.29a0eep-1, -0x1.77971cp-1, 0x1.9cd6c2p-3, 0x1.0f2346p-1, -0x1.6b1574p0, -0x1.1c673cp-2, 0x1.df5992p-4, -0x1.367ep0, -0x1.b53508p-2, -0x1.5b3732p0, -0x1.6bf422p0, -0x1.293ed6p-1, -0x1.ed5c66p-2, -0x1.f4f3cp0, 0x1.f2169ap-1, -0x1.7ba9f6p-2, -0x1.41786ap-1, -0x1.6a7a24p-2, 0x1.a690eap0, -0x1.8495bep-2, 0x1.399e1p-2, -0x1.c6cf24p-1, 0x1.9efdfap0, -0x1.3d066cp0, -0x1.95b2e2p-5, -0x1.cbd41cp-4, 0x1.f2a89cp0, -0x1.077bacp-5, -0x1.ad8414p0, 0x1.1a9ebap-1, -0x1.713e34p-2, -0x1.e445aap0, -0x1.0ad39p0, 0x1.35f7a2p-2, 0x1.a5893p-1, 0x1.320c82p0, -0x1.c1d2e8p-3, -0x1.7f53c8p0, -0x1.5e69d4p0, -0x1.9a4bf4p0, -0x1.f78ac6p0, 0x1.861decp-1, 0x1.c0135ep-1, 0x1.9152bp-1, -0x1.a42696p0, 0x1.316d4ep0, -0x1.9d61c8p-1, 0x1.bfa308p-1, -0x1.23c116p-1, 0x1.0c866ap0, -0x1.e980f6p-2, -0x1.da857ep-1, 0x1.c814b6p-5, -0x1.82edbcp-1, 0x1.33ed88p-3, -0x1.d84498p0, 0x1.8a5f32p0, -0x1.99a238p-2, -0x1.5162b8p0, 0x1.1bc07p-1, 0x1.67870ep0, -0x1.2858acp0, -0x1.0510d8p0, 0x1.f8333p-2, -0x1.016882p-2, -0x1.b938f6p-1, -0x1.2464dp-3, -0x1.60ee1ep0, -0x1.4ae008p-1, -0x1.96c79p0, 0x1.35cb1p-4, 0x1.bd062cp0, -0x1.9226aap0, -0x1.0ac96p0, 0x1.4253cp0, 0x1.e4b18ep-1, -0x1.c1d49p-2, -0x1.addfcp-1, 0x1.0e176ep-7, -0x1.ad9032p-1, -0x1.588a4ap-1, 0x1.3f1d76p-1, -0x1.1da1c6p0, -0x1.e64796p0, -0x1.2c885ep-1, 0x1.e203a8p0, -0x1.5cd95ep-2, 0x1.c13eap0, -0x1.f45cb6p-1, 0x1.0246eap-2, 0x1.e42338p-1, 0x1.4a3a3cp-1, 0x1.30a47cp-8, -0x1.d13f2p-2, -0x1.284a72p-1, -0x1.fd4c28p0, 0x1.5abf6cp-2, 0x1.dd3636p0, -0x1.5c3254p0, -0x1.5c432ep-1, -0x1.ea9816p-3, 0x1.e75092p0, -0x1.a0e246p0, 0x1.8826c2p0, -0x1.55c65ap-1, 0x1.a32ebcp0, -0x1.ad15d2p0, -0x1.9dc28ap0, -0x1.d021fap0, -0x1.7f5552p-3, 0x1.5964c2p-4, -0x1.52ab7ep-1, -0x1.0c3876p-1, -0x1.98a04ep-1, -0x1.980fa8p0, -0x1.67d8cp-3, -0x1.a2239ep-2, 0x1.a17894p-1, -0x1.13f57p0, 0x1.fd6594p0, 0x1.1b6a48p0, -0x1.09522cp-6, -0x1.aa1ffap0, 0x1.d70572p-2, -0x1.411fa4p-2, 0x1.de64c4p-1, -0x1.28131p-1, 0x1.f50a5p-1, 0x1.3f1332p0, -0x1.0e52dcp-1, -0x1.0ddf6ap0, 0x1.42c246p0, 0x1.d57502p-1, 0x1.a4489ap-2, 0x1.2ff10cp-1, -0x1.2b96cep-1, 0x1.176362p-2, 0x1.a44566p-3, -0x1.5ccc6p0, 0x1.cbf18p-1, -0x1.c65eb6p-2, -0x1.2d2e14p-4, -0x1.417ad4p-1, -0x1.ad40f6p0, 0x1.2bd16cp-1, -0x1.27819cp0, 0x1.97624ap-1, -0x1.eb6acap-1, -0x1.3e39aap0, 0x1.1ab72p-1, 0x1.ac97fap-1, -0x1.e74e46p0, -0x1.524e82p0, -0x1.e5ea8ap0, 0x1.e7e3dp0, 0x1.2efc96p0, -0x1.3ff4a4p-2, -0x1.f20664p-1, -0x1.843dp-1, -0x1.10831cp-2, -0x1.47079ap-1, -0x1.d33734p-2, 0x1.2c7fa6p0, 0x1.4f0f7cp-5, -0x1.390c42p-1, -0x1.2c5822p-1, -0x1.6f1e36p-1, 0x1.52ed0ep0, -0x1.2081c4p-3, 0x1.70eaaep0, 0x1.e2f2e6p0, 0x1.00717ap-1, -0x1.31cfdcp-4, -0x1.b978d4p-1, -0x1.f15446p-1, -0x1.b48972p0, -0x1.a5474ep0, -0x1.bdde8cp-3, 0x1.112b86p-6, 0x1.e661bap0, 0x1.234b2p0, -0x1.79dcp-2, -0x1.8d7154p0, -0x1.9a7302p-3, -0x1.4db06cp-3, -0x1.f1d9b6p0, -0x1.cccb24p-2, 0x1.a24158p0, 0x1.e7ce1cp0, -0x1.9599c4p0, -0x1.5e5c8cp-3, 0x1.731436p-3, 0x1.cdbe5cp0, 0x1.3a0ef6p0, 0x1.02a2bcp0, -0x1.92594cp0, 0x1.05a1dep0, 0x1.86914p-3, -0x1.a81154p-1, 0x1.b9a992p-3, 0x1.69af8ep0, -0x1.3cb20cp-2, -0x1.daf4b6p-3, -0x1.e26934p0, 0x1.64fb1p0, 0x1.12eeap0, -0x1.ac6c08p0, 0x1.ec9dcep-5, 0x1.048ceap0, 0x1.88c4c8p0, -0x1.8b8428p-1, -0x1.876a36p0, 0x1.b80fb4p-1, 0x1.cb3266p0, 0x1.d8ea26p0, -0x1.2840c8p-1, -0x1.11878cp0, -0x1.89dc4ep-1, 0x1.5c389ep-1, -0x1.c13a3p0, 0x1.1ffcfp-1, -0x1.8a9b66p-1, 0x1.38d5b8p-3, 0x1.38a4c6p0, -0x1.c74508p0, -0x1.ece884p0, -0x1.b2d50ep0, 0x1.9f525p0, 0x1.7337fap-1, -0x1.84ee3ap-3, 0x1.350c7ep-6, -0x1.de8f54p-1, -0x1.c6fbd4p-1, -0x1.2c9c28p-1, -0x1.7f8158p-3, -0x1.b8395ap-2, -0x1.b310fep0, -0x1.f27f08p-1, 0x1.adfadap0, 0x1.905862p-1, -0x1.921ce6p-6, -0x1.7cc75p-1, -0x1.ee8506p-4, 0x1.e1c1dp0, 0x1.266662p0, 0x1.64cce2p0, 0x1.2eb1f6p-1, -0x1.d5eecep0, -0x1.da203p0, 0x1.95110ep0, -0x1.ddc0fep-3, -0x1.622516p0, -0x1.2ff466p-1, -0x1.0097fep-1, -0x1.784d2ap-1, 0x1.037a9ap-3, 0x1.9ed8eep-3, -0x1.bbc99ap0, 0x1.8ca6fep0, 0x1.753824p-1, -0x1.605c1ep0, 0x1.0f7796p0, -0x1.337aaap0, 0x1.0b38dcp-1, -0x1.4712fap0, 0x1.7c9c3ep-1, -0x1.c2a044p0, 0x1.dd3222p-1, 0x1.e0a70ap-1, 0x1.0a4f14p0, 0x1.e5bdep0, 0x1.6fa1ap-3, -0x1.f56336p-1, -0x1.4fae28p0, -0x1.3f0648p0, 0x1.81b628p0, -0x1.b7667ep-1, 0x1.ae654p0, 0x1.c78262p-2, 0x1.e671b4p0, -0x1.7e46eap0, 0x1.a2a3p-1, 0x1.92178ap0, -0x1.f9cd28p-2, -0x1.bd7ba6p-2, 0x1.6e2f4p0, 0x1.3d0b2ep-1, 0x1.f434bep0, 0x1.5a60b6p0, 0x1.dca7ap0, -0x1.99b9b4p0, -0x1.a0fcc2p-1, -0x1.2a9306p0, -0x1.0035b4p0, -0x1.e375a2p0, -0x1.914674p-1, -0x1.adb772p-2, -0x1.d9904cp-1, 0x1.8425b2p-2, -0x1.65a52ep0, 0x1.d020dcp-1, 0x1.a59748p-2, 0x1.2b29bp-1, -0x1.f13a38p-1, -0x1.8143b6p0, 0x1.ff197ap0, -0x1.48198p-1, -0x1.bfcc66p0, 0x1.e37206p0, -0x1.3b195p-4, -0x1.b9e608p-5, -0x1.cf9464p0, 0x1.7f12cap0, 0x1.29f8dcp0, -0x1.e0e01cp0, -0x1.c70b8p0, 0x1.3a9b5ep0, -0x1.eaba16p0, 0x1.297b18p-2, 0x1.006d68p-6, -0x1.c92a54p0, -0x1.126d3p0, 0x1.a111e6p-3, 0x1.94418ap-1, 0x1.c59952p0, 0x1.6d6138p0, 0x1.c4537ap0, -0x1.bf152ep-2, -0x1.9bcd3cp0, -0x1.ac8098p-1, -0x1.a4b5aep-3, -0x1.b40266p0, -0x1.beb1e2p-2, 0x1.4245e2p0, 0x1.84e42ap-2, -0x1.a89e6ap-1, -0x1.e5fb3p-1, -0x1.af3d86p-1, 0x1.c628a2p0, -0x1.6f01cep0, -0x1.f7edbap-6, -0x1.7e2f78p0, -0x1.9fb424p-1, 0x1.b34ce6p0, -0x1.00a2b4p-2, -0x1.0c7094p-1, 0x1.cf77f4p0, -0x1.41f37cp-2, 0x1.846bbep0, 0x1.f032eep0, 0x1.87257p0, -0x1.96ec8ep-2, -0x1.9343f2p0, -0x1.ddbb66p0, 0x1.049222p0, -0x1.9dda4p0, -0x1.b46bf2p0, 0x1.64b648p-1, 0x1.ad0382p-1, 0x1.13d594p0, 0x1.565076p-2, -0x1.8155bap0, 0x1.afe664p-1, -0x1.227022p0, 0x1.95a6f6p0, -0x1.1dacbcp0, 0x1.2bba2p0, -0x1.ba16f6p0, -0x1.9431bcp0, -0x1.c3b286p0, 0x1.e3d3cp-1, 0x1.56b0f6p-2, 0x1.6612e6p-1, -0x1.81a19ap0, 0x1.781664p0, -0x1.896114p0, 0x1.867b6cp-1, 0x1.630b32p0, 0x1.90d412p0, 0x1.523a56p0, 0x1.0bb9cap-2, -0x1.40a81ap-1, 0x1.05b5f6p0, 0x1.59d662p-1, 0x1.3c466ap0, 0x1.d2190ep0, -0x1.811a1ep-5, -0x1.815278p0, 0x1.d43fap-1, -0x1.ef70aep-3, 0x1.9adc0ap-1, 0x1.62ab7ap0, 0x1.b634dcp-3, -0x1.fbe7d8p-4, -0x1.610b5ap0, -0x1.e5f916p-1, -0x1.b90e68p-1, -0x1.344c16p0, -0x1.94888ap0, 0x1.87728p0, 0x1.fe52aap0, -0x1.804a44p-1, -0x1.f19f14p0, -0x1.114b3cp-1, 0x1.023f9p-2, -0x1.91105p0, -0x1.b4aa02p-5, -0x1.ec92fep-5, -0x1.64dc88p-1, 0x1.130ab2p0, 0x1.34a174p-2, -0x1.ab00dp-1, 0x1.c9710ap0, 0x1.3b1ceep-1, -0x1.832778p0, -0x1.59db04p-2, 0x1.96e9f8p-1, -0x1.a131bap0, 0x1.15d50ap-5, 0x1.7ec44p0, 0x1.0e651ep0, -0x1.a7b732p-5, -0x1.2100eep-2, 0x1.70e88p0, 0x1.d77836p-1, -0x1.c179e4p0, -0x1.2e59cap-2, -0x1.61fe7p-1, 0x1.051b38p0, 0x1.709a8cp0, 0x1.3ceea6p0, 0x1.3382d2p-1, 0x1.71ce12p0, -0x1.8153eap0, 0x1.450b18p0, -0x1.b41018p-1, 0x1.2394c4p0, 0x1.1f70a2p0, -0x1.c50b48p0, 0x1.e97bc2p-1, -0x1.28f512p0, -0x1.fdb464p-6, -0x1.216cbp0, -0x1.a18df8p0, -0x1.3500fap-2, 0x1.c099p-6, 0x1.d52184p0, -0x1.8d71d4p0, -0x1.4a77e4p-1, 0x1.82befcp-1, 0x1.d12acp-1, 0x1.c1806ap-1, -0x1.fec76p0, 0x1.1b57cp0, 0x1.6c745p-5, -0x1.fb525ap0, 0x1.302332p0, -0x1.74d7a2p0, 0x1.91617ap0, -0x1.8e83f2p-1, 0x1.11f954p-1, 0x1.fb5d98p0, 0x1.82eefcp-3, 0x1.395246p0, -0x1.fa9d62p-1, -0x1.16dd72p-2, -0x1.f473c6p-4, -0x1.39edf2p-1, 0x1.9a6006p-2, -0x1.40bf3ep-3, -0x1.7527f6p-1, -0x1.756d88p0, -0x1.2d7844p0, -0x1.368042p-1, 0x1.2a809cp-1, -0x1.322f88p-2, 0x1.440f7ap0, -0x1.ca9d1p-1, 0x1.d112acp-2, -0x1.77b1d8p0, 0x1.7e5058p-1, 0x1.f82522p0, -0x1.7bf744p0, 0x1.c54f1ap-2, 0x1.665b44p0, 0x1.622448p-2, -0x1.3ca19ep-3, 0x1.c829bap-4, -0x1.28012ep-1, -0x1.b6d1bep0, 0x1.b1ece8p-4, -0x1.01bd26p-1, -0x1.803fbap0, 0x1.17c85cp-1, -0x1.2dd89ap-4, 0x1.b8b84ap-5, 0x1.606edcp-1, -0x1.b3a9a6p0, -0x1.0ffe28p-3, 0x1.e18b84p0, -0x1.ae2566p-1, -0x1.73be4cp0, -0x1.6ed502p0, 0x1.6e010ep-1, 0x1.7e807ap-1, -0x1.2d818p-5, -0x1.39a15p-4, -0x1.5297ap0, -0x1.3d1cdep0, 0x1.288128p-1, 0x1.1ff9a6p-2, -0x1.4bbfc6p0, -0x1.e63152p0, 0x1.4451f2p0, 0x1.9bae0ep0, 0x1.2d3224p0, 0x1.9a6606p0, -0x1.921e0ep-1, 0x1.9c33e2p0, -0x1.cd5b26p-1, -0x1.1afb86p0, 0x1.58122cp0, 0x1.3ec54ap0, -0x1.0dfef8p-1, -0x1.45bceep-3, 0x1.4531fcp-6, -0x1.80d52ep0, -0x1.9fd48cp-1, -0x1.93299cp-2, 0x1.4fc98ap0, -0x1.9d8016p-3, -0x1.99c878p-1, -0x1.be3868p-1, 0x1.4d7574p0, 0x1.86a1d8p0, 0x1.62f31p-4, 0x1.d3497p0, 0x1.22b1dap0, 0x1.6f9e6ap0, 0x1.fc5b42p-1, -0x1.877004p0, 0x1.402f7ap0, 0x1.017024p0, 0x1.a60cccp-4, -0x1.2db0b2p0, 0x1.5f8d76p0, 0x1.2164fap0, -0x1.4c191ap0, -0x1.3dd7bp0, 0x1.fd0e5p0, -0x1.9bf9ep0, 0x1.2003d6p-1, 0x1.524c1p0, -0x1.339c48p0, -0x1.aadd1cp0, 0x1.0144dep0, -0x1.417d52p-2, -0x1.836b22p-1, -0x1.bb1aap0, 0x1.6ada98p0, -0x1.32ab28p-3, 0x1.f4b5bap-1, -0x1.73199ep0, 0x1.3fdf0ep0, -0x1.551924p0, -0x1.6fd83ap-3, -0x1.1952e2p-1, 0x1.f82e0cp0, -0x1.3dd44ap0, -0x1.4a871cp0, 0x1.fa9798p0, -0x1.e370dp0, 0x1.b38292p0, 0x1.ebf5dap0, -0x1.97f6p0, 0x1.c2b626p-1, -0x1.7c2b52p-2, -0x1.b2f1b2p-1, 0x1.07da3p0, -0x1.5904d8p-1, -0x1.067eaep-1, -0x1.730b96p0, -0x1.7195ccp0, 0x1.990a2cp-5, 0x1.7add8ap-1, -0x1.d48278p0, -0x1.a3d734p-1, -0x1.3c1aa2p-3, 0x1.e0ec4ep-4, -0x1.7dd7eap0, -0x1.6c1feap-1, -0x1.bf966ap-1, 0x1.1b7042p-6, -0x1.d76b0ep0, -0x1.8b2ab6p-1, 0x1.ba713cp-2, -0x1.0e0feep0, -0x1.b02a96p-2, -0x1.2d417cp0, -0x1.c25ffcp-1, -0x1.df33bp-4, -0x1.c11072p0, -0x1.e190ap-1, 0x1.d427d2p-2, -0x1.b57468p-1, 0x1.01048p-3, 0x1.a2eaccp0, -0x1.8ee3d4p-4, 0x1.7bdaf4p-2, -0x1.04a7a6p-1, 0x1.21a6bp-2, 0x1.a41f1ap0, 0x1.63b2a8p-1, 0x1.6980d8p-1, 0x1.f30f0cp0, 0x1.a2cb7cp-1, -0x1.b978f2p-1, -0x1.d5174cp0, -0x1.743e7ep0, 0x1.40c2c6p0, 0x1.47a226p0, -0x1.491acep0, -0x1.9bc916p0, 0x1.fec6e4p0, -0x1.dda0b4p-2, -0x1.05ad62p0, -0x1.e2a466p-1, -0x1.f7bc32p0, 0x1.847bdap0, -0x1.89d898p-1, 0x1.aa6c4cp-2, 0x1.176504p0, 0x1.a7e00ep-1, -0x1.48dap0, -0x1.2690dcp0, -0x1.a09026p0, 0x1.5799fcp-1, 0x1.a01598p-3, -0x1.7164d4p-1, 0x1.ab9944p-5, -0x1.406974p-3, 0x1.9cc54ap0, -0x1.2b21c8p-3, -0x1.77bdfep-2, -0x1.055b1ep-2, -0x1.3bef84p-1, 0x1.9cccd4p-1, 0x1.7652ep0, -0x1.793e86p-1, -0x1.c08d76p-6, 0x1.d9738cp-1, 0x1.179d84p-1, 0x1.f884c4p-1, -0x1.ed026ap-1, -0x1.f5d1p-1, -0x1.b4b33ep-3, 0x1.b257e6p-2, 0x1.791aeep0, 0x1.095b46p0, 0x1.bbe80ap-1, 0x1.4c29d8p0, 0x1.dc162p-3, 0x1.38db18p0, 0x1.4773cep0, 0x1.2f76p-1, 0x1.67a74ap0, 0x1.735394p0, -0x1.833f08p0, -0x1.51b75ap-3, -0x1.853536p0, 0x1.36e65cp-2, 0x1.70a78cp0, 0x1.ffd2e2p0, 0x1.0eee1p0, 0x1.240ebcp0, 0x1.1b7ea6p0, -0x1.5b0c3p-2, -0x1.b81418p0, 0x1.aae7bap0, 0x1.672d9ep-1, 0x1.939c1ep0, 0x1.dc18b2p0, 0x1.58d34p0, -0x1.7a63e4p-1, -0x1.f67a9ap-1, 0x1.0675c4p-3, -0x1.46d7b6p0, -0x1.800dd6p0, -0x1.1a6bdp-3, 0x1.257258p-3, 0x1.17cd6ep-2, -0x1.01b472p0, 0x1.5fe87ep-3, 0x1.710086p-2, -0x1.e719ecp-3, -0x1.223934p0, -0x1.c2005ep0, 0x1.f0f842p-2, -0x1.444702p-1, -0x1.c0078cp-1, 0x1.8384e2p-1, 0x1.3fb818p-2, -0x1.b540ecp-1, 0x1.70c1e8p-1, -0x1.6f183ap-1, 0x1.3c925p0, 0x1.03d688p0, 0x1.a1ade2p0, -0x1.74f784p0, -0x1.3ea12ep0, 0x1.13e87cp-1, -0x1.38acb6p-2, 0x1.b1a4eap-2, 0x1.35d04p0, 0x1.d1e28ep0, -0x1.9d31eap0, 0x1.95459ap0, 0x1.762078p-3, 0x1.6b9c18p0, -0x1.f74b14p0, 0x1.8fafbcp0, 0x1.9334b2p0, 0x1.763278p0, -0x1.63f372p-3, 0x1.b21d14p-1, 0x1.483b92p0, 0x1.cd8846p-1, 0x1.a9f9c6p0, -0x1.fb6efcp0, 0x1.8b6b68p-1, 0x1.f59ed8p0, 0x1.ddaee8p0, -0x1.6b5878p0, -0x1.c1f7e4p-1, -0x1.a9d146p0, -0x1.d5db38p0, -0x1.ae176ep0, -0x1.730a46p-1, 0x1.28b33cp-1, -0x1.f6a15cp-1, -0x1.2b61d8p-1, -0x1.a81aa4p0, -0x1.8618dp-1, 0x1.84efc6p0, -0x1.8a618cp0 };
float keras_activation_3_test5_array[6] = { 0x1.955a1cp-3, 0x1.7400e4p-4, 0x1.292c28p-5, 0x1.e22a7ep-5, 0x1.2e7ee6p-1, 0x1.9ea17ep-6 };
float test6_dense_input_input_array[2622] = { 0x1.003146p-1, 0x1.50c0bp0, -0x1.5ba15ep-1, 0x1.e121eap-1, -0x1.0d14f4p0, -0x1.12802ep0, -0x1.d44ed8p-1, -0x1.b84e74p0, -0x1.b3d532p0, -0x1.839ddap-1, 0x1.16e2b8p0, 0x1.e79d6cp0, 0x1.3a2922p-2, 0x1.861044p-2, 0x1.cb8d62p-2, 0x1.517b7cp0, -0x1.acf084p-4, -0x1.8d4e5ep0, -0x1.fb8884p-2, -0x1.d6b3dap0, 0x1.633286p-2, -0x1.ec40cp-1, 0x1.3218f2p-1, 0x1.e732f2p0, -0x1.4a9f6p0, 0x1.c5fb06p0, -0x1.b95a0ap-1, 0x1.3cbf94p0, 0x1.e5b448p0, 0x1.48e0f8p-2, -0x1.414cf6p0, -0x1.3e2e12p0, -0x1.b850eep-1, 0x1.41908ep0, 0x1.1b0ddap-3, -0x1.20875ep0, -0x1.c2a95p0, -0x1.db895ep0, -0x1.477a9ep-1, -0x1.f8e5ccp-2, -0x1.4f6476p0, 0x1.23fcd8p0, 0x1.9f3a02p0, -0x1.09bb76p0, -0x1.5bcdbep0, 0x1.706c6ap-2, 0x1.e189eap0, 0x1.97ffaap-2, 0x1.52408p0, -0x1.8d3596p-2, 0x1.e3abc4p0, -0x1.7c7308p-2, -0x1.6c9cdap0, -0x1.67d30cp0, -0x1.bdba3ap-6, -0x1.5251bap0, -0x1.16d97ap0, -0x1.1ece5cp0, -0x1.a27b78p-3, 0x1.ef8f82p-1, 0x1.d46bccp-1, 0x1.f2d044p0, 0x1.978ce2p-1, -0x1.1ca84ep-1, -0x1.5a34f4p0, -0x1.4f0938p0, -0x1.84fcc4p-1, 0x1.b263acp-1, -0x1.7c74a6p0, -0x1.e385aap0, -0x1.e8362p0, 0x1.9d60d2p-1, 0x1.d86f58p0, -0x1.537fb6p-1, -0x1.01db2cp-1, -0x1.84b30cp-1, -0x1.87b37ep-2, 0x1.98dcaap-2, -0x1.ad7742p0, -0x1.36024ep-3, -0x1.b28e2p0, 0x1.d2793p0, 0x1.f086dp0, 0x1.c4baecp0, -0x1.0b184ep-4, -0x1.212abap0, -0x1.9e8508p0, -0x1.f77f9p0, -0x1.d3aee8p-2, 0x1.293c04p0, -0x1.3818dp-2, 0x1.7aed08p-2, -0x1.7e985p-3, -0x1.afd7d6p-1, 0x1.52653ap0, -0x1.f94004p0, 0x1.62dd8p-2, 0x1.b4cc64p-4, -0x1.ac1a72p-4, -0x1.71f928p-1, 0x1.8cb1e2p-1, -0x1.af935ap-1, -0x1.0559c6p-1, 0x1.0321a8p-8, -0x1.966294p0, -0x1.2f2cb2p-2, -0x1.8f798cp0, -0x1.124facp0, -0x1.e5656cp-2, 0x1.fb1822p-1, 0x1.167862p0, 0x1.2c3304p0, -0x1.b013c2p-1, -0x1.dba92cp-2, 0x1.74acbcp-3, -0x1.33cd66p-1, 0x1.031618p-1, 0x1.8ea1c8p-3, -0x1.00b876p-1, 0x1.baa09p0, 0x1.2fc99ep0, 0x1.c901fap0, 0x1.b395eap0, 0x1.4810bp-1, -0x1.f63f08p0, 0x1.dfe65ep0, -0x1.aa3d1ap0, 0x1.e3b2ecp-2, 0x1.a26852p-4, -0x1.2d80e8p-1, -0x1.248e86p-1, 0x1.36626ep0, -0x1.d53df6p-4, -0x1.ac54d8p-2, 0x1.4dbce2p0, -0x1.add742p-1, -0x1.b555c2p-4, -0x1.b1847p-4, 0x1.0d183cp0, 0x1.c42466p-2, -0x1.bff84ep-2, -0x1.52a2p-2, 0x1.ea937cp-2, 0x1.102e56p-1, 0x1.ab473ep-2, -0x1.f0738ep0, -0x1.15f146p-1, 0x1.4e48b2p0, 0x1.8ebf02p-1, 0x1.a6c91ap0, 0x1.293f4ep0, 0x1.768842p0, 0x1.3491f6p-1, 0x1.eb34aap-2, 0x1.427646p-2, 0x1.cef85cp-1, 0x1.c7c18ap0, -0x1.8eb4bcp-6, -0x1.24c77ep0, 0x1.15287cp0, -0x1.f7e36p-4, 0x1.ec5b96p0, -0x1.c5f66ap0, 0x1.0e9092p-2, -0x1.7282b4p-1, 0x1.60cebp0, -0x1.84e072p-2, -0x1.ca600ap-1, 0x1.36445p-4, 0x1.81e888p-6, 0x1.27d256p-4, 0x1.161894p0, -0x1.f9b5cep0, -0x1.12243cp0, -0x1.24c1a8p-1, 0x1.9ebab6p-6, -0x1.48c95ep-2, -0x1.b247fcp-1, 0x1.f2307p0, 0x1.a38e6cp0, 0x1.6bcb8ep0, -0x1.afb332p0, 0x1.be50a6p-2, -0x1.061e1cp-1, -0x1.b8c7b2p0, -0x1.8f71c2p-3, 0x1.337698p0, 0x1.8b9b8ap0, -0x1.6448dep0, 0x1.12ece4p-1, 0x1.a66836p0, 0x1.22a94ap0, 0x1.4d2d2p-4, -0x1.8e26e2p-1, 0x1.409abcp-4, 0x1.82319cp-3, 0x1.10c296p-1, 0x1.caab84p0, 0x1.c17e5ep-3, -0x1.cbe8ccp0, -0x1.5ddedap0, 0x1.9690c2p-2, -0x1.dedcfap0, 0x1.72b1a4p-1, -0x1.4cbb0cp-1, -0x1.9f7cbap0, 0x1.1be036p-3, 0x1.cdf41ep-1, -0x1.2ba6f8p-1, -0x1.5182a8p0, -0x1.1aef02p0, -0x1.ee64ecp0, -0x1.f77b94p-1, 0x1.892d9p0, 0x1.0b38cp0, 0x1.870ff4p-1, -0x1.3e047cp0, -0x1.1b4f94p-3, -0x1.cd1a46p0, 0x1.63ec62p-1, -0x1.6d6332p-1, -0x1.d94f94p-1, 0x1.7a8054p0, -0x1.ace3a2p-4, -0x1.16dd7ep-1, -0x1.7fd578p0, 0x1.0ab318p0, 0x1.71ad64p0, -0x1.4c8bdp0, 0x1.18bff6p-3, -0x1.a6b9eap-1, -0x1.b5efc8p0, 0x1.3567cep0, -0x1.3eb12ap0, -0x1.8a1e2cp-1, 0x1.05c8d2p-4, -0x1.65f738p-5, -0x1.d158d6p0, -0x1.516a2ap-1, -0x1.1bae84p0, -0x1.462cb2p0, -0x1.a00fe4p0, 0x1.5492fep0, -0x1.853b8ap0, 0x1.a78904p-1, -0x1.977994p-2, -0x1.f5b88p-1, 0x1.92129ap-2, -0x1.c93d4ap0, 0x1.397b54p0, 0x1.5f32ap0, -0x1.15b588p0, -0x1.e2fe76p-2, -0x1.d61b9p0, -0x1.e3f4e6p0, -0x1.1b7ebcp0, -0x1.a09d7cp0, 0x1.eafdfcp-2, 0x1.df73a2p-1, -0x1.effcbep0, -0x1.50b3fep0, -0x1.9cd936p0, 0x1.1d9b32p-5, 0x1.f2aa68p0, 0x1.7143cep-1, -0x1.fb4e7ep-1, 0x1.342becp-1, 0x1.266a06p0, -0x1.d6490cp-2, -0x1.70f2e4p0, 0x1.fa5cfap0, 0x1.8b03aap0, 0x1.a6a42cp0, -0x1.27ad44p0, -0x1.9d33ep0, 0x1.1554acp-1, -0x1.bb6d92p-1, 0x1.4d8144p0, -0x1.0cee8p-1, 0x1.19eabp-1, -0x1.9d54bep-1, 0x1.11d01cp0, 0x1.7a06f6p-1, 0x1.4f4a5ep-2, -0x1.afb4fap-3, 0x1.b188a2p0, 0x1.f5a3cap-1, 0x1.fe183ep0, -0x1.30697ap0, -0x1.55d382p0, -0x1.831032p-2, 0x1.e4765ap-1, -0x1.b3697cp0, -0x1.6bbee6p-1, -0x1.ee5d32p-1, 0x1.e6fc42p0, -0x1.fef9f8p-2, 0x1.82d006p0, -0x1.242574p-2, 0x1.231848p-5, 0x1.d5996cp-2, 0x1.a2f6f4p-2, 0x1.089a82p0, 0x1.52e57ep-2, 0x1.a98804p-2, -0x1.b53caep-1, 0x1.f35b38p-2, -0x1.5b4088p0, 0x1.0f830ap-2, -0x1.1cb8c2p0, 0x1.f97434p-2, 0x1.6e6a9ap-2, -0x1.1f667ep0, -0x1.a177dp-6, 0x1.83d63ap-2, 0x1.3d1558p-1, -0x1.f8a05p0, 0x1.24af7p0, 0x1.7faa6p-2, -0x1.550cbep-2, 0x1.159a7p0, 0x1.91d5a8p-1, 0x1.c24dbp0, 0x1.5b8ec4p0, -0x1.ceabb2p0, -0x1.7ce28cp-4, 0x1.20ead6p0, -0x1.d6e878p-1, -0x1.ae2dcep-1, -0x1.8047f4p-2, 0x1.216a42p0, -0x1.eb0ea8p-1, 0x1.1ae0b8p0, 0x1.4d18cep-4, 0x1.4bf378p0, 0x1.dde27ep0, -0x1.e1fe6ep0, -0x1.c37fccp-1, 0x1.22721ep-4, -0x1.a7a1d2p0, -0x1.a57ea2p-1, 0x1.f13974p0, 0x1.06edf2p0, -0x1.c72224p-1, -0x1.f430fcp-1, 0x1.3b4c4p-2, -0x1.9d0c9cp-4, -0x1.1fefeap0, -0x1.883098p0, -0x1.beef1cp0, -0x1.cb8332p-1, -0x1.0c6cdcp0, 0x1.e72214p-3, 0x1.559e22p-1, 0x1.f6caeap-1, 0x1.7dd5f4p0, -0x1.995b1p0, -0x1.d65456p-3, -0x1.40e85ep0, -0x1.3640eap0, 0x1.1d2e34p-1, 0x1.1fbd2cp0, -0x1.7f754ep-2, -0x1.9da618p-1, 0x1.156edp0, -0x1.3771c8p-1, 0x1.b390c2p0, 0x1.c69786p-1, 0x1.3b777p-1, -0x1.7039e4p0, -0x1.d3c028p-1, 0x1.c2c234p-2, 0x1.d1cf6ap0, 0x1.958dd4p-1, 0x1.921c12p0, 0x1.1ae2cep-1, 0x1.3fbf72p0, -0x1.e1d19ap0, 0x1.808204p-1, 0x1.bddb8ep0, -0x1.ff976ap-5, -0x1.c6eff6p0, -0x1.27a254p-1, -0x1.4cd86ep-1, -0x1.8ad788p0, 0x1.179418p-1, 0x1.d2c4d4p0, -0x1.b5756p0, 0x1.d2844cp0, -0x1.80af1ap0, 0x1.cddb7ep-2, 0x1.4adaecp-3, -0x1.4b4cb4p-1, -0x1.90d71cp-3, 0x1.8b136cp-1, 0x1.526c32p0, -0x1.56ce02p0, -0x1.3e9364p-1, 0x1.fdce4ap-3, 0x1.c97b2ep0, 0x1.9dac16p0, 0x1.a113cap0, -0x1.8609ecp0, 0x1.0b6044p-1, -0x1.4680b6p-1, 0x1.7f0232p0, -0x1.55d2a4p-1, -0x1.40b08cp0, 0x1.6142b8p0, -0x1.9c4e78p-2, -0x1.6eefd6p-1, -0x1.ce8e9cp0, 0x1.fc340ap-2, 0x1.d11d22p-2, 0x1.72393ep-1, 0x1.b6d9c2p0, 0x1.70a3cp0, -0x1.195826p-2, -0x1.aba8a8p0, 0x1.64263ep-1, -0x1.53d4fp-4, -0x1.05a69ap0, -0x1.a1e7a2p-1, -0x1.85ac68p-1, -0x1.091b86p0, -0x1.1d9f6ep0, 0x1.4faec8p0, -0x1.3e6134p0, 0x1.0dafcap-3, -0x1.90adc2p-4, 0x1.e571dp0, -0x1.8ec824p-2, -0x1.8f4a6cp0, 0x1.62d568p0, -0x1.4c90f6p-4, 0x1.0913eep-2, -0x1.bc072ap-1, 0x1.67048ep0, -0x1.0781aap-2, -0x1.0f36ecp-8, -0x1.f777e8p-4, -0x1.2096eep-4, 0x1.07463ap0, 0x1.4ad67cp-1, -0x1.e66f38p0, -0x1.ab3cd6p0, -0x1.f799b6p0, 0x1.72918cp-1, -0x1.c6ca28p-1, 0x1.1daa1p-2, 0x1.62bfbep-1, -0x1.8bbad6p0, -0x1.4e953p0, 0x1.75f8dep-6, -0x1.23561ep0, 0x1.d9e9eep-2, -0x1.4b6646p0, 0x1.11ccf6p0, 0x1.95afacp0, -0x1.406fc2p0, 0x1.63ee8ep0, 0x1.f72954p-2, -0x1.3c2472p-1, 0x1.c488cap0, -0x1.1e4982p0, -0x1.d0bc1p-1, -0x1.588e32p-1, 0x1.d6f2c6p0, 0x1.b9bbfap-1, 0x1.c4b5ccp0, 0x1.65e98ap0, 0x1.9bebbp-1, 0x1.021bbcp0, 0x1.cfdebap-1, -0x1.92828ap0, -0x1.b686f8p-1, -0x1.96982ap-4, -0x1.0fdcc6p-8, 0x1.eb3ea2p0, 0x1.23e442p-1, -0x1.7cdb7p0, -0x1.3016dcp-2, -0x1.0d1f74p-2, -0x1.1fc17ap-2, -0x1.b6c3e6p0, -0x1.d5b4a8p0, -0x1.886a26p-1, -0x1.63eddp0, -0x1.6ed1acp-4, 0x1.7cc546p0, 0x1.821204p0, 0x1.6e46a8p0, 0x1.b0719p-1, -0x1.03c108p-1, 0x1.25c596p0, 0x1.6e58dp-1, -0x1.51c3b6p0, -0x1.f769eap-2, 0x1.1d915ap0, -0x1.0376f8p-1, -0x1.33b5c4p0, 0x1.7e368cp-1, -0x1.ab9156p-1, -0x1.360644p0, -0x1.d1a708p0, 0x1.6515b8p0, -0x1.b2e0e2p0, -0x1.9d3782p-2, -0x1.1a55c8p0, 0x1.ccd16ap-2, -0x1.c208bcp0, 0x1.77c7bap-4, 0x1.ad5dp0, 0x1.f3d45p-1, -0x1.f9a4a2p-1, 0x1.1e81cp0, 0x1.0cc8bcp0, -0x1.9601e2p-3, 0x1.7e5bfcp-12, 0x1.506ec8p-1, 0x1.ae95dcp0, -0x1.624218p-2, -0x1.7118f6p-1, 0x1.b43f5p0, -0x1.3fdeaap0, 0x1.5cb57cp-1, -0x1.93c96p-4, 0x1.54d016p0, 0x1.7c69fcp0, 0x1.be1e32p-7, -0x1.7a1e78p-5, -0x1.7ac928p-1, 0x1.0e06bap0, -0x1.b88af4p-2, -0x1.179bfep-1, -0x1.4e7554p0, 0x1.b0f024p-4, 0x1.c74926p0, -0x1.f6265ap-3, -0x1.f4754ep-1, -0x1.c28628p-1, 0x1.920d08p0, 0x1.ca797p0, 0x1.7d170cp-2, -0x1.57c6fp0, -0x1.9889a6p-1, -0x1.e6f416p-1, -0x1.af231p-1, 0x1.5073a2p0, -0x1.b3ae1cp0, -0x1.4fce78p0, 0x1.52b678p0, 0x1.b7f768p-1, -0x1.8e8212p-6, -0x1.bde934p-3, -0x1.62e148p0, -0x1.4d8d58p0, -0x1.f7a7e4p0, -0x1.888e64p0, -0x1.4a3ebep-3, 0x1.34c266p-1, 0x1.05fa98p-2, -0x1.6136bcp0, 0x1.60872p-1, -0x1.c9ca0cp-4, 0x1.776bf2p0, -0x1.295256p-1, -0x1.d366dcp-3, 0x1.adaefep0, 0x1.36c67cp0, -0x1.d4f752p0, -0x1.69160ap0, -0x1.fb0458p-2, 0x1.109202p0, 0x1.328c7ap-1, -0x1.cb067ep0, -0x1.2d6d6cp0, 0x1.cbfe94p-4, -0x1.552f7ap0, -0x1.974ea4p-2, 0x1.abe2c8p0, -0x1.df567ep-1, 0x1.62f618p0, -0x1.ff27e8p0, 0x1.58bb4cp0, 0x1.74f116p0, 0x1.03a18cp-1, 0x1.56feb4p0, 0x1.ced572p-2, -0x1.f329e4p-2, 0x1.90ec6p-1, 0x1.e4e4c2p-3, -0x1.17f51ep0, 0x1.37f67cp-1, -0x1.0fa912p-1, 0x1.74dcd2p0, 0x1.f8b7b2p-5, 0x1.9cbc8p-7, -0x1.5a841ap-2, 0x1.b3cf1p0, -0x1.b8b078p0, 0x1.47535ep0, -0x1.60c39ap0, -0x1.7167e4p-1, 0x1.6a637ap-1, 0x1.76c13p0, 0x1.8d15a6p0, 0x1.237ab6p0, 0x1.c9d2a2p-1, -0x1.120dc2p0, 0x1.53b0eep-6, 0x1.c25888p0, -0x1.4e6decp0, 0x1.b0de22p-3, 0x1.a3f114p0, 0x1.0e7e36p-3, -0x1.925dfep-2, -0x1.50b06ep0, 0x1.25efaap-6, 0x1.456412p0, -0x1.339a3ep0, -0x1.29a348p-5, -0x1.a831c4p0, -0x1.d68322p0, 0x1.ff19a2p-1, -0x1.d4c672p0, 0x1.879ce4p-2, 0x1.cfd5cp0, -0x1.65665p0, 0x1.1e0caap0, -0x1.7cc04ap-1, 0x1.3148d6p0, 0x1.b7e47cp-1, 0x1.4900b6p0, 0x1.640682p0, -0x1.458f3ep0, -0x1.4a799cp0, -0x1.e2862p-1, -0x1.020e44p0, -0x1.bc4c5ap0, 0x1.82a068p0, 0x1.c3dfa4p-1, -0x1.2e70e8p0, -0x1.8bfec2p0, 0x1.770f2p-1, 0x1.a1d8f2p0, -0x1.a1349ep-6, 0x1.d36046p0, -0x1.4e56b4p-1, -0x1.fe99b2p-2, 0x1.67aee6p0, -0x1.c074p0, -0x1.2c8c58p-2, 0x1.f2346ep-2, -0x1.2b8c2p0, 0x1.29931ap0, 0x1.d691ep0, 0x1.910b1ep-1, -0x1.2f468ap-1, -0x1.d41af8p-4, 0x1.6cd0f4p0, -0x1.94798cp0, -0x1.09a44cp0, 0x1.adc09ap-1, -0x1.46d0ep0, -0x1.c6b728p-1, 0x1.61200ap-1, -0x1.77fbep-5, 0x1.41b54p-6, 0x1.95000cp0, -0x1.981ba8p0, 0x1.1404b4p-2, 0x1.b3cb08p0, -0x1.3e1a44p-1, -0x1.f830aep-1, 0x1.92d7ecp0, -0x1.e7c66ep-3, 0x1.d61734p-1, 0x1.cfc938p0, 0x1.c04544p-1, 0x1.35419ap0, 0x1.683d38p0, 0x1.4217e4p-1, -0x1.882172p-4, -0x1.45b7f6p0, 0x1.53fd74p0, -0x1.c47c34p0, -0x1.0fd05cp0, 0x1.a606ap0, -0x1.7ea2dp-3, -0x1.2efd34p-5, 0x1.d73e62p0, -0x1.6ceedp0, -0x1.8d2d1ap0, 0x1.eecadp0, -0x1.8da64p0, -0x1.62f1cep-1, -0x1.b92eb8p-1, -0x1.d32c7ap-1, -0x1.867a72p0, 0x1.9857b4p-1, 0x1.8fba28p-2, 0x1.cc8ef4p0, -0x1.6db876p-5, 0x1.01a314p-1, 0x1.6e4a5ap0, 0x1.82fa06p-6, 0x1.077b6p-2, 0x1.bf6136p-7, -0x1.6918c8p-2, 0x1.98c76ep-5, -0x1.525edap0, -0x1.6adfe2p-1, -0x1.02781p0, -0x1.d3f03ep-1, 0x1.83c9f8p-2, 0x1.d08d76p0, 0x1.78bda2p-2, 0x1.60e062p-2, 0x1.e0c40cp-1, -0x1.eca7ccp0, -0x1.53dap0, 0x1.a25e98p-2, -0x1.8f47f2p-1, 0x1.60caeap0, 0x1.d16facp-2, -0x1.1d4796p-1, -0x1.dc4a52p-2, -0x1.b34212p0, -0x1.3eac02p-5, 0x1.8a7c9cp-1, 0x1.0b48fp0, -0x1.72c89ap0, -0x1.ff8334p-1, 0x1.eb4d48p0, -0x1.876708p-4, 0x1.5af368p-3, -0x1.763252p-2, -0x1.c84f8p0, -0x1.322faap0, -0x1.0f3c22p0, -0x1.20ff4p-2, -0x1.9bad52p-1, -0x1.f93682p0, 0x1.51597cp0, -0x1.fad218p-2, -0x1.863f26p0, -0x1.4a51fap-1, 0x1.dfed26p0, -0x1.c0358p-1, -0x1.e32a6ap0, 0x1.72d956p0, 0x1.b8b5f4p-4, -0x1.911baep0, 0x1.4fe282p0, 0x1.51f28ap0, 0x1.0b29c6p-1, 0x1.fe87d4p0, -0x1.ffa762p-1, 0x1.2bb614p-1, 0x1.b33aaep-1, -0x1.28cff2p-1, 0x1.89419cp-3, 0x1.e2c05p-2, -0x1.9d7d2cp-1, 0x1.9d97dp0, 0x1.9fbb2ap0, 0x1.99b31p0, -0x1.99d142p-2, 0x1.087dbap0, -0x1.9b77acp0, 0x1.b2e766p0, 0x1.dfef32p-1, -0x1.4283b4p0, -0x1.2ed1d6p0, -0x1.f89bc6p-1, 0x1.cf6f06p0, 0x1.1cd71cp0, 0x1.2aa37ap0, -0x1.8a47b8p-1, 0x1.1c4684p-5, -0x1.5a40bep-4, 0x1.e2866ap-1, 0x1.7d1934p0, -0x1.93182ap0, -0x1.8226dp-5, 0x1.40d566p-5, 0x1.8df832p-5, -0x1.260754p0, -0x1.40a22p-1, 0x1.ad7044p0, 0x1.3c6362p-1, -0x1.50613ep-2, -0x1.20a048p-2, 0x1.69cdccp-1, -0x1.12756cp0, 0x1.e289bcp0, 0x1.9e3a3p-2, 0x1.af88c6p0, -0x1.19d854p0, 0x1.000d74p0, 0x1.0070ep-1, -0x1.c6ddd8p0, 0x1.5493bp0, 0x1.23ad9p-4, 0x1.f75416p0, 0x1.aeeaf6p0, 0x1.1ab7cap-2, 0x1.1e0e28p-1, 0x1.b441a4p-1, 0x1.92cf74p-5, 0x1.c8136p-1, -0x1.5bf572p-5, -0x1.67cdd4p-3, -0x1.874d8cp0, 0x1.17f8a6p0, -0x1.0a21c6p-2, -0x1.38ab36p0, -0x1.641866p0, 0x1.d78d3cp0, -0x1.e6c5e4p-1, -0x1.94f97ap-2, -0x1.728bfcp-3, -0x1.0337e8p0, -0x1.78a458p-1, 0x1.d8edaap-1, 0x1.52181ep-1, -0x1.3d2514p-3, 0x1.377b3p-2, -0x1.336fe2p-1, -0x1.277ap-1, 0x1.476ba8p0, 0x1.350c2cp-2, -0x1.5023b2p-1, -0x1.6a92eep-3, -0x1.6378ccp0, -0x1.e910f6p0, -0x1.36df3p-1, -0x1.6af234p-3, -0x1.2e7e3p0, -0x1.afcb44p-3, -0x1.eb7508p0, -0x1.202b74p0, 0x1.f41f9ep0, 0x1.dd991p0, 0x1.c18bep0, 0x1.5f1318p0, -0x1.8eaeacp-1, -0x1.6fec82p0, 0x1.6c080cp-3, 0x1.52e8cp-2, -0x1.c96bfep-2, -0x1.c6bbe2p-2, 0x1.2225cep-1, 0x1.421f5ap-1, -0x1.d34faep-3, 0x1.b2c87ep-1, 0x1.22dc64p0, -0x1.4653b4p-2, 0x1.e7a6cp-1, -0x1.478528p0, 0x1.6f0e22p0, -0x1.8841d8p-3, -0x1.08903cp0, 0x1.b5c956p0, -0x1.5b8de6p0, 0x1.4cf2ccp-1, -0x1.39d4f6p-1, -0x1.e815ecp0, 0x1.8da776p0, -0x1.9af19cp0, -0x1.c0fe6p0, -0x1.740182p-2, 0x1.e96d62p-2, 0x1.8d4d38p-1, 0x1.1b3cdcp-1, -0x1.e71522p0, 0x1.0a416cp0, -0x1.4292d6p0, -0x1.952b54p-1, 0x1.38a7c2p-1, -0x1.ad743ep0, -0x1.966e54p-2, 0x1.ced086p0, 0x1.8ba04p0, 0x1.74dedcp-1, 0x1.4e8f5ep0, 0x1.392c82p0, -0x1.31b9c2p-1, 0x1.13c87ap0, -0x1.557504p-1, -0x1.c8b524p-1, 0x1.90c68p-3, -0x1.39700ep-1, 0x1.07ea4ep0, 0x1.08decap0, -0x1.4dcacap0, -0x1.93792ap-1, 0x1.8744ep0, 0x1.570602p0, -0x1.f9f77p0, -0x1.e4943cp0, 0x1.2a59dcp-1, -0x1.5697e2p-5, -0x1.5a2a44p-6, 0x1.c1b3aap0, 0x1.15fe0ep0, 0x1.a388fp0, 0x1.e5e284p-1, 0x1.9e17dep0, 0x1.38e896p-3, -0x1.4aec66p0, -0x1.b9c062p-2, -0x1.820b2ap-1, 0x1.9e195ap-1, 0x1.fa6006p-1, 0x1.763d3p-2, -0x1.7d80ap0, 0x1.a3a2cep-1, 0x1.22a492p0, -0x1.a5863ap-1, 0x1.f578bep-1, -0x1.1a4dcep-2, -0x1.5b0d7p0, -0x1.dc2968p0, -0x1.a08facp0, -0x1.106b4ap-3, 0x1.b19cd4p-2, -0x1.d59776p-1, 0x1.e47738p0, -0x1.1a9a02p0, -0x1.b624b8p0, -0x1.ef1fd4p-4, 0x1.857e58p-2, -0x1.8e8424p-4, -0x1.1246f6p-2, -0x1.c3ae9ep0, -0x1.85d978p0, -0x1.b3f30ap0, 0x1.316886p-1, -0x1.b4e2c6p-2, -0x1.9a0b4cp-1, -0x1.f27e6p-1, 0x1.21f588p0, 0x1.4b66e8p0, 0x1.e12b26p0, -0x1.2e06aep-2, -0x1.4a05ap-1, 0x1.d0b47ep-1, 0x1.0171e8p-2, 0x1.ad7d44p0, -0x1.7aad14p-4, 0x1.fc317ap0, 0x1.7eb672p-1, -0x1.0ef94p-1, 0x1.741536p-2, 0x1.135c36p0, 0x1.2d1f0cp-1, -0x1.4d8cfep-1, 0x1.e6f5e4p0, -0x1.33469ep0, 0x1.5fc6b2p-3, -0x1.4ab896p-5, -0x1.e1692cp0, 0x1.9767d6p0, -0x1.5d0cap-1, 0x1.f3063p0, -0x1.ddadfp-1, -0x1.dbd878p-1, 0x1.4eec34p-2, -0x1.efd0d2p0, 0x1.4e5772p-1, 0x1.dd8f92p-4, -0x1.ad1526p-1, 0x1.b35012p0, -0x1.3780f2p-1, 0x1.c5e81ap-1, 0x1.b5cc5p-2, 0x1.c99b1p0, -0x1.58969p-1, 0x1.816fd2p0, 0x1.580d36p0, 0x1.3e301cp-1, -0x1.cf5f54p0, 0x1.d85904p-1, -0x1.0bbcf8p-1, -0x1.1edb72p0, -0x1.cd369cp0, 0x1.8c8606p-1, 0x1.b06902p0, 0x1.5c9decp0, -0x1.7bb75cp0, 0x1.e50c46p0, -0x1.58acdp0, -0x1.eac17p0, 0x1.bf9d94p0, 0x1.7cb48p-2, 0x1.0030bp0, -0x1.fdb852p0, -0x1.1e820ap0, 0x1.e19ce6p-1, 0x1.8561cap0, -0x1.9b173cp-6, 0x1.9b198cp0, -0x1.516638p0, -0x1.a1f73ap-1, -0x1.869d64p0, -0x1.24a4b4p-1, -0x1.91cf9cp0, 0x1.55e504p0, -0x1.24150cp-3, -0x1.b7a56ap0, 0x1.696708p0, -0x1.1aa02ap0, -0x1.619408p0, -0x1.3dc496p-1, -0x1.0fcc5p0, 0x1.96f65ep0, -0x1.3e75e6p0, -0x1.9afd9ep-2, 0x1.0505fap-1, -0x1.d18e82p0, 0x1.db0df8p0, 0x1.f33348p-2, 0x1.4e850ap0, -0x1.8f8f1cp-5, 0x1.46702cp-3, 0x1.8a4542p-3, 0x1.9b0d86p0, 0x1.44e118p0, 0x1.e0f99ap-2, -0x1.5f6936p-3, -0x1.cd7e28p0, -0x1.7151bp0, 0x1.85bab2p0, 0x1.48ae24p-1, -0x1.a33b8p-3, -0x1.20a0dep-1, -0x1.2153bp0, -0x1.b90a5ep0, 0x1.b52dd8p-4, -0x1.89e74p0, -0x1.9ba334p0, 0x1.f98aa2p0, 0x1.eb4e66p0, -0x1.3bc00ep-1, -0x1.12b864p0, 0x1.f15eep-3, 0x1.4b3f4p0, -0x1.89b35p-2, -0x1.1d482ep-5, -0x1.fd986cp-1, 0x1.fe2d08p-1, 0x1.2546f4p-1, 0x1.b73142p-1, -0x1.147c56p-3, -0x1.90378ep0, -0x1.f3437p-1, 0x1.5754e8p0, -0x1.80803p-2, -0x1.1db93p-1, 0x1.7239dp0, -0x1.20919ap0, 0x1.f90b2ap-2, -0x1.2e6224p0, 0x1.4583p0, 0x1.98d2d2p0, 0x1.9cbb32p0, 0x1.8aa1bcp0, 0x1.4d47acp0, -0x1.e641b2p0, -0x1.033a9ep0, 0x1.d03068p0, 0x1.86932ap-1, -0x1.693eep-1, 0x1.9ed034p0, -0x1.e94766p-1, -0x1.6ab01ap0, 0x1.829b7p0, 0x1.c2cdfp-3, -0x1.eae384p0, 0x1.2a2468p-2, 0x1.d45cb2p-3, -0x1.2af97cp-1, -0x1.a492dp-5, 0x1.d71abcp0, 0x1.4176fcp-1, -0x1.29769cp-3, -0x1.6aa876p0, 0x1.b79f4ap0, -0x1.acdcecp-4, 0x1.53647p0, -0x1.f169dp-6, 0x1.4c001ep-2, -0x1.461134p0, 0x1.b8cd9p-2, 0x1.2020fep0, -0x1.83cf94p0, -0x1.38e888p-3, -0x1.f09582p0, 0x1.7d6704p-5, 0x1.a8123ep0, 0x1.05c3c2p0, 0x1.d6b83cp0, 0x1.8834cap0, 0x1.b1f8f4p-7, 0x1.2fd2e8p-1, -0x1.77bcf2p0, 0x1.f5c9d6p-1, 0x1.ce4c36p0, -0x1.d3390cp0, -0x1.8e2aeep-2, 0x1.7ed87ep0, 0x1.e582fep0, 0x1.b9065ep0, -0x1.a30366p-1, 0x1.a97e9p-5, 0x1.14e502p-1, 0x1.0c52ecp0, 0x1.e50368p-2, -0x1.87d80ap0, 0x1.21bd48p0, 0x1.272da4p0, 0x1.78680ep-2, -0x1.c0a134p-2, -0x1.46c678p0, -0x1.c1c324p0, -0x1.353ee6p-1, 0x1.9cf522p0, -0x1.26d86cp-2, -0x1.3c340cp0, 0x1.a7f64ap0, -0x1.ce82c2p0, 0x1.27b1dap0, 0x1.abb3a2p0, 0x1.780724p-8, 0x1.aabe2ap-1, 0x1.1d8026p-1, 0x1.8fb25p-1, -0x1.65c4b6p-1, -0x1.a2c64p-1, 0x1.244564p-2, 0x1.889196p0, 0x1.ee3f56p-7, -0x1.70e33ep0, 0x1.9174f6p0, 0x1.2ade18p0, 0x1.a7219p-2, -0x1.1e124ep-2, -0x1.a38aa2p0, 0x1.e9c1aep-2, 0x1.33d57ep0, 0x1.3df334p-1, -0x1.1c0f9ap0, 0x1.ec7f9cp0, 0x1.cc904ep-1, 0x1.a0bd5ap0, -0x1.5cef54p-1, -0x1.9f3774p0, 0x1.f954e2p-1, -0x1.5677dap-1, -0x1.661f92p-2, 0x1.5ca9fep-1, 0x1.381fep-1, 0x1.879b3ap0, -0x1.4c7b5ap-3, 0x1.335574p0, 0x1.fc4e94p0, 0x1.cdbd5ep0, 0x1.420876p-1, 0x1.05b466p0, -0x1.ff6e68p-1, 0x1.ca1c4p-1, -0x1.47533p-2, 0x1.88a4a6p-1, -0x1.0bb79cp-2, 0x1.70669ep-4, 0x1.5cfde6p0, 0x1.d1e65ap0, -0x1.7eeacep0, -0x1.4b98cap-1, 0x1.e825f6p0, -0x1.57578p0, -0x1.d13d04p0, 0x1.c4ea58p-1, 0x1.69016ep0, -0x1.cf6222p0, -0x1.fe935ap0, -0x1.67d626p0, 0x1.f5b37cp0, -0x1.6dc288p-2, 0x1.984e0cp-1, 0x1.1ef39p-1, 0x1.309a2p0, -0x1.ec53ep-2, -0x1.c9c8cp0, -0x1.44fd64p-1, 0x1.954ec4p-6, 0x1.53cca6p0, -0x1.337414p0, 0x1.8c917cp0, -0x1.4eee06p0, 0x1.ad0414p-1, 0x1.82469ep-2, -0x1.0a0804p0, 0x1.6d6f9ep0, -0x1.21ed42p0, -0x1.d589dcp-3, -0x1.cd8e46p-1, -0x1.704e3ap-1, 0x1.3a3a8p-5, 0x1.03c7eap0, -0x1.c9eaf4p-1, -0x1.29c7e2p0, 0x1.daa298p0, -0x1.9f87bcp0, -0x1.e2557p-1, 0x1.5ad8cep-1, -0x1.866856p0, 0x1.865224p0, -0x1.3f53a4p0, -0x1.259cc6p0, 0x1.7c21fp-2, 0x1.1327fap0, 0x1.de83f4p-3, -0x1.e1e814p0, 0x1.64763ep0, 0x1.00b628p-1, -0x1.4c655ap-1, -0x1.2c790cp-2, 0x1.830efp-1, 0x1.c7acf2p-1, -0x1.1f6a6ap-1, 0x1.b76c94p0, -0x1.d4954cp0, 0x1.1275acp-2, 0x1.49c3b6p0, -0x1.1b97ccp0, 0x1.39df2ep-2, 0x1.0eb496p-1, 0x1.c26b6cp-1, 0x1.cc77d8p-3, 0x1.406e3cp0, -0x1.79d81p0, -0x1.7c6ef6p0, -0x1.cd862p-1, 0x1.6d917cp0, -0x1.390dbap0, 0x1.60f968p-1, -0x1.001dc8p-2, 0x1.d5c9f4p0, 0x1.4f507ap-2, -0x1.6b09dap-2, 0x1.56cb1cp-2, -0x1.acf3c6p0, 0x1.2f9c38p-2, 0x1.4cc174p-5, 0x1.d7ca98p0, -0x1.c76a54p0, -0x1.028a8ep0, -0x1.3d75d2p0, -0x1.2b8df4p0, 0x1.d57322p-2, 0x1.07f694p-1, -0x1.56167ap-3, -0x1.33ab14p0, 0x1.2ea6cp-1, -0x1.120c64p-1, -0x1.25792cp0, 0x1.bbb8dep0, 0x1.8c1ec2p0, -0x1.d3ecf4p-1, 0x1.59f63ap-1, 0x1.a55d22p-1, -0x1.b1a886p0, -0x1.68052p0, -0x1.539bdep-1, 0x1.3477c2p0, 0x1.d33cdcp0, 0x1.94a8cep0, 0x1.f2ab6ap0, 0x1.cd9f9cp-2, -0x1.5fbd58p0, -0x1.9057c4p-1, 0x1.de7f0ap0, 0x1.616e64p0, -0x1.cbe2dep-4, -0x1.6fe4b4p-1, 0x1.0ad8e2p0, -0x1.0332c2p-5, -0x1.34bde8p0, -0x1.907f02p-4, -0x1.57c96cp-8, 0x1.9d1904p-5, -0x1.ed6478p0, 0x1.4ea95p-5, 0x1.e3847cp0, 0x1.0ebe2ep0, -0x1.1c022cp-4, -0x1.49f292p0, -0x1.2e2906p-2, 0x1.95491ap-2, 0x1.0eaac8p0, -0x1.771b8ep-1, -0x1.ec8a7ep0, -0x1.8d6d58p-9, 0x1.45bdd2p-3, 0x1.331368p-2, -0x1.c9e8aap-2, 0x1.5002fap-1, 0x1.0572bep-8, -0x1.f4851ep0, 0x1.9b680ep0, -0x1.579b12p0, -0x1.138e4cp-7, 0x1.fef63p0, -0x1.26890ap-1, -0x1.79a6c6p-1, 0x1.229e14p0, -0x1.cce22cp-4, -0x1.dfaa64p-3, 0x1.eb31d2p-3, 0x1.18d10cp0, -0x1.c50934p-2, 0x1.964f48p0, -0x1.73fbbp0, 0x1.dbaf2ep0, -0x1.950054p-1, -0x1.6aba94p0, 0x1.e8b51ep0, -0x1.2bf5c4p0, -0x1.851968p0, -0x1.92ec74p-4, 0x1.a525cp0, -0x1.1d615ap-1, 0x1.58810ep-1, 0x1.72ca8ap0, -0x1.75cfc4p-1, 0x1.c8fbdap-3, 0x1.bcb546p0, 0x1.a4ecdcp-2, -0x1.23bb3cp0, -0x1.dee80cp0, -0x1.9ae4f2p0, -0x1.db7e6ep-2, -0x1.b7033p0, 0x1.5dcdfcp-1, -0x1.5d4b82p0, 0x1.10649ep0, -0x1.80f13cp-1, 0x1.6d4fp-1, 0x1.86507cp0, -0x1.d23fbp-5, -0x1.9f77fcp-2, -0x1.e4e33p0, -0x1.29778cp0, 0x1.cf4fccp-2, -0x1.d59234p-1, 0x1.bde6d4p-1, 0x1.e4ea7ep0, 0x1.8b1e68p0, -0x1.11eb9ap0, -0x1.121056p0, -0x1.7962ecp0, 0x1.936a22p-1, -0x1.b0b1cap-2, -0x1.af4a8ap-1, -0x1.b2d434p-1, 0x1.1ac5eep-1, 0x1.0369c6p-4, -0x1.71b1f4p0, 0x1.272b54p0, -0x1.203998p0, -0x1.49e69ap-1, 0x1.25420ap-1, -0x1.e7e256p-1, 0x1.51d3b6p0, 0x1.dd12a8p0, -0x1.b5418cp-1, 0x1.55fdd2p-1, -0x1.91aee6p-1, -0x1.a3e98cp0, 0x1.7d8634p-2, -0x1.aac3d8p-3, -0x1.8a514ap-1, 0x1.0c41dap-2, 0x1.7bb512p-2, -0x1.056694p-2, 0x1.0148cp-2, -0x1.577516p0, 0x1.23f68ap-1, -0x1.eb8ecp0, 0x1.f29e1ep0, 0x1.7fce7cp0, 0x1.a5c01ep-1, -0x1.fd30cp0, -0x1.62666p0, -0x1.5cf978p-4, 0x1.48c8p0, 0x1.9691dp0, -0x1.611d4ap0, 0x1.f19aaep0, 0x1.8f5882p-4, -0x1.2b5ddap0, 0x1.237026p0, 0x1.eaf3e8p0, -0x1.35f2aep0, -0x1.12e89ep-7, -0x1.1a3458p-4, 0x1.d26ee2p0, -0x1.29538ep0, 0x1.4705e8p-2, 0x1.629efcp0, 0x1.0200bep-1, -0x1.13a072p0, 0x1.6f0adap0, -0x1.5c3eb6p0, -0x1.ae692ap0, -0x1.cc77f6p-1, 0x1.1eb1c4p0, -0x1.5a3352p-1, -0x1.700e8ep-2, 0x1.ba66f8p-1, 0x1.59bf74p-1, 0x1.488668p0, -0x1.b3e63p-1, 0x1.0cef82p-6, 0x1.0f6e8cp-3, -0x1.25402p0, -0x1.560d24p-1, 0x1.5edeaap-4, 0x1.1cfdb8p0, -0x1.107df4p0, -0x1.c72f2ep-2, -0x1.fde222p-1, -0x1.abba7ap0, 0x1.003d82p-4, -0x1.f9b434p0, 0x1.713ab4p0, 0x1.9d71bcp0, 0x1.f944dp-3, 0x1.ee392p0, -0x1.d127eep-1, -0x1.e54f7p-3, -0x1.60803cp0, -0x1.2ee6fep0, -0x1.6e80aap-1, 0x1.c187fcp0, 0x1.356p0, 0x1.f90f62p0, -0x1.8e7248p-4, 0x1.07ef7ap-3, 0x1.7be75p0, 0x1.b044cap0, 0x1.cee32p-2, 0x1.a5b306p0, -0x1.f95eeep0, 0x1.f2986ep-2, 0x1.2730cap0, 0x1.579fe6p-1, 0x1.73d5f4p0, 0x1.bcd0f4p-1, -0x1.03b3p-1, 0x1.1906b4p-4, 0x1.05358p0, 0x1.5126c4p0, -0x1.8b93ecp0, 0x1.020fa2p-3, 0x1.26d74cp0, -0x1.a4f53ep-1, -0x1.745a2ep0, 0x1.e84448p-1, 0x1.6a7e4p0, 0x1.71a984p0, 0x1.48aecp0, -0x1.48f0cep0, 0x1.6c0bc6p-1, -0x1.383438p-2, -0x1.a8c9eap-4, -0x1.c0a35ep0, -0x1.f37f6ap-4, -0x1.045214p-3, 0x1.6170ep-5, 0x1.0a5d9p-1, 0x1.5d46e6p-1, 0x1.4b3fccp0, 0x1.eacb48p-5, -0x1.0666fp0, -0x1.5ba666p0, 0x1.8062dap-2, 0x1.137c0cp0, 0x1.c4965cp-1, -0x1.1b758ep-1, -0x1.8f8bcep-1, -0x1.88002cp0, 0x1.299a2ap-2, -0x1.a1052ep0, -0x1.07c708p0, 0x1.fcaee4p-2, -0x1.65defp0, -0x1.463f9ep0, -0x1.c5b136p-1, 0x1.8048p0, -0x1.33bcd6p-2, -0x1.820ee6p-1, -0x1.d85f9ap-3, 0x1.81ef8cp0, 0x1.b9129ep-1, 0x1.82ce68p-1, -0x1.62d92ep-1, 0x1.28f68ap0, -0x1.69165ep-3, -0x1.54914ap0, -0x1.9db03ap0, -0x1.ffc2bap-1, -0x1.f66f1cp-1, -0x1.7c742cp0, -0x1.2f814ap0, 0x1.5dbf44p0, 0x1.4b3decp0, -0x1.545f54p0, 0x1.14c08ep-1, 0x1.40d0fp0, 0x1.767a72p-1, -0x1.fd6d8p0, 0x1.7c5d34p-2, 0x1.c3d85ep-2, -0x1.4021bcp-1, -0x1.138f6p-1, 0x1.dba576p0, 0x1.0f55fep-3, 0x1.cd9a3cp0, -0x1.d6317cp-3, 0x1.72b58ep0, -0x1.67294ep-5, -0x1.3a00a6p0, -0x1.3ab0c6p0, 0x1.ce4638p0, -0x1.c20c6ep0, 0x1.5d9772p-2, -0x1.e08fd8p0, -0x1.c77b48p0, 0x1.6608c6p-3, 0x1.80dc82p0, 0x1.19c0c6p-2, -0x1.2cf224p0, 0x1.7454bap0, -0x1.aabe02p-4, -0x1.875c1p-2, 0x1.677dd4p-6, -0x1.0cd6a8p-2, 0x1.8e4b8p0, 0x1.6d2a4p-1, 0x1.15bc16p-1, 0x1.f5df5cp-2, -0x1.7f9c82p-1, -0x1.b0a7ap-1, -0x1.b488eep-3, -0x1.fa9caep0, 0x1.0135bcp-1, 0x1.5e4634p0, 0x1.ab6668p-2, -0x1.be812p-1, -0x1.a8d444p-1, 0x1.c5ac54p0, 0x1.9c82b2p-1, 0x1.9dea54p-1, 0x1.3624e6p0, -0x1.cd2ffcp0, 0x1.8114fep0, 0x1.ed06bep0, 0x1.7f1a02p-1, 0x1.583c2ap-1, 0x1.fecb02p-2, -0x1.2a23ep-1, -0x1.5e8716p-2, 0x1.43e466p-1, 0x1.0196dp-2, 0x1.d95014p-1, -0x1.24f588p0, -0x1.119158p-2, 0x1.15452ap-5, 0x1.59638ap0, -0x1.5166b4p0, -0x1.b46768p0, 0x1.a36e6ap-3, -0x1.eaddfap-3, 0x1.282cd2p0, 0x1.b6b5a2p0, 0x1.d012d4p-2, -0x1.402becp0, 0x1.0b84ecp0, 0x1.31aaa8p0, 0x1.b7db82p0, -0x1.7f3deep-3, 0x1.c5c5b8p0, -0x1.524642p-7, 0x1.bc3f6p-1, 0x1.33a7ap0, -0x1.e32ecap-2, -0x1.3970f2p0, 0x1.4b52a6p-2, 0x1.0a3b6ap0, 0x1.6050eep-2, -0x1.c70f52p-2, 0x1.a90282p0, -0x1.5c0eb6p0, 0x1.e8de8ap-1, -0x1.ddff58p-1, -0x1.24f0a6p0, -0x1.c4b4eep-1, 0x1.59fd1ep0, -0x1.e4083ep0, -0x1.b6b6e6p-1, -0x1.b3fdccp0, -0x1.5a832p0, -0x1.2975f6p0, -0x1.48e6f4p0, 0x1.55f5aep-1, 0x1.34dce8p-1, -0x1.d0014cp0, -0x1.46fc86p0, 0x1.458d92p0, -0x1.1ddafep0, -0x1.92610ap-1, -0x1.e9e52p0, -0x1.9bd5bp-1, 0x1.c4817cp0, 0x1.3bdb0ep-2, -0x1.8c98eap-1, 0x1.0588fcp0, 0x1.2a10d2p-1, 0x1.6bf882p0, -0x1.45d64p-2, -0x1.38c83ep0, -0x1.7bbdf2p-4, -0x1.beec06p0, -0x1.3d8d42p-6, -0x1.046354p0, 0x1.42ee64p-1, 0x1.93b51ap-1, 0x1.848ff6p-2, 0x1.c4bcc4p0, 0x1.426a42p0, -0x1.e34e3ap0, -0x1.a67b3ap-5, 0x1.787c8ep-4, -0x1.18cba6p-1, -0x1.1c0a32p-3, -0x1.dcf7d4p-1, 0x1.9d0f82p-1, 0x1.86f15cp0, 0x1.78020ep0, 0x1.30dde6p-2, -0x1.44c77ep0, 0x1.ba1486p-1, -0x1.a1cb1ap0, -0x1.327f66p0, -0x1.68447ap0, -0x1.473ed6p0, 0x1.4494e6p-2, 0x1.e18d24p0, 0x1.d6405cp0, -0x1.f45a4p0, 0x1.08c95cp0, 0x1.bc85eep0, 0x1.f46f5ep0, 0x1.f2c51p0, -0x1.34d74p-3, 0x1.235662p0, 0x1.2da08cp-1, -0x1.d56ee6p0, 0x1.629d52p0, 0x1.970318p-4, 0x1.c0387ep0, -0x1.8373aep0, 0x1.1e19a8p0, 0x1.c21a54p0, 0x1.b3dbbcp-1, -0x1.c1a68p-1, 0x1.9f1d2cp0, 0x1.bc2bep-4, 0x1.7fbb96p-1, -0x1.767c08p0, -0x1.1d399ep-2, 0x1.d48a6p0, -0x1.a9601cp-2, -0x1.fe69c2p-1, 0x1.1ffd82p0, 0x1.6a892p-1, 0x1.ad90c4p0, 0x1.5f946cp-2, 0x1.e4cc0cp0, -0x1.cbb302p0, -0x1.e0a582p0, -0x1.ed043ep0, 0x1.262eap-2, 0x1.6c4d42p0, -0x1.3a7456p-4, -0x1.ab1a1p-3, 0x1.174eccp-1, 0x1.30e21cp-3, -0x1.6834e2p0, 0x1.14d398p0, -0x1.eef39ap-3, -0x1.800c36p0, -0x1.3a2b82p-1, -0x1.8afabp-1, -0x1.8c2ed4p-6, -0x1.f0528ep-1, 0x1.8fe3dcp0, 0x1.8393d4p0, 0x1.59301cp-1, -0x1.8197fap0, 0x1.1ef992p0, -0x1.85f6bep0, 0x1.95dfccp-1, -0x1.1629aap-1, -0x1.3b0332p-1, -0x1.951e8cp0, -0x1.07838p-1, -0x1.dfe0aap0, -0x1.6cf742p-10, -0x1.aca14p-1, -0x1.0217eep0, -0x1.e1975p0, -0x1.5b1722p-1, -0x1.06c31ep-1, 0x1.26c432p0, -0x1.0a27eap-2, -0x1.886db2p-1, -0x1.e354ccp-1, -0x1.1225b2p-1, -0x1.b496dcp-1, 0x1.6f8a56p0, -0x1.64b04cp0, -0x1.272148p0, -0x1.ee1a8p0, -0x1.0f7c66p0, 0x1.324222p-2, -0x1.d235e6p-6, 0x1.f27e6p-4, -0x1.8cfcc2p0, -0x1.ef69ccp0, 0x1.b41856p0, -0x1.b0663ap-1, 0x1.882076p0, 0x1.99adc6p0, -0x1.d8a2bcp-1, 0x1.96f95ep-1, -0x1.89f88p0, 0x1.966e72p-4, -0x1.66739p-4, 0x1.7d07ecp-3, -0x1.3f0e88p-1, 0x1.77117cp-1, 0x1.0290ep-2, 0x1.d72c72p-1, -0x1.050d12p0, -0x1.10b56cp-1, -0x1.c91acp-4, 0x1.5b5c28p-2, 0x1.a29396p-1, 0x1.6c12fep0, -0x1.a31d36p0, -0x1.35c662p-1, -0x1.442fb4p-1, 0x1.01108p0, 0x1.1d212cp0, -0x1.a76f28p-1, 0x1.2631fap0, -0x1.8601dep-1, 0x1.8e0b46p-3, 0x1.0b0ccap0, 0x1.e6cb98p0, 0x1.6d2c26p-1, -0x1.97ab68p-1, 0x1.dc44bcp-2, -0x1.d9a534p-2, -0x1.61b2e6p-1, -0x1.a5893p0, -0x1.aacbbp0, 0x1.4fd18ep0, -0x1.cb776ep-1, -0x1.5ab964p0, 0x1.cb96eep0, -0x1.652548p0, 0x1.ead934p-1, -0x1.1b87d4p-2, -0x1.f92cb4p0, 0x1.b8d99p0, -0x1.67bc2ep0, -0x1.eed05ep-1, -0x1.27085ep-2, -0x1.47f6b2p0, 0x1.781674p0, 0x1.e0a2p0, -0x1.cf1062p0, -0x1.eabef2p-3, -0x1.20b0a6p0, 0x1.34bf8cp-3, -0x1.01a93ap-3, 0x1.0dfad8p-2, 0x1.dd31acp0, 0x1.a46ad4p0, 0x1.3956d4p-1, 0x1.aa6c4p-1, -0x1.6d512ap0, 0x1.b66c44p-1, -0x1.48fd34p-3, 0x1.1de1dcp0, 0x1.5550a6p-3, 0x1.b43872p0, -0x1.57e14cp0, 0x1.915744p-4, -0x1.1a0bbp-2, -0x1.b1927ep0, 0x1.1b497ep0, -0x1.7288d2p-3, -0x1.e62796p-1, 0x1.9686a2p-3, 0x1.5f13fap0, -0x1.5cc8e4p-1, -0x1.1442a6p0, 0x1.145f2ap-3, 0x1.ebfa0ep-3, 0x1.63cdp-4, -0x1.378602p-1, -0x1.f7727cp-1, 0x1.611cfp0, -0x1.93f7bep0, -0x1.b7a718p-3, -0x1.14ef9p-3, 0x1.280818p-4, 0x1.57aed6p0, -0x1.e3713ep-3, -0x1.42ded6p0, -0x1.f91796p0, -0x1.8a44p0, -0x1.cbfd1cp0, 0x1.876588p-2, -0x1.428048p0, -0x1.9e74d4p-5, -0x1.d1fb84p0, 0x1.fddc64p-1, 0x1.e9fd56p-1, -0x1.714e5ap-3, -0x1.b68876p-3, -0x1.75251cp0, 0x1.86197cp0, -0x1.32e2ccp-3, -0x1.7447bp0, -0x1.3b9c12p-1, 0x1.faa0f2p-1, 0x1.2c87a8p0, 0x1.abad78p0, 0x1.9c34d8p-1, 0x1.3b6e66p0, -0x1.cf1e48p0, -0x1.083a24p-1, -0x1.72567cp-3, 0x1.a4689ep0, -0x1.43c20ep0, 0x1.af334ep0, -0x1.403e02p-3, -0x1.750516p-1, 0x1.dacfe4p-2, -0x1.3cf3fp0, -0x1.ae6ed8p-2, 0x1.72359p-3, -0x1.12967cp-2, 0x1.cac03p0, -0x1.752f86p0, -0x1.c26f98p0, 0x1.510fd8p-2, -0x1.11bc42p0, 0x1.5b807ap-1, -0x1.386366p-2, 0x1.7a3b44p-6, -0x1.1c77d2p0, 0x1.360cd4p0, -0x1.e1b26cp0, -0x1.88f91ep0, 0x1.525ffcp0, 0x1.563bb4p-1, 0x1.f4c348p0, 0x1.cd4158p0, -0x1.c64734p0, -0x1.afb304p-3, -0x1.1e6d92p-1, -0x1.0a2a56p0, 0x1.93a5fap0, -0x1.a27edcp0, -0x1.ce561cp-2, -0x1.9bb47ep0, -0x1.91642p-1, 0x1.3f10dap0, -0x1.c1d1aap0, -0x1.f0dee8p-1, 0x1.34f102p-1, 0x1.37818cp0, 0x1.481096p-1, 0x1.50b512p-1, 0x1.2bcc88p-1, 0x1.c3ace2p0, -0x1.ab5a78p0, 0x1.54e274p-1, -0x1.d5891cp-8, -0x1.02f678p-1, 0x1.c819c6p-1, 0x1.0a9c66p0, -0x1.28fcdap-1, 0x1.11e2d8p-2, -0x1.a2a1ap0, 0x1.c008d6p0, -0x1.23f1c6p0, 0x1.c95facp-2, -0x1.e38938p0, -0x1.1c9a0cp-1, 0x1.5d5f66p0, -0x1.408366p-1, -0x1.090012p-1, 0x1.873142p0, 0x1.f7bb82p0, 0x1.f87abcp0, -0x1.684cacp0, 0x1.5ebf88p-1, 0x1.30f402p0, -0x1.a63072p-3, 0x1.3b1014p-2, -0x1.aa0298p0, -0x1.631a78p0, -0x1.6a4268p-1, -0x1.0c12cp0, 0x1.7f8eb4p0, -0x1.a597c2p-1, 0x1.60658p0, 0x1.2293aep-5, -0x1.c412dcp-1, -0x1.46652p-1, -0x1.cdeac4p-2, 0x1.3f079ap-5, 0x1.4e0acp0, 0x1.b1f95ep0, -0x1.d1b81p0, -0x1.8c98f4p0, 0x1.3434eep0, 0x1.8a53dep-3, 0x1.4aaac2p0, -0x1.72fd7p-1, -0x1.491a58p-3, -0x1.10c284p0, -0x1.81181ep0, 0x1.45a86cp0, -0x1.0a925ap-1, 0x1.bc8d86p-2, -0x1.e2258ap0, 0x1.ed856ep-2, -0x1.defe66p-1, -0x1.38f14ep0, 0x1.3bd9acp-2, -0x1.859ffap-1, 0x1.1d0012p-1, 0x1.1a8528p-1, -0x1.9e1a66p0, -0x1.a1de86p-3, 0x1.9a2166p0, -0x1.64fd2p-1, 0x1.38eba6p0, -0x1.365528p0, 0x1.2813fp0, -0x1.370764p0, 0x1.a0470ap-1, 0x1.fc7b16p-1, -0x1.f227a2p0, -0x1.3db36ep-1, -0x1.899c74p-2, 0x1.723618p0, 0x1.61ee96p0, 0x1.288aa4p0, -0x1.45bc94p-2, 0x1.1cad62p-1, -0x1.7615dep-2, -0x1.de71f6p0, -0x1.54b916p0, -0x1.f592cep0, -0x1.3a6c62p-3, -0x1.a81ca6p0, 0x1.9e9feep0, -0x1.d04508p0, -0x1.b02768p-2, -0x1.79cbd8p-1, 0x1.b0b3fcp0, -0x1.7dfa2ep0, -0x1.ce8e64p0, -0x1.05759p0, -0x1.7606e4p-2, 0x1.c5baa6p0, -0x1.6ad98p-2, 0x1.13532ep-1, -0x1.84e816p0, 0x1.2df544p0, 0x1.225f8cp0, 0x1.9a1fccp-2, -0x1.0267b2p0, 0x1.cbda2cp-3, 0x1.308bb6p0, -0x1.998314p-1, -0x1.c43da8p0, -0x1.5a45f8p0, -0x1.a3ef5cp0, -0x1.0f3088p0, 0x1.26010ep0, 0x1.76c5f2p-1, 0x1.506b76p-2, -0x1.e37814p0, -0x1.afd2ccp-1, 0x1.bc9f32p-4, 0x1.1f53c6p0, 0x1.08c832p0, 0x1.d3345p0, -0x1.1ffc1ep-1, -0x1.1c9e7ep0, 0x1.8006e2p0, 0x1.c06108p-1, 0x1.5194ap0, -0x1.bb663ep0, -0x1.b81aaep0, 0x1.f4f7ap0, 0x1.d9d7f6p-1, 0x1.6b94fcp-2, 0x1.eed2aap-2, -0x1.67dfbep-4, 0x1.63p0, -0x1.798032p-4, -0x1.eb548ep-3, 0x1.5da8f6p0, 0x1.63f978p0, 0x1.d6cbb2p-2, 0x1.c32a5cp0, 0x1.6f12d2p-2, 0x1.fa32dap-3, 0x1.cdb5a6p-1, 0x1.20b1bap0, -0x1.488c3ep-1, -0x1.293d9ap-3, 0x1.efd93p0, -0x1.413p-5, 0x1.6812b6p-2, -0x1.8a2798p0, 0x1.6b9b12p-2, 0x1.0b926p0, 0x1.c7187ep0, 0x1.3605cap-3, 0x1.b21d44p0, 0x1.131d42p-1, 0x1.b3c604p-3, 0x1.780abcp-1, -0x1.2f55cap0, -0x1.4b6426p0, 0x1.6acd82p-2, -0x1.8c822ap0, -0x1.27125ap0, 0x1.607956p-1, -0x1.63f8c6p0, 0x1.168aaep-1, 0x1.3448eep0, -0x1.52d1d4p0, -0x1.690d5ep0, -0x1.d67dd2p-2, 0x1.73cc3p0, 0x1.64fe8p-1, -0x1.65ca66p-3, -0x1.823ae8p0, -0x1.c41448p0, 0x1.91f8eep-9, 0x1.f85d54p-2, 0x1.962028p0, -0x1.94760ap-4, 0x1.21f12ap-2, -0x1.18a5a8p0, 0x1.14e9cep0, 0x1.89595ap-1, -0x1.a980d6p-2, -0x1.f93c06p0, 0x1.8905e2p0, 0x1.72401ep-3, 0x1.049f72p-2, -0x1.b529bp-2, 0x1.d1761ep0, 0x1.a285cp-2, -0x1.aa904p-1, -0x1.658fd8p0, 0x1.a39768p-2, 0x1.15f2b6p-3, -0x1.e01e02p-1, -0x1.034de6p-3, -0x1.97adc8p-2, -0x1.31d698p0, -0x1.223d34p-1, -0x1.217c64p0, -0x1.109c36p-2, 0x1.b0f212p0, 0x1.27337p0, 0x1.19f6d6p-5, -0x1.1cf404p-1, 0x1.3e567ep0, -0x1.8a903cp0, 0x1.eb9ec4p0, -0x1.a00bc2p0, -0x1.df96ep-3, 0x1.bdd298p0, -0x1.188822p0, -0x1.b24806p-6, -0x1.bc1b82p-1, -0x1.99b164p0, 0x1.1e0438p0, 0x1.624b1cp-2, -0x1.cbf884p-1, -0x1.7afd3p0, 0x1.d188dcp0, -0x1.58129ep-2, -0x1.6f6c1ap-1, -0x1.a7cc8cp0, 0x1.45697ep0, 0x1.290bc2p-2, -0x1.767138p-5, 0x1.a6376ap-2, -0x1.1a74cap-1, 0x1.08cc6ep-1, -0x1.da0a66p0, -0x1.497c34p-2, 0x1.a0d2ep0, 0x1.19095p-1, 0x1.55a0e8p0, -0x1.07f17cp-5, -0x1.806e18p0, -0x1.5f89c2p-1, -0x1.3473f8p-3, 0x1.2d003ap-1, -0x1.79c362p0, -0x1.a0404ap-1, -0x1.e8619p0, 0x1.411b94p-1, 0x1.48ecaap-1, 0x1.4d102ep-2, -0x1.64e638p0, -0x1.4691cap-3, -0x1.f0a3a6p-1, 0x1.0bae92p0, 0x1.93c278p0, -0x1.2eacaap-3, 0x1.7a27fap0, 0x1.aef90ep0, 0x1.596e98p0, -0x1.894d38p0, 0x1.752776p0, -0x1.d7f41ep-2, 0x1.ad5548p-1, 0x1.4a1fd8p0, -0x1.584c62p-1, -0x1.6d0a66p0, -0x1.86c314p-1, -0x1.8a81f4p-4, -0x1.822884p0, 0x1.d7d616p0, -0x1.a66bf8p0, 0x1.a741b6p-1, -0x1.7608bcp-3, 0x1.91ada4p0, -0x1.ebae3ep0, -0x1.a81f76p0, -0x1.25dbd6p0, 0x1.5f3b24p0, -0x1.9d57c2p0, -0x1.16f28p0, 0x1.3dc658p-4, 0x1.4125bap-1, 0x1.3122cap0, 0x1.bee25cp0, -0x1.a0b7dcp-3, -0x1.c9c3c6p0, -0x1.b4e5e8p0, -0x1.f444a8p-4, 0x1.71fe56p-1, -0x1.0081eap0, -0x1.d2b9d6p-3, 0x1.609e8cp-1, -0x1.72fad2p-5, -0x1.adad4cp0, 0x1.b0afb8p0, -0x1.b7586ep-1, 0x1.a7f3eap0, 0x1.808e28p-2, 0x1.bcde74p-4, 0x1.212f6cp0, 0x1.8022fap0, 0x1.d6417cp0, 0x1.1a98ccp-4, -0x1.37920cp0, -0x1.b9a988p-1, 0x1.e7a6ccp-2, 0x1.8488p0, -0x1.0387d8p-1, -0x1.dc2f7ap-1, -0x1.1c8308p0, 0x1.cf11fap0, -0x1.876a1ep0, -0x1.e51abap0, 0x1.fc9cacp-2, -0x1.99d7cap-1, 0x1.03f83ep-2, 0x1.fc8d94p0, -0x1.50d6a2p-3, -0x1.ca2942p-1, -0x1.cafe3ep-1, 0x1.e79596p-1, -0x1.0a13ap-1, -0x1.d27c0ep-6, 0x1.df58a6p-2, 0x1.5e6cb6p0, -0x1.486b82p-6, 0x1.46b38ep-2, -0x1.d26b4ap0, 0x1.64dd46p-1, 0x1.7dc3bap-1, 0x1.83254ap-3, 0x1.20597cp0, -0x1.97d388p-1, -0x1.71fc9ep-3, -0x1.d08882p-1, 0x1.70a0fcp0, -0x1.b8349p-3, 0x1.a53e84p0, 0x1.bcfacep-2, -0x1.c3116ep0, 0x1.b988f6p0, -0x1.9433dp0, 0x1.1bcc82p0, -0x1.8c599p-1, -0x1.1251e8p0, -0x1.01634ep-3, -0x1.03c584p-1, -0x1.f66758p-2, 0x1.0176dep-1, -0x1.fe28f4p0, 0x1.0b094ep0, -0x1.191fbp0, -0x1.68ececp-3, -0x1.37d32ap-3, 0x1.91bf02p-1, 0x1.69b016p0, -0x1.71d88cp-1, 0x1.035aecp-1, 0x1.1336b4p0, -0x1.541dap0, 0x1.6319aap-2, 0x1.4cdb88p-1, -0x1.00db64p-2, 0x1.61396ap0, 0x1.a624b8p-1, -0x1.07625ap0, 0x1.337d46p-2, 0x1.70b61ap0, -0x1.489772p-1, 0x1.c110e4p0, 0x1.7a9d9ap-1, -0x1.5d68d8p0, 0x1.6dd116p-3, 0x1.6a4a34p0, 0x1.1079dap-3, 0x1.a29f1ap-2, -0x1.9d5cf8p0, -0x1.93fa8cp0, -0x1.c01e5ep-1, 0x1.510754p0, -0x1.2a5a36p-1, 0x1.f65be8p0, 0x1.62209ap0, -0x1.f7cc0cp-1, -0x1.f41626p-2, 0x1.f2c58ap-1, 0x1.b1b894p0, 0x1.bfc5f8p0, -0x1.520b02p0, -0x1.b4d624p-2, -0x1.ed7008p-1, -0x1.fff508p0, -0x1.4d2c7ap-2, 0x1.d08596p-1, 0x1.42a4ap0, -0x1.9eb32ap-1, 0x1.167dc4p0, 0x1.a0eb98p-2, 0x1.1d6ed8p-2, -0x1.769654p0, 0x1.4df8eep-2, -0x1.ee448p-1, 0x1.bc5298p-1, -0x1.b8be8p-1, 0x1.455f3p0, -0x1.7ea134p0, 0x1.039a9cp-2, 0x1.70e0ep-1, 0x1.f26b82p0, -0x1.60695ep0, -0x1.afcd9p0, 0x1.e9138ep0, 0x1.281ed8p-1, -0x1.06486ap0, 0x1.796faep0, -0x1.21aa02p-3, -0x1.7d329cp-2, 0x1.f39416p0, -0x1.65d5cap-1, -0x1.1088fap-3, -0x1.7222f8p-1, -0x1.328956p-1, 0x1.f68a9ap0, 0x1.1553aep-3, -0x1.101fa6p-5, 0x1.ac2a62p-1, -0x1.e31514p-2, -0x1.99ec76p0, 0x1.c0bccep-1, 0x1.5b44dap-1, 0x1.327f26p0, 0x1.a1e27cp-1, 0x1.6b52d8p0, 0x1.0e035cp-1, 0x1.da6fbp-1, 0x1.d30258p0, 0x1.8ee1fp0, 0x1.cdbaap-4, 0x1.febbcp0, 0x1.7a1f94p-4, 0x1.2f23ecp0, -0x1.cff174p-1, 0x1.986f52p-1, 0x1.dcdd9cp-3, 0x1.8e5efcp0, -0x1.78e02cp0, -0x1.a5fa0cp0, -0x1.0a8eb2p0, -0x1.8ba10cp0, 0x1.28b746p0, 0x1.43efb8p-4, 0x1.4e4fa8p0, 0x1.102bbp0, 0x1.f0095cp0, 0x1.a0cc6ap0, -0x1.2eee8p-5, -0x1.0032b8p-1, 0x1.54e59cp-1, -0x1.75c6f2p-3, 0x1.d49f68p0, -0x1.da228ep-1, -0x1.aef7e2p0, 0x1.e25384p0, 0x1.ca6e6ep0, 0x1.73e2b2p0, -0x1.679c44p-2, -0x1.41158ap0, 0x1.971796p-1, 0x1.a5289ep-5, -0x1.e094f4p0, 0x1.c494bp0, -0x1.065e3p0, 0x1.38f678p0, 0x1.313e94p0, 0x1.d209d6p0, -0x1.6b6596p0, 0x1.bd7c46p-1, 0x1.4073e4p-2, 0x1.16ef8ep-2, 0x1.65a4aep0, -0x1.b10b4cp-2, 0x1.79ad46p0, -0x1.24e9dap-1, -0x1.e407b4p-1, 0x1.06c88p0, -0x1.36c85cp0, -0x1.18fc0cp-1, -0x1.97b59ep0, -0x1.ac619ep0, -0x1.68dfa4p-3, -0x1.7a5856p0, -0x1.0e8dc4p-1, 0x1.de497ep-2, -0x1.c5ca24p-4, 0x1.94ad1p0, 0x1.4b80aap0, 0x1.ef1622p0, -0x1.738df2p-3, -0x1.d81d4cp0, 0x1.020014p-3, 0x1.040afp0, -0x1.d45e0ep-5, -0x1.b69c4p-5, -0x1.b47c5ep-1, 0x1.fa515p0, -0x1.74ee1ap0, -0x1.17ef54p0, -0x1.db056ep-1, -0x1.2d8e6p-2, -0x1.890d96p-3, -0x1.3df17cp0, -0x1.3b5d2ep0, 0x1.5f4c86p-16, -0x1.87c2c4p-4, -0x1.262062p-1, 0x1.1ad51ap-1, -0x1.bb9274p-3, 0x1.27892ep0, 0x1.e322d2p0, 0x1.52c04p-1, 0x1.1c9184p-2, 0x1.5ca79ep-1, -0x1.1461aap-1, -0x1.1ff848p-1, -0x1.6354dp-1, -0x1.76cdc2p-1, -0x1.22dbd4p0, 0x1.cd343ap-2, 0x1.ee4ad2p0, -0x1.9a6312p-3, 0x1.43231ap0, 0x1.db3f5ep0, 0x1.b2ecccp-1, -0x1.0cd38cp0, 0x1.31cd0ap0, 0x1.1f8f52p0, -0x1.e1be34p0, -0x1.5b89f2p-4, -0x1.eabccap0, 0x1.da9d14p-1, 0x1.8c83c8p0, -0x1.dd6dd2p0, 0x1.27fd7p0, 0x1.6bb72p-2, -0x1.4641e6p-1, 0x1.8b646ap-2, -0x1.21673p0, -0x1.dbb792p0, -0x1.9d9d62p-7, -0x1.006244p0, -0x1.f2191p0, -0x1.d4408p-6, 0x1.2ac332p-6, -0x1.abdf88p0, -0x1.ae09a6p-2, 0x1.0e2502p0, -0x1.4ea8c8p0, 0x1.d6b6d6p-3, 0x1.2f1c9ap0, -0x1.9d9c5ep0, 0x1.44c3c8p0, 0x1.f1f482p0, 0x1.8152e2p-5, 0x1.cb1af6p0, -0x1.ff3fe4p-1, 0x1.677a36p-1, -0x1.e7548cp0, -0x1.293bf2p0, 0x1.73011ep-2, 0x1.2f6bd8p0, -0x1.0f3d22p-1, 0x1.d4914p0, 0x1.26ccf4p0, -0x1.8da676p0, -0x1.b21aap-1, 0x1.b998f2p0, 0x1.e3e708p-2, -0x1.19638cp0, -0x1.249ffp-1, -0x1.d57488p0, -0x1.a81666p0, 0x1.259098p-1, -0x1.001184p-2, -0x1.6d05ecp0, 0x1.aa7b54p-1, 0x1.5a1b92p0, -0x1.b9cdf2p-2, 0x1.6c5542p-2, -0x1.626f16p-1, -0x1.d65646p-2, -0x1.97736ap-1, 0x1.92e548p0, -0x1.50929cp-3, 0x1.81cffcp0, -0x1.99763ap-1, 0x1.14e50ep-1, 0x1.c68e4ap-1, 0x1.74266p0, 0x1.d0249ap0, -0x1.2ddb7cp0, -0x1.36ac24p-2, 0x1.f8149ap0, -0x1.9cba6cp0, 0x1.69d1dap0, 0x1.20d124p-2, -0x1.864114p-2, 0x1.b4a752p0, 0x1.c9980ap-1, -0x1.c1c626p-2, 0x1.09354ep-2, -0x1.40b1c8p0, 0x1.5918fcp0, -0x1.817518p0, -0x1.4605a4p0, 0x1.13762p-3, -0x1.368a08p0, -0x1.638fa2p0, 0x1.702932p-2, -0x1.0a7e72p0, -0x1.90aa96p-1, -0x1.09ce3cp0, 0x1.69527ep0, 0x1.09d354p-2, -0x1.b4238ep0, 0x1.407436p0, 0x1.5db62ap-3, -0x1.ff0052p-2, 0x1.c336fap-1, -0x1.080062p-1, -0x1.cd3986p-1, 0x1.0c3d8p-1, -0x1.fb375p-4, 0x1.05b88p-3, -0x1.9689e2p0, -0x1.55652cp-1, -0x1.5c8f58p-1, -0x1.6a974ep0, -0x1.b20c56p-3, 0x1.03f64cp-2, 0x1.49e132p-4, -0x1.c3257p-1, 0x1.da44ecp0, 0x1.066da2p-1, 0x1.57a07cp-2, -0x1.419f08p-3, 0x1.5eb16cp0, -0x1.57d6fcp0, 0x1.f8fbc4p-2, 0x1.97c51p0, -0x1.538d4cp-1, -0x1.f79cbcp-3, 0x1.f20d18p0, 0x1.2580fap0, -0x1.626882p-7, 0x1.2c2036p0, 0x1.a7e016p-1, -0x1.fb298p0, -0x1.b53cacp-1, 0x1.cb749ep-2, 0x1.276b62p0, -0x1.13c6aep0, -0x1.231304p0, -0x1.db9ebp-1, -0x1.5448a8p0, 0x1.5dc8fap0, 0x1.b9589ep-3, 0x1.40ef96p-1, -0x1.c43ad6p-5, -0x1.daa572p-3, 0x1.4f8236p0, 0x1.0eac2p-3, -0x1.5ce20cp0, -0x1.9e6fc2p-1, -0x1.704dd8p-2, 0x1.83d7dcp-4, 0x1.b97702p-2, 0x1.9bfee6p-1, 0x1.5c5bd2p-1, 0x1.0c9bb6p0, -0x1.be5468p0, -0x1.5d1688p-1, -0x1.2945dep0, -0x1.7c3ceap0, 0x1.005d4ep-1, 0x1.ddfb78p-2, -0x1.f46bc2p-6, 0x1.1f8ea2p-2, -0x1.98f7ap0, 0x1.172ceap0, -0x1.5a6988p0, 0x1.098182p0, -0x1.c1afdep-1, 0x1.f7ee48p-1, 0x1.651ef8p-3, 0x1.6edb88p0, 0x1.cb32ep-2, -0x1.9bb866p0, 0x1.db18f4p-2, 0x1.b64a4p0, 0x1.a410a6p0, -0x1.e3b19cp-1, 0x1.c0bd98p0, -0x1.c01a5cp0, -0x1.a58358p0, -0x1.02c12cp-2, 0x1.23249cp-1, 0x1.e23e1ep-1, 0x1.4c7c4p-3, 0x1.114fd8p-1, 0x1.d9b8e6p-2, 0x1.cc36b8p-1, 0x1.70717ep-4, -0x1.5c9c0ap0, 0x1.26131ep-1, 0x1.760428p-2, 0x1.2db87ep-2, 0x1.504d22p0, 0x1.7d33acp0, 0x1.3f0b1p0, 0x1.2160fcp0, 0x1.6a67b6p0, 0x1.b15b06p0, -0x1.74f374p-4, -0x1.79d1bap0, -0x1.efac5cp0, -0x1.e73682p-1 };
float test1_dense_input_input_array[2622] = { 0x1.be157p0, -0x1.2952a4p0, -0x1.f1a53ap-3, 0x1.89c2cep0, 0x1.643852p-1, -0x1.5ad3b8p0, -0x1.c55c24p0, 0x1.a191bap-1, -0x1.041c5ap-1, -0x1.be5946p0, 0x1.58e52ap0, 0x1.1eb0fp-1, 0x1.b13f7p0, -0x1.08215ap0, 0x1.dc6bdp0, -0x1.0f0fe2p-3, 0x1.e4b17ep0, 0x1.18a7fcp0, 0x1.5f4fdp0, 0x1.b42e16p0, -0x1.660bdep0, 0x1.1645e8p0, -0x1.a8f982p-3, 0x1.841482p0, -0x1.2a0c46p-1, -0x1.c9d6ap0, 0x1.61f90cp-6, 0x1.17c2fcp-1, -0x1.05875ap-1, 0x1.fb67cp0, -0x1.0071ccp0, 0x1.c167bcp-1, 0x1.c0e4d2p-1, -0x1.47a0fep0, -0x1.d2d068p0, -0x1.f08856p0, 0x1.f8abp-1, -0x1.e3733cp-2, 0x1.a8aadp-3, -0x1.b5b0a6p-1, -0x1.e382fep0, -0x1.6118d6p-2, 0x1.4210cap-3, 0x1.f5010cp-3, -0x1.968a3cp0, -0x1.c36a7ap-1, -0x1.746da8p0, 0x1.eeb1ecp-4, 0x1.6f5944p-1, 0x1.807a4ap0, 0x1.7bca22p-1, -0x1.1aaa7cp0, 0x1.3e1844p0, -0x1.1d9bfep0, 0x1.a05c86p-2, 0x1.c55676p0, -0x1.203368p0, 0x1.2a3592p-2, 0x1.9f42c2p0, 0x1.90b79ep-1, -0x1.23b942p-2, 0x1.0a31acp-1, 0x1.bcb7fcp-2, 0x1.938442p-1, 0x1.8014eap0, -0x1.662b7ep0, 0x1.e54b32p-1, -0x1.0c6aecp0, -0x1.8bffd8p-1, 0x1.d167b8p-4, -0x1.9580cap-1, -0x1.50541cp-1, 0x1.9c3546p0, -0x1.c3436ep0, 0x1.fcc9a8p0, -0x1.b04936p0, -0x1.49949ep0, -0x1.bfc7c4p0, 0x1.7657fcp-1, -0x1.34fc0cp0, 0x1.6ce432p-1, 0x1.664f5p-1, -0x1.be7bd6p0, 0x1.7b52ep0, 0x1.9a2dc6p-1, 0x1.642266p-1, -0x1.bb3fe6p-2, 0x1.2685a6p0, 0x1.0e4ac8p0, 0x1.78d95ep0, -0x1.280478p-3, 0x1.b313a4p-2, -0x1.3dee5ep-1, -0x1.b76df4p-2, 0x1.4ab12p-1, 0x1.8afcf4p-1, -0x1.a953fap0, -0x1.342364p0, 0x1.48493p-1, 0x1.24adeap-3, 0x1.086998p-3, -0x1.496e12p-2, -0x1.443ee6p-2, 0x1.a8c46ep0, -0x1.c77394p0, -0x1.93cfcap0, 0x1.cda6bcp-2, -0x1.0f87c2p-1, -0x1.c619a6p-1, -0x1.109782p0, 0x1.d17e62p-2, -0x1.07403ap0, 0x1.edf2dp0, 0x1.6ee3p-1, 0x1.ab9366p-6, 0x1.b5ab1ep0, -0x1.8a564ap0, 0x1.34d524p0, 0x1.b201fap0, -0x1.0d50f2p0, 0x1.c7b5c8p0, -0x1.e78cbep-8, 0x1.84554p-2, -0x1.81a0c8p0, 0x1.f5c2a4p0, 0x1.4f2106p-1, 0x1.04421p-1, -0x1.f1e65p-1, -0x1.f50b58p-1, -0x1.0c5d98p0, 0x1.c5ac24p-1, 0x1.035824p0, 0x1.751dfp0, -0x1.e03024p-1, -0x1.f57c56p-1, 0x1.fd8454p0, 0x1.dcb06ap0, 0x1.11413ap-1, -0x1.4d3f6ep-1, 0x1.3cec4ep-2, 0x1.238884p0, 0x1.264c54p0, -0x1.048dfep-4, 0x1.01b9cp-7, -0x1.45ffa4p-1, -0x1.e85be2p0, -0x1.865104p0, 0x1.428fc4p0, 0x1.5ca1ep0, 0x1.8dbe46p0, 0x1.fdc35ep-1, 0x1.7713b2p-1, -0x1.806952p0, 0x1.8067e6p0, 0x1.db3456p-1, -0x1.a7ef7cp0, 0x1.dd941p-6, -0x1.a526dcp0, -0x1.70a3eap-1, -0x1.e6734ep0, 0x1.7e0cfep0, -0x1.5d2b0ep-1, 0x1.603536p0, -0x1.462724p-1, -0x1.e5c57p-1, -0x1.b5ee7ep0, -0x1.52a35p-7, -0x1.73717cp-1, 0x1.e52f22p-1, -0x1.e98a7p-4, -0x1.8d85a6p-1, -0x1.58ed6cp-1, 0x1.580d1ap-1, -0x1.d53aep-2, 0x1.100022p-2, 0x1.839f3ap-6, -0x1.241ad2p0, 0x1.f3d012p-1, -0x1.d03a54p-5, 0x1.83426p0, -0x1.9097p0, 0x1.06f088p-2, -0x1.11dd88p-2, -0x1.4decbp-1, -0x1.269b62p-1, -0x1.84843p-3, -0x1.7e9de4p-1, -0x1.0d7f7ep0, 0x1.88821cp-1, 0x1.6f20fp0, 0x1.f8c87p0, 0x1.28cf46p-1, 0x1.0969f4p-1, 0x1.abef8ep0, -0x1.8b9924p0, 0x1.483774p-3, -0x1.7b9eb2p-1, 0x1.36b744p-3, 0x1.9710fp0, -0x1.11cd04p0, 0x1.d9c6a6p0, -0x1.8b506p0, 0x1.a5f392p0, -0x1.dcad46p0, -0x1.d9f3c6p-2, -0x1.15de3ap-1, 0x1.3a06ep-1, -0x1.b33b28p0, -0x1.1bd9b8p0, 0x1.2aba62p0, -0x1.fdf718p0, -0x1.e0ce7ep0, -0x1.c6fc4ap0, 0x1.8f639cp0, -0x1.ac3842p0, 0x1.7d6d0ep-1, 0x1.63590ap0, 0x1.53c696p-1, 0x1.a17d98p-2, -0x1.9cf65ap0, 0x1.208d94p0, 0x1.2d2f54p0, 0x1.0b0974p0, -0x1.cf2102p0, 0x1.70c68ep0, -0x1.bc965ep-3, 0x1.e5903p0, 0x1.67e16p-3, 0x1.739d04p0, -0x1.b9d5dep-3, 0x1.e17378p0, -0x1.068944p-1, 0x1.abd5c2p-1, 0x1.1dcdbp-1, 0x1.f6fd6ap0, -0x1.f840dep0, 0x1.423bfcp-1, 0x1.a95706p-1, 0x1.48d46ap-2, -0x1.6c5ccp-1, -0x1.01c876p-1, 0x1.5f75b6p0, 0x1.ace124p0, -0x1.a2cffep-2, -0x1.ebedc4p-3, -0x1.a60168p0, -0x1.262128p0, -0x1.5a4458p-2, -0x1.d093d4p0, -0x1.f7e018p-2, -0x1.1803b4p0, -0x1.c5eb36p0, 0x1.321dbap-1, 0x1.3587c8p0, -0x1.c74cap0, 0x1.9468d4p-1, -0x1.a1b22ep0, -0x1.7f08fap-4, -0x1.6f22p-1, -0x1.4e66ecp0, 0x1.bfba1ep0, 0x1.6d347ep0, -0x1.8f58b4p-4, -0x1.4a92dp0, 0x1.e8e3b6p0, 0x1.a4f664p0, 0x1.a3f816p0, -0x1.b96a66p0, -0x1.9b4eecp0, 0x1.961b4cp0, -0x1.d5e416p0, 0x1.9ba77ap-3, -0x1.9852ap0, 0x1.b74fcp-1, -0x1.5ae6fep0, -0x1.54fep0, 0x1.beab44p-1, -0x1.7879dep0, -0x1.d65306p-1, 0x1.b94f92p-1, 0x1.40ffa6p-2, -0x1.0d4c3p0, 0x1.b560b6p-1, -0x1.71b6fep0, -0x1.35966ap-1, 0x1.d2fe84p0, -0x1.e0a71p0, -0x1.14f8a2p0, -0x1.e9c9f4p-2, 0x1.f53822p-1, 0x1.fd031ap0, 0x1.c47308p-1, 0x1.be8a1ap-2, 0x1.4670e8p0, 0x1.f0ad36p-1, 0x1.8a90ccp-2, 0x1.b49b56p-1, -0x1.51a81cp-1, 0x1.b59848p0, 0x1.075744p0, -0x1.d5b0cp0, 0x1.ddd10cp-4, 0x1.29be42p0, -0x1.65d3dp0, 0x1.05a0b8p0, 0x1.e11bfep-1, -0x1.7c79b4p-2, 0x1.efe54cp-1, -0x1.3ddec2p-3, -0x1.a5430ap-1, 0x1.d97136p0, 0x1.bcae46p-2, -0x1.35db52p-3, 0x1.9edf3ap0, 0x1.dd4136p-1, 0x1.d245bep0, 0x1.cc9ac2p0, -0x1.fc274cp-7, -0x1.99d876p-1, 0x1.ce8aap-1, -0x1.4fdc7ap0, 0x1.66e388p-4, 0x1.ed2e2ap-1, -0x1.ee1426p-4, -0x1.e5a42ap-2, 0x1.4fb866p-1, 0x1.20d8d4p0, 0x1.3d4044p0, 0x1.81e36cp0, 0x1.3881bap0, 0x1.69949p0, -0x1.4b544cp-1, -0x1.fc398cp-1, 0x1.828cd6p0, -0x1.003e18p-1, -0x1.8c78e8p0, -0x1.a1f0dp0, 0x1.8ed50ap-2, 0x1.b21a16p0, 0x1.2c00c6p-1, 0x1.a1dda6p-2, -0x1.09275ap-1, -0x1.5c632ap-2, 0x1.87708p0, 0x1.e8a85cp-4, 0x1.5c321ap-1, 0x1.b35ae6p-1, 0x1.b29056p0, -0x1.52a8eap0, 0x1.66b15p-3, 0x1.4596d2p0, -0x1.76c592p-2, -0x1.5a9886p0, 0x1.3125acp-1, 0x1.1f47a6p0, -0x1.f875c8p0, -0x1.d64014p0, -0x1.3e0fe6p0, -0x1.3bac64p-1, 0x1.d13a1ep-3, 0x1.58121p-1, -0x1.21ff42p-1, 0x1.013e82p0, -0x1.cdf66p-4, -0x1.aa1536p-1, 0x1.973496p0, 0x1.9fb552p0, 0x1.4c221p0, -0x1.bd730ap-3, 0x1.2a630cp0, -0x1.0bb90ap0, -0x1.85273p0, -0x1.935766p-1, -0x1.dbbd46p-3, 0x1.554d9p-1, -0x1.b13c6cp0, 0x1.81b8cep-2, 0x1.734a9p0, -0x1.fa8482p0, 0x1.2ccefep0, 0x1.64cb5p0, 0x1.c7411ep-3, -0x1.6ab27cp-4, 0x1.9c759cp-3, -0x1.01a87p-2, 0x1.229c1cp-1, 0x1.8de68p-1, -0x1.5ddf8cp0, 0x1.8845f8p0, -0x1.f422c4p0, 0x1.875f2p0, -0x1.c969a8p0, -0x1.85669cp0, -0x1.bbcb74p0, 0x1.ef0728p-1, -0x1.3f4ae2p-1, 0x1.99d7b6p-4, 0x1.f6af8p0, -0x1.279f24p0, -0x1.3ee392p-1, -0x1.36955ap0, 0x1.fa97fp-1, -0x1.afb50cp-1, -0x1.fcd466p0, -0x1.713022p0, -0x1.7e8d68p-4, 0x1.b22f5ap0, -0x1.5f26e2p-1, -0x1.895182p-2, 0x1.32708cp0, 0x1.c5867cp0, 0x1.7400dap0, 0x1.90e1b4p0, 0x1.7141cp-1, 0x1.24794p0, 0x1.7bb9fp-8, 0x1.445ebp-4, 0x1.5cda3ap0, 0x1.2319cp0, 0x1.da0a22p0, 0x1.071d32p0, 0x1.d0c84cp-1, -0x1.f544b2p-4, 0x1.84b556p-2, -0x1.dcc848p0, 0x1.d01954p-1, 0x1.1a225ap-1, -0x1.b386e8p-1, 0x1.dbc07ep0, -0x1.a4920ep-2, -0x1.138a3ap-2, 0x1.3459dcp0, -0x1.cbf024p-1, 0x1.153d5p0, -0x1.e4ed58p-3, 0x1.a820c8p-1, 0x1.4258a6p-4, -0x1.6e3d46p0, 0x1.ea66c4p0, 0x1.c8a958p-2, 0x1.b5ab74p-3, -0x1.ff8224p0, 0x1.759ce6p-2, 0x1.a49f34p0, -0x1.2afecep0, -0x1.e2739cp0, -0x1.6e72ccp-1, -0x1.6a755p0, -0x1.99975ep0, -0x1.4b16dcp-2, -0x1.608302p-2, 0x1.929beep-1, 0x1.19ad8cp0, 0x1.d7181p0, 0x1.01f61p-3, -0x1.97036p-2, 0x1.ddf918p-1, -0x1.91a878p0, 0x1.083b8ep0, -0x1.a486d8p-2, -0x1.113516p0, -0x1.2c1a76p0, 0x1.633a26p-2, -0x1.0509c2p-4, 0x1.8faafp0, 0x1.b1ca82p-2, -0x1.84fdc2p0, -0x1.6f0d1p0, -0x1.7d314cp0, -0x1.835822p-3, -0x1.af50dap0, 0x1.b5251p-5, -0x1.ca721cp0, -0x1.8c4c78p-1, 0x1.4fa8p-1, -0x1.5ad532p0, -0x1.a1a1ep0, -0x1.4258f6p-2, -0x1.02007ep-4, -0x1.4da6fp0, -0x1.adcba6p-1, -0x1.0f297ep-2, 0x1.45cea8p0, -0x1.f287fap-2, -0x1.4c865ep-3, -0x1.65c6fep0, -0x1.75c14ep-6, -0x1.e57f7ap-1, 0x1.d32b0ep0, -0x1.de220ap-1, -0x1.f89c7cp-1, 0x1.18f4a4p-1, 0x1.356f84p0, -0x1.e1f746p0, -0x1.d7f4eep-8, 0x1.6cde32p0, -0x1.103742p0, -0x1.408f06p0, -0x1.a17ap-1, -0x1.9fbc4ep0, 0x1.b148b2p-2, -0x1.631b5cp0, -0x1.952a64p-1, -0x1.df8514p0, 0x1.e0e9ecp0, -0x1.508d54p-3, 0x1.3b09fep0, -0x1.5c6cfap0, -0x1.aa59a2p-1, -0x1.4980fep0, -0x1.811b6ap0, 0x1.171ae6p-3, 0x1.305aa6p0, -0x1.afc6f2p-2, -0x1.61bd98p-3, 0x1.a85296p-2, -0x1.92ab04p0, 0x1.8e384p0, -0x1.2f1334p0, -0x1.f2026ep0, 0x1.348274p-1, 0x1.e7e85cp-2, 0x1.8bcde8p-4, 0x1.ea72p0, -0x1.b1a768p0, -0x1.657678p0, 0x1.2d1752p0, 0x1.32cdf4p0, -0x1.1fbd6p-3, -0x1.3f1bp0, -0x1.decf8p-2, 0x1.b6fe9ep-1, 0x1.b47fa6p-3, 0x1.0f4f4ep0, -0x1.4dc7b2p0, 0x1.6f44c8p0, 0x1.845ccap0, 0x1.b8226ap-1, -0x1.ee734ap0, -0x1.49028ep0, 0x1.3acbe2p0, 0x1.e1eb46p0, -0x1.ec42d6p0, 0x1.510406p-2, -0x1.239174p-1, -0x1.df37cep0, 0x1.576204p0, 0x1.8268bp-3, 0x1.a1e12p0, 0x1.01c082p-1, -0x1.bf741ap-2, 0x1.0ffbbcp-1, 0x1.972d36p-2, -0x1.73ee26p-1, -0x1.52f45cp-1, -0x1.31d988p0, 0x1.849a5ep0, 0x1.a16d28p-1, -0x1.c9641cp-2, -0x1.704e06p0, 0x1.2b8b64p0, -0x1.fc9996p-1, -0x1.5aa0d6p-3, 0x1.c008cap-1, 0x1.4cb634p0, -0x1.b0c4e4p-1, 0x1.77cc8p0, 0x1.c6f41cp-1, -0x1.bb4302p0, 0x1.413aa2p0, -0x1.82d7d6p0, 0x1.a914f6p0, -0x1.4909b8p-4, 0x1.ff489p-5, -0x1.783ba8p0, 0x1.536176p-1, 0x1.47b0ccp-4, -0x1.d757aap0, -0x1.fc0c02p-4, 0x1.447b2ap-2, 0x1.90290ep0, 0x1.7c54b6p0, 0x1.cdf8fep-1, -0x1.bb691cp0, -0x1.0bf2f2p-1, 0x1.f8e2fp-2, 0x1.80bb24p-2, 0x1.8309aap-1, 0x1.b3c95cp0, 0x1.b6c704p-5, -0x1.13fbbep-1, 0x1.50bb86p-1, -0x1.a2c77ep0, 0x1.5b6e2ap-2, 0x1.dafc9cp-2, -0x1.422bf2p0, -0x1.f6edb4p0, -0x1.2c2d66p0, -0x1.1c4bccp-1, 0x1.464e78p0, 0x1.f7ff9cp-1, -0x1.9a3ab6p-1, 0x1.0528bap0, -0x1.a26116p-4, 0x1.f30bd8p-2, 0x1.b76beap0, -0x1.58fde4p-3, 0x1.4a813ap-1, -0x1.c1aa0cp-1, -0x1.421d12p-2, 0x1.8f79e8p-3, 0x1.b6dddep0, -0x1.a09fc6p-4, -0x1.9c1e58p-1, 0x1.94ac9ep-4, -0x1.806fa2p-4, -0x1.0c542ap0, -0x1.aa567p-1, 0x1.674b4ep-1, 0x1.e7f128p-1, 0x1.248b02p0, 0x1.ae3f6p0, -0x1.323e46p-8, -0x1.515478p0, -0x1.fdf1f6p-1, 0x1.2d6cb6p0, 0x1.78ae8ep-1, 0x1.104e56p-1, -0x1.0343aap0, 0x1.0f5d54p0, -0x1.534638p0, 0x1.465e12p0, -0x1.af1744p0, 0x1.d6f50ep0, 0x1.478b64p0, -0x1.8683eep-1, 0x1.b1f0dap-1, -0x1.e8c602p-2, 0x1.58fa18p-1, 0x1.e45d96p0, -0x1.e62cc2p-1, -0x1.44f6aep-2, 0x1.77d21p0, -0x1.995f1cp-1, 0x1.97d328p0, 0x1.16ccfp-3, 0x1.9c45aep-2, -0x1.e24d5ep0, 0x1.0a953cp0, 0x1.c54f8cp0, -0x1.f1f0bcp-1, 0x1.0ec71cp0, 0x1.5f127p0, 0x1.4e7b86p0, -0x1.8f7d8ep-1, 0x1.c60df4p0, -0x1.ca3e28p0, -0x1.eca828p-2, -0x1.390a04p-1, 0x1.4bd84ap-2, -0x1.ac1da6p0, 0x1.5458dp0, -0x1.084f8p-2, -0x1.f1739cp-2, 0x1.2b6c3cp0, -0x1.082c62p0, 0x1.46702ap-1, -0x1.186156p0, -0x1.9e73a4p-2, 0x1.c5bd6cp-1, -0x1.435688p0, -0x1.22c758p-1, -0x1.5ee272p0, 0x1.2ad966p0, 0x1.1dd024p-2, -0x1.357c5p0, -0x1.051786p0, -0x1.c8bf2p0, -0x1.862e32p0, -0x1.59eaa8p-2, 0x1.8f604ep-2, -0x1.4c6cd4p-2, 0x1.b8fa3p-1, -0x1.706d0cp-1, 0x1.575c6ep0, 0x1.5d909cp0, -0x1.93a008p0, 0x1.d65578p0, -0x1.9e082ap0, -0x1.e8d3a4p-1, -0x1.d23e9ep0, 0x1.a3076p-1, -0x1.24442ap0, 0x1.5a4d5ap0, -0x1.0fce16p-1, -0x1.bfcb1cp0, 0x1.d4fe5p-1, -0x1.b8b98ap0, 0x1.844f28p-1, 0x1.e2f1c2p0, -0x1.28469p-1, 0x1.62a898p0, 0x1.78aed8p-2, 0x1.aa455p0, 0x1.5a176cp-5, 0x1.0a68f4p-1, -0x1.bbf32ap0, 0x1.fed704p0, -0x1.764cfp-2, -0x1.a26aep0, -0x1.94b3aap-1, -0x1.7593b4p-3, 0x1.df9adp0, -0x1.6368ccp0, -0x1.6d454p-3, 0x1.e362dep-3, 0x1.82407ep-1, -0x1.8df76cp0, 0x1.f212a6p-5, -0x1.aa2d96p-1, -0x1.7b547p-1, 0x1.421fc8p0, 0x1.325104p0, 0x1.3b66fep-1, -0x1.ddb3d2p-4, 0x1.734ec2p-2, 0x1.195e1cp0, -0x1.a8624cp0, 0x1.c6667ep0, -0x1.a1041cp-4, -0x1.2b707ep-1, 0x1.21663cp0, 0x1.0a94aap0, -0x1.03658cp-2, 0x1.781502p-2, 0x1.ca1898p-2, -0x1.a43bb8p0, -0x1.120a9p-2, 0x1.e75b9cp-1, -0x1.55d5f8p-1, -0x1.5321d2p0, 0x1.301d6p-1, 0x1.0e2362p0, -0x1.f62958p0, -0x1.9ac05cp-2, -0x1.096112p0, 0x1.e93772p-1, -0x1.81ad8cp0, -0x1.d064a8p-1, -0x1.66bd9p0, -0x1.af5614p-1, -0x1.5654ep0, -0x1.bd97bcp0, -0x1.ac46e2p0, -0x1.eec6cep-3, -0x1.9b3ce2p0, 0x1.01df2ap0, -0x1.a507a4p0, 0x1.4a9c5ep0, 0x1.f723fcp-2, 0x1.9faa86p-3, -0x1.1ddbfep-2, -0x1.235e3cp0, -0x1.3ac986p-1, -0x1.ed6a66p0, 0x1.81dcd2p0, 0x1.ed8592p-2, 0x1.9809cep-1, 0x1.2efdd4p-2, -0x1.a43c48p-1, 0x1.570b12p-2, -0x1.a85ed6p-3, -0x1.19645ep0, 0x1.5d9a1cp0, -0x1.89ec74p0, 0x1.e07e9ap0, -0x1.026518p-1, -0x1.25a3fp0, 0x1.378d9ap0, -0x1.4916e8p0, -0x1.b3fe14p0, -0x1.15aaeap0, 0x1.3f45a6p0, 0x1.0c302p0, 0x1.50a846p0, 0x1.2d5852p-6, 0x1.5a44acp-2, -0x1.61143cp0, -0x1.998cp0, -0x1.6f0bb2p-1, -0x1.0a40e4p0, 0x1.90bbap-1, -0x1.62dd2cp-1, 0x1.f6570ap-3, 0x1.e5f4cap-2, -0x1.bacd12p-1, 0x1.9dc76cp-1, 0x1.5a70d8p-6, -0x1.0eec04p-1, -0x1.b23282p0, -0x1.850e68p0, 0x1.085e82p-1, 0x1.b07628p-4, 0x1.535274p0, -0x1.d7ef86p0, -0x1.e9e6cp-2, 0x1.3e7bd8p0, 0x1.136692p-3, 0x1.fc1102p0, -0x1.50e8bap-1, 0x1.f320c8p-1, -0x1.027b3cp-3, 0x1.fba2eep0, 0x1.bbf764p-2, -0x1.b3ab3p0, 0x1.166d6cp0, 0x1.2894c4p0, -0x1.23993ep0, -0x1.49726p-4, -0x1.461616p0, -0x1.bdaf08p0, -0x1.2b2338p-3, 0x1.45c13ep-4, -0x1.793704p0, 0x1.ac0ea2p0, 0x1.e85148p-3, -0x1.88f38p0, -0x1.5c6bdep-3, -0x1.a746ecp-1, 0x1.4bf80ep0, -0x1.3219bep-2, 0x1.fd24f8p-1, 0x1.30425cp0, -0x1.1e41cp0, -0x1.ddf9d8p-1, 0x1.cdf302p-1, -0x1.14ee98p0, -0x1.39f1a8p0, -0x1.e3902ep0, 0x1.89926cp-2, 0x1.6794b6p0, 0x1.035848p-2, 0x1.0d1bc8p-1, -0x1.7b2c64p-5, 0x1.7fe38ep0, -0x1.d45d64p-1, -0x1.cf986cp0, 0x1.636128p-1, 0x1.643c56p-2, -0x1.c7e228p0, 0x1.bfae6cp-1, 0x1.2972fp0, -0x1.348f3cp-3, 0x1.d7fecep0, 0x1.b651a6p0, -0x1.e79434p-1, 0x1.311a26p-5, -0x1.5e89p0, -0x1.7c0998p-1, -0x1.5ce60ep-1, -0x1.4231ep0, -0x1.0e9412p0, 0x1.80ef26p-2, -0x1.ff2daap0, 0x1.c5dbeap0, -0x1.a09186p-3, -0x1.3d12ecp0, -0x1.8b7e5ep-4, 0x1.7a924ep-3, 0x1.5fe7b2p0, 0x1.b3a6f2p-1, 0x1.74068p0, 0x1.31dcp-1, -0x1.ebb8dap-1, 0x1.4feca8p-1, -0x1.92fc84p0, -0x1.5c643ap0, -0x1.b356b4p0, -0x1.538604p-4, -0x1.4ab19p-2, -0x1.a8d31ep0, 0x1.2878dap-1, -0x1.3a26dep0, -0x1.6e9be8p0, -0x1.49bcbcp-2, -0x1.f277a4p-2, 0x1.98027ep0, 0x1.80891ap0, 0x1.d2936p0, 0x1.de72e4p0, 0x1.8e25c8p0, -0x1.6ef96cp0, 0x1.2af9c6p-1, -0x1.9622fcp-2, -0x1.cf4f8p0, -0x1.15c9d8p0, 0x1.6c2c52p0, -0x1.2c364p-2, -0x1.cb5b7ap-3, -0x1.befa36p0, 0x1.f425e8p0, 0x1.4fdfccp0, -0x1.33238ep0, 0x1.d0c892p-1, 0x1.27abe2p0, 0x1.253e14p0, -0x1.c8edfp-1, -0x1.a54a2ep-1, 0x1.a8bdc4p-3, -0x1.c9f008p0, -0x1.2bdb6ap0, 0x1.72bc0ap-2, 0x1.2e21f2p0, 0x1.a49cfp0, 0x1.f1c9e2p-5, -0x1.0d02d8p0, -0x1.828cep0, 0x1.0b7946p0, -0x1.ac4136p-1, -0x1.f4a204p0, 0x1.2c36eap-3, -0x1.000172p0, -0x1.6ae4f2p0, 0x1.da12bep0, 0x1.885aep0, -0x1.161e44p0, 0x1.1feccap0, -0x1.3770cp-1, -0x1.82399cp0, 0x1.feccp-4, -0x1.c4173ep-1, 0x1.0a16b2p0, 0x1.364dfep0, 0x1.457c38p0, 0x1.f07ccep0, -0x1.65a55ep-2, -0x1.8b8842p-1, -0x1.6c2f2ep-2, 0x1.a118f6p-2, -0x1.7dd416p-4, 0x1.50495p0, 0x1.82ce98p-1, -0x1.620e72p0, -0x1.4d75d8p-3, 0x1.7847d8p-1, -0x1.b88896p-1, 0x1.cf4dp-1, 0x1.1b1acep0, -0x1.25774ep-3, -0x1.6e521p-3, 0x1.ea6bccp-3, 0x1.da7d84p-3, 0x1.84439cp-2, -0x1.46424cp0, 0x1.09a062p0, -0x1.6d36b4p0, -0x1.fb2654p0, -0x1.9ff886p-2, -0x1.00d30ap-2, 0x1.f12cf8p-2, -0x1.c82e06p-1, 0x1.1078cep0, 0x1.1b72fcp-1, -0x1.bf3b74p0, 0x1.cd2da4p0, -0x1.4e84bep-1, 0x1.512eccp-2, -0x1.52eb58p-5, 0x1.f53deep-1, -0x1.39d5dcp-2, -0x1.0e522ap-1, 0x1.a3759p-1, 0x1.b1179cp0, 0x1.55d738p0, 0x1.3a2616p0, -0x1.bf46bap0, -0x1.83e10cp-3, 0x1.1c05f6p0, -0x1.fa6046p-2, -0x1.32946ap0, 0x1.9abbb2p-1, -0x1.294bc8p0, 0x1.c29932p0, 0x1.1a61e2p-9, -0x1.dc4bcp0, -0x1.6456ep-2, -0x1.53e3dep0, -0x1.78aeb8p-1, -0x1.56ee72p-3, 0x1.07f8f4p-2, -0x1.9b94c8p-1, -0x1.89f8a2p-1, 0x1.6c139cp-3, -0x1.8d7df2p0, 0x1.e3eb12p-1, -0x1.a2e36ep0, 0x1.a7e22p-1, 0x1.af1894p-1, -0x1.5ff906p0, 0x1.dd797ap-1, 0x1.b3fdap-4, -0x1.fc7758p-1, 0x1.3aad04p-2, -0x1.d9c096p-1, -0x1.6030cep0, -0x1.bedb98p0, 0x1.c71892p-6, -0x1.04610cp0, -0x1.034014p0, 0x1.b745dep-6, 0x1.4cdb2ep0, -0x1.601564p0, 0x1.0956b4p-1, -0x1.906ec2p0, -0x1.51ef56p-2, 0x1.04979ep-8, -0x1.02fdfep-1, 0x1.271ef4p-1, 0x1.dd7a12p-3, -0x1.d533b4p0, 0x1.e8827ap0, -0x1.06e6c4p-1, -0x1.35e19ap-2, 0x1.18313cp0, -0x1.67b20ap-1, -0x1.f90a7ep0, 0x1.6b7e28p-1, -0x1.a5afcap0, 0x1.c745a8p-1, 0x1.794aa4p-2, 0x1.d76156p0, -0x1.8202b2p-1, -0x1.8a8d2ap-4, -0x1.01d82ap-1, 0x1.c72e6ap-2, 0x1.74f17ep0, 0x1.93593ep0, 0x1.321e3ep0, 0x1.a2dbc2p0, -0x1.9756fp0, 0x1.b5651cp0, 0x1.ccc608p-5, -0x1.72f222p-2, 0x1.8b9f3ap-1, -0x1.0dba4cp0, 0x1.215a38p-7, 0x1.fe7b3p-3, -0x1.f2819p0, 0x1.e57c6cp-1, 0x1.3038d2p-1, -0x1.84db06p-3, 0x1.dfa7c8p0, 0x1.4282b4p0, -0x1.e1a7e4p-1, 0x1.73220cp0, 0x1.b2f2f2p0, 0x1.27b88ap-1, -0x1.39a2e2p0, 0x1.d80864p0, 0x1.a8db08p0, -0x1.7ff826p0, -0x1.21948cp-1, 0x1.6fe032p-1, 0x1.8444dp0, -0x1.99abb4p-2, 0x1.2aff2ap-1, 0x1.ebb90ep0, 0x1.796c48p-4, 0x1.797e0ep-1, 0x1.0b3a3ep0, -0x1.e4f69p0, -0x1.f5f88ap0, 0x1.459404p0, 0x1.6b94c2p0, -0x1.fa78cap0, -0x1.9d5912p-2, -0x1.8a195cp0, -0x1.687f02p-1, -0x1.946b18p-3, 0x1.ca9e92p0, -0x1.9fed58p0, -0x1.57f6acp-1, -0x1.2089a8p-1, -0x1.bdb55ap0, -0x1.8980c6p-1, -0x1.ba0392p-6, -0x1.98b7ep-2, 0x1.466ef4p-1, -0x1.0fe2ep-8, 0x1.ea9f2cp0, -0x1.3090acp-2, -0x1.59c69p-1, -0x1.64455p-2, -0x1.218576p0, 0x1.674bd4p0, -0x1.e7ff16p0, -0x1.e953b4p-1, 0x1.634e1p0, 0x1.628312p-1, -0x1.946f98p0, -0x1.c13ad2p-1, 0x1.b889aep0, 0x1.2c508cp0, 0x1.bc7b8ep-2, -0x1.46f4c8p0, 0x1.69f9b2p-1, 0x1.9a5fd4p0, 0x1.7325d4p-1, -0x1.5cf956p0, 0x1.5213e8p-2, 0x1.ae3b38p-2, -0x1.31f484p0, 0x1.917862p0, -0x1.02bc02p-2, -0x1.e99682p0, -0x1.eec1fcp-1, -0x1.84f5dap0, 0x1.0c68a4p0, 0x1.069fc4p0, 0x1.f3ef2ap-2, -0x1.c3e75cp-1, -0x1.1bbbfap-1, -0x1.53d82p0, -0x1.db6788p0, 0x1.341eccp0, -0x1.5429c6p0, 0x1.5602dep0, -0x1.280692p-2, -0x1.8e6428p-1, -0x1.437b1p-2, 0x1.4b79cp0, 0x1.94fcf2p-1, -0x1.107356p-2, -0x1.9a631ap-1, -0x1.1224f6p0, 0x1.34b2fep-4, -0x1.c3fee6p-2, 0x1.4946bcp-1, 0x1.c745b6p-2, -0x1.8a54b2p0, 0x1.f3ccbep-3, 0x1.ca5b52p0, 0x1.823dcap0, -0x1.b88dbep0, -0x1.21ed0ap-1, 0x1.411db6p0, -0x1.b7159ep-1, 0x1.98ad82p-1, -0x1.fb30a8p-1, -0x1.a1c1e8p-4, 0x1.56848p0, 0x1.a0dad8p0, -0x1.5378d6p-1, 0x1.b01134p-1, -0x1.81d1dp0, -0x1.8f0442p0, 0x1.26b4e6p-1, 0x1.e45c3ap-5, 0x1.1d0fbcp0, -0x1.3ddde8p-4, 0x1.570354p0, -0x1.8d6d26p-1, 0x1.4f081cp0, -0x1.d349cap0, 0x1.e45806p-1, -0x1.fdc2dap-1, -0x1.bdb8f2p-1, 0x1.269fa4p-1, 0x1.e21c0ap0, -0x1.e23136p-1, -0x1.1ee9f4p0, 0x1.61e7b8p0, 0x1.972002p-2, 0x1.f7471p-2, 0x1.b63ad6p0, -0x1.6a3312p0, 0x1.b5d882p-2, -0x1.feb0f4p-1, -0x1.28355cp0, 0x1.4aa42ep-1, 0x1.8777fcp-1, -0x1.d74a94p0, 0x1.9d2fa8p0, 0x1.86a60ep-2, 0x1.f8e19cp0, 0x1.19bc32p-1, 0x1.95c914p0, -0x1.f1471p-1, -0x1.44f7e2p-8, -0x1.87265p0, 0x1.4089f2p-1, -0x1.5221dep0, 0x1.13299ep0, -0x1.d2f4b6p0, -0x1.fe151ap0, -0x1.c82546p0, -0x1.d113a2p-1, 0x1.614c2cp-2, 0x1.a785c8p0, 0x1.5ad0acp-6, -0x1.9e5e28p0, -0x1.1a8ac4p0, 0x1.5adabap-1, 0x1.8a92bap-1, 0x1.b448fcp0, 0x1.040a12p0, 0x1.cdd88cp0, -0x1.b2091ap-2, -0x1.5c3d86p0, -0x1.95feap-2, -0x1.0bf81cp-2, 0x1.63a9c8p-1, -0x1.458d44p-5, 0x1.2300ccp-2, 0x1.d404ecp-2, 0x1.b4eb8p0, 0x1.d07c7p-3, 0x1.c083e4p-2, -0x1.87404cp-2, 0x1.6d2f2ep-1, -0x1.f92078p-4, -0x1.be3b8ep-3, -0x1.06e53ep-6, 0x1.e9c58cp-1, 0x1.82b3c2p0, 0x1.3f843ap0, -0x1.b2ea8ap0, 0x1.ab5cdep-2, 0x1.795436p0, -0x1.70123cp-1, 0x1.2b9b66p0, -0x1.79124ap-1, -0x1.fd5d8p-3, -0x1.160142p-1, 0x1.951352p0, -0x1.cfa8e8p0, 0x1.6603cap-4, 0x1.791bf8p-1, 0x1.9c366p-1, -0x1.444eb4p0, -0x1.5a5f2ap-1, 0x1.ab46d6p0, -0x1.717da2p-1, -0x1.57e344p0, -0x1.27ee54p-2, -0x1.ffec8cp-1, -0x1.55d24ep0, 0x1.e43196p0, 0x1.068686p-1, -0x1.5ea596p-1, -0x1.2eb572p-1, -0x1.5581dep-2, -0x1.2dfd04p-2, 0x1.c3b67p0, -0x1.82cc2ep0, 0x1.f8b2fap-2, 0x1.09a4b2p0, -0x1.73b4c4p0, 0x1.5aa606p-3, 0x1.fe3a5ap-2, -0x1.919686p0, 0x1.111fcep-2, -0x1.1fea6ap-1, -0x1.19b68p-1, -0x1.95299p-1, -0x1.9d1216p0, 0x1.2d22b6p0, -0x1.544d2cp-1, 0x1.1bc4p-5, 0x1.2c03fp-1, 0x1.71305ep0, 0x1.8c077ep-6, 0x1.2f7e4ep0, -0x1.828392p0, 0x1.4e48acp-1, -0x1.d20dfcp-1, -0x1.0733eap0, -0x1.ae1858p-2, -0x1.a1a1fep0, 0x1.7f8642p-3, -0x1.eaa1d6p0, -0x1.ab0bp0, 0x1.30782ep0, -0x1.14dbdap0, -0x1.358588p0, -0x1.e6393ep-2, 0x1.db69cep-1, 0x1.3f0918p-3, -0x1.830ee6p0, -0x1.1be984p-2, -0x1.99ab3ap0, -0x1.b6291ap0, 0x1.175a9ap-1, 0x1.a6dd2cp0, 0x1.c5894ep-1, 0x1.3a6936p0, 0x1.ffc704p0, -0x1.812fdcp-2, 0x1.ec442ap-2, -0x1.d65d64p0, 0x1.481f72p-1, 0x1.fbae1ap-2, -0x1.4a654cp0, -0x1.d99a6ap0, 0x1.cfff62p-3, -0x1.c8aadep-1, -0x1.431804p-5, -0x1.a71618p0, -0x1.7bc93cp0, 0x1.2ddaf6p-1, 0x1.24634ap0, 0x1.e496e4p0, 0x1.df6e8cp0, 0x1.543df4p-1, -0x1.9b459ep-1, 0x1.cfff02p0, 0x1.6e213cp0, 0x1.c8a86ap0, 0x1.950938p0, 0x1.3f3fcp0, -0x1.fc1ed4p-2, 0x1.1b90a8p-1, -0x1.1f9d5p-2, -0x1.86db22p-2, -0x1.65da1ep0, 0x1.8fdb7p-3, -0x1.1fa282p0, 0x1.7ca006p-3, -0x1.53dd04p-1, 0x1.ed939p-2, -0x1.c03f1ep0, 0x1.ce00aap0, 0x1.190bcep0, -0x1.84e652p-1, -0x1.b37086p0, -0x1.072af8p0, -0x1.d84584p-2, 0x1.9d0efep-1, -0x1.9f25acp0, 0x1.882072p0, 0x1.cef2cap-1, 0x1.125ab6p0, -0x1.168abap0, 0x1.18fbaap0, 0x1.3ea86ep0, 0x1.1ca5ecp0, -0x1.547976p0, 0x1.b86fc8p-2, -0x1.95e3ep-3, -0x1.3cae8cp0, -0x1.da5e82p0, 0x1.440742p0, -0x1.0d0032p-3, 0x1.bee01ep-3, -0x1.35697ep0, -0x1.420d64p0, -0x1.7e1b02p-3, -0x1.fed6e6p-2, 0x1.984bf2p-2, -0x1.443adcp0, 0x1.7ab9f2p0, 0x1.6a6d6p-1, -0x1.3b0356p-5, 0x1.d57cp0, 0x1.40cd72p-1, -0x1.822fc4p0, -0x1.49088p-1, -0x1.ac2974p0, -0x1.d3ef4ep-2, -0x1.b83454p0, 0x1.03921ap-1, 0x1.3e9eaap0, -0x1.916114p0, 0x1.cba49ap0, -0x1.2a6b72p0, -0x1.358a0cp-1, -0x1.7e6d38p-2, -0x1.a9030ep0, -0x1.2a30ccp-1, 0x1.02bf42p-1, 0x1.844908p-1, -0x1.7013ccp0, 0x1.8a06dp-1, 0x1.6d1a1cp-1, -0x1.92dbe4p0, 0x1.bf1e12p-4, 0x1.8f5736p0, 0x1.8f845cp0, 0x1.5f6db4p-1, -0x1.d9c8b2p-2, 0x1.cd93ep0, -0x1.b7b53ep-1, 0x1.03a87cp-7, 0x1.a51be2p0, 0x1.a0cadap0, 0x1.d4e596p-1, -0x1.28e2a6p-1, -0x1.9f5f08p0, -0x1.c7e058p0, -0x1.a5e96ap0, -0x1.04d15p-1, -0x1.1445acp0, 0x1.b8161ap-1, -0x1.2c2418p-1, -0x1.295198p-3, 0x1.466b76p0, -0x1.6ad6fap-1, 0x1.2e774p-3, -0x1.c07686p0, 0x1.da8d2cp-3, 0x1.02177ap0, 0x1.297ccep0, -0x1.afdf9ep-1, -0x1.4522eep0, 0x1.91afbcp0, -0x1.a5cdc2p-3, -0x1.f3f4aap0, 0x1.3c52ap0, 0x1.1c8eep-2, -0x1.94de2ap-1, -0x1.b31fccp0, 0x1.45a3a6p-4, -0x1.a51c82p-2, -0x1.2b27cap0, 0x1.8761p-1, -0x1.85b87ep-1, 0x1.eca098p0, -0x1.23b832p-1, 0x1.5eb6ccp-4, 0x1.8797cp-5, 0x1.bc9832p-1, 0x1.59e316p-2, -0x1.800ef8p0, -0x1.9990cp0, -0x1.db8c8ap-2, -0x1.4e3e26p-1, 0x1.2e75fep-1, 0x1.fa6256p-1, 0x1.67a966p-1, -0x1.47165p0, -0x1.5684f2p0, 0x1.cceca2p-1, 0x1.526dc8p-1, 0x1.e237a6p0, 0x1.a0892ap-5, 0x1.c5c2ep-1, -0x1.89f244p-2, 0x1.f3115p-1, 0x1.8f3bcap-1, -0x1.1615bap-3, -0x1.28524ap-3, 0x1.3417c4p-1, 0x1.a1c6fcp-1, 0x1.907766p-2, 0x1.eabf8p-2, -0x1.eef8eep0, -0x1.a33e76p-2, -0x1.1ed10cp-1, -0x1.224d5p0, 0x1.c194d2p0, 0x1.5104d4p-1, 0x1.86474p-1, 0x1.bc4da2p0, 0x1.4a5c72p-1, 0x1.c25408p0, -0x1.701d68p0, 0x1.84084p0, 0x1.4bde04p0, 0x1.401f9cp-2, 0x1.7d2f7ep0, -0x1.72541p-2, 0x1.3aeafep-1, 0x1.090638p-1, 0x1.4c28fap0, -0x1.e77016p-1, -0x1.6ad2f4p0, 0x1.13b0bap-2, -0x1.22ef86p0, 0x1.12de9ep-1, 0x1.36386ep0, 0x1.9fc894p0, -0x1.cc6f24p-1, 0x1.47112ap-1, 0x1.e180e2p-3, 0x1.90115ap0, -0x1.1a58b4p-1, 0x1.41726p-3, 0x1.d25658p0, -0x1.3c73fp-1, -0x1.43b908p0, 0x1.5aa82cp-1, 0x1.825118p-3, 0x1.22879cp-3, 0x1.6df808p0, -0x1.95d776p0, 0x1.0f032cp-1, 0x1.af647p0, 0x1.461ce2p0, -0x1.2c751ep-1, -0x1.0ff6b2p0, -0x1.d7e996p-1, -0x1.5e59a2p-7, -0x1.9b9d6p0, 0x1.6c724p-2, 0x1.36421cp0, -0x1.47e6c6p-3, -0x1.fa9ebep0, 0x1.ed525ep-2, -0x1.69f86p0, 0x1.7baf96p-2, 0x1.8b0732p-2, -0x1.f57c56p0, 0x1.931bdp-1, 0x1.e2fbeap-1, 0x1.87558ap0, -0x1.067184p0, -0x1.30ce88p-2, 0x1.2cdd3cp0, -0x1.c21bdep0, -0x1.2c6566p0, 0x1.aab9f8p-1, -0x1.d8ed2p-3, -0x1.e2597ap0, -0x1.b8326p0, -0x1.8dc5a2p-6, -0x1.1b124ap0, -0x1.ad417p0, -0x1.b29d5p0, -0x1.76fe3p0, -0x1.f148fp-1, -0x1.a2e88ep0, 0x1.7fca26p0, 0x1.8769ecp-1, 0x1.5c5b3ap-1, 0x1.584faap0, -0x1.c8c83cp-1, -0x1.6b147cp-6, 0x1.0eeaap-2, -0x1.92244ep-3, 0x1.ceeb4cp0, -0x1.bdcbcp-4, 0x1.1e824ap0, 0x1.ccee2ep0, -0x1.a0bbe2p-1, 0x1.dd371ap-1, 0x1.9862bp0, -0x1.2c3a9p-1, -0x1.1162eep-5, 0x1.8ab37ep0, -0x1.740d42p0, -0x1.699f2ap0, -0x1.3cc9cap0, -0x1.bf5ec4p-1, -0x1.598c1cp-4, -0x1.7a91p0, 0x1.0c889ep0, 0x1.c76004p-7, -0x1.b6a308p0, 0x1.2c001ap-3, 0x1.dee9c4p-3, 0x1.0d8b4ep0, 0x1.160834p0, 0x1.17464ap0, -0x1.0398d2p-1, 0x1.98c9aap-1, -0x1.e8aeeep0, 0x1.ddcb7ap0, 0x1.b4a2b8p0, -0x1.3c3c74p0, 0x1.6f313p0, -0x1.59420ep0, 0x1.628966p-2, 0x1.448e9ap-3, 0x1.7b046cp0, -0x1.535e6ep-1, 0x1.79301p0, 0x1.293d52p-6, 0x1.67ad86p0, 0x1.91e08ap-3, 0x1.f4e522p-2, 0x1.c4ca1ap0, -0x1.5415f2p-1, -0x1.fd5e46p-2, -0x1.215f0ep0, 0x1.11c7dep0, -0x1.f9f98ep-1, -0x1.3b95ep-8, -0x1.9327e6p-1, -0x1.8657acp0, -0x1.2d3dfcp-3, 0x1.2f641ap-1, -0x1.d90bcp-5, -0x1.b62842p0, -0x1.0f54c6p0, 0x1.ce16c2p0, -0x1.051474p-4, -0x1.bde34p-1, 0x1.6d238ep-2, -0x1.b41eb2p0, 0x1.0e0b12p-1, -0x1.765496p0, -0x1.d26bacp0, -0x1.f58e3p-2, 0x1.1fba58p-1, 0x1.89550cp-4, 0x1.f2dd1cp-2, -0x1.7ba6dcp0, 0x1.baf9bp0, -0x1.6c777ap0, 0x1.fc2348p0, 0x1.793ecep-1, 0x1.2ac858p0, 0x1.494e2cp0, -0x1.639842p0, 0x1.e2f326p-5, -0x1.bc9248p0, 0x1.285d22p-1, -0x1.eb577ep-1, -0x1.ac2f86p0, 0x1.ef7c66p-1, 0x1.592fd4p0, -0x1.356892p-2, -0x1.d0fae4p-2, -0x1.f1abd8p0, -0x1.a68c64p0, -0x1.a4e86ep-4, -0x1.2afdep0, 0x1.6dfa2cp0, -0x1.878d52p-1, -0x1.d4eb2cp-5, -0x1.c6f9d8p0, 0x1.048beap0, -0x1.f76a9cp-1, 0x1.03a98cp0, -0x1.c90cf4p-1, -0x1.daa2d4p-1, -0x1.d90cp0, 0x1.0cef06p0, 0x1.9229bp0, 0x1.c6c3bcp0, 0x1.b23f7ep0, -0x1.fc9e5cp-1, -0x1.8847fep0, 0x1.056c34p0, -0x1.45b4b8p0, 0x1.6fb608p0, -0x1.0d8854p-2, -0x1.484498p-1, -0x1.231c62p-2, -0x1.0772a8p-2, -0x1.8a8dbcp-1, 0x1.702046p0, 0x1.c1eed6p-3, 0x1.334d38p-1, 0x1.c25ea4p0, 0x1.fec5aep-1, 0x1.2f498cp-3, -0x1.b3069p0, -0x1.b14c3cp-3, -0x1.8d70aep-5, 0x1.ca276p-4, -0x1.fd2fep0, -0x1.f6b982p-2, -0x1.55eac4p0, -0x1.4256dcp0, -0x1.68ab6cp0, -0x1.bfc334p-1, 0x1.2dff7p-2, 0x1.bccfe8p0, 0x1.84f39ep-4, 0x1.b22a8p0, 0x1.ca45dp0, -0x1.9cb08p-1, 0x1.74ac76p-3, -0x1.aecf0cp0, -0x1.28df62p0, -0x1.6040f4p0, -0x1.8ff9fcp-1, -0x1.dda1dcp-4, 0x1.9bd0fap-2, 0x1.20fbd8p-2, -0x1.5dc1e2p-1, 0x1.13a034p-1, -0x1.99582p0, 0x1.4868ecp0, -0x1.3fdc42p-2, -0x1.b23ccep0, -0x1.2c541p0, -0x1.3df282p-1, -0x1.e4b39p0, 0x1.7fdee4p-4, -0x1.ab7aaap0, 0x1.3c20a4p0, 0x1.eaff5p0, 0x1.d2cecap0, -0x1.cee992p-1, 0x1.566072p0, -0x1.f7c9d6p-1, -0x1.57a0fep-3, -0x1.c597e6p-1, -0x1.26aac2p-2, 0x1.1c5f32p-1, 0x1.d3754ep0, -0x1.c7459ap-1, -0x1.b44ep0, -0x1.9d8d9cp-4, -0x1.387f7ap-3, 0x1.d67a1ap0, 0x1.e2ff3cp0, 0x1.a25514p0, -0x1.e8f59ap0, 0x1.e6f99ap-2, -0x1.9bd2d6p0, -0x1.6fcbcap0, 0x1.2d836ep0, 0x1.b6ba02p0, 0x1.f7da6cp-4, 0x1.1f9adap0, 0x1.f9f438p-4, 0x1.db661p-4, -0x1.8626e8p0, -0x1.876c16p-1, -0x1.395bbp0, -0x1.e3a52p-3, -0x1.3ff32cp-1, 0x1.33c8cp0, 0x1.a42aep-3, 0x1.c9f526p0, 0x1.8af614p-2, -0x1.289de6p0, -0x1.0cda2p0, -0x1.50e7a2p0, -0x1.043ba8p-1, 0x1.374088p-6, 0x1.949216p-1, -0x1.8e61a2p-2, 0x1.24dea2p0, -0x1.63c5d6p0, 0x1.458698p0, -0x1.772bbp-5, -0x1.eaaf48p-3, 0x1.4544fcp-4, 0x1.efb10cp0, -0x1.71893cp-1, 0x1.ab4ea2p-2, 0x1.2bace2p-1, 0x1.20ec3p0, -0x1.29906p0, 0x1.6f9b82p-3, -0x1.042ea2p0, 0x1.58a2cp0, 0x1.0002cap-1, -0x1.9a656ap0, -0x1.39e734p0, 0x1.a8cadep0, 0x1.34b51cp-1, 0x1.15ee0ap-3, 0x1.8f45a2p-5, 0x1.8931a8p0, -0x1.fd0bb8p0, -0x1.65f0a8p-1, 0x1.05e6f4p0, 0x1.6467cap0, -0x1.eb2228p-3, -0x1.c558c2p-1, 0x1.91c3ecp-1, 0x1.85bf78p-4, -0x1.219bdep0, 0x1.44bd5p0, 0x1.90392p-2, -0x1.77563cp0, 0x1.b2910ap-7, 0x1.81029p-4, -0x1.c02a64p0, -0x1.5275p0, 0x1.a607a6p-1, -0x1.5b9914p0, -0x1.987dap0, 0x1.975ac4p-1, -0x1.79af28p-2, 0x1.f78eccp-1, 0x1.895e4ap0, -0x1.fa8356p0, 0x1.dd94f8p-2, 0x1.34c408p-1, -0x1.fa4a2cp-5, -0x1.76bf36p-2, 0x1.01d706p0, 0x1.f885ap-1, -0x1.0c1498p-3, -0x1.a2465p-3, -0x1.08a49cp0, -0x1.594cap-1, -0x1.a41dccp-1, 0x1.7f0308p0, -0x1.73b27cp0, -0x1.97522p0, -0x1.108bdap-4, -0x1.01a97ep-2, -0x1.08be62p-1, -0x1.9ef766p-2, 0x1.71ffe8p-1, -0x1.cb0dd4p0, 0x1.f50a3ep0, 0x1.e30fc8p-1, -0x1.3b1cfp-3, -0x1.89501p0, 0x1.e3554ap0, -0x1.8fbc42p0, -0x1.bc048p-3, 0x1.70f61cp0, 0x1.f5e27p0, 0x1.f3da7ep-4, -0x1.b386eap0, 0x1.53cd1ap0, 0x1.340088p0, -0x1.bdf1dp-3, 0x1.e344d8p-3, 0x1.6a21f4p0, -0x1.20b98ep-1, 0x1.0be6e4p-1, 0x1.7fa6fep-2, -0x1.474d52p-1, -0x1.ee0bcep0, 0x1.f44a94p0, 0x1.550ccap0, -0x1.a209bep0, 0x1.6f24f8p0, 0x1.a5e40ap-1, -0x1.76353ap-1, 0x1.41242cp0, 0x1.ec3546p-1, -0x1.40cc28p-1, -0x1.bde7bep0, -0x1.3d567p-2, 0x1.844cdap0, -0x1.60197ep0, 0x1.e61e34p-1, -0x1.596aaap0, 0x1.55bc52p-3, 0x1.43fc54p0, 0x1.9ed28ep-1, -0x1.60e146p-1, -0x1.1a6a94p0, -0x1.bcc6ep0, -0x1.143894p0, -0x1.9713a2p0, 0x1.d44204p-3, -0x1.b990cp-1, 0x1.90c35p-1, 0x1.b0361ep0, 0x1.e52d7cp0, 0x1.35c80ep-1, 0x1.f4b2fp-1, 0x1.be61ap-1, 0x1.b979cp0, 0x1.578bccp0, -0x1.008768p0, 0x1.068a2p0, -0x1.cbd912p0, 0x1.d62f9p-1, 0x1.cf23a6p-2, -0x1.6ca072p-4, -0x1.5ebfe4p0, -0x1.67e8ap0, 0x1.7e17cep-2, 0x1.c5bb36p-2, -0x1.7a4618p0, 0x1.c398aep-1, 0x1.166962p-1, 0x1.12f9a4p-2, 0x1.d950eep-1, -0x1.8dc27ep-1, 0x1.319202p0, 0x1.960b94p0, 0x1.93816cp0, 0x1.655276p0, 0x1.bd8232p-1, -0x1.d1e96ep-3, -0x1.d11d9ap-1, 0x1.9c3034p-2, -0x1.f6a76ap-2, -0x1.42408cp-2, 0x1.0e588p-2, 0x1.5ccd5ap0, -0x1.cc5538p0, 0x1.dab628p-2, 0x1.5d4f7cp-7, 0x1.3edb8ap-1, -0x1.956482p0, 0x1.7e85dp0, 0x1.b0a24p-1, -0x1.449ee6p-1, 0x1.ccc39ap0, -0x1.4f639p0, 0x1.d75424p-2, 0x1.08490ap0, -0x1.aa561cp0, -0x1.93f3dep0, -0x1.07621ap-1, -0x1.c82ffcp0, -0x1.c03896p0, -0x1.83896ep0, 0x1.dbd482p-1, -0x1.0cedc6p0, -0x1.fda356p0, -0x1.fb3886p-1, -0x1.d90ba4p-3, 0x1.826dfep0, -0x1.7af602p-1, -0x1.d94f02p0, 0x1.9f4ep0, -0x1.4a0e5cp-7, 0x1.836ba8p0, 0x1.943ba2p0, -0x1.c3303p0, 0x1.935aecp-2, 0x1.13b4c8p0, 0x1.890696p-2, 0x1.441178p0, -0x1.17e0bap-1, -0x1.f2c3f8p-2, -0x1.70e538p0, -0x1.29ee9cp0, -0x1.7c7c4cp0, 0x1.f27e98p-2, 0x1.4b3644p-3, 0x1.f6686cp0, -0x1.e57c16p0, -0x1.6774eep0, 0x1.6f288ap0, 0x1.ed0252p-1, 0x1.0b2f9cp-4, 0x1.81d338p0, 0x1.983174p-1, -0x1.651288p0, 0x1.17a304p-2, 0x1.c73aa2p0, -0x1.da879ap0, -0x1.e20924p-1, -0x1.afa7d8p0, 0x1.a7c666p0, 0x1.276a8ap-2, -0x1.c60cep0, -0x1.1ce5ep-1, 0x1.dd595cp0, -0x1.dceb44p0, -0x1.66636ep-1, 0x1.4cb9fep0, -0x1.7d8ed2p-2, -0x1.604fdep0, 0x1.7793a2p0, -0x1.95ff58p-2, -0x1.05c61ap0, 0x1.181744p-4, -0x1.e20a78p0, 0x1.60577p-3, 0x1.230692p0, -0x1.0082f8p0, 0x1.4b6d2p0, -0x1.0928d6p0, 0x1.bf2ecep0, 0x1.d3f20cp-1, 0x1.1027e6p-3, 0x1.1a441ep-1, 0x1.84cccap-3, -0x1.ac4d6cp-1, -0x1.498ccap0, 0x1.1ad018p0, -0x1.4117dap0, 0x1.305918p0, -0x1.f00f7p0, 0x1.bf1df2p-2, -0x1.e8e01ep0, -0x1.64a396p0, 0x1.b8ecfp-3, 0x1.fa87fp-1, 0x1.362778p-4, 0x1.0d66fep0, 0x1.482b36p0, 0x1.e530b8p0, 0x1.1a006p-1, 0x1.f153aap0, -0x1.233acap0, 0x1.9dbc9p0, 0x1.168abap-1, 0x1.9d11f2p0, -0x1.28af84p0, -0x1.ff9ca2p0, 0x1.dff044p-1, -0x1.2e098ap-1, 0x1.071064p-1, 0x1.d7f038p0, -0x1.c691dep0, 0x1.5515d8p-2, -0x1.9375aap-3, -0x1.cf680ap-2, 0x1.2a160ep0, 0x1.fd6e2p-4, -0x1.68506p-1, -0x1.d5ba36p-1, 0x1.35b544p0, -0x1.718214p0, 0x1.0798cap-1, 0x1.cb3dbep0, 0x1.f0bb9p0, -0x1.24c194p0, -0x1.b85cd4p-1, 0x1.b26d7p-2, -0x1.2be8a6p0, 0x1.ec30bp-2, -0x1.5b97e8p0, 0x1.bc266ep-1, -0x1.d6912cp-4, 0x1.5f6458p0, -0x1.affd3cp-2, 0x1.8f40bap-2, -0x1.29d814p-1, -0x1.73641ep-1, 0x1.b5f5d6p-1, -0x1.bbf884p0, -0x1.c851ccp0, 0x1.ed372p-3, -0x1.42c182p0, 0x1.6d1e5p0, 0x1.870cfap0, -0x1.09ce72p-1, -0x1.1703d2p0, -0x1.11012ap0, 0x1.262f72p-2, -0x1.8856dap0, 0x1.3d63d8p-2, -0x1.627ce6p0, 0x1.6b0ef8p0, -0x1.d71774p0, -0x1.0b9a2p0, 0x1.a5028ep-2, -0x1.f3a3bcp0, 0x1.fe14ep0, 0x1.442612p0, -0x1.5c20c2p-1, 0x1.044caep0, 0x1.45428cp0, 0x1.b3ad52p0, 0x1.6cd838p0, 0x1.f9c5f2p0, 0x1.afded2p0, -0x1.5eec32p-1, 0x1.e4a01p-2, -0x1.ffd5eap0, -0x1.61876ep0, -0x1.384e0cp-1, -0x1.3168eap0, 0x1.e6ee46p-3, 0x1.6f753ap-1, 0x1.405c4cp0, -0x1.b7fa9ap-1, -0x1.63b652p0, 0x1.3dc5fap-1, -0x1.20b1ccp-1, -0x1.e789a2p0, 0x1.f6d5d8p-1, -0x1.b1408ap0, 0x1.76cc3cp-3, -0x1.0046c8p-2, 0x1.fefcaep-1, -0x1.fcff28p0, -0x1.f541c8p-3, -0x1.105c7ep-2, -0x1.b08f4cp0, -0x1.343b9ap-1, -0x1.c159f4p0, 0x1.b333c8p0, -0x1.3d2ef4p0, 0x1.4ebdc8p0, -0x1.e91e26p-2, -0x1.f5dd16p-3, 0x1.bd31cap0, -0x1.1d4de4p0, 0x1.188fa4p-7, 0x1.991d04p-1, 0x1.73a03p0, 0x1.81fb98p0, 0x1.d2f708p0, -0x1.f37dc8p-1, -0x1.4f5a5ap-1, 0x1.1524b8p0, -0x1.bcf8a4p0, -0x1.a1ba1p-1, 0x1.ab44acp-2, 0x1.d90872p0, -0x1.ec793cp0, 0x1.5a71cap-2, 0x1.e0389p-1, -0x1.11e496p-1, -0x1.13ab14p-2, -0x1.b2ecfcp0, -0x1.c00ce6p0, 0x1.13a37p0, 0x1.5c58acp-1, -0x1.8d5864p-1, -0x1.bc25dcp-4, -0x1.8d257ep0, 0x1.281004p-3, 0x1.229168p0, -0x1.5f3922p0, 0x1.51e4bp0, -0x1.6bcb84p-3, 0x1.2a8c28p0, -0x1.898e88p0, 0x1.7932f6p0, -0x1.ef09dcp0, 0x1.498bfap0, 0x1.7977d8p0, -0x1.deb64ep0, 0x1.44f29ep0, 0x1.d17492p0, -0x1.a29b92p0, -0x1.6031dcp-2, -0x1.ed1c6p0, -0x1.fe79p-1, -0x1.c55f68p-4, 0x1.7bb412p0, 0x1.1585bcp-1, -0x1.8d0d44p-4, 0x1.52126cp-1, -0x1.813976p-2, -0x1.281e9p-1, 0x1.44789p-1, 0x1.117e84p-1, -0x1.e6c462p0, 0x1.1e0d7ep0, -0x1.70131cp-1, 0x1.07e106p0, 0x1.889f4cp-1, -0x1.3dc684p0, -0x1.5764a8p-1, -0x1.1ac952p-2, 0x1.50d04p-4, -0x1.e9055p0, -0x1.2823f2p0, 0x1.8803fcp0, -0x1.677b1ep-2, 0x1.12f6c8p0, 0x1.1b6328p0, 0x1.27586cp-1, -0x1.ad34fp-1, -0x1.1efde8p-2, -0x1.1a17bp0, -0x1.a72feap-1, -0x1.eb8546p-2, 0x1.4c525ap-1, -0x1.9ce048p0, 0x1.55927cp0, 0x1.923d56p-1, 0x1.9ecf76p0, 0x1.12c5dap0, -0x1.7cbe56p0, 0x1.50362ap-3, 0x1.0eec7cp0, 0x1.5b5cdap0, 0x1.ef3c48p-1, 0x1.e36d44p0, 0x1.9a3e96p-1, -0x1.bb4d72p0, -0x1.f406aap-1, 0x1.219b7cp0, 0x1.dba176p-2, -0x1.d0921p-2, -0x1.35a318p-3, -0x1.8d6012p-9, 0x1.ef803ep-1, -0x1.6df9f6p-1, 0x1.d90612p0, -0x1.ad2e5p-1, 0x1.6ea3c2p-1, -0x1.e9101ep-2, 0x1.404812p0, 0x1.4185c8p-3, -0x1.5ae84cp-1, 0x1.d65a1ap-1, 0x1.1140e2p-1, 0x1.e0a828p0, -0x1.f53614p-1, 0x1.8cf7acp-1, 0x1.c0c0ap-1, 0x1.2d8944p-1, 0x1.3fb6c6p0, -0x1.69ee68p-2, 0x1.dcc79ap0, 0x1.c83a78p0, 0x1.4cffcp0, -0x1.4a59e8p0, 0x1.ec6502p-3, -0x1.ef6554p0, -0x1.e0b454p-2, 0x1.c00dd8p0, 0x1.fbc966p0, -0x1.1cc604p0, 0x1.5ce66ep-1, -0x1.9b267cp-1, 0x1.798eecp0, -0x1.9b391ap-6, 0x1.c4470cp0, 0x1.7d955cp-2, 0x1.70c6bcp0, 0x1.d51208p-1, 0x1.fa361ap0, -0x1.903eaep0, -0x1.27d78ap-1, 0x1.2bea14p-2, 0x1.104126p-1, -0x1.8a1cf2p-1, -0x1.10b686p-1, 0x1.a96058p0, -0x1.3b0a42p0, -0x1.0f6a54p-2, 0x1.511d0ap-2, 0x1.f819bcp0, -0x1.32bf6p-1, 0x1.e9afdcp-2, -0x1.9c9a7ap-1, -0x1.0be088p0, 0x1.e8d76ap-2, -0x1.7b1604p0, -0x1.60ccdep0, 0x1.f85838p0, 0x1.615308p0, 0x1.16e382p0, 0x1.ec5c26p0, 0x1.b1517p0, 0x1.bd9c1ep-5, 0x1.dbae64p0, -0x1.b11316p0, -0x1.033e08p0, -0x1.79bb9p-2, 0x1.572e42p-1, 0x1.68b1cep0, -0x1.c434a6p0, 0x1.f325ap-1, 0x1.243162p0, 0x1.516a06p-3, 0x1.b45208p-2, -0x1.0c3adep0, 0x1.b5fa2cp0, -0x1.375a4p-1, 0x1.2b24ccp0, 0x1.fc6f1ep0, 0x1.78feacp0, 0x1.2addcp-2, -0x1.ecfc92p-2, -0x1.b4856ep0, -0x1.e629e6p0, -0x1.ef75ecp-1, 0x1.0096c4p-4, 0x1.655ee8p0, 0x1.7c9bb4p-1, 0x1.ccfed4p0, 0x1.5426f6p-1, 0x1.b86ddep-1, -0x1.b7927p0, -0x1.59695p0, -0x1.43d988p0, 0x1.c9d612p0, -0x1.fc02a2p0, -0x1.c46f88p-4, -0x1.e35608p0, 0x1.f1fe86p0, 0x1.6d2518p-2, 0x1.102edcp-4, 0x1.d1ee6cp0, 0x1.87e224p-1, -0x1.b4a23p-1, -0x1.a14fep-1, 0x1.c986fap-1, 0x1.34b262p0, 0x1.26ea6ep-1, -0x1.6f9d14p-3, -0x1.e01ff2p0, -0x1.f8bf5cp-1, 0x1.dba7e2p-1, 0x1.1a2c22p-1, -0x1.a1409cp-1, -0x1.721fa2p0, -0x1.d4d34ep0, 0x1.a3393ap-1, 0x1.ed58ccp0, 0x1.bb4138p-1, -0x1.055ee4p-2, -0x1.15bb16p0, -0x1.6be264p0, 0x1.6ba13ep0, -0x1.a351ep-1, 0x1.4dfda4p0, -0x1.a95c4ap0, 0x1.21d8d2p0, -0x1.82ca06p-1, 0x1.3ef6cp0, 0x1.b745f2p-1, 0x1.76ce36p0, -0x1.69caf6p-3, -0x1.435df8p0, 0x1.966ba2p-1, 0x1.2a9d48p0, 0x1.47db8p0, 0x1.dad3b2p-1, 0x1.8a87e4p0, 0x1.ec9502p-1, 0x1.c51f1p0, 0x1.b7b812p-1, 0x1.d0a104p-1, -0x1.bab2d4p-1, 0x1.b6eee2p-1, 0x1.bf07e8p-1, -0x1.1cbbb4p0, -0x1.1488f4p-3, -0x1.ca5f9p0, 0x1.a39b6ep-1, -0x1.f4c94ap-1, -0x1.e66b34p0, -0x1.97d9fap-1, -0x1.33f5fap0, -0x1.17568ap0, -0x1.a207ep0, 0x1.a480acp-1, -0x1.611702p0, -0x1.2b8cecp-2, -0x1.b960b4p0, 0x1.e1bff6p-2, 0x1.fa027p-1, 0x1.8d09dap0, -0x1.7266d2p0, 0x1.5fea02p0, 0x1.4df992p-2, 0x1.c73be2p0, 0x1.d23e84p-1, -0x1.2d0baap0, -0x1.cd4132p0, 0x1.ad14f8p-1, -0x1.21e69ep0, -0x1.f4e21cp-1, 0x1.f27f8cp-3, -0x1.13794p-2, 0x1.3a8faep-1, -0x1.5e231ap-1, 0x1.49446ap-1, 0x1.0d33fp0, -0x1.5f2494p-1, 0x1.dd653p-1, -0x1.94cb62p0, -0x1.020894p0, 0x1.f90f8p0, 0x1.c6e74p-1, 0x1.1dcb28p0, 0x1.b93828p0, 0x1.360fb4p0, -0x1.64cc22p-1, 0x1.c0125cp-1, -0x1.6923b6p-1, 0x1.3f0f28p0, -0x1.90aefep0, -0x1.e8e1f4p-2, -0x1.03ca6ep0, -0x1.4ef296p-2, -0x1.b93592p-2, 0x1.0db428p-4, -0x1.0d76cap0, 0x1.849192p-2, -0x1.f74424p-1, 0x1.e901dp0, -0x1.6ff56p0, -0x1.6f3b7ep-2, -0x1.457622p0, -0x1.386dbp0, -0x1.a3961ep0, -0x1.ca220ep0, -0x1.249fb8p-1, -0x1.7320ccp0, 0x1.4508ep0, 0x1.bd9f76p0, 0x1.288b86p-4, 0x1.a42f9cp0, -0x1.446408p0, 0x1.dde32ap0, 0x1.fa9d9ep0, 0x1.eb50d8p-1, 0x1.24f6b6p0, -0x1.3fecacp-1, 0x1.d72968p0, 0x1.18228cp-2, 0x1.e1148ap-1, -0x1.6b5342p0, 0x1.685f44p-1, -0x1.e76c06p0, -0x1.3f653ap0, 0x1.6aa484p0, 0x1.06831p-4, 0x1.69d41ep0, 0x1.e262c6p-2, -0x1.006b4cp0, -0x1.2667dep-1, 0x1.0ce03cp-1, 0x1.36ebe8p-1, -0x1.066bfap0, 0x1.bbe7e2p-2, -0x1.3f33bp-2, 0x1.b1641cp-1, -0x1.e1af8ep-2, -0x1.c05a64p0, -0x1.f6ea6ap0, 0x1.ccf3d2p0, -0x1.5fa32cp0, 0x1.f26208p-1, 0x1.90113ap0, 0x1.b7e26ap0, 0x1.bfd39cp-1, 0x1.07d3dep-2, -0x1.2253e2p0, -0x1.052ce2p0, -0x1.6c9ba2p0, -0x1.60809cp-1, 0x1.177d5p0, 0x1.0959a8p-2, 0x1.07e854p-1, 0x1.716d2p-1, 0x1.7a09ap-1, -0x1.58d5f4p0, -0x1.5df1dep-5, -0x1.4a9bdp0, 0x1.d4660cp0, -0x1.1aa564p-2, -0x1.7e5efcp-5, 0x1.31ce06p-1, 0x1.e341d2p-1, -0x1.b0c9aep0, -0x1.c397a4p-1, -0x1.6f576ep-1, -0x1.6e12d6p0, 0x1.8e9cf2p0, 0x1.7535a8p-2, -0x1.5dfe38p0, -0x1.ef0bcep-3, -0x1.3ad09p-5, -0x1.888a18p0, 0x1.40df18p0, -0x1.4367f8p-1, -0x1.76b0a6p0, -0x1.b29c1ap0, -0x1.fc137ap0, 0x1.95fc1p0, 0x1.5a286ap-6, -0x1.871d9ep-1, 0x1.e7ddb4p0, 0x1.bac01ep0, -0x1.c07ec4p0, -0x1.ebbfdap0, 0x1.29fa0cp0, -0x1.034dep0, -0x1.71e9e4p0, 0x1.4f1becp-1, -0x1.0f11cep-1, 0x1.0e287ap-5, 0x1.762af4p-1, -0x1.afb344p0, -0x1.64d986p0, -0x1.52961p-1, -0x1.b70c02p-3, -0x1.339176p0, 0x1.ae68fap0, 0x1.bc3be4p0, -0x1.91095cp-1, -0x1.a403c2p-1, 0x1.7e1b2p0, -0x1.852206p0, 0x1.8cf658p0, -0x1.b80f36p-2, 0x1.4ff8f8p-2, 0x1.a6f342p0, 0x1.17b558p0, -0x1.1f868ap-1, 0x1.dc23f6p0, 0x1.04f6ap-2, 0x1.dee01ap-3, 0x1.0c902p-1, 0x1.3668cep-4, -0x1.f351f4p-3, 0x1.f58afap0, 0x1.63db8cp-1, 0x1.7e8e3ap0, 0x1.23133ap0, -0x1.51292ep0, 0x1.8aa8d6p0, -0x1.8681acp0, 0x1.63f5a8p-1, -0x1.e637d4p0, 0x1.73654cp-6, 0x1.925c0ep-1, -0x1.0b17ccp-3, 0x1.02b8ecp-2, -0x1.9e4282p0, 0x1.ca5a98p0, -0x1.5c6fe6p0, -0x1.ee1146p-2, -0x1.d0694cp0, -0x1.17d31ep0, -0x1.58447ap-2, 0x1.852ccep-1, -0x1.cb824p-2, -0x1.1a0d88p-1, 0x1.fa4574p0, -0x1.f714e6p-1, 0x1.2bd514p0, 0x1.8708f8p-2, -0x1.158d8p0, -0x1.ffbcb6p0, 0x1.84d5a8p0, 0x1.1c17aep-5, 0x1.b46cf4p-2, -0x1.15ec24p-1, -0x1.3435dp-1, -0x1.9674eep0, 0x1.4ea01ep0, 0x1.d3e4aep-2, 0x1.276902p-2, -0x1.b3407ap-1, 0x1.9f32b6p-1, -0x1.5518d4p-4, 0x1.42a9dep0, 0x1.d4d3f8p0, 0x1.eafa72p-3, -0x1.2655c8p0, 0x1.c53d4ep0, 0x1.e2608cp0, 0x1.031dcap-4, 0x1.560a7ap-4, -0x1.feb7eap-2, -0x1.aff3eep-2, 0x1.17f8a4p-2, -0x1.0f998p-5, 0x1.84e994p-1, -0x1.33f7e4p0, 0x1.3e7584p-1, 0x1.dc6cdp-2, -0x1.4d651cp0, 0x1.635f32p0, 0x1.dee16p0, 0x1.82ad7cp-2, -0x1.fc4b5ap0, 0x1.9c44ecp-1, 0x1.c1447ap0, -0x1.923498p0, -0x1.15e582p0, 0x1.0c674ap-2, -0x1.fcc012p-4, 0x1.15f0ap0, 0x1.fda48ep-1, -0x1.facbecp0, 0x1.654682p-3, 0x1.0c54ap0, -0x1.e7b202p0, 0x1.c916a4p0, 0x1.00b7c8p0, 0x1.c6273cp-2, -0x1.93c7eap0, -0x1.f7cbf6p-2, -0x1.c237b6p0, -0x1.a67694p-1, -0x1.85027ep-1, -0x1.241f8ap0, -0x1.c560dp-4, 0x1.5cf176p0, -0x1.e5cf14p-3, -0x1.eb156ap-2, 0x1.da5646p-2, 0x1.6f18e2p0, -0x1.c413c6p0, 0x1.a0f312p0, 0x1.65afacp-1, -0x1.cfe8e2p0, 0x1.0c1036p-1, 0x1.1fdf8ep-2, -0x1.61fe34p0, 0x1.45171p-3, 0x1.bfa9d2p-4, -0x1.ccaf9ap-1, 0x1.a20936p-1, 0x1.dd6c3p0, -0x1.e6b47cp-2, -0x1.5ff522p0, 0x1.660b66p0, 0x1.744b82p-3, 0x1.374e06p-1, 0x1.beda1ep0, -0x1.e9273p-1, 0x1.a4c4b4p-1, 0x1.7a6d92p-1, 0x1.5d7ac8p-1, -0x1.c36c5cp0, -0x1.cac9a6p0, 0x1.e2f4ep0, 0x1.9c5acep-1, -0x1.372788p-2, 0x1.816dbcp-1, -0x1.5faad8p0, -0x1.c0a1a4p0, 0x1.35942p0, -0x1.48b08cp-1, 0x1.107612p-3, -0x1.9717fp-2, 0x1.9f188p0, 0x1.e0ae2ep-1, -0x1.0d5478p-2, 0x1.9b02e2p-1, 0x1.aa8a4ap-3, -0x1.f97324p0, -0x1.91d326p0, -0x1.192714p0, 0x1.f659e2p-2, -0x1.55686ap-2, 0x1.cc0bcep0, 0x1.0015d6p-1, -0x1.41a7bcp0 };
float keras_activation_3_test6_array[6] = { 0x1.ae026cp-3, 0x1.48e88ap-5, 0x1.a5fac8p-6, 0x1.542c9p-4, 0x1.379596p-1, 0x1.0a5df2p-5 };
float c_activation_3_test6_array[6];
float test7_dense_input_input_array[2622] = { 0x1.0b5c34p0, 0x1.72fd22p-2, 0x1.9fcf9ap-2, 0x1.838cbp-2, -0x1.71669cp0, -0x1.a8d27ap-1, 0x1.a7dbeep0, 0x1.d2d1dp0, 0x1.fe6e78p-1, 0x1.6f2d12p0, -0x1.bdfc86p-2, -0x1.271018p-1, 0x1.9ed692p-2, 0x1.cb2d58p0, 0x1.839fdcp0, -0x1.c58a96p0, 0x1.805006p0, -0x1.a98fdcp-4, -0x1.f71044p0, -0x1.e70066p-1, -0x1.f37f7p0, 0x1.384ddep-5, -0x1.b75eb6p0, 0x1.fd39b8p0, -0x1.c605a8p0, -0x1.5afc08p-2, 0x1.edf498p0, -0x1.4dfb94p-1, 0x1.54334ap0, -0x1.f2bd0ep0, -0x1.ad1d8cp0, -0x1.ca9ce4p-1, 0x1.67531cp0, 0x1.601ba4p-2, 0x1.4871d4p-1, 0x1.8e4dfap0, -0x1.5ff858p0, 0x1.025056p0, -0x1.ff3d5ep-3, 0x1.a0ecdcp-2, 0x1.f8241ep-8, 0x1.50b2fcp0, -0x1.d1f032p0, -0x1.bc89cp-1, 0x1.466f84p-1, -0x1.ce1b16p-1, 0x1.b66dcp-2, -0x1.e97e8ap-1, 0x1.da58b6p-2, 0x1.8bc36ep-4, 0x1.1602bp-4, 0x1.65c772p-2, -0x1.c150b4p0, -0x1.dc124p-3, 0x1.7c6588p0, 0x1.acfd1ep0, -0x1.16ec1ap-4, -0x1.a14adep0, 0x1.695f8cp-2, 0x1.159b2ep0, 0x1.34aedcp0, 0x1.dff34ap0, -0x1.0785b8p-3, -0x1.6d41ep-1, -0x1.95d9bap0, -0x1.d2eaa8p-1, -0x1.29c35ep0, 0x1.90294p-1, 0x1.85066ep0, 0x1.d7873ep-1, -0x1.f8b4bcp0, -0x1.a39a9p-5, -0x1.cf46dap0, -0x1.d583d6p-4, -0x1.a3560ap0, -0x1.dbdb6ep-1, 0x1.9e67c6p-2, -0x1.d70608p0, 0x1.cdcd58p-1, 0x1.687f28p-2, 0x1.dcdc82p0, 0x1.be54d6p-3, 0x1.ff402ap-1, -0x1.a59c7p0, -0x1.1430f4p-1, -0x1.0365dcp-8, 0x1.e51bcp0, -0x1.540a26p0, 0x1.291114p-1, 0x1.183d9ap0, 0x1.7ae5c4p-2, -0x1.13b0dcp0, 0x1.c00e2cp-2, -0x1.ae702p-1, 0x1.ee2eeap0, 0x1.a34bc8p0, -0x1.77a488p0, -0x1.9ae392p0, -0x1.c79624p0, -0x1.13f322p-1, 0x1.226788p-4, -0x1.2122ecp0, -0x1.76dcbp-3, -0x1.197f48p-3, -0x1.6ce032p0, -0x1.40b79ep0, -0x1.318efcp-1, -0x1.5dbf8cp-3, -0x1.67867ap-11, -0x1.b4872ap0, 0x1.199e1cp-1, -0x1.6ca0aap0, 0x1.456d54p0, -0x1.bfe0bcp0, 0x1.75106p-2, 0x1.b8e018p-4, -0x1.a45316p-2, 0x1.ff9cb2p0, 0x1.f069e6p0, 0x1.20f7dcp-1, -0x1.7852fcp0, 0x1.478e2cp0, -0x1.3187acp0, 0x1.c13746p-1, -0x1.e5687p-3, -0x1.13cd26p0, -0x1.fad524p-2, 0x1.d56f1cp0, 0x1.5e704cp0, -0x1.1ea67cp0, 0x1.6cc83cp0, 0x1.233ffcp-6, 0x1.a81a3ap0, 0x1.155336p-1, 0x1.fcaaf6p0, 0x1.6a8fdcp0, -0x1.19beb4p-2, 0x1.25d438p-1, 0x1.daa612p-1, 0x1.6d62ap0, -0x1.0b6e16p0, 0x1.2be4ecp0, -0x1.d34566p0, 0x1.3e1efap-1, -0x1.159c1ap0, -0x1.656854p0, -0x1.71ea7cp-1, -0x1.33bd66p-4, -0x1.6a2b26p-2, 0x1.95c5fap-1, 0x1.bb7034p-1, -0x1.45cd06p0, 0x1.2867p0, -0x1.af8a96p-1, 0x1.e6e0e8p0, -0x1.62a2e8p0, -0x1.0bc5fcp0, -0x1.5535c2p-3, -0x1.095c84p0, 0x1.1d65f8p-3, -0x1.b8ed8p0, 0x1.096cfcp0, 0x1.84303p-1, -0x1.7656b8p0, -0x1.d79428p-1, -0x1.ff50f4p-1, 0x1.5f11fap0, -0x1.9a1ae2p0, -0x1.829156p-1, -0x1.166914p0, -0x1.955e52p0, 0x1.e917cp-2, 0x1.093ccap-2, 0x1.ea2bf6p0, 0x1.eacab8p0, 0x1.c9a136p0, 0x1.b58f8p0, -0x1.a1f9p-3, -0x1.04b32p0, 0x1.52f61ep-1, 0x1.ee0482p0, 0x1.ae34bcp-1, -0x1.e867dep0, -0x1.03b894p-1, 0x1.94503p0, -0x1.d9ba18p-3, -0x1.5ba428p0, 0x1.d42ae6p0, -0x1.248468p-2, 0x1.a086e4p-3, -0x1.6554fp-2, 0x1.2b92aep-1, 0x1.1f5ce8p-1, 0x1.8a6bcp0, 0x1.bf872cp0, 0x1.d6851ap-1, 0x1.f4c762p0, 0x1.714ed8p-3, 0x1.43d444p0, 0x1.a390e2p-2, -0x1.859fd4p0, 0x1.b7d826p0, -0x1.b1fd92p0, 0x1.8ca216p-3, -0x1.98da42p0, 0x1.3eb44p-2, -0x1.4972fcp-3, 0x1.1a9968p0, 0x1.9f75acp0, -0x1.213376p-5, 0x1.3a5502p-1, 0x1.a2b6e4p-1, -0x1.0c0f1cp-2, -0x1.14b024p-1, 0x1.dc5ceep-3, 0x1.effb9ep0, 0x1.567624p0, 0x1.0fd464p-3, 0x1.ab1204p0, 0x1.79eca4p-4, 0x1.ae674p0, 0x1.5ffbdep-1, -0x1.ca7194p0, 0x1.4fe198p-2, 0x1.94a798p0, 0x1.2acdb4p0, -0x1.31ed02p0, 0x1.32900ap0, 0x1.a34a08p0, 0x1.ddcd06p-2, -0x1.84dc04p-1, -0x1.967664p-1, -0x1.78a56p0, 0x1.08cdeep0, 0x1.17aa46p0, 0x1.7665f4p-1, -0x1.a06c2p-3, -0x1.b1375p0, 0x1.3aacc6p-2, -0x1.0ff2bep0, -0x1.fd46b2p0, -0x1.8c6906p0, -0x1.0afb3ap0, 0x1.1fc2f6p-1, -0x1.4ce1b2p-3, -0x1.81eae8p-2, -0x1.cdd8b2p0, 0x1.009772p0, -0x1.cfe00cp-2, -0x1.01086ep-2, 0x1.9193e6p0, 0x1.ce2458p-1, 0x1.7ce926p0, 0x1.3bdb3cp0, -0x1.1dff8ep-2, -0x1.362652p-2, 0x1.ca3596p0, -0x1.a7a85ep0, -0x1.b39434p-1, 0x1.e03a08p0, -0x1.8106c8p0, 0x1.8ed3a8p-3, -0x1.d889e2p0, 0x1.731392p-2, -0x1.661fd2p-1, -0x1.9923a2p0, 0x1.3574dcp-1, 0x1.182794p-1, 0x1.9ac36ep0, -0x1.515b1p-2, -0x1.60836cp0, 0x1.11ba8ep-1, -0x1.f8b774p0, 0x1.1cc2dep0, 0x1.33ca68p-1, 0x1.174578p-2, -0x1.4dacb8p0, 0x1.252dc6p0, -0x1.e6f81ap0, -0x1.265e24p-4, -0x1.96587cp0, -0x1.1fceeep-1, 0x1.cfcb94p0, -0x1.906bc4p-1, -0x1.6bc37p-2, 0x1.a05c28p-4, 0x1.4e5b38p-1, 0x1.0248p0, 0x1.561d06p-4, -0x1.6f34dp0, -0x1.508c04p0, 0x1.7f0098p0, 0x1.edf67ap-2, 0x1.7aca26p-1, -0x1.e34428p0, -0x1.29bc1cp-4, -0x1.f539e2p-1, 0x1.9eb666p-1, 0x1.797092p0, 0x1.1801ccp0, 0x1.2d2d28p0, -0x1.9be794p-7, 0x1.ffa842p0, 0x1.cf5d72p0, -0x1.014262p0, 0x1.bcc282p-5, -0x1.58e942p-5, 0x1.4b68aap-2, 0x1.0ad274p-1, 0x1.943786p0, -0x1.30f98cp0, 0x1.5404dep0, 0x1.35cdaep-3, -0x1.b064e4p-1, -0x1.4c6a7ap-1, -0x1.0f05d6p0, 0x1.12b40cp-1, -0x1.a6c08p0, 0x1.1c822ap0, 0x1.c82576p0, 0x1.47b6a8p-5, -0x1.3ab9b2p-2, 0x1.267a58p-4, -0x1.ee5346p0, 0x1.f4e9bp-2, 0x1.521fap-1, -0x1.5d2508p0, 0x1.7053d6p0, -0x1.113b16p-1, 0x1.10d7ap-4, 0x1.db9dd8p0, -0x1.661a8cp0, 0x1.6274fp-1, -0x1.fe473ap0, -0x1.a5045ap0, 0x1.7d2e26p0, 0x1.1a933p-6, -0x1.0fcbaap0, 0x1.4f5854p0, 0x1.1620e6p0, 0x1.51c4bap-1, 0x1.78ff2ap-1, 0x1.bedb8cp-1, -0x1.6229a6p0, -0x1.e9e9d6p0, 0x1.4a3548p0, -0x1.1c216cp-3, 0x1.5c2a58p0, -0x1.7ab7bap-2, -0x1.9f7d1p0, 0x1.d0bd82p-1, 0x1.dae848p-1, -0x1.adde56p0, 0x1.26aea2p0, 0x1.e8eab8p0, 0x1.f8cd58p-1, -0x1.d6650ep-1, -0x1.1927f2p0, 0x1.938b9cp0, -0x1.e1a78p-1, -0x1.fb060ep0, -0x1.94fe14p0, 0x1.b353acp0, -0x1.2ce738p0, 0x1.16bbc8p0, 0x1.c00c0ap0, 0x1.ec551ep0, -0x1.e2cc54p-1, 0x1.4f7ebap0, -0x1.3b0678p-2, -0x1.d916b4p0, 0x1.09592cp-3, -0x1.710fc4p-1, 0x1.1dcddp-3, 0x1.eeb672p-3, -0x1.ca9a02p-1, 0x1.8fc4e8p0, 0x1.278268p0, -0x1.57a87ap-2, -0x1.7ad536p0, 0x1.dc464ep0, -0x1.7fca8cp0, -0x1.963668p-1, -0x1.85e5d2p-1, -0x1.df743p0, 0x1.7e893ap0, 0x1.cf49fep-12, -0x1.15c1b4p-3, -0x1.985fe8p0, -0x1.2178ep0, -0x1.f9055ep0, -0x1.acb862p-1, -0x1.9b982p-1, 0x1.01665p0, 0x1.232c22p0, -0x1.b54296p-3, -0x1.5d6c76p0, -0x1.8f5feep0, -0x1.ed49f8p-1, -0x1.120d3ap-3, -0x1.7095bep0, -0x1.80a73ap-1, 0x1.935768p0, -0x1.18aebap0, -0x1.11c27cp0, -0x1.50df66p0, 0x1.ca58eep0, 0x1.8c1d58p0, 0x1.a00ab8p0, 0x1.9f8b82p0, 0x1.68a16p-6, -0x1.7f411ap-1, 0x1.f6d9ep-1, 0x1.f29b76p0, 0x1.addee6p0, -0x1.815586p0, -0x1.e397b4p-2, 0x1.437e2ap0, 0x1.c6f7f8p-1, 0x1.b90d6cp-1, -0x1.9a4b5ep0, 0x1.32f496p-1, 0x1.43f53p-1, -0x1.19226ap-3, 0x1.b2931p-2, -0x1.47a9dp-1, -0x1.d667dp0, -0x1.188f4p0, 0x1.427792p0, -0x1.92b8fp-1, -0x1.181c2ap0, 0x1.c5712cp0, 0x1.dfe76ep-1, -0x1.aaa414p0, 0x1.0906cap-3, 0x1.8be054p0, -0x1.a2174cp0, -0x1.3b35aep-7, 0x1.5c29d8p-1, 0x1.26078ep-1, -0x1.a5ca76p-1, -0x1.06c732p-4, -0x1.737fb8p0, -0x1.bc4d44p0, 0x1.9a38aep0, -0x1.2612c4p-1, -0x1.edbbe6p0, 0x1.063cd6p0, 0x1.cee82cp0, -0x1.4e7b3ap0, -0x1.9b4f08p0, -0x1.ce5ac4p0, 0x1.a85b0ap-1, 0x1.456b2ap-1, -0x1.a70b28p-4, 0x1.8c1e1p0, 0x1.df9abep-2, -0x1.9ce99ep-1, 0x1.6e027ep0, 0x1.26cb96p-1, -0x1.17126ep-1, 0x1.f3c0e2p-3, -0x1.2e3382p-1, 0x1.b29a06p0, -0x1.842002p0, 0x1.52f214p-1, -0x1.51e238p0, -0x1.856708p-1, -0x1.56b038p-3, 0x1.0c13a2p-3, -0x1.d97b7cp-3, 0x1.ccae46p-2, 0x1.976ddp0, 0x1.0bf78ap0, 0x1.ca5432p0, 0x1.a4cd64p0, -0x1.7031dep0, -0x1.5120b2p0, -0x1.083a34p0, 0x1.dd4f68p-3, 0x1.1bc9ep0, 0x1.03641ap-3, 0x1.97855p0, -0x1.9547d4p0, 0x1.a568f8p-3, 0x1.59507cp0, 0x1.a0dcaap0, -0x1.1e56bep-1, 0x1.d5fc36p0, 0x1.16559ap0, 0x1.353652p-1, -0x1.753ed2p0, -0x1.e5522cp-1, -0x1.4d67cap0, 0x1.28f63ap0, 0x1.646978p0, 0x1.3e5fb4p0, 0x1.164062p-1, 0x1.2110aap-1, 0x1.a8bd38p0, -0x1.99b1aap-1, -0x1.576016p0, -0x1.faf398p0, 0x1.313816p0, 0x1.719566p-1, 0x1.623588p0, -0x1.f44b5p-1, -0x1.cd64aep-6, -0x1.7e66fcp-1, 0x1.73944ep-2, -0x1.8dfc9p-1, 0x1.074a1ap0, 0x1.785788p-1, 0x1.5c8392p-2, -0x1.1e9b76p-1, 0x1.e9df74p-1, 0x1.84d67ep0, 0x1.dae06ap0, 0x1.8c36f4p-4, 0x1.e05586p-5, 0x1.3bdf56p0, -0x1.0549p-1, -0x1.0bf87ep-3, -0x1.d198eap-1, -0x1.803524p-1, 0x1.0caa0cp0, 0x1.10997cp0, -0x1.7e77eep0, -0x1.c669eep0, 0x1.d0f2a6p0, 0x1.5bc5bep0, -0x1.cec92ap-2, -0x1.e8dd4p-2, 0x1.390284p-1, -0x1.2e3c22p-3, -0x1.561442p-1, -0x1.31c858p0, -0x1.56b18ap-1, 0x1.a03bb4p0, -0x1.cc3c5ap0, -0x1.4c39f8p-2, 0x1.c7d074p-1, 0x1.be53f2p-1, -0x1.520666p0, 0x1.9d1a2p-1, -0x1.a6023p0, -0x1.b9e12p-4, 0x1.ced4cap0, 0x1.2a3344p0, -0x1.33028ap0, -0x1.9b61dap0, 0x1.a7a8fp-1, 0x1.d6a35ap-1, 0x1.6dcadp0, 0x1.a9cef6p-2, -0x1.85159p0, 0x1.61caccp0, 0x1.da8796p-2, -0x1.0923a4p0, -0x1.94e334p0, 0x1.7c47b4p-1, -0x1.d2527ap0, 0x1.d9ffdep0, 0x1.5da9d8p-1, -0x1.48802ap0, -0x1.6ee6cep0, 0x1.7dee74p0, 0x1.6ec498p-2, -0x1.cae7d8p0, -0x1.4462dp0, 0x1.82319p-1, 0x1.b20da4p-1, -0x1.38d06p0, -0x1.838d88p0, 0x1.7b1958p0, -0x1.e3da66p0, 0x1.9ee5d4p0, -0x1.f74b82p0, -0x1.76691ap-1, 0x1.3cabbap-1, 0x1.246344p0, -0x1.fad316p0, 0x1.630aap-1, 0x1.4dbceep-2, -0x1.66e8p0, -0x1.c481dcp0, 0x1.3f84c8p-2, -0x1.2a880ap0, 0x1.ad9268p0, 0x1.0ef336p0, 0x1.59b3fp0, -0x1.685c04p0, 0x1.da9f4p0, -0x1.9b1bb2p0, -0x1.62fc5ap-5, -0x1.e0d6d4p-1, 0x1.e56adap0, 0x1.a4048ep-1, 0x1.1769p-3, -0x1.7f0a9ep0, -0x1.16c7b4p0, -0x1.ce6c12p0, -0x1.6b6b84p-1, -0x1.f54a2cp0, -0x1.58e2e2p-6, -0x1.272598p-3, 0x1.76f7bep-1, -0x1.3cdde6p0, -0x1.04bc2cp0, -0x1.0bebd4p0, 0x1.6a5a04p-2, 0x1.1bb864p-1, 0x1.124c8ep0, -0x1.d5a3fp0, 0x1.b7b486p0, -0x1.6f2c74p0, -0x1.59cf1ap-7, 0x1.63134ep-2, -0x1.384be4p0, -0x1.b01c1cp-8, -0x1.8f25eap0, 0x1.6e8ebep0, 0x1.85f46ep-1, -0x1.c1449cp-1, -0x1.bb0514p0, 0x1.c9d80cp0, -0x1.6a8608p-1, 0x1.dd6ffp-2, -0x1.c1982cp-3, 0x1.28c606p-2, -0x1.ad1edap-4, 0x1.d714a6p0, -0x1.37a972p-2, 0x1.9abcbcp0, 0x1.7ef7e8p0, 0x1.c66936p-1, -0x1.77612ep-1, 0x1.e140fcp-1, -0x1.af059ep0, 0x1.f501e2p0, 0x1.56a5eep0, 0x1.ecf0bcp-1, 0x1.2496a2p-4, -0x1.5113d2p0, 0x1.51f466p-8, 0x1.a60d44p-1, -0x1.85ec84p0, 0x1.8af0fap0, 0x1.53cccep-1, -0x1.ad25a4p0, 0x1.7921ep0, 0x1.c3366cp-1, 0x1.052b3ap0, -0x1.46782cp0, -0x1.756e04p0, -0x1.f3a012p0, 0x1.792eb2p0, -0x1.ea915p-2, 0x1.ceb108p0, 0x1.9a4236p0, -0x1.454e62p0, -0x1.02bca6p0, -0x1.f5e2aep-6, 0x1.db5622p0, -0x1.1548ap0, -0x1.d1f678p0, 0x1.2a7494p-2, -0x1.82a6e4p0, 0x1.d96e38p-3, 0x1.4efa48p-3, 0x1.e7f9bp-2, 0x1.131128p0, 0x1.30b0fp-9, -0x1.dd4598p0, 0x1.0b068p0, 0x1.fb251ep-1, 0x1.60d4ccp-1, 0x1.4d34fep-1, 0x1.9bbd0ap-3, 0x1.05fabp-2, 0x1.b4179ep0, 0x1.2c212ep0, -0x1.c4778cp-5, 0x1.fb4d4ap0, 0x1.b8e672p0, 0x1.26ffeep-2, -0x1.89c366p0, 0x1.589284p-2, -0x1.363d6ap-1, 0x1.76d912p-4, 0x1.225b22p0, -0x1.05236p-2, 0x1.04ab32p-1, 0x1.d3edaap0, -0x1.a88c7p-1, -0x1.992242p-1, -0x1.f7c124p-1, 0x1.aaa09p-1, -0x1.ce681ap-1, 0x1.8463a4p0, -0x1.5241ecp0, 0x1.5fbbccp-1, -0x1.b946dcp0, -0x1.21ffeep0, 0x1.2c7efp-1, -0x1.95967ep-4, -0x1.7189ep-2, -0x1.752458p-1, 0x1.51f8eap0, -0x1.e19be4p0, 0x1.1e7f0ap-1, 0x1.76d72ep0, 0x1.2f44p-4, -0x1.bdb6cp-2, 0x1.fe1db8p-1, -0x1.82ebeep0, -0x1.a50906p0, 0x1.83b778p-1, -0x1.4b48a2p-3, -0x1.2854d2p0, 0x1.e8ebf8p-2, -0x1.e145e4p-4, 0x1.abac8cp-4, -0x1.f84464p0, -0x1.318112p-2, -0x1.ee1c04p0, 0x1.7eb082p-3, -0x1.4faad2p-1, 0x1.0c1174p0, -0x1.64907cp-5, -0x1.d49498p-1, -0x1.04e006p-1, 0x1.47bbd8p-4, -0x1.8ead24p0, 0x1.73447p-1, -0x1.6c41ccp-5, -0x1.82c708p-1, 0x1.8bd006p0, -0x1.ab9p0, 0x1.b0c13p0, 0x1.cc57c4p-1, 0x1.20faap0, -0x1.d4f242p0, -0x1.7b476cp0, 0x1.f1e7f8p-6, 0x1.f3fb6ap0, 0x1.3c8b14p0, -0x1.5463f6p-1, -0x1.6ca7b4p0, 0x1.4e62bp0, -0x1.d24764p-1, 0x1.d09bf8p-4, 0x1.cae73ep0, -0x1.461312p-3, 0x1.0b91bap0, 0x1.7dcc2ap0, -0x1.9b635ep-1, 0x1.e6707p0, 0x1.619644p-3, 0x1.cda83p-2, -0x1.473376p-1, 0x1.680312p-3, -0x1.3f99bp0, -0x1.f4fdc6p-2, 0x1.908fe8p0, -0x1.385facp-6, -0x1.7b258p0, 0x1.a4bbbcp-2, 0x1.1653ap0, -0x1.d9d528p-4, -0x1.e84acap-9, 0x1.7ba922p0, 0x1.fb5e9ep0, -0x1.e8972ap0, -0x1.deee7p-1, -0x1.6f1beap0, 0x1.a0887ap0, 0x1.254696p0, 0x1.ceb92p0, 0x1.955e78p0, 0x1.b817e4p-2, -0x1.33b87p0, -0x1.8f3cfcp0, -0x1.376f14p0, -0x1.18fdep-1, -0x1.b56cdp-4, 0x1.c48128p0, 0x1.0e68d6p0, 0x1.6190acp0, -0x1.9ef4bep0, 0x1.efc5fap0, -0x1.4d93bcp0, 0x1.45732cp0, -0x1.caf27ap-3, -0x1.705734p0, -0x1.663a74p0, -0x1.ffc0ecp-2, -0x1.13c316p0, 0x1.3b7636p-2, 0x1.88c61p-2, -0x1.b0a0f2p0, 0x1.748426p-1, 0x1.d682fep-2, -0x1.0615b6p0, 0x1.5d4922p-3, -0x1.1bd7d6p-1, -0x1.3dbc82p-1, 0x1.02622ep0, 0x1.1bcc72p-2, -0x1.f74f42p-3, 0x1.74cb96p0, -0x1.255094p-2, 0x1.4ca4ep0, -0x1.08073p-1, 0x1.feca18p-1, 0x1.d2919ap0, 0x1.4edbdp-1, -0x1.e9a1bap-3, 0x1.1e9384p-1, -0x1.e26724p-1, 0x1.0c3b26p-2, 0x1.e9f6b6p0, 0x1.ca0bd8p-3, 0x1.9d88f4p0, 0x1.392834p0, 0x1.d69acep-5, -0x1.3694d4p0, -0x1.712d9ap0, -0x1.3af84ap-1, -0x1.9e4f82p-1, 0x1.664b36p0, 0x1.b97288p0, 0x1.39911ap0, -0x1.c01c8ap-1, -0x1.34817ap0, -0x1.05b6bep-1, -0x1.d94a56p0, -0x1.56193ap0, 0x1.463facp0, 0x1.81894p-3, 0x1.0dae4cp0, -0x1.a7387ap-2, 0x1.ba1288p0, 0x1.1de0d2p-2, 0x1.49eb1p-1, 0x1.dea84cp0, -0x1.5f2d74p0, -0x1.6a886cp0, -0x1.67b4e8p0, 0x1.e85ef8p0, 0x1.8acce2p-2, 0x1.99079ep0, 0x1.bbaaecp0, -0x1.041356p-14, 0x1.f3ed5ap-1, -0x1.cc9e82p0, -0x1.9b2ad2p0, 0x1.e91608p0, 0x1.3caedcp-1, -0x1.3a63b4p-1, 0x1.f1a74ep-2, 0x1.6ccc5p-1, -0x1.6779a8p-5, -0x1.c1111p-1, 0x1.3093aap-1, -0x1.953fc6p0, 0x1.53b0e8p0, -0x1.f704a8p-1, -0x1.71ae2ap0, 0x1.e50b9p-4, 0x1.9d5486p-2, 0x1.d383p0, -0x1.b46b54p-2, 0x1.69516cp-4, -0x1.ccab4cp0, -0x1.04871ep0, 0x1.a2445cp-2, 0x1.d9228ap0, 0x1.1d84fep0, 0x1.a5f23cp-1, -0x1.e8a88ap0, 0x1.3cec42p0, 0x1.38e66p-2, -0x1.55797cp-1, 0x1.31b5c6p-1, -0x1.347bd6p-1, -0x1.08608ep-3, -0x1.baf8eap-1, -0x1.2477b2p0, -0x1.2364f4p-1, -0x1.827bacp-1, 0x1.7976p0, 0x1.50896ep0, -0x1.7d047ap-1, -0x1.10749p0, 0x1.0b7b62p-5, -0x1.4c2aap0, 0x1.31323p0, 0x1.786122p0, 0x1.0746c8p0, -0x1.108fbp-1, 0x1.37ec22p0, -0x1.478582p-6, 0x1.65c3a6p-1, -0x1.1721cep-2, 0x1.07fe6ap0, -0x1.de1036p-1, 0x1.861218p0, -0x1.19c086p-2, -0x1.8cc2a2p0, 0x1.e3c07cp-1, 0x1.c29852p0, -0x1.1c64p0, 0x1.29e9f8p-4, -0x1.6dcfcep0, -0x1.7d6a8ep0, 0x1.ffe674p-3, 0x1.8eabccp0, 0x1.4e864p-2, 0x1.a42938p0, 0x1.23e548p0, -0x1.bc1d44p0, -0x1.a622a6p-1, 0x1.799938p-1, -0x1.a86e0ap-1, -0x1.9c3074p0, 0x1.000fcp-2, -0x1.ebfb3p-4, 0x1.ce3a2ap0, -0x1.9ee4d2p0, 0x1.974b16p-3, -0x1.b8a304p0, 0x1.76c58cp0, 0x1.b045f6p0, -0x1.6a9032p0, -0x1.2428bcp0, -0x1.99d3cp-1, -0x1.102a5ap-1, 0x1.f3118ap0, 0x1.021f3p-2, 0x1.f5e57p0, -0x1.1fd4bap-2, 0x1.1021f6p0, 0x1.6c8f16p0, -0x1.c1ef6ap-2, -0x1.61bd2cp-1, 0x1.4eaebep0, 0x1.c3df22p0, 0x1.161b68p-4, -0x1.353134p0, 0x1.947fb6p-1, -0x1.aabfaep-1, 0x1.2e137ap0, -0x1.249c1ep0, -0x1.27923cp-4, -0x1.513476p-6, 0x1.b349dp0, -0x1.1eac9p0, 0x1.ad06aap0, 0x1.661e6p0, -0x1.d07466p-1, -0x1.09e08ep-1, 0x1.41684p-2, -0x1.d2947ap0, 0x1.5b26fp0, 0x1.58d216p-2, -0x1.89ef98p0, 0x1.6a8358p0, 0x1.eacd9ap0, 0x1.43375ep-3, -0x1.332cb8p-4, -0x1.fdf85p-2, 0x1.7081c2p-1, -0x1.ed778p0, 0x1.4e4234p-2, 0x1.21946ap-3, 0x1.92ed72p0, 0x1.f02528p-5, -0x1.43b088p-2, -0x1.bd3664p0, 0x1.f5b27cp0, -0x1.979c82p-1, -0x1.db0b02p-7, -0x1.57a92ep-1, 0x1.9d1676p0, 0x1.0b3954p0, 0x1.fe418ap-2, 0x1.473896p-1, -0x1.25c476p0, 0x1.f5c29p0, -0x1.c3e346p0, -0x1.82157ap0, 0x1.02b9d4p0, -0x1.f2376cp-1, -0x1.a0a4eep-1, -0x1.2294bap0, 0x1.d39b3cp0, -0x1.2ddd5cp-5, -0x1.55e88cp0, -0x1.2e0bcep0, 0x1.e6cfacp-2, 0x1.ec1cdcp-1, -0x1.d100cp-4, -0x1.bbd788p0, 0x1.a797e6p0, 0x1.e6c10cp0, -0x1.25ac08p-1, -0x1.c5703cp0, 0x1.07e63cp-1, -0x1.06cd82p-3, -0x1.cbcdap0, 0x1.6825f6p0, -0x1.a5c736p0, -0x1.5a84fap0, -0x1.73b51ep0, 0x1.11f206p0, -0x1.db7552p0, -0x1.4517b4p0, -0x1.14a0fcp-3, -0x1.ebd5dap0, -0x1.866434p-1, -0x1.3ed2fep0, -0x1.d3a354p-1, -0x1.151ab2p-2, 0x1.ec3418p0, 0x1.b84ce8p-1, -0x1.a82b8ep-1, 0x1.af7bacp0, 0x1.38ae12p-1, -0x1.76ce94p0, 0x1.219fa4p-2, -0x1.8934b4p0, -0x1.d56cep-2, 0x1.3d89f2p0, -0x1.d5fcb8p0, 0x1.0cb864p0, 0x1.c81b24p-3, 0x1.d5cb4ep-6, 0x1.7daf5p-2, -0x1.392f6cp0, -0x1.6f5558p0, -0x1.d2c392p0, -0x1.6b3de2p-2, -0x1.80ab8ap-4, -0x1.b161cp-1, -0x1.7ca902p-2, 0x1.fbf628p-4, -0x1.3c4cb4p0, 0x1.6fdc48p0, 0x1.de1956p0, 0x1.4fef9ap0, 0x1.9af0fep0, 0x1.89929ep-6, 0x1.c3b328p0, -0x1.8903d2p0, -0x1.da29cp0, 0x1.2cf222p0, 0x1.b54442p-1, -0x1.4e6b6ep-1, 0x1.5c4a1ap0, -0x1.71fc62p0, -0x1.2c956ap-2, 0x1.b55f2ap-1, -0x1.13f5c8p0, 0x1.6dba98p0, 0x1.c9e8dp0, 0x1.37233p-2, -0x1.e1b91ep-3, -0x1.99064ap-2, 0x1.49578ap0, -0x1.6ea51p0, 0x1.7f34a2p0, 0x1.1bd23p-1, 0x1.4ba212p-1, -0x1.5fed7ap0, -0x1.ab70c6p0, -0x1.8db196p-1, -0x1.0cdfc8p-2, 0x1.885246p0, -0x1.5122b2p-3, -0x1.43c96p-7, -0x1.0ae04p-2, -0x1.e083b6p0, 0x1.c8b032p0, 0x1.5d6a68p-5, -0x1.b07d88p-3, -0x1.e55cfap-1, 0x1.fca206p-1, -0x1.c8e71cp0, -0x1.aaa5fp0, 0x1.2f14f6p0, -0x1.f159e8p0, 0x1.3f4d0ap0, 0x1.a6e314p-1, 0x1.6d879ap0, 0x1.cc3812p0, -0x1.aaaac6p-1, -0x1.69ab08p0, 0x1.e02f0cp0, 0x1.e6d16ap0, -0x1.522908p-1, -0x1.f2826ap0, 0x1.48fe96p-1, 0x1.7dd596p-2, -0x1.038ed2p0, -0x1.4940bcp0, -0x1.8c3948p-2, 0x1.ab359ap0, -0x1.91187ep0, 0x1.bcaap0, 0x1.d3e6bcp0, 0x1.bad3a2p0, -0x1.1a08e4p0, 0x1.1da4b6p0, 0x1.e6c526p0, 0x1.61ca6ep0, 0x1.a6385ep0, 0x1.5b22e4p-3, 0x1.41ba5p0, 0x1.c894c8p0, 0x1.caad16p0, -0x1.1efcap-3, -0x1.02860ep-2, 0x1.7a987ep-1, -0x1.4c228ep0, -0x1.739c2ep-1, -0x1.85f6d2p0, 0x1.44232cp0, 0x1.419e36p0, -0x1.30cb9cp-2, -0x1.cec566p0, -0x1.aa2f3p0, 0x1.dbf83cp0, 0x1.f84c9ap-2, -0x1.6a9dcap-1, -0x1.848cd4p0, 0x1.01fbe4p-1, 0x1.f9efe4p-2, 0x1.d00e86p-3, -0x1.c9957cp-1, -0x1.4967bcp0, 0x1.23797ap0, -0x1.80406ap-1, -0x1.162e62p0, 0x1.6c4d2ap-2, -0x1.0159bp0, 0x1.a292aap0, 0x1.071ed6p-1, 0x1.4b1a26p-2, -0x1.60673cp0, -0x1.33b15ap-1, -0x1.0681c8p0, 0x1.905edap0, -0x1.8501acp0, 0x1.26c168p-1, -0x1.1ad05p0, -0x1.786b92p0, 0x1.fdc9bep-3, -0x1.acb074p-1, 0x1.c658c8p-1, 0x1.a63af8p-1, -0x1.3c3d5p-1, 0x1.2cf4d8p-1, -0x1.aa6d5ep-1, -0x1.fc0d4p0, -0x1.7ecfcap-1, 0x1.5f9aaap-2, 0x1.6a3e56p-1, -0x1.c8518p-2, -0x1.65873cp-2, -0x1.3cf96p0, -0x1.d2ad02p0, -0x1.8047bap0, 0x1.52b2e4p-1, -0x1.d18f72p0, 0x1.a66696p0, -0x1.782dc4p-1, -0x1.439878p0, 0x1.5442b4p-1, -0x1.955ec2p-3, 0x1.ed3344p0, -0x1.152418p0, -0x1.f50eaap0, -0x1.92a8c2p-1, -0x1.c497f2p-1, -0x1.8a02f4p-3, -0x1.11a038p0, -0x1.ae0e7p-3, -0x1.2fc854p0, -0x1.63c2e6p-2, 0x1.9a0c74p-1, -0x1.accadp0, -0x1.1971eep-5, 0x1.ebdd6cp-1, 0x1.3668e4p0, 0x1.2ba4fap-1, -0x1.30141ep-1, 0x1.d3a3bep0, -0x1.1a0a2ap0, 0x1.a1888p0, 0x1.c9d66ep-2, 0x1.e96b48p0, -0x1.108d96p0, -0x1.b9954ap-1, 0x1.8724cap-2, 0x1.342f58p-5, 0x1.33f55cp-1, 0x1.6867p0, -0x1.474118p-1, 0x1.4e3c1cp0, 0x1.a8ae9p-1, -0x1.2196acp0, -0x1.daf766p-1, 0x1.839566p-1, -0x1.2f56d4p0, -0x1.2917b8p0, 0x1.31d8bcp0, -0x1.8e496cp-3, -0x1.e24634p0, 0x1.9ac424p-1, 0x1.110f78p0, -0x1.1ae536p0, -0x1.1c67acp-2, -0x1.37b77ep0, 0x1.1510fp-2, 0x1.26be68p0, 0x1.e0137ap-2, -0x1.e561d6p0, -0x1.293912p-1, 0x1.e2b3c4p0, -0x1.a2aa04p-1, -0x1.241edap-1, -0x1.05dbb2p-3, -0x1.f482cp0, -0x1.6f6e52p0, -0x1.84c238p-1, -0x1.5c9bd4p0, 0x1.1e1d84p0, 0x1.f5b022p-2, -0x1.d50a68p-1, -0x1.951fbcp0, 0x1.2728acp-1, 0x1.afae6p-3, -0x1.8b59ccp0, -0x1.69c42ep0, -0x1.a396a4p-2, -0x1.364998p0, -0x1.b6518ep-1, 0x1.f0efeap-2, 0x1.2f23f8p-1, 0x1.ef3178p0, -0x1.bf6842p0, -0x1.c63a7ep0, 0x1.f42caap-2, 0x1.ef1faep-1, 0x1.be4d0ap0, 0x1.7da082p0, 0x1.18d11ap0, -0x1.c31904p-1, -0x1.9689d4p0, 0x1.2e9b28p-2, -0x1.d5060ep-1, -0x1.fa2f76p0, 0x1.2b3862p0, -0x1.666518p0, 0x1.2a1d1cp-5, -0x1.e14a6ap0, 0x1.f4ccd6p-1, -0x1.bd00c4p-1, -0x1.e47a5cp-2, -0x1.865eb6p0, -0x1.6dc852p-2, -0x1.c8bb84p0, -0x1.0d1cb6p-1, 0x1.25f4ap-4, -0x1.4807e2p0, -0x1.219caep0, 0x1.599aep0, 0x1.eef8a2p-2, -0x1.7ec4dep0, 0x1.768dc8p0, -0x1.17d3ep-1, 0x1.58493p0, 0x1.a9975ep0, 0x1.d26692p-6, -0x1.695dc8p0, -0x1.e254dep0, -0x1.32d38ep-1, -0x1.b11eap-1, -0x1.940ec8p0, -0x1.ea9282p-5, 0x1.07ebd8p0, -0x1.96275cp-4, -0x1.8f5a36p0, 0x1.5f7b36p0, 0x1.c39abp-5, -0x1.4ae01ap0, -0x1.17327p-2, -0x1.25750ap0, -0x1.d2f5dcp-1, 0x1.7dafccp0, 0x1.afcbaep-1, 0x1.ab68d8p-2, -0x1.a514e6p-2, -0x1.b3c7a2p0, -0x1.8e1aeep-1, 0x1.4eee2p-1, 0x1.beb236p0, -0x1.2c5676p-2, 0x1.0fb78ep-1, -0x1.5c0422p0, -0x1.e81f36p0, 0x1.e4a1e8p0, -0x1.6dfbf6p-2, -0x1.fd2cf2p0, 0x1.16c88ep-3, 0x1.71e0ep0, 0x1.2d9fdap-2, -0x1.bf62f6p-3, -0x1.fbff34p-2, 0x1.6ad8b4p0, -0x1.27a93p0, 0x1.bca1ecp0, 0x1.6b6db2p0, 0x1.4f277p0, 0x1.9b710ap0, -0x1.8d757ep0, -0x1.225f2cp0, 0x1.09a1d2p0, -0x1.0170a6p-3, -0x1.f00b5ap0, -0x1.0a05d8p0, 0x1.a98ee4p0, 0x1.2d312p-1, 0x1.0d49e8p-3, -0x1.f67864p0, -0x1.4c1b7cp0, -0x1.ebc71cp0, 0x1.be5292p0, -0x1.adf024p0, -0x1.1d687cp0, -0x1.62189ap0, 0x1.942af6p-4, 0x1.af8b8ep-1, 0x1.078a08p-2, 0x1.da0fdcp0, -0x1.c79d4cp0, 0x1.8f51ap0, 0x1.ace652p0, -0x1.2b574ap0, 0x1.af7dc2p0, 0x1.89a582p0, 0x1.7589cep0, 0x1.0c6eecp0, -0x1.d908bep0, -0x1.f4ffbep0, -0x1.b2601ap0, 0x1.83cddcp-4, 0x1.a57d1p-2, 0x1.c558ecp-1, 0x1.23585p-3, 0x1.91b8c2p0, 0x1.5ff292p0, 0x1.895812p-1, -0x1.70c34ap0, -0x1.292f7ap-3, 0x1.f30c86p0, 0x1.00d8a6p-1, -0x1.935e82p0, 0x1.a71ee8p-2, -0x1.855da4p-1, 0x1.720814p0, -0x1.ec3c48p-2, 0x1.8d346cp-5, -0x1.59b93p0, -0x1.2b5a9ep-1, -0x1.33c802p-1, 0x1.5564e6p0, -0x1.910baep-1, -0x1.77807p-6, 0x1.23a196p0, -0x1.3f30c6p-4, -0x1.65262ep-3, 0x1.a86522p0, -0x1.f4307ap-1, -0x1.bead4p-3, 0x1.de404ap-3, 0x1.04177ap-3, 0x1.585f66p0, -0x1.38654ep-1, -0x1.861a36p0, -0x1.31c912p-1, -0x1.10a0a4p-1, 0x1.b34e08p0, 0x1.6b1adep-1, 0x1.d39fb6p-1, -0x1.dc62aep0, -0x1.463ep0, -0x1.00f96p-3, -0x1.5abbccp0, 0x1.28576ap-2, 0x1.b0d688p-1, -0x1.034274p0, 0x1.d242d2p0, 0x1.63929p0, 0x1.73b8b2p0, 0x1.c19b0ep-1, 0x1.be512ap-2, -0x1.cac116p0, 0x1.75d7c6p0, 0x1.63a52p-2, 0x1.66e1fcp-1, -0x1.4edfep-1, 0x1.6d87p0, -0x1.52c38ap0, 0x1.54078cp0, -0x1.019aaap0, 0x1.770b58p0, -0x1.703bfp0, 0x1.edde2ep0, -0x1.14eef2p0, -0x1.9f12dp0, 0x1.6c1c44p0, -0x1.67bb46p-5, -0x1.5ddf5ap0, -0x1.09504ap-1, 0x1.68d4bap-1, 0x1.119b9ep-4, 0x1.303ebep-1, 0x1.73c7p0, -0x1.6128aap-3, -0x1.aa43fap0, -0x1.ea7706p-2, -0x1.f13922p0, 0x1.8a5688p0, 0x1.674b6ap-1, -0x1.cae70ep-4, 0x1.207966p-2, -0x1.e4c4c2p0, -0x1.71bebcp-3, -0x1.c1be1p0, -0x1.71a894p0, 0x1.7157c4p-3, 0x1.830466p0, 0x1.f2acf4p0, 0x1.42169ep-4, 0x1.6ce556p-2, -0x1.2e812cp-2, -0x1.08fa42p0, -0x1.6f3404p0, 0x1.d92b82p0, -0x1.bc2cf8p0, -0x1.43674p0, -0x1.97c45ep0, -0x1.aa65f4p-2, -0x1.813e54p-2, -0x1.65b3f6p0, -0x1.5028fep0, -0x1.c78556p-2, -0x1.6b2f3p0, 0x1.09213cp0, 0x1.eb17eap-2, -0x1.be08f6p-2, 0x1.281216p-4, -0x1.f05232p-2, 0x1.8f7fb4p0, -0x1.1f10e8p-2, 0x1.8ee53ap-1, 0x1.68aa3cp0, -0x1.fa2b76p0, 0x1.1e05a4p-2, 0x1.6e1aecp0, -0x1.17c84ap0, -0x1.af32aep-1, 0x1.644606p-1, -0x1.f4fd48p0, 0x1.2e2b2cp0, -0x1.f653fap0, -0x1.2022cap-1, -0x1.ca820ep0, 0x1.49db8p-1, 0x1.161568p0, -0x1.e37386p0, 0x1.bb0bep0, -0x1.c16424p-6, 0x1.e7f1eep0, -0x1.1b6064p-1, 0x1.5167d6p-2, -0x1.cf546ep-1, 0x1.92e604p0, 0x1.04e1c6p-3, -0x1.485666p0, 0x1.624d8ap-1, 0x1.ed5868p0, -0x1.83e1ccp0, -0x1.739b28p-6, 0x1.e032f6p0, 0x1.f980eap0, -0x1.4f1a62p0, 0x1.087106p-1, 0x1.8b7deap0, 0x1.e38734p0, 0x1.beb1cep-1, -0x1.0c4c1ep0, 0x1.0a0d0ep-1, 0x1.855228p0, 0x1.13163ap0, 0x1.be5e6p-1, -0x1.80ce0cp0, 0x1.65ef76p-1, -0x1.f99566p-3, 0x1.df8652p-2, 0x1.c5cffap-2, -0x1.51b25p-1, -0x1.a3bf02p0, -0x1.9da07p0, -0x1.23dedcp0, 0x1.365352p0, -0x1.cc4f6ep0, -0x1.f47f6cp0, 0x1.619d9p0, -0x1.dcc75cp0, -0x1.fac2c2p-1, 0x1.4d7d0ep0, 0x1.6982e8p0, 0x1.771f4ap0, -0x1.ea919ap0, -0x1.22567ap0, 0x1.40c94ep-3, 0x1.664b9ep0, -0x1.662c68p-4, -0x1.2d2b6ap0, -0x1.adec18p0, -0x1.03f404p0, 0x1.d7f976p-2, -0x1.5b737ap0, 0x1.c84b22p0, -0x1.94e22ap0, 0x1.5c980ap-1, 0x1.81d9eap0, -0x1.b720bep-3, -0x1.6f15b8p-1, -0x1.37192p-2, 0x1.c9baa4p0, 0x1.a9eaeep-1, 0x1.7cc99ap-1, 0x1.e93302p-1, 0x1.a3e898p0, -0x1.4dee9cp0, -0x1.9756f8p-4, -0x1.01c4cap0, -0x1.45f9bp0, -0x1.b89f2ep-1, -0x1.536e64p0, 0x1.d7da72p-1, 0x1.fcc9dep0, -0x1.b8e56ep0, 0x1.bf41eap0, 0x1.c2ea0ep0, 0x1.e78768p0, -0x1.86b146p0, 0x1.a7ee54p0, 0x1.96929p0, 0x1.24b802p0, 0x1.39d6d6p-2, -0x1.9518bp0, -0x1.53baep0, 0x1.93124ep0, -0x1.6cf6eap-3, -0x1.575c64p0, 0x1.f45c4ap0, 0x1.9fc5d4p-1, -0x1.738e18p0, -0x1.99e7ep0, -0x1.5f5984p0, 0x1.c490c4p0, 0x1.865934p-4, -0x1.440076p-3, -0x1.ea4c6ep-1, 0x1.68bf3ep-1, 0x1.281d8cp-2, -0x1.60bb52p-3, 0x1.46fc6ap-2, 0x1.a19202p-4, -0x1.6dce16p0, 0x1.f5ea82p0, -0x1.6a3862p-5, 0x1.2443acp0, -0x1.a966ccp0, 0x1.75534ep-1, -0x1.79b76p-1, 0x1.a9283p0, 0x1.338a8p-1, 0x1.88069ap0, -0x1.588c2ep0, -0x1.28c7e6p0, 0x1.ca81aap-1, -0x1.347e8ap-2, 0x1.ff9cbap0, 0x1.c9a28p0, 0x1.a11298p0, -0x1.7c0ecap-3, 0x1.cc19a2p-6, 0x1.33174ap-1, -0x1.4f6f5p-2, 0x1.442d98p-1, -0x1.3db3bep0, 0x1.fada3ep0, -0x1.d5d1b6p-3, -0x1.07aba2p-1, 0x1.52d048p0, 0x1.93e3e2p-2, -0x1.97c6dap-4, -0x1.e4ae9p-1, 0x1.8ada7ap0, -0x1.f900f4p-1, 0x1.0e8efap-3, -0x1.715922p0, -0x1.e9ac94p-1, 0x1.4aef48p-1, -0x1.769e08p0, -0x1.e1b2f4p-2, 0x1.2eef5p-1, -0x1.e84ea2p-1, 0x1.0fdd82p-1, 0x1.6c7698p0, 0x1.b6af4ep-3, -0x1.01750cp-2, -0x1.5f301p0, 0x1.81555p0, 0x1.977f66p0, -0x1.d63056p0, 0x1.4aec5ap-1, 0x1.08826p0, 0x1.1da8dap-1, 0x1.6ba84p0, 0x1.c1f54cp0, -0x1.32f198p0, -0x1.d03272p0, -0x1.830c3ap-1, 0x1.afe348p0, -0x1.3b5e7ap0, -0x1.9fe824p-3, -0x1.678dd6p-3, -0x1.9d9038p-2, 0x1.059bbp-3, -0x1.f26186p-2, 0x1.3479aep0, -0x1.bc9206p0, -0x1.f98e88p-3, -0x1.b62e6p0, 0x1.45a282p0, -0x1.8b556cp0, -0x1.0b4d3ap-3, -0x1.a15092p-4, 0x1.72205ep0, -0x1.ffcecap0, 0x1.ff87dap0, 0x1.818ad4p0, -0x1.cf7564p0, 0x1.8a5c1ap-5, -0x1.0b6a1ep0, -0x1.052b98p0, -0x1.5415f4p-1, 0x1.6cfb34p0, 0x1.b0178cp0, 0x1.9221e2p-1, -0x1.8e531p-1, 0x1.0e939ap0, -0x1.9bb016p-1, -0x1.a900ep0, 0x1.ec80eap0, -0x1.faa9e4p-2, 0x1.7e16f4p-2, 0x1.198ce2p-1, -0x1.4b7bcap-2, -0x1.74d2e4p-2, -0x1.ea9674p-3, 0x1.a3346ep0, -0x1.118982p-1, -0x1.0c07b6p-2, -0x1.0255acp0, -0x1.1cf46p-2, 0x1.d79834p-1, 0x1.c074d6p-2, 0x1.65bbe6p0, -0x1.af24cp-3, -0x1.edffccp-1, 0x1.dbfa46p-5, 0x1.c16216p0, 0x1.b1f27ap-1, 0x1.4dac74p0, -0x1.96c65ap0, -0x1.a96d94p0, 0x1.cf5daep-1, -0x1.419862p0, 0x1.f5b608p-1, 0x1.fa13a6p0, 0x1.689946p0, 0x1.63a882p0, 0x1.5c7c28p0, -0x1.ad3f16p-2, 0x1.ad8afcp0, -0x1.38cd04p-2, 0x1.1d6224p0, -0x1.e6cca4p-1, -0x1.e16a44p-1, -0x1.73e0c4p-1, 0x1.daed96p-2, 0x1.1a5d3ap-1, 0x1.0b2dbp0, 0x1.f7f96p-1, -0x1.5b9c1ep0, -0x1.2bd96ap0, -0x1.82e938p0, -0x1.f40a2ap-1, -0x1.93e97cp-2, -0x1.f7b59ap0, -0x1.9c2866p0, 0x1.fbc618p-5, 0x1.88eaeap-1, 0x1.68f37cp-4, 0x1.f3486ap-2, -0x1.47621ep0, 0x1.2488b8p0, -0x1.9a6604p-2, -0x1.2a0642p-2, 0x1.143bc4p-1, -0x1.c3ade4p0, 0x1.10d3f4p-7, -0x1.6a1ca8p-2, -0x1.b3e3bp-3, 0x1.2c50e4p-1, -0x1.a0a984p0, 0x1.c9fbc2p0, -0x1.43dcfep-4, -0x1.ca8112p-1, 0x1.499fbp0, 0x1.6a901cp-1, -0x1.bd2b92p0, -0x1.39477ep0, -0x1.fb3b58p-1, 0x1.5dcf18p0, 0x1.19caa8p0, 0x1.3777cap-4, -0x1.d61bb6p0, 0x1.e29e7p0, 0x1.f45bfep0, 0x1.9db45p-1, -0x1.b8623cp-1, -0x1.05d906p-1, 0x1.762e92p-1, 0x1.723c04p-2, 0x1.41a99cp-2, -0x1.003d2cp-2, 0x1.18a36cp0, 0x1.047e78p-1, -0x1.ff37f8p-1, -0x1.07f2a2p-2, -0x1.69332cp0, -0x1.925612p-2, 0x1.b65644p0, -0x1.e6a242p0, -0x1.60f662p-1, 0x1.fc8b5p0, -0x1.ecffe6p-1, -0x1.d1b322p-2, -0x1.044e6cp-2, 0x1.60773ep0, 0x1.307bb6p0, 0x1.0e371ap-4, 0x1.f6aceep-4, -0x1.9cf37p-1, -0x1.f43a0ep0, -0x1.0fd13ap0, -0x1.36c806p0, -0x1.5b3b68p-1, 0x1.df0ac4p0, -0x1.1f074p0, -0x1.45df9p-1, 0x1.0b2ca6p-2, 0x1.9213e8p0, 0x1.d03522p-1, -0x1.14a8bep-1, 0x1.30bb46p-2, 0x1.e2feeep0, 0x1.afb41cp-1, -0x1.dab492p-3, 0x1.39fd3cp0, -0x1.933224p-1, 0x1.db03a6p-2, 0x1.6b4f3ap0, 0x1.7b182cp0, -0x1.9ff824p-1, -0x1.b6d4dp0, -0x1.1aed7ep-1, 0x1.d9158ep-2, -0x1.46397ep0, 0x1.6c356ep-2, -0x1.7b1476p-1, -0x1.ee7b28p0, 0x1.1597dp0, 0x1.4c739p0, 0x1.6bf618p0, 0x1.860c84p-3, -0x1.49ef66p0, -0x1.5a3248p0, 0x1.b94b6p0, 0x1.18f912p-4, -0x1.5c63c2p0, -0x1.20c9f4p-1, -0x1.1e7dep0, 0x1.b40408p0, -0x1.aa0282p-3, 0x1.a36784p-2, 0x1.8e5ecep0, 0x1.ae313ap-8, -0x1.dadc06p-3, -0x1.999692p0, 0x1.5a2e7p-1, 0x1.3c374p-4, 0x1.be083ep0, 0x1.c801b4p-1, 0x1.897d28p-1, 0x1.17f3e6p-4, 0x1.344d04p-2, -0x1.2ee966p0, 0x1.cbc0dap0, -0x1.8ae3a4p-2, -0x1.7c1588p0, 0x1.728ebep-1, -0x1.673e66p0, -0x1.b40a8ep0, 0x1.0c0b2ep0, -0x1.cec864p0, 0x1.50d70ap0, -0x1.016008p-1, 0x1.8a9b6ep0, 0x1.a506aap0, -0x1.1ff4dcp-4, -0x1.a01a64p-2, -0x1.fe1b2ap0, 0x1.2e96dp-3, -0x1.376b48p0, -0x1.d68786p-2, 0x1.0954c4p0, -0x1.b8be9ep0, 0x1.23bcb6p-1, 0x1.72ea56p-1, 0x1.08fddp0, 0x1.b0cbf4p-2, 0x1.7f31a2p-2, -0x1.221014p0, 0x1.f37e1p0, -0x1.a03b0ap-3, -0x1.b2aacep-1, 0x1.2969ccp-2, 0x1.6c449ap-2, -0x1.07ce84p-3, -0x1.2bb34ep0, 0x1.34526cp0, -0x1.23814ep0, 0x1.5461f2p0, 0x1.fc489ap-1, -0x1.34a5e2p-1, -0x1.2005fep-4, -0x1.978e96p0, -0x1.eab892p0, -0x1.b4b884p0, -0x1.c0d38ap0, -0x1.570f6ep0, -0x1.06aad2p0, -0x1.ebba96p-1, -0x1.76eed2p-1, -0x1.0b12eap-1, -0x1.db481cp0, -0x1.93e354p0, 0x1.88a7d4p0, -0x1.a4037ep-2, 0x1.48545p0, 0x1.395382p-1, 0x1.bd54a2p0, 0x1.6c9a8ep0, -0x1.78c576p0, -0x1.51179ep-1, -0x1.5bcd2p-1, -0x1.8c6468p0, -0x1.bb166ap-1, -0x1.f74a94p-1, 0x1.512bd8p0, -0x1.aed9cep-3, 0x1.091dbp0, 0x1.e20ce4p-4, -0x1.fcd74ap-1, 0x1.eb0f18p-1, 0x1.8d9bcep0, -0x1.1b6868p0, 0x1.596e0cp-1, 0x1.0931ep0, -0x1.db30fap0, -0x1.c4d4e4p-1, 0x1.644674p-3, -0x1.fd6e64p0, 0x1.87d6b4p-2, 0x1.1ba91cp0, 0x1.aaf82ap-2, -0x1.16684ep-2, 0x1.8cafeep0, -0x1.1e247ep0, 0x1.cb1b8ap-2, 0x1.24509ap0, 0x1.ac2542p0, -0x1.7e25aep-1, 0x1.7e8152p0, -0x1.f2b692p-1, 0x1.685acep0, 0x1.11cd42p-2, -0x1.63bf94p-2, -0x1.920936p0, -0x1.c99edcp0, 0x1.ec60b6p-1, -0x1.2f4272p0, 0x1.78485ap0, -0x1.96b6a4p0, -0x1.0607f8p0, 0x1.85cd1cp-4, 0x1.bf60e8p-1, -0x1.0ac11cp0, 0x1.e9f27p-1, -0x1.a42c9ap-1, -0x1.78aeecp0, 0x1.b6296cp-1, -0x1.e57bcp-4, -0x1.2352c8p0, 0x1.292ac6p-8, -0x1.53755cp-4, 0x1.b889b6p0, -0x1.c6316ep0, -0x1.121f9ap-2, -0x1.614a2ap0, 0x1.50dd7p-1, -0x1.1186e8p0, 0x1.eb8408p-1, 0x1.83126ap0, 0x1.c4b61ap-1, -0x1.69e586p-2, -0x1.9d7054p0, -0x1.328b1ap-1, 0x1.32895p0, 0x1.9324a6p0, -0x1.9d75dap-8, 0x1.a98918p-1, 0x1.8d5554p-1, -0x1.1e85d6p0, 0x1.c65c2p-2, 0x1.d1ed1p0, -0x1.21afb4p0, 0x1.dd0442p0, -0x1.56b0ccp0, 0x1.cdf852p0, -0x1.418f24p-2, -0x1.a5e42ap0, -0x1.9b900ap0, -0x1.1f457ap0, -0x1.5f26fp-4, 0x1.2152b8p0, 0x1.fb864cp-3, 0x1.e01d7ep-4, -0x1.a6607p0, 0x1.e9bc52p-3, -0x1.c83bacp0, 0x1.d1f17cp-1, 0x1.382cc2p0, 0x1.cc822p-1, -0x1.6d09ap-1, -0x1.07f28cp-1, -0x1.8b0514p-3, 0x1.de7b02p0, 0x1.034106p0, -0x1.bd1dcep-1, 0x1.e84476p-1, -0x1.c390bap0, 0x1.49db7ep0, 0x1.5cfd14p-1, -0x1.5c2d96p0, -0x1.6e37ep-4, -0x1.60b88ap-1, -0x1.6361e8p0, 0x1.56713ep-1, -0x1.0743c6p-3, -0x1.586cc8p-1, -0x1.a5d916p-3, -0x1.36772ap0, 0x1.2e724cp-2, -0x1.2add98p0, 0x1.80d274p0, -0x1.a968e6p0, 0x1.510698p0, 0x1.90d34ep0, -0x1.c74302p-4, 0x1.49218ep-2, 0x1.8cb1acp-1, 0x1.0ecf3ap0, 0x1.9a5baap0, 0x1.dae4bap0, -0x1.4ff1bap0, 0x1.af0992p0, 0x1.908bdep-1, -0x1.9c7e6ap0, -0x1.92ebecp0, 0x1.cce5f2p0, -0x1.f489c2p-5, -0x1.56fbe4p-1, 0x1.147964p0, -0x1.25d876p0, 0x1.f0489ep0, -0x1.95c786p-1, 0x1.209dfep0, 0x1.2c80f8p0, -0x1.9c7394p-3, -0x1.30b8a4p-2, 0x1.e44f22p-2, -0x1.6fc70cp-1, -0x1.b850ep-1, -0x1.ec3dc6p0, 0x1.a83f76p0, 0x1.bb4384p-2, 0x1.8411fap0, -0x1.7df5e4p0, 0x1.144546p-1, -0x1.edd1bep-2, -0x1.558224p-5, 0x1.28957ap-1, 0x1.265d7ap0, 0x1.e055aep-2, -0x1.52bbe6p0, -0x1.82cc78p-1, -0x1.7cfffep0, 0x1.f38466p0, 0x1.63a34cp-3, -0x1.db9e6ep-2, -0x1.0d68d6p0, 0x1.ef7e68p0, -0x1.773e26p0, 0x1.bf7942p-1, 0x1.4f9598p-1, 0x1.3c5542p-1, -0x1.b8869p-4, -0x1.1a9b8ep-1, 0x1.6ddf3ap0, -0x1.9743a2p-1, -0x1.1c80ecp0, 0x1.9cb4d2p0, 0x1.faac9cp0, 0x1.eebb74p-2, 0x1.f4de1cp0, 0x1.7959eep-2, -0x1.9fc78ap0, 0x1.6bc23cp-3, -0x1.846d46p-1, 0x1.0b6552p-1, 0x1.fc0a94p0, -0x1.cf1a08p0, 0x1.7cdc3p-1, -0x1.682f4ep-1, -0x1.9a507p0, -0x1.14d9c4p-2, 0x1.2f51a4p0, 0x1.7d2e66p-1, 0x1.e048ep0, -0x1.1548dep0, 0x1.c79e8ap0, -0x1.121064p0, 0x1.7eed9ep-2, -0x1.214dbcp-3, 0x1.1ac622p0, -0x1.d427bep-4, 0x1.254c24p-6, -0x1.e2f49ap-1, 0x1.542d0ep0, 0x1.be38d6p-4, -0x1.870704p-1, 0x1.3499cep-2, -0x1.af9324p0, 0x1.b34ab2p-3, -0x1.4473d6p0, -0x1.5b9ca8p-2, -0x1.4a7ce2p0, 0x1.1e82c6p0, 0x1.0261fcp-4, 0x1.0bcfe2p-3, 0x1.05761ep0, -0x1.7996b6p-1, 0x1.9fcf26p-2, 0x1.4528cp-2, -0x1.090224p0, 0x1.e4f25p-4, -0x1.c95fa2p-1, 0x1.c175d2p-2, 0x1.5aa25ep-2, 0x1.6bd0cap-6, 0x1.d1ba86p-2, -0x1.66321cp0, -0x1.5abc0ep0, 0x1.f3c5aap-3, -0x1.85bfaap-1, 0x1.9b9d86p0, -0x1.70162ap-1, -0x1.6b8484p0, 0x1.3f2418p0, 0x1.e08836p-1, 0x1.a2abeep-2, 0x1.b5a826p0, -0x1.3f098ep-6, 0x1.c24146p0, 0x1.0b3e88p-3, 0x1.ad2afcp0, -0x1.aa2f6p-1, 0x1.11c324p-1, -0x1.577542p0, -0x1.584318p-1, -0x1.126a7ap-2, 0x1.f717ecp0, 0x1.305c16p0, 0x1.5c9dcp0, -0x1.51d9ecp0, 0x1.fa0f66p0, -0x1.288ab8p0, -0x1.4ca75p0, 0x1.f9cbb4p-2, 0x1.90d85cp0, -0x1.4ed8a4p-1, -0x1.8f31dp-1, 0x1.d2f56ep-2, -0x1.832bcp0, 0x1.6fbf96p-1, 0x1.7e9064p-2, 0x1.3ee7cap0, -0x1.de7ee2p0, -0x1.9a7c18p-3, 0x1.ef9c9ap0, 0x1.af527cp-1, 0x1.302e7p-4, -0x1.95a0eep-1, -0x1.708786p0, -0x1.b5d388p0, -0x1.1a5d82p-1, 0x1.8fda8ep0, 0x1.74c72ep-2, 0x1.ec5dd2p0, 0x1.1f194ap-4, -0x1.ea6ef4p-3, 0x1.a8bad6p-1, -0x1.6b0ecap-1, -0x1.cadc58p-1, 0x1.316ad2p0, 0x1.1157c8p0, 0x1.cd6a68p-1, 0x1.d41586p-1, -0x1.fcc246p-1, 0x1.a15b5ap-1, -0x1.7c285ep0, -0x1.85c146p0, -0x1.304486p-1, -0x1.2f1aacp-1, 0x1.21575ap-3, 0x1.f68a7cp-2, 0x1.b885c6p-1, 0x1.c2d9fap0, -0x1.c6584ep-1, -0x1.2cceccp-1, 0x1.ce788ap-2, 0x1.377ed6p0, 0x1.dc91e6p0, 0x1.b36a6ep0, 0x1.33dea2p-1, -0x1.ad3df4p0, -0x1.f71408p0, -0x1.536a24p-4, 0x1.d7862ap0, 0x1.ed1efep0, 0x1.198f12p-4, -0x1.7f70f6p0, 0x1.b4fd06p-2, -0x1.b61ep0, 0x1.76a16cp0, -0x1.06c27p0, 0x1.2abd64p-1, -0x1.08198ap0, 0x1.ee0a0cp0, -0x1.324e22p-2, -0x1.3a206ap-3, 0x1.595ce8p-2, -0x1.9a5ab8p0, 0x1.5d7a28p0, 0x1.4fa584p-2, -0x1.e53846p-4, 0x1.ed9052p0, -0x1.467b9cp-1, -0x1.0e44e2p0, -0x1.87dccap0, -0x1.9e54e4p0, -0x1.ad4d98p0, 0x1.3c708ap-2, -0x1.52e1bap-2, 0x1.2ea906p-1, -0x1.6bd0e8p0, 0x1.c32802p0, 0x1.48496p0, 0x1.6148fp0, 0x1.9f0154p-2, -0x1.186bacp-4, 0x1.faec1ep0, -0x1.a3dd18p-2, -0x1.d63bbp-1, -0x1.d999c8p0, 0x1.02c7f4p0, -0x1.1d012ep-1, -0x1.919b4p0, 0x1.c23a2cp-1, 0x1.668d9ap-4, 0x1.c1eae6p0, -0x1.4106dap0, -0x1.a1307cp0, 0x1.3970a2p-2, 0x1.ee7162p-2, -0x1.062b0cp-1, 0x1.30717cp0, -0x1.5b917cp0, 0x1.81b856p-2, 0x1.96995p0, 0x1.fbdaeap0, 0x1.280c3p0, 0x1.78b9d6p0, -0x1.607d06p-1, -0x1.4439c2p0, -0x1.3c8fa8p0, 0x1.13092p-3, 0x1.31d7a2p0, -0x1.bd23e6p-2, 0x1.af67c4p0, 0x1.3f181ap-1, 0x1.c01cfap-2, -0x1.68789p0, -0x1.4fabc4p-3, 0x1.0d8876p-7, 0x1.77d182p-2, -0x1.e017e2p-3, -0x1.b5b84cp0, 0x1.d81fe8p0, -0x1.b5b128p-1, 0x1.e26834p0, -0x1.71cf16p0, 0x1.782178p0, 0x1.54a922p0, -0x1.0390c8p-1, -0x1.188d7ap-2, 0x1.1296dap-1, -0x1.0bad3ep0, -0x1.6148cep0, 0x1.cac0eep0, 0x1.da6088p-1, -0x1.fedbaep-1, 0x1.08272ap-2, 0x1.d4d8b6p0, -0x1.74b33cp-1, -0x1.5f3efcp-4, -0x1.01c044p0, 0x1.147972p0, 0x1.1d2e58p-2, -0x1.12fe04p0, -0x1.5da4d4p0, -0x1.e10b5cp-7, 0x1.d69d1ap-1, 0x1.734baap0, 0x1.5f5212p0, -0x1.f13b12p-6, -0x1.77661p-1, 0x1.3ea69ap-3, -0x1.3ce756p-2, -0x1.e2ed02p0, -0x1.d7934p0, 0x1.d904b6p0, 0x1.98d7a6p-3, 0x1.73cbp0, -0x1.c07222p0, -0x1.63ed74p-3, -0x1.fb710ap0, 0x1.b8616cp0, 0x1.12c12p0, 0x1.3f589ep0, 0x1.ae193ap0, -0x1.8f9d64p-1, -0x1.dba7b6p-2, 0x1.81916ap-1, 0x1.963f68p0, -0x1.5832dcp0, -0x1.b92a3ep-1, -0x1.f44e2p-2, -0x1.83c6ecp0, -0x1.ec21aep-2, 0x1.ed7cbap0, -0x1.0d9674p-2, -0x1.6c47b4p0, -0x1.1f4bep0, -0x1.d763a8p0, -0x1.b5a284p-1, -0x1.2487fp-1, 0x1.99f218p-4, -0x1.9fd0fcp0, 0x1.3c79f8p-3, -0x1.3f73fep0, -0x1.cabc62p-1, -0x1.b5620ep0, -0x1.98a742p-1, 0x1.2fdf98p0, 0x1.0ac894p-4, -0x1.4d5244p-1, 0x1.5e89dap0, 0x1.b7852ep-1, 0x1.3a294cp0, 0x1.3e802ap-6, 0x1.fa6d06p0, -0x1.91597ep-3, -0x1.1361d6p-1, 0x1.8b50a6p-5, -0x1.63b2a2p-2, -0x1.d5939ep-2, 0x1.0e3fb2p0, 0x1.098394p-1, -0x1.a07996p0, -0x1.24c53cp0, -0x1.950c76p-2, 0x1.020eeap-4, 0x1.f9f31p0, 0x1.9ffd44p-2, 0x1.ba461ep-3, -0x1.603fdcp-4, 0x1.e53b5cp0, -0x1.a8ee5cp0, -0x1.e58cf6p0, 0x1.31d586p-1, 0x1.c40058p0, -0x1.8413ccp-1, 0x1.cfae02p-1, 0x1.b90e6p-5, -0x1.665006p-3, 0x1.26b596p-1, -0x1.485afcp-1, 0x1.c7b87p0, -0x1.1fd65cp-1, -0x1.ab425cp0, 0x1.c4333p-1, -0x1.22d514p0, -0x1.cfbedap-1, -0x1.6a8178p0, -0x1.2370fp-1, 0x1.c017b2p0, -0x1.64ad86p-3, 0x1.859a46p0, -0x1.a7cfb6p-4, 0x1.ff249cp0, -0x1.72f3c2p-1, 0x1.08e80ap0, 0x1.cfbf22p0, 0x1.4d2deep-5, 0x1.1a501ep-1, -0x1.47de7cp0, -0x1.f76e5cp0, -0x1.f839b2p-2, -0x1.fadef4p0, 0x1.ffb02ap-1, -0x1.589ebcp-1, -0x1.a5e992p-2, 0x1.1b1214p-1, -0x1.d5a4bep-1, -0x1.7a6d24p0, 0x1.21d286p0, -0x1.73ea52p0, 0x1.8113cep-1, 0x1.a8aac4p-1, -0x1.cd0176p-1, -0x1.363b84p0, -0x1.8d9832p0, 0x1.d0c16p-1, 0x1.7715aap0, -0x1.f2fd1cp0, -0x1.aae9c6p-5, 0x1.04e43cp0, 0x1.0001ep0, 0x1.87656cp-4, -0x1.c5df76p-1, 0x1.ac82f6p-3, 0x1.f5b77p0, -0x1.8c6d26p0, -0x1.31834ap-3, 0x1.412c76p-2, 0x1.2886c6p-2, -0x1.eef5b8p0, 0x1.08140cp-1, -0x1.ae3d44p0, -0x1.98c92ap0, 0x1.e1124ap0, -0x1.675aa2p-1, 0x1.5e1beap0, -0x1.268752p0, 0x1.b876cap0, 0x1.1ede52p0, -0x1.219826p-2, 0x1.d56c2p0, 0x1.dd1d0ep0, 0x1.9cd4eap0, -0x1.28e1d4p-1, -0x1.28f0fcp-1, -0x1.0f64a6p-2, 0x1.14037p-1, 0x1.cc5d52p-1, -0x1.dbf48p-2, 0x1.e9159ep-2, -0x1.8c4058p-2, -0x1.3bc06p0, -0x1.d14c0ep-1, -0x1.0cf804p0, -0x1.3289e4p-1, -0x1.8f49dep0, -0x1.f59076p0, 0x1.ab042ap0, -0x1.8ddf66p-1, -0x1.32e682p0, 0x1.5fc896p0, -0x1.7cd77cp-3, -0x1.8e8f8p0, -0x1.165776p-2, -0x1.5759aap-3, -0x1.d82124p-1, 0x1.99a654p0, -0x1.53700ap-1, 0x1.abf726p0, 0x1.525e0ap0, 0x1.f1dd8p0, -0x1.7a8806p0, 0x1.3690f6p0, 0x1.2b8778p0, -0x1.b7283p0, 0x1.858e82p-3, 0x1.c1cd28p0, 0x1.147afcp-2, -0x1.84228ap-3, -0x1.92fc3cp0, -0x1.f23152p0, 0x1.c3b402p0, 0x1.3fcef6p0, 0x1.7cc1d2p0, -0x1.fd7804p-3, -0x1.b2343p0, 0x1.f93db6p-2, -0x1.de8594p-1, 0x1.fce9f2p-1, 0x1.2a984cp-3, 0x1.18e7dap0, 0x1.bc5862p-1, 0x1.d73b4cp0, -0x1.647c52p-7, 0x1.a12366p-2, 0x1.ce3862p0, -0x1.e0705cp0, 0x1.8b4b98p0, -0x1.a4d8a4p-2, -0x1.d3f0e4p-1, -0x1.f4a96p0, -0x1.d2cc76p0, -0x1.f36844p-1, 0x1.903d06p0, 0x1.15bde4p-1, -0x1.b2acap0, 0x1.75d786p-1, -0x1.87d024p-1, -0x1.f97afp-2, 0x1.bf51p0, 0x1.ddad3ep-1, -0x1.34a46cp-1, 0x1.22b94cp-1, 0x1.913b06p0, 0x1.c80c9cp0, 0x1.366fa2p0, -0x1.6ff85cp0, 0x1.d468b4p0, -0x1.2b108cp0, 0x1.32067cp-2, 0x1.b4c6d6p0, -0x1.0f2e1ep0, -0x1.1a4e7p0, -0x1.a6212cp-1, 0x1.be56p-1, 0x1.013262p-1, -0x1.7d3fd4p-2, 0x1.de26a4p-2, -0x1.835c9ep0, -0x1.bfd842p0, 0x1.7d0a32p0, -0x1.4468b8p-1, -0x1.280134p-3, 0x1.42693ep0, 0x1.57cd2ep-1, 0x1.3ed144p0, 0x1.9f0e3ep-1, 0x1.7e0a6ep0, -0x1.170a5ep-1, 0x1.f1f8a4p-1, 0x1.3b4e56p0, 0x1.eea69ep0, -0x1.adef24p0, 0x1.92a34ap-1, 0x1.a6a98ap0, -0x1.048c34p-2, -0x1.a9a18p-2, -0x1.c0fa4cp0, 0x1.06ec32p0, 0x1.275dc6p-1, 0x1.39fb78p0, 0x1.34325ap0, 0x1.9adf94p0, -0x1.d9e3e6p-1, 0x1.39d88p0, 0x1.e8c344p0, 0x1.94cd96p0, 0x1.ef1b9ep-1, -0x1.efaf5p-7, -0x1.c330acp-2, 0x1.79ff9ep-1, -0x1.70bb4ap0, 0x1.ab8ce4p-2, -0x1.dcd368p0, -0x1.70a96ap0, -0x1.ead8c8p0, 0x1.5fa8dp-1, 0x1.f598bp0, 0x1.d5657ap0, -0x1.16130ap-3, 0x1.aa7ca4p0, -0x1.8bcd12p0, -0x1.464742p0, -0x1.7272c8p0, 0x1.e727aap-1, 0x1.13808p0, -0x1.ea56ecp0, 0x1.ce999ep-4, -0x1.ae6eacp-1, -0x1.fc5afcp-1, 0x1.91fb14p0, -0x1.c0e5e4p-1, -0x1.aa436p-2, -0x1.f9353cp-1, 0x1.c3bf8ap-3, 0x1.7a92a8p0, 0x1.00fd6cp-1, -0x1.3bdc9ap-3, 0x1.a67678p-3, 0x1.7ec1eep-4, 0x1.af190cp0, 0x1.5c9f28p0, 0x1.0e4058p0, -0x1.b2b866p0, -0x1.0a7f08p0, 0x1.be35d8p0, 0x1.d12498p0, 0x1.0656b6p0, 0x1.a535fcp-2, 0x1.3d0646p-1, -0x1.8d8d9ep0, 0x1.5bd05ep-3, 0x1.10c9d2p-2, 0x1.714b0cp0, -0x1.7704d6p0, -0x1.33cdaap0, -0x1.0575fcp-1, 0x1.b6cb52p-2, -0x1.a1e378p-1, 0x1.752a04p-1, 0x1.38529p0, 0x1.bcee9ep-1, -0x1.2874d6p-3, -0x1.101a26p0, -0x1.9170cep-3, 0x1.e1ec04p-1, 0x1.be1476p0, 0x1.c151a2p0, 0x1.8130dep0, -0x1.41c84cp0, 0x1.5028eep0, 0x1.7d002cp-2, -0x1.ccbaf2p0, -0x1.6d2776p-2, -0x1.0eae5p0, 0x1.d48ae2p-1, 0x1.6ee4dep-1, 0x1.8c8e44p0, -0x1.66c3p0, 0x1.35ced6p0, 0x1.566b86p-1, 0x1.8b9fd6p-1, 0x1.0f0f2ap0, 0x1.f5e028p-5, 0x1.ee1d76p-1, -0x1.c53e5p0, 0x1.3eeef8p0, -0x1.c3eb14p0, 0x1.a8512cp-1, 0x1.a8ea84p0, 0x1.819e6cp-1, 0x1.7a22bap0, 0x1.3ed3ccp-1, -0x1.20cf1ep0, -0x1.d2275ep0, -0x1.e8fa7p-1, 0x1.b95d78p0, 0x1.f9c99ep-4, -0x1.d88f8ap-1, 0x1.f68b5ep0, 0x1.c7e28ap0, 0x1.6d1de4p0, -0x1.efc1eep0 };
l_struct_OC_k2c_tensor test1_dense_input_input __ATTRIBUTE_WEAK__;
float c_activation_3_test10_array[6];
float c_activation_3_test7_array[6];
unsigned int j __ATTRIBUTE_WEAK__;
float c_activation_3_test8_array[6];
float test10_dense_input_input_array[2622] = { 0x1.06e78ep-2, -0x1.d19c3cp-5, -0x1.4cf864p-1, -0x1.67c4c4p-2, -0x1.d2076cp-1, 0x1.110214p0, 0x1.ec4942p0, -0x1.f88066p0, -0x1.59b376p-1, -0x1.d8f43cp0, 0x1.2af9d8p0, 0x1.93dc1cp0, -0x1.a5f43ap-5, -0x1.1b0f54p-1, -0x1.beb6bap0, 0x1.bd1feap0, -0x1.aeabcep-3, -0x1.5dbf6cp0, -0x1.7d620ep0, -0x1.d7275p-3, 0x1.82fd54p0, -0x1.27942cp-3, -0x1.79ba0ap-2, 0x1.592dacp-2, 0x1.9ed404p0, 0x1.ca4d46p0, -0x1.190c7ap-3, 0x1.1a4c5ap-2, -0x1.bbb98p0, -0x1.2646bcp-2, 0x1.9004b2p0, -0x1.09478ap-1, -0x1.aa6d18p0, -0x1.c5e776p0, 0x1.2df27ep0, -0x1.02ab06p0, 0x1.b10312p0, -0x1.630d3ap0, -0x1.cba452p-5, -0x1.5bc3b2p0, -0x1.f91fd2p0, 0x1.66ba1ep0, -0x1.fd8efap0, -0x1.ac5c2ep-1, 0x1.aa6014p-1, 0x1.560f1ap0, -0x1.5a742p0, -0x1.a2dccp0, 0x1.14b976p0, -0x1.0b0e38p0, -0x1.60afacp-1, -0x1.7ae074p-1, -0x1.8d891ap-1, 0x1.77b562p-3, -0x1.90eb7cp-2, -0x1.cc8e2ep-1, -0x1.f54ad6p0, 0x1.1f249p0, -0x1.54b532p0, -0x1.9af738p-1, 0x1.b5982p0, 0x1.71e7aep0, 0x1.76fdbep0, 0x1.95bdf6p-1, 0x1.b1c15p-1, 0x1.ff4026p-2, 0x1.6d6afap0, 0x1.0e6ba2p-1, 0x1.be3e24p-1, -0x1.380a46p0, -0x1.95b84ep0, 0x1.7cb708p0, 0x1.033e9ep-1, 0x1.b174dap-4, -0x1.8f8442p-1, -0x1.b5a76ep-1, -0x1.788f42p-1, -0x1.86811ap0, -0x1.a4f30cp0, -0x1.f51512p-1, 0x1.cd5fccp-1, -0x1.3c6dap0, -0x1.4a7984p-2, -0x1.1f1edap0, -0x1.c22a28p0, -0x1.45866cp0, 0x1.56abacp0, -0x1.387aacp0, -0x1.bc7b8p-1, 0x1.f67b0cp-5, -0x1.06c6ccp-1, 0x1.3e5512p-4, -0x1.ca087ap-1, -0x1.ec6272p-1, 0x1.670828p-2, -0x1.a50b98p0, -0x1.52f37cp-1, 0x1.bd4e7ep-1, -0x1.ce7a3cp0, -0x1.ad9286p-1, -0x1.21dfcap-2, 0x1.afb65cp-1, 0x1.859a3ap-3, -0x1.ecb37cp0, 0x1.4f58cp-3, -0x1.ebf67ap0, 0x1.9bdc6ep0, -0x1.0eeef2p0, 0x1.959a7p-2, 0x1.9eee1ap0, 0x1.5d7d9p0, -0x1.6dba6cp-4, 0x1.d66272p0, 0x1.f5188ap0, -0x1.083414p-2, -0x1.61b416p-3, -0x1.b25dc6p-1, -0x1.c304acp0, 0x1.32cb9ap0, -0x1.0373b2p0, 0x1.58a1b8p-1, -0x1.7b3db6p0, 0x1.2da964p0, -0x1.15acfap0, 0x1.7fc482p0, 0x1.eff63p0, -0x1.4d4ba2p0, 0x1.d50546p0, 0x1.2ba79ep0, -0x1.3f67e6p0, -0x1.1a0782p0, -0x1.bb24e4p0, 0x1.ba906ep0, 0x1.98e5f8p0, -0x1.aa0064p-2, -0x1.db67fep-5, -0x1.7ea514p-1, -0x1.6fdefp-3, -0x1.8ff7d4p-3, -0x1.ee440ap-2, -0x1.b70c62p0, -0x1.ad05a6p-1, 0x1.62037ep0, -0x1.197582p-1, 0x1.0807dep0, -0x1.257412p0, 0x1.cfb8acp0, -0x1.a46732p-1, -0x1.4d9e34p0, 0x1.ec6d06p0, 0x1.5de9f2p0, -0x1.65c344p0, 0x1.df103ep-1, 0x1.b7b85ap0, -0x1.dd0ad6p0, 0x1.2ff342p-1, 0x1.e74ab2p0, 0x1.2749eap0, -0x1.6b7b6ap-2, -0x1.ac094cp-1, -0x1.28f34ap0, -0x1.685a3cp0, -0x1.00c72p-1, -0x1.1819f8p-3, -0x1.fb966ap-1, -0x1.4e313cp-2, -0x1.cdb11ep-2, 0x1.ba67d4p-1, 0x1.4cdba6p0, 0x1.fc543ap0, -0x1.640214p-1, -0x1.651954p0, -0x1.1c2b94p-6, 0x1.03d8ap-3, -0x1.0496cp-1, -0x1.ac8c98p0, 0x1.1fd38ep-2, 0x1.57e592p-1, 0x1.51187cp0, 0x1.c6612p-1, 0x1.ab4b9ap-2, -0x1.9172aap-1, -0x1.b11bb8p0, -0x1.9d85e4p0, -0x1.ab0e2p0, 0x1.b9d074p-3, 0x1.d95cbp-1, -0x1.4b77eap-3, -0x1.9cd8b2p-1, 0x1.e3c728p-1, 0x1.f7997ap-2, -0x1.e683f4p-2, -0x1.c7fdeep0, -0x1.9a8038p0, 0x1.2d27b6p-1, 0x1.321532p-1, 0x1.371fdep0, 0x1.3d67f2p0, -0x1.ec306p0, -0x1.6cd3c4p0, -0x1.b603a8p-1, 0x1.58056p0, 0x1.66841p0, -0x1.f5a71ep-2, 0x1.dabd7cp0, 0x1.137b5cp0, 0x1.9998f8p0, -0x1.54decp0, 0x1.4479e6p0, 0x1.78c4acp-2, 0x1.4938d2p0, -0x1.94c3e8p0, 0x1.ce4162p-2, 0x1.56d232p-1, -0x1.809f5cp0, -0x1.766868p0, -0x1.b3b758p0, 0x1.647fa6p-3, -0x1.c90114p-2, 0x1.7c3cdcp0, 0x1.aefafep-1, 0x1.64f584p0, 0x1.1aec98p-1, 0x1.581abcp-2, -0x1.a67dd4p0, 0x1.72327cp0, -0x1.259438p0, -0x1.87c67ep0, -0x1.dffd2p0, -0x1.02865ap0, -0x1.ff81ccp-1, -0x1.7e97e4p-2, 0x1.ac1c38p0, 0x1.3b7abp-1, 0x1.20ff12p-1, -0x1.72b24ap-6, 0x1.7e113ap0, 0x1.8dc65cp0, 0x1.86c9b2p0, 0x1.b967d8p-1, -0x1.03b918p0, -0x1.e9569ep-3, -0x1.b24a44p-1, 0x1.0b6f78p-1, -0x1.dd3f5ap-1, 0x1.1f260cp0, 0x1.a2569ep0, -0x1.46cef4p0, 0x1.3657bep-2, 0x1.172c0ap0, -0x1.2339e8p0, -0x1.21e654p0, 0x1.a8560ap0, -0x1.319882p-1, 0x1.58fa56p-2, -0x1.7c5da8p0, 0x1.20bd42p-4, 0x1.67d804p0, 0x1.af72bep-1, -0x1.373c8p0, -0x1.95cf4p-3, -0x1.6fa71ap-2, -0x1.b1cf74p0, -0x1.43a70cp-1, -0x1.2d8b0ep0, -0x1.a565e8p-1, -0x1.df5764p-1, 0x1.d6c594p0, -0x1.0a3268p0, 0x1.5e3374p0, 0x1.e87712p-1, -0x1.161bdcp-6, -0x1.c964a8p-2, 0x1.79e4f6p0, -0x1.5c626ap0, -0x1.8e6e02p-2, 0x1.927eb4p0, -0x1.c111a2p-1, -0x1.b71596p-3, 0x1.13d418p-1, -0x1.b5c3p-3, -0x1.91999ap-1, 0x1.5158p0, 0x1.5d0cc2p0, 0x1.11223ep-4, -0x1.126232p-2, -0x1.abcaa8p0, -0x1.2c570ap0, 0x1.b9261p-1, 0x1.b948d6p0, -0x1.814026p-1, 0x1.18616ap-1, 0x1.9798a6p0, -0x1.14ca64p-3, -0x1.70028ep-3, 0x1.629df2p0, 0x1.bb86c8p0, -0x1.502cf2p-1, -0x1.e23718p-1, -0x1.897c36p0, -0x1.16ec44p0, 0x1.b2336ep0, 0x1.e94e16p-1, -0x1.27706ap-5, -0x1.d501bp0, -0x1.8a7328p0, -0x1.7a026p0, 0x1.7d6f6cp0, -0x1.e9e65ep-2, 0x1.f387cep-2, -0x1.b7233ep-1, -0x1.a793cp-2, -0x1.503ef6p0, 0x1.b33864p-1, -0x1.3531eep0, -0x1.3a8408p0, 0x1.67ca98p-4, -0x1.102f54p-3, -0x1.cf7696p0, 0x1.db9ed6p-2, -0x1.d4cbbp0, 0x1.3bc8f4p-1, -0x1.42c05p0, 0x1.0a624p-1, -0x1.bfcd24p0, -0x1.1753cep-2, -0x1.46fb6p0, 0x1.bb56cap0, 0x1.862bf6p-1, -0x1.f51a62p-1, 0x1.c6757cp0, 0x1.6a7e32p0, -0x1.c0d044p0, 0x1.b5d30cp0, -0x1.deb2fcp0, 0x1.289424p0, -0x1.d61098p0, -0x1.292816p0, -0x1.d2f378p-2, 0x1.b53ddap-4, 0x1.a3e85p0, 0x1.d18dd6p-2, -0x1.aec068p0, 0x1.132acp-1, 0x1.abfb0ap0, 0x1.84623ep0, -0x1.6a6d88p0, 0x1.91fb44p0, -0x1.d53d8ep0, -0x1.bcca76p0, 0x1.4c842cp0, -0x1.9f4c5ep0, -0x1.897dcp0, -0x1.368028p-1, -0x1.3e834ep0, -0x1.5ec482p0, 0x1.b05364p0, -0x1.15e23p0, -0x1.84a542p-4, -0x1.e416f8p0, -0x1.bb389ap-1, 0x1.eb6082p0, 0x1.4d977ap0, -0x1.9b8b36p-1, -0x1.d5a90ap-1, -0x1.4cbe1cp0, 0x1.880494p-6, 0x1.c9ac04p0, -0x1.2ff75cp-4, -0x1.9fe0fap-2, 0x1.c0ab6cp-2, -0x1.4154bcp0, 0x1.d8e7d4p-3, -0x1.efbea8p-1, 0x1.33ed22p-1, 0x1.c8f6b6p-2, 0x1.328b44p0, 0x1.5e4638p0, -0x1.fa6538p-1, -0x1.6e5cfep-2, 0x1.a3d1p0, -0x1.b81cdep0, 0x1.6257c8p0, 0x1.d45b04p-1, 0x1.e09d5p0, -0x1.074b0cp-4, 0x1.4f448ep-2, -0x1.91236ep-1, 0x1.d0bc22p-1, -0x1.d1bdfep-1, 0x1.c14a36p0, -0x1.cb4e1p-4, 0x1.5a1b98p0, 0x1.397384p-6, -0x1.104308p-1, 0x1.c9b416p-1, -0x1.02be1p-1, -0x1.9d9a7ap-1, -0x1.0ccc52p0, -0x1.868526p0, 0x1.3a4decp-3, -0x1.4c284cp-2, 0x1.8139bep-3, 0x1.fafee8p0, 0x1.5d28p0, 0x1.080842p0, -0x1.975712p-4, 0x1.144fp0, 0x1.9f3d4cp0, -0x1.ee5d1ap-1, -0x1.e94ffp-2, -0x1.cecc5cp0, -0x1.3fb626p-1, -0x1.bb0672p-3, -0x1.6b0c04p-1, -0x1.d8269p0, 0x1.c689p-1, -0x1.d412e8p-6, -0x1.929edcp-1, -0x1.036014p-1, -0x1.2430dcp-3, 0x1.096652p-2, 0x1.2495d4p0, 0x1.54a8d2p0, 0x1.d4357p-2, -0x1.8c61fep0, 0x1.aceefep0, 0x1.cd69bap-1, 0x1.23455p-7, 0x1.ca4ad2p0, 0x1.be61ap-1, -0x1.d2f292p-1, -0x1.141f9cp0, 0x1.0cc2b2p-2, -0x1.e5fec8p0, 0x1.f096ecp0, 0x1.95863ap-2, 0x1.be24bp0, -0x1.b4140cp-2, -0x1.85b5ccp-1, -0x1.c8194p-1, 0x1.e634fcp0, -0x1.8d6218p0, 0x1.94673cp0, -0x1.ba5362p-4, 0x1.c2f6e6p0, -0x1.8ccb4cp-1, 0x1.c924cp0, 0x1.aee18ap-1, 0x1.357bccp0, 0x1.5e0d8ep0, -0x1.691f86p0, 0x1.0531dp0, -0x1.a300fp0, 0x1.246edp0, 0x1.7e94acp0, 0x1.45eaf2p0, 0x1.07f5ccp0, 0x1.088716p-2, 0x1.711b4p0, -0x1.4a8e5ap-3, -0x1.70015cp0, -0x1.c6aacep0, 0x1.b62372p0, 0x1.b1ab1cp-1, 0x1.22acf6p-2, -0x1.68b082p0, -0x1.0dbe2ep0, 0x1.128db4p0, 0x1.1028a6p0, 0x1.d2d0ap-2, -0x1.596d9ep0, -0x1.324ab4p0, 0x1.46da16p0, 0x1.a6adb6p0, 0x1.77aa9ap0, -0x1.7ed60ap0, -0x1.6e8d92p-1, -0x1.cc156ap0, -0x1.28193ap-3, -0x1.7a3c48p0, -0x1.54f89p0, 0x1.bf4814p-3, -0x1.3fad0ap-5, 0x1.67dc6ap-1, -0x1.bc2bf4p0, -0x1.991fc8p-2, 0x1.145cb2p-1, 0x1.1ef9a6p0, 0x1.e8e382p0, 0x1.ea046p0, 0x1.c6d28ap-2, -0x1.9a4338p0, -0x1.d6743cp-1, -0x1.bf34ep0, 0x1.6b44a2p-2, 0x1.9dbb3cp-1, 0x1.bbe9ccp-2, -0x1.99e7aep0, 0x1.7e722cp-1, -0x1.e40ddap-1, 0x1.73abacp0, -0x1.b4e8c2p0, 0x1.1b4d34p-1, -0x1.7f138p0, -0x1.70d0ep-2, -0x1.9f0f6p0, -0x1.30810ep-3, -0x1.1cd696p-2, 0x1.54682cp0, 0x1.8627e2p0, -0x1.11eb12p0, 0x1.e5c0d4p0, -0x1.2c207ap-1, 0x1.6dfa6cp-1, 0x1.2a4386p0, -0x1.6ac83p-1, 0x1.5f11ccp0, -0x1.6d3a2p-1, 0x1.1ce99p0, 0x1.4c0286p0, -0x1.893368p-2, 0x1.ebb17ap0, -0x1.ce9b7p0, -0x1.d0f8dcp-2, -0x1.1e9e9ep0, 0x1.b23e9ap-1, -0x1.a3006ep0, 0x1.acda1p0, 0x1.ce65bep0, -0x1.a73cc6p0, 0x1.138c98p0, -0x1.6f416ap-4, -0x1.2dcf72p-2, -0x1.2d450ap-1, -0x1.1807f6p-3, 0x1.6c554cp-1, 0x1.19f9b4p0, -0x1.a5ef36p0, 0x1.55044cp0, -0x1.f91316p-1, -0x1.eb709p0, 0x1.4e23eap-2, -0x1.12813ep0, -0x1.174d8p0, 0x1.ab7ccep0, 0x1.ea15a4p-1, -0x1.b1f13p-2, -0x1.956afcp0, -0x1.088206p-1, 0x1.e17be6p0, -0x1.399522p-1, 0x1.b1187p0, -0x1.73cf2ep0, -0x1.ed409p0, -0x1.1aa748p-1, -0x1.5440c2p0, -0x1.6f5572p-4, -0x1.09d6f2p-1, 0x1.8f307ep0, 0x1.e6ee9ap-2, -0x1.969954p0, 0x1.351992p-1, 0x1.4704c8p-1, 0x1.c04468p0, -0x1.2aae66p-3, -0x1.e43cbcp0, 0x1.205e06p-1, -0x1.aea59cp-1, -0x1.bee2ap0, 0x1.d55272p-3, 0x1.b3beaap-2, 0x1.3d87f4p-2, 0x1.c77ff6p-2, -0x1.4047cep-1, 0x1.1f44c4p0, -0x1.e6eefep-1, 0x1.7403c6p0, -0x1.f05cc4p-1, -0x1.5d6716p0, 0x1.b53ed8p-1, -0x1.4f47f2p0, 0x1.deee68p-1, 0x1.03a20cp-4, -0x1.8dd9a6p-2, -0x1.0fcae6p0, 0x1.f1411p0, -0x1.e9061ep-1, -0x1.e6197ap-1, 0x1.c7e264p0, -0x1.35a46cp-1, -0x1.986ab4p0, 0x1.69432cp0, 0x1.91b9c2p0, 0x1.ea3a2ap0, 0x1.fdfe34p0, -0x1.6598fcp-2, 0x1.d7fca2p0, -0x1.87ee16p-2, -0x1.01fc7p0, -0x1.4ca9p-2, 0x1.e31c6p-1, -0x1.29b462p-5, -0x1.96c0d6p-3, -0x1.6c5146p-1, 0x1.f8e424p0, -0x1.d3fa1ap-1, -0x1.931712p0, -0x1.6def9ep-1, 0x1.c584b4p0, 0x1.c768b8p-1, 0x1.b9ab2ep-1, 0x1.8cb236p-4, -0x1.023daep-2, -0x1.987116p-3, -0x1.1d15b4p0, 0x1.229128p0, -0x1.5b599ap-3, -0x1.c35a1cp-2, 0x1.f481bcp0, 0x1.9844cep-4, -0x1.63bab2p-1, -0x1.eae8bp0, -0x1.6fa816p0, -0x1.bf9b14p-2, 0x1.ce1e06p-2, -0x1.e00dccp0, 0x1.818882p0, -0x1.380d82p-1, -0x1.0ee064p-2, -0x1.588cfep-2, -0x1.5abf3cp-3, -0x1.ef6c8ap0, 0x1.574062p0, -0x1.9ab944p0, -0x1.995a1cp0, -0x1.c278a4p0, -0x1.fe50f2p0, 0x1.6e5fb6p0, 0x1.57812cp-1, 0x1.2ffd2ap-1, 0x1.f0eb16p0, -0x1.4c2bcep-5, 0x1.159e12p-1, 0x1.79868cp-1, -0x1.836654p-1, -0x1.a2e056p-6, 0x1.f2bb86p-3, 0x1.91ff3ap-2, 0x1.b551b2p-2, -0x1.6fc4ecp-1, 0x1.3b0acp0, 0x1.a03e52p-1, -0x1.be28bep0, 0x1.13eadcp0, 0x1.82e414p-1, 0x1.d91e94p-3, 0x1.0983p0, -0x1.e39d06p0, -0x1.00f93p0, -0x1.89d034p0, 0x1.20c262p-1, 0x1.441fe2p0, 0x1.a164aep0, -0x1.adf13p-3, 0x1.0b4c7cp0, -0x1.07bb34p-1, 0x1.07a422p-3, 0x1.3a240ep0, -0x1.5083eap-1, 0x1.f486a6p-2, 0x1.0f0c2ep-1, 0x1.57bdc4p-3, 0x1.3998a4p0, 0x1.fd8572p-2, -0x1.d4a878p-3, -0x1.718e8ep-1, 0x1.a9f75p-3, 0x1.f803dcp0, -0x1.550fbp0, -0x1.9f4cc8p0, -0x1.38ccd2p-1, 0x1.6783bp0, -0x1.921f9ep-3, -0x1.a0d894p-2, 0x1.db7b9p-4, 0x1.4ba7c4p0, -0x1.15d17cp-1, -0x1.34aabap-1, -0x1.39cc2p0, -0x1.eb9a48p-1, 0x1.3a4e14p0, 0x1.25f0dcp-1, -0x1.ff8f46p0, 0x1.231dccp-1, 0x1.dfe422p0, -0x1.fba64ep-1, 0x1.7626ep-1, 0x1.63f2d4p-2, 0x1.8b76e4p-2, -0x1.330fbap-2, 0x1.806186p0, -0x1.95ed84p0, -0x1.124ccep0, -0x1.d9f55cp0, 0x1.b0977p0, -0x1.88207ep-1, 0x1.517054p0, -0x1.ad4384p-2, 0x1.8921e6p0, -0x1.17254ep0, 0x1.e762f6p0, 0x1.a6bcf4p-1, -0x1.fb4fa4p0, -0x1.66cefp-1, 0x1.95660ap0, -0x1.0e265ep-1, -0x1.6594e2p0, 0x1.7c6fd6p-1, -0x1.0d964ap-5, 0x1.d982e6p0, 0x1.7b3c9p0, -0x1.134c9ep0, 0x1.56b79cp-1, -0x1.1dab5p-1, 0x1.1d7272p0, -0x1.526878p0, -0x1.da6018p0, 0x1.d3588cp0, 0x1.8b65b2p0, 0x1.835bf6p0, 0x1.518ffep-3, -0x1.1f461cp-2, -0x1.73e536p0, -0x1.b50236p-1, 0x1.37055cp-2, 0x1.0020e6p-1, 0x1.2e8f3p0, 0x1.99014p0, -0x1.5c1ca4p0, -0x1.8bb29ep0, -0x1.22be76p-6, 0x1.3fe258p-2, 0x1.728e4ap0, -0x1.867e5ap0, 0x1.4c6cd4p-1, -0x1.66f4e2p-2, -0x1.f0f4d2p0, 0x1.65932p0, -0x1.ca9a0ep0, -0x1.e993ap-3, 0x1.05ed7cp-1, -0x1.2a3ff6p0, -0x1.f1907ep0, -0x1.b6dfe2p-1, -0x1.5fe518p0, -0x1.465702p-2, -0x1.fb3438p-4, -0x1.e3288p0, -0x1.fa837ep0, -0x1.192bf8p-1, 0x1.51596cp-1, -0x1.4eb86ep0, 0x1.59853cp-2, 0x1.8eab96p-2, 0x1.7747ep0, -0x1.5e2a28p-3, 0x1.18f704p0, -0x1.fe4acp-1, -0x1.a203c8p0, 0x1.de3306p0, 0x1.d2b9d2p-1, -0x1.ef3dcap-1, 0x1.2ecd7cp-1, 0x1.57f98ep-2, -0x1.c8b1b6p-1, -0x1.bb59fap-2, 0x1.f29372p-1, 0x1.f0f98cp-1, -0x1.eea9fap-1, -0x1.76427p0, -0x1.9b4cfap0, -0x1.8594ep-4, 0x1.28db2ap-2, 0x1.41be44p0, 0x1.63b876p-2, -0x1.965e64p0, -0x1.15cfeap-3, 0x1.03edaap-1, -0x1.c9a958p-5, -0x1.32aa9ap-4, 0x1.7cae4ep-3, -0x1.4b68f8p0, 0x1.4dd984p-3, -0x1.fffb78p-5, 0x1.bb4874p-2, 0x1.5c715ap-2, 0x1.cdd15ep0, 0x1.795706p0, -0x1.107682p0, 0x1.bc0b4cp0, 0x1.869dc4p-1, 0x1.4f378cp0, -0x1.4f973ep-1, 0x1.37b2a6p-1, -0x1.e6056p0, 0x1.0ededap0, -0x1.735926p0, 0x1.1d4916p-2, -0x1.2428a4p0, -0x1.54386ap-1, -0x1.4b5a8ep-7, 0x1.006448p-2, -0x1.210d9cp-1, 0x1.d30fap0, -0x1.2bc868p-2, -0x1.553462p-3, 0x1.b92d8cp-1, 0x1.4abcacp-2, -0x1.2176dp0, -0x1.3b7e2p0, -0x1.8d7b0cp-4, 0x1.aa1944p0, -0x1.6690d2p0, 0x1.d35d74p-1, -0x1.1419d4p0, -0x1.8bb79p0, -0x1.d45c3cp0, 0x1.0ae1c6p-1, -0x1.a47158p-1, -0x1.d0a9fp-3, -0x1.c2408ep0, 0x1.fb6c24p0, -0x1.ad4538p0, 0x1.bd494ep0, 0x1.10bde6p-5, -0x1.04ef8p-3, 0x1.aeae36p-1, 0x1.00480ap-2, -0x1.d5e12cp0, 0x1.14d474p-7, -0x1.5e3db6p0, -0x1.1651cep-1, -0x1.0a80d6p-3, 0x1.bf6cd4p-1, 0x1.3a8632p0, -0x1.f5d94p-3, 0x1.4f8578p-1, -0x1.f06cap0, 0x1.4d776ap0, 0x1.59dc74p0, -0x1.6fe694p-1, -0x1.9162fep-2, -0x1.13d02ep-1, 0x1.2d336cp0, 0x1.45575ap-1, 0x1.aefbp-1, -0x1.b5586ap-7, 0x1.0b9186p-1, 0x1.d0dbb6p-1, -0x1.bc7ecep0, 0x1.8d792p-3, -0x1.2644b4p0, 0x1.40c11ep-2, -0x1.ec1a9p0, 0x1.68551ep0, -0x1.535f2p0, -0x1.ad1032p-5, 0x1.77c394p-1, 0x1.529964p-1, 0x1.d89c4ep0, -0x1.a7ea38p0, 0x1.109938p0, 0x1.fd34cep-1, 0x1.0b7f5ep0, -0x1.a90106p0, -0x1.e6ebaep0, -0x1.a364d8p0, 0x1.3e1dcp-2, -0x1.ae454cp-1, 0x1.b3d702p-1, -0x1.311d86p-1, -0x1.f068c6p0, 0x1.ed89aap-2, -0x1.b40c8ap0, -0x1.0f7d3cp-2, -0x1.a0e688p-1, 0x1.68ce3ep0, -0x1.da41aap-2, 0x1.5102dp0, -0x1.9be5aap0, 0x1.e5d30ap0, -0x1.6d24dp0, 0x1.5c3828p-2, -0x1.e17896p-1, 0x1.64c7eep-2, 0x1.9d4fbap-1, -0x1.99b266p-2, 0x1.fe3a42p0, -0x1.e0f90cp-3, 0x1.298428p0, -0x1.7df896p-2, 0x1.0f1bb8p-1, -0x1.15d0b2p0, 0x1.7544ecp-1, -0x1.ac36f8p0, -0x1.3bce88p0, -0x1.1ceb42p0, 0x1.b87b4cp-4, 0x1.f9b782p-3, 0x1.bf0aa8p-4, 0x1.3a0196p-1, 0x1.d51116p-1, 0x1.9c367ep0, -0x1.1e1506p-3, 0x1.1471cap-2, 0x1.6287b6p0, -0x1.308196p0, -0x1.d1f644p-1, 0x1.3165b2p0, -0x1.c9063ep-1, 0x1.1303dap0, 0x1.232fap-2, -0x1.aebf98p-1, -0x1.89dfccp-2, -0x1.aeef4ap0, -0x1.d14b84p0, 0x1.13552cp0, 0x1.f75b02p-4, 0x1.7264bep0, 0x1.27fcfp-1, -0x1.419f64p-1, 0x1.613e0cp0, 0x1.89792p-1, 0x1.92a4b2p0, -0x1.090a42p-2, 0x1.beeb24p-1, 0x1.170678p-2, -0x1.2f071p0, 0x1.d95958p0, -0x1.589098p-3, -0x1.cf3b16p0, 0x1.ff87e4p0, -0x1.a2ba2ep-3, -0x1.f65eccp0, -0x1.ef673ep0, 0x1.998becp0, -0x1.bcee8p0, 0x1.b770f8p-3, 0x1.63a932p-4, -0x1.74294p0, -0x1.794fecp0, -0x1.d4f5dap0, -0x1.b62b96p-3, -0x1.1ce0f4p0, 0x1.39bf54p0, -0x1.20021cp-1, -0x1.b0c4b8p-7, 0x1.1b936cp-1, -0x1.f79836p0, 0x1.84df8ap-2, -0x1.4d896ap-4, 0x1.c4d288p0, -0x1.095752p0, -0x1.d75102p-1, -0x1.52cfcep-3, 0x1.9249e4p0, 0x1.15202p-3, 0x1.6e9f4ep0, 0x1.b2c74cp0, -0x1.d0a12cp-1, 0x1.ed18d2p0, 0x1.09463ap0, 0x1.1877acp-4, 0x1.3dfc4p0, -0x1.a1b5p-3, 0x1.dfd796p-1, 0x1.0f6332p-3, 0x1.98072ap0, 0x1.f1ed22p0, -0x1.d12f3ep0, 0x1.7074d2p0, -0x1.53d154p0, 0x1.a7ff12p0, 0x1.9ef264p0, 0x1.1992a4p-1, -0x1.cb43a2p0, -0x1.0f1972p-3, -0x1.935278p-2, 0x1.bec028p0, 0x1.802c6ap0, -0x1.2ac8b6p0, -0x1.3da866p-3, 0x1.d3f1cap-1, -0x1.53da5p-4, -0x1.adb65p0, 0x1.c60738p-1, 0x1.7606aep0, -0x1.5d9cc4p0, 0x1.c5632cp0, -0x1.56ef12p0, 0x1.0fe72p0, 0x1.28cbbp-1, 0x1.86f07ep-2, 0x1.76d0bp-1, 0x1.5c9864p0, 0x1.43c5ep0, -0x1.f4d51p-2, 0x1.030c3p0, -0x1.469204p-4, 0x1.106358p-8, -0x1.21c786p-1, -0x1.8aaccep-1, 0x1.9a59b4p-7, -0x1.d6ea4p-1, -0x1.df625ep0, 0x1.e75ce8p-1, 0x1.881f2p0, -0x1.f9dcb2p-2, 0x1.41658ap0, -0x1.128fbp-1, -0x1.b71478p-2, 0x1.1404acp0, 0x1.13282ep-1, -0x1.96585p-1, 0x1.96b4d8p0, 0x1.183c1ep-1, 0x1.2e2836p0, 0x1.1658bcp0, -0x1.453d02p-2, -0x1.6cf71p0, 0x1.c5a03ep0, 0x1.43ea3ap0, -0x1.1b3994p0, 0x1.23392p-4, 0x1.46481p-1, 0x1.c83048p0, 0x1.66ab7ep0, -0x1.1112ccp0, -0x1.eed538p-4, -0x1.e0203ep0, -0x1.807f16p-1, 0x1.0be65ap-2, -0x1.f2e70ap-1, 0x1.aa73c4p-1, 0x1.6fc01cp-1, 0x1.daf964p-1, 0x1.938748p0, -0x1.5c0aap-1, 0x1.34f8d8p0, 0x1.8fecf6p-3, 0x1.15ddfep-2, -0x1.20841p-1, 0x1.c6caf6p0, -0x1.b8afap-3, 0x1.4b93bap0, -0x1.dacaaep-4, 0x1.fe5a36p-1, 0x1.956c3ap-2, -0x1.47374ep0, 0x1.dc2a28p-1, 0x1.5f2674p-2, -0x1.fa77c2p0, 0x1.202d12p0, -0x1.553572p0, 0x1.21c27ep0, -0x1.62243ep-6, -0x1.bd9ae4p-3, 0x1.e3204ap0, 0x1.844244p-1, -0x1.b08e0ep0, 0x1.eb8f0ep0, -0x1.7c26dcp0, 0x1.ab054ep0, -0x1.8bdbaap-1, -0x1.e5f32cp-5, 0x1.7407aap0, 0x1.b4bffp0, 0x1.fbd65ep0, 0x1.80172ep0, 0x1.8cc546p-2, 0x1.2c003ep0, 0x1.5d54acp-1, -0x1.cc91aap0, 0x1.81357ep0, 0x1.a4f5fep-1, -0x1.5134a4p-2, 0x1.5c7abcp0, -0x1.0242bep0, 0x1.d8dd56p-2, 0x1.3f8856p0, 0x1.8fcbe4p0, -0x1.70616p0, -0x1.d50ed2p-1, 0x1.ca9006p0, 0x1.de7ca4p0, 0x1.6b5526p0, 0x1.0b8846p-1, -0x1.893dcep0, -0x1.8dc36ep0, -0x1.7d2a66p0, -0x1.47e68p0, 0x1.97198cp-2, -0x1.26824ep0, 0x1.688c0ep0, 0x1.70a98ep-2, 0x1.f2ae3ep0, 0x1.5f2f26p0, -0x1.b6d7e4p0, -0x1.5a6bacp0, 0x1.13e1bcp0, -0x1.d0026cp-2, -0x1.c71f9ap0, 0x1.3e4544p0, 0x1.30e63p0, -0x1.298906p0, 0x1.6e73b2p0, 0x1.5a2856p-1, 0x1.b6e228p0, 0x1.c3a19cp-1, -0x1.433aa8p0, 0x1.d62506p-4, -0x1.d777b4p-1, -0x1.b6dfe8p0, 0x1.69443ap0, -0x1.4365a6p0, 0x1.e15fbep-2, -0x1.edd83ap0, -0x1.83db7cp-4, -0x1.d0e7dep-1, -0x1.3d6eacp-1, 0x1.4e9754p-1, 0x1.e013ep0, -0x1.fe5078p-2, 0x1.fd9d1p-2, -0x1.f300aep0, -0x1.c27598p-2, -0x1.65d90ap-1, -0x1.2ec92ap0, -0x1.0cc34ap0, 0x1.8b325ap0, -0x1.2ec148p0, -0x1.60d37cp-4, -0x1.ada106p-3, -0x1.b36c0ap0, 0x1.a6615p-4, 0x1.af4ae4p0, -0x1.b5d314p0, -0x1.be6b52p-2, -0x1.6bf9f8p-3, 0x1.ad808ep-3, 0x1.450f36p-8, -0x1.1d4464p0, 0x1.ca461cp0, -0x1.f74a84p-1, 0x1.bb1ca4p-1, -0x1.8374f2p0, -0x1.76aa18p0, -0x1.2eaabp-1, -0x1.07b8f8p0, 0x1.fe6594p0, -0x1.fdf964p-1, 0x1.725fdep-1, 0x1.3e8c72p-1, -0x1.a0ec7p-1, 0x1.73185p-1, 0x1.3ad0ep0, -0x1.e9f5a2p0, 0x1.39b11p0, -0x1.43226ep0, 0x1.8c6ff8p-2, 0x1.cf97bcp0, 0x1.206eap0, -0x1.0796c6p-1, -0x1.395a98p-1, 0x1.671082p-2, -0x1.22e178p-1, 0x1.7b333ep-2, 0x1.cea36cp-1, -0x1.ab620cp0, 0x1.d7c91cp-4, 0x1.22aefp0, -0x1.7c7d34p0, 0x1.1703cap0, 0x1.638244p0, -0x1.0f16fcp0, -0x1.fac49cp-3, 0x1.ea69a2p0, -0x1.178852p-3, 0x1.b9beeap-1, 0x1.9cb3c4p0, 0x1.fa23f4p0, -0x1.4ba9fcp-4, -0x1.e5a222p0, 0x1.9a9acap-2, -0x1.9424fap-4, -0x1.ab6728p-1, 0x1.963b12p-1, 0x1.601df6p0, 0x1.1d27dcp-4, 0x1.0b0892p0, -0x1.d41a2ep0, -0x1.b6dca6p0, 0x1.f39848p0, 0x1.08474cp0, -0x1.1044e4p0, 0x1.898eacp0, 0x1.a52762p0, 0x1.acc548p-1, -0x1.5384dap-1, -0x1.470b0ep0, -0x1.f815bap0, 0x1.ebce06p-4, 0x1.b6008cp0, -0x1.678aacp-6, -0x1.d03564p0, -0x1.adf28p-1, -0x1.3936e4p-6, -0x1.f0ac1p0, -0x1.e4dc14p-1, 0x1.25930ap-1, -0x1.e071f4p-1, 0x1.237d6cp-1, 0x1.264eecp0, -0x1.176e9ap-1, -0x1.ced252p0, -0x1.5c9ee8p0, -0x1.b8108ep-5, 0x1.41250ep0, 0x1.ca4d78p0, 0x1.be92a8p-1, 0x1.e37c6p-2, -0x1.3d79cp-2, -0x1.6e1458p-3, 0x1.51102p0, -0x1.1c6bf8p-1, 0x1.a5d644p0, 0x1.e31046p0, 0x1.06280cp0, 0x1.ddd464p0, 0x1.e1128ep0, 0x1.97a0a2p-1, 0x1.25e662p0, -0x1.14a07p-1, 0x1.324fbcp-1, 0x1.5fce8cp-3, -0x1.326702p0, -0x1.e46ae2p0, -0x1.050588p0, 0x1.f7c746p0, -0x1.2380c8p-1, -0x1.44c82ap-5, 0x1.b2826p0, -0x1.f62edcp-1, 0x1.c2a4dep-1, 0x1.c8182ep-1, 0x1.ef3898p-1, -0x1.4cf6aap-2, -0x1.2dfd4p0, 0x1.d213d4p-1, 0x1.67712cp0, -0x1.8b88fep-3, 0x1.fd420ap0, -0x1.5e3be6p-1, -0x1.7654d6p0, 0x1.694e32p-1, -0x1.7e5ed4p0, -0x1.9b377ep-1, 0x1.d10ef8p-2, 0x1.e86fa6p0, -0x1.eaec98p-1, -0x1.cea00cp-1, -0x1.e7fc5ap0, 0x1.f61798p-3, 0x1.9f638ep-2, -0x1.8baab6p-2, 0x1.37515ap0, -0x1.70eadcp-1, 0x1.28e4e6p0, 0x1.05c7a2p-1, 0x1.80a658p-1, 0x1.743e64p-1, -0x1.b8263ep0, -0x1.7bd052p0, -0x1.12ac3ep0, -0x1.b85ba2p-4, -0x1.c7e71cp0, -0x1.3bf66cp0, 0x1.e0bde2p0, 0x1.5b7afep-3, -0x1.11a2eap-1, 0x1.a6f77cp0, 0x1.63fbc6p-1, 0x1.b2d4bcp0, 0x1.7dedbep-1, 0x1.84ad96p-1, 0x1.91a90cp-2, -0x1.34ecdap-1, 0x1.1d13aap0, -0x1.dd7faap0, 0x1.b7b7b4p0, 0x1.a87478p0, -0x1.3f6a5p-2, 0x1.aaaa3ep0, -0x1.1354aap0, 0x1.0a188ap0, 0x1.92f26ap-1, -0x1.9abe16p0, 0x1.5c5734p-1, 0x1.40d9d6p0, 0x1.ed6d62p0, 0x1.8a9ca2p0, 0x1.943458p0, -0x1.6f39f6p0, -0x1.29062ep0, 0x1.f4ab5p-1, -0x1.f9332ep0, -0x1.2a4b9p-1, 0x1.a937ep-1, 0x1.63457cp0, -0x1.68c1a6p0, -0x1.1bb73ap0, 0x1.ce79e6p-1, -0x1.a4a134p0, -0x1.89220ap0, 0x1.cd3c4ep-2, 0x1.ad298p-1, -0x1.71d75ep-2, -0x1.b31b2ap-3, 0x1.8b779ap-2, 0x1.a71d4ap0, 0x1.92bcd6p0, -0x1.30bf1ep0, 0x1.57739cp-7, -0x1.4f4798p0, 0x1.bcc08p-1, 0x1.7098ep0, -0x1.c30998p-1, 0x1.38d42ep0, 0x1.08b586p0, -0x1.ea25b8p0, 0x1.941406p-3, -0x1.980acp0, 0x1.967456p0, -0x1.c8a548p-2, 0x1.2fb1c8p-1, -0x1.ece4f6p-2, 0x1.589e72p0, 0x1.d6fc72p-4, 0x1.070f8p0, 0x1.d9b85ap0, 0x1.e71488p-4, 0x1.2e4fa6p-2, 0x1.42e708p0, -0x1.ebd84cp-1, 0x1.5d306cp-2, -0x1.7f445ep-1, -0x1.deff0cp-1, 0x1.4f35c2p0, 0x1.0b9adcp0, -0x1.7e3792p0, -0x1.6b04fap-1, -0x1.376c4ap0, 0x1.b6c826p-1, 0x1.bc819p-1, 0x1.913c66p-1, -0x1.ea8de8p0, -0x1.95150ap0, -0x1.91c8d4p0, 0x1.6b11ap0, -0x1.49e674p-2, -0x1.081d1ap-1, -0x1.dafa5p0, 0x1.4f5fb2p-2, 0x1.30a4b2p0, -0x1.2ebb92p-2, -0x1.ce34f8p0, 0x1.ad9606p-4, -0x1.2035ep-1, 0x1.578b92p-1, -0x1.14237ep0, -0x1.6c131p-1, -0x1.5811bap-2, 0x1.e4a5fcp-2, 0x1.397b56p0, -0x1.244ed8p0, -0x1.7fccp0, 0x1.2452bp-1, 0x1.4f8348p0, 0x1.0274dcp-1, 0x1.a0a1b8p-1, 0x1.694f3cp-1, -0x1.f99b7p0, -0x1.444c46p-1, 0x1.32ba8cp0, -0x1.f0854ap0, 0x1.6e11fap-1, -0x1.115d7cp0, -0x1.0a8f6cp0, 0x1.a501ap0, -0x1.0f8472p0, 0x1.ca5458p-1, -0x1.5f56e4p0, 0x1.b34b5ap-1, 0x1.46f32ap0, 0x1.526234p0, -0x1.285dbep0, -0x1.fbaf1cp0, -0x1.1093aap-3, -0x1.b0580ep0, 0x1.9e925cp-1, 0x1.2b69fep-1, -0x1.07ea24p0, -0x1.9a5bf4p-2, -0x1.b95f72p-1, -0x1.128b04p-1, -0x1.29e36ep-1, 0x1.71088ap0, 0x1.608644p0, 0x1.069202p-2, -0x1.3e251p-2, 0x1.4d7534p-2, 0x1.206a04p-1, -0x1.51660cp-1, 0x1.ef28fcp-1, 0x1.e01e4ap-1, -0x1.b7f444p-1, -0x1.eeb6cp-2, 0x1.03bf94p-3, 0x1.e54816p-2, 0x1.59a5eap0, 0x1.618a84p0, 0x1.51960cp-1, 0x1.bdfe78p0, -0x1.6198aap-1, -0x1.e5bbd2p0, -0x1.53e8acp-1, 0x1.6f1a7cp-2, 0x1.7bf99cp0, 0x1.cc4588p0, -0x1.53367p0, 0x1.d0aa06p-4, 0x1.0df9dp-2, 0x1.eae71p0, 0x1.03ad7ap-4, 0x1.c72f6ep0, -0x1.1b89aep-1, 0x1.90b374p0, 0x1.b3c84ap-5, 0x1.499386p0, 0x1.61ff56p0, -0x1.25fbep-3, 0x1.bc5308p-2, -0x1.282a68p0, 0x1.bcb2d8p-1, -0x1.e2285p-2, -0x1.99dcfp-5, 0x1.54966p0, 0x1.521058p-2, 0x1.878eb6p0, 0x1.44600ap0, -0x1.5c06dap0, -0x1.021c26p0, -0x1.62ee6ep0, -0x1.2c6b62p-1, 0x1.5f9f12p-1, -0x1.9999a8p0, 0x1.0b0114p-3, 0x1.a9be8ap0, -0x1.a400a6p-2, 0x1.b45696p0, -0x1.8f9e72p0, -0x1.29448ap-1, 0x1.8c9c5ap0, 0x1.0778fep-5, 0x1.b5b4bcp-1, -0x1.20373cp-1, 0x1.0d2eccp-2, -0x1.cd1da8p-1, -0x1.de3f6cp0, 0x1.7dd42cp0, 0x1.4be98p0, 0x1.14d812p-2, -0x1.4c2254p-1, 0x1.8ba9f4p-3, 0x1.552b46p-1, -0x1.2114dp0, -0x1.57ccb2p-1, 0x1.fcec7cp-1, -0x1.90797ep0, -0x1.3b0c08p-1, 0x1.86dbbap-1, -0x1.b65c66p0, -0x1.5d170ap-1, -0x1.d79cd6p0, 0x1.e5f8aep0, 0x1.38977ap0, -0x1.3761ecp0, -0x1.89aee2p0, -0x1.76e9e4p-2, 0x1.1d8b1cp0, 0x1.87b208p0, 0x1.6cb1d6p-1, -0x1.cb6b06p-1, -0x1.68082ep-2, 0x1.dd390ap-2, -0x1.e4046ap0, 0x1.5631dp-1, -0x1.b6d37cp0, 0x1.8ec86ep0, 0x1.578c0ep-3, 0x1.12c5acp0, 0x1.248d1p-6, 0x1.2406ep0, -0x1.33a3f8p-1, -0x1.16b516p0, -0x1.3141bep0, -0x1.09c50ep-1, -0x1.7e0a16p-3, 0x1.f2396ap0, 0x1.492072p-1, 0x1.fe9a7ep0, -0x1.4232eap0, -0x1.9c08d2p-1, -0x1.432bcp-3, 0x1.eb90a2p0, -0x1.0c528cp-1, 0x1.8c6408p-1, 0x1.90855ep0, 0x1.31cd2ep-4, -0x1.6e51b4p-2, -0x1.eebc6cp0, -0x1.5e69cap-3, -0x1.f20942p0, -0x1.7181fcp-2, 0x1.ad251ep-1, -0x1.c7e91ap-5, 0x1.e1291ap0, 0x1.cdebfep-1, -0x1.c8a1a6p-1, 0x1.8c8454p0, 0x1.1eb6cp-1, 0x1.ccb4d6p0, -0x1.21365ap0, -0x1.cfb264p0, -0x1.b7dd66p0, -0x1.f7e326p-3, 0x1.1a953ap-1, -0x1.c42214p0, -0x1.3d8dc4p0, -0x1.e6cd7cp-2, 0x1.2e56bcp-1, -0x1.0b1b36p0, -0x1.02600ep0, 0x1.ecee16p-2, -0x1.334fc8p0, 0x1.4117bap-1, -0x1.88aa38p0, 0x1.db5c8ap0, -0x1.3edc34p0, -0x1.0265d6p-1, 0x1.a6c3a2p0, 0x1.c1c462p-2, 0x1.e469ccp0, 0x1.2f32ep-2, 0x1.2143a4p-2, -0x1.09e1eep0, 0x1.be99p-1, -0x1.669cbap0, -0x1.23236cp0, 0x1.9ccf66p0, -0x1.53be74p-2, 0x1.1eb8bep-1, 0x1.efc484p-3, -0x1.18ce34p0, 0x1.d4c194p-4, 0x1.f2b0f2p0, -0x1.fa5ffap-2, -0x1.62a3aap0, 0x1.5dfcecp-1, 0x1.ff4eaep0, 0x1.18632ep0, -0x1.c6960ep-2, -0x1.31ef86p-1, 0x1.95c542p0, 0x1.82e5f2p-2, -0x1.89e4d8p0, -0x1.c4d07ep0, -0x1.0c77cp-1, -0x1.c67e94p-1, 0x1.a5ee64p-1, -0x1.75071ap0, 0x1.31829cp0, 0x1.dfeb7cp0, 0x1.a18a0ep0, 0x1.0e7d8p0, 0x1.79a83p0, 0x1.b284fp0, 0x1.363bcp0, -0x1.9829bep-1, 0x1.7bb9ccp0, 0x1.bd6954p0, -0x1.ff269ap0, 0x1.98a8e2p0, -0x1.649054p0, -0x1.1fe35ep0, 0x1.331568p0, 0x1.35a2b2p0, 0x1.63e882p0, 0x1.2cac8p-2, 0x1.aac12ap0, -0x1.7228e6p0, 0x1.e6394ep-1, 0x1.6689d8p0, 0x1.9ea582p-1, 0x1.b9f5a4p-3, -0x1.3092e8p-1, 0x1.64850ep-2, 0x1.2a8698p0, -0x1.7e0238p-2, -0x1.01ed1ap-1, 0x1.bf161ap-1, 0x1.520facp-3, 0x1.0e45e6p-1, 0x1.1bd2eap-2, 0x1.7b2b5p0, -0x1.00e6acp0, 0x1.23a45p0, 0x1.11f89p-1, -0x1.e6a6dp-2, -0x1.fe60ecp-1, -0x1.f06636p-1, -0x1.96b568p-3, 0x1.3df5d6p0, 0x1.635e16p-1, 0x1.36b74ep0, 0x1.65e018p-5, -0x1.fa0cp0, 0x1.bb79d4p0, -0x1.51c894p-4, 0x1.e3f4f8p-1, 0x1.79778cp-3, 0x1.40dc9cp0, -0x1.82f5dcp-1, 0x1.e14504p0, -0x1.481048p-3, -0x1.13f7c4p0, 0x1.0103fap0, 0x1.d3372ap0, 0x1.4c4084p0, 0x1.5314aep-1, -0x1.f28548p0, -0x1.cdf024p-1, 0x1.38fe3ap0, -0x1.33f5e8p0, -0x1.62745cp-4, -0x1.cc51dp0, 0x1.e26c3cp0, 0x1.287ddep0, -0x1.0f908p-1, -0x1.5991c4p0, -0x1.968cbp-1, 0x1.5e4238p-3, -0x1.e73598p-3, -0x1.a39cfp0, -0x1.c020aap0, -0x1.02d36ep-1, 0x1.6e7602p-1, -0x1.351b24p-2, -0x1.8b9d6cp0, -0x1.f04b2ep-1, 0x1.f9517cp0, 0x1.5ff4d8p-1, 0x1.c855d6p-1, -0x1.74f1d2p0, -0x1.294064p-1, -0x1.94c866p-2, -0x1.a137fp0, 0x1.c4ee0cp-2, -0x1.2e7956p-2, 0x1.df163p0, -0x1.276a76p-2, 0x1.8a911ep0, -0x1.063d4ep-1, 0x1.ca73c8p-3, 0x1.bf0c14p-1, 0x1.48b99cp0, 0x1.8d7c24p-6, -0x1.31141ep-1, -0x1.e307e6p-1, 0x1.d6146ep-2, -0x1.5f0526p-1, 0x1.9b852ep-1, -0x1.a9c4eep0, 0x1.66a4d8p0, 0x1.56eb64p-2, -0x1.70c30ep-4, 0x1.4cf892p-2, -0x1.202e6ep0, -0x1.5d97e2p0, 0x1.f60fecp0, -0x1.615138p-2, 0x1.af2deap-1, -0x1.220fdep-4, 0x1.6b4e32p-2, 0x1.352e86p-1, -0x1.b051b4p0, -0x1.06475ap0, -0x1.af4cbep0, -0x1.4cdbbp0, 0x1.826efp0, -0x1.229c22p0, -0x1.b2ea9cp-1, 0x1.0f1b4ap-2, 0x1.08569cp0, -0x1.cc6c94p-3, 0x1.a43e2cp0, -0x1.255214p-3, -0x1.99452cp-1, -0x1.d40566p0, 0x1.80b6cp0, -0x1.a51p-2, -0x1.93919cp0, 0x1.88150ep0, -0x1.e4b5b4p0, -0x1.4e9f06p0, -0x1.7c820cp0, -0x1.3895fep-4, 0x1.e844fp0, -0x1.270a5ep0, -0x1.b89926p-3, 0x1.29747ep-1, -0x1.b2b44ep-1, 0x1.4bdc24p0, -0x1.050718p0, 0x1.84bc6p0, 0x1.acdacp-1, -0x1.106c1ep-5, -0x1.ef4b1ap0, -0x1.429beap0, -0x1.c12fc6p0, 0x1.f77ad6p-3, 0x1.f20fp0, -0x1.19d57cp-1, 0x1.309e14p-1, 0x1.c3931ep-4, 0x1.f9a13cp0, -0x1.1286dap-1, 0x1.77eeaap0, -0x1.d1e00cp-1, 0x1.202e1cp-2, -0x1.075f86p0, -0x1.90d6fp-2, -0x1.3cea26p0, -0x1.f427d6p0, -0x1.5fba38p-2, -0x1.475404p0, 0x1.b37b12p-1, -0x1.874ca2p0, 0x1.3c11a2p0, -0x1.d0638p0, 0x1.a969e8p0, -0x1.2d0b82p0, -0x1.d9ed9cp0, 0x1.c4d7ecp-1, -0x1.07b122p-2, 0x1.27a10ap-2, -0x1.d384bep0, 0x1.b694dep0, -0x1.047b7p0, 0x1.fd12e2p-1, 0x1.bb1a22p0, -0x1.ae3074p0, -0x1.2af03p0, 0x1.80e3c8p-1, 0x1.4c2f58p-1, -0x1.d9261cp0, 0x1.f24f96p-2, -0x1.7c9f9ap0, 0x1.52b1f2p-1, -0x1.38ec72p0, -0x1.711a0ap-1, -0x1.13016ep-2, 0x1.bab62ap-3, 0x1.ae8484p-3, 0x1.a75dbep-2, 0x1.bd3dd8p0, 0x1.ebca9p0, 0x1.9dbfacp-1, -0x1.9a8c06p0, -0x1.e4c068p0, -0x1.d5f6ap-3, 0x1.2bd8bp0, 0x1.094838p0, -0x1.f5c314p0, 0x1.e4edacp-2, -0x1.25b1a8p-2, -0x1.b18dd4p0, 0x1.e5a4bap0, -0x1.6066dap-3, -0x1.21d06cp-5, 0x1.e9e07cp-4, 0x1.8a4168p0, -0x1.730d28p-1, 0x1.3149dcp-3, 0x1.7f6a2p-3, -0x1.ef9d82p-1, 0x1.a4517ep0, -0x1.d89d6p0, -0x1.fdc67ep0, -0x1.3e193ap-1, -0x1.2257f6p0, 0x1.78e58p-1, 0x1.10315p0, 0x1.6278fep0, -0x1.4e2956p-1, -0x1.e13926p0, -0x1.edbdc2p0, -0x1.4d0966p0, -0x1.7a072ep-1, -0x1.c71bcap-3, -0x1.c5fa4p0, -0x1.e54fc8p-1, -0x1.fe68c4p-2, -0x1.e585bep0, 0x1.82c2cep-1, -0x1.3f2bb2p-6, 0x1.8f464ep0, -0x1.4f42d2p-2, 0x1.392176p-4, 0x1.495366p0, 0x1.4ddf4ep-1, -0x1.85fa3p0, 0x1.9abc4p0, -0x1.846304p0, 0x1.1c1f56p-2, 0x1.1b0ea8p-5, -0x1.fc43e6p-3, -0x1.587016p-1, 0x1.b650bp-2, 0x1.333e32p-1, -0x1.be166ap0, -0x1.20a4aep0, 0x1.eb9a3cp-1, -0x1.f1b872p-4, 0x1.86880ep0, -0x1.bc2848p-1, 0x1.894548p-3, 0x1.9f046cp0, -0x1.68b3d8p0, 0x1.e5b936p0, 0x1.b75e4ap-4, -0x1.da271p-4, -0x1.083fcp-1, -0x1.fd3096p0, 0x1.a26572p0, 0x1.9929cap-1, 0x1.565edp-1, 0x1.49fe9ep-2, -0x1.96e88p-2, 0x1.c056aap0, -0x1.628974p0, 0x1.532444p0, -0x1.9fee9cp0, 0x1.02778ap-1, -0x1.3c420ap0, -0x1.8dc102p-2, 0x1.b8bb54p-2, -0x1.ef258ep0, -0x1.cebb8ap0, 0x1.eb96e6p0, 0x1.0d6246p-2, -0x1.9475a4p-1, -0x1.45fa1ap0, 0x1.60bffep0, 0x1.9ae0ap0, -0x1.6b352ap-1, 0x1.387bccp-1, 0x1.d282p0, -0x1.57db18p0, 0x1.29edc8p-1, -0x1.69711ap-2, -0x1.76211cp0, 0x1.5b9b74p-2, -0x1.4655e2p-1, 0x1.49641p0, -0x1.e1b6dap0, 0x1.3c8c2ap0, -0x1.d9ae6cp-2, 0x1.15e77p0, 0x1.ebfa9cp0, 0x1.a0de54p-1, -0x1.92f00ep0, -0x1.0b47f8p0, -0x1.3bfdcp-1, 0x1.d1c64ep0, -0x1.bd3946p-1, 0x1.d8570cp-3, 0x1.ec6d78p-2, 0x1.df343ep0, 0x1.2de886p-1, 0x1.8e3bdp-1, -0x1.8a9958p-1, -0x1.d524c2p0, -0x1.0f522p-1, 0x1.567148p-1, 0x1.35caccp-4, 0x1.d0edf4p0, 0x1.43bd58p0, 0x1.4cf82p-1, 0x1.175a98p0, -0x1.3a9d1p0, 0x1.a84daap0, 0x1.88449cp-1, -0x1.acc236p-1, -0x1.06f87p0, -0x1.3ccec4p0, 0x1.c490e6p0, -0x1.5eb22p0, 0x1.513464p-1, -0x1.888fc6p0, -0x1.064822p0, 0x1.6deb8p0, 0x1.45318ep-1, -0x1.907b2ep0, 0x1.25642p0, -0x1.6099cep-3, -0x1.fcfe56p-1, -0x1.15e452p0, 0x1.2d2becp0, 0x1.9183b8p0, 0x1.2f494p0, 0x1.6388d4p-1, 0x1.7228b8p0, 0x1.be0aa8p-1, -0x1.9a4c9cp0, -0x1.60f73p0, 0x1.2dc2c2p0, 0x1.8a0088p-1, -0x1.7e0a4ep0, 0x1.aaee06p-1, 0x1.6084f6p-1, 0x1.22a7b6p0, 0x1.8b88eep0, -0x1.e6f06ep0, 0x1.425996p-1, 0x1.06bb6p-2, 0x1.771fdap-3, -0x1.a809f6p-1, -0x1.9e9102p-1, -0x1.4758fcp0, 0x1.c90ae2p0, -0x1.e7c1fp-2, -0x1.ead6c2p-1, -0x1.239464p-2, -0x1.e89aacp0, -0x1.5105f6p-1, 0x1.aa7e6cp0, 0x1.dd32dap-1, 0x1.4b7a26p0, -0x1.c1fcfp0, 0x1.ad4206p0, -0x1.7a6936p0, 0x1.96689ep0, 0x1.429488p0, 0x1.9d026ep0, 0x1.14d4bcp0, 0x1.c06e1ap0, 0x1.ca8182p-9, 0x1.4142f6p-7, -0x1.45629ap-1, 0x1.d71c9ap-4, -0x1.1d3388p-1, -0x1.169228p0, -0x1.4edc5ap0, 0x1.9e1318p0, 0x1.5385dap-1, -0x1.cdfe54p-1, -0x1.fbbd88p-5, -0x1.fc3648p-3, 0x1.1ba37ap0, 0x1.425b8ep0, -0x1.43e64p0, 0x1.75d974p0, 0x1.ba5892p0, -0x1.78c204p-4, 0x1.34d886p0, 0x1.3553cap0, -0x1.6d5ec8p-1, 0x1.fa3238p0, 0x1.8f5a6p0, 0x1.14021ep0, 0x1.a11b68p-3, 0x1.542c8ap0, 0x1.b01d68p-1, -0x1.12dd92p-1, 0x1.467ec6p0, 0x1.31a444p-1, -0x1.58683p-2, -0x1.e22398p0, 0x1.4ab3c4p-4, 0x1.5a69e2p0, 0x1.c5a0ccp0, 0x1.18a4aep-1, -0x1.5622dap-8, 0x1.5ab56p0, -0x1.e7c6d4p-2, -0x1.0c25fap0, 0x1.db9a1cp-1, 0x1.73d55p0, -0x1.9243eap0, 0x1.17225ap0, 0x1.fc00b2p0, -0x1.e44c9p0, 0x1.a42df8p-2, -0x1.96621ap-2, -0x1.5a9c4p-2, -0x1.74b356p-1, 0x1.ce854ap-2, -0x1.c6769p-2, -0x1.ce16ap-3, -0x1.ef1e64p0, -0x1.aa58c6p-3, -0x1.c2348ap-3, -0x1.306662p0, -0x1.ffd7cep0, -0x1.e2efcp0, 0x1.5bda7p-1, 0x1.46c1ecp-1, -0x1.b3a76ap-2, 0x1.680ed4p0, 0x1.a0185p-1, 0x1.e5f0ap0, -0x1.eea2e6p0, -0x1.d694b2p-6, 0x1.5d3b08p-3, 0x1.ddf5fep-4, -0x1.4d914ep-1, 0x1.a3ec66p-2, -0x1.ecd028p-1, 0x1.ac690ep0, -0x1.52393ep0, 0x1.d301b6p-1, 0x1.cf809p0, 0x1.6cb2f4p0, -0x1.8e7f34p0, -0x1.58dd5p-3, -0x1.e72b5ep0, -0x1.a64992p-1, 0x1.dee8p0, -0x1.2663eep0, 0x1.7b382p0, -0x1.03c7e4p0, -0x1.63de8ep-2, -0x1.904beap0, -0x1.23e312p-5, -0x1.15ffaep0, 0x1.d7dae6p0, 0x1.b1ebc2p-2, -0x1.5f6bc4p0, -0x1.8eacd4p-3, 0x1.799804p0, -0x1.67bdacp0, -0x1.2d4c7ep-1, -0x1.bf029ap0, 0x1.a21ec6p0, -0x1.62890cp-1, 0x1.dcc9e8p-1, -0x1.c412a2p0, -0x1.b82c3ap0, -0x1.14ecap-3, -0x1.81870ap0, -0x1.ca4b12p-4, 0x1.e14ffp0, 0x1.9b092ep-4, 0x1.624c4ap0, -0x1.092388p-1, 0x1.34edp-2, -0x1.4497e6p0, -0x1.288a36p0, 0x1.522b06p0, -0x1.69aa9p0, 0x1.dcd9a6p0, 0x1.7bdae2p0, 0x1.bdf606p0, 0x1.5448ep-2, 0x1.0868fap-1, -0x1.27648cp-2, 0x1.3b51a6p0, 0x1.a4e0e2p0, 0x1.8ec29p0, 0x1.1fc0d2p-2, -0x1.b65f96p-4, -0x1.80eb3ap-1, 0x1.a2ef4ap-2, 0x1.d9feaep0, 0x1.9a7f86p0, 0x1.d90234p-1, -0x1.5a343cp0, -0x1.2349fap-1, -0x1.5bfabep0, 0x1.734e26p-2, 0x1.ae4e9p-2, 0x1.12509ep0, -0x1.7067cp0, 0x1.0c12a8p0, 0x1.675f92p-1, 0x1.e6ba16p-2, 0x1.900296p-1, -0x1.eb843ep-3, -0x1.71c28cp-2, -0x1.7ce51p0, 0x1.86afa8p-1, -0x1.417f9ap0, 0x1.b1e33ep0, -0x1.b508bep-2, 0x1.0def76p0, -0x1.397e78p-1, 0x1.3d407ap0, -0x1.ddf2fp0, 0x1.8b297p0, 0x1.93c5ecp0, -0x1.796374p0, -0x1.141caap-2, -0x1.8f850ap-2, 0x1.95ab06p0, 0x1.967d8ap-1, -0x1.057024p-1, 0x1.d1e602p-1, -0x1.a2198p-2, -0x1.c4fd84p0, 0x1.1a7092p-2, -0x1.532e7cp-3, -0x1.c066aep-2, -0x1.35129cp0, 0x1.3c6ab8p0, -0x1.28320ep-2, -0x1.77925ap-4, -0x1.8bae86p-3, 0x1.f172dcp-3, -0x1.e2da04p-1, -0x1.e6ccecp0, 0x1.2224cep-1, -0x1.bf6a9p-6, 0x1.9a1048p-2, -0x1.df74d4p-1, -0x1.b80dd6p0, 0x1.ea923p0, -0x1.ea98fcp-1, 0x1.e5f546p0, -0x1.4b117ap0, -0x1.a84ceap-1, -0x1.9e68ap-1, -0x1.63a638p-3, -0x1.872c9ap0, 0x1.09e864p-4, -0x1.5f5134p0, -0x1.203962p0, -0x1.d1e69ep0, 0x1.015c3p-2, -0x1.f2fd0ep-3, 0x1.4bf37p0, 0x1.91225ap-3, 0x1.76a32ap0, -0x1.1ed2b4p-1, -0x1.e71226p-1, 0x1.b6de2ep0, 0x1.179d2ep-2, -0x1.a26dfep-1, 0x1.e8c528p0, -0x1.daf07ep0, -0x1.548e24p-1, -0x1.5ae43ep-1, 0x1.0fe50ap-1, 0x1.456002p0, 0x1.3d3556p-3, -0x1.472a1ep0, -0x1.25b47cp-2, 0x1.afadfcp-1, -0x1.a6931ep-1, -0x1.9a5e82p-1, 0x1.07ac0ap0, -0x1.00b558p0, 0x1.7d364ap-5, -0x1.93d3bep-1, 0x1.c5e07cp0, -0x1.7b473ap0, 0x1.11b914p-1, -0x1.faac4p-1, 0x1.db5092p0, -0x1.5badd8p-1, 0x1.f79c28p0, -0x1.750f4cp0, -0x1.0cf58ap-2, 0x1.b7723cp0, -0x1.66d722p0, -0x1.2f6ba6p0, -0x1.57d264p-1, 0x1.456fb4p0, 0x1.7207e6p0, -0x1.6a64ccp-1, 0x1.c0255cp0, 0x1.9d23a6p-9, 0x1.27868ap-4, 0x1.3af33cp-2, -0x1.b1ed18p-2, 0x1.c4f59p0, -0x1.6f0e84p-1, 0x1.9bc1c2p0, 0x1.24ff32p-1, 0x1.73fb0ep-1, -0x1.a37684p0, 0x1.489a72p0, 0x1.fc255ep0, 0x1.5549ep-1, -0x1.7b0486p0, -0x1.6d7af4p0, -0x1.70d2dp0, 0x1.27f02cp0, -0x1.ba346ap0, 0x1.bbbf0cp-1, -0x1.046192p-2, 0x1.558d38p-2, 0x1.5a56e6p0, -0x1.8bad5cp0, -0x1.aacb26p0, 0x1.5205ecp0, -0x1.8be91cp-1, 0x1.ad79cp0, 0x1.266da4p0, -0x1.5c7182p-1, -0x1.21071cp0, 0x1.ba57b4p-1, -0x1.3d9f66p-3, -0x1.4f8918p-5, 0x1.239028p-1, -0x1.936caep-5, 0x1.a4485cp-1, -0x1.a05d96p-1, 0x1.4e797cp0, -0x1.f36f06p-2, -0x1.0977bap0, -0x1.75f464p0, -0x1.460626p0, -0x1.82d4acp-2, -0x1.2a0b54p0, -0x1.c4a436p0, 0x1.bb55b2p0, -0x1.87d396p0, -0x1.571988p-2, -0x1.9c25e8p0, 0x1.2da26ap0, 0x1.740ceep-1, 0x1.48893ep0, -0x1.562f5ep0, 0x1.963f82p-2, 0x1.d4aaf2p0, 0x1.b8c038p0, -0x1.e1e18p0, 0x1.757d38p0, 0x1.a1a7f6p-1, -0x1.5fe81cp-1, -0x1.c6d534p-1, 0x1.74ce4p-2, -0x1.1ee95p-2, -0x1.635212p0, 0x1.aac52ep0, 0x1.2ea032p0, 0x1.b61f0cp0, 0x1.ce02ccp0, 0x1.0c0798p-6, 0x1.952664p0, 0x1.a9164ep0, -0x1.26a0f6p-3, 0x1.b3b482p0, -0x1.edae5cp-1, -0x1.f2ba26p0, 0x1.70064p0, -0x1.cf70ecp-3, -0x1.16f358p0, 0x1.4b238ep0, -0x1.05ed1ep-1, -0x1.f940a6p0, 0x1.cacd2ap-6, -0x1.e935a6p-3, -0x1.23bdf6p-3, -0x1.615cdep0, -0x1.c1e6aap-1, -0x1.fa5ebap-2, 0x1.4e5c7ep-1, -0x1.b33cacp0, 0x1.5eac94p0, -0x1.d324ap-1, 0x1.6bccdcp-1, -0x1.135fe6p0, 0x1.a2800ep-1, 0x1.6258a6p0, -0x1.aa6e44p-1, -0x1.d9ed1cp-1, -0x1.8995ccp-3, -0x1.e60d02p-3, 0x1.919d58p0, -0x1.70386ep0, -0x1.85d1dep-3, -0x1.24c8dcp-1, -0x1.560ae2p-4, 0x1.896c6cp0, -0x1.73b98cp-1, 0x1.47046p0, -0x1.32f3e8p-1, 0x1.d4acc8p0, -0x1.e4f47ap-1, -0x1.52e30ep-3, 0x1.729d1p-2, -0x1.08f6bep-1, -0x1.be84acp-1, 0x1.64ce18p0, 0x1.16e32ap-1, 0x1.c66f1ep-1, -0x1.6de542p0, 0x1.963514p-2, -0x1.d37ae4p-4, 0x1.41aefp-4, -0x1.15b15ep0, -0x1.02bdc6p0, 0x1.595f9ap0, 0x1.82775cp0, 0x1.2ac98ep-5, 0x1.3cd744p0, -0x1.85bc2cp-1, 0x1.2f5bbp0, -0x1.60cb1ap0, -0x1.98ff9ap0, 0x1.b05a4p0, 0x1.975b2ep-3, -0x1.5d3d94p0, -0x1.2e03b4p-3, -0x1.d17a3cp0, 0x1.4bd7aap-2, 0x1.bb483cp0, -0x1.a982a8p-2, 0x1.a0505p-1, 0x1.35e2b2p0, 0x1.940bfp-1, -0x1.6bd63cp-2, -0x1.e5dadcp0, 0x1.025dbap-1, 0x1.705acap0, -0x1.f7d69ap0, 0x1.6f30a2p-4, 0x1.c46ca6p0, -0x1.75085cp-2, -0x1.2a9448p-1, -0x1.27b5a4p0, 0x1.aeae94p0, 0x1.0d1022p0, 0x1.aabf48p0, -0x1.5f84ep-3, -0x1.3d295ep0, 0x1.0746acp0, -0x1.5606dep0, -0x1.49498ep0, 0x1.38c176p-1, -0x1.0f151ep-1, -0x1.d8274ep-3, 0x1.8e7574p-2, 0x1.7e7606p-1, -0x1.717f14p-2, 0x1.d1fd9ep-1, 0x1.633854p0, 0x1.92fbfp0, -0x1.d7cbb6p0, 0x1.ebbf9ap0, -0x1.3b3e54p0, 0x1.efff12p0, -0x1.de0a3ep-2, -0x1.f07958p-2, 0x1.80112p0, 0x1.b4a32cp-4, 0x1.0eebaep0, -0x1.228ffep0, 0x1.9e2168p-3, -0x1.3f65acp0, -0x1.e50b68p0, -0x1.3614ap-2, -0x1.440348p-2, 0x1.1de7a8p0, -0x1.69182cp0, -0x1.0b3f8ap-3, 0x1.9e6142p-2, -0x1.23bb68p-1, -0x1.0410acp-1, -0x1.4d9432p0, 0x1.58dad2p-3, -0x1.eafaaap0, 0x1.3d643ep0, -0x1.e5d956p-4, 0x1.5c880ap0, -0x1.7d4d46p-3, -0x1.4ad184p-2, 0x1.f1068cp-1, -0x1.24726p0, 0x1.f1ca7cp-2, -0x1.b4c198p-1, -0x1.d70716p-10, 0x1.7ccafcp-1, -0x1.ef719p-4, 0x1.6f5a6ap-3, 0x1.63db24p-1, -0x1.9dcc04p-1, 0x1.9c9742p0, -0x1.4beeeep-1, 0x1.2da9a8p-1, 0x1.5911e8p0, 0x1.7ee09ap0, 0x1.860d6cp0, 0x1.aa87ccp-2, -0x1.05098ep0, -0x1.75fe0ap-2, -0x1.5bcb98p-1, 0x1.2f698p0, 0x1.2554fep-2, -0x1.5248aap0, -0x1.70a8a4p0, -0x1.1657e2p-2, 0x1.3d63dp0, 0x1.cfc78cp0, 0x1.4e402ep0, 0x1.511968p0, 0x1.1e9a94p-4, -0x1.289c6p-2, 0x1.1a365p0, 0x1.574012p-3, -0x1.88e52ep0, 0x1.c93638p-4, -0x1.4944eap-4, -0x1.d74302p-1, 0x1.4a2a92p0, -0x1.34c826p-5, 0x1.b7f39ep0, 0x1.d2f4dcp0, 0x1.b77a66p-3, 0x1.6491dep0, -0x1.cb35fap-1, -0x1.cc0688p0, 0x1.79ba74p-1, -0x1.609cbcp-2, -0x1.4ee01p0, -0x1.17ad26p-2, -0x1.dd9dfep-1, 0x1.810256p-1, -0x1.4adf96p0, -0x1.51b554p-1, -0x1.1b394ep0, -0x1.05163ep0, 0x1.36575p-1, -0x1.e97f98p-1, -0x1.f420a8p0, -0x1.2d17f8p0, 0x1.b7e2bep0, -0x1.820aeap-1, -0x1.d4faeep-2, 0x1.d18896p-3, -0x1.46e982p0, 0x1.e2ce52p0, -0x1.438826p-2, -0x1.b7f94ep-3, -0x1.09f0f4p0, 0x1.82153cp-3, 0x1.e999bap-1, -0x1.3d7d5ap0, -0x1.2b7f64p0, 0x1.688cdcp-1, -0x1.6f951p0, -0x1.09acc2p0, 0x1.b97e84p0, 0x1.18d04p-1, 0x1.34888ap-2, 0x1.95a1a4p-2, -0x1.87bf2ep0, 0x1.f49deep0, -0x1.0315aap-1, -0x1.42b5c4p0, -0x1.4d5f78p0, 0x1.abfb4cp-1, -0x1.30428p-2, 0x1.cee1e6p-3, -0x1.ab54ecp-1, 0x1.184528p0, -0x1.2a9c4p0, -0x1.33e36ap0, 0x1.347df2p0, 0x1.1f2e1cp0, 0x1.6f25c6p0, 0x1.2d3964p0, -0x1.c9f1fep-3, -0x1.6061bap-1, -0x1.0e6f26p-6, -0x1.4f298p-2, 0x1.378b4cp0, -0x1.eeb102p0, -0x1.6f6804p0, -0x1.709426p0, 0x1.3e4baep-1, -0x1.959e8ap0, -0x1.e415d6p0, 0x1.3db676p-5, -0x1.049df2p0, 0x1.b1d9e8p-1, -0x1.6f54fep0, 0x1.a440dap-1, -0x1.8497ap-5, -0x1.9b6818p-3, -0x1.a8312p0, -0x1.0543fep0, 0x1.4cf116p0, -0x1.73d4dep-1, -0x1.a513a2p0, 0x1.e626a4p-1, -0x1.0adc8ep0, -0x1.b793d6p-2, 0x1.ab961ep-1, -0x1.0d3a2cp0, 0x1.df13fap-1, -0x1.b8343ep-2, 0x1.690204p-4, -0x1.291c68p0, -0x1.4a2032p0, 0x1.b3bb64p0, 0x1.3d2d9p-5, -0x1.d0915cp0, 0x1.cf733cp0, 0x1.a7cbeep-2, 0x1.331fep0, 0x1.fc044p0, 0x1.6e522p-1, -0x1.ae596ep0, -0x1.8d212cp0, -0x1.4ad3d2p0, 0x1.d8f762p0, 0x1.a63f6ap0, -0x1.9d407ap-2, 0x1.10bed6p0, -0x1.63c83p0, -0x1.9a3728p0, 0x1.d2384ap-2, 0x1.a7a07p-4, -0x1.9cf9ecp-2, 0x1.0e7976p-1, -0x1.71c7d4p-3, -0x1.b2e73ap0, -0x1.e8317ep0, -0x1.6f0dbap-5, 0x1.4adbdep-2, 0x1.cd227ap-4, 0x1.a16072p-3, -0x1.2caaccp-5, 0x1.532b5p-1, 0x1.ce4558p-3, 0x1.4ec50ep-1, -0x1.b4568ap0, -0x1.bc1d2ap-2, 0x1.16a90cp-1, -0x1.9afdfp0, -0x1.4327c6p0, -0x1.b3ca9cp-1, -0x1.278c2p0, 0x1.7e4e34p0, -0x1.2001aap-7, 0x1.56887ep-2, 0x1.db8d64p0, -0x1.63257p-2, 0x1.b7df04p0, 0x1.c66a18p0, -0x1.1afb58p0, -0x1.7150eap-2, -0x1.4331e8p-2, -0x1.4cd1acp-2, -0x1.a0aa5ap0, 0x1.c2c22ap0, 0x1.12c186p-2, 0x1.44ab92p-1, 0x1.052728p-1, 0x1.416fd6p0, -0x1.9bbee4p-1, 0x1.be0b8ep-1, 0x1.6a649ep-3, -0x1.b15d9ap0, 0x1.bc74ep-1, -0x1.5e6952p-1, 0x1.f2250cp0, -0x1.d973d4p0, 0x1.a2beaep0, 0x1.d368e4p0, -0x1.f35bd6p-1, 0x1.c0b044p0, 0x1.529324p0, -0x1.87a07cp0, 0x1.413232p0, 0x1.27f238p-3, 0x1.3d51fap-3, -0x1.39620ap-2, -0x1.9704f8p0, 0x1.613f04p-1, 0x1.8da7a4p0, -0x1.315e2ep0, -0x1.ec37aep0, -0x1.286ddep0, 0x1.47f9f4p0, -0x1.de098ep0, -0x1.f5116ap-1, 0x1.4c2886p-2, 0x1.d96a38p0, 0x1.716e66p-5, -0x1.b2b5f2p-1, -0x1.84b156p0, 0x1.406c6ep0, 0x1.b2453p0, -0x1.58aedp-1, -0x1.8f9db6p0, -0x1.0b6bd6p-1, 0x1.262efep0 };
l_struct_OC_k2c_tensor test2_dense_input_input __ATTRIBUTE_WEAK__;
float test8_dense_input_input_array[2622] = { 0x1.1b14fap0, 0x1.fb0146p0, -0x1.5b1922p-1, 0x1.ed50b2p-2, 0x1.e2353ep-1, 0x1.a8655ap0, 0x1.c41e9ep0, 0x1.315312p0, 0x1.6ce996p-2, 0x1.56d2bp-2, 0x1.0dcaaep-1, -0x1.ed2dd6p-1, 0x1.8383bp0, 0x1.47774cp-1, -0x1.8a84b4p-2, 0x1.51b2eap-2, -0x1.e9e0d6p0, 0x1.03833p-1, -0x1.0d3162p-2, 0x1.53c30ep0, -0x1.124cf8p0, -0x1.8c1934p-1, 0x1.0038fcp0, 0x1.08e948p-2, 0x1.e225dap0, 0x1.af5dfap0, 0x1.2363dp0, -0x1.eabb4cp0, 0x1.6f55p0, -0x1.10112cp0, -0x1.39ffp0, 0x1.9e29dp0, -0x1.f1c72p0, 0x1.30ea6ap-3, 0x1.5bebfp0, 0x1.90af56p-2, 0x1.e85172p-1, 0x1.8507a8p0, -0x1.a8bcb6p-2, -0x1.5099bcp0, -0x1.4e3058p-2, 0x1.0b8e32p0, -0x1.1854acp0, 0x1.39e8e6p0, -0x1.b9eb06p-1, 0x1.a67ae4p-3, 0x1.80025p0, -0x1.7a0d6ep-4, -0x1.c59ea6p-2, -0x1.7c2c66p-1, 0x1.8efd2ep-1, 0x1.f2f25p0, -0x1.fa4bdcp0, -0x1.b5627ep-1, -0x1.ad288p-2, -0x1.03bf72p-3, -0x1.ec212ap0, -0x1.b26864p0, 0x1.1148eep-2, -0x1.541aeep-1, -0x1.8e06cp-1, -0x1.415bb6p-3, 0x1.ee947cp0, 0x1.14e926p-5, -0x1.b15e3ap0, 0x1.458f54p0, -0x1.75f18p-1, 0x1.6a993p-1, 0x1.70fd66p-1, -0x1.a792aap0, 0x1.9ca598p-2, 0x1.a3e1b2p-3, 0x1.e769b4p0, 0x1.869df8p-1, -0x1.55cdep0, 0x1.1219aep0, -0x1.4d3cb2p-3, -0x1.45c1cap-4, 0x1.e7349cp0, -0x1.d8d198p0, 0x1.76ffbap-2, -0x1.b4edb6p-1, -0x1.7fb51ap-1, -0x1.2e2032p-2, -0x1.29030ap-1, -0x1.ffba1ap0, -0x1.4fd5e2p-3, 0x1.0de702p0, -0x1.6578cp-1, 0x1.9b313cp0, -0x1.e1ab5p-1, -0x1.6d2f12p-1, -0x1.09b186p-2, -0x1.78a54cp-1, 0x1.a168cp-2, 0x1.2a70d2p0, 0x1.f46126p0, 0x1.11a70ap0, -0x1.3841e4p-1, 0x1.011324p0, -0x1.a3e508p-1, 0x1.b6985p0, 0x1.6ea128p0, -0x1.e4757cp-9, 0x1.66fdf4p0, 0x1.d0e53cp0, -0x1.e52176p0, -0x1.599226p-1, -0x1.df35e2p0, 0x1.d540c4p0, -0x1.d5fd48p-2, 0x1.438e7ep0, -0x1.46c202p-2, -0x1.2b08aep-2, -0x1.2ec9d2p-1, 0x1.4a00e8p0, 0x1.b46534p-1, -0x1.c6b336p0, 0x1.3d9f22p-1, 0x1.10a992p-3, -0x1.ca57e2p-2, 0x1.744b98p-1, -0x1.3a1cfp-1, -0x1.a1be6cp-1, 0x1.e9767ep0, 0x1.1ed354p0, -0x1.000942p-2, -0x1.2a9cc4p-1, 0x1.c4c9e4p0, 0x1.03db04p0, 0x1.b0a36p0, 0x1.f9b712p-1, -0x1.7ba1a4p0, -0x1.e27c92p0, -0x1.3bd6b2p0, -0x1.32aaccp-1, -0x1.9ac3cap0, 0x1.39e84ap-2, -0x1.c6519p-1, -0x1.7be19p0, -0x1.dc28fcp-3, 0x1.d3efc8p-1, 0x1.d08ec4p-1, -0x1.306ab2p0, -0x1.be763cp0, 0x1.10cd18p-2, -0x1.360e44p0, -0x1.c682b2p0, 0x1.063508p0, -0x1.656c1p0, -0x1.0e69f4p0, 0x1.a4a5bcp0, -0x1.4e7292p0, -0x1.5a9156p0, -0x1.9e561p0, 0x1.b71b3cp-1, 0x1.08f756p0, -0x1.ea082ap0, -0x1.f9238p-1, -0x1.cb206ap-3, -0x1.f2b418p0, 0x1.e232b6p-2, -0x1.3b2f3ep0, -0x1.65672cp-1, -0x1.49dc7ep0, 0x1.72ef06p-4, 0x1.72bfcp0, -0x1.40633ap-1, 0x1.490f8ap0, -0x1.9087a8p0, -0x1.478332p0, -0x1.8161c8p0, -0x1.b270f8p0, -0x1.1387aep0, -0x1.6b1b88p0, -0x1.a4b3acp-2, -0x1.01f1dp0, -0x1.345f82p-1, 0x1.cb4088p-1, 0x1.31b5c2p-1, 0x1.d8f52p0, 0x1.ccb968p0, 0x1.4b66ap0, -0x1.d5d704p-1, -0x1.63c54ap0, 0x1.fe072ep-1, 0x1.5f6fap0, 0x1.d20c0cp-1, 0x1.bd4cc2p0, 0x1.d01cdep-3, -0x1.8c2b9ap-1, 0x1.912f38p-2, 0x1.1a5424p0, 0x1.f4b882p0, -0x1.a5caa8p-2, 0x1.730ef8p0, -0x1.f7f08ep0, -0x1.2e0a2p-2, 0x1.411d9ep-2, -0x1.24f0a2p0, -0x1.7eb8b4p-4, -0x1.8f6b3cp-2, 0x1.a04798p0, -0x1.cbe89ap-2, -0x1.4acadp0, 0x1.b6d84ap0, -0x1.90a4b4p-1, 0x1.434bacp0, 0x1.fa0ecp-4, -0x1.af629cp-1, -0x1.768766p-3, -0x1.7c408ep-5, -0x1.015e9ap0, 0x1.3d38fep0, 0x1.9c046p-1, 0x1.c26504p0, -0x1.f63d5cp0, 0x1.490296p0, -0x1.593becp0, -0x1.3f26b4p-1, -0x1.7190f2p-3, 0x1.84a0e4p0, 0x1.837a4ap0, 0x1.6e6368p0, 0x1.28b00ap-1, -0x1.fc3982p0, 0x1.71fea6p0, -0x1.83af32p0, -0x1.ca6172p0, -0x1.868f42p0, 0x1.ef7de2p0, 0x1.7043fcp0, 0x1.ecf6cep-3, 0x1.1807d8p-2, 0x1.41941ap-1, -0x1.209022p-4, 0x1.1c6048p0, 0x1.206378p0, -0x1.f2bbcap0, 0x1.74dc52p0, 0x1.bd26a8p-1, 0x1.af3e08p-3, 0x1.3ccb3ep-2, 0x1.0f7568p-8, 0x1.d4998p0, -0x1.73396p-4, -0x1.489edcp-3, -0x1.a425acp-3, 0x1.008362p-1, 0x1.198372p0, -0x1.7a2acp0, 0x1.0492fap-1, 0x1.11e20cp-2, 0x1.c350a6p0, -0x1.b5d262p-1, -0x1.9084d2p0, 0x1.150b1cp-1, 0x1.f7aa94p0, 0x1.61adbp-2, 0x1.e049a4p-1, -0x1.54b9e6p0, 0x1.b3ab8ep-2, 0x1.8cad94p0, 0x1.8ed75p0, 0x1.19a48p0, 0x1.eee95p0, -0x1.e56416p0, -0x1.295968p-3, -0x1.895094p0, 0x1.06f5e2p-1, -0x1.020d0ep-2, 0x1.1fb4cep-3, 0x1.298ccp-3, 0x1.8ddb4ap0, -0x1.e2b24ep0, 0x1.9e146p0, 0x1.4313bp-1, 0x1.d29a5ep0, -0x1.cda86p0, -0x1.a1056cp-1, -0x1.e97fe2p-1, 0x1.c3bcf4p0, -0x1.b5efd6p-2, -0x1.9eb02ep0, -0x1.e389e2p-1, -0x1.fca2f6p-2, 0x1.40644cp0, -0x1.772b8p-1, 0x1.739396p0, 0x1.59c886p-1, -0x1.026444p-2, 0x1.35ee32p0, -0x1.91c516p0, -0x1.f3fbdep0, -0x1.dd595ap0, -0x1.492342p-2, -0x1.c283bcp-5, 0x1.f7344ep-2, 0x1.baf7a2p0, -0x1.7b021ap-2, -0x1.c45d62p-1, -0x1.6b30dcp-3, 0x1.cc0756p-1, -0x1.459d2ep0, -0x1.26949ap-2, 0x1.68dbf8p-1, 0x1.13a5cp-1, -0x1.b7a4dp-2, 0x1.03ec86p0, 0x1.aa04f6p-1, 0x1.f61daap-3, 0x1.5a282cp0, 0x1.4ba496p-1, -0x1.d63bfp0, 0x1.4f4e0ep0, -0x1.577d14p0, 0x1.812fd6p-1, -0x1.d91dep0, -0x1.8cfa0cp0, 0x1.269022p0, 0x1.c87278p0, -0x1.3cde76p0, -0x1.0d381cp0, 0x1.55edp-2, 0x1.b0e9c6p-2, 0x1.9ea806p-3, -0x1.024e78p-2, 0x1.7e5476p0, -0x1.f549bcp0, 0x1.655556p-3, -0x1.a8456ep0, 0x1.40a386p-4, -0x1.c6cbf2p-1, -0x1.802b2ep0, -0x1.657544p0, -0x1.d7fb46p0, 0x1.98cf1ep0, -0x1.083c5p0, -0x1.16cb24p0, 0x1.c4ec2cp-2, 0x1.41d606p0, 0x1.a48a62p0, -0x1.09666ap0, -0x1.d17a9ep0, 0x1.862ae2p0, -0x1.f37f22p0, -0x1.e1466ep-1, 0x1.4cc71ep-2, 0x1.3d4164p0, 0x1.df33f2p0, -0x1.588b22p0, 0x1.63e718p0, 0x1.1b733ep0, 0x1.32865p0, 0x1.f85a86p0, 0x1.50cc9p0, -0x1.73c0d8p0, 0x1.3b188p0, -0x1.a69a06p0, -0x1.a144d2p-2, 0x1.80fc8cp-9, -0x1.e6aa36p0, -0x1.cb287p0, 0x1.787c4cp-1, -0x1.2efe5p-1, -0x1.16cbp-3, 0x1.c9c7cp-2, -0x1.81a86cp0, -0x1.f96b0ap-1, -0x1.67d508p0, 0x1.31c282p-2, -0x1.46ea04p-1, -0x1.341f62p0, -0x1.c126dp-1, -0x1.da63b6p-1, -0x1.342b94p-3, -0x1.55cc7p-1, 0x1.149f44p0, 0x1.525066p-1, -0x1.5a6e14p-2, 0x1.e62404p-1, -0x1.f3c21ap0, -0x1.552308p0, -0x1.883b6ep0, 0x1.b39b88p-1, -0x1.8f029ap0, 0x1.c0871cp0, -0x1.18815p-1, 0x1.973a86p0, -0x1.b52c2ep0, 0x1.e1b2b4p0, 0x1.7c96ccp0, -0x1.b8ea98p0, 0x1.83e8eep0, 0x1.14ac0ep-5, -0x1.02a5cap-4, 0x1.94550ap-2, -0x1.c536bp-2, -0x1.9b4fcp0, 0x1.de967ep-1, 0x1.5cf618p0, 0x1.1ddb5ep0, -0x1.21699cp-2, -0x1.cc887ep-1, -0x1.c38a2ep0, -0x1.5c3136p-1, 0x1.b479d2p-1, -0x1.3b54fcp0, 0x1.d30dcap0, -0x1.cbc2e8p-2, 0x1.74a6eep0, 0x1.d80a78p-1, 0x1.e62cd4p-3, 0x1.7f12c2p-1, -0x1.0c8fb6p-1, 0x1.b6b118p-2, 0x1.c1bdf2p-4, 0x1.066752p0, 0x1.596d88p-2, -0x1.4a5678p0, -0x1.d12d64p0, -0x1.9031cep-2, -0x1.4d9f64p-5, 0x1.966262p0, -0x1.79a07cp-1, -0x1.3d47e8p-3, 0x1.8c363p0, 0x1.df2436p-3, 0x1.56fea4p-2, 0x1.55cff6p0, 0x1.e74184p-2, 0x1.a8ea18p-4, -0x1.cb0b42p0, -0x1.0126e6p0, 0x1.60dee8p0, 0x1.89bd7ap-2, -0x1.bccbdcp-2, -0x1.686804p0, -0x1.56b39ap0, -0x1.4d550ep-2, 0x1.1a931ap-2, 0x1.876ff4p0, 0x1.7eb726p0, -0x1.c850d4p0, 0x1.7cb478p-2, 0x1.e97694p0, 0x1.619078p-2, 0x1.3f11ecp0, -0x1.ab651p-5, -0x1.fb576cp-1, -0x1.9c95fcp0, -0x1.74cd88p-2, 0x1.544242p0, -0x1.461d9ep-3, -0x1.9ad074p0, -0x1.c51d96p-1, 0x1.20eaacp0, -0x1.c9fb58p-2, -0x1.9972dp0, -0x1.486132p0, 0x1.c7050cp0, -0x1.3941f2p-2, -0x1.3136bep-2, 0x1.26033cp-1, 0x1.038008p0, -0x1.acf7c4p0, -0x1.13bcp0, 0x1.57d9fp0, 0x1.0bb21p-2, -0x1.675014p0, 0x1.123aap0, -0x1.bfdfcp0, 0x1.c7615cp-3, 0x1.f0e786p-1, -0x1.64ef2p0, 0x1.2f3568p0, 0x1.ec01f4p0, 0x1.c6ce46p0, 0x1.8f1d2ep0, 0x1.e38d2p-3, -0x1.9234c4p-1, -0x1.9c921p-1, 0x1.8edebcp-2, -0x1.0f4c4ap0, 0x1.b31cecp-4, 0x1.90c69cp0, 0x1.faf22ep0, -0x1.94df28p-1, 0x1.19a4a8p-1, -0x1.cd9b9ep0, 0x1.3cdd86p0, -0x1.8560bcp0, 0x1.3aacaap-1, 0x1.bee1ap0, 0x1.41cb42p-1, -0x1.46319ap0, -0x1.6fd5c2p-1, 0x1.2c4268p-1, -0x1.1012bep-1, -0x1.b6b14ep0, 0x1.44d2a8p0, 0x1.80d5cap0, 0x1.692c8p0, -0x1.7698e2p-4, -0x1.6e8afep0, -0x1.ff5cf8p-2, 0x1.f2c5d8p-2, 0x1.3f101ep0, 0x1.68472p0, 0x1.7238e2p0, -0x1.b568cp0, 0x1.de00bap-1, -0x1.293a1p-2, 0x1.2b5a74p0, -0x1.65c3fcp-1, -0x1.01179cp0, -0x1.7bb7fap0, -0x1.e6eed8p-1, 0x1.4a8132p-3, -0x1.c05b6p-4, -0x1.385a3cp0, 0x1.329bfap0, 0x1.6ffd7cp0, 0x1.dbc3cep-1, -0x1.049e5ep0, 0x1.09f16p0, -0x1.942ba4p0, 0x1.cfe5c4p-1, 0x1.35a25cp0, -0x1.0660ecp-2, 0x1.91e33ep-1, 0x1.0fdf56p0, 0x1.171b1cp0, 0x1.1eeec4p0, -0x1.038d92p-1, -0x1.dc5c76p0, -0x1.208068p0, -0x1.a39c9cp0, 0x1.e69208p0, -0x1.cb7eep-1, -0x1.7a9996p0, -0x1.72de4ap-7, -0x1.274a94p-3, 0x1.6039c2p0, -0x1.45ec22p0, -0x1.9d527cp-4, -0x1.976a2p0, 0x1.b0ad2ep0, 0x1.365b44p0, -0x1.2e2b2p-2, 0x1.8f6b76p-1, -0x1.a93296p-3, -0x1.bfd8f4p-4, -0x1.bb0b4ap-2, 0x1.21dd88p0, -0x1.cba84ep0, 0x1.83303p0, 0x1.25e88ep-1, 0x1.e5dadcp0, -0x1.a47f16p-1, 0x1.379054p-1, 0x1.948bd6p0, 0x1.cc7026p-2, -0x1.3a0dbep0, -0x1.8de2e4p-3, -0x1.6f9964p-3, -0x1.f0a654p-4, 0x1.842f92p-3, -0x1.bc2216p0, -0x1.87979ep0, -0x1.b3d2fap-1, -0x1.2bfbbap-3, -0x1.3e2dfap-1, 0x1.67c7b4p-2, -0x1.c5aa16p-3, -0x1.cc8ab8p-2, 0x1.4e8f4ap-1, 0x1.2af5a2p0, -0x1.e175bap0, 0x1.1620bap-3, -0x1.557afcp0, 0x1.466954p0, -0x1.6eb58ep-1, -0x1.26f768p-1, -0x1.5baa92p0, 0x1.2e7562p-1, 0x1.2a2f22p0, 0x1.a24a7p0, 0x1.8fb03p0, 0x1.a1bf0cp-1, -0x1.2c8e8ep-1, 0x1.ecb38p-3, 0x1.cb481ap-2, -0x1.da242ap-1, 0x1.283746p0, 0x1.c31ebcp0, 0x1.c4dec2p0, 0x1.675f12p0, -0x1.9dc8f2p-1, 0x1.2331b8p0, -0x1.508c86p-1, -0x1.6ec73ap0, -0x1.84edb4p-1, -0x1.a977fp0, 0x1.78b5bep0, -0x1.a6697p-2, -0x1.3b0a08p-1, -0x1.576d3ep0, -0x1.3da838p-1, -0x1.e0b1dcp0, 0x1.10419p0, 0x1.5bc9e8p-2, 0x1.601d3p-3, 0x1.81a8ccp-1, 0x1.8c6dfcp0, -0x1.26495p-2, 0x1.64c44ap0, -0x1.f68cecp0, 0x1.c17fcap0, 0x1.63198p0, -0x1.a560d2p-2, -0x1.f9605cp0, -0x1.cea89cp0, 0x1.a00b6p0, 0x1.6d2b0cp-4, 0x1.ce07fep-4, 0x1.2e5d7p0, -0x1.bf233p-1, 0x1.140a66p0, -0x1.33256p-1, -0x1.e39aeap-2, -0x1.768924p-1, -0x1.96c9e6p0, -0x1.c3729p0, -0x1.4ee146p-1, -0x1.381766p-6, 0x1.56d554p0, -0x1.a01244p-1, -0x1.e82a1ep0, -0x1.97066cp-1, -0x1.47dc34p-1, -0x1.81561ep-1, 0x1.25fba4p-2, 0x1.e0246p0, -0x1.ed9da6p0, 0x1.48724p-3, -0x1.603b0ap-1, 0x1.dff77ap0, -0x1.822826p-1, 0x1.86a004p-4, -0x1.7d5c6ep-1, -0x1.481e46p0, -0x1.af4632p-1, 0x1.f15254p-1, -0x1.ec162ap-2, 0x1.4dcf94p-1, -0x1.cf669cp0, 0x1.8308a6p-4, 0x1.7fdc16p0, 0x1.96f21p-1, -0x1.de36eap-1, 0x1.5ff3a6p0, -0x1.8be7b6p0, 0x1.b47f0ap0, -0x1.da7f58p-3, 0x1.1b5408p0, -0x1.39f46cp-2, 0x1.e9774cp0, -0x1.bf9d6cp0, -0x1.2bd2cep0, 0x1.4e0f74p0, -0x1.38b71cp0, 0x1.449ff6p-2, 0x1.dd3ec8p0, 0x1.4bccdep-6, 0x1.e926ccp-8, -0x1.00cbd6p-3, -0x1.58d7c4p0, 0x1.d3ed18p0, 0x1.a09cfcp0, -0x1.461e36p0, -0x1.849312p-2, 0x1.c158f8p-1, -0x1.c38676p-2, -0x1.fcf7cep-3, -0x1.9011e2p-1, 0x1.0f8faap-2, 0x1.6aea98p-3, 0x1.019be6p-2, 0x1.39e23cp-1, 0x1.799a5ap-2, 0x1.2193bp-2, 0x1.3623b2p-2, -0x1.dfe656p-3, -0x1.1865bcp0, 0x1.8fbe9cp0, 0x1.013d88p-3, -0x1.f7b17cp0, -0x1.bdda8ep0, 0x1.a894e2p-1, 0x1.a63b1cp0, 0x1.ab383cp0, -0x1.23fb82p-1, -0x1.1e4044p0, 0x1.781d3ep0, -0x1.d0a8dep-1, -0x1.691f2cp0, -0x1.ade7dcp0, 0x1.a39c8p0, -0x1.b27956p-1, -0x1.f41342p-2, -0x1.961b68p0, -0x1.896bp-1, -0x1.2747ap0, -0x1.f72cbap0, 0x1.9dfbecp-13, 0x1.99674ep-1, 0x1.4e9538p-2, -0x1.f4afc4p-2, -0x1.83b06ep0, -0x1.7c5632p0, -0x1.49ba02p0, 0x1.b97f3ap0, 0x1.b67382p0, 0x1.758f3ep0, -0x1.2e4c12p0, -0x1.1a2a04p-1, -0x1.3ad732p-1, 0x1.885d7p-4, -0x1.a9716cp-3, -0x1.e79034p0, -0x1.3c10ep-3, -0x1.50e61cp0, -0x1.d1372ep0, -0x1.8cad88p-1, 0x1.98a3dp-1, -0x1.5ad478p-3, 0x1.fd4328p0, -0x1.c6eb14p0, 0x1.3e5406p-1, 0x1.040a18p0, -0x1.6bb82ep0, -0x1.686ce8p0, -0x1.061a8cp-3, -0x1.41e866p0, -0x1.3ced26p0, 0x1.2b2716p-1, 0x1.59f3dcp0, 0x1.ab3a52p0, 0x1.ec1ca8p-2, -0x1.da26dep0, -0x1.601c92p-1, 0x1.aa18eep0, 0x1.e92a06p0, -0x1.3f8864p-1, -0x1.8e3cb4p0, 0x1.973e72p-3, 0x1.3e43b2p-1, -0x1.6192acp0, -0x1.996a8p-1, -0x1.dc3ae2p-1, -0x1.01da2cp0, 0x1.0754f6p-3, -0x1.89e284p-2, -0x1.3010acp-1, 0x1.5d8beap0, 0x1.d88198p-4, -0x1.e33098p0, -0x1.df369ap-1, -0x1.5aed02p0, 0x1.f386bep0, 0x1.53349p-1, -0x1.9a790ap-1, 0x1.b17792p0, -0x1.f3ceeep-1, 0x1.299c1p0, -0x1.9bc874p0, -0x1.0d368ap0, -0x1.1640ccp-1, 0x1.3caa4p0, -0x1.78c252p0, -0x1.401a64p0, 0x1.f4b1a2p0, -0x1.3762ap0, -0x1.176dcep-2, 0x1.7f8dc2p0, 0x1.8b1d8cp0, -0x1.aa4d8ap0, 0x1.c3cce4p-1, 0x1.629dacp0, 0x1.d2728p-1, -0x1.424356p-1, 0x1.c48e12p-1, 0x1.29b02ap0, -0x1.25d3b8p-3, 0x1.de51b6p-1, -0x1.bed5cp-1, 0x1.23dc22p0, -0x1.487b6cp-1, 0x1.b8ce16p-1, 0x1.309398p0, 0x1.0f1ccap-1, 0x1.6e5322p0, 0x1.35ba2ap-2, -0x1.0fbe24p-4, 0x1.5ea134p-2, -0x1.8b0d1p0, -0x1.ecd14cp0, -0x1.22f7ap-2, -0x1.7e9514p-2, -0x1.fbd9e2p-3, 0x1.7d9eaap0, 0x1.38553ep-2, -0x1.674b44p-2, 0x1.6c56acp0, -0x1.237666p0, 0x1.91adf4p0, -0x1.6bdcd4p-1, -0x1.8f302cp-10, 0x1.b4a1bep-8, 0x1.512432p0, -0x1.2da8dp0, 0x1.79541ep-1, -0x1.47d1fp-1, 0x1.13de14p-1, 0x1.85de34p-2, 0x1.ba53c2p0, 0x1.8f5f22p0, 0x1.c40afep-1, 0x1.f9a4cp0, -0x1.350e6ep-1, 0x1.7c37acp-1, -0x1.6f7a24p-2, -0x1.026c88p0, -0x1.ae21f2p-3, 0x1.502404p0, -0x1.c1cf82p0, 0x1.796718p0, 0x1.bbfd1p0, 0x1.b3bc64p0, -0x1.3032b6p0, 0x1.bb5184p-1, -0x1.6c94dcp-1, 0x1.20eccep-1, -0x1.164796p-2, 0x1.423272p0, -0x1.4a34bcp-5, 0x1.75a83p-3, -0x1.5d36d4p0, 0x1.59bd7ep0, 0x1.210b48p0, -0x1.877f18p0, 0x1.ec04a6p-1, -0x1.be3534p0, -0x1.78f48ap-1, -0x1.f6f5ccp0, -0x1.5495dcp0, -0x1.4860fcp-1, 0x1.23965ep0, -0x1.b2c1e2p-1, -0x1.15483cp-2, -0x1.588ccp0, -0x1.0cabcp-3, -0x1.10d378p-2, -0x1.816b5ap-2, 0x1.d6cfb4p-2, 0x1.481988p-4, -0x1.18442ep0, -0x1.21acf8p-1, 0x1.717ac4p-5, 0x1.508bd8p0, 0x1.ac13eap-1, 0x1.ed1fb8p0, -0x1.2dccb4p0, -0x1.1b746cp-1, 0x1.f87362p0, -0x1.383ebp-1, -0x1.f58fc2p0, -0x1.3801e4p-1, 0x1.8a6162p0, -0x1.66f68p-2, 0x1.f81c6cp-2, -0x1.fa2f2cp-1, -0x1.265834p-1, -0x1.5c0974p0, -0x1.6c231p0, 0x1.e8911ap-1, -0x1.ea2d22p0, -0x1.920d38p-1, -0x1.5d462p0, -0x1.939684p-1, 0x1.4abb7p0, -0x1.fe83dcp-1, -0x1.112692p-4, -0x1.5981bep0, 0x1.7b0a1cp0, 0x1.ce5e1ep0, -0x1.b2f78p0, -0x1.d8da9ap-1, 0x1.4f66eap0, -0x1.c3726ep0, 0x1.0a4334p-2, 0x1.8c5372p-3, -0x1.b09e4p0, 0x1.9abcacp0, 0x1.06b35ep0, -0x1.88ed06p-2, 0x1.28c9fap0, -0x1.82a922p0, 0x1.638908p0, -0x1.8e3276p0, 0x1.11181p-2, 0x1.2fe966p-4, -0x1.12055p0, -0x1.d9c712p-1, 0x1.6b310ep-2, -0x1.1720aep-2, -0x1.1d1882p-3, 0x1.fdb05cp-1, 0x1.55f274p0, -0x1.2057d2p0, -0x1.4c800cp-2, 0x1.07727ap0, 0x1.190d5cp-3, 0x1.d6b446p0, -0x1.3df98ep-2, -0x1.315288p0, -0x1.0534bp0, 0x1.71ec04p0, -0x1.194464p-1, -0x1.8e88c4p0, -0x1.9e9486p-1, 0x1.b42e86p0, -0x1.7b4aa4p-2, -0x1.1a18c8p0, 0x1.081764p-2, 0x1.5eb654p-3, -0x1.0fb982p-2, -0x1.0048acp0, 0x1.946338p0, 0x1.222862p-3, 0x1.74b7e4p0, 0x1.2954f8p0, -0x1.6d02ap-3, 0x1.6d2dcep-2, -0x1.af661ap0, 0x1.174c62p-3, 0x1.2b5356p-1, 0x1.107544p-4, -0x1.6c2156p0, 0x1.4a37c2p0, -0x1.14c6eep0, 0x1.60c9ep0, 0x1.26f4cap0, -0x1.5f62dcp-5, -0x1.f7603p0, 0x1.344144p-3, 0x1.2e2f32p-1, 0x1.795e96p-1, 0x1.4936d4p0, -0x1.7c25b4p0, 0x1.db828ep0, 0x1.3c064p0, 0x1.024de4p-2, -0x1.630e94p0, -0x1.df530cp-3, -0x1.707c1p0, -0x1.5227eep-1, -0x1.51aa74p-3, -0x1.8f43cp-2, -0x1.e67b7p0, -0x1.0f7d5p0, -0x1.944cfp-4, -0x1.d3235ap-1, 0x1.5fd646p0, -0x1.e9de38p-3, 0x1.80f8ap0, 0x1.4bca36p0, -0x1.c5df34p0, -0x1.2d461p-1, 0x1.989414p-1, -0x1.2d8b7cp0, 0x1.c1fc64p0, 0x1.628d08p-1, -0x1.ca274ep-3, -0x1.048672p-1, -0x1.1273eap0, 0x1.e21342p0, 0x1.056b48p-1, -0x1.277fdep0, -0x1.9604a4p-1, -0x1.8b4f8ap-1, -0x1.44c43cp0, -0x1.69ac04p-1, -0x1.e20832p0, 0x1.411d5ap0, 0x1.cf26cap-1, -0x1.d47524p0, 0x1.68e6dcp0, 0x1.3bdc7ep-8, -0x1.ab4512p0, 0x1.0f7f2ap0, 0x1.92840cp0, -0x1.e8afc8p-1, -0x1.b6458cp0, 0x1.b0eafap-1, -0x1.b8ba2p0, 0x1.8d1b44p-3, -0x1.747a5p0, -0x1.6a31cap-4, -0x1.695b4ep0, -0x1.12b7bp-3, -0x1.09484cp0, 0x1.c4c708p0, -0x1.e1651cp-2, -0x1.786e46p0, 0x1.f6df7ap-5, 0x1.a3973cp0, 0x1.920752p-1, 0x1.fd6e52p0, -0x1.956706p-1, 0x1.0d8de6p-2, 0x1.085936p-2, -0x1.7c198cp-3, -0x1.883bbcp0, 0x1.931c8ep0, -0x1.660a82p0, 0x1.c9113cp-1, -0x1.2aebap0, -0x1.13c846p0, -0x1.11054cp-4, -0x1.0b1ab6p0, 0x1.cae3cp0, -0x1.859f9cp0, 0x1.b30368p0, -0x1.667ddep0, 0x1.f30904p0, 0x1.098b64p0, -0x1.2ddf4ap-4, -0x1.0fae98p0, 0x1.80439ep-3, -0x1.f9d862p-1, -0x1.9c4624p0, 0x1.c0f084p-4, 0x1.675f3cp-1, -0x1.932cf4p-2, -0x1.c8186cp-1, -0x1.b17be4p-2, 0x1.08843p-2, 0x1.42aaeap-2, 0x1.72d1f2p-1, -0x1.a6b3a8p-1, -0x1.3205dp-2, 0x1.39ecaap-4, -0x1.da014cp-1, -0x1.e0300cp-1, -0x1.16a4a6p0, -0x1.b3aa26p-2, -0x1.918a1ep-1, 0x1.c13e26p-2, 0x1.7e5a0ap0, -0x1.aab0eep-1, 0x1.8286a2p-2, -0x1.1855fp0, -0x1.8679d6p0, -0x1.75b194p-1, 0x1.05a5bp-1, -0x1.1f508ep0, 0x1.615ddcp-2, -0x1.c21846p-3, -0x1.d20ap-8, 0x1.5e71d8p0, -0x1.aa4254p-3, 0x1.c158eep-1, 0x1.82020ap0, 0x1.9338fp-1, 0x1.857b9cp-3, 0x1.efe86cp-4, 0x1.7dc82cp-2, -0x1.94bf84p-1, 0x1.03b04ep0, 0x1.e79d6ap-2, 0x1.31b82ap0, -0x1.f8533p-1, -0x1.db12dcp0, 0x1.5cebaep-1, 0x1.1f0a98p0, 0x1.ea8554p0, 0x1.4c9988p-1, 0x1.27d16ep0, -0x1.6e224p-2, 0x1.891ef6p-2, 0x1.b9cd38p0, -0x1.ef79d6p-2, 0x1.ea7c42p-1, -0x1.edf15ep-3, 0x1.567e0cp0, 0x1.0eb33ap-1, 0x1.6a063cp-3, -0x1.0c32c4p0, 0x1.bfaed6p-1, 0x1.b6b704p0, 0x1.8f727p-1, 0x1.461874p-2, -0x1.008ec8p-1, 0x1.2ce83cp0, -0x1.e78918p-1, -0x1.3e6b94p0, -0x1.7bdba8p-1, 0x1.5ec0c8p-1, 0x1.e56346p0, -0x1.587d94p0, -0x1.f86894p-2, -0x1.2b95dep-3, 0x1.d375dp0, -0x1.cedc38p0, 0x1.e1c65ep-1, 0x1.fee71cp0, 0x1.f999e2p-5, -0x1.b57668p-2, -0x1.d072d6p-1, -0x1.30d0e6p-4, -0x1.a790b2p0, 0x1.d3eeecp0, -0x1.e4010ep-2, 0x1.45dcf8p-1, 0x1.52906p-1, -0x1.1a29cep-2, 0x1.9fab4p-1, -0x1.1ccd62p0, -0x1.8ce40ep-1, 0x1.02884ap-2, 0x1.6b412ep0, 0x1.dc4c5ap-3, -0x1.0d8b02p-4, 0x1.35a94p-2, -0x1.01dae4p0, -0x1.3967a4p0, 0x1.1c9378p0, 0x1.a1edc2p0, -0x1.c1b528p0, 0x1.70eec4p0, -0x1.357d46p-1, 0x1.6dd6acp-1, 0x1.65bfp-3, 0x1.a2062cp-1, 0x1.e86c56p0, -0x1.d75ff6p-1, 0x1.f064fap-4, 0x1.f30b5ap0, 0x1.31d37ep0, -0x1.6af5f4p0, 0x1.e74484p0, 0x1.b59e86p0, 0x1.a8d658p0, 0x1.1b01b4p-1, 0x1.fee1ecp0, -0x1.e8c1b2p0, 0x1.8e49fep0, -0x1.956c12p-1, 0x1.2b922p0, 0x1.92d908p0, 0x1.2e2512p-3, 0x1.4fd086p-2, -0x1.1b3978p-1, 0x1.74db5ap0, 0x1.181a76p-3, -0x1.cd865p-3, -0x1.10460cp-1, 0x1.a3621p-2, 0x1.162db4p-2, 0x1.a85e5p-2, -0x1.e5b28ep-4, -0x1.2c328ep0, 0x1.b4a1c2p0, -0x1.53e98ep0, 0x1.af5866p0, -0x1.5df3b2p-1, -0x1.126864p0, -0x1.d24f04p-1, -0x1.174efap0, -0x1.905b56p-1, -0x1.18373ap0, 0x1.e7c028p-3, -0x1.6f0048p0, 0x1.da7648p-1, 0x1.4546a2p-1, 0x1.2214d4p-1, -0x1.1a6fa8p0, -0x1.15bd5ap0, 0x1.549858p-2, 0x1.b931e2p0, -0x1.3e025cp-3, 0x1.33742ap-5, 0x1.044942p-1, -0x1.710426p-2, -0x1.787b98p0, 0x1.0ed5ep-1, 0x1.8badbap-2, 0x1.9a587cp-3, -0x1.a495f8p0, 0x1.65f254p-2, 0x1.9853fcp-2, -0x1.1d7f86p-1, 0x1.a4b0dcp-7, -0x1.3d8168p-2, -0x1.46daa8p-1, -0x1.ba5a3p0, -0x1.0630cap0, -0x1.57b26ep-2, -0x1.ba3968p0, 0x1.6a82d4p0, -0x1.db99d8p-1, 0x1.4e59bp-1, -0x1.f719d4p-1, -0x1.6586b6p-1, -0x1.9a4f5p-1, 0x1.dbcd7ap-1, -0x1.3c1278p0, 0x1.5bce8ep-4, 0x1.60dab4p0, 0x1.13c7fcp0, -0x1.e9044ap-2, 0x1.af8272p0, 0x1.332e88p-1, 0x1.b06cdcp0, 0x1.e1b7dcp-1, 0x1.f45cp0, -0x1.44a87cp0, -0x1.6247a2p0, -0x1.b556acp-4, 0x1.c88f4ap0, 0x1.4d8778p-2, -0x1.a3054p0, -0x1.f8b094p0, -0x1.c819ep0, -0x1.04486p0, 0x1.9cee34p0, 0x1.19dbaep0, 0x1.b8f13ap-3, -0x1.6b492cp-1, 0x1.51c9fap0, 0x1.c8166cp0, -0x1.f49e6ep0, 0x1.89eaeap0, 0x1.70c15cp-2, -0x1.97dd2cp-1, 0x1.83a16ep0, 0x1.7179p-2, -0x1.295e46p-1, 0x1.4c0b2ap-1, 0x1.61de2ep0, 0x1.020decp0, 0x1.82755ap-3, -0x1.699866p-2, 0x1.42347p-2, 0x1.b4b464p-2, 0x1.492dcp0, -0x1.a2bd04p-2, -0x1.ce44b4p0, 0x1.82632cp-3, 0x1.aaaa2p0, 0x1.a21f5ap-1, 0x1.0de8acp-1, -0x1.648482p-1, 0x1.59dc66p0, -0x1.eb2746p-1, -0x1.6d088ap0, -0x1.2563f4p0, -0x1.f298bep0, 0x1.14c722p-3, -0x1.46e552p0, -0x1.9f71b4p-1, 0x1.0afe7ap0, -0x1.b60ab8p0, -0x1.c1317ap0, -0x1.0dc7d2p0, 0x1.bb201p0, 0x1.508b32p0, 0x1.b9322p-1, 0x1.5685fcp0, -0x1.fe7f7cp-2, 0x1.168916p0, -0x1.bb6edap0, 0x1.6a788p0, -0x1.5c14a8p-4, -0x1.da797ep0, 0x1.cf6358p0, 0x1.170182p-4, -0x1.14893cp0, -0x1.8fb732p0, 0x1.3bf818p-1, 0x1.cb7382p0, -0x1.34076ep0, -0x1.dd0e1ep-2, 0x1.cd85e4p-3, 0x1.5c57ep0, -0x1.2a909ep0, -0x1.27abe2p-1, -0x1.4e4dap0, -0x1.e2b83ap-1, 0x1.86bcf6p-1, -0x1.63862ap0, -0x1.8c1e0cp0, 0x1.74e1fep-2, -0x1.4aa97cp0, -0x1.c7eaf2p-1, 0x1.1fba4p-1, 0x1.060b76p-2, 0x1.aa9da8p-1, 0x1.49dab6p0, -0x1.6df938p0, 0x1.dc64bep0, 0x1.009278p0, -0x1.844206p0, -0x1.e5acp-1, 0x1.3c26fp0, -0x1.f29104p0, 0x1.40ed6ap0, -0x1.1c13bcp0, -0x1.3edd4ap-3, 0x1.df6c68p0, -0x1.7b539ep0, 0x1.0591dp0, 0x1.fcd69p0, -0x1.b0eb68p0, -0x1.662672p-4, 0x1.e6b438p-2, 0x1.fe393ap-1, 0x1.aebc3ep0, 0x1.ee732ap0, -0x1.eb9df4p-2, 0x1.ba6fb2p0, 0x1.7d176ap0, -0x1.77bbb2p-1, -0x1.6b9cdp-1, -0x1.65258cp-4, 0x1.095736p-1, -0x1.45e9b2p0, -0x1.680208p-2, -0x1.0c2adep0, 0x1.1f95fp0, -0x1.5c7fap0, 0x1.b425ccp-4, -0x1.60b02p0, -0x1.139512p0, 0x1.0e944p-1, 0x1.7611aep0, -0x1.8f63cep0, -0x1.544a2ap0, -0x1.5bb608p-2, 0x1.6e311p0, -0x1.d8cd06p-2, -0x1.5ec3ap-1, 0x1.06e0fap-4, 0x1.f3debp0, 0x1.a2271cp0, 0x1.79861p0, -0x1.28aa44p0, 0x1.759c98p-2, -0x1.77dad8p-1, -0x1.0fdba8p0, -0x1.3205dcp-1, 0x1.7b9424p0, 0x1.b6bd24p0, 0x1.7cb49ap-3, 0x1.319fep0, -0x1.9ef5b6p0, 0x1.bc8574p0, -0x1.b8082ep0, -0x1.bfc3e4p0, -0x1.c1a364p0, 0x1.bad5aap0, -0x1.b80ac6p-1, 0x1.fbb9a8p0, 0x1.be3f74p0, -0x1.fb1a92p-4, -0x1.9291b8p0, -0x1.85882ap0, -0x1.aa7f2cp0, 0x1.e79ff2p-2, -0x1.155c1cp0, 0x1.c58b72p0, -0x1.09176ep0, -0x1.7f1bep-2, 0x1.2e3934p0, -0x1.b119c2p0, 0x1.d75158p-1, 0x1.5c03bap-1, -0x1.18a0c2p0, 0x1.aefbe4p-2, -0x1.5a24c2p0, -0x1.b332bap0, 0x1.03b8a8p0, -0x1.588c16p-2, -0x1.adcde6p0, 0x1.d8882p-5, 0x1.c63b3ap0, -0x1.958fccp-1, -0x1.e1b2cp0, -0x1.b6f5a6p0, -0x1.11ee28p-1, -0x1.0df4d2p-2, -0x1.f30e16p0, -0x1.45ff6ap-2, 0x1.401a2p0, 0x1.80a5e4p0, -0x1.e3b31ap-1, 0x1.377fcep0, -0x1.cd5844p-1, -0x1.15f2ecp-9, 0x1.c367f8p-3, -0x1.8e8a98p-1, 0x1.cdb8a4p-2, 0x1.a1eb62p-2, 0x1.3bd22p0, 0x1.95a82ep0, 0x1.aa88e2p-1, 0x1.6275acp0, 0x1.705a4cp0, 0x1.c76752p-2, -0x1.7bcae8p-1, 0x1.d1c36ap-2, 0x1.db1866p0, -0x1.430a66p0, 0x1.a64754p-3, -0x1.6a32b6p-2, 0x1.74da86p-2, 0x1.1f43c2p-2, 0x1.04f27p0, -0x1.f3516ep-3, -0x1.6850c2p0, -0x1.4d01aap0, -0x1.e0872cp0, 0x1.8b235ep-1, 0x1.809daep0, 0x1.896684p-2, -0x1.4b6ccep0, -0x1.1f133p-1, 0x1.c1658ep0, 0x1.e40f6p-1, 0x1.5f17fcp0, -0x1.952d16p0, 0x1.2b251ap-1, -0x1.e40c48p-1, -0x1.08f23ep-2, -0x1.c8b216p-7, 0x1.291048p0, 0x1.99588ep-3, 0x1.90a59p-1, -0x1.e12e68p-4, -0x1.5509f4p-6, -0x1.2ed21p-7, -0x1.fbcbe8p0, 0x1.68b3fep0, 0x1.5d6308p0, -0x1.c26e06p0, 0x1.24f6aap0, 0x1.1f109ap-1, -0x1.0b1288p-2, -0x1.9c44fp0, -0x1.75d4fep0, -0x1.b4bce4p0, -0x1.b740ep-2, -0x1.244204p-1, 0x1.465bc4p-1, 0x1.bf0e26p-2, -0x1.04360cp-1, -0x1.99f466p-1, 0x1.d9d8d8p0, -0x1.5ed04p0, -0x1.513b92p0, -0x1.c3a332p0, -0x1.f64186p-2, -0x1.13381p0, -0x1.021692p0, 0x1.abd38ap0, -0x1.433b7cp-1, 0x1.92b89ep0, -0x1.fa316p0, -0x1.893a62p0, -0x1.c02de2p-1, -0x1.0a3136p-1, 0x1.8ac85ep-3, 0x1.3c40ep-3, -0x1.ebbb3ap-4, 0x1.5e2274p0, 0x1.72145cp-1, -0x1.d66282p0, 0x1.fbcafep0, 0x1.1e9aa8p-2, -0x1.d0b734p-4, -0x1.aeebaep-1, -0x1.7c2844p-3, -0x1.8bbee4p0, -0x1.269c2ap-1, -0x1.067d94p-2, -0x1.53c188p0, -0x1.2b5f2cp-3, 0x1.69f3dep0, -0x1.16782p0, -0x1.dbf62p0, 0x1.69b70ep0, 0x1.fe8624p-1, -0x1.aece2p-4, -0x1.1e0368p-3, 0x1.afd1dcp0, 0x1.e8032p0, 0x1.e9768p0, 0x1.9da29ap-3, -0x1.1b7c22p-1, 0x1.96013cp0, -0x1.bf8118p-2, 0x1.3b807ep0, -0x1.b53ac2p0, 0x1.14d7c6p0, 0x1.f21d4cp0, -0x1.d03d4cp-3, -0x1.b0f54ap-1, -0x1.d02162p0, 0x1.cf672p0, 0x1.1462dep-1, -0x1.f4ea82p-3, 0x1.fcf65ap-2, -0x1.a903cap0, -0x1.333a1ep0, 0x1.ffb5d4p-8, -0x1.0beb5p0, 0x1.0e70b6p0, 0x1.3bc258p0, -0x1.bde0fcp-2, -0x1.2d61c2p0, -0x1.c17076p-4, -0x1.1e2926p-3, -0x1.8cc0f4p0, 0x1.00865p0, -0x1.6490cap-2, -0x1.645b8ep-1, 0x1.62783cp0, 0x1.aa4772p-8, 0x1.94d246p0, -0x1.657272p0, 0x1.8f0abp-1, 0x1.2313bp-1, 0x1.4a22cp0, -0x1.ea7b94p-1, -0x1.85671ep-1, 0x1.ff01f8p0, -0x1.cc872p0, -0x1.209888p0, -0x1.416a44p0, 0x1.e7f31ap-2, 0x1.282832p-1, 0x1.d7f2bep-8, 0x1.595f6p0, -0x1.3a0c3ep-1, 0x1.111f36p0, 0x1.a09ecp0, 0x1.d1892cp0, -0x1.c34972p-2, 0x1.0e38cp-1, -0x1.d90c9p-1, 0x1.a28bdep0, -0x1.adc2dep-1, -0x1.0a66a2p-1, 0x1.805dbap0, -0x1.4e4e6p0, 0x1.9c0264p0, 0x1.5067ecp-2, -0x1.98dd76p-1, 0x1.af442cp-2, -0x1.fa03c6p-1, -0x1.cff1e2p0, -0x1.444e92p0, -0x1.370956p-1, -0x1.55748cp0, -0x1.e15a58p-1, 0x1.b021bep-1, 0x1.1477b4p0, 0x1.e80914p-3, 0x1.154672p0, -0x1.d4bd9p0, 0x1.40823ap-1, -0x1.cff678p-2, -0x1.e4f4bep0, 0x1.4575a6p0, -0x1.64ad9ep0, -0x1.a5ba94p-1, 0x1.eec142p-1, -0x1.cde52p0, -0x1.6260eep-1, 0x1.8489a4p0, 0x1.ab596ep-2, -0x1.e202bep-2, 0x1.9a544ap-1, -0x1.6b4578p-3, 0x1.fe0fb2p0, -0x1.8b28d2p-2, -0x1.d85738p-8, 0x1.9976bep-3, -0x1.3d54f8p0, -0x1.aed7f2p-2, 0x1.eec09ap-2, -0x1.8c65f6p-4, -0x1.639198p0, -0x1.36b348p-4, -0x1.db79e6p-1, -0x1.db5e64p-1, -0x1.945728p0, -0x1.d57176p0, -0x1.cc1126p-1, 0x1.e31fb8p-2, -0x1.3fb8ap-3, 0x1.15d92p-1, -0x1.c95682p-3, 0x1.089b7ap0, -0x1.8725bp0, 0x1.fd323ep0, -0x1.cfb8p-3, 0x1.f5c884p-1, 0x1.440954p0, -0x1.af77cap0, 0x1.9d70bep-2, -0x1.2520b6p0, -0x1.f14882p-4, -0x1.ea42f8p0, -0x1.210ffcp0, 0x1.ab4b3cp0, 0x1.fd5d54p0, -0x1.45b064p-2, -0x1.a504ccp0, 0x1.29d288p0, -0x1.857b66p0, -0x1.a10efcp0, -0x1.43ffd2p0, -0x1.7b2364p0, -0x1.f75754p-3, 0x1.c14a7p-3, -0x1.a101f2p0, 0x1.3c815ap-1, 0x1.3bd43ep-5, -0x1.0be31cp0, 0x1.bacf94p-2, -0x1.88054ep0, -0x1.82e7b8p0, -0x1.4daf7p0, 0x1.c14a78p0, -0x1.93bc8cp0, 0x1.e020dap-3, -0x1.6f85f8p0, -0x1.87cc4ap0, 0x1.24fa6cp-1, 0x1.da5e7ap0, -0x1.d2490ap0, -0x1.f4a5a8p-3, 0x1.81236cp0, 0x1.f03358p0, 0x1.59cd9ep0, -0x1.b51a32p-3, -0x1.4554bap0, 0x1.4075b2p0, -0x1.a32e6ep0, 0x1.96459ep0, 0x1.1b5542p-1, 0x1.757d74p-2, -0x1.c3c4c2p-3, -0x1.2b4f24p-5, -0x1.dc9c6ep0, 0x1.7203ecp0, -0x1.432392p0, 0x1.bd5cbcp-3, -0x1.f042e6p-1, 0x1.0f335cp0, 0x1.88958p-2, -0x1.526ff6p0, -0x1.05156ep-1, 0x1.cd2016p-1, -0x1.f9c30ep0, 0x1.258f8ap0, -0x1.64fd4ap0, 0x1.cbcc9ep0, 0x1.46cc5ep0, 0x1.29d21p-2, 0x1.5347dcp-1, 0x1.26827cp-3, -0x1.0b747ap-1, -0x1.ae067p-1, -0x1.d96d26p0, 0x1.66ac32p-2, -0x1.c722fep-5, -0x1.1276bap0, 0x1.5c1bd8p0, -0x1.539f5cp-1, -0x1.759bap0, -0x1.bbc076p-2, 0x1.9b4736p-1, 0x1.dfedf6p-1, -0x1.8d97b2p-2, 0x1.bc79a2p-4, -0x1.0617cap0, 0x1.9ce2p0, -0x1.9416c8p0, 0x1.b1dea2p0, 0x1.f3e74p-2, 0x1.2ffcfp-1, -0x1.0fb1dep0, 0x1.aff56ap-5, -0x1.52ba08p-1, 0x1.5991b6p-1, -0x1.f6683cp0, 0x1.f75aa6p-1, 0x1.d895d6p-4, -0x1.f1f686p-2, -0x1.dd8bdcp-4, -0x1.f67792p-2, 0x1.1cb2c2p0, -0x1.c85d7p-3, -0x1.ca4834p0, -0x1.633b4ap0, -0x1.93c86p0, 0x1.314152p0, -0x1.024c04p-4, -0x1.9b023p-1, 0x1.cfcdd4p-4, 0x1.72d386p-3, 0x1.e81f94p0, 0x1.326618p-1, -0x1.62184p0, 0x1.f6b67p0, 0x1.1ecb64p-1, -0x1.6df1ecp-2, 0x1.8ccb2ep0, -0x1.997962p0, -0x1.7f7056p-2, 0x1.9e7524p-3, -0x1.05518p0, -0x1.dc2b68p0, 0x1.b79026p0, 0x1.579506p-1, 0x1.d2eaa6p0, 0x1.83b1f6p0, -0x1.9a43d2p-2, -0x1.c2395p0, 0x1.14df5cp-1, 0x1.a468bep-1, -0x1.36930ap0, 0x1.7e9ef4p0, 0x1.f6dae6p0, -0x1.497812p-5, -0x1.961b4ep0, -0x1.b2bae2p-4, 0x1.cc1f98p0, 0x1.a5c692p0, 0x1.f2b3fep0, 0x1.ed635cp-7, 0x1.b5add4p0, 0x1.0b16ecp-1, -0x1.8e2bf2p-2, 0x1.f538a4p-2, -0x1.d37a3cp0, -0x1.fc3e6cp-1, -0x1.00f40ep0, 0x1.86d8dep-1, 0x1.93032ep-1, -0x1.33ccaep-2, 0x1.bb427ap0, -0x1.b228e4p0, 0x1.7d26a2p0, -0x1.8c7d48p-3, -0x1.dbc42p-5, 0x1.b513b2p-1, -0x1.04320ap-12, 0x1.24a8d8p-2, 0x1.eaee7p-1, -0x1.0b901ap-3, -0x1.9f5f1p0, 0x1.c7c80cp-3, 0x1.a144eap0, 0x1.b4fed8p-2, -0x1.8a50f6p-2, 0x1.92777p0, -0x1.204908p0, 0x1.a2c636p0, 0x1.63e366p-1, -0x1.a7fdacp-3, 0x1.54992p-2, 0x1.ba14cp-1, 0x1.59b3e4p-1, 0x1.2f1dep0, 0x1.fa1a2p-1, -0x1.3cc668p-2, -0x1.614166p0, -0x1.f4c094p-7, -0x1.7e18f4p0, -0x1.f2cc8ep0, 0x1.e8a76p-2, 0x1.3a1bf6p-1, 0x1.565c1p0, 0x1.a7558p0, -0x1.c5b592p0, 0x1.ae2738p0, 0x1.dee876p0, -0x1.a51588p0, 0x1.5bf04cp-1, -0x1.400e3ap0, -0x1.f78feep-1, 0x1.339694p-1, -0x1.b6a5d2p-3, -0x1.f10f5cp0, -0x1.11dda8p-1, 0x1.773a38p-1, 0x1.a07244p-2, 0x1.b27672p-1, 0x1.d294dcp-6, -0x1.7020a6p-2, 0x1.9ad06p0, -0x1.7419f4p0, 0x1.a13264p-1, 0x1.540822p-3, 0x1.5d430cp0, 0x1.1658dp-1, -0x1.7eb3f4p-1, 0x1.c29f5ap0, -0x1.3c3e02p0, -0x1.0e75acp-8, 0x1.0bb558p-2, -0x1.55ce6ep-3, 0x1.8e4d52p-1, -0x1.ab5328p0, -0x1.5e7688p0, -0x1.b2efp-1, -0x1.bd1a1p-1, 0x1.9f99c6p0, 0x1.39d84cp-1, -0x1.6f3f84p-1, 0x1.bb0cfp0, 0x1.3c260ap-1, 0x1.619142p0, -0x1.28da28p-4, -0x1.caae96p-1, -0x1.2cdc4ap0, -0x1.ef40f2p0, -0x1.dfa38ep-7, 0x1.c39f08p0, 0x1.1d7cf8p0, -0x1.857a0ep0, 0x1.d95efep0, -0x1.d5c7f4p-3, -0x1.440562p-1, -0x1.3737c4p-2, -0x1.bf738ap-2, 0x1.d8cd28p0, 0x1.69befp-2, 0x1.279312p-3, 0x1.8c9a7ep-5, 0x1.905afcp-1, -0x1.1ae702p-1, 0x1.4d7978p0, 0x1.5d1d1ep0, -0x1.2213ecp-1, 0x1.a8791cp0, -0x1.f8254ap0, -0x1.84d61p-2, -0x1.472d7ep0, -0x1.de1476p-1, 0x1.d7b8dcp-1, -0x1.5140eep0, -0x1.009c44p-6, 0x1.1cfd14p0, 0x1.3ba9dp0, 0x1.f50652p-1, 0x1.acb8ap-1, -0x1.14819p-5, -0x1.fccc06p0, 0x1.9a174p0, 0x1.77b432p0, 0x1.37dc3cp-2, -0x1.8d549ap-1, 0x1.e2eccep-2, 0x1.c5b186p-3, 0x1.01e646p-1, -0x1.7b5a84p0, -0x1.9915eep0, 0x1.c7524cp-1, 0x1.bb321cp-4, -0x1.bb3bdep-4, 0x1.d91df6p0, 0x1.14c9d4p-1, -0x1.a0517ep-2, -0x1.974b92p0, -0x1.ba64acp-2, 0x1.13460cp-1, 0x1.3b7904p0, 0x1.ee39dap-2, 0x1.4b4ae8p0, -0x1.f0fb4cp-3, -0x1.060126p-2, -0x1.3c8fdep0, 0x1.2788acp0, -0x1.5130b2p-1, 0x1.deae5p-1, -0x1.cd571ap0, -0x1.467f76p-1, -0x1.db3088p-1, -0x1.de1ac4p-1, 0x1.0145f4p0, 0x1.ab8914p-2, 0x1.1c7feep0, -0x1.be296cp-1, 0x1.ed9b16p0, -0x1.4fc96p-3, -0x1.174b1p-3, -0x1.6e9aaap0, -0x1.8d0508p0, -0x1.c0a4fcp-4, -0x1.a194f8p0, 0x1.19ea1ap0, 0x1.c010d6p0, -0x1.48468ap-2, 0x1.3c520ep0, 0x1.122f5cp0, -0x1.bb1726p-1, -0x1.62108ap-1, -0x1.089d7ep-2, -0x1.b5a612p0, 0x1.b32d1ep-1, 0x1.1d6764p-1, 0x1.c6e18cp0, -0x1.4fa864p-2, 0x1.871bf8p-3, 0x1.bcd22cp-5, -0x1.b00294p0, -0x1.af2d38p0, 0x1.38ba22p0, -0x1.21efa2p-2, 0x1.8aca72p-2, 0x1.f8e5f6p0, 0x1.564244p0, -0x1.ba9fe6p-4, -0x1.f2622ep0, 0x1.6154fcp-8, 0x1.fbacecp0, 0x1.f8f3dp-6, 0x1.32ce16p-2, -0x1.73a4ecp-1, 0x1.109106p-2, -0x1.8b7d14p0, -0x1.f43ea4p-4, -0x1.bb2d2p-1, -0x1.4a6ae4p-1, -0x1.81c088p0, 0x1.c3e76p0, -0x1.fed7cp-1, 0x1.84f0e6p0, -0x1.86bb52p0, -0x1.40a4d8p0, 0x1.eb3c5cp-1, 0x1.715dcp-1, -0x1.d2ee4cp0, 0x1.eb7962p0, -0x1.ec858ep-1, -0x1.759e06p0, -0x1.0ce86p-2, -0x1.596d6ap0, 0x1.ff18c6p-1, 0x1.62a986p0, 0x1.25a1f6p-2, -0x1.19cd1cp0, -0x1.b76da8p-5, -0x1.ac9bfcp-1, 0x1.fb1174p-1, 0x1.c2ac5p-5, -0x1.e07388p-4, -0x1.26d53ap0, -0x1.cf2694p-3, 0x1.0061ep-1, 0x1.67e746p-1, -0x1.8c863cp0, -0x1.40cb24p0, 0x1.0eaa28p-1, 0x1.b2a464p0, -0x1.bd4bf4p0, 0x1.d038dap-1, -0x1.3d75c2p0, 0x1.0b75bp-1, 0x1.49b2f6p-1, 0x1.291d4ap-2, -0x1.3d756ap0, -0x1.4362aep0, -0x1.b438p0, 0x1.7eec32p0, 0x1.3c00f8p-1, 0x1.bb25d2p-1, -0x1.6431dap0, -0x1.316a14p-7, -0x1.a64592p-1, -0x1.5b397p-1, 0x1.620df2p-1, 0x1.55d89ep0, -0x1.adbf06p-4, 0x1.bc71a8p0, -0x1.708aeep-2, 0x1.b3b542p0, 0x1.7ee5fp0, -0x1.806b7ap0, -0x1.ce38p0, 0x1.981f68p0, -0x1.b5cdfap-2, 0x1.4b1b58p0, 0x1.df8f0ap-1, 0x1.e6a0bcp0, -0x1.2b02cp0, -0x1.04418p0, -0x1.eef644p-3, -0x1.67392ap0, -0x1.87e33ep-1, 0x1.5c6706p0, -0x1.e25f5ap-1, 0x1.818788p0, 0x1.f6e672p-2, -0x1.c61d1ep0, -0x1.2d41e8p-1, -0x1.c469b4p0, 0x1.6adf74p-6, -0x1.9cfd42p0, 0x1.9cb9dp-1, -0x1.22e212p-2, 0x1.e1cf58p0, -0x1.4737eap-1, -0x1.14136cp-1, 0x1.0110f8p0, -0x1.6979aap0, -0x1.7184bp-1, -0x1.66dap0, 0x1.dc80d8p0, 0x1.b4e4cep-3, 0x1.f1427p-1, -0x1.4c0f1ap-1, 0x1.779032p0, -0x1.3d9b2ep0, 0x1.5cb65ep0, -0x1.598516p-4, -0x1.6c929ep0, 0x1.566398p0, -0x1.8f6f0cp-3, 0x1.b69a42p-1, -0x1.033634p0, -0x1.7434dap-4, 0x1.bf7518p-3, 0x1.9ccadep0, 0x1.7055a8p-1, -0x1.4dd4a8p-6, -0x1.5fe79p0, -0x1.34ced8p0, -0x1.ed186ep-1, -0x1.e25b66p-1, 0x1.07abecp-1, -0x1.3ae644p0, 0x1.fe101cp-1, 0x1.225e56p-2, -0x1.255b7p-1, -0x1.a7b12cp-7, -0x1.1393d8p0, 0x1.9ad0d6p0, 0x1.311fc8p-2, -0x1.4ab37ap0, -0x1.4c45b8p-1, -0x1.b95e34p0, 0x1.652214p0, -0x1.c8654p-1, -0x1.8b1464p0, 0x1.ea38c4p-1, 0x1.a96dcap0, -0x1.f29cd8p-5, 0x1.5e8822p0, 0x1.86802p0, 0x1.7b1aacp-2, 0x1.139b26p0, 0x1.c709f2p-4, 0x1.9546bcp-3, -0x1.01b8e6p0, 0x1.50ad86p0, 0x1.6cd5d6p-3, 0x1.b3305cp0, 0x1.0c0bf6p-1, -0x1.e84a98p0, -0x1.c4c72cp0, 0x1.321e82p-2, 0x1.a2b2cep-3, -0x1.8c4b06p0, -0x1.d7b618p0, -0x1.ddcac6p-3, 0x1.754b2ep-3, -0x1.d086cap-1, 0x1.cdfe7ep0, -0x1.2bebf6p-5, -0x1.dd980ap0, -0x1.925318p-1, 0x1.31e0a8p-5, 0x1.858692p-3, 0x1.423cf2p0, -0x1.f46b96p-3, -0x1.f59f96p-4, 0x1.ad852p0, 0x1.fa577p0, 0x1.f215a2p0, -0x1.6cf52ap-4, -0x1.0df8fap-2, 0x1.bcb7e8p-2, -0x1.239d14p-6, 0x1.4e3fd2p-2, 0x1.70c826p0, -0x1.84620cp0, -0x1.4d9908p0, 0x1.0cf392p-6, -0x1.52518ap0, -0x1.883132p0, 0x1.ec365ep-1, -0x1.d78a0cp0, -0x1.bbda3ap-1, -0x1.801126p-1, 0x1.876b86p-1, -0x1.81c39ep0, 0x1.bc667p-3, 0x1.2e91a8p0, -0x1.611ebp-1, -0x1.b553c8p0, 0x1.06ff84p0, -0x1.2edeb8p0, -0x1.4f3ab6p0, -0x1.b5db2p-5, 0x1.ca09e4p0, 0x1.9be5eap0, -0x1.ca0c72p0, 0x1.3ed19cp0, -0x1.1de45ap0, -0x1.18e80cp0, 0x1.7dd932p0, -0x1.2ad68cp0, -0x1.4682c8p0, -0x1.6730b4p-2, 0x1.2c3c3p-1, -0x1.3a9242p0, -0x1.111bdep0, 0x1.e225dap-1, 0x1.416f5ap0, -0x1.d3ab2ap-3, -0x1.59901p0, 0x1.c965c6p-3, 0x1.3d99a6p-1, 0x1.52495cp0, -0x1.0cc8eep-1, -0x1.44ea6p-1, 0x1.21d212p-1, 0x1.91c42ap-2, 0x1.513d46p0, 0x1.b80feap0, 0x1.b22c5ap0, 0x1.33e8bp-2, -0x1.8b1a4cp-2, 0x1.98fdfep-1, -0x1.ec72fep-2, 0x1.1ea6ap-1, 0x1.f4273ap0, 0x1.043732p0, -0x1.a8a188p0, 0x1.bd110ep0, -0x1.f39b96p0, 0x1.7c3af2p-3, -0x1.9176f8p0, -0x1.c1a5aap-3, 0x1.b0d378p-4, -0x1.b32c88p0, 0x1.44831ep0, -0x1.55f5f8p0, 0x1.d3f88cp0, -0x1.6e12bcp0, -0x1.3b4c64p-2, 0x1.84b89cp-1, 0x1.4f9942p0, 0x1.c02a28p0, -0x1.269a62p0, -0x1.1f73bcp-2, 0x1.9ba224p-3, 0x1.43f9eep0, -0x1.903da4p0, -0x1.704cacp0, 0x1.d53fa6p-2, -0x1.0e749ep-2, 0x1.06f92ap0, 0x1.a1e2f8p0, 0x1.d6b0c6p-4, -0x1.6b4774p-1, 0x1.c27d4ep0, 0x1.fc2ad2p0, -0x1.1b03eep-1, -0x1.1db2d8p0, 0x1.727ecp-1, 0x1.47eb84p0, 0x1.e76cbcp0, 0x1.f2745ap-2, 0x1.8d661ep-1, -0x1.91a8a8p0, 0x1.a34f74p0, 0x1.3a2db2p-1, -0x1.25f538p0, 0x1.9639d4p0, -0x1.0e5196p0, -0x1.0b0102p-1, -0x1.24ffd8p0, -0x1.7dd69ap-1, 0x1.1765ep0, 0x1.17655p-1, 0x1.330afep0, 0x1.7b291ep0, 0x1.a80d4cp0, -0x1.fd6f22p0, -0x1.da5088p0, 0x1.c1d5b8p0, -0x1.aa0a0cp0, 0x1.335b8cp-1, -0x1.1f8762p0, -0x1.3051fp-2, 0x1.a156dp-4, -0x1.1004dp-4, -0x1.45d278p-2, 0x1.0002fep0, -0x1.484a88p-1, 0x1.0c2df6p-3, 0x1.ee0f84p0, 0x1.db2782p-2, -0x1.26385ep0, 0x1.4297d2p0, 0x1.8501c6p0, 0x1.aa468ep0, 0x1.5c87ap-4, -0x1.adcc2ap-3, 0x1.8e0fecp-1, -0x1.1d622cp0, -0x1.abad0ap0, 0x1.25167p0, 0x1.5ebe16p-1, 0x1.c9ebe8p-1, -0x1.210e8p0, -0x1.d5e38ap0, 0x1.2d7518p-1, -0x1.85260cp0, -0x1.0c99d4p-1, -0x1.961ffcp0, 0x1.1d31bp-1, -0x1.079726p-2, -0x1.ef9cecp-6, 0x1.726668p0, -0x1.d3508p-2, -0x1.e4d7a2p-1, 0x1.0d4886p0, -0x1.92abdep0, -0x1.2d2dcep0, -0x1.fa6174p-1, 0x1.499cdp-2, -0x1.5c9b76p0, -0x1.cbb64cp-1, -0x1.0e61a2p-1, -0x1.2be67cp-2, -0x1.66f294p0, -0x1.18a59ep-1, 0x1.d9d286p0, 0x1.0f8104p0, -0x1.53642cp0, 0x1.8ab06ap-11, -0x1.f0518ep-2, 0x1.7df1aap0, -0x1.22daap-4, 0x1.62df76p-2, -0x1.4ec8bap-1, -0x1.516a34p0, 0x1.cf5844p0, 0x1.58459ap-4, 0x1.5751bcp0, 0x1.548a28p-1, -0x1.d2f1f4p-1, -0x1.a9455ap-4, -0x1.2ae93cp-2, 0x1.fe0974p-1, -0x1.40b854p0, -0x1.1a1cbp-2, -0x1.d2458p0, 0x1.37e42cp0, -0x1.225f88p0, 0x1.1dda9cp0, 0x1.0de46p-2, -0x1.00a0a2p-1, 0x1.fd26bcp-1, 0x1.abdec2p-1, 0x1.079e9ap0, -0x1.f44f2ep-1, 0x1.352e98p-2, 0x1.780d3cp0, 0x1.c4980cp-2, 0x1.6600bep0, -0x1.6b78d2p-4, -0x1.ba0a4ep-4, -0x1.68558cp-1, -0x1.5f9cfap0, -0x1.26f826p-2, 0x1.3e3682p0, -0x1.c12a12p0, 0x1.353172p-1, 0x1.ef525ap-2, -0x1.96e922p-1, -0x1.51552p-1, 0x1.5e6d0ap-2, 0x1.d6cf36p0, -0x1.32cd74p-5, 0x1.cd376cp0, 0x1.a8eb0ap0, 0x1.aa1efcp-1, 0x1.18aecap-3, 0x1.f1ad3p-1, 0x1.bc56f6p0, -0x1.854af8p-4, 0x1.279ffp0, 0x1.64c80ep0, 0x1.a4781ep-3, 0x1.e08784p-1, -0x1.f274p-1, -0x1.af84eap0, -0x1.09d762p0, -0x1.e1f0d8p0, 0x1.c6c46cp-2, 0x1.86425cp-2, -0x1.b392ccp-1, -0x1.6f2f76p0, -0x1.9df9a2p-2, 0x1.3c961cp0, 0x1.46f63ap-1, -0x1.9bd312p-1, -0x1.1baa18p-1, -0x1.b2ccc2p0, -0x1.a0561ep-1, -0x1.d886ecp0, -0x1.f1d58cp-3, 0x1.1112dcp-3, 0x1.d7274ap0, -0x1.937a1ep-2, 0x1.5add8cp-3, -0x1.8a431p0, 0x1.e0b2p-4, 0x1.769028p0, -0x1.931a7ap0, 0x1.72f634p0, -0x1.d7caf4p-1, -0x1.fc5824p0, 0x1.6b083p-1, -0x1.345d1p0, -0x1.d09942p0, 0x1.b83c0cp0, -0x1.acd832p0, 0x1.1acf7ap0, 0x1.33c9dcp-1, 0x1.c452cp-1, 0x1.c5fc1ep0, -0x1.f2e396p0, -0x1.0c342ap-1, -0x1.dc43c2p0, -0x1.0c910ep-2, -0x1.bd303ap0, 0x1.1d271cp0, -0x1.320b28p0, 0x1.9ae5cp-1, -0x1.3f2a62p0, -0x1.9d2ffcp0, 0x1.546d1ep0, 0x1.32af46p0, -0x1.190e2ep-3, 0x1.cf8898p-1, -0x1.e24276p0, 0x1.5abf62p-5, 0x1.d4ae6ep0, -0x1.0169cep0, -0x1.ad5454p-1, 0x1.ca083ap-4, -0x1.da164ap0, 0x1.531f74p-2, 0x1.0e4766p-1, -0x1.1d1924p0, -0x1.3c25p-3, -0x1.66df6ap-3, 0x1.05944ap0, -0x1.5d7f7cp-4, 0x1.dc36eap-5, 0x1.6c0026p0, 0x1.52b3e8p0, 0x1.ca899ap-3, -0x1.7a4d7ep0, -0x1.f2a58p0, 0x1.85c8cep-2, 0x1.b9f2e6p0, -0x1.606d0ep0, -0x1.72353p-1, -0x1.9cf094p-3, -0x1.e81462p-2, 0x1.3500bap-1, -0x1.99301ap-1, -0x1.831b7ep-1, -0x1.5891c6p-1, -0x1.53cc0ep0, -0x1.53575p0, 0x1.6c84a4p0, 0x1.120e08p-1, -0x1.230d68p0, -0x1.bbc3e4p-1, -0x1.4c59b6p-4, -0x1.f6b90ap0, -0x1.37e0bep-2, 0x1.7ebfb2p0, -0x1.163c8cp0, -0x1.f0fc02p0, -0x1.113c66p-2, 0x1.0f80ep0, -0x1.681568p0, -0x1.caeffcp-1, -0x1.8a0f2ep0, -0x1.96a418p-1, -0x1.cfa476p0, -0x1.417712p0, -0x1.ae5816p-7, 0x1.e6dd34p0, -0x1.bbf576p-2, 0x1.cf081ap-1, -0x1.45c662p-2, -0x1.68f18ap-1, -0x1.c9ce54p-1, -0x1.89e086p0, -0x1.49ccep0, 0x1.958efap-1, -0x1.825a88p-1, 0x1.38ab2ap-1, -0x1.c613c6p0, -0x1.07792p0, 0x1.f76ecap0, 0x1.dcf0fap-3, 0x1.2da3dp0, 0x1.e0106ep-1, 0x1.0d5c2p0, -0x1.2d427cp-1, 0x1.40240ep-7, -0x1.8562f8p0, -0x1.8789ap-3, -0x1.cd4ed4p0, -0x1.8deaep0, 0x1.569e78p0, -0x1.d02dap0, 0x1.7540fp0, 0x1.15b31p-1, -0x1.9325a8p0, 0x1.ce851cp-1, 0x1.b3766ap-2, -0x1.377c64p0, -0x1.5fc09cp-2, -0x1.de9588p-1, 0x1.85b18p-3, 0x1.a22628p0, 0x1.d9b112p0, 0x1.fdfd24p0, 0x1.0c255p0, -0x1.7a66a4p0, -0x1.3b902ep-2, 0x1.4bd6f4p-1, -0x1.b6a826p0, -0x1.533418p-3, 0x1.81b504p-1, -0x1.7f29dp-2, 0x1.3121c2p0, -0x1.3f27ep-1, -0x1.d779f2p-3, -0x1.b5980ep-2, -0x1.b2b7fep-1, -0x1.f5daep-3, 0x1.924b32p-3, 0x1.374c72p0, -0x1.7eda96p0, -0x1.ec3318p0, 0x1.fd4a6cp-4, 0x1.42cb2ap0, -0x1.a6f062p0, -0x1.40258ap0, 0x1.5ae11p-4, 0x1.773ep-1, -0x1.f2877ap0, -0x1.48e7dep-1, 0x1.8be6bcp-2, 0x1.950cdep-3, -0x1.f2fc56p-1, 0x1.b540e6p-3, -0x1.63caacp0, -0x1.e9cabap0, 0x1.d9a7d2p-2, -0x1.0e19b6p-1, -0x1.72a2cap-1, -0x1.9508dap0, 0x1.a96faap0, -0x1.7d0fb6p-4, 0x1.133c9cp0, 0x1.e00d1cp0, 0x1.ad82bep-1, -0x1.811b5ap-3, -0x1.673214p-3, 0x1.3059bap-3, 0x1.e50c1p0, -0x1.1722ecp0, -0x1.97cb96p-1, -0x1.c6b904p0, -0x1.cc15b8p0, 0x1.098592p-1, 0x1.64e99ep-1, -0x1.23647p-2, -0x1.11ecc2p0, -0x1.410d3p0, 0x1.0e10cp0, -0x1.8911p0, -0x1.1a39b4p0, -0x1.6a6cfap-1, -0x1.c2a0d6p-1, 0x1.24437ep-4, 0x1.63bf7cp0, -0x1.86dc84p-1, 0x1.a5cd96p-5, -0x1.58108cp0, -0x1.7c6042p-1, 0x1.52fe4cp-1, 0x1.41bb3p-1, -0x1.562a3ap0, -0x1.2a98ep0, -0x1.ed2e2p-1, 0x1.43718cp0, 0x1.77410ep-4, -0x1.a954c6p0, 0x1.afc4f8p0, 0x1.1fd1dcp0, -0x1.14e28ep-1, -0x1.190bcp-2, 0x1.0c9094p0, -0x1.1098acp-5, 0x1.75b88ap0, 0x1.362ae8p-3, -0x1.a9bf06p-5, 0x1.d141c8p-1, -0x1.d264cep-4, -0x1.2c3ab8p0, -0x1.2fcd42p0, -0x1.3031bep0, -0x1.1de41ep0, -0x1.a6a5ep-4, -0x1.f0b206p0, 0x1.82132p0, -0x1.2f2bccp0, -0x1.26f1b6p0, 0x1.ff0114p-1, 0x1.50be32p-1, -0x1.67969p-3, -0x1.e2d9b2p0, 0x1.17800ap0, 0x1.a2249p0, 0x1.530744p0, -0x1.f0c642p-1, -0x1.970facp-2, -0x1.fd81bp-1, -0x1.501b96p-1, 0x1.ca3abp-2, -0x1.bcd01ap-2, 0x1.f15b9ep0, 0x1.0a1e76p0, 0x1.9ad5b6p0, 0x1.c0cfe8p0, 0x1.a93132p0, -0x1.544874p0, -0x1.d7fa68p-3, -0x1.cc0d12p-1, 0x1.00e904p-1, -0x1.d121d6p0, 0x1.1e7c56p-1, 0x1.8e7c52p0, 0x1.12ee2ap0, 0x1.f3386p0, 0x1.01852p0, -0x1.4e782cp-3, -0x1.ff19c4p-2, 0x1.661954p0, 0x1.5ef598p-1, 0x1.9a57c8p-2, -0x1.1c16a6p0, -0x1.130edp0, -0x1.c38cd2p-1, -0x1.41f418p-1, 0x1.68ce7ep0, -0x1.e7e72ep0, 0x1.f043e2p0, -0x1.29c586p-3, -0x1.9a45b8p-1, -0x1.612adp-1, 0x1.4b3d96p0, 0x1.25fe04p-1, -0x1.c3ea04p0, 0x1.fdbe8cp0, 0x1.9cee4ep0, 0x1.74f906p0, -0x1.f208f6p0, -0x1.743ea2p0, 0x1.71afep-1, -0x1.8d4e36p-6, 0x1.04cb72p-1, -0x1.41ac3cp0, -0x1.ff4afcp-4, 0x1.a453dp-2, -0x1.9b8d58p-1, 0x1.e25c06p0, -0x1.f17beap-2, -0x1.ed21f2p-8, -0x1.d2127p0, 0x1.cd538ap0, -0x1.25658p0 };
l_struct_OC_k2c_tensor keras_activation_3_test2 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor test3_dense_input_input __ATTRIBUTE_WEAK__;
float c_activation_3_test9_array[6];
l_struct_OC_k2c_tensor keras_activation_3_test1 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor keras_activation_3_test3 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor c_activation_3_test1 __ATTRIBUTE_WEAK__;
float keras_activation_3_test10_array[6] = { 0x1.b1d6bap-3, 0x1.1f57e6p-4, 0x1.9722p-6, 0x1.8ed504p-4, 0x1.1f8d72p-1, 0x1.17e32ep-5 };
l_struct_OC_k2c_tensor c_activation_3_test2 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor c_activation_3_test3 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor test4_dense_input_input __ATTRIBUTE_WEAK__;
float test9_dense_input_input_array[2622] = { -0x1.984d74p-1, -0x1.93f748p0, 0x1.93fd96p0, -0x1.192c78p-2, 0x1.4c5d0ep-3, -0x1.e8bd38p-2, -0x1.29bfbcp0, -0x1.5dccf4p0, -0x1.c26324p0, -0x1.7fd30cp0, 0x1.27c88cp-2, -0x1.a65f7ap0, 0x1.277104p0, 0x1.d79de6p-2, 0x1.585426p0, -0x1.488bc6p0, 0x1.446e76p-1, -0x1.88a00cp-1, 0x1.01dcaep-1, -0x1.a6f9bep0, -0x1.879a48p-4, 0x1.b3202ap-2, 0x1.2d7686p0, 0x1.2c84e4p0, -0x1.8a1406p-1, -0x1.31a3cp0, 0x1.b7b5aep-1, -0x1.c77ccep0, 0x1.4df938p-1, 0x1.d51c32p0, 0x1.2081dap0, 0x1.e53bf2p0, -0x1.995ccp0, 0x1.38e924p0, -0x1.a022bcp-4, 0x1.a8c98ap0, -0x1.29fca8p0, -0x1.c9d108p0, 0x1.219ef6p0, -0x1.86e1d4p0, -0x1.a2e824p0, 0x1.523feap-2, 0x1.1c3584p-2, 0x1.4d056p-1, -0x1.8b43fp0, -0x1.e82a58p-3, -0x1.a7b9aap-2, -0x1.b72d26p-1, 0x1.315236p-1, -0x1.bac36ap-1, -0x1.c3cabp0, -0x1.b90d8cp0, 0x1.79f694p0, -0x1.29e99ap-5, -0x1.3ec6eep-3, -0x1.e8bb7ap0, -0x1.b3aa04p-2, -0x1.d8c0c8p0, -0x1.5779bcp0, -0x1.8149d8p-1, -0x1.5c1804p0, -0x1.0828ap-1, 0x1.c8d99ep0, -0x1.ada0fp-1, -0x1.7e476cp0, 0x1.b2f17ep0, -0x1.a1594cp0, 0x1.f03538p0, 0x1.9d4858p-1, 0x1.df8fc2p-2, -0x1.cd9b3ap0, -0x1.6f9396p-3, 0x1.ab739ap-3, -0x1.cfae72p-5, -0x1.c79d7p-3, 0x1.cfacap0, 0x1.a620f4p-6, 0x1.976bcp0, -0x1.d7475ap0, 0x1.6bf8e4p0, 0x1.3e5602p0, -0x1.53d3d4p0, 0x1.0d5884p0, 0x1.3d129cp0, -0x1.073cc6p-2, -0x1.cafc84p-2, 0x1.32db4ep-2, -0x1.2d3b4ep0, -0x1.fd2828p0, -0x1.5676c8p0, -0x1.73d858p0, -0x1.7c5fc8p0, -0x1.95c34cp-1, 0x1.f36674p-1, 0x1.b4b0dp-1, -0x1.651eeep-1, -0x1.0feaf8p0, 0x1.291178p0, -0x1.0a7d66p-3, -0x1.4b43c8p-1, 0x1.cedd64p-1, -0x1.b77c9cp0, -0x1.abfc18p-1, -0x1.7591dep-2, 0x1.209326p0, -0x1.ba6c38p-5, 0x1.bf1dcap0, -0x1.d2b186p0, -0x1.3bb15ep-1, 0x1.c6d874p0, -0x1.e74d8ep-2, 0x1.258196p-1, -0x1.cd910cp0, -0x1.783p-8, 0x1.9f2bfcp0, -0x1.6be0a8p-1, 0x1.c6ba2ap0, -0x1.8d36p-1, -0x1.ba057cp0, 0x1.0bc9aap-1, -0x1.0f9972p-3, 0x1.1da3bp-1, 0x1.714edcp0, 0x1.f9605p0, -0x1.bd4de4p0, 0x1.3ac87cp0, 0x1.99b384p-2, 0x1.545632p0, -0x1.d4e3b4p-1, -0x1.5f965ap-1, -0x1.025a18p-1, -0x1.bec31ap0, 0x1.341b32p0, 0x1.5ffaa2p0, 0x1.7d1b3p-2, -0x1.ecf6d4p-1, -0x1.858182p-3, 0x1.57bf7cp-4, 0x1.c71d3ep-4, 0x1.f8f10ap0, 0x1.b655e6p-1, 0x1.327f8ap0, -0x1.011d28p-2, 0x1.087b88p0, -0x1.668d6cp-1, 0x1.d08ad6p0, 0x1.91f52p0, -0x1.68f9dcp-3, -0x1.da4b44p0, 0x1.82e5b6p-1, -0x1.cd5ce2p-1, 0x1.ce0b76p-2, -0x1.2980e6p-3, -0x1.8e3d0cp-1, -0x1.295fecp0, -0x1.22e08ep-5, 0x1.1df7bap0, 0x1.0900d2p0, 0x1.c0a7a6p-4, -0x1.b321ecp0, -0x1.9de756p0, 0x1.ad01a6p-2, -0x1.9f13d2p-4, 0x1.afd204p-3, -0x1.7a6f1p-1, 0x1.e8d2e8p-1, 0x1.0d763p-1, -0x1.7c033ep0, -0x1.f9dae4p-5, 0x1.79bd84p-1, 0x1.e2aab8p-1, 0x1.0ea18ep-5, 0x1.e0d978p-1, 0x1.497456p-2, 0x1.364b9p-6, 0x1.e152b8p0, -0x1.7ea5a6p-6, 0x1.662238p0, 0x1.c9ac44p-4, -0x1.6fe30cp-1, -0x1.8fed6ep0, -0x1.6dd19ap0, 0x1.7fb0dap-2, 0x1.aa6c5cp0, 0x1.d8b224p-2, -0x1.38ebc8p0, -0x1.bf75ecp-1, 0x1.983ee6p0, 0x1.27a2fap0, -0x1.06b454p-3, 0x1.656d1ap0, -0x1.31b4f2p0, 0x1.a2eea4p-3, -0x1.c8444cp-2, -0x1.4d8326p-2, 0x1.7e9a8p-1, -0x1.87e8fap-2, 0x1.39d3fp-1, -0x1.94f3fep-1, -0x1.1e1ddep0, 0x1.c8fd46p0, -0x1.d2821ap-1, 0x1.9af238p-1, -0x1.0e006cp-4, -0x1.cf5e2p0, -0x1.6bd6d8p0, 0x1.015206p0, -0x1.ca951cp0, -0x1.886ff6p-7, -0x1.d1b348p-3, -0x1.518276p-1, 0x1.b2201ep-1, 0x1.d4238ap-1, -0x1.1758d4p-3, -0x1.9915p-4, 0x1.28575ep0, 0x1.1a35b6p-1, -0x1.62eep0, 0x1.f22c92p-1, -0x1.4247dap-2, -0x1.1c4e22p-4, -0x1.a3c24p-1, -0x1.ad3c64p-4, -0x1.951b6ap-1, -0x1.35f04cp0, 0x1.d7263p0, -0x1.6a0cc2p0, -0x1.bc520ep0, 0x1.85c382p-1, -0x1.bbed7ap-1, 0x1.4e1adap0, 0x1.8ec5fp-1, -0x1.1babcap0, -0x1.92c6c6p-1, 0x1.684a82p0, -0x1.e37e64p-5, 0x1.5325fap-4, -0x1.3349a4p0, -0x1.6420f8p0, 0x1.cc684cp-2, 0x1.1d2df4p0, 0x1.e9a796p0, 0x1.6e36acp-1, 0x1.4658ep-2, -0x1.36d48ap-2, 0x1.2b2424p0, 0x1.1b9836p-1, -0x1.0e6816p-4, -0x1.e561ecp0, 0x1.1b7512p-1, 0x1.08318cp-1, -0x1.45f2aap0, -0x1.1b0df8p0, 0x1.d6ee6ap0, -0x1.c69642p0, 0x1.2a3a64p-4, 0x1.27542ap0, 0x1.19cca2p-3, -0x1.c5a77cp0, -0x1.fd1e5ap0, 0x1.503cep0, -0x1.b3f2ap-1, 0x1.9473fcp-1, -0x1.ad5264p-1, -0x1.7d40ap0, -0x1.9315bap0, -0x1.fe5a66p-2, -0x1.095beap-2, -0x1.fedd8cp0, 0x1.bf3ae4p0, 0x1.c5863ap-3, -0x1.e3873cp-6, 0x1.2a9f6ap0, 0x1.d452eap0, -0x1.3fcf5ap0, 0x1.20d6b2p0, -0x1.0a438cp-2, 0x1.de1daep0, -0x1.b329e4p0, 0x1.7ce1dcp-1, 0x1.31a3a2p-5, -0x1.bc6f52p0, -0x1.b0f2cap0, 0x1.d3873ep-8, 0x1.5e0d8ap-3, -0x1.af1104p-2, 0x1.99b35cp-1, -0x1.961794p0, 0x1.aa5636p0, 0x1.a4e5cp0, -0x1.c16ffcp0, -0x1.e3f046p0, 0x1.d99594p0, 0x1.b698f4p-4, 0x1.932288p0, -0x1.5ca644p-2, -0x1.f4c6f6p0, 0x1.0eaec8p0, -0x1.e799ap-3, 0x1.d68b96p0, -0x1.984552p0, -0x1.947dfep0, -0x1.248866p0, -0x1.479ee8p0, 0x1.80181ap0, 0x1.add846p0, -0x1.c98e94p-1, -0x1.680308p-4, -0x1.2ee39ap0, 0x1.0068d8p0, -0x1.00e402p0, -0x1.dd5d8p0, 0x1.08ac88p-3, 0x1.240416p0, -0x1.312eb6p-1, -0x1.dda916p-1, 0x1.ae2cc2p-1, -0x1.fee37ep-2, 0x1.029ddep0, -0x1.60c418p-1, -0x1.a1d0eap0, 0x1.1794d6p0, -0x1.7f5da8p-1, 0x1.3c1ep0, -0x1.7820aap-6, -0x1.348136p0, 0x1.4b5eecp-8, -0x1.a148e8p-1, -0x1.a84294p-2, -0x1.b8b932p-1, -0x1.b0449p-2, 0x1.ed051ep0, -0x1.4b6b38p-2, 0x1.b8e8b6p0, 0x1.bbdfa4p-1, 0x1.7100fcp-1, 0x1.1208c4p0, -0x1.168cb2p0, 0x1.879858p-1, -0x1.9c511p-1, -0x1.f2b892p-2, 0x1.7ad1ep-1, -0x1.aaaabp-5, -0x1.7ddeeap0, -0x1.7024b4p-1, -0x1.d8042cp0, -0x1.bafcbp-2, 0x1.24c34p0, 0x1.72ac74p0, 0x1.2fd092p0, -0x1.bbe866p0, 0x1.67596ap0, 0x1.0918acp0, -0x1.746a6cp0, -0x1.eccb04p0, -0x1.c5608p0, -0x1.800d94p0, 0x1.c86138p0, 0x1.1e17ecp-1, -0x1.3ea4eep0, -0x1.61c9e2p0, -0x1.c60aeep0, -0x1.cb7a16p0, 0x1.35075ep0, -0x1.645f12p-1, 0x1.6e1fbp0, 0x1.542b74p-4, -0x1.801e08p0, -0x1.71983p-1, -0x1.f3f42ap0, -0x1.928bp0, -0x1.a24222p-2, -0x1.aa4f8ep-1, 0x1.5e705ap0, 0x1.8ae9a4p-1, -0x1.280bbcp-2, 0x1.c184a6p0, 0x1.b1201cp0, -0x1.d0f642p-3, 0x1.f8c312p-1, 0x1.d4c4b8p-2, 0x1.ae3522p-1, 0x1.6081p-2, 0x1.91d2c8p0, 0x1.53339p-3, -0x1.5f3958p-1, 0x1.b4f804p0, -0x1.5a2e9cp0, 0x1.c688acp-2, -0x1.10d76cp0, -0x1.38322ap0, 0x1.5ec3bep0, 0x1.dcb302p0, -0x1.871ac2p0, -0x1.77920ap0, -0x1.b7de4p0, 0x1.a128d6p-2, -0x1.c82ed4p0, -0x1.e0c4f4p0, 0x1.684e36p-1, -0x1.50187ep-1, 0x1.1f381p0, 0x1.98ed4ep-5, -0x1.0ad77ap-2, -0x1.84eb04p-2, 0x1.c18866p0, -0x1.c6890ep-3, 0x1.7cd9bep-1, 0x1.79a7bep0, 0x1.b8bdc8p-2, 0x1.fab5a4p0, -0x1.881564p0, -0x1.581c2p0, 0x1.61154cp0, -0x1.0883eep-7, 0x1.77cc3cp0, -0x1.51a69p-5, 0x1.b07cep-3, 0x1.d81218p-3, -0x1.533628p-2, 0x1.3ce44p-1, -0x1.e7745ap0, 0x1.dc3f02p0, 0x1.6e5222p0, -0x1.a72b88p0, 0x1.cfe564p0, 0x1.a1fb4ap-1, -0x1.65c7ap0, -0x1.3aac1cp-1, -0x1.3d5284p0, 0x1.e6f256p0, -0x1.f349f8p0, -0x1.3d4af8p-1, -0x1.966f5ap0, 0x1.27dea4p0, 0x1.ea596p-2, 0x1.1e83b6p0, -0x1.67877ep-1, -0x1.f893b2p-3, 0x1.37977ep-1, -0x1.d449e6p0, -0x1.ce0388p-2, 0x1.697fb8p0, -0x1.77723ap0, -0x1.4f12ap-4, -0x1.b9b426p0, 0x1.c70d08p0, 0x1.c8a58ap-3, -0x1.02e43p0, -0x1.2bfb46p0, 0x1.a05cccp-4, 0x1.acc078p0, 0x1.a1f8fap0, 0x1.0fc08ep-1, -0x1.169312p0, 0x1.03acacp0, -0x1.256112p-3, 0x1.16ec5ap-1, -0x1.55df5ep-3, -0x1.de766ep-1, 0x1.568f36p-1, -0x1.cf0fcap0, -0x1.091a2ap-1, 0x1.e8aap0, 0x1.27bfe2p0, -0x1.6bfedcp0, 0x1.1e4576p0, 0x1.d2eba4p0, -0x1.e3fd48p0, 0x1.be61b2p0, -0x1.307f92p-1, 0x1.f08064p0, 0x1.2ecc9p0, -0x1.8b1c5ap-1, 0x1.9e59ap0, 0x1.3ae6cap0, -0x1.a09436p-3, -0x1.65be6p-2, 0x1.d8d0aep0, -0x1.11c1a4p0, 0x1.4a6a8p-1, -0x1.11963cp0, 0x1.bda3f4p-1, -0x1.91e04ap-4, -0x1.2001cp0, -0x1.ae0928p-1, -0x1.3d8388p0, 0x1.86c286p-1, 0x1.03b702p-1, -0x1.29b0dap-2, 0x1.c7b86p0, -0x1.44bbdep-2, 0x1.b7efacp0, -0x1.c7d6bap0, -0x1.d45dc8p-1, -0x1.a3f5dep0, 0x1.5cb2eep0, 0x1.4dc5cap0, 0x1.51fcccp-1, 0x1.f495d2p0, -0x1.bc23d6p-3, 0x1.bd07fcp-2, 0x1.a6cc08p-2, 0x1.c4523ap-1, -0x1.fbae18p-2, -0x1.9fff46p-2, 0x1.989f3ap-2, -0x1.9bd64cp0, 0x1.2ca936p0, 0x1.2c440ap-2, 0x1.aa2d62p-1, -0x1.08718ap0, -0x1.9e0e96p0, 0x1.946194p-2, 0x1.e4f15p0, -0x1.c4cfe6p0, -0x1.1e40f6p0, -0x1.998194p-2, -0x1.74c7ep-3, -0x1.c60886p-2, 0x1.650d12p-1, 0x1.de3572p0, -0x1.b0b87ap0, -0x1.2b25d8p-1, -0x1.b31d5ap-2, 0x1.aaf312p0, -0x1.7dd70cp0, 0x1.f33706p0, 0x1.15ff4p0, -0x1.f0429p0, -0x1.65d858p0, 0x1.b3c13ap-1, -0x1.0e552p0, 0x1.aa59c8p-2, -0x1.f507b8p0, -0x1.f73b42p-2, 0x1.fa45dep-10, -0x1.3ba442p0, 0x1.52ddap0, -0x1.f5fffp-5, 0x1.412806p-1, -0x1.ebd7f2p-1, 0x1.40df84p0, -0x1.cdd88cp-1, -0x1.4cbe0ep-1, -0x1.2fe39ep0, -0x1.93706ep-1, 0x1.e93354p0, -0x1.d977cp0, 0x1.4053f6p-2, -0x1.34e39p0, 0x1.67db4ep0, -0x1.74f1fp0, 0x1.8894cap0, -0x1.0f6c7ap0, 0x1.e94ceap-7, 0x1.316f8p0, 0x1.993812p-1, 0x1.439dcp-1, -0x1.f962aep-2, -0x1.12c07cp0, -0x1.49f9f4p-1, -0x1.0ed318p-1, -0x1.9d9ddcp0, 0x1.5f03f2p-1, 0x1.2d9f52p-2, 0x1.8e8ccap0, -0x1.d79a3cp-1, -0x1.f36112p-2, -0x1.d2f77p-2, -0x1.928c4p0, 0x1.2e76dp0, 0x1.7c9e88p0, 0x1.4976fap0, 0x1.d7e60ep0, -0x1.56aa64p-2, -0x1.8b69cep0, -0x1.43dcd2p0, 0x1.6aab64p0, 0x1.0f83d8p0, -0x1.fc3222p0, -0x1.fe8552p-1, 0x1.d30ceap0, -0x1.620dd6p0, -0x1.539b44p-2, -0x1.2b9fb8p0, -0x1.2232ccp0, 0x1.980626p-3, 0x1.c6d8bp0, -0x1.e50c74p-1, 0x1.8c5d72p-1, 0x1.8346f4p0, -0x1.9d669ap-2, 0x1.e560eep0, -0x1.0b6e72p-1, -0x1.62dc5cp-1, -0x1.5f3e92p0, 0x1.62798cp-3, -0x1.57bc32p0, -0x1.4b487ep-2, 0x1.de5928p0, 0x1.9f0aa4p-5, 0x1.99aadp-2, -0x1.3bbe8cp-1, 0x1.eab82p0, -0x1.023872p0, -0x1.aebefcp-1, -0x1.cd7f54p0, 0x1.66700cp0, -0x1.093c8ep-2, 0x1.1e581cp-1, -0x1.d4ac58p-3, -0x1.ac5d26p-1, 0x1.6b19a6p-1, 0x1.e30346p0, 0x1.8e9048p-1, -0x1.ef3d7p0, -0x1.2e0014p-6, -0x1.8e3c8ep0, -0x1.485d86p-1, 0x1.d3833ap-1, -0x1.e9fbf2p-2, 0x1.0fdaa4p0, 0x1.d5d4b6p-1, 0x1.fca36ep-1, -0x1.04cfcp0, 0x1.452f1ap0, 0x1.608fdep0, 0x1.ed85c2p-5, 0x1.0846acp-6, 0x1.6bd934p-2, 0x1.5c0864p-4, 0x1.5b397ep-2, -0x1.b9cdb8p0, -0x1.a32fd8p-1, 0x1.0faf16p-1, -0x1.5e53f6p0, 0x1.d857cap0, 0x1.34b8e8p-1, -0x1.aceb28p-1, 0x1.f4476p-1, -0x1.c263bp-1, -0x1.571afp0, -0x1.f036a2p0, -0x1.2d2f02p-2, 0x1.0259ccp0, 0x1.b6fecap-2, 0x1.3cba4cp0, 0x1.a1c82p-1, 0x1.55f9b8p0, -0x1.ae47a4p-1, -0x1.e87da4p0, -0x1.787622p0, -0x1.d2d0dp0, -0x1.efb47cp0, -0x1.d53136p-1, 0x1.4c92b4p0, -0x1.17a40ap-1, 0x1.fab3aap0, -0x1.6e8dc8p-4, -0x1.b3bf68p-1, -0x1.067e82p-1, -0x1.2238bcp0, 0x1.a8e46cp0, -0x1.59149p-4, 0x1.b2d60cp-1, 0x1.421a3p0, 0x1.c6439p-1, -0x1.9914e2p-1, 0x1.3b4e18p-2, -0x1.70e37ep0, 0x1.0a0c6ap0, -0x1.532768p-1, 0x1.354956p0, -0x1.e6026ap0, -0x1.11a71p-1, -0x1.8c164ep-4, 0x1.036002p0, -0x1.1156eap-1, -0x1.e9709ep-7, -0x1.df60e4p0, 0x1.f5b5dap0, -0x1.38d084p-2, -0x1.775288p0, 0x1.d20f7ep-2, -0x1.617b3p-4, -0x1.05996ap-1, -0x1.6081cep0, -0x1.f979dep-1, 0x1.da8fc4p-3, -0x1.46f74cp-2, 0x1.24ff14p-2, 0x1.f7c14cp0, -0x1.fe7524p-2, 0x1.746b98p0, -0x1.74fcdap0, -0x1.b7bd5ap0, 0x1.c171a6p-1, -0x1.205076p0, 0x1.488b5p-1, 0x1.bf8af6p0, -0x1.dcd65ep-2, 0x1.ee5b9ap0, 0x1.6f9d16p-2, -0x1.8eacb4p0, 0x1.b03d56p-3, -0x1.23f0dap-1, -0x1.e34636p0, -0x1.e6b5fcp-4, 0x1.e4608p-1, 0x1.06d0a4p-1, 0x1.4e73p0, 0x1.0447c8p0, -0x1.827446p-4, -0x1.e5f18cp-2, 0x1.98bce2p-1, 0x1.2ec5e2p0, -0x1.d14156p-3, -0x1.315d22p-1, 0x1.43d5eep0, -0x1.04d6d4p0, -0x1.3a1dep-1, -0x1.60826cp-1, 0x1.665a5ap-1, -0x1.76b374p0, 0x1.7a6424p-2, -0x1.8f090ap0, 0x1.2142a4p-2, -0x1.f285fep0, -0x1.d3c8d6p-1, -0x1.ebb0acp0, -0x1.5a3934p0, -0x1.6b98dep0, -0x1.9380bep0, -0x1.eb2ddap-2, 0x1.cf43bep0, -0x1.c456d8p0, 0x1.15a57cp-2, 0x1.7f6a52p-1, 0x1.17640cp-4, 0x1.64861ep0, 0x1.cb2f9ap-3, 0x1.f3cf92p0, 0x1.95132ap-1, -0x1.5638c8p-1, 0x1.da3d0ap-9, 0x1.97f97ap-3, 0x1.269006p-1, -0x1.d4ef46p-5, 0x1.c22cdep-1, 0x1.b4ca7ap0, 0x1.4f94d8p0, 0x1.81335p-4, -0x1.dcbf5ap-1, -0x1.92461ap0, 0x1.0abffap-1, -0x1.a55452p0, 0x1.8e93ap0, 0x1.978358p-1, 0x1.b2817cp-8, 0x1.b8a564p-1, -0x1.a2cd34p-1, -0x1.15bc64p-3, -0x1.cf8074p-3, 0x1.7b2f5p-1, -0x1.04aabp0, -0x1.d5934p0, 0x1.293e14p0, 0x1.aba894p-1, -0x1.0c6776p-2, -0x1.a8601ap-3, 0x1.a47a68p-1, -0x1.5190e4p-2, 0x1.b0748p-1, -0x1.65cefp-3, 0x1.8fbe5cp0, -0x1.72451cp-3, -0x1.ab38eap0, -0x1.cf6942p0, -0x1.ca9edcp-1, 0x1.6c8d8p-1, -0x1.98f0e4p0, 0x1.5170cep-2, 0x1.80ae2ep0, 0x1.d37054p-4, 0x1.90d054p0, 0x1.b66edap-1, -0x1.19da18p0, 0x1.19ff0ep-1, 0x1.8b68dp-3, 0x1.537994p-1, -0x1.686bb4p0, 0x1.a81b9p-6, -0x1.0c8beap-1, 0x1.15a334p0, 0x1.2e3f4p0, 0x1.f82fc2p-3, 0x1.e1844p-2, -0x1.5b7cf4p-1, 0x1.6a36f6p-2, 0x1.8a4424p0, 0x1.cb56acp0, 0x1.47940cp0, 0x1.209172p0, 0x1.d3f8dep-3, 0x1.f63226p-1, 0x1.a29aecp0, -0x1.889082p-2, 0x1.0f5606p-2, 0x1.bd7faep-2, -0x1.7dbce8p-1, 0x1.ac0b1ap0, 0x1.314b9cp-1, -0x1.7200c8p0, 0x1.511a82p-7, -0x1.c51472p-3, -0x1.c1ba3cp-2, -0x1.54f008p0, 0x1.b6c786p0, -0x1.dfe8fcp0, 0x1.b719f4p0, 0x1.0a095ep-1, 0x1.5056eap0, -0x1.86ff72p-2, -0x1.75e6aap0, -0x1.4b5234p0, 0x1.b9e4cp0, -0x1.4df62p-10, 0x1.13a664p0, 0x1.19a156p0, 0x1.3db95ep-1, 0x1.2efefep0, -0x1.291062p0, -0x1.3781cep0, -0x1.bf2ea2p-1, -0x1.91730ep0, -0x1.622964p-2, 0x1.f8988ap0, -0x1.d8026ap-1, 0x1.11444ep0, -0x1.d9a79p0, -0x1.22d5c8p0, -0x1.6d97fep-1, 0x1.626abcp0, 0x1.95274ap-2, 0x1.4173fcp0, 0x1.618008p0, 0x1.a49244p-1, 0x1.7ea08p-5, -0x1.cdba54p-1, 0x1.569d16p0, -0x1.f81718p-2, 0x1.a3c9e8p-1, 0x1.4fabc8p0, -0x1.334a18p-1, -0x1.845106p-6, 0x1.89458ap-2, 0x1.b95fd2p-3, -0x1.981f92p0, 0x1.0abd6ep-1, -0x1.a5dc52p-1, -0x1.d8e06ap0, 0x1.4368ecp-1, -0x1.88fc9p0, 0x1.246722p0, -0x1.097368p-1, 0x1.f88918p0, 0x1.e7dcbp-1, -0x1.4f4d8ep0, -0x1.a526bcp-3, 0x1.14bba8p-2, 0x1.6d1538p0, -0x1.9b8d7p0, 0x1.c9b98p-1, -0x1.8b54bcp-1, 0x1.376992p0, -0x1.5b352ep0, 0x1.29eecep0, 0x1.6e30c6p-2, -0x1.cf3b38p0, -0x1.7c19c8p0, 0x1.ef3f0ap0, -0x1.4655f6p0, 0x1.473448p-3, -0x1.24a2bcp0, -0x1.8ae19ap-6, -0x1.b8272ap0, 0x1.00001ap0, 0x1.22e556p-3, 0x1.8c631p-1, -0x1.5620eap-1, 0x1.607e96p-2, 0x1.b3f6ep-3, -0x1.bb6e0cp-1, 0x1.d3cd66p-3, -0x1.2a660ap-3, -0x1.b7744ep0, -0x1.17c002p-4, -0x1.8943c6p-1, -0x1.3250ep-1, -0x1.b48372p0, 0x1.3024bcp0, 0x1.6ecde6p-1, -0x1.9dd07ep-1, -0x1.115f18p0, 0x1.1e5a2p-1, -0x1.19d306p0, -0x1.73aadcp0, 0x1.8ba058p-4, -0x1.cbc75cp0, 0x1.cc24b8p0, -0x1.e0713cp0, -0x1.11ff06p-1, -0x1.cba9e4p-8, -0x1.f1096ep0, -0x1.6953b2p0, 0x1.56af1cp-3, -0x1.bc0904p0, 0x1.c0f716p0, -0x1.0c10d6p-1, 0x1.d548fp-4, 0x1.2da79ap0, -0x1.b22e34p0, 0x1.5d6098p0, 0x1.b89aaep-1, 0x1.fb0bbp-1, -0x1.0e4184p0, -0x1.a5f7cp-2, 0x1.528d1ep-1, -0x1.2c7a54p-2, 0x1.e165fp0, 0x1.aa2294p0, -0x1.1eecep0, -0x1.e27e9ap0, -0x1.e9d65ap-2, -0x1.4eec1cp0, 0x1.28fb02p-3, 0x1.9c7378p0, 0x1.df6996p-1, -0x1.e74282p-3, 0x1.ac3d6ap-3, 0x1.8360c2p-1, 0x1.2dfe74p-1, -0x1.c9ee62p-1, -0x1.84ba92p-1, -0x1.d8a916p-1, -0x1.8237bcp-2, 0x1.0bea98p-3, -0x1.63245cp-1, -0x1.d492c2p0, 0x1.649d1ap-3, 0x1.df1e7ep-2, -0x1.857daep-1, 0x1.b614fep0, -0x1.02862cp-2, -0x1.ce9566p-1, 0x1.89f214p0, -0x1.d40d1ep0, -0x1.f03058p-3, 0x1.93f9e8p0, 0x1.b58b4p0, 0x1.199cd8p-1, -0x1.42e15cp0, -0x1.f28b32p-1, -0x1.31e42ap0, 0x1.9aeec2p-3, 0x1.9c5cdp-1, 0x1.61806p0, 0x1.b04238p0, -0x1.a611c2p0, -0x1.06451p-2, -0x1.7078eep-1, -0x1.8c3aeap-3, 0x1.bcce94p0, 0x1.bdc44ap-1, -0x1.f07c48p0, -0x1.b7dc02p0, -0x1.ab4548p0, 0x1.48b804p0, -0x1.9a239ep0, 0x1.49029p-2, -0x1.d902e6p-2, -0x1.823014p0, 0x1.b3d716p-1, 0x1.69e9e2p-1, 0x1.91fb9p0, 0x1.56b886p-1, -0x1.886b08p-2, 0x1.289864p0, 0x1.a01d0ep-2, -0x1.35e806p0, 0x1.55660ap0, -0x1.113f4cp0, 0x1.b3fb2ep0, -0x1.59ed7ap-1, 0x1.19d0e6p-1, -0x1.91b146p-5, 0x1.39c46ap0, 0x1.4374p0, -0x1.37104ap-1, 0x1.1088aep-1, -0x1.1687a2p0, 0x1.3b1c36p-2, -0x1.a3fe3p-3, -0x1.fee812p0, 0x1.5e1cfap-1, 0x1.47ebeap0, -0x1.e1ad48p-2, -0x1.9ffd12p0, -0x1.6733bp-3, 0x1.7a00d6p-1, -0x1.79da9ap0, 0x1.f273e2p-3, -0x1.fd947ap-4, 0x1.fc2444p-3, -0x1.fa461ep0, 0x1.fd9068p-1, 0x1.70e3cep0, 0x1.726ee2p-3, 0x1.ae357p-3, -0x1.6880f6p0, -0x1.a37bf8p-4, 0x1.5f01e8p0, -0x1.f6d836p-2, 0x1.6dfa8p-1, -0x1.39f97ap-1, 0x1.721a3cp-1, 0x1.be0bf2p-3, 0x1.b70f94p-1, 0x1.ce0592p-1, -0x1.8e6c94p-1, 0x1.409714p-1, 0x1.d15fa2p0, -0x1.2c75c4p0, 0x1.291fap-2, -0x1.a9cb02p0, 0x1.24dddap0, 0x1.61697ap-1, -0x1.86e764p-4, -0x1.79964ep0, -0x1.de70d6p-1, -0x1.0fc372p-7, -0x1.839344p-3, -0x1.c64212p0, -0x1.353b9cp0, -0x1.1de2a4p-1, 0x1.bf9504p0, 0x1.b2acdcp0, 0x1.23d326p-1, -0x1.a146d8p-2, -0x1.75d68cp0, 0x1.b343fcp-1, -0x1.6e4902p0, 0x1.7140d6p-3, -0x1.1746b2p0, -0x1.100e8cp0, -0x1.615e5ap0, 0x1.b00844p0, 0x1.2cfc92p-2, -0x1.cae48ep0, -0x1.a9f9acp-1, -0x1.2068a6p-3, 0x1.f0cdb4p0, -0x1.1e334ep-2, 0x1.ce1066p0, 0x1.19bf5ep-1, -0x1.e64138p0, -0x1.3596bcp-1, -0x1.47267ap0, -0x1.cd8cdp-3, -0x1.c5a996p0, 0x1.631a92p-1, -0x1.9065bep-1, -0x1.ae45eep-2, 0x1.173e8cp-1, -0x1.36634cp0, 0x1.605c0ep-1, 0x1.fc373cp0, 0x1.e24ffep-1, 0x1.77d8d8p-1, 0x1.5bc954p0, -0x1.50168ep-1, -0x1.1a1c94p-1, -0x1.0ac8fcp0, -0x1.4ae9a8p0, -0x1.d4387ap0, 0x1.c32d98p0, -0x1.d46a9ap0, 0x1.3e3c8ap-1, -0x1.a6c404p-1, 0x1.6b303ep-4, 0x1.f0bf96p-1, -0x1.e232dap0, -0x1.ad945ep-1, -0x1.aa031ap-5, 0x1.08db04p-1, 0x1.16c526p-1, -0x1.826ecap0, -0x1.5b77e6p0, 0x1.b0bee4p-1, 0x1.4bf732p-2, 0x1.572ad4p-1, 0x1.ac9cdp-2, 0x1.110908p-2, 0x1.2e23ep0, -0x1.577d78p0, 0x1.4c361cp-1, 0x1.04947ep0, -0x1.1945aap0, 0x1.79df86p-1, -0x1.3910dcp0, 0x1.94ba34p0, 0x1.97a2ccp-1, 0x1.21ff2ap0, -0x1.82d15cp0, 0x1.e2b0f4p-2, -0x1.03759p-1, -0x1.cf4c4ep0, 0x1.e8443p0, 0x1.5b993cp0, -0x1.4bb61cp0, -0x1.51e74ap0, 0x1.6312b4p0, -0x1.fba9bp0, 0x1.ca6944p0, 0x1.860ep-1, -0x1.6a4a0ap-1, -0x1.337c04p-1, 0x1.fe26dap-3, -0x1.59aa6cp0, 0x1.922504p-2, 0x1.019cd4p-2, 0x1.8211dap-8, 0x1.320d64p-1, -0x1.ce9362p0, -0x1.1b469ep-1, -0x1.38a0cp-3, 0x1.b29098p0, 0x1.76842p-2, -0x1.482df8p-2, -0x1.be431p0, 0x1.8066f6p-7, 0x1.7984b6p0, -0x1.3d8728p0, -0x1.b024cp-1, -0x1.0fda74p-2, 0x1.0fa736p0, -0x1.cf3fp0, -0x1.276f0ep0, 0x1.188246p0, 0x1.4c2034p0, -0x1.7703bcp-1, -0x1.5c6d86p-1, 0x1.f73bcep-3, 0x1.0d4b74p-2, -0x1.36bb62p0, 0x1.54f0f2p-1, -0x1.e09c82p-4, -0x1.929fc2p0, -0x1.4fe9ap-2, 0x1.00ec2ep0, -0x1.bc57ep0, -0x1.5906f6p-4, -0x1.78be64p-1, 0x1.dc6316p0, 0x1.b6d45ap-1, -0x1.a9a6ecp-2, -0x1.db6b96p0, 0x1.34da42p-3, 0x1.2cbba2p-1, 0x1.19f2f6p0, 0x1.076156p0, -0x1.8283ap0, -0x1.8e82bcp0, 0x1.d80b98p0, 0x1.bdfa48p-2, -0x1.4d37e2p-1, 0x1.cd70e4p-2, 0x1.cd1674p0, -0x1.bf5a34p0, -0x1.de32c2p0, 0x1.06ff18p0, 0x1.4d2e66p-1, -0x1.7abbaep-1, 0x1.fedd1p-1, -0x1.945f84p0, 0x1.a5a91p0, -0x1.a3b326p-3, 0x1.d5ed72p-3, -0x1.67c054p0, -0x1.1eb94ep0, -0x1.291eecp0, 0x1.80543p-2, -0x1.898096p0, 0x1.17f7ccp0, 0x1.d6afeap0, -0x1.c8265ap-1, -0x1.ab2becp0, 0x1.6ff4aap-1, -0x1.c6de8p-2, 0x1.2e074ep0, -0x1.8826d4p-2, -0x1.877b54p-1, -0x1.47dbcap-3, -0x1.f800f8p-4, -0x1.783686p-1, 0x1.98ea8ep-1, -0x1.0d1c98p0, 0x1.c51fd2p-1, -0x1.59f45p-2, -0x1.c8d9dap0, 0x1.ec1ad6p0, 0x1.64198ep0, 0x1.601ae6p0, 0x1.93a95p0, -0x1.01a286p0, -0x1.06301ep0, 0x1.66f1c4p-2, -0x1.e41d1cp0, 0x1.381c1cp0, -0x1.57156cp-3, 0x1.380c18p0, -0x1.e1aabcp-1, -0x1.d164eap0, 0x1.8b5e96p-1, -0x1.ea11cap0, 0x1.2e9b1cp-3, -0x1.64c244p0, -0x1.a8323p0, -0x1.7c368p0, -0x1.8b972ep-2, 0x1.de3338p-3, 0x1.5fc6d6p-1, 0x1.2d768ap0, 0x1.95c928p-1, 0x1.ea28d2p-1, 0x1.4f352ep-2, 0x1.da398p0, -0x1.7820fp0, 0x1.af47e4p0, 0x1.26f68ep0, 0x1.f7ab2p0, -0x1.e46628p0, 0x1.1de20cp-1, -0x1.b2b6c4p-2, 0x1.61bc1cp-1, -0x1.05e29ep-4, -0x1.0eb7cap0, -0x1.d4d3ccp0, -0x1.e3f996p-2, -0x1.f07feap-2, -0x1.70427ap0, -0x1.783f68p-1, -0x1.b453cap-2, 0x1.bd6f78p0, 0x1.d9bcd2p-2, -0x1.27dc2cp-1, 0x1.2cf74ep0, 0x1.c6280cp-1, 0x1.22ffc4p0, 0x1.99fa2ap0, 0x1.492accp-4, 0x1.f9c3f2p0, -0x1.8e5706p0, -0x1.f19d76p0, -0x1.020028p0, -0x1.3a9d58p0, 0x1.60b464p-1, 0x1.42bafep-2, -0x1.3b4cc8p-3, 0x1.631b92p0, -0x1.3b5ad2p0, 0x1.40542p0, -0x1.292e6ap0, 0x1.f9ab62p0, -0x1.b84bf6p-1, 0x1.a3fe34p0, -0x1.5cb2e4p-1, -0x1.e6a212p-1, 0x1.9e849ap0, -0x1.a2adaap-2, -0x1.77bed8p-1, 0x1.f2b30ap0, 0x1.ceb298p-3, -0x1.90c4dep-2, 0x1.48d1e2p0, -0x1.a9e7d2p0, 0x1.1132e4p-1, -0x1.58bdc4p0, -0x1.55a41p0, 0x1.e8e75cp-2, 0x1.bb0674p-1, 0x1.dc00f6p-3, 0x1.cb7c7cp0, 0x1.5ddb2ap-3, 0x1.dd930cp0, -0x1.347572p-3, -0x1.97afd8p0, -0x1.9fea0ep-1, -0x1.b1e6aap-1, -0x1.c8216ap-5, 0x1.34dc2ep0, 0x1.3775e2p-2, -0x1.23631ap-2, -0x1.647762p0, -0x1.8c7e42p-1, 0x1.435a12p0, -0x1.b02efp0, 0x1.b063ap-4, 0x1.e74a84p0, -0x1.632308p-3, -0x1.26a008p0, 0x1.56942p-1, 0x1.706c0ep-1, 0x1.4d9c7ep-2, -0x1.f8952ap0, 0x1.61efb8p0, 0x1.2269fcp0, -0x1.70686ap-3, -0x1.fb0812p0, -0x1.22a1dap-3, -0x1.5a0cc6p0, 0x1.c62296p0, 0x1.0ba628p0, 0x1.ebca26p-1, -0x1.81f09p-4, -0x1.a7ada6p-1, -0x1.a0ee1ep-1, -0x1.40e788p0, -0x1.37f32ep-2, -0x1.792a76p0, 0x1.9f8794p0, -0x1.e98adap-1, -0x1.a5617ap0, 0x1.54fb74p-7, -0x1.ee859ep-2, 0x1.19c132p-1, 0x1.0d857cp0, 0x1.969dbap-1, 0x1.0cb60cp-1, 0x1.13c29ap0, -0x1.57504cp0, 0x1.677448p-1, -0x1.fa7f3p-1, -0x1.48236ap-3, -0x1.482e32p-2, 0x1.a2f534p-2, -0x1.37b724p0, 0x1.e21058p0, -0x1.97e80ap0, -0x1.bcb0eap0, -0x1.69699ep-1, -0x1.a19b7ap-2, -0x1.ef891cp-4, -0x1.de091ap-4, 0x1.9063f4p-3, -0x1.8b15c2p-1, 0x1.21f844p0, 0x1.76ce2cp-2, 0x1.f7e474p0, 0x1.7adeaep-3, -0x1.1be8dep-1, 0x1.4e90e8p0, 0x1.6e9eaap0, -0x1.bf13c4p0, -0x1.f67e3ap-2, 0x1.49620ep-3, -0x1.b176fap0, 0x1.fe6adep0, -0x1.9a9edcp-1, 0x1.28f7bp-4, 0x1.f09a3p0, -0x1.91bc08p0, -0x1.84eab2p0, -0x1.739158p-1, -0x1.0e4b6p-2, -0x1.382036p-1, 0x1.26b8acp-3, 0x1.da0c5ep0, 0x1.1bdf8p0, -0x1.449c86p-4, 0x1.304dbep-4, -0x1.436d94p0, -0x1.4ec2eep0, -0x1.51c12p-1, -0x1.9ee8a4p0, 0x1.25768cp0, -0x1.2ae8d4p0, 0x1.ff2d72p-1, 0x1.153634p-1, -0x1.1d717ap-1, -0x1.7e5d28p-2, -0x1.7fcdfcp-1, 0x1.e4b77p0, -0x1.592abcp0, 0x1.578918p-1, -0x1.051c5cp0, -0x1.20746p-1, -0x1.28e0f8p0, -0x1.875054p0, -0x1.2ae264p0, 0x1.b4489cp-1, 0x1.c8b5bep-1, -0x1.24548p0, 0x1.f64ea8p0, -0x1.499578p0, 0x1.006ddp0, -0x1.f123a8p-4, 0x1.09b156p0, 0x1.083544p-1, -0x1.c074f4p0, 0x1.15d584p-2, -0x1.ec476ap-1, -0x1.2cf56cp0, 0x1.1fe4ap-1, 0x1.8ccff4p0, 0x1.0b23e4p0, 0x1.a717d8p-3, -0x1.fd93aap-3, 0x1.955e1ep0, 0x1.869afap0, 0x1.a891f4p0, 0x1.dd92f8p0, -0x1.460842p0, 0x1.e5655cp0, -0x1.be0aecp-1, -0x1.8ec982p0, -0x1.6e0ceap0, 0x1.f09796p-1, -0x1.8ee8ep-2, 0x1.69423ep-2, 0x1.b9429p-4, -0x1.7595ep0, -0x1.cf7666p-1, 0x1.0b9aap-1, -0x1.4ab33ep-2, 0x1.4ed906p-1, 0x1.318e34p-1, -0x1.e7d302p-1, -0x1.3941dep0, 0x1.22dcecp-2, -0x1.d3f4a8p0, -0x1.070118p0, 0x1.73852ep0, -0x1.4d8de8p-2, 0x1.ec116p-1, 0x1.d78556p0, 0x1.e02b8ep0, 0x1.cd50c2p-2, 0x1.4c4ccap-1, -0x1.8b6b9p-2, 0x1.d409aep0, -0x1.700ad2p0, 0x1.750052p-2, -0x1.c7bb86p0, -0x1.bb9dcep-3, -0x1.261bcp-2, -0x1.56d122p-1, 0x1.0a3524p0, -0x1.dacc1p0, -0x1.6faee4p0, 0x1.d1d71ep0, 0x1.079cep-2, -0x1.bd62bap-4, 0x1.9ac67cp0, -0x1.8aa15cp-1, -0x1.5db4dp-1, 0x1.34c2dp-2, 0x1.7426a2p0, -0x1.0e1a2ep0, 0x1.bb6c06p-2, -0x1.f8eb8cp-2, 0x1.30829p-2, -0x1.f23276p-1, -0x1.d25ea4p-6, -0x1.28fae2p0, 0x1.c707aep0, -0x1.907774p0, -0x1.29a78p-2, -0x1.db50f8p0, 0x1.48580ep0, -0x1.548ad6p-5, -0x1.b32aa4p0, -0x1.2bbd8p0, 0x1.48b7e8p-2, -0x1.2af01ep0, 0x1.9734d4p-1, -0x1.cc431ap-2, 0x1.3a5156p0, -0x1.80cf6ep-2, 0x1.277092p0, -0x1.6489d8p-1, -0x1.7e198ap0, -0x1.d535aap-1, 0x1.188c44p0, 0x1.5bb046p-4, 0x1.671cf2p0, -0x1.201f2ep-3, 0x1.b54ccap0, 0x1.e12206p-2, -0x1.2531b6p0, -0x1.54a5f8p-4, -0x1.389afcp-4, 0x1.62114ep-1, 0x1.c37fep0, -0x1.4d5d88p0, 0x1.813544p0, -0x1.e4d638p0, -0x1.16fe16p-1, -0x1.c53368p-10, 0x1.a51858p-2, -0x1.40631ap0, -0x1.6b8162p-1, -0x1.51a514p0, 0x1.ece488p0, 0x1.6381b6p-3, -0x1.38f01ap0, 0x1.35f954p-1, 0x1.bf0ebcp0, -0x1.936994p0, -0x1.909d02p-5, -0x1.96c1f2p0, -0x1.647bacp-5, 0x1.839168p-1, -0x1.b74196p0, 0x1.0ebaf8p-2, -0x1.25bc4p-3, 0x1.8832a2p-1, -0x1.424e2cp-1, -0x1.f97622p0, 0x1.e777ep0, -0x1.960af6p0, -0x1.30da44p0, -0x1.257892p-1, -0x1.624428p-1, 0x1.49375cp0, 0x1.251aep0, -0x1.27f8ep0, -0x1.3f1c54p-1, -0x1.f8ea44p0, -0x1.00a504p-3, -0x1.867f54p-1, 0x1.7d95a4p0, -0x1.62bb4ep-1, 0x1.0af088p-2, -0x1.82f67cp0, -0x1.6cba12p0, 0x1.f0273ep0, -0x1.ad1a96p0, 0x1.16656ap0, 0x1.a1ab3ep-1, 0x1.76b3fcp0, -0x1.82dc3ep-2, -0x1.decb8cp-1, 0x1.d03edap0, -0x1.cd3ccp-2, -0x1.2fa1f8p-1, 0x1.171c8cp0, -0x1.9f946ep-1, -0x1.6474a2p0, -0x1.ce3376p-2, -0x1.691548p-1, -0x1.4f94b2p0, 0x1.17d6c6p-1, 0x1.8d681p0, 0x1.356528p0, -0x1.4d7852p0, 0x1.c0cc4ap0, -0x1.9effb2p-1, -0x1.9a84c2p0, -0x1.563a5p-6, -0x1.907868p0, -0x1.9d2e8cp0, 0x1.a483f8p0, 0x1.949d22p-1, 0x1.9c5528p0, -0x1.43340ep0, -0x1.dd301cp0, -0x1.5f0368p-1, 0x1.eb442ap-1, 0x1.51ea7cp0, -0x1.ef5adap0, -0x1.e54644p0, 0x1.81404ap0, 0x1.d0fe9ep0, 0x1.3e244ep0, 0x1.72bdfp-3, 0x1.e91956p0, 0x1.54cb4ap0, -0x1.4d9a88p-3, 0x1.9dfb86p0, -0x1.3cec3ep0, 0x1.fa816ap0, 0x1.139586p0, -0x1.209856p-2, 0x1.4251aep0, -0x1.6affaep-1, 0x1.61a5bep0, 0x1.65ba9p0, -0x1.349b66p-2, 0x1.e63754p0, -0x1.7a7788p0, -0x1.6fb74p-3, -0x1.cbb972p0, -0x1.7133d8p0, -0x1.655082p0, -0x1.7d42c2p0, -0x1.72e3e6p0, -0x1.c2cf72p0, 0x1.f6d352p-1, -0x1.a1ebe4p0, -0x1.80b592p0, -0x1.5d5c58p-1, 0x1.239efep-1, -0x1.54357cp-2, 0x1.eaac06p-4, 0x1.b42782p-3, 0x1.33p-2, -0x1.673854p0, -0x1.116442p0, 0x1.11fd14p-2, -0x1.8a23eap0, -0x1.c3d54cp-2, -0x1.f92ef8p-1, -0x1.8b4a5ap0, 0x1.b9ec3cp0, 0x1.94092p0, -0x1.d09df4p0, 0x1.4c45ap0, -0x1.ac622cp-1, 0x1.703832p-3, 0x1.ba2868p-1, -0x1.3c2772p0, -0x1.b60dbap-1, -0x1.1d293p-2, -0x1.3951b4p0, 0x1.d4417p0, -0x1.3b7a58p-2, -0x1.ecf856p-3, -0x1.1ab744p-2, 0x1.ac4edep0, 0x1.abd64cp-1, -0x1.dffd3ap0, -0x1.e66408p-1, 0x1.34b7cap-1, -0x1.90f4p0, 0x1.100aa4p-1, -0x1.b416b8p0, -0x1.bd6be4p-5, -0x1.bd2becp0, 0x1.220624p-1, 0x1.4c5494p0, 0x1.520de8p-1, -0x1.04c71ap-1, -0x1.8f40fep-1, 0x1.2bdac6p-1, 0x1.7370c4p0, 0x1.096c56p0, 0x1.17bc02p0, -0x1.a706acp0, 0x1.6bd448p-1, -0x1.64744p0, 0x1.a2a1cap-1, 0x1.296876p0, 0x1.ad4c7cp-1, -0x1.311e8ap0, 0x1.db98fep0, 0x1.339572p0, -0x1.ec8678p0, -0x1.cdda5ap0, -0x1.d8055cp0, -0x1.3a5402p0, 0x1.72a636p-1, -0x1.24611cp-3, 0x1.3a71b4p0, -0x1.03c2e8p0, 0x1.dc126p-1, 0x1.d5293ap-4, 0x1.2fa958p-1, -0x1.929982p0, -0x1.25ef36p0, -0x1.e9c15ep0, -0x1.443dp0, -0x1.4abb42p0, 0x1.b2e892p-1, -0x1.f0edd4p-2, -0x1.2282b2p-2, 0x1.dd763ep-2, -0x1.686daap0, -0x1.dbdbe6p0, 0x1.c1ca3ap0, -0x1.72522cp0, -0x1.6cf042p0, 0x1.b41bbap-1, -0x1.95ffeep0, -0x1.1667b4p0, -0x1.a0a9bap0, 0x1.744f84p-1, 0x1.6946d4p0, -0x1.16c36ep0, 0x1.f667d4p0, 0x1.06aa8ap0, 0x1.945fcp-3, 0x1.cf2ba6p0, -0x1.06c338p0, -0x1.d90912p-1, 0x1.e3710cp0, 0x1.a67bf6p-1, 0x1.0d412cp-1, 0x1.5d8bc2p0, -0x1.946e04p0, -0x1.e666cp-1, -0x1.65ae26p-1, -0x1.ab41c8p-1, 0x1.767824p-3, -0x1.d82622p0, -0x1.c0e88p0, 0x1.fb78d2p-1, -0x1.c531c4p-1, -0x1.f45c44p0, 0x1.f1251p-3, -0x1.31aa9p-3, -0x1.e6148ep0, 0x1.d14edcp0, -0x1.6cd3a4p0, 0x1.028856p0, 0x1.25706ap0, -0x1.0f005ep-2, 0x1.549f1cp-1, -0x1.23b85cp0, -0x1.dbdfdap0, -0x1.e353e4p-4, -0x1.041f1cp0, 0x1.85d5dap0, 0x1.6a23cap-1, -0x1.6eee3cp0, 0x1.402584p-1, 0x1.bfc57ep-3, -0x1.86e452p0, 0x1.b3c592p0, 0x1.069be2p0, -0x1.4873dp-1, -0x1.8f142ap-1, 0x1.ca3978p-2, -0x1.32f5dap0, -0x1.681172p0, 0x1.795c9ap-2, 0x1.2805ccp0, -0x1.e5a57p-2, -0x1.5fc808p-1, -0x1.7be674p-2, -0x1.3368a6p-4, 0x1.77acf4p0, -0x1.d5dcd4p0, 0x1.216c9ap0, 0x1.8eb33ap-1, -0x1.bcf9dap-1, 0x1.8aa7b2p0, -0x1.8d4724p-1, -0x1.7ea3d8p0, 0x1.70993p0, 0x1.15e434p-1, 0x1.74a034p0, 0x1.1440b4p0, 0x1.68ef88p0, -0x1.2cc362p0, -0x1.147a4ap0, -0x1.91b7c8p-6, 0x1.6a89b6p0, -0x1.691d6ep0, 0x1.f34be4p0, -0x1.ee1518p0, -0x1.49debp0, -0x1.c96a0ep0, 0x1.f21d0ep-1, -0x1.4045f6p0, -0x1.7707dep0, 0x1.5d545cp-2, -0x1.468ab4p0, -0x1.b52048p-1, -0x1.1edb4ep0, -0x1.07017cp-1, -0x1.56444p0, -0x1.9b5cecp0, -0x1.13bfdcp0, -0x1.f15dbcp0, -0x1.61d94p-1, -0x1.848b0ap0, -0x1.9d1544p0, -0x1.657ee8p-1, 0x1.fa1976p0, -0x1.a4e6bep-7, 0x1.c4667ap-1, 0x1.a4a3p-1, -0x1.67b962p0, -0x1.ca236cp-2, 0x1.de8bbep0, 0x1.2af612p0, -0x1.96df8cp0, 0x1.888944p-4, 0x1.13edap0, -0x1.45ba8ap-1, -0x1.829c04p-1, -0x1.10ae34p0, -0x1.0e0572p-1, 0x1.b24e4p0, -0x1.75db2cp-2, 0x1.5e3facp-3, -0x1.0b3d36p-1, 0x1.646eep-1, 0x1.fafc7cp0, 0x1.ef4d9ep-1, 0x1.8482dcp0, -0x1.7304f6p-2, 0x1.cc92b8p-1, 0x1.88217p-2, 0x1.4d1f4ep-1, -0x1.c32c42p-1, -0x1.fe0daep-4, 0x1.7da05cp0, 0x1.7d4efcp0, -0x1.5a4084p0, 0x1.3a5f8ap-2, -0x1.50a112p0, -0x1.afec4p0, -0x1.e34ca6p-1, -0x1.6d20a6p0, -0x1.3e5a8cp0, -0x1.8321eap0, -0x1.c1698ap0, 0x1.be39e4p0, -0x1.6ef894p-2, -0x1.0ace2p-1, -0x1.3674c8p-1, 0x1.642108p0, -0x1.e07538p-2, 0x1.6a4876p0, -0x1.88d6dap0, -0x1.07b1d8p-1, -0x1.3ef3b4p0, 0x1.3c9b78p0, 0x1.38e5e4p0, 0x1.901ff2p0, 0x1.e14662p-2, 0x1.001a9ep0, 0x1.92ad0ap-1, 0x1.dd758p0, -0x1.9911e4p-1, -0x1.83604ep-2, 0x1.8abf2cp-3, -0x1.832a16p0, -0x1.ac1474p0, -0x1.178a22p-1, 0x1.d9eaacp0, 0x1.8d3e56p0, 0x1.a46058p0, -0x1.cde71ep-2, -0x1.432f64p0, -0x1.92e60cp0, 0x1.a60172p0, -0x1.96f666p-2, 0x1.db33d2p0, 0x1.84643ep0, 0x1.12dd1p-1, 0x1.4ca4ccp-1, 0x1.5c361ap-1, -0x1.b4bd96p0, -0x1.60399ep-3, -0x1.4f8fecp0, 0x1.f160d8p-2, -0x1.7dc648p-1, -0x1.98438ap-2, -0x1.66ba64p-1, -0x1.a9e412p-1, 0x1.0a0f2cp-3, -0x1.6b155ep0, 0x1.af6336p0, -0x1.6a028ep0, -0x1.dfc60cp0, -0x1.9de9d6p0, -0x1.be8782p-4, -0x1.b88ea6p-1, -0x1.f7a6c8p0, 0x1.9ce74cp0, -0x1.be912cp-1, 0x1.2f3a92p0, -0x1.14f7e4p0, -0x1.1b3ad8p0, 0x1.d979e2p0, 0x1.f0a258p-1, -0x1.5e35f2p-5, 0x1.12dc4cp-3, 0x1.e8fd5cp0, 0x1.83d4c6p-6, 0x1.284302p0, 0x1.4fd064p0, -0x1.5d3a4cp0, -0x1.6badc8p0, -0x1.cf47dap-2, 0x1.08aedap-3, 0x1.b1d53ep-3, 0x1.fbd8p-1, 0x1.f2e19ap0, 0x1.36468p-1, 0x1.825d9ap0, 0x1.5dbebp-1, -0x1.ce8a74p0, 0x1.f08da4p0, 0x1.b37c54p-2, -0x1.d2cea8p-1, 0x1.ce4946p0, 0x1.ebe386p-2, 0x1.f35c84p0, -0x1.7f4ce2p0, -0x1.60e3f4p-3, -0x1.58ad64p-4, 0x1.661aaap-2, -0x1.0bf8cap0, 0x1.b40bb8p0, 0x1.d3491ep0, -0x1.c38d6ep-1, -0x1.2bb15ep-2, 0x1.1eb3aep-1, 0x1.29ec7p0, -0x1.4022p-1, 0x1.e6e782p0, -0x1.1b0ab8p0, -0x1.3695fcp0, -0x1.60d88ep0, 0x1.24196p0, -0x1.2d431cp-1, -0x1.f00faap0, 0x1.f2eee6p-5, -0x1.006d98p0, 0x1.90d968p0, -0x1.bef482p-1, -0x1.6d168ep-1, 0x1.9f4bd6p0, 0x1.4b0b3ap-2, -0x1.c5c5bcp-1, -0x1.8b0fa6p-2, 0x1.7e57bp-1, -0x1.54f5a6p-1, 0x1.3a541p-2, 0x1.e2cfb8p0, -0x1.898b78p0, 0x1.9463acp-1, -0x1.618fc6p-1, 0x1.386254p0, -0x1.8c17c4p-3, 0x1.268996p0, 0x1.597adp0, -0x1.e92c8cp0, -0x1.2180d4p-1, 0x1.926ddcp-1, 0x1.4eb65p0, 0x1.f47712p-1, -0x1.7baabp0, -0x1.4b6154p-1, 0x1.1ff14ap0, 0x1.fa82fp0, -0x1.ba067ap-1, 0x1.fb55bcp-1, -0x1.623e42p0, -0x1.2bd42p-2, 0x1.dab9f4p-1, 0x1.4052dcp-2, -0x1.e7a0bcp-4, -0x1.e8d734p-1, 0x1.520106p0, -0x1.cf1152p-3, -0x1.b262a4p-2, -0x1.9bd084p0, -0x1.f0679cp-1, 0x1.c44202p-1, 0x1.d4cc6ap0, -0x1.d668p0, 0x1.ae645p0, -0x1.f9cfa8p0, -0x1.0f4dbap0, 0x1.9bc4e4p0, 0x1.694476p0, 0x1.a9c4d6p0, -0x1.186b44p0, -0x1.81131p0, -0x1.f24ddep0, 0x1.ec0864p0, 0x1.d088aap-3, -0x1.438c9cp-1, -0x1.05ee12p0, -0x1.a08d8ap0, -0x1.7f325p-1, -0x1.fe5264p-3, 0x1.7210f6p0, -0x1.76e10ap0, -0x1.44c626p0, 0x1.278378p0, 0x1.f5605p0, 0x1.60ce0ep0, -0x1.927f3cp0, 0x1.b59df2p0, -0x1.ecd7b2p0, -0x1.ad8a44p0, 0x1.f9bd5ap-2, 0x1.8cee94p-1, 0x1.9b694ep0, 0x1.12e32cp0, -0x1.a3a1fep0, 0x1.ac0cfep-1, 0x1.594f7ep-1, 0x1.458714p0, -0x1.ffb406p0, -0x1.e5203ep0, 0x1.624b7ep0, -0x1.5efd3ap0, -0x1.5aae4ap0, -0x1.96a286p0, -0x1.3e403p0, -0x1.4e11aep0, -0x1.ffe596p0, 0x1.c96a96p0, 0x1.375988p0, -0x1.13d832p0, -0x1.4d631cp-1, -0x1.90b202p-1, 0x1.e9b02ap-2, -0x1.efbc3ep0, -0x1.c79d06p0, 0x1.829f4ap-1, -0x1.24b602p-1, 0x1.b48e42p-1, 0x1.fce396p-1, -0x1.7026cep0, -0x1.319132p0, -0x1.af7656p-2, 0x1.9680d2p0, 0x1.f28da4p-3, 0x1.2d37acp0, -0x1.815ecap-1, -0x1.10267p-1, -0x1.94dcecp0, -0x1.5e48d4p-1, -0x1.cc0dd8p0, -0x1.d6ab2p0, -0x1.97b906p0, -0x1.fafcd4p-1, -0x1.8727c2p-2, 0x1.1defd8p-1, 0x1.94c908p0, -0x1.5a9634p0, 0x1.8cdbd4p0, 0x1.9a5a44p-2, -0x1.236cf8p-1, -0x1.6d7dbcp-1, -0x1.3f4cccp0, -0x1.ccd892p-2, 0x1.556182p-1, -0x1.a469c8p0, -0x1.9356b4p0, -0x1.375e7p-1, -0x1.a688a8p0, -0x1.a5ec5p-3, 0x1.fc609ap0, 0x1.5bf7ccp-1, 0x1.0fca38p-1, -0x1.66e34p0, -0x1.ab573p-2, -0x1.ee717cp0, 0x1.cd42acp-9, 0x1.2480d4p0, 0x1.775054p-2, 0x1.0a0498p-3, -0x1.9b1282p-3, -0x1.441df8p0, 0x1.8858a8p0, -0x1.6e3f1cp0, 0x1.a86bbp0, -0x1.c1fa7ep-1, 0x1.9f4c02p-2, 0x1.11322ap0, 0x1.866d26p0, 0x1.a16954p-5, -0x1.c38dep0, -0x1.4176fep0, 0x1.1c3516p-3, 0x1.9fe2d4p0, 0x1.c0f0e6p-1, 0x1.1fa92p-3, -0x1.0dbb4cp0, 0x1.6522c8p-1, -0x1.b226c4p0, -0x1.ff6c9ep0, -0x1.592234p0, 0x1.7c1f2ep0, -0x1.32250ap-2, -0x1.2fe59ep0, 0x1.19ba98p0, -0x1.596bb2p0, -0x1.6f8be6p-1, -0x1.96e5a4p0, 0x1.63b8e8p-2, -0x1.13535ep0, 0x1.d67684p0, -0x1.11bd2p0, 0x1.39483ep0, 0x1.23cd7cp-2, -0x1.307554p0, -0x1.960c38p-2, 0x1.0639b8p0, -0x1.9fddd8p-2, -0x1.90aadp0, -0x1.0affb6p-1, 0x1.dedd5ap-1, -0x1.937ed8p0, 0x1.296e3ep0, -0x1.d42946p0, 0x1.e1e45ep0, 0x1.89c8dcp0, -0x1.403308p0, 0x1.c2aae6p-1, -0x1.9dc098p-1, -0x1.283e3ap0, -0x1.506826p-3, 0x1.d97bfap0, 0x1.8a8feap0, 0x1.e4aa4cp0, -0x1.360782p-1, -0x1.06a624p0, 0x1.829f58p-2, 0x1.1d65f2p0, -0x1.d72c12p-2, -0x1.683d22p-1, -0x1.9ce136p-1, -0x1.dab1fp-1, -0x1.f78ec8p-3, 0x1.65fef2p-6, 0x1.54419p-1, -0x1.d9ea9ep-1, 0x1.a46b64p-1, -0x1.02c678p0, -0x1.c453ap0, -0x1.34eb26p-2, -0x1.22209ep-3, 0x1.a0ac18p-1, 0x1.0569e6p-3, 0x1.305d8ep0, -0x1.e27b1cp0, -0x1.d81b32p0, 0x1.0f58cp0, 0x1.fa75b8p0, 0x1.c8cdcep-2, -0x1.372be4p0, 0x1.4007ccp-2, 0x1.452818p-3, -0x1.11c2dep0, -0x1.b026bcp0, -0x1.c26cc8p0, -0x1.010bdep0, -0x1.91aa6ap-1, 0x1.a345fap0, -0x1.84e46ap-5, -0x1.f03472p-2, -0x1.fc1f06p0, -0x1.c63f0ep-6, 0x1.6f1f48p-1, 0x1.fd039ep0, -0x1.230448p-1, 0x1.0ade78p-4, 0x1.df5fbcp0, 0x1.555e8p-2, -0x1.3b2ec6p0, -0x1.b7e0f2p0, 0x1.0cb732p0, -0x1.abc94ep-1, 0x1.983734p0, -0x1.41986cp-2, -0x1.0c4606p-5, 0x1.be6a06p0, -0x1.01eb08p-6, -0x1.1d535ep0, 0x1.aab234p0, -0x1.a937aep-1, -0x1.2ea43ep-10, 0x1.503434p0, 0x1.3d1ef8p0, -0x1.bb7b08p0, 0x1.bb976p-2, -0x1.17153ep-1, 0x1.edd456p-1, 0x1.e4c87p0, 0x1.021922p-2, -0x1.cb6944p0, -0x1.327c8cp-2, 0x1.515a72p-1, -0x1.f353dap-1, -0x1.ef7af8p-2, -0x1.098d6ap-1, 0x1.4d0f6ep-1, -0x1.1093e6p0, 0x1.f4d864p0, 0x1.5fda0cp0, -0x1.6787ecp0, -0x1.995ab2p-2, 0x1.175106p0, 0x1.17149ep-1, -0x1.6150b2p0, -0x1.2ad9a4p0, 0x1.6dd376p0, 0x1.f0d81cp0, -0x1.20ad76p-2, 0x1.7aa86ap-2, -0x1.5b1dacp0, 0x1.feacb6p0, -0x1.1904eap0, -0x1.1887cap-2, 0x1.6d1902p0, 0x1.d9fa1ep0, 0x1.00e318p-2, 0x1.e6267cp-1, 0x1.f29646p-4, -0x1.b4819ep0, -0x1.76756ep-3, -0x1.bb761ep0, -0x1.0c17f2p-1, -0x1.6c217p0, -0x1.bcb478p-2, -0x1.be5a7ap-4, 0x1.3a657cp-1, 0x1.01f034p0, 0x1.f3c314p0, -0x1.fa0d9ap-2, -0x1.d18f74p-6, -0x1.b9f356p0, -0x1.95ec54p0, 0x1.b38038p0, -0x1.77d4bp-1, -0x1.12749ep-2, -0x1.d92b88p-1, 0x1.b99b4cp-5, -0x1.06f292p-1, -0x1.8913f8p0, -0x1.b792a8p-2, 0x1.6fb6c2p0, -0x1.088958p0, -0x1.b85b7p0, 0x1.01786ep0, 0x1.8f1e5ep-2, -0x1.149d56p-1, 0x1.7f5d06p-1, -0x1.c28c7p0, -0x1.69e3ep-5, -0x1.341a4ap0, -0x1.9a51b4p-1, -0x1.cb708ap0, -0x1.7f0534p0, 0x1.6052b2p-2, 0x1.622a1cp0, -0x1.2162fp-1, -0x1.ee1c88p-2, 0x1.5a02f4p0, 0x1.77ec82p-1, -0x1.de7f58p-1, 0x1.228ccep-1, -0x1.d63674p-1, -0x1.9bc52cp-2, 0x1.0300cap0, -0x1.a7df7cp0, 0x1.17224ep-1, -0x1.2990ccp0, -0x1.57defap-4, -0x1.6cda5cp0, 0x1.5f9526p-4, 0x1.c5dcb2p-1, 0x1.d7735p0, 0x1.a103dap0, 0x1.ad77fep0, -0x1.1a2a12p0, 0x1.1fa12p-4, 0x1.9a2faap-4, -0x1.40b808p0, -0x1.b886b4p0, 0x1.bf736p-1, -0x1.dde278p0, -0x1.f5555cp0, -0x1.d2c544p0, -0x1.0f93e8p0, 0x1.ab4d66p0, -0x1.6b889ap-1, 0x1.cfd2a6p-2, -0x1.97384ep-6, -0x1.6f1d6cp-3, -0x1.ce611cp0, 0x1.991b4cp0, 0x1.9d124cp0, -0x1.35cd6p-3, -0x1.941018p0, -0x1.9b98bcp-3, 0x1.18ca2p0, -0x1.67b3e2p0, 0x1.dc5aa8p-1, 0x1.68fc48p0, 0x1.08af5p-2, -0x1.dd6aaep0, -0x1.e7a99p0, -0x1.32fb8ap0, 0x1.9f5214p-5, -0x1.00c0a2p-3, -0x1.fc7f36p0, -0x1.ce517p0, -0x1.cf3c7cp-1, -0x1.dd69c6p-1, 0x1.a9d426p-6, -0x1.dd7dbp0, 0x1.daf5eep0, -0x1.4501b8p-3, 0x1.aba4bap0, 0x1.1a126ap0, -0x1.684b7cp-1, 0x1.ea83e2p0, -0x1.d30c8ap0, -0x1.43ad7ap-1, 0x1.ab2a72p-2, -0x1.d40136p-1, -0x1.ff4634p-1, -0x1.8f7d7ep0, 0x1.e9952ap-4, 0x1.d3fa9cp-1, 0x1.c48204p0, -0x1.6c779cp-1, -0x1.c7ffp-1, 0x1.59d05ap0, 0x1.b82c14p0, 0x1.abf91cp-1, 0x1.b96836p0, 0x1.f0b354p0, 0x1.9692b8p0, -0x1.56a99ap-1, -0x1.e3da58p0, -0x1.03f182p-1, -0x1.5885a2p-2, -0x1.d8f564p-1, 0x1.293508p-1, -0x1.daf166p-1, 0x1.b79958p-2, -0x1.7f405cp0, 0x1.858084p0, -0x1.5a330ep-6, 0x1.283046p-1, -0x1.39ed28p-2, -0x1.efbc32p0, 0x1.fff624p0, -0x1.3f44e6p-4, -0x1.57914ep-1, -0x1.5a7bc8p-2, 0x1.e692d8p-2, 0x1.910e1p-2, -0x1.2c6dbcp0, 0x1.3dca64p-6, -0x1.51eb7cp-1, 0x1.61ec9ep-1, 0x1.d397dp0, -0x1.55bb66p0, -0x1.2d328ep0, 0x1.bc417cp-2, 0x1.6bfed6p0, 0x1.ad4cd6p0, 0x1.aaa376p-1, 0x1.811ea6p-1, -0x1.5b0838p-2, 0x1.b8c1c2p0, -0x1.e68ce8p-2, -0x1.a51076p-5, 0x1.3059acp-2, -0x1.717a68p-2, -0x1.58c456p0, 0x1.7e29ccp-1, 0x1.32e0f4p-4, -0x1.b85236p-6, 0x1.ba61bep0, -0x1.4d315p0, -0x1.c7f622p-6, 0x1.595b62p-1, -0x1.3a76f8p0, -0x1.e50544p-3, -0x1.e514bcp-1, -0x1.e0a478p-2, -0x1.f06dfp0, -0x1.b1fba2p0, 0x1.afd014p0, -0x1.81364ap-1, 0x1.799f86p-3, 0x1.6ff852p-4, -0x1.4f397cp0, -0x1.7907cp-1, 0x1.d49b1cp0, -0x1.6c77dp0, -0x1.86e2ccp0, -0x1.e7ff78p0, -0x1.01c904p0, -0x1.90d42p0, 0x1.8969ccp0, -0x1.8bb0a8p-1, -0x1.3783ccp0, -0x1.d58afep-1, -0x1.b95f9ep-1, -0x1.d230c2p-1, -0x1.6e04bp0, -0x1.9e8e0ap0, -0x1.c78a66p0, 0x1.2e282ap0, -0x1.df2642p0, 0x1.94c4c2p-2, -0x1.3ad444p-2, -0x1.e0c612p-3, -0x1.0ef938p0, -0x1.19e1d6p-1, -0x1.370f0ap0, -0x1.bcbdcp0, 0x1.cbab9ap0, -0x1.cdd476p-3, 0x1.f50338p-1, -0x1.a4557ep-3, -0x1.379fdcp-3, 0x1.1b9da4p-1, 0x1.e053ap-3, 0x1.3d75bcp0, 0x1.b30806p0, 0x1.8f6b72p0, -0x1.bf693p0, 0x1.7181bep0, -0x1.5507a2p-1, -0x1.6e63a8p-3, 0x1.783476p0, 0x1.7741aep-1, -0x1.ae8bbep0, 0x1.d8ee8p-2, 0x1.b204b8p0, 0x1.97b7fap-4, 0x1.ab1c8ap-3, 0x1.68844p-1, -0x1.62dab2p-4, -0x1.3f3f7cp0, 0x1.6ce96ep-3, 0x1.b59f72p-1, 0x1.d74a4ep0, 0x1.1c69cp0, -0x1.b4365p-2, 0x1.b1ad34p0, 0x1.c68392p0, 0x1.1c48e4p0, 0x1.84d118p-1, 0x1.c965eep-1, 0x1.594eecp-2, 0x1.9013b6p0, 0x1.5e4aa6p0, 0x1.85760cp0, -0x1.f9ed8ep-2, -0x1.dc7648p0, -0x1.46cf3cp-1, 0x1.25535ap0, -0x1.f10242p-1, 0x1.9149d2p0, 0x1.f7d5d8p-4, 0x1.421eep0, -0x1.6301bcp0, 0x1.82ac2ap0, 0x1.fa08bep-5, -0x1.6fdb56p0, -0x1.afda14p-1, -0x1.50122p-2, 0x1.e7779ap-2, 0x1.08b466p-3, 0x1.f41aeep0, -0x1.4abd0ep-1, 0x1.6940f8p-1, 0x1.72034ep-6, -0x1.90ff7ep-2, 0x1.aa6ef8p-3, -0x1.4778ep-3, 0x1.5f5076p0, 0x1.6192p-1, -0x1.d44d64p0, -0x1.504dd6p0, 0x1.dbd63p-2, -0x1.e4f2fap-2, 0x1.888a06p0, 0x1.b6c458p-1, 0x1.1475a2p0, -0x1.47a074p-1, -0x1.506c82p0, 0x1.990daap-2, 0x1.b91f3ap0, 0x1.113bfp0, -0x1.e3cb2p0, -0x1.58d788p0, 0x1.95b49cp-1, 0x1.f657dcp-1, 0x1.76f31p0, -0x1.a87a9ep-4, -0x1.42eaf8p0, 0x1.1c8242p0, 0x1.95f8f2p0, -0x1.6d5f2ap0, -0x1.bd8cfep0, 0x1.06ff34p0, 0x1.b4fdd4p0, -0x1.868d66p-1, -0x1.107f52p0, 0x1.7dcc78p0, -0x1.e7be64p-1, -0x1.371a28p0, -0x1.9f3c4cp-1, -0x1.9cfcbp0, -0x1.9dcfecp0, 0x1.33e6bep0, -0x1.994cb6p0, 0x1.6b1c1ap-2, 0x1.d1262p0, 0x1.df0aecp-1, -0x1.242166p0, -0x1.44c5acp0, -0x1.bc70b4p-1, -0x1.d5d038p-2, -0x1.c2fd26p-1, 0x1.f5d88p-1, 0x1.d8009ep0, -0x1.981bcap0, 0x1.bba178p0, 0x1.a8dac8p-3, 0x1.1abb54p-1, 0x1.585c3cp-4, -0x1.0b5c2p-1, 0x1.804b8p-2, 0x1.f54d62p-2, -0x1.2b180ep-3, 0x1.9308d4p-1, 0x1.c79ce4p0, 0x1.20e5fcp-5, -0x1.0cdafcp-1, 0x1.86da32p0, 0x1.fc6974p0, 0x1.bc4becp0, 0x1.cf82fp0, 0x1.fb6042p-2, -0x1.6cea32p0, -0x1.c93a02p-2, 0x1.350ff2p-1, 0x1.fe309ep-3, -0x1.740c56p-1, -0x1.d08db8p0, -0x1.5dadbp0, 0x1.07338ap0, -0x1.5a2e06p0, 0x1.121ce8p0, 0x1.de1c78p0, 0x1.dd3bbap-3, 0x1.01600ep0, 0x1.d4b0dap-1, 0x1.f9013p0, 0x1.e327ap0, 0x1.455ba6p0, 0x1.cec7aap0, -0x1.9b2e8cp-3, -0x1.ed978p0, 0x1.11ebc4p-1, 0x1.dc8674p-2, 0x1.2312bep-4, -0x1.a68122p-2, -0x1.f1b964p-1, 0x1.f80ba2p-1, -0x1.c3012ap0, -0x1.abd5cep0, 0x1.7e18e8p0, -0x1.81f9c4p0, 0x1.da3c98p0, -0x1.47359p-1, -0x1.4069e2p0, 0x1.5cc99cp0, -0x1.28a182p-1, -0x1.de218p-4, 0x1.bf6d92p-7, -0x1.14e91p0, -0x1.7d8d08p-1, 0x1.b7b44cp0, 0x1.94f054p-3, -0x1.d65056p-2, -0x1.45535cp0, -0x1.097376p0, 0x1.c13096p-1, -0x1.8a4ddp0, 0x1.3d726ep-1, -0x1.cbbf78p-1, 0x1.3ee38ap0, 0x1.dba5cep0, 0x1.d050e4p0, -0x1.2d3efep-2, 0x1.132894p0, -0x1.1364d2p-4, 0x1.04e2b4p0, 0x1.4e4004p-2, -0x1.74e3cap-1, 0x1.4b8522p-5, 0x1.f3d44cp0, -0x1.690a98p-1, 0x1.6576f2p-1, 0x1.45f66ap-2, -0x1.a5d036p-1, 0x1.c284ccp0, 0x1.3f1408p-2, -0x1.a5f19p-1, 0x1.399a88p0, -0x1.fa6224p-1, -0x1.0ed39cp-3, -0x1.e52184p-2, -0x1.d31c4ep0, -0x1.157022p0, -0x1.357204p0, -0x1.7db67p-1, 0x1.3723bep-1, 0x1.bbd7aep0, 0x1.33c3p0, -0x1.21139cp-1 };
float keras_activation_3_test7_array[6] = { 0x1.bde014p-3, 0x1.0c3c84p-4, 0x1.697f86p-6, 0x1.136296p-4, 0x1.35af6ep-1, 0x1.73162p-6 };
float keras_activation_3_test8_array[6] = { 0x1.2550f2p-3, 0x1.3a445p-4, 0x1.4508ccp-6, 0x1.98398ep-5, 0x1.648526p-1, 0x1.cc8c9cp-7 };
float keras_activation_3_test9_array[6] = { 0x1.9ff158p-3, 0x1.2afe8ep-4, 0x1.34dbaap-6, 0x1.649344p-5, 0x1.4c3b14p-1, 0x1.9e2c0ap-7 };
l_struct_OC_k2c_tensor test10_dense_input_input __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor c_activation_3_test5 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor c_activation_3_test10 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor keras_activation_3_test8 __ATTRIBUTE_WEAK__;
static  char aesl_internal__OC_str1[38] = "Max absolute error for 10 tests: %e \n";
l_struct_OC_k2c_tensor test9_dense_input_input __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor c_activation_3_test9 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor c_activation_3_test6 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor c_activation_3_test4 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor test7_dense_input_input __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor keras_activation_3_test6 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor c_activation_3_test7 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor c_activation_3_test8 __ATTRIBUTE_WEAK__;
static  char aesl_internal__OC_str[35] = "Average time over 10 tests: %e s \n";
l_struct_OC_k2c_tensor keras_activation_3_test4 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor keras_activation_3_test10 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor keras_activation_3_test7 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor test6_dense_input_input __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor test8_dense_input_input __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor test5_dense_input_input __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor keras_activation_3_test9 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor keras_activation_3_test5 __ATTRIBUTE_WEAK__;


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

signed int main(void) {
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
  unsigned int llvm_cbe_tmp__1;
  unsigned int llvm_cbe_tmp__1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  float *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  float llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  float *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_exitcond148_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  float llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  float llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  float llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  float llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  float llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  float llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  float llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  float llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  float llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  float llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  float llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  float llvm_cbe_tmp__18;
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
  unsigned int llvm_cbe_tmp__19;
  unsigned int llvm_cbe_tmp__19__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  float *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  float llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  float *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_exitcond145_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  float llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  float llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  float llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  float llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  float llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  float llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  float llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  float llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  float llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  float llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  float llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  float llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned int llvm_cbe_tmp__37;
  unsigned int llvm_cbe_tmp__37__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned long long llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  float *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  float llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  float *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_exitcond142_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  float llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  float llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  float llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  float llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  float llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  float llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  float llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  float llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  float llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  float llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  float llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  float llvm_cbe_tmp__54;
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
  unsigned int llvm_cbe_tmp__55;
  unsigned int llvm_cbe_tmp__55__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned long long llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  float *llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  float llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  float *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_exitcond139_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  float llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  float llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  float llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  float llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  float llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  float llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  float llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  float llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  float llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  float llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  float llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  float llvm_cbe_tmp__72;
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
  unsigned int llvm_cbe_tmp__73;
  unsigned int llvm_cbe_tmp__73__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  unsigned long long llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  float *llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  float llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  float *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  unsigned int llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_exitcond136_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  float llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  float llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  float llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  float llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  float llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  float llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  float llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  float llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  float llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  float llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  float llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  float llvm_cbe_tmp__90;
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
  unsigned int llvm_cbe_tmp__91;
  unsigned int llvm_cbe_tmp__91__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  unsigned long long llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  float *llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  float llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  float *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  unsigned int llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_exitcond133_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  float llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  float llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  float llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  float llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  float llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  float llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  float llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  float llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  float llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  float llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  float llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  float llvm_cbe_tmp__108;
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
  unsigned int llvm_cbe_tmp__109;
  unsigned int llvm_cbe_tmp__109__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  unsigned long long llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  float *llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  float llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  float *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned int llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_exitcond130_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  float llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  float llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  float llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  float llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  float llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  float llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  float llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  float llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  float llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  float llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  float llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  float llvm_cbe_tmp__126;
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
  unsigned int llvm_cbe_tmp__127;
  unsigned int llvm_cbe_tmp__127__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  unsigned long long llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  float *llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  float llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  float *llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  unsigned int llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_exitcond127_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  float llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  float llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  float llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  float llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  float llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  float llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  float llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  float llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  float llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  float llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  float llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  float llvm_cbe_tmp__144;
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
  unsigned int llvm_cbe_tmp__145;
  unsigned int llvm_cbe_tmp__145__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  unsigned long long llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  float *llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  float llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  float *llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  unsigned int llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_exitcond124_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  float llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  float llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  float llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  float llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  float llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  float llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  float llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  float llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  float llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  float llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  float llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  float llvm_cbe_tmp__162;
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
  unsigned int llvm_cbe_tmp__163;
  unsigned int llvm_cbe_tmp__163__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  unsigned long long llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  float *llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  float llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  float *llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  unsigned int llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  float llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  float llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  float llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  float llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  float llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  float llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  float llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  float llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  float llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  float llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  float llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  float llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  unsigned int llvm_cbe_tmp__181;
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
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  unsigned int llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  double llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  double llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  double llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  double llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  double llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  unsigned int llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  float llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  float llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  float llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  float llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  float llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  float llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  float llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  float llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  float llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  float llvm_cbe_tmp__198;
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
  float llvm_cbe_tmp__199;
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
  float llvm_cbe_tmp__200;
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
  float llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
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
  float llvm_cbe_tmp__202;
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
  float llvm_cbe_tmp__203;
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
  float llvm_cbe_tmp__204;
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
  float llvm_cbe_tmp__205;
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
  float llvm_cbe_tmp__206;
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
  float llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  double llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  unsigned int llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge31_count = 0;
  unsigned int llvm_cbe_storemerge31;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 1), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_2_count);
  *((&test1_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 2), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_3_count);
  *((&test1_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_4_count);
  *((&test1_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_5_count);
  *((&test1_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_6_count);
  *((&test1_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_7_count);
  *((&test1_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_8_count);
  *((&test1_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_9_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__210;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__210:
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = phi i32 [ 0, %%0 ], [ %%7, %%1 ], !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__1 = (unsigned int )llvm_cbe_tmp__1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%2 to i64, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__2 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [2622 x float]* @test1_dense_input_input_array, i64 0, i64 %%3, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__3 = (float *)(&test1_dense_input_input_array[(((signed long long )llvm_cbe_tmp__2))
#ifdef AESL_BC_SIM
 % 2622
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__2) < 2622)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test1_dense_input_input_array' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load float* %%4, align 4, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__4 = (float )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__4, *(int*)(&llvm_cbe_tmp__4));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 0, i64 %%3, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__5 = (float *)(&test1_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__2))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%5, float* %%6, align 4, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_16_count);
  *llvm_cbe_tmp__5 = llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%2, 1, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(llvm_cbe_tmp__1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__6&4294967295ull)));
  if (((llvm_cbe_tmp__6&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__211;
  } else {
    llvm_cbe_tmp__1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__6;   /* for PHI node */
    goto llvm_cbe_tmp__210;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__211:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 1), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_19_count);
  *((&keras_activation_3_test1.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 2), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_20_count);
  *((&keras_activation_3_test1.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 0), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_21_count);
  *((&keras_activation_3_test1.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 1), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_22_count);
  *((&keras_activation_3_test1.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 2), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_23_count);
  *((&keras_activation_3_test1.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 3), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_24_count);
  *((&keras_activation_3_test1.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 4), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_25_count);
  *((&keras_activation_3_test1.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 0), align 16, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__7 = (float )*((&keras_activation_3_test1_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__7, *(int*)(&llvm_cbe_tmp__7));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%9, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 0), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_27_count);
  *((&keras_activation_3_test1.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 1), align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__8 = (float )*((&keras_activation_3_test1_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__8, *(int*)(&llvm_cbe_tmp__8));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%10, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 1), align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_29_count);
  *((&keras_activation_3_test1.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 2), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__9 = (float )*((&keras_activation_3_test1_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__9, *(int*)(&llvm_cbe_tmp__9));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%11, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 2), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_31_count);
  *((&keras_activation_3_test1.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 3), align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__10 = (float )*((&keras_activation_3_test1_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__10, *(int*)(&llvm_cbe_tmp__10));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 3), align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_33_count);
  *((&keras_activation_3_test1.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 4), align 16, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__11 = (float )*((&keras_activation_3_test1_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__11, *(int*)(&llvm_cbe_tmp__11));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%13, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 4), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_35_count);
  *((&keras_activation_3_test1.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 5), align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__12 = (float )*((&keras_activation_3_test1_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__12, *(int*)(&llvm_cbe_tmp__12));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%14, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 5), align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_37_count);
  *((&keras_activation_3_test1.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 1), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_38_count);
  *((&c_activation_3_test1.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 2), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_39_count);
  *((&c_activation_3_test1.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 3, i64 0), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_40_count);
  *((&c_activation_3_test1.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 3, i64 1), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_41_count);
  *((&c_activation_3_test1.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 3, i64 2), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_42_count);
  *((&c_activation_3_test1.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 3, i64 3), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_43_count);
  *((&c_activation_3_test1.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 3, i64 4), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_44_count);
  *((&c_activation_3_test1.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 0), align 16, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__13 = (float )*((&c_activation_3_test1_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__13, *(int*)(&llvm_cbe_tmp__13));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 0, i64 0), align 8, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_46_count);
  *((&c_activation_3_test1.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 1), align 4, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__14 = (float )*((&c_activation_3_test1_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__14, *(int*)(&llvm_cbe_tmp__14));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%16, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 0, i64 1), align 4, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_48_count);
  *((&c_activation_3_test1.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 2), align 8, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__15 = (float )*((&c_activation_3_test1_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__15, *(int*)(&llvm_cbe_tmp__15));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%17, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 0, i64 2), align 8, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_50_count);
  *((&c_activation_3_test1.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 3), align 4, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__16 = (float )*((&c_activation_3_test1_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__16, *(int*)(&llvm_cbe_tmp__16));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%18, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 0, i64 3), align 4, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_52_count);
  *((&c_activation_3_test1.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 4), align 16, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__17 = (float )*((&c_activation_3_test1_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__17, *(int*)(&llvm_cbe_tmp__17));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%19, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 0, i64 4), align 8, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_54_count);
  *((&c_activation_3_test1.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 5), align 4, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__18 = (float )*((&c_activation_3_test1_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__18, *(int*)(&llvm_cbe_tmp__18));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%20, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 0, i64 5), align 4, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_56_count);
  *((&c_activation_3_test1.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test2_dense_input_input, i64 0, i32 1), align 8, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_57_count);
  *((&test2_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test2_dense_input_input, i64 0, i32 2), align 8, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_58_count);
  *((&test2_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test2_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_59_count);
  *((&test2_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test2_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_60_count);
  *((&test2_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test2_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_61_count);
  *((&test2_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test2_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_62_count);
  *((&test2_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test2_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_63_count);
  *((&test2_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_64_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__19__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__212;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__212:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = phi i32 [ 0, %%8 ], [ %%27, %%21 ], !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__19 = (unsigned int )llvm_cbe_tmp__19__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__19);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__24);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sext i32 %%22 to i64, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__20 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds [2622 x float]* @test2_dense_input_input_array, i64 0, i64 %%23, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__21 = (float *)(&test2_dense_input_input_array[(((signed long long )llvm_cbe_tmp__20))
#ifdef AESL_BC_SIM
 % 2622
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__20));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__20) < 2622)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test2_dense_input_input_array' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load float* %%24, align 4, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__22 = (float )*llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__22, *(int*)(&llvm_cbe_tmp__22));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.k2c_tensor* @test2_dense_input_input, i64 0, i32 0, i64 %%23, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__23 = (float *)(&test2_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__20))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__20));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%25, float* %%26, align 4, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_71_count);
  *llvm_cbe_tmp__23 = llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add nsw i32 %%22, 1, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_tmp__19&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
  if (((llvm_cbe_tmp__24&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__213;
  } else {
    llvm_cbe_tmp__19__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__24;   /* for PHI node */
    goto llvm_cbe_tmp__212;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__213:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 1), align 8, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_74_count);
  *((&keras_activation_3_test2.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 2), align 8, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_75_count);
  *((&keras_activation_3_test2.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 3, i64 0), align 8, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_76_count);
  *((&keras_activation_3_test2.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 3, i64 1), align 8, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_77_count);
  *((&keras_activation_3_test2.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 3, i64 2), align 8, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_78_count);
  *((&keras_activation_3_test2.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 3, i64 3), align 8, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_79_count);
  *((&keras_activation_3_test2.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 3, i64 4), align 8, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_80_count);
  *((&keras_activation_3_test2.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test2_array, i64 0, i64 0), align 16, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__25 = (float )*((&keras_activation_3_test2_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__25, *(int*)(&llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%29, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 0, i64 0), align 8, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_82_count);
  *((&keras_activation_3_test2.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test2_array, i64 0, i64 1), align 4, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__26 = (float )*((&keras_activation_3_test2_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__26, *(int*)(&llvm_cbe_tmp__26));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%30, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 0, i64 1), align 4, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_84_count);
  *((&keras_activation_3_test2.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__26;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test2_array, i64 0, i64 2), align 8, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__27 = (float )*((&keras_activation_3_test2_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__27, *(int*)(&llvm_cbe_tmp__27));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%31, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 0, i64 2), align 8, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_86_count);
  *((&keras_activation_3_test2.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test2_array, i64 0, i64 3), align 4, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__28 = (float )*((&keras_activation_3_test2_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__28, *(int*)(&llvm_cbe_tmp__28));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%32, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 0, i64 3), align 4, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_88_count);
  *((&keras_activation_3_test2.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test2_array, i64 0, i64 4), align 16, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__29 = (float )*((&keras_activation_3_test2_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__29, *(int*)(&llvm_cbe_tmp__29));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%33, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 0, i64 4), align 8, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_90_count);
  *((&keras_activation_3_test2.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__29;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test2_array, i64 0, i64 5), align 4, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__30 = (float )*((&keras_activation_3_test2_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__30, *(int*)(&llvm_cbe_tmp__30));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%34, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 0, i64 5), align 4, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_92_count);
  *((&keras_activation_3_test2.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 1), align 8, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_93_count);
  *((&c_activation_3_test2.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 2), align 8, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_94_count);
  *((&c_activation_3_test2.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 3, i64 0), align 8, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_95_count);
  *((&c_activation_3_test2.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 3, i64 1), align 8, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_96_count);
  *((&c_activation_3_test2.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 3, i64 2), align 8, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_97_count);
  *((&c_activation_3_test2.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 3, i64 3), align 8, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_98_count);
  *((&c_activation_3_test2.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 3, i64 4), align 8, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_99_count);
  *((&c_activation_3_test2.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test2_array, i64 0, i64 0), align 16, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__31 = (float )*((&c_activation_3_test2_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__31, *(int*)(&llvm_cbe_tmp__31));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%35, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 0, i64 0), align 8, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_101_count);
  *((&c_activation_3_test2.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test2_array, i64 0, i64 1), align 4, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__32 = (float )*((&c_activation_3_test2_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__32, *(int*)(&llvm_cbe_tmp__32));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%36, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 0, i64 1), align 4, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_103_count);
  *((&c_activation_3_test2.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test2_array, i64 0, i64 2), align 8, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__33 = (float )*((&c_activation_3_test2_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__33, *(int*)(&llvm_cbe_tmp__33));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%37, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 0, i64 2), align 8, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_105_count);
  *((&c_activation_3_test2.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test2_array, i64 0, i64 3), align 4, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__34 = (float )*((&c_activation_3_test2_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__34, *(int*)(&llvm_cbe_tmp__34));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%38, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 0, i64 3), align 4, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_107_count);
  *((&c_activation_3_test2.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test2_array, i64 0, i64 4), align 16, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__35 = (float )*((&c_activation_3_test2_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__35, *(int*)(&llvm_cbe_tmp__35));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%39, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 0, i64 4), align 8, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_109_count);
  *((&c_activation_3_test2.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test2_array, i64 0, i64 5), align 4, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__36 = (float )*((&c_activation_3_test2_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__36, *(int*)(&llvm_cbe_tmp__36));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%40, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test2, i64 0, i32 0, i64 5), align 4, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_111_count);
  *((&c_activation_3_test2.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test3_dense_input_input, i64 0, i32 1), align 8, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_112_count);
  *((&test3_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test3_dense_input_input, i64 0, i32 2), align 8, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_113_count);
  *((&test3_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test3_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_114_count);
  *((&test3_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test3_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_115_count);
  *((&test3_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test3_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !19 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_116_count);
  *((&test3_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test3_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_117_count);
  *((&test3_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test3_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_118_count);
  *((&test3_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_119_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__37__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__214;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__214:
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = phi i32 [ 0, %%28 ], [ %%47, %%41 ], !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__37 = (unsigned int )llvm_cbe_tmp__37__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__37);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = sext i32 %%42 to i64, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__38 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds [2622 x float]* @test3_dense_input_input_array, i64 0, i64 %%43, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__39 = (float *)(&test3_dense_input_input_array[(((signed long long )llvm_cbe_tmp__38))
#ifdef AESL_BC_SIM
 % 2622
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__38));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__38) < 2622)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test3_dense_input_input_array' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load float* %%44, align 4, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__40 = (float )*llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__40, *(int*)(&llvm_cbe_tmp__40));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds %%struct.k2c_tensor* @test3_dense_input_input, i64 0, i32 0, i64 %%43, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__41 = (float *)(&test3_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__38))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__38));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%45, float* %%46, align 4, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_126_count);
  *llvm_cbe_tmp__41 = llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = add nsw i32 %%42, 1, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__42 = (unsigned int )((unsigned int )(llvm_cbe_tmp__37&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__42&4294967295ull)));
  if (((llvm_cbe_tmp__42&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__215;
  } else {
    llvm_cbe_tmp__37__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__42;   /* for PHI node */
    goto llvm_cbe_tmp__214;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__215:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 1), align 8, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_129_count);
  *((&keras_activation_3_test3.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 2), align 8, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_130_count);
  *((&keras_activation_3_test3.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 3, i64 0), align 8, !dbg !20 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_131_count);
  *((&keras_activation_3_test3.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 3, i64 1), align 8, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_132_count);
  *((&keras_activation_3_test3.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 3, i64 2), align 8, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_133_count);
  *((&keras_activation_3_test3.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 3, i64 3), align 8, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_134_count);
  *((&keras_activation_3_test3.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 3, i64 4), align 8, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_135_count);
  *((&keras_activation_3_test3.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test3_array, i64 0, i64 0), align 16, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__43 = (float )*((&keras_activation_3_test3_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__43, *(int*)(&llvm_cbe_tmp__43));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%49, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 0, i64 0), align 8, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_137_count);
  *((&keras_activation_3_test3.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test3_array, i64 0, i64 1), align 4, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__44 = (float )*((&keras_activation_3_test3_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__44, *(int*)(&llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%50, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 0, i64 1), align 4, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_139_count);
  *((&keras_activation_3_test3.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test3_array, i64 0, i64 2), align 8, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__45 = (float )*((&keras_activation_3_test3_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__45, *(int*)(&llvm_cbe_tmp__45));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%51, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 0, i64 2), align 8, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_141_count);
  *((&keras_activation_3_test3.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test3_array, i64 0, i64 3), align 4, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__46 = (float )*((&keras_activation_3_test3_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__46, *(int*)(&llvm_cbe_tmp__46));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%52, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 0, i64 3), align 4, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_143_count);
  *((&keras_activation_3_test3.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test3_array, i64 0, i64 4), align 16, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__47 = (float )*((&keras_activation_3_test3_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__47, *(int*)(&llvm_cbe_tmp__47));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%53, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 0, i64 4), align 8, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_145_count);
  *((&keras_activation_3_test3.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__47;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test3_array, i64 0, i64 5), align 4, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__48 = (float )*((&keras_activation_3_test3_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__48, *(int*)(&llvm_cbe_tmp__48));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%54, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test3, i64 0, i32 0, i64 5), align 4, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_147_count);
  *((&keras_activation_3_test3.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 1), align 8, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_148_count);
  *((&c_activation_3_test3.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 2), align 8, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_149_count);
  *((&c_activation_3_test3.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 3, i64 0), align 8, !dbg !21 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_150_count);
  *((&c_activation_3_test3.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 3, i64 1), align 8, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_151_count);
  *((&c_activation_3_test3.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 3, i64 2), align 8, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_152_count);
  *((&c_activation_3_test3.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 3, i64 3), align 8, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_153_count);
  *((&c_activation_3_test3.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 3, i64 4), align 8, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_154_count);
  *((&c_activation_3_test3.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test3_array, i64 0, i64 0), align 16, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__49 = (float )*((&c_activation_3_test3_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__49, *(int*)(&llvm_cbe_tmp__49));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%55, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 0, i64 0), align 8, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_156_count);
  *((&c_activation_3_test3.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test3_array, i64 0, i64 1), align 4, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__50 = (float )*((&c_activation_3_test3_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__50, *(int*)(&llvm_cbe_tmp__50));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%56, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 0, i64 1), align 4, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_158_count);
  *((&c_activation_3_test3.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test3_array, i64 0, i64 2), align 8, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_159_count);
  llvm_cbe_tmp__51 = (float )*((&c_activation_3_test3_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__51, *(int*)(&llvm_cbe_tmp__51));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%57, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 0, i64 2), align 8, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_160_count);
  *((&c_activation_3_test3.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test3_array, i64 0, i64 3), align 4, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__52 = (float )*((&c_activation_3_test3_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__52, *(int*)(&llvm_cbe_tmp__52));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%58, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 0, i64 3), align 4, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_162_count);
  *((&c_activation_3_test3.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__52;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test3_array, i64 0, i64 4), align 16, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__53 = (float )*((&c_activation_3_test3_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__53, *(int*)(&llvm_cbe_tmp__53));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%59, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 0, i64 4), align 8, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_164_count);
  *((&c_activation_3_test3.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test3_array, i64 0, i64 5), align 4, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__54 = (float )*((&c_activation_3_test3_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__54, *(int*)(&llvm_cbe_tmp__54));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%60, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test3, i64 0, i32 0, i64 5), align 4, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_166_count);
  *((&c_activation_3_test3.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__54;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test4_dense_input_input, i64 0, i32 1), align 8, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_167_count);
  *((&test4_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test4_dense_input_input, i64 0, i32 2), align 8, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_168_count);
  *((&test4_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test4_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !22 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_169_count);
  *((&test4_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test4_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_170_count);
  *((&test4_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test4_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_171_count);
  *((&test4_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test4_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_172_count);
  *((&test4_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test4_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_173_count);
  *((&test4_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_174_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__55__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__216;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__216:
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = phi i32 [ 0, %%48 ], [ %%67, %%61 ], !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__55 = (unsigned int )llvm_cbe_tmp__55__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__55);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__60);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = sext i32 %%62 to i64, !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__56 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds [2622 x float]* @test4_dense_input_input_array, i64 0, i64 %%63, !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__57 = (float *)(&test4_dense_input_input_array[(((signed long long )llvm_cbe_tmp__56))
#ifdef AESL_BC_SIM
 % 2622
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__56));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__56) < 2622)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test4_dense_input_input_array' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = load float* %%64, align 4, !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__58 = (float )*llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__58, *(int*)(&llvm_cbe_tmp__58));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = getelementptr inbounds %%struct.k2c_tensor* @test4_dense_input_input, i64 0, i32 0, i64 %%63, !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__59 = (float *)(&test4_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__56))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__56));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%65, float* %%66, align 4, !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_181_count);
  *llvm_cbe_tmp__59 = llvm_cbe_tmp__58;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = add nsw i32 %%62, 1, !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__60 = (unsigned int )((unsigned int )(llvm_cbe_tmp__55&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__60&4294967295ull)));
  if (((llvm_cbe_tmp__60&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__217;
  } else {
    llvm_cbe_tmp__55__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__60;   /* for PHI node */
    goto llvm_cbe_tmp__216;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__217:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 1), align 8, !dbg !23 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_184_count);
  *((&keras_activation_3_test4.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 2), align 8, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_185_count);
  *((&keras_activation_3_test4.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 3, i64 0), align 8, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_186_count);
  *((&keras_activation_3_test4.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 3, i64 1), align 8, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_187_count);
  *((&keras_activation_3_test4.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 3, i64 2), align 8, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_188_count);
  *((&keras_activation_3_test4.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 3, i64 3), align 8, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_189_count);
  *((&keras_activation_3_test4.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 3, i64 4), align 8, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_190_count);
  *((&keras_activation_3_test4.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test4_array, i64 0, i64 0), align 16, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__61 = (float )*((&keras_activation_3_test4_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__61, *(int*)(&llvm_cbe_tmp__61));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%69, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 0, i64 0), align 8, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_192_count);
  *((&keras_activation_3_test4.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test4_array, i64 0, i64 1), align 4, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_193_count);
  llvm_cbe_tmp__62 = (float )*((&keras_activation_3_test4_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__62, *(int*)(&llvm_cbe_tmp__62));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%70, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 0, i64 1), align 4, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_194_count);
  *((&keras_activation_3_test4.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test4_array, i64 0, i64 2), align 8, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_195_count);
  llvm_cbe_tmp__63 = (float )*((&keras_activation_3_test4_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__63, *(int*)(&llvm_cbe_tmp__63));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%71, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 0, i64 2), align 8, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_196_count);
  *((&keras_activation_3_test4.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__63;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test4_array, i64 0, i64 3), align 4, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__64 = (float )*((&keras_activation_3_test4_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__64, *(int*)(&llvm_cbe_tmp__64));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%72, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 0, i64 3), align 4, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_198_count);
  *((&keras_activation_3_test4.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__64;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test4_array, i64 0, i64 4), align 16, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__65 = (float )*((&keras_activation_3_test4_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__65, *(int*)(&llvm_cbe_tmp__65));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%73, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 0, i64 4), align 8, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_200_count);
  *((&keras_activation_3_test4.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__65;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test4_array, i64 0, i64 5), align 4, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__66 = (float )*((&keras_activation_3_test4_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__66, *(int*)(&llvm_cbe_tmp__66));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%74, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test4, i64 0, i32 0, i64 5), align 4, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_202_count);
  *((&keras_activation_3_test4.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__66;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 1), align 8, !dbg !24 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_203_count);
  *((&c_activation_3_test4.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 2), align 8, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_204_count);
  *((&c_activation_3_test4.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 3, i64 0), align 8, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_205_count);
  *((&c_activation_3_test4.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 3, i64 1), align 8, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_206_count);
  *((&c_activation_3_test4.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 3, i64 2), align 8, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_207_count);
  *((&c_activation_3_test4.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 3, i64 3), align 8, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_208_count);
  *((&c_activation_3_test4.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 3, i64 4), align 8, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_209_count);
  *((&c_activation_3_test4.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test4_array, i64 0, i64 0), align 16, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__67 = (float )*((&c_activation_3_test4_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__67, *(int*)(&llvm_cbe_tmp__67));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%75, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 0, i64 0), align 8, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_211_count);
  *((&c_activation_3_test4.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test4_array, i64 0, i64 1), align 4, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__68 = (float )*((&c_activation_3_test4_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__68, *(int*)(&llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%76, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 0, i64 1), align 4, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_213_count);
  *((&c_activation_3_test4.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__68;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test4_array, i64 0, i64 2), align 8, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__69 = (float )*((&c_activation_3_test4_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__69, *(int*)(&llvm_cbe_tmp__69));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%77, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 0, i64 2), align 8, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_215_count);
  *((&c_activation_3_test4.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__69;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test4_array, i64 0, i64 3), align 4, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__70 = (float )*((&c_activation_3_test4_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__70, *(int*)(&llvm_cbe_tmp__70));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%78, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 0, i64 3), align 4, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_217_count);
  *((&c_activation_3_test4.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__70;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test4_array, i64 0, i64 4), align 16, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_218_count);
  llvm_cbe_tmp__71 = (float )*((&c_activation_3_test4_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__71, *(int*)(&llvm_cbe_tmp__71));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%79, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 0, i64 4), align 8, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_219_count);
  *((&c_activation_3_test4.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__71;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test4_array, i64 0, i64 5), align 4, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_220_count);
  llvm_cbe_tmp__72 = (float )*((&c_activation_3_test4_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__72, *(int*)(&llvm_cbe_tmp__72));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%80, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test4, i64 0, i32 0, i64 5), align 4, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_221_count);
  *((&c_activation_3_test4.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__72;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test5_dense_input_input, i64 0, i32 1), align 8, !dbg !25 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_222_count);
  *((&test5_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test5_dense_input_input, i64 0, i32 2), align 8, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_223_count);
  *((&test5_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test5_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_224_count);
  *((&test5_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test5_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_225_count);
  *((&test5_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test5_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_226_count);
  *((&test5_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test5_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_227_count);
  *((&test5_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test5_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_228_count);
  *((&test5_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_229_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__73__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__218;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__218:
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = phi i32 [ 0, %%68 ], [ %%87, %%81 ], !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_231_count);
  llvm_cbe_tmp__73 = (unsigned int )llvm_cbe_tmp__73__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__73);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__78);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = sext i32 %%82 to i64, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_232_count);
  llvm_cbe_tmp__74 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = getelementptr inbounds [2622 x float]* @test5_dense_input_input_array, i64 0, i64 %%83, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_233_count);
  llvm_cbe_tmp__75 = (float *)(&test5_dense_input_input_array[(((signed long long )llvm_cbe_tmp__74))
#ifdef AESL_BC_SIM
 % 2622
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__74));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__74) < 2622)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test5_dense_input_input_array' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = load float* %%84, align 4, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_234_count);
  llvm_cbe_tmp__76 = (float )*llvm_cbe_tmp__75;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__76, *(int*)(&llvm_cbe_tmp__76));
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = getelementptr inbounds %%struct.k2c_tensor* @test5_dense_input_input, i64 0, i32 0, i64 %%83, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_235_count);
  llvm_cbe_tmp__77 = (float *)(&test5_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__74))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__74));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%85, float* %%86, align 4, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_236_count);
  *llvm_cbe_tmp__77 = llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = add nsw i32 %%82, 1, !dbg !26 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_237_count);
  llvm_cbe_tmp__78 = (unsigned int )((unsigned int )(llvm_cbe_tmp__73&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__78&4294967295ull)));
  if (((llvm_cbe_tmp__78&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__219;
  } else {
    llvm_cbe_tmp__73__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__78;   /* for PHI node */
    goto llvm_cbe_tmp__218;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__219:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 1), align 8, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_239_count);
  *((&keras_activation_3_test5.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 2), align 8, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_240_count);
  *((&keras_activation_3_test5.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 3, i64 0), align 8, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_241_count);
  *((&keras_activation_3_test5.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 3, i64 1), align 8, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_242_count);
  *((&keras_activation_3_test5.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 3, i64 2), align 8, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_243_count);
  *((&keras_activation_3_test5.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 3, i64 3), align 8, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_244_count);
  *((&keras_activation_3_test5.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 3, i64 4), align 8, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_245_count);
  *((&keras_activation_3_test5.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test5_array, i64 0, i64 0), align 16, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__79 = (float )*((&keras_activation_3_test5_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__79, *(int*)(&llvm_cbe_tmp__79));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%89, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 0, i64 0), align 8, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_247_count);
  *((&keras_activation_3_test5.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__79);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test5_array, i64 0, i64 1), align 4, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_248_count);
  llvm_cbe_tmp__80 = (float )*((&keras_activation_3_test5_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__80, *(int*)(&llvm_cbe_tmp__80));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%90, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 0, i64 1), align 4, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_249_count);
  *((&keras_activation_3_test5.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__80;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test5_array, i64 0, i64 2), align 8, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__81 = (float )*((&keras_activation_3_test5_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__81, *(int*)(&llvm_cbe_tmp__81));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%91, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 0, i64 2), align 8, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_251_count);
  *((&keras_activation_3_test5.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__81;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test5_array, i64 0, i64 3), align 4, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__82 = (float )*((&keras_activation_3_test5_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__82, *(int*)(&llvm_cbe_tmp__82));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%92, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 0, i64 3), align 4, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_253_count);
  *((&keras_activation_3_test5.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__82;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test5_array, i64 0, i64 4), align 16, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_254_count);
  llvm_cbe_tmp__83 = (float )*((&keras_activation_3_test5_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__83, *(int*)(&llvm_cbe_tmp__83));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%93, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 0, i64 4), align 8, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_255_count);
  *((&keras_activation_3_test5.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__83;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test5_array, i64 0, i64 5), align 4, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__84 = (float )*((&keras_activation_3_test5_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__84, *(int*)(&llvm_cbe_tmp__84));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%94, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test5, i64 0, i32 0, i64 5), align 4, !dbg !27 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_257_count);
  *((&keras_activation_3_test5.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__84;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 1), align 8, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_258_count);
  *((&c_activation_3_test5.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 2), align 8, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_259_count);
  *((&c_activation_3_test5.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 3, i64 0), align 8, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_260_count);
  *((&c_activation_3_test5.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 3, i64 1), align 8, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_261_count);
  *((&c_activation_3_test5.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 3, i64 2), align 8, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_262_count);
  *((&c_activation_3_test5.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 3, i64 3), align 8, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_263_count);
  *((&c_activation_3_test5.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 3, i64 4), align 8, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_264_count);
  *((&c_activation_3_test5.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test5_array, i64 0, i64 0), align 16, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_265_count);
  llvm_cbe_tmp__85 = (float )*((&c_activation_3_test5_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__85, *(int*)(&llvm_cbe_tmp__85));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%95, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 0, i64 0), align 8, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_266_count);
  *((&c_activation_3_test5.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__85;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test5_array, i64 0, i64 1), align 4, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_267_count);
  llvm_cbe_tmp__86 = (float )*((&c_activation_3_test5_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__86, *(int*)(&llvm_cbe_tmp__86));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%96, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 0, i64 1), align 4, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_268_count);
  *((&c_activation_3_test5.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__86;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test5_array, i64 0, i64 2), align 8, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_269_count);
  llvm_cbe_tmp__87 = (float )*((&c_activation_3_test5_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__87, *(int*)(&llvm_cbe_tmp__87));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%97, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 0, i64 2), align 8, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_270_count);
  *((&c_activation_3_test5.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__87;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test5_array, i64 0, i64 3), align 4, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_271_count);
  llvm_cbe_tmp__88 = (float )*((&c_activation_3_test5_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__88, *(int*)(&llvm_cbe_tmp__88));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%98, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 0, i64 3), align 4, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_272_count);
  *((&c_activation_3_test5.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__88;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test5_array, i64 0, i64 4), align 16, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_273_count);
  llvm_cbe_tmp__89 = (float )*((&c_activation_3_test5_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__89, *(int*)(&llvm_cbe_tmp__89));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%99, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 0, i64 4), align 8, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_274_count);
  *((&c_activation_3_test5.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test5_array, i64 0, i64 5), align 4, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__90 = (float )*((&c_activation_3_test5_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__90, *(int*)(&llvm_cbe_tmp__90));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%100, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test5, i64 0, i32 0, i64 5), align 4, !dbg !28 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_276_count);
  *((&c_activation_3_test5.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__90;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test6_dense_input_input, i64 0, i32 1), align 8, !dbg !29 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_277_count);
  *((&test6_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test6_dense_input_input, i64 0, i32 2), align 8, !dbg !29 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_278_count);
  *((&test6_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test6_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !29 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_279_count);
  *((&test6_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test6_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !29 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_280_count);
  *((&test6_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test6_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !29 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_281_count);
  *((&test6_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test6_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !29 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_282_count);
  *((&test6_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test6_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !29 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_283_count);
  *((&test6_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !29 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_284_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__91__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__220;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__220:
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = phi i32 [ 0, %%88 ], [ %%107, %%101 ], !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_286_count);
  llvm_cbe_tmp__91 = (unsigned int )llvm_cbe_tmp__91__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__91);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__96);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = sext i32 %%102 to i64, !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_287_count);
  llvm_cbe_tmp__92 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__91);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = getelementptr inbounds [2622 x float]* @test6_dense_input_input_array, i64 0, i64 %%103, !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__93 = (float *)(&test6_dense_input_input_array[(((signed long long )llvm_cbe_tmp__92))
#ifdef AESL_BC_SIM
 % 2622
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__92));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__92) < 2622)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test6_dense_input_input_array' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = load float* %%104, align 4, !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_289_count);
  llvm_cbe_tmp__94 = (float )*llvm_cbe_tmp__93;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__94, *(int*)(&llvm_cbe_tmp__94));
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = getelementptr inbounds %%struct.k2c_tensor* @test6_dense_input_input, i64 0, i32 0, i64 %%103, !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_290_count);
  llvm_cbe_tmp__95 = (float *)(&test6_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__92))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__92));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%105, float* %%106, align 4, !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_291_count);
  *llvm_cbe_tmp__95 = llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = add nsw i32 %%102, 1, !dbg !29 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_292_count);
  llvm_cbe_tmp__96 = (unsigned int )((unsigned int )(llvm_cbe_tmp__91&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__96&4294967295ull)));
  if (((llvm_cbe_tmp__96&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__221;
  } else {
    llvm_cbe_tmp__91__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__96;   /* for PHI node */
    goto llvm_cbe_tmp__220;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__221:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 1), align 8, !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_294_count);
  *((&keras_activation_3_test6.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 2), align 8, !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_295_count);
  *((&keras_activation_3_test6.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 3, i64 0), align 8, !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_296_count);
  *((&keras_activation_3_test6.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 3, i64 1), align 8, !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_297_count);
  *((&keras_activation_3_test6.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 3, i64 2), align 8, !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_298_count);
  *((&keras_activation_3_test6.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 3, i64 3), align 8, !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_299_count);
  *((&keras_activation_3_test6.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 3, i64 4), align 8, !dbg !30 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_300_count);
  *((&keras_activation_3_test6.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test6_array, i64 0, i64 0), align 16, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_301_count);
  llvm_cbe_tmp__97 = (float )*((&keras_activation_3_test6_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__97, *(int*)(&llvm_cbe_tmp__97));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%109, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 0, i64 0), align 8, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_302_count);
  *((&keras_activation_3_test6.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__97);
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test6_array, i64 0, i64 1), align 4, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_303_count);
  llvm_cbe_tmp__98 = (float )*((&keras_activation_3_test6_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__98, *(int*)(&llvm_cbe_tmp__98));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%110, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 0, i64 1), align 4, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_304_count);
  *((&keras_activation_3_test6.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__98;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test6_array, i64 0, i64 2), align 8, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__99 = (float )*((&keras_activation_3_test6_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__99, *(int*)(&llvm_cbe_tmp__99));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%111, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 0, i64 2), align 8, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_306_count);
  *((&keras_activation_3_test6.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__99;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test6_array, i64 0, i64 3), align 4, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_307_count);
  llvm_cbe_tmp__100 = (float )*((&keras_activation_3_test6_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__100, *(int*)(&llvm_cbe_tmp__100));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%112, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 0, i64 3), align 4, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_308_count);
  *((&keras_activation_3_test6.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test6_array, i64 0, i64 4), align 16, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_309_count);
  llvm_cbe_tmp__101 = (float )*((&keras_activation_3_test6_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__101, *(int*)(&llvm_cbe_tmp__101));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%113, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 0, i64 4), align 8, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_310_count);
  *((&keras_activation_3_test6.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test6_array, i64 0, i64 5), align 4, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_311_count);
  llvm_cbe_tmp__102 = (float )*((&keras_activation_3_test6_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__102, *(int*)(&llvm_cbe_tmp__102));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%114, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test6, i64 0, i32 0, i64 5), align 4, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_312_count);
  *((&keras_activation_3_test6.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__102;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 1), align 8, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_313_count);
  *((&c_activation_3_test6.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 2), align 8, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_314_count);
  *((&c_activation_3_test6.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 3, i64 0), align 8, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_315_count);
  *((&c_activation_3_test6.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 3, i64 1), align 8, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_316_count);
  *((&c_activation_3_test6.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 3, i64 2), align 8, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_317_count);
  *((&c_activation_3_test6.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 3, i64 3), align 8, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_318_count);
  *((&c_activation_3_test6.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 3, i64 4), align 8, !dbg !31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_319_count);
  *((&c_activation_3_test6.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%115 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test6_array, i64 0, i64 0), align 16, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_320_count);
  llvm_cbe_tmp__103 = (float )*((&c_activation_3_test6_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__103, *(int*)(&llvm_cbe_tmp__103));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%115, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 0, i64 0), align 8, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_321_count);
  *((&c_activation_3_test6.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE)
printf("\n  %%116 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test6_array, i64 0, i64 1), align 4, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_322_count);
  llvm_cbe_tmp__104 = (float )*((&c_activation_3_test6_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__104, *(int*)(&llvm_cbe_tmp__104));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%116, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 0, i64 1), align 4, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_323_count);
  *((&c_activation_3_test6.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__104;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%117 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test6_array, i64 0, i64 2), align 8, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__105 = (float )*((&c_activation_3_test6_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__105, *(int*)(&llvm_cbe_tmp__105));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%117, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 0, i64 2), align 8, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_325_count);
  *((&c_activation_3_test6.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__105;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE)
printf("\n  %%118 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test6_array, i64 0, i64 3), align 4, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__106 = (float )*((&c_activation_3_test6_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__106, *(int*)(&llvm_cbe_tmp__106));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%118, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 0, i64 3), align 4, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_327_count);
  *((&c_activation_3_test6.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__106;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE)
printf("\n  %%119 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test6_array, i64 0, i64 4), align 16, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__107 = (float )*((&c_activation_3_test6_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__107, *(int*)(&llvm_cbe_tmp__107));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%119, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 0, i64 4), align 8, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_329_count);
  *((&c_activation_3_test6.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__107;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%120 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test6_array, i64 0, i64 5), align 4, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_330_count);
  llvm_cbe_tmp__108 = (float )*((&c_activation_3_test6_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__108, *(int*)(&llvm_cbe_tmp__108));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%120, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test6, i64 0, i32 0, i64 5), align 4, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_331_count);
  *((&c_activation_3_test6.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__108;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test7_dense_input_input, i64 0, i32 1), align 8, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_332_count);
  *((&test7_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test7_dense_input_input, i64 0, i32 2), align 8, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_333_count);
  *((&test7_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test7_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_334_count);
  *((&test7_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test7_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_335_count);
  *((&test7_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test7_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_336_count);
  *((&test7_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test7_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_337_count);
  *((&test7_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test7_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_338_count);
  *((&test7_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_339_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__109__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__222;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__222:
if (AESL_DEBUG_TRACE)
printf("\n  %%122 = phi i32 [ 0, %%108 ], [ %%127, %%121 ], !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_341_count);
  llvm_cbe_tmp__109 = (unsigned int )llvm_cbe_tmp__109__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__109);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__114);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%123 = sext i32 %%122 to i64, !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_342_count);
  llvm_cbe_tmp__110 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE)
printf("\n  %%124 = getelementptr inbounds [2622 x float]* @test7_dense_input_input_array, i64 0, i64 %%123, !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_343_count);
  llvm_cbe_tmp__111 = (float *)(&test7_dense_input_input_array[(((signed long long )llvm_cbe_tmp__110))
#ifdef AESL_BC_SIM
 % 2622
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__110));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__110) < 2622)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test7_dense_input_input_array' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%125 = load float* %%124, align 4, !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_344_count);
  llvm_cbe_tmp__112 = (float )*llvm_cbe_tmp__111;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__112, *(int*)(&llvm_cbe_tmp__112));
if (AESL_DEBUG_TRACE)
printf("\n  %%126 = getelementptr inbounds %%struct.k2c_tensor* @test7_dense_input_input, i64 0, i32 0, i64 %%123, !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_345_count);
  llvm_cbe_tmp__113 = (float *)(&test7_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__110))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__110));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%125, float* %%126, align 4, !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_346_count);
  *llvm_cbe_tmp__113 = llvm_cbe_tmp__112;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__112);
if (AESL_DEBUG_TRACE)
printf("\n  %%127 = add nsw i32 %%122, 1, !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__114 = (unsigned int )((unsigned int )(llvm_cbe_tmp__109&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__114&4294967295ull)));
  if (((llvm_cbe_tmp__114&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__223;
  } else {
    llvm_cbe_tmp__109__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__114;   /* for PHI node */
    goto llvm_cbe_tmp__222;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__223:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 1), align 8, !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_349_count);
  *((&keras_activation_3_test7.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 2), align 8, !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_350_count);
  *((&keras_activation_3_test7.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 3, i64 0), align 8, !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_351_count);
  *((&keras_activation_3_test7.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 3, i64 1), align 8, !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_352_count);
  *((&keras_activation_3_test7.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 3, i64 2), align 8, !dbg !33 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_353_count);
  *((&keras_activation_3_test7.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 3, i64 3), align 8, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_354_count);
  *((&keras_activation_3_test7.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 3, i64 4), align 8, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_355_count);
  *((&keras_activation_3_test7.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%129 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test7_array, i64 0, i64 0), align 16, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_356_count);
  llvm_cbe_tmp__115 = (float )*((&keras_activation_3_test7_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__115, *(int*)(&llvm_cbe_tmp__115));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%129, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 0, i64 0), align 8, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_357_count);
  *((&keras_activation_3_test7.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__115;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%130 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test7_array, i64 0, i64 1), align 4, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__116 = (float )*((&keras_activation_3_test7_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__116, *(int*)(&llvm_cbe_tmp__116));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%130, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 0, i64 1), align 4, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_359_count);
  *((&keras_activation_3_test7.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__116;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE)
printf("\n  %%131 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test7_array, i64 0, i64 2), align 8, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_360_count);
  llvm_cbe_tmp__117 = (float )*((&keras_activation_3_test7_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__117, *(int*)(&llvm_cbe_tmp__117));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%131, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 0, i64 2), align 8, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_361_count);
  *((&keras_activation_3_test7.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__117;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__117);
if (AESL_DEBUG_TRACE)
printf("\n  %%132 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test7_array, i64 0, i64 3), align 4, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_362_count);
  llvm_cbe_tmp__118 = (float )*((&keras_activation_3_test7_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__118, *(int*)(&llvm_cbe_tmp__118));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%132, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 0, i64 3), align 4, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_363_count);
  *((&keras_activation_3_test7.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__118;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__118);
if (AESL_DEBUG_TRACE)
printf("\n  %%133 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test7_array, i64 0, i64 4), align 16, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__119 = (float )*((&keras_activation_3_test7_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__119, *(int*)(&llvm_cbe_tmp__119));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%133, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 0, i64 4), align 8, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_365_count);
  *((&keras_activation_3_test7.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__119;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__119);
if (AESL_DEBUG_TRACE)
printf("\n  %%134 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test7_array, i64 0, i64 5), align 4, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_366_count);
  llvm_cbe_tmp__120 = (float )*((&keras_activation_3_test7_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__120, *(int*)(&llvm_cbe_tmp__120));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%134, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test7, i64 0, i32 0, i64 5), align 4, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_367_count);
  *((&keras_activation_3_test7.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__120;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__120);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 1), align 8, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_368_count);
  *((&c_activation_3_test7.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 2), align 8, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_369_count);
  *((&c_activation_3_test7.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 3, i64 0), align 8, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_370_count);
  *((&c_activation_3_test7.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 3, i64 1), align 8, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_371_count);
  *((&c_activation_3_test7.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 3, i64 2), align 8, !dbg !34 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_372_count);
  *((&c_activation_3_test7.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 3, i64 3), align 8, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_373_count);
  *((&c_activation_3_test7.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 3, i64 4), align 8, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_374_count);
  *((&c_activation_3_test7.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%135 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test7_array, i64 0, i64 0), align 16, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__121 = (float )*((&c_activation_3_test7_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__121, *(int*)(&llvm_cbe_tmp__121));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%135, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 0, i64 0), align 8, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_376_count);
  *((&c_activation_3_test7.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__121;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__121);
if (AESL_DEBUG_TRACE)
printf("\n  %%136 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test7_array, i64 0, i64 1), align 4, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_377_count);
  llvm_cbe_tmp__122 = (float )*((&c_activation_3_test7_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__122, *(int*)(&llvm_cbe_tmp__122));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%136, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 0, i64 1), align 4, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_378_count);
  *((&c_activation_3_test7.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__122;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE)
printf("\n  %%137 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test7_array, i64 0, i64 2), align 8, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_379_count);
  llvm_cbe_tmp__123 = (float )*((&c_activation_3_test7_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__123, *(int*)(&llvm_cbe_tmp__123));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%137, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 0, i64 2), align 8, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_380_count);
  *((&c_activation_3_test7.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__123;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  %%138 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test7_array, i64 0, i64 3), align 4, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_381_count);
  llvm_cbe_tmp__124 = (float )*((&c_activation_3_test7_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__124, *(int*)(&llvm_cbe_tmp__124));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%138, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 0, i64 3), align 4, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_382_count);
  *((&c_activation_3_test7.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__124;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE)
printf("\n  %%139 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test7_array, i64 0, i64 4), align 16, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_383_count);
  llvm_cbe_tmp__125 = (float )*((&c_activation_3_test7_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__125, *(int*)(&llvm_cbe_tmp__125));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%139, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 0, i64 4), align 8, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_384_count);
  *((&c_activation_3_test7.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__125;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__125);
if (AESL_DEBUG_TRACE)
printf("\n  %%140 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test7_array, i64 0, i64 5), align 4, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_385_count);
  llvm_cbe_tmp__126 = (float )*((&c_activation_3_test7_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__126, *(int*)(&llvm_cbe_tmp__126));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%140, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test7, i64 0, i32 0, i64 5), align 4, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_386_count);
  *((&c_activation_3_test7.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__126;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__126);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test8_dense_input_input, i64 0, i32 1), align 8, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_387_count);
  *((&test8_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test8_dense_input_input, i64 0, i32 2), align 8, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_388_count);
  *((&test8_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test8_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_389_count);
  *((&test8_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test8_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_390_count);
  *((&test8_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test8_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !35 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_391_count);
  *((&test8_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test8_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_392_count);
  *((&test8_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test8_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_393_count);
  *((&test8_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_394_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__127__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__224;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__224:
if (AESL_DEBUG_TRACE)
printf("\n  %%142 = phi i32 [ 0, %%128 ], [ %%147, %%141 ], !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_396_count);
  llvm_cbe_tmp__127 = (unsigned int )llvm_cbe_tmp__127__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__127);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__132);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%143 = sext i32 %%142 to i64, !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_397_count);
  llvm_cbe_tmp__128 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__127);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__128);
if (AESL_DEBUG_TRACE)
printf("\n  %%144 = getelementptr inbounds [2622 x float]* @test8_dense_input_input_array, i64 0, i64 %%143, !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_398_count);
  llvm_cbe_tmp__129 = (float *)(&test8_dense_input_input_array[(((signed long long )llvm_cbe_tmp__128))
#ifdef AESL_BC_SIM
 % 2622
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__128));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__128) < 2622)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test8_dense_input_input_array' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%145 = load float* %%144, align 4, !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_399_count);
  llvm_cbe_tmp__130 = (float )*llvm_cbe_tmp__129;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__130, *(int*)(&llvm_cbe_tmp__130));
if (AESL_DEBUG_TRACE)
printf("\n  %%146 = getelementptr inbounds %%struct.k2c_tensor* @test8_dense_input_input, i64 0, i32 0, i64 %%143, !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_400_count);
  llvm_cbe_tmp__131 = (float *)(&test8_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__128))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__128));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%145, float* %%146, align 4, !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_401_count);
  *llvm_cbe_tmp__131 = llvm_cbe_tmp__130;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE)
printf("\n  %%147 = add nsw i32 %%142, 1, !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_402_count);
  llvm_cbe_tmp__132 = (unsigned int )((unsigned int )(llvm_cbe_tmp__127&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__132&4294967295ull)));
  if (((llvm_cbe_tmp__132&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__225;
  } else {
    llvm_cbe_tmp__127__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__132;   /* for PHI node */
    goto llvm_cbe_tmp__224;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__225:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 1), align 8, !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_404_count);
  *((&keras_activation_3_test8.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 2), align 8, !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_405_count);
  *((&keras_activation_3_test8.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 3, i64 0), align 8, !dbg !36 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_406_count);
  *((&keras_activation_3_test8.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 3, i64 1), align 8, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_407_count);
  *((&keras_activation_3_test8.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 3, i64 2), align 8, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_408_count);
  *((&keras_activation_3_test8.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 3, i64 3), align 8, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_409_count);
  *((&keras_activation_3_test8.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 3, i64 4), align 8, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_410_count);
  *((&keras_activation_3_test8.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%149 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test8_array, i64 0, i64 0), align 16, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_411_count);
  llvm_cbe_tmp__133 = (float )*((&keras_activation_3_test8_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__133, *(int*)(&llvm_cbe_tmp__133));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%149, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 0, i64 0), align 8, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_412_count);
  *((&keras_activation_3_test8.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__133;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE)
printf("\n  %%150 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test8_array, i64 0, i64 1), align 4, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_413_count);
  llvm_cbe_tmp__134 = (float )*((&keras_activation_3_test8_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__134, *(int*)(&llvm_cbe_tmp__134));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%150, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 0, i64 1), align 4, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_414_count);
  *((&keras_activation_3_test8.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__134;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__134);
if (AESL_DEBUG_TRACE)
printf("\n  %%151 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test8_array, i64 0, i64 2), align 8, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_415_count);
  llvm_cbe_tmp__135 = (float )*((&keras_activation_3_test8_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__135, *(int*)(&llvm_cbe_tmp__135));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%151, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 0, i64 2), align 8, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_416_count);
  *((&keras_activation_3_test8.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__135;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE)
printf("\n  %%152 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test8_array, i64 0, i64 3), align 4, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_417_count);
  llvm_cbe_tmp__136 = (float )*((&keras_activation_3_test8_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__136, *(int*)(&llvm_cbe_tmp__136));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%152, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 0, i64 3), align 4, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_418_count);
  *((&keras_activation_3_test8.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__136;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__136);
if (AESL_DEBUG_TRACE)
printf("\n  %%153 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test8_array, i64 0, i64 4), align 16, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_419_count);
  llvm_cbe_tmp__137 = (float )*((&keras_activation_3_test8_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__137, *(int*)(&llvm_cbe_tmp__137));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%153, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 0, i64 4), align 8, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_420_count);
  *((&keras_activation_3_test8.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__137;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n  %%154 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test8_array, i64 0, i64 5), align 4, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_421_count);
  llvm_cbe_tmp__138 = (float )*((&keras_activation_3_test8_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__138, *(int*)(&llvm_cbe_tmp__138));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%154, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test8, i64 0, i32 0, i64 5), align 4, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_422_count);
  *((&keras_activation_3_test8.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__138);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 1), align 8, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_423_count);
  *((&c_activation_3_test8.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 2), align 8, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_424_count);
  *((&c_activation_3_test8.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 3, i64 0), align 8, !dbg !37 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_425_count);
  *((&c_activation_3_test8.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 3, i64 1), align 8, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_426_count);
  *((&c_activation_3_test8.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 3, i64 2), align 8, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_427_count);
  *((&c_activation_3_test8.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 3, i64 3), align 8, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_428_count);
  *((&c_activation_3_test8.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 3, i64 4), align 8, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_429_count);
  *((&c_activation_3_test8.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%155 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test8_array, i64 0, i64 0), align 16, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_430_count);
  llvm_cbe_tmp__139 = (float )*((&c_activation_3_test8_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__139, *(int*)(&llvm_cbe_tmp__139));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%155, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 0, i64 0), align 8, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_431_count);
  *((&c_activation_3_test8.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__139;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__139);
if (AESL_DEBUG_TRACE)
printf("\n  %%156 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test8_array, i64 0, i64 1), align 4, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_432_count);
  llvm_cbe_tmp__140 = (float )*((&c_activation_3_test8_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__140, *(int*)(&llvm_cbe_tmp__140));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%156, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 0, i64 1), align 4, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_433_count);
  *((&c_activation_3_test8.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__140;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE)
printf("\n  %%157 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test8_array, i64 0, i64 2), align 8, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_434_count);
  llvm_cbe_tmp__141 = (float )*((&c_activation_3_test8_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__141, *(int*)(&llvm_cbe_tmp__141));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%157, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 0, i64 2), align 8, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_435_count);
  *((&c_activation_3_test8.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__141;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__141);
if (AESL_DEBUG_TRACE)
printf("\n  %%158 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test8_array, i64 0, i64 3), align 4, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_436_count);
  llvm_cbe_tmp__142 = (float )*((&c_activation_3_test8_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__142, *(int*)(&llvm_cbe_tmp__142));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%158, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 0, i64 3), align 4, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_437_count);
  *((&c_activation_3_test8.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__142;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__142);
if (AESL_DEBUG_TRACE)
printf("\n  %%159 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test8_array, i64 0, i64 4), align 16, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_438_count);
  llvm_cbe_tmp__143 = (float )*((&c_activation_3_test8_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__143, *(int*)(&llvm_cbe_tmp__143));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%159, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 0, i64 4), align 8, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_439_count);
  *((&c_activation_3_test8.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__143;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__143);
if (AESL_DEBUG_TRACE)
printf("\n  %%160 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test8_array, i64 0, i64 5), align 4, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__144 = (float )*((&c_activation_3_test8_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__144, *(int*)(&llvm_cbe_tmp__144));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%160, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test8, i64 0, i32 0, i64 5), align 4, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_441_count);
  *((&c_activation_3_test8.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__144;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__144);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test9_dense_input_input, i64 0, i32 1), align 8, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_442_count);
  *((&test9_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test9_dense_input_input, i64 0, i32 2), align 8, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_443_count);
  *((&test9_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test9_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !38 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_444_count);
  *((&test9_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test9_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_445_count);
  *((&test9_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test9_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_446_count);
  *((&test9_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test9_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_447_count);
  *((&test9_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test9_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_448_count);
  *((&test9_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_449_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__145__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__226;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__226:
if (AESL_DEBUG_TRACE)
printf("\n  %%162 = phi i32 [ 0, %%148 ], [ %%167, %%161 ], !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_451_count);
  llvm_cbe_tmp__145 = (unsigned int )llvm_cbe_tmp__145__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__145);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__150);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%163 = sext i32 %%162 to i64, !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_452_count);
  llvm_cbe_tmp__146 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__145);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__146);
if (AESL_DEBUG_TRACE)
printf("\n  %%164 = getelementptr inbounds [2622 x float]* @test9_dense_input_input_array, i64 0, i64 %%163, !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_453_count);
  llvm_cbe_tmp__147 = (float *)(&test9_dense_input_input_array[(((signed long long )llvm_cbe_tmp__146))
#ifdef AESL_BC_SIM
 % 2622
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__146));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__146) < 2622)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test9_dense_input_input_array' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%165 = load float* %%164, align 4, !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_454_count);
  llvm_cbe_tmp__148 = (float )*llvm_cbe_tmp__147;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__148, *(int*)(&llvm_cbe_tmp__148));
if (AESL_DEBUG_TRACE)
printf("\n  %%166 = getelementptr inbounds %%struct.k2c_tensor* @test9_dense_input_input, i64 0, i32 0, i64 %%163, !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_455_count);
  llvm_cbe_tmp__149 = (float *)(&test9_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__146))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__146));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%165, float* %%166, align 4, !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_456_count);
  *llvm_cbe_tmp__149 = llvm_cbe_tmp__148;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__148);
if (AESL_DEBUG_TRACE)
printf("\n  %%167 = add nsw i32 %%162, 1, !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_457_count);
  llvm_cbe_tmp__150 = (unsigned int )((unsigned int )(llvm_cbe_tmp__145&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__150&4294967295ull)));
  if (((llvm_cbe_tmp__150&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__227;
  } else {
    llvm_cbe_tmp__145__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__150;   /* for PHI node */
    goto llvm_cbe_tmp__226;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__227:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 1), align 8, !dbg !39 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_459_count);
  *((&keras_activation_3_test9.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 2), align 8, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_460_count);
  *((&keras_activation_3_test9.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 3, i64 0), align 8, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_461_count);
  *((&keras_activation_3_test9.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 3, i64 1), align 8, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_462_count);
  *((&keras_activation_3_test9.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 3, i64 2), align 8, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_463_count);
  *((&keras_activation_3_test9.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 3, i64 3), align 8, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_464_count);
  *((&keras_activation_3_test9.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 3, i64 4), align 8, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_465_count);
  *((&keras_activation_3_test9.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%169 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test9_array, i64 0, i64 0), align 16, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_466_count);
  llvm_cbe_tmp__151 = (float )*((&keras_activation_3_test9_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__151, *(int*)(&llvm_cbe_tmp__151));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%169, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 0, i64 0), align 8, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_467_count);
  *((&keras_activation_3_test9.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__151;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__151);
if (AESL_DEBUG_TRACE)
printf("\n  %%170 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test9_array, i64 0, i64 1), align 4, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_468_count);
  llvm_cbe_tmp__152 = (float )*((&keras_activation_3_test9_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__152, *(int*)(&llvm_cbe_tmp__152));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%170, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 0, i64 1), align 4, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_469_count);
  *((&keras_activation_3_test9.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__152;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__152);
if (AESL_DEBUG_TRACE)
printf("\n  %%171 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test9_array, i64 0, i64 2), align 8, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_470_count);
  llvm_cbe_tmp__153 = (float )*((&keras_activation_3_test9_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__153, *(int*)(&llvm_cbe_tmp__153));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%171, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 0, i64 2), align 8, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_471_count);
  *((&keras_activation_3_test9.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__153;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__153);
if (AESL_DEBUG_TRACE)
printf("\n  %%172 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test9_array, i64 0, i64 3), align 4, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_472_count);
  llvm_cbe_tmp__154 = (float )*((&keras_activation_3_test9_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__154, *(int*)(&llvm_cbe_tmp__154));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%172, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 0, i64 3), align 4, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_473_count);
  *((&keras_activation_3_test9.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__154;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__154);
if (AESL_DEBUG_TRACE)
printf("\n  %%173 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test9_array, i64 0, i64 4), align 16, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_474_count);
  llvm_cbe_tmp__155 = (float )*((&keras_activation_3_test9_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__155, *(int*)(&llvm_cbe_tmp__155));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%173, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 0, i64 4), align 8, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_475_count);
  *((&keras_activation_3_test9.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__155;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__155);
if (AESL_DEBUG_TRACE)
printf("\n  %%174 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test9_array, i64 0, i64 5), align 4, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_476_count);
  llvm_cbe_tmp__156 = (float )*((&keras_activation_3_test9_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__156, *(int*)(&llvm_cbe_tmp__156));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%174, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test9, i64 0, i32 0, i64 5), align 4, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_477_count);
  *((&keras_activation_3_test9.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__156;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__156);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 1), align 8, !dbg !40 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_478_count);
  *((&c_activation_3_test9.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 2), align 8, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_479_count);
  *((&c_activation_3_test9.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 3, i64 0), align 8, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_480_count);
  *((&c_activation_3_test9.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 3, i64 1), align 8, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_481_count);
  *((&c_activation_3_test9.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 3, i64 2), align 8, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_482_count);
  *((&c_activation_3_test9.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 3, i64 3), align 8, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_483_count);
  *((&c_activation_3_test9.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 3, i64 4), align 8, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_484_count);
  *((&c_activation_3_test9.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%175 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test9_array, i64 0, i64 0), align 16, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_485_count);
  llvm_cbe_tmp__157 = (float )*((&c_activation_3_test9_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__157, *(int*)(&llvm_cbe_tmp__157));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%175, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 0, i64 0), align 8, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_486_count);
  *((&c_activation_3_test9.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__157;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__157);
if (AESL_DEBUG_TRACE)
printf("\n  %%176 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test9_array, i64 0, i64 1), align 4, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_487_count);
  llvm_cbe_tmp__158 = (float )*((&c_activation_3_test9_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__158, *(int*)(&llvm_cbe_tmp__158));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%176, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 0, i64 1), align 4, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_488_count);
  *((&c_activation_3_test9.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__158;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__158);
if (AESL_DEBUG_TRACE)
printf("\n  %%177 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test9_array, i64 0, i64 2), align 8, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_489_count);
  llvm_cbe_tmp__159 = (float )*((&c_activation_3_test9_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__159, *(int*)(&llvm_cbe_tmp__159));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%177, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 0, i64 2), align 8, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_490_count);
  *((&c_activation_3_test9.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__159;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__159);
if (AESL_DEBUG_TRACE)
printf("\n  %%178 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test9_array, i64 0, i64 3), align 4, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_491_count);
  llvm_cbe_tmp__160 = (float )*((&c_activation_3_test9_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__160, *(int*)(&llvm_cbe_tmp__160));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%178, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 0, i64 3), align 4, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_492_count);
  *((&c_activation_3_test9.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__160;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__160);
if (AESL_DEBUG_TRACE)
printf("\n  %%179 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test9_array, i64 0, i64 4), align 16, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_493_count);
  llvm_cbe_tmp__161 = (float )*((&c_activation_3_test9_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__161, *(int*)(&llvm_cbe_tmp__161));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%179, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 0, i64 4), align 8, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_494_count);
  *((&c_activation_3_test9.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__161;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE)
printf("\n  %%180 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test9_array, i64 0, i64 5), align 4, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_495_count);
  llvm_cbe_tmp__162 = (float )*((&c_activation_3_test9_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__162, *(int*)(&llvm_cbe_tmp__162));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%180, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test9, i64 0, i32 0, i64 5), align 4, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_496_count);
  *((&c_activation_3_test9.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__162;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__162);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test10_dense_input_input, i64 0, i32 1), align 8, !dbg !41 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_497_count);
  *((&test10_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test10_dense_input_input, i64 0, i32 2), align 8, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_498_count);
  *((&test10_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test10_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_499_count);
  *((&test10_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test10_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_500_count);
  *((&test10_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test10_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_501_count);
  *((&test10_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test10_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_502_count);
  *((&test10_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test10_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_503_count);
  *((&test10_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_504_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__163__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__228;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__228:
if (AESL_DEBUG_TRACE)
printf("\n  %%182 = phi i32 [ 0, %%168 ], [ %%187, %%181 ], !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_506_count);
  llvm_cbe_tmp__163 = (unsigned int )llvm_cbe_tmp__163__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__163);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__168);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%183 = sext i32 %%182 to i64, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_507_count);
  llvm_cbe_tmp__164 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__163);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__164);
if (AESL_DEBUG_TRACE)
printf("\n  %%184 = getelementptr inbounds [2622 x float]* @test10_dense_input_input_array, i64 0, i64 %%183, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_508_count);
  llvm_cbe_tmp__165 = (float *)(&test10_dense_input_input_array[(((signed long long )llvm_cbe_tmp__164))
#ifdef AESL_BC_SIM
 % 2622
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__164));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__164) < 2622)) fprintf(stderr, "%s:%d: warning: Read access out of array 'test10_dense_input_input_array' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%185 = load float* %%184, align 4, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_509_count);
  llvm_cbe_tmp__166 = (float )*llvm_cbe_tmp__165;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__166, *(int*)(&llvm_cbe_tmp__166));
if (AESL_DEBUG_TRACE)
printf("\n  %%186 = getelementptr inbounds %%struct.k2c_tensor* @test10_dense_input_input, i64 0, i32 0, i64 %%183, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_510_count);
  llvm_cbe_tmp__167 = (float *)(&test10_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__164))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__164));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%185, float* %%186, align 4, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_511_count);
  *llvm_cbe_tmp__167 = llvm_cbe_tmp__166;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__166);
if (AESL_DEBUG_TRACE)
printf("\n  %%187 = add nsw i32 %%182, 1, !dbg !42 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_512_count);
  llvm_cbe_tmp__168 = (unsigned int )((unsigned int )(llvm_cbe_tmp__163&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__168&4294967295ull)));
  if (((llvm_cbe_tmp__168&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__229;
  } else {
    llvm_cbe_tmp__163__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__168;   /* for PHI node */
    goto llvm_cbe_tmp__228;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__229:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 1), align 8, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_514_count);
  *((&keras_activation_3_test10.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 2), align 8, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_515_count);
  *((&keras_activation_3_test10.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 3, i64 0), align 8, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_516_count);
  *((&keras_activation_3_test10.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 3, i64 1), align 8, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_517_count);
  *((&keras_activation_3_test10.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 3, i64 2), align 8, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_518_count);
  *((&keras_activation_3_test10.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 3, i64 3), align 8, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_519_count);
  *((&keras_activation_3_test10.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 3, i64 4), align 8, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_520_count);
  *((&keras_activation_3_test10.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%189 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test10_array, i64 0, i64 0), align 16, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_521_count);
  llvm_cbe_tmp__169 = (float )*((&keras_activation_3_test10_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__169, *(int*)(&llvm_cbe_tmp__169));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%189, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 0, i64 0), align 8, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_522_count);
  *((&keras_activation_3_test10.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__169;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__169);
if (AESL_DEBUG_TRACE)
printf("\n  %%190 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test10_array, i64 0, i64 1), align 4, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_523_count);
  llvm_cbe_tmp__170 = (float )*((&keras_activation_3_test10_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__170, *(int*)(&llvm_cbe_tmp__170));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%190, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 0, i64 1), align 4, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_524_count);
  *((&keras_activation_3_test10.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__170;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__170);
if (AESL_DEBUG_TRACE)
printf("\n  %%191 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test10_array, i64 0, i64 2), align 8, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_525_count);
  llvm_cbe_tmp__171 = (float )*((&keras_activation_3_test10_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__171, *(int*)(&llvm_cbe_tmp__171));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%191, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 0, i64 2), align 8, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_526_count);
  *((&keras_activation_3_test10.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__171;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__171);
if (AESL_DEBUG_TRACE)
printf("\n  %%192 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test10_array, i64 0, i64 3), align 4, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_527_count);
  llvm_cbe_tmp__172 = (float )*((&keras_activation_3_test10_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__172, *(int*)(&llvm_cbe_tmp__172));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%192, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 0, i64 3), align 4, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_528_count);
  *((&keras_activation_3_test10.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__172;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__172);
if (AESL_DEBUG_TRACE)
printf("\n  %%193 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test10_array, i64 0, i64 4), align 16, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_529_count);
  llvm_cbe_tmp__173 = (float )*((&keras_activation_3_test10_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__173, *(int*)(&llvm_cbe_tmp__173));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%193, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 0, i64 4), align 8, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_530_count);
  *((&keras_activation_3_test10.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__173;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__173);
if (AESL_DEBUG_TRACE)
printf("\n  %%194 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test10_array, i64 0, i64 5), align 4, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_531_count);
  llvm_cbe_tmp__174 = (float )*((&keras_activation_3_test10_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__174, *(int*)(&llvm_cbe_tmp__174));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%194, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test10, i64 0, i32 0, i64 5), align 4, !dbg !43 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_532_count);
  *((&keras_activation_3_test10.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__174;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__174);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 1), align 8, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_533_count);
  *((&c_activation_3_test10.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 2), align 8, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_534_count);
  *((&c_activation_3_test10.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 3, i64 0), align 8, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_535_count);
  *((&c_activation_3_test10.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 3, i64 1), align 8, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_536_count);
  *((&c_activation_3_test10.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 3, i64 2), align 8, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_537_count);
  *((&c_activation_3_test10.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 3, i64 3), align 8, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_538_count);
  *((&c_activation_3_test10.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 3, i64 4), align 8, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_539_count);
  *((&c_activation_3_test10.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%195 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test10_array, i64 0, i64 0), align 16, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_540_count);
  llvm_cbe_tmp__175 = (float )*((&c_activation_3_test10_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__175, *(int*)(&llvm_cbe_tmp__175));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%195, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 0, i64 0), align 8, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_541_count);
  *((&c_activation_3_test10.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__175;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__175);
if (AESL_DEBUG_TRACE)
printf("\n  %%196 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test10_array, i64 0, i64 1), align 4, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_542_count);
  llvm_cbe_tmp__176 = (float )*((&c_activation_3_test10_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__176, *(int*)(&llvm_cbe_tmp__176));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%196, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 0, i64 1), align 4, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_543_count);
  *((&c_activation_3_test10.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__176;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__176);
if (AESL_DEBUG_TRACE)
printf("\n  %%197 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test10_array, i64 0, i64 2), align 8, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__177 = (float )*((&c_activation_3_test10_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__177, *(int*)(&llvm_cbe_tmp__177));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%197, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 0, i64 2), align 8, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_545_count);
  *((&c_activation_3_test10.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__177;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE)
printf("\n  %%198 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test10_array, i64 0, i64 3), align 4, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_546_count);
  llvm_cbe_tmp__178 = (float )*((&c_activation_3_test10_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__178, *(int*)(&llvm_cbe_tmp__178));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%198, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 0, i64 3), align 4, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_547_count);
  *((&c_activation_3_test10.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__178;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__178);
if (AESL_DEBUG_TRACE)
printf("\n  %%199 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test10_array, i64 0, i64 4), align 16, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_548_count);
  llvm_cbe_tmp__179 = (float )*((&c_activation_3_test10_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__179, *(int*)(&llvm_cbe_tmp__179));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%199, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 0, i64 4), align 8, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_549_count);
  *((&c_activation_3_test10.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__179;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__179);
if (AESL_DEBUG_TRACE)
printf("\n  %%200 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test10_array, i64 0, i64 5), align 4, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_550_count);
  llvm_cbe_tmp__180 = (float )*((&c_activation_3_test10_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__180, *(int*)(&llvm_cbe_tmp__180));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%200, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test10, i64 0, i32 0, i64 5), align 4, !dbg !44 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_551_count);
  *((&c_activation_3_test10.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__180;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__180);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 6, i32* @j, align 4, !dbg !45 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_552_count);
  *(&j) = 6u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 6u);
if (AESL_DEBUG_TRACE)
printf("\n  call void bitcast (void (...)* @face_classifier_c_initialize to void ()*)() nounwind, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_557_count);
  face_classifier_c_initialize();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%201 = call i32 @clock() nounwind, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_558_count);
  llvm_cbe_tmp__181 = (unsigned int )clock();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__181);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @face_classifier_c(%%struct.k2c_tensor* @test1_dense_input_input, %%struct.k2c_tensor* @c_activation_3_test1) nounwind, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_561_count);
  face_classifier_c((l_struct_OC_k2c_tensor *)(&test1_dense_input_input), (l_struct_OC_k2c_tensor *)(&c_activation_3_test1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @face_classifier_c(%%struct.k2c_tensor* @test2_dense_input_input, %%struct.k2c_tensor* @c_activation_3_test2) nounwind, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_562_count);
  face_classifier_c((l_struct_OC_k2c_tensor *)(&test2_dense_input_input), (l_struct_OC_k2c_tensor *)(&c_activation_3_test2));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @face_classifier_c(%%struct.k2c_tensor* @test3_dense_input_input, %%struct.k2c_tensor* @c_activation_3_test3) nounwind, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_563_count);
  face_classifier_c((l_struct_OC_k2c_tensor *)(&test3_dense_input_input), (l_struct_OC_k2c_tensor *)(&c_activation_3_test3));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @face_classifier_c(%%struct.k2c_tensor* @test4_dense_input_input, %%struct.k2c_tensor* @c_activation_3_test4) nounwind, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_564_count);
  face_classifier_c((l_struct_OC_k2c_tensor *)(&test4_dense_input_input), (l_struct_OC_k2c_tensor *)(&c_activation_3_test4));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @face_classifier_c(%%struct.k2c_tensor* @test5_dense_input_input, %%struct.k2c_tensor* @c_activation_3_test5) nounwind, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_565_count);
  face_classifier_c((l_struct_OC_k2c_tensor *)(&test5_dense_input_input), (l_struct_OC_k2c_tensor *)(&c_activation_3_test5));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @face_classifier_c(%%struct.k2c_tensor* @test6_dense_input_input, %%struct.k2c_tensor* @c_activation_3_test6) nounwind, !dbg !47 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_566_count);
  face_classifier_c((l_struct_OC_k2c_tensor *)(&test6_dense_input_input), (l_struct_OC_k2c_tensor *)(&c_activation_3_test6));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @face_classifier_c(%%struct.k2c_tensor* @test7_dense_input_input, %%struct.k2c_tensor* @c_activation_3_test7) nounwind, !dbg !47 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_567_count);
  face_classifier_c((l_struct_OC_k2c_tensor *)(&test7_dense_input_input), (l_struct_OC_k2c_tensor *)(&c_activation_3_test7));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @face_classifier_c(%%struct.k2c_tensor* @test8_dense_input_input, %%struct.k2c_tensor* @c_activation_3_test8) nounwind, !dbg !47 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_568_count);
  face_classifier_c((l_struct_OC_k2c_tensor *)(&test8_dense_input_input), (l_struct_OC_k2c_tensor *)(&c_activation_3_test8));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @face_classifier_c(%%struct.k2c_tensor* @test9_dense_input_input, %%struct.k2c_tensor* @c_activation_3_test9) nounwind, !dbg !47 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_569_count);
  face_classifier_c((l_struct_OC_k2c_tensor *)(&test9_dense_input_input), (l_struct_OC_k2c_tensor *)(&c_activation_3_test9));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @face_classifier_c(%%struct.k2c_tensor* @test10_dense_input_input, %%struct.k2c_tensor* @c_activation_3_test10) nounwind, !dbg !47 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_570_count);
  face_classifier_c((l_struct_OC_k2c_tensor *)(&test10_dense_input_input), (l_struct_OC_k2c_tensor *)(&c_activation_3_test10));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%202 = call i32 @clock() nounwind, !dbg !47 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_571_count);
  llvm_cbe_tmp__182 = (unsigned int )clock();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__182);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%203 = sitofp i32 %%202 to double, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_574_count);
  llvm_cbe_tmp__183 = (double )((double )(signed int )llvm_cbe_tmp__182);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__183, *(long long*)(&llvm_cbe_tmp__183));
if (AESL_DEBUG_TRACE)
printf("\n  %%204 = sitofp i32 %%201 to double, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_575_count);
  llvm_cbe_tmp__184 = (double )((double )(signed int )llvm_cbe_tmp__181);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__184, *(long long*)(&llvm_cbe_tmp__184));
if (AESL_DEBUG_TRACE)
printf("\n  %%205 = fsub double %%203, %%204, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_576_count);
  llvm_cbe_tmp__185 = (double )llvm_cbe_tmp__183 - llvm_cbe_tmp__184;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__185, *(long long*)(&llvm_cbe_tmp__185));
if (AESL_DEBUG_TRACE)
printf("\n  %%206 = fdiv double %%205, 1.000000e+03, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_577_count);
  llvm_cbe_tmp__186 = (double )llvm_cbe_tmp__185 / 0x1.f4p9;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__186, *(long long*)(&llvm_cbe_tmp__186));
if (AESL_DEBUG_TRACE)
printf("\n  %%207 = fdiv double %%206, 1.000000e+01, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_578_count);
  llvm_cbe_tmp__187 = (double )llvm_cbe_tmp__186 / 0x1.4p3;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__187, *(long long*)(&llvm_cbe_tmp__187));
if (AESL_DEBUG_TRACE)
printf("\n  %%208 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([35 x i8]* @aesl_internal_.str, i64 0, i64 0), double %%207) nounwind, !dbg !46 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_579_count);
  printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 35
#endif
])), llvm_cbe_tmp__187);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__187, *(long long*)(&llvm_cbe_tmp__187));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__188);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%209 = call float @maxabs(%%struct.k2c_tensor* @keras_activation_3_test1, %%struct.k2c_tensor* @c_activation_3_test1), !dbg !47 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_580_count);
  llvm_cbe_tmp__189 = (float )maxabs((l_struct_OC_k2c_tensor *)(&keras_activation_3_test1), (l_struct_OC_k2c_tensor *)(&c_activation_3_test1));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__189);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%210 = call float @maxabs(%%struct.k2c_tensor* @keras_activation_3_test2, %%struct.k2c_tensor* @c_activation_3_test2), !dbg !47 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_581_count);
  llvm_cbe_tmp__190 = (float )maxabs((l_struct_OC_k2c_tensor *)(&keras_activation_3_test2), (l_struct_OC_k2c_tensor *)(&c_activation_3_test2));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__190);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%211 = call float @maxabs(%%struct.k2c_tensor* @keras_activation_3_test3, %%struct.k2c_tensor* @c_activation_3_test3), !dbg !48 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_582_count);
  llvm_cbe_tmp__191 = (float )maxabs((l_struct_OC_k2c_tensor *)(&keras_activation_3_test3), (l_struct_OC_k2c_tensor *)(&c_activation_3_test3));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__191);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%212 = call float @maxabs(%%struct.k2c_tensor* @keras_activation_3_test4, %%struct.k2c_tensor* @c_activation_3_test4), !dbg !48 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_583_count);
  llvm_cbe_tmp__192 = (float )maxabs((l_struct_OC_k2c_tensor *)(&keras_activation_3_test4), (l_struct_OC_k2c_tensor *)(&c_activation_3_test4));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__192);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%213 = call float @maxabs(%%struct.k2c_tensor* @keras_activation_3_test5, %%struct.k2c_tensor* @c_activation_3_test5), !dbg !48 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_584_count);
  llvm_cbe_tmp__193 = (float )maxabs((l_struct_OC_k2c_tensor *)(&keras_activation_3_test5), (l_struct_OC_k2c_tensor *)(&c_activation_3_test5));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__193);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%214 = call float @maxabs(%%struct.k2c_tensor* @keras_activation_3_test6, %%struct.k2c_tensor* @c_activation_3_test6), !dbg !48 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_585_count);
  llvm_cbe_tmp__194 = (float )maxabs((l_struct_OC_k2c_tensor *)(&keras_activation_3_test6), (l_struct_OC_k2c_tensor *)(&c_activation_3_test6));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__194);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%215 = call float @maxabs(%%struct.k2c_tensor* @keras_activation_3_test7, %%struct.k2c_tensor* @c_activation_3_test7), !dbg !48 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_586_count);
  llvm_cbe_tmp__195 = (float )maxabs((l_struct_OC_k2c_tensor *)(&keras_activation_3_test7), (l_struct_OC_k2c_tensor *)(&c_activation_3_test7));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__195);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%216 = call float @maxabs(%%struct.k2c_tensor* @keras_activation_3_test8, %%struct.k2c_tensor* @c_activation_3_test8), !dbg !48 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_587_count);
  llvm_cbe_tmp__196 = (float )maxabs((l_struct_OC_k2c_tensor *)(&keras_activation_3_test8), (l_struct_OC_k2c_tensor *)(&c_activation_3_test8));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__196);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%217 = call float @maxabs(%%struct.k2c_tensor* @keras_activation_3_test9, %%struct.k2c_tensor* @c_activation_3_test9), !dbg !48 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_588_count);
  llvm_cbe_tmp__197 = (float )maxabs((l_struct_OC_k2c_tensor *)(&keras_activation_3_test9), (l_struct_OC_k2c_tensor *)(&c_activation_3_test9));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__197);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%218 = call float @maxabs(%%struct.k2c_tensor* @keras_activation_3_test10, %%struct.k2c_tensor* @c_activation_3_test10), !dbg !48 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_589_count);
  llvm_cbe_tmp__198 = (float )maxabs((l_struct_OC_k2c_tensor *)(&keras_activation_3_test10), (l_struct_OC_k2c_tensor *)(&c_activation_3_test10));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__198);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%220 = select i1 %%219, float %%210, float %%209, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_604_count);
  llvm_cbe_tmp__199 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__190, llvm_cbe_tmp__189))) ? ((float )llvm_cbe_tmp__190) : ((float )llvm_cbe_tmp__189));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__199, *(int*)(&llvm_cbe_tmp__199));
if (AESL_DEBUG_TRACE)
printf("\n  %%222 = select i1 %%221, float %%211, float %%220, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_616_count);
  llvm_cbe_tmp__200 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__191, llvm_cbe_tmp__199))) ? ((float )llvm_cbe_tmp__191) : ((float )llvm_cbe_tmp__199));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__200, *(int*)(&llvm_cbe_tmp__200));
if (AESL_DEBUG_TRACE)
printf("\n  %%224 = select i1 %%223, float %%212, float %%222, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_628_count);
  llvm_cbe_tmp__201 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__192, llvm_cbe_tmp__200))) ? ((float )llvm_cbe_tmp__192) : ((float )llvm_cbe_tmp__200));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__201, *(int*)(&llvm_cbe_tmp__201));
if (AESL_DEBUG_TRACE)
printf("\n  %%226 = select i1 %%225, float %%213, float %%224, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_640_count);
  llvm_cbe_tmp__202 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__193, llvm_cbe_tmp__201))) ? ((float )llvm_cbe_tmp__193) : ((float )llvm_cbe_tmp__201));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__202, *(int*)(&llvm_cbe_tmp__202));
if (AESL_DEBUG_TRACE)
printf("\n  %%228 = select i1 %%227, float %%214, float %%226, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_652_count);
  llvm_cbe_tmp__203 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__194, llvm_cbe_tmp__202))) ? ((float )llvm_cbe_tmp__194) : ((float )llvm_cbe_tmp__202));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__203, *(int*)(&llvm_cbe_tmp__203));
if (AESL_DEBUG_TRACE)
printf("\n  %%230 = select i1 %%229, float %%215, float %%228, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_664_count);
  llvm_cbe_tmp__204 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__195, llvm_cbe_tmp__203))) ? ((float )llvm_cbe_tmp__195) : ((float )llvm_cbe_tmp__203));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__204, *(int*)(&llvm_cbe_tmp__204));
if (AESL_DEBUG_TRACE)
printf("\n  %%232 = select i1 %%231, float %%216, float %%230, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_676_count);
  llvm_cbe_tmp__205 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__196, llvm_cbe_tmp__204))) ? ((float )llvm_cbe_tmp__196) : ((float )llvm_cbe_tmp__204));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__205, *(int*)(&llvm_cbe_tmp__205));
if (AESL_DEBUG_TRACE)
printf("\n  %%234 = select i1 %%233, float %%217, float %%232, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_688_count);
  llvm_cbe_tmp__206 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__197, llvm_cbe_tmp__205))) ? ((float )llvm_cbe_tmp__197) : ((float )llvm_cbe_tmp__205));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__206, *(int*)(&llvm_cbe_tmp__206));
if (AESL_DEBUG_TRACE)
printf("\n  %%236 = select i1 %%235, float %%218, float %%234, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_700_count);
  llvm_cbe_tmp__207 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__198, llvm_cbe_tmp__206))) ? ((float )llvm_cbe_tmp__198) : ((float )llvm_cbe_tmp__206));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__207, *(int*)(&llvm_cbe_tmp__207));
if (AESL_DEBUG_TRACE)
printf("\n  %%237 = fpext float %%236 to double, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_707_count);
  llvm_cbe_tmp__208 = (double )((double )llvm_cbe_tmp__207);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__208, *(long long*)(&llvm_cbe_tmp__208));
if (AESL_DEBUG_TRACE)
printf("\n  %%238 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([38 x i8]* @aesl_internal_.str1, i64 0, i64 0), double %%237) nounwind, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_708_count);
  printf(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 38
#endif
])), llvm_cbe_tmp__208);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__208, *(long long*)(&llvm_cbe_tmp__208));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__209);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void bitcast (void (...)* @face_classifier_c_terminate to void ()*)() nounwind, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_709_count);
  face_classifier_c_terminate();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge31 = zext i1 %%239 to i32, !dbg !49 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge31_count);
  llvm_cbe_storemerge31 = (unsigned int )((unsigned int )(bool )(llvm_fcmp_ogt(llvm_cbe_tmp__208, 0x1.4f8b588e368f1p-17))&1U);
if (AESL_DEBUG_TRACE)
printf("\nstoremerge31 = 0x%X\n", llvm_cbe_storemerge31);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_storemerge31;
}


float maxabs(l_struct_OC_k2c_tensor *llvm_cbe_tensor1, l_struct_OC_k2c_tensor *llvm_cbe_tensor2) {
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
  signed long long *llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  unsigned long long llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  float llvm_cbe_tmp__232;
  float llvm_cbe_tmp__232__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  float *llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  float llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  float *llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  float llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  float llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  float llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  float llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  unsigned long long llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  unsigned long long llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  float llvm_cbe__2e_lcssa;
  float llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @maxabs\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%tensor1, i64 0, i32 2, !dbg !12 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_728_count);
  llvm_cbe_tmp__230 = (signed long long *)(&llvm_cbe_tensor1->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !12 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_729_count);
  llvm_cbe_tmp__231 = (unsigned long long )*llvm_cbe_tmp__230;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__231);
  if (((llvm_cbe_tmp__231&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__232__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%13, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__240);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = phi float [ %%12, %%.lr.ph ], [ 0.000000e+00, %%0  for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_732_count);
  llvm_cbe_tmp__232 = (float )llvm_cbe_tmp__232__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__232);
printf("\n = %f",llvm_cbe_tmp__239);
printf("\n = %f",0x0p0);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%tensor1, i64 0, i32 0, i64 %%storemerge1, !dbg !12 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_733_count);
  llvm_cbe_tmp__233 = (float *)(&llvm_cbe_tensor1->field0[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%5, align 4, !dbg !12 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_734_count);
  llvm_cbe_tmp__234 = (float )*llvm_cbe_tmp__233;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__234, *(int*)(&llvm_cbe_tmp__234));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.k2c_tensor* %%tensor2, i64 0, i32 0, i64 %%storemerge1, !dbg !12 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_735_count);
  llvm_cbe_tmp__235 = (float *)(&llvm_cbe_tensor2->field0[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 4, !dbg !12 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_736_count);
  llvm_cbe_tmp__236 = (float )*llvm_cbe_tmp__235;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__236, *(int*)(&llvm_cbe_tmp__236));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fsub float %%6, %%8, !dbg !12 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_737_count);
  llvm_cbe_tmp__237 = (float )((float )(llvm_cbe_tmp__234 - llvm_cbe_tmp__236));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__237, *(int*)(&llvm_cbe_tmp__237));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call float @fabsf(float %%9) nounwind, !dbg !12 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_738_count);
  llvm_cbe_tmp__238 = (float ) /*tail*/ fabsf(llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__237, *(int*)(&llvm_cbe_tmp__237));
printf("\nReturn  = %f",llvm_cbe_tmp__238);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = select i1 %%11, float %%10, float %%4, !dbg !13 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_746_count);
  llvm_cbe_tmp__239 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__238, llvm_cbe_tmp__232))) ? ((float )llvm_cbe_tmp__238) : ((float )llvm_cbe_tmp__232));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__239, *(int*)(&llvm_cbe_tmp__239));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i64 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_748_count);
  llvm_cbe_tmp__240 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__240&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%1, align 8, !dbg !12 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_754_count);
  llvm_cbe_tmp__241 = (unsigned long long )*llvm_cbe_tmp__230;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__241);
  if ((((unsigned long long )llvm_cbe_tmp__240&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__241&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__240;   /* for PHI node */
    llvm_cbe_tmp__232__PHI_TEMPORARY = (float )llvm_cbe_tmp__239;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (float )llvm_cbe_tmp__239;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi float [ 0.000000e+00, %%0 ], [ %%12, %%.lr.ph  for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (float )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = %f",llvm_cbe__2e_lcssa);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__239);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @maxabs}\n");
  return llvm_cbe__2e_lcssa;
}

