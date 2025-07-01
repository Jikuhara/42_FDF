# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 16:15:00 by kei2003730        #+#    #+#              #
#    Updated: 2025/07/01 16:06:30 by kei2003730       ###   ########.fr        #
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

OBJDIR		:= obj

#─ sources & objects ─────────────────────────────────────────────────────────

SRCS		:= 00_main.c \
		   01_get_map_dimentions.c \
		   02_allocate_map_memory.c \
		   03_fill_map_data.c \
		   99_utils.c

OBJS		:= $(SRCS:%.c=$(OBJDIR)/%.o)

#─ colors ────────────────────────────────────────────────────────────────────

GREEN		:= \033[32m
YELLOW		:= \033[33m
CYAN		:= \033[36m
WHITE		:= \033[37m
RESET		:= \033[0m
BOLD		:= \033[1m

#-----------------------------------------------------------------------------
#> rules
#-----------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	@echo "$(GREEN)$(BOLD)========================================="
	@echo "    $(NAME) created successfully!"
	@echo "=========================================$(RESET)"

$(OBJDIR)/%.o: %.c
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
test: $(NAME) norm
	@echo "$(YELLOW)$(BOLD)========================================="
	@echo "    Building and running tests..."
	@echo "=========================================$(RESET)"
	@$(CC) $(CFLAGS) -o test_map_parse test_map_parse.c $(NAME)
	@echo "$(GREEN)Test executable created$(RESET)"
	@echo "$(CYAN)Running tests...$(RESET)"
	@./test_map_parse
	@echo "$(GREEN)$(BOLD)Tests completed!$(RESET)"

.PHONY: all clean fclean re norm test
