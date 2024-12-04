# Répertoire principal
MINITALK_DIR = .

# Répertoire pour la bibliothèque libft
LIBFT_DIR = $(MINITALK_DIR)/libft

# Nom des exécutables à générer
CLIENT = client
SERVER = server

# Fichiers sources
CLIENT_SRC = client.c
SERVER_SRC = server.c
MINITALK_SRC = minitalk.c  # Si ce fichier est présent dans votre projet

# Fichiers objets
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
MINITALK_OBJ = $(MINITALK_SRC:.c=.o)

# Bibliothèque libft
LIBFT = $(LIBFT_DIR)/libft.a

# Options de compilation
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

# Compilateur
CC = gcc

# Règles de compilation
all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(CLIENT_OBJ) $(LDLIBS)

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(SERVER_OBJ) $(LDLIBS)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(MINITALK_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re


