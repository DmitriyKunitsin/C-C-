GCC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra -pedantic
PROGRAMM = programm

hello : clean
	@$(GCC) $(CFLAGS) hello.cpp -o $(PROGRAMM)
	@./$(PROGRAMM)
	@echo "\033[36mПроект успешно собран\n\033[0m"

ref : clean
	$(GCC) $(CFLAGS) Reference.cpp -o $(PROGRAMM)
	@./$(PROGRAMM)
	@echo "\033[36mПроект успешно собран\n\033[0m"


string : clean
	@$(GCC) $(CFLAGS) string.cpp -o $(PROGRAMM)
	@./$(PROGRAMM)
	@echo "\033[36mПроект успешно собран\n\033[0m"

ptr :
	@$(GCC) $(CFLAGS) prt.cpp -o $(PROGRAMM)
	@./$(PROGRAMM)
	@echo "\033[36mПроект успешно собран\n\033[0m"

clean :
	@rm -rf *.o
	@rm -rf $(PROGRAMM)
	@echo "\033[36mФайлы успешно удалены\n\033[0m"