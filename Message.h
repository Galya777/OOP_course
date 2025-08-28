//
// Created by galya777 on 11.06.25.
//

#ifndef OOP_COURSE_MESSAGE_H
#define OOP_COURSE_MESSAGE_H


class Message {
    MessageElement** elements;
    int count;

public:
    Message(int n) : count(n) {
        elements = new MessageElement*[n];
        for (int i = 0; i < n; ++i) {
            elements[i] = nullptr;
        }
    }

    ~Message() {
        for (int i = 0; i < count; ++i) {
            delete elements[i];
        }
        delete[] elements;
    }

    void set(int i, MessageElement* el) {
        if (i >= 0 && i < count) {
            delete elements[i]; // За всеки случай
            elements[i] = el;
        }
    }

    void printAll(char* buffer) const {
        int index = 0;
        for (int i = 0; i < count; ++i) {
            if (elements[i]) {
                elements[i]->print(buffer, index);
            }
        }
        buffer[index] = '\0';
    }
};


#endif //OOP_COURSE_MESSAGE_H
