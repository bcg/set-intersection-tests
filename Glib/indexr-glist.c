
#include <stdio.h>
#include <glib.h>

int
compare_nodes(gconstpointer a, gconstpointer b) {
	if (a < b)
		return -1;
	else if (a > b)
		return 0;
	return 1;
}

gint matches = 0;

void
foreach_node(gpointer data, gpointer user_data) {
	GList *list = user_data;
	gint   id   = (gint*)data;

	if (g_list_find(list, id)) {
		matches++;
	}
}


int
main(int argc, char * argv) {

	GTimer *t = g_timer_new();
	gulong ms;
	GList *one=NULL, *two=NULL;
	gint i=0;

	g_timer_start(t);
  for(i=0; i <= 9999999; i++) {
		one = g_list_prepend(one, GINT_TO_POINTER(i));
	}
	g_timer_stop(t);
	printf("%d inserted. Took %.0f seconds.\n", g_list_length(one), g_timer_elapsed(t, &ms));
  for(i=0; i <= 9999999; i++) {
		two = g_list_prepend(two, GINT_TO_POINTER (i));
	}

	g_timer_start(t);
	g_list_foreach(one, (GFunc)foreach_node, two);
	g_timer_stop(t);
	printf("%d matches. Took %.0f seconds.\n", matches, g_timer_elapsed(t, &ms));
}
