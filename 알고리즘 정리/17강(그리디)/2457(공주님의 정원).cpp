#include <iostream>
#include <algorithm>

using namespace std;

struct T{
    int start_hour;
    int start_min;
    int end_hour;
    int end_min;
};

bool compareObject(T a, T b){
    if(a.start_hour > b.start_hour){
        return 0;
    }
    else if(a.start_hour == b.start_hour){
        return a.start_min < b.start_min;
    }
    else{
        return 1;
    }
}

int N;
T arr[100011];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int start_hour;
    int start_min;
    int end_hour;
    int end_min;
    for(int i=0; i<N; i++){
        cin >> start_hour;
        cin >> start_min;
        cin >> end_hour;
        cin >> end_min;
        arr[i] = {start_hour,start_min,end_hour, end_min};
    }

    sort(arr, arr+N, compareObject);

    int target_hour = 3;
    int target_min = 1;
    int flower = 0;
    
    int end_hour_max = 0;
    int end_min_max = 0;

    if (arr[0].start_hour > 3 || (arr[0].start_hour == 3 && arr[0].start_min != 1) ) 
    {
        cout << 0;
        return 0;
    }

    for(int i=0; i<N; i++){
        if(arr[i].start_hour == arr[i].end_hour && arr[i].start_min == arr[i].end_min){
            continue;
        }
        // if(target_hour < arr[i].start_hour)
        // cout << arr[i].start_hour << ", " << arr[i].start_min << " // " << arr[i].end_hour << ", " << arr[i].end_min << "\n";    
        if(arr[i].start_hour < target_hour || (arr[i].start_hour == target_hour && arr[i].start_min <= target_min)){
            if(end_hour_max < arr[i].end_hour){
                end_hour_max = arr[i].end_hour;
                end_min_max = arr[i].end_min;
            }
            else if(end_hour_max == arr[i].end_hour){
                if(end_min_max < arr[i].end_min){
                    end_hour_max = arr[i].end_hour;
                    end_min_max = arr[i].end_min;
                }
            }

            if(end_hour_max > 11){
                target_hour = end_hour_max;
                target_min = end_min_max;
                flower++;
                break;
            }
            
        }
        else{
            
            flower++;
            target_hour = end_hour_max;
            target_min = end_min_max;
            
            // cout << "target_hour : " << target_hour << ", " << "target_min : " << target_min << "\n";
            if(target_hour > 11 || i == N-1){
                
                if(arr[i].start_hour < target_hour || (arr[i].start_hour == target_hour && arr[i].start_min <= target_min)){
                    
                    flower++;
                    target_hour = arr[i].end_hour;
                    target_min = arr[i].end_min;
                }
                break;
            }
            i--;
        }

    }
    if(target_hour > 11){
        cout << flower ;
    }
    else{
        cout << 0;
    }
}