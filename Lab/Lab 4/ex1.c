#include <stdio.h>

int bits;

void p(int pil) {
	if(pil == 5)
		return;
	p(pil+1);
	printf("%u\n", &pil);
}

void g() {
	int goa;
	printf("%u\n", &goa);
	h();
}

void h() {
	int hyd;
	printf("%u\n", &hyd);
	d();
}

void d() {
	int dub;
	printf("%u\n", &dub);
}



int main() {
	//p(0);
	g();
	h();
	d();
	//printf("%u\n", &bits);
}
