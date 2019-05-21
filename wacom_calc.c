#include <stdio.h>

int main ()
{
	float m_x, m_y;//모니터 해상도, Monitor xy
	float w_x, w_y;//와콤 눈금 칸, Wacom spaces
	float mrg_x, mrg_y;//와콤 여백, Wacom margin
	float r_x, r_y, rmrg_x, rmrg_y;


	printf("Monitor\n\n");
	printf("모니터 가로 해상도 입력 \n > "); //Monitor x
	scanf("%f",&m_x);

	printf("모니터 세로 해상도 입력 \n > "); //Monitor y
        scanf("%f",&m_y);

	printf("\n\nWacom\n");
	printf("ex> · · · · = 3 \n\n");

	printf("와콤 가로 눈금 칸 입력 \n > "); //Wacom x spaces
        scanf("%f",&w_x);
	printf("와콤 세로 눈금 칸 입력 \n > "); //Wacom y spaces
        scanf("%f",&w_y);
	printf("와콤에서 사용하지 않을 여백의 충 칸(가로)  \n > "); //Wacom x margin(all)
        scanf("%f",&mrg_x);
	

	printf("\n\n----------------\n\n입력정보 \n");
	printf("모니터 해상도 : %d X %d\n와콤 칸 크기 : %d X %d \n와콤 가로 여백 : 총 %d 칸",(int)m_x,(int)m_y,(int)w_x,(int)w_y,(int)mrg_x);


	mrg_y=w_y-((w_x-mrg_x)/(m_x/m_y));
	r_x=m_x/(w_x-mrg_x)*w_x;
	r_y=m_y/(w_y-mrg_y)*w_y;
	rmrg_x=(m_x/(w_x-mrg_x)*mrg_x)/2;
	rmrg_y=(m_y/(w_y-mrg_y)*mrg_y)/2;


	printf("\n\n----------------\n\n계산결과 \n");
	printf("와콤 추천 해상도 : %d X %d\n 와콤 추천 여백 : %d X %d\n",(int)r_x,(int)r_y,(int)rmrg_x,(int)rmrg_y);

	printf("\nxset 명령어 (와콤 Intuos CTL-4100 기준)\n");
	printf("xsetwacom --set ""Wacom Intuos S Pen stylus"" MapToOutput %dx%d-%d-%d\n\n",(int)r_x,(int)r_y,(int)rmrg_x,(int)rmrg_y);

}

