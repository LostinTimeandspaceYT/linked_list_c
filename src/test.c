#include "../linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int ret_val = 1;
  linked_list_head_t *list;
  list = calloc(1, sizeof(*list));

  if (!list) {
    printf("ERROR: Could not allocate memory...\nExiting Program.\n");
    return 1;
  }

  /* add the capital letters of the ASCII alphabet */
  for (unsigned char c = 0x5A; c > 0x40; --c) {
    if (!node_add(list, (void *)c)) {
      goto cleanup;
    }
  }

  node_t *node = (node_t *)list->first;
  while (node) {
    printf("Node address: %p\t", node);
    printf("Data: %c\n", (char)node->data);
    node = (node_t *)node->node.next;
  }
  ret_val = 0;

cleanup:
  linked_list_foreach_safe(p, list->first) free(p);

  free(list);
  printf("Finished cleaning up...\nExiting program with exit code - %i.\n",
         ret_val);
  return ret_val;
}
/* END OF FILE */
