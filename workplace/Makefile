# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 14:37:47 by kjikuhar          #+#    #+#              #
#    Updated: 2025/07/01 16:16:04 by kei2003730       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------
#> options
#-----------------------------------------------------------------------------
BLACK	:=	\033[30m
RED		:=	\033[31m
GREEN	:=	\033[32m
YELLOW	:=	\033[33m
BLUE	:=	\033[96m
MAGENTA	:=	\033[38;5;206m
CYAN	:=	\033[36m
WHITE	:=	\033[37m
RESET	:=	\033[0m
BOLD	:=	\033[1m
DIM		:=	\033[2m
ITALIC	:=	\033[3m
UNDER	:=	\033[4m
BLINK	:=	\033[5m
REVERSE	:=	\033[7m
HIDDEN	:=	\033[8m
PINK	:=	\033[35m

#-----------------------------------------------------------------------------

#▸ variables

#-----------------------------------------------------------------------------

NAME		:=	fdf

#─ compile config ────────────────────────────────────────────────────────────

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -Iincludes -Ilibft -Isrc/01_parse_map
CCFLAGS		:=	-Wall -Wextra -Werror -Iincludes -Ilibft -Isrc/01_parse_map -lXext -lX11 -lm
# CFLAGS		:=	-Iincludes -Ilibft
# CFLAGS		:=	-Wall -Wextra -Werror -Iincludes -Ilibft -fsanitize=address
T_CFLAGS	:=	-Iincludes -Ilibft

#─ directory name ────────────────────────────────────────────────────────────

SRCDIR		:=	src
MAND 		:=	mandatory
OBJDIR		:=	obj
LIBFT_DIR	:=	libft
LIBFT_A		:=	$(LIBFT_DIR)/libft.a
LIBMLX		:=	libmlx.a
MAP_PARSE_DIR	:=	src/01_parse_map
MAP_PARSE_A	:=	$(MAP_PARSE_DIR)/map_parse.a

#─ sources & objects ─────────────────────────────────────────────────────────

#mandatory sources

SRCS_MAND	:=	src/main.c \
		src/99_utils.c \
		src/00_input_validation/00_main.c \
		src/02_initalize_graphics/00_main.c \
		src/02_initalize_graphics/01_init_fdf.c \
		src/02_initalize_graphics/02_init_image.c \
		src/03_setup_events/00_main.c \
		src/04_calculate_projection_params/00_main.c \
		src/05_draw_map/00_main.c \
		src/05_draw_map/draw.c \
		src/05_draw_map/graphics.c \
		src/05_draw_map/projection.c

#object files

OBJS_MAND	:=	$(SRCS_MAND:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

#-----------------------------------------------------------------------------

#▸ rules

#-----------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(LIBFT_A) $(MAP_PARSE_A) $(OBJS_MAND)
	@echo "Compiled with $(GREEN)$(BOLD)$(CFLAGS)$(RESET)"
	@$(CC) $(OBJS_MAND) -o $@ $(MAP_PARSE_A) $(LIBFT_A) $(LIBMLX) $(CCFLAGS)
	@echo "$(YELLOW)$(BOLD)========================================="
	@echo "    You can use My $(NAME)!!"
	@echo "=========================================$(RESET)"

# compile object files

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiled ✅ $(WHITE) $(BOLD) $^ $(RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $^

# libft

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

# map_parse

$(MAP_PARSE_A): $(LIBFT_A)
	@$(MAKE) -C $(MAP_PARSE_DIR)

# clean targets

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MAP_PARSE_DIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MAP_PARSE_DIR) fclean
	@rm -f $(NAME)

re: fclean all

# ノルムチェック
norm:
	@echo "$(CYAN)$(BOLD)========================================="
	@echo "    Checking 42 Norm..."
	@echo "=========================================$(RESET)"
	@norminette $(SRCS_MAND) includes/fdf.h
	@echo "$(GREEN)$(BOLD)Norm check completed!$(RESET)"

# リークチェック
leak: $(NAME)
	@echo "$(MAGENTA)$(BOLD)========================================="
	@echo "    Checking Memory Leaks..."
	@echo "=========================================$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(NAME) test.fdf
	@echo "$(GREEN)$(BOLD)Leak check completed!$(RESET)"

# フルテスト（ノルム + リーク）
test: norm leak
	@echo "$(GREEN)$(BOLD)========================================="
	@echo "    All tests completed!"
	@echo "=========================================$(RESET)"

# デバッグビルド（fsanitize付き）
debug: CFLAGS := -Wall -Wextra -Werror -Iincludes -Ilibft -g -fsanitize=address
debug: CCFLAGS := -Wall -Wextra -Werror -Iincludes -Ilibft -lXext -lX11 -g -fsanitize=address
debug: re
	@echo "$(YELLOW)$(BOLD)Debug build completed with fsanitize!$(RESET)"

# 軽量テスト（引数チェックのみ）
quicktest: $(NAME)
	@echo "$(BLUE)$(BOLD)========================================="
	@echo "    Quick Test..."
	@echo "=========================================$(RESET)"
	@echo "Testing with no arguments:"
	@./$(NAME) || true
	@echo "Testing with wrong extension:"
	@./$(NAME) test.txt || true
	@echo "Testing with non-existent file:"
	@./$(NAME) nonexistent.fdf || true
	@echo "Testing with valid file:"
	@./$(NAME) test.fdf
	@echo "$(GREEN)$(BOLD)Quick test completed!$(RESET)"


.PHONY: all clean fclean re norm leak test debug quicktest
