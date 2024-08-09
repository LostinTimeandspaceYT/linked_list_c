/** @file linked_list.c
 *
 * @brief This module implements the linked list.
 *
 * @author Nathan Winslow
 *
 * @par
 * Source:
 * https://felipec.wordpress.com/2024/03/03/c-skill-issue-how-the-white-house-is-wrong/
 *
 */

#include "../linked_list.h"
#include <stdlib.h>
#include <strings.h>

static inline void linked_list_add(linked_list_node_t *node,
                                   linked_list_head_t *head) {
  node->next = head->first;
  head->first = node;
}

bool node_add(linked_list_head_t *list, void *data) {
  node_t *node;
  node = malloc(sizeof(*node));
  if (!node) {
    return false;
  }
  node->data = data;
  linked_list_add((linked_list_node_t *)node, list);
  return true;
}

bool node_remove_at(linked_list_head_t *list, unsigned int index) {

  if (index == 0) {
    linked_list_node_t *tmp = list->first;
    list->first = list->first->next;
    free(tmp);
    return true;
  }

  unsigned int pos = 0;
  linked_list_foreach_safe(p, list->first) {
    pos++;
    if (pos == (index + 1)) {
      linked_list_node_t *tmp = p->next;
      p->next = p->next->next;
      free(tmp);
      return true;
    }
  }
  return false;
}
