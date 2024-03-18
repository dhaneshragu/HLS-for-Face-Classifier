#include <ap_int.h>
#include <stdio.h>

// ap_uint<17> denotes an unsigned integer with a width of 17 bits.
// This custom data type is often used in FPGA development to represent fixed-width
// unsigned integers.

//ap_uint<17> ALU(ap_uint<17> inA, ap_uint<17> inB, ap_uint<1> op)
//{
//	if(op == 1)
//	{
//		return inA+inB;
//	}
//	else
//	{
//		return inA-inB;
//	}
//}

unsigned int ALU(unsigned int inA, unsigned int inB, unsigned int op) {
    unsigned int result;

    switch(op) {
        case 0:  // Addition
            result = inA + inB;
            break;
        case 1:  // Subtraction
            result = inA - inB;
            break;
        case 2:  // Bitwise AND
            result = inA & inB;
            break;
        case 3:  // Bitwise OR
            result = inA | inB;
            break;
        case 4:  // Bitwise XOR
            result = inA ^ inB;
            break;
        default: // Unsupported operation
            printf("Unsupported operation\n");
            result = 0; // Return a default value
            break;
    }

    return result;
}
