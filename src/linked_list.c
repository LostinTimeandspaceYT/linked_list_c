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

bool node_push(linked_list_head_t *list, void *data) {
  node_t *node;
  node = malloc(sizeof(*node));
  if (!node) {
    return false;
  }
  node->data = data;
  linked_list_add((linked_list_node_t *)node, list);
  return true;
}

bool node_append(linked_list_head_t *list, void *data) {
  node_t *node;
  node = malloc(sizeof(*node));
  if (!node) {
    return false;
  }
  node->data = data;

  linked_list_node_t *tmp = list->first;
  while (tmp->next) {
    tmp = tmp->next;
  }
  tmp->next = (linked_list_node_t *)node;
  tmp->next->next = NULL;
  return true;
}

/**
 * @brief returns the first node in the list. freeing the memory is the
 * responsibility of the callee.
 *
 * @param list
 * @return node_t * to the first element.
 */
node_t *node_pop(linked_list_head_t *list) {
  if (!list->first) {
    return NULL;
  }
  node_t *node;
  node = (node_t *)list->first;
  list->first = list->first->next;
  return node;
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
    if (pos == index) {
      linked_list_node_t *tmp = p->next;
      p->next = p->next->next;
      free(tmp);
      return true;
    }
  }
  return false;
}

bool node_insert_at(linked_list_head_t *list, linked_list_node_t *node,
                    unsigned int index) {
  if (index == 0) {
    linked_list_add((linked_list_node_t *)node, list);
    return true;
  }
  unsigned int pos = 0;
  linked_list_foreach_safe(p, list->first) {
    pos++;
    if (pos == index) {
      node->next = p->next;
      p->next = node;
    }
  }

  return false;
}
