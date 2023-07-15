wait:{`x@(("/usr/bin/sleep";"1.0");"")}
tx.init:{tc.i[];tc.c[]}
tx.fini:{tc.c[];tc.f[]}
tx.loop:{{1}{tc.mws[0;0;$x];tc.g[]}/1}
tx.main:{tx.init[];tx.loop[];tx.fini[]}
tx.demo:{tc.i[];tc.c[];tc.mws[10;10;"Hello!"];tc.r[];wait[];tc.f[]}
