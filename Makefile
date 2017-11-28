# capstone library name (without prefix 'lib' and suffix '.so')
LIBNAME = capstone

ins_dec_bin: ins_dec_bin.o ins_dec.o
	${CC} ins_dec_bin.o ins_dec.o -O3 -Wall  -l$(LIBNAME) -o $@


#ins_dec: ins_dec.o
#	${CC} $< -O3 -Wall -l$(LIBNAME) -o $@


libinsdec.so: ins_dec.o
	${CC} -shared $< -O3 -Wall -l$(LIBNAME) -o $@


ins_dec_bin.o: ins_dec_bin.c
	${CC} -c $< -fPIC -o $@

%.o: %.c
	${CC} -fPIC -c $< -o $@
	
	
clean:
	rm -f ins_dec
	rm -f ins_dec_bin
	rm -f ./*.o
	rm -f ./*.so
	rm -f *.bak *~  # emacs erzeugt *~ als Sicherheitskopie

