NAME = test_cgi

SRCS = cgi_handler.cpp tests_cgi.cpp
INCS = -Iinc

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
