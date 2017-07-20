
#include <capstone/platform.h>
#include <capstone/capstone.h>
#ifndef ins_dec_H
#define ins_dec_H
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef enum id_ins_type {
	// 
	TYPE_ADD,
	TYPE_SUB,
	TYPE_MUL,
	TYPE_DIV,		//ARM_GRP_DIVIDE
	TYPE_LOGICAL,
	TYPE_FMA,
	TYPE_REC,
	TYPE_SQRT,
	TYPE_SIN,
	TYPE_COS,
	TYPE_TAN,
	TYPE_SINCOS,
	TYPE_ATAN,
	TYPE_MOVE, 
	TYPE_CONTROLFLOW, //(CALL, RET, JUMP, SYSCALL) = CS_GRP_RET, CS_GRP_CALL, CS_GRP_JUMP, CS_GRP_INT, CS_GRP_IRET
	TYPE_NOP, 
	TYPE_OTHER // CS_GRP_PRIVILEGE
} id_ins_type;

typedef enum id_datatype {
	DATA_SIGNED,
	DATA_UNSIGNED,
	DATA_FLOAT,
	DATA_DECIMAL,
} id_datatype;

typedef enum id_register_type{
	REG_GPR,
	REG_FLOAT,
	REG_VECTOR,
	REG_OTHER,
} id_register_type;

typedef enum id_op_type {
	OP_OTHER = 0, // = CS_OP_INVALID (Uninitialized).
	OP_REG, // = CS_OP_REG (Register operand).
	OP_IMM, // = CS_OP_IMM (Immediate operand).
	OP_MEM, // = CS_OP_MEM (Memory operand).
} id_op_type;

typedef struct id_ins_operand{
	id_datatype 		datatype;
	unsigned int 		number_elements : 1; 
	unsigned int 		element_width : 4; //in bytes
	unsigned int 		load_store : 2;
	id_op_type 		type;
	id_register_type 	register_type;
	
} id_ins_operand;

typedef struct id_ins_dec{
	char 			mnemonic[160];
	char 			op_str[160];
	id_ins_type 		ins_type;
	unsigned int 		flags : 4;
	uint8_t 		op_count;
	id_ins_operand 		*ops; //capstone uses space for up to 32 registers/operands
	

} id_ins_dec;


typedef struct id_arch_functions{
	void (*getOperandsPtr)(cs_insn*, id_ins_operand**, uint8_t*);
	unsigned int (*getPrefixPtr)(cs_insn*);
	id_ins_type (*getInsTypePtr)(cs_insn*);
	
} id_arch_functions;




typedef struct id_platform {
	cs_arch 		arch;
	cs_mode 		mode;
	//unsigned char *code;
//	size_t 			size;
	const char 		*comment;
	cs_opt_type 		opt_type;
	cs_opt_value 		opt_value;
} id_platform;


typedef struct ins_decAPI{
	id_arch_functions 	*functionPtrs;
	id_ins_dec 		*id_insn;
	unsigned int 		id_insn_count;
	id_platform 		platform;
} ins_decAPI;

ins_decAPI* ins_dec_new();
void ins_dec_free(ins_decAPI* id);
void id_setPlatform(ins_decAPI* id, const char* desc);
void id_decodeInstruction(ins_decAPI* id, char *code);
int bin2str(const char *in, int len, char *out);
void print_string_hex(char *comment, unsigned char *str, size_t len);

#ifdef __cplusplus
}
#endif

#endif


