//
// Created by galya777 on 11.06.25.
//

#ifndef OOP_COURSE_TEXT_H
#define OOP_COURSE_TEXT_H


class Text : public MessageElement {
    char* content;
public:
    Text(const char* str) {
        content = new char[strlen(str) + 1];
        strcpy(content, str);
    }

    ~Text() {
        delete[] content;
    }

    void print(char* buffer, int& index) const override {
        int len = strlen(content);
        for (int i = 0; i < len; ++i) {
            buffer[index++] = content[i];
        }
    }
};



#endif //OOP_COURSE_TEXT_H
