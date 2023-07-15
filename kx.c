#include <locale.h>
#include <kx.h>
#include <a.h>
void kxinit_tc(void);
void kxinit_ml(void);
void kxinit_mp(void);
int main(int argc, char **argv) {
	int i;
	setlocale(LC_ALL, "");
	kinit();
	kxinit_tc();
	kxinit_ml();
	kxinit_mp();
	for(i = 1; i < argc; i++) {
		Kx(argv[i]);
	}
	repl();
	return 0;
}

