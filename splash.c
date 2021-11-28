// 수학과 2017115475 문경덕
#include <stdio.h>
#include <ncurses.h>  // cureses 함수들 사용하기 위해서
#include <locale.h>  // setlocale, LC_ALL
#include <unistd.h>  // sleep, usleep

void menu();  // menu 선택 화면
void background();  // 만들게 된 배경

int main()
{
	setlocale(LC_ALL, "ko_KR.utf8");  // curses 함수에서 한글과 특수문자를 출력하기 위해 utf8 설정으로 바꾸어줌

	// cureses 함수 사용
	initscr();
	clear();

	for(int time = 0 ; time < 5;time++)
	{
		if(time % 2 == 1)
			standout();
	
		// H	
		for(int i = 20;i<40;i++)
		{
			move(i, 19);
			addstr("■");	
			move(i, 20);
			addstr("■");
			move(i, 41);
			addstr("■");	
			move(i, 40);
			addstr("■");
		}
		for(int i=22;i<39;i++)
		{
			move(29, i);
			addstr("■");	
			move(30, i);
			addstr("■");
		}

		// E
		for(int i=20;i<40;i++)
		{
			move(i, 59);
			addstr("■");
			move(i, 60);
			addstr("■");
		}

		for(int i=61;i<79;i++)
		{
			move(20, i);
			addstr("■");
			move(21, i);
			addstr("■");
			move(29, i);
			addstr("■");
			move(30, i);
			addstr("■");
			move(38, i);
			addstr("■");
			move(39, i);
			addstr("■");
		}

		// L
		for(int i=20;i<40;i++)
		{
			move(i, 94);
			addstr("■");
			move(i, 95);
			addstr("■");
		}

		for(int i=96;i<115;i++)
		{
			move(38, i);
			addstr("■");
			move(39, i);
			addstr("■");
		}		

		// L
		for(int i = 20;i<40;i++)
		{
			move(i, 130);
			addstr("■");
			move(i, 131);
			addstr("■");
		}

		for(int i = 132;i<150;i++)
		{
			move(38, i);
			addstr("■");
			move(39, i);
			addstr("■");
		}	

		// O
		for(int i = 20;i<40;i++)
		{
			move(i, 165);
			addstr("■");
			move(i, 166);
			addstr("■");
			move(i, 182);
			addstr("■");
			move(i, 183);
			addstr("■");	
		}

		for(int i = 167;i<182;i++)
		{
			move(20, i);
			addstr("■");
			move(21, i);
			addstr("■");
			move(38, i);
			addstr("■");
			move(39, i);
			addstr("■");
		}

		move(LINES-1, COLS-1);

		if(time % 2 == 1)
			standend();

		refresh();
		usleep(1000 * 300);
	}

	move(50, 90);
	addstr("Made by 문 경 덕");
	move(LINES - 1, COLS - 1);	
	refresh();
	usleep(1000 * 300);

	move(53, 90);
	addstr("Enter to start");
	move(LINES - 1, COLS - 1);
	refresh();	
	
	getch();
	endwin();

	// 메뉴 선택 화면
	menu();	

	return 0;	
}

void menu()
{
	char menu;

	initscr();
	
	while(1)
	{
		clear();	
		refresh();

		move(0, 0);
		addstr("실행하고 싶은 항목의 번호를 입력해주세요");
		usleep(1000 * 100);
		refresh();

		move(2, 0);
		addstr("1. 만들게 된 배경");
		usleep(1000 * 700);
		refresh();
	
		move(4, 0);	
		addstr("2. 학습하러 가기");	
		usleep(1000 * 700);
		refresh();
		
		move(6, 0);
		addstr("3. 참고 자료");	
		usleep(1000 * 700);
		refresh();
		
		move(8, 0);
		addstr("4. 크레딧");	
		usleep(1000 * 700);
		refresh();
		
		move(10, 0);
		addstr("0. 종료");	
		usleep(1000 * 700);
		refresh();

		move(12, 0);
		addstr("번호를 입력해주세요 : ");
		refresh();
		
		getnstr(&menu, 1);  // ncurses 내부의 문자열을 입력받는 함수	
	
		switch(menu)
		{
			case '1':
				clear();
				endwin();
				background();
				break;
	
			case '2':
		
			case '3':
	
			case '4':

			case '0':
				endwin();
				return;

			defalut :
				move(14, 0);
				addstr("올바른 형식으로 입력해주세요 ex) 1");	
				usleep(1000 * 0.5);
		}

	

	}
}

#define mar(row, msg) {move(row, 0); addstr(msg); refresh(); sleep(7); }
// 매크로 함수 정의 move_addstr_refresh

void background()
{
	printf("123123123");
	initscr();

	mar(0, "안녕하세요. 정설영 교수님의 시스템 프로그래밍 수업을 들었던 수학과 17학번 문경덕 입니다.");
	
	mar(2, "유닉스, 리눅스에 관한 아무런 배경 지식도 가지고 있지 않은 상태로 교수님의 수업을 듣게 되었습니다.");

	mar(4, "약 4개월 가량의 시간을 교수님의 수업과 함께하였습니다.");
		
	mar(6, "수업이 마무리될 때쯤 돌아보니 유닉스와 리눅스의 각종 명령어뿐만 아니라"); 	

	mar(8, "디스크와 메모리, 디바이스와의 관계, kernel과 user_space의 상호 작용 등 컴퓨터 구조적인 부분에 대해서 정말 많이 배울 수 있었습니다.");

	mar(10, "아마 교수님께서 개념 정리와 코드 설명이 자세하게 되어 있는 좋은 강의 자료를 제공해주시고");

	mar(12, "수업 내내 친절하게 설명해주시면서 Q&A와 각종 의견에 대한 피드백을 활발하게 해주셔서 많은 걸 얻어갈 수 있었던 것 같습니다.");

	mar(14, "(개인적으로는 비대면 수업 중 가장 활발한 의사소통이 진행되었습니다. (^-^) )");

	mar(16, "전 진심으로 감사했기 때문에 이번 학기말 프로젝트에 최선을 다하고 또 잘하고 싶었습니다.");

	mar(18, "그렇게 고민하던 중 교수님과의 수업 내용을 담은 학습 도우미 프로그램을 만들면 어떨까 하고 생각하게 되었습니다.");

	mar(20, "학기를 마무리하며 그동안 공부하였던 내용들을 복습할 수 있으며, 필요에 따라 다시 유닉스, 리눅스를 공부하게 되었을 때 저에게 많은 도움이 될 것 같았습니다.");

	mar(22, "더 나아가 프로그램이 다듬어져서 어느 정도의 퀄리티를 갖추게 된다면 정설영 교수님의 수업을 듣게 될");

	mar(24, "초심자 분들께도 도움을 드릴 수 있을 것이라고 생각하였습니다.");

	mar(26, "공적으로나 개인적으로나 여러모로 도움이 된다고 생각했기 때문에 망설이지 않고 해당 프로젝트를 시작하게 되었습니다.");

	mar(28, "길지 않은 시간 동안 다른 과목들을 병행하면서 프로젝트를 진행하였기 때문에 부족한 부분도 있을 것이라고 생각합니다.");

	mar(30, "하지만, 주어진 시간과 환경에서 최선을 다해서 프로젝트를 완수해보겠습니다.");

	mar(32, "사담이지만 전 컴퓨터 학부 심화컴퓨터를 복수전공하고 있습니다.");

	mar(34, "그래서 앞으로도 컴퓨터 수업을 많이 듣게 될 텐데 좋은 기회가 된다면 교수님의 수업에 다시 찾아뵙겠습니다.");

	move(36, 0);
	addstr("감사합니다 !!!");
	refresh();
	sleep(1);

	move(44, 0);
	addstr("Enter to back to menu");
	refresh();

	getch();
	
	endwin();

}

