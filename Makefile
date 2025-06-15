SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra

INCDIR = .
SRCDIR = .

SERVER_SRCS = $(SRCDIR)/server.c \
			  $(SRCDIR)/utils.c
SERVER_OBJS = $(SERVER_SRCS:$(SRCDIR)/%.c=%.o)

CLIENT_SRCS = $(SRCDIR)/client.c \
			  $(SRCDIR)/utils.c
CLIENT_OBJS = $(CLIENT_SRCS:$(SRCDIR)/%.c=%.o)

SERVER_BONUS_SRCS = $(SRCDIR)/server_bonus.c \
					$(SRCDIR)/utils.c
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:$(SRCDIR)/%.c=%.o)

CLIENT_BONUS_SRCS = $(SRCDIR)/client_bonus.c \
 					$(SRCDIR)/utils.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:$(SRCDIR)/%.c=%.o)

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -I $(INCDIR) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -I $(INCDIR) -o $(CLIENT)

$(SERVER_BONUS): $(SERVER_BONUS_OBJS)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) -I $(INCDIR) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) -I $(INCDIR) -o $(CLIENT_BONUS)

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean: clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: fclean all re clean bonus