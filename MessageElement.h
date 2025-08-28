//
// Created by galya777 on 11.06.25.
//

#ifndef OOP_COURSE_MESSAGEELEMENT_H
#define OOP_COURSE_MESSAGEELEMENT_H


// Абстрактен базов клас
class MessageElement {
public:
    virtual void print(char* buffer, int& index) const = 0;
    virtual ~MessageElement() {}
};



#endif //OOP_COURSE_MESSAGEELEMENT_H
