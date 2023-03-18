#include "secure_data.h"

void free_strarray(char **arr)
{
	int idx = 0;
	while (arr[idx] != NULL)
	{
		free(arr[idx]);
		idx++;
	}
}

void free_all(t_secure_data *secure_data, t_house *house)
{
	free(secure_data->owner_name);
	free_strarray(secure_data->authorized_keys);
	free(secure_data->authorized_keys);
	free(secure_data);

	if (house->inserted_key != NULL)
		free(house->inserted_key);
	free_strarray(house->entered_users);
	free(house->entered_users);
	free(house);
}