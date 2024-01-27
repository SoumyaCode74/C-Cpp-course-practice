.PHONY = clean
clean:
	@echo "Remove all .o, .out, .exe files and clear screen"
	@rm -f *.o *.out *.elf *.exe
	@clear
# Add your recipe for each C program
#outputfile.out:outputfile1.c outputfile2.c outputfile1.h outputfile2.h
single_list:
	@echo "Building single_list.c"
	@gcc single_list.c -o single_list.exe
sorted_linked_list:
	@echo "Building sorted_linked_list.c"
	@gcc sorted_linked_list.c -o sorted_linked_list.exe
