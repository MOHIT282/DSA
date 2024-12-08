// Given that there are N books and M students. Also given are the number of pages in each book in ascending order. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum, with the condition that every student is assigned to read some consecutive books.

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int booksArr[], int noOfBooks, int noOfStudents, int mid){

    int students = 1;
    int pageCount = 0;

    for(int i = 0; i<noOfBooks; i++){

        if(pageCount + booksArr[i] <= mid){
            pageCount += booksArr[i];
        }
        else{
            students++;
            if(students > noOfStudents || booksArr[i] > mid ){
                return false;
            }
            pageCount = booksArr[i];
        }
    }
    return true;
}

int allocateBooks(int booksArr[], int noOfBooks, int noOfStudents){

    if(noOfStudents > noOfBooks){ // no. of students is more than no. of books than there must be on student who will not get any book which should be avoided
        return -1;
    }
    int beg = 0;
    int sumOfPages = 0;

    for(int i = 0; i< noOfBooks; i++){
        sumOfPages += booksArr[i];
    }

    int end = sumOfPages,mid;
    int ans = -1;

    while(beg <= end){

        mid = beg + (end - beg)/2;
        cout<<"mid ->"<<mid<<endl;
        if(isPossible(booksArr, noOfBooks, noOfStudents,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            beg = mid + 1;
        }
    }
    return ans;

}

int main(){

    int books[] = {12,34,67,90};
    int numStudents = 4;
    int ans = allocateBooks(books,4,numStudents);
    if(ans == -1){
        cout<<"All the sudents can't be assigned a book";
    }
    else
    cout<<"The maximum no. of pages assigned to a student is : "<<ans<<endl;

}