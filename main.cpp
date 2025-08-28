//
// Created by galya777 on 11.06.25.
//
int main() {
    Message msg(3);
    msg.set(0, new Text("Temp:"));
    msg.set(1, new Number(25));
    msg.set(2, new Separator());

    char buffer[1024];
    msg.printAll(buffer);

    printf("%s\n", buffer); // Очакваме: Temp:25 |

    return 0;
}
