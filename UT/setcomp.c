#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utlist.h"
#include "uthash.h"

typedef struct cid_t {
    int id;
    struct cid_t *next;
} cid_t;

int cid_matches(cid_t *list1, cid_t *list2) {
  cid_t *tmp1, *tmp2, *elt1, *elt2;
  int matches = 0;

  LL_FOREACH_SAFE(list1,elt1,tmp1) {
    LL_FOREACH_SAFE(list2,elt2,tmp2) {
      if (elt1->id == elt2->id) {
        matches++;
      }
    }
  }
  return matches;
}

struct cid_hash_t {
    int id;
    int present;
    UT_hash_handle hh;
} cid_hash_t;


int cid_matches_hash(cid_t *list1, cid_t *list2) {
  struct cid_hash_t *cid_hash = NULL;
  cid_t *tmp1, *tmp2, *elt1, *elt2;
  int matches = 0;

  LL_FOREACH_SAFE(list1,elt1,tmp1) {
    struct cid_hash_t *elem;
    elem = malloc(sizeof(struct cid_hash_t));
    elem->id = elt1->id;
    elem->present = 1;
    HASH_ADD_INT(cid_hash, id, elem);
  }

  LL_FOREACH_SAFE(list2,elt2,tmp2) {
    struct cid_hash_t *elem = NULL;
    HASH_FIND_INT(cid_hash, &elt2->id, elem);
    if (elem) {
      matches++;
    }
  }

  return matches;
}

int cid_hash_match(struct cid_hash_t *one, struct cid_hash_t *two) {
  int matches = 0;
  struct cid_hash_t *iter = NULL;

  for(iter=one; iter != NULL; iter=iter->hh.next) {
    struct cid_hash_t *elem = NULL;
    HASH_FIND_INT(two, &iter->id, elem);
    if (elem) {
      matches++;
    }

  }
  return matches;

}

int main(int argc, char *argv) {
  int i, matches = 0;
  time_t start, stop;

/*
  cid_t *one, *two = NULL;

  for(i=0; i<=1000000; i++) {
    cid_t *id;
    if ( (id = (cid_t*)malloc(sizeof(id))) == NULL) exit(-1);
    id->id = i; 
    LL_APPEND(one, id);
  }

  for(i=0; i<=1000000; i++) {
    cid_t *id;
    if ( (id = (cid_t*)malloc(sizeof(id))) == NULL) exit(-1);
    id->id = i; 
    LL_APPEND(two, id);
  }
*/

  struct cid_hash_t *one = NULL, *two = NULL;

  printf("Test list generation complete.\n");
  time(&start);
  for(i=0; i<=10000000; i++) {
    struct cid_hash_t *tmp;
    tmp = malloc(sizeof(struct cid_hash_t));
    tmp->id = i;
    tmp->present = 1;
    HASH_ADD_INT(one, id, tmp);
  }
  time(&stop);
  printf("Loaded data in %.0f seconds.\n", matches, difftime(stop, start));

  for(i=0; i<=10000000; i++) {
    struct cid_hash_t *tmp;
    tmp = malloc(sizeof(struct cid_hash_t));
    tmp->id = i;
    tmp->present = 1;
    HASH_ADD_INT(two, id, tmp);
  }
  printf("Test list generation complete.\n");
/*
  printf("=> Starting iterative matches...\n");

  time(&start);
  matches = cid_matches(one, two);
  time(&stop);
  printf("There are %d matches in %.0f seconds.\n", matches, difftime(stop, start));

  printf("=> Starting hash match...\n");
  time(&start);
  matches = cid_matches_hash(one, two);
  time(&stop);
  printf("There are %d matches in %.0f seconds.\n", matches, difftime(stop, start));
*/
  printf("=> Starting hash match...\n");
  time(&start);
  matches = cid_hash_match(one, two);
  time(&stop);
  printf("There are %d matches in %.0f seconds.\n", matches, difftime(stop, start));
  return;
}
