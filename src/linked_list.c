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
