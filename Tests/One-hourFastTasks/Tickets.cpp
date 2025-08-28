//
// Created by galya777 on 5.08.25 г..
//
#include <cstdio>
#include <cstring>

#define MAX_NAME_LEN 100

// === Абстрактен базов клас ===
class Ticket {
protected:
    int date;           // например 20250805
    int hour;           // например 1930
    int hallNumber;     // от 1 до 10
    double basePrice;

public:
    Ticket(int d, int h, int hall, double price)
            : date(d), hour(h), hallNumber(hall), basePrice(price) {}

    virtual double calculatePrice() const = 0;

    virtual ~Ticket() {} // ВАЖНО за полиморфизъм
};

// === Ordinary Ticket ===
class OrdinaryTicket : public Ticket {
private:
    int row;
    int seat;

public:
    OrdinaryTicket(int d, int h, int hall, double price,
                   int r, int s)
            : Ticket(d, h, hall, price), row(r), seat(s) {}

    double calculatePrice() const override {
        return basePrice;
    }
};

// === Named Ticket ===
class NamedTicket : public Ticket {
private:
    char name[MAX_NAME_LEN];
    int lodgeNumber;

public:
    NamedTicket(int d, int h, int hall, double price,
                const char* userName, int lodge)
            : Ticket(d, h, hall, price), lodgeNumber(lodge) {
        strncpy(name, userName, MAX_NAME_LEN);
        name[MAX_NAME_LEN - 1] = '\0';
    }

    double calculatePrice() const override {
        return basePrice * 3;
    }
};

// === Special Guest Ticket ===
class SpecialTicket : public NamedTicket {
private:
    int meetDate;
    int meetHour;

public:
    SpecialTicket(int d, int h, int hall, double price,
                  const char* userName, int lodge,
                  int meetD, int meetH)
            : NamedTicket(d, h, hall, price, userName, lodge),
              meetDate(meetD), meetHour(meetH) {}

    double calculatePrice() const override {
        return 0.0; // безплатен
    }
};

// === Функция за сумиране ===
double totalPrice(Ticket* tickets[], int count) {
    double sum = 0.0;
    for (int i = 0; i < count; ++i) {
        sum += tickets[i]->calculatePrice(); // ВАЖНО: полиморфно
    }
    return sum;
}

// === Демонстрация ===
int main() {
    // Създаваме билети в стека
    OrdinaryTicket t1(20250805, 1930, 2, 20.0, 10, 15);
    NamedTicket t2(20250805, 1930, 3, 25.0, "Ivan Ivanov", 5);
    SpecialTicket t3(20250805, 1930, 4, 30.0, "Maria Petrova", 7, 20250805, 1830);

    // Масив от указатели към базовия клас
    Ticket* tickets[3] = { &t1, &t2, &t3 };

    double total = totalPrice(tickets, 3);

    printf("Total price of all tickets: %.2f\n", total);

    return 0;
}
