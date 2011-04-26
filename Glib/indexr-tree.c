
#include <stdio.h>
#include <glib.h>

int
compare_nodes(gconstpointer a, gconstpointer b) {
	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	return 0;
}

gint matches = 0;

gboolean
foreach_node(gpointer key, gpointer value, gpointer user_data) {
	GTree *tree= user_data;

	if (g_tree_lookup(tree, key)) {
		matches++;
	}
	return FALSE;
}

int
main(int argc, char * argv) {

	GTimer *t = g_timer_new();
	gulong ms;
	GTree *one = g_tree_new(compare_nodes);
	GTree *two = g_tree_new(compare_nodes);
	gint i=0;

	g_timer_start(t);
  for(i=0; i <= 9999999; i++) {
		g_tree_insert(one,  GINT_TO_POINTER(i),  GINT_TO_POINTER(i));
	}
	g_timer_stop(t);
	printf("%d inserted. Took %.0f seconds.\n", g_tree_nnodes(one), g_timer_elapsed(t, &ms));
  for(i=0; i <= 9999999; i++) {
		g_tree_insert(two,  GINT_TO_POINTER(i),  GINT_TO_POINTER(i));
	}

	g_timer_start(t);
	g_tree_foreach(one, (GTraverseFunc)foreach_node, two);
	g_timer_stop(t);
	printf("%d matches. Took %.0f seconds.\n", matches, g_timer_elapsed(t, &ms));
}
