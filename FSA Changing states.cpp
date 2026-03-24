#include <iostream>
#include <string>

//do not use namespace, try to learn without using it
class FSA {
public:
    //enum used to hold multiple states, think of it like an array
    enum class State {
        Start,
        A1,
        A2,              // for aa, same line of thinking on b2
        B1,
        B2,              
        Acceptingstate   //if aaa/bbb, will be accepted
    };

    FSA() : current(State::Start) {}

    void reset() {
        current = State::Start;
    }

//if ever confused on case, think of it like buttons on a remote
    void processchar(char ch) { //operates like an fsa charts, puts the word through the appropriate state
        switch (current) { 
            case State::Start:
                if (ch == 'a') current = State::A1;
                else if (ch == 'b') current = State::B1;
                else if (ch == 'c') current = State::Start;
                break;

            case State::A1:
                if (ch == 'a') current = State::A2;
                else if (ch == 'b') current = State::B1;
                else if (ch == 'c') current = State::Start;
                break;

            case State::A2:
                if (ch == 'a') current = State::Acceptingstate; 
                else if (ch == 'b') current = State::B1;
                else if (ch == 'c') current = State::Start;
                break;

            case State::B1:
                if (ch == 'b') current = State::B2;
                else if (ch == 'a') current = State::A1;
                else if (ch == 'c') current = State::Start;
                break;

            case State::B2:
                if (ch == 'b') current = State::Acceptingstate; 
                else if (ch == 'a') current = State::A1;
                else if (ch == 'c') current = State::Start;
                break;

            case State::Acceptingstate:
             
                if (ch == 'a' || ch == 'b' || ch == 'c') {
                    current = State::Acceptingstate;
                }
                break;
        }
    }

    bool Wordchecker(const std::string &word) {
        reset();

        for (char ch : word) {
            if (ch != 'a' && ch != 'b' && ch != 'c') {
                return false; //if anything exceeds the given alphabet
            }
            processchar(ch);
        }

        return isaccepted();
    }

    bool isaccepted() const {
        return current == State::Acceptingstate;
    }

private:
    State current;
};

int main() {
    FSA automaton; //created instance for FSA
    std::string input;

    std::cout << "Enter a word over {a, b, c}: ";
    std::cin >> input;

    bool accepted = automaton.Wordchecker(input); 

    if (accepted) {
        std::cout << "word status: (" << input << ") Acceptable.\n";
    } else {
        std::cout << "word status: (" << input << ") Rejected.\n";
    }

    return 0;
}

