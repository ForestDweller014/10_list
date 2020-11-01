struct session {char username[20]; char login_token[256]; struct session *next;};
struct session *new_session(char *user);
int print_session(struct session *curr_session);
void print_list(struct session *curr_session);
struct session *insert_front(struct session *curr_session, char *user);
struct session *free_list(struct session *curr_session);
struct session *remove_node(struct session *front, char *user); 