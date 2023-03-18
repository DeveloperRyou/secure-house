#ifndef SECURE_DATA_H
# define SECURE_DATA_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define SECRET_KEY "FIREFIGHTER_SECRET_KEY"

# define TRUE 1
# define FALSE 0

# define LOCKED 0
# define INSERTED 1
# define TURNED 2

typedef struct s_secure_data
{
	char *owner_name;
	int authorized_keys_number;
	char **authorized_keys;
}	t_secure_data;

typedef struct s_house
{
	int lock_state;
	char *inserted_key;
	int entered_users_number;
	char **entered_users;
}	t_house;

// init.c
void initSecure(t_secure_data *secure_data, int argc, char **argv);
void initHouse(t_house *house);

// utils.c
char *parse(char *str);

// print.c
void printInsert(char *user_name, char *key);
void printTurn(char *user_name, char *key, int success);
void printEnter(int allowed);
void printInside(t_house *house);
void printChangeLocks(int changed);
void printLeave(char *user_name, int left);
void printError();

// operate.c
void insert_key(t_house *house);
void turn_key(t_secure_data *secure_data, t_house *house);
void enter_house(t_house *house);
void change_locks(t_secure_data *secure_data, t_house *house);
void leave_house(t_house *house);

// free.c
void free_strarray(char **arr);
void free_all(t_secure_data *secure_data, t_house *house);

#endif