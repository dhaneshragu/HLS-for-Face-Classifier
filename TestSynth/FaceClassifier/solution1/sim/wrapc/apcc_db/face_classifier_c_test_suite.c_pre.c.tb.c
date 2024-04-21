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
typedef struct l_struct_OC_k2c_tensor2 l_struct_OC_k2c_tensor2;
typedef struct l_struct_OC_k2c_tensor l_struct_OC_k2c_tensor;

/* Structure contents */
struct l_struct_OC_k2c_tensor2 {
  float field0[2622];
  unsigned long long field1;
  unsigned long long field2;
  signed long long field3[5];
};

struct l_struct_OC_k2c_tensor {
  float field0[262200];
  unsigned long long field1;
  unsigned long long field2;
  signed long long field3[5];
};


/* External Global Variable Declarations */
extern unsigned int j;
extern float test1_dense_input_input_array[2622];
extern float keras_activation_3_test1_array[6];
extern float c_activation_3_test1_array[6];
extern float test2_dense_input_input_array[2622];
extern float keras_activation_3_test2_array[6];
extern float c_activation_3_test2_array[6];
extern l_struct_OC_k2c_tensor2 test1_dense_input_input;
extern l_struct_OC_k2c_tensor keras_activation_3_test1;
extern l_struct_OC_k2c_tensor2 c_activation_3_test1;
extern l_struct_OC_k2c_tensor2 test2_dense_input_input;
extern l_struct_OC_k2c_tensor keras_activation_3_test2;
extern l_struct_OC_k2c_tensor2 c_activation_3_test2;
extern float errors[10];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int main(void);
void face_classifier_c_initialize();
void AESL_WRAP_face_classifier_c(l_struct_OC_k2c_tensor2 , l_struct_OC_k2c_tensor2 *);
float maxabs(l_struct_OC_k2c_tensor *llvm_cbe_tensor1, l_struct_OC_k2c_tensor2 *llvm_cbe_tensor2);
void face_classifier_c_terminate();
float fabsf(float );


/* Global Variable Definitions and Initialization */
unsigned int j;
float test1_dense_input_input_array[2622] = { 0x1.be157p0, -0x1.2952a4p0, -0x1.f1a53ap-3, 0x1.89c2cep0, 0x1.643852p-1, -0x1.5ad3b8p0, -0x1.c55c24p0, 0x1.a191bap-1, -0x1.041c5ap-1, -0x1.be5946p0, 0x1.58e52ap0, 0x1.1eb0fp-1, 0x1.b13f7p0, -0x1.08215ap0, 0x1.dc6bdp0, -0x1.0f0fe2p-3, 0x1.e4b17ep0, 0x1.18a7fcp0, 0x1.5f4fdp0, 0x1.b42e16p0, -0x1.660bdep0, 0x1.1645e8p0, -0x1.a8f982p-3, 0x1.841482p0, -0x1.2a0c46p-1, -0x1.c9d6ap0, 0x1.61f90cp-6, 0x1.17c2fcp-1, -0x1.05875ap-1, 0x1.fb67cp0, -0x1.0071ccp0, 0x1.c167bcp-1, 0x1.c0e4d2p-1, -0x1.47a0fep0, -0x1.d2d068p0, -0x1.f08856p0, 0x1.f8abp-1, -0x1.e3733cp-2, 0x1.a8aadp-3, -0x1.b5b0a6p-1, -0x1.e382fep0, -0x1.6118d6p-2, 0x1.4210cap-3, 0x1.f5010cp-3, -0x1.968a3cp0, -0x1.c36a7ap-1, -0x1.746da8p0, 0x1.eeb1ecp-4, 0x1.6f5944p-1, 0x1.807a4ap0, 0x1.7bca22p-1, -0x1.1aaa7cp0, 0x1.3e1844p0, -0x1.1d9bfep0, 0x1.a05c86p-2, 0x1.c55676p0, -0x1.203368p0, 0x1.2a3592p-2, 0x1.9f42c2p0, 0x1.90b79ep-1, -0x1.23b942p-2, 0x1.0a31acp-1, 0x1.bcb7fcp-2, 0x1.938442p-1, 0x1.8014eap0, -0x1.662b7ep0, 0x1.e54b32p-1, -0x1.0c6aecp0, -0x1.8bffd8p-1, 0x1.d167b8p-4, -0x1.9580cap-1, -0x1.50541cp-1, 0x1.9c3546p0, -0x1.c3436ep0, 0x1.fcc9a8p0, -0x1.b04936p0, -0x1.49949ep0, -0x1.bfc7c4p0, 0x1.7657fcp-1, -0x1.34fc0cp0, 0x1.6ce432p-1, 0x1.664f5p-1, -0x1.be7bd6p0, 0x1.7b52ep0, 0x1.9a2dc6p-1, 0x1.642266p-1, -0x1.bb3fe6p-2, 0x1.2685a6p0, 0x1.0e4ac8p0, 0x1.78d95ep0, -0x1.280478p-3, 0x1.b313a4p-2, -0x1.3dee5ep-1, -0x1.b76df4p-2, 0x1.4ab12p-1, 0x1.8afcf4p-1, -0x1.a953fap0, -0x1.342364p0, 0x1.48493p-1, 0x1.24adeap-3, 0x1.086998p-3, -0x1.496e12p-2, -0x1.443ee6p-2, 0x1.a8c46ep0, -0x1.c77394p0, -0x1.93cfcap0, 0x1.cda6bcp-2, -0x1.0f87c2p-1, -0x1.c619a6p-1, -0x1.109782p0, 0x1.d17e62p-2, -0x1.07403ap0, 0x1.edf2dp0, 0x1.6ee3p-1, 0x1.ab9366p-6, 0x1.b5ab1ep0, -0x1.8a564ap0, 0x1.34d524p0, 0x1.b201fap0, -0x1.0d50f2p0, 0x1.c7b5c8p0, -0x1.e78cbep-8, 0x1.84554p-2, -0x1.81a0c8p0, 0x1.f5c2a4p0, 0x1.4f2106p-1, 0x1.04421p-1, -0x1.f1e65p-1, -0x1.f50b58p-1, -0x1.0c5d98p0, 0x1.c5ac24p-1, 0x1.035824p0, 0x1.751dfp0, -0x1.e03024p-1, -0x1.f57c56p-1, 0x1.fd8454p0, 0x1.dcb06ap0, 0x1.11413ap-1, -0x1.4d3f6ep-1, 0x1.3cec4ep-2, 0x1.238884p0, 0x1.264c54p0, -0x1.048dfep-4, 0x1.01b9cp-7, -0x1.45ffa4p-1, -0x1.e85be2p0, -0x1.865104p0, 0x1.428fc4p0, 0x1.5ca1ep0, 0x1.8dbe46p0, 0x1.fdc35ep-1, 0x1.7713b2p-1, -0x1.806952p0, 0x1.8067e6p0, 0x1.db3456p-1, -0x1.a7ef7cp0, 0x1.dd941p-6, -0x1.a526dcp0, -0x1.70a3eap-1, -0x1.e6734ep0, 0x1.7e0cfep0, -0x1.5d2b0ep-1, 0x1.603536p0, -0x1.462724p-1, -0x1.e5c57p-1, -0x1.b5ee7ep0, -0x1.52a35p-7, -0x1.73717cp-1, 0x1.e52f22p-1, -0x1.e98a7p-4, -0x1.8d85a6p-1, -0x1.58ed6cp-1, 0x1.580d1ap-1, -0x1.d53aep-2, 0x1.100022p-2, 0x1.839f3ap-6, -0x1.241ad2p0, 0x1.f3d012p-1, -0x1.d03a54p-5, 0x1.83426p0, -0x1.9097p0, 0x1.06f088p-2, -0x1.11dd88p-2, -0x1.4decbp-1, -0x1.269b62p-1, -0x1.84843p-3, -0x1.7e9de4p-1, -0x1.0d7f7ep0, 0x1.88821cp-1, 0x1.6f20fp0, 0x1.f8c87p0, 0x1.28cf46p-1, 0x1.0969f4p-1, 0x1.abef8ep0, -0x1.8b9924p0, 0x1.483774p-3, -0x1.7b9eb2p-1, 0x1.36b744p-3, 0x1.9710fp0, -0x1.11cd04p0, 0x1.d9c6a6p0, -0x1.8b506p0, 0x1.a5f392p0, -0x1.dcad46p0, -0x1.d9f3c6p-2, -0x1.15de3ap-1, 0x1.3a06ep-1, -0x1.b33b28p0, -0x1.1bd9b8p0, 0x1.2aba62p0, -0x1.fdf718p0, -0x1.e0ce7ep0, -0x1.c6fc4ap0, 0x1.8f639cp0, -0x1.ac3842p0, 0x1.7d6d0ep-1, 0x1.63590ap0, 0x1.53c696p-1, 0x1.a17d98p-2, -0x1.9cf65ap0, 0x1.208d94p0, 0x1.2d2f54p0, 0x1.0b0974p0, -0x1.cf2102p0, 0x1.70c68ep0, -0x1.bc965ep-3, 0x1.e5903p0, 0x1.67e16p-3, 0x1.739d04p0, -0x1.b9d5dep-3, 0x1.e17378p0, -0x1.068944p-1, 0x1.abd5c2p-1, 0x1.1dcdbp-1, 0x1.f6fd6ap0, -0x1.f840dep0, 0x1.423bfcp-1, 0x1.a95706p-1, 0x1.48d46ap-2, -0x1.6c5ccp-1, -0x1.01c876p-1, 0x1.5f75b6p0, 0x1.ace124p0, -0x1.a2cffep-2, -0x1.ebedc4p-3, -0x1.a60168p0, -0x1.262128p0, -0x1.5a4458p-2, -0x1.d093d4p0, -0x1.f7e018p-2, -0x1.1803b4p0, -0x1.c5eb36p0, 0x1.321dbap-1, 0x1.3587c8p0, -0x1.c74cap0, 0x1.9468d4p-1, -0x1.a1b22ep0, -0x1.7f08fap-4, -0x1.6f22p-1, -0x1.4e66ecp0, 0x1.bfba1ep0, 0x1.6d347ep0, -0x1.8f58b4p-4, -0x1.4a92dp0, 0x1.e8e3b6p0, 0x1.a4f664p0, 0x1.a3f816p0, -0x1.b96a66p0, -0x1.9b4eecp0, 0x1.961b4cp0, -0x1.d5e416p0, 0x1.9ba77ap-3, -0x1.9852ap0, 0x1.b74fcp-1, -0x1.5ae6fep0, -0x1.54fep0, 0x1.beab44p-1, -0x1.7879dep0, -0x1.d65306p-1, 0x1.b94f92p-1, 0x1.40ffa6p-2, -0x1.0d4c3p0, 0x1.b560b6p-1, -0x1.71b6fep0, -0x1.35966ap-1, 0x1.d2fe84p0, -0x1.e0a71p0, -0x1.14f8a2p0, -0x1.e9c9f4p-2, 0x1.f53822p-1, 0x1.fd031ap0, 0x1.c47308p-1, 0x1.be8a1ap-2, 0x1.4670e8p0, 0x1.f0ad36p-1, 0x1.8a90ccp-2, 0x1.b49b56p-1, -0x1.51a81cp-1, 0x1.b59848p0, 0x1.075744p0, -0x1.d5b0cp0, 0x1.ddd10cp-4, 0x1.29be42p0, -0x1.65d3dp0, 0x1.05a0b8p0, 0x1.e11bfep-1, -0x1.7c79b4p-2, 0x1.efe54cp-1, -0x1.3ddec2p-3, -0x1.a5430ap-1, 0x1.d97136p0, 0x1.bcae46p-2, -0x1.35db52p-3, 0x1.9edf3ap0, 0x1.dd4136p-1, 0x1.d245bep0, 0x1.cc9ac2p0, -0x1.fc274cp-7, -0x1.99d876p-1, 0x1.ce8aap-1, -0x1.4fdc7ap0, 0x1.66e388p-4, 0x1.ed2e2ap-1, -0x1.ee1426p-4, -0x1.e5a42ap-2, 0x1.4fb866p-1, 0x1.20d8d4p0, 0x1.3d4044p0, 0x1.81e36cp0, 0x1.3881bap0, 0x1.69949p0, -0x1.4b544cp-1, -0x1.fc398cp-1, 0x1.828cd6p0, -0x1.003e18p-1, -0x1.8c78e8p0, -0x1.a1f0dp0, 0x1.8ed50ap-2, 0x1.b21a16p0, 0x1.2c00c6p-1, 0x1.a1dda6p-2, -0x1.09275ap-1, -0x1.5c632ap-2, 0x1.87708p0, 0x1.e8a85cp-4, 0x1.5c321ap-1, 0x1.b35ae6p-1, 0x1.b29056p0, -0x1.52a8eap0, 0x1.66b15p-3, 0x1.4596d2p0, -0x1.76c592p-2, -0x1.5a9886p0, 0x1.3125acp-1, 0x1.1f47a6p0, -0x1.f875c8p0, -0x1.d64014p0, -0x1.3e0fe6p0, -0x1.3bac64p-1, 0x1.d13a1ep-3, 0x1.58121p-1, -0x1.21ff42p-1, 0x1.013e82p0, -0x1.cdf66p-4, -0x1.aa1536p-1, 0x1.973496p0, 0x1.9fb552p0, 0x1.4c221p0, -0x1.bd730ap-3, 0x1.2a630cp0, -0x1.0bb90ap0, -0x1.85273p0, -0x1.935766p-1, -0x1.dbbd46p-3, 0x1.554d9p-1, -0x1.b13c6cp0, 0x1.81b8cep-2, 0x1.734a9p0, -0x1.fa8482p0, 0x1.2ccefep0, 0x1.64cb5p0, 0x1.c7411ep-3, -0x1.6ab27cp-4, 0x1.9c759cp-3, -0x1.01a87p-2, 0x1.229c1cp-1, 0x1.8de68p-1, -0x1.5ddf8cp0, 0x1.8845f8p0, -0x1.f422c4p0, 0x1.875f2p0, -0x1.c969a8p0, -0x1.85669cp0, -0x1.bbcb74p0, 0x1.ef0728p-1, -0x1.3f4ae2p-1, 0x1.99d7b6p-4, 0x1.f6af8p0, -0x1.279f24p0, -0x1.3ee392p-1, -0x1.36955ap0, 0x1.fa97fp-1, -0x1.afb50cp-1, -0x1.fcd466p0, -0x1.713022p0, -0x1.7e8d68p-4, 0x1.b22f5ap0, -0x1.5f26e2p-1, -0x1.895182p-2, 0x1.32708cp0, 0x1.c5867cp0, 0x1.7400dap0, 0x1.90e1b4p0, 0x1.7141cp-1, 0x1.24794p0, 0x1.7bb9fp-8, 0x1.445ebp-4, 0x1.5cda3ap0, 0x1.2319cp0, 0x1.da0a22p0, 0x1.071d32p0, 0x1.d0c84cp-1, -0x1.f544b2p-4, 0x1.84b556p-2, -0x1.dcc848p0, 0x1.d01954p-1, 0x1.1a225ap-1, -0x1.b386e8p-1, 0x1.dbc07ep0, -0x1.a4920ep-2, -0x1.138a3ap-2, 0x1.3459dcp0, -0x1.cbf024p-1, 0x1.153d5p0, -0x1.e4ed58p-3, 0x1.a820c8p-1, 0x1.4258a6p-4, -0x1.6e3d46p0, 0x1.ea66c4p0, 0x1.c8a958p-2, 0x1.b5ab74p-3, -0x1.ff8224p0, 0x1.759ce6p-2, 0x1.a49f34p0, -0x1.2afecep0, -0x1.e2739cp0, -0x1.6e72ccp-1, -0x1.6a755p0, -0x1.99975ep0, -0x1.4b16dcp-2, -0x1.608302p-2, 0x1.929beep-1, 0x1.19ad8cp0, 0x1.d7181p0, 0x1.01f61p-3, -0x1.97036p-2, 0x1.ddf918p-1, -0x1.91a878p0, 0x1.083b8ep0, -0x1.a486d8p-2, -0x1.113516p0, -0x1.2c1a76p0, 0x1.633a26p-2, -0x1.0509c2p-4, 0x1.8faafp0, 0x1.b1ca82p-2, -0x1.84fdc2p0, -0x1.6f0d1p0, -0x1.7d314cp0, -0x1.835822p-3, -0x1.af50dap0, 0x1.b5251p-5, -0x1.ca721cp0, -0x1.8c4c78p-1, 0x1.4fa8p-1, -0x1.5ad532p0, -0x1.a1a1ep0, -0x1.4258f6p-2, -0x1.02007ep-4, -0x1.4da6fp0, -0x1.adcba6p-1, -0x1.0f297ep-2, 0x1.45cea8p0, -0x1.f287fap-2, -0x1.4c865ep-3, -0x1.65c6fep0, -0x1.75c14ep-6, -0x1.e57f7ap-1, 0x1.d32b0ep0, -0x1.de220ap-1, -0x1.f89c7cp-1, 0x1.18f4a4p-1, 0x1.356f84p0, -0x1.e1f746p0, -0x1.d7f4eep-8, 0x1.6cde32p0, -0x1.103742p0, -0x1.408f06p0, -0x1.a17ap-1, -0x1.9fbc4ep0, 0x1.b148b2p-2, -0x1.631b5cp0, -0x1.952a64p-1, -0x1.df8514p0, 0x1.e0e9ecp0, -0x1.508d54p-3, 0x1.3b09fep0, -0x1.5c6cfap0, -0x1.aa59a2p-1, -0x1.4980fep0, -0x1.811b6ap0, 0x1.171ae6p-3, 0x1.305aa6p0, -0x1.afc6f2p-2, -0x1.61bd98p-3, 0x1.a85296p-2, -0x1.92ab04p0, 0x1.8e384p0, -0x1.2f1334p0, -0x1.f2026ep0, 0x1.348274p-1, 0x1.e7e85cp-2, 0x1.8bcde8p-4, 0x1.ea72p0, -0x1.b1a768p0, -0x1.657678p0, 0x1.2d1752p0, 0x1.32cdf4p0, -0x1.1fbd6p-3, -0x1.3f1bp0, -0x1.decf8p-2, 0x1.b6fe9ep-1, 0x1.b47fa6p-3, 0x1.0f4f4ep0, -0x1.4dc7b2p0, 0x1.6f44c8p0, 0x1.845ccap0, 0x1.b8226ap-1, -0x1.ee734ap0, -0x1.49028ep0, 0x1.3acbe2p0, 0x1.e1eb46p0, -0x1.ec42d6p0, 0x1.510406p-2, -0x1.239174p-1, -0x1.df37cep0, 0x1.576204p0, 0x1.8268bp-3, 0x1.a1e12p0, 0x1.01c082p-1, -0x1.bf741ap-2, 0x1.0ffbbcp-1, 0x1.972d36p-2, -0x1.73ee26p-1, -0x1.52f45cp-1, -0x1.31d988p0, 0x1.849a5ep0, 0x1.a16d28p-1, -0x1.c9641cp-2, -0x1.704e06p0, 0x1.2b8b64p0, -0x1.fc9996p-1, -0x1.5aa0d6p-3, 0x1.c008cap-1, 0x1.4cb634p0, -0x1.b0c4e4p-1, 0x1.77cc8p0, 0x1.c6f41cp-1, -0x1.bb4302p0, 0x1.413aa2p0, -0x1.82d7d6p0, 0x1.a914f6p0, -0x1.4909b8p-4, 0x1.ff489p-5, -0x1.783ba8p0, 0x1.536176p-1, 0x1.47b0ccp-4, -0x1.d757aap0, -0x1.fc0c02p-4, 0x1.447b2ap-2, 0x1.90290ep0, 0x1.7c54b6p0, 0x1.cdf8fep-1, -0x1.bb691cp0, -0x1.0bf2f2p-1, 0x1.f8e2fp-2, 0x1.80bb24p-2, 0x1.8309aap-1, 0x1.b3c95cp0, 0x1.b6c704p-5, -0x1.13fbbep-1, 0x1.50bb86p-1, -0x1.a2c77ep0, 0x1.5b6e2ap-2, 0x1.dafc9cp-2, -0x1.422bf2p0, -0x1.f6edb4p0, -0x1.2c2d66p0, -0x1.1c4bccp-1, 0x1.464e78p0, 0x1.f7ff9cp-1, -0x1.9a3ab6p-1, 0x1.0528bap0, -0x1.a26116p-4, 0x1.f30bd8p-2, 0x1.b76beap0, -0x1.58fde4p-3, 0x1.4a813ap-1, -0x1.c1aa0cp-1, -0x1.421d12p-2, 0x1.8f79e8p-3, 0x1.b6dddep0, -0x1.a09fc6p-4, -0x1.9c1e58p-1, 0x1.94ac9ep-4, -0x1.806fa2p-4, -0x1.0c542ap0, -0x1.aa567p-1, 0x1.674b4ep-1, 0x1.e7f128p-1, 0x1.248b02p0, 0x1.ae3f6p0, -0x1.323e46p-8, -0x1.515478p0, -0x1.fdf1f6p-1, 0x1.2d6cb6p0, 0x1.78ae8ep-1, 0x1.104e56p-1, -0x1.0343aap0, 0x1.0f5d54p0, -0x1.534638p0, 0x1.465e12p0, -0x1.af1744p0, 0x1.d6f50ep0, 0x1.478b64p0, -0x1.8683eep-1, 0x1.b1f0dap-1, -0x1.e8c602p-2, 0x1.58fa18p-1, 0x1.e45d96p0, -0x1.e62cc2p-1, -0x1.44f6aep-2, 0x1.77d21p0, -0x1.995f1cp-1, 0x1.97d328p0, 0x1.16ccfp-3, 0x1.9c45aep-2, -0x1.e24d5ep0, 0x1.0a953cp0, 0x1.c54f8cp0, -0x1.f1f0bcp-1, 0x1.0ec71cp0, 0x1.5f127p0, 0x1.4e7b86p0, -0x1.8f7d8ep-1, 0x1.c60df4p0, -0x1.ca3e28p0, -0x1.eca828p-2, -0x1.390a04p-1, 0x1.4bd84ap-2, -0x1.ac1da6p0, 0x1.5458dp0, -0x1.084f8p-2, -0x1.f1739cp-2, 0x1.2b6c3cp0, -0x1.082c62p0, 0x1.46702ap-1, -0x1.186156p0, -0x1.9e73a4p-2, 0x1.c5bd6cp-1, -0x1.435688p0, -0x1.22c758p-1, -0x1.5ee272p0, 0x1.2ad966p0, 0x1.1dd024p-2, -0x1.357c5p0, -0x1.051786p0, -0x1.c8bf2p0, -0x1.862e32p0, -0x1.59eaa8p-2, 0x1.8f604ep-2, -0x1.4c6cd4p-2, 0x1.b8fa3p-1, -0x1.706d0cp-1, 0x1.575c6ep0, 0x1.5d909cp0, -0x1.93a008p0, 0x1.d65578p0, -0x1.9e082ap0, -0x1.e8d3a4p-1, -0x1.d23e9ep0, 0x1.a3076p-1, -0x1.24442ap0, 0x1.5a4d5ap0, -0x1.0fce16p-1, -0x1.bfcb1cp0, 0x1.d4fe5p-1, -0x1.b8b98ap0, 0x1.844f28p-1, 0x1.e2f1c2p0, -0x1.28469p-1, 0x1.62a898p0, 0x1.78aed8p-2, 0x1.aa455p0, 0x1.5a176cp-5, 0x1.0a68f4p-1, -0x1.bbf32ap0, 0x1.fed704p0, -0x1.764cfp-2, -0x1.a26aep0, -0x1.94b3aap-1, -0x1.7593b4p-3, 0x1.df9adp0, -0x1.6368ccp0, -0x1.6d454p-3, 0x1.e362dep-3, 0x1.82407ep-1, -0x1.8df76cp0, 0x1.f212a6p-5, -0x1.aa2d96p-1, -0x1.7b547p-1, 0x1.421fc8p0, 0x1.325104p0, 0x1.3b66fep-1, -0x1.ddb3d2p-4, 0x1.734ec2p-2, 0x1.195e1cp0, -0x1.a8624cp0, 0x1.c6667ep0, -0x1.a1041cp-4, -0x1.2b707ep-1, 0x1.21663cp0, 0x1.0a94aap0, -0x1.03658cp-2, 0x1.781502p-2, 0x1.ca1898p-2, -0x1.a43bb8p0, -0x1.120a9p-2, 0x1.e75b9cp-1, -0x1.55d5f8p-1, -0x1.5321d2p0, 0x1.301d6p-1, 0x1.0e2362p0, -0x1.f62958p0, -0x1.9ac05cp-2, -0x1.096112p0, 0x1.e93772p-1, -0x1.81ad8cp0, -0x1.d064a8p-1, -0x1.66bd9p0, -0x1.af5614p-1, -0x1.5654ep0, -0x1.bd97bcp0, -0x1.ac46e2p0, -0x1.eec6cep-3, -0x1.9b3ce2p0, 0x1.01df2ap0, -0x1.a507a4p0, 0x1.4a9c5ep0, 0x1.f723fcp-2, 0x1.9faa86p-3, -0x1.1ddbfep-2, -0x1.235e3cp0, -0x1.3ac986p-1, -0x1.ed6a66p0, 0x1.81dcd2p0, 0x1.ed8592p-2, 0x1.9809cep-1, 0x1.2efdd4p-2, -0x1.a43c48p-1, 0x1.570b12p-2, -0x1.a85ed6p-3, -0x1.19645ep0, 0x1.5d9a1cp0, -0x1.89ec74p0, 0x1.e07e9ap0, -0x1.026518p-1, -0x1.25a3fp0, 0x1.378d9ap0, -0x1.4916e8p0, -0x1.b3fe14p0, -0x1.15aaeap0, 0x1.3f45a6p0, 0x1.0c302p0, 0x1.50a846p0, 0x1.2d5852p-6, 0x1.5a44acp-2, -0x1.61143cp0, -0x1.998cp0, -0x1.6f0bb2p-1, -0x1.0a40e4p0, 0x1.90bbap-1, -0x1.62dd2cp-1, 0x1.f6570ap-3, 0x1.e5f4cap-2, -0x1.bacd12p-1, 0x1.9dc76cp-1, 0x1.5a70d8p-6, -0x1.0eec04p-1, -0x1.b23282p0, -0x1.850e68p0, 0x1.085e82p-1, 0x1.b07628p-4, 0x1.535274p0, -0x1.d7ef86p0, -0x1.e9e6cp-2, 0x1.3e7bd8p0, 0x1.136692p-3, 0x1.fc1102p0, -0x1.50e8bap-1, 0x1.f320c8p-1, -0x1.027b3cp-3, 0x1.fba2eep0, 0x1.bbf764p-2, -0x1.b3ab3p0, 0x1.166d6cp0, 0x1.2894c4p0, -0x1.23993ep0, -0x1.49726p-4, -0x1.461616p0, -0x1.bdaf08p0, -0x1.2b2338p-3, 0x1.45c13ep-4, -0x1.793704p0, 0x1.ac0ea2p0, 0x1.e85148p-3, -0x1.88f38p0, -0x1.5c6bdep-3, -0x1.a746ecp-1, 0x1.4bf80ep0, -0x1.3219bep-2, 0x1.fd24f8p-1, 0x1.30425cp0, -0x1.1e41cp0, -0x1.ddf9d8p-1, 0x1.cdf302p-1, -0x1.14ee98p0, -0x1.39f1a8p0, -0x1.e3902ep0, 0x1.89926cp-2, 0x1.6794b6p0, 0x1.035848p-2, 0x1.0d1bc8p-1, -0x1.7b2c64p-5, 0x1.7fe38ep0, -0x1.d45d64p-1, -0x1.cf986cp0, 0x1.636128p-1, 0x1.643c56p-2, -0x1.c7e228p0, 0x1.bfae6cp-1, 0x1.2972fp0, -0x1.348f3cp-3, 0x1.d7fecep0, 0x1.b651a6p0, -0x1.e79434p-1, 0x1.311a26p-5, -0x1.5e89p0, -0x1.7c0998p-1, -0x1.5ce60ep-1, -0x1.4231ep0, -0x1.0e9412p0, 0x1.80ef26p-2, -0x1.ff2daap0, 0x1.c5dbeap0, -0x1.a09186p-3, -0x1.3d12ecp0, -0x1.8b7e5ep-4, 0x1.7a924ep-3, 0x1.5fe7b2p0, 0x1.b3a6f2p-1, 0x1.74068p0, 0x1.31dcp-1, -0x1.ebb8dap-1, 0x1.4feca8p-1, -0x1.92fc84p0, -0x1.5c643ap0, -0x1.b356b4p0, -0x1.538604p-4, -0x1.4ab19p-2, -0x1.a8d31ep0, 0x1.2878dap-1, -0x1.3a26dep0, -0x1.6e9be8p0, -0x1.49bcbcp-2, -0x1.f277a4p-2, 0x1.98027ep0, 0x1.80891ap0, 0x1.d2936p0, 0x1.de72e4p0, 0x1.8e25c8p0, -0x1.6ef96cp0, 0x1.2af9c6p-1, -0x1.9622fcp-2, -0x1.cf4f8p0, -0x1.15c9d8p0, 0x1.6c2c52p0, -0x1.2c364p-2, -0x1.cb5b7ap-3, -0x1.befa36p0, 0x1.f425e8p0, 0x1.4fdfccp0, -0x1.33238ep0, 0x1.d0c892p-1, 0x1.27abe2p0, 0x1.253e14p0, -0x1.c8edfp-1, -0x1.a54a2ep-1, 0x1.a8bdc4p-3, -0x1.c9f008p0, -0x1.2bdb6ap0, 0x1.72bc0ap-2, 0x1.2e21f2p0, 0x1.a49cfp0, 0x1.f1c9e2p-5, -0x1.0d02d8p0, -0x1.828cep0, 0x1.0b7946p0, -0x1.ac4136p-1, -0x1.f4a204p0, 0x1.2c36eap-3, -0x1.000172p0, -0x1.6ae4f2p0, 0x1.da12bep0, 0x1.885aep0, -0x1.161e44p0, 0x1.1feccap0, -0x1.3770cp-1, -0x1.82399cp0, 0x1.feccp-4, -0x1.c4173ep-1, 0x1.0a16b2p0, 0x1.364dfep0, 0x1.457c38p0, 0x1.f07ccep0, -0x1.65a55ep-2, -0x1.8b8842p-1, -0x1.6c2f2ep-2, 0x1.a118f6p-2, -0x1.7dd416p-4, 0x1.50495p0, 0x1.82ce98p-1, -0x1.620e72p0, -0x1.4d75d8p-3, 0x1.7847d8p-1, -0x1.b88896p-1, 0x1.cf4dp-1, 0x1.1b1acep0, -0x1.25774ep-3, -0x1.6e521p-3, 0x1.ea6bccp-3, 0x1.da7d84p-3, 0x1.84439cp-2, -0x1.46424cp0, 0x1.09a062p0, -0x1.6d36b4p0, -0x1.fb2654p0, -0x1.9ff886p-2, -0x1.00d30ap-2, 0x1.f12cf8p-2, -0x1.c82e06p-1, 0x1.1078cep0, 0x1.1b72fcp-1, -0x1.bf3b74p0, 0x1.cd2da4p0, -0x1.4e84bep-1, 0x1.512eccp-2, -0x1.52eb58p-5, 0x1.f53deep-1, -0x1.39d5dcp-2, -0x1.0e522ap-1, 0x1.a3759p-1, 0x1.b1179cp0, 0x1.55d738p0, 0x1.3a2616p0, -0x1.bf46bap0, -0x1.83e10cp-3, 0x1.1c05f6p0, -0x1.fa6046p-2, -0x1.32946ap0, 0x1.9abbb2p-1, -0x1.294bc8p0, 0x1.c29932p0, 0x1.1a61e2p-9, -0x1.dc4bcp0, -0x1.6456ep-2, -0x1.53e3dep0, -0x1.78aeb8p-1, -0x1.56ee72p-3, 0x1.07f8f4p-2, -0x1.9b94c8p-1, -0x1.89f8a2p-1, 0x1.6c139cp-3, -0x1.8d7df2p0, 0x1.e3eb12p-1, -0x1.a2e36ep0, 0x1.a7e22p-1, 0x1.af1894p-1, -0x1.5ff906p0, 0x1.dd797ap-1, 0x1.b3fdap-4, -0x1.fc7758p-1, 0x1.3aad04p-2, -0x1.d9c096p-1, -0x1.6030cep0, -0x1.bedb98p0, 0x1.c71892p-6, -0x1.04610cp0, -0x1.034014p0, 0x1.b745dep-6, 0x1.4cdb2ep0, -0x1.601564p0, 0x1.0956b4p-1, -0x1.906ec2p0, -0x1.51ef56p-2, 0x1.04979ep-8, -0x1.02fdfep-1, 0x1.271ef4p-1, 0x1.dd7a12p-3, -0x1.d533b4p0, 0x1.e8827ap0, -0x1.06e6c4p-1, -0x1.35e19ap-2, 0x1.18313cp0, -0x1.67b20ap-1, -0x1.f90a7ep0, 0x1.6b7e28p-1, -0x1.a5afcap0, 0x1.c745a8p-1, 0x1.794aa4p-2, 0x1.d76156p0, -0x1.8202b2p-1, -0x1.8a8d2ap-4, -0x1.01d82ap-1, 0x1.c72e6ap-2, 0x1.74f17ep0, 0x1.93593ep0, 0x1.321e3ep0, 0x1.a2dbc2p0, -0x1.9756fp0, 0x1.b5651cp0, 0x1.ccc608p-5, -0x1.72f222p-2, 0x1.8b9f3ap-1, -0x1.0dba4cp0, 0x1.215a38p-7, 0x1.fe7b3p-3, -0x1.f2819p0, 0x1.e57c6cp-1, 0x1.3038d2p-1, -0x1.84db06p-3, 0x1.dfa7c8p0, 0x1.4282b4p0, -0x1.e1a7e4p-1, 0x1.73220cp0, 0x1.b2f2f2p0, 0x1.27b88ap-1, -0x1.39a2e2p0, 0x1.d80864p0, 0x1.a8db08p0, -0x1.7ff826p0, -0x1.21948cp-1, 0x1.6fe032p-1, 0x1.8444dp0, -0x1.99abb4p-2, 0x1.2aff2ap-1, 0x1.ebb90ep0, 0x1.796c48p-4, 0x1.797e0ep-1, 0x1.0b3a3ep0, -0x1.e4f69p0, -0x1.f5f88ap0, 0x1.459404p0, 0x1.6b94c2p0, -0x1.fa78cap0, -0x1.9d5912p-2, -0x1.8a195cp0, -0x1.687f02p-1, -0x1.946b18p-3, 0x1.ca9e92p0, -0x1.9fed58p0, -0x1.57f6acp-1, -0x1.2089a8p-1, -0x1.bdb55ap0, -0x1.8980c6p-1, -0x1.ba0392p-6, -0x1.98b7ep-2, 0x1.466ef4p-1, -0x1.0fe2ep-8, 0x1.ea9f2cp0, -0x1.3090acp-2, -0x1.59c69p-1, -0x1.64455p-2, -0x1.218576p0, 0x1.674bd4p0, -0x1.e7ff16p0, -0x1.e953b4p-1, 0x1.634e1p0, 0x1.628312p-1, -0x1.946f98p0, -0x1.c13ad2p-1, 0x1.b889aep0, 0x1.2c508cp0, 0x1.bc7b8ep-2, -0x1.46f4c8p0, 0x1.69f9b2p-1, 0x1.9a5fd4p0, 0x1.7325d4p-1, -0x1.5cf956p0, 0x1.5213e8p-2, 0x1.ae3b38p-2, -0x1.31f484p0, 0x1.917862p0, -0x1.02bc02p-2, -0x1.e99682p0, -0x1.eec1fcp-1, -0x1.84f5dap0, 0x1.0c68a4p0, 0x1.069fc4p0, 0x1.f3ef2ap-2, -0x1.c3e75cp-1, -0x1.1bbbfap-1, -0x1.53d82p0, -0x1.db6788p0, 0x1.341eccp0, -0x1.5429c6p0, 0x1.5602dep0, -0x1.280692p-2, -0x1.8e6428p-1, -0x1.437b1p-2, 0x1.4b79cp0, 0x1.94fcf2p-1, -0x1.107356p-2, -0x1.9a631ap-1, -0x1.1224f6p0, 0x1.34b2fep-4, -0x1.c3fee6p-2, 0x1.4946bcp-1, 0x1.c745b6p-2, -0x1.8a54b2p0, 0x1.f3ccbep-3, 0x1.ca5b52p0, 0x1.823dcap0, -0x1.b88dbep0, -0x1.21ed0ap-1, 0x1.411db6p0, -0x1.b7159ep-1, 0x1.98ad82p-1, -0x1.fb30a8p-1, -0x1.a1c1e8p-4, 0x1.56848p0, 0x1.a0dad8p0, -0x1.5378d6p-1, 0x1.b01134p-1, -0x1.81d1dp0, -0x1.8f0442p0, 0x1.26b4e6p-1, 0x1.e45c3ap-5, 0x1.1d0fbcp0, -0x1.3ddde8p-4, 0x1.570354p0, -0x1.8d6d26p-1, 0x1.4f081cp0, -0x1.d349cap0, 0x1.e45806p-1, -0x1.fdc2dap-1, -0x1.bdb8f2p-1, 0x1.269fa4p-1, 0x1.e21c0ap0, -0x1.e23136p-1, -0x1.1ee9f4p0, 0x1.61e7b8p0, 0x1.972002p-2, 0x1.f7471p-2, 0x1.b63ad6p0, -0x1.6a3312p0, 0x1.b5d882p-2, -0x1.feb0f4p-1, -0x1.28355cp0, 0x1.4aa42ep-1, 0x1.8777fcp-1, -0x1.d74a94p0, 0x1.9d2fa8p0, 0x1.86a60ep-2, 0x1.f8e19cp0, 0x1.19bc32p-1, 0x1.95c914p0, -0x1.f1471p-1, -0x1.44f7e2p-8, -0x1.87265p0, 0x1.4089f2p-1, -0x1.5221dep0, 0x1.13299ep0, -0x1.d2f4b6p0, -0x1.fe151ap0, -0x1.c82546p0, -0x1.d113a2p-1, 0x1.614c2cp-2, 0x1.a785c8p0, 0x1.5ad0acp-6, -0x1.9e5e28p0, -0x1.1a8ac4p0, 0x1.5adabap-1, 0x1.8a92bap-1, 0x1.b448fcp0, 0x1.040a12p0, 0x1.cdd88cp0, -0x1.b2091ap-2, -0x1.5c3d86p0, -0x1.95feap-2, -0x1.0bf81cp-2, 0x1.63a9c8p-1, -0x1.458d44p-5, 0x1.2300ccp-2, 0x1.d404ecp-2, 0x1.b4eb8p0, 0x1.d07c7p-3, 0x1.c083e4p-2, -0x1.87404cp-2, 0x1.6d2f2ep-1, -0x1.f92078p-4, -0x1.be3b8ep-3, -0x1.06e53ep-6, 0x1.e9c58cp-1, 0x1.82b3c2p0, 0x1.3f843ap0, -0x1.b2ea8ap0, 0x1.ab5cdep-2, 0x1.795436p0, -0x1.70123cp-1, 0x1.2b9b66p0, -0x1.79124ap-1, -0x1.fd5d8p-3, -0x1.160142p-1, 0x1.951352p0, -0x1.cfa8e8p0, 0x1.6603cap-4, 0x1.791bf8p-1, 0x1.9c366p-1, -0x1.444eb4p0, -0x1.5a5f2ap-1, 0x1.ab46d6p0, -0x1.717da2p-1, -0x1.57e344p0, -0x1.27ee54p-2, -0x1.ffec8cp-1, -0x1.55d24ep0, 0x1.e43196p0, 0x1.068686p-1, -0x1.5ea596p-1, -0x1.2eb572p-1, -0x1.5581dep-2, -0x1.2dfd04p-2, 0x1.c3b67p0, -0x1.82cc2ep0, 0x1.f8b2fap-2, 0x1.09a4b2p0, -0x1.73b4c4p0, 0x1.5aa606p-3, 0x1.fe3a5ap-2, -0x1.919686p0, 0x1.111fcep-2, -0x1.1fea6ap-1, -0x1.19b68p-1, -0x1.95299p-1, -0x1.9d1216p0, 0x1.2d22b6p0, -0x1.544d2cp-1, 0x1.1bc4p-5, 0x1.2c03fp-1, 0x1.71305ep0, 0x1.8c077ep-6, 0x1.2f7e4ep0, -0x1.828392p0, 0x1.4e48acp-1, -0x1.d20dfcp-1, -0x1.0733eap0, -0x1.ae1858p-2, -0x1.a1a1fep0, 0x1.7f8642p-3, -0x1.eaa1d6p0, -0x1.ab0bp0, 0x1.30782ep0, -0x1.14dbdap0, -0x1.358588p0, -0x1.e6393ep-2, 0x1.db69cep-1, 0x1.3f0918p-3, -0x1.830ee6p0, -0x1.1be984p-2, -0x1.99ab3ap0, -0x1.b6291ap0, 0x1.175a9ap-1, 0x1.a6dd2cp0, 0x1.c5894ep-1, 0x1.3a6936p0, 0x1.ffc704p0, -0x1.812fdcp-2, 0x1.ec442ap-2, -0x1.d65d64p0, 0x1.481f72p-1, 0x1.fbae1ap-2, -0x1.4a654cp0, -0x1.d99a6ap0, 0x1.cfff62p-3, -0x1.c8aadep-1, -0x1.431804p-5, -0x1.a71618p0, -0x1.7bc93cp0, 0x1.2ddaf6p-1, 0x1.24634ap0, 0x1.e496e4p0, 0x1.df6e8cp0, 0x1.543df4p-1, -0x1.9b459ep-1, 0x1.cfff02p0, 0x1.6e213cp0, 0x1.c8a86ap0, 0x1.950938p0, 0x1.3f3fcp0, -0x1.fc1ed4p-2, 0x1.1b90a8p-1, -0x1.1f9d5p-2, -0x1.86db22p-2, -0x1.65da1ep0, 0x1.8fdb7p-3, -0x1.1fa282p0, 0x1.7ca006p-3, -0x1.53dd04p-1, 0x1.ed939p-2, -0x1.c03f1ep0, 0x1.ce00aap0, 0x1.190bcep0, -0x1.84e652p-1, -0x1.b37086p0, -0x1.072af8p0, -0x1.d84584p-2, 0x1.9d0efep-1, -0x1.9f25acp0, 0x1.882072p0, 0x1.cef2cap-1, 0x1.125ab6p0, -0x1.168abap0, 0x1.18fbaap0, 0x1.3ea86ep0, 0x1.1ca5ecp0, -0x1.547976p0, 0x1.b86fc8p-2, -0x1.95e3ep-3, -0x1.3cae8cp0, -0x1.da5e82p0, 0x1.440742p0, -0x1.0d0032p-3, 0x1.bee01ep-3, -0x1.35697ep0, -0x1.420d64p0, -0x1.7e1b02p-3, -0x1.fed6e6p-2, 0x1.984bf2p-2, -0x1.443adcp0, 0x1.7ab9f2p0, 0x1.6a6d6p-1, -0x1.3b0356p-5, 0x1.d57cp0, 0x1.40cd72p-1, -0x1.822fc4p0, -0x1.49088p-1, -0x1.ac2974p0, -0x1.d3ef4ep-2, -0x1.b83454p0, 0x1.03921ap-1, 0x1.3e9eaap0, -0x1.916114p0, 0x1.cba49ap0, -0x1.2a6b72p0, -0x1.358a0cp-1, -0x1.7e6d38p-2, -0x1.a9030ep0, -0x1.2a30ccp-1, 0x1.02bf42p-1, 0x1.844908p-1, -0x1.7013ccp0, 0x1.8a06dp-1, 0x1.6d1a1cp-1, -0x1.92dbe4p0, 0x1.bf1e12p-4, 0x1.8f5736p0, 0x1.8f845cp0, 0x1.5f6db4p-1, -0x1.d9c8b2p-2, 0x1.cd93ep0, -0x1.b7b53ep-1, 0x1.03a87cp-7, 0x1.a51be2p0, 0x1.a0cadap0, 0x1.d4e596p-1, -0x1.28e2a6p-1, -0x1.9f5f08p0, -0x1.c7e058p0, -0x1.a5e96ap0, -0x1.04d15p-1, -0x1.1445acp0, 0x1.b8161ap-1, -0x1.2c2418p-1, -0x1.295198p-3, 0x1.466b76p0, -0x1.6ad6fap-1, 0x1.2e774p-3, -0x1.c07686p0, 0x1.da8d2cp-3, 0x1.02177ap0, 0x1.297ccep0, -0x1.afdf9ep-1, -0x1.4522eep0, 0x1.91afbcp0, -0x1.a5cdc2p-3, -0x1.f3f4aap0, 0x1.3c52ap0, 0x1.1c8eep-2, -0x1.94de2ap-1, -0x1.b31fccp0, 0x1.45a3a6p-4, -0x1.a51c82p-2, -0x1.2b27cap0, 0x1.8761p-1, -0x1.85b87ep-1, 0x1.eca098p0, -0x1.23b832p-1, 0x1.5eb6ccp-4, 0x1.8797cp-5, 0x1.bc9832p-1, 0x1.59e316p-2, -0x1.800ef8p0, -0x1.9990cp0, -0x1.db8c8ap-2, -0x1.4e3e26p-1, 0x1.2e75fep-1, 0x1.fa6256p-1, 0x1.67a966p-1, -0x1.47165p0, -0x1.5684f2p0, 0x1.cceca2p-1, 0x1.526dc8p-1, 0x1.e237a6p0, 0x1.a0892ap-5, 0x1.c5c2ep-1, -0x1.89f244p-2, 0x1.f3115p-1, 0x1.8f3bcap-1, -0x1.1615bap-3, -0x1.28524ap-3, 0x1.3417c4p-1, 0x1.a1c6fcp-1, 0x1.907766p-2, 0x1.eabf8p-2, -0x1.eef8eep0, -0x1.a33e76p-2, -0x1.1ed10cp-1, -0x1.224d5p0, 0x1.c194d2p0, 0x1.5104d4p-1, 0x1.86474p-1, 0x1.bc4da2p0, 0x1.4a5c72p-1, 0x1.c25408p0, -0x1.701d68p0, 0x1.84084p0, 0x1.4bde04p0, 0x1.401f9cp-2, 0x1.7d2f7ep0, -0x1.72541p-2, 0x1.3aeafep-1, 0x1.090638p-1, 0x1.4c28fap0, -0x1.e77016p-1, -0x1.6ad2f4p0, 0x1.13b0bap-2, -0x1.22ef86p0, 0x1.12de9ep-1, 0x1.36386ep0, 0x1.9fc894p0, -0x1.cc6f24p-1, 0x1.47112ap-1, 0x1.e180e2p-3, 0x1.90115ap0, -0x1.1a58b4p-1, 0x1.41726p-3, 0x1.d25658p0, -0x1.3c73fp-1, -0x1.43b908p0, 0x1.5aa82cp-1, 0x1.825118p-3, 0x1.22879cp-3, 0x1.6df808p0, -0x1.95d776p0, 0x1.0f032cp-1, 0x1.af647p0, 0x1.461ce2p0, -0x1.2c751ep-1, -0x1.0ff6b2p0, -0x1.d7e996p-1, -0x1.5e59a2p-7, -0x1.9b9d6p0, 0x1.6c724p-2, 0x1.36421cp0, -0x1.47e6c6p-3, -0x1.fa9ebep0, 0x1.ed525ep-2, -0x1.69f86p0, 0x1.7baf96p-2, 0x1.8b0732p-2, -0x1.f57c56p0, 0x1.931bdp-1, 0x1.e2fbeap-1, 0x1.87558ap0, -0x1.067184p0, -0x1.30ce88p-2, 0x1.2cdd3cp0, -0x1.c21bdep0, -0x1.2c6566p0, 0x1.aab9f8p-1, -0x1.d8ed2p-3, -0x1.e2597ap0, -0x1.b8326p0, -0x1.8dc5a2p-6, -0x1.1b124ap0, -0x1.ad417p0, -0x1.b29d5p0, -0x1.76fe3p0, -0x1.f148fp-1, -0x1.a2e88ep0, 0x1.7fca26p0, 0x1.8769ecp-1, 0x1.5c5b3ap-1, 0x1.584faap0, -0x1.c8c83cp-1, -0x1.6b147cp-6, 0x1.0eeaap-2, -0x1.92244ep-3, 0x1.ceeb4cp0, -0x1.bdcbcp-4, 0x1.1e824ap0, 0x1.ccee2ep0, -0x1.a0bbe2p-1, 0x1.dd371ap-1, 0x1.9862bp0, -0x1.2c3a9p-1, -0x1.1162eep-5, 0x1.8ab37ep0, -0x1.740d42p0, -0x1.699f2ap0, -0x1.3cc9cap0, -0x1.bf5ec4p-1, -0x1.598c1cp-4, -0x1.7a91p0, 0x1.0c889ep0, 0x1.c76004p-7, -0x1.b6a308p0, 0x1.2c001ap-3, 0x1.dee9c4p-3, 0x1.0d8b4ep0, 0x1.160834p0, 0x1.17464ap0, -0x1.0398d2p-1, 0x1.98c9aap-1, -0x1.e8aeeep0, 0x1.ddcb7ap0, 0x1.b4a2b8p0, -0x1.3c3c74p0, 0x1.6f313p0, -0x1.59420ep0, 0x1.628966p-2, 0x1.448e9ap-3, 0x1.7b046cp0, -0x1.535e6ep-1, 0x1.79301p0, 0x1.293d52p-6, 0x1.67ad86p0, 0x1.91e08ap-3, 0x1.f4e522p-2, 0x1.c4ca1ap0, -0x1.5415f2p-1, -0x1.fd5e46p-2, -0x1.215f0ep0, 0x1.11c7dep0, -0x1.f9f98ep-1, -0x1.3b95ep-8, -0x1.9327e6p-1, -0x1.8657acp0, -0x1.2d3dfcp-3, 0x1.2f641ap-1, -0x1.d90bcp-5, -0x1.b62842p0, -0x1.0f54c6p0, 0x1.ce16c2p0, -0x1.051474p-4, -0x1.bde34p-1, 0x1.6d238ep-2, -0x1.b41eb2p0, 0x1.0e0b12p-1, -0x1.765496p0, -0x1.d26bacp0, -0x1.f58e3p-2, 0x1.1fba58p-1, 0x1.89550cp-4, 0x1.f2dd1cp-2, -0x1.7ba6dcp0, 0x1.baf9bp0, -0x1.6c777ap0, 0x1.fc2348p0, 0x1.793ecep-1, 0x1.2ac858p0, 0x1.494e2cp0, -0x1.639842p0, 0x1.e2f326p-5, -0x1.bc9248p0, 0x1.285d22p-1, -0x1.eb577ep-1, -0x1.ac2f86p0, 0x1.ef7c66p-1, 0x1.592fd4p0, -0x1.356892p-2, -0x1.d0fae4p-2, -0x1.f1abd8p0, -0x1.a68c64p0, -0x1.a4e86ep-4, -0x1.2afdep0, 0x1.6dfa2cp0, -0x1.878d52p-1, -0x1.d4eb2cp-5, -0x1.c6f9d8p0, 0x1.048beap0, -0x1.f76a9cp-1, 0x1.03a98cp0, -0x1.c90cf4p-1, -0x1.daa2d4p-1, -0x1.d90cp0, 0x1.0cef06p0, 0x1.9229bp0, 0x1.c6c3bcp0, 0x1.b23f7ep0, -0x1.fc9e5cp-1, -0x1.8847fep0, 0x1.056c34p0, -0x1.45b4b8p0, 0x1.6fb608p0, -0x1.0d8854p-2, -0x1.484498p-1, -0x1.231c62p-2, -0x1.0772a8p-2, -0x1.8a8dbcp-1, 0x1.702046p0, 0x1.c1eed6p-3, 0x1.334d38p-1, 0x1.c25ea4p0, 0x1.fec5aep-1, 0x1.2f498cp-3, -0x1.b3069p0, -0x1.b14c3cp-3, -0x1.8d70aep-5, 0x1.ca276p-4, -0x1.fd2fep0, -0x1.f6b982p-2, -0x1.55eac4p0, -0x1.4256dcp0, -0x1.68ab6cp0, -0x1.bfc334p-1, 0x1.2dff7p-2, 0x1.bccfe8p0, 0x1.84f39ep-4, 0x1.b22a8p0, 0x1.ca45dp0, -0x1.9cb08p-1, 0x1.74ac76p-3, -0x1.aecf0cp0, -0x1.28df62p0, -0x1.6040f4p0, -0x1.8ff9fcp-1, -0x1.dda1dcp-4, 0x1.9bd0fap-2, 0x1.20fbd8p-2, -0x1.5dc1e2p-1, 0x1.13a034p-1, -0x1.99582p0, 0x1.4868ecp0, -0x1.3fdc42p-2, -0x1.b23ccep0, -0x1.2c541p0, -0x1.3df282p-1, -0x1.e4b39p0, 0x1.7fdee4p-4, -0x1.ab7aaap0, 0x1.3c20a4p0, 0x1.eaff5p0, 0x1.d2cecap0, -0x1.cee992p-1, 0x1.566072p0, -0x1.f7c9d6p-1, -0x1.57a0fep-3, -0x1.c597e6p-1, -0x1.26aac2p-2, 0x1.1c5f32p-1, 0x1.d3754ep0, -0x1.c7459ap-1, -0x1.b44ep0, -0x1.9d8d9cp-4, -0x1.387f7ap-3, 0x1.d67a1ap0, 0x1.e2ff3cp0, 0x1.a25514p0, -0x1.e8f59ap0, 0x1.e6f99ap-2, -0x1.9bd2d6p0, -0x1.6fcbcap0, 0x1.2d836ep0, 0x1.b6ba02p0, 0x1.f7da6cp-4, 0x1.1f9adap0, 0x1.f9f438p-4, 0x1.db661p-4, -0x1.8626e8p0, -0x1.876c16p-1, -0x1.395bbp0, -0x1.e3a52p-3, -0x1.3ff32cp-1, 0x1.33c8cp0, 0x1.a42aep-3, 0x1.c9f526p0, 0x1.8af614p-2, -0x1.289de6p0, -0x1.0cda2p0, -0x1.50e7a2p0, -0x1.043ba8p-1, 0x1.374088p-6, 0x1.949216p-1, -0x1.8e61a2p-2, 0x1.24dea2p0, -0x1.63c5d6p0, 0x1.458698p0, -0x1.772bbp-5, -0x1.eaaf48p-3, 0x1.4544fcp-4, 0x1.efb10cp0, -0x1.71893cp-1, 0x1.ab4ea2p-2, 0x1.2bace2p-1, 0x1.20ec3p0, -0x1.29906p0, 0x1.6f9b82p-3, -0x1.042ea2p0, 0x1.58a2cp0, 0x1.0002cap-1, -0x1.9a656ap0, -0x1.39e734p0, 0x1.a8cadep0, 0x1.34b51cp-1, 0x1.15ee0ap-3, 0x1.8f45a2p-5, 0x1.8931a8p0, -0x1.fd0bb8p0, -0x1.65f0a8p-1, 0x1.05e6f4p0, 0x1.6467cap0, -0x1.eb2228p-3, -0x1.c558c2p-1, 0x1.91c3ecp-1, 0x1.85bf78p-4, -0x1.219bdep0, 0x1.44bd5p0, 0x1.90392p-2, -0x1.77563cp0, 0x1.b2910ap-7, 0x1.81029p-4, -0x1.c02a64p0, -0x1.5275p0, 0x1.a607a6p-1, -0x1.5b9914p0, -0x1.987dap0, 0x1.975ac4p-1, -0x1.79af28p-2, 0x1.f78eccp-1, 0x1.895e4ap0, -0x1.fa8356p0, 0x1.dd94f8p-2, 0x1.34c408p-1, -0x1.fa4a2cp-5, -0x1.76bf36p-2, 0x1.01d706p0, 0x1.f885ap-1, -0x1.0c1498p-3, -0x1.a2465p-3, -0x1.08a49cp0, -0x1.594cap-1, -0x1.a41dccp-1, 0x1.7f0308p0, -0x1.73b27cp0, -0x1.97522p0, -0x1.108bdap-4, -0x1.01a97ep-2, -0x1.08be62p-1, -0x1.9ef766p-2, 0x1.71ffe8p-1, -0x1.cb0dd4p0, 0x1.f50a3ep0, 0x1.e30fc8p-1, -0x1.3b1cfp-3, -0x1.89501p0, 0x1.e3554ap0, -0x1.8fbc42p0, -0x1.bc048p-3, 0x1.70f61cp0, 0x1.f5e27p0, 0x1.f3da7ep-4, -0x1.b386eap0, 0x1.53cd1ap0, 0x1.340088p0, -0x1.bdf1dp-3, 0x1.e344d8p-3, 0x1.6a21f4p0, -0x1.20b98ep-1, 0x1.0be6e4p-1, 0x1.7fa6fep-2, -0x1.474d52p-1, -0x1.ee0bcep0, 0x1.f44a94p0, 0x1.550ccap0, -0x1.a209bep0, 0x1.6f24f8p0, 0x1.a5e40ap-1, -0x1.76353ap-1, 0x1.41242cp0, 0x1.ec3546p-1, -0x1.40cc28p-1, -0x1.bde7bep0, -0x1.3d567p-2, 0x1.844cdap0, -0x1.60197ep0, 0x1.e61e34p-1, -0x1.596aaap0, 0x1.55bc52p-3, 0x1.43fc54p0, 0x1.9ed28ep-1, -0x1.60e146p-1, -0x1.1a6a94p0, -0x1.bcc6ep0, -0x1.143894p0, -0x1.9713a2p0, 0x1.d44204p-3, -0x1.b990cp-1, 0x1.90c35p-1, 0x1.b0361ep0, 0x1.e52d7cp0, 0x1.35c80ep-1, 0x1.f4b2fp-1, 0x1.be61ap-1, 0x1.b979cp0, 0x1.578bccp0, -0x1.008768p0, 0x1.068a2p0, -0x1.cbd912p0, 0x1.d62f9p-1, 0x1.cf23a6p-2, -0x1.6ca072p-4, -0x1.5ebfe4p0, -0x1.67e8ap0, 0x1.7e17cep-2, 0x1.c5bb36p-2, -0x1.7a4618p0, 0x1.c398aep-1, 0x1.166962p-1, 0x1.12f9a4p-2, 0x1.d950eep-1, -0x1.8dc27ep-1, 0x1.319202p0, 0x1.960b94p0, 0x1.93816cp0, 0x1.655276p0, 0x1.bd8232p-1, -0x1.d1e96ep-3, -0x1.d11d9ap-1, 0x1.9c3034p-2, -0x1.f6a76ap-2, -0x1.42408cp-2, 0x1.0e588p-2, 0x1.5ccd5ap0, -0x1.cc5538p0, 0x1.dab628p-2, 0x1.5d4f7cp-7, 0x1.3edb8ap-1, -0x1.956482p0, 0x1.7e85dp0, 0x1.b0a24p-1, -0x1.449ee6p-1, 0x1.ccc39ap0, -0x1.4f639p0, 0x1.d75424p-2, 0x1.08490ap0, -0x1.aa561cp0, -0x1.93f3dep0, -0x1.07621ap-1, -0x1.c82ffcp0, -0x1.c03896p0, -0x1.83896ep0, 0x1.dbd482p-1, -0x1.0cedc6p0, -0x1.fda356p0, -0x1.fb3886p-1, -0x1.d90ba4p-3, 0x1.826dfep0, -0x1.7af602p-1, -0x1.d94f02p0, 0x1.9f4ep0, -0x1.4a0e5cp-7, 0x1.836ba8p0, 0x1.943ba2p0, -0x1.c3303p0, 0x1.935aecp-2, 0x1.13b4c8p0, 0x1.890696p-2, 0x1.441178p0, -0x1.17e0bap-1, -0x1.f2c3f8p-2, -0x1.70e538p0, -0x1.29ee9cp0, -0x1.7c7c4cp0, 0x1.f27e98p-2, 0x1.4b3644p-3, 0x1.f6686cp0, -0x1.e57c16p0, -0x1.6774eep0, 0x1.6f288ap0, 0x1.ed0252p-1, 0x1.0b2f9cp-4, 0x1.81d338p0, 0x1.983174p-1, -0x1.651288p0, 0x1.17a304p-2, 0x1.c73aa2p0, -0x1.da879ap0, -0x1.e20924p-1, -0x1.afa7d8p0, 0x1.a7c666p0, 0x1.276a8ap-2, -0x1.c60cep0, -0x1.1ce5ep-1, 0x1.dd595cp0, -0x1.dceb44p0, -0x1.66636ep-1, 0x1.4cb9fep0, -0x1.7d8ed2p-2, -0x1.604fdep0, 0x1.7793a2p0, -0x1.95ff58p-2, -0x1.05c61ap0, 0x1.181744p-4, -0x1.e20a78p0, 0x1.60577p-3, 0x1.230692p0, -0x1.0082f8p0, 0x1.4b6d2p0, -0x1.0928d6p0, 0x1.bf2ecep0, 0x1.d3f20cp-1, 0x1.1027e6p-3, 0x1.1a441ep-1, 0x1.84cccap-3, -0x1.ac4d6cp-1, -0x1.498ccap0, 0x1.1ad018p0, -0x1.4117dap0, 0x1.305918p0, -0x1.f00f7p0, 0x1.bf1df2p-2, -0x1.e8e01ep0, -0x1.64a396p0, 0x1.b8ecfp-3, 0x1.fa87fp-1, 0x1.362778p-4, 0x1.0d66fep0, 0x1.482b36p0, 0x1.e530b8p0, 0x1.1a006p-1, 0x1.f153aap0, -0x1.233acap0, 0x1.9dbc9p0, 0x1.168abap-1, 0x1.9d11f2p0, -0x1.28af84p0, -0x1.ff9ca2p0, 0x1.dff044p-1, -0x1.2e098ap-1, 0x1.071064p-1, 0x1.d7f038p0, -0x1.c691dep0, 0x1.5515d8p-2, -0x1.9375aap-3, -0x1.cf680ap-2, 0x1.2a160ep0, 0x1.fd6e2p-4, -0x1.68506p-1, -0x1.d5ba36p-1, 0x1.35b544p0, -0x1.718214p0, 0x1.0798cap-1, 0x1.cb3dbep0, 0x1.f0bb9p0, -0x1.24c194p0, -0x1.b85cd4p-1, 0x1.b26d7p-2, -0x1.2be8a6p0, 0x1.ec30bp-2, -0x1.5b97e8p0, 0x1.bc266ep-1, -0x1.d6912cp-4, 0x1.5f6458p0, -0x1.affd3cp-2, 0x1.8f40bap-2, -0x1.29d814p-1, -0x1.73641ep-1, 0x1.b5f5d6p-1, -0x1.bbf884p0, -0x1.c851ccp0, 0x1.ed372p-3, -0x1.42c182p0, 0x1.6d1e5p0, 0x1.870cfap0, -0x1.09ce72p-1, -0x1.1703d2p0, -0x1.11012ap0, 0x1.262f72p-2, -0x1.8856dap0, 0x1.3d63d8p-2, -0x1.627ce6p0, 0x1.6b0ef8p0, -0x1.d71774p0, -0x1.0b9a2p0, 0x1.a5028ep-2, -0x1.f3a3bcp0, 0x1.fe14ep0, 0x1.442612p0, -0x1.5c20c2p-1, 0x1.044caep0, 0x1.45428cp0, 0x1.b3ad52p0, 0x1.6cd838p0, 0x1.f9c5f2p0, 0x1.afded2p0, -0x1.5eec32p-1, 0x1.e4a01p-2, -0x1.ffd5eap0, -0x1.61876ep0, -0x1.384e0cp-1, -0x1.3168eap0, 0x1.e6ee46p-3, 0x1.6f753ap-1, 0x1.405c4cp0, -0x1.b7fa9ap-1, -0x1.63b652p0, 0x1.3dc5fap-1, -0x1.20b1ccp-1, -0x1.e789a2p0, 0x1.f6d5d8p-1, -0x1.b1408ap0, 0x1.76cc3cp-3, -0x1.0046c8p-2, 0x1.fefcaep-1, -0x1.fcff28p0, -0x1.f541c8p-3, -0x1.105c7ep-2, -0x1.b08f4cp0, -0x1.343b9ap-1, -0x1.c159f4p0, 0x1.b333c8p0, -0x1.3d2ef4p0, 0x1.4ebdc8p0, -0x1.e91e26p-2, -0x1.f5dd16p-3, 0x1.bd31cap0, -0x1.1d4de4p0, 0x1.188fa4p-7, 0x1.991d04p-1, 0x1.73a03p0, 0x1.81fb98p0, 0x1.d2f708p0, -0x1.f37dc8p-1, -0x1.4f5a5ap-1, 0x1.1524b8p0, -0x1.bcf8a4p0, -0x1.a1ba1p-1, 0x1.ab44acp-2, 0x1.d90872p0, -0x1.ec793cp0, 0x1.5a71cap-2, 0x1.e0389p-1, -0x1.11e496p-1, -0x1.13ab14p-2, -0x1.b2ecfcp0, -0x1.c00ce6p0, 0x1.13a37p0, 0x1.5c58acp-1, -0x1.8d5864p-1, -0x1.bc25dcp-4, -0x1.8d257ep0, 0x1.281004p-3, 0x1.229168p0, -0x1.5f3922p0, 0x1.51e4bp0, -0x1.6bcb84p-3, 0x1.2a8c28p0, -0x1.898e88p0, 0x1.7932f6p0, -0x1.ef09dcp0, 0x1.498bfap0, 0x1.7977d8p0, -0x1.deb64ep0, 0x1.44f29ep0, 0x1.d17492p0, -0x1.a29b92p0, -0x1.6031dcp-2, -0x1.ed1c6p0, -0x1.fe79p-1, -0x1.c55f68p-4, 0x1.7bb412p0, 0x1.1585bcp-1, -0x1.8d0d44p-4, 0x1.52126cp-1, -0x1.813976p-2, -0x1.281e9p-1, 0x1.44789p-1, 0x1.117e84p-1, -0x1.e6c462p0, 0x1.1e0d7ep0, -0x1.70131cp-1, 0x1.07e106p0, 0x1.889f4cp-1, -0x1.3dc684p0, -0x1.5764a8p-1, -0x1.1ac952p-2, 0x1.50d04p-4, -0x1.e9055p0, -0x1.2823f2p0, 0x1.8803fcp0, -0x1.677b1ep-2, 0x1.12f6c8p0, 0x1.1b6328p0, 0x1.27586cp-1, -0x1.ad34fp-1, -0x1.1efde8p-2, -0x1.1a17bp0, -0x1.a72feap-1, -0x1.eb8546p-2, 0x1.4c525ap-1, -0x1.9ce048p0, 0x1.55927cp0, 0x1.923d56p-1, 0x1.9ecf76p0, 0x1.12c5dap0, -0x1.7cbe56p0, 0x1.50362ap-3, 0x1.0eec7cp0, 0x1.5b5cdap0, 0x1.ef3c48p-1, 0x1.e36d44p0, 0x1.9a3e96p-1, -0x1.bb4d72p0, -0x1.f406aap-1, 0x1.219b7cp0, 0x1.dba176p-2, -0x1.d0921p-2, -0x1.35a318p-3, -0x1.8d6012p-9, 0x1.ef803ep-1, -0x1.6df9f6p-1, 0x1.d90612p0, -0x1.ad2e5p-1, 0x1.6ea3c2p-1, -0x1.e9101ep-2, 0x1.404812p0, 0x1.4185c8p-3, -0x1.5ae84cp-1, 0x1.d65a1ap-1, 0x1.1140e2p-1, 0x1.e0a828p0, -0x1.f53614p-1, 0x1.8cf7acp-1, 0x1.c0c0ap-1, 0x1.2d8944p-1, 0x1.3fb6c6p0, -0x1.69ee68p-2, 0x1.dcc79ap0, 0x1.c83a78p0, 0x1.4cffcp0, -0x1.4a59e8p0, 0x1.ec6502p-3, -0x1.ef6554p0, -0x1.e0b454p-2, 0x1.c00dd8p0, 0x1.fbc966p0, -0x1.1cc604p0, 0x1.5ce66ep-1, -0x1.9b267cp-1, 0x1.798eecp0, -0x1.9b391ap-6, 0x1.c4470cp0, 0x1.7d955cp-2, 0x1.70c6bcp0, 0x1.d51208p-1, 0x1.fa361ap0, -0x1.903eaep0, -0x1.27d78ap-1, 0x1.2bea14p-2, 0x1.104126p-1, -0x1.8a1cf2p-1, -0x1.10b686p-1, 0x1.a96058p0, -0x1.3b0a42p0, -0x1.0f6a54p-2, 0x1.511d0ap-2, 0x1.f819bcp0, -0x1.32bf6p-1, 0x1.e9afdcp-2, -0x1.9c9a7ap-1, -0x1.0be088p0, 0x1.e8d76ap-2, -0x1.7b1604p0, -0x1.60ccdep0, 0x1.f85838p0, 0x1.615308p0, 0x1.16e382p0, 0x1.ec5c26p0, 0x1.b1517p0, 0x1.bd9c1ep-5, 0x1.dbae64p0, -0x1.b11316p0, -0x1.033e08p0, -0x1.79bb9p-2, 0x1.572e42p-1, 0x1.68b1cep0, -0x1.c434a6p0, 0x1.f325ap-1, 0x1.243162p0, 0x1.516a06p-3, 0x1.b45208p-2, -0x1.0c3adep0, 0x1.b5fa2cp0, -0x1.375a4p-1, 0x1.2b24ccp0, 0x1.fc6f1ep0, 0x1.78feacp0, 0x1.2addcp-2, -0x1.ecfc92p-2, -0x1.b4856ep0, -0x1.e629e6p0, -0x1.ef75ecp-1, 0x1.0096c4p-4, 0x1.655ee8p0, 0x1.7c9bb4p-1, 0x1.ccfed4p0, 0x1.5426f6p-1, 0x1.b86ddep-1, -0x1.b7927p0, -0x1.59695p0, -0x1.43d988p0, 0x1.c9d612p0, -0x1.fc02a2p0, -0x1.c46f88p-4, -0x1.e35608p0, 0x1.f1fe86p0, 0x1.6d2518p-2, 0x1.102edcp-4, 0x1.d1ee6cp0, 0x1.87e224p-1, -0x1.b4a23p-1, -0x1.a14fep-1, 0x1.c986fap-1, 0x1.34b262p0, 0x1.26ea6ep-1, -0x1.6f9d14p-3, -0x1.e01ff2p0, -0x1.f8bf5cp-1, 0x1.dba7e2p-1, 0x1.1a2c22p-1, -0x1.a1409cp-1, -0x1.721fa2p0, -0x1.d4d34ep0, 0x1.a3393ap-1, 0x1.ed58ccp0, 0x1.bb4138p-1, -0x1.055ee4p-2, -0x1.15bb16p0, -0x1.6be264p0, 0x1.6ba13ep0, -0x1.a351ep-1, 0x1.4dfda4p0, -0x1.a95c4ap0, 0x1.21d8d2p0, -0x1.82ca06p-1, 0x1.3ef6cp0, 0x1.b745f2p-1, 0x1.76ce36p0, -0x1.69caf6p-3, -0x1.435df8p0, 0x1.966ba2p-1, 0x1.2a9d48p0, 0x1.47db8p0, 0x1.dad3b2p-1, 0x1.8a87e4p0, 0x1.ec9502p-1, 0x1.c51f1p0, 0x1.b7b812p-1, 0x1.d0a104p-1, -0x1.bab2d4p-1, 0x1.b6eee2p-1, 0x1.bf07e8p-1, -0x1.1cbbb4p0, -0x1.1488f4p-3, -0x1.ca5f9p0, 0x1.a39b6ep-1, -0x1.f4c94ap-1, -0x1.e66b34p0, -0x1.97d9fap-1, -0x1.33f5fap0, -0x1.17568ap0, -0x1.a207ep0, 0x1.a480acp-1, -0x1.611702p0, -0x1.2b8cecp-2, -0x1.b960b4p0, 0x1.e1bff6p-2, 0x1.fa027p-1, 0x1.8d09dap0, -0x1.7266d2p0, 0x1.5fea02p0, 0x1.4df992p-2, 0x1.c73be2p0, 0x1.d23e84p-1, -0x1.2d0baap0, -0x1.cd4132p0, 0x1.ad14f8p-1, -0x1.21e69ep0, -0x1.f4e21cp-1, 0x1.f27f8cp-3, -0x1.13794p-2, 0x1.3a8faep-1, -0x1.5e231ap-1, 0x1.49446ap-1, 0x1.0d33fp0, -0x1.5f2494p-1, 0x1.dd653p-1, -0x1.94cb62p0, -0x1.020894p0, 0x1.f90f8p0, 0x1.c6e74p-1, 0x1.1dcb28p0, 0x1.b93828p0, 0x1.360fb4p0, -0x1.64cc22p-1, 0x1.c0125cp-1, -0x1.6923b6p-1, 0x1.3f0f28p0, -0x1.90aefep0, -0x1.e8e1f4p-2, -0x1.03ca6ep0, -0x1.4ef296p-2, -0x1.b93592p-2, 0x1.0db428p-4, -0x1.0d76cap0, 0x1.849192p-2, -0x1.f74424p-1, 0x1.e901dp0, -0x1.6ff56p0, -0x1.6f3b7ep-2, -0x1.457622p0, -0x1.386dbp0, -0x1.a3961ep0, -0x1.ca220ep0, -0x1.249fb8p-1, -0x1.7320ccp0, 0x1.4508ep0, 0x1.bd9f76p0, 0x1.288b86p-4, 0x1.a42f9cp0, -0x1.446408p0, 0x1.dde32ap0, 0x1.fa9d9ep0, 0x1.eb50d8p-1, 0x1.24f6b6p0, -0x1.3fecacp-1, 0x1.d72968p0, 0x1.18228cp-2, 0x1.e1148ap-1, -0x1.6b5342p0, 0x1.685f44p-1, -0x1.e76c06p0, -0x1.3f653ap0, 0x1.6aa484p0, 0x1.06831p-4, 0x1.69d41ep0, 0x1.e262c6p-2, -0x1.006b4cp0, -0x1.2667dep-1, 0x1.0ce03cp-1, 0x1.36ebe8p-1, -0x1.066bfap0, 0x1.bbe7e2p-2, -0x1.3f33bp-2, 0x1.b1641cp-1, -0x1.e1af8ep-2, -0x1.c05a64p0, -0x1.f6ea6ap0, 0x1.ccf3d2p0, -0x1.5fa32cp0, 0x1.f26208p-1, 0x1.90113ap0, 0x1.b7e26ap0, 0x1.bfd39cp-1, 0x1.07d3dep-2, -0x1.2253e2p0, -0x1.052ce2p0, -0x1.6c9ba2p0, -0x1.60809cp-1, 0x1.177d5p0, 0x1.0959a8p-2, 0x1.07e854p-1, 0x1.716d2p-1, 0x1.7a09ap-1, -0x1.58d5f4p0, -0x1.5df1dep-5, -0x1.4a9bdp0, 0x1.d4660cp0, -0x1.1aa564p-2, -0x1.7e5efcp-5, 0x1.31ce06p-1, 0x1.e341d2p-1, -0x1.b0c9aep0, -0x1.c397a4p-1, -0x1.6f576ep-1, -0x1.6e12d6p0, 0x1.8e9cf2p0, 0x1.7535a8p-2, -0x1.5dfe38p0, -0x1.ef0bcep-3, -0x1.3ad09p-5, -0x1.888a18p0, 0x1.40df18p0, -0x1.4367f8p-1, -0x1.76b0a6p0, -0x1.b29c1ap0, -0x1.fc137ap0, 0x1.95fc1p0, 0x1.5a286ap-6, -0x1.871d9ep-1, 0x1.e7ddb4p0, 0x1.bac01ep0, -0x1.c07ec4p0, -0x1.ebbfdap0, 0x1.29fa0cp0, -0x1.034dep0, -0x1.71e9e4p0, 0x1.4f1becp-1, -0x1.0f11cep-1, 0x1.0e287ap-5, 0x1.762af4p-1, -0x1.afb344p0, -0x1.64d986p0, -0x1.52961p-1, -0x1.b70c02p-3, -0x1.339176p0, 0x1.ae68fap0, 0x1.bc3be4p0, -0x1.91095cp-1, -0x1.a403c2p-1, 0x1.7e1b2p0, -0x1.852206p0, 0x1.8cf658p0, -0x1.b80f36p-2, 0x1.4ff8f8p-2, 0x1.a6f342p0, 0x1.17b558p0, -0x1.1f868ap-1, 0x1.dc23f6p0, 0x1.04f6ap-2, 0x1.dee01ap-3, 0x1.0c902p-1, 0x1.3668cep-4, -0x1.f351f4p-3, 0x1.f58afap0, 0x1.63db8cp-1, 0x1.7e8e3ap0, 0x1.23133ap0, -0x1.51292ep0, 0x1.8aa8d6p0, -0x1.8681acp0, 0x1.63f5a8p-1, -0x1.e637d4p0, 0x1.73654cp-6, 0x1.925c0ep-1, -0x1.0b17ccp-3, 0x1.02b8ecp-2, -0x1.9e4282p0, 0x1.ca5a98p0, -0x1.5c6fe6p0, -0x1.ee1146p-2, -0x1.d0694cp0, -0x1.17d31ep0, -0x1.58447ap-2, 0x1.852ccep-1, -0x1.cb824p-2, -0x1.1a0d88p-1, 0x1.fa4574p0, -0x1.f714e6p-1, 0x1.2bd514p0, 0x1.8708f8p-2, -0x1.158d8p0, -0x1.ffbcb6p0, 0x1.84d5a8p0, 0x1.1c17aep-5, 0x1.b46cf4p-2, -0x1.15ec24p-1, -0x1.3435dp-1, -0x1.9674eep0, 0x1.4ea01ep0, 0x1.d3e4aep-2, 0x1.276902p-2, -0x1.b3407ap-1, 0x1.9f32b6p-1, -0x1.5518d4p-4, 0x1.42a9dep0, 0x1.d4d3f8p0, 0x1.eafa72p-3, -0x1.2655c8p0, 0x1.c53d4ep0, 0x1.e2608cp0, 0x1.031dcap-4, 0x1.560a7ap-4, -0x1.feb7eap-2, -0x1.aff3eep-2, 0x1.17f8a4p-2, -0x1.0f998p-5, 0x1.84e994p-1, -0x1.33f7e4p0, 0x1.3e7584p-1, 0x1.dc6cdp-2, -0x1.4d651cp0, 0x1.635f32p0, 0x1.dee16p0, 0x1.82ad7cp-2, -0x1.fc4b5ap0, 0x1.9c44ecp-1, 0x1.c1447ap0, -0x1.923498p0, -0x1.15e582p0, 0x1.0c674ap-2, -0x1.fcc012p-4, 0x1.15f0ap0, 0x1.fda48ep-1, -0x1.facbecp0, 0x1.654682p-3, 0x1.0c54ap0, -0x1.e7b202p0, 0x1.c916a4p0, 0x1.00b7c8p0, 0x1.c6273cp-2, -0x1.93c7eap0, -0x1.f7cbf6p-2, -0x1.c237b6p0, -0x1.a67694p-1, -0x1.85027ep-1, -0x1.241f8ap0, -0x1.c560dp-4, 0x1.5cf176p0, -0x1.e5cf14p-3, -0x1.eb156ap-2, 0x1.da5646p-2, 0x1.6f18e2p0, -0x1.c413c6p0, 0x1.a0f312p0, 0x1.65afacp-1, -0x1.cfe8e2p0, 0x1.0c1036p-1, 0x1.1fdf8ep-2, -0x1.61fe34p0, 0x1.45171p-3, 0x1.bfa9d2p-4, -0x1.ccaf9ap-1, 0x1.a20936p-1, 0x1.dd6c3p0, -0x1.e6b47cp-2, -0x1.5ff522p0, 0x1.660b66p0, 0x1.744b82p-3, 0x1.374e06p-1, 0x1.beda1ep0, -0x1.e9273p-1, 0x1.a4c4b4p-1, 0x1.7a6d92p-1, 0x1.5d7ac8p-1, -0x1.c36c5cp0, -0x1.cac9a6p0, 0x1.e2f4ep0, 0x1.9c5acep-1, -0x1.372788p-2, 0x1.816dbcp-1, -0x1.5faad8p0, -0x1.c0a1a4p0, 0x1.35942p0, -0x1.48b08cp-1, 0x1.107612p-3, -0x1.9717fp-2, 0x1.9f188p0, 0x1.e0ae2ep-1, -0x1.0d5478p-2, 0x1.9b02e2p-1, 0x1.aa8a4ap-3, -0x1.f97324p0, -0x1.91d326p0, -0x1.192714p0, 0x1.f659e2p-2, -0x1.55686ap-2, 0x1.cc0bcep0, 0x1.0015d6p-1, -0x1.41a7bcp0 };
float keras_activation_3_test1_array[6] = { 0x1.f75064p-3, 0x1.214cfcp-4, 0x1.bab6f2p-6, 0x1.d66c34p-4, 0x1.07d79p-1, 0x1.b0ef8p-6 };
float c_activation_3_test1_array[6];
float test2_dense_input_input_array[2622] = { 0x1.8fbccap-1, -0x1.5edbc4p0, 0x1.f4613ep0, -0x1.e949bp0, -0x1.67465ep0, 0x1.c91f26p-1, -0x1.d056bep-5, -0x1.364fp0, 0x1.6204a8p0, -0x1.da3366p0, 0x1.59a468p-4, 0x1.e1d684p-1, -0x1.4c450ap-1, -0x1.04799cp-5, 0x1.94fdd2p-3, -0x1.daaeb4p-2, -0x1.a4d14p-2, 0x1.16246p-4, 0x1.817ffp-2, -0x1.3bd71p0, 0x1.5b9a6ep0, 0x1.a00056p0, -0x1.d8e0fep-1, 0x1.d6a84ap0, 0x1.7deb32p0, 0x1.a6f7aap0, -0x1.b5c838p0, -0x1.f90276p0, -0x1.9f589p-2, -0x1.6e5e74p0, -0x1.4f356cp-2, -0x1.a33d9p0, -0x1.3238bap0, 0x1.df7004p0, 0x1.1dccd2p0, 0x1.b07a38p0, -0x1.70608cp0, -0x1.aa887ap0, -0x1.b8bbb4p-2, 0x1.04c28ep0, 0x1.70f63ep-1, -0x1.c55d44p0, 0x1.d04ad8p-2, -0x1.9a1704p0, 0x1.6894ap-1, -0x1.566d3cp0, 0x1.be091p0, 0x1.119124p0, 0x1.dd8238p-1, -0x1.322f26p0, 0x1.a70c0ep0, 0x1.ddb39p0, 0x1.11d144p0, 0x1.1ba8b8p0, -0x1.8e4466p-2, -0x1.34029ep-5, 0x1.67fc1p-3, -0x1.227038p0, 0x1.e9bb32p0, 0x1.b32118p-3, 0x1.241d6cp0, -0x1.e285bcp-3, 0x1.8510d6p-1, 0x1.a335dp-2, -0x1.5dc3ap0, 0x1.3f9266p0, 0x1.e5e3f2p-1, 0x1.c27d4p0, 0x1.d7a08ep0, 0x1.6c94cp0, -0x1.cb3b28p0, -0x1.b528fp-1, -0x1.ea2364p-1, -0x1.b2ac06p-1, -0x1.2a37bap-1, -0x1.2d6184p-6, -0x1.4ebcaep-5, -0x1.f65534p0, 0x1.8bdb76p0, 0x1.e95e9ep0, -0x1.0c9c1ep-3, 0x1.ef7e2cp-2, -0x1.450922p0, -0x1.8365c4p0, -0x1.3d7cfp0, 0x1.777feap0, 0x1.1b6a64p-1, -0x1.07233cp0, -0x1.95ffbep-4, 0x1.99d43ep-1, 0x1.100a1ep0, 0x1.1e01bep-1, -0x1.9ac5a2p-4, -0x1.c9781p0, -0x1.d91d0cp0, -0x1.e9ce16p0, -0x1.c5d5cep0, -0x1.f5cd74p0, -0x1.52bc5cp0, -0x1.a6b0e6p-1, 0x1.2c74e4p0, -0x1.8281b2p0, -0x1.2cdab6p-7, -0x1.334692p0, 0x1.30ca0ep-1, -0x1.8ec5d2p-1, -0x1.06ac8p0, -0x1.467b6p0, -0x1.d8bdd6p-1, -0x1.754364p-3, 0x1.73faeap-1, -0x1.18dbb4p-4, -0x1.924e88p-1, -0x1.54062ap0, -0x1.3ccbdap0, -0x1.73e4e6p-2, 0x1.3cc6cp0, 0x1.4d6208p0, -0x1.a0da9p-5, 0x1.3c5244p0, -0x1.352266p0, 0x1.cca9a2p-2, -0x1.42fb8ep-1, 0x1.fba162p-5, 0x1.7f70fep-1, 0x1.06a712p0, 0x1.bea892p-1, 0x1.486828p0, 0x1.790896p-1, -0x1.4b4026p-1, 0x1.de0f1ap-4, 0x1.47e66ap0, -0x1.fb4722p-3, -0x1.e6a41cp0, -0x1.f3727ap0, -0x1.f5b304p0, -0x1.e13326p0, -0x1.ad1fa8p-1, -0x1.7f8afap0, -0x1.2f9afep-2, -0x1.80a2f6p-1, 0x1.91d174p-1, 0x1.f75ee4p0, -0x1.4e9094p0, -0x1.c4713p-3, 0x1.aa5668p0, 0x1.db62b8p0, -0x1.ab1e58p0, 0x1.c3980ep0, 0x1.1e486ep0, -0x1.f2277cp0, -0x1.497c26p-4, 0x1.55c15p0, -0x1.957e26p-2, 0x1.e0bcb8p0, 0x1.d2ff3p0, 0x1.b2fc24p0, -0x1.29dffap0, -0x1.dbbc7cp-2, -0x1.dd502p-1, -0x1.943e08p0, 0x1.79acaep-4, 0x1.9793aap-3, 0x1.3bf7a8p0, 0x1.da8ffp0, -0x1.f8f136p0, 0x1.3cea8cp-2, -0x1.bf761cp-4, -0x1.a9b3eep0, -0x1.99964cp-1, 0x1.a261c4p-2, -0x1.6e7e5ep-1, 0x1.0080ccp-3, -0x1.ee3a9ep-1, 0x1.cb839cp0, -0x1.809078p-2, 0x1.5320e2p0, 0x1.83e8aap0, -0x1.776b4p-1, 0x1.8c9fp-1, -0x1.880064p0, -0x1.36fc1p-1, -0x1.1c97c4p-3, -0x1.5895aep0, -0x1.1cf1b4p-2, -0x1.f8716p-4, 0x1.b32c04p0, -0x1.faec94p0, 0x1.c0f662p0, 0x1.a02b6ap-2, 0x1.0be258p0, 0x1.5ba9dcp0, -0x1.09075p-2, -0x1.d611e2p0, 0x1.7f06e2p-1, 0x1.219d4p-1, -0x1.f19ea4p0, 0x1.ae9e5p0, -0x1.e643b2p0, 0x1.5fa528p0, 0x1.5e8a3p0, -0x1.752528p-2, -0x1.2a37e8p0, 0x1.fd7b1ap0, -0x1.73915p0, 0x1.a27908p-3, 0x1.7dd2aap-3, 0x1.477288p0, 0x1.f0128p0, 0x1.765246p-2, -0x1.b0ed4p-2, -0x1.bd4976p-1, 0x1.73ddp-4, 0x1.8c87f4p0, -0x1.2f4bc2p-3, -0x1.1df426p0, -0x1.eff0dcp-1, -0x1.e11c02p-1, -0x1.cf1e98p-2, 0x1.a0f4dep-1, 0x1.7d525ep-4, -0x1.86bd02p-5, -0x1.34b3dcp0, 0x1.b7ba4p-2, 0x1.12ebc6p-2, 0x1.cc37d4p-2, -0x1.33886ap0, 0x1.b56366p0, -0x1.854234p0, -0x1.22477cp-2, -0x1.a2bebcp0, 0x1.14c09cp-1, -0x1.08ebf8p-1, -0x1.8ffc1cp0, 0x1.66de7p-1, -0x1.c8a6ap0, 0x1.b08c2ep-1, -0x1.a2852cp-1, 0x1.787b62p0, 0x1.55db7ap0, 0x1.4d7d0ep0, -0x1.b421bp0, 0x1.31d1aep-1, -0x1.391d3p0, 0x1.069544p0, 0x1.77734ap-4, 0x1.0487ap-2, 0x1.62e468p0, -0x1.59a9f6p0, -0x1.df8ba6p0, 0x1.0d89d6p0, -0x1.6e346ap-1, 0x1.ac7ap-1, -0x1.56bb4p-1, 0x1.636892p-1, 0x1.e25266p0, 0x1.91174p-1, -0x1.52a2c2p-1, -0x1.10af1cp0, -0x1.e4e41ap-1, 0x1.4487eep0, -0x1.bebb54p-1, -0x1.04ddd8p0, 0x1.22d80ep-1, -0x1.04a886p0, 0x1.8a4bc6p0, 0x1.87aea4p0, 0x1.4c981ap0, 0x1.c5f35cp-1, -0x1.92ba86p-2, 0x1.b53f6cp-2, 0x1.311bc8p0, -0x1.d0ba3p0, 0x1.0168e4p0, -0x1.041306p0, 0x1.a00de4p0, -0x1.05f9d6p0, 0x1.590552p0, 0x1.01ad38p-1, 0x1.fcec6ap-2, -0x1.e3e88ep0, -0x1.4a4decp-4, 0x1.85cedcp0, 0x1.40f6cap-1, 0x1.e074b4p-2, -0x1.49423cp0, 0x1.32a568p0, -0x1.c98092p-1, -0x1.e56bd8p-4, -0x1.fa5ca8p-1, 0x1.2b9f18p0, 0x1.78d99ap0, -0x1.c7f02p0, 0x1.123334p0, 0x1.28b1e8p-3, 0x1.3af668p0, -0x1.eb1598p-1, -0x1.b0c29ep0, 0x1.2d5fcp-1, 0x1.69752ap0, 0x1.a3c17cp-1, -0x1.2f960cp0, 0x1.f65894p-2, 0x1.2b4f3ep-1, 0x1.58aa2ep0, -0x1.d05f9ep-1, -0x1.df7afap0, 0x1.6ee0aap-1, 0x1.8d4d1cp0, 0x1.640746p-3, -0x1.a737cap-1, 0x1.1a8768p-1, 0x1.ebd772p0, -0x1.8cd0ep-5, -0x1.6dfa3ap-2, 0x1.0386a8p0, -0x1.b26ab8p0, -0x1.1e926p0, 0x1.99e9a4p-1, 0x1.1cb2fp0, -0x1.187332p-3, 0x1.b36496p0, 0x1.0c7ed4p-4, 0x1.9e8dd6p0, -0x1.a076cap-1, 0x1.c6d04ep0, 0x1.774f24p0, -0x1.3afb4ep-1, -0x1.52a9e2p-2, -0x1.0ec27cp0, -0x1.a78a8p0, -0x1.fca0c6p-1, 0x1.e8d782p0, -0x1.193d4p-1, 0x1.f83dcep0, -0x1.59408p-1, 0x1.86394p-1, -0x1.c37364p0, 0x1.e3ec1p0, 0x1.e8023p-2, 0x1.5c9962p-3, 0x1.4ae812p-3, -0x1.a79de6p-1, 0x1.636292p-2, -0x1.142094p0, 0x1.ab5506p-4, 0x1.5d3ae2p-4, -0x1.9de1c6p-1, -0x1.9dc056p0, -0x1.8a90dap-1, 0x1.e871acp-2, 0x1.cb02f4p0, -0x1.7d8be2p0, 0x1.b94d16p-1, 0x1.31f124p-1, 0x1.fe5272p0, -0x1.fc6e48p-2, -0x1.7771c4p-1, -0x1.9ba46ep0, 0x1.4f302ep0, 0x1.89e3c8p0, -0x1.797628p0, -0x1.b7c3dep0, 0x1.fbd018p-3, -0x1.9a7676p0, -0x1.c5842ap-1, 0x1.8435cap-2, 0x1.c78718p0, 0x1.a12eb8p0, 0x1.bf5638p-2, -0x1.473bc6p-2, 0x1.62e8b4p-4, -0x1.39b716p0, 0x1.14bcf8p0, 0x1.573df4p0, -0x1.8d3274p-1, 0x1.075a4ep0, 0x1.0eb472p-1, 0x1.35942ep-1, -0x1.c94f6p0, -0x1.2d9214p-1, 0x1.3085bp-1, -0x1.48bbacp-1, 0x1.a881bcp0, 0x1.bc8a24p0, 0x1.b3b158p0, 0x1.ddb444p-1, -0x1.122b14p-1, -0x1.00b994p0, -0x1.8ec7f2p-4, 0x1.0ebe82p-3, -0x1.d9e52ap0, 0x1.b092d2p-1, -0x1.d7f352p0, -0x1.521d76p-1, 0x1.883362p0, -0x1.c4c776p0, -0x1.a3997ep0, -0x1.ed0918p0, 0x1.7bc038p-2, -0x1.de8244p-7, 0x1.cf84aap-3, 0x1.e96026p-2, -0x1.7617f6p-1, -0x1.c3bcb8p0, 0x1.ddccf4p0, 0x1.10265ep-1, 0x1.4c61d6p-1, 0x1.3a5042p-2, 0x1.0f6ee8p0, -0x1.8e80f6p0, 0x1.dc7ef8p0, 0x1.0bfd38p0, 0x1.e8d672p0, -0x1.4e23cap-1, -0x1.c5159cp0, -0x1.22f7e4p0, 0x1.bb215cp0, -0x1.7d46a4p-2, -0x1.2aee1cp0, 0x1.e19d98p-3, 0x1.4c5a94p0, 0x1.9bff8cp0, -0x1.37a972p0, -0x1.6323fcp-5, -0x1.f12b0ap0, -0x1.61a5d6p-2, 0x1.82e486p0, -0x1.7a9aap-1, -0x1.f667e6p0, 0x1.36a3p0, -0x1.ebe9cap-1, -0x1.0de066p0, 0x1.7e7ad2p0, 0x1.885ce6p-4, 0x1.fc6d12p-3, 0x1.0e2b08p-1, -0x1.ee2dp0, 0x1.5cc8fep0, 0x1.a235aap0, 0x1.67c2bep0, 0x1.a68268p0, -0x1.611a3ep-5, 0x1.bfb04cp0, -0x1.4473a2p-3, -0x1.141654p0, 0x1.0e706cp0, 0x1.cf2c8ap0, -0x1.f9caf8p-1, 0x1.ccb1a2p-5, -0x1.0156ccp0, 0x1.286df6p-1, 0x1.15bb02p-2, 0x1.fedc6cp0, 0x1.008bp-3, -0x1.5f48b8p-1, 0x1.72ebdcp-1, -0x1.aa10acp-2, -0x1.ea7292p0, 0x1.a54b04p0, 0x1.6e98f6p-2, 0x1.7cdd7ep-1, -0x1.0a6a36p-2, 0x1.8d26cap-1, -0x1.2d3fc2p0, -0x1.0ee9d2p0, 0x1.f6289cp-2, 0x1.f3c29cp0, 0x1.22e55ap-2, 0x1.8f90f8p0, 0x1.78ab36p-1, -0x1.933932p-1, 0x1.62ae98p0, 0x1.fcdc1cp0, -0x1.908938p-5, -0x1.b1af68p0, -0x1.e011ep0, -0x1.f3490ep-2, 0x1.75f69p0, 0x1.5f0b3cp0, 0x1.05ba96p0, 0x1.fef78cp0, -0x1.35f64cp0, -0x1.f2a774p-1, 0x1.30be72p0, 0x1.b957e2p0, -0x1.dde776p0, -0x1.9e436cp0, 0x1.a2d2c8p0, 0x1.38cf66p-5, -0x1.fe38fp0, -0x1.602c7cp-1, 0x1.b596e8p-2, -0x1.27645p0, 0x1.025fcp0, -0x1.e866bp0, 0x1.3ba9cp-1, 0x1.6c1434p0, 0x1.13009cp0, -0x1.a3e1fap0, 0x1.82c5a8p0, -0x1.afe7bcp-1, 0x1.c62f18p-6, 0x1.ce232ap0, 0x1.6e5fcep0, 0x1.98aa9p0, 0x1.bd6b28p-1, 0x1.6418acp-1, 0x1.63bc24p-2, -0x1.fa31f4p0, 0x1.4d64c4p-1, -0x1.8a9402p-2, -0x1.f8d43ep-2, -0x1.f92b66p-1, 0x1.d071b6p-1, 0x1.610a06p0, 0x1.1a161cp0, 0x1.525502p0, -0x1.189f64p0, 0x1.61b336p0, 0x1.78c65p0, -0x1.956bfcp0, 0x1.7f5222p0, 0x1.837ec6p0, -0x1.faf224p-1, -0x1.707e2ap0, 0x1.8fdac2p-1, 0x1.5aa89p-1, 0x1.23c682p-1, -0x1.716afap0, 0x1.09863cp0, 0x1.974accp0, -0x1.7ddfacp0, 0x1.a68786p-3, 0x1.ab097ep-3, 0x1.ef899ap-7, 0x1.fa6106p-3, -0x1.62bf5ap0, 0x1.33f484p-1, -0x1.3f3d9cp0, 0x1.c5e3e6p-1, 0x1.7dfa98p0, 0x1.3f836ap0, 0x1.706d62p0, -0x1.6d3fdp-1, -0x1.bdb44ep0, 0x1.6827e4p-3, -0x1.9406f4p-2, 0x1.2150fap0, -0x1.7d9a2ap-1, 0x1.1cfbe6p0, -0x1.c93d42p-4, -0x1.172172p-1, 0x1.b31a84p-1, 0x1.8e6c1p-1, 0x1.68d714p-4, 0x1.ac42ep0, 0x1.5450ep0, -0x1.419976p0, -0x1.f9f3cp-1, 0x1.ef43bep-2, -0x1.8f0178p0, 0x1.0c3df8p-3, 0x1.6eb20ap-2, 0x1.390702p0, 0x1.c610a4p-2, -0x1.6687b6p0, 0x1.7c64bcp-1, 0x1.0631a4p-1, 0x1.d051bap-5, -0x1.c4ddaep-1, 0x1.390b6cp-4, 0x1.94d4c4p0, -0x1.5a255ap-2, -0x1.a903aep0, 0x1.dc7524p0, -0x1.64a306p0, -0x1.ca0fc2p0, -0x1.5be15cp0, 0x1.bf949cp-1, 0x1.0879dap0, -0x1.2e9c3ep-1, 0x1.4dc64ap0, -0x1.ef293ap0, 0x1.a4947ep0, 0x1.af5f44p0, 0x1.c6ed3ap0, 0x1.5b3afcp0, -0x1.ec89f4p0, 0x1.ac235cp0, -0x1.b97e4ep-2, 0x1.bb61ccp-5, 0x1.75f6e6p-2, 0x1.20d892p0, -0x1.aaef54p0, -0x1.4c807ep-6, -0x1.573492p-1, 0x1.c32602p-3, 0x1.73d86cp0, 0x1.f54f28p-1, -0x1.6f9b2ap-2, 0x1.d4febap-2, 0x1.4640c2p0, 0x1.f1bf28p-1, -0x1.9c28cep-1, 0x1.b886e8p-2, 0x1.c35e8ap-1, 0x1.0768a4p0, -0x1.49e032p0, 0x1.84a09ap-2, -0x1.4e779ep-2, 0x1.051968p-1, -0x1.49b99p0, -0x1.beda08p-1, -0x1.fdbbc4p-1, -0x1.3043e6p-1, 0x1.c85024p-2, -0x1.cab6a8p-2, -0x1.74fdep-3, -0x1.04062cp0, -0x1.70f2bap-2, -0x1.03682ap-1, 0x1.809eeap-1, 0x1.123342p-1, 0x1.e94142p-2, -0x1.881172p0, 0x1.0b65cep0, -0x1.565734p0, -0x1.c03dep-2, 0x1.6b1a8cp-1, 0x1.8298e8p0, 0x1.29ffcap0, -0x1.4c63c2p-1, -0x1.a6d9dcp0, -0x1.131426p0, 0x1.8ab28p0, 0x1.0c334ep-1, -0x1.0c8e22p0, 0x1.ed1a8cp-2, 0x1.ab45bcp0, -0x1.286b8p-1, 0x1.51e776p0, 0x1.7ea8eap0, 0x1.72d81p0, -0x1.2d4a1ap-1, 0x1.10c764p0, 0x1.9aca2ap-1, 0x1.eb2e5ap0, 0x1.c3183ep0, -0x1.493266p-1, -0x1.93d464p0, -0x1.49fc4ep0, -0x1.1c8f6ep0, 0x1.bbfaa4p-2, -0x1.524e4cp0, 0x1.95ec82p0, 0x1.91dd5ep-1, 0x1.6607d4p0, -0x1.0a552p0, -0x1.715198p0, 0x1.6b4646p-4, 0x1.9ec3e8p-1, -0x1.d25e78p0, -0x1.acb402p-4, -0x1.ac5da6p-3, -0x1.202136p0, -0x1.07db54p-2, -0x1.42d556p0, -0x1.e646acp0, 0x1.751ac2p-2, -0x1.a8ec1p-1, -0x1.d12c52p0, 0x1.c3564p0, 0x1.9d8324p0, -0x1.57ca12p0, 0x1.e34428p-4, -0x1.27c77cp-2, 0x1.75d87p-1, 0x1.834f38p0, 0x1.fa1154p0, 0x1.586736p-3, -0x1.bfedap0, 0x1.32ba88p-1, -0x1.5f8afep0, -0x1.5b8db2p-1, -0x1.57c2d2p0, -0x1.3ebdbep-2, 0x1.d27d42p0, -0x1.76cabp-3, -0x1.862762p-2, 0x1.f7601ep-1, -0x1.548efep-2, -0x1.62a3a4p0, -0x1.3b271ap0, 0x1.204e6p0, 0x1.e147bcp0, 0x1.3ecee8p0, 0x1.59f9c6p-1, 0x1.00e30cp0, 0x1.cb8abcp-1, 0x1.0607c8p0, 0x1.4d477ap-1, 0x1.8ebd92p0, -0x1.d3fbeap-1, -0x1.72ecf4p0, -0x1.c4fa36p0, 0x1.971fc8p-1, -0x1.20b972p-3, -0x1.824ad2p-3, -0x1.00de4ep0, -0x1.7e2082p0, 0x1.28555p-2, -0x1.02cebap-1, -0x1.4c054ap-1, -0x1.80d1aap-4, -0x1.027746p0, -0x1.cdd99ap0, -0x1.cfcd42p0, -0x1.696c88p-2, -0x1.b610e6p-1, 0x1.bb51f2p-1, -0x1.58e854p-1, -0x1.2922eap-1, -0x1.a9919p0, 0x1.753e9cp0, 0x1.bca2c4p-1, 0x1.c64382p0, -0x1.7aecaap-3, 0x1.750f8p0, -0x1.5a660cp0, -0x1.464176p0, 0x1.dd80bap0, -0x1.62b57ep0, -0x1.6e3eb8p0, -0x1.d827ecp0, -0x1.30340cp0, 0x1.34e1bcp0, 0x1.ea7c6ep0, -0x1.a6e3e4p0, 0x1.006bcp0, -0x1.613108p0, -0x1.51bd96p-1, -0x1.26858ep0, 0x1.47486ap0, 0x1.47d18cp0, 0x1.0caaaap-2, -0x1.ca7de4p-2, 0x1.392d9ep-2, -0x1.f1b07ep0, -0x1.1f7d9cp-2, 0x1.b56fd6p-4, -0x1.23f4ap-1, 0x1.c3ee1p-2, -0x1.e04036p-1, 0x1.db9fc6p-4, -0x1.f6edep-1, -0x1.4db708p0, -0x1.0ab736p-4, -0x1.dbd0bp0, 0x1.cdff94p-2, 0x1.206cap0, -0x1.0c833cp-3, 0x1.c3ae16p0, 0x1.42595p-5, -0x1.7e2062p-2, 0x1.a5d7dap0, 0x1.972aeep-5, -0x1.9cb0c8p-6, -0x1.c4f97ap0, 0x1.8f348cp0, -0x1.518292p-1, 0x1.d68db6p0, 0x1.946658p0, -0x1.5a16fep-5, 0x1.6a6a8ep0, -0x1.9010d4p0, -0x1.3aeb4cp-5, 0x1.02fdaap-4, 0x1.6f36bep-1, 0x1.d1e0bap0, 0x1.f68738p0, 0x1.4ffc78p0, -0x1.e0c1eep0, -0x1.745afep0, -0x1.fe323ep0, 0x1.c326dep0, 0x1.109476p0, 0x1.177f2p0, -0x1.d593b8p-2, 0x1.f54864p-1, 0x1.701dacp-1, -0x1.b7d23cp-1, 0x1.a81a74p0, 0x1.4bc2b2p0, -0x1.454b3ap0, 0x1.0b3494p0, -0x1.b2c868p0, -0x1.3fa64p0, 0x1.818c76p-1, 0x1.d376bcp0, -0x1.b19408p0, -0x1.7f5e6ep-1, 0x1.c5cf98p-1, -0x1.dc4794p0, 0x1.393936p-1, -0x1.b17ebep-1, -0x1.74ef36p-2, 0x1.b9d46p-2, 0x1.97517ap-2, -0x1.49ab7cp0, -0x1.534db6p-1, 0x1.e04a92p0, 0x1.888fe4p0, -0x1.e2b896p0, -0x1.bd2fc4p-1, -0x1.071098p-3, -0x1.10db42p-1, -0x1.f89f38p0, 0x1.64bb88p-1, 0x1.1bf3dp-1, -0x1.6bab14p0, -0x1.75ded2p-1, -0x1.62e0aap-1, 0x1.e50504p-1, 0x1.eb2d32p0, 0x1.8f9a7ap-1, 0x1.67716p0, 0x1.c7a4f2p-1, 0x1.18f828p0, -0x1.c91e24p-1, 0x1.d3f06ep-1, -0x1.3a8a8cp0, -0x1.aa8094p0, 0x1.6adaaap-1, 0x1.740a2p0, 0x1.f00d4ap0, 0x1.29fde6p0, 0x1.33a236p0, 0x1.720262p0, 0x1.a55d38p0, 0x1.687c98p-1, -0x1.9cddeap-4, -0x1.5770e4p-1, -0x1.3fdc0ep-1, 0x1.900ee6p-7, -0x1.e08dcp-1, 0x1.73e54ep-1, 0x1.e3d15ap0, -0x1.054a26p-1, 0x1.b09ee4p-8, 0x1.f1b124p0, 0x1.ecee78p0, -0x1.8dd8e4p0, 0x1.18cec6p0, -0x1.bd7516p-2, -0x1.4b7ca6p0, 0x1.27cfdp-1, 0x1.3c3778p0, -0x1.f6d2c8p0, -0x1.5c844p0, -0x1.c38edp0, -0x1.53affap-1, -0x1.ab9f44p-4, -0x1.51e91cp-1, -0x1.e6f184p-1, -0x1.4c1d7ap-3, -0x1.0df72ep0, -0x1.b3ed82p0, -0x1.3c0adcp-4, 0x1.95f5f2p-3, 0x1.943816p0, 0x1.82fdf2p0, 0x1.268a2ap-1, -0x1.2ce898p-1, -0x1.7be0dcp-2, 0x1.a5a182p-4, 0x1.08d6d8p0, -0x1.6efe4cp-1, -0x1.2a4742p-1, 0x1.4fc784p0, -0x1.3220fcp-1, -0x1.b5443p-2, -0x1.6721ecp0, 0x1.9da54ep-4, -0x1.612152p0, 0x1.ee70a8p0, 0x1.33a8c8p0, 0x1.f001ccp0, -0x1.f2e824p0, -0x1.a8faa2p0, -0x1.83e042p0, -0x1.20197p-1, -0x1.552558p0, 0x1.328d04p0, 0x1.584ecp0, -0x1.b1cfap0, 0x1.0cd914p-1, -0x1.0a852p0, 0x1.e31118p0, 0x1.789b04p-1, -0x1.f2d832p0, -0x1.6ccd94p0, -0x1.0a1f8ap0, -0x1.f89464p0, -0x1.b716c6p0, 0x1.c23ddcp-3, 0x1.d933ccp0, 0x1.977186p0, -0x1.61438ap-1, -0x1.52fd7p0, 0x1.a8f306p0, 0x1.426ebcp0, 0x1.2cb362p-1, 0x1.e6d6acp0, 0x1.5e5afcp-1, -0x1.e8eafep-6, -0x1.23bc2p0, 0x1.11f39ap-2, 0x1.335e96p-1, -0x1.f53a86p0, -0x1.3c11d4p-3, 0x1.38a6d2p0, 0x1.da8698p0, 0x1.be1f9cp-2, 0x1.e6b7dcp-2, 0x1.496df2p-1, 0x1.7cfc4p-4, 0x1.9f0c62p-1, 0x1.4e49b4p0, 0x1.776f88p0, 0x1.19463ap-2, -0x1.57afeap-2, 0x1.17ff72p0, -0x1.c98ec6p-2, 0x1.90a088p0, -0x1.28b3ccp0, -0x1.cd195cp0, 0x1.f79346p-1, 0x1.1a4fd2p-2, -0x1.38caa6p-1, -0x1.9443cep-1, 0x1.20c2e4p-3, -0x1.a29ebp-2, 0x1.d03edcp0, 0x1.4398dp-1, 0x1.fe49bcp-1, -0x1.96a67p-1, 0x1.d1bb9ap-1, 0x1.03f5aep-2, -0x1.99ab74p-2, -0x1.c71842p-1, -0x1.20cbc4p0, -0x1.384c7ep0, 0x1.6f72ecp-2, 0x1.48a06ap0, -0x1.ad7c18p-1, -0x1.4e7f2ep0, 0x1.e2e3eap-4, -0x1.f2e00ep0, 0x1.e7c11p-3, -0x1.572372p-1, 0x1.0d8d2p-3, 0x1.6df01ep-2, 0x1.ffea6p0, -0x1.db943ep0, -0x1.915e52p-2, 0x1.388faap0, 0x1.8593d2p0, -0x1.c356c8p-2, 0x1.e8f13ap-2, 0x1.07729p0, 0x1.fce124p-2, 0x1.b67b12p0, 0x1.eb1216p0, -0x1.152bc2p-1, -0x1.04b972p0, -0x1.f7f48ap0, -0x1.c42fdap0, -0x1.5b8fd8p0, -0x1.dc29e4p-1, 0x1.444518p-3, 0x1.118504p0, 0x1.4725c8p-3, 0x1.6894c8p0, -0x1.e86c98p-2, -0x1.d017e2p-1, 0x1.7c7054p0, 0x1.76c0ecp0, 0x1.ed3e78p0, 0x1.34e66cp0, 0x1.a83938p0, 0x1.a4f33ap-1, 0x1.ef2f56p-2, -0x1.33a89ap-1, -0x1.08df56p0, -0x1.478f5ep0, -0x1.1e86f6p0, 0x1.8a1d18p0, 0x1.c21916p0, -0x1.d7d6e4p0, 0x1.7b5d26p0, -0x1.d7f23p0, 0x1.918d94p0, -0x1.a8abccp0, -0x1.fcb7cap-4, 0x1.391c76p-3, -0x1.29c6eep0, -0x1.f1cf8ap0, -0x1.879e16p0, 0x1.1af0eap-1, 0x1.820214p0, 0x1.d3fc1cp-3, -0x1.e7243p0, 0x1.eac7a4p-1, 0x1.f07f26p-2, 0x1.8ea964p-1, -0x1.d91f78p-8, 0x1.93b3aep-1, -0x1.9e6128p-1, 0x1.3d5538p-4, 0x1.c2cd46p-2, 0x1.a8ffdp-2, -0x1.8f0e9cp0, -0x1.c6feb8p0, 0x1.7f7a2p-1, 0x1.0da2fap-5, -0x1.5c45bcp0, 0x1.e2629p-2, -0x1.56b228p0, 0x1.aaac5p0, 0x1.16be9p0, 0x1.26270ep-1, -0x1.083952p-1, -0x1.ded65p-1, 0x1.483744p-1, -0x1.11397ep0, 0x1.ff94a6p0, 0x1.772464p0, -0x1.28bcp-2, -0x1.5eeb88p0, 0x1.ac7fb6p0, -0x1.02ca12p0, -0x1.df702cp0, -0x1.2196cap-1, -0x1.e71bdp0, -0x1.b6a26cp-1, -0x1.6aec22p-1, 0x1.b92dep-4, -0x1.b13ef4p-1, -0x1.b41af4p0, 0x1.bdf1ap0, 0x1.4d7f44p-2, 0x1.53c554p0, -0x1.f1dd8ep-4, 0x1.b035e2p-1, -0x1.8880e2p0, 0x1.8cedbp0, -0x1.0c042cp-1, 0x1.05ec96p0, 0x1.428b22p-1, 0x1.2c017ep-1, -0x1.42f514p0, -0x1.f5ee02p-1, 0x1.59c22cp-1, -0x1.41bdf2p-1, 0x1.efafaap-1, -0x1.8ce32cp0, -0x1.245534p0, 0x1.82010ap-1, 0x1.35f154p-3, 0x1.5aa692p-1, -0x1.bb7ddp0, 0x1.26fcb6p0, -0x1.9b70dp0, -0x1.cc17fep-2, -0x1.39f95cp-4, -0x1.e236f2p0, -0x1.9ce152p-2, 0x1.9b3aa4p0, 0x1.0a24a8p0, 0x1.697d0cp0, -0x1.b3905p-2, 0x1.c69678p-1, 0x1.08d25ep-1, -0x1.323348p-1, 0x1.e111d8p0, 0x1.a9aac6p0, -0x1.7189c4p0, 0x1.9421c2p-2, 0x1.60c436p0, -0x1.68206ep0, 0x1.34b66cp-2, 0x1.8df34p-2, 0x1.e7cc0cp-2, -0x1.a36cf8p-1, -0x1.2c367ep0, 0x1.117e06p-4, -0x1.1b63ccp0, -0x1.e8d642p-2, -0x1.99f5aep-3, -0x1.4e3816p-2, -0x1.4c85e6p-3, 0x1.a92e88p0, 0x1.f88916p0, 0x1.11d7acp0, 0x1.718c9p0, 0x1.5377dcp0, 0x1.2968dep0, -0x1.96afc2p-2, -0x1.7865bep-1, 0x1.04b0aap-1, 0x1.3c7d84p-1, -0x1.fb4314p0, -0x1.50c67cp0, -0x1.a0d25ep-2, 0x1.0c2cf8p-2, 0x1.43451ap0, 0x1.3dac58p-3, 0x1.a4094ap-1, -0x1.515ab6p-1, -0x1.b89cfep-6, -0x1.cfcdb4p-4, 0x1.d2090ep0, 0x1.2dd2d2p0, 0x1.561e24p0, 0x1.d011fap-3, 0x1.497962p0, -0x1.107e48p-2, 0x1.212e16p0, 0x1.34adc2p0, 0x1.a3416cp-2, -0x1.1bac08p-1, -0x1.151442p0, 0x1.77b96p0, 0x1.73f02cp0, 0x1.408178p0, 0x1.9776d8p0, -0x1.b6302ep-2, 0x1.af066p-5, -0x1.7ba314p0, -0x1.e2dbeap-1, 0x1.50fab6p-1, -0x1.612058p-4, -0x1.2380dp0, 0x1.6203fp0, -0x1.993e3cp-4, 0x1.10b856p0, -0x1.6d2196p0, 0x1.99cf16p-2, 0x1.0297b2p-1, -0x1.90398ap-1, 0x1.64c32ep0, 0x1.5f85f8p0, 0x1.197bdap-3, 0x1.126accp0, 0x1.fd6282p0, 0x1.67bbccp-1, -0x1.5b73bap-1, 0x1.dcce46p0, 0x1.de3cf2p-1, 0x1.fef33p-2, -0x1.546c6p0, -0x1.2302a2p-1, 0x1.f4a66cp0, 0x1.8c36d2p-1, 0x1.7cf45cp0, -0x1.3b275p0, 0x1.8b8fcap0, 0x1.4564dap0, 0x1.9dd1f8p-1, -0x1.2d9edp-1, 0x1.ecc436p-1, 0x1.dd3e22p-1, -0x1.0952d6p0, 0x1.b9abbap-1, 0x1.e789a8p0, -0x1.dcc4f2p0, 0x1.e4eaf8p0, -0x1.b76bap0, -0x1.b0add2p-1, -0x1.7c7d3ep-3, 0x1.3929d4p0, -0x1.33f0e6p0, 0x1.514c3ap0, 0x1.9b19fap0, -0x1.08174ap-1, -0x1.c3be32p-1, -0x1.2d827cp0, 0x1.3537ccp-2, -0x1.918e5cp0, -0x1.e19286p0, 0x1.81c4d8p-1, 0x1.fd5de8p-2, 0x1.e18dbap-3, -0x1.144672p-2, -0x1.0cc368p-1, -0x1.820f08p-3, 0x1.2ba58ap0, -0x1.21f45p0, -0x1.29066p0, -0x1.6e004ap-1, 0x1.a8cac6p-1, 0x1.2e24f4p0, 0x1.c5c2aap-2, 0x1.bcc1f4p0, 0x1.8feda6p-2, 0x1.294592p-2, 0x1.a7409p0, 0x1.796cfep-3, -0x1.3688bap0, -0x1.a4ba9ep-1, -0x1.845ddap-3, -0x1.ba671ap0, -0x1.78562ap-1, -0x1.6d86ep-1, -0x1.48c31ep0, 0x1.af2a04p-1, -0x1.fdb238p0, -0x1.65c9cep0, -0x1.8317e2p0, -0x1.01a00ap-1, 0x1.44eb4p-3, -0x1.b4fb28p-1, 0x1.634b32p-1, -0x1.d4299ap0, 0x1.0f1436p-1, 0x1.1f6432p-1, 0x1.361b8ap-1, -0x1.71b77p0, -0x1.15da26p-1, -0x1.b855fep-3, -0x1.489d84p-1, -0x1.0debc6p-1, 0x1.45a062p-3, -0x1.4648aep0, 0x1.6d10cp0, 0x1.6231bep-1, -0x1.3a73a6p0, -0x1.91447cp-4, -0x1.fa820cp0, 0x1.a18816p-1, -0x1.bfe5d4p0, 0x1.39fe84p0, 0x1.ae45a6p-1, -0x1.26144ep0, -0x1.39cd2ap-5, 0x1.bf4efcp-1, -0x1.dde09ap-3, -0x1.054a64p0, -0x1.d228a4p0, -0x1.30698cp0, -0x1.f3905ap-2, -0x1.add1d4p-2, 0x1.7959e2p0, -0x1.1423f2p-3, -0x1.d76942p-7, -0x1.1b4dcp0, -0x1.c52c78p-1, 0x1.69e91cp-2, 0x1.23a574p-1, 0x1.eb3c64p-1, -0x1.d26c2ep0, 0x1.f8267cp0, 0x1.b2bd72p0, 0x1.2cd19ap-1, 0x1.0f2adp-1, 0x1.7fbeeep0, 0x1.664c8p0, 0x1.641a8ep0, 0x1.5db66ep0, -0x1.926374p-1, 0x1.df269ap0, -0x1.755a44p-4, 0x1.d92e5ap-4, 0x1.ee72cep-1, 0x1.18a8eep-1, -0x1.0ce26ap-1, -0x1.457d68p-1, 0x1.7a8ab2p-2, -0x1.0e4142p-1, -0x1.1aa148p-4, -0x1.a1a6eep-1, -0x1.89fd78p0, -0x1.3b4748p-2, 0x1.4a6484p-1, -0x1.fbad9cp0, 0x1.091152p-5, 0x1.19ff44p-2, 0x1.ae61aep0, 0x1.29aee4p-1, 0x1.b6b29ep0, -0x1.3cedfap0, 0x1.0870fep-1, -0x1.148a78p-1, -0x1.1b9fecp0, -0x1.d068c4p-1, -0x1.9b8abcp0, 0x1.545142p0, -0x1.c69fb4p0, -0x1.f1991cp0, 0x1.11a1dp0, 0x1.ee5a5cp-3, -0x1.94e6dp0, 0x1.66396cp-1, -0x1.4d054p-1, -0x1.bd8ad8p0, 0x1.6d5d3ap-3, 0x1.ca0a14p0, 0x1.004758p0, 0x1.2d9d22p0, -0x1.4c0a66p0, 0x1.b0e064p-1, 0x1.666f38p0, 0x1.eff7b4p-1, -0x1.1d0efp0, 0x1.589aa4p-1, -0x1.0ed54ap0, 0x1.358fdep-1, -0x1.28dee4p-1, -0x1.46b62ep0, -0x1.b40b06p0, -0x1.60fed2p0, 0x1.0a84f4p-4, -0x1.914ef8p-1, 0x1.9d9428p0, -0x1.5e8beep0, 0x1.5d376p-4, -0x1.869696p-2, 0x1.4e27aap-1, 0x1.2eb8aap-2, -0x1.af38ep-2, -0x1.2fb012p-3, -0x1.4eed2cp-1, -0x1.efc46cp-2, 0x1.923dd2p0, 0x1.a8dfc8p-1, 0x1.f28eb6p-2, -0x1.6de188p0, -0x1.c6ca8p0, -0x1.57bbc6p-1, 0x1.9a49b4p0, 0x1.08a2eep0, -0x1.9695fp0, -0x1.2c692ep-2, -0x1.457206p0, -0x1.743944p-2, -0x1.78118ep0, 0x1.ca6eccp0, -0x1.fa8d58p-1, -0x1.ca334p-1, 0x1.066702p0, 0x1.4724aep0, -0x1.edfa3cp0, 0x1.ad3798p-1, -0x1.9a7606p-2, 0x1.e2bde4p-1, 0x1.8923d2p0, 0x1.c8af36p0, 0x1.adf6a6p-2, 0x1.4e0c0ap0, -0x1.047062p-1, 0x1.872876p0, -0x1.dc13c6p0, -0x1.472af8p-3, 0x1.948c8ap-1, -0x1.5f35f2p0, 0x1.60a062p0, -0x1.1933a6p-1, 0x1.83434p-1, -0x1.60276p0, 0x1.7c8708p0, 0x1.6d5cbep-1, 0x1.1c08d6p-4, -0x1.8d0e42p-2, 0x1.58c182p0, 0x1.b5507cp0, 0x1.682ecp-5, 0x1.9ea5p-3, -0x1.3e20a6p-3, 0x1.997e3p-5, -0x1.c00d64p0, 0x1.574956p0, -0x1.33df64p0, -0x1.1b79e6p-1, -0x1.302d08p-2, -0x1.b78b3ap-2, 0x1.827e8ap0, 0x1.53b33cp0, -0x1.d708fp0, -0x1.d4892p0, -0x1.18183ap0, -0x1.f78ec2p-2, -0x1.05d13p0, 0x1.aee2cep-7, -0x1.4053aap0, -0x1.573e16p0, 0x1.0c1c98p-1, 0x1.b1ef1cp-1, -0x1.34df9ep0, 0x1.a84048p-1, -0x1.81f49cp-1, 0x1.e5b494p-1, -0x1.4f22acp0, 0x1.7a7322p0, -0x1.85d788p-7, 0x1.c110dap-2, -0x1.621284p-5, 0x1.7ba786p0, -0x1.7cc2dp-1, -0x1.6145d2p0, 0x1.f064c2p-7, -0x1.dcc106p0, -0x1.507dep-1, 0x1.f2b9c6p0, -0x1.eb97dap0, 0x1.101a72p-1, -0x1.0c35bp-1, 0x1.d77fcp-5, 0x1.0dcc0ep-1, 0x1.264d98p0, -0x1.e7f89cp0, -0x1.1f5c0cp0, -0x1.246a14p0, -0x1.8b358p-2, 0x1.18ecf6p0, -0x1.3f2ed8p0, -0x1.dc06d6p-1, 0x1.d01b4ap0, -0x1.1f41acp-5, 0x1.52871ep-1, -0x1.fc78cep0, 0x1.8231f8p0, -0x1.ea1cb2p-1, -0x1.2aba04p0, 0x1.370976p-2, -0x1.838936p0, 0x1.eb3ae4p-1, 0x1.afb666p0, -0x1.a30a5cp-2, 0x1.0e81ep0, -0x1.bfad34p0, 0x1.b3ba7p-1, -0x1.11695ap-5, -0x1.88663cp0, 0x1.86c22p0, 0x1.a7545ep0, -0x1.a67ep-2, 0x1.d72a28p0, 0x1.59a66ep0, 0x1.9d4f96p0, 0x1.941ac8p-1, -0x1.e8d5aap0, -0x1.4e0232p-3, -0x1.7510d2p-2, 0x1.b6b8d8p0, -0x1.f1b7bp0, -0x1.ebac82p-1, 0x1.14b236p-1, -0x1.724356p-1, -0x1.04b388p-1, 0x1.a49b02p-1, -0x1.31802ep0, -0x1.4238cp0, -0x1.58d4cp-2, -0x1.565444p0, -0x1.6e5adep0, -0x1.cd5754p0, -0x1.f70934p0, 0x1.4fcf5cp-1, -0x1.2fb402p-1, 0x1.5444bap0, -0x1.9df142p-1, 0x1.b83032p-3, 0x1.11ae5cp-1, -0x1.925fd8p-1, -0x1.0860a8p0, -0x1.e96a46p0, -0x1.842802p-2, -0x1.c99c5cp-3, 0x1.c56bfp0, 0x1.c1b094p-2, -0x1.d2ec4cp0, 0x1.a668e8p-2, 0x1.730b8ap0, 0x1.03a21p-1, -0x1.6f4cc2p0, -0x1.1d1352p-3, 0x1.cc6c92p0, 0x1.d1994p0, 0x1.1e0d2cp0, 0x1.699eeap0, -0x1.2d5a34p0, -0x1.3a7ddap0, 0x1.9f84e2p0, -0x1.dc14c8p-1, -0x1.46228cp0, -0x1.10bed8p0, 0x1.15dc9ep-2, 0x1.5e2e44p0, 0x1.4bfd52p-2, 0x1.67a16ap-1, 0x1.81f9ccp-3, 0x1.a2e71ap-2, 0x1.a6a5ccp-1, 0x1.eac9c2p-3, -0x1.ebad46p0, 0x1.5da636p0, 0x1.c2eb24p-2, -0x1.709658p-1, -0x1.f22204p0, 0x1.c9b394p0, -0x1.d449b2p0, 0x1.8ab32cp-2, -0x1.d4dd2cp0, -0x1.bcbc6p-2, 0x1.5fa096p-2, 0x1.dd4522p-5, 0x1.248966p0, -0x1.a965a4p0, -0x1.33546cp-2, 0x1.654df8p0, 0x1.3ba72cp-1, -0x1.75ef8p0, -0x1.c34592p-2, -0x1.db1a9ep0, -0x1.0ceacap0, -0x1.9b7786p0, -0x1.eddf4p-1, -0x1.a82378p-1, -0x1.d5101ep0, 0x1.e8f59cp-1, -0x1.14bbccp-3, -0x1.8e1aap-1, -0x1.eeda72p0, -0x1.8a073cp-1, 0x1.59a024p-1, 0x1.39ca46p-4, 0x1.bc8444p0, 0x1.0baa48p0, -0x1.9753fep0, -0x1.e6638cp0, -0x1.dd27e8p-5, -0x1.c9ec2ap-2, -0x1.8a1cbep-1, 0x1.3482a8p-1, 0x1.0a5f7ep-1, -0x1.28e886p0, -0x1.cd2398p-4, 0x1.e68468p0, -0x1.bbeec4p0, -0x1.6c91bap0, 0x1.e9fa5ep-1, -0x1.7ce558p0, -0x1.780a8cp-1, 0x1.8857ep-1, 0x1.730a7ap0, 0x1.6b0e8ep-1, -0x1.0f05cep-2, -0x1.1a8a44p-1, 0x1.61dcc8p-1, 0x1.07450cp0, -0x1.8e6eep-1, 0x1.86516p0, 0x1.f43664p0, 0x1.363fe8p-2, -0x1.58b5c8p0, 0x1.684256p-8, -0x1.180d2ep-1, -0x1.9cf1bcp0, -0x1.57d528p-5, 0x1.c71c6ap-1, 0x1.11e20ep0, 0x1.5dc41p0, 0x1.9fe45ep0, -0x1.438eecp0, 0x1.01553ap0, -0x1.300dd4p0, -0x1.3eae2ap0, 0x1.6ddfbep-1, 0x1.cd6e68p0, -0x1.29c772p0, -0x1.6f1054p-1, 0x1.4d1b84p0, 0x1.58095cp0, 0x1.58cddp-2, 0x1.8033p0, -0x1.f92ebap0, 0x1.aadb84p0, 0x1.5fd5acp-2, 0x1.dfb418p0, -0x1.6034f8p0, 0x1.064b12p-1, -0x1.68e8fep0, 0x1.0ff986p0, 0x1.9400f2p0, 0x1.0f5932p-2, -0x1.35f3ccp0, -0x1.13f3ecp0, 0x1.eb5254p-2, -0x1.07bc52p-1, 0x1.744a68p-2, 0x1.973bcep-2, -0x1.4e9364p-2, -0x1.27c4p-1, 0x1.1ef2aap-2, -0x1.2877ep-4, -0x1.b6c932p-4, 0x1.19d05ap-1, 0x1.349366p0, 0x1.c2844cp0, -0x1.ee65cep0, 0x1.07edeep0, 0x1.1cad0ap0, 0x1.216b88p0, -0x1.c26938p0, 0x1.7ba21ep-3, -0x1.bfc09cp0, -0x1.f2989ap-7, 0x1.f68df6p0, -0x1.9e3c7ap-1, -0x1.fddccp0, -0x1.7d4a84p0, -0x1.570962p0, -0x1.a4fc3p0, 0x1.3b56acp-7, -0x1.8b77bcp0, -0x1.499b7p0, 0x1.1fbe56p0, 0x1.58f9eap-1, -0x1.2f855ap-1, 0x1.f1c1dcp-2, -0x1.2a6aa2p0, 0x1.c66622p-1, -0x1.addbdp-3, -0x1.3a9e04p0, -0x1.d4e574p-1, 0x1.3b9e7cp0, 0x1.17b17p-2, -0x1.078038p0, -0x1.a27c66p0, -0x1.d4a892p0, 0x1.f9352p0, -0x1.199592p-4, 0x1.992b36p0, -0x1.1ca27p0, -0x1.055b68p0, -0x1.abce9p-2, 0x1.20b9cep0, 0x1.787cdcp-1, -0x1.38e7p-1, 0x1.63ee0ep-1, -0x1.ae2534p-1, -0x1.59e598p-1, 0x1.0b4cbcp0, -0x1.e089cp0, 0x1.b057a2p-2, 0x1.13dd9ep-3, -0x1.156436p0, -0x1.26a922p0, -0x1.f6b298p-1, -0x1.986a5ep0, -0x1.47013cp0, 0x1.cb20f2p-1, -0x1.b3b7bp-2, -0x1.7c5426p-2, -0x1.f3fc04p0, 0x1.905b4p-1, -0x1.1dd4acp-2, 0x1.ca5e1p-5, -0x1.255254p0, 0x1.0de6b6p0, -0x1.8b7b2cp0, 0x1.c89e6cp0, -0x1.30d884p-2, -0x1.3bf4f8p0, 0x1.d3babcp-1, 0x1.dc1c76p0, 0x1.b5319cp0, 0x1.dc8ae6p-1, -0x1.a25942p-2, -0x1.5da718p-4, 0x1.75bfa8p0, 0x1.74c396p0, 0x1.5ecb2cp0, 0x1.fafcaap0, 0x1.c2e8b6p0, -0x1.59d9fep-1, -0x1.b61e66p-4, -0x1.a6ecd6p0, 0x1.364de2p0, -0x1.7503aap0, -0x1.821914p0, 0x1.a60058p-1, 0x1.1cb68ap-2, 0x1.34bad6p0, 0x1.8d2aaep0, -0x1.33ca7ap-2, -0x1.bb1436p-1, -0x1.fb2fd2p-3, -0x1.1ca2c8p-5, 0x1.c2936p-1, -0x1.59cdaap-2, 0x1.ad98c6p0, 0x1.c6ecfep-1, -0x1.6ec6c8p-2, 0x1.81a3eep-4, -0x1.ecefbp-1, -0x1.263748p-1, 0x1.161c52p0, 0x1.0031fp0, -0x1.d9bf7cp0, -0x1.b98c4ap0, 0x1.dfb388p0, -0x1.0f373p-1, 0x1.ec13bcp0, 0x1.30e76ap0, -0x1.7d8d26p-1, -0x1.e43de8p-1, -0x1.34b13p-4, -0x1.1030c2p-1, -0x1.04b72cp-1, -0x1.281d74p-4, -0x1.40c6fep0, -0x1.9c6faap0, -0x1.4b3ffp0, 0x1.d449d2p-1, -0x1.c3244ap0, -0x1.25540ap-1, 0x1.742166p-4, 0x1.8e6db4p-2, 0x1.9c728ep0, 0x1.14cf04p0, -0x1.f14296p-3, 0x1.d4389cp-2, 0x1.160158p-3, -0x1.0e3a8ap-1, 0x1.acdb4cp0, -0x1.ad9922p0, 0x1.177858p0, 0x1.0197a8p-1, 0x1.def5bp-2, -0x1.1c3144p0, -0x1.abb0bap0, -0x1.66443ap0, -0x1.d31f9p0, -0x1.380392p0, -0x1.4af3d6p0, -0x1.17526p-3, -0x1.836548p0, 0x1.df9ce2p-2, -0x1.d77a0ep0, -0x1.23da74p0, 0x1.4acdf4p0, -0x1.1ffd36p-1, -0x1.b712eap-2, -0x1.b50816p-3, 0x1.b7f302p0, 0x1.20fbe2p0, 0x1.ff0904p0, 0x1.65596ep-1, 0x1.db73acp-1, -0x1.172294p0, -0x1.526a5p-1, -0x1.dff1a2p-3, -0x1.45cc04p-5, 0x1.4fdf5ep0, -0x1.b7353ap-2, -0x1.efc9ap-3, 0x1.809a46p0, 0x1.cdc272p-6, 0x1.3eb684p0, -0x1.4b76cap0, -0x1.9c7a64p-3, -0x1.885a2ap-1, 0x1.0f95d4p-1, 0x1.4ce938p0, -0x1.a56f54p0, 0x1.445eecp-1, -0x1.87d3bap0, -0x1.09627p0, -0x1.7fffd4p-4, 0x1.5a55bap-6, 0x1.6c6612p-2, -0x1.c80822p-2, 0x1.c3afe4p-2, 0x1.1bccccp0, -0x1.f38398p0, 0x1.205cap0, 0x1.530716p0, -0x1.2f03fep-3, 0x1.eb53fp0, -0x1.90bcdap0, 0x1.39a8acp0, -0x1.a6aa92p-1, 0x1.585372p0, 0x1.142c2ep0, -0x1.05047p-3, -0x1.6f6b34p0, 0x1.fd780ep0, -0x1.22d5fp-1, -0x1.5dff58p-1, -0x1.9f89fep0, 0x1.4622a2p-1, 0x1.b10c3cp-4, 0x1.6d9756p-4, -0x1.ab3f36p0, -0x1.846408p-2, 0x1.7f891ap0, 0x1.61bb7p-3, 0x1.34e8fp0, 0x1.49496ep0, 0x1.e87d2cp0, -0x1.400ff8p0, -0x1.afc15ep-1, -0x1.fe0346p0, 0x1.3127cap0, -0x1.582996p-2, 0x1.cf5a26p-3, -0x1.bd5c22p-2, -0x1.82490ep0, -0x1.c8d284p0, 0x1.a6a314p0, 0x1.78d76cp0, -0x1.28f846p0, 0x1.5d9fb4p0, -0x1.2d59e2p-1, 0x1.a5dccap-1, -0x1.fe8984p0, -0x1.50dacp-1, -0x1.ed45a6p0, 0x1.e3ef7ep0, 0x1.0d35dap-1, -0x1.ab00aep0, -0x1.874e46p0, -0x1.8a8a64p0, -0x1.98f178p0, 0x1.a6df22p0, -0x1.69e534p-1, -0x1.c6018ep0, 0x1.60954ep0, 0x1.e47afap0, -0x1.b1d7a6p0, 0x1.bd563p0, 0x1.ee6906p0, 0x1.ce5068p0, -0x1.9ad934p0, -0x1.e299b8p-2, -0x1.579e46p0, -0x1.ccfe06p0, 0x1.b479ccp-4, -0x1.574a24p0, 0x1.6391f8p-1, 0x1.6a44ccp-1, 0x1.d4207ep-1, -0x1.7f0096p-3, -0x1.b24f1ap0, -0x1.7998p0, 0x1.38b0dap-5, -0x1.11a2b6p0, 0x1.5d0e66p0, -0x1.761d3p-2, 0x1.30619ap0, 0x1.c2fb3cp-1, -0x1.e5f45ep0, -0x1.280eecp0, 0x1.391f44p-1, -0x1.82a952p-1, -0x1.bb8eb6p-1, 0x1.c5b95cp-2, 0x1.b497fcp0, -0x1.e6a4fcp0, -0x1.c94768p0, 0x1.1ccda4p-1, -0x1.03585cp0, 0x1.3b28fcp-1, 0x1.0e7946p-1, -0x1.2da4bp0, 0x1.2431ccp0, -0x1.27f18p-1, -0x1.54494cp0, 0x1.3291d8p0, -0x1.974448p0, -0x1.1f0734p0, -0x1.bc1b4ap0, -0x1.600de8p-1, 0x1.7ae3acp-1, 0x1.fe384cp-1, -0x1.caaefep-1, 0x1.9be61ep0, 0x1.7309a8p0, 0x1.d33e3ap-4, 0x1.b3d9d6p0, -0x1.2b50c6p0, -0x1.738ed6p-1, 0x1.cdcf5cp-1, 0x1.cc2c5ap0, 0x1.e3daap0, 0x1.f5d892p0, -0x1.eafa94p-1, 0x1.4c00dap0, 0x1.11190ep0, -0x1.cefab8p-1, -0x1.7957dp0, 0x1.f98474p0, 0x1.87819p-1, 0x1.2ec47p-3, -0x1.3a41c8p0, 0x1.60d7ccp-1, -0x1.308824p-1, 0x1.f73344p-2, 0x1.43dff4p0, 0x1.3df75cp-1, -0x1.38457ep-4, 0x1.64ba32p-3, -0x1.c9ada4p-7, -0x1.0cf5fap0, 0x1.863858p0, 0x1.7ae3c6p0, -0x1.a0edbp0, -0x1.ea52dcp-4, 0x1.ebfaacp0, 0x1.56fbb4p0, 0x1.891804p-2, 0x1.ce19ecp-1, 0x1.80afb4p0, 0x1.1806fep0, 0x1.9f0f7ep0, -0x1.035bf6p-1, -0x1.ec010cp-2, -0x1.494e74p-10, 0x1.9b64cep0, -0x1.e3e89ap-3, 0x1.881612p0, -0x1.ab2fdcp0, -0x1.2034ccp-3, 0x1.5d3f8ap0, -0x1.57ecf8p-2, 0x1.576268p-1, -0x1.484872p-2, -0x1.5c7c0ap0, 0x1.58262cp-1, 0x1.79a292p0, 0x1.aa086ap0, 0x1.5290e6p0, -0x1.18f81cp-4, 0x1.d8c452p0, 0x1.7aa1p-2, 0x1.d9b7f4p0, 0x1.16ce7ep-4, 0x1.e664dap-1, -0x1.cc236cp0, -0x1.be5d64p-2, -0x1.260452p0, 0x1.d63c16p-1, -0x1.24ccd6p-1, 0x1.2d92ecp-1, -0x1.53781p-4, -0x1.f98154p-1, 0x1.617dfep0, 0x1.bc3e9ep0, -0x1.8707aap-2, -0x1.e6cd0ep0, 0x1.dcfb5cp-1, -0x1.c1f73cp0, -0x1.ebb5d8p0, 0x1.d053ecp0, -0x1.1a0594p-1, 0x1.b1cf5ep0, -0x1.73b014p-2, -0x1.2ce586p-2, 0x1.28a38cp-1, -0x1.9b8988p0, -0x1.01c91ap0, 0x1.d03a8ap-1, 0x1.9daa3cp0, 0x1.7fb4aap-2, -0x1.29dd14p-3, 0x1.36e4b4p0, 0x1.d86138p-1, 0x1.24ea7ap0, -0x1.0fe8c6p-3, 0x1.bfe6b8p0, -0x1.b2b75ap0, 0x1.f7df0ep-1, -0x1.11ab2cp-2, 0x1.794678p-1, -0x1.3f98e2p-3, 0x1.5dba36p0, -0x1.dd611ep0, 0x1.3e260cp0, 0x1.dcb6fp0, -0x1.17eb36p0, 0x1.eac0fap-1, -0x1.edf622p-2, 0x1.318cf2p0, -0x1.5ca8aap-1, -0x1.c0252ep-2, 0x1.ee31b8p0, 0x1.15ac98p0, 0x1.be0704p0, 0x1.1f2a68p0, -0x1.df458p-2, 0x1.363e9ep0, 0x1.b4174ap-1, 0x1.daf9ccp-2, -0x1.c8a5dap0, -0x1.b500bep0, -0x1.6e7baap0, 0x1.734aaep-5, 0x1.0dd48ep-1, 0x1.8fd08p0, 0x1.4824d6p-4, 0x1.095512p0, -0x1.eff652p0, -0x1.9e71bcp0, -0x1.03efbep0, -0x1.8cae24p0, -0x1.fe92e4p0, -0x1.15eb84p0, -0x1.30dd1ap0, 0x1.e29b16p-1, 0x1.622adcp-5, 0x1.dd4762p0, 0x1.35eb6p-2, 0x1.1d44a4p0, 0x1.5929p-3, 0x1.867278p0, 0x1.e5f5b4p-3, -0x1.b959dap0, -0x1.c1edacp-1, 0x1.715048p0, 0x1.3989d2p0, 0x1.c4bfccp-1, 0x1.dfa3ep-4, 0x1.cee7bcp-2, 0x1.d6584ep0, 0x1.d754c4p0, 0x1.4da81ep-3, -0x1.7d815ep0, 0x1.b3d2a8p0, -0x1.a6b42ap0, -0x1.dab6bcp0, -0x1.900f06p-3, 0x1.3c4e86p0, 0x1.fc97ecp-2, 0x1.8b553ap0, -0x1.38499ap-1, -0x1.bccb38p-1, -0x1.99b36cp0, -0x1.94b83ap0, 0x1.050766p-3, 0x1.5ef9eep0, -0x1.21c2aep-1, 0x1.29d5cp-5, -0x1.54f9f6p-1, -0x1.a32a44p-5, 0x1.1e79ecp0, 0x1.fbef04p-2, 0x1.65dc2cp-6, -0x1.6a8f48p-3, 0x1.d18a54p-2, -0x1.2b14e4p-2, 0x1.90887ap-1, 0x1.ac333p-1, -0x1.4e2d86p-1, 0x1.a80bc8p0, 0x1.0ca8e4p-1, -0x1.34a5cap-4, -0x1.0f0252p-2, 0x1.82b294p-1, -0x1.8c4cfcp0, 0x1.fd97c2p0, 0x1.b7037ep-1, -0x1.e46848p0, -0x1.c09b94p-5, -0x1.5b9bd8p-4, -0x1.478c12p0, 0x1.4e297ap0, -0x1.4d04a2p0, 0x1.8eb08cp-4, -0x1.0c2e38p-1, 0x1.49bbcap0, 0x1.ac3ba2p-1, 0x1.d76716p-3, -0x1.43f0d4p-1, -0x1.47f904p0, -0x1.f11fe4p0, 0x1.ef26c8p0, -0x1.f3a4bap0, 0x1.3a56a8p0, 0x1.d68bfp0, 0x1.6ed20ep0, 0x1.61b8dcp-4, -0x1.a19efcp-3, 0x1.439b82p-2, 0x1.018798p0, -0x1.528246p0, 0x1.ae29ep-4, 0x1.ad435cp-2, 0x1.aba6f4p0, -0x1.38743cp0, 0x1.e31c12p-1, 0x1.9df348p0, 0x1.a1b5e6p-1, -0x1.52e25ap0, 0x1.027e7cp0, -0x1.48c1fap0, 0x1.2cebbcp-2, 0x1.c9db18p-1, 0x1.e0f83ep-3, 0x1.c2be7cp0, 0x1.bb6bd2p-1, 0x1.22532ep-1, 0x1.aa98a2p0, -0x1.f70e3p0, -0x1.bc48a4p0, -0x1.3c3f88p-2, 0x1.c38f54p-1, -0x1.1aeadp0, -0x1.6b4178p-1, 0x1.234abap0, -0x1.3a0ceep-1, 0x1.489328p-2, 0x1.4dd9cp0, 0x1.edd5fcp-2, -0x1.46b924p0, -0x1.46ca7ap0, 0x1.53221cp0, 0x1.954d8ap-1, 0x1.244668p0, 0x1.d7aceap-4, 0x1.d24cccp0, 0x1.803fa2p0, 0x1.54406ap0, 0x1.e36908p-2, -0x1.de0956p-2, -0x1.b2cc28p0, -0x1.fd4296p-2, -0x1.f538eep0, -0x1.100ec8p-2, -0x1.b1d02ap-1, 0x1.99b232p-2, -0x1.3ec36cp0, -0x1.8bb55p-2, -0x1.30334ep0, -0x1.0de88ap0, 0x1.918328p-1, 0x1.b8556ep-1, -0x1.76cfbp-1, -0x1.65c04p-1, -0x1.7de6fcp-2, -0x1.1c3a12p0, 0x1.c395bep-2, 0x1.fdb892p0, 0x1.3117aap0, 0x1.0dcb9cp0, 0x1.6b3d6cp0, 0x1.2004d6p0, -0x1.87ec78p-1, 0x1.6b04f4p-4, 0x1.7f4daap0, 0x1.904964p0, -0x1.0e9cfp0, 0x1.bc800cp-1, -0x1.85d75ep-5, -0x1.f58a4p0, 0x1.4ff8f8p-2, -0x1.ef655cp0, 0x1.b64d6p0, 0x1.cc32c4p0, 0x1.7b0734p-1, -0x1.2f074cp-2, -0x1.19d674p0, 0x1.f7afc6p0, 0x1.29dfep-2, 0x1.3c7a72p-1, 0x1.9578eap-4, 0x1.41ca9cp0, -0x1.08eefep0, 0x1.cba2aap0, 0x1.cbdb6p-1, 0x1.fe38cep0, 0x1.0322c4p0, 0x1.1bbbe2p0, -0x1.947122p-1, 0x1.402604p-3, 0x1.f8b6acp-1, 0x1.281544p-2, 0x1.fda0ep0, 0x1.0aaedap0, 0x1.230918p0, -0x1.772d0ap0, 0x1.915fbep-1, -0x1.3da854p0, 0x1.10599ap-1, -0x1.85ec26p-1, 0x1.339cfep-1, 0x1.e1fcdp0, 0x1.7e4cf8p-3, 0x1.ec6bf8p0, -0x1.002e1cp0, 0x1.897482p0, -0x1.9ea0f4p0, 0x1.976ab8p-2, -0x1.964afap-1, 0x1.ed0bfp-3, -0x1.c31a7cp0, -0x1.548dbcp0, 0x1.ec8548p0, -0x1.43fc94p-2, -0x1.b6152ep-2, -0x1.b0f1e8p-1, 0x1.307736p0, -0x1.25e478p-3, -0x1.15e68p-1, -0x1.ab4eacp0, 0x1.d1c20ep0, -0x1.0099aep-1, 0x1.faa7ecp0, -0x1.c52298p-1, 0x1.3b07dap0, 0x1.11db38p-2, -0x1.ce9252p-1, -0x1.c2131p-1, -0x1.5657p0, 0x1.c512acp-1, 0x1.84ab34p-3, -0x1.5a9022p0, 0x1.10eb36p0, -0x1.df094p0, 0x1.059d2p-4, -0x1.767842p-4, -0x1.3fa7ap0, 0x1.369c26p0, -0x1.7e18p-2, -0x1.a2702ap-1, 0x1.88cd04p-1, 0x1.f451cep-2, 0x1.1a70d8p-1, 0x1.f0b41ep-6, -0x1.4b2e5cp-2, -0x1.02bc98p-3, -0x1.4ac7f2p0, 0x1.0ae0b8p-6, 0x1.5fff92p-3, 0x1.b57072p-1, -0x1.f0c1d4p0, 0x1.da428ap-3, -0x1.03383p0, -0x1.d5810ep-2, 0x1.9d490cp0, 0x1.32fb86p0, -0x1.770764p0, 0x1.ef0c0ap0, -0x1.0a07eep-2, -0x1.b4cab6p-1, 0x1.40ef88p0, 0x1.bde2f6p-3, -0x1.85cea4p-3, 0x1.688ad6p-1, 0x1.396a44p-5, 0x1.84076p-5, 0x1.99caecp0, 0x1.f058d2p-1, -0x1.12e2b6p-4, 0x1.5bb1b6p0, 0x1.d966b6p-1, -0x1.f7de58p0, 0x1.716beep-2, -0x1.ebcea8p0, 0x1.0109a4p0, 0x1.4f1c3cp0, 0x1.aea16p0, 0x1.791c04p0, 0x1.395b36p-2, 0x1.482118p-2, 0x1.a15024p-1, -0x1.aa14eap-2, 0x1.6324b2p0, 0x1.91b308p-1, 0x1.f9d662p-1, 0x1.c31ac4p-1, -0x1.5fa784p-1, 0x1.d751b8p0, -0x1.42575ap0, 0x1.1adf0cp0, -0x1.ec1a4p-1, -0x1.738d4cp-2, 0x1.15d894p0, 0x1.724142p-2, 0x1.259474p0, -0x1.d7c166p-4, 0x1.8f4a1p-2, -0x1.328682p0, 0x1.3a8c28p-1, 0x1.236e7cp-1, 0x1.e7c04ap-1, 0x1.1718dcp-7, 0x1.2355acp-5, -0x1.f699dep0, 0x1.680694p-1, -0x1.f565f2p-1, -0x1.75a558p-3, 0x1.51700ap0, 0x1.5e95c4p-1, -0x1.bb4efp-1, -0x1.2c52a6p-5, -0x1.628f74p0, -0x1.34abf6p0, 0x1.ddc894p-2, -0x1.856a24p0, -0x1.de90ccp0, -0x1.61cd68p-2, -0x1.b3ccb8p0, -0x1.a9a26p0, 0x1.c1a3a4p0, -0x1.7fd1ap0, -0x1.5c031ap0, -0x1.c60f34p-1, 0x1.3592dp-2, -0x1.f616a8p0, 0x1.6c2ca8p-2, 0x1.94ed74p-2, 0x1.25af4cp0, 0x1.b27aa8p0, 0x1.81d1eep-1, 0x1.b66b1cp0, 0x1.7888f8p0, -0x1.4d52c2p0, -0x1.23687ap-2, 0x1.e02b32p-1, -0x1.236c1p-2, 0x1.4768bp-1, -0x1.ccebf4p0, -0x1.26f43ap-2, -0x1.28a25p0, 0x1.fa4aa4p-1, -0x1.7f7be8p-4, 0x1.46255cp0, -0x1.660204p-2, -0x1.378632p-2, -0x1.90812ep0, -0x1.119b4ap0, -0x1.199b9p0, -0x1.ba0a04p0, -0x1.e16f88p-2, 0x1.805a7ap-2, 0x1.ccd0b8p0, 0x1.52c744p0, -0x1.4d0508p0, -0x1.4752bep0, -0x1.c6bb52p-1, -0x1.c2b3a6p0, 0x1.1a3d8cp-3, -0x1.410c8ep0, 0x1.ff14cep-1, -0x1.95a28ap0, 0x1.02739cp0, -0x1.915038p0, 0x1.7820f4p-3, -0x1.b3168ep0, 0x1.a8247ep-4, -0x1.4d1bc2p0, -0x1.5d2104p0, 0x1.bf9a4ep0, 0x1.d25c3cp0, -0x1.6c3d5ep0, 0x1.21a6eep-1, 0x1.a18eb8p0, -0x1.c47d3ap0, -0x1.996a66p0, 0x1.33d972p-1, -0x1.114d36p0, -0x1.84dfa4p-1, 0x1.671b26p-1, -0x1.b9d89p0, 0x1.ff756p0, 0x1.ae685ep0, 0x1.1d69dep0, 0x1.c05e98p0, 0x1.79394ep-2, -0x1.959226p-2, -0x1.40aa5ep-2, 0x1.7c770cp0, 0x1.f557cp-2, 0x1.95be04p-3, 0x1.454816p0, 0x1.1da982p-1, -0x1.b5fbfep-4, -0x1.29b748p0, -0x1.e7768ep0, 0x1.d410f8p-1, 0x1.54cccep0, -0x1.725588p-1, -0x1.c0c076p0, 0x1.6d683ap-1, 0x1.dcf456p-1, 0x1.ecf96ap0, 0x1.951c4cp-3, 0x1.055a32p0, 0x1.411142p0, -0x1.3aabd6p0, 0x1.298b0cp0, -0x1.f25bdp0, 0x1.8bf5cp0, -0x1.414bd4p-1, -0x1.1d0bf8p-2, -0x1.62c452p0, -0x1.97ece2p0, 0x1.8a3524p-1, -0x1.c396aap0, 0x1.0ea91ap-2, 0x1.433558p0, -0x1.ec4d34p-1, -0x1.b9fbcp0, -0x1.5ec7b4p0, -0x1.7ebed8p-1, -0x1.4e2b32p-1, 0x1.496f34p0, 0x1.455778p0, 0x1.8cb818p0, -0x1.6e392cp-1, 0x1.7f247ap0, 0x1.6a911p0, -0x1.2f3eb4p-1, 0x1.f40f94p0, -0x1.34cbdp0, 0x1.ae721p-3, -0x1.8dcfep0, 0x1.43046ep-2, 0x1.a65588p-1, -0x1.8725c8p-1, 0x1.b8aa44p-1, -0x1.21641ep0, 0x1.6113b2p-2, 0x1.7392eap-1, 0x1.106fdcp0, -0x1.329e02p-1, 0x1.d800a8p-1, -0x1.33c0ap-1, 0x1.9ad578p0, 0x1.03f188p-3, 0x1.12200ap0, 0x1.cf615p0, -0x1.33a1ep-3, 0x1.546c1cp0, 0x1.00690ep-1, 0x1.51e742p0, -0x1.b6e278p-1, 0x1.9ca14ap-1, -0x1.55534cp0, -0x1.fcbab6p-5, 0x1.69109ap0, 0x1.d2fbcp-1, 0x1.ad23dep0, -0x1.0a63b4p0, 0x1.8e98bcp-3, -0x1.4da5ccp-3, 0x1.ba057ap0, 0x1.050554p0, 0x1.752b7cp0, 0x1.9b6cecp-1, 0x1.5db648p0, 0x1.c4b808p-1, 0x1.e232fp-1, -0x1.82023cp-2, -0x1.1d35e6p0, 0x1.9723ap-1, 0x1.988e14p0, -0x1.bffc8ep0, 0x1.eaa9a4p0, -0x1.6cddb2p0, -0x1.d617e6p0, -0x1.3738cp0, -0x1.5e56b6p-1, -0x1.90df9cp0, 0x1.bd882ap-1, -0x1.a21964p-1, 0x1.4634aap0, 0x1.3d705ap-1, -0x1.937362p0, 0x1.734f0cp-2, 0x1.02a3c8p-1, 0x1.c38dfep0, 0x1.cbfe42p0, 0x1.e6d248p-5, 0x1.67c29ap0, -0x1.5084a2p-1, 0x1.691f46p-5, 0x1.2da736p0, 0x1.90be1cp-1, -0x1.852142p-1, -0x1.1d4a1p0, 0x1.d860e6p0, -0x1.7ddc5cp0, -0x1.990a72p0, -0x1.44f66cp0, -0x1.df7eaap0, -0x1.ab3136p0, 0x1.3cdfcp0, 0x1.fe3f4p0, -0x1.8cf41p0, 0x1.58d5c6p0, 0x1.62d366p0, -0x1.1969b4p-6, -0x1.098ed4p-4, -0x1.a8acfep0, -0x1.3ce82p0, 0x1.a9e03p0, -0x1.723bfp0, 0x1.446fcp-1, 0x1.352986p-1, -0x1.d8841ep-9, -0x1.3a2888p0, -0x1.3e71ccp-3, 0x1.5fad18p0, -0x1.a2121cp-4, -0x1.95f36ep-2, -0x1.688108p-2, 0x1.bebacap-1, 0x1.02318p-1, 0x1.62129p0, -0x1.bfdc18p0, -0x1.9bb996p-3, 0x1.cc09acp0, 0x1.e622d4p-2, 0x1.0b1784p-1, -0x1.118c5ep0, 0x1.c0f0cp0, 0x1.75c512p0, 0x1.247f4ap-1, 0x1.911a5ep-1, 0x1.73fc6cp0, -0x1.a99004p0, 0x1.828c3p-3, 0x1.74a94p-2, -0x1.9134ccp0, -0x1.bb7a2cp0, 0x1.3ad4eap-1, 0x1.67ee38p0, -0x1.d751ap-2, -0x1.1863eap0, 0x1.768c3p0, 0x1.5d776p0, 0x1.ecdf4p-1, 0x1.1eec48p0, 0x1.88b688p0, 0x1.fb9872p-2, -0x1.282936p-1, -0x1.703956p-4, -0x1.d343dep0, -0x1.7b5dc4p-2, 0x1.f4d5c4p-1, 0x1.f08d36p0, 0x1.812058p0, 0x1.00781ep-1, 0x1.51492p-2, 0x1.5a4b04p-4, 0x1.f89ffcp-5, -0x1.53d494p-1, 0x1.a53d8p-5, 0x1.3ac2ep-1, 0x1.8e2792p0, -0x1.66d6e2p0, -0x1.ce5958p0, 0x1.fe74e2p-1, -0x1.5999a2p0, -0x1.a915fcp-1, 0x1.44403ap0, -0x1.768eap-1, -0x1.47550ap0, 0x1.261d62p0, 0x1.e76484p-1, 0x1.6297f6p0, 0x1.0c5962p-1, -0x1.c20786p0, -0x1.2f26eep0, 0x1.4c457cp-1, -0x1.ef4e3ap-4, -0x1.58e9dp0, -0x1.efe826p-2, -0x1.9bb2c4p0, -0x1.cffa02p-2, -0x1.d4776ep0, 0x1.167e4p0, 0x1.76e99cp-2, -0x1.6f0cep-2, -0x1.84b0cap-1, -0x1.690328p-1, -0x1.70c752p-2, -0x1.691c86p0, -0x1.c02b84p0, 0x1.abc2cp0, 0x1.62c95cp0, -0x1.998332p-1, 0x1.c7735cp-3, 0x1.0f1d4ep0, -0x1.3fe09ep0, 0x1.61096ep-1, -0x1.c44f7ep-5, -0x1.3792ecp-2, 0x1.37752cp-1, -0x1.66532ep0, 0x1.1889eep-1, -0x1.9dc3f6p0, -0x1.e53d74p-1, 0x1.d0b636p0, -0x1.e6be22p-1, -0x1.2c010ep-3, 0x1.b78c3cp-4, 0x1.a24ed6p0, 0x1.397f5ep0, -0x1.c7f204p0, 0x1.e6dd36p-1, 0x1.7e23eep-2, 0x1.f0c3f6p0, 0x1.12bbccp0, 0x1.9f513cp-1, 0x1.ba9cd8p0, 0x1.019f56p0, -0x1.b04bb2p0, 0x1.f26c0cp-2 };
l_struct_OC_k2c_tensor2 test2_dense_input_input __ATTRIBUTE_WEAK__;
float keras_activation_3_test2_array[6] = { 0x1.c65434p-3, 0x1.7d7a3ep-5, 0x1.a05032p-6, 0x1.2d338p-4, 0x1.38972ep-1, 0x1.6a65dep-6 };
float c_activation_3_test2_array[6];
float errors[10] __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor2 test1_dense_input_input __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor keras_activation_3_test1 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor2 c_activation_3_test1 __ATTRIBUTE_WEAK__;
static  char aesl_internal__OC_str1[37] = "Max absolute error for 2 tests: %e \n";
l_struct_OC_k2c_tensor keras_activation_3_test2 __ATTRIBUTE_WEAK__;
l_struct_OC_k2c_tensor2 c_activation_3_test2 __ATTRIBUTE_WEAK__;
static  char aesl_internal__OC_str[34] = "Average time over 2 tests: %e s \n";


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
  static  unsigned long long aesl_llvm_cbe_exitcond34_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned int llvm_cbe_tmp__19;
  unsigned int llvm_cbe_tmp__19__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  float *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  float llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  float *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  float llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  float llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  float llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  float llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  float llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  float llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  float llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  float llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  float llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  float llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  float llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  float llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  double llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  double llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  double llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  double llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  double llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  float llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  double llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned int llvm_cbe_storemerge7;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_1_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__48;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__48:
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = phi i32 [ 0, %%0 ], [ %%7, %%1 ], !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_3_count);
  llvm_cbe_tmp__1 = (unsigned int )llvm_cbe_tmp__1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%2 to i64, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_4_count);
  llvm_cbe_tmp__2 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [2622 x float]* @test1_dense_input_input_array, i64 0, i64 %%3, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_5_count);
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
printf("\n  %%5 = load float* %%4, align 4, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_6_count);
  llvm_cbe_tmp__4 = (float )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__4, *(int*)(&llvm_cbe_tmp__4));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.k2c_tensor2* @test1_dense_input_input, i64 0, i32 0, i64 %%3, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_7_count);
  llvm_cbe_tmp__5 = (float *)(&test1_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__2))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%5, float* %%6, align 4, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_8_count);
  *llvm_cbe_tmp__5 = llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%2, 1, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_9_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(llvm_cbe_tmp__1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__6&4294967295ull)));
  if (((llvm_cbe_tmp__6&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__49;
  } else {
    llvm_cbe_tmp__1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__6;   /* for PHI node */
    goto llvm_cbe_tmp__48;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__49:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test1_dense_input_input, i64 0, i32 1), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_11_count);
  *((&test1_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test1_dense_input_input, i64 0, i32 2), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_12_count);
  *((&test1_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test1_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_13_count);
  *((&test1_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test1_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_14_count);
  *((&test1_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test1_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_15_count);
  *((&test1_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test1_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_16_count);
  *((&test1_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test1_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_17_count);
  *((&test1_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 1), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_18_count);
  *((&keras_activation_3_test1.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 2), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_19_count);
  *((&keras_activation_3_test1.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 0), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_20_count);
  *((&keras_activation_3_test1.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 1), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_21_count);
  *((&keras_activation_3_test1.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 2), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_22_count);
  *((&keras_activation_3_test1.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 3), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_23_count);
  *((&keras_activation_3_test1.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 3, i64 4), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_24_count);
  *((&keras_activation_3_test1.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 0), align 16, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__7 = (float )*((&keras_activation_3_test1_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__7, *(int*)(&llvm_cbe_tmp__7));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%9, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 0), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_26_count);
  *((&keras_activation_3_test1.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 1), align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__8 = (float )*((&keras_activation_3_test1_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__8, *(int*)(&llvm_cbe_tmp__8));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%10, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 1), align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_28_count);
  *((&keras_activation_3_test1.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 2), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__9 = (float )*((&keras_activation_3_test1_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__9, *(int*)(&llvm_cbe_tmp__9));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%11, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 2), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_30_count);
  *((&keras_activation_3_test1.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 3), align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__10 = (float )*((&keras_activation_3_test1_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__10, *(int*)(&llvm_cbe_tmp__10));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 3), align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_32_count);
  *((&keras_activation_3_test1.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 4), align 16, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__11 = (float )*((&keras_activation_3_test1_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__11, *(int*)(&llvm_cbe_tmp__11));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%13, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 4), align 8, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_34_count);
  *((&keras_activation_3_test1.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test1_array, i64 0, i64 5), align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__12 = (float )*((&keras_activation_3_test1_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__12, *(int*)(&llvm_cbe_tmp__12));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%14, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test1, i64 0, i32 0, i64 5), align 4, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_36_count);
  *((&keras_activation_3_test1.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 1), align 8, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_37_count);
  *((&c_activation_3_test1.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 2), align 8, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_38_count);
  *((&c_activation_3_test1.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 3, i64 0), align 8, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_39_count);
  *((&c_activation_3_test1.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 3, i64 1), align 8, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_40_count);
  *((&c_activation_3_test1.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 3, i64 2), align 8, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_41_count);
  *((&c_activation_3_test1.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 3, i64 3), align 8, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_42_count);
  *((&c_activation_3_test1.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 3, i64 4), align 8, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_43_count);
  *((&c_activation_3_test1.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 0), align 16, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__13 = (float )*((&c_activation_3_test1_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__13, *(int*)(&llvm_cbe_tmp__13));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 0, i64 0), align 8, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_45_count);
  *((&c_activation_3_test1.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 1), align 4, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__14 = (float )*((&c_activation_3_test1_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__14, *(int*)(&llvm_cbe_tmp__14));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%16, float* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 0, i64 1), align 4, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_47_count);
  *((&c_activation_3_test1.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 2), align 8, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__15 = (float )*((&c_activation_3_test1_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__15, *(int*)(&llvm_cbe_tmp__15));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%17, float* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 0, i64 2), align 8, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_49_count);
  *((&c_activation_3_test1.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 3), align 4, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__16 = (float )*((&c_activation_3_test1_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__16, *(int*)(&llvm_cbe_tmp__16));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%18, float* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 0, i64 3), align 4, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_51_count);
  *((&c_activation_3_test1.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 4), align 16, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__17 = (float )*((&c_activation_3_test1_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__17, *(int*)(&llvm_cbe_tmp__17));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%19, float* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 0, i64 4), align 8, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_53_count);
  *((&c_activation_3_test1.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test1_array, i64 0, i64 5), align 4, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__18 = (float )*((&c_activation_3_test1_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__18, *(int*)(&llvm_cbe_tmp__18));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%20, float* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test1, i64 0, i32 0, i64 5), align 4, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_55_count);
  *((&c_activation_3_test1.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test2_dense_input_input, i64 0, i32 1), align 8, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_56_count);
  *((&test2_dense_input_input.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test2_dense_input_input, i64 0, i32 2), align 8, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_57_count);
  *((&test2_dense_input_input.field2)) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2622, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test2_dense_input_input, i64 0, i32 3, i64 0), align 8, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_58_count);
  *((&test2_dense_input_input.field3[(((signed long long )0ull))])) = 2622ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2622ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test2_dense_input_input, i64 0, i32 3, i64 1), align 8, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_59_count);
  *((&test2_dense_input_input.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test2_dense_input_input, i64 0, i32 3, i64 2), align 8, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_60_count);
  *((&test2_dense_input_input.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test2_dense_input_input, i64 0, i32 3, i64 3), align 8, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_61_count);
  *((&test2_dense_input_input.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @test2_dense_input_input, i64 0, i32 3, i64 4), align 8, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_62_count);
  *((&test2_dense_input_input.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @j, align 4, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_63_count);
  *(&j) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  llvm_cbe_tmp__19__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__50;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__50:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = phi i32 [ 0, %%8 ], [ %%27, %%21 ], !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__19 = (unsigned int )llvm_cbe_tmp__19__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__19);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__24);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sext i32 %%22 to i64, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__20 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds [2622 x float]* @test2_dense_input_input_array, i64 0, i64 %%23, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_67_count);
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
printf("\n  %%25 = load float* %%24, align 4, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__22 = (float )*llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__22, *(int*)(&llvm_cbe_tmp__22));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.k2c_tensor2* @test2_dense_input_input, i64 0, i32 0, i64 %%23, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__23 = (float *)(&test2_dense_input_input.field0[(((signed long long )llvm_cbe_tmp__20))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__20));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%25, float* %%26, align 4, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_70_count);
  *llvm_cbe_tmp__23 = llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add nsw i32 %%22, 1, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_tmp__19&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
  if (((llvm_cbe_tmp__24&4294967295U) == (2622u&4294967295U))) {
    goto llvm_cbe_tmp__51;
  } else {
    llvm_cbe_tmp__19__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__24;   /* for PHI node */
    goto llvm_cbe_tmp__50;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__51:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 1), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_73_count);
  *((&keras_activation_3_test2.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 2), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_74_count);
  *((&keras_activation_3_test2.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 3, i64 0), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_75_count);
  *((&keras_activation_3_test2.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 3, i64 1), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_76_count);
  *((&keras_activation_3_test2.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 3, i64 2), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_77_count);
  *((&keras_activation_3_test2.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 3, i64 3), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_78_count);
  *((&keras_activation_3_test2.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 3, i64 4), align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_79_count);
  *((&keras_activation_3_test2.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test2_array, i64 0, i64 0), align 16, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__25 = (float )*((&keras_activation_3_test2_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__25, *(int*)(&llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%29, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 0, i64 0), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_81_count);
  *((&keras_activation_3_test2.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test2_array, i64 0, i64 1), align 4, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__26 = (float )*((&keras_activation_3_test2_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__26, *(int*)(&llvm_cbe_tmp__26));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%30, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 0, i64 1), align 4, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_83_count);
  *((&keras_activation_3_test2.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__26;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test2_array, i64 0, i64 2), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__27 = (float )*((&keras_activation_3_test2_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__27, *(int*)(&llvm_cbe_tmp__27));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%31, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 0, i64 2), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_85_count);
  *((&keras_activation_3_test2.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test2_array, i64 0, i64 3), align 4, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__28 = (float )*((&keras_activation_3_test2_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__28, *(int*)(&llvm_cbe_tmp__28));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%32, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 0, i64 3), align 4, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_87_count);
  *((&keras_activation_3_test2.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test2_array, i64 0, i64 4), align 16, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__29 = (float )*((&keras_activation_3_test2_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__29, *(int*)(&llvm_cbe_tmp__29));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%33, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 0, i64 4), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_89_count);
  *((&keras_activation_3_test2.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__29;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load float* getelementptr inbounds ([6 x float]* @keras_activation_3_test2_array, i64 0, i64 5), align 4, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__30 = (float )*((&keras_activation_3_test2_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__30, *(int*)(&llvm_cbe_tmp__30));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%34, float* getelementptr inbounds (%%struct.k2c_tensor* @keras_activation_3_test2, i64 0, i32 0, i64 5), align 4, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_91_count);
  *((&keras_activation_3_test2.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 1), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_92_count);
  *((&c_activation_3_test2.field1)) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 2), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_93_count);
  *((&c_activation_3_test2.field2)) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 6, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 3, i64 0), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_94_count);
  *((&c_activation_3_test2.field3[(((signed long long )0ull))])) = 6ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 6ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 3, i64 1), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_95_count);
  *((&c_activation_3_test2.field3[(((signed long long )1ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 3, i64 2), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_96_count);
  *((&c_activation_3_test2.field3[(((signed long long )2ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 3, i64 3), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_97_count);
  *((&c_activation_3_test2.field3[(((signed long long )3ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 3, i64 4), align 8, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_98_count);
  *((&c_activation_3_test2.field3[(((signed long long )4ull))])) = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test2_array, i64 0, i64 0), align 16, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__31 = (float )*((&c_activation_3_test2_array[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__31, *(int*)(&llvm_cbe_tmp__31));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%35, float* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 0, i64 0), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_100_count);
  *((&c_activation_3_test2.field0[(((signed long long )0ull))])) = llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test2_array, i64 0, i64 1), align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__32 = (float )*((&c_activation_3_test2_array[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__32, *(int*)(&llvm_cbe_tmp__32));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%36, float* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 0, i64 1), align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_102_count);
  *((&c_activation_3_test2.field0[(((signed long long )1ull))])) = llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test2_array, i64 0, i64 2), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__33 = (float )*((&c_activation_3_test2_array[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__33, *(int*)(&llvm_cbe_tmp__33));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%37, float* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 0, i64 2), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_104_count);
  *((&c_activation_3_test2.field0[(((signed long long )2ull))])) = llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test2_array, i64 0, i64 3), align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__34 = (float )*((&c_activation_3_test2_array[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__34, *(int*)(&llvm_cbe_tmp__34));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%38, float* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 0, i64 3), align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_106_count);
  *((&c_activation_3_test2.field0[(((signed long long )3ull))])) = llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test2_array, i64 0, i64 4), align 16, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__35 = (float )*((&c_activation_3_test2_array[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__35, *(int*)(&llvm_cbe_tmp__35));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%39, float* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 0, i64 4), align 8, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_108_count);
  *((&c_activation_3_test2.field0[(((signed long long )4ull))])) = llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load float* getelementptr inbounds ([6 x float]* @c_activation_3_test2_array, i64 0, i64 5), align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__36 = (float )*((&c_activation_3_test2_array[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__36, *(int*)(&llvm_cbe_tmp__36));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%40, float* getelementptr inbounds (%%struct.k2c_tensor2* @c_activation_3_test2, i64 0, i32 0, i64 5), align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_110_count);
  *((&c_activation_3_test2.field0[(((signed long long )5ull))])) = llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 6, i32* @j, align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_111_count);
  *(&j) = 6u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 6u);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void bitcast (void (...)* @face_classifier_c_initialize to void ()*)() nounwind, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_116_count);
   /*tail*/ face_classifier_c_initialize();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = tail call i32 @clock() nounwind, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__37 = (unsigned int ) /*tail*/ clock();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @AESL_WRAP_face_classifier_c(%%struct.k2c_tensor2* byval @test1_dense_input_input, %%struct.k2c_tensor2* @c_activation_3_test1) nounwind, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_120_count);
   /*tail*/ AESL_WRAP_face_classifier_c(test1_dense_input_input, (l_struct_OC_k2c_tensor2 *)(&c_activation_3_test1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = tail call i32 @clock() nounwind, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__38 = (unsigned int ) /*tail*/ clock();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__38);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = sitofp i32 %%42 to double, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__39 = (double )((double )(signed int )llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__39, *(long long*)(&llvm_cbe_tmp__39));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = sitofp i32 %%41 to double, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__40 = (double )((double )(signed int )llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__40, *(long long*)(&llvm_cbe_tmp__40));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = fsub double %%43, %%44, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__41 = (double )llvm_cbe_tmp__39 - llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__41, *(long long*)(&llvm_cbe_tmp__41));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = fdiv double %%45, 1.000000e+03, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__42 = (double )llvm_cbe_tmp__41 / 0x1.f4p9;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__42, *(long long*)(&llvm_cbe_tmp__42));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = fdiv double %%46, 1.000000e+01, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__43 = (double )llvm_cbe_tmp__42 / 0x1.4p3;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__43, *(long long*)(&llvm_cbe_tmp__43));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([34 x i8]* @aesl_internal_.str, i64 0, i64 0), double %%47) nounwind, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_129_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 34
#endif
])), llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__43, *(long long*)(&llvm_cbe_tmp__43));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__44);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = tail call float @maxabs(%%struct.k2c_tensor* @keras_activation_3_test1, %%struct.k2c_tensor2* @c_activation_3_test1), !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__45 = (float ) /*tail*/ maxabs((l_struct_OC_k2c_tensor *)(&keras_activation_3_test1), (l_struct_OC_k2c_tensor2 *)(&c_activation_3_test1));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = %f",llvm_cbe_tmp__45);
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%49, float* getelementptr inbounds ([10 x float]* @errors, i64 0, i64 0), align 16, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_131_count);
  *((&errors[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = fpext float %%49 to double, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__46 = (double )((double )llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__46, *(long long*)(&llvm_cbe_tmp__46));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([37 x i8]* @aesl_internal_.str1, i64 0, i64 0), double %%50) nounwind, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_144_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 37
#endif
])), llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__46, *(long long*)(&llvm_cbe_tmp__46));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__47);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void bitcast (void (...)* @face_classifier_c_terminate to void ()*)() nounwind, !dbg !18 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_145_count);
   /*tail*/ face_classifier_c_terminate();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = zext i1 %%52 to i32, !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned int )((unsigned int )(bool )(llvm_fcmp_ogt(llvm_cbe_tmp__45, 0x1p0))&1U);
if (AESL_DEBUG_TRACE)
printf("\nstoremerge7 = 0x%X\n", llvm_cbe_storemerge7);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_storemerge7;
}


float maxabs(l_struct_OC_k2c_tensor *llvm_cbe_tensor1, l_struct_OC_k2c_tensor2 *llvm_cbe_tensor2) {
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
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  signed long long *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  unsigned long long llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  float llvm_cbe_tmp__54;
  float llvm_cbe_tmp__54__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  float *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  float llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  float *llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  float llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  float llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  float llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  float llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  unsigned long long llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  float llvm_cbe__2e_lcssa;
  float llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @maxabs\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.k2c_tensor* %%tensor1, i64 0, i32 2, !dbg !9 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__52 = (signed long long *)(&llvm_cbe_tensor1->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__53 = (unsigned long long )*llvm_cbe_tmp__52;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__53);
  if (((llvm_cbe_tmp__53&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__54__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%13, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__62);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = phi float [ %%12, %%.lr.ph ], [ 0.000000e+00, %%0  for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__54 = (float )llvm_cbe_tmp__54__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__54);
printf("\n = %f",llvm_cbe_tmp__61);
printf("\n = %f",0x0p0);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.k2c_tensor* %%tensor1, i64 0, i32 0, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__55 = (float *)(&llvm_cbe_tensor1->field0[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%5, align 4, !dbg !9 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__56 = (float )*llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__56, *(int*)(&llvm_cbe_tmp__56));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.k2c_tensor2* %%tensor2, i64 0, i32 0, i64 %%storemerge1, !dbg !9 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__57 = (float *)(&llvm_cbe_tensor2->field0[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 4, !dbg !9 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__58 = (float )*llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__58, *(int*)(&llvm_cbe_tmp__58));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fsub float %%6, %%8, !dbg !9 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__59 = (float )((float )(llvm_cbe_tmp__56 - llvm_cbe_tmp__58));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__59, *(int*)(&llvm_cbe_tmp__59));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call float @fabsf(float %%9) nounwind, !dbg !9 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_174_count);
  llvm_cbe_tmp__60 = (float ) /*tail*/ fabsf(llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__59, *(int*)(&llvm_cbe_tmp__59));
printf("\nReturn  = %f",llvm_cbe_tmp__60);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = select i1 %%11, float %%10, float %%4, !dbg !10 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__61 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__60, llvm_cbe_tmp__54))) ? ((float )llvm_cbe_tmp__60) : ((float )llvm_cbe_tmp__54));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__61, *(int*)(&llvm_cbe_tmp__61));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i64 %%storemerge1, 1, !dbg !10 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__62 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__62&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @maxabs  --> \n", ++aesl_llvm_cbe_190_count);
  llvm_cbe_tmp__63 = (unsigned long long )*llvm_cbe_tmp__52;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__63);
  if ((((unsigned long long )llvm_cbe_tmp__62&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__63&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__62;   /* for PHI node */
    llvm_cbe_tmp__54__PHI_TEMPORARY = (float )llvm_cbe_tmp__61;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (float )llvm_cbe_tmp__61;   /* for PHI node */
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
printf("\n = %f",llvm_cbe_tmp__61);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @maxabs}\n");
  return llvm_cbe__2e_lcssa;
}

