
#include <stdio.h>
#include <glib.h>

gint matches = 0;

void
foreach_node(gpointer key, gpointer value, gpointer user_data) {
	GHashTable *ht = user_data;

	if (g_hash_table_lookup(ht, key)) {
		matches++;
	}
	return;
}

int
main(int argc, char * argv) {

	GTimer *t = g_timer_new();
	gulong ms;
	GHashTable *one = g_hash_table_new(NULL, NULL);
	GHashTable *two = g_hash_table_new(NULL, NULL);
	gint i=0;

	g_timer_start(t);
  for(i=0; i <= 9999999; i++) {
		g_hash_table_insert(one,  GINT_TO_POINTER(i),  GINT_TO_POINTER(i));
	}
	g_timer_stop(t);
	printf("%d inserted. Took %.0f seconds.\n", g_hash_table_size(one), g_timer_elapsed(t, &ms));
  for(i=0; i <= 9999999; i++) {
		g_hash_table_insert(two,  GINT_TO_POINTER(i),  GINT_TO_POINTER(i));
	}

	g_timer_start(t);
	g_hash_table_foreach(one, (GHFunc)foreach_node, two);
	g_timer_stop(t);
	printf("%d matches. Took %.0f seconds.\n", matches, g_timer_elapsed(t, &ms));
}
