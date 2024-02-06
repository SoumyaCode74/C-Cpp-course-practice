.PHONY = clean
clean:
	@echo "Remove all .o, .out, .exe files and clear screen"
	@rm -f *.o *.out *.elf *.exe
	@clear
# Add your recipe for each C program
#outputfile.out:outputfile1.c outputfile2.c outputfile1.h outputfile2.h
single_list:
	@echo "Building single_list.c"
	@gcc src/single_list.c -I"inc/" -o single_list.exe
sorted_linked_list:
	@echo "Building sorted_linked_list.c"
	@gcc src/sorted_linked_list.c -I"inc/" -o sorted_linked_list.exe
struct_rationals:
	@echo "Building struct_rationals.c"
	@gcc src/Struct_Rationales.c -I"inc/" -o Struct_Rationales.exe
set_unset:
	@echo "Building count_set_unset.c"
	@gcc src/count_set_unset.c -I"inc/" -o Count_Set_Unset_Bits.exe
bytes_and_nibbles:
	@echo "Building extract_bytes_and_nibbles.c"
	@gcc src/extract_bytes_and_nibbles.c -o Extract_bytes_and_nibbles.exe
first_order_filter:
	@echo "Building first_order_filter.c"
	@gcc src/first_order_filter.c -o First-Order-Low-Pass-Filter.exe
count_set_unset_recursive:
	@echo "Building count_set_unset_recursive.c"
	@gcc src/count_set_unset_recursive.c

