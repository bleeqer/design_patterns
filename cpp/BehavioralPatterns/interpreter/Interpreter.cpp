#include <iostream>
#include <unordered_map>

class Context {
    public:
    void set(char variable, bool value) {
        maps.insert(std::make_pair(variable, value));
    }

    bool get(char var) {
        return maps[var];
    }

    private:
    std::unordered_map<char, bool> maps;
};

class AbstractExpression {
    public:
    virtual ~AbstractExpression() {}
    virtual bool interpret(Context* const context) = 0;
};

class TerminalExpression : public AbstractExpression {
    public:
    TerminalExpression(char var) : var(var) {}
    ~TerminalExpression() {}

    bool interpret(Context* const context) override {
        return context->get(var);
    }

    private:
    char var;
};

class NonTerminalExpression : public AbstractExpression {
    public:
    NonTerminalExpression(AbstractExpression* left, AbstractExpression* right) : left(left), right(right) {}

    ~NonTerminalExpression() {
        if(left) {
            delete left;
        }
        if(right) {
            delete right;
        }
    }

    bool interpret(Context* const context) override {
        return left->interpret(context) && right->interpret(context);
    }

    private:
    AbstractExpression* left;
    AbstractExpression* right;
};

int main() {
    Context* context = new Context();
    context->set('A', true);
    context->set('B', false);
    context->set('C', true);

    AbstractExpression *expressionA = new TerminalExpression('A');
    AbstractExpression *expressionB = new TerminalExpression('B');
    AbstractExpression *expressionC = new TerminalExpression('C');

    AbstractExpression *expressionAB = new NonTerminalExpression(expressionA, expressionB);
    AbstractExpression *expressionAC = new NonTerminalExpression(expressionA, expressionC);

    std::cout << "A -> " << expressionA->interpret(context) << std::endl;
    std::cout << "B -> " << expressionB->interpret(context) << std::endl;
    std::cout << "C -> " << expressionC->interpret(context) << std::endl;
    
    std::cout << "AB -> " << expressionAB->interpret(context) << std::endl;
    std::cout << "AC -> " << expressionAC->interpret(context) << std::endl;

    delete expressionA;
    delete expressionB;
    delete expressionC;
    delete expressionAB;
    delete expressionAC;

    delete context;
    return 0;
}