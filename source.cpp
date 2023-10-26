#include<iostream>
#include<cassert>

struct HanoiRecord {
    int _numberDisks;
    int _sourcePole, _sparePole, _destinationPole;

    HanoiRecord() {
        _sourcePole = _sparePole = _destinationPole = 0;
        _numberDisks = 0;
    }

    HanoiRecord(int numberDisks, int sourcePole, int sparePole, int destinationPole) {
        _numberDisks = numberDisks;
        _sourcePole = sourcePole;
        _sparePole = sparePole;
        _destinationPole = destinationPole;
    }
};

class stack {
private:
    struct HanoiRecordLink {
        HanoiRecord value;
        HanoiRecordLink* next;
    };
    
    HanoiRecordLink* _top;

    public:
        stack() {
            _top = nullptr;
        }

        void push(HanoiRecord record);
        HanoiRecord pop();
        HanoiRecord top() {
        /* missing code */
        }

        bool is_empty(){
            return _top == nullptr;

        }
 };

 void stack::push(HanoiRecord record) {
 /* missing code */
    }
    
 HanoiRecord stack::pop() {
 
/* missing code */
}
 //-----------end of stack class definition------------
int main() {
    int numberOfDisks = 0;
    HanoiRecord tRecord;
    stack HanoiStack;
    std::cout << "How many disks? " << std::flush;
    std::cin >> numberOfDisks;
    
    HanoiStack.push(HanoiRecord(numberOfDisks, 1, 2, 3));
 /* missing code */
 }
