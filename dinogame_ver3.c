#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include <stdint.h>

#define DINOSAUR_BOTTOM_Y 22
#define TREE_BOTTOM_Y 30
#define PYRAMID_BOTTOM_Y 25
#define OBSTACLE_BOTTOM_X 100

// 공룡과 장애물의 이동 변위를 저장하는 구조체
typedef struct Delta {
    int dinov;
    int obstacleh;
} Delta;

// 콘솔 화면 생성자
void SetConsoleView() {
    system("mode con:cols=500 lines=300");
    system("title Google Dinosaurs. By Jinho");
}

// 콘솔 화면의 좌표값을 입력받아 해당 위치로 이동하는 함수
void GotoXY(int X, int Y) {
    COORD Pos;
    Pos.X = X;
    Pos.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 키가 눌렸는지 확인하는 함수
int GetKeyDown() {
    if (_kbhit()) {
        return _getch();
    }
    return 0;
}

// 'z' 키가 눌렸는지 확인하는 함수
void Ztyped(bool z, bool* pisJumping, bool* pisBottom) {
    if (z) {
        *pisJumping = true;
        *pisBottom = false;
    }
}

// 공룡을 그리는 함수
void DrawDino(int DINO_Y) {
    GotoXY(20, DINO_Y);
    static bool legFlag = true;
    printf("        $$$$$$$ \n");
    printf("                           $$ $$$$$$\n");
    printf("                           $$$$$$$$$\n");
    printf("                    $      $$$      \n");
    printf("                    $$     $$$$$$$  \n");
    printf("                    $$$   $$$$$     \n");
    printf("                     $$  $$$$$$$$$$ \n");
    printf("                     $$$$$$$$$$$    \n");
    printf("                      $$$$$$$$$$    \n");
    printf("                        $$$$$$$$    \n");
    printf("                         $$$$$$     \n");

    if (legFlag) {
        printf("                         $    $$$    \n");
        printf("                         $$          ");
        legFlag = false;
    }
    else {
        printf("                         $$$  $     \n");
        printf("                              $$    ");
        legFlag = true;
    }
}

// 나무를 그리는 함수
void DrawTree(int TREE_X) {
    GotoXY(TREE_X, TREE_BOTTOM_Y);
    printf("$$$$");
    GotoXY(TREE_X, TREE_BOTTOM_Y + 1);
    printf(" $$ ");
    GotoXY(TREE_X, TREE_BOTTOM_Y + 2);
    printf(" $$ ");
    GotoXY(TREE_X, TREE_BOTTOM_Y + 3);
    printf(" $$ ");
    GotoXY(TREE_X, TREE_BOTTOM_Y + 4);
    printf(" $$ ");
}

// 피라미드를 그리는 함수
void DrawPyramid(int PYRAMID_X) {
    GotoXY(PYRAMID_X, PYRAMID_BOTTOM_Y);
    printf("         *         ");
    GotoXY(PYRAMID_X, PYRAMID_BOTTOM_Y + 1);
    printf("        ***        ");
    GotoXY(PYRAMID_X, PYRAMID_BOTTOM_Y + 2);
    printf("       *****       ");
    GotoXY(PYRAMID_X, PYRAMID_BOTTOM_Y + 3);
    printf("      *******      ");
    GotoXY(PYRAMID_X, PYRAMID_BOTTOM_Y + 4);
    printf("     *********     ");
    GotoXY(PYRAMID_X, PYRAMID_BOTTOM_Y + 5);
    printf("    ***********    ");
    GotoXY(PYRAMID_X, PYRAMID_BOTTOM_Y + 6);
    printf("   *************   ");
    GotoXY(PYRAMID_X, PYRAMID_BOTTOM_Y + 7);
    printf("  ***************  ");
    GotoXY(PYRAMID_X, PYRAMID_BOTTOM_Y + 8);
    printf(" ***************** ");
    GotoXY(PYRAMID_X, PYRAMID_BOTTOM_Y + 9);
    printf("*******************");
}

// 게임 종료 창을 그리는 함수
void DrawGameOver(int SCORE) {
    system("cls");
    int x = 50;
    int y = 10;
    GotoXY(x, y);
    printf("===========================");
    GotoXY(x, y + 1);
    printf("======G A M E O V E R======");
    GotoXY(x, y + 2);
    printf("===========================");
    GotoXY(x, y + 5);
    printf("SCORE = %d", SCORE);
    printf("\n\n\n\n\n\n\n\n\n");
    system("pause");
}

// 공룡과 나무가 충돌했는지 여부를 확인하는 함수
bool TreeCollision(int TREE_X, int DINO_Y) {
    GotoXY(0, 0);
    if (TREE_X <= 28 && TREE_X >= 24 && DINO_Y > 8) {
        return true;
    }
    return false;
}

// 공룡과 피라미드가 충돌했는지 여부를 확인하는 함수
bool PyramidCollision(int PYRAMID_X, int DINO_Y) {
    GotoXY(0, 0);
    if (PYRAMID_X <= 43 && PYRAMID_X >= 24 && DINO_Y > 16) {
        return true;
    }
    return false;
}

// 공룡이 장애물과 충돌했는지 여부를 검사하는 함수
bool isCollision(int* pobstaclecase, int* pobstaclex, int* pdinoy) {
    switch (*pobstaclecase) {
    case 1:
        return TreeCollision(*pobstaclex, *pdinoy);
        break;
    case 2:
        return PyramidCollision(*pobstaclex, *pdinoy);
    default:
        return -1;
        break;
    }
}

// 공룡의 이동 변위를 난수에 따라 반환하는 함수
int DinoDelta(int obstaclecase, Delta d1, Delta d2) {
    switch (obstaclecase) {
    case 1:
        return d1.dinov;
        break;
    case 2:
        return d2.dinov;
        break;
    default:
        return -1;
        break;
    }
}

// 난수에 따라 장애물의 변위를 반환하는 함수
int ObstacleDelta(int* pobstaclecase, Delta d1, Delta d2) {
    switch (*pobstaclecase) {
    case 1:
        return d1.obstacleh;
        break;
    case 2:
        return d2.obstacleh;
        break;
    default:
        return -1;
        break;
    }
}

// 난수를 생성하는 함수
uint32_t GetRandomNumber() {
    // seed를 현재 시간으로 초기화
    srand((uint32_t)time(NULL));

    // 1부터 2까지의 난수 생성
    uint32_t randomNumber = rand() % 2 + 1;

    return randomNumber;
}

// 공룡의 움직임을 계산하는 함순
void DinoMove(bool* pisJumping, int* pdinoy, int* pdinodelta) {
    if (*pisJumping) {
        *pdinoy -= *pdinodelta;
    }
    else {
        *pdinoy += *pdinodelta;
    }
}

// 공룡의 움직임을 수정하는 함수
void ModifyDinoMove(bool* pisJumping, bool* pisBottom, int* pdinoy) {
    if (*pdinoy <= 1) {
        *pisJumping = false;
    }

    if (*pdinoy >= DINOSAUR_BOTTOM_Y) {
        *pdinoy = DINOSAUR_BOTTOM_Y;
        *pisBottom = true;
    }
}

// 장애물의 움직임을 계산하는 함수
void ObstacleMove(int* pobstaclecase, int* pobstaclex, int obstacledelta) {
    *pobstaclex -= obstacledelta;
    if (*pobstaclex <= 0) {
        *pobstaclecase = GetRandomNumber();
        *pobstaclex = OBSTACLE_BOTTOM_X;
    }
}

// 난수에 따라 장애물을 그리는 함수
void DrawObstacle(int* pobstaclecase, int* pobstaclex) {
    switch (*pobstaclecase) {
    case 1:
        DrawTree(*pobstaclex);
        break;
    case 2:
        DrawPyramid(*pobstaclex);
        break;
    default:
        break;
    }
}

int main(void) {
    SetConsoleView();
    int obstaclecase = GetRandomNumber();;
    int obstaclex;
    int dinoy;
    int dinodelta;
    int score = 0;
    clock_t start, curr;
    bool isJumping = false;
    bool isBottom = true;

    Delta Tree = {5, 10};
    Delta Pyramid = {4, 6};
    while (true) {
        dinodelta = DinoDelta(obstaclecase, Tree, Pyramid);
        dinoy = DINOSAUR_BOTTOM_Y;
        obstaclex = OBSTACLE_BOTTOM_X;
        start = clock();

        while (true) {
            // 충돌 여부 확인
            if (isCollision(&obstaclecase, &obstaclex, &dinoy)) {
                break;
            }

            // /z' 키가 눌렸는지 확인
            Ztyped(GetKeyDown() == 'z' && isBottom, &isJumping, &isBottom);

            // 공룡을 이동시킴
            DinoMove(&isJumping, &dinoy, &dinodelta);

            // 공룡의 위치를 수정
            ModifyDinoMove(&isJumping, &isBottom, &dinoy);

            // 장애물을 이동시킴
            ObstacleMove(&obstaclecase, &obstaclex, ObstacleDelta(&obstaclecase, Tree, Pyramid));

            // 화면 지우고 공룡 및 장애물 그리기
            system("cls");
            DrawDino(dinoy);
            DrawObstacle(&obstaclecase, &obstaclex);

            // 점수 계산
            curr = clock();
            if (((curr - start) / CLOCKS_PER_SEC) >= 1) {
                score++;
                start = clock();
            }

            // 화면에 점수 출력
            GotoXY(22, 0);
            printf("Score : %d ", score);

            // 프레임 간 간격 설정
            Sleep(60);
        }

        // 게임 종료 화면 표시
        DrawGameOver(score);
    }
    return 0;
}