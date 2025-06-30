# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 14:37:47 by kjikuhar          #+#    #+#              #
#    Updated: 2025/06/30 17:49:04 by kei2003730       ###   ########.fr        #
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
CFLAGS		:=	-Wall -Wextra -Werror -Iincludes -Ilibft
CCFLAGS		:=	-Wall -Wextra -Werror -Iincludes -Ilibft -lXext -lX11
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

#─ sources & objects ─────────────────────────────────────────────────────────

#mandatory sources

SRCS_MAND	:=	src/main.c \
		src/input_validation/input_validation.c \
		src/input_validation/map_parser.c \
		src/get_next_line.c

#bonus sources

# SRCS_BONUS	:=

#object files

OBJS_MAND	:=	$(SRCS_MAND:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
# OBJS_BONUS	:=	$(SRCS_BONUS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
# OBJS	 	:=	$(OBJS_MAND) $(OBJS_BONUS)

#test

# TEST        := test/test_printf.c
# OBJ_T       := $(TEST:.c=.o)

#-----------------------------------------------------------------------------

#▸ rules

#-----------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS_MAND)
	@echo "Compiled with $(GREEN)$(BOLD)$(CFLAGS)$(RESET)"
	@$(CC) $(CCFLAGS)  $(OBJS_MAND) -o $@ $(LIBFT_A) $(LIBMLX)
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

# clean targets

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

# bonus: $(LIBFT_A) $(OBJS_BONUS)
# 	@cp $(LIBFT_A) $(NAME)
# 	@echo "Compiled with $(GREEN)$(BOLD)$(CFLAGS)$(RESET)"
# 	@ar rcs $(NAME) $(OBJS_BONUS)
# 	@echo "$(YELLOW)$(BOLD)========================================="
# 	@echo "  You can use My Bonus_$(NAME)!!"
# 	@echo "=========================================$(RESET)"

# test: $(NAME)
# 	@norminette $(SRCS_MAND) $(SRCS_BONUS)
# 	@$(CC) $(T_CFLAGS) $(TEST) $(NAME) -o $(OBJ_T)
# 	@valgrind --leak-check=full ./$(OBJ_T)
# 	@rm $(OBJ_T)
# 	fclean

# test_bonus: bonus
# 	@$(CC) $(T_CFLAGS) $(TEST) $(NAME) -o $(OBJ_T)
# 	@valgrind --leak-check=full ./$(OBJ_T)
# 	@rm $(OBJ_T)
# 	fclean


.PHONY: all clean fclean re bonus test
