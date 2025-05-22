# # ============== COLORS =================
# MAKEFLAGS += --silent
# RED=\033[1;31m
# GREEN=\033[1;32m
# NC=\033[0m

# # ============== COMPILER/FLAGS ============
# CXX = c++
# CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
# RM = rm -rf

# # ============== FILES ====================
# NAME = webserv
# SRC_DIR = SRC
# CGI = cgi
# INC_DIR = INC/utils

# SRCS = main.cpp \
# 		$(SRC_DIR)/Server.cpp \
# 		$(SRC_DIR)/Socket.cpp \
# 		$(SRC_DIR)/Location.cpp \
# 		$(SRC_DIR)/ServerManager.cpp \
# 		$(SRC_DIR)/HTTPRequest_test.cpp \
# 		$(SRC_DIR)/Content_test.cpp \
# 		$(SRC_DIR)/Client.cpp \
# 		$(SRC_DIR)/HTTPResponse.cpp \
# 		$(SRC_DIR)/Utils.cpp \
# 		$(CGI)/receiveRequest.cpp \
# 		$(CGI)/prepEnv.cpp \
# 		$(CGI)/executeScript.cpp \
# 		$(CGI)/returnOutput.cpp \
# 		#$(CGI)/CgiHandler.cpp \

# OBJS = $(SRCS:.cpp=.o)

# # ============== RULES ====================
# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CXX) $(CXXFLAGS) $(OBJS) -I$(INC_DIR) -o $(NAME)
# 	@echo "[$(GREEN)WEBSERV$(NC)] Build complete!"

# %.o: %.cpp
# 	@echo "[$(GREEN)WEBSERV$(NC)] Compiling...$<"
# 	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# # ============== CLEAN ====================
# clean:
# 	@echo "[$(RED)WEBSERV$(NC)] Cleaning object files..."
# 	@$(RM) $(OBJS)

# fclean: clean
# 	@echo "[$(RED)WEBSERV$(NC)] Cleaning executable..."
# 	@$(RM) $(NAME)

# re: fclean all

# leaks:
# 	valgrind --leak-check=full ./$(NAME)

# .PHONY: all clean fclean re
