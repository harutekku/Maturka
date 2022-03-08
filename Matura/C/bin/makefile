OUTPUTFILE = c-matura.a # Change for Windows

../$(OUTPUTFILE): Cipher.o Numeric.o Search.o Sort.o Text.o Utilities.o
	ar ru $@ $^
	ar -s $@
