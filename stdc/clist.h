/*****************************************************************************
*                                                                            *
*  ------------------------------- clist.h --------------------------------  *
*                                                                            *
*****************************************************************************/

#ifndef CLIST_H
#define CLIST_H

/*****************************************************************************
*                                                                            *
*  Define a structure for circular doubly-linked list elements.              *
*                                                                            *
*****************************************************************************/

typedef struct CListElmt_ {

void               *data;
struct CListElmt_  *prev;
struct CListElmt_  *next;

} CListElmt;

/*****************************************************************************
*                                                                            *
*  Define a structure for circular doubly-linked lists.                      *
*                                                                            *
*****************************************************************************/

typedef struct CList_ {

int                size;

int                (*match)(const void *key1, const void *key2);
void               (*destroy)(void *data);

CListElmt          *link;

} CList;

/*****************************************************************************
*                                                                            *
*  --------------------------- Public Interface ---------------------------  *
*                                                                            *
*****************************************************************************/

void clist_init(CList *list, void (*destroy)(void *data));

void clist_destroy(CList *list);

int clist_ins_next(CList *list, CListElmt *element, const void *data);

int clist_ins_prev(CList *list, CListElmt *element, const void *data);

int clist_remove(CList *list, CListElmt *element, void **data);

#define clist_size(list) ((list)->size)

#define clist_link(list) ((list)->link)

#define clist_data(element) ((element)->data)

#define clist_next(element) ((element)->next)

#define clist_prev(element) ((element)->prev)

#endif
