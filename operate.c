#include "secure_data.h"

void insert_key(t_house *house)
{
	char *user_name = parse(NULL);
	char *key = parse(NULL);
	if (user_name == NULL || key == NULL)
	{
		printError();
		return;
	}
	if (house->inserted_key != NULL)
		free(house->inserted_key);
	house->inserted_key = strdup(key);
	house->lock_state = INSERTED;
	printInsert(user_name, key);
}

void turn_key(t_secure_data *secure_data, t_house *house)
{
	char *user_name = parse(NULL);
	if (user_name == NULL)
	{
		printError();
		return;
	}
	if (house->lock_state != INSERTED)
	{
		printTurn(user_name, NULL, FALSE);
		return;
	}
	for(int i=0;i<secure_data->authorized_keys_number;i++)
	{
		if (strcmp(secure_data->authorized_keys[i], house->inserted_key) == 0)
		{
			house->lock_state = TURNED;
			printTurn(user_name, house->inserted_key, TRUE);
			return;
		}
	}
	if (strcmp(SECRET_KEY, house->inserted_key) == 0)
	{
		house->lock_state = TURNED;
		printTurn(user_name, house->inserted_key, TRUE);
		return;
	}
	printTurn(user_name, house->inserted_key, FALSE);
}

void enter_house(t_house *house)
{
	char *user_name = parse(NULL);
	if (user_name == NULL)
	{
		printError();
		return;
	}
	if (house->lock_state == TURNED)
	{
		house->entered_users_number++;
		house->entered_users = realloc(house->entered_users, 
		sizeof(char*) * (house->entered_users_number + 1));
		house->entered_users[house->entered_users_number - 1] = strdup(user_name);
		house->entered_users[house->entered_users_number] = NULL;
		house->lock_state = LOCKED;
		printEnter(TRUE);
	}
	else
		printEnter(FALSE);
}

void resetkey(t_secure_data *secure_data)
{
	secure_data->authorized_keys_number = 0;
	free_strarray(secure_data->authorized_keys);
	
	int idx = 0;
	char *key = parse(NULL);
	while (key != NULL)
	{
		secure_data->authorized_keys_number++;
		secure_data->authorized_keys = realloc(secure_data->authorized_keys, 
		sizeof(char*) * (secure_data->authorized_keys_number + 1));
		
		secure_data->authorized_keys[idx] = strdup(key);
		idx++;

		key = parse(NULL);
	}
	secure_data->authorized_keys[idx] = NULL;
}

void change_locks(t_secure_data *secure_data, t_house *house)
{
	char *user_name = parse(NULL);
	if (user_name == NULL)
	{
		printError();
		return;
	}
	if (strcmp(secure_data->owner_name, user_name) != 0)
	{
		printChangeLocks(FALSE);
		return;
	}
	for (int i=0;i<house->entered_users_number;i++)
	{
		if (strcmp(house->entered_users[i], user_name) == 0)
		{
			resetkey(secure_data);
			house->lock_state = LOCKED;
			printChangeLocks(TRUE);
			return;
		}
	}
	printChangeLocks(FALSE);
}

void leave_house(t_house *house)
{
	char *user_name = parse(NULL);
	if (user_name == NULL)
	{
		printError();
		return;
	}

	int flag = FALSE;
	for (int i=0;i<house->entered_users_number;i++)
	{
		if (flag == TRUE)
			house->entered_users[i - 1] = house->entered_users[i];
		else if (strcmp(house->entered_users[i], user_name) == 0)
		{
			free(house->entered_users[i]);
			flag = TRUE;
		}
	}
	if (flag == TRUE)
	{
		house->entered_users_number--;
		house->entered_users[house->entered_users_number] = NULL;
	}
	printLeave(user_name, flag);
}
