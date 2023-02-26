NAME = cpps

SRCS = $(wildcard *.cpp)

C++ = g++

OBJS = $(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(C++) $(OBJS) -o $(NAME)

clean:
	rm -f ./*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
