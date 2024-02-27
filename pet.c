#include <stio.h>

int main() {
	int n;
	printf("enter the size	");
	scanf("%d",&n);

	printf("Output:\n");

	int num = 1, k=0,m=4;

	for (int i = 1; i <= n/2; i++) {
		for (int j = 1; j <= n; j++) {
			if (i==1) {
				printf("%d ", num);
			num += (j + i);
			} else {
				if(j==n)
					num--;
				printf("%d ", num);
			num += (i + j );
			}
		}
		printf("\n");
		num=2;
	}
	num=4;
	for (int i = 1; i <= n/2; i++) {
                for (int j = 1; j <= n; j++) {
                        if (i==1) {
				if(j>2){
					num--;
					k=2;
				}
                                printf("%d ", num);
                        num += (j + i + 2-k);
                        } else {
                                printf("%d ", num);
                        num += m--;
                        }
                }
                printf("\n");
                num=7;
        }

	return 0;
}
