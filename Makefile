.PHONY = clean
clean:
	@echo "Remove all .o, .out, .exe files and clear screen"
	@rm -f *.o *.out *.elf *.exe
	@clear
# Add your recipe for each C program
#outputfile.out:outputfile1.c outputfile2.c outputfile1.h outputfile2.h
single_list:
	@echo "Building..."
	@gcc single_list.c -o single_list.exe
