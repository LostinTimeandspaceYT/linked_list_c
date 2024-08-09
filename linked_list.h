/** @file linked_list.h
 *
 * @brief The purpose of this module to create a generic linked list data
 * structure.
 *
 * @author Nathan Winslow
 *
 * @par
 * This module takes inspiration from FELIPEC's blog post "C skill issue; how
 * the White House is wrong" and expands upon it.
 *
 * Source:
 * https://felipec.wordpress.com/2024/03/03/c-skill-issue-how-the-white-house-is-wrong/
 *
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct linked_list_node_t {
  struct linked_list_node_t *next;
} linked_list_node_t;

typedef struct linked_list_head_t {
  struct linked_list_node_t *first;
} linked_list_head_t;

typedef struct node_t {
  linked_list_node_t node;
  void *data;
} node_t;

#define linked_list_foreach(pos, node)                                         \
  for (typeof(*(node)) *(pos) = (node); (pos); (pos) = (pos)->next)

#define linked_list_foreach_safe(pos, node)                                    \
  for (typeof(*(node)) *(pos) = (node), *n; (pos) && (n = (pos)->next, 1);     \
       (pos) = n)

static inline void linked_list_add(linked_list_node_t *node,
                                   linked_list_head_t *head);

bool node_push(linked_list_head_t *list, void *data);
bool node_remove_at(linked_list_head_t *list, unsigned int index);

#ifdef __cplusplus
}
#endif

#endif /* END LINKED_LIST_H */
