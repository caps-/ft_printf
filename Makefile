NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

#--[SOURCES]----------#

SRC_PRINTF = ft_printf.c \
			ft_printbase.c \
			ft_printchar.c \
			ft_printnum.c \
			ft_printunum.c \
			ft_printptr.c \
			ft_printstr.c \
			utils.c

SRC_DIR = src

SRC_RAW = $(SRC_PRINTF)

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_RAW))

OBJ_DIR = obj

OBJS_RAW = $(SRC_RAW:.c=.o)

OBJS = $(patsubst %,$(OBJ_DIR)/%, $(OBJS_RAW))


#--[RULES]------------#

all: $(NAME)

bonus: all

# REF: Meaning of $@ $< $^
# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean
# REF: Making missing directory if needed
# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) extra -C ./libft
	cp libft/libft.a $(NAME)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)
	rm -df obj

fclean:
	$(MAKE) fclean -C ./libft
	rm -f $(OBJS)
	rm -df obj
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
