
all: clean indexr indexr-tree indexr-glist

indexr:
	cc `pkg-config --cflags --libs glib-2.0` indexr.c -o indexr 

indexr-tree:
	cc `pkg-config --cflags --libs glib-2.0` indexr-tree.c -o indexr-tree

indexr-glist:
	cc `pkg-config --cflags --libs glib-2.0` indexr-glist.c -o indexr-glist

clean:
	rm -f indexr indexr-tree indexr-glist *.o
