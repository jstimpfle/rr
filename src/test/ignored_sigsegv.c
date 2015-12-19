/* -*- Mode: C; tab-width: 8; c-basic-offset: 2; indent-tabs-mode: nil; -*- */

#include "rrutil.h"

static void* start_thread(void* p) {
  atomic_puts("EXIT-SUCCESS");

  *(int*)NULL = 0;

  return NULL;
}

int main(int argc, char* argv[]) {
  struct sigaction act;
  pthread_t thread;

  act.sa_handler = SIG_IGN;
  act.sa_flags = SA_NODEFER;
  sigemptyset(&act.sa_mask);
  sigaction(SIGSEGV, &act, NULL);

  pthread_create(&thread, NULL, start_thread, NULL);
  pthread_join(thread, NULL);

  return 0;
}