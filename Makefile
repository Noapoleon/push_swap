# Project structure
NAME	=	push_swap
CHECKER	=	checker
INCDIR	=	incs
LIBDIR	=	libs
SRCDIR	=	srcs
OBJDIR	=	objs
LIBFT	=	libft

# Compiler options
CC		=	cc
CWARNS	=	-Wall -Wextra -Werror -g
CLIBS	=	-L./$(LIBDIR) -lft
CINCS	=	-I./$(INCDIR)

# Other
RM		=	rm -rf
DEBUG	=	-g3 -gdwarf-4

# Files
SRCS	:=	push_swap.c \
			parser1.c \
			parser2.c \
			utils.c \
			operations1.c \
			operations2.c \
			small_sorts.c \
			quick_sort.c \
			fraction_sort1.c \
			fraction_sort2.c \
			fraction_sort3.c \
			sorts_utils1.c \
			sorts_utils2.c
SRCS_B	:=	checker_bonus.c \
			checker_utils_bonus.c \
			get_operations_bonus.c \
			parser1.c \
			parser2.c \
			utils.c \
			operations1.c \
			operations2.c
OBJS	:=	$(SRCS:.c=.o)
OBJS_B	:=	$(SRCS_B:.c=.o)
SRCS	:=	$(addprefix $(SRCDIR)/, $(SRCS))
SRCS_B	:=	$(addprefix $(SRCDIR)/, $(SRCS_B))
OBJS	:=	$(addprefix $(OBJDIR)/, $(OBJS))
OBJS_B	:=	$(addprefix $(OBJDIR)/, $(OBJS_B))

all: $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(LIBDIR)/libft.a $(OBJS_B)
	$(CC) $(CWARNS) $(OBJS_B) $(CLIBS) -o $(CHECKER)

$(NAME): $(LIBDIR)/libft.a $(OBJS)
	$(CC) $(CWARNS) $(OBJS) $(CLIBS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) $(LIBDIR)
	$(CC) $(CWARNS) $(CINCS) -c $< -o $@

$(LIBDIR)/libft.a: | $(LIBDIR)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a $(LIBDIR)/

$(OBJDIR):
	mkdir -p $(OBJDIR)
$(LIBDIR):
	mkdir -p $(LIBDIR)

resrcs: cleansrcs $(OBJS)

cleansrcs:
	$(RM) $(OBJS)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(LIBFT)/libft.a
	$(RM) $(LIBDIR)/libft.a
	$(RM) $(NAME) $(CHECKER)

re: fclean all

rebonus: fclean bonus

malloc_test: $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} $(CLIBS) -L. -lmallocator

#norminette $(SRCS) $(INCDIR) | awk '{if ($$NF == "OK!") { print "\033[0;92m"$$0"\033[0m" } else if ($$NF == "Error!") { print "\033[0;91m"$$0"\033[0m" } else { print }}'
#norminette $(SRCS_B) $(INCDIR) | awk '{if ($$NF == "OK!") { print "\033[0;92m"$$0"\033[0m" } else if ($$NF == "Error!") { print "\033[0;91m"$$0"\033[0m" } else { print }}'
#@echo "\n"
norm:
	@echo "\033[44;97;1m               \033[0m"
	@echo "\033[44;97;1m  LIBFT NORM:  \033[46;97;1m  \033[0m"
	@echo "\033[44;97;1m               \033[46;97;1m  \033[0m"
	@echo " \033[46;97;1m                \033[0m"
	@norminette $(LIBFT) | awk '{if ($$NF == "OK!") { print "\033[0;92m"$$0"\033[0m" } else if ($$NF == "Error!") { print "\033[41;97;5;1m"$$0"\033[0m" } else { print }}'
	@echo "\n"
	@echo "\033[44;97;1m                 \033[0m"
	@echo "\033[44;97;1m  SOURCES NORM:  \033[46;97;1m  \033[0m"
	@echo "\033[44;97;1m                 \033[46;97;1m  \033[0m"
	@echo " \033[46;97;1m                  \033[0m"
	@norminette $(SRCDIR) | awk '{if ($$NF == "OK!") { print "\033[0;92m"$$0"\033[0m" } else if ($$NF == "Error!") { print "\033[41;97;5;1m"$$0"\033[0m" } else { print }}'
	@echo "\n"
	@echo "\033[44;97;1m                  \033[0m"
	@echo "\033[44;97;1m  INCLUDES NORM:  \033[46;97;1m  \033[0m"
	@echo "\033[44;97;1m                  \033[46;97;1m  \033[0m"
	@echo " \033[46;97;1m                   \033[0m"
	@norminette $(INCDIR) | awk '{if ($$NF == "OK!") { print "\033[0;92m"$$0"\033[0m" } else if ($$NF == "Error!") { print "\033[41;97;5;1m"$$0"\033[0m" } else { print }}'

.PHONY: all bonus rebonus resrcs cleansrcs clean fclean re norm
