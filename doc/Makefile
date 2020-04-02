all:
	doxygen Doxyfile
	@make -C latex
	mv latex/refman.pdf doc_OOP_arcade_2019.pdf
	$(MAKE) clean

clean:
	rm -rf latex
fclean:
	rm -f doc_OOP_arcade_2019.pdf