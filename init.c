#include "secure_data.h"

void initSecure(t_secure_data *secure_data, int argc, char **argv)
{
	secure_data->owner_name = strdup(argv[1]);
	secure_data->authorized_keys_number = argc - 2;
	secure_data->authorized_keys = malloc(sizeof(char*) * (secure_data->authorized_keys_number + 1));
	for (int i=2;i<argc;i++)
	{
		secure_data->authorized_keys[i - 2] = strdup(argv[i]);
	}
	secure_data->authorized_keys[argc - 2] = NULL;
}

void initHouse(t_house *house)
{
	house->lock_state = LOCKED;
	house->inserted_key = NULL;
	house->entered_users_number = 0;
	house->entered_users = malloc(sizeof(char*));
	house->entered_users[0] = NULL;
}
