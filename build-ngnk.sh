SRC="kx.c tc.c ml.c mp.c"
PKG="primesieve ncursesw"
PKG_C=$(pkg-config --cflags ${PKG})
PKG_L=$(pkg-config --libs ${PKG})
gcc -std=c11 -g -O3 -march=native -fPIC -Wall -I ../i/ngnk -I . -L ../i/ngnk ${PKG_C} -o xngnk ${SRC} -lk -lm ${PKG_L} -Wl,-rpath=$PWD/../i/ngnk
