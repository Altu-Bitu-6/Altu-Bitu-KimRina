#include<iostream>
#include <cmath>

using namespace std;

int main() {
    int before_w, before_m, t;
    int D, diet_i, diet_a;

    cin >> before_w >> before_m >> t;
    cin >> D >> diet_i >> diet_a;

    int w0 = before_w; // 변화 반영x 무게
    int w1 = before_w; // 변화 반영o 무게

    int change_m = before_m; // 변화 반영 기초대사량

    for(int i=0; i<D; i++) {
        /*
        변화 반영x
        무게 += (에너지섭취량 - (기초대사량 + 활동 대사량)) 만큼 체중 변화
        */
        w0 += diet_i - (before_m + diet_a);

        /*
        변화 반영o
        무게 += (에너지섭취량 - (기초대사량 + 활동 대사량)) 만큼 체중 변화
        (에너지섭취량 - (기초대사량 + 활동 대사량)) T 초과이면,
        기초 대사량 += ⌊ (에너지섭취량 - (기초대사량 + 활동 대사량)) / 2 ⌋
        */
        w1 += diet_i - (change_m + diet_a);
        if( abs(diet_i - (change_m + diet_a)) > t) {
            change_m += floor((diet_i - (change_m + diet_a))/2.0);
        }
    }

    if (w0 <= 0)
        cout << "Danger Diet\n";
    else
        cout << w0 << " " << before_m << "\n";

    if (w1 <= 0 || change_m <= 0) 
        cout << "Danger Diet\n";
    else {
        cout << w1 << " " << change_m << " ";
        if(change_m < before_m)
            cout << "YOYO";
        else
            cout << "NO";
    }
}


/*
전 체중, 전 기초대사량, 기초대사량 변화역치
다이어트기간, 에너지섭취량, 활동대사량

변화 반영x
무게 += (에너지섭취량 - (기초대사량 + 활동 대사량)) 만큼 체중 변화

변화 반영 o
무게 += (에너지섭취량 - (기초대사량 + 활동 대사량)) 만큼 체중 변화
(에너지섭취량 - (기초대사량 + 활동 대사량)) T 초과이면,
기초 대사량 += ⌊ (에너지섭취량 - (기초대사량 + 활동 대사량)) / 2 ⌋

일일 기초 대사량 변화는 같은 날의 체중 변화 다음에 일어난다.
*/

    //다이어트 후 예상 체중, 일일 기초대사량 출력 / 죽을 경우 Danger Diet 출력
    
    //일일 기초대사량변화 고려x

    //일일 기초대사량변화 고려o 체중 증가 시 요요
    