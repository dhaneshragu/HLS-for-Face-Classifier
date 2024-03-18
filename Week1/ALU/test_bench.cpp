#include <ap_int.h>
#include <stdio.h>

//ap_uint<17> ALU(ap_uint<17> inA, ap_uint<17> inB, ap_uint<1> op);

unsigned int ALU(unsigned int inA, unsigned int inB, unsigned int op);

int main()
{
//	ap_uint<17> inA = 10;
//	ap_uint<17> inB = 8;
//
//	printf("The result of addition w/o using function is: %d \n", (unsigned int)inA + (unsigned int)inB);
//	printf("The result of subtraction w/o using function is: %d \n", (unsigned int)inA - (unsigned int)inB);
//
//	ap_uint<17> add_fun = ALU(inA,inB,1);
//	ap_uint<17> sub_fun = ALU(inA,inB,0);
//
//	printf("The result of addition using function is: %d \n", (unsigned int)add_fun);
//	printf("The result of subtraction using function is: %d \n", (unsigned int)sub_fun);

	unsigned int inA = 10;
	unsigned int inB = 8;

	printf("The result of addition w/o using function is: %d \n", (unsigned int)inA + (unsigned int)inB);
	printf("The result of subtraction w/o using function is: %d \n", (unsigned int)inA - (unsigned int)inB);
	printf("The result of AND w/o using function is: %d \n", (unsigned int)inA & (unsigned int)inB);
	printf("The result of OR w/o using function is: %d \n", (unsigned int)inA | (unsigned int)inB);
	printf("The result of XOR w/o using function is: %d \n", (unsigned int)inA ^ (unsigned int)inB);

	unsigned int add_fun = ALU(inA,inB,0);
	unsigned int sub_fun = ALU(inA,inB,1);
	unsigned int and_fun = ALU(inA,inB,2);
	unsigned int or_fun = ALU(inA,inB,3);
	unsigned int xor_fun = ALU(inA,inB,4);
	unsigned int def_fun = ALU(inA,inB,5);

	printf("The result of addition using function is: %d \n", add_fun);
	printf("The result of subtraction using function is: %d \n", sub_fun);
	printf("The result of AND using function is: %d \n", and_fun);
	printf("The result of OR using function is: %d \n", or_fun);
	printf("The result of XOR using function is: %d \n", xor_fun);
	printf("The result of some other operation using function is: %d \n", def_fun);



	return 0;
}
