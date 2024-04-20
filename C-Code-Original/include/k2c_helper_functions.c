/**
 k2c_helper_functions.c
 This file is part of keras2c
 Copyright 2020 Rory Conlin
 Licensed under MIT License
 https://github.com/f0uriest/keras2c
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "k2c_include.h"

/**
 * Just your basic 1d matrix multipication.
 * computes C = A*B
 * assumes A,B,C are all 1d arrays of matrices stored in row major order.
 *
 * :param C: output array.
 * :param A: input array 1.
 * :param B: input array 2.
 * :param outrows: number of rows of C and A.
 * :param outcols: number of cols of C and B.
 * :param innderdim: number of cols of A and rows of B
 */
// void k2c_matmul(float  *C, const float * A, const float * B, const size_t outrows,
//                 const size_t outcols, const size_t innerdim) {
// 	size_t i; size_t j;
//     for (i = 0 ; i < outrows; ++i) {
//         for (j = 0;  j < outcols; ++j) {
//             C[i*outcols + j] = 0;
//             for (size_t k = 0; k < innerdim; ++k) {
//                 C[i*outcols + j] += A[i*innerdim + k] * B[k*outcols + j];
//             }
//         }
//     }
// }

/**
 * Affine matrix multiplication.
 * computes C = A*B + d, where d is a vector that is added to each
 row of A*B
 * assumes A,B,C are all 1d arrays of matrices stored in row major order
 *
 * :param C: output array.
 * :param A: input array 1.
 * :param B: input array 2.
 * :param d: input array 3.
 * :param outrows: number of rows of C and A.
 * :param outcols: number of cols of C, B and d.
 * :param innderdim: number of cols of A and rows of B
 */
void k2c_affine_matmul(float C[100000], const float A[100000],
		const float B[100000], const float d[100000], const size_t outrows,
		const size_t outcols, const size_t innerdim) {

	// make sure output is empty
//    memset(C, 0, outrows*outcols*sizeof(C[0]));
	size_t i;
	for (i = 0; i < outrows; ++i) {
		const size_t outrowidx = i * outcols;
		const size_t inneridx = i * innerdim;
		for (size_t j = 0; j < outcols; ++j) {
			C[outrowidx + j] = 0;
			for (size_t k = 0; k < innerdim; ++k) {
				C[outrowidx + j] += A[inneridx + k] * B[k * outcols + j];
			}
			C[outrowidx + j] += d[j];
		}
	}
}

/**
 * Converts subscripts to linear indices in row major order.
 *
 * :param sub: array[ndim] subscript to convert.
 * :param shape: array[ndim] shape of array being indexed.
 * :param ndim: number of dimensions of array being indexed.
 * :return: linear index in row major order.
 */
size_t k2c_sub2idx(const size_t * sub, const size_t * shape, const size_t ndim) {

	size_t idx = 0;
	size_t temp = 0;
#pragma HLS pipeline
	for (size_t i = 0; i < ndim; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
		temp = sub[i];
#pragma HLS pipeline
		for (size_t j = ndim - 1; j > i; --j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
			temp *= shape[j];
		}
		idx += temp;
	}
	return idx;
}

/**
 * Converts linear indices to subscripts in row major order.
 *
 * :param idx: linear index in row major order.
 * :param sub: array[ndim] output subscript.
 * :param shape: array[ndim] shape of array being indexed.
 * :param ndim: number of dimensions of array being indexed.
 */
void k2c_idx2sub(const size_t idx, size_t * sub, const size_t * shape,
		const size_t ndim) {

	size_t idx2 = idx;
#pragma HLS pipeline
	for (int i = ndim - 1; i >= 0; --i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
		sub[i] = idx2 % shape[i];
		idx2 /= shape[i];
	}
}

/**
 * Dot product (tensor contraction) between 2 tensors. C=A*B
 *
 * :param C: output tensor.
 * :param A: input tensor 1.
 * :param B: input tensor 2.
 * :param axesA: array[naxes] of axes of A being contracted.
 * :param axesB: array[naxes] of axes of B being contracted.
 * :param naxes: number of axes being contracted from each input.
 * :param normalize: (0,1) whether to L2-normalize samples along the dot product axis before taking the dot product. If set to 1, then the output of the dot product is the cosine proximity between the two samples.
 * :param fwork: array of working space, size(fwork) = size(A) + size(B)
 // */
//void k2c_dot(k2c_tensor2* C, const k2c_tensor2* Ar, const k2c_tensor* B, const size_t * axesA,
//             const size_t * axesB, const size_t naxes, const int normalize, float * fwork) {
//
//    size_t permA[K2C_MAX_NDIM];
//    size_t permB[K2C_MAX_NDIM];
//    size_t prod_axesA = 1;
//    size_t prod_axesB = 1;
//    size_t free_axesA, free_axesB;
//    size_t freeA[K2C_MAX_NDIM];
//    size_t freeB[K2C_MAX_NDIM];
//    size_t count;
//    int isin;
//    size_t newshpA[K2C_MAX_NDIM];
//    size_t newshpB[K2C_MAX_NDIM];
//    const size_t ndimA = Ar->ndim;
//    const size_t ndimB = B->ndim;
//    float *reshapeA = &fwork[0];   // temp working storage
//    float *reshapeB = &fwork[Ar->numel];
//    size_t Asub[K2C_MAX_NDIM];
//    size_t Bsub[K2C_MAX_NDIM];
//    // find which axes are free (ie, not being summed over)
//    count=0;
//    size_t i,j;
//    for ( i=0; i<ndimA; ++i) {
//        isin = 0;
//        for (size_t j=0; j<naxes; ++j) {
//            if (i==axesA[j]) {
//                isin=1;
//            }
//        }
//        if (!isin) {
//            freeA[count] = i;
//            ++count;
//        }
//    }
//    count=0;
//    for ( i=0; i<ndimB; ++i) {
//        isin = 0;
//        for (size_t j=0; j<naxes; ++j) {
//            if (i==axesB[j]) {
//                isin=1;
//            }
//        }
//        if (!isin) {
//            freeB[count] = i;
//            ++count;
//        }
//    }
//
//    // number of elements in inner dimension
//    for ( i=0; i < naxes; ++i) {
//        prod_axesA *= Ar->shape[axesA[i]];
//    }
//    for (i=0; i < naxes; ++i) {
//        prod_axesB *= B->shape[axesB[i]];
//    }
//    // number of elements in free dimension
//    free_axesA = Ar->numel/prod_axesA;
//    free_axesB = B->numel/prod_axesB;
//    // find permutation of axes to get into matmul shape
//    for ( i=0; i<ndimA-naxes; ++i) {
//        permA[i] = freeA[i];
//    }
//    for ( i=ndimA-naxes, j=0; i<ndimA; ++i, ++j) {
//        permA[i] = axesA[j];
//    }
//    for ( i=0; i<naxes; ++i) {
//        permB[i] = axesB[i];
//    }
//    for (i=naxes, j=0; i<ndimB; ++i, ++j) {
//        permB[i] = freeB[j];
//    }
//
//
//
//    for ( i=0; i<ndimA; ++i) {
//        newshpA[i] = Ar->shape[permA[i]];
//    }
//    for ( i=0; i<ndimB; ++i) {
//        newshpB[i] = B->shape[permB[i]];
//    }
//
//    // reshape arrays
//    for ( i=0; i<Ar->numel; ++i) {
//        k2c_idx2sub(i,Asub,Ar->shape,ndimA);
//        for (size_t j=0; j<ndimA; ++j) {
//            Bsub[j] = Asub[permA[j]];
//        }
//        size_t bidx = k2c_sub2idx(Bsub,newshpA,ndimA);
//        reshapeA[bidx] = Ar->array[i];
//    }
//
//    for ( i=0; i<B->numel; ++i) {
//        k2c_idx2sub(i,Bsub,B->shape,ndimB);
//        for (size_t j=0; j<ndimB; ++j) {
//            Asub[j] = Bsub[permB[j]];
//        }
//        size_t bidx = k2c_sub2idx(Asub,newshpB,ndimB);
//        reshapeB[bidx] = B->array[i];
//    }
//
//
//    if (normalize) {
//
//        float sum;
//        float inorm;
//        size_t i;
//        for ( i=0; i<free_axesA; ++i) {
//            sum = 0;
//            size_t j;
//            for ( j=0; j<prod_axesA; ++j) {
//                sum += reshapeA[i*prod_axesA + j]*reshapeA[i*prod_axesA + j];
//            }
//            inorm = 1.0f/sqrtf(sum);
//            for ( j=0; j<prod_axesA; ++j) {
//                reshapeA[i*prod_axesA + j] *= inorm;
//            }
//        }
//        for ( i=0; i<free_axesB; ++i) {
//            sum = 0;
//            size_t j;
//            for ( j=0; j<prod_axesB; ++j) {
//                sum += reshapeB[i + free_axesB*j]*reshapeB[i + free_axesB*j];
//            }
//            inorm = 1.0f/sqrtf(sum);
//            for ( j=0; j<prod_axesB; ++j) {
//                reshapeB[i + free_axesB*j] *= inorm;
//            }
//        }
//    }
//
//    //k2c_matmul(C->array, reshapeA, reshapeB, free_axesA,free_axesB, prod_axesA);
//
//        for (i = 0 ; i < free_axesA; ++i) {
//            for (size_t j = 0;  j < free_axesB; ++j) {
//                C->array[i*free_axesB + j] = 0;
//                for (size_t k = 0; k < prod_axesA; ++k) {
//                    C->array[i*free_axesB + j] += reshapeA[i*prod_axesA + k] * reshapeB[k*free_axesB + j];
//                }
//            }
//        }
//}
//

void k2c_dot(k2c_tensor2* C, const k2c_tensor2* Ar, const k2c_tensor* B,
		const size_t * axesA, const size_t * axesB, const size_t naxes,
		const int normalize, float * fwork) {

	size_t permA[K2C_MAX_NDIM];
	size_t permB[K2C_MAX_NDIM];
	size_t prod_axesA = 1;
	size_t prod_axesB = 1;
	size_t free_axesA, free_axesB;
	size_t freeA[K2C_MAX_NDIM];
	size_t freeB[K2C_MAX_NDIM];
	size_t count;
	int isin;
	size_t newshpA[K2C_MAX_NDIM];
	size_t newshpB[K2C_MAX_NDIM];
	const size_t ndimA = Ar->ndim;
	const size_t ndimB = B->ndim;
	float *reshapeA = &fwork[0];   // temp working storage
	float *reshapeB = &fwork[Ar->numel];
	size_t Asub[K2C_MAX_NDIM];
	size_t Bsub[K2C_MAX_NDIM];
	size_t i, j;

	// Find which axes are free (i.e., not being summed over) in array Ar
	count = 0;
	for (i = 0; i < ndimA; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2 avg=2
		isin = 0;
		for (j = 0; j < naxes; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS unroll
			if (i == axesA[j]) {
				isin = 1;
			}
		}
		if (!isin) {
			freeA[count] = i;
			++count;
		}
	}

	// Find which axes are free (i.e., not being summed over) in array B
	count = 0;
	for (i = 0; i < ndimB; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2 avg=2
		isin = 0;
		for (j = 0; j < naxes; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS unroll
			if (i == axesB[j]) {
				isin = 1;
			}
		}
		if (!isin) {
			freeB[count] = i;
			++count;
		}
	}

	// Calculate the number of elements in the inner dimension for arrays Ar and B
	for (i = 0; i < naxes; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS unroll
		prod_axesA *= Ar->shape[axesA[i]];
	}
	for (i = 0; i < naxes; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS unroll
		prod_axesB *= B->shape[axesB[i]];
	}

	// Calculate the number of elements in free dimensions
	free_axesA = Ar->numel / prod_axesA;
	free_axesB = B->numel / prod_axesB;

	// Find permutation of axes to get into matmul shape for array Ar
	for (i = 0; i < ndimA - naxes; ++i) {
//		#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS PIPELINE
		permA[i] = freeA[i];
	}
	for (i = ndimA - naxes, j = 0; i < ndimA; ++i, ++j) {
//		#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS PIPELINE
		permA[i] = axesA[j];
	}

	// Find permutation of axes to get into matmul shape for array B
	for (i = 0; i < naxes; ++i) {
//		#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS PIPELINE
		permB[i] = axesB[i];
	}
	for (i = naxes, j = 0; i < ndimB; ++i, ++j) {
//		#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS PIPELINE
		permB[i] = freeB[j];
	}

	for (i = 0; i < ndimA; ++i) {
//		#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=2 avg=2
#pragma HLS PIPELINE
		newshpA[i] = Ar->shape[permA[i]];
	}
	for (i = 0; i < ndimB; ++i) {
//		#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=2 avg=2
#pragma HLS PIPELINE
		newshpB[i] = B->shape[permB[i]];
	}

	// Reshape arrays
	for (i = 0; i < Ar->numel; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622 avg=2622
		k2c_idx2sub(i, Asub, Ar->shape, ndimA);
		for (j = 0; j < ndimA; ++j) {
//			#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=ndimA
#pragma HLS PIPELINE
			Bsub[j] = Asub[permA[j]];
		}
		size_t bidx = k2c_sub2idx(Bsub, newshpA, ndimA);
		reshapeA[bidx] = Ar->array[i];
	}

	for (i = 0; i < B->numel; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
		k2c_idx2sub(i, Bsub, B->shape, ndimB);
		for (j = 0; j < ndimB; ++j) {
//			#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=5
#pragma HLS PIPELINE
			Asub[j] = Bsub[permB[j]];
		}
		size_t bidx = k2c_sub2idx(Asub, newshpB, ndimB);
		reshapeB[bidx] = B->array[i];
	}

	if (normalize) {
		float sum;
		float inorm;
		for (i = 0; i < free_axesA; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
			sum = 0;
			for (j = 0; j < prod_axesA; ++j) {
//				#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
#pragma HLS PIPELINE
				sum += reshapeA[i * prod_axesA + j]
						* reshapeA[i * prod_axesA + j];
			}
			inorm = 1.0f / sqrtf(sum);
			for (j = 0; j < prod_axesA; ++j) {
//				#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
#pragma HLS PIPELINE
				reshapeA[i * prod_axesA + j] *= inorm;
			}
		}
		for (i = 0; i < free_axesB; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
			sum = 0;
			for (j = 0; j < prod_axesB; ++j) {
//				#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622 avg=2622
#pragma HLS PIPELINE
				sum += reshapeB[i + free_axesB * j]
						* reshapeB[i + free_axesB * j];
			}
			inorm = 1.0f / sqrtf(sum);
			for (j = 0; j < prod_axesB; ++j) {
//				#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622 avg=2622
#pragma HLS PIPELINE
				reshapeB[i + free_axesB * j] *= inorm;
			}
		}
	}

	// Perform matrix multiplication
	for (i = 0; i < free_axesA; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622 avg=2622
		for (j = 0; j < free_axesB; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622 avg=2622
			C->array[i * free_axesB + j] = 0;
			for (size_t k = 0; k < prod_axesA; ++k) {
//				#pragma HLS unroll
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622 avg=2622
#pragma HLS PIPELINE
				C->array[i * free_axesB + j] += reshapeA[i * prod_axesA + k]
						* reshapeB[k * free_axesB + j];
			}
		}
	}
}

//void k2c_dot2(k2c_tensor2* C, const k2c_tensor2* Ar, const k2c_tensor2* B, const size_t * axesA,
//             const size_t * axesB, const size_t naxes, const int normalize, float * fwork) {
//
//    size_t permA[K2C_MAX_NDIM];
//    size_t permB[K2C_MAX_NDIM];
//    size_t prod_axesA = 1;
//    size_t prod_axesB = 1;
//    size_t free_axesA, free_axesB;
//    size_t freeA[K2C_MAX_NDIM];
//    size_t freeB[K2C_MAX_NDIM];
//    size_t count;
//    int isin;
//    size_t newshpA[K2C_MAX_NDIM];
//    size_t newshpB[K2C_MAX_NDIM];
//    const size_t ndimA = Ar->ndim;
//    const size_t ndimB = B->ndim;
//    float *reshapeA = &fwork[0];   // temp working storage
//    float *reshapeB = &fwork[Ar->numel];
//    size_t Asub[K2C_MAX_NDIM];
//    size_t Bsub[K2C_MAX_NDIM];
//    // find which axes are free (ie, not being summed over)
//    count=0;
//    size_t i,j;
//    for ( i=0; i<ndimA; ++i) {
//        isin = 0;
//        for (size_t j=0; j<naxes; ++j) {
//            if (i==axesA[j]) {
//                isin=1;
//            }
//        }
//        if (!isin) {
//            freeA[count] = i;
//            ++count;
//        }
//    }
//    count=0;
//    for ( i=0; i<ndimB; ++i) {
//        isin = 0;
//        for (size_t j=0; j<naxes; ++j) {
//            if (i==axesB[j]) {
//                isin=1;
//            }
//        }
//        if (!isin) {
//            freeB[count] = i;
//            ++count;
//        }
//    }
//
//    // number of elements in inner dimension
//    for ( i=0; i < naxes; ++i) {
//        prod_axesA *= Ar->shape[axesA[i]];
//    }
//    for (i=0; i < naxes; ++i) {
//        prod_axesB *= B->shape[axesB[i]];
//    }
//    // number of elements in free dimension
//    free_axesA = Ar->numel/prod_axesA;
//    free_axesB = B->numel/prod_axesB;
//    // find permutation of axes to get into matmul shape
//    for ( i=0; i<ndimA-naxes; ++i) {
//        permA[i] = freeA[i];
//    }
//    for ( i=ndimA-naxes, j=0; i<ndimA; ++i, ++j) {
//        permA[i] = axesA[j];
//    }
//    for ( i=0; i<naxes; ++i) {
//        permB[i] = axesB[i];
//    }
//    for (i=naxes, j=0; i<ndimB; ++i, ++j) {
//        permB[i] = freeB[j];
//    }
//
//
//
//    for ( i=0; i<ndimA; ++i) {
//        newshpA[i] = Ar->shape[permA[i]];
//    }
//    for ( i=0; i<ndimB; ++i) {
//        newshpB[i] = B->shape[permB[i]];
//    }
//
//    // reshape arrays
//    for ( i=0; i<Ar->numel; ++i) {
//        k2c_idx2sub(i,Asub,Ar->shape,ndimA);
//        for (size_t j=0; j<ndimA; ++j) {
//            Bsub[j] = Asub[permA[j]];
//        }
//        size_t bidx = k2c_sub2idx(Bsub,newshpA,ndimA);
//        reshapeA[bidx] = Ar->array[i];
//    }
//
//    for ( i=0; i<B->numel; ++i) {
//        k2c_idx2sub(i,Bsub,B->shape,ndimB);
//        for (size_t j=0; j<ndimB; ++j) {
//            Asub[j] = Bsub[permB[j]];
//        }
//        size_t bidx = k2c_sub2idx(Asub,newshpB,ndimB);
//        reshapeB[bidx] = B->array[i];
//    }
//
//
//    if (normalize) {
//
//        float sum;
//        float inorm;
//        size_t i;
//        for ( i=0; i<free_axesA; ++i) {
//            sum = 0;
//            size_t j;
//            for ( j=0; j<prod_axesA; ++j) {
//                sum += reshapeA[i*prod_axesA + j]*reshapeA[i*prod_axesA + j];
//            }
//            inorm = 1.0f/sqrtf(sum);
//            for ( j=0; j<prod_axesA; ++j) {
//                reshapeA[i*prod_axesA + j] *= inorm;
//            }
//        }
//        for ( i=0; i<free_axesB; ++i) {
//            sum = 0;
//            size_t j;
//            for ( j=0; j<prod_axesB; ++j) {
//                sum += reshapeB[i + free_axesB*j]*reshapeB[i + free_axesB*j];
//            }
//            inorm = 1.0f/sqrtf(sum);
//            for ( j=0; j<prod_axesB; ++j) {
//                reshapeB[i + free_axesB*j] *= inorm;
//            }
//        }
//    }
//
//    //k2c_matmul(C->array, reshapeA, reshapeB, free_axesA,free_axesB, prod_axesA);
//
//        for (i = 0 ; i < free_axesA; ++i) {
//            for (size_t j = 0;  j < free_axesB; ++j) {
//                C->array[i*free_axesB + j] = 0;
//                for (size_t k = 0; k < prod_axesA; ++k) {
//                    C->array[i*free_axesB + j] += reshapeA[i*prod_axesA + k] * reshapeB[k*free_axesB + j];
//                }
//            }
//        }
//}

void k2c_dot2(k2c_tensor2* C, const k2c_tensor2* Ar, const k2c_tensor2* B,
		const size_t * axesA, const size_t * axesB, const size_t naxes,
		const int normalize, float * fwork) {

	size_t permA[K2C_MAX_NDIM];
	size_t permB[K2C_MAX_NDIM];
	size_t prod_axesA = 1;
	size_t prod_axesB = 1;
	size_t free_axesA, free_axesB;
	size_t freeA[K2C_MAX_NDIM];
	size_t freeB[K2C_MAX_NDIM];
	size_t count;
	int isin;
	size_t newshpA[K2C_MAX_NDIM];
	size_t newshpB[K2C_MAX_NDIM];
	const size_t ndimA = Ar->ndim;
	const size_t ndimB = B->ndim;
	float *reshapeA = &fwork[0];   // temp working storage
	float *reshapeB = &fwork[Ar->numel];
	size_t Asub[K2C_MAX_NDIM];
	size_t Bsub[K2C_MAX_NDIM];
	// find which axes are free (ie, not being summed over)
	count = 0;
	size_t i, j;
	for (i = 0; i < ndimA; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2 avg=2
		isin = 0;
		for (size_t j = 0; j < naxes; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS unroll
			if (i == axesA[j]) {
				isin = 1;
			}
		}
		if (!isin) {
			freeA[count] = i;
			++count;
		}
	}
	count = 0;
	for (i = 0; i < ndimB; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2 avg=2
		isin = 0;
		for (size_t j = 0; j < naxes; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS unroll
			if (i == axesB[j]) {
				isin = 1;
			}
		}
		if (!isin) {
			freeB[count] = i;
			++count;
		}
	}

	// number of elements in inner dimension
	for (i = 0; i < naxes; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS unroll
		prod_axesA *= Ar->shape[axesA[i]];
	}
	for (i = 0; i < naxes; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS unroll
		prod_axesB *= B->shape[axesB[i]];
	}
	// number of elements in free dimension
	free_axesA = Ar->numel / prod_axesA;
	free_axesB = B->numel / prod_axesB;
	// find permutation of axes to get into matmul shape
	for (i = 0; i < ndimA - naxes; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS PIPELINE
		permA[i] = freeA[i];
	}
	for (i = ndimA - naxes, j = 0; i < ndimA; ++i, ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS PIPELINE
		permA[i] = axesA[j];
	}
	for (i = 0; i < naxes; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS PIPELINE
		permB[i] = axesB[i];
	}
	for (i = naxes, j = 0; i < ndimB; ++i, ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS PIPELINE
		permB[i] = freeB[j];
	}

	for (i = 0; i < ndimA; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2 avg=2
#pragma HLS PIPELINE
		newshpA[i] = Ar->shape[permA[i]];
	}
	for (i = 0; i < ndimB; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2 avg=2
#pragma HLS PIPELINE
		newshpB[i] = B->shape[permB[i]];
	}

	// reshape arrays
	for (i = 0; i < Ar->numel; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
		k2c_idx2sub(i, Asub, Ar->shape, ndimA);
		for (size_t j = 0; j < ndimA; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS PIPELINE
			Bsub[j] = Asub[permA[j]];
		}
		size_t bidx = k2c_sub2idx(Bsub, newshpA, ndimA);
		reshapeA[bidx] = Ar->array[i];
	}

	for (i = 0; i < B->numel; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
		k2c_idx2sub(i, Bsub, B->shape, ndimB);
		for (size_t j = 0; j < ndimB; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=5 avg=5
#pragma HLS PIPELINE
			Asub[j] = Bsub[permB[j]];
		}
		size_t bidx = k2c_sub2idx(Asub, newshpB, ndimB);
		reshapeB[bidx] = B->array[i];
	}

	if (normalize) {

		float sum;
		float inorm;
		size_t i;
		for (i = 0; i < free_axesA; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
			sum = 0;
			size_t j;
			for (j = 0; j < prod_axesA; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
#pragma HLS PIPELINE
				sum += reshapeA[i * prod_axesA + j]
						* reshapeA[i * prod_axesA + j];
			}
			inorm = 1.0f / sqrtf(sum);
			for (j = 0; j < prod_axesA; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
#pragma HLS PIPELINE
				reshapeA[i * prod_axesA + j] *= inorm;
			}
		}
		for (i = 0; i < free_axesB; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
			sum = 0;
			size_t j;
			for (j = 0; j < prod_axesB; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
#pragma HLS PIPELINE
				sum += reshapeB[i + free_axesB * j]
						* reshapeB[i + free_axesB * j];
			}
			inorm = 1.0f / sqrtf(sum);
			for (j = 0; j < prod_axesB; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
#pragma HLS PIPELINE
				reshapeB[i + free_axesB * j] *= inorm;
			}
		}
	}

	//k2c_matmul(C->array, reshapeA, reshapeB, free_axesA,free_axesB, prod_axesA);

	for (i = 0; i < free_axesA; ++i) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622 avg=2622

		for (size_t j = 0; j < free_axesB; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622 avg=2622

			C->array[i * free_axesB + j] = 0;
			for (size_t k = 0; k < prod_axesA; ++k) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622 avg=2622

#pragma HLS PIPELINE
				C->array[i * free_axesB + j] += reshapeA[i * prod_axesA + k]
						* reshapeB[k * free_axesB + j];
			}
		}
	}
}

/**
 * Adds bias vector b to tensor A.
 * assumes b is a rank 1 tensor that is added to the last dimension of A.
 *
 * :param A: input tensor. Overwritten with outputs.
 * :param b: bias tensor.
 */
void k2c_bias_add(k2c_tensor2* A, const k2c_tensor2* b) {

#pragma HLS pipeline
	for (size_t i = 0; i < A->numel; i += b->numel) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622 avg=2622
#pragma HLS pipeline
		for (size_t j = 0; j < b->numel; ++j) {
#pragma HLS LOOP_TRIPCOUNT min=1 max=2622
			A->array[i + j] += b->array[j];
		}
	}
}

/**
 * Flips a tensor along specified axis.
 * overwrites input with flipped output.
 *
 * :param A: input tensor. Overwritten with outputs.
 * :param axis: axis along which to flip
 */

void k2c_flip(k2c_tensor *A, const size_t axis) {
	const size_t ndim = A->ndim;
	const size_t * shape = A->shape;
	const size_t numel = A->numel;
	size_t sub[K2C_MAX_NDIM] = { 0 };
	const size_t step = 1;
	size_t k = 0;
	size_t idx = 0;
	float temp;

	size_t reduced_size = 1;
	for (size_t i = axis; i < ndim; ++i) {
		reduced_size *= shape[i];
	}
	const size_t threshold = reduced_size / 2;
	const size_t jump = reduced_size;

	while (k < numel) {
		k2c_idx2sub(k, sub, shape, ndim);
		sub[axis] = shape[axis] - sub[axis] - 1;
		idx = k2c_sub2idx(sub, shape, ndim);
		temp = A->array[k];
		A->array[k] = A->array[idx];
		A->array[idx] = temp;
		if ((k + step) % jump >= threshold) {
			k = (k + step - threshold + jump);
		} else {
			k += step;
		}
	}
}

/**
 * Reads array from csv file.
 *
 * :param filename: file to read from. Assumed comma separated ascii text.
 * :param array_size: how many values to read from the file.
 * :return: pointer to allocated array.
 */
float* k2c_read_array(const char* filename, const size_t array_size) {
	float* ptr = (float*) malloc(array_size * sizeof(float));
	if (!ptr) {
		printf("cannot allocate memory %s \n", filename);
		exit(-1);
	}
	size_t ctr = 0;
	FILE *finp;
	int foo;
	finp = fopen(filename, "r");
	if (NULL == finp) {
		printf("Unable to open file %s \n", filename);
		exit(-1);
	}
	while ((!feof(finp)) && (ctr < array_size)) {
		foo = fscanf(finp, "%f,", &ptr[ctr++]);
	}
	fclose(finp);
	return ptr;
}
