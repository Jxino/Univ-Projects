# 프로젝트명

이 프로젝트는 미니 프로젝트를 만들기 위해 C언어를 사용한 게임입니다.

## 설치

https://github.com/Jxino/Univ-Projects.git에서 DinoGame.c 파일을 다운로드하실 수 있습니다.

## 시작하기

vscode 2022 기준으로
```bash
gcc -o DinoGame DinoGame.c
```
```bash
./DinoGame
```
위의 명령어 두 개를 git bash 확장을 설치하고 터미널에 치면 실행됩니다.

## 주요 기능

- 피라미드가 장애물로 새롭게 추가된 구글의 공룡 게임을 플레이할 수 있습니다.
- 공룡과 장애물의 이동 속도를 사용자가 직접 조정할 수 있습니다.

## 기여 방법

1. 이 저장소를 포크합니다.
2. 새로운 브랜치를 생성합니다: 
```bash
git checkout -b feature/새로운 기능
```
3. 변경 사항을 커밋합니다: 
```bash
git commit -m '새로운 기능 추가'
```
4. 원격 저장소에 푸시합니다: 
```bash
git push origin feature/새로운기능
```
5. 풀 리퀘스트를 생성합니다.

## 라이선스

이 프로젝트는 MIT 라이선스에 따라 배포됩니다.

---

이 코드는 https://github.com/BlockDMask/Google_Dino의 일부를 기반으로 작성되었습니다.

**https://github.com/BlockDMask/Google_Dino**: https://blockdmask.tistory.com/344

## 팀

- 개발자 1: 김진호
- 개발자 2: 박도현

## 알려진 문제

- 장애물 추가가 어렵다.
- 공룡과 장애물의 충돌 여부 판정이 정밀하지 않다.

## 개선사항

- 공룡과 장애물의 변위 등의 정보를 담은 구조체와 그 구조체를 저장할 배열을 만들고 각각 동적 할당한다.
- 여러 번의 테스트를 거쳐 최선의 수치를 얻어낸다.