
#include <stdio.h>
#include <stdlib.h>

#include <capstone/platform.h>
#include <capstone/capstone.h>

#ifndef ins_dec_C
#define ins_dec_C


#ifdef __cplusplus
extern "C" {
#endif
#include "ins_dec.h"
#include "x86.h"
#include "arm64.h"

static csh handle;

ins_decAPI* ins_dec_new(){
	ins_decAPI *id = (ins_decAPI*) malloc(sizeof(ins_decAPI));
	id->functionPtrs = (id_arch_functions*) malloc(sizeof(id_arch_functions));
	return id;
} 

void id_setPlatform(ins_decAPI* id, const char* desc){
	
	if(strcmp(desc, "X86_64") == 0){
		id->platform= x86_platform;
		id->functionPtrs->getOperandsPtr=&getX86Operands;
		id->functionPtrs->getPrefixPtr=&getX86Prefix;
		id->functionPtrs->getInsTypePtr=&getX86InsType;
	}
	
	if(strcmp(desc, "ARM64") == 0){
		id->platform = arm64_platform;
		id->functionPtrs->getOperandsPtr=&getARM64Operands;
		id->functionPtrs->getPrefixPtr=&getARM64Prefix;
		id->functionPtrs->getInsTypePtr=&getARM64InsType;
	}
	cs_err err = cs_open(id->platform.arch, id->platform.mode, &handle);
	if (err) {
		printf("Failed on cs_open() with error returned: %u\n", err);
		abort();
	}
	cs_option(handle, CS_OPT_DETAIL, CS_OPT_ON);
}

void id_decodeInstruction(ins_decAPI* id, char *code){
	size_t size = sizeof(code);
	size_t count;
	uint64_t address = 0x0;
	if(id->id_insn_count>0) free(id->id_insn);
	
	
		
	cs_insn *insn;
/*	printf("code has %lu bytes\n", size);*/
	count = cs_disasm(handle, code, sizeof(code)-1, address, 0, &insn);
	id->id_insn_count = count;

	if (count) {
		id->id_insn = (id_ins_dec*) malloc(count*sizeof(id_ins_dec));
		size_t j;
		for (j = 0; j < count; j++) {
		printf("insn: %s %s\n",  insn[j].mnemonic,  insn[j].op_str);
			strcpy(id->id_insn[j].mnemonic, insn[j].mnemonic);
			strcpy(id->id_insn[j].op_str, insn[j].op_str);
			id->id_insn[j].ins_type = (*(id->functionPtrs->getInsTypePtr))(&(insn[j]));
			id->id_insn[j].flags = (*(id->functionPtrs->getPrefixPtr))(&(insn[j]));
			(*(id->functionPtrs->getOperandsPtr))(	&(insn[j]), 
								&(id->id_insn[j].ops), 
								&(id->id_insn[j].op_count));
	
		}
		print_string_hex("CODE: ", code, size);
		// free memory allocated by cs_disasm()
		cs_free(insn, count);
	} else {
		id->id_insn = (id_ins_dec*) malloc(sizeof(id_ins_dec));
		id->id_insn_count = 1;
		strcpy(id->id_insn[0].mnemonic, "fail");
		strcpy(id->id_insn[0].op_str, "fail");
		printf("****************\n");
		printf("Platform: %s\n", id->platform.comment);
		printf("ERROR: Failed to disasm given code!\n");
		print_string_hex("CODE: \t\t", code, sizeof(code));

	}
}

void ins_dec_free(ins_decAPI* id){
	
	cs_close(&handle);
	free(id);
}

void print_string_hex(char *comment, unsigned char *str, size_t len)
{
	unsigned char *c;

	printf("%s", comment);
	for (c = str; c < str + len; c++) {
		printf("0x%02x ", *c & 0xff);
	}

	printf("\n");
}

int bin2str(const char *in, int len, char *out) {
	int i, idx;
	char tmp[5];
	if (len < 0)
		return 0;
	for (idx = i = 0; i < len; i++, idx += 2)  {
		snprintf (tmp, sizeof (tmp), "%02x", in[i]);
		memcpy (out+idx, tmp, 2);
	}
	out[idx] = 0;
	return len;
}

#ifdef __cplusplus
}
#endif

#endif
