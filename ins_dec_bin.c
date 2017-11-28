

#ifdef __cplusplus
extern "C" {
#endif
#include "ins_dec.h"
/*#define CODE "\x8f\xe8\x60\xcd\xe2\x07"*/
#define CODE "\xF3\x0F\xE6\xcd\xe2\x07"
int main()
{
	int i,t;
	
	ins_decAPI *id;
	id = ins_dec_new();
	print_string_hex("Decode Instructions: ", CODE, sizeof(CODE)-1);
	printf("code_size %lu\n",sizeof(CODE)-1);
	
	id_setPlatform(id, "X86_64");
	id_decodeInstruction(id, CODE,sizeof(CODE)-1);
	for(t=0; t<id->id_insn_count; t++){
		printf("insn: %s %s\n",  id->id_insn[t].mnemonic,  id->id_insn[t].op_str);
		printf("Instruction type: %d \n", id->id_insn[t].ins_type);
		printf("Instruction prefix: %d \n", id->id_insn[t].prefix);
		printf("Instruction number of operands: %d \n", id->id_insn[t].op_count);
		for(i=0; i<id->id_insn[t].op_count; i++){
			printf("Operand: %d \n", i);
			printf("\tOperand elements: %d \n", id->id_insn[t].ops[i].number_elements);
			printf("\tOperand element width: %d bytes\n", id->id_insn[t].ops[i].element_width);
			printf("\tOperand load store: %d\n", id->id_insn[t].ops[i].load_store);
			printf("\tOperand type: %d\n", id->id_insn[t].ops[i].type);
			printf("\tOperand reg type: %d\n", id->id_insn[t].ops[i].register_type);
		}
	}
	return 0;
}


#ifdef __cplusplus
}
#endif
