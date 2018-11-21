#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list_item {
	struct list_item *next;
	char *path_component;
};

//put new element to linked list
void push(list_item * list, char *val) {
	list_item * current = list;
	while (current->next != NULL) {
		current = current->next;
	}

	/* allocate memory for new item */
	current->next = (list_item *)malloc(sizeof(list_item));
	current->next->path_component = val;
	current->next->next = NULL;
}

struct list_item *path_to_list(char *path)
{
	//Initialize linked list
	struct list_item * components = NULL;
	components = (list_item *)malloc(sizeof(list_item));
	if (components == NULL)
		return NULL;
	components->next = NULL;

	char * token;
	char * next;
	char deli[] = "/";
	token = strtok_s(path, deli, &next);
	components->path_component = token;
	while (token != NULL) {
		token = strtok_s(NULL, deli, &next);
		push(components, token);
	}
	return components;
}

static char g_line[1024];
char *readline(void)
{
	return fgets(g_line, sizeof(g_line), stdin);
}

int main(int argc, char **argv)
{
	char *line;

	while ((line = readline())) {
		struct list_item *list;
		size_t len = strlen(line);
		if (len && line[len - 1] == '\n')
			line[len - 1] = '\0';
		list = path_to_list(line);
		do {
			printf("%s\n", list->path_component);
		} while ((list = list->next));
	}
	return 0;
}