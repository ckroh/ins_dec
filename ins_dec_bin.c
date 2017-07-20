

#ifdef __cplusplus
extern "C" {
#endif
#include "ins_dec.h"
#define CODE "\x05\x78\x56\x00\x00"
#define BINCODE "\x48\x8d\x14\xc5\x00"
int main()
{
	int i;
	
	ins_decAPI *id;
	id = ins_dec_new();
	print_string_hex("Decode Instructions: ", BINCODE, sizeof(BINCODE)-1);
	
	id_setPlatform(id, "X86_64");
	id_decodeInstruction(id, BINCODE);
	
	printf("Decoded %d Instructions: \n", id->id_insn_count);
	for(i=0; i<id->id_insn_count; i++){
/*		printf("%s\n", id->id_insn[i].code);*/
	}
	return 0;
}


#ifdef __cplusplus
}
#endif
