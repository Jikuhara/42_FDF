# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 12:55:33 by kei2003730        #+#    #+#              #
#    Updated: 2025/07/01 13:32:51 by kei2003730       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------
#> variables
#-----------------------------------------------------------------------------

NAME		:= map_parse.a

#─ compile config ────────────────────────────────────────────────────────────

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I. -I../../includes -I../../libft
AR			:= ar
ARFLAGS		:= rcs

#─ directory name ────────────────────────────────────────────────────────────

SRCDIR		:= src
OBJDIR		:= obj

#─ sources & objects ─────────────────────────────────────────────────────────

SRCS		:= src/00_main.c \
		   src/01_get_map_dimentions.c \
		   src/02_allocate_map_memory.c \
		   src/03_fill_map_data.c \
		   src/99_utils.c

OBJS		:= $(SRCS:src/%.c=$(OBJDIR)/%.o)

#─ colors ────────────────────────────────────────────────────────────────────

GREEN		:= \033[32m
YELLOW		:= \033[33m
CYAN		:= \033[36m
WHITE		:= \033[37m
RESET		:= \033[0m
BOLD		:= \033[1m

#-----------------------------------------------------------------------------
#▸ rules
#-----------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	@echo "$(GREEN)$(BOLD)========================================="
	@echo "    $(NAME) created successfully!"
	@echo "=========================================$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "Compiled ✅ $(WHITE)$(BOLD) $< $(RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJDIR)
	@echo "$(CYAN)Object files cleaned.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME) removed.$(RESET)"

re: fclean all

# ノルムチェック
norm:
	@echo "$(CYAN)$(BOLD)========================================="
	@echo "    Checking 42 Norm for map_parse..."
	@echo "=========================================$(RESET)"
	@norminette $(SRCS) map_parse.h
	@echo "$(GREEN)$(BOLD)Norm check completed!$(RESET)"

# テスト実行
test: $(NAME) norm test-valgrind
	@echo "$(YELLOW)$(BOLD)========================================="
	@echo "    Building and running tests..."
	@echo "=========================================$(RESET)"
	@$(CC) $(CFLAGS) -o test_map_parse test_map_parse.c $(NAME)
	@echo "$(GREEN)Test executable created$(RESET)"
	@echo "$(CYAN)Running tests...$(RESET)"
	@./test_map_parse
	@echo "$(GREEN)$(BOLD)Tests completed!$(RESET)"

# テストファイルのクリーンアップ
test-clean:
	@rm -f test_map_parse *.fdf
	@echo "$(CYAN)Test files cleaned.$(RESET)"

# メモリリークチェック（valgrind使用）
test-valgrind: $(NAME)
	@echo "$(YELLOW)$(BOLD)========================================="
	@echo "    Running tests with Valgrind..."
	@echo "=========================================$(RESET)"
	@$(CC) $(CFLAGS) -g -o test_map_parse test_map_parse.c $(NAME)
	@echo "$(GREEN)Test executable created with debug info$(RESET)"
	@echo "$(CYAN)Running Valgrind memory check...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./test_map_parse
	@echo "$(GREEN)$(BOLD)Valgrind check completed!$(RESET)"

# パフォーマンステスト
test-performance: $(NAME)
	@echo "$(YELLOW)$(BOLD)========================================="
	@echo "    Running performance tests..."
	@echo "=========================================$(RESET)"
	@$(CC) $(CFLAGS) -O3 -o test_map_parse_perf test_map_parse.c $(NAME)
	@echo "$(GREEN)Performance test executable created$(RESET)"
	@echo "$(CYAN)Running performance tests...$(RESET)"
	@time ./test_map_parse_perf > /dev/null
	@rm -f test_map_parse_perf
	@echo "$(GREEN)$(BOLD)Performance tests completed!$(RESET)"

# ヘッダーファイルをincludesディレクトリにコピー
install-header:
	@cp map_parse.h ../../includes/
	@echo "$(GREEN)$(BOLD)Header file installed to ../../includes/$(RESET)"

# 使用例の表示
usage:
	@echo "$(CYAN)$(BOLD)========================================="
	@echo "    map_parse library usage:"
	@echo "=========================================$(RESET)"
	@echo "1. Include the header: #include \"map_parse.h\""
	@echo "2. Link the library: -L. -lmap_parse"
	@echo "3. Main function: parse_map(filename, &map, &rows, &cols)"
	@echo "4. Clean up: free_map(map, rows)"
	@echo ""
	@echo "$(YELLOW)Available make targets:$(RESET)"
	@echo "- make          : Build the library"
	@echo "- make test     : Run basic test suite"
	@echo "- make test-valgrind : Run tests with memory leak detection"
	@echo "- make test-performance : Run performance benchmarks"
	@echo "- make norm     : Check 42 Norm compliance"
	@echo "- make clean    : Remove object files"
	@echo "- make fclean   : Remove all build files"
	@echo ""
	@echo "$(YELLOW)External dependencies needed:$(RESET)"
	@echo "- get_next_line(int fd)"
	@echo "- ft_split(char const *s, char c)"
	@echo "- ft_free_split(char **split)"
	@echo "- ft_atoi(const char *str)"

.PHONY: all clean fclean re norm test test-clean test-valgrind test-performance install-header usage

