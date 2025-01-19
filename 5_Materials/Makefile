CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++11 -g

IDIR = includes/
IFLAGS = -I$(IDIR).

NAME = materials
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

RES = result.ppm

all: $(NAME) $(RES)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(IFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(IFLAGS) -c $<

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
