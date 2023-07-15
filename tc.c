//// Terminal Curses
#include <curses.h>
#include <kx.h>
// error
static K tc_Er(int r) {
  if(r == OK) {
    return Ki(0);
  } else {
    return KE("tc_error");
  }
}
// init
static K tc_i(void) {
  initscr();
  // tty
  cbreak();
  noecho();
  nonl();
  // get
  timeout(500);
  intrflush(stdscr,FALSE);
  nodelay(stdscr,FALSE);
  notimeout(stdscr,FALSE);
  // key
  keypad(stdscr,TRUE);
  // done
  return Ki(0);
}
// fini
static K tc_f(void) {
  return tc_Er(endwin());
}
// refresh
static K tc_r(void) {
  return tc_Er(refresh());
}
// erase
static K tc_e(void) {
  return tc_Er(erase());
}
// clear
static K tc_c(void) {
  return tc_Er(clear());
}
// move
static K tc_m(K x, K y) {
  return tc_Er(move(iK(x),iK(y)));
}
// get
static K tc_g(void) {
  return Ki(getch());
}
// move get
static K tc_mg(K x, K y) {
  return Ki(mvgetch(iK(x),iK(y)));
}
// write string
static K tc_ws(K c) {
  C tc = TK(c);
  if(tc == 'c') {
    addch(cK(c));
  } else if (tc == 'C') {
    addnstr(dK(c),NK(c));
  } else {
    return KE("tc_ws_args");
  }
  return Ki(0);
}
// write attrs
static K tc_wa(K n, K a, K c) {
  C tn = TK(n); C ta = TK(a); C tc = TK(c);
  if(tn == 'i' && ta == 'i' && tc == 'i') {
    chgat(iK(n),iK(a),iK(c),NULL);
  } else {
    return KE("tc_wa_args");
  }
  return Ki(0);
}
#if 0 // not working due to ngn/k argument restriction
// move write string
static K tc_mws(K x, K y, K c) {
  C tx = TK(x); C ty = TK(y); C tc = TK(c);
  if(tx == 'i' && ty == 'i') {
    if(tc == 'c') {
      mvaddch(iK(x),iK(y),cK(c));
    } else if (tc == 'C') {
      mvaddnstr(iK(x),iK(y),dK(c),NK(c));
    }
    return Ki(0);
  }
  return KE("tc_mws_args");
}
// move write attrs
static K tc_mwa(K x, K y, K n, K a, K c) {
  C tx = TK(x); C ty = TK(y);
  C tn = TK(n); C ta = TK(a); C tc = TK(c);
  if(tx == 'i' && ty == 'i' &&
     tn == 'i' && ta == 'i' && tc == 'i') {
    mvchgat(iK(x),iK(y),iK(n),iK(a),iK(c),NULL);
  } else {
    return KE("tc_mwa_args");
  }
  return Ki(0);
}
#endif
// registration
void kxinit_tc(void) {
  // constants
  KA("tc.O",Ki(OK));
  KA("tc.E",Ki(ERR));
  // attributes
  KA("tc.aN",Ki(A_NORMAL));
  KA("tc.aS",Ki(A_STANDOUT));
  KA("tc.aU",Ki(A_UNDERLINE));
  KA("tc.aR",Ki(A_REVERSE));
  KA("tc.aK",Ki(A_BLINK));
  KA("tc.aD",Ki(A_DIM));
  KA("tc.aB",Ki(A_BOLD));
  KA("tc.aP",Ki(A_PROTECT));
  KA("tc.aH",Ki(A_INVIS));
  KA("tc.aI",Ki(A_ITALIC));
  // colors
  KA("tc.cR",Ki(COLOR_RED));
  KA("tc.cG",Ki(COLOR_GREEN));
  KA("tc.cB",Ki(COLOR_BLUE));
  KA("tc.cC",Ki(COLOR_CYAN));
  KA("tc.cM",Ki(COLOR_MAGENTA));
  KA("tc.cY",Ki(COLOR_YELLOW));
  KA("tc.cK",Ki(COLOR_BLACK));
  KA("tc.cW",Ki(COLOR_WHITE));
  // keys
  KA("tc.kU",Ki(KEY_UP));
  KA("tc.kD",Ki(KEY_DOWN));
  KA("tc.kL",Ki(KEY_LEFT));
  KA("tc.kR",Ki(KEY_RIGHT));
  KA("tc.kH",Ki(KEY_HOME));
  KA("tc.kE",Ki(KEY_END));
  for(I i=1;i<=12;i++) {
    C s[8];
    bzero(s,8);
    snprintf(s,sizeof(s),"tc.kF%d",i);
    KA(s,Ki(KEY_F(i)));
  }
  // functions
  KR("tc.i",tc_i,0);
  KR("tc.f",tc_f,0);
  KR("tc.r",tc_r,0);
  KR("tc.e",tc_e,0);
  KR("tc.c",tc_c,0);
  KR("tc.m",tc_m,2);
  KR("tc.g",tc_g,0);
  KR("tc.mg",tc_mg,2);
  KR("tc.ws",tc_ws,1);
  KR("tc.wa",tc_wa,3);
  // emulate mws/mwa to work around ngn/k argument restriction
  //KR("tc.mws",tc_mws,3);
  //KR("tc.mwa",tc_mwa,5);
  Kx("tc.mws:{[x;y;c];tc.m[x;y];tc.ws[c]}");
  Kx("tc.mwa:{[x;y;n;a;c];tc.m[x;y];tc.wa[n;a;c]}");
}
