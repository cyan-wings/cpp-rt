CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -g
IFLAGS = -I.

NAME = ppm_image
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

RES = result.ppm

all: $(NAME) $(RES)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

$(RES): $(NAME)
	./$(NAME) > $(RES)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(RES)

re: fclean all

run: $(RES)
	open $(RES)

.PHONY: all clean fclean run
