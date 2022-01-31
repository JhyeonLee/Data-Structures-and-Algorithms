#pragma once
// #ifdef __ARRAYLISTS_H_
// #define __ARRAYLISTS_H_
#include<stdio.h>

// 부당한 순위에 대한 접근으로 인해 처리 불가능한 상황
int invalidRankException() {
    printf("invalid Rank Exception\n");
    return -1;
}
// 리스트가 만훤이라 처리 불가능한 상황
int fullListException() {
    printf("full List Exception\n");
    return -1;
}
//리스트가 비어 있어 처리 불가은한 상황
int emptyListException() {
    printf("empty List Exception");
    return -1;
}
int notEnoughMemory() {
    printf("not Enough Memory");
    return -1;
}
int fullStackException() {
    printf("full Stack Exception");
    return -1;
}
int emptyStackException() {
    printf("empty Stack Exception");
    return -1;
}

// #endif