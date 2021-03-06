#ifndef NODE_QUICKFIX_THREADING_H
#define NODE_QUICKFIX_THREADING_H


#ifdef _WIN32

#include <windows.h>

    #define NODE_QUICKFIX_MUTEX_t HANDLE mutex;

    #define NODE_QUICKFIX_MUTEX_INIT mutex = CreateMutex(NULL, FALSE, NULL);

    #define NODE_QUICKFIX_MUTEX_LOCK(m) WaitForSingleObject(*m, INFINITE);

    #define NODE_QUICKFIX_MUTEX_UNLOCK(m) ReleaseMutex(*m);

    #define NODE_QUICKFIX_MUTEX_DESTROY CloseHandle(mutex);

#elif defined(NODE_QUICKFIX_BOOST_THREADING)

#include <boost/thread/mutex.hpp>

    #define NODE_QUICKFIX_MUTEX_t boost::mutex mutex;

    #define NODE_QUICKFIX_MUTEX_INIT

    #define NODE_QUICKFIX_MUTEX_LOCK(m) (*m).lock();

    #define NODE_QUICKFIX_MUTEX_UNLOCK(m) (*m).unlock();

    #define NODE_QUICKFIX_MUTEX_DESTROY mutex.unlock();

#else

    #define NODE_QUICKFIX_MUTEX_t pthread_mutex_t mutex;

    #define NODE_QUICKFIX_MUTEX_INIT pthread_mutex_init(&mutex,NULL);

    #define NODE_QUICKFIX_MUTEX_LOCK(m) pthread_mutex_lock(m);

    #define NODE_QUICKFIX_MUTEX_UNLOCK(m) pthread_mutex_unlock(m);

    #define NODE_QUICKFIX_MUTEX_DESTROY pthread_mutex_destroy(&mutex);

#endif


#endif // NODE_QUICKFIX_THREADING_H