#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/*
문제
수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 
단, N은 홀수라고 가정하자.

산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 단, N은 홀수이다. 그 다음 N개의 줄에는 정수들이 주어진다. 
입력되는 정수의 절댓값은 4,000을 넘지 않는다.

출력
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.
*/


int sorted[500001];
void Merge(int list[], int leftFirst, int leftEnd, int rightFirst, int rightEnd) {
    int saveFirst = leftFirst;
    
    int index = leftFirst;
    while (leftFirst <= leftEnd && rightFirst <= rightEnd) {
        if (list[leftFirst] < list[rightFirst])
            sorted[index] = list[leftFirst++];
        else
            sorted[index] = list[rightFirst++];
        index++;
    }

    while (leftFirst <= leftEnd) {
        sorted[index] = list[leftFirst++];
        index++;
    }
    while (rightFirst <= rightEnd) {
        sorted[index] = list[rightFirst++];
        index++;
    }
    for (int i = saveFirst; i <= rightEnd; i++) {
        list[i] = sorted[i];
    }
}
void Merge_sort(int list[], int left, int right) {
 
    if (left < right) {
        int mid = (left + right) / 2;
        Merge_sort(list, left, mid);
        Merge_sort(list, mid + 1, right);
        Merge(list, left, mid, mid + 1, right);
    }
}


int main()
{
    int n;
    int count_arr[8001] = { 0 };
    int arr[500001];
    
    double sansul = 0;
    cin >> n;
    int cur_num;
    
    for (int i = 0; i < n; i++) {
        cin >> cur_num;
        sansul += cur_num;
        count_arr[cur_num + 4000]++;
        arr[i] = cur_num;
    }
    
    // 산술평균
    sansul = sansul / n;
    if (sansul > 0) sansul += 0.5;
    else sansul -= 0.5;
    cout << (int)sansul << "\n";
    

    // 중앙값
    Merge_sort(arr, 0, n - 1);
    //sort(arr, arr + n);
    cout << arr[n / 2] << "\n";

    //최빈값 
    int flag;
    int max_num = 0;
    for (int i = 0; i <= 8000; i++) {
        if (count_arr[i] > max_num) {
            max_num = count_arr[i];
            flag = i;
        }
    }
    for (int i = flag + 1; i <= 8000; i++) {
        if (count_arr[i] == max_num) {
            flag = i;
            break;
        }
    }
    cout << flag - 4000 << "\n";

    //범위
    cout << arr[n - 1] - arr[0];
    
}

