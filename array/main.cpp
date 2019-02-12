#include <iostream>
bool duplicate(int numbers[], int length, int* duplication){
    if(numbers == nullptr || length <= 0)
        return false;
    for (int i = 0; i < length; ++i) {
        if(numbers[i]<0 || numbers[i]>length-1)
            return false;
    }

    for (int j = 0; j < length; ++j) {
        while (numbers[j]!=j){
            if (numbers[j] == numbers[numbers[j]]){
                *duplication = numbers[j];
                return true;
            }
            swap(numbers[j], numbers[numbers[j]]);
        }
    }
    return false;
}

int getDuplication(int numbers[], int length){
    if(numbers == nullptr || length <=0)
        return -1;
    int start = 1;
    int end = length -1;
    while (start <= end){
        int mid = (end - start)/2+start;
        int count = countRange(numbers, length, start, mid);
        if(end == start){
            if(count > 1)
                return start;
            else
                break;
        }
        if(count > (mid-start+1))
            end = mid;
        else
            start = mid+1;
    }
    return -1;
}

int countRange(const int* numbers[], int length, int start, int end){
    if(numbers == nullptr)
        return 0;

    int count = 0;
    for (int i = 0; i < length; ++i) {
        if(numbers[i] >= start && numbers[i]<= end)
            count++;
    }
    return count;
}

bool Find(int *matrix, int rows,int columns, int number){
    bool found = false;
    if(matrix != nullptr && rows>0 && columns>0){
        int row = 0;
        int column = columns-1;
        while (row < rows && column >=0){
            if(matrix[row*columns+column] == number){
                found = true;
                break;
            }
            else if (matrix[row*columns+column] > number){
                column --;
            } else
                row++;
        }
    }
    return found;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}