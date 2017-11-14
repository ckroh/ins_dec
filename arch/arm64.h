
#ifndef ARM64_H
#define ARM64_H

#ifdef __cplusplus
extern "C" {
#endif

#include <capstone/platform.h>
#include <capstone/capstone.h>

#include "../ins_dec.h"

id_platform arm64_platform = {CS_ARCH_ARM, CS_MODE_64, "ARM64", CS_OPT_DETAIL, CS_OPT_ON};

arm64_reg arm64_gpr[] =
{
	ARM64_REG_X29

};

arm64_reg arm64_float[] =
{
	ARM64_REG_X29

};

arm64_reg arm64_vector[] =
{
	ARM64_REG_X29

};

arm64_insn arm64_add_insn[] = 
{
	ARM64_INS_ABS
};

arm64_insn arm64_sub_insn[] = 
{
	ARM64_INS_ABS
};

arm64_insn arm64_mul_insn[] = 
{ARM64_INS_ABS
};	

arm64_insn arm64_div_insn[] = 
{
	ARM64_INS_ABS
};

arm64_insn arm64_logical_insn[] = 
{
	//AND
	ARM64_INS_ABS

	//OR

};
arm64_insn arm64_fma_insn[] = 
{ARM64_INS_ABS
};	
arm64_insn arm64_rec_insn[] = 
{ARM64_INS_ABS
};	
arm64_insn arm64_sqrt_insn[] = 
{ARM64_INS_ABS
};	
arm64_insn arm64_sin_insn[] = 
{ARM64_INS_ABS
};	
arm64_insn arm64_cos_insn[] = 
{ARM64_INS_ABS
};	
arm64_insn arm64_tan_insn[] = 
{ARM64_INS_ABS
};	
arm64_insn arm64_sincos_insn[] = 
{ARM64_INS_ABS
};	
arm64_insn arm64_atan_insn[] = 
{ARM64_INS_ABS
};	
arm64_insn arm64_move_insn[] = 
{ARM64_INS_ABS
};	
arm64_insn arm64_controlflow_insn[] = 
{ARM64_INS_ABS
};	


id_ins_type getARM64InsType(cs_insn *ins){
	
	
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
	
	for (i = 0; i < sizeof(arm64_add_insn)/sizeof(arm64_add_insn[0]); i++) {
		if(arm64_add_insn[i] == ins->id)
			return TYPE_ADD;
	}
	
//	
	for (i = 0; i < sizeof(arm64_sub_insn)/sizeof(arm64_sub_insn[0]); i++) {
		if(arm64_sub_insn[i] == ins->id)
			return TYPE_SUB;
	}
	
	for (i = 0; i < sizeof(arm64_mul_insn)/sizeof(arm64_mul_insn[0]); i++) {
		if(arm64_mul_insn[i] == ins->id)
			return TYPE_MUL;
	}
	
	
	for (i = 0; i < sizeof(arm64_div_insn)/sizeof(arm64_div_insn[0]); i++) {
		if(arm64_div_insn[i] == ins->id)
			return TYPE_DIV;
	}
	
	
	for (i = 0; i < sizeof(arm64_logical_insn)/sizeof(arm64_logical_insn[0]); i++) {
		if(arm64_logical_insn[i] == ins->id)
			return TYPE_LOGICAL;
	}
	
	
	for (i = 0; i < sizeof(arm64_fma_insn)/sizeof(arm64_fma_insn[0]); i++) {
		if(arm64_fma_insn[i] == ins->id)
			return TYPE_FMA;
	}
	
	
	for (i = 0; i < sizeof(arm64_rec_insn)/sizeof(arm64_rec_insn[0]); i++) {
		if(arm64_rec_insn[i] == ins->id)
			return TYPE_REC;
	}
	
	
	for (i = 0; i < sizeof(arm64_sqrt_insn)/sizeof(arm64_sqrt_insn[0]); i++) {
		if(arm64_sqrt_insn[i] == ins->id)
			return TYPE_SQRT;
	}
	
	
	for (i = 0; i < sizeof(arm64_sin_insn)/sizeof(arm64_sin_insn[0]); i++) {
		if(arm64_sin_insn[i] == ins->id)
			return TYPE_SIN;
	}
	
	
	for (i = 0; i < sizeof(arm64_cos_insn)/sizeof(arm64_cos_insn[0]); i++) {
		if(arm64_cos_insn[i] == ins->id)
			return TYPE_COS;
	}
	
	
	for (i = 0; i < sizeof(arm64_tan_insn)/sizeof(arm64_tan_insn[0]); i++) {
		if(arm64_tan_insn[i] == ins->id)
			return TYPE_TAN;
	}
	
	
	for (i = 0; i < sizeof(arm64_sincos_insn)/sizeof(arm64_sincos_insn[0]); i++) {
		if(arm64_sincos_insn[i] == ins->id)
			return TYPE_SINCOS;
	}
	
	
	for (i = 0; i < sizeof(arm64_atan_insn)/sizeof(arm64_atan_insn[0]); i++) {
		if(arm64_atan_insn[i] == ins->id)
			return TYPE_ATAN;
	}
	
	
	for (i = 0; i < sizeof(arm64_move_insn)/sizeof(arm64_move_insn[0]); i++) {
		if(arm64_move_insn[i] == ins->id)
			return TYPE_MOVE;
	}
	
	
	for (i = 0; i < sizeof(arm64_controlflow_insn)/sizeof(arm64_controlflow_insn[0]); i++) {
		if(arm64_controlflow_insn[i] == ins->id)
			return TYPE_CONTROLFLOW;
	}
	
	
	return TYPE_OTHER;
}




id_op_type getARM64OpType(cs_arm64_op* op){
	switch((int)op->type) {
			case ARM64_OP_REG:
				return OP_REG;
				break;
			case ARM64_OP_IMM:
				return OP_IMM;
				break;
			case ARM64_OP_MEM:
				return OP_MEM;
				break;
			default:
				return OP_OTHER;
				break;
		}
}

id_register_type getARM64RegType(cs_arm64_op* op){
	unsigned int i;
	if(getARM64OpType(op)==OP_IMM || getARM64OpType(op)==OP_MEM || getARM64OpType(op)==OP_OTHER) return REG_OTHER;
	
	for (i = 0; i < sizeof(arm64_gpr)/sizeof(arm64_gpr[0]); i++) {
		if(arm64_gpr[i] == op->reg)
			return REG_GPR;
	}
	for (i = 0; i < sizeof(arm64_float)/sizeof(arm64_float[0]); i++) {
		if(arm64_gpr[i] == op->reg)
			return REG_FLOAT;
	}
	for (i = 0; i < sizeof(arm64_vector)/sizeof(arm64_vector[0]); i++) {
		if(arm64_gpr[i] == op->reg)
			return REG_VECTOR;
	}
	return REG_OTHER;
}

void getARM64Operands(cs_insn *ins, id_ins_operand** ops, uint8_t* op_count){
	cs_arm64 *arm64; 
	
	arm64 = &(ins->detail->arm64);
	*op_count = arm64->op_count;
	(*ops) = (id_ins_operand*) malloc(sizeof(id_ins_operand) * arm64->op_count);
	for(int i = 0; i<arm64->op_count; i++){
//		TODO: get datatype and element_width
		(*ops)[i]=(id_ins_operand) {
						0, 			//set number of elements
						arm64->operands[i].vess, 					//set element width? -> vector
						arm64->operands[i].access, 		//acess: READ,WRITE,READ_WRITE
						getARM64OpType(&arm64->operands[i]), 	//operand type: REG,MEM,IMM 
						getARM64RegType(&arm64->operands[i])};	//operand register type: GPR,FLOAT,VECTOR,INVALID
	}
			
}

unsigned int getARM64Prefix(cs_insn *ins){
	uint32_t flags = 0;
//	TODO: port to arm64
//	cs_arm64 *arm64; 	
//	
//	arm64 = &(ins->detail->arm64);
//	for(int i = 0; i<sizeof(arm64->prefix)/sizeof(uint8_t); i++){
//		
//		uint32_t shift = (arm64->prefix[i] << (8 * i));
//		uint32_t mask = 0xff << shift;
//		flags = (~mask & flags) | shift;
//	}
			
	return flags;
}


#ifdef __cplusplus
}
#endif
#endif
