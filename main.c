#include "secure_data.h"

void operator(t_secure_data *secure_data, t_house *house, char *line)
{
	char *copy = strdup(line);
	parse(copy);
	parse(NULL);
	if (strncmp(line, "INSERT KEY ", strlen("INSERT KEY ")) == 0)
		insert_key(house);
	else if (strncmp(line, "TURN KEY ", strlen("TURN KEY ")) == 0)
		turn_key(secure_data, house);
	else if (strncmp(line, "ENTER HOUSE ", strlen("ENTER HOUSE ")) == 0)
		enter_house(house);
	else if (strncmp(line, "WHO'S INSIDE?\n", strlen(line)) == 0)
		printInside(house);
	else if (strncmp(line, "CHANGE LOCKS ", strlen("CHANGE LOCKS ")) == 0)
		change_locks(secure_data, house);
	else if (strncmp(line, "LEAVE HOUSE " , strlen("LEAVE HOUSE ")) == 0)
		leave_house(house);
	else
		printError();
	free(copy);
}

void loop(t_secure_data *secure_data, t_house *house)
{
	size_t len = 0;
	char *line = NULL;

	while (TRUE)
	{
		getline(&line, &len, stdin);
		if (*line == '\n')
			break;
		operator(secure_data, house, line);
		//system("leaks secure_house");
	}
	free(line);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printError();
		return (1);
	}
	t_secure_data *secure_data = malloc(sizeof(t_secure_data));
	t_house *house = malloc(sizeof(t_house));
	initSecure(secure_data, argc, argv);
	initHouse(house);
	loop(secure_data, house);
	free_all(secure_data, house);
	system("leaks secure_house");
}
