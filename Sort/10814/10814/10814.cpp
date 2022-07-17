
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*
문제
온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 이때, 회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다. 입력은 가입한 순서로 주어진다.

출력
첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.*/
vector<pair<int, string>> sorted(100001);
void merge(vector<pair<int, string>>& vec, int leftFirst, int leftEnd, int rightFirst, int rightEnd) {
    int saveFirst = leftFirst;
    
    int index = leftFirst;
    while (leftFirst <= leftEnd && rightFirst <= rightEnd) {
        if (vec[leftFirst].first <= vec[rightFirst].first)
            sorted[index++] = vec[leftFirst++];
        else
            sorted[index++] = vec[rightFirst++];
    }

    while (leftFirst <= leftEnd) {
        sorted[index++] = vec[leftFirst++];
    }
    while (rightFirst <= rightEnd) {
        sorted[index++] = vec[rightFirst++];
    }
    for (int i = saveFirst; i <= rightEnd; i++) {
        vec[i] = sorted[i];
    }
}
void merge_sort(vector<pair<int, string>>& vec, int first, int end) {
    if (first < end) {
       
        int mid = (first + end) / 2;
        merge_sort(vec, first, mid);
        merge_sort(vec, mid+1, end);
        merge(vec, first, mid, mid + 1, end);

    }
}
void Swap(pair<int, string> &a, pair<int, string>& b) {
    pair<int, string> temp = a;
    a = b;
    b = temp;
}
bool compare(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);


    vector<pair<int, string>> vec; // pair를 이용

    int n;
    cin >> n;
    int x; string y;

    for (int i = 0; i < n; i++) {
        cin >> x;
        cin >> y;
        vec.push_back(make_pair(x, y));
    }
    //stable_sort(vec.begin(), vec.end(), compare);
    
    merge_sort(vec, 0, n-1);
    
    for (int i = 0; i < n; i++) {
        cout << vec[i].first << " " << vec[i].second << "\n";
    }
}

