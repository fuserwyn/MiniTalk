NAME_SERVER = server

NAME_CLIENT = client

CC = gcc

FLAGS = -Wall -Werror -Wextra

MINITALK_SERVER = ./src/server.c

MINITALK_CLIENT = ./src/client.c

MINITALK_SERVER_BONUS = ./src/server_bonus.c

MINITALK_CLIENT_BONUS = ./src/client_bonus.c

NAME_SERVER_BONUS = server_bonus

NAME_CLIENT_BONUS = client_bonus

OBJS_DIR		=	./objs/

HEADERS_DIR		=	./includes/

LIBFT_DIR	=	./libft/

HEADER = ./includes/minitalk.h

HEADER_B = ./includes/minitalk_bonus.h

RM				=	rm -f

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(MINITALK_SERVER) $(LIBFT)
	@$(CC) $(FLAGS) $(MINITALK_SERVER) $(LIBFT) -o $(NAME_SERVER) -I ./includes
	@echo "server is ready"

$(NAME_CLIENT): $(MINITALK_CLIENT) $(LIBFT)
	@$(CC) $(FLAGS) $(MINITALK_CLIENT) $(LIBFT) -o $(NAME_CLIENT) -I ./includes
	@echo "client is ready"

$(NAME_SERVER_BONUS): $(MINITALK_SERVER_BONUS) $(LIBFT)
	@$(CC) $(FLAGS) $(MINITALK_SERVER_BONUS) $(LIBFT) -o $(NAME_SERVER_BONUS) -I ./includes
	@echo "server_bonus is ready"

$(NAME_CLIENT_BONUS): $(MINITALK_CLIENT_BONUS) $(LIBFT)
	@$(CC) $(FLAGS) $(MINITALK_CLIENT_BONUS) $(LIBFT) -o $(NAME_CLIENT_BONUS) -I ./includes
	@echo "client_bonus is ready"

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	@echo "[bonus version is ready to use]"

clean:
		$(RM) -r $(OBJS_DIR)
		make clean -C $(LIBFT_DIR) fclean

fclean: clean
		$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
		make clean -C $(LIBFT_DIR) fclean

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

re:	fclean all

.PHONY : all re fclean bonus 
