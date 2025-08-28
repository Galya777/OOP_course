//
// Created by galya777 on 11.06.25.
//

#ifndef OOP_COURSE_SEPARATOR_H
#define OOP_COURSE_SEPARATOR_H


class Separator : public MessageElement {
public:
    void print(char* buffer, int& index) const override {
        const char* sep = " | ";
        for (int i = 0; sep[i] != '\0'; ++i) {
            buffer[index++] = sep[i];
        }
    }
};



#endif //OOP_COURSE_SEPARATOR_H
