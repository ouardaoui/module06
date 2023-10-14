cc = c++
flags = -Wall -Wextra -Werror 
src = main.cpp Base.cpp  
obj = ${src:.cpp=.o}
name = exe 

all: ${name}

%.o: %.cpp
	${cc} ${flags} -c -o $@ $<

${name}: ${obj}
	${cc} ${flags} ${obj} -o ${name}

clean:
	rm -rf ${obj}

fclean: clean
	rm -rf ${name}

run:
	make re && ./converter

re: fclean all

.PHONY: all clean fclean run re
