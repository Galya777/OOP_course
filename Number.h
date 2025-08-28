//
// Created by galya777 on 11.06.25.
//

#ifndef OOP_COURSE_NUMBER_H
#define OOP_COURSE_NUMBER_H


class Number : public MessageElement {
    int value;
public:
    Number(int v) : value(v) {}

    void print(char* buffer, int& index) const override {
        char temp[32];
        sprintf(temp, "%d", value);
        for (int i = 0; temp[i] != '\0'; ++i) {
            buffer[index++] = temp[i];
        }
    }
};



#endif //OOP_COURSE_NUMBER_H
