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
    HanoiRecord top();
    bool is_empty();
 };

 void stack::push(HanoiRecord record) {
    HanoiRecordLink* newLink = new HanoiRecordLink{record, _top};
    _top = newLink;
}
    
 HanoiRecord stack::pop() {
    assert(!is_empty() && "The stack is empty");
    HanoiRecordLink* poppedLink = _top;
    _top = poppedLink->next;
    HanoiRecord poppedRecord = poppedLink->value;
    delete poppedLink;
    return poppedRecord;    
}

HanoiRecord stack::top(){
    assert(!is_empty() && "The stack is empty");
    return _top->value;
}

bool stack::is_empty(){
            return _top == nullptr;
}

void moveDisk(int sourcePole, int destinationPole){
    std::cout << "Move disk from pole " << sourcePole << " to pole " << destinationPole << std::endl;
}

void hanoiIterative(int n){
    stack stack;
    stack.push(HanoiRecord(n, 1, 2, 3));

    while (!stack.is_empty()) {
        HanoiRecord current = stack.pop();

        if (current._numberDisks == 1) {
            moveDisk(current._sourcePole, current._destinationPole);
        } else {
            stack.push(HanoiRecord(current._numberDisks - 1, current._sparePole, current._sourcePole, current._destinationPole));
            stack.push(HanoiRecord(1, current._sourcePole, current._sparePole, current._destinationPole));
            stack.push(HanoiRecord(current._numberDisks - 1, current._sourcePole, current._destinationPole, current._sparePole));
        }
    }
} 

//-----------end of stack class definition------------
int main() {
    int numberOfDisks;
    HanoiRecord tRecord;
    stack HanoiStack;
    std::cout << "How many disks?: " << std::flush;
    std::cin >> numberOfDisks;
    
    hanoiIterative(numberOfDisks);

    return 0;
 }
