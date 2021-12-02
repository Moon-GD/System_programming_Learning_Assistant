// 수학과 2017115475 문경덕
#include <stdio.h>
#include <ncurses.h>  // cureses 함수들 사용하기 위해서
#include <locale.h>  // setlocale, LC_ALL
#include <unistd.h>  // sleep, usleep

void menu();  // menu 선택 화면
void background();  // 만들게 된 배경
void study();

// chap 2
void chap2();
void chap2_concept();
void chap2_goal();
void chap2_command();

// chap 3
void chap3();
void chap3_goal();
void chap3_concept();
void chap3_command();

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
				clear();
				endwin();	
				study();
				break;		
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

#define mars(row, msg) {move(row, 0); addstr(msg); refresh(); sleep(7); }
// 매크로 함수 정의 move_addstr_refresh_sleep

void background()
{
	initscr();

	mars(0, "안녕하세요. 정설영 교수님의 시스템 프로그래밍 수업을 들었던 수학과 17학번 문경덕 입니다.");
	
	mars(2, "유닉스, 리눅스에 관한 아무런 배경 지식도 가지고 있지 않은 상태로 교수님의 수업을 듣게 되었습니다.");

	mars(4, "약 4개월 가량의 시간을 교수님의 수업과 함께하였습니다.");
		
	mars(6, "수업이 마무리될 때쯤 돌아보니 유닉스와 리눅스의 각종 명령어뿐만 아니라"); 	

	mars(8, "디스크와 메모리, 디바이스와의 관계, kernel과 user_space의 상호 작용 등 컴퓨터 구조적인 부분에 대해서 정말 많이 배울 수 있었습니다.");

	mars(10, "아마 교수님께서 개념 정리와 코드 설명이 자세하게 되어 있는 좋은 강의 자료를 제공해주시고");

	mars(12, "수업 내내 친절하게 설명해주시면서 Q&A와 각종 의견에 대한 피드백을 활발하게 해주셔서 많은 걸 얻어갈 수 있었던 것 같습니다.");

	mars(14, "(개인적으로는 비대면 수업 중 가장 활발한 의사소통이 진행되었습니다. (^-^) )");

	mars(16, "전 진심으로 감사했기 때문에 이번 학기말 프로젝트에 최선을 다하고 또 잘하고 싶었습니다.");

	mars(18, "그렇게 고민하던 중 교수님과의 수업 내용을 담은 학습 도우미 프로그램을 만들면 어떨까 하고 생각하게 되었습니다.");

	mars(20, "학기를 마무리하며 그동안 공부하였던 내용들을 복습할 수 있으며, 필요에 따라 다시 유닉스, 리눅스를 공부하게 되었을 때 저에게 많은 도움이 될 것 같았습니다.");

	mars(22, "더 나아가 프로그램이 다듬어져서 어느 정도의 퀄리티를 갖추게 된다면 정설영 교수님의 수업을 듣게 될");

	mars(24, "초심자 분들께도 도움을 드릴 수 있을 것이라고 생각하였습니다.");

	mars(26, "공적으로나 개인적으로나 여러모로 도움이 된다고 생각했기 때문에 망설이지 않고 해당 프로젝트를 시작하게 되었습니다.");

	mars(28, "길지 않은 시간 동안 다른 과목들을 병행하면서 프로젝트를 진행하였기 때문에 부족한 부분도 있을 것이라고 생각합니다.");

	mars(30, "하지만, 주어진 시간과 환경에서 최선을 다해서 프로젝트를 완수해보겠습니다.");

	mars(32, "사담이지만 전 컴퓨터 학부 심화컴퓨터를 복수전공하고 있습니다.");

	mars(34, "그래서 앞으로도 컴퓨터 수업을 많이 듣게 될 텐데 좋은 기회가 된다면 교수님의 수업에 다시 찾아뵙겠습니다.");

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


#define mar(row, message) {move(row, 0); addstr(message); refresh();}
// move_addstr_refresh
void study()
{
	char chap;
	
	// curses 시작	
	initscr();

	while(1)
	{
	
		clear();

		mar(0, "학습을 시작합니다.");

		mar(2, "학습에 도움을 받을 챕터를 선택해주세요.");

		sleep(1);

		mar(4, "1. chap 1_OT");

		mar(6, "2. chap 2_who");

		mar(8, "3. chap 3_ls");

		mar(10, "4. chap 4_pwd");

		mar(12, "5. chap 5_stty");

		mar(14, "6. chap 6_signal");

		mar(16, "7. chap 7_event-driven");

		mar(18, "0. back to menu");

		mar(20, "번호를 입력해주세요 : ");

		getnstr(&chap, 1);
		
		switch(chap)
		{
			case '1':

			case '2':
				clear();
				endwin();
				chap2();
				break;			

			case '3':
				clear();
				endwin();
				chap3();
				break;

			case '4':

			case '5':

			case '6':

			case '7':

			case '0':
				endwin();
				return ;

			defalut :
				move(24, 0);
				addstr("올바른 형식으로 입력해주세요.");
				usleep(1000 * 0.5);
		}				
	}
}

void chap2()
{
	initscr();

	while(1)
	{
		clear();

		char choice;

		mar(0, "챕터 2의 학습을 시작합니다.");

		mar(2, "학습하실 항목을 선택해주세요.");

		sleep(1);

		mar(4, "1. 학습 주제 및 목표");

		mar(6, "2. 개념 학습");

		mar(8, "3. C언어 함수 정리");

		mar(10, "0. 종료");

		mar(12, "번호를 입력해주세요 : ");

		getnstr(&choice, 1);

		switch(choice)
		{
			case '1':
				endwin();
				chap2_goal();
				break;

			case '2':		
				endwin();
				chap2_concept();
				break;	

			case '3':
				endwin();
				chap2_command();
				break;

			case '0':
				endwin();
				return ;

			defalut:
				mar(16, "올바른 형식으로 입력해주세요.");
				usleep(1000 * 0.5);
		}	
	}
}

void chap2_goal()
{
	initscr();
	char c;
	while(1)
	{
		clear();

		mar(0, "●  학습 주제 : who 명령어란? ");

		mar(2, "●  학습 목표 : ");

		mar(4, "  1. who 명령어의 개념을 정확하게 이해할 수 있다.");

		mar(6, "  2. C언어로 who 명령어를 작성해보며 who 명령어의 data-flow를 파악할 수 있다.");
	
		mar(8, "  3. User mode와 Kernel 모드를 정확하게 구분하고 System call에 발생하는 cost를 인지하여 효율적으로 관리할 수 있다."); 

		sleep(1);

		mar(12, " Enter to back to menu");
	
		getnstr(&c, 1);
		
		endwin();
		break;
	}


}

void chap2_concept()
{
	initscr();
	char c;
	while(1)
	{
		clear();
		mar(0, "1. 명령어의 개념");
	
		sleep(1);

		mar(2, "컴퓨터를 공부하면서 누구나 윈도우나 맥 또는 기타 cmd 프로그램을 사용해 보신 적이 있을 것입니다.");	

		mar(4, "예를 들면, $ cd home 을 통해 home 디렉토리로 이동하거나 $ ls 를 통해 디렉토리 내부의 파일 정보를 뽑을 수 있습니다."); 

		mar(6, "우분투의 터미널에서도 비슷한 명령어들이 활용됩니다.");

		mar(8, "우분투의 대부분의 Unix 명령어들은 C언어로 쓰여진 간단한 프로그램입니다.");

		mar(10, "즉, 저희가 Unix 명령어를 사용한다는 것은 C언어를 기반으로 만들어진 프로그램을 실행하는 것과 같습니다.");

		mar(12, "위의 예로 돌아가보면 $ ls 라는 것은 ls라는 이름의 C언어 프로그램을 shell에게 실행하도록 요청하는 것입니다.");
		
		mar(14, "Unix/Linux 개발자들은 사용자들의 편의성을 위해 자주 활용되는 기능들을 미리 구현하여 담아두었습니다.");

		mar(16, "해당 프로그램들은 효율성이 증명된 깔끔한 프로그램이며, /bin, /usr/bin 디렉토리에 담겨있습니다.");

		mar(18, "이는 다시 말하면 누구나 C언어로 프로그램을 만들고 위의 디렉토리에 넣어서 shell에서 사용할 수 있음을 의미합니다.");

		mar(20, "이번 챕터에서는 who 명령어를 작성하는 방법에 대해서 공부하겠습니다.");

		mar(24, "Enter to continue (0 : 학습 종료)");

		getnstr(&c, 1);
		if( c == '0') {break;}

		clear();
		mar(0, "2. who 명령어가 하는 일");

		sleep(1);

		mar(2, "who 명령어는 현재 컴퓨터에 접속하고 있는 사용자들의 정보를 출력해주는 명령어 입니다.");

		mar(4, "사용자 이름 | 터미널 이름 | 로그인 시간 | 로그인 host 의 기본적인 형식을 맞추어 출력하여 줍니다.");

		mar(6, "예를 들면");

		mar(8, "gyoungdeok ttyp1 2021-11-29 11:23 (:0) 과 같이 출력될 수 있습니다." ); 

		mar(10, "순서대로 gyoungdeok 은 사용자 이름, ttyp1은 터미널 이름, 시간은 로그인 시간, (:0)은 로그인 host를 나타냅니다.");

		mar(12, "아마 대부분의 분들께서 실제로 who 명령어를 사용해보시면 한 줄 혹은 두 줄밖에 출력되지 않을 것입니다.");

		mar(14, "이는 지극히 자연스러운 현상이며 책과 다르다고 걱정하실 필요가 없습니다."); 
	
		mar(16, "앞으로 네트워크와 통신, socket, thread, stty 등을 학습하며 다른 사용자와 상호작용을 하는 방법을 배우면서");

		mar(18, "점차 여러 개의 줄로 만들 수 있을 것 입니다.");

		mar(22, "Enter to continue (0 : 학습 종료)");

		getnstr(&c, 1);	
		if( c == '0') {break;}

		clear();
		mar(0, "3. UTMP");

		sleep(1);

		mar(2, "UTMP 파일은 현재 로그인한 사용자의 로그인 기록에 대한 문서(로그 파일)라고 생각하시면 됩니다.");

		mar(4, "이전에 배웠던 who 명령어를 실행하였을 때 출력되는 결과들은 UTMP 파일의 내용이라고 생각하면 될 것 같습니다.");

		mar(6, "who 명령어를 C언어로 직접 구현해볼 때 UTMP 파일의 내용을 불러와서 활용할 것 입니다.");
		
		mar(8, "C언어로 구현할 때는 <utmp.h>라는 헤더파일을 불러와서 UTMP를 다루어 볼 것입니다.");

		mar(10, "조금만 더 말씀드리자면, <utmp.h>에서 UTMP 파일의 내용을 담을 수 있도록 구현되어 있는 UTMP 구조체를 사용할 것 입니다.");

		mar(12, "( UTMP 구조체 내부 : 사용자 이름, 디바이스 이름, 로그인 시간, host 정보 )");

		mar(14, "참고로 UTMP 파일과 비슷한 WTMP 파일이 있습니다.");

		mar(16, "UTMP 파일이 현재 로그인한 사용자의 정보를 담고 있다면, WTMP 파일은 그동안 성공했던 로그인 및 로그아웃에 대한 모든 히스토리를 담고 있습니다.");

		mar(18, "터미널에서 $ last 를 통해서 확인할 수 있으니 참고하는 것도 좋을 것 같습니다.");

		mar(22, "Enter to continue (0 : 학습 종료)");
		getnstr(&c, 1);
		if(c == '0') {break;}
		
		clear();
		mar(0, "4. who 명령어의 Data-Flow");
		
		sleep(1);

		mar(2, "저희는 다음과 같은 방식으로 who 명령어를 구현할 예정입니다.");

		mar(4, "  ①  UTMP 파일 open");
	
		mar(6, "  ②  UTMP 구조체를 통해 UTMP 파일 read");

		mar(8, "  ③  읽어온 정보들 출력");	

		mar(10, "  ④  읽을 내용이 없을 때까지 ②  ~ ③  반복");

		mar(12, "  ⑤  UTMP 파일 close");

		mar(16, "Enter to continue (0 : 학습 종료)");

		getnstr(&c, 1);
		if(c == '0') {break;}

		clear();
		mar(0, "5. cp 명령어란?");

		sleep(1);

		mar(2, "cp 명령어는 파일의 복사본을 만드는 명령어입니다.");

		mar(4, "$ cp original new 을 통해 original 파일의 내용을 그대로 복사한 new 파일을 생성할 수 있습니다.");

		mar(6, "C언어에서 copy를 구현하는 자세한 방법은 chap 2의 '명령어 및 함수 정리'에서 다루겠습니다.");

		mar(8, "다음 장이 개념 정리의 마지막 장입니다. 조금만 힘내세요 !");

		mar(12, "Enter to continue (0 : 학습 종료)");

		getnstr(&c, 1);
		if(c == '0') {break;}

		clear();
		mar(0, "6. ★  User Mode & Kernel Mode  ★");

		sleep(1);

		mar(2, "저희가 UNIX를 다룰 때 크게 2 가지의 Mode로 나누어져 사용하게 됩니다.");
	
		mar(4, "첫 번째가 User_mode이고 두 번째는 Kernel_mode 입니다.");

		mar(6, "User_mode는 사용자가 접근할 수 있는 제한된 영역에 있을 때 활성화되는 mode입니다.");

		mar(8, "이 mode에서 사용자는 코드를 작성하거나 프로세스를 실행하는 등의 행동을 수행할 수 있습니다.");

		mar(10, "Kernel_mode는 User_mode에서 요청이 발생하였을 때 활성화될 수 있는 mode입니다.");

		mar(12, "User_mode와는 다르게 디스크, 메모리, CPU 등의 모든 자원에 접근하여 데이터를 관리하고 교류하는 역할을 합니다.");

		mar(14, "이렇게 나누어져 있는 가장 큰 이유는 컴퓨터 내부의 Data를 안전하게 관리하기 위함입니다.");

		mar(16, "만약, 사용자가 임의로 데이터를 사용하고 가져갈 수 있다면 Data_Pollution이나 Data_Loss가 발생할 수 있을 것입니다.");

		mar(18, "Kernel은 이러한 일을 방지하도록 설계되었습니다. ( 참고로 Kernel은 다른 많은 일에도 관할하고 있습니다. )");		

		mar(20, "저희가 프로세스를 실행하는 동안 프로세스는 두 개의 mode를 번갈아가며 실행이 됩니다.");

		mar(22, "예를 들어 프로세스가 실행되는 동안에 open함수를 호출했다고 가정해보겠습니다.");

		mar(24, "그렇게 되면 system call 함수인 open 이 호출되면서 Kernel_mode로 넘어갑니다.");

		mar(26, "open에 대한 입력값들이 Kernel로 함께 전달이 되고 관련 업무들을 수행한 이후, Kernel에서는 적절한 값을 반환하여 줍니다.");

		mar(28, "아마 이 예시에서는 open을 할 파일의 이름을 전달하였고, open 함수가 성공하였다면 해당 파일 디스크립터를 반환하여 줄 것입니다.");

		mar(30, "이 때의 값 반환과 함께 User_mode로 돌아가게 됩니다.");

		mar(32, "실제 프로세스에서는 다양한 system call이 호출되기 때문에 위의 흐름이 수없이 반복됩니다.");

		mar(34, "따라서, 프로그램을 작성할 때에는 System call이 호출됨에 따라 Time_Cost가 발생함을 충분히 고려하여야 합니다.");

		mar(36, "다시 말해서 Mode의 변환이 최소화 될 수 있도록 프로그램을 작성하여 효율성을 높여야 합니다.");

		mar(38, "예를 들어 5MB의 데이터를 복사한다면, 버퍼 사이즈를 1로 했을 때보다 4096으로 설정하는 것이 좋습니다.");

		mar(40, "메모리는 조금 차지할지라도, 소모되는 시간을 약 278배 정도 빠르게 할 수 있기 때문입니다.");
			
		mar(42, "★  중요한 부분이니 충분히 이해하고 넘어가셨으면 좋을 것 같습니다.  ★");

		mar(46, "Enter to end");

		getnstr(&c, 1);
		break;

	}
}

void chap2_command()
{
	initscr();

	while(1)
	{
		clear();
		refresh();

		char c;
	
		mar(0, "챕터 2의 C언어 함수를 살펴봅니다.");

		sleep(1);

		mar(2, "1. open");

		mar(4, "2. read");

		mar(6, "3. close");

		mar(8, "4. creat");

		mar(10, "5. write");

		mar(12, "6. lseek");

		mar(14, "0. 종료");

		mar(16, "번호를 입력해주세요 : ");

		getnstr(&c, 1);

		switch(c)
		{
			case '1':
				clear();
				mar(0, "open 함수 정리");
				mar(2, "헤더 파일 : <fcntl.h>");
				mar(4, "용도 : 파일과의 연결을 형성하고자 할 때 사용. 즉, 파일의 내용을 읽거나 파일을 다루고 싶을 때 사용함"); 	
				mar(6, "사용 방법 : open(열고자 하는 파일 이름, int how)");
				mar(7, "파일을 여는 목적에 따라 how의 값이 달라짐");
				mar(8, "O_RDONLY : 읽기 전용, O_WRONLY : 쓰기 전용, O_RDWR : 읽고 쓰기 전용");
				mar(9, "예시) open(input.txt, O_RDONLY");
				mar(11, "return 값");
				mar(12, "실패시 -1 반환, 성공시 file_descriptor 반환");
				mar(13, "file_descriptor : 파일과의 연결을 형성하면 프로세스마다 커널의 배열에 파일과의 연결 번호를 저장하는데 그 값을 의미");
				mar(14, "좀 더 나아가자면 모든 프로세스들은 기본적으로 0, 1, 2의 파일 디스크립터를 가지고 있다.");
				mar(15, "0 : 표준 입력, 1 : 표준 출력, 2 : 표준 에러 출력 (자세한 내용은 다른 챕터에서 공부함)");
				mar(19, "Enter to end");
				getnstr(&c, 1);
				break;
				
			case '2':
				clear();
				mar(0, "read 함수 정리");
				mar(2, "헤더 파일 : <unistd.h>");
				mar(4, "용도 : 파일의 내용을 지정한 버퍼에 담기 위해 사용. 즉, 파일의 내용을 읽기 위해서 사용함");
				mar(6, "사용 방법 : read(열고자 하는 파일의 fd, 버퍼 포인터, 읽을 크기)");
				mar(7, "예시) read(3, &buffer, BUFSIZ)");
				mar(9, "실패시 -1 반환, 성공시 읽은 만큼의 수를 반환");
				mar(13, "Enter to end");
				getnstr(&c, 1);
				break;
	
			case '3':
				clear();
				mar(0, "close 함수 정리");
				mar(2, "헤더 파일 : <unistd.h>");
				mar(4, "용도 : 파일과의 연결을 해제하고자 할 때 사용.");
				mar(6, "사용 방법 : close(해제하고자 하는 파일의 fd)");
				mar(7, "예시) close(3)");		
				mar(9, "실패시 -1 반환, 성공시 0 반환");
				mar(13, "Enter to end");
				getnstr(&c, 1);	
				break;

			case '4':
				clear();
				mar(0, "creat 함수 정리");
				mar(2, "헤더 파일 : <fcntl.h>");
				mar(4, "용도 : 새로운 파일을 만들고자 할 때 사용");
				mar(6, "사용 방법 : creat(새로운 파일의 이름, mode_t mode)");
				mar(7, "mode는 rw-r--r--와 같은 파일 권한을 의미");
				mar(8, "mode 표현 방법은 파일의 권한을 이진법으로 표기한 후 8진법으로 작성한다");
				mar(9, "예를 들어 rw-r--r--가 파일 권한이라면 이진법으로는 110100100이 되고 이를 8진법으로 고치면 0644가 된다");
				mar(10, "컴퓨터마다 기본적으로 깔려 있는 계산기의 프로그래머 기능을 활용하면 편하니 꼭 사용해볼 것");
				mar(11, "예시) creat(filename, 0644)");
				mar(13, "실패시 -1 반환, 성공시 새로운 파일의 파일 디스크립터를 반환");
				mar(17, "Enter to end");
				getnstr(&c, 1);
				break;

			case '5':
				clear();
				mar(0, "write 함수 정리");
				mar(2, "헤더 파일 : <unistd.h>");
				mar(4, "용도 : 버퍼의 내용을 파일에 담기 위해 사용. 즉, 파일에 내용을 쓰고 싶을 때 사용함");
				mar(6, "사용 방법 : write(작성할 파일의 fd, 버퍼 포인터, 작성할 양");
				mar(7, "예시) write(1, &buffer, BUFSIZ)");
				mar(9, "실패시 -1을 반환, 성공시 작성한 만큼의 양을 반환");
				mar(13, "Enter to end");
				getnstr(&c, 1);
				break;

			case '6':
				clear();
				mar(0, "lseek 함수 정리");
				mar(2, "헤더 파일 : <sys/types.h> <unistd.h>");
				mar(4, "용도 : 간단하게 설명하면 파일 내부에서 커서의 위치를 옮기기 위해서 사용함");
				mar(6, "사용 방법 : lseek(파일의 fd, 옮길 만큼의 거리, 시작점)");
				mar(7, "예시) lseek(3, 10, SEEK_CUR) : 커서의 현재 위치에서 10만큼 이동한다");
				mar(8, "시작점에 대한 변수 3가지");
				mar(9, "SEEK_SET : 시작점, SEEK_CUR : 현재 위치, SEEK_END : 파일의 끝지점");
				mar(11, "실패시 -1을 반환하며 성공시 0을 반환");
				mar(15, "Enter to end");
				getnstr(&c, 1);
				break;	
				clear();
			
			case '0':
				endwin();
				return; 
	
			defalut:
				mar(20, "올바른 형식으로 입력해주세요.");	
				usleep(1000 * 0.5);


		}	

		
	}
}

void chap3()
{
        initscr();

        while(1)
        {
                clear();

                char choice;

                mar(0, "챕터 3의 학습을 시작합니다.");

                mar(2, "학습하실 항목을 선택해주세요.");

                sleep(1);

                mar(4, "1. 학습 주제 및 목표");

                mar(6, "2. 개념 학습");

                mar(8, "3. C언어 함수 정리");

                mar(10, "0. 종료");

                mar(12, "번호를 입력해주세요 : ");

                getnstr(&choice, 1);

                switch(choice)
                {
                        case '1':
                                endwin();
                                chap3_goal();
                                break;

                        case '2':
                                endwin();
                                chap3_concept();
                                break;

                        case '3':
                                endwin();
                                chap3_command();
                                break;

                        case '0':
                                endwin();
                                return ;

                        default:
                                mar(16, "올바른 형식으로 입력해주세요.");
                                usleep(1000 * 0.5);
                }
        }
}

void chap3_goal()
{
        initscr();
        char c;
        while(1)
        {
                clear();

                mar(0, "●  학습 주제 : ls 명령어란? ");

                mar(2, "●  학습 목표 : ");

                mar(4, "  1. ls 명령어의 개념을 정확하게 이해하고 여러 명령어들을 활용할 수 있다.");

                mar(6, "  2. 디렉토리의 정확한 의미와 내부 구조를 파악할 수 있다.");

                mar(8, "  3. File에 관한 특성 및 정보를 정확하게 이해할 수 있다.");

		mar(10, "  4. ls 명령어 프로그램을 작성할 수 있다."); 
 
                sleep(1);

                mar(14, " Enter to back to menu");

                getnstr(&c, 1);

                endwin();
                break;
        }


}

void chap3_concept()
{
	char c;
	
	while(1) {
	
	clear();
	mar(0, "1. ls 명령어가 하는 일");

	sleep(1);

	mar(2, "모든 프로세스는 자신이 위치하고 있는 디렉토리의 위치 정보를 포함하고 있습니다.");

	mar(4, "ls는 현재 프로세스가 위치하고 있는 디렉토리의 파일들과 하위 디렉토리의 정보를 출력해주는 명령어 입니다.");

	mar(6, "기본적은로 옵션 없이 $ ls  를 실행할 경우 파일의 이름만 출력되게 됩니다.");

	mar(8, "예시) $ ls");

	mar(10, "공개 음악 문서 다운로드 test input.txt");

	mar(12, "파일에 관한 좀 더 자세한 설명을 받고자 한다면 ls 뒤에 옵션을 주어서 실행하면 됩니다.");

	mar(14, "가장 많이 사용되는 옵션은 '-l' 입니다. $ ls -l 을 하게 되면 각 파일에 대한 세부적인 정보를 불러올 수 있습니다.");

	mar(16, "더 나아가 a를 붙이면 '-al'은 숨겨져 있던 파일의 내용도 출력해주며 (all)");

	mar(18, "i를 붙이게 되면 각 파일의 inode number도 추가적으로 파악할 수 있습니다. (추후에 배우게 됨)");

	mar(20, "하이픈 기호(-) 를 사용한 옵션 말고도 다른 디렉토리의 이름을 옵션으로 줄 수 있습니다.");

	mar(22, "예를 들어 루트 노드에 있는 tmp 디렉토리 파일의 정보를 불러오고 싶다면 $ ls /tmp 와 같이 사용하면 됩니다.");

	mar(24, "정리해서 ls 명령어는 크게 2가지 정도만 이해하면 될 것 같습니다.");

	mar(26, "1. ls 명령어는 디렉토리 내부의 파일 정보를 읽어온다.");	

	mar(28, "2. -a 옵션을 주었을 때 출력되는 '.'은 현재 디렉토리를 의미하며 '..'은 상위 디렉토리를 의미한다.");

	mar(32, "Enter to Continue (0 : 종료)");

	getnstr(&c, 1);
	if(c == '0') { break;}
	clear();

	mar(0, "2. ls 명령어의 구현");

	sleep(1);

	mar(2, "ls 명령어의 기본적인 logic은 다음과 같습니다.");

	mar(4, "①  open 디렉토리");

	mar(6, "②  디렉토리 내부의 항목들 읽어오기");

	mar(8, "③  파일 세부 정보 출력");

	mar(10, "④  디렉토리의 모든 항목들에 대해서 ②  ~ ③  반복 수행");

	mar(12, "⑤  close 디렉토리");

	mar(14, "그렇다면 ①  번에서 디렉토리를 open 하기 위해서 chapter 2에서 사용했었던 open 함수를 사용해도 될까요?");

	mar(16, "결론을 말씀드리자면, 디렉토리는 파일과 내부적인 구조가 다르게 구현되어 있기 때문에 다른 라이브러리를 불러와서 사용해야 합니다.");

	mar(18, "<sys/types.h>  :  디렉토리 구조체와 디렉토리 포인터의 자료형이 구현되어 있는 헤더 파일");

	mar(20, "<dirent.h> : 디렉토리와 관련된 함수들이 구현되어 있는 헤더 파일");

	mar(22, "기본적으로 <dirent.h>의 opendir(), readdir(), closedir()을 통해서 디렉토리를 다루게 되는데 자세한 함수 설명은 함수 정리 부분에서 다루겠습니다.");

	mar(26, "Enter to Continue (0 : 종료)");

	getnstr(&c, 1);
	if(c == '0') {break;}
	clear();

	mar(0, "3. ls -l 세부 사항");

	sleep(1);

	mar(2, "$ ls -l 명령어는 프로세스가 위치한 디렉토리의 각 파일의 세부적인 정보들을 출력해 준다고 배웠습니다.");

	mar(4, "구체적으로는 다음과 같이 출력됩니다.");

	mar(6, "File 모드 및 권한 | 링크 수 | 파일을 소유한 사용자 이름 | 파일을 소유한 그룹 이름 | 파일 크기 | 마지막 수정 시간 | 파일명");

	mar(8, "예시");

	mar(10, "합계 64");

	mar(12, "drwxrw-r-- 3 Moon knu 4096 12월 1일 17:19 temp_directoy");

	mar(14, "가장 위에 나열되는 합계는 디렉토리 내부의 Block size를 의미합니다.");

	mar(16, "Block은 쉽게 생각해서 모든 파일을 동등한 공간에 효율적으로 저장하고자 지정한 최소 크기입니다.");

	mar(18, "A라는 파일은 1칸에 10 byte씩 저장하고 B라는 파일은 1칸에 300byte식 저장한다고 하면 저장 공간 관리 차원에서 비효율적일 것입니다.");

	mar(18, "이를 예방하고자 나온 개념이 Block입니다. 기본적으로 Linux 계열 커널은 block 1개가 512 byte의 크기를 가집니다.");

	mar(20, "다음으로는 1줄씩 출력되는 파일의 정보를 상세하게 알아보도록 하겠습니다.");

	mar(22, "첫 번째로 나오는 파일 모드와 두 번째로 나오는 링크 수는 다음 페이지에서 상세하게 다루도록 하겠습니다.");
	
	mar(24, "그 다음 항목들로는 moon과 knu가 출력되었습니다. 모든 파일은 사용자 및 그룹에 속해있는데 순서대로 해당 파일의 사용자 이름(moon)과 그룹 이름(knu)을 나타냅니다.");

	mar(26, " 다음의 4096은 파일의 크기를 의미합니다. 기본적으로 파일 크기는 byte 단위로 나타내며 $ ls -lh 와 같이 h 옵션을 추가하여 사람이 보기 편한 형식으로 바꾸어 줄 수 있습니다.");

	mar(28, "참고로 리눅스 계열에서 디렉토리의 파일 크기는 거의 4096으로 출력됩니다. 이는, 디스크에서 디렉토리에 대한 메타 정보를 저장하는데 보통 4096(4kb)가 필요하기 때문입니다.");

	mar(30, "이후에 나오는 수정 시간과 파일명은 직관적으로 이해할 수 있으실 것입니다.");

	mar(32, "다음 페이지에서 파일 모드와 링크 수에 대해서 알아보겠습니다.");

	mar(36, "Enter to Continue (0 : 종료)");
	getnstr(&c, 1);
	if(c == '0') {break;}
	clear();

	mar(0, "3-1. File 모드와 권한");

	sleep(1);

	mar(2, "이전의 예시에서 drwxrw-r--과 같이 출력되었습니다.");

	mar(4, "이는 파일의 상태와 권한에 대해서 나타내는 정보인데 첫 번째 칸이 파일의 상태(File인지, Directory인지 등등)을 나타내고 뒤에 9칸이 권한을 나타냅니다.");

	mar(6, "해당 예시에서 첫 번째 칸이 d로 채워져있는 것은 directory임을 의미합니다.");

	mar(8, "그리고 순서대로 3칸씩 파일의 사용자에 대한 권한, 그룹에 대한 권한, 기타 사용자에 대한 권한을 나타냅니다.");

	mar(10, "즉, 2~4칸 : User 권한, 5~7칸 : Group 권한, 8~10칸 : Others 권한 입니다.");

	mar(12, "그리고 각 칸은 r, w, x의 순서로 채워지는데 각각 읽기, 쓰기, 실행 권한을 의미합니다.");

	mar(14, "해당 칸에 대한 권한이 없을 경우 - 로 표시합니다.");

	mar(16, "예시의 경우를 따져보면, User는 읽고 쓰고 실행하는 것이 가능하고, Gruop은 읽고 쓰는 것만, Others는 읽는 것만 가능한 디렉토리였습니다.");

	mar(18, "추가적으로, 파일 권한에 대해서 3가지의 Special bit가 존재합니다.");

	mar(20, "첫 번째로 suid bit입니다. 해당 비트가 활성화 되어 있는 파일의 경우 파일의 소유 권한이 없는 사용자라도 사용 권한이 있는 것처럼 실행할 수 있게 됩니다.");

	mar(22, "이를 조금 더 어렵게 말해서 user id를 effective한 user id로 설정하였다고 표현합니다.");
	
	mar(24, "suid bit가 활성화되면 4번째 칸인 User 권한 영역의 x자리가 s로 표기됩니다.");

	mar(26, "두 번째는 sgid bit입니다. sgid 비트는 suid와 비슷한 역할을 그룹에게 해준다고 생각하면 됩니다.");

	mar(28, "즉, group id를 effective한 gruop id로 바꾸어 사용 권한이 있는 그룹처럼 해당 파일을 실행할 수 있게 해줍니다.");

	mar(30, "sgid bit가 활성화되면 7번째 칸인 Group 영역의 x자리가 s로 표기됩니다.");

	mar(32, "마지막 special bit는 sticky bit입니다. sticky bit는 파일에 적용된 경우와 디렉토리에 적용이 된 경우에 따라 역할이 달라집니다.");

	mar(34, "우선 파일에 적용이 되었을 경우 해당 파일이 사용되지 않게 되었을 때 메모리에서 해제하지 않고 그대로 유지하게 됩니다.");

	mar(36, "다음에 사용하게 되었을 때 디스크에서 따로 파일을 불러와서 메모리에 할당할 필요없이 바로 사용하면 되는 것이죠.");

	mar(38, "디렉토리에 적용이 되었을 경우 해당 디렉토리를 공용 디렉토리처럼 모두가 사용할 수 있도록 합니다. 하지만 삭제나 이름 변경등은 실제 소유자나 슈퍼 유저만 할 수 있습니다.");

	mar(40, "리눅스 터미널에서 $ chmod g+x 와 같이 파일의 권한을 변경할 수 있으니 직접 실습해보며 익혀보는 것도 좋을 것 같습니다.");

	mar(44, "Enter to Continue (0: 종료)");

	getnstr(&c, 1);
	if(c == '0') {break;}
	clear();

	mar(0, "3-2. 링크");
	
	sleep(1);

	mar(2, "세부적인 내용은 이후의 챕터에서 다룰 것이니 간단하게만 설명을 드리겠습니다.");

	mar(4, "링크는 파일이 다른 것들과 연결된 포인터의 개수라고 생각하시면 됩니다.");

	mar(6, "A라는 파일이 2라는 링크를 가지고 있다면 디렉토리 또는 파일에 연결된 포인터가 2개가 있다고 생각하시면 됩니다.");

	mar(8, "저희가 파일을 디렉토리 내부에 새롭게 생성할 때도, 파일의 내용이 작성된 이후에 현재 디렉토리와의 연결 포인터를 하나 만듭니다. 따라서 링크 수가 1로 생성됩니다."); 

	mar(10, "기타 하드 링크나 심볼릭 링크를 통해서도 파일 간의 값을 공유하거나 참조할 수 있는데 자세한 방법들은 이후의 챕터에서 다룰 것이니");

	mar(12, "링크의 개념만 인지하시고 하드 링크나 심볼릭 링크라는 방법을 통해서 링크를 만들 수 있음을 이해하시면 될 것 같습니다.");

	mar(16, "Enter to Continue");

	getnstr(&c, 1);
	if(c == '0')
	{break;}
	clear();
	
	}

}

void chap3_command()
{
	 initscr();

        while(1)
        {
                clear();
                refresh();

                char c;

                mar(0, "챕터 3의 C언어 함수를 살펴봅니다.");

                sleep(1);

                mar(2, "1. opendir");

                mar(4, "2. readdir");

                mar(6, "3. closedir");

                mar(8, "4. stat");

                mar(10, "5. chmod");

                mar(12, "6. chown");

                mar(14, "0. 종료");

                mar(16, "번호를 입력해주세요 : ");

                getnstr(&c, 1);

                switch(c)
                {
                        case '1':
                                clear();
                                mar(0, "opendir 함수 정리");
                                mar(2, "헤더 파일 : <sys/types.h> <dirent.h>");
                                mar(4, "용도 : 디렉토리를 열고자 할 때 사용");
                               	mar(6, "사용 방법 : DIR* opendir(const char* name)");
				mar(7, "name : 열고자 하는 디렉토리 이름"); 
                                mar(9, "예시) opendir('..')");
                               	mar(11, "실패 시 NULL 반환, 성공시 디렉토리 구조체 포인터 DIR* 반환"); 
				mar(13, "파일 디스크립터와 비슷하며 디렉토리 처리가 완료되면 닫아주는 것을 잊지 말 것!");
				mar(17, "Enter to end");
				getnstr(&c, 1);
				break;

                        case '2':
                                clear();
                                mar(0, "readdir 함수 정리");
                                mar(2, "헤더 파일 : <sys/types.h> <dirent.h>");
				mar(4, "용도 : 특정 디렉토리 내용을 읽기 위해서 사용");
				mar(6, "사용 방법 : struct dirent* readdir(DIR* dir)");
				mar(7, "opendir을 통해 반환받은 값을 인자로 넣어주면 됨.");
				mar(9, "예시) DIR* dir_ptr, struct dirent* entry로 선언되어 있을 때,");
				mar(10, "entry = readdir(dir_ptr) 과 같이 사용");
				mar(12, "실패 시 NULL qksghks, 성공 시 dirent 구조체에 대한 포인터(struct dirent*) 반환");                                
				mar(16, "Enter to end");
				getnstr(&c, 1);
				break;

                        case '3':
                                clear();
                                mar(0, "closedir 함수 정리");
                                mar(2, "헤더 파일 : <sys/types.h> <dirent.h>");
                                mar(4, "용도 : opendir() 호출로 반환 받았던 DIR과 연관된 디렉토리를 닫을 때 사용. 즉, 디렉토리를 닫을 때 사용");
				mar(6, "사용 방법 : int closedir(Dir* dirp)");	
				mar(8, "예시) closedir(dir_ptr)");
                                mar(10, "실패시 -1 반환, 성공시 0 반환");
				mar(14, "Enter to end");	
				getnstr(&c, 1);
				break;
	
			case '4':	
				clear();
				mar(0, "stat 함수 정리");
				mar(2, "헤더 파일 : <sys/stat.h>");
				mar(4, "용도 : 파일 크기, 권한, 생성 일자, 최종 변경일 등의 파일의 상태나 정보를 얻기 위해 사용");
				mar(6, "사용 방법 : stat(const char* pathname, struct stat* statbuf");
				mar(7, "pathname에는 현재 디렉토리 내부의 파일 이름이나 읽고자 하는 파일의 경로를 넘겨줘야 함");
				mar(8, "statbuf에는 비어 있는 stat 구조체 포인터를 넘겨주어야 함 (읽어온 정보를 저장할 공간으로 활용됨)");
				mar(10, "예시) char dirname = 'dir', struct stat* ptr 일때,");
				mar(11, "stat(dirname, ptr) 과 같이 사용");	
				mar(13, "실패 시 -1 반환, 성공 시 0 반환 (성공적으로 파일 정보를 조회하였음을 의미)");
				mar(17, "Enter to end");
				getnstr(&c, 1);
				break;
				
			case '5':
				clear();
				mar(0, "chomod 함수 정리");
				mar(2, "헤더 파일 : <sys/types.h> <sys/stat.h>");
				mar(4, "용도 : 파일의 권한을 바꾸거나 Special bit(suid, sgid, sticky)을 활성화하기 위해서 활용");
				mar(6, "사용 방법 : int chmod(char* path, mode_t mode)");
				mar(7, "path는 파일의 경로를 의미");
				mar(8, "mode는 파일 생성함수인 creat와 비슷하게 8진수 활용");
				mar(10, "예를 들어 mode에 0764를 넣어줬다면? ");
				mar(11, "0764 (8진수) -> 111 110 100 (2진수)");
				mar(12, "따라서 파일의 권한을 rwx rw- r-- 으로 재설정함");	
				mar(14, "예시) chmod('/tmp/myfile', 04764) ");
				mar(16, "실패 시 -1 반환, 성공 시 0 반환");
				mar(20, "Enter to end");	
				getnstr(&c, 1);
				break;

			case '6':
				clear();
				mar(0, "chown 함수 정리");
				mar(2, "헤더 파일 : <unistd.h>");
				mar(4, "용도 : 파일의 사용자나 그룹 아이디를 변경하기 위해서 사용. 즉, 파일의 소유 주체를 변경하기 위해서 사용");
				mar(6, "사용 방법 : int chown(char* path, uid_t owner, gid_t group)");
				mar(8, "예시) chown(filename, 100, 20) : 파일의 소유 주체가 uid가 100번인 사용자와 gid가 20번인 그룹으로 변경됨");	
				mar(10, "실제 사용 시에는 uid와 pid 인수 자리에");
				mar(11, "chmod(filename, user_info->pw_uid, group_info->gr_gid) 와 같이 다른 구조체의 값이 활용됨"); 
				mar(13, "실패 시 -1 반환, 성공 시 0 반환");
				mar(17, "Enter to end");
				getnstr(&c, 1);
				break;	

			case '0':
				endwin();
				return;

			default:
				mar(20, "올바른 형식으로 입력해주세요.");
				usleep(1000 * 0.5);
		}
	}
}










