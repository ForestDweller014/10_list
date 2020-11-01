#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mystruct.h"
   
struct session *new_session(char *user) {
	struct session *ns;
	ns = malloc(sizeof(struct session));

	strncpy(ns->username, user, sizeof(ns->username));
	
	char *nt = ns->login_token; 
	int i;
	for (i = 0; i < 256; i++) {
		*(nt + i) = (rand() % (62));
		if (*(nt + i) < 10) {
			*(nt + i) += 48;
		} else if (*(nt + i) < 36) {
			*(nt + i) += 65 - 10;
		} else {
			*(nt + i) += 97 - 36;
		}
	}

	return ns;
}

int print_session(struct session *curr_session) {
	printf("Username: %s\nLogin token: %s\n", curr_session->username, curr_session->login_token);
	return 0;
}

void print_list(struct session *curr_session) {
	struct session *tracker = curr_session;
	while (tracker) {
		print_session(tracker);
		printf("\n");
		tracker = tracker->next;
	}
}

struct session *insert_front(struct session *curr_session, char *user) {
	struct session *new_s = new_session(user);
	new_s->next = curr_session;

	return new_s;
}

struct session *free_list(struct session *curr_session) {
	struct session *tracker;
	while (curr_session) {
		tracker = curr_session->next;
		free(curr_session);
		curr_session = tracker;
	}
	return curr_session;
}

struct session *remove_node(struct session *front, char *user) {
	if (!front) {
		return NULL;
	} else if (!strcmp(front->username, user)) {
		struct session *new_front = front->next;
		free(front);
		return new_front;
	}
	struct session *behind_tracker = front;
	struct session *tracker = front->next;
	while (tracker) {
		if (!strcmp(tracker->username, user)) {
			behind_tracker->next = tracker->next;
			free(tracker);
		}
		behind_tracker = behind_tracker->next;
		tracker = behind_tracker->next;
	}
	return front;
}