#include <iostream>

class Receiver {
    public:
    void action() {
        std::cout << "Receiver: executing command" << std::endl;
    }
};

class Command {
    public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

class ConcreteCommand : public Command {
    public:
    ConcreteCommand(Receiver *receiver) : receiver(receiver) {}

    void execute() override {
        receiver->action();
    }

    private:
    Receiver *receiver;
};

class Invoker {
    public:
    void setCommand(Command *command) {
        this->command = command;
    }

    void executeCommand() {
        command->execute();
    }

    private:
    Command *command;   
};

int main() {
    Receiver* receiver = new Receiver();
    Command* command = new ConcreteCommand(receiver);
    Invoker* invoker = new Invoker();

    invoker->setCommand(command);
    invoker->executeCommand();

    delete receiver;
    delete command;
    delete invoker;

    return 0;
}