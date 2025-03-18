#include <stdio.h>
void main(void)
{
	int score;
	char grade;
	printf("점수를 입력하세요: ");
	scanf("%d", &score);

	switch (score / 10) {
	case 10:					// 100점 이거나
	case 9:	grade = 'A'; break;		// 90점 이상이면 A 
	case 8:	grade = 'B'; break;		// 80점 이상이면 B 
	case 7:	grade = 'C'; break;		// 70점 이상이면 C 
	case 6:	grade = 'D'; break;		// 60점 이상이면 D 
	default:grade = 'F'; break;		// 60점 미만이면 F
	}
	printf(" 학점은 %c입니다.\n", grade);
}