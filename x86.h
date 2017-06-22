
#ifndef X86_H
#define X86_H

#ifdef __cplusplus
extern "C" {
#endif

#include <capstone/platform.h>
#include <capstone/capstone.h>
#include "ins_dec.h"
id_platform x86_platform = {CS_ARCH_X86, CS_MODE_64, "X86 64bit (Intel syntax)", CS_OPT_DETAIL, CS_OPT_ON};


x86_reg x86_gpr[] =
{
	X86_REG_AH, X86_REG_AL, X86_REG_AX, X86_REG_BH, X86_REG_BL,
	X86_REG_BP, X86_REG_BPL, X86_REG_BX, X86_REG_CH, X86_REG_CL,
	X86_REG_CS, X86_REG_CX, X86_REG_DH, X86_REG_DI, X86_REG_DIL,
	X86_REG_DL, X86_REG_DS, X86_REG_DX, X86_REG_EAX, X86_REG_EBP,
	X86_REG_EBX, X86_REG_ECX, X86_REG_EDI, X86_REG_EDX, X86_REG_EFLAGS,
	X86_REG_EIP, X86_REG_EIZ, X86_REG_ES, X86_REG_ESI, X86_REG_ESP,
	X86_REG_FPSW, X86_REG_FS, X86_REG_GS, X86_REG_IP, X86_REG_RAX,
	X86_REG_RBP, X86_REG_RBX, X86_REG_RCX, X86_REG_RDI, X86_REG_RDX,
	X86_REG_RIP, X86_REG_RIZ, X86_REG_RSI, X86_REG_RSP, X86_REG_SI,
	X86_REG_SIL, X86_REG_SP, X86_REG_SPL, X86_REG_SS, X86_REG_CR0,

};

x86_reg x86_float[] =
{
	X86_REG_ST0, X86_REG_ST1, X86_REG_ST2, X86_REG_ST3,
	X86_REG_ST4, X86_REG_ST5, X86_REG_ST6, X86_REG_ST7,

};

x86_reg x86_vector[] =
{
	 X86_REG_ST7

};

x86_insn x86_add_insn[] = 
{
	X86_INS_ADD,
	X86_INS_ADDPD,
	X86_INS_ADDPS,
	X86_INS_ADDSD,
	X86_INS_ADDSS,
//	X86_INS_ADDSUBPD,
//	X86_INS_ADDSUBPS,
	X86_INS_FADD,
	X86_INS_FIADD,
	X86_INS_FADDP,
	X86_INS_HADDPD,
	X86_INS_HADDPS,
	X86_INS_PADDB,
	X86_INS_PADDD,
	X86_INS_PADDQ,
	X86_INS_PADDSB,
	X86_INS_PADDSW,
	X86_INS_PADDUSB,
	X86_INS_PADDUSW,
	X86_INS_PADDW,
	X86_INS_XADD,
	X86_INS_PHADDSW,
	X86_INS_PHADDW,
	X86_INS_PHADDD,
	X86_INS_PMADDUBSW,
	X86_INS_PMADDWD,
	X86_INS_PFADD,
	X86_INS_VADDPD,
	X86_INS_VADDPS,
	X86_INS_VADDSD,
	X86_INS_VADDSS,
//	X86_INS_VADDSUBPD,
//	X86_INS_VADDSUBPS,
	X86_INS_VFMADD132PD,
	X86_INS_VFMADD132PS,
	X86_INS_VFMADDPD,
	X86_INS_VFMADD213PD,
	X86_INS_VFMADD231PD,
	X86_INS_VFMADDPS,
	X86_INS_VFMADD213PS,
	X86_INS_VFMADD231PS,
	X86_INS_VFMADDSD,
	X86_INS_VFMADD213SD,
	X86_INS_VFMADD132SD,
	X86_INS_VFMADD231SD,
	X86_INS_VFMADDSS,
	X86_INS_VFMADD213SS,
	X86_INS_VFMADD132SS,
	X86_INS_VFMADD231SS,
//	X86_INS_VFMADDSUB132PD,
//	X86_INS_VFMADDSUB132PS,
//	X86_INS_VFMADDSUBPD,x86_vector
//	X86_INS_VFMADDSUB213PD,
//	X86_INS_VFMADDSUB231PD,
//	X86_INS_VFMADDSUBPS,
//	X86_INS_VFMADDSUB213PS,
//	X86_INS_VFMADDSUB231PS,
	X86_INS_VFNMADD132PD,
	X86_INS_VFNMADD132PS,
	X86_INS_VFNMADDPD,
	X86_INS_VFNMADD213PD,
	X86_INS_VFNMADD231PD,
	X86_INS_VFNMADDPS,
	X86_INS_VFNMADD213PS,
	X86_INS_VFNMADD231PS,
	X86_INS_VFNMADDSD,
	X86_INS_VFNMADD213SD,
	X86_INS_VFNMADD132SD,
	X86_INS_VFNMADD231SD,
	X86_INS_VFNMADDSS,
	X86_INS_VFNMADD213SS,
	X86_INS_VFNMADD132SS,
	X86_INS_VFNMADD231SS,
	X86_INS_VHADDPD,
	X86_INS_VHADDPS,
	X86_INS_VPADDB,
	X86_INS_VPADDD,
	X86_INS_VPADDQ,
	X86_INS_VPADDSB,
	X86_INS_VPADDSW,
	X86_INS_VPADDUSB,
	X86_INS_VPADDUSW,
	X86_INS_VPADDW,
	X86_INS_VPHADDBD,
	X86_INS_VPHADDBQ,
	X86_INS_VPHADDBW,
	X86_INS_VPHADDDQ,
	X86_INS_VPHADDD,
	X86_INS_VPHADDSW,
	X86_INS_VPHADDUBD,
	X86_INS_VPHADDUBQ,
	X86_INS_VPHADDUBW,
	X86_INS_VPHADDUDQ,
	X86_INS_VPHADDUWD,
	X86_INS_VPHADDUWQ,
	X86_INS_VPHADDWD,
	X86_INS_VPHADDWQ,
	X86_INS_VPHADDW,
	X86_INS_VPMADDWD,
};

x86_insn x86_sub_insn[] = 
{
	X86_INS_HSUBPD,
	X86_INS_HSUBPS,
	X86_INS_SUB,
	X86_INS_PHSUBD,
	X86_INS_PHSUBSW,
	X86_INS_PHSUBW,
	X86_INS_PSUBB,
	X86_INS_PSUBD,
	X86_INS_PSUBQ,
	X86_INS_PSUBSB,
	X86_INS_PSUBSW,
	X86_INS_PSUBUSB,
	X86_INS_PSUBUSW,
	X86_INS_PSUBW,
	X86_INS_PFSUBR,
	X86_INS_PFSUB,
	X86_INS_SUBPD,
	X86_INS_SUBPS,
	X86_INS_FSUBR,
	X86_INS_FISUBR,
	X86_INS_FSUBRP,
	X86_INS_SUBSD,
	X86_INS_SUBSS,
	X86_INS_FSUB,
	X86_INS_FISUB,
	X86_INS_FSUBP,
	X86_INS_VFMSUB132PD,
	X86_INS_VFMSUB132PS,
	X86_INS_VFMSUBADD132PD,
	X86_INS_VFMSUBADD132PS,
	X86_INS_VFMSUBADDPD,
	X86_INS_VFMSUBADD213PD,
	X86_INS_VFMSUBADD231PD,
	X86_INS_VFMSUBADDPS,
	X86_INS_VFMSUBADD213PS,
	X86_INS_VFMSUBADD231PS,
	X86_INS_VFMSUBPD,
	X86_INS_VFMSUB213PD,
	X86_INS_VFMSUB231PD,
	X86_INS_VFMSUBPS,
	X86_INS_VFMSUB213PS,
	X86_INS_VFMSUB231PS,
	X86_INS_VFMSUBSD,
	X86_INS_VFMSUB213SD,
	X86_INS_VFMSUB132SD,
	X86_INS_VFMSUB231SD,
	X86_INS_VFMSUBSS,
	X86_INS_VFMSUB213SS,
	X86_INS_VFMSUB132SS,
	X86_INS_VFMSUB231SS,
	X86_INS_VFNMSUB132PD,
	X86_INS_VFNMSUB132PS,
	X86_INS_VFNMSUBPD,
	X86_INS_VFNMSUB213PD,
	X86_INS_VFNMSUB231PD,
	X86_INS_VFNMSUBPS,
	X86_INS_VFNMSUB213PS,
	X86_INS_VFNMSUB231PS,
	X86_INS_VFNMSUBSD,
	X86_INS_VFNMSUB213SD,
	X86_INS_VFNMSUB132SD,
	X86_INS_VFNMSUB231SD,
	X86_INS_VFNMSUBSS,
	X86_INS_VFNMSUB213SS,
	X86_INS_VFNMSUB132SS,
	X86_INS_VFNMSUB231SS,
	X86_INS_VHSUBPD,
	X86_INS_VHSUBPS,
	X86_INS_VPHSUBBW,
	X86_INS_VPHSUBDQ,
	X86_INS_VPHSUBD,
	X86_INS_VPHSUBSW,
	X86_INS_VPHSUBWD,
	X86_INS_VPHSUBW,
	X86_INS_VPSUBB,
	X86_INS_VPSUBD,
	X86_INS_VPSUBQ,
	X86_INS_VPSUBSB,
	X86_INS_VPSUBSW,
	X86_INS_VPSUBUSB,
	X86_INS_VPSUBUSW,
	X86_INS_VPSUBW,
	X86_INS_VSUBPD,
	X86_INS_VSUBPS,
	X86_INS_VSUBSD,
	X86_INS_VSUBSS,
};

x86_insn x86_mul_insn[] = 
{
	X86_INS_DIVPD,
};	

x86_insn x86_div_insn[] = 
{
	X86_INS_DIV,
	X86_INS_DIVPD,
	X86_INS_DIVPS,
	X86_INS_FDIVR,
	X86_INS_FIDIVR,
	X86_INS_FDIVRP,
	X86_INS_DIVSD,
	X86_INS_DIVSS,
	X86_INS_FDIV,
	X86_INS_FIDIV,
	X86_INS_FDIVP,
	X86_INS_IDIV,
	X86_INS_VDIVPD,
	X86_INS_VDIVPS,
	X86_INS_VDIVSD,
	X86_INS_VDIVSS,
};

x86_insn x86_logical_insn[] = 
{
	//AND
	X86_INS_AND,
	X86_INS_ANDN,
	X86_INS_ANDNPD,
	X86_INS_ANDNPS,
	X86_INS_ANDPD,
	X86_INS_ANDPS,
	X86_INS_KANDB,
	X86_INS_KANDD,
	X86_INS_KANDNB,
	X86_INS_KANDND,
	X86_INS_KANDNQ,
	X86_INS_KANDNW,
	X86_INS_KANDQ,
	X86_INS_KANDW,
	X86_INS_PANDN,
	X86_INS_PAND,
	X86_INS_VANDNPD,
	X86_INS_VANDNPS,
	X86_INS_VANDPD,
	X86_INS_VANDPS,
	X86_INS_VPANDD,
	X86_INS_VPANDND,
	X86_INS_VPANDNQ,
	X86_INS_VPANDN,
	X86_INS_VPANDQ,
	X86_INS_VPAND,

	//OR

};
x86_insn x86_fma_insn[] = 
{
	X86_INS_DIVPD,
};	
x86_insn x86_rec_insn[] = 
{
	X86_INS_DIVPD,
};	
x86_insn x86_sqrt_insn[] = 
{
	X86_INS_DIVPD,
};	
x86_insn x86_sin_insn[] = 
{
	X86_INS_DIVPD,
};	
x86_insn x86_cos_insn[] = 
{
	X86_INS_DIVPD,
};	
x86_insn x86_tan_insn[] = 
{
	X86_INS_DIVPD,
};	
x86_insn x86_sincos_insn[] = 
{
	X86_INS_DIVPD,
};	
x86_insn x86_atan_insn[] = 
{
	X86_INS_DIVPD,
};	
x86_insn x86_move_insn[] = 
{
	X86_INS_DIVPD,
};	
x86_insn x86_controlflow_insn[] = 
{
	X86_INS_DIVPD,
};	


id_ins_type getX86InsType(cs_insn *ins){
	
	
	if (ins->detail == NULL)
		return TYPE_NOP;

	unsigned int i;
	
	
	
	for(i = 0; i < ins->detail->groups_count; i++){
		switch(ins->detail->groups[i]){
			default: break;
			
			case CS_GRP_RET:
			case CS_GRP_CALL:
			case CS_GRP_JUMP:
			case CS_GRP_INT:
			case CS_GRP_IRET:
				return TYPE_CONTROLFLOW;
		}
	}
	
	for (i = 0; i < sizeof(x86_add_insn)/sizeof(x86_add_insn); i++) {
		if(x86_add_insn[i] == ins->id)
			return TYPE_ADD;
	}
	
//	
	for (i = 0; i < sizeof(x86_sub_insn)/sizeof(x86_sub_insn[0]); i++) {
		if(x86_sub_insn[i] == ins->id)
			return TYPE_SUB;
	}
	
	for (i = 0; i < sizeof(x86_mul_insn)/sizeof(x86_mul_insn[0]); i++) {
		if(x86_mul_insn[i] == ins->id)
			return TYPE_MUL;
	}
	
	
	for (i = 0; i < sizeof(x86_div_insn)/sizeof(x86_div_insn[0]); i++) {
		if(x86_div_insn[i] == ins->id)
			return TYPE_DIV;
	}
	
	
	for (i = 0; i < sizeof(x86_logical_insn)/sizeof(x86_logical_insn[0]); i++) {
		if(x86_logical_insn[i] == ins->id)
			return TYPE_LOGICAL;
	}
	
	
	for (i = 0; i < sizeof(x86_fma_insn)/sizeof(x86_fma_insn[0]); i++) {
		if(x86_fma_insn[i] == ins->id)
			return TYPE_FMA;
	}
	
	
	for (i = 0; i < sizeof(x86_rec_insn)/sizeof(x86_rec_insn[0]); i++) {
		if(x86_rec_insn[i] == ins->id)
			return TYPE_REC;
	}
	
	
	for (i = 0; i < sizeof(x86_sqrt_insn)/sizeof(x86_sqrt_insn[0]); i++) {
		if(x86_sqrt_insn[i] == ins->id)
			return TYPE_SQRT;
	}
	
	
	for (i = 0; i < sizeof(x86_sin_insn)/sizeof(x86_sin_insn[0]); i++) {
		if(x86_sin_insn[i] == ins->id)
			return TYPE_SIN;
	}
	
	
	for (i = 0; i < sizeof(x86_cos_insn)/sizeof(x86_cos_insn[0]); i++) {
		if(x86_cos_insn[i] == ins->id)
			return TYPE_COS;
	}
	
	
	for (i = 0; i < sizeof(x86_tan_insn)/sizeof(x86_tan_insn[0]); i++) {
		if(x86_tan_insn[i] == ins->id)
			return TYPE_TAN;
	}
	
	
	for (i = 0; i < sizeof(x86_sincos_insn)/sizeof(x86_sincos_insn[0]); i++) {
		if(x86_sincos_insn[i] == ins->id)
			return TYPE_SINCOS;
	}
	
	
	for (i = 0; i < sizeof(x86_atan_insn)/sizeof(x86_atan_insn[0]); i++) {
		if(x86_atan_insn[i] == ins->id)
			return TYPE_ATAN;
	}
	
	
	for (i = 0; i < sizeof(x86_move_insn)/sizeof(x86_move_insn[0]); i++) {
		if(x86_move_insn[i] == ins->id)
			return TYPE_MOVE;
	}
	
	
	for (i = 0; i < sizeof(x86_controlflow_insn)/sizeof(x86_controlflow_insn[0]); i++) {
		if(x86_controlflow_insn[i] == ins->id)
			return TYPE_CONTROLFLOW;
	}
	
	
	return TYPE_OTHER;
}




id_op_type getX86OpType(cs_x86_op* op){
	switch((int)op->type) {
			case X86_OP_REG:
				return OP_REG;
				break;
			case X86_OP_IMM:
				return OP_IMM;
				break;
			case X86_OP_MEM:
				return OP_MEM;
				break;
			default:
				return OP_OTHER;
				break;
		}
}

id_register_type getX86RegType(cs_x86_op* op){
	unsigned int i;
	if(getX86OpType(op)==OP_IMM || getX86OpType(op)==OP_MEM || getX86OpType(op)==OP_OTHER) return REG_OTHER;
	
	for (i = 0; i < sizeof(x86_gpr)/sizeof(x86_gpr[0]); i++) {
		if(x86_gpr[i] == op->reg)
			return REG_GPR;
	}
	for (i = 0; i < sizeof(x86_float)/sizeof(x86_float[0]); i++) {
		if(x86_gpr[i] == op->reg)
			return REG_FLOAT;
	}
	for (i = 0; i < sizeof(x86_vector)/sizeof(x86_vector[0]); i++) {
		if(x86_gpr[i] == op->reg)
			return REG_VECTOR;
	}
	return REG_OTHER;
}

void getX86Operands(cs_insn *ins, id_ins_operand** ops, uint8_t* op_count){
	cs_x86 *x86; 
	
	x86 = &(ins->detail->x86);
	*op_count = x86->op_count;
	(*ops) = (id_ins_operand*) malloc(sizeof(id_ins_operand) * x86->op_count);
	for(int i = 0; i<x86->op_count; i++){
//		TODO: get datatype and element_width
		(*ops)[i]=(id_ins_operand) {	DATA_SIGNED, 				//set operand data type	
						0, 			//set number of elements
						x86->operands[i].size, 					//set element width? -> vector
						x86->operands[i].access, 		//acess: READ,WRITE,READ_WRITE
						getX86OpType(&x86->operands[i]), 	//operand type: REG,MEM,IMM 
						getX86RegType(&x86->operands[i])};	//operand register type: GPR,FLOAT,VECTOR,INVALID
	}
			
}

unsigned int getX86Prefix(cs_insn *ins){
	uint32_t flags = 0;
	cs_x86 *x86; 	
	
	x86 = &(ins->detail->x86);
	for(int i = 0; i<sizeof(x86->prefix)/sizeof(uint8_t); i++){
		
		uint32_t shift = (x86->prefix[i] << (8 * i));
		uint32_t mask = 0xff << shift;
		flags = (~mask & flags) | shift;
	}
			
	return flags;
}


#ifdef __cplusplus
}
#endif
#endif
