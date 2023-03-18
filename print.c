#include "secure_data.h"

void printInsert(char *user_name, char *key)
{
	printf("KEY %s INSERTED BY %s\n", key, user_name);
}

void printTurn(char *user_name, char *key, int success)
{
	if (success == TRUE)
		printf("SUCCESS %s TURNS KEY %s\n", user_name, key);
	else
	{
		if (key == NULL)
			printf("FAILURE %s UNABLE TO TURN KEY\n", user_name);
		else
			printf("FAILURE %s UNABLE TO TURN KEY %s\n", user_name, key);
	}
}

void printEnter(int allowed)
{
	if (allowed == TRUE)
		printf("ACCESS ALLOWED\n");
	else
		printf("ACCESS DENIED\n");
}

void printInside(t_house *house)
{
	if (house->entered_users_number == 0)
		printf("NOBODY HOME\n");
	else
	{
		for (int i=0;i<house->entered_users_number;i++)
		{
			printf("%s", house->entered_users[i]);
			if (i != house->entered_users_number - 1)
				printf(", ");
		}
		printf("\n");
	}
}

void printChangeLocks(int changed)
{
	if (changed == TRUE)
		printf("LOCK CHANGED\n");
	else
		printf("LOCK CHANGE DENIED\n");
}

void printLeave(char *user_name, int left)
{
	if (left == TRUE)
		printf("%s LEFT\n", user_name);
	else
		printf("%s NOT HERE\n", user_name);
}

void printError()
{
	printf("ERROR\n");
}
