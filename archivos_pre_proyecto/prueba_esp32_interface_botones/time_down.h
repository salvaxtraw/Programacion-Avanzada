#ifndef time_down_h
#define time_down_h

void timer_init();
bool timer_ready();
bool menu_ready();
extern unsigned long ultimo_push;
extern unsigned long tiempo;
extern const unsigned long timeoutms;

#endif 