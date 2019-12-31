#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
#ifndef __EVENT_THREAD_H__
#define __EVENT_THREAD_H__

#include <event2/event.h>
#include <event2/util.h>
#include <pthread.h>
#include <sched.h>
#include <sys/queue.h>

/*
enum evthr_res {
	EVTHR_RES_OK = 0,
	EVTHR_RES_BACKLOG = -1,
	EVTHR_RES_RETRY = -2,
	EVTHR_RES_NOCB = -3,
	EVTHR_RES_FATAL = -4
};
*/

struct evthr_pool;
struct evthr;

typedef struct event_base evbase_t;
typedef struct event ev_t;
typedef event_callback_fn ev_cb;

/*
typedef enum evthr_res evthr_res;
*/
typedef struct evthr evthr_t;
typedef struct evthr_pool evthr_pool_t;

evthr_t *evthr_new(long shutdown_sec);
evthr_t *evthr_assign(evbase_t *evbase, long shutdown_sec);
void evthr_free(evthr_t *evthr);
evbase_t *evthr_get_base(evthr_t *thr);
pthread_t *evthr_get_thread(evthr_t *evthr);

int evthr_get_backlog(evthr_t *evthr);
evthr_t *evthr_event_add(evthr_t *thr, evutil_socket_t fd, short what, void *arg);

/*
void           evthr_set_aux(evthr_t * thr, void * aux);
void         * evthr_get_aux(evthr_t * thr);
*/
int evthr_start(evthr_t *evthr);
int evthr_stop(evthr_t *evthr);

ev_t *evthr_event_add(evthr_t *evthr, ev_cb cb, void *arg);

/*
evthr_pool_t * evthr_pool_new(int nthreads, evthr_init_cb init_cb, void *
shared); int            evthr_pool_start(evthr_pool_t * pool); evthr_res
evthr_pool_stop(evthr_pool_t * pool); evthr_res evthr_pool_defer(evthr_pool_t *
pool, evthr_cb cb, void * arg); void           evthr_pool_free(evthr_pool_t *
pool);
*/

#endif /* __EVENT_THREAD_H__ */
