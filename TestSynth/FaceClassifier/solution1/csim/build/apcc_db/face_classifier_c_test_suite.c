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
extern unsigned int j;
extern l_struct_OC_k2c_tensor test1_dense_input_input;
extern l_struct_OC_k2c_tensor keras_activation_3_test1;
extern l_struct_OC_k2c_tensor c_activation_3_test1;
extern float errors[10];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int main(void);
void face_classifier_c_initialize();
void face_classifier_c(l_struct_OC_k2c_tensor , l_struct_OC_k2c_tensor *);
float maxabs(l_struct_OC_k2c_tensor *llvm_cbe_tensor1, l_struct_OC_k2c_tensor *llvm_cbe_tensor2);
void face_classifier_c_terminate();
float fabsf(float );


/* Global Variable Definitions and Initialization */
float test1_dense_input_input_array[2622] = { 0x1.be157p0, -0x1.2952a4p0, -0x1.f1a53ap-3, 0x1.89c2cep0, 0x1.643852p-1, -0x1.5ad3b8p0, -0x1.c55c24p0, 0x1.a191bap-1, -0x1.041c5ap-1, -0x1.be5946p0, 0x1.58e52ap0, 0x1.1eb0fp-1, 0x1.b13f7p0, -0x1.08215ap0, 0x1.dc6bdp0, -0x1.0f0fe2p-3, 0x1.e4b17ep0, 0x1.18a7fcp0, 0x1.5f4fdp0, 0x1.b42e16p0, -0x1.660bdep0, 0x1.1645e8p0, -0x1.a8f982p-3, 0x1.841482p0, -0x1.2a0c46p-1, -0x1.c9d6ap0, 0x1.61f90cp-6, 0x1.17c2fcp-1, -0x1.05875ap-1, 0x1.fb67cp0, -0x1.0071ccp0, 0x1.c167bcp-1, 0x1.c0e4d2p-1, -0x1.47a0fep0, -0x1.d2d068p0, -0x1.f08856p0, 0x1.f8abp-1, -0x1.e3733cp-2, 0x1.a8aadp-3, -0x1.b5b0a6p-1, -0x1.e382fep0, -0x1.6118d6p-2, 0x1.4210cap-3, 0x1.f5010cp-3, -0x1.968a3cp0, -0x1.c36a7ap-1, -0x1.746da8p0, 0x1.eeb1ecp-4, 0x1.6f5944p-1, 0x1.807a4ap0, 0x1.7bca22p-1, -0x1.1aaa7cp0, 0x1.3e1844p0, -0x1.1d9bfep0, 0x1.a05c86p-2, 0x1.c55676p0, -0x1.203368p0, 0x1.2a3592p-2, 0x1.9f42c2p0, 0x1.90b79ep-1, -0x1.23b942p-2, 0x1.0a31acp-1, 0x1.bcb7fcp-2, 0x1.938442p-1, 0x1.8014eap0, -0x1.662b7ep0, 0x1.e54b32p-1, -0x1.0c6aecp0, -0x1.8bffd8p-1, 0x1.d167b8p-4, -0x1.9580cap-1, -0x1.50541cp-1, 0x1.9c3546p0, -0x1.c3436ep0, 0x1.fcc9a8p0, -0x1.b04936p0, -0x1.49949ep0, -0x1.bfc7c4p0, 0x1.7657fcp-1, -0x1.34fc0cp0, 0x1.6ce432p-1, 0x1.664f5p-1, -0x1.be7bd6p0, 0x1.7b52ep0, 0x1.9a2dc6p-1, 0x1.642266p-1, -0x1.bb3fe6p-2, 0x1.2685a6p0, 0x1.0e4ac8p0, 0x1.78d95ep0, -0x1.280478p-3, 0x1.b313a4p-2, -0x1.3dee5ep-1, -0x1.b76df4p-2, 0x1.4ab12p-1, 0x1.8afcf4p-1, -0x1.a953fap0, -0x1.342364p0, 0x1.48493p-1, 0x1.24adeap-3, 0x1.086998p-3, -0x1.496e12p-2, -0x1.443ee6p-2, 0x1.a8c46ep0, -0x1.c77394p0, -0x1.93cfcap0, 0x1.cda6bcp-2, -0x1.0f87c2p-1, -0x1.c619a6p-1, -0x1.109782p0, 0x1.d17e62p-2, -0x1.07403ap0, 0x1.edf2dp0, 0x1.6ee3p-1, 0x1.ab9366p-6, 0x1.b5ab1ep0, -0x1.8a564ap0, 0x1.34d524p0, 0x1.b201fap0, -0x1.0d50f2p0, 0x1.c7b5c8p0, -0x1.e78cbep-8, 0x1.84554p-2, -0x1.81a0c8p0, 0x1.f5c2a4p0, 0x1.4f2106p-1, 0x1.04421p-1, -0x1.f1e65p-1, -0x1.f50b58p-1, -0x1.0c5d98p0, 0x1.c5ac24p-1, 0x1.035824p0, 0x1.751dfp0, -0x1.e03024p-1, -0x1.f57c56p-1, 0x1.fd8454p0, 0x1.dcb06ap0, 0x1.11413ap-1, -0x1.4d3f6ep-1, 0x1.3cec4ep-2, 0x1.238884p0, 0x1.264c54p0, -0x1.048dfep-4, 0x1.01b9cp-7, -0x1.45ffa4p-1, -0x1.e85be2p0, -0x1.865104p0, 0x1.428fc4p0, 0x1.5ca1ep0, 0x1.8dbe46p0, 0x1.fdc35ep-1, 0x1.7713b2p-1, -0x1.806952p0, 0x1.8067e6p0, 0x1.db3456p-1, -0x1.a7ef7cp0, 0x1.dd941p-6, -0x1.a526dcp0, -0x1.70a3eap-1, -0x1.e6734ep0, 0x1.7e0cfep0, -0x1.5d2b0ep-1, 0x1.603536p0, -0x1.462724p-1, -0x1.e5c57p-1, -0x1.b5ee7ep0, -0x1.52a35p-7, -0x1.73717cp-1, 0x1.e52f22p-1, -0x1.e98a7p-4, -0x1.8d85a6p-1, -0x1.58ed6cp-1, 0x1.580d1ap-1, -0x1.d53aep-2, 0x1.100022p-2, 0x1.839f3ap-6, -0x1.241ad2p0, 0x1.f3d012p-1, -0x1.d03a54p-5, 0x1.83426p0, -0x1.9097p0, 0x1.06f088p-2, -0x1.11dd88p-2, -0x1.4decbp-1, -0x1.269b62p-1, -0x1.84843p-3, -0x1.7e9de4p-1, -0x1.0d7f7ep0, 0x1.88821cp-1, 0x1.6f20fp0, 0x1.f8c87p0, 0x1.28cf46p-1, 0x1.0969f4p-1, 0x1.abef8ep0, -0x1.8b9924p0, 0x1.483774p-3, -0x1.7b9eb2p-1, 0x1.36b744p-3, 0x1.9710fp0, -0x1.11cd04p0, 0x1.d9c6a6p0, -0x1.8b506p0, 0x1.a5f392p0, -0x1.dcad46p0, -0x1.d9f3c6p-2, -0x1.15de3ap-1, 0x1.3a06ep-1, -0x1.b33b28p0, -0x1.1bd9b8p0, 0x1.2aba62p0, -0x1.fdf718p0, -0x1.e0ce7ep0, -0x1.c6fc4ap0, 0x1.8f639cp0, -0x1.ac3842p0, 0x1.7d6d0ep-1, 0x1.63590ap0, 0x1.53c696p-1, 0x1.a17d98p-2, -0x1.9cf65ap0, 0x1.208d94p0, 0x1.2d2f54p0, 0x1.0b0974p0, -0x1.cf2102p0, 0x1.70c68ep0, -0x1.bc965ep-3, 0x1.e5903p0, 0x1.67e16p-3, 0x1.739d04p0, -0x1.b9d5dep-3, 0x1.e17378p0, -0x1.068944p-1, 0x1.abd5c2p-1, 0x1.1dcdbp-1, 0x1.f6fd6ap0, -0x1.f840dep0, 0x1.423bfcp-1, 0x1.a95706p-1, 0x1.48d46ap-2, -0x1.6c5ccp-1, -0x1.01c876p-1, 0x1.5f75b6p0, 0x1.ace124p0, -0x1.a2cffep-2, -0x1.ebedc4p-3, -0x1.a60168p0, -0x1.262128p0, -0x1.5a4458p-2, -0x1.d093d4p0, -0x1.f7e018p-2, -0x1.1803b4p0, -0x1.c5eb36p0, 0x1.321dbap-1, 0x1.3587c8p0, -0x1.c74cap0, 0x1.9468d4p-1, -0x1.a1b22ep0, -0x1.7f08fap-4, -0x1.6f22p-1, -0x1.4e66ecp0, 0x1.bfba1ep0, 0x1.6d347ep0, -0x1.8f58b4p-4, -0x1.4a92dp0, 0x1.e8e3b6p0, 0x1.a4f664p0, 0x1.a3f816p0, -0x1.b96a66p0, -0x1.9b4eecp0, 0x1.961b4cp0, -0x1.d5e416p0, 0x1.9ba77ap-3, -0x1.9852ap0, 0x1.b74fcp-1, -0x1.5ae6fep0, -0x1.54fep0, 0x1.beab44p-1, -0x1.7879dep0, -0x1.d65306p-1, 0x1.b94f92p-1, 0x1.40ffa6p-2, -0x1.0d4c3p0, 0x1.b560b6p-1, -0x1.71b6fep0, -0x1.35966ap-1, 0x1.d2fe84p0, -0x1.e0a71p0, -0x1.14f8a2p0, -0x1.e9c9f4p-2, 0x1.f53822p-1, 0x1.fd031ap0, 0x1.c47308p-1, 0x1.be8a1ap-2, 0x1.4670e8p0, 0x1.f0ad36p-1, 0x1.8a90ccp-2, 0x1.b49b56p-1, -0x1.51a81cp-1, 0x1.b59848p0, 0x1.075744p0, -0x1.d5b0cp0, 0x1.ddd10cp-4, 0x1.29be42p0, -0x1.65d3dp0, 0x1.05a0b8p0, 0x1.e11bfep-1, -0x1.7c79b4p-2, 0x1.efe54cp-1, -0x1.3ddec2p-3, -0x1.a5430ap-1, 0x1.d97136p0, 0x1.bcae46p-2, -0x1.35db52p-3, 0x1.9edf3ap0, 0x1.dd4136p-1, 0x1.d245bep0, 0x1.cc9ac2p0, -0x1.fc274cp-7, -0x1.99d876p-1, 0x1.ce8aap-1, -0x1.4fdc7ap0, 0x1.66e388p-4, 0x1.ed2e2ap-1, -0x1.ee1426p-4, -0x1.e5a42ap-2, 0x1.4fb866p-1, 0x1.20d8d4p0, 0x1.3d4044p0, 0x1.81e36cp0, 0x1.3881bap0, 0x1.69949p0, -0x1.4b544cp-1, -0x1.fc398cp-1, 0x1.828cd6p0, -0x1.003e18p-1, -0x1.8c78e8p0, -0x1.a1f0dp0, 0x1.8ed50ap-2, 0x1.b21a16p0, 0x1.2c00c6p-1, 0x1.a1dda6p-2, -0x1.09275ap-1, -0x1.5c632ap-2, 0x1.87708p0, 0x1.e8a85cp-4, 0x1.5c321ap-1, 0x1.b35ae6p-1, 0x1.b29056p0, -0x1.52a8eap0, 0x1.66b15p-3, 0x1.4596d2p0, -0x1.76c592p-2, -0x1.5a9886p0, 0x1.3125acp-1, 0x1.1f47a6p0, -0x1.f875c8p0, -0x1.d64014p0, -0x1.3e0fe6p0, -0x1.3bac64p-1, 0x1.d13a1ep-3, 0x1.58121p-1, -0x1.21ff42p-1, 0x1.013e82p0, -0x1.cdf66p-4, -0x1.aa1536p-1, 0x1.973496p0, 0x1.9fb552p0, 0x1.4c221p0, -0x1.bd730ap-3, 0x1.2a630cp0, -0x1.0bb90ap0, -0x1.85273p0, -0x1.935766p-1, -0x1.dbbd46p-3, 0x1.554d9p-1, -0x1.b13c6cp0, 0x1.81b8cep-2, 0x1.734a9p0, -0x1.fa8482p0, 0x1.2ccefep0, 0x1.64cb5p0, 0x1.c7411ep-3, -0x1.6ab27cp-4, 0x1.9c759cp-3, -0x1.01a87p-2, 0x1.229c1cp-1, 0x1.8de68p-1, -0x1.5ddf8cp0, 0x1.8845f8p0, -0x1.f422c4p0, 0x1.875f2p0, -0x1.c969a8p0, -0x1.85669cp0, -0x1.bbcb74p0, 0x1.ef0728p-1, -0x1.3f4ae2p-1, 0x1.99d7b6p-4, 0x1.f6af8p0, -0x1.279f24p0, -0x1.3ee392p-1, -0x1.36955ap0, 0x1.fa97fp-1, -0x1.afb50cp-1, -0x1.fcd466p0, -0x1.713022p0, -0x1.7e8d68p-4, 0x1.b22f5ap0, -0x1.5f26e2p-1, -0x1.895182p-2, 0x1.32708cp0, 0x1.c5867cp0, 0x1.7400dap0, 0x1.90e1b4p0, 0x1.7141cp-1, 0x1.24794p0, 0x1.7bb9fp-8, 0x1.445ebp-4, 0x1.5cda3ap0, 0x1.2319cp0, 0x1.da0a22p0, 0x1.071d32p0, 0x1.d0c84cp-1, -0x1.f544b2p-4, 0x1.84b556p-2, -0x1.dcc848p0, 0x1.d01954p-1, 0x1.1a225ap-1, -0x1.b386e8p-1, 0x1.dbc07ep0, -0x1.a4920ep-2, -0x1.138a3ap-2, 0x1.3459dcp0, -0x1.cbf024p-1, 0x1.153d5p0, -0x1.e4ed58p-3, 0x1.a820c8p-1, 0x1.4258a6p-4, -0x1.6e3d46p0, 0x1.ea66c4p0, 0x1.c8a958p-2, 0x1.b5ab74p-3, -0x1.ff8224p0, 0x1.759ce6p-2, 0x1.a49f34p0, -0x1.2afecep0, -0x1.e2739cp0, -0x1.6e72ccp-1, -0x1.6a755p0, -0x1.99975ep0, -0x1.4b16dcp-2, -0x1.608302p-2, 0x1.929beep-1, 0x1.19ad8cp0, 0x1.d7181p0, 0x1.01f61p-3, -0x1.97036p-2, 0x1.ddf918p-1, -0x1.91a878p0, 0x1.083b8ep0, -0x1.a486d8p-2, -0x1.113516p0, -0x1.2c1a76p0, 0x1.633a26p-2, -0x1.0509c2p-4, 0x1.8faafp0, 0x1.b1ca82p-2, -0x1.84fdc2p0, -0x1.6f0d1p0, -0x1.7d314cp0, -0x1.835822p-3, -0x1.af50dap0, 0x1.b5251p-5, -0x1.ca721cp0, -0x1.8c4c78p-1, 0x1.4fa8p-1, -0x1.5ad532p0, -0x1.a1a1ep0, -0x1.4258f6p-2, -0x1.02007ep-4, -0x1.4da6fp0, -0x1.adcba6p-1, -0x1.0f297ep-2, 0x1.45cea8p0, -0x1.f287fap-2, -0x1.4c865ep-3, -0x1.65c6fep0, -0x1.75c14ep-6, -0x1.e57f7ap-1, 0x1.d32b0ep0, -0x1.de220ap-1, -0x1.f89c7cp-1, 0x1.18f4a4p-1, 0x1.356f84p0, -0x1.e1f746p0, -0x1.d7f4eep-8, 0x1.6cde32p0, -0x1.103742p0, -0x1.408f06p0, -0x1.a17ap-1, -0x1.9fbc4ep0, 0x1.b148b2p-2, -0x1.631b5cp0, -0x1.952a64p-1, -0x1.df8514p0, 0x1.e0e9ecp0, -0x1.508d54p-3, 0x1.3b09fep0, -0x1.5c6cfap0, -0x1.aa59a2p-1, -0x1.4980fep0, -0x1.811b6ap0, 0x1.171ae6p-3, 0x1.305aa6p0, -0x1.afc6f2p-2, -0x1.61bd98p-3, 0x1.a85296p-2, -0x1.92ab04p0, 0x1.8e384p0, -0x1.2f1334p0, -0x1.f2026ep0, 0x1.348274p-1, 0x1.e7e85cp-2, 0x1.8bcde8p-4, 0x1.ea72p0, -0x1.b1a768p0, -0x1.657678p0, 0x1.2d1752p0, 0x1.32cdf4p0, -0x1.1fbd6p-3, -0x1.3f1bp0, -0x1.decf8p-2, 0x1.b6fe9ep-1, 0x1.b47fa6p-3, 0x1.0f4f4ep0, -0x1.4dc7b2p0, 0x1.6f44c8p0, 0x1.845ccap0, 0x1.b8226ap-1, -0x1.ee734ap0, -0x1.49028ep0, 0x1.3acbe2p0, 0x1.e1eb46p0, -0x1.ec42d6p0, 0x1.510406p-2, -0x1.239174p-1, -0x1.df37cep0, 0x1.576204p0, 0x1.8268bp-3, 0x1.a1e12p0, 0x1.01c082p-1, -0x1.bf741ap-2, 0x1.0ffbbcp-1, 0x1.972d36p-2, -0x1.73ee26p-1, -0x1.52f45cp-1, -0x1.31d988p0, 0x1.849a5ep0, 0x1.a16d28p-1, -0x1.c9641cp-2, -0x1.704e06p0, 0x1.2b8b64p0, -0x1.fc9996p-1, -0x1.5aa0d6p-3, 0x1.c008cap-1, 0x1.4cb634p0, -0x1.b0c4e4p-1, 0x1.77cc8p0, 0x1.c6f41cp-1, -0x1.bb4302p0, 0x1.413aa2p0, -0x1.82d7d6p0, 0x1.a914f6p0, -0x1.4909b8p-4, 0x1.ff489p-5, -0x1.783ba8p0, 0x1.536176p-1, 0x1.47b0ccp-4, -0x1.d757aap0, -0x1.fc0c02p-4, 0x1.447b2ap-2, 0x1.90290ep0, 0x1.7c54b6p0, 0x1.cdf8fep-1, -0x1.bb691cp0, -0x1.0bf2f2p-1, 0x1.f8e2fp-2, 0x1.80bb24p-2, 0x1.8309aap-1, 0x1.b3c95cp0, 0x1.b6c704p-5, -0x1.13fbbep-1, 0x1.50bb86p-1, -0x1.a2c77ep0, 0x1.5b6e2ap-2, 0x1.dafc9cp-2, -0x1.422bf2p0, -0x1.f6edb4p0, -0x1.2c2d66p0, -0x1.1c4bccp-1, 0x1.464e78p0, 0x1.f7ff9cp-1, -0x1.9a3ab6p-1, 0x1.0528bap0, -0x1.a26116p-4, 0x1.f30bd8p-2, 0x1.b76beap0, -0x1.58fde4p-3, 0x1.4a813ap-1, -0x1.c1aa0cp-1, -0x1.421d12p-2, 0x1.8f79e8p-3, 0x1.b6dddep0, -0x1.a09fc6p-4, -0x1.9c1e58p-1, 0x1.94ac9ep-4, -0x1.806fa2p-4, -0x1.0c542ap0, -0x1.aa567p-1, 0x1.674b4ep-1, 0x1.e7f128p-1, 0x1.248b02p0, 0x1.ae3f6p0, -0x1.323e46p-8, -0x1.515478p0, -0x1.fdf1f6p-1, 0x1.2d6cb6p0, 0x1.78ae8ep-1, 0x1.104e56p-1, -0x1.0343aap0, 0x1.0f5d54p0, -0x1.534638p0, 0x1.465e12p0, -0x1.af1744p0, 0x1.d6f50ep0, 0x1.478b64p0, -0x1.8683eep-1, 0x1.b1f0dap-1, -0x1.e8c602p-2, 0x1.58fa18p-1, 0x1.e45d96p0, -0x1.e62cc2p-1, -0x1.44f6aep-2, 0x1.77d21p0, -0x1.995f1cp-1, 0x1.97d328p0, 0x1.16ccfp-3, 0x1.9c45aep-2, -0x1.e24d5ep0, 0x1.0a953cp0, 0x1.c54f8cp0, -0x1.f1f0bcp-1, 0x1.0ec71cp0, 0x1.5f127p0, 0x1.4e7b86p0, -0x1.8f7d8ep-1, 0x1.c60df4p0, -0x1.ca3e28p0, -0x1.eca828p-2, -0x1.390a04p-1, 0x1.4bd84ap-2, -0x1.ac1da6p0, 0x1.5458dp0, -0x1.084f8p-2, -0x1.f1739cp-2, 0x1.2b6c3cp0, -0x1.082c62p0, 0x1.46702ap-1, -0x1.186156p0, -0x1.9e73a4p-2, 0x1.c5bd6cp-1, -0x1.435688p0, -0x1.22c758p-1, -0x1.5ee272p0, 0x1.2ad966p0, 0x1.1dd024p-2, -0x1.357c5p0, -0x1.051786p0, -0x1.c8bf2p0, -0x1.862e32p0, -0x1.59eaa8p-2, 0x1.8f604ep-2, -0x1.4c6cd4p-2, 0x1.b8fa3p-1, -0x1.706d0cp-1, 0x1.575c6ep0, 0x1.5d909cp0, -0x1.93a008p0, 0x1.d65578p0, -0x1.9e082ap0, -0x1.e8d3a4p-1, -0x1.d23e9ep0, 0x1.a3076p-1, -0x1.24442ap0, 0x1.5a4d5ap0, -0x1.0fce16p-1, -0x1.bfcb1cp0, 0x1.d4fe5p-1, -0x1.b8b98ap0, 0x1.844f28p-1, 0x1.e2f1c2p0, -0x1.28469p-1, 0x1.62a898p0, 0x1.78aed8p-2, 0x1.aa455p0, 0x1.5a176cp-5, 0x1.0a68f4p-1, -0x1.bbf32ap0, 0x1.fed704p0, -0x1.764cfp-2, -0x1.a26aep0, -0x1.94b3aap-1, -0x1.7593b4p-3, 0x1.df9adp0, -0x1.6368ccp0, -0x1.6d454p-3, 0x1.e362dep-3, 0x1.82407ep-1, -0x1.8df76cp0, 0x1.f212a6p-5, -0x1.aa2d96p-1, -0x1.7b547p-1, 0x1.421fc8p0, 0x1.325104p0, 0x1.3b66fep-1, -0x1.ddb3d2p-4, 0x1.734ec2p-2, 0x1.195e1cp0, -0x1.a8624cp0, 0x1.c6667ep0, -0x1.a1041cp-4, -0x1.2b707ep-1, 0x1.21663cp0, 0x1.0a94aap0, -0x1.03658cp-2, 0x1.781502p-2, 0x1.ca1898p-2, -0x1.a43bb8p0, -0x1.120a9p-2, 0x1.e75b9cp-1, -0x1.55d5f8p-1, -0x1.5321d2p0, 0x1.301d6p-1, 0x1.0e2362p0, -0x1.f62958p0, -0x1.9ac05cp-2, -0x1.096112p0, 0x1.e93772p-1, -0x1.81ad8cp0, -0x1.d064a8p-1, -0x1.66bd9p0, -0x1.af5614p-1, -0x1.5654ep0, -0x1.bd97bcp0, -0x1.ac46e2p0, -0x1.eec6cep-3, -0x1.9b3ce2p0, 0x1.01df2ap0, -0x1.a507a4p0, 0x1.4a9c5ep0, 0x1.f723fcp-2, 0x1.9faa86p-3, -0x1.1ddbfep-2, -0x1.235e3cp0, -0x1.3ac986p-1, -0x1.ed6a66p0, 0x1.81dcd2p0, 0x1.ed8592p-2, 0x1.9809cep-1, 0x1.2efdd4p-2, -0x1.a43c48p-1, 0x1.570b12p-2, -0x1.a85ed6p-3, -0x1.19645ep0, 0x1.5d9a1cp0, -0x1.89ec74p0, 0x1.e07e9ap0, -0x1.026518p-1, -0x1.25a3fp0, 0x1.378d9ap0, -0x1.4916e8p0, -0x1.b3fe14p0, -0x1.15aaeap0, 0x1.3f45a6p0, 0x1.0c302p0, 0x1.50a846p0, 0x1.2d5852p-6, 0x1.5a44acp-2, -0x1.61143cp0, -0x1.998cp0, -0x1.6f0bb2p-1, -0x1.0a40e4p0, 0x1.90bbap-1, -0x1.62dd2cp-1, 0x1.f6570ap-3, 0x1.e5f4cap-2, -0x1.bacd12p-1, 0x1.9dc76cp-1, 0x1.5a70d8p-6, -0x1.0eec04p-1, -0x1.b23282p0, -0x1.850e68p0, 0x1.085e82p-1, 0x1.b07628p-4, 0x1.535274p0, -0x1.d7ef86p0, -0x1.e9e6cp-2, 0x1.3e7bd8p0, 0x1.136692p-3, 0x1.fc1102p0, -0x1.50e8bap-1, 0x1.f320c8p-1, -0x1.027b3cp-3, 0x1.fba2eep0, 0x1.bbf764p-2, -0x1.b3ab3p0, 0x1.166d6cp0, 0x1.2894c4p0, -0x1.23993ep0, -0x1.49726p-4, -0x1.461616p0, -0x1.bdaf08p0, -0x1.2b2338p-3, 0x1.45c13ep-4, -0x1.793704p0, 0x1.ac0ea2p0, 0x1.e85148p-3, -0x1.88f38p0, -0x1.5c6bdep-3, -0x1.a746ecp-1, 0x1.4bf80ep0, -0x1.3219bep-2, 0x1.fd24f8p-1, 0x1.30425cp0, -0x1.1e41cp0, -0x1.ddf9d8p-1, 0x1.cdf302p-1, -0x1.14ee98p0, -0x1.39f1a8p0, -0x1.e3902ep0, 0x1.89926cp-2, 0x1.6794b6p0, 0x1.035848p-2, 0x1.0d1bc8p-1, -0x1.7b2c64p-5, 0x1.7fe38ep0, -0x1.d45d64p-1, -0x1.cf986cp0, 0x1.636128p-1, 0x1.643c56p-2, -0x1.c7e228p0, 0x1.bfae6cp-1, 0x1.2972fp0, -0x1.348f3cp-3, 0x1.d7fecep0, 0x1.b651a6p0, -0x1.e79434p-1, 0x1.311a26p-5, -0x1.5e89p0, -0x1.7c0998p-1, -0x1.5ce60ep-1, -0x1.4231ep0, -0x1.0e9412p0, 0x1.80ef26p-2, -0x1.ff2daap0, 0x1.c5dbeap0, -0x1.a09186p-3, -0x1.3d12ecp0, -0x1.8b7e5ep-4, 0x1.7a924ep-3, 0x1.5fe7b2p0, 0x1.b3a6f2p-1, 0x1.74068p0, 0x1.31dcp-1, -0x1.ebb8dap-1, 0x1.4feca8p-1, -0x1.92fc84p0, -0x1.5c643ap0, -0x1.b356b4p0, -0x1.538604p-4, -0x1.4ab19p-2, -0x1.a8d31ep0, 0x1.2878dap-1, -0x1.3a26dep0, -0x1.6e9be8p0, -0x1.49bcbcp-2, -0x1.f277a4p-2, 0x1.98027ep0, 0x1.80891ap0, 0x1.d2936p0, 0x1.de72e4p0, 0x1.8e25c8p0, -0x1.6ef96cp0, 0x1.2af9c6p-1, -0x1.9622fcp-2, -0x1.cf4f8p0, -0x1.15c9d8p0, 0x1.6c2c52p0, -0x1.2c364p-2, -0x1.cb5b7ap-3, -0x1.befa36p0, 0x1.f425e8p0, 0x1.4fdfccp0, -0x1.33238ep0, 0x1.d0c892p-1, 0x1.27abe2p0, 0x1.253e14p0, -0x1.c8edfp-1, -0x1.a54a2ep-1, 0x1.a8bdc4p-3, -0x1.c9f008p0, -0x1.2bdb6ap0, 0x1.72bc0ap-2, 0x1.2e21f2p0, 0x1.a49cfp0, 0x1.f1c9e2p-5, -0x1.0d02d8p0, -0x1.828cep0, 0x1.0b7946p0, -0x1.ac4136p-1, -0x1.f4a204p0, 0x1.2c36eap-3, -0x1.000172p0, -0x1.6ae4f2p0, 0x1.da12bep0, 0x1.885aep0, -0x1.161e44p0, 0x1.1feccap0, -0x1.3770cp-1, -0x1.82399cp0, 0x1.feccp-4, -0x1.c4173ep-1, 0x1.0a16b2p0, 0x1.364dfep0, 0x1.457c38p0, 0x1.f07ccep0, -0x1.65a55ep-2, -0x1.8b8842p-1, -0x1.6c2f2ep-2, 0x1.a118f6p-2, -0x1.7dd416p-4, 0x1.50495p0, 0x1.82ce98p-1, -0x1.620e72p0, -0x1.4d75d8p-3, 0x1.7847d8p-1, -0x1.b88896p-1, 0x1.cf4dp-1, 0x1.1b1acep0, -0x1.25774ep-3, -0x1.6e521p-3, 0x1.ea6bccp-3, 0x1.da7d84p-3, 0x1.84439cp-2, -0x1.46424cp0, 0x1.09a062p0, -0x1.6d36b4p0, -0x1.fb2654p0, -0x1.9ff886p-2, -0x1.00d30ap-2, 0x1.f12cf8p-2, -0x1.c82e06p-1, 0x1.1078cep0, 0x1.1b72fcp-1, -0x1.bf3b74p0, 0x1.cd2da4p0, -0x1.4e84bep-1, 0x1.512eccp-2, -0x1.52eb58p-5, 0x1.f53deep-1, -0x1.39d5dcp-2, -0x1.0e522ap-1, 0x1.a3759p-1, 0x1.b1179cp0, 0x1.55d738p0, 0x1.3a2616p0, -0x1.bf46bap0, -0x1.83e10cp-3, 0x1.1c05f6p0, -0x1.fa6046p-2, -0x1.32946ap0, 0x1.9abbb2p-1, -0x1.294bc8p0, 0x1.c29932p0, 0x1.1a61e2p-9, -0x1.dc4bcp0, -0x1.6456ep-2, -0x1.53e3dep0, -0x1.78aeb8p-1, -0x1.56ee72p-3, 0x1.07f8f4p-2, -0x1.9b94c8p-1, -0x1.89f8a2p-1, 0x1.6c139cp-3, -0x1.8d7df2p0, 0x1.e3eb12p-1, -0x1.a2e36ep0, 0x1.a7e22p-1, 0x1.af1894p-1, -0x1.5ff906p0, 0x1.dd797ap-1, 0x1.b3fdap-4, -0x1.fc7758p-1, 0x1.3aad04p-2, -0x1.d9c096p-1, -0x1.6030cep0, -0x1.bedb98p0, 0x1.c71892p-6, -0x1.04610cp0, -0x1.034014p0, 0x1.b745dep-6, 0x1.4cdb2ep0, -0x1.601564p0, 0x1.0956b4p-1, -0x1.906ec2p0, -0x1.51ef56p-2, 0x1.04979ep-8, -0x1.02fdfep-1, 0x1.271ef4p-1, 0x1.dd7a12p-3, -0x1.d533b4p0, 0x1.e8827ap0, -0x1.06e6c4p-1, -0x1.35e19ap-2, 0x1.18313cp0, -0x1.67b20ap-1, -0x1.f90a7ep0, 0x1.6b7e28p-1, -0x1.a5afcap0, 0x1.c745a8p-1, 0x1.794aa4p-2, 0x1.d76156p0, -0x1.8202b2p-1, -0x1.8a8d2ap-4, -0x1.01d82ap-1, 0x1.c72e6ap-2, 0x1.74f17ep0, 0x1.93593ep0, 0x1.321e3ep0, 0x1.a2dbc2p0, -0x1.9756fp0, 0x1.b5651cp0, 0x1.ccc608p-5, -0x1.72f222p-2, 0x1.8b9f3ap-1, -0x1.0dba4cp0, 0x1.215a38p-7, 0x1.fe7b3p-3, -0x1.f2819p0, 0x1.e57c6cp-1, 0x1.3038d2p-1, -0x1.84db06p-3, 0x1.dfa7c8p0, 0x1.4282b4p0, -0x1.e1a7e4p-1, 0x1.73220cp0, 0x1.b2f2f2p0, 0x1.27b88ap-1, -0x1.39a2e2p0, 0x1.d80864p0, 0x1.a8db08p0, -0x1.7ff826p0, -0x1.21948cp-1, 0x1.6fe032p-1, 0x1.8444dp0, -0x1.99abb4p-2, 0x1.2aff2ap-1, 0x1.ebb90ep0, 0x1.796c48p-4, 0x1.797e0ep-1, 0x1.0b3a3ep0, -0x1.e4f69p0, -0x1.f5f88ap0, 0x1.459404p0, 0x1.6b94c2p0, -0x1.fa78cap0, -0x1.9d5912p-2, -0x1.8a195cp0, -0x1.687f02p-1, -0x1.946b18p-3, 0x1.ca9e92p0, -0x1.9fed58p0, -0x1.57f6acp-1, -0x1.2089a8p-1, -0x1.bdb55ap0, -0x1.8980c6p-1, -0x1.ba0392p-6, -0x1.98b7ep-2, 0x1.466ef4p-1, -0x1.0fe2ep-8, 0x1.ea9f2cp0, -0x1.3090acp-2, -0x1.59c69p-1, -0x1.64455p-2, -0x1.218576p0, 0x1.674bd4p0, -0x1.e7ff16p0, -0x1.e953b4p-1, 0x1.634e1p0, 0x1.628312p-1, -0x1.946f98p0, -0x1.c13ad2p-1, 0x1.b889aep0, 0x1.2c508cp0, 0x1.bc7b8ep-2, -0x1.46f4c8p0, 0x1.69f9b2p-1, 0x1.9a5fd4p0, 0x1.7325d4p-1, -0x1.5cf956p0, 0x1.5213e8p-2, 0x1.ae3b38p-2, -0x1.31f484p0, 0x1.917862p0, -0x1.02bc02p-2, -0x1.e99682p0, -0x1.eec1fcp-1, -0x1.84f5dap0, 0x1.0c68a4p0, 0x1.069fc4p0, 0x1.f3ef2ap-2, -0x1.c3e75cp-1, -0x1.1bbbfap-1, -0x1.53d82p0, -0x1.db6788p0, 0x1.341eccp0, -0x1.5429c6p0, 0x1.5602dep0, -0x1.280692p-2, -0x1.8e6428p-1, -0x1.437b1p-2, 0x1.4b79cp0, 0x1.94fcf2p-1, -0x1.107356p-2, -0x1.9a631ap-1, -0x1.1224f6p0, 0x1.34b2fep-4, -0x1.c3fee6p-2, 0x1.4946bcp-1, 0x1.c745b6p-2, -0x1.8a54b2p0, 0x1.f3ccbep-3, 0x1.ca5b52p0, 0x1.823dcap0, -0x1.b88dbep0, -0x1.21ed0ap-1, 0x1.411db6p0, -0x1.b7159ep-1, 0x1.98ad82p-1, -0x1.fb30a8p-1, -0x1.a1c1e8p-4, 0x1.56848p0, 0x1.a0dad8p0, -0x1.5378d6p-1, 0x1.b01134p-1, -0x1.81d1dp0, -0x1.8f0442p0, 0x1.26b4e6p-1, 0x1.e45c3ap-5, 0x1.1d0fbcp0, -0x1.3ddde8p-4, 0x1.570354p0, -0x1.8d6d26p-1, 0x1.4f081cp0, -0x1.d349cap0, 0x1.e45806p-1, -0x1.fdc2dap-1, -0x1.bdb8f2p-1, 0x1.269fa4p-1, 0x1.e21c0ap0, -0x1.e23136p-1, -0x1.1ee9f4p0, 0x1.61e7b8p0, 0x1.972002p-2, 0x1.f7471p-2, 0x1.b63ad6p0, -0x1.6a3312p0, 0x1.b5d882p-2, -0x1.feb0f4p-1, -0x1.28355cp0, 0x1.4aa42ep-1, 0x1.8777fcp-1, -0x1.d74a94p0, 0x1.9d2fa8p0, 0x1.86a60ep-2, 0x1.f8e19cp0, 0x1.19bc32p-1, 0x1.95c914p0, -0x1.f1471p-1, -0x1.44f7e2p-8, -0x1.87265p0, 0x1.4089f2p-1, -0x1.5221dep0, 0x1.13299ep0, -0x1.d2f4b6p0, -0x1.fe151ap0, -0x1.c82546p0, -0x1.d113a2p-1, 0x1.614c2cp-2, 0x1.a785c8p0, 0x1.5ad0acp-6, -0x1.9e5e28p0, -0x1.1a8ac4p0, 0x1.5adabap-1, 0x1.8a92bap-1, 0x1.b448fcp0, 0x1.040a12p0, 0x1.cdd88cp0, -0x1.b2091ap-2, -0x1.5c3d86p0, -0x1.95feap-2, -0x1.0bf81cp-2, 0x1.63a9c8p-1, -0x1.458d44p-5, 0x1.2300ccp-2, 0x1.d404ecp-2, 0x1.b4eb8p0, 0x1.d07c7p-3, 0x1.c083e4p-2, -0x1.87404cp-2, 0x1.6d2f2ep-1, -0x1.f92078p-4, -0x1.be3b8ep-3, -0x1.06e53ep-6, 0x1.e9c58cp-1, 0x1.82b3c2p0, 0x1.3f843ap0, -0x1.b2ea8ap0, 0x1.ab5cdep-2, 0x1.795436p0, -0x1.70123cp-1, 0x1.2b9b66p0, -0x1.79124ap-1, -0x1.fd5d8p-3, -0x1.160142p-1, 0x1.951352p0, -0x1.cfa8e8p0, 0x1.6603cap-4, 0x1.791bf8p-1, 0x1.9c366p-1, -0x1.444eb4p0, -0x1.5a5f2ap-1, 0x1.ab46d6p0, -0x1.717da2p-1, -0x1.57e344p0, -0x1.27ee54p-2, -0x1.ffec8cp-1, -0x1.55d24ep0, 0x1.e43196p0, 0x1.068686p-1, -0x1.5ea596p-1, -0x1.2eb572p-1, -0x1.5581dep-2, -0x1.2dfd04p-2, 0x1.c3b67p0, -0x1.82cc2ep0, 0x1.f8b2fap-2, 0x1.09a4b2p0, -0x1.73b4c4p0, 0x1.5aa606p-3, 0x1.fe3a5ap-2, -0x1.919686p0, 0x1.111fcep-2, -0x1.1fea6ap-1, -0x1.19b68p-1, -0x1.95299p-1, -0x1.9d1216p0, 0x1.2d22b6p0, -0x1.544d2cp-1, 0x1.1bc4p-5, 0x1.2c03fp-1, 0x1.71305ep0, 0x1.8c077ep-6, 0x1.2f7e4ep0, -0x1.828392p0, 0x1.4e48acp-1, -0x1.d20dfcp-1, -0x1.0733eap0, -0x1.ae1858p-2, -0x1.a1a1fep0, 0x1.7f8642p-3, -0x1.eaa1d6p0, -0x1.ab0bp0, 0x1.30782ep0, -0x1.14dbdap0, -0x1.358588p0, -0x1.e6393ep-2, 0x1.db69cep-1, 0x1.3f0918p-3, -0x1.830ee6p0, -0x1.1be984p-2, -0x1.99ab3ap0, -0x1.b6291ap0, 0x1.175a9ap-1, 0x1.a6dd2cp0, 0x1.c5894ep-1, 0x1.3a6936p0, 0x1.ffc704p0, -0x1.812fdcp-2, 0x1.ec442ap-2, -0x1.d65d64p0, 0x1.481f72p-1, 0x1.fbae1ap-2, -0x1.4a654cp0, -0x1.d99a6ap0, 0x1.cfff62p-3, -0x1.c8aadep-1, -0x1.431804p-5, -0x1.a71618p0, -0x1.7bc93cp0, 0x1.2ddaf6p-1, 0x1.24634ap0, 0x1.e496e4p0, 0x1.df6e8cp0, 0x1.543df4p-1, -0x1.9b459ep-1, 0x1.cfff02p0, 0x1.6e213cp0, 0x1.c8a86ap0, 0x1.950938p0, 0x1.3f3fcp0, -0x1.fc1ed4p-2, 0x1.1b90a8p-1, -0x1.1f9d5p-2, -0x1.86db22p-2, -0x1.65da1ep0, 0x1.8fdb7p-3, -0x1.1fa282p0, 0x1.7ca006p-3, -0x1.53dd04p-1, 0x1.ed939p-2, -0x1.c03f1ep0, 0x1.ce00aap0, 0x1.190bcep0, -0x1.84e652p-1, -0x1.b37086p0, -0x1.072af8p0, -0x1.d84584p-2, 0x1.9d0efep-1, -0x1.9f25acp0, 0x1.882072p0, 0x1.cef2cap-1, 0x1.125ab6p0, -0x1.168abap0, 0x1.18fbaap0, 0x1.3ea86ep0, 0x1.1ca5ecp0, -0x1.547976p0, 0x1.b86fc8p-2, -0x1.95e3ep-3, -0x1.3cae8cp0, -0x1.da5e82p0, 0x1.440742p0, -0x1.0d0032p-3, 0x1.bee01ep-3, -0x1.35697ep0, -0x1.420d64p0, -0x1.7e1b02p-3, -0x1.fed6e6p-2, 0x1.984bf2p-2, -0x1.443adcp0, 0x1.7ab9f2p0, 0x1.6a6d6p-1, -0x1.3b0356p-5, 0x1.d57cp0, 0x1.40cd72p-1, -0x1.822fc4p0, -0x1.49088p-1, -0x1.ac2974p0, -0x1.d3ef4ep-2, -0x1.b83454p0, 0x1.03921ap-1, 0x1.3e9eaap0, -0x1.916114p0, 0x1.cba49ap0, -0x1.2a6b72p0, -0x1.358a0cp-1, -0x1.7e6d38p-2, -0x1.a9030ep0, -0x1.2a30ccp-1, 0x1.02bf42p-1, 0x1.844908p-1, -0x1.7013ccp0, 0x1.8a06dp-1, 0x1.6d1a1cp-1, -0x1.92dbe4p0, 0x1.bf1e12p-4, 0x1.8f5736p0, 0x1.8f845cp0, 0x1.5f6db4p-1, -0x1.d9c8b2p-2, 0x1.cd93ep0, -0x1.b7b53ep-1, 0x1.03a87cp-7, 0x1.a51be2p0, 0x1.a0cadap0, 0x1.d4e596p-1, -0x1.28e2a6p-1, -0x1.9f5f08p0, -0x1.c7e058p0, -0x1.a5e96ap0, -0x1.04d15p-1, -0x1.1445acp0, 0x1.b8161ap-1, -0x1.2c2418p-1, -0x1.295198p-3, 0x1.466b76p0, -0x1.6ad6fap-1, 0x1.2e774p-3, -0x1.c07686p0, 0x1.da8d2cp-3, 0x1.02177ap0, 0x1.297ccep0, -0x1.afdf9ep-1, -0x1.4522eep0, 0x1.91afbcp0, -0x1.a5cdc2p-3, -0x1.f3f4aap0, 0x1.3c52ap0, 0x1.1c8eep-2, -0x1.94de2ap-1, -0x1.b31fccp0, 0x1.45a3a6p-4, -0x1.a51c82p-2, -0x1.2b27cap0, 0x1.8761p-1, -0x1.85b87ep-1, 0x1.eca098p0, -0x1.23b832p-1, 0x1.5eb6ccp-4, 0x1.8797cp-5, 0x1.bc9832p-1, 0x1.59e316p-2, -0x1.800ef8p0, -0x1.9990cp0, -0x1.db8c8ap-2, -0x1.4e3e26p-1, 0x1.2e75fep-1, 0x1.fa6256p-1, 0x1.67a966p-1, -0x1.47165p0, -0x1.5684f2p0, 0x1.cceca2p-1, 0x1.526dc8p-1, 0x1.e237a6p0, 0x1.a0892ap-5, 0x1.c5c2ep-1, -0x1.89f244p-2, 0x1.f3115p-1, 0x1.8f3bcap-1, -0x1.1615bap-3, -0x1.28524ap-3, 0x1.3417c4p-1, 0x1.a1c6fcp-1, 0x1.907766p-2, 0x1.eabf8p-2, -0x1.eef8eep0, -0x1.a33e76p-2, -0x1.1ed10cp-1, -0x1.224d5p0, 0x1.c194d2p0, 0x1.5104d4p-1, 0x1.86474p-1, 0x1.bc4da2p0, 0x1.4a5c72p-1, 0x1.c25408p0, -0x1.701d68p0, 0x1.84084p0, 0x1.4bde04p0, 0x1.401f9cp-2, 0x1.7d2f7ep0, -0x1.72541p-2, 0x1.3aeafep-1, 0x1.090638p-1, 0x1.4c28fap0, -0x1.e77016p-1, -0x1.6ad2f4p0, 0x1.13b0bap-2, -0x1.22ef86p0, 0x1.12de9ep-1, 0x1.36386ep0, 0x1.9fc894p0, -0x1.cc6f24p-1, 0x1.47112ap-1, 0x1.e180e2p-3, 0x1.90115ap0, -0x1.1a58b4p-1, 0x1.41726p-3, 0x1.d25658p0, -0x1.3c73fp-1, -0x1.43b908p0, 0x1.5aa82cp-1, 0x1.825118p-3, 0x1.22879cp-3, 0x1.6df808p0, -0x1.95d776p0, 0x1.0f032cp-1, 0x1.af647p0, 0x1.461ce2p0, -0x1.2c751ep-1, -0x1.0ff6b2p0, -0x1.d7e996p-1, -0x1.5e59a2p-7, -0x1.9b9d6p0, 0x1.6c724p-2, 0x1.36421cp0, -0x1.47e6c6p-3, -0x1.fa9ebep0, 0x1.ed525ep-2, -0x1.69f86p0, 0x1.7baf96p-2, 0x1.8b0732p-2, -0x1.f57c56p0, 0x1.931bdp-1, 0x1.e2fbeap-1, 0x1.87558ap0, -0x1.067184p0, -0x1.30ce88p-2, 0x1.2cdd3cp0, -0x1.c21bdep0, -0x1.2c6566p0, 0x1.aab9f8p-1, -0x1.d8ed2p-3, -0x1.e2597ap0, -0x1.b8326p0, -0x1.8dc5a2p-6, -0x1.1b124ap0, -0x1.ad417p0, -0x1.b29d5p0, -0x1.76fe3p0, -0x1.f148fp-1, -0x1.a2e88ep0, 0x1.7fca26p0, 0x1.8769ecp-1, 0x1.5c5b3ap-1, 0x1.584faap0, -0x1.c8c83cp-1, -0x1.6b147cp-6, 0x1.0eeaap-2, -0x1.92244ep-3, 0x1.ceeb4cp0, -0x1.bdcbcp-4, 0x1.1e824ap0, 0x1.ccee2ep0, -0x1.a0bbe2p-1, 0x1.dd371ap-1, 0x1.9862bp0, -0x1.2c3a9p-1, -0x1.1162eep-5, 0x1.8ab37ep0, -0x1.740d42p0, -0x1.699f2ap0, -0x1.3cc9cap0, -0x1.bf5ec4p-1, -0x1.598c1cp-4, -0x1.7a91p0, 0x1.0c889ep0, 0x1.c76004p-7, -0x1.b6a308p0, 0x1.2c001ap-3, 0x1.dee9c4p-3, 0x1.0d8b4ep0, 0x1.160834p0, 0x1.17464ap0, -0x1.0398d2p-1, 0x1.98c9aap-1, -0x1.e8aeeep0, 0x1.ddcb7ap0, 0x1.b4a2b8p0, -0x1.3c3c74p0, 0x1.6f313p0, -0x1.59420ep0, 0x1.628966p-2, 0x1.448e9ap-3, 0x1.7b046cp0, -0x1.535e6ep-1, 0x1.79301p0, 0x1.293d52p-6, 0x1.67ad86p0, 0x1.91e08ap-3, 0x1.f4e522p-2, 0x1.c4ca1ap0, -0x1.5415f2p-1, -0x1.fd5e46p-2, -0x1.215f0ep0, 0x1.11c7dep0, -0x1.f9f98ep-1, -0x1.3b95ep-8, -0x1.9327e6p-1, -0x1.8657acp0, -0x1.2d3dfcp-3, 0x1.2f641ap-1, -0x1.d90bcp-5, -0x1.b62842p0, -0x1.0f54c6p0, 0x1.ce16c2p0, -0x1.051474p-4, -0x1.bde34p-1, 0x1.6d238ep-2, -0x1.b41eb2p0, 0x1.0e0b12p-1, -0x1.765496p0, -0x1.d26bacp0, -0x1.f58e3p-2, 0x1.1fba58p-1, 0x1.89550cp-4, 0x1.f2dd1cp-2, -0x1.7ba6dcp0, 0x1.baf9bp0, -0x1.6c777ap0, 0x1.fc2348p0, 0x1.793ecep-1, 0x1.2ac858p0, 0x1.494e2cp0, -0x1.639842p0, 0x1.e2f326p-5, -0x1.bc9248p0, 0x1.285d22p-1, -0x1.eb577ep-1, -0x1.ac2f86p0, 0x1.ef7c66p-1, 0x1.592fd4p0, -0x1.356892p-2, -0x1.d0fae4p-2, -0x1.f1abd8p0, -0x1.a68c64p0, -0x1.a4e86ep-4, -0x1.2afdep0, 0x1.6dfa2cp0, -0x1.878d52p-1, -0x1.d4eb2cp-5, -0x1.c6f9d8p0, 0x1.048beap0, -0x1.f76a9cp-1, 0x1.03a98cp0, -0x1.c90cf4p-1, -0x1.daa2d4p-1, -0x1.d90cp0, 0x1.0cef06p0, 0x1.9229bp0, 0x1.c6c3bcp0, 0x1.b23f7ep0, -0x1.fc9e5cp-1, -0x1.8847fep0, 0x1.056c34p0, -0x1.45b4b8p0, 0x1.6fb608p0, -0x1.0d8854p-2, -0x1.484498p-1, -0x1.231c62p-2, -0x1.0772a8p-2, -0x1.8a8dbcp-1, 0x1.702046p0, 0x1.c1eed6p-3, 0x1.334d38p-1, 0x1.c25ea4p0, 0x1.fec5aep-1, 0x1.2f498cp-3, -0x1.b3069p0, -0x1.b14c3cp-3, -0x1.8d70aep-5, 0x1.ca276p-4, -0x1.fd2fep0, -0x1.f6b982p-2, -0x1.55eac4p0, -0x1.4256dcp0, -0x1.68ab6cp0, -0x1.bfc334p-1, 0x1.2dff7p-2, 0x1.bccfe8p0, 0x1.84f39ep-4, 0x1.b22a8p0, 0x1.ca45dp0, -0x1.9cb08p-1, 0x1.74ac76p-3, -0x1.aecf0cp0, -0x1.28df62p0, -0x1.6040f4p0, -0x1.8ff9fcp-1, -0x1.dda1dcp-4, 0x1.9bd0fap-2, 0x1.20fbd8p-2, -0x1.5dc1e2p-1, 0x1.13a034p-1, -0x1.99582p0, 0x1.4868ecp0, -0x1.3fdc42p-2, -0x1.b23ccep0, -0x1.2c541p0, -0x1.3df282p-1, -0x1.e4b39p0, 0x1.7fdee4p-4, -0x1.ab7aaap0, 0x1.3c20a4p0, 0x1.eaff5p0, 0x1.d2cecap0, -0x1.cee992p-1, 0x1.566072p0, -0x1.f7c9d6p-1, -0x1.57a0fep-3, -0x1.c597e6p-1, -0x1.26aac2p-2, 0x1.1c5f32p-1, 0x1.d3754ep0, -0x1.c7459ap-1, -0x1.b44ep0, -0x1.9d8d9cp-4, -0x1.387f7ap-3, 0x1.d67a1ap0, 0x1.e2ff3cp0, 0x1.a25514p0, -0x1.e8f59ap0, 0x1.e6f99ap-2, -0x1.9bd2d6p0, -0x1.6fcbcap0, 0x1.2d836ep0, 0x1.b6ba02p0, 0x1.f7da6cp-4, 0x1.1f9adap0, 0x1.f9f438p-4, 0x1.db661p-4, -0x1.8626e8p0, -0x1.876c16p-1, -0x1.395bbp0, -0x1.e3a52p-3, -0x1.3ff32cp-1, 0x1.33c8cp0, 0x1.a42aep-3, 0x1.c9f526p0, 0x1.8af614p-2, -0x1.289de6p0, -0x1.0cda2p0, -0x1.50e7a2p0, -0x1.043ba8p-1, 0x1.374088p-6, 0x1.949216p-1, -0x1.8e61a2p-2, 0x1.24dea2p0, -0x1.63c5d6p0, 0x1.458698p0, -0x1.772bbp-5, -0x1.eaaf48p-3, 0x1.4544fcp-4, 0x1.efb10cp0, -0x1.71893cp-1, 0x1.ab4ea2p-2, 0x1.2bace2p-1, 0x1.20ec3p0, -0x1.29906p0, 0x1.6f9b82p-3, -0x1.042ea2p0, 0x1.58a2cp0, 0x1.0002cap-1, -0x1.9a656ap0, -0x1.39e734p0, 0x1.a8cadep0, 0x1.34b51cp-1, 0x1.15ee0ap-3, 0x1.8f45a2p-5, 0x1.8931a8p0, -0x1.fd0bb8p0, -0x1.65f0a8p-1, 0x1.05e6f4p0, 0x1.6467cap0, -0x1.eb2228p-3, -0x1.c558c2p-1, 0x1.91c3ecp-1, 0x1.85bf78p-4, -0x1.219bdep0, 0x1.44bd5p0, 0x1.90392p-2, -0x1.77563cp0, 0x1.b2910ap-7, 0x1.81029p-4, -0x1.c02a64p0, -0x1.5275p0, 0x1.a607a6p-1, -0x1.5b9914p0, -0x1.987dap0, 0x1.975ac4p-1, -0x1.79af28p-2, 0x1.f78eccp-1, 0x1.895e4ap0, -0x1.fa8356p0, 0x1.dd94f8p-2, 0x1.34c408p-1, -0x1.fa4a2cp-5, -0x1.76bf36p-2, 0x1.01d706p0, 0x1.f885ap-1, -0x1.0c1498p-3, -0x1.a2465p-3, -0x1.08a49cp0, -0x1.594cap-1, -0x1.a41dccp-1, 0x1.7f0308p0, -0x1.73b27cp0, -0x1.97522p0, -0x1.108bdap-4, -0x1.01a97ep-2, -0x1.08be62p-1, -0x1.9ef766p-2, 0x1.71ffe8p-1, -0x1.cb0dd4p0, 0x1.f50a3ep0, 0x1.e30fc8p-1, -0x1.3b1cfp-3, -0x1.89501p0, 0x1.e3554ap0, -0x1.8fbc42p0, -0x1.bc048p-3, 0x1.70f61cp0, 0x1.f5e27p0, 0x1.f3da7ep-4, -0x1.b386eap0, 0x1.53cd1ap0, 0x1.340088p0, -0x1.bdf1dp-3, 0x1.e344d8p-3, 0x1.6a21f4p0, -0x1.20b98ep-1, 0x1.0be6e4p-1, 0x1.7fa6fep-2, -0x1.474d52p-1, -0x1.ee0bcep0, 0x1.f44a94p0, 0x1.550ccap0, -0x1.a209bep0, 0x1.6f24f8p0, 0x1.a5e40ap-1, -0x1.76353ap-1, 0x1.41242cp0, 0x1.ec3546p-1, -0x1.40cc28p-1, -0x1.bde7bep0, -0x1.3d567p-2, 0x1.844cdap0, -0x1.60197ep0, 0x1.e61e34p-1, -0x1.596aaap0, 0x1.55bc52p-3, 0x1.43fc54p0, 0x1.9ed28ep-1, -0x1.60e146p-1, -0x1.1a6a94p0, -0x1.bcc6ep0, -0x1.143894p0, -0x1.9713a2p0, 0x1.d44204p-3, -0x1.b990cp-1, 0x1.90c35p-1, 0x1.b0361ep0, 0x1.e52d7cp0, 0x1.35c80ep-1, 0x1.f4b2fp-1, 0x1.be61ap-1, 0x1.b979cp0, 0x1.578bccp0, -0x1.008768p0, 0x1.068a2p0, -0x1.cbd912p0, 0x1.d62f9p-1, 0x1.cf23a6p-2, -0x1.6ca072p-4, -0x1.5ebfe4p0, -0x1.67e8ap0, 0x1.7e17cep-2, 0x1.c5bb36p-2, -0x1.7a4618p0, 0x1.c398aep-1, 0x1.166962p-1, 0x1.12f9a4p-2, 0x1.d950eep-1, -0x1.8dc27ep-1, 0x1.319202p0, 0x1.960b94p0, 0x1.93816cp0, 0x1.655276p0, 0x1.bd8232p-1, -0x1.d1e96ep-3, -0x1.d11d9ap-1, 0x1.9c3034p-2, -0x1.f6a76ap-2, -0x1.42408cp-2, 0x1.0e588p-2, 0x1.5ccd5ap0, -0x1.cc5538p0, 0x1.dab628p-2, 0x1.5d4f7cp-7, 0x1.3edb8ap-1, -0x1.956482p0, 0x1.7e85dp0, 0x1.b0a24p-1, -0x1.449ee6p-1, 0x1.ccc39ap0, -0x1.4f639p0, 0x1.d75424p-2, 0x1.08490ap0, -0x1.aa561cp0, -0x1.93f3dep0, -0x1.07621ap-1, -0x1.c82ffcp0, -0x1.c03896p0, -0x1.83896ep0, 0x1.dbd482p-1, -0x1.0cedc6p0, -0x1.fda356p0, -0x1.fb3886p-1, -0x1.d90ba4p-3, 0x1.826dfep0, -0x1.7af602p-1, -0x1.d94f02p0, 0x1.9f4ep0, -0x1.4a0e5cp-7, 0x1.836ba8p0, 0x1.943ba2p0, -0x1.c3303p0, 0x1.935aecp-2, 0x1.13b4c8p0, 0x1.890696p-2, 0x1.441178p0, -0x1.17e0bap-1, -0x1.f2c3f8p-2, -0x1.70e538p0, -0x1.29ee9cp0, -0x1.7c7c4cp0, 0x1.f27e98p-2, 0x1.4b3644p-3, 0x1.f6686cp0, -0x1.e57c16p0, -0x1.6774eep0, 0x1.6f288ap0, 0x1.ed0252p-1, 0x1.0b2f9cp-4, 0x1.81d338p0, 0x1.983174p-1, -0x1.651288p0, 0x1.17a304p-2, 0x1.c73aa2p0, -0x1.da879ap0, -0x1.e20924p-1, -0x1.afa7d8p0, 0x1.a7c666p0, 0x1.276a8ap-2, -0x1.c60cep0, -0x1.1ce5ep-1, 0x1.dd595cp0, -0x1.dceb44p0, -0x1.66636ep-1, 0x1.4cb9fep0, -0x1.7d8ed2p-2, -0x1.604fdep0, 0x1.7793a2p0, -0x1.95ff58p-2, -0x1.05c61ap0, 0x1.181744p-4, -0x1.e20a78p0, 0x1.60577p-3, 0x1.230692p0, -0x1.0082f8p0, 0x1.4b6d2p0, -0x1.0928d6p0, 0x1.bf2ecep0, 0x1.d3f20cp-1, 0x1.1027e6p-3, 0x1.1a441ep-1, 0x1.84cccap-3, -0x1.ac4d6cp-1, -0x1.498ccap0, 0x1.1ad018p0, -0x1.4117dap0, 0x1.305918p0, -0x1.f00f7p0, 0x1.bf1df2p-2, -0x1.e8e01ep0, -0x1.64a396p0, 0x1.b8ecfp-3, 0x1.fa87fp-1, 0x1.362778p-4, 0x1.0d66fep0, 0x1.482b36p0, 0x1.e530b8p0, 0x1.1a006p-1, 0x1.f153aap0, -0x1.233acap0, 0x1.9dbc9p0, 0x1.168abap-1, 0x1.9d11f2p0, -0x1.28af84p0, -0x1.ff9ca2p0, 0x1.dff044p-1, -0x1.2e098ap-1, 0x1.071064p-1, 0x1.d7f038p0, -0x1.c691dep0, 0x1.5515d8p-2, -0x1.9375aap-3, -0x1.cf680ap-2, 0x1.2a160ep0, 0x1.fd6e2p-4, -0x1.68506p-1, -0x1.d5ba36p-1, 0x1.35b544p0, -0x1.718214p0, 0x1.0798cap-1, 0x1.cb3dbep0, 0x1.f0bb9p0, -0x1.24c194p0, -0x1.b85cd4p-1, 0x1.b26d7p-2, -0x1.2be8a6p0, 0x1.ec30bp-2, -0x1.5b97e8p0, 0x1.bc266ep-1, -0x1.d6912cp-4, 0x1.5f6458p0, -0x1.affd3cp-2, 0x1.8f40bap-2, -0x1.29d814p-1, -0x1.73641ep-1, 0x1.b5f5d6p-1, -0x1.bbf884p0, -0x1.c851ccp0, 0x1.ed372p-3, -0x1.42c182p0, 0x1.6d1e5p0, 0x1.870cfap0, -0x1.09ce72p-1, -0x1.1703d2p0, -0x1.11012ap0, 0x1.262f72p-2, -0x1.8856dap0, 0x1.3d63d8p-2, -0x1.627ce6p0, 0x1.6b0ef8p0, -0x1.d71774p0, -0x1.0b9a2p0, 0x1.a5028ep-2, -0x1.f3a3bcp0, 0x1.fe14ep0, 0x1.442612p0, -0x1.5c20c2p-1, 0x1.044caep0, 0x1.45428cp0, 0x1.b3ad52p0, 0x1.6cd838p0, 0x1.f9c5f2p0, 0x1.afded2p0, -0x1.5eec32p-1, 0x1.e4a01p-2, -0x1.ffd5eap0, -0x1.61876ep0, -0x1.384e0cp-1, -0x1.3168eap0, 0x1.e6ee46p-3, 0x1.6f753ap-1, 0x1.405c4cp0, -0x1.b7fa9ap-1, -0x1.63b652p0, 0x1.3dc5fap-1, -0x1.20b1ccp-1, -0x1.e789a2p0, 0x1.f6d5d8p-1, -0x1.b1408ap0, 0x1.76cc3cp-3, -0x1.0046c8p-2, 0x1.fefcaep-1, -0x1.fcff28p0, -0x1.f541c8p-3, -0x1.105c7ep-2, -0x1.b08f4cp0, -0x1.343b9ap-1, -0x1.c159f4p0, 0x1.b333c8p0, -0x1.3d2ef4p0, 0x1.4ebdc8p0, -0x1.e91e26p-2, -0x1.f5dd16p-3, 0x1.bd31cap0, -0x1.1d4de4p0, 0x1.188fa4p-7, 0x1.991d04p-1, 0x1.73a03p0, 0x1.81fb98p0, 0x1.d2f708p0, -0x1.f37dc8p-1, -0x1.4f5a5ap-1, 0x1.1524b8p0, -0x1.bcf8a4p0, -0x1.a1ba1p-1, 0x1.ab44acp-2, 0x1.d90872p0, -0x1.ec793cp0, 0x1.5a71cap-2, 0x1.e0389p-1, -0x1.11e496p-1, -0x1.13ab14p-2, -0x1.b2ecfcp0, -0x1.c00ce6p0, 0x1.13a37p0, 0x1.5c58acp-1, -0x1.8d5864p-1, -0x1.bc25dcp-4, -0x1.8d257ep0, 0x1.281004p-3, 0x1.229168p0, -0x1.5f3922p0, 0x1.51e4bp0, -0x1.6bcb84p-3, 0x1.2a8c28p0, -0x1.898e88p0, 0x1.7932f6p0, -0x1.ef09dcp0, 0x1.498bfap0, 0x1.7977d8p0, -0x1.deb64ep0, 0x1.44f29ep0, 0x1.d17492p0, -0x1.a29b92p0, -0x1.6031dcp-2, -0x1.ed1c6p0, -0x1.fe79p-1, -0x1.c55f68p-4, 0x1.7bb412p0, 0x1.1585bcp-1, -0x1.8d0d44p-4, 0x1.52126cp-1, -0x1.813976p-2, -0x1.281e9p-1, 0x1.44789p-1, 0x1.117e84p-1, -0x1.e6c462p0, 0x1.1e0d7ep0, -0x1.70131cp-1, 0x1.07e106p0, 0x1.889f4cp-1, -0x1.3dc684p0, -0x1.5764a8p-1, -0x1.1ac952p-2, 0x1.50d04p-4, -0x1.e9055p0, -0x1.2823f2p0, 0x1.8803fcp0, -0x1.677b1ep-2, 0x1.12f6c8p0, 0x1.1b6328p0, 0x1.27586cp-1, -0x1.ad34fp-1, -0x1.1efde8p-2, -0x1.1a17bp0, -0x1.a72feap-1, -0x1.eb8546p-2, 0x1.4c525ap-1, -0x1.9ce048p0, 0x1.55927cp0, 0x1.923d56p-1, 0x1.9ecf76p0, 0x1.12c5dap0, -0x1.7cbe56p0, 0x1.50362ap-3, 0x1.0eec7cp0, 0x1.5b5cdap0, 0x1.ef3c48p-1, 0x1.e36d44p0, 0x1.9a3e96p-1, -0x1.bb4d72p0, -0x1.f406aap-1, 0x1.219b7cp0, 0x1.dba176p-2, -0x1.d0921p-2, -0x1.35a318p-3, -0x1.8d6012p-9, 0x1.ef803ep-1, -0x1.6df9f6p-1, 0x1.d90612p0, -0x1.ad2e5p-1, 0x1.6ea3c2p-1, -0x1.e9101ep-2, 0x1.404812p0, 0x1.4185c8p-3, -0x1.5ae84cp-1, 0x1.d65a1ap-1, 0x1.1140e2p-1, 0x1.e0a828p0, -0x1.f53614p-1, 0x1.8cf7acp-1, 0x1.c0c0ap-1, 0x1.2d8944p-1, 0x1.3fb6c6p0, -0x1.69ee68p-2, 0x1.dcc79ap0, 0x1.c83a78p0, 0x1.4cffcp0, -0x1.4a59e8p0, 0x1.ec6502p-3, -0x1.ef6554p0, -0x1.e0b454p-2, 0x1.c00dd8p0, 0x1.fbc966p0, -0x1.1cc604p0, 0x1.5ce66ep-1, -0x1.9b267cp-1, 0x1.798eecp0, -0x1.9b391ap-6, 0x1.c4470cp0, 0x1.7d955cp-2, 0x1.70c6bcp0, 0x1.d51208p-1, 0x1.fa361ap0, -0x1.903eaep0, -0x1.27d78ap-1, 0x1.2bea14p-2, 0x1.104126p-1, -0x1.8a1cf2p-1, -0x1.10b686p-1, 0x1.a96058p0, -0x1.3b0a42p0, -0x1.0f6a54p-2, 0x1.511d0ap-2, 0x1.f819bcp0, -0x1.32bf6p-1, 0x1.e9afdcp-2, -0x1.9c9a7ap-1, -0x1.0be088p0, 0x1.e8d76ap-2, -0x1.7b1604p0, -0x1.60ccdep0, 0x1.f85838p0, 0x1.615308p0, 0x1.16e382p0, 0x1.ec5c26p0, 0x1.b1517p0, 0x1.bd9c1ep-5, 0x1.dbae64p0, -0x1.b11316p0, -0x1.033e08p0, -0x1.79bb9p-2, 0x1.572e42p-1, 0x1.68b1cep0, -0x1.c434a6p0, 0x1.f325ap-1, 0x1.243162p0, 0x1.516a06p-3, 0x1.b45208p-2, -0x1.0c3adep0, 0x1.b5fa2cp0, -0x1.375a4p-1, 0x1.2b24ccp0, 0x1.fc6f1ep0, 0x1.78feacp0, 0x1.2addcp-2, -0x1.ecfc92p-2, -0x1.b4856ep0, -0x1.e629e6p0, -0x1.ef75ecp-1, 0x1.0096c4p-4, 0x1.655ee8p0, 0x1.7c9bb4p-1, 0x1.ccfed4p0, 0x1.5426f6p-1, 0x1.b86ddep-1, -0x1.b7927p0, -0x1.59695p0, -0x1.43d988p0, 0x1.c9d612p0, -0x1.fc02a2p0, -0x1.c46f88p-4, -0x1.e35608p0, 0x1.f1fe86p0, 0x1.6d2518p-2, 0x1.102edcp-4, 0x1.d1ee6cp0, 0x1.87e224p-1, -0x1.b4a23p-1, -0x1.a14fep-1, 0x1.c986fap-1, 0x1.34b262p0, 0x1.26ea6ep-1, -0x1.6f9d14p-3, -0x1.e01ff2p0, -0x1.f8bf5cp-1, 0x1.dba7e2p-1, 0x1.1a2c22p-1, -0x1.a1409cp-1, -0x1.721fa2p0, -0x1.d4d34ep0, 0x1.a3393ap-1, 0x1.ed58ccp0, 0x1.bb4138p-1, -0x1.055ee4p-2, -0x1.15bb16p0, -0x1.6be264p0, 0x1.6ba13ep0, -0x1.a351ep-1, 0x1.4dfda4p0, -0x1.a95c4ap0, 0x1.21d8d2p0, -0x1.82ca06p-1, 0x1.3ef6cp0, 0x1.b745f2p-1, 0x1.76ce36p0, -0x1.69caf6p-3, -0x1.435df8p0, 0x1.966ba2p-1, 0x1.2a9d48p0, 0x1.47db8p0, 0x1.dad3b2p-1, 0x1.8a87e4p0, 0x1.ec9502p-1, 0x1.c51f1p0, 0x1.b7b812p-1, 0x1.d0a104p-1, -0x1.bab2d4p-1, 0x1.b6eee2p-1, 0x1.bf07e8p-1, -0x1.1cbbb4p0, -0x1.1488f4p-3, -0x1.ca5f9p0, 0x1.a39b6ep-1, -0x1.f4c94ap-1, -0x1.e66b34p0, -0x1.97d9fap-1, -0x1.33f5fap0, -0x1.17568ap0, -0x1.a207ep0, 0x1.a480acp-1, -0x1.611702p0, -0x1.2b8cecp-2, -0x1.b960b4p0, 0x1.e1bff6p-2, 0x1.fa027p-1, 0x1.8d09dap0, -0x1.7266d2p0, 0x1.5fea02p0, 0x1.4df992p-2, 0x1.c73be2p0, 0x1.d23e84p-1, -0x1.2d0baap0, -0x1.cd4132p0, 0x1.ad14f8p-1, -0x1.21e69ep0, -0x1.f4e21cp-1, 0x1.f27f8cp-3, -0x1.13794p-2, 0x1.3a8faep-1, -0x1.5e231ap-1, 0x1.49446ap-1, 0x1.0d33fp0, -0x1.5f2494p-1, 0x1.dd653p-1, -0x1.94cb62p0, -0x1.020894p0, 0x1.f90f8p0, 0x1.c6e74p-1, 0x1.1dcb28p0, 0x1.b93828p0, 0x1.360fb4p0, -0x1.64cc22p-1, 0x1.c0125cp-1, -0x1.6923b6p-1, 0x1.3f0f28p0, -0x1.90aefep0, -0x1.e8e1f4p-2, -0x1.03ca6ep0, -0x1.4ef296p-2, -0x1.b93592p-2, 0x1.0db428p-4, -0x1.0d76cap0, 0x1.849192p-2, -0x1.f74424p-1, 0x1.e901dp0, -0x1.6ff56p0, -0x1.6f3b7ep-2, -0x1.457622p0, -0x1.386dbp0, -0x1.a3961ep0, -0x1.ca220ep0, -0x1.249fb8p-1, -0x1.7320ccp0, 0x1.4508ep0, 0x1.bd9f76p0, 0x1.288b86p-4, 0x1.a42f9cp0, -0x1.446408p0, 0x1.dde32ap0, 0x1.fa9d9ep0, 0x1.eb50d8p-1, 0x1.24f6b6p0, -0x1.3fecacp-1, 0x1.d72968p0, 0x1.18228cp-2, 0x1.e1148ap-1, -0x1.6b5342p0, 0x1.685f44p-1, -0x1.e76c06p0, -0x1.3f653ap0, 0x1.6aa484p0, 0x1.06831p-4, 0x1.69d41ep0, 0x1.e262c6p-2, -0x1.006b4cp0, -0x1.2667dep-1, 0x1.0ce03cp-1, 0x1.36ebe8p-1, -0x1.066bfap0, 0x1.bbe7e2p-2, -0x1.3f33bp-2, 0x1.b1641cp-1, -0x1.e1af8ep-2, -0x1.c05a64p0, -0x1.f6ea6ap0, 0x1.ccf3d2p0, -0x1.5fa32cp0, 0x1.f26208p-1, 0x1.90113ap0, 0x1.b7e26ap0, 0x1.bfd39cp-1, 0x1.07d3dep-2, -0x1.2253e2p0, -0x1.052ce2p0, -0x1.6c9ba2p0, -0x1.60809cp-1, 0x1.177d5p0, 0x1.0959a8p-2, 0x1.07e854p-1, 0x1.716d2p-1, 0x1.7a09ap-1, -0x1.58d5f4p0, -0x1.5df1dep-5, -0x1.4a9bdp0, 0x1.d4660cp0, -0x1.1aa564p-2, -0x1.7e5efcp-5, 0x1.31ce06p-1, 0x1.e341d2p-1, -0x1.b0c9aep0, -0x1.c397a4p-1, -0x1.6f576ep-1, -0x1.6e12d6p0, 0x1.8e9cf2p0, 0x1.7535a8p-2, -0x1.5dfe38p0, -0x1.ef0bcep-3, -0x1.3ad09p-5, -0x1.888a18p0, 0x1.40df18p0, -0x1.4367f8p-1, -0x1.76b0a6p0, -0x1.b29c1ap0, -0x1.fc137ap0, 0x1.95fc1p0, 0x1.5a286ap-6, -0x1.871d9ep-1, 0x1.e7ddb4p0, 0x1.bac01ep0, -0x1.c07ec4p0, -0x1.ebbfdap0, 0x1.29fa0cp0, -0x1.034dep0, -0x1.71e9e4p0, 0x1.4f1becp-1, -0x1.0f11cep-1, 0x1.0e287ap-5, 0x1.762af4p-1, -0x1.afb344p0, -0x1.64d986p0, -0x1.52961p-1, -0x1.b70c02p-3, -0x1.339176p0, 0x1.ae68fap0, 0x1.bc3be4p0, -0x1.91095cp-1, -0x1.a403c2p-1, 0x1.7e1b2p0, -0x1.852206p0, 0x1.8cf658p0, -0x1.b80f36p-2, 0x1.4ff8f8p-2, 0x1.a6f342p0, 0x1.17b558p0, -0x1.1f868ap-1, 0x1.dc23f6p0, 0x1.04f6ap-2, 0x1.dee01ap-3, 0x1.0c902p-1, 0x1.3668cep-4, -0x1.f351f4p-3, 0x1.f58afap0, 0x1.63db8cp-1, 0x1.7e8e3ap0, 0x1.23133ap0, -0x1.51292ep0, 0x1.8aa8d6p0, -0x1.8681acp0, 0x1.63f5a8p-1, -0x1.e637d4p0, 0x1.73654cp-6, 0x1.925c0ep-1, -0x1.0b17ccp-3, 0x1.02b8ecp-2, -0x1.9e4282p0, 0x1.ca5a98p0, -0x1.5c6fe6p0, -0x1.ee1146p-2, -0x1.d0694cp0, -0x1.17d31ep0, -0x1.58447ap-2, 0x1.852ccep-1, -0x1.cb824p-2, -0x1.1a0d88p-1, 0x1.fa4574p0, -0x1.f714e6p-1, 0x1.2bd514p0, 0x1.8708f8p-2, -0x1.158d8p0, -0x1.ffbcb6p0, 0x1.84d5a8p0, 0x1.1c17aep-5, 0x1.b46cf4p-2, -0x1.15ec24p-1, -0x1.3435dp-1, -0x1.9674eep0, 0x1.4ea01ep0, 0x1.d3e4aep-2, 0x1.276902p-2, -0x1.b3407ap-1, 0x1.9f32b6p-1, -0x1.5518d4p-4, 0x1.42a9dep0, 0x1.d4d3f8p0, 0x1.eafa72p-3, -0x1.2655c8p0, 0x1.c53d4ep0, 0x1.e2608cp0, 0x1.031dcap-4, 0x1.560a7ap-4, -0x1.feb7eap-2, -0x1.aff3eep-2, 0x1.17f8a4p-2, -0x1.0f998p-5, 0x1.84e994p-1, -0x1.33f7e4p0, 0x1.3e7584p-1, 0x1.dc6cdp-2, -0x1.4d651cp0, 0x1.635f32p0, 0x1.dee16p0, 0x1.82ad7cp-2, -0x1.fc4b5ap0, 0x1.9c44ecp-1, 0x1.c1447ap0, -0x1.923498p0, -0x1.15e582p0, 0x1.0c674ap-2, -0x1.fcc012p-4, 0x1.15f0ap0, 0x1.fda48ep-1, -0x1.facbecp0, 0x1.654682p-3, 0x1.0c54ap0, -0x1.e7b202p0, 0x1.c916a4p0, 0x1.00b7c8p0, 0x1.c6273cp-2, -0x1.93c7eap0, -0x1.f7cbf6p-2, -0x1.c237b6p0, -0x1.a67694p-1, -0x1.85027ep-1, -0x1.241f8ap0, -0x1.c560dp-4, 0x1.5cf176p0, -0x1.e5cf14p-3, -0x1.eb156ap-2, 0x1.da5646p-2, 0x1.6f18e2p0, -0x1.c413c6p0, 0x1.a0f312p0, 0x1.65afacp-1, -0x1.cfe8e2p0, 0x1.0c1036p-1, 0x1.1fdf8ep-2, -0x1.61fe34p0, 0x1.45171p-3, 0x1.bfa9d2p-4, -0x1.ccaf9ap-1, 0x1.a20936p-1, 0x1.dd6c3p0, -0x1.e6b47cp-2, -0x1.5ff522p0, 0x1.660b66p0, 0x1.744b82p-3, 0x1.374e06p-1, 0x1.beda1ep0, -0x1.e9273p-1, 0x1.a4c4b4p-1, 0x1.7a6d92p-1, 0x1.5d7ac8p-1, -0x1.c36c5cp0, -0x1.cac9a6p0, 0x1.e2f4ep0, 0x1.9c5acep-1, -0x1.372788p-2, 0x1.816dbcp-1, -0x1.5faad8p0, -0x1.c0a1a4p0, 0x1.35942p0, -0x1.48b08cp-1, 0x1.107612p-3, -0x1.9717fp-2, 0x1.9f188p0, 0x1.e0ae2ep-1, -0x1.0d5478p-2, 0x1.9b02e2p-1, 0x1.aa8a4ap-3, -0x1.f97324p0, -0x1.91d326p0, -0x1.192714p0, 0x1.f659e2p-2, -0x1.55686ap-2, 0x1.cc0bcep0, 0x1.0015d6p-1, -0x1.41a7bcp0 };
float keras_activation_3_test1_array[6] = { 0x1.f75064p-3, 0x1.214cfcp-4, 0x1.bab6f2p-6, 0x1.d66c34p-4, 0x1.07d79p-1, 0x1.b0ef8p-6 };
float c_activation_3_test1_array[6];
unsigned int j __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor test1_dense_input_input __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor keras_activation_3_test1 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor c_activation_3_test1 __ATTRIBUTE_WEAK__;
static  char aesl_internal__OC_str[34] = "Average time over 1 tests: %e s \n";
float errors[10] __ATTRIBUTE_WEAK__;
static  char aesl_internal__OC_str1[38] = "Max absolute error for 10 tests: %e \n";


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
  unsigned int llvm_cbe_tmp__1;
  unsigned int llvm_cbe_tmp__1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  float *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  float llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  float *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
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
  float llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  float llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  float llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  float llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  float llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  float llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  float llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  float llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  float llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  float llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  float llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  float llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  double llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  double llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  double llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  double llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  double llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  float llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  double llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  float llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  double llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned int llvm_cbe_storemerge4;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_1_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__32;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__32:
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = phi i32 [ 0, %%0 ], [ %%7, %%1 ], !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_3_count);
  llvm_cbe_tmp__1 = (unsigned int )llvm_cbe_tmp__1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%2 to i64, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_4_count);
  llvm_cbe_tmp__2 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [2622 x float]* @test1_dense_input_input_array, i64 0, i64 %%3, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_5_count);
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
printf("\n  %%5 = load float* %%4, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_6_count);
  llvm_cbe_tmp__4 = (float )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__4, *(int*)(&llvm_cbe_tmp__4));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 0, i64 %%3, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_7_count);
  llvm_cbe_tmp__5 = (float *)(&test1_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__2))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%5, float* %%6, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_8_count);
  *llvm_cbe_tmp__5 = llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%2, 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_9_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(llvm_cbe_tmp__1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__6&4294967295ull)));
  if (((llvm_cbe_tmp__6&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__33;
  } else {
    llvm_cbe_tmp__1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__6;   /* for PHI node */
    goto llvm_cbe_tmp__32;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 1), align 8, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_11_count);
  *((&test1_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 2), align 8, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_12_count);
  *((&test1_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_13_count);
  *((&test1_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_14_count);
  *((&test1_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_15_count);
  *((&test1_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_16_count);
  *((&test1_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @test1_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_17_count);
  *((&test1_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 1), align 8, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_18_count);
  *((&keras_activation_3_test1.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 2), align 8, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_19_count);
  *((&keras_activation_3_test1.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 0), align 8, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_20_count);
  *((&keras_activation_3_test1.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 1), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_21_count);
  *((&keras_activation_3_test1.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 2), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_22_count);
  *((&keras_activation_3_test1.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 3), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_23_count);
  *((&keras_activation_3_test1.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 4), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_24_count);
  *((&keras_activation_3_test1.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 0), align 16, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__7 = (float )*((&keras_activation_3_test1_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__7, *(int*)(&llvm_cbe_tmp__7));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%9, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 0), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_26_count);
  *((&keras_activation_3_test1.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 1), align 4, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__8 = (float )*((&keras_activation_3_test1_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__8, *(int*)(&llvm_cbe_tmp__8));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%10, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 1), align 4, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_28_count);
  *((&keras_activation_3_test1.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 2), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__9 = (float )*((&keras_activation_3_test1_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__9, *(int*)(&llvm_cbe_tmp__9));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%11, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 2), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_30_count);
  *((&keras_activation_3_test1.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 3), align 4, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__10 = (float )*((&keras_activation_3_test1_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__10, *(int*)(&llvm_cbe_tmp__10));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 3), align 4, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_32_count);
  *((&keras_activation_3_test1.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 4), align 16, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__11 = (float )*((&keras_activation_3_test1_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__11, *(int*)(&llvm_cbe_tmp__11));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%13, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 4), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_34_count);
  *((&keras_activation_3_test1.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 5), align 4, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__12 = (float )*((&keras_activation_3_test1_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__12, *(int*)(&llvm_cbe_tmp__12));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%14, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 5), align 4, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_36_count);
  *((&keras_activation_3_test1.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 1), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_37_count);
  *((&c_activation_3_test1.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 2), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_38_count);
  *((&c_activation_3_test1.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 3, i64 0), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_39_count);
  *((&c_activation_3_test1.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 3, i64 1), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_40_count);
  *((&c_activation_3_test1.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 3, i64 2), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_41_count);
  *((&c_activation_3_test1.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 3, i64 3), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_42_count);
  *((&c_activation_3_test1.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 3, i64 4), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_43_count);
  *((&c_activation_3_test1.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 0), align 16, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__13 = (float )*((&c_activation_3_test1_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__13, *(int*)(&llvm_cbe_tmp__13));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 0, i64 0), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_45_count);
  *((&c_activation_3_test1.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 1), align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__14 = (float )*((&c_activation_3_test1_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__14, *(int*)(&llvm_cbe_tmp__14));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%16, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 0, i64 1), align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_47_count);
  *((&c_activation_3_test1.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 2), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__15 = (float )*((&c_activation_3_test1_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__15, *(int*)(&llvm_cbe_tmp__15));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%17, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 0, i64 2), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_49_count);
  *((&c_activation_3_test1.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 3), align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__16 = (float )*((&c_activation_3_test1_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__16, *(int*)(&llvm_cbe_tmp__16));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%18, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 0, i64 3), align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_51_count);
  *((&c_activation_3_test1.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 4), align 16, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__17 = (float )*((&c_activation_3_test1_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__17, *(int*)(&llvm_cbe_tmp__17));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%19, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 0, i64 4), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_53_count);
  *((&c_activation_3_test1.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 5), align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__18 = (float )*((&c_activation_3_test1_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__18, *(int*)(&llvm_cbe_tmp__18));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%20, float* getelementptr inbounds (%%struct.k2c_tensor* @c_activation_3_test1, i64 0, i32 0, i64 5), align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_55_count);
  *((&c_activation_3_test1.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 6, i32* @j, align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_56_count);
  *(&j) = 6u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 6u);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void bitcast (void (...)* @face_classifier_c_initialize to void ()*)() nounwind, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_61_count);
   /*tail*/ face_classifier_c_initialize();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = tail call i32 @clock() nounwind, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__19 = (unsigned int ) /*tail*/ clock();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @face_classifier_c(%%struct.k2c_tensor* byval @test1_dense_input_input, %%struct.k2c_tensor* @c_activation_3_test1) nounwind, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_65_count);
   /*tail*/ face_classifier_c(test1_dense_input_input, (l_struct_OC_k2c_tensor *)(&c_activation_3_test1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = tail call i32 @clock() nounwind, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__20 = (unsigned int ) /*tail*/ clock();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sitofp i32 %%22 to double, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__21 = (double )((double )(signed int )llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__21, *(long long*)(&llvm_cbe_tmp__21));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = sitofp i32 %%21 to double, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__22 = (double )((double )(signed int )llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__22, *(long long*)(&llvm_cbe_tmp__22));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = fsub double %%23, %%24, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__23 = (double )llvm_cbe_tmp__21 - llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__23, *(long long*)(&llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = fdiv double %%25, 1.000000e+03, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__24 = (double )llvm_cbe_tmp__23 / 0x1.f4p9;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__24, *(long long*)(&llvm_cbe_tmp__24));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = fdiv double %%26, 1.000000e+01, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__25 = (double )llvm_cbe_tmp__24 / 0x1.4p3;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__25, *(long long*)(&llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([34 x i8]* @aesl_internal_.str, i64 0, i64 0), double %%27) nounwind, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_74_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 34
#endif
])), llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__25, *(long long*)(&llvm_cbe_tmp__25));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__26);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = tail call float @maxabs(%%struct.k2c_tensor* @keras_activation_3_test1, %%struct.k2c_tensor* @c_activation_3_test1), !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__27 = (float ) /*tail*/ maxabs((l_struct_OC_k2c_tensor *)(&keras_activation_3_test1), (l_struct_OC_k2c_tensor *)(&c_activation_3_test1));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%29, float* getelementptr inbounds ([10 x float]* @errors, i64 0, i64 0), align 16, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_76_count);
  *((&errors[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = fpext float %%29 to double, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__28 = (double )((double )llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__28, *(long long*)(&llvm_cbe_tmp__28));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([38 x i8]* @aesl_internal_.str1, i64 0, i64 0), double %%30) nounwind, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_85_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 38
#endif
])), llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__28, *(long long*)(&llvm_cbe_tmp__28));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__29);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void bitcast (void (...)* @face_classifier_c_terminate to void ()*)() nounwind, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_86_count);
   /*tail*/ face_classifier_c_terminate();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load float* getelementptr inbounds ([10 x float]* @errors, i64 0, i64 0), align 16, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__30 = (float )*((&errors[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__30, *(int*)(&llvm_cbe_tmp__30));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = fpext float %%32 to double, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__31 = (double )((double )llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__31, *(long long*)(&llvm_cbe_tmp__31));
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = zext i1 %%34 to i32, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned int )((unsigned int )(bool )(llvm_fcmp_ogt(llvm_cbe_tmp__31, 0x1.4f8b588e368f1p-17))&1U);
if (AESL_DEBUG_TRACE)
printf("\nstoremerge4 = 0x%X\n", llvm_cbe_storemerge4);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_storemerge4;
}


float maxabs(l_struct_OC_k2c_tensor *llvm_cbe_tensor1, l_struct_OC_k2c_tensor *llvm_cbe_tensor2) {
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
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  signed long long *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned long long llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  float llvm_cbe_tmp__36;
  float llvm_cbe_tmp__36__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  float *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  float llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  float *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  float llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  float llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  float llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  float llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  unsigned long long llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  unsigned long long llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  float llvm_cbe__2e_lcssa;
  float llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @maxabs\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%tensor1, i64 0, i32 2, !dbg !7 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__34 = (signed long long *)(&llvm_cbe_tensor1->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !7 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__35 = (unsigned long long )*llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__35);
  if (((llvm_cbe_tmp__35&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__36__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%13, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__44);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = phi float [ %%12, %%.lr.ph ], [ 0.000000e+00, %%0  for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__36 = (float )llvm_cbe_tmp__36__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__36);
printf("\n = %f",llvm_cbe_tmp__43);
printf("\n = %f",0x0p0);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%tensor1, i64 0, i32 0, i64 %%storemerge1, !dbg !7 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__37 = (float *)(&llvm_cbe_tensor1->field0[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%5, align 4, !dbg !7 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__38 = (float )*llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__38, *(int*)(&llvm_cbe_tmp__38));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.k2c_tensor* %%tensor2, i64 0, i32 0, i64 %%storemerge1, !dbg !7 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__39 = (float *)(&llvm_cbe_tensor2->field0[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 4, !dbg !7 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__40 = (float )*llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__40, *(int*)(&llvm_cbe_tmp__40));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fsub float %%6, %%8, !dbg !7 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__41 = (float )((float )(llvm_cbe_tmp__38 - llvm_cbe_tmp__40));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__41, *(int*)(&llvm_cbe_tmp__41));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call float @fabsf(float %%9) nounwind, !dbg !7 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__42 = (float ) /*tail*/ fabsf(llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__41, *(int*)(&llvm_cbe_tmp__41));
printf("\nReturn  = %f",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = select i1 %%11, float %%10, float %%4, !dbg !8 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__43 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__42, llvm_cbe_tmp__36))) ? ((float )llvm_cbe_tmp__42) : ((float )llvm_cbe_tmp__36));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__43, *(int*)(&llvm_cbe_tmp__43));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i64 %%storemerge1, 1, !dbg !9 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__44 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__44&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%1, align 8, !dbg !7 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__45 = (unsigned long long )*llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__45);
  if ((((unsigned long long )llvm_cbe_tmp__44&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__45&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__44;   /* for PHI node */
    llvm_cbe_tmp__36__PHI_TEMPORARY = (float )llvm_cbe_tmp__43;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (float )llvm_cbe_tmp__43;   /* for PHI node */
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
printf("\n = %f",llvm_cbe_tmp__43);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @maxabs}\n");
  return llvm_cbe__2e_lcssa;
}

