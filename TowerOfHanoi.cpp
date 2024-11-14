#include <iostream>
#include <cmath>
using namespace std;

class Stack{
    int top;
    int* arr;
    int capacity;
public:
    Stack(int c){
        capacity = c;
        top = -1;
        arr = new int[c];
    }
    // push function
    void push(int data){
        if(top == capacity - 1){
            cout << "Overflow." << endl;
            return;
        }
        arr[++top] = data;
    }
    // pop function
    int pop(){
        if(top == -1){
            cout << "Underflow." << endl;
            return -1;
        }
        return arr[top--];
    }
    // check if empty stack
    bool isEmpty(){
        return top == -1;
    }
    // show top value
    int Get_Top(){
        if(top == -1){
            cout << "There is no element in top." << endl;
            return -1;
        }
        return arr[top];
    }
    // show that at what point disk is moving
    void move_Disk(int disk, char From_Stand, char To_Stand){
        cout << "Move the disk " << disk << " from " << From_Stand << " to " << To_Stand << endl;
    }
    // tower function
    void Tower_Of_Hanoi(int number_of_disks){
        Stack first(number_of_disks), second(number_of_disks), third(number_of_disks);

            for (int i = number_of_disks; i >= 1; i--) {
            int disk_no;
			cout << "Enter the disk number :"; // enter disk no. manualy
            cin>> disk_no;
            first.push(disk_no);
        }
        int total_moves = pow(2, number_of_disks) - 1;
        for(int i = 1; i <= total_moves; i++){
            if(i % 3 == 1){
                if(first.isEmpty() || (!third.isEmpty() && third.Get_Top() < first.Get_Top())) {
                    int disk = third.pop();
					first.push(disk);
                    move_Disk(first.Get_Top(), 'C', 'A');
                }else{
                    int disk = first.pop();
					third.push(disk);
                    move_Disk(third.Get_Top(), 'A', 'C');
                }
            }else if(i % 3 == 2){
                if(first.isEmpty() || (!second.isEmpty() && second.Get_Top() < first.Get_Top())){
                    int disk = second.pop();
					first.push(disk);
                    move_Disk(first.Get_Top(), 'B', 'A');
                }else{
                    int disk = first.pop();
					second.push(disk);
                    move_Disk(second.Get_Top(), 'A', 'B');
                }
            }else{
                if(second.isEmpty() || (!third.isEmpty() && third.Get_Top() < second.Get_Top())){
                    int disk = third.pop();
					second.push(disk);
                    move_Disk(second.Get_Top(), 'C', 'B');
                }else{
                    int disk = second.pop();
					third.push(disk);
                    move_Disk(third.Get_Top(), 'B', 'C');
                }
            }
        }
    }
};
int main() {
    int number_of_disks;
    cout << "Enter the number of disks: ";
    cin >> number_of_disks;

    Stack stack(number_of_disks);
    stack.Tower_Of_Hanoi(number_of_disks); 

    return 0;
}

