/*
==============================+===============================================================
@ File Name : 1931_MeetingRoom.h
@ Author : jopemachine
@ Created Date : 2019-06-30, 10:37:49
@ Desc : 
@    회의실배정
@ Issue : 
@    11
@    1 4
@    3 5
@    0 6
@    5 7
@    3 8
@    5 9
@    6 10
@    8 11
@    8 12
@    2 13
@    12 14
==============================+===============================================================
*/
//
// Created by wonma on 2019-06-30.
//

#ifndef ALGORITHM_1931_MEETINGROOM_H
#define ALGORITHM_1931_MEETINGROOM_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>

using namespace std;


int descendingCompare(const void* a, const void* b)
{
    int num1 = (*(pair<int, int>*) a).second;
    int num2 = (*(pair<int, int>*) b).second;

    if (num1 > num2)
        return 1;
    else if (num1 < num2)
        return -1;

    else {
        int num1_1 = (*(pair<int, int>*) a).first;
        int num1_2 = (*(pair<int, int>*) b).first;

        if(num1_1 > num1_2){
            return 1;
        }
        else if(num1_1 < num1_2){
            return -1;
        }
        else {
            return 0;
        }
    }
}



void solve_1931(){


    int N;
    cin >> N;

    pair<int, int> *meetingTime = new pair<int,int>[N];

    int currentTime = 0;
    int maxMeetingRoomNum = 0;
    int maxStartTime = 0;

    for (int i = 0; i< N; i++){
        cin >> meetingTime[i].first >> meetingTime[i].second;
        if(meetingTime[i].first > maxStartTime) maxStartTime = meetingTime[i].first;
    }


    qsort(meetingTime, N, sizeof(pair<int, int>), descendingCompare);

    for (int i = 0; i < N; i++){
        if(meetingTime[i].first >= currentTime){
            maxMeetingRoomNum++;
            currentTime = meetingTime[i].second;
        }
    }

    cout << maxMeetingRoomNum;

}


#endif //ALGORITHM_1931_MEETINGROOM_H
