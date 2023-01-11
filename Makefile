# Project structure
NAME	=	push_swap
INCDIR	=	incs
LIBDIR	=	libs
SRCDIR	=	srcs
OBJDIR	=	objs
LIBFT	=	libft

# Compiler options
CC		=	cc
CWARNS	=	-Wall -Wextra -Werror
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
			sorts.c \
			test_utils.c
OBJS	:=	$(SRCS:.c=.o)
SRCS	:=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:=	$(addprefix $(OBJDIR)/, $(OBJS))

all: $(NAME)

test:
	$(CC) $(DEBUG) $(CWARNS) $(CINCS) unit_test/test.c -o test $(CLIBS)

$(NAME): $(LIBDIR)/libft.a $(OBJS)
	$(CC) $(DEBUG) $(CWARNS) $(OBJS) $(CLIBS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) $(LIBDIR)
	$(CC) $(DEBUG) $(CWARNS) $(CINCS) -c $< -o $@

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
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT)/libft.a
	$(RM) $(LIBDIR)/libft.a
	$(RM) $(NAME)

re: fclean all

norm:
	norminette $(SRCS) $(INCDIR) | awk '{if ($$NF == "OK!") { print "\033[0;92m"$$0"\033[0m" } else if ($$NF == "Error!") { print "\033[0;91m"$$0"\033[0m" } else { print }}'

.PHONY: all bonus resrcs cleansrcs clean fclean re norm test
